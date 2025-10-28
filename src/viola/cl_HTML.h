/*
 * class        : HTML
 * superClass	: txtDisp
 */
#include "cl_txtDisp.h"

extern ClassInfo class_HTML;
long helper_HTML_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID);
long helper_HTML_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID);

long meth_HTML_back(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_config(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_get(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_initialize(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_pathSimplify(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_purgeCache(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_render(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_search(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_set(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_HTML_WWWNameOfFile(VObj* self, Packet* result, int argc, Packet argv[]);
