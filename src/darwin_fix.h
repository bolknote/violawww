/* darwin_fix.h - Workarounds for macOS compilation issues */
#ifndef DARWIN_FIX_H
#define DARWIN_FIX_H

#ifdef __APPLE__
/* Prevent duplicate definitions of byte order functions */
#define _I386__OSBYTEORDER_H_
#define _ARM__OSBYTEORDER_H_

/* Include the actual byte order functions once */
#include <libkern/OSByteOrder.h>

/* Mark as already included to prevent re-inclusion */
#define _OSBYTEORDER_H

#endif /* __APPLE__ */

#endif /* DARWIN_FIX_H */
