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

int SLBellVolume(int percent) {
    XBell(display, percent);
    return percent;
}

int SLBell(void) {
    XBell(display, 0);
    XFlush(display);
    return 0;
}
