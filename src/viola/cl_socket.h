/*
 * class        : socket
 * superClass	: client
 */
#include "cl_client.h"

extern ClassInfo class_socket;
long helper_socket_get();
long helper_socket_set();

long meth_socket__startClient();
long meth_socket_freeSelf();
long meth_socket_get();
long meth_socket_set();
