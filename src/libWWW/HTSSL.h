/*	SSL/TLS Support for libwww - Header			HTSSL.h
**	====================================
**
**	This module provides SSL/TLS encryption support for HTTP connections
**	using OpenSSL library.
**
** Authors:
**	Added for ViolaWWW HTTPS support - 2025
*/

#ifndef HTSSL_H
#define HTSSL_H

#include "HTUtils.h"

#ifdef USE_SSL

#include <openssl/ssl.h>
#include <openssl/err.h>

/*	SSL Context and Connection Structures
*/
typedef struct _HTSSLContext {
    SSL_CTX* ctx;
    int initialized;
} HTSSLContext;

typedef struct _HTSSLConnection {
    SSL* ssl;
    int socket;
    int connected;
} HTSSLConnection;

/*	Initialize SSL library
**	----------------------
**	Must be called once at program startup
**
** On exit:
**	returns	0	Success
**		-1	Error
*/
extern int HTSSL_init(void);

/*	Shutdown SSL library
**	--------------------
**	Call at program exit
*/
extern void HTSSL_shutdown(void);

/*	Create SSL connection
**	---------------------
**	Wraps a regular socket with SSL
**
** On entry:
**	socket	Connected TCP socket
**	hostname	Server hostname (for SNI)
**
** On exit:
**	returns	Pointer to SSL connection structure, or NULL on error
*/
extern HTSSLConnection* HTSSL_connect(int socket, const char* hostname);

/*	Close SSL connection
**	--------------------
**
** On entry:
**	conn	SSL connection to close
*/
extern void HTSSL_close(HTSSLConnection* conn);

/*	Read from SSL connection
**	------------------------
**	Similar to read()/recv()
**
** On entry:
**	conn	SSL connection
**	buffer	Buffer to read into
**	length	Maximum bytes to read
**
** On exit:
**	returns	Number of bytes read, or -1 on error
*/
extern int HTSSL_read(HTSSLConnection* conn, char* buffer, int length);

/*	Write to SSL connection
**	-----------------------
**	Similar to write()/send()
**
** On entry:
**	conn	SSL connection
**	buffer	Data to write
**	length	Number of bytes to write
**
** On exit:
**	returns	Number of bytes written, or -1 on error
*/
extern int HTSSL_write(HTSSLConnection* conn, const char* buffer, int length);

/*	Get last SSL error
**	------------------
**
** On exit:
**	returns	Error string
*/
extern const char* HTSSL_get_error(void);

#endif /* USE_SSL */

#endif /* HTSSL_H */

