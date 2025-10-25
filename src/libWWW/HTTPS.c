/*	HyperText Transfer Protocol over SSL/TLS - Client		HTTPS.c
**	===============================================
**
**	This is a modified version of HTTP.c with SSL/TLS support
**	for HTTPS connections (https:// URLs).
**
**	Based on HTTP.c from libwww
*/

#include "HTTPS.h"

#ifdef USE_SSL

#include "HTAABrow.h"
#include "HTAlert.h"
#include "HTFormat.h"
#include "HTInit.h"
#include "HTMIME.h"
#include "HTML.h"
#include "HTParse.h"
#include "HTTCP.h"
#include "HTUtils.h"
#include "HTSSL.h"
#include "HTWayback.h"
#include "HTKeepAlive.h"
#include "tcp.h"
#include <ctype.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/time.h>

/* Forward declarations */
extern void http_progress_notify();

/* Read chunked transfer encoding data */
PRIVATE int read_chunked_data ARGS3(
    HTSSLConnection*, ssl_conn,
    char*, buffer,
    int, buffer_size
) {
    char chunk_size_line[32];
    int chunk_size;
    int pos = 0;
    int total_read = 0;
    
    /* Read chunk size (hex number until CRLF) */
    while (pos < sizeof(chunk_size_line) - 1) {
        int status = HTSSL_read(ssl_conn, chunk_size_line + pos, 1);
        if (status <= 0) {
            return -1;
        }
        
        if (pos > 0 && chunk_size_line[pos-1] == '\r' && chunk_size_line[pos] == '\n') {
            chunk_size_line[pos-1] = '\0';  /* Terminate before \r\n */
            break;
        }
        pos++;
    }
    
    /* Parse hex chunk size */
    chunk_size = (int)strtol(chunk_size_line, NULL, 16);
    
    if (chunk_size == 0) {
        /* Last chunk - read trailing CRLF */
        char trail[2];
        HTSSL_read(ssl_conn, trail, 2);
        return 0;  /* EOF */
    }
    
    /* Read chunk data */
    if (chunk_size > buffer_size) {
        chunk_size = buffer_size;  /* Limit to buffer size */
    }
    
    total_read = 0;
    while (total_read < chunk_size) {
        int status = HTSSL_read(ssl_conn, buffer + total_read, chunk_size - total_read);
        if (status <= 0) {
            return -1;
        }
        total_read += status;
    }
    
    /* Read trailing CRLF after chunk data */
    {
        char trail[2];
        HTSSL_read(ssl_conn, trail, 2);
    }
    
    return total_read;
}

#define HTTPS_VERSION "HTTP/1.0"
#define HTTPS2 /* Version is greater than 0.9 */

#define INIT_LINE_SIZE 1024    /* Start with line buffer this big */
#define LINE_EXTEND_THRESH 256 /* Minimum read size */
#define VERSION_LENGTH 20      /* for returned protocol version */

/* These are shared with HTTP.c */
extern int http_method;
extern char* http_dataToPost;

struct _HTStream {
    HTStreamClass* isa; /* all we need to know */
};

extern char* HTAppName;    /* Application name */
extern char* HTAppVersion; /* Application version */

/*	Find HTTP header (case-insensitive)
**	-----------------------------------
*/
PRIVATE char* find_header(char* headers, const char* header_name) {
    char* p = headers;
    int len = strlen(header_name);
    
    while (*p) {
        /* Check if we're at start of line */
        if (p == headers || *(p-1) == '\n') {
            /* Compare header name case-insensitively */
            int i;
            int match = 1;
            for (i = 0; i < len && p[i]; i++) {
                if (TOLOWER(p[i]) != TOLOWER(header_name[i])) {
                    match = 0;
                    break;
                }
            }
            /* Make sure we matched the full length and have room to check ':' */
            if (match && i == len && p[len] && p[len] == ':') {
                return p;
            }
        }
        p++;
    }
    return NULL;
}

