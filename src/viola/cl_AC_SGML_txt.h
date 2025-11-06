/*
 * class        : AC_SGML_txt
 * superClass	: txtDisp
 */
#include "cl_txtDisp.h"

extern ClassInfo class_AC_SGML_txt;
long int helper_AC_SGML_txt_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID);
long int helper_AC_SGML_txt_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID);

long int meth_AC_SGML_txt_get(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_AC_SGML_txt_initialize(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_AC_SGML_txt_render(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_AC_SGML_txt_set(VObj* self, Packet* result, int argc, Packet argv[]);
