#pragma once

typedef struct VList {
    struct VList* next;
    long id;
} VList;

VList* prependVListNode(VList** head_list, VList* list);
VList* scanVListNode(VList**, long, long (*)(long, long));
VList* removeVListNode(VList**, long, long (*)(long, long));
