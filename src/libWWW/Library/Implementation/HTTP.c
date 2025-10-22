/*	HyperText Tranfer Protocol	- Client implementation		HTTP.c
**	==========================
**
** Status:
**	Implemented:
**		✓ Redirection (3xx status codes with Location header)
**		✓ Error handling (4xx and 5xx status codes)
**		✓ Web Archive fallback (DNS failures)
**
**	Not implemented:
**		Forward/Proxy support
*/

/*	Module parameters:
**	-----------------
**
**  These may be undefined and redefined by syspec.h
*/

/*	MOSAIC_HACK2 is a kludge to guess the file type of trabsferred
**	file from the URL.  It is STRICTLY illegal to do this!
*/

/* Implements:
 */
#include "HTTP.h"
#include "HTWayback.h"
#include "HTKeepAlive.h"
#include <stddef.h>
#include <unistd.h>
#include <sys/time.h>

/* Forward declarations */
extern void http_progress_notify();

#define HTTP_VERSION "HTTP/1.0"
#define HTTP2 /* Version is greater than 0.9 */

#define INIT_LINE_SIZE 1024    /* Start with line buffer this big */
#define LINE_EXTEND_THRESH 256 /* Minimum read size */
#define VERSION_LENGTH 20      /* for returned protocol version */

int http_method = HTTP_METHOD_GET;
char* http_dataToPost = NULL;

/* Uses:
 */
#include "HTAABrow.h" /* Access Authorization */
#include "HTAlert.h"
#include "HTFormat.h"
#include "HTInit.h" /* SCW */
#include "HTMIME.h"
#include "HTML.h" /* SCW */
#include "HTParse.h"
#include "HTTCP.h"
#include "HTUtils.h"
#include "tcp.h"
#include <ctype.h>

struct _HTStream {
    HTStreamClass* isa; /* all we need to know */
};

extern char* HTAppName;    /* Application name: please supply */
extern char* HTAppVersion; /* Application version: please supply */

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

