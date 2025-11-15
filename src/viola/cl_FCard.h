/*
 * class        : FCard
 * superClass	: pane
 */
#include "cl_pane.h"

extern ClassInfo class_FCard;
long helper_FCard_get(VObj*, Packet*, int, Packet*, long);
long helper_FCard_set(VObj*, Packet*, int, Packet*, long);

long meth_FCard_config(VObj *, Packet *, int, Packet *);
long meth_FCard_expose(VObj *, Packet *, int, Packet *);
long meth_FCard_get(VObj *, Packet *, int, Packet *);
long meth_FCard_initialize(VObj *, Packet *, int, Packet *);
long meth_FCard_render(VObj *, Packet *, int, Packet *);
long meth_FCard_set(VObj *, Packet *, int, Packet *);
