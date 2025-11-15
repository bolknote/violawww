/*
 * class        : toggle
 * superClass	: XBM
 */
#include "cl_XBM.h"

extern ClassInfo class_toggle;
long helper_toggle_get(VObj*, Packet*, int, Packet*, long);
long helper_toggle_set(VObj*, Packet*, int, Packet*, long);

long meth_toggle_get(VObj *, Packet *, int, Packet *);
long meth_toggle_render(VObj *, Packet *, int, Packet *);
long meth_toggle_set(VObj *, Packet *, int, Packet *);
long meth_toggle_toggle(VObj *, Packet *, int, Packet *);