/*		Load Document from HTTP Server			HTLoadHTTP()
**		==============================
**
**	Given a hypertext address, this routine loads a document.
**
**
** On entry,
**	arg	is the hypertext reference of the article to be loaded.
**	gate	is nill if no gateway, else the gateway address.
**
** On exit,
**	returns	>=0	If no error, a good socket number
**		<0	Error.
**
**	The socket must be closed by the caller after the document has been
**	read.
**
*/
PUBLIC int HTLoadHTTP ARGS4(CONST char*, arg,
                            /*	CONST char *,		gate, */
                            HTParentAnchor*, anAnchor, HTFormat, format_out, HTStream*, sink) {
    int s;                   /* Socket number for returned data */
    char* command;           /* The whole command */
    char* eol = 0;           /* End of line if found */
    char* start_of_data;     /* Start of body of reply */
    int length;              /* Number of valid bytes in buffer */
    int status;              /* tcp return */
    char crlf[3];            /* A CR LF equivalent string */
    HTStream* target = NULL; /* Unconverted data */
    HTFormat format_in;      /* Format arriving in the message */
    char* auth = NULL;       /* Authorization information */

    CONST char* gate = 0; /* disable this feature */
    SockA soc_address;    /* Binary network address */
    SockA* sin = &soc_address;
    BOOL had_header = NO; /* Have we had at least one header? */
    char* text_buffer = NULL;
    char* binary_buffer = NULL;
    int buffer_length = INIT_LINE_SIZE; /* Why not? */
    BOOL extensions = YES;              /* Assume good HTTP server */
    int server_status = 0;
    ptrdiff_t offset = 0;  /* Changed from int to ptrdiff_t for 64-bit safety */

    int tries = 0;
    static int redirect_count = 0;  /* Track redirect depth */
    #define MAX_REDIRECTS 10
    
    HTConnection* pooled_conn = NULL;  /* Connection from pool */
    BOOL connection_from_pool = NO;
    BOOL keep_alive = NO;  /* Server supports keep-alive */
    char* hostname = NULL;
    int port = 80;  /* Default HTTP port */
    
    /* Performance monitoring */
    struct timeval start_time, end_time, connect_time;
    long connect_ms = 0, total_ms = 0;
    int bytes_received = 0;
    
    gettimeofday(&start_time, NULL);

    extern int http_progress_expected_total_bytes; /*PYW*/
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
        return -3; /* Bad if no name sepcified	*/
    if (!*arg)
        return -2; /* Bad if name had zero length	*/

/*  Set up defaults:
 */
#ifdef DECNET
    sin->sdn_family = AF_DECnet; /* Family = DECnet, host order */
    sin->sdn_objnum = DNP_OBJ;   /* Default: http object number */
#else                            /* Internet */
    sin->sin_family = AF_INET;       /* Family = internet, host order */
    sin->sin_port = htons(TCP_PORT); /* Default: http port    */
#endif

    sprintf(crlf, "%c%c", CR, LF); /* To be corect on Mac, VM, etc */

    if (TRACE) {
        if (gate)
            fprintf(stderr, "HTTPAccess: Using gateway %s for %s\n", gate, arg);
        else
            fprintf(stderr, "HTTPAccess: Direct access for %s\n", arg);
    }

    /* Get node name and optional port number:
     */
    {
        char* p1 = HTParse(gate ? gate : arg, "", PARSE_HOST);
        int status = HTParseInet(sin, p1); /* TBL 920622 */
        
        /* Extract hostname and port for connection pooling */
        if (p1) {
            char* colon = strchr(p1, ':');
            if (colon) {
                *colon = '\0';
                port = atoi(colon + 1);
            }
            hostname = strdup(p1);
        }
        
        free(p1);
        if (status) {
            if (hostname) free(hostname);
            return status; /* No such host - let caller handle Wayback */
        }
    }

retry:

    /* Check redirect limit */
    if (redirect_count >= MAX_REDIRECTS) {
        redirect_count = 0;
        HTAlert("Too many redirects");
        return -1;
    }

/*
** Compose authorization information (this was moved here
** from after the making of the connection so that the connection
** wouldn't have to wait while prompting username and password
** from the user).				-- AL 13.10.93
*/
#ifdef ACCESS_AUTH
#define FREE(x)                                                                                    \
    if (x) {                                                                                       \
        free(x);                                                                                   \
        x = NULL;                                                                                  \
    }
{
    char* docname;
    char* hostname;
    char* colon;
    int portnumber;

    docname = HTParse(arg, "", PARSE_PATH);
    hostname = HTParse((gate ? gate : arg), "", PARSE_HOST);
    if (hostname && NULL != (colon = strchr(hostname, ':'))) {
        *(colon++) = '\0'; /* Chop off port number */
        portnumber = atoi(colon);
    } else
        portnumber = 80;

    auth = HTAA_composeAuth(hostname, portnumber, docname);

    if (TRACE) {
        if (auth)
            fprintf(stderr, "HTTP: Sending authorization: %s\n", auth);
        else
            fprintf(stderr, "HTTP: Not sending authorization (yet)\n");
    }
    FREE(hostname);
    FREE(docname);
}
#endif /* ACCESS_AUTH */

    /* Try to get connection from pool */
    pooled_conn = HTKeepAlive_getConnection(hostname, port, NO);
    
    if (pooled_conn) {
        /* Reuse existing connection */
        s = pooled_conn->socket;
        connection_from_pool = YES;
        
        fprintf(stderr, "*** HTTP: REUSING keep-alive connection to %s:%d (saved TCP handshake!)\n", hostname, port);
        gettimeofday(&connect_time, NULL);
        connect_ms = 0; /* No connection time for reused connections */
    } else {
        /*	Now, let's get a socket set up from the server for the data:
         */
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
            fprintf(stderr, "HTTP: Connecting to %s:%d...\n", hostname, port);
        }
        
        status = connect(s, (struct sockaddr*)&soc_address, sizeof(soc_address));
        if (status < 0) {
            if (TRACE) {
                fprintf(stderr, "HTTP: Connection failed (errno=%d)\n", errno);
            }
            if (hostname) free(hostname);
            /* free(command);   BUG OUT TBL 921121 */
            return HTInetStatus("connect");
        }
        
        gettimeofday(&connect_time, NULL);
        connect_ms = (connect_time.tv_sec - start_time.tv_sec) * 1000 + 
                     (connect_time.tv_usec - start_time.tv_usec) / 1000;
    }

    /*	Ask that node for the document,
    **	omitting the host name & anchor if not gatewayed.
    */
    if (gate) {
        command = malloc(4 + strlen(arg) + 2 + 31);
        if (command == NULL)
            outofmem(__FILE__, "HTLoadHTTP");

        /*PYW*/
        if (http_method == HTTP_METHOD_POST)
            strcpy(command, "POST ");
        else
            strcpy(command, "GET");

        strcat(command, arg);
    } else { /* not gatewayed */
        char* p1 = HTParse(arg, "", PARSE_PATH | PARSE_PUNCTUATION);
        command = malloc(4 + strlen(p1) + 2 + 31);
        if (command == NULL)
            outofmem(__FILE__, "HTLoadHTTP");

        /*PYW*/
        if (http_method == HTTP_METHOD_POST)
            strcpy(command, "POST ");
        else
            strcpy(command, "GET ");

        strcat(command, p1);
        free(p1);
    }
