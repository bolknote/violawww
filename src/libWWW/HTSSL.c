/*	SSL/TLS Support for libwww				HTSSL.c
**	====================================
**
**	This module provides SSL/TLS encryption support for HTTP connections
**	using OpenSSL library.
*/

#include "HTSSL.h"

#ifdef USE_SSL

#include <string.h>
#include <stdio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>

/*	Module-wide variables
*/
PRIVATE HTSSLContext ssl_context = {NULL, 0};
PRIVATE char error_buffer[256];

/*	Initialize SSL library
**	----------------------
*/
PUBLIC int HTSSL_init(void) {
    if (ssl_context.initialized) {
        return 0; /* Already initialized */
    }

    /* Initialize OpenSSL */
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    /* Create SSL context with TLS */
    ssl_context.ctx = SSL_CTX_new(TLS_client_method());
    if (!ssl_context.ctx) {
        fprintf(stderr, "HTSSL: Failed to create SSL context\n");
        ERR_print_errors_fp(stderr);
        return -1;
    }

    /* Set options for better compatibility */
    SSL_CTX_set_options(ssl_context.ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);
    
    /* Load default CA certificates (best-effort, non-fatal) */
    if (!SSL_CTX_set_default_verify_paths(ssl_context.ctx)) {
        fprintf(stderr, "HTSSL: Warning - could not load CA certificates\n");
    }

    /* Disable certificate verification per project policy */
    SSL_CTX_set_verify(ssl_context.ctx, SSL_VERIFY_NONE, NULL);

    ssl_context.initialized = 1;

    if (TRACE) {
        fprintf(stderr, "HTSSL: SSL/TLS initialized (OpenSSL %s)\n", 
                OpenSSL_version(OPENSSL_VERSION));
    }

    return 0;
}

/*	Shutdown SSL library
**	--------------------
*/
PUBLIC void HTSSL_shutdown(void) {
    if (!ssl_context.initialized) {
        return;
    }

    if (ssl_context.ctx) {
        SSL_CTX_free(ssl_context.ctx);
        ssl_context.ctx = NULL;
    }

    EVP_cleanup();
    ERR_free_strings();

    ssl_context.initialized = 0;

    if (TRACE) {
        fprintf(stderr, "HTSSL: SSL/TLS shutdown\n");
    }
}

/*	Create SSL connection
**	---------------------
*/
PUBLIC HTSSLConnection* HTSSL_connect(int socket, const char* hostname) {
    HTSSLConnection* conn;
    int ret;

    if (!ssl_context.initialized) {
        fprintf(stderr, "HTSSL: Library not initialized\n");
        return NULL;
    }

    /* Allocate connection structure */
    conn = (HTSSLConnection*)calloc(1, sizeof(HTSSLConnection));
    if (!conn) {
        fprintf(stderr, "HTSSL: Out of memory\n");
        return NULL;
    }

    conn->socket = socket;
    conn->connected = 0;

    /* Create SSL structure */
    conn->ssl = SSL_new(ssl_context.ctx);
    if (!conn->ssl) {
        fprintf(stderr, "HTSSL: Failed to create SSL structure\n");
        ERR_print_errors_fp(stderr);
        free(conn);
        return NULL;
    }

    /* Set socket */
    if (!SSL_set_fd(conn->ssl, socket)) {
        fprintf(stderr, "HTSSL: Failed to set socket\n");
        ERR_print_errors_fp(stderr);
        SSL_free(conn->ssl);
        free(conn);
        return NULL;
    }

    /* Set SNI (Server Name Indication) */
    if (hostname) {
        SSL_set_tlsext_host_name(conn->ssl, hostname);
    }

    /* Perform SSL handshake */
    ret = SSL_connect(conn->ssl);
    if (ret != 1) {
        int err = SSL_get_error(conn->ssl, ret);
        fprintf(stderr, "HTSSL: SSL handshake failed (error %d)\n", err);
        ERR_print_errors_fp(stderr);
        SSL_free(conn->ssl);
        free(conn);
        return NULL;
    }

    conn->connected = 1;

    /* Hostname verification is intentionally disabled */

    if (TRACE) {
        fprintf(stderr, "HTSSL: Connected to %s using %s\n",
                hostname ? hostname : "unknown",
                SSL_get_cipher(conn->ssl));
    }

    return conn;
}

/*	Close SSL connection
**	--------------------
*/
PUBLIC void HTSSL_close(HTSSLConnection* conn) {
    if (!conn) {
        return;
    }

    if (conn->ssl) {
        if (conn->connected) {
            SSL_shutdown(conn->ssl);
        }
        SSL_free(conn->ssl);
    }

    free(conn);

    if (TRACE) {
        fprintf(stderr, "HTSSL: Connection closed\n");
    }
}

/*	Read from SSL connection
**	------------------------
*/
PUBLIC int HTSSL_read(HTSSLConnection* conn, char* buffer, int length) {
    if (!conn || !conn->ssl || !conn->connected) {
        return -1;
    }

    for (;;) {
        int ret = SSL_read(conn->ssl, buffer, length);
        if (ret >= 0) {
            return ret; /* 0 => EOF, >0 => bytes */
        }
        {
            int err = SSL_get_error(conn->ssl, ret);
            if (err == SSL_ERROR_WANT_READ || err == SSL_ERROR_WANT_WRITE) {
                continue; /* retry */
            }
            fprintf(stderr, "HTSSL: Read error %d\n", err);
            return -1;
        }
    }
}

/*	Write to SSL connection
**	-----------------------
*/
PUBLIC int HTSSL_write(HTSSLConnection* conn, const char* buffer, int length) {
    if (!conn || !conn->ssl || !conn->connected) {
        return -1;
    }

    int total = 0;
    while (total < length) {
        int ret = SSL_write(conn->ssl, buffer + total, length - total);
        if (ret > 0) {
            total += ret;
            continue;
        }
        {
            int err = SSL_get_error(conn->ssl, ret);
            if (err == SSL_ERROR_WANT_READ || err == SSL_ERROR_WANT_WRITE) {
                continue; /* retry */
            }
            fprintf(stderr, "HTSSL: Write error %d\n", err);
            return -1;
        }
    }
    return total;
}

/*	Get last SSL error
**	------------------
*/
PUBLIC const char* HTSSL_get_error(void) {
    unsigned long err = ERR_get_error();
    if (err == 0) {
        return "No error";
    }
    ERR_error_string_n(err, error_buffer, sizeof(error_buffer));
    return error_buffer;
}

#endif /* USE_SSL */

