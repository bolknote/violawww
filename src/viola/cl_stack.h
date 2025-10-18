/*
 * class        : stack
 * superClass	: pane
 */
#include "cl_pane.h"

extern ClassInfo class_stack;
long helper_stack_get();
long helper_stack_set();

long meth_stack_anyCard();
long meth_stack_card();
long meth_stack_config();
long meth_stack_countBCards();
long meth_stack_countFCards();
long meth_stack_create();
long meth_stack_currentCard();
long meth_stack_expose();
long meth_stack_firstCard();
long meth_stack_get();
long meth_stack_getCurrentCard();
long meth_stack_initialize();
long meth_stack_lastCard();
long meth_stack_nextCard();
long meth_stack_previousCard();
long meth_stack_render();
long meth_stack_set();
long meth_stack_setCurrentCard();

VObj* findStackObj();
