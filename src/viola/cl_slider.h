/*
 * class        : slider
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_slider;
long helper_slider_get(VObj*, Packet*, int, Packet*, long);
long helper_slider_set(VObj*, Packet*, int, Packet*, long);

long meth_slider_config(VObj *, Packet *, int, Packet *);
long meth_slider_processMouseInput(VObj *, Packet *, int, Packet *);
long meth_slider_drawLine(VObj *, Packet *, int, Packet *);
long meth_slider_drawText(VObj *, Packet *, int, Packet *);
long meth_slider_get(VObj *, Packet *, int, Packet *);
long meth_slider_initialize(VObj *, Packet *, int, Packet *);
long meth_slider_info(VObj *, Packet *, int, Packet *);
long meth_slider_render(VObj *, Packet *, int, Packet *);
long meth_slider_set(VObj *, Packet *, int, Packet *);
