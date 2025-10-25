/*	HTTP/HTTPS Keep-Alive Connection Pool			HTKeepAlive.h
**	========================================
**
**	This module manages persistent HTTP/HTTPS connections to improve
**	performance by reusing TCP/SSL connections instead of opening
**	a new connection for each request.
**
**	Author: Generated for ViolaWWW2
*/

#ifndef HTKEEPALIVE_H
#define HTKEEPALIVE_H

#include "HTUtils.h"
#include "tcp.h"

#ifdef USE_SSL
#include "HTSSL.h"
#endif

/* Connection pool entry */
typedef struct _HTConnection {
    char* hostname;              /* Hostname (for matching) */
    int port;                    /* Port number */
    int socket;                  /* Socket file descriptor */
    time_t last_used;            /* Last used timestamp */
    time_t created;              /* When connection was created */
    BOOL is_ssl;                 /* Is this an SSL connection? */
#ifdef USE_SSL
    HTSSLConnection* ssl_conn;   /* SSL connection object */
#endif
    /* Statistics */
    int reuse_count;             /* Number of times reused */
    long total_bytes;            /* Total bytes transferred */
    long total_requests;         /* Total requests made */
    struct _HTConnection* next;  /* Next in list */
} HTConnection;

/* Initialize the connection pool */
extern void HTKeepAlive_init NOPARAMS;

/* Clean up and close all connections in pool */
extern void HTKeepAlive_cleanup NOPARAMS;

/* Get a connection from the pool (returns NULL if none available) */
extern HTConnection* HTKeepAlive_getConnection PARAMS((
    CONST char* hostname,
    int port,
    BOOL is_ssl
));

/* Return a connection to the pool for reuse */
extern void HTKeepAlive_returnConnection PARAMS((
    HTConnection* conn
));

/* Close and remove a connection from the pool */
extern void HTKeepAlive_closeConnection PARAMS((
    HTConnection* conn
));

/* Close expired connections (older than max_age seconds) */
extern void HTKeepAlive_closeExpired PARAMS((
    int max_age
));

#endif /* HTKEEPALIVE_H */

