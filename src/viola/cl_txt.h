/*
 * class        : txt
 * superClass	: pane
 */
#include "cl_pane.h"

extern ClassInfo class_txt;
long helper_txt_get(VObj*, Packet*, int, Packet*, long);
long helper_txt_set(VObj*, Packet*, int, Packet*, long);

long meth_txt_clone(VObj *, Packet *, int, Packet *);
long meth_txt_clone2(VObj *, Packet *, int, Packet *);
long meth_txt_config(VObj *, Packet *, int, Packet *);
long meth_txt_expose(VObj *, Packet *, int, Packet *);
long meth_txt_freeSelf(VObj *, Packet *, int, Packet *);
long meth_txt_get(VObj *, Packet *, int, Packet *);
long meth_txt_initialize(VObj *, Packet *, int, Packet *);
long meth_txt_render(VObj *, Packet *, int, Packet *);
long meth_txt_set(VObj *, Packet *, int, Packet *);
