/*
 * class        : XPM
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_XPM;
long helper_XPM_get(VObj*, Packet*, int, Packet*, long);
long helper_XPM_set(VObj*, Packet*, int, Packet*, long);

long meth_XPM_config(VObj *, Packet *, int, Packet *);
long meth_XPM_freeSelf(VObj *, Packet *, int, Packet *);
long meth_XPM_get(VObj *, Packet *, int, Packet *);
long meth_XPM_initialize(VObj *, Packet *, int, Packet *);
long meth_XPM_info(VObj *, Packet *, int, Packet *);
long meth_XPM_render(VObj *, Packet *, int, Packet *);
long meth_XPM_set(VObj *, Packet *, int, Packet *);
