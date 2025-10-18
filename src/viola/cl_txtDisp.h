/*
 * class        : txtDisp
 * superClass	: txt
 */
#include "cl_txt.h"

extern ClassInfo class_txtDisp;
long int helper_txtDisp_get();
long int helper_txtDisp_set();

#define FORMAT_NONE 0
#define FORMAT_WRAP 1
#define FORMAT_CENTER 2
#define FORMAT_LEFT 3
#define FORMAT_RIGHT 4

long int meth_txtDisp__getSelection();

long int meth_txtDisp_append();
long int meth_txtDisp_building_maxFontDescent();
long int meth_txtDisp_building_maxFontHeight();
long int meth_txtDisp_building_vspan();
long int meth_txtDisp_charMask();
long int meth_txtDisp_charButtonMask();
long int meth_txtDisp_charHighLiteMask();
long int meth_txtDisp_charUnderlineMask();
long int meth_txtDisp_clearSelection();
long int meth_txtDisp_clone();
long meth_txtDisp_clone2();
long int meth_txtDisp_config();
long int meth_txtDisp_currentChar();
long int meth_txtDisp_currentLine();
long int meth_txtDisp_currentTag();
long int meth_txtDisp_currentWord();
long int meth_txtDisp_cursorColumn();
long int meth_txtDisp_cursorRow();
long int meth_txtDisp_deHighLight();
long int meth_txtDisp_drawCursor();
long int meth_txtDisp_eraseCursor();
long int meth_txtDisp_expose();
long int meth_txtDisp_freeSelf();
long int meth_txtDisp_get();
long int meth_txtDisp_highLight();
long int meth_txtDisp_initialize();
long int meth_txtDisp_insert();
long int meth_txtDisp_lineRowOffset();
long int meth_txtDisp_nextTag();
long int meth_txtDisp_numberOfLinesDisplayed();
long int meth_txtDisp_previousTag();
long int meth_txtDisp_processInput();
long int meth_txtDisp_processKeyInput();
long int meth_txtDisp_processMouseInput();
long int meth_txtDisp_processMouseMove();
long int meth_txtDisp_render();
long int meth_txtDisp_selectionInfo();
long int meth_txtDisp_set();
long int meth_txtDisp_setSelection();
long int meth_txtDisp_shownDepend();
long int meth_txtDisp_totalLineCount();
long int meth_txtDisp_setRevVideoFlag();

long int helper_txtDisp_updateShownInfo();
int help_txtDisp_shownPositionV();

long meth_txtDisp_test4();
