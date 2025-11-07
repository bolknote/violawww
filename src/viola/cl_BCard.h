/*
 * class        : BCard
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_BCard;
long helper_BCard_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID);
long helper_BCard_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID);

long meth_BCard_config(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_BCard_expose(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_BCard_get(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_BCard_initialize(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_BCard_render(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_BCard_set(VObj* self, Packet* result, int argc, Packet argv[]);
