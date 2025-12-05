/*
 * sync_multicast.c - UDP broadcast for real-time sync
 *
 * Uses UDP broadcast for instant message delivery between ViolaWWW instances.
 * All browsers listen on the same port and broadcast sync messages.
 * Messages include page hash so only matching pages process them.
 */

#include "sync_multicast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

/* External function to register socket with Xt input handler */
extern void registerSyncSocket(int fd);

/* Broadcast port for sync messages */
#define SYNC_PORT 54379

/* Message format: "VIOLA|hash|instance|seq|id|func|args" */
#define MSG_PREFIX "VIOLA"
#define MAX_MSG_SIZE 1024

/* Forward declaration */
extern void discovery_dispatch_sync(const char* id, const char* func, const char* args);

/* Module state */
static struct {
    int initialized;
    int sock_fd;
    struct sockaddr_in bcast_addr;
    unsigned int page_hash;
    unsigned int send_seq;
    unsigned int instance_id;    /* Unique ID for this browser instance */
} sync_state = {0};

/*
 * Initialize UDP broadcast socket
 */
int sync_multicast_init(void)
{
    int sock;
    int reuse = 1;
    int bcast = 1;
    int flags;
    
    if (sync_state.initialized) return 1;
    
    fprintf(stderr, "[Sync] Initializing UDP broadcast on port %d\n", SYNC_PORT);
    
    /* Create UDP socket */
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("[Sync] socket");
        return 0;
    }
    
    /* Allow multiple sockets to use same port */
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("[Sync] SO_REUSEADDR");
    }
    
#ifdef SO_REUSEPORT
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) < 0) {
        perror("[Sync] SO_REUSEPORT");
    }
#endif
    
    /* Enable broadcast */
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &bcast, sizeof(bcast)) < 0) {
        perror("[Sync] SO_BROADCAST");
    }
    
    /* Bind to receive broadcasts */
    struct sockaddr_in bind_addr;
    memset(&bind_addr, 0, sizeof(bind_addr));
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind_addr.sin_port = htons(SYNC_PORT);
    
    if (bind(sock, (struct sockaddr*)&bind_addr, sizeof(bind_addr)) < 0) {
        perror("[Sync] bind");
        close(sock);
        return 0;
    }
    
    /* Set non-blocking */
    flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags | O_NONBLOCK);
    
    /* Setup broadcast destination (255.255.255.255) */
    memset(&sync_state.bcast_addr, 0, sizeof(sync_state.bcast_addr));
    sync_state.bcast_addr.sin_family = AF_INET;
    sync_state.bcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    sync_state.bcast_addr.sin_port = htons(SYNC_PORT);
    
    sync_state.sock_fd = sock;
    sync_state.initialized = 1;
    sync_state.send_seq = 0;
    
    /* Generate unique instance ID from PID and time */
    sync_state.instance_id = (unsigned int)getpid() ^ (unsigned int)time(NULL);
    
    fprintf(stderr, "[Sync] Ready (instance %08x), fd=%d\n", sync_state.instance_id, sock);
    
    /* Register with Xt for immediate notification when data arrives */
    registerSyncSocket(sock);
    
    return 1;
}

/*
 * Set current page hash
 */
void sync_multicast_set_page(unsigned int hash)
{
    sync_state.page_hash = hash;
}

/*
 * Broadcast a sync message
 */
void sync_multicast_broadcast(const char* id, const char* func, const char* args)
{
    char msg[MAX_MSG_SIZE];
    int len;
    
    if (!sync_state.initialized || !id || !func) return;
    if (sync_state.page_hash == 0) return;
    
    sync_state.send_seq++;
    
    /* Format: VIOLA|hash|instance|seq|id|func|args */
    len = snprintf(msg, sizeof(msg), "%s|%08x|%08x|%u|%s|%s|%s",
                   MSG_PREFIX,
                   sync_state.page_hash,
                   sync_state.instance_id,
                   sync_state.send_seq,
                   id, func,
                   args ? args : "");
    
    sendto(sync_state.sock_fd, msg, len, 0,
           (struct sockaddr*)&sync_state.bcast_addr,
           sizeof(sync_state.bcast_addr));
}

/*
 * Process incoming messages
 */
void sync_multicast_process(void)
{
    char buf[MAX_MSG_SIZE];
    ssize_t len;
    struct sockaddr_in from_addr;
    socklen_t from_len;
    
    if (!sync_state.initialized) return;
    
    /* Read all available messages */
    while (1) {
        from_len = sizeof(from_addr);
        len = recvfrom(sync_state.sock_fd, buf, sizeof(buf) - 1, 0,
                       (struct sockaddr*)&from_addr, &from_len);
        
        if (len <= 0) break;
        
        buf[len] = '\0';
        
        /* Parse message: VIOLA|hash|instance|seq|id|func|args */
        char* p = buf;
        char* prefix = strsep(&p, "|");
        char* hash_str = strsep(&p, "|");
        char* inst_str = strsep(&p, "|");
        char* seq_str = strsep(&p, "|");
        char* id = strsep(&p, "|");
        char* func = strsep(&p, "|");
        char* args = p;  /* Rest is args */
        
        if (!prefix || !hash_str || !inst_str || !seq_str || !id || !func) continue;
        if (strcmp(prefix, MSG_PREFIX) != 0) continue;
        
        /* Check page hash */
        unsigned int msg_hash = (unsigned int)strtoul(hash_str, NULL, 16);
        if (msg_hash != sync_state.page_hash) continue;
        
        /* Skip our own messages */
        unsigned int msg_inst = (unsigned int)strtoul(inst_str, NULL, 16);
        if (msg_inst == sync_state.instance_id) continue;
        
        (void)seq_str;  /* Sequence number available if needed */
        
        /* Dispatch to object */
        discovery_dispatch_sync(id, func, args);
    }
}

/*
 * Get socket fd for select()
 */
int sync_multicast_get_fd(void)
{
    return sync_state.initialized ? sync_state.sock_fd : -1;
}

/*
 * Shutdown
 */
void sync_multicast_shutdown(void)
{
    if (!sync_state.initialized) return;
    
    close(sync_state.sock_fd);
    sync_state.initialized = 0;
    fprintf(stderr, "[Sync] Shutdown\n");
}
