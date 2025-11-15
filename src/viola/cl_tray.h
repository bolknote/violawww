/*
 * class        : tray
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_tray;
long helper_tray_get(VObj*, Packet*, int, Packet*, long);
long helper_tray_set(VObj*, Packet*, int, Packet*, long);

long meth_tray_config(VObj *, Packet *, int, Packet *);
long meth_tray_get(VObj *, Packet *, int, Packet *);
long meth_tray_initialize(VObj *, Packet *, int, Packet *);
long meth_tray_render(VObj *, Packet *, int, Packet *);
long meth_tray_set(VObj *, Packet *, int, Packet *);
