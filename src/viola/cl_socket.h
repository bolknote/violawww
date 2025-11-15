/*
 * class        : socket
 * superClass	: client
 */
#include "cl_client.h"

extern ClassInfo class_socket;
long helper_socket_get(VObj*, Packet*, int, Packet*, long);
long helper_socket_set(VObj*, Packet*, int, Packet*, long);

long meth_socket__startClient(VObj *, Packet *, int, Packet *);
long meth_socket_freeSelf(VObj *, Packet *, int, Packet *);
long meth_socket_get(VObj *, Packet *, int, Packet *);
long meth_socket_set(VObj *, Packet *, int, Packet *);
