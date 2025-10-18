#pragma once

typedef struct VList {
	struct VList *next;
	long id;
} VList;

VList *prependVListNode(VList **head_list, VList *list);
VList *removeVListNode();
