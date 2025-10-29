/*
 * class        : txtDisp
 * superClass	: txt
 */
#include "cl_txt.h"

extern ClassInfo class_txtDisp;
/* lightweight forward declarations to allow prototypes without heavy includes */
#ifndef VOBJ_DEFINED
#define VOBJ_DEFINED
typedef long VObj;
#endif
typedef struct Packet Packet;
typedef struct TFStruct TFStruct;

long int helper_txtDisp_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID);
long int helper_txtDisp_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID);

#define FORMAT_NONE 0
#define FORMAT_WRAP 1
#define FORMAT_CENTER 2
#define FORMAT_LEFT 3
#define FORMAT_RIGHT 4

long int meth_txtDisp__getSelection(VObj* self, Packet* result, int argc, Packet argv[]);

long int meth_txtDisp_append(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_building_maxFontDescent(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_building_maxFontHeight(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_building_vspan(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_charMask(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_charButtonMask(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_charHighLiteMask(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_charUnderlineMask(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_clearSelection(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_clone(VObj* self, Packet* result, int argc, Packet argv[]);
long meth_txtDisp_clone2(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_config(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_currentChar(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_currentLine(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_currentTag(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_currentWord(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_cursorColumn(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_cursorRow(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_deHighLight(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_drawCursor(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_eraseCursor(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_expose(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_freeSelf(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_get(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_highLight(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_initialize(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_insert(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_lineRowOffset(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_nextTag(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_numberOfLinesDisplayed(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_previousTag(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_processInput(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_processKeyInput(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_processMouseInput(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_processMouseMove(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_render(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_selectionInfo(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_set(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_setSelection(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_shownDepend(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_totalLineCount(VObj* self, Packet* result, int argc, Packet argv[]);
long int meth_txtDisp_setRevVideoFlag(VObj* self, Packet* result, int argc, Packet argv[]);

long int helper_txtDisp_updateShownInfo(TFStruct* tf);
int help_txtDisp_shownPositionV(VObj* self, int newPosition);

long meth_txtDisp_test4(VObj* self, Packet* result, int argc, Packet argv[]);