/*		Load Document from HTTPS Server			HTLoadHTTPS()
**		===============================
**
**	Given a hypertext address, this routine loads a document over SSL/TLS.
**
** On entry,
**	arg	is the hypertext reference of the article to be loaded.
**
** On exit,
**	returns	>=0	If no error, a good socket number
**		<0	Error.
*/
PUBLIC int HTLoadHTTPS ARGS4(CONST char*, arg,
                             HTParentAnchor*, anAnchor, 
                             HTFormat, format_out, 
                             HTStream*, sink) {
    int s;                   /* Socket number for returned data */
    HTSSLConnection* ssl_conn = NULL; /* SSL connection */
    char* command;           /* The whole command */
    char* eol = 0;           /* End of line if found */
    char* start_of_data;     /* Start of body of reply */
    int length;              /* Number of valid bytes in buffer */
    int status;              /* tcp return */
    char crlf[3];            /* A CR LF equivalent string */
    HTStream* target = NULL; /* Unconverted data */
    HTFormat format_in;      /* Format arriving in the message */
    char* auth = NULL;       /* Authorization information */

    CONST char* gate = 0; /* disable gateway feature */
    SockA soc_address;    /* Binary network address */
    SockA* sin = &soc_address;
    BOOL had_header = NO;
    char* text_buffer = NULL;
    char* binary_buffer = NULL;
    int buffer_length = INIT_LINE_SIZE;
    BOOL extensions = YES;
    int server_status = 0;
    ptrdiff_t offset = 0;

    int tries = 0;
    char* hostname = NULL;
    static int redirect_count = 0;  /* Track redirect depth */
    #define MAX_REDIRECTS 10
    
    HTConnection* pooled_conn = NULL;  /* Connection from pool */
    BOOL connection_from_pool = NO;
    BOOL keep_alive = NO;  /* Server supports keep-alive */
    int port = 443;  /* Default HTTPS port */
    
    /* Performance monitoring */
    struct timeval start_time, end_time, connect_time;
    long connect_ms = 0, total_ms = 0;
    int bytes_received = 0;
    
    gettimeofday(&start_time, NULL);

    extern int http_progress_expected_total_bytes;
    extern int http_progress_subtotal_bytes;
    extern int http_progress_total_bytes;
    extern int http_progress_reporter_level;
    static int delimSize = 0;
    static char* delim = "Content-length: ";
    char delimBuf[32];
    int i, j, delimi = 0;
    char *cp, *buffp, buff[100];
    int foundContentLength = 0;

    if (delimSize == 0)
        delimSize = strlen(delim);

    if (!arg)
        return -3;
    if (!*arg)
        return -2;

    /* Set up defaults - use port 443 for HTTPS */
#ifdef DECNET
    sin->sdn_family = AF_DECnet;
    sin->sdn_objnum = DNP_OBJ;
#else
    sin->sin_family = AF_INET;
    sin->sin_port = htons(443); /* HTTPS port */
#endif

    sprintf(crlf, "%c%c", CR, LF);

    if (TRACE) {
        fprintf(stderr, "HTTPSAccess: Direct HTTPS access for %s\n", arg);
    }

    /* Get node name and optional port number */
    {
        char* p1 = HTParse(arg, "", PARSE_HOST);
        int status = HTParseInet(sin, p1);
        free(p1);
        if (status) {
            return status; /* No such host - let caller handle Wayback */
        }
    }

    /* Extract hostname and port for SNI and connection pooling */
    {
        char* hostport = HTParse(arg, "", PARSE_HOST);
        if (hostport) {
            char* colon = strchr(hostport, ':');
            if (colon) {
                *colon = '\0';
                port = atoi(colon + 1);
            }
            hostname = strdup(hostport);
            free(hostport);
        }
    }

retry:

    /* Check redirect limit */
    if (redirect_count >= MAX_REDIRECTS) {
        redirect_count = 0;
        if (hostname) free(hostname);
        HTAlert("Too many redirects");
        return -1;
    }

    /* Compose authorization information */
#ifdef ACCESS_AUTH
#define FREE(x)                                                                                    \
    if (x) {                                                                                       \
        free(x);                                                                                   \
        x = NULL;                                                                                  \
    }
{
    char* docname;
    char* hostport;
    char* colon;
    int portnumber;

    docname = HTParse(arg, "", PARSE_PATH);
    hostport = HTParse(arg, "", PARSE_HOST);
    if (hostport && NULL != (colon = strchr(hostport, ':'))) {
        *(colon++) = '\0';
        portnumber = atoi(colon);
    } else
        portnumber = 443;

    auth = HTAA_composeAuth(hostport, portnumber, docname);

    if (TRACE) {
        if (auth)
            fprintf(stderr, "HTTPS: Sending authorization: %s\n", auth);
        else
            fprintf(stderr, "HTTPS: Not sending authorization (yet)\n");
    }
    FREE(hostport);
    FREE(docname);
}
#endif /* ACCESS_AUTH */

    /* Try to get connection from pool */
    pooled_conn = HTKeepAlive_getConnection(hostname, port, YES);
    
    if (pooled_conn) {
        /* Reuse existing connection */
        s = pooled_conn->socket;
        ssl_conn = pooled_conn->ssl_conn;
        connection_from_pool = YES;
        
        if (TRACE) {
            fprintf(stderr, "HTTPS: Reusing keep-alive connection to %s:%d\n", hostname, port);
        }
        gettimeofday(&connect_time, NULL);
        connect_ms = 0;
    } else {
        /* Create new socket */
#ifdef DECNET
        s = socket(AF_DECnet, SOCK_STREAM, 0);
#else
        s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
#endif
        
        /* Set socket timeouts to prevent hanging on unresponsive servers */
        {
            struct timeval timeout;
            /* Connect/Send timeout: 30 seconds */
            timeout.tv_sec = 30;
            timeout.tv_usec = 0;
            setsockopt(s, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
            
            /* Initial read timeout: 60 seconds (like modern browsers) */
            timeout.tv_sec = 60;
            timeout.tv_usec = 0;
            setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
        }
        
        if (TRACE) {
            fprintf(stderr, "HTTPS: Connecting to %s:%d...\n", hostname, port);
        }
        
        status = connect(s, (struct sockaddr*)&soc_address, sizeof(soc_address));
        if (status < 0) {
            if (TRACE) {
                fprintf(stderr, "HTTPS: Connection failed (errno=%d)\n", errno);
            }
            if (hostname) free(hostname);
            return HTInetStatus("connect");
        }
        
        if (TRACE) {
            fprintf(stderr, "HTTPS: Connected successfully\n");
        }

        /* Wrap socket with SSL */
        ssl_conn = HTSSL_connect(s, hostname);
        if (!ssl_conn) {
            fprintf(stderr, "HTTPS: SSL connection failed\n");
            close(s);
            if (hostname) free(hostname);
            return -1;
        }

        gettimeofday(&connect_time, NULL);
        connect_ms = (connect_time.tv_sec - start_time.tv_sec) * 1000 + 
                     (connect_time.tv_usec - start_time.tv_usec) / 1000;
        if (TRACE) {
            fprintf(stderr, "HTTPS: New connection to %s:%d (handshake %ld ms)\n", 
                    hostname, port, connect_ms);
        }
    }

    /* Build HTTP request */
    {
        char* p1 = HTParse(arg, "", PARSE_PATH | PARSE_PUNCTUATION);
        command = malloc(4 + strlen(p1) + 2 + 31);
        if (command == NULL) {
            HTSSL_close(ssl_conn);
            if (hostname) free(hostname);
            outofmem(__FILE__, "HTLoadHTTPS");
        }

        if (http_method == HTTP_METHOD_POST)
            strcpy(command, "POST ");
        else
            strcpy(command, "GET ");

        strcat(command, p1);
        free(p1);
    }

#ifdef HTTPS2
    if (extensions) {
        strcat(command, " ");
        strcat(command, HTTPS_VERSION);
    }
#endif

    strcat(command, crlf);

    if (extensions) {
        int n;
        int i;
        HTAtom* present = WWW_PRESENT;
        char line[256];

        if (!HTPresentations)
            HTFormatInit();
        n = HTList_count(HTPresentations);

        for (i = 0; i < n; i++) {
            HTPresentation* pres = HTList_objectAt(HTPresentations, i);
            if (pres->rep_out == present) {
                if (pres->quality != 1.0) {
                    sprintf(line, "Accept: %s q=%.3f%c%c", HTAtom_name(pres->rep), pres->quality,
                            CR, LF);
                } else {
                    sprintf(line, "Accept: %s%c%c", HTAtom_name(pres->rep), CR, LF);
                }
                StrAllocCat(command, line);
            }
        }

        sprintf(line, "User-Agent:  %s/%s  libwww/%s (HTTPS)%s",
                HTAppName ? HTAppName : "unknown", HTAppVersion ? HTAppVersion : "0.0",
                HTLibraryVersion, crlf);
        StrAllocCat(command, line);

        /* Add Host: header */
        if (hostname && *hostname) {
            char* host_with_port = HTParse(arg, "", PARSE_HOST);
            sprintf(line, "Host: %s%s", host_with_port, crlf);
            StrAllocCat(command, line);
            free(host_with_port);
        }

        /* Add Connection: Keep-Alive header */
        sprintf(line, "Connection: Keep-Alive%s", crlf);
        StrAllocCat(command, line);

#ifdef ACCESS_AUTH
        if (auth != NULL) {
            sprintf(line, "%s%s", auth, crlf);
            StrAllocCat(command, line);
        }
#endif

        if (http_dataToPost) {
            sprintf(line, "Content-type: application/x-www-form-urlencoded%s", crlf);
            StrAllocCat(command, line);

            sprintf(line, "Content-length: %zu%s", strlen(http_dataToPost), crlf);
            StrAllocCat(command, line);

            StrAllocCat(command, crlf);
            StrAllocCat(command, http_dataToPost);
        }
    }

    StrAllocCat(command, crlf);

    /* Translate to ASCII if needed */
#ifdef NOT_ASCII
    {
        char* p;
        for (p = command; *p; p++) {
            *p = TOASCII(*p);
        }
    }
#endif

    /* Send request over SSL */
    status = HTSSL_write(ssl_conn, command, strlen(command));
    free(command);
    if (status < 0) {
        if (TRACE) {
            fprintf(stderr, "HTTPS: Write failed (status=%d)%s\n", 
                    status, connection_from_pool ? " on reused connection" : "");
        }
        
        if (connection_from_pool && pooled_conn) {
            /* Reused connection is broken - close it and retry with new one */
            if (TRACE) fprintf(stderr, "HTTPS: Retrying with new connection\n");
            HTSSL_close(ssl_conn);
            free(pooled_conn);
            pooled_conn = NULL;
            connection_from_pool = NO;
            goto retry;
        }
        
        HTSSL_close(ssl_conn);
        if (hostname) free(hostname);
        return HTInetStatus("SSL write");
    }

    /* Read response */
    {
        BOOL end_of_file = NO;
        HTAtom* encoding = HTAtom_for("7bit");

        binary_buffer = (char*)malloc(buffer_length * sizeof(char));
        if (!binary_buffer) {
            HTSSL_close(ssl_conn);
            if (hostname) free(hostname);
            outofmem(__FILE__, "HTLoadHTTPS");
        }
        text_buffer = (char*)malloc(buffer_length * sizeof(char));
        if (!text_buffer) {
            HTSSL_close(ssl_conn);
            if (hostname) free(hostname);
            outofmem(__FILE__, "HTLoadHTTPS");
        }
        length = 0;

        http_progress_subtotal_bytes = 0;
        if (http_progress_reporter_level == 0) {
            http_progress_total_bytes = 0;
            http_progress_expected_total_bytes = 0;
        }
        ++http_progress_reporter_level;

        do {
            if (buffer_length - length < LINE_EXTEND_THRESH) {
                buffer_length = buffer_length + buffer_length;
                binary_buffer = (char*)realloc(binary_buffer, buffer_length * sizeof(char));
                if (!binary_buffer) {
                    HTSSL_close(ssl_conn);
                    if (hostname) free(hostname);
                    outofmem(__FILE__, "HTLoadHTTPS");
                }
                text_buffer = (char*)realloc(text_buffer, buffer_length * sizeof(char));
                if (!text_buffer) {
                    HTSSL_close(ssl_conn);
                    if (hostname) free(hostname);
                    outofmem(__FILE__, "HTLoadHTTPS");
                }
            }
            
            status = HTSSL_read(ssl_conn, binary_buffer + length, buffer_length - length - 1);
            if (status < 0) {
                if (connection_from_pool && pooled_conn && length == 0) {
                    /* First read failed on reused connection - retry with new one */
                    if (TRACE) fprintf(stderr, "HTTPS: First read failed on pooled connection, retrying\n");
                    HTSSL_close(ssl_conn);
                    free(pooled_conn);
                    pooled_conn = NULL;
                    connection_from_pool = NO;
                    if (binary_buffer) free(binary_buffer);
                    if (text_buffer) free(text_buffer);
                    goto retry;
                }
                
                HTAlert("Unexpected SSL read error on response");
                HTSSL_close(ssl_conn);
                if (hostname) free(hostname);
                return status;
            }
            
            if (status > 0) {
                bytes_received += status;
            }

            if (TRACE)
                fprintf(stderr, "HTTPS: SSL read returned %d bytes (total: %d).\n", status, bytes_received);

#ifdef VIOLA
            http_progress_notify(status);
#endif

            if (status == 0) {
                end_of_file = YES;
                break;
            }
            binary_buffer[length + status] = 0;

            /* Make ASCII copy */
#ifdef NOT_ASCII
            if (TRACE)
                fprintf(stderr, "Local codes CR=%d, LF=%d\n", CR, LF);
#endif
            {
                char* p;
                char* q;
                for (p = binary_buffer + length, q = text_buffer + length; *p; p++, q++) {
                    *q = FROMASCII(*p);
                }
                *q++ = 0;
            }

            /* Check for HTTP response */
#define STUB_LENGTH 20
            if (length < STUB_LENGTH && length + status >= STUB_LENGTH) {
                if (strncmp("HTTP/", text_buffer, 5) != 0) {
                    char* p;
                    start_of_data = text_buffer;
                    for (p = binary_buffer; p < binary_buffer + STUB_LENGTH; p++) {
                        if (((int)*p) & 128) {
                            format_in = HTAtom_for("www/unknown");
                            length = length + status;
                            goto copy;
                        }
                    }
                }
            }

            eol = strchr(text_buffer + length, 10);
            if (eol) {
                *eol = 0;
                if (eol[-1] == CR)
                    eol[-1] = 0;
            }

            length = length + status;

        } while (!eol && !end_of_file);
    }

    /* Parse response line */
    if (TRACE)
        fprintf(stderr, "HTTPS: Rx: %.70s\n", text_buffer);

    {
        int fields;
        char server_version[VERSION_LENGTH + 1];

        /* Handle old HTTP/0.9 servers */
        if (extensions && 0 == strcmp(text_buffer,
                                      "Document address invalid or access not authorised")) {
            extensions = NO;
            if (binary_buffer)
                free(binary_buffer);
            if (text_buffer)
                free(text_buffer);
            if (TRACE) fprintf(stderr, "HTTPS: Retrying with HTTP0\n");
            HTSSL_close(ssl_conn);
            if (pooled_conn) {
                free(pooled_conn);
                pooled_conn = NULL;
            }
            connection_from_pool = NO;
            goto retry;
        }

        fields = sscanf(text_buffer, "%20s%d", server_version, &server_status);

        if (fields < 2 || strncmp(server_version, "HTTP/", 5) != 0) {
            format_in = WWW_HTML;
            start_of_data = text_buffer;
            if (eol)
                *eol = '\n';
        } else {
            format_in = HTAtom_for("www/mime");
            start_of_data = eol ? eol + 1 : text_buffer + length;

            /* Check if server supports keep-alive */
            {
                char* conn_header = find_header(start_of_data, "Connection");
                if (conn_header) {
                    char* p = conn_header + 11; /* Skip "Connection:" */
                    while (*p == ' ' || *p == '\t') p++;
                    if (strncasecmp(p, "Keep-Alive", 10) == 0 || 
                        strncasecmp(p, "keep-alive", 10) == 0) {
                        /* Server claims to support keep-alive */
                        /* But in HTTP/1.0 we NEED Content-Length for keep-alive to work! */
                        char* cl_check = find_header(start_of_data, "Content-Length");
                        if (cl_check) {
                            keep_alive = YES;
                            if (TRACE) fprintf(stderr, "HTTPS: Server supports keep-alive\n");
                        } else {
                            keep_alive = NO;
                            if (TRACE) fprintf(stderr, "HTTPS: Keep-Alive without Content-Length - ignoring\n");
                        }
                    }
                }
            }

            switch (server_status / 100) {
            default:
                HTAlert("Unknown status reply from server!");
                break;

            case 3: /* Various forms of redirection */
                {
                    char* location = NULL;
                    char* p;
                    
                    /* Parse Location header from response (case-insensitive) */
                    p = find_header(start_of_data, "Location");
                    
                    if (p) {
                        char new_url[2048];
                        char* end;
                        
                        /* Skip "Location:" */
                        p += 9;
                        while (*p == ' ' || *p == '\t') p++;
                        
                        /* Extract URL until newline */
                        end = strchr(p, '\r');
                        if (!end) end = strchr(p, '\n');
                        
                        if (end) {
                            int url_len = end - p;
                            if (url_len > 0 && url_len < sizeof(new_url) - 1) {
                                strncpy(new_url, p, url_len);
                                new_url[url_len] = '\0';
                                
                                /* Make absolute URL if relative */
                                location = HTParse(new_url, arg, PARSE_ALL);
                                
                                if (TRACE) {
                                    fprintf(stderr, "HTTPS: Redirect %d -> %s\n", 
                                            server_status, location);
                                }
                                
                                /* Clean up and follow redirect */
                                if (TRACE) {
                                    fprintf(stderr, "HTTPS: Redirect %d -> %s\n", server_status, location);
                                }
                                
                                /* Check if redirect is to same host - can reuse connection! */
                                char* new_hostname = HTParse(location, "", PARSE_HOST);
                                char* new_hostname_clean = NULL;
                                int new_port = 443;
                                BOOL same_host = NO;
                                
                                if (new_hostname) {
                                    char* colon = strchr(new_hostname, ':');
                                    if (colon) {
                                        *colon = '\0';
                                        new_port = atoi(colon + 1);
                                    }
                                    new_hostname_clean = strdup(new_hostname);
                                    
                                    if (hostname && strcmp(new_hostname, hostname) == 0 && new_port == port) {
                                        same_host = YES;
                                        if (TRACE) fprintf(stderr, "HTTPS: Same-host redirect\n");
                                    }
                                    
                                    free(new_hostname);
                                }
                                
                                if (binary_buffer) free(binary_buffer);
                                if (text_buffer) free(text_buffer);
                                
                                if (same_host && keep_alive && ssl_conn) {
                                    /* Return connection to pool before same-host redirect */
                                    if (TRACE) fprintf(stderr, "HTTPS: Returning connection before redirect\n");
                                    
                                    if (connection_from_pool && pooled_conn) {
                                        /* Update existing pool entry */
                                        pooled_conn->last_used = time(NULL);
                                        pooled_conn->total_requests++;
                                        pooled_conn->total_bytes += bytes_received;
                                        HTKeepAlive_returnConnection(pooled_conn);
                                    } else {
                                        /* Create new pool entry for this connection */
                                        HTConnection* conn_entry = (HTConnection*)malloc(sizeof(HTConnection));
                                        if (conn_entry) {
                                            conn_entry->hostname = strdup(hostname);
                                            conn_entry->port = port;
                                            conn_entry->socket = s;
                                            conn_entry->is_ssl = YES;
                                            conn_entry->ssl_conn = ssl_conn;
                                            conn_entry->created = time(NULL);
                                            conn_entry->last_used = conn_entry->created;
                                            conn_entry->reuse_count = 0;
                                            conn_entry->total_bytes = bytes_received;
                                            conn_entry->total_requests = 1;
                                            conn_entry->next = NULL;
                                            HTKeepAlive_returnConnection(conn_entry);
                                        }
                                    }
                                    pooled_conn = NULL;
                                    connection_from_pool = NO;
                                } else {
                                    /* Different host or no keep-alive - close connection */
                                    HTSSL_close(ssl_conn);
                                    if (pooled_conn) {
                                        free(pooled_conn);
                                        pooled_conn = NULL;
                                    }
                                    connection_from_pool = NO;
                                }
                                
                                if (hostname) free(hostname);
                                hostname = new_hostname_clean;
                                
                                redirect_count++;
                                arg = location;  /* Follow redirect */
                                
                                goto retry;
                            }
                        }
                    }
                    
                    /* If we couldn't parse Location header */
                    HTAlert("Redirection response but no Location header found");
                    if (location) free(location);
                }
                break;

            case 4:
#ifdef ACCESS_AUTH
                switch (server_status) {
                case 401:
                    length -= start_of_data - text_buffer;
                    if (HTAA_shouldRetryWithAuth(start_of_data, length, s)) {
                        if (binary_buffer)
                            free(binary_buffer);
                        if (text_buffer)
                            free(text_buffer);
                        if (TRACE) fprintf(stderr, "HTTPS: Retrying with auth\n");
                        HTSSL_close(ssl_conn);
                        if (pooled_conn) {
                            free(pooled_conn);
                            pooled_conn = NULL;
                        }
                        connection_from_pool = NO;
                        goto retry;
                        break;
                    } else {
                        /* FALL THROUGH */
                    }
                default: {
                    char* p1 = HTParse(arg, "", PARSE_HOST);
                    char* message;

                    if (!(message = (char*)malloc(strlen(text_buffer) + strlen(p1) + 100))) {
                        HTSSL_close(ssl_conn);
                        if (hostname) free(hostname);
                        outofmem(__FILE__, "HTTPS 4xx status");
                    }
                    sprintf(message, "HTTPS server at %s replies:\n%s\n\n%s\n", p1, text_buffer,
                            ((server_status == 401) ? "Access Authorization package giving up.\n"
                                                    : ""));
                    status = HTLoadError(sink, server_status, message);
                    free(message);
                    free(p1);
                    goto clean_up;
                }
                }
                goto clean_up;
                break;
#else
                /* Fall through to case 5 */
#endif

            case 5: {
                char* p1 = HTParse(arg, "", PARSE_HOST);
                char* message = (char*)malloc(strlen(text_buffer) + strlen(p1) + 100);
                if (!message) {
                    HTSSL_close(ssl_conn);
                    if (hostname) free(hostname);
                    outofmem(__FILE__, "HTTPS 5xx status");
                }
                sprintf(message, "HTTPS server at %s replies:\n%s", p1, text_buffer);
                status = HTLoadError(sink, server_status, message);
                free(message);
                free(p1);
                goto clean_up;
            }
            break;

            case 2:
                break;
            }
        }
    }

    /* Set up stream stack */
copy:
    target = HTStreamStack(format_in, format_out, sink, anAnchor);

    if (!target) {
        char buffer[1024];
        if (binary_buffer)
            free(binary_buffer);
        if (text_buffer)
            free(text_buffer);
        sprintf(buffer, "Sorry, no known way of converting %s to %s.", HTAtom_name(format_in),
                HTAtom_name(format_out));
        status = HTLoadError(sink, 501, buffer);
        goto clean_up;
    }

    if (format_in == WWW_HTML) {
        target = HTNetToText(target);
    }

    /* Check for Transfer-Encoding: chunked */
    BOOL is_chunked = NO;
    {
        char* te_header = find_header(start_of_data, "Transfer-Encoding");
        if (te_header) {
            char* p = te_header + 18;  /* Skip "Transfer-Encoding:" */
            while (*p == ' ' || *p == '\t') p++;
            if (strncasecmp(p, "chunked", 7) == 0) {
                is_chunked = YES;
                if (TRACE) fprintf(stderr, "HTTPS: Transfer-Encoding: chunked\n");
            }
        }
    }
    
    /* Parse Content-Length - CRITICAL for keep-alive! */
    /* MUST parse ALWAYS, not just when http_progress_reporter_level == 1 */
    int content_length = -1;  /* -1 means unknown */
    if (!is_chunked) {
        char* cl_header = find_header(start_of_data, "Content-Length");
        if (cl_header) {
            char* p = cl_header + 15;  /* Skip "Content-Length:" */
            while (*p == ' ' || *p == '\t') p++;  /* Skip whitespace */
            
            /* Read number */
            for (buffp = buff; *p && *p != '\r' && *p != '\n'; buffp++, p++)
                *buffp = *p;
            *buffp = '\0';
            
            content_length = atoi(buff);
            if (http_progress_reporter_level == 1) {
                http_progress_expected_total_bytes = content_length;
            }
            if (TRACE) {
                fprintf(stderr, "HTTPS: Content-Length = %d bytes\n", content_length);
            }
        } else {
            if (keep_alive) {
                if (TRACE) fprintf(stderr, "HTTPS: Keep-Alive without Content-Length - disabling\n");
                keep_alive = NO;
            }
        }
        foundContentLength = 1;
    }

    /* Strip MIME headers and copy data */
    if (server_status) {
        if (server_status / 100 == 2 && format_out == WWW_SOURCE) {
            char *sp, *end;
            char lc = '\0', llc = '\0', lllc = '\0';

            if (foundContentLength == 0 && http_progress_reporter_level == 1) {
                cp = strstr(binary_buffer, "Content-length: ");
                if (!cp)
                    cp = strstr(binary_buffer, "Content-Length: ");
                if (cp) {
                    cp += strlen("Content-length: ");
                    for (buffp = buff; *cp != '\n'; buffp++, cp++)
                        *buffp = *cp;
                    *buffp = '\0';
                    http_progress_expected_total_bytes = atoi(buff);
                }
            }

            /* Find end of headers */
            {
                sp = binary_buffer + (start_of_data - text_buffer);
                char* buffer_end = binary_buffer + length;
                while (sp < buffer_end && *sp) {
                    if (llc == '\n' && lc == '\n') {
                        offset = sp - binary_buffer - (start_of_data - text_buffer);
                        goto wheee;
                    } else if (lllc == '\n' && llc == '\r' && lc == '\n') {
                        offset = sp - binary_buffer - (start_of_data - text_buffer);
                        goto wheee;
                    }
                    lllc = llc;
                    llc = lc;
                    lc = *sp++;
                }
            }
            
            /* Continue reading to find header end */
            {
                for (;;) {
                    status = HTSSL_read(ssl_conn, binary_buffer, buffer_length - 1);
                    if (status < 0) {
                        HTAlert("Unexpected SSL read error on response");
                        HTSSL_close(ssl_conn);
                        if (hostname) free(hostname);
                        return status;
                    }
                    if (status == 0)
                        break;  /* EOF without finding end of headers */
                    sp = binary_buffer;
                    char* chunk_end = binary_buffer + status;
                    while (sp < chunk_end) {
                        if (llc == '\n' && lc == '\n') {
                            offset = sp - binary_buffer;
                            goto dofus;
                        } else if (lllc == '\n' && llc == '\r' && lc == '\n') {
                            offset = sp - binary_buffer;
                            goto dofus;
                        }
                        lllc = llc;
                        llc = lc;
                        lc = *sp++;
                    }
                }
            dofus:
                (*target->isa->put_block)(target, binary_buffer + offset, status - offset);
                bytes_received += (status - offset);
                
                /* Copy remaining data using SSL - with Content-Length awareness */
                if (is_chunked) {
                    for (;;) {
                        int chunk_bytes = read_chunked_data(ssl_conn, binary_buffer, buffer_length - 1);
                        if (chunk_bytes <= 0)
                            break;
                        bytes_received += chunk_bytes;
                        (*target->isa->put_block)(target, binary_buffer, chunk_bytes);
                    }
                } else if (content_length >= 0) {
                    int bytes_read = status - offset;
                    
                    while (bytes_read < content_length) {
                        int to_read = content_length - bytes_read;
                        if (to_read > buffer_length - 1)
                            to_read = buffer_length - 1;
                        
                        status = HTSSL_read(ssl_conn, binary_buffer, to_read);
                        if (status <= 0)
                            break;
                        bytes_received += status;
                        bytes_read += status;
                        (*target->isa->put_block)(target, binary_buffer, status);
                    }
                } else {
                    for (;;) {
                        status = HTSSL_read(ssl_conn, binary_buffer, buffer_length - 1);
                        if (status <= 0)
                            break;
                        bytes_received += status;
                        (*target->isa->put_block)(target, binary_buffer, status);
                    }
                }
                
                (*target->isa->free)(target);
                status = HT_LOADED;
                goto clean_up;
            }
        }
    }
    
wheee:
    {
        ptrdiff_t data_offset = start_of_data - text_buffer;
        ptrdiff_t remaining_length = length - data_offset - offset;
        int initial_data = (int)remaining_length;
        (*target->isa->put_block)(target, binary_buffer + data_offset + offset, initial_data);
    }
    
    /* Copy remaining data - chunked, Content-Length, or EOF */
    if (is_chunked) {
        /* Chunked transfer encoding - read chunks until size 0 */
        struct timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
        
        for (;;) {
            int chunk_bytes = read_chunked_data(ssl_conn, binary_buffer, buffer_length - 1);
            if (chunk_bytes <= 0)
                break;
            bytes_received += chunk_bytes;
            (*target->isa->put_block)(target, binary_buffer, chunk_bytes);
        }
    } else if (content_length >= 0) {
        /* We know exact length - read only what's needed */
        ptrdiff_t data_offset = start_of_data - text_buffer;
        ptrdiff_t remaining_length = length - data_offset - offset;
        int bytes_to_read = content_length - (int)remaining_length;
        int bytes_read_so_far = 0;
        
        struct timeval timeout;
        timeout.tv_sec = 60;
        timeout.tv_usec = 0;
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
        
        while (bytes_read_so_far < bytes_to_read) {
            int to_read = (bytes_to_read - bytes_read_so_far);
            if (to_read > buffer_length - 1) {
                to_read = buffer_length - 1;
            }
            
            status = HTSSL_read(ssl_conn, binary_buffer, to_read);
            if (status <= 0)
                break;
            
            bytes_received += status;
            bytes_read_so_far += status;
            (*target->isa->put_block)(target, binary_buffer, status);
        }
    } else {
        /* No Content-Length/chunked - read until EOF or timeout */
        struct timeval timeout;
        timeout.tv_sec = 60;
        timeout.tv_usec = 0;
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
        
        for (;;) {
            status = HTSSL_read(ssl_conn, binary_buffer, buffer_length - 1);
            if (status <= 0)
                break;
            bytes_received += status;
            (*target->isa->put_block)(target, binary_buffer, status);
        }
    }
    
    (*target->isa->free)(target);
    status = HT_LOADED;

clean_up:
    --http_progress_reporter_level;
    if (http_progress_reporter_level == 0) {
        http_progress_total_bytes = 0;
        http_progress_expected_total_bytes = 0;
#ifdef VIOLA
        http_progress_notify(-1);
#endif
    }
    http_progress_subtotal_bytes = 0;

    if (binary_buffer)
        free(binary_buffer);
    if (text_buffer)
        free(text_buffer);

    /* Calculate total time */
    gettimeofday(&end_time, NULL);
    total_ms = (end_time.tv_sec - start_time.tv_sec) * 1000 + 
               (end_time.tv_usec - start_time.tv_usec) / 1000;
    
    if (TRACE) {
        fprintf(stderr, "HTTPS: %d bytes in %ld ms (%.1f KB/s, connect: %ld ms)\n",
                bytes_received, total_ms, 
                total_ms > 0 ? (bytes_received / 1024.0) / (total_ms / 1000.0) : 0.0,
                connect_ms);
        fprintf(stderr, "HTTPS: %s SSL connection.\n", 
                keep_alive ? "Returning to pool" : "Closing");
    }
    
    /* Return connection to pool if keep-alive, otherwise close */
    /* ВАЖНО: делаем это ДО освобождения hostname! */
    
    if (keep_alive && status == HT_LOADED && ssl_conn && s >= 0 && hostname) {
        if (connection_from_pool && pooled_conn) {
            /* Reuse the same pooled_conn object - just update timestamp and stats */
            time_t now = time(NULL);
            long reuse_delay = now - pooled_conn->last_used;
            pooled_conn->last_used = now;
            pooled_conn->total_requests++;
            pooled_conn->total_bytes += bytes_received;
            
            HTKeepAlive_returnConnection(pooled_conn);
        } else {
            /* Create a new pool entry for a new connection */
            HTConnection* conn_entry = (HTConnection*)malloc(sizeof(HTConnection));
            if (conn_entry) {
                conn_entry->hostname = strdup(hostname);
                conn_entry->port = port;
                conn_entry->socket = s;
                conn_entry->is_ssl = YES;
                conn_entry->ssl_conn = ssl_conn;
                conn_entry->created = time(NULL);
                conn_entry->last_used = conn_entry->created;
                conn_entry->reuse_count = 0;
                conn_entry->total_bytes = bytes_received;
                conn_entry->total_requests = 1;
                conn_entry->next = NULL;
                
                /* Return to pool */
                HTKeepAlive_returnConnection(conn_entry);
            } else {
                /* Failed to create pool entry, close connection */
                HTSSL_close(ssl_conn);
            }
        }
    } else {
        /* Close connection */
        if (ssl_conn) {
            HTSSL_close(ssl_conn);
        }
        if (pooled_conn) {
            free(pooled_conn);
        }
    }
    
    /* Free hostname AFTER using it for conn_entry */
    if (hostname)
        free(hostname);

    redirect_count = 0;  /* Reset redirect counter on successful completion */
    return status;
}

/*	Protocol descriptor
*/
GLOBALDEF PUBLIC HTProtocol HTTPS = {"https", HTLoadHTTPS, 0};

#endif /* USE_SSL */

