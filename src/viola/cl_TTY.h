/*
 * class        : TTY
 * superClass	: client
 */
#include "cl_client.h"

extern ClassInfo class_TTY;
long helper_TTY_get(VObj*, Packet*, int, Packet*, long);
long helper_TTY_set(VObj*, Packet*, int, Packet*, long);

long meth_TTY_get(VObj *, Packet *, int, Packet *);
long meth_TTY_set(VObj *, Packet *, int, Packet *);
long meth_TTY__startClient(VObj *, Packet *, int, Packet *);
