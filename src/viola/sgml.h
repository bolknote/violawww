/*
 * SGMLS interface, an optimized hmml.v. Hopefully generalized, too.
 */
#pragma once

#include "attr.h"
#include "obj.h"
#include "packet.h"

typedef struct SGMLTagMappingInfo {
    char* tag;
    char* type;
    int inlineP;
    int notifyOnCreationP;
    int flushAlwaysP;
    int flushOnSubTagP;
    int hpaneP;
    VObj* template; /* place holder for binary 'type' */
    long (*cloneMeth)(VObj* self, Packet* result, int argc,
                      Packet* argv); /* to avoid repeatly looking it up */
    int top;
    int bottom;
    int left;
    int right;
    struct SGMLDocMappingInfo* dmi; /* for objects derive DTD info */
    Attr* returnCache;              /* reusable style list */
} SGMLTagMappingInfo;

typedef struct SGMLDocMappingInfo {
    char* DTDName;
    SGMLTagMappingInfo* tagMap;
    int* tag2StyleIndexMap;
} SGMLDocMappingInfo;

extern SGMLDocMappingInfo SGMLForms[];
extern int SGMLBuildDoc_span;
extern int SGMLBuildDoc_inChanged;  /* depth counter for CHANGED regions */

#define DATABUFF_SIZE 100000 /* icky ick */

extern char dataBuff[];
extern int dataBuffIdx;
extern int dataBuffIdxStack[];
extern int dataBuffIdxStackIdx;

extern int SGMLBuildDoc_span;

int SGMLInit(void);
VObj* SGMLBuildDoc(char*, char*, VObj*, char*, int, char*);
VObj* SGMLBuildDoc_B(char*, char*, VObj*, char*, int, char*);
int SGMLBuildDoc_setBuff(VObj*, int);
void SGMLBuildDoc_flush(void);
void SGMLBuildDoc_enterChanged(void);
void SGMLBuildDoc_leaveChanged(void);
int SGMLTileDoc(VObj*, int, int);
int SGMLFindAnchorOffset(VObj*, char*);
void SGMLBuildDoc_insertObj(VObj*, int);
VObj* SGMLReBuildDoc(VObj*);
int getSGMLStyle(char*, char*, char*, Packet*);
int setSGMLStyle(char*, char*, char*, Packet*);
SGMLDocMappingInfo* setSGMLStylesheet(char*, char*);
int getVSpan(VObj*, int);
