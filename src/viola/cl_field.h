/*
 * class        : field
 * superClass	: generic
 */
#include "cl_generic.h"

extern ClassInfo class_field;
long helper_field_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID);
long helper_field_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID);

long meth_field_canvalize(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_clean(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_clearArea(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_clearWindow(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_clone(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_clone2(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_config(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_copyArea(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_cycleColors(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_deepObjectListSend(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_drawFillOval(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_drawFillRect(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_drawLine(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_drawOval(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_drawRect(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_drawText(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_eraseFillOval(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_eraseFillRect(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_eraseLine(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_eraseOval(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_eraseRect(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_eraseText(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_eventMask(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_expose(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_fillArc(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_flush(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_freeSelf(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_get(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_iconName(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_initialize(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_invertFillOval(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_invertFillRect(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_invertLine(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_invertOval(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_invertRect(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_invertText(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_lower(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_mouse(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_mouseLocal(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_mouseButton(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_mouseX(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_mouseY(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_objectListAppend(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_objectListCount(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_objectListDelete(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_objectListPrepend(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_objectListSend(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_raise(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_randomizeArea(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_render(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_set(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_smudge(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_windowName(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_field_windowPosition(VObj* self, Packet* result, int argc, Packet argv[]);
