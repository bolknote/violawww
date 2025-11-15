/*
 * class        : stack
 * superClass	: pane
 */
#include "cl_pane.h"

extern ClassInfo class_stack;
long helper_stack_get(VObj*, Packet*, int, Packet*, long);
long helper_stack_set(VObj*, Packet*, int, Packet*, long);

long meth_stack_anyCard(VObj *, Packet *, int, Packet *);
long meth_stack_card(VObj *, Packet *, int, Packet *);
long meth_stack_config(VObj *, Packet *, int, Packet *);
long meth_stack_countBCards(VObj *, Packet *, int, Packet *);
long meth_stack_countFCards(VObj *, Packet *, int, Packet *);
long meth_stack_create(VObj *, Packet *, int, Packet *);
long meth_stack_currentCard(VObj *, Packet *, int, Packet *);
long meth_stack_expose(VObj *, Packet *, int, Packet *);
long meth_stack_firstCard(VObj *, Packet *, int, Packet *);
long meth_stack_get(VObj *, Packet *, int, Packet *);
long meth_stack_getCurrentCard(VObj *, Packet *, int, Packet *);
long meth_stack_initialize(VObj *, Packet *, int, Packet *);
long meth_stack_lastCard(VObj *, Packet *, int, Packet *);
long meth_stack_nextCard(VObj *, Packet *, int, Packet *);
long meth_stack_previousCard(VObj *, Packet *, int, Packet *);
long meth_stack_render(VObj *, Packet *, int, Packet *);
long meth_stack_set(VObj *, Packet *, int, Packet *);
long meth_stack_setCurrentCard(VObj *, Packet *, int, Packet *);

VObj* findStackObj(VObj*);
