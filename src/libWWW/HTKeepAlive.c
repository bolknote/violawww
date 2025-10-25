/*	HTTP/HTTPS Keep-Alive Connection Pool			HTKeepAlive.c
**	========================================
**
**	This module manages persistent HTTP/HTTPS connections to improve
**	performance by reusing TCP/SSL connections instead of opening
**	a new connection for each request.
*/

#include "HTKeepAlive.h"
#include "HTUtils.h"
#include "tcp.h"
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifdef USE_SSL
#include "HTSSL.h"
#endif

/* Maximum number of connections to keep alive */
#define MAX_KEEPALIVE_CONNECTIONS 6

/* Maximum idle time before closing connection (seconds) */
#define MAX_IDLE_TIME 30

/* Head of connection pool linked list */
PRIVATE HTConnection* connection_pool = NULL;

/* Number of connections currently in pool */
PRIVATE int pool_size = 0;

/*	Initialize the connection pool
**	------------------------------
*/
PUBLIC void HTKeepAlive_init NOPARAMS {
    connection_pool = NULL;
    pool_size = 0;
    
    if (TRACE) {
        fprintf(stderr, "HTKeepAlive: Pool initialized (max=%d, timeout=%ds)\n",
                MAX_KEEPALIVE_CONNECTIONS, MAX_IDLE_TIME);
    }
}

/*	Clean up and close all connections in pool
**	------------------------------------------
*/
PUBLIC void HTKeepAlive_cleanup NOPARAMS {
    HTConnection* conn = connection_pool;
    HTConnection* next;
    
    while (conn) {
        next = conn->next;
        
        if (TRACE) {
            fprintf(stderr, "HTKeepAlive: Closing connection to %s:%d\n", 
                    conn->hostname, conn->port);
        }
        
#ifdef USE_SSL
        if (conn->is_ssl && conn->ssl_conn) {
            HTSSL_close(conn->ssl_conn);
        } else
#endif
        if (conn->socket >= 0) {
            close(conn->socket);
        }
        
        if (conn->hostname) {
            free(conn->hostname);
        }
        free(conn);
        
        conn = next;
    }
    
    connection_pool = NULL;
    pool_size = 0;
}

/*	Get a connection from the pool
**	------------------------------
**	Returns NULL if no matching connection is available
*/
PUBLIC HTConnection* HTKeepAlive_getConnection ARGS3(
    CONST char*, hostname,
    int, port,
    BOOL, is_ssl
) {
    HTConnection* conn = connection_pool;
    HTConnection* prev = NULL;
    
    if (!hostname) return NULL;
    
    /* Search for matching connection */
    while (conn) {
        if (conn->port == port && 
            conn->is_ssl == is_ssl &&
            conn->hostname &&
            strcmp(conn->hostname, hostname) == 0) {
            
            /* Found a match - remove from pool */
            if (prev) {
                prev->next = conn->next;
            } else {
                connection_pool = conn->next;
            }
            pool_size--;
            
            /* Test if connection is still alive */
            /* We do this by trying a non-blocking read */
            char test_byte;
            int flags = fcntl(conn->socket, F_GETFL, 0);
            fcntl(conn->socket, F_SETFL, flags | O_NONBLOCK);
            int result = recv(conn->socket, &test_byte, 1, MSG_PEEK);
            fcntl(conn->socket, F_SETFL, flags);
            
            if (result == 0 || (result < 0 && errno != EAGAIN && errno != EWOULDBLOCK)) {
                /* Connection closed by server */
                if (TRACE) {
                    fprintf(stderr, "HTKeepAlive: Stale connection to %s:%d discarded\n",
                            hostname, port);
                }
#ifdef USE_SSL
                if (conn->is_ssl && conn->ssl_conn) {
                    HTSSL_close(conn->ssl_conn);
                } else
#endif
                if (conn->socket >= 0) {
                    close(conn->socket);
                }
                if (conn->hostname) free(conn->hostname);
                free(conn);
                return NULL;
            }
            
            /* Update statistics */
            conn->reuse_count++;
            
            if (TRACE) {
                fprintf(stderr, "HTKeepAlive: Reusing %s connection to %s:%d (reuse #%d)\n",
                        conn->is_ssl ? "HTTPS" : "HTTP", hostname, port, conn->reuse_count);
            }
            
            conn->next = NULL;
            return conn;
        }
        
        prev = conn;
        conn = conn->next;
    }
    
    return NULL; /* No matching connection found */
}