#ifdef HTTP2
    if (extensions) {
        strcat(command, " ");
        strcat(command, HTTP_VERSION);
    }
#endif

    strcat(command, crlf); /* CR LF, as in rfc 977 */

    if (extensions) {

        int n;
        int i;
        HTAtom* present = WWW_PRESENT;
        char line[256]; /*@@@@ */

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

        sprintf(line, "User-Agent:  %s/%s  libwww/%s (modified)%s",
                HTAppName ? HTAppName : "unknown", HTAppVersion ? HTAppVersion : "0.0",
                HTLibraryVersion, crlf);
        StrAllocCat(command, line);

        /* Add Host: header (required by many modern servers, even for HTTP/1.0) */
        {
            char* hostname = HTParse(arg, "", PARSE_HOST);
            if (hostname && *hostname) {
                sprintf(line, "Host: %s%s", hostname, crlf);
                StrAllocCat(command, line);
            }
            if (hostname)
                free(hostname);
        }

        /* Add Connection: Keep-Alive header */
        sprintf(line, "Connection: Keep-Alive%s", crlf);
        StrAllocCat(command, line);

#ifdef ACCESS_AUTH
        if (auth != NULL) {
            sprintf(line, "%s%s", auth, crlf);
            StrAllocCat(command, line);
        }
#endif /* ACCESS_AUTH */

        if (http_dataToPost) { /*PYW -- this is kludgy */
            sprintf(line, "Content-type: application/x-www-form-urlencoded%s", crlf);
            StrAllocCat(command, line);

            sprintf(line, "Content-length: %d%s", strlen(http_dataToPost), crlf);
            StrAllocCat(command, line);

            StrAllocCat(command, crlf); /* Blank line means "end" */

            StrAllocCat(command, http_dataToPost);
        }
    }

    StrAllocCat(command, crlf); /* Blank line means "end" */

/*	Translate into ASCII if necessary
 */
#ifdef NOT_ASCII
    {
        char* p;
        for (p = command; *p; p++) {
            *p = TOASCII(*p);
        }
    }
