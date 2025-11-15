/*
 * class        : txtEditLine
 * superClass	: txtEdit
 */
#include "cl_txtDisp.h"

extern ClassInfo class_txtEditLine;
long int helper_txtEditLine_get(VObj*, Packet*, int, Packet*, long);
long int helper_txtEditLine_set(VObj*, Packet*, int, Packet*, long);

long int meth_txtEditLine_get(VObj *, Packet *, int, Packet *);
long int meth_txtEditLine_initialize(VObj *, Packet *, int, Packet *);
long int meth_txtEditLine_expose(VObj *, Packet *, int, Packet *);
long int meth_txtEditLine_render(VObj *, Packet *, int, Packet *);
long int meth_txtEditLine_set(VObj *, Packet *, int, Packet *);