/*	Return a connection to the pool for reuse
**	-----------------------------------------
*/
PUBLIC void HTKeepAlive_returnConnection ARGS1(
    HTConnection*, conn
) {
    if (!conn) return;
    
    /* Close expired connections to make room */
    HTKeepAlive_closeExpired(MAX_IDLE_TIME);
    
    /* If pool is full, close oldest connection */
    if (pool_size >= MAX_KEEPALIVE_CONNECTIONS) {
        HTConnection* oldest = connection_pool;
        HTConnection* prev = NULL;
        HTConnection* current = connection_pool;
        HTConnection* oldest_prev = NULL;
        time_t oldest_time = time(NULL);
        
        /* Find oldest connection */
        while (current) {
            if (current->last_used < oldest_time) {
                oldest_time = current->last_used;
                oldest = current;
                oldest_prev = prev;
            }
            prev = current;
            current = current->next;
        }
        
        /* Remove oldest */
        if (oldest) {
            if (oldest_prev) {
                oldest_prev->next = oldest->next;
            } else {
                connection_pool = oldest->next;
            }
            
            if (TRACE) {
                fprintf(stderr, "HTKeepAlive: Pool full, closing oldest connection to %s:%d\n",
                        oldest->hostname, oldest->port);
            }
            
#ifdef USE_SSL
            if (oldest->is_ssl && oldest->ssl_conn) {
                HTSSL_close(oldest->ssl_conn);
            } else
#endif
            if (oldest->socket >= 0) {
                close(oldest->socket);
            }
            if (oldest->hostname) free(oldest->hostname);
            free(oldest);
            pool_size--;
        }
    }
    
    /* Add connection to pool */
    conn->last_used = time(NULL);
    conn->next = connection_pool;
    connection_pool = conn;
    pool_size++;
    
    if (TRACE) {
        time_t now = time(NULL);
        long age = now - conn->created;
        fprintf(stderr, "HTKeepAlive: Stored %s connection to %s:%d (reuses=%d, requests=%ld, bytes=%ld, age=%lds, pool=%d/%d)\n",
                conn->is_ssl ? "HTTPS" : "HTTP", conn->hostname, conn->port,
                conn->reuse_count, conn->total_requests, conn->total_bytes, age,
                pool_size, MAX_KEEPALIVE_CONNECTIONS);
    }
}

/*	Close and remove a connection from the pool
**	-------------------------------------------
*/
PUBLIC void HTKeepAlive_closeConnection ARGS1(
    HTConnection*, conn
) {
    if (!conn) return;
    
    if (TRACE) {
        fprintf(stderr, "HTKeepAlive: Closing connection to %s:%d\n",
                conn->hostname ? conn->hostname : "unknown", conn->port);
    }
    
#ifdef USE_SSL
    if (conn->is_ssl && conn->ssl_conn) {
        HTSSL_close(conn->ssl_conn);
    } else
#endif
    if (conn->socket >= 0) {
        close(conn->socket);
    }
    
    if (conn->hostname) {
        free(conn->hostname);
    }
    free(conn);
}

/*	Close expired connections
**	-------------------------
*/
PUBLIC void HTKeepAlive_closeExpired ARGS1(
    int, max_age
) {
    HTConnection* conn = connection_pool;
    HTConnection* prev = NULL;
    HTConnection* next;
    time_t now = time(NULL);
    
    while (conn) {
        next = conn->next;
        
        if (now - conn->last_used > max_age) {
            /* Remove from pool */
            if (prev) {
                prev->next = next;
            } else {
                connection_pool = next;
            }
            pool_size--;
            
            if (TRACE) {
                fprintf(stderr, "HTKeepAlive: Closing expired connection to %s:%d\n",
                        conn->hostname, conn->port);
            }
            
#ifdef USE_SSL
            if (conn->is_ssl && conn->ssl_conn) {
                HTSSL_close(conn->ssl_conn);
            } else
#endif
            if (conn->socket >= 0) {
                close(conn->socket);
            }
            if (conn->hostname) free(conn->hostname);
            free(conn);
        } else {
            prev = conn;
        }
        
        conn = next;
    }
}

