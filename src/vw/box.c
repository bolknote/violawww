/*
 * box.c
 *
 * Generic container for structures.
 *
 */
/*
 * Copyright 1993 O'Reilly & Associates. All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "box.h"

Box* cloneBox(Box* box) {
    if (!box)
        return (NULL);

    Box* newone = (Box*)malloc(sizeof(Box));
    *newone = (Box){
        .data = box->data,
        .dataIsCopy = 1,
        .next = NULL
    };
    Box* bp = newone;

    while (box->next) {
        bp->next = (Box*)malloc(sizeof(Box));
        *(bp->next) = (Box){
            .data = box->next->data,
            .dataIsCopy = 1,
            .next = NULL
        };
        box = box->next;
        bp = bp->next;
    }

    return newone;
}

void putInBox(Box** box, void* item) {
    if (!item) {
        return;
    }
    
    Box* bp = (Box*)malloc(sizeof(Box));
    *bp = (Box){
        .data = item,
        .dataIsCopy = 0,
        .next = *box ? *box : NULL
    };
    *box = bp;
}

void* getFromBox(Box** box, void* key, CompareFunction compare, _Bool findFirstOne) {
    static int whichOne = 1;
    int i = 0;
    Box* bp = *box;

    if (!*box || !key)
        return (NULL);

    if (findFirstOne)
        whichOne = 1;

    do {
        i++;
        while (bp && !compare(key, bp->data))
            bp = bp->next;
        if (i != whichOne && bp)
            bp = bp->next;
    } while (i < whichOne && bp);

    if (bp) {
        whichOne++;
        return (bp->data);
    } else {
        whichOne = 1;
        return (NULL);
    }
}

void deleteFromBox(Box** box, void* key, CompareFunction compare, FreeFunction freeData, _Bool deleteAllItems) {
    Box* prev = NULL;
    Box* bp = *box;
    
    do {
        while (bp && !compare(key, bp->data)) {
            prev = bp;
            bp = bp->next;
        }

        if (bp) {
            if (bp == *box) {
                *box = bp->next;
                if (!bp->dataIsCopy && freeData)
                    freeData(bp->data);
                free(bp);
                bp = *box;
            } else {
                prev->next = bp->next;
                if (!bp->dataIsCopy && freeData)
                    freeData(bp->data);
                free(bp);
                bp = prev->next;
            }
        }
    } while (bp && deleteAllItems);
}

void deleteBox(Box* box, FreeFunction freeData) {
    if (!box)
        return;
    deleteFromBox(&box, NULL, alwaysTrue, freeData, true);
}

_Bool alwaysTrue(void *vkey, void *vdata) {
    return true;
}
