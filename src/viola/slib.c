/*
 * Sound Library
 *
 * well, what can I say... we're just not there yet.
 */
#include "error.h"
#include "file.h"
#include "glib.h"
#include "hash.h"
#include "ident.h"
#include "mystrings.h"
#include "obj.h"
#include "slotaccess.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

#ifdef __APPLE__
/* Implemented in slib_darwin.c using AudioToolbox */
extern void SLBell_Darwin(void);
extern int SLBellVolume_Darwin(int percent);
#endif

int SLBellVolume(int percent) {
#ifdef __APPLE__
    return SLBellVolume_Darwin(percent);
#else
    XBell(display, percent);
    return percent;
#endif
}

int SLBell(void) {
#ifdef __APPLE__
    SLBell_Darwin();
#else
    XBell(display, 0);
    XFlush(display);
#endif
    return 0;
}
