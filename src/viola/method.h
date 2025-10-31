#ifndef VOBJ_DEFINED
#define VOBJ_DEFINED
typedef long VObj;
#endif

/* Ensure Packet type is visible to prototypes */
#include "packet.h"

/* Strong prototypes for 64-bit safety */
extern long callMeth(VObj* self, Packet* result, int argc, Packet argv[], long funcid);
extern long findMeth(VObj* self, long funcid);
