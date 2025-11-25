#pragma once

#include "hash.h"

#ifndef VOBJ_DEFINED
#define VOBJ_DEFINED
typedef long VObj;
#endif

typedef struct ObjList {
    struct ObjList* next; /* must be the first item  (see vlist.h) */
    VObj* o;              /* must be the second item (see vlist.h) */
} VObjList;

extern HashTable* objID2Obj;     /* Obj strID  -> Obj vector 	*/
extern HashTable* objObj2ExistP; /* Obj vector -> existence flag */

extern VObj* VResourceObj;     /* refers to "res" object		*/
extern VObj* VFontResourceObj; /* refers to "res.font" object 		*/
extern VObj* VCurrentObj;      /* refers to the current object context */
extern VObj* VTargetObj;       /* refers to the marked object		*/
extern VObj* VPrevObj;         /* refers to the previous object	*/

extern long securityMode;

VObjList* scanVObjListNode(VObjList* head, long objID);
VObjList* removeVObjListNode(VObjList* head, long objID);
VObjList* prependVObjListNode(VObjList* head, VObj* obj);
VObjList* appendVObjListNode(VObjList* head, VObj* obj);

/*int validObjectP();*/
#define validObjectP(self) objObj2ExistP->get(objObj2ExistP, (long)(self))

VObj* findObject(long objNameStrID);
VObjList* appendObjToList(VObjList*, VObj*);
void freeAllObjects(void);

int exitingViola;
