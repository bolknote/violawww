/*
 * class        : menu
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_menu;
long helper_menu_get(VObj*, Packet*, int, Packet*, long);
long helper_menu_set(VObj*, Packet*, int, Packet*, long);

long meth_menu_config(VObj *, Packet *, int, Packet *);
long meth_menu_freeSelf(VObj *, Packet *, int, Packet *);
long meth_menu_get(VObj *, Packet *, int, Packet *);
long meth_menu_initialize(VObj *, Packet *, int, Packet *);
long meth_menu_processMouseInput(VObj *, Packet *, int, Packet *);
long meth_menu_render(VObj *, Packet *, int, Packet *);
long meth_menu_set(VObj *, Packet *, int, Packet *);
