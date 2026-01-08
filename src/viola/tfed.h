/*
 * tfed.h
 */
#pragma once

#include "ascii.h"
#include "sys.h"

extern MethodInfo defaultKeyBinding[];

#define MAX_EDIT_LINE_LENGTH 20000
#define OUT_OF_RANGE 999999;

/* shift into reverse and out of reverse */
#define SHIFT_IN 15
#define SHIFT_OUT 14

typedef struct TFChar {
    unsigned char c;
    unsigned short fontID;  /* Supports up to 65535 fonts/images */
    unsigned char tagID;
    unsigned short flags;
} TFChar;

/* This should be replaced with generalized viola objects
 */
#define TFPic_XBML 0
#define TFPic_XBM 1
#define TFPic_GIF 2
#define TFPic_XPM 3

typedef struct TFPic {
    int id;
    int type;
    XImage* data;
    int width;
    int height;
    char canFree;
    struct TFPic* next;
} TFPic;

#define TFCChar(tfcp) (tfcp)->c
#define TFCFontID(tfcp) (tfcp)->fontID
#define TFCTagID(tfcp) (tfcp)->tagID
#define TFCFlags(tfcp) (tfcp)->flags
#define TFCWidth(tfcp) FontWidths((tfcp)->fontID)[(tfcp)->c]
#define TFCClear(tfcp)                                                                             \
    {                                                                                              \
        (tfcp)->c = 0;                                                                             \
        (tfcp)->fontID = 0;                                                                        \
        (tfcp)->tagID = 0;                                                                         \
        (tfcp)->flags = 0;                                                                         \
    }
#define TFCSet(tfcp, c, tagval, fontID)                                                            \
    {                                                                                              \
        (tfcp)->c = c;                                                                             \
        (tfcp)->tagID = tagval;                                                                    \
        (tfcp)->fontID = fontID;                                                                   \
    }

/* used in char info
 */
#define TAGINFO_SIZE 16

typedef struct TagInfo {
    char* info;
    /*	int x_begin;
            int x_end;
            int valid;
    */
} TagInfo;

/* this whole flags setup needs to be revampped */
#define MASK_WRAP (1 << 0)       /* line wrap break (internal)*/
#define MASK_REVERSE (1 << 1)    /* reverse video	*/
/*#define MASK_UNDER	(1<<2)*/ /* underline		*/
#define MASK_RELIEF (1 << 2)     /* for hypertext links	*/
#define MASK_BUTTON (1 << 3)     /* fake button (unvisited link) */
#define MASK_VISITED (1 << 8)    /* visited link */
/*#define MASK_XRULE	(1<<4)*/ /* horizontal rule 	*/
#define MASK_OBJ (1 << 4)        /* object be here 	*/
#define MASK_NL (1 << 5)         /* really a newline	*/
#define MASK_PIC (1 << 6)        /* picture be here	*/
#define MASK_ITALIC (1 << 7)     /* be italic		*/
#define MASK_MARKED (1 << 9)     /* marked/highlighted background */

typedef struct TFLineNode {
    TFChar* linep;
    struct TFLineNode* next;
    struct TFLineNode* prev;
    TagInfo* tagInfo;
    int tagInfoCount;    /* count of tagInfo array elements */
    int length;          /* number of characters */
    int maxPixelExtentX; /* for minimizing b/c of Expose events */
    int maxPixelExtentY;
    short maxFontHeight;
    short maxFontDescent;
    short breakc;        /* break count */
    short breakcIsValid; /* to avoid redundantly recomputing breakc */
} TFLineNode;

typedef struct TFStruct {

    /* line node pointers
     */
    TFLineNode* currentp;
    TFLineNode* firstp;
    TFLineNode* lastp;
    TFLineNode* offsetp;

    /* position, in chars, of the cursor,
     * offset from left-upper corner of the text.
     */
    int current_col;
    int current_col_sticky;
    int current_row;

    /* position, in chars, of the cursor,
     * offset from left-upper corner of the field.
     */
    int csr_px;
    int csr_px_sticky;
    int csr_py;

    /* offset of visible portion of the field from the entire field...
     */
    int screen_col_offset;
    int screen_row_offset;

    /* number of line nodes in the entire field
     */
    int lineNodeCount;

    /* number of visible lines in the entire field (sum of breakc)
     */
    int lineVisibleCount;

    /* number of lines within the param
     */
    int num_of_lines;

    int esc_toggle;
    int bufferUsed; /* used in yank stuff */

    /* stuff copied from self
     */
    Window w;
    VObj* self;
    int xUL, yUL; /* upper left x,y */
    int xLR, yLR; /* lower right x,y */
    int width, height;
    int fontID;
    int currentFontID;
    int wrap;
    int cursorIsVisible;
    long cursorTimeInfo;
    long cursorBlinkDelay; /* millisecs to next state change */
    int highLiteFrom_cx, highLiteFrom_cy;
    int highLiteTo_cx, highLiteTo_cy;
    int isRenderAble;
    int shownPosition;
    int shownSize;

    int building_maxFontHeight; /* used for object embedding */
    int building_maxFontDescent;
    int building_vspan;
    int editableP;
    MemoryGroup* mg;

    int align; /*using paneConfig values */

    TFPic* pics;

    /*
     * Dumb stuff for the text search "Feature"
     *
     */
    int search_len, search_x, search_y;

} TFStruct;

