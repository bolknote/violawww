/*
 * class        : txtButton
 * superClass	: txt
 */
#include "cl_txt.h"

extern ClassInfo class_txtButton;
long int helper_txtButton_get(VObj*, Packet*, int, Packet*, long);
long int helper_txtButton_set(VObj*, Packet*, int, Packet*, long);

long int meth_txtButton_get(VObj *, Packet *, int, Packet *);
long int meth_txtButton_initialize(VObj *, Packet *, int, Packet *);
long int meth_txtButton_render(VObj *, Packet *, int, Packet *);
long int meth_txtButton_set(VObj *, Packet *, int, Packet *);
