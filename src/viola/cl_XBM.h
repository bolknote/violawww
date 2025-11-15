/*
 * class        : XBM
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_XBM;
long helper_XBM_get(VObj*, Packet*, int, Packet*, long);
long helper_XBM_set(VObj*, Packet*, int, Packet*, long);

long meth_XBM_config(VObj *, Packet *, int, Packet *);
long meth_XBM_expose(VObj *, Packet *, int, Packet *);
long meth_XBM_freeSelf(VObj *, Packet *, int, Packet *);
long meth_XBM_get(VObj *, Packet *, int, Packet *);
long meth_XBM_initialize(VObj *, Packet *, int, Packet *);
long meth_XBM_info(VObj *, Packet *, int, Packet *);
long meth_XBM_render(VObj *, Packet *, int, Packet *);
long meth_XBM_set(VObj *, Packet *, int, Packet *);
