/*
 * class        : project
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_project;
long helper_project_get(VObj*, Packet*, int, Packet*, long);
long helper_project_set(VObj*, Packet*, int, Packet*, long);

long meth_project_config(VObj *, Packet *, int, Packet *);
long meth_project_expose(VObj *, Packet *, int, Packet *);
long meth_project_get(VObj *, Packet *, int, Packet *);
long meth_project_initialize(VObj *, Packet *, int, Packet *);
long meth_project_info(VObj *, Packet *, int, Packet *);
long meth_project_render(VObj *, Packet *, int, Packet *);
long meth_project_set(VObj *, Packet *, int, Packet *);
