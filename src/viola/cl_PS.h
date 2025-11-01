/*
 * class        : PS
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_PS;
long helper_PS_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID);
long helper_PS_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID);

long meth_PS_config(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_PS_get(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_PS_initialize(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_PS_info(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_PS_render(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_PS_set(VObj* self, Packet* result, int argc, Packet argv[]);
