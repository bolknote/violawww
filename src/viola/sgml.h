/* 
 * SGMLS interface, an optimized hmml.v. Hopefully generalized, too.
 */
#pragma once

typedef struct SGMLTagMappingInfo {
	char 	*tag;
	char 	*type;
	int	inlineP;
	int	notifyOnCreationP;
	int	flushAlwaysP;
	int	flushOnSubTagP;
	int	hpaneP;
	VObj 	*template;		/* place holder for binary 'type' */
	long	(*cloneMeth)(VObj *self, Packet *result, int argc, Packet *argv);	/* to avoid repeatly looking it up */
	int 	top;
	int 	bottom;
	int 	left;
	int 	right;
	struct SGMLDocMappingInfo *dmi;	/* for objects derive DTD info */
	Attr 	*returnCache;			/* reusable style list */
} SGMLTagMappingInfo;

typedef struct SGMLDocMappingInfo {
	char *DTDName;
	SGMLTagMappingInfo *tagMap;
	int *tag2StyleIndexMap;
} SGMLDocMappingInfo;

extern SGMLDocMappingInfo SGMLForms[];
extern int SGMLBuildDoc_span;

#define DATABUFF_SIZE 100000		/* icky ick */

extern char dataBuff[];
extern int dataBuffIdx;
extern int dataBuffIdxStack[];
extern int dataBuffIdxStackIdx;

extern int SGMLBuildDoc_span;

int SGMLInit();
VObj *SGMLBuildDoc();
VObj *SGMLBuildDoc_B();
int SGMLBuildDoc_setBuff();
int SGMLTileDoc();
int SGMLFindAnchorOffset();
void SGMLBuildDoc_insertObj();
VObj *SGMLReBuildDoc();
int getSGMLStyle();
int setSGMLStyle();
SGMLDocMappingInfo *setSGMLStylesheet();
int getVSpan();
