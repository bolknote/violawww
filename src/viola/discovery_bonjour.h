/*
 * discovery_bonjour.h - Bonjour/DNS-SD implementation for macOS
 *
 * This is the macOS-specific implementation of the peer discovery API.
 * It uses Apple's DNS Service Discovery (DNS-SD) framework, commonly
 * known as Bonjour, to provide zero-configuration networking.
 *
 * This header is internal - external code should use discovery.h instead.
 *
 * Implementation details:
 *   - Service type: "_violawww._tcp" (registered with IANA-style naming)
 *   - TXT record contains: hash=<8-digit hex>, url=<truncated URL>
 *   - Uses DNSServiceRegister for service announcement
 *   - Uses DNSServiceBrowse for peer discovery
 *   - Uses DNSServiceResolve to get peer TXT records
 *
 * Thread safety:
 *   - All functions must be called from the main thread
 *   - DNS-SD callbacks are delivered on the main thread via process()
 *
 * Copyright 2025. Part of the ViolaWWW restoration project.
 */

#ifndef DISCOVERY_BONJOUR_H
#define DISCOVERY_BONJOUR_H

#ifdef __APPLE__

/*
 * Initialize Bonjour service registration and browsing.
 * Registers this browser as "_violawww._tcp" and starts browsing for peers.
 * Returns: 1 on success, 0 on failure
 */
int discovery_bonjour_init(void);

/*
 * Update the current page URL hash in the service's TXT record.
 * Also checks existing peers for matching hashes.
 */
void discovery_bonjour_set_page(const char* url);

/*
 * Process pending DNS-SD events (non-blocking).
 * Should be called from the event loop idle handler.
 */
void discovery_bonjour_process(void);

/*
 * Get the file descriptor for the browse service.
 * Can be used with select() for tighter event loop integration.
 * Returns: fd >= 0 on success, -1 if not initialized
 */
int discovery_bonjour_get_fd(void);

/*
 * Shut down Bonjour services and release resources.
 * Deregisters the service and stops browsing.
 */
void discovery_bonjour_shutdown(void);

/*
 * Get the current URL hash value.
 * Returns: 32-bit djb2 hash, or 0 if no page set
 */
unsigned int discovery_bonjour_get_hash(void);

/*
 * Broadcast a sync message to peers via TXT record update.
 * Format: sync=SEQ:N|id|func|args
 */
void discovery_bonjour_broadcast(const char* id, const char* func, const char* args);

/*
 * Get the current broadcast sequence number.
 */
unsigned int discovery_bonjour_get_seq(void);

#endif /* __APPLE__ */

#endif /* DISCOVERY_BONJOUR_H */
