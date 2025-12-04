/*
 * vw_stubs.c
 *
 * Stub implementations of vw functions for standalone viola binary
 * (without the vw Motif interface).
 */

#include <stddef.h>

/* Stub for docViews - not available in standalone viola */
void* docViews = NULL;

/* Stub for isURLInHistory - always returns 0 (not visited) */
int isURLInHistory(void* dvi, char* url) {
    (void)dvi;
    (void)url;
    return 0;
}

/* Stub for compareDocViewCloneID - not used in standalone */
int compareDocViewCloneID(void* vkey, void* vdata) {
    (void)vkey;
    (void)vdata;
    return 0;
}

