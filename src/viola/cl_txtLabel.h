/*
 * class        : txtLabel
 * superClass	: txt
 */
#include "cl_txt.h"

extern ClassInfo class_txtLabel;
long int helper_txtLabel_get(VObj*, Packet*, int, Packet*, long);
long int helper_txtLabel_set(VObj*, Packet*, int, Packet*, long);

long int meth_txtLabel_config(VObj *, Packet *, int, Packet *);
long int meth_txtLabel_get(VObj *, Packet *, int, Packet *);
long int meth_txtLabel_initialize(VObj *, Packet *, int, Packet *);
long int meth_txtLabel_render(VObj *, Packet *, int, Packet *);
long int meth_txtLabel_set(VObj *, Packet *, int, Packet *);