#endif

    status = NETWRITE(s, command, strlen(command));
    free(command);
    if (status < 0) {
        return HTInetStatus("send");
    }

    /*	Read the first line of the response
    **	-----------------------------------
    **
    **	HTTP0 servers must return ASCII style text, though it can in
    **	principle be just text without any markup at all.
    **	Full HTTP servers must return a response
    **	line and RFC822 style header.  The response must therefore in
    **	either case have a CRLF somewhere soon.
    **
    **	This is the theory.  In practice, there are (1993) unfortunately
    **	many binary documents just served up with HTTP0.9.  This
    **	means we have to preserve the binary buffer (on the assumption that
    **	conversion from ASCII may lose information) in case it turns
    **	out that we want the binary original.
    */

    {

        /* Get numeric status etc */

        BOOL end_of_file = NO;
        HTAtom* encoding = HTAtom_for("7bit");

        binary_buffer = (char*)malloc(buffer_length * sizeof(char));
        if (!binary_buffer)
            outofmem(__FILE__, "HTLoadHTTP");
        text_buffer = (char*)malloc(buffer_length * sizeof(char));
        if (!text_buffer)
            outofmem(__FILE__, "HTLoadHTTP");
        length = 0;

        http_progress_subtotal_bytes = 0;
        if (http_progress_reporter_level == 0) { /*PYW*/
            http_progress_total_bytes = 0;
            http_progress_expected_total_bytes = 0;
        }
        ++http_progress_reporter_level;

        do { /* Loop to read in the first line */

            /* Extend line buffer if necessary for those crazy WAIS URLs ;-) */

            if (buffer_length - length < LINE_EXTEND_THRESH) {
                buffer_length = buffer_length + buffer_length;
                binary_buffer = (char*)realloc(binary_buffer, buffer_length * sizeof(char));
                if (!binary_buffer)
                    outofmem(__FILE__, "HTLoadHTTP");
                text_buffer = (char*)realloc(text_buffer, buffer_length * sizeof(char));
                if (!text_buffer)
                    outofmem(__FILE__, "HTLoadHTTP");
            }
            status = NETREAD(s, binary_buffer + length, buffer_length - length - 1);
            if (status < 0) {
                HTAlert("Unexpected network read error on response");
                NETCLOSE(s);
                return status;
            }
            
            if (status > 0) {
                bytes_received += status;
            }

            if (TRACE)
                fprintf(stderr, "HTTP: read returned %d bytes (total: %d).\n", status, bytes_received);

#ifdef VIOLA /* KLUDGE ALERT */
            http_progress_notify(status);
#endif

            if (status == 0) {
                end_of_file = YES;
                break;
            }
            binary_buffer[length + status] = 0;

/*	Make an ASCII *copy* of the buffer
 */
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

/* Kludge to trap binary responses from illegal HTTP0.9 servers.
** First time we have enough, look at the stub in ASCII
** and get out of here if it doesn't look right.
**
** We also check for characters above 128 in the first few bytes, and
** if we find them we forget the html default.
**
** Bugs: A HTTP0.9 server returning a document starting "HTTP/"
**	will be taken as a HTTP 1.0 server.  Failure.
**	An HTTP 0.9 server returning a binary document with
**	characters < 128 will be read as ASCII.
*/
#define STUB_LENGTH 20
            if (length < STUB_LENGTH && length + status >= STUB_LENGTH) {
                if (strncmp("HTTP/", text_buffer, 5) != 0) {
                    char* p;
                    start_of_data = text_buffer; /* reparse whole reply */
                    for (p = binary_buffer; p < binary_buffer + STUB_LENGTH; p++) {
                        if (((int)*p) & 128) {
                            format_in = HTAtom_for("www/unknown");
                            length = length + status;
                            goto copy; /* out of while loop */
                        }
                    }
                }
            }
            /* end kludge */

            eol = strchr(text_buffer + length, 10);
            if (eol) {
                *eol = 0; /* Terminate the line */
                if (eol[-1] == CR)
                    eol[-1] = 0; /* Chop trailing CR */
                                 /* = corrected to ==  -- AL  */
            }

            length = length + status;

        } while (!eol && !end_of_file); /* No LF */
    } /* Scope of loop variables */

    /*	We now have a terminated unfolded line. Parse it.
    **	-------------------------------------------------
    */

    if (TRACE)
        fprintf(stderr, "HTTP: Rx: %.70s\n", text_buffer);

    {
        int fields;
        char server_version[VERSION_LENGTH + 1];

        /* Kludge to work with old buggy servers.  They can't handle the third word
        ** so we try again without it.
        */
        if (extensions && 0 == strcmp(text_buffer, /* Old buggy server? */
                                      "Document address invalid or access not authorised")) {
            extensions = NO;
            if (binary_buffer)
                free(binary_buffer);
            if (text_buffer)
                free(text_buffer);
            if (TRACE)
                fprintf(stderr, "HTTP: close socket %d to retry with HTTP0\n", s);
            NETCLOSE(s);
            goto retry; /* @@@@@@@@@@ */
        }
        /* end kludge */

        fields = sscanf(text_buffer, "%20s%d", server_version, &server_status);

        if (fields < 2 || strncmp(server_version, "HTTP/", 5) != 0) { /* HTTP0 reply */
            format_in = WWW_HTML;
            start_of_data = text_buffer; /* reread whole reply */
            if (eol)
                *eol = '\n'; /* Reconstitute buffer */

        } else { /* Full HTTP reply */

            /*	Decode full HTTP response */

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
                            fprintf(stderr, "+++ HTTP: Server %s:%d SUPPORTS keep-alive (has Content-Length)!\n", hostname, port);
                        } else {
                            keep_alive = NO;
                            fprintf(stderr, "--- HTTP: Server says Keep-Alive but NO Content-Length (HTTP/1.0 violation) - ignoring\n");
                        }
                    }
                } else {
                    fprintf(stderr, "--- HTTP: No Connection header from %s:%d - will close\n", hostname, port);
                }
            }

            switch (server_status / 100) {

            default: /* bad number */
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
                                    fprintf(stderr, "HTTP: Redirect %d -> %s\n", 
                                            server_status, location);
                                }
                                
                                /* Clean up and follow redirect */
                                if (binary_buffer) free(binary_buffer);
                                if (text_buffer) free(text_buffer);
                                NETCLOSE(s);
                                
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

            case 4: /* Access Authorization problem */
