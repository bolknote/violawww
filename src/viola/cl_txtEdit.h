/*
 * class        : txtEdit
 * superClass	: txtDisp
 */
#include "cl_txtDisp.h"

extern ClassInfo class_txtEdit;
long int helper_txtEdit_get(VObj*, Packet*, int, Packet*, long);
long int helper_txtEdit_set(VObj*, Packet*, int, Packet*, long);

long int meth_txtEdit_get(VObj *, Packet *, int, Packet *);
long int meth_txtEdit_initialize(VObj *, Packet *, int, Packet *);
long int meth_txtEdit_expose(VObj *, Packet *, int, Packet *);
long int meth_txtEdit_render(VObj *, Packet *, int, Packet *);
long int meth_txtEdit_set(VObj *, Packet *, int, Packet *);
