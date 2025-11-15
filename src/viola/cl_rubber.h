/*
 * class        : rubber
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_rubber;
long int helper_rubber_get(VObj*, Packet*, int, Packet*, long);
long int helper_rubber_set(VObj*, Packet*, int, Packet*, long);

long meth_rubber_config(VObj *, Packet *, int, Packet *);
long meth_rubber_get(VObj *, Packet *, int, Packet *);
long meth_rubber_initialize(VObj *, Packet *, int, Packet *);
long meth_rubber_render(VObj *, Packet *, int, Packet *);
long meth_rubber_set(VObj *, Packet *, int, Packet *);
