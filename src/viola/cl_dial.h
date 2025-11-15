/*
 * class        : dial
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_dial;
long helper_dial_get(VObj*, Packet*, int, Packet*, long);
long helper_dial_set(VObj*, Packet*, int, Packet*, long);

long meth_dial_config(VObj *, Packet *, int, Packet *);
long meth_dial_expose(VObj *, Packet *, int, Packet *);
long meth_dial_get(VObj *, Packet *, int, Packet *);
long meth_dial_initialize(VObj *, Packet *, int, Packet *);
long meth_dial_render(VObj *, Packet *, int, Packet *);
long meth_dial_set(VObj *, Packet *, int, Packet *);
