/*		Wayback Machine (Internet Archive) Integration		HTWayback.c
**		==============================================
**
**	This module provides integration with the Internet Archive's
**	Wayback Machine for accessing archived versions of websites.
*/

#include "HTWayback.h"
#include "HTParse.h"
#include "HTTCP.h"
#include "HTUtils.h"
#include "tcp.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

/* External UI function - defined in viola code */
extern void showHelpMessageInMainWindow(char* message) __attribute__((weak));

/* Parse chunked encoding from buffer (not from socket!) */
PRIVATE char* parse_chunked_body ARGS2(char*, chunked_data, int*, out_len) {
    char* result = (char*)malloc(8192);
    char* src = chunked_data;
    int total = 0;
    
    if (!result) {
        *out_len = 0;
        return NULL;
    }
    
    if (TRACE) fprintf(stderr, "Wayback: Parsing chunked body from buffer\n");
    
    while (*src) {
        /* Read chunk size (hex) until \r\n */
        char size_str[32];
        int i = 0;
        while (*src && *src != '\r' && i < 31) {
            size_str[i++] = *src++;
        }
        size_str[i] = '\0';
        
        /* Skip \r\n */
        if (*src == '\r') src++;
        if (*src == '\n') src++;
        
        /* Parse hex size */
        int chunk_size = (int)strtol(size_str, NULL, 16);
        if (TRACE) fprintf(stderr, "Wayback: Chunk size: %d (0x%s)\n", chunk_size, size_str);
        
        if (chunk_size == 0) {
            if (TRACE) fprintf(stderr, "Wayback: Got final chunk\n");
            break;  /* Last chunk */
        }
        
        /* Copy chunk data */
        if (total + chunk_size < 8192) {
            memcpy(result + total, src, chunk_size);
            total += chunk_size;
            src += chunk_size;
        } else {
            if (TRACE) fprintf(stderr, "Wayback: Chunk too large, buffer full\n");
            break;
        }
        
        /* Skip trailing \r\n after chunk data */
        if (*src == '\r') src++;
        if (*src == '\n') src++;
    }
    
    result[total] = '\0';
    *out_len = total;
    if (TRACE) fprintf(stderr, "Wayback: Total dechunked data: %d bytes\n", total);
    return result;
}

/* Helper to safely call UI update function (same way as html2.c does) */
PRIVATE void safe_show_message(const char* message) {
#ifdef VIOLA
    extern void* mesgObj;  /* VObj* but we don't want to include viola.h */
    if (!mesgObj) {
        /* Try to find message object */
        extern void* findObject(int);
        extern int getIdent(const char*);
        mesgObj = findObject(getIdent("www.mesg.tf"));
    }
    if (mesgObj) {
        extern int sendMessage1N1str(void*, const char*, char*);
        sendMessage1N1str(mesgObj, "show", (char*)message);
    }
#else
    /* Fallback for non-Viola builds */
    if (showHelpMessageInMainWindow) {
        showHelpMessageInMainWindow((char*)message);
    }
#endif
}

#define WAYBACK_API_HOST "web.archive.org"
#define WAYBACK_API_PORT 80
#define WAYBACK_API_TIMEOUT 5 /* seconds */

