/*
 * discovery.h - Peer discovery API for ViolaWWW
 *
 * This module implements network peer discovery, allowing multiple ViolaWWW
 * browser instances on a local network to find each other and detect when
 * they are viewing the same web page.
 *
 * This is the foundation for implementing the SC (synchronization) attribute
 * from Pei-Yuan Wei's original 1994 proto-VRML design, which envisioned
 * multi-user shared virtual spaces where object state changes would be
 * broadcast to all viewers.
 *
 * Architecture:
 *   - discovery.h     : Platform-independent public API (this file)
 *   - discovery.c     : Dispatcher that routes to platform implementations
 *   - discovery_bonjour.c : macOS implementation using Bonjour/DNS-SD
 *   - discovery_avahi.c   : Linux implementation using Avahi (TODO)
 *
 * How it works:
 *   1. On startup, the browser registers itself as a network service
 *   2. It also browses for other ViolaWWW instances on the local network
 *   3. When navigating to a page, a hash of the URL is broadcast
 *   4. When another browser with the same URL hash is found, a match
 *      is reported (currently to console, future: enable state sync)
 *
 * Copyright 2025. Part of the ViolaWWW restoration project.
 */

#ifndef DISCOVERY_H
#define DISCOVERY_H

/*
 * discovery_enable - Enable peer discovery for the current page
 *
 * This function should be called when an SC (synchronization) attribute is
 * encountered during HTML parsing. It sets a flag indicating that the current
 * page requires peer discovery.
 *
 * Discovery is "opt-in" per page: only pages with SC attributes will trigger
 * peer discovery. This follows Pei-Yuan Wei's original proto-VRML design where
 * SC was used to mark properties for network synchronization.
 *
 * The actual initialization happens lazily when discovery_set_page() is called.
 */
void discovery_enable(void);

/*
 * discovery_reset - Reset the enabled flag for new page load
 *
 * This function should be called when starting to load a new page, before
 * HTML parsing begins. It clears the enabled flag so that discovery will
 * only be active if the new page also contains SC attributes.
 */
void discovery_reset(void);

/*
 * discovery_is_enabled - Check if discovery is enabled for current page
 *
 * Returns: 1 if discovery_enable() was called, 0 otherwise
 */
int discovery_is_enabled(void);

/*
 * discovery_init - Initialize the peer discovery service
 *
 * This function performs the actual initialization of peer discovery:
 *   - Registration of this browser instance as a discoverable service
 *   - Starting to browse for other ViolaWWW instances on the network
 *   - Setting up necessary callbacks for service events
 *
 * Normally called automatically by discovery_set_page() when needed.
 *
 * On macOS, this uses Bonjour (DNS-SD) to register a "_violawww._tcp" service.
 * On Linux, this will use Avahi (when implemented).
 * On unsupported platforms, this is a no-op that returns 0.
 *
 * Returns: 1 on success, 0 on failure or if discovery is not supported
 */
int discovery_init(void);

/*
 * discovery_set_page - Notify discovery service of current page URL
 *
 * This function should be called whenever the browser navigates to a new page.
 * It computes a hash of the URL and:
 *   - Updates the service's TXT record with the new hash
 *   - Checks if any known peers have the same hash (viewing same page)
 *   - Logs a message if a peer match is found
 *
 * The hash is computed using djb2, a simple but effective string hash function.
 * Only the hash is broadcast, not the full URL (for efficiency and privacy).
 *
 * Parameters:
 *   url - The full URL of the current page (e.g., "http://example.com/page.html")
 *         If NULL or empty, the call is ignored.
 */
void discovery_set_page(const char* url);

/*
 * discovery_process - Process pending discovery events
 *
 * This function should be called periodically from the application's event loop
 * (typically in the idle handler). It checks for and processes any pending
 * network events related to peer discovery:
 *   - New peers appearing on the network
 *   - Peers leaving the network
 *   - Peers updating their page hash (navigating to different pages)
 *
 * The function is non-blocking - it uses select() with zero timeout to check
 * for events without waiting.
 *
 * On platforms without discovery support, this is a no-op.
 */
void discovery_process(void);

/*
 * discovery_get_fd - Get file descriptor for select/poll integration
 *
 * Returns the file descriptor that can be used to integrate discovery events
 * into an external event loop using select() or poll(). When this fd becomes
 * readable, discovery_process() should be called.
 *
 * This is useful for applications that need tighter event loop integration
 * than periodic polling.
 *
 * Returns: File descriptor (>= 0) on success, -1 if not available or not supported
 */
int discovery_get_fd(void);

/*
 * discovery_shutdown - Shut down the discovery service
 *
 * This function should be called when the browser is closing. It performs:
 *   - Deregistration of this browser instance from the network
 *   - Cleanup of browsing sessions and callbacks
 *   - Release of any allocated resources
 *
 * After calling this function, discovery_init() must be called again
 * before using any other discovery functions.
 */
void discovery_shutdown(void);

/*
 * discovery_get_hash - Get the current page URL hash
 *
 * Returns the djb2 hash of the current page URL. This is primarily useful
 * for debugging and testing to verify that the correct hash is being
 * broadcast.
 *
 * Returns: The 32-bit hash value, or 0 if no page has been set
 */
unsigned int discovery_get_hash(void);

/*
 * discovery_supported - Check if discovery is available on this platform
 *
 * Returns whether peer discovery is supported and functional on the current
 * platform. This can be used to conditionally enable/disable discovery-related
 * UI elements or features.
 *
 * Returns: 1 if discovery is supported, 0 otherwise
 */
int discovery_supported(void);

/* ============================================================================
 * Synchronization API - for broadcasting and receiving state changes
 * ============================================================================
 */

/*
 * discovery_broadcast - Broadcast a state change to peers
 *
 * Called when an SC-enabled property changes locally. Broadcasts the change
 * to all peers viewing the same page via mDNS TXT record update.
 *
 * Parameters:
 *   id   - Object ID (e.g., "myRect")
 *   func - Function/message name (e.g., "setRotZ")
 *   args - Arguments as pipe-separated string (e.g., "45.5" or "1.0|2.0")
 *
 * The broadcast format in TXT record is: "SEQ:N|id|func|args"
 */
void discovery_broadcast(const char* id, const char* func, const char* args);

/*
 * discovery_begin_remote - Mark start of remote message processing
 *
 * Called before dispatching a received sync message to an object.
 * Sets a flag so that handlers know not to re-broadcast the change.
 */
void discovery_begin_remote(void);

/*
 * discovery_end_remote - Mark end of remote message processing
 *
 * Called after dispatching a received sync message.
 * Clears the remote processing flag.
 */
void discovery_end_remote(void);

/*
 * discovery_is_remote - Check if currently processing a remote message
 *
 * Used by object handlers to determine if a property change originated
 * from the network (remote) or from local user interaction.
 *
 * Returns: 1 if processing remote message, 0 if local
 */
int discovery_is_remote(void);

/*
 * discovery_get_seq - Get current sequence number
 *
 * Returns the current broadcast sequence number for debugging.
 *
 * Returns: Current sequence number
 */
unsigned int discovery_get_seq(void);

#endif /* DISCOVERY_H */
