/*
 * sync_multicast.h - UDP multicast for real-time sync
 *
 * Uses UDP multicast for instant message delivery between ViolaWWW instances.
 * All browsers join a multicast group and broadcast/receive sync messages.
 * Messages include page hash so only matching pages process them.
 */

#ifndef SYNC_MULTICAST_H
#define SYNC_MULTICAST_H

/*
 * Initialize multicast socket and join group.
 * Returns 1 on success, 0 on failure.
 */
int sync_multicast_init(void);

/*
 * Set current page hash for filtering incoming messages.
 */
void sync_multicast_set_page(unsigned int hash);

/*
 * Broadcast a sync message to all peers.
 * Only peers with matching page hash will process it.
 * Format: id=object name, func=function to call, args=pipe-separated arguments
 */
void sync_multicast_broadcast(const char* id, const char* func, const char* args);

/*
 * Process incoming multicast messages (non-blocking).
 * Call this from the main event loop.
 */
void sync_multicast_process(void);

/*
 * Get socket fd for external select() integration.
 * Returns -1 if not initialized.
 */
int sync_multicast_get_fd(void);

/*
 * Shutdown multicast.
 */
void sync_multicast_shutdown(void);

#endif /* SYNC_MULTICAST_H */

