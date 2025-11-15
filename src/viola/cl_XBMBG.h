/*
 * class        : XBMBG
 * superClass	: XBM
 */
#include "cl_XBM.h"

extern ClassInfo class_XBMBG;
long helper_XBMBG_get(VObj*, Packet*, int, Packet*, long);
long helper_XBMBG_set(VObj*, Packet*, int, Packet*, long);

long meth_XBMBG_expose(VObj *, Packet *, int, Packet *);
long meth_XBMBG_render(VObj *, Packet *, int, Packet *);