/*	Check if URL is available in Wayback Machine
**	---------------------------------------------
**
**  Uses the Wayback Availability API to check if a snapshot exists
*/
PUBLIC char* HTWaybackCheck PARAMS((CONST char* url)) {
    int s = -1;
    SockA soc_address;
    SockA* sin = &soc_address;
    char* request = NULL;
    char* response_buffer = NULL;
    char* wayback_url = NULL;
    int status;
    int response_len = 0;
    int total_read = 0;
    char* url_encoded = NULL;
    char* timestamp_start = NULL;
    char* url_start = NULL;
    char* p;
    int i;

    if (!url || !*url) {
        return NULL;
    }

    if (TRACE) fprintf(stderr, "Wayback: Checking URL: %s\n", url);
    
    /* Show status message */
    safe_show_message("Searching in Web Archive...");

    /* CDX API accepts full URLs as-is: url=http://www.example.com/path
    ** We only need to URL-encode characters that would break the query string
    ** Keep protocol, slashes, colons as-is - they're valid in query parameters
    */
    url_encoded = (char*)malloc(strlen(url) * 3 + 1);
    if (!url_encoded) {
        return NULL;
    }

    /* Minimal URL encoding - only encode what's truly problematic */
    {
        CONST char* src = url;
        char* dst = url_encoded;
        while (*src) {
            if (*src == ' ') {
                *dst++ = '+';
            } else if (*src == '&') {
                strcpy(dst, "%26");
                dst += 3;
            } else if (*src == '#') {
                strcpy(dst, "%23");
                dst += 3;
            } else {
                /* Keep everything else as-is, including : / ? */
                *dst++ = *src;
            }
            src++;
        }
        *dst = '\0';
    }
    
    /* Set up socket address for archive.org */
    memset(sin, 0, sizeof(*sin));
    sin->sin_family = AF_INET;
    sin->sin_port = htons(WAYBACK_API_PORT);

    /* Resolve archive.org hostname */
    {
        struct hostent* phost;
        char msg[256];
        
        sprintf(msg, "DNS resolve: %s", WAYBACK_API_HOST);
        safe_show_message(msg);
        
        phost = gethostbyname(WAYBACK_API_HOST);
        if (!phost) {
            if (TRACE) fprintf(stderr, "Wayback: DNS resolution failed\n");
            safe_show_message("Web Archive: DNS resolution failed");
            free(url_encoded);
            return NULL;
        }
        if (TRACE) fprintf(stderr, "Wayback: Resolved to IP\n");
        memcpy(&sin->sin_addr, phost->h_addr, phost->h_length);
    }

    /* Create socket - EXPLICITLY in blocking mode */
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s < 0) {
        if (TRACE) fprintf(stderr, "Wayback: Cannot create socket (errno=%d)\n", errno);
        free(url_encoded);
        return NULL;
    }
    
    /* Ensure socket is in BLOCKING mode */
    {
        int flags = fcntl(s, F_GETFL, 0);
        if (flags & O_NONBLOCK) {
            fcntl(s, F_SETFL, flags & ~O_NONBLOCK);
        }
    }
    
    /* Set socket timeout - CDX API can take 20+ seconds to respond */
    {
        struct timeval timeout;
        timeout.tv_sec = 30;  /* CDX API needs ~20 seconds */
        timeout.tv_usec = 0;
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
        setsockopt(s, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    }

    /* Connect to archive.org */
    safe_show_message("Connecting to Web Archive...");
    
    status = connect(s, (struct sockaddr*)sin, sizeof(*sin));
    if (status < 0) {
        if (TRACE) fprintf(stderr, "Wayback: Connection failed (errno=%d)\n", errno);
        safe_show_message("Web Archive: Connection failed");
        close(s);
        free(url_encoded);
        return NULL;
    }
    if (TRACE) fprintf(stderr, "Wayback: Connected to %s:%d\n", WAYBACK_API_HOST, WAYBACK_API_PORT);

    /* Build HTTP request for Wayback CDX API (get EARLIEST snapshot) */
    request =
        (char*)malloc(strlen(url_encoded) + 512); /* Extra space for HTTP headers and path */
    if (!request) {
        close(s);
        free(url_encoded);
        return NULL;
    }

    sprintf(request,
            "GET /cdx/search/cdx?url=%s&limit=1&sort=ascending HTTP/1.1\r\n"
            "Host: %s\r\n"
            "User-Agent: ViolaWWW/4.0 (Wayback)\r\n"
            "Connection: close\r\n"
            "\r\n",
            url_encoded, WAYBACK_API_HOST);

    /* Send request */
    safe_show_message("Querying Web Archive database...");
    
    if (TRACE) {
        fprintf(stderr, "Wayback: Querying CDX API for %s\n", url_encoded);
    }
    
    status = NETWRITE(s, request, strlen(request));
    free(request);
    free(url_encoded);
    if (status < 0) {
        if (TRACE) fprintf(stderr, "Wayback: Query failed (status=%d)\n", status);
        safe_show_message("Web Archive: Query failed");
        close(s);
        return NULL;
    }
    if (TRACE) fprintf(stderr, "Wayback: Query sent\n");

    /* Read response */
    safe_show_message("Reading Web Archive response...");
    
    response_buffer = (char*)malloc(8192); /* Should be enough for JSON response */
    if (!response_buffer) {
        close(s);
        return NULL;
    }

    total_read = 0;
    int read_attempts = 0;
    while (total_read < 8191) {
        response_len = NETREAD(s, response_buffer + total_read, 8191 - total_read);
        read_attempts++;
        
        if (response_len < 0) {
            if (TRACE) fprintf(stderr, "Wayback: Read error: errno=%d (%s)\n", errno, strerror(errno));
            break;
        }
        if (response_len == 0) {
            break;  /* EOF */
        }
        
        total_read += response_len;
    }
    response_buffer[total_read] = '\0';
    close(s);

    if (total_read == 0) {
        if (TRACE) fprintf(stderr, "Wayback: No response received\n");
        free(response_buffer);
        return NULL;
    }
    if (TRACE) fprintf(stderr, "Wayback: Received %d bytes\n", total_read);

    /* Parse CDX text response to get EARLIEST snapshot
    ** CDX returns simple space-separated format (default, not JSON):
    ** urlkey timestamp original mimetype statuscode digest length
    ** Example:
    ** ru,hackzone)/ 19970327140651 http://www.hackzone.ru:80/ text/html 200 7ZWL... 564
    **
    ** We need fields [1]=timestamp and [2]=original
    */

    /* Check if response uses chunked encoding */
    BOOL is_chunked = NO;
    if (strstr(response_buffer, "Transfer-Encoding: chunked") || 
        strstr(response_buffer, "transfer-encoding: chunked")) {
        is_chunked = YES;
        if (TRACE) fprintf(stderr, "Wayback: Response uses chunked encoding\n");
    }
    
    /* Skip HTTP headers - find empty line (double newline) */
    char* body = NULL;
    {
        body = strstr(response_buffer, "\r\n\r\n");
        if (!body) {
            body = strstr(response_buffer, "\n\n");
        }
        if (!body) {
            if (TRACE) fprintf(stderr, "Wayback: Cannot find end of HTTP headers\n");
            free(response_buffer);
            return NULL;
        }
        body += 4; /* Skip past \r\n\r\n */
        if (*body == '\n') body++; /* Skip extra newline if present */
    }
    
    /* If chunked, parse the chunks from the buffer we already read */
    if (is_chunked) {
        int dechunked_len = 0;
        char* dechunked_body = parse_chunked_body(body, &dechunked_len);
        
        if (!dechunked_body || dechunked_len == 0) {
            if (TRACE) fprintf(stderr, "Wayback: Failed to parse chunked body\n");
            free(response_buffer);
            if (dechunked_body) free(dechunked_body);
            return NULL;
        }
        
        /* Replace response_buffer with dechunked data */
        free(response_buffer);
        response_buffer = dechunked_body;
        body = response_buffer;
        
        /* Parse space-separated fields */
        {
            char timestamp[32] = {0};
            char original_url[512] = {0};
            char* field_start = body;
            char* field_end;
            int field_index = 0;

            /* Parse first 3 fields: urlkey timestamp original */
            while (*field_start && field_index < 3) {
                /* Skip leading whitespace */
                while (*field_start == ' ' || *field_start == '\t' || *field_start == '\r' || *field_start == '\n') {
                    field_start++;
                }
                
                if (*field_start == '\0') break;

                /* Find end of field (space, tab, or newline) */
                field_end = field_start;
                while (*field_end && *field_end != ' ' && *field_end != '\t' && *field_end != '\r' && *field_end != '\n') {
                    field_end++;
                }

                /* Extract field */
                if (field_index == 1) {
                    /* timestamp */
                    int len = field_end - field_start;
                    if (len > 0 && len < 32) {
                        strncpy(timestamp, field_start, len);
                        timestamp[len] = '\0';
                    }
                } else if (field_index == 2) {
                    /* original URL */
                    int len = field_end - field_start;
                    if (len > 0 && len < 512) {
                        strncpy(original_url, field_start, len);
                        original_url[len] = '\0';
                    }
                }

                field_start = field_end;
                field_index++;
            }

            /* Check if we got both timestamp and original URL */
            if (timestamp[0] == '\0' || original_url[0] == '\0') {
                if (TRACE) fprintf(stderr, "Wayback: No snapshots found in response\n");
                safe_show_message("Web Archive: No archived versions found");
                free(response_buffer);
                return NULL;
            }
            
            if (TRACE) fprintf(stderr, "Wayback: Found snapshot: %s for %s\n", timestamp, original_url);

            /* Construct Wayback URL with EARLIEST timestamp */
            wayback_url = (char*)malloc(strlen(original_url) + 128);
            if (!wayback_url) {
                free(response_buffer);
                return NULL;
            }
            sprintf(wayback_url, "https://web.archive.org/web/%s/%s", timestamp, original_url);
            
            /* Show success message with date */
            {
                char msg[256];
                char date_str[32];
                /* Format timestamp YYYYMMDDHHMMSS to readable format */
                if (strlen(timestamp) >= 8) {
                    sprintf(date_str, "%.4s-%.2s-%.2s", timestamp, timestamp+4, timestamp+6);
                    sprintf(msg, "Found in Web Archive (snapshot from %s)", date_str);
                } else {
                    sprintf(msg, "Found in Web Archive, loading...");
                }
                safe_show_message(msg);
            }
        }
    }

    free(response_buffer);

    if (TRACE) fprintf(stderr, "Wayback: Generated URL: %s\n", wayback_url);

    return wayback_url;
}

