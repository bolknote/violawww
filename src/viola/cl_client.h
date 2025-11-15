/*
 * class        : client
 * superClass	: field
 */
#include "cl_field.h"

extern ClassInfo class_client;
long helper_client_get(VObj*, Packet*, int, Packet*, long);
long helper_client_set(VObj*, Packet*, int, Packet*, long);

long meth_client_endClient(VObj *, Packet *, int, Packet *);
long meth_client_freeSelf(VObj *, Packet *, int, Packet *);
long meth_client_get(VObj *, Packet *, int, Packet *);
long meth_client_initialize(VObj *, Packet *, int, Packet *);
long meth_client_input(VObj *, Packet *, int, Packet *);
long meth_client_inputn(VObj *, Packet *, int, Packet *);
long meth_client_output(VObj *, Packet *, int, Packet *);
long meth_client_set(VObj *, Packet *, int, Packet *);
long meth_client_startClient(VObj *, Packet *, int, Packet *);