#ifdef ACCESS_AUTH
                switch (server_status) {
                case 401:
                    length -= start_of_data - text_buffer;
                    if (HTAA_shouldRetryWithAuth(start_of_data, length, s)) {
                        /* Clean up before retrying */
                        if (binary_buffer)
                            free(binary_buffer);
                        if (text_buffer)
                            free(text_buffer);
                        if (TRACE)
                            fprintf(stderr, "%s %d %s\n", "HTTP: close socket", s,
                                    "to retry with Access Authorization");
                        (void)NETCLOSE(s);
                        goto retry;
                        break;
                    } else {
                        /* FALL THROUGH */
                    }
                default: {
                    char* p1 = HTParse(gate ? gate : arg, "", PARSE_HOST);
                    char* message;

                    if (!(message = (char*)malloc(strlen(text_buffer) + strlen(p1) + 100)))
                        outofmem(__FILE__, "HTTP 4xx status");
                    sprintf(message, "HTTP server at %s replies:\n%s\n\n%s\n", p1, text_buffer,
                            ((server_status == 401) ? "Access Authorization package giving up.\n"
                                                    : ""));
                    status = HTLoadError(sink, server_status, message);
                    free(message);
                    free(p1);
                    goto clean_up;
                }
                } /* switch */
                goto clean_up;
                break;
#else
                /* case 4 without Access Authorization falls through */
                /* to case 5 (previously "I think I goofed").  -- AL */
#endif /* ACCESS_AUTH */

            case 5: /* I think you goofed */
                {
                    char* p1 = HTParse(gate ? gate : arg, "", PARSE_HOST);
                    char* message = (char*)malloc(strlen(text_buffer) + strlen(p1) + 100);
                    if (!message)
                        outofmem(__FILE__, "HTTP 5xx status");
                    sprintf(message, "HTTP server at %s replies:\n%s", p1, text_buffer);
                    status = HTLoadError(sink, server_status, message);
                    free(message);
                    free(p1);
                    goto clean_up;
                }
                break;

            case 2: /* Good: Got MIME object */
                /*printf("XXXXXXXXX retrying to read header text_buffer={%s}\n",
                      text_buffer);
                */
                /* don't exit until the whole header is read */
                /*		if (strstr(text_buffer, "\n\n")) break;
                                if (strstr(text_buffer, "\n\r\n")) break;
                                if (tries++ < 3) goto retry;
                */
                break;
            } /* switch on response code */

        } /* Full HTTP reply */

    } /* scope of fields */

    /*	Set up the stream stack to handle the body of the message
     */

copy:
    target = HTStreamStack(format_in, format_out, sink, anAnchor);

    if (!target) {
        char buffer[1024]; /* @@@@@@@@ */
        if (binary_buffer)
            free(binary_buffer);
        if (text_buffer)
            free(text_buffer);
        sprintf(buffer, "Sorry, no known way of converting %s to %s.", HTAtom_name(format_in),
                HTAtom_name(format_out));
        status = HTLoadError(sink, 501, buffer);
        goto clean_up;
    }

    /*	Push the data down the stream
    **	We have to remember the end of the first buffer we just read
    */
    if (format_in == WWW_HTML) {
        target = HTNetToText(target); /* Pipe through CR stripper */
    }

    /* Parse Content-Length - CRITICAL for keep-alive! */
    /* MUST parse ALWAYS, not just when http_progress_reporter_level == 1 */
    int content_length = -1;  /* -1 means unknown */
    {
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
        } else {
            if (keep_alive) {
                keep_alive = NO;
            }
        }
        foundContentLength = 1;
    }

#ifdef WRONG
    http_progress_subtotal_bytes = 0;
    if (server_status && http_progress_reporter_level == 0) { /*PYW*/
        http_progress_total_bytes = 0;
        http_progress_expected_total_bytes = 0;

        if (server_status / 100 == 2) {
            char* sp = binary_buffer + (start_of_data - text_buffer);
            char lc = '\0', llc = '\0', lllc = '\0';
            for (;;) {
                if (*sp == delim[delimi]) {
                    if (++delimi >= delimSize) {
                        for (i = 0, j = strchr(sp, '\n') - sp; i < j; i++)
                            delimBuf[i] = *(sp + i);
                        delimBuf[i] = '\0';
                        http_progress_expected_total_bytes = atoi(delimBuf);
                        delimi = 0;
                        break;
                    }
                } else
                    delimi = 0;
                if (llc == '\n' && lc == '\n') {
                    break;
                } else if (lllc == '\n' && llc == '\r' && lc == '\n') {
                    break;
                }
                lllc = llc;
                llc = lc;
                lc = *sp++;
            }
        }
    }
