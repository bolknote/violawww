/*
 * class        : GIF
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_GIF;

typedef struct Packet Packet;
typedef long VObj;

long helper_GIF_get();
long helper_GIF_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID);

long meth_GIF_config(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_GIF_expose(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_GIF_get();
long meth_GIF_initialize(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_GIF_render(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_GIF_set(VObj* self, Packet* result, int argc, Packet argv[]);