/**************************************************************************
 * for external referencing
 */
extern int tfed_init(void);
TFStruct* tfed_setUpTFStruct(VObj* self, char* text);
TFStruct* tfed_updateTFStruct(VObj* self, char* text);
TFStruct* tfed_clone(VObj* orig, VObj* clone, char* suffix);
TFStruct* updateEStrUser(VObj* self);
int tfed_render(VObj* self);
int tfed_processMouseInput(VObj* self);
char* tfed_processMouseMove(VObj* self);
int tfed_processKeyEvent(VObj* self, Window w, char c);
void tfed_insertChar(VObj* self, char c);
int tfed_setBuffer(TFStruct* tf, char* str);
int tfed_getBuffer(char* str);
int tfed_drawCursor(VObj* self);
int tfed_eraseCursor(VObj* self);
int tfed_jumpToOffsetLine(VObj* self, int destLine);
int tfed_jumpToLine(VObj* self, int destLine);
int tfed_setCursorBlinkDelay(VObj* self, long delay);
int tfed_expose(VObj* self, int x, int y, int width, int height);
long kbf_newline(TFStruct* tf);
long kbf_dump(TFStruct* tf);
long kbf_refresh(TFStruct* tf);
long kbf_beginning_of_line(TFStruct* tf);
long kbf_backward_char(TFStruct* tf);
long kbf_delete_char(TFStruct* tf);
long kbf_end_of_line(TFStruct* tf);
long kbf_forward_char(TFStruct* tf);
long kbf_delete_backward_char(TFStruct* tf);
long kbf_join_line(TFStruct* tf);
long kbf_kill_line(TFStruct* tf);
long kbf_open_line_below(TFStruct* tf);
long kbf_next_line(TFStruct* tf);
long kbf_open_line(TFStruct* tf);
long kbf_previous_line(TFStruct* tf);
long kbf_scroll_up_line(TFStruct* tf);
long kbf_delete_line(TFStruct* tf);
long kbf_scroll_up(TFStruct* tf);
long kbf_scroll_down(TFStruct* tf);
long kbf_insert_yank(TFStruct* tf);
long kbf_scroll_down_line(TFStruct* tf);
long kbf_esc_prefix(TFStruct* tf);
long kbf_ident(TFStruct* tf);
long kbf_useFont_context(TFStruct* tf);
long kbf_useFont_fixed(TFStruct* tf);
long kbf_useFont_normal(TFStruct* tf);
long kbf_useFont_normal_large(TFStruct* tf);
long kbf_useFont_normal_largest(TFStruct* tf);
long kbf_useFont_bold(TFStruct* tf);
long kbf_useFont_bold_large(TFStruct* tf);
long kbf_useFont_bold_largest(TFStruct* tf);

int tfed_get_currentChar(TFStruct* tf, char* c);
int tfed_get_currentLine(TFStruct* tf, char* strBuff);
int tfed_get_cursorColumn(TFStruct* tf);
int tfed_get_cursorRow(TFStruct* tf);
int tfed_get_lineRowOffset(TFStruct* tf);
int tfed_get_charMask(TFStruct* tf);
char* tfed_get_currentTag(TFStruct* tf);
int tfed_get_currentWord(TFStruct* tf, char* strBuff);
char* tfed_get_nextTag(TFStruct* tf);
char* tfed_get_previousTag(TFStruct* tf);
int tfed_get_numberOfLinesDisplayed(TFStruct* tf);
int tfed_get_totalLineCount(TFStruct* tf);
int tfed_set_wrap(TFStruct* tf, int wrap);
int tfed_append(TFStruct* tf, char* str);
int tfed_clearSelection(VObj* self);
char* tfed_getSelection(VObj* self);

char* convertNodeLinesToStr(VObj* self, TFLineNode* headp);
int scanVerticalMetrics(TFStruct* tf);
int lineFlagSet(TFStruct* tf, int ln, int cn, int mask, int op);

#define DUMP_CHAR 1
#define DUMP_FONT 2
#define DUMP_WRAP 3
#define DUMP_NL 4
void dumpTFCArray(int mask, TFChar tfcbuff[], TagInfo* tagInfo, int tagInfoCount);

int tfed_setReverseMaskInButtonRange(TFStruct* tf, int boolval);
int tfed_setReliefMaskInButtonRange(TFStruct* tf, int boolval);

TFPic* tfed_addPicFromFile(TFPic** pics, char* id, char* src);
TFPic* tfed_addPic(TFPic** pics, TFPic* oldpic);