#endif
    /* strip MIME headers */
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
            {
                for (;;) {
                    status = NETREAD(s, binary_buffer, buffer_length - 1);
                    if (status < 0) {
                        HTAlert("Unexpected network read error on response");
                        NETCLOSE(s);
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
                HTCopy(s, target);
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
    
    /* Copy remaining data - use Content-Length if available */
    if (content_length >= 0) {
        /* We know exact length - read only what's needed */
        ptrdiff_t data_offset = start_of_data - text_buffer;
        ptrdiff_t remaining_length = length - data_offset - offset;
        int bytes_to_read = content_length - (int)remaining_length;
        int bytes_read_so_far = 0;
        
        /* Keep 60s timeout for Content-Length reads */
        
        while (bytes_read_so_far < bytes_to_read) {
            int to_read = (bytes_to_read - bytes_read_so_far);
            if (to_read > buffer_length - 1) {
                to_read = buffer_length - 1;
            }
            
            status = NETREAD(s, binary_buffer, to_read);
            if (status <= 0) {
                break;
            }
            
            bytes_received += status;
            bytes_read_so_far += status;
            (*target->isa->put_block)(target, binary_buffer, status);
        }
    } else {
        /* No Content-Length - read until EOF with 60s timeout */
        HTCopy(s, target);
    }
    
    (*target->isa->free)(target);
    status = HT_LOADED;

    /*	Clean up
     */

clean_up:
    --http_progress_reporter_level;
    if (http_progress_reporter_level == 0) {
        http_progress_total_bytes = 0;
        http_progress_expected_total_bytes = 0;
#ifdef VIOLA                      /* KLUDGE ALERT */
        http_progress_notify(-1); /* to say "it's done" */
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

    if (TRACE)
        fprintf(stderr, "HTTP: %s connection.\n", 
                keep_alive ? "Returning to pool" : "Closing");
    
    /* Return connection to pool if keep-alive, otherwise close */
    /* ВАЖНО: делаем это ДО освобождения hostname! */
    if (keep_alive && status == HT_LOADED && s >= 0 && hostname) {
        if (connection_from_pool && pooled_conn) {
            /* Reuse the same pooled_conn object - just update timestamp and stats */
            time_t now = time(NULL);
            long reuse_delay = now - pooled_conn->last_used;
            pooled_conn->last_used = now;
            pooled_conn->total_requests++;
            pooled_conn->total_bytes += bytes_received;
            
            HTKeepAlive_returnConnection(pooled_conn);
            
            fprintf(stderr, "<<< Keep-Alive: Returned REUSED connection to pool (was idle %ld sec)\n", reuse_delay);
            fprintf(stderr, "    This request: %d bytes in %ld ms\n", bytes_received, total_ms);
        } else {
            /* Create a new pool entry for a new connection */
            HTConnection* conn_entry = (HTConnection*)malloc(sizeof(HTConnection));
            if (conn_entry) {
                conn_entry->hostname = strdup(hostname);
                conn_entry->port = port;
                conn_entry->socket = s;
                conn_entry->is_ssl = NO;
#ifdef USE_SSL
                conn_entry->ssl_conn = NULL;
#endif
                conn_entry->created = time(NULL);
                conn_entry->last_used = conn_entry->created;
                conn_entry->reuse_count = 0;
                conn_entry->total_bytes = bytes_received;
                conn_entry->total_requests = 1;
                conn_entry->next = NULL;
                
                /* Return to pool */
                HTKeepAlive_returnConnection(conn_entry);
                fprintf(stderr, "    Initial request: %d bytes in %ld ms\n", bytes_received, total_ms);
            } else {
                /* Failed to create pool entry, close connection */
                (void)NETCLOSE(s);
            }
        }
    } else {
        /* Close connection */
        (void)NETCLOSE(s);
        if (pooled_conn) {
            /* Connection came from pool but we're not reusing it */
            free(pooled_conn);
        }
    }
    
    /* Free hostname AFTER using it for conn_entry */
    if (hostname)
        free(hostname);

    redirect_count = 0;  /* Reset redirect counter on successful completion */
    return status; /* Good return */
}

/*	Protocol descriptor
 */

GLOBALDEF PUBLIC HTProtocol HTTP = {"http", HTLoadHTTP, 0};
