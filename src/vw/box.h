/*
 * box.h
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

#ifndef _BOX_H_
#define _BOX_H_

typedef struct LLNode {
    void* data;
    char dataIsCopy;
    struct LLNode* next;
} LLNode, Box;

#ifdef _NOBOOLEAN_
typedef long Boolean;
enum { FALSE = 0, TRUE };
#endif /* _NOBOOLEAN_ */

/*
 * CompareFunction(void *key, void *data);
 */
typedef Boolean (*CompareFunction)(void *key, void *data);

/*
 * FreeFunction(void *item);
 */
typedef void (*FreeFunction)(void *item);

/*
 * putInBox(Box **box, void *item)
 */
void putInBox(Box** box, void* item);

/*
 * getFromBox(Box **box,
 *            void *key,
 *            CompareFunction compare,
 *            Boolean findFirstOne)
 */
void* getFromBox(Box** box, void* key, CompareFunction compare, Boolean findFirstOne);

/*
 * deleteFromBox(Box **box,
 *               void *key,
 *               CompareFunction compare,
 *               FreeFunction freeitem,
 *               Boolean deleteAllItems)
 */
void deleteFromBox(Box** box, void* key, CompareFunction compare, FreeFunction freeData, Boolean deleteAllItems);

/*
 * cloneBox(Box *box)
 */
Box* cloneBox(Box* box);

/*
 * deleteBox(Box *box,
 *           FreeFunction freeData)
 */
void deleteBox(Box* box, FreeFunction freeData);

/*
 * alwaysTrue()
 */
Boolean alwaysTrue(void *vkey, void *vdata);

#endif /* _BOX_H_ */
