/*
 * class        : cosmic
 * superClass	: NULL
 */
#include "class.h"
#include "obj.h"
#include "packet.h"

extern ClassInfo class_cosmic;
long helper_cosmic_get(VObj*, Packet*, int, Packet*, long);
long helper_cosmic_set(VObj*, Packet*, int, Packet*, long);

long meth_cosmic_clone(VObj *, Packet *, int, Packet *);
long meth_cosmic_clone2(VObj *, Packet *, int, Packet *);
long meth_cosmic_cloneID(VObj *, Packet *, int, Packet *);
long meth_cosmic_create(VObj *, Packet *, int, Packet *);
long meth_cosmic_debug(VObj *, Packet *, int, Packet *);
long meth_cosmic_destroy(VObj *, Packet *, int, Packet *);
long meth_cosmic_detach(VObj *, Packet *, int, Packet *);
long meth_cosmic_exist(VObj *, Packet *, int, Packet *);
long meth_cosmic_exit(VObj *, Packet *, int, Packet *);
long meth_cosmic_freeSelf(VObj *, Packet *, int, Packet *);
long meth_cosmic_info(VObj *, Packet *, int, Packet *);
long meth_cosmic_interpret(VObj *, Packet *, int, Packet *);
long meth_cosmic_loadObjFile(VObj *, Packet *, int, Packet *);
long meth_cosmic_object(VObj *, Packet *, int, Packet *);
long meth_cosmic_pop(VObj *, Packet *, int, Packet *);
long meth_cosmic_push(VObj *, Packet *, int, Packet *);
long meth_cosmic_quit(VObj *, Packet *, int, Packet *);
long meth_cosmic_save(VObj *, Packet *, int, Packet *);
long meth_cosmic_saveAs(VObj *, Packet *, int, Packet *);
long meth_cosmic_saveObjFile(VObj *, Packet *, int, Packet *);
long meth_cosmic_send(VObj *, Packet *, int, Packet *);
long meth_cosmic_test1(VObj *, Packet *, int, Packet *);
long meth_cosmic_test2(VObj *, Packet *, int, Packet *);
long meth_cosmic_test3(VObj *, Packet *, int, Packet *);
long meth_cosmic_test4(VObj *, Packet *, int, Packet *);
long meth_cosmic_tweak(VObj *, Packet *, int, Packet *);
long meth_cosmic_usual(VObj *, Packet *, int, Packet *);

long meth_cosmic_modalExit(VObj *, Packet *, int, Packet *);

void sendInitToChildren(VObj*);
