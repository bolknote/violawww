/*
 *    class.h
 */
#pragma once

#include <stdio.h>
#include "hash.h"
#include "membership.h"

#ifndef VOBJ_DEFINED
#define VOBJ_DEFINED
typedef long VObj;
#endif

/* Forward declaration */
typedef struct Packet Packet;

/*****************************************************************************
 * slot info
 */
#define SLOT_MASK_TYPE 0x000f

#define LONG 1  /* long */
#define OBJP 2  /* object pointer */
#define OBJL 3  /* object list */
#define PTRV 4  /* generic pointer */
#define PTRS 5  /* string */
#define PTRA 6  /* string, append to */
#define ATTR 7  /* attributes */
#define SFUNC 8  /* set value to function */
#define PROC 9  /* procedure, don't set slot value */
#define CLSI 10 /* classInfo */
#define PCOD 11 /* pcode */
#define ARRY 12 /* array */
#define RGBV 13 /* RGB structure */
#define TFLD 14 /* TFStruct (text field structure) */
#define STRI 15 /* StrInfo */

#define SLOT_MASK_RW 0x00f0

#define SLOT_R 0x0010
#define SLOT_W 0x0020
#define SLOT_RW 0x0030

/* to be converted to later... */

typedef struct SlotInfo {
    long id;     /* str ID 	*/
    int flags;   /* slot type, save-or-not */
    long val;    /* slot value	*/
    int offset;  /* slot offset  */
    int section; /* section to look in */
    long tmp;    /* temporary	*/
} SlotInfo;

/*****************************************************************************
 * method info
 */
typedef struct MethodInfo {
    int id;
    long (*method)(VObj *, Packet *, int, Packet *);
} MethodInfo;

/*****************************************************************************
 * class info
 */
#ifndef CLASSINFO_DEFINED
#define CLASSINFO_DEFINED
typedef struct ClassInfo {
    long (*slotGetMeth)(VObj*, Packet*, int, Packet*, long);
    long (*slotSetMeth)(VObj*, Packet*, int, Packet*, long);

    SlotInfo** slots;
    MethodInfo* methods;
    int id;
    struct ClassInfo* superClass;

    MHInfo mhp;
    HashTable* mht;

    /* used to build private slots */
    SlotInfo** slookup;
    int newcount;   /* count of new slots */
    int totalcount; /* count of all slots in this type */

    /* used to build common slots */
    VObj* common; /* object containing common slots */
    SlotInfo** common_slookup;
    int common_newcount; /* used for building common obj */
    int common_totalcount;
} ClassInfo;
#endif

extern int init_class(void);
extern ClassInfo* getClassInfoByID(int);
extern ClassInfo* getClassInfoByName(char*);
extern VObj* buildObjWithLoadedSlots(ClassInfo*, long (*)[100][2], int);
extern VObj* instantiateObj(long (*)[100][2], int*);
extern long* searchSlot(long (*)[100][2], int, int);
extern int saveSelfAndChildren(VObj*, FILE*);
extern int dumpObj(VObj*, long (*)(FILE*, const char*, ...), FILE*, int, int);
extern VObj* clone(VObj*);
extern int loadClassScriptsP;
