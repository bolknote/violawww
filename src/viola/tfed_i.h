/* tfed internal decls */

#include <limits.h>  /* for INT_MAX */
#include <string.h>  /* for strlen */

extern int MSTAT_tfed;
extern int MSTAT_tfed_convertNodeLinesToStr;

void tfed_registerTmpFileToFree(char*);
void tfed_FreeTmpFileToFree(int);

/*MemoryGroup *tfed_mg;*/

/*#define Vmalloc(group, size) malloc(size)*/
/*#define Vfree(group, ptr) free(ptr)*/

extern MethodInfo defaultKeyBinding[];

extern long (*kbflookup[128])(TFStruct*);
extern char sbuff[];
extern int buffi;

/* 
 * VT100 sequence for reversing and unreverse video
 */
extern char enterReverse_vt100[];
extern char leaveReverse_vt100[];

/* used to specify
 */
#define STAG_OPEN '('
#define STAG_CLOSE ')'

extern TFChar TFC_ARRAY_NEWLINE[];

#define TFC_TAB_SPACES 8

extern TFChar TFC_ARRAY_SPACES[];

#define RANGEMODE_NONE 0
#define RANGEMODE_CLIP 1
#define RANGEMODE_DELETE 2

#define BORDERTW 4
#define BORDERTH 4
#define PXX 2
#define PYY 2

/* CHAR=no update, LINE=update line, SCREEN=update screen */
#define CHAR 0
#define LINE 1
#define SCREEN 2
extern int refreshMode;
extern int updateShown;

#define TFCBUFF_SIZE 100000
extern TFChar tfcEditStr[TFCBUFF_SIZE];
extern TFChar tfcYankStr[TFCBUFF_SIZE];
extern TFChar tfcBuffStr[TFCBUFF_SIZE];
extern TFLineNode* theEditLN; /* editing buffer		*/
extern TFLineNode* theYankLN; /* cut/paste/kill/yank buffer 	*/
extern TFLineNode* theBuffLN; /* very temporary buffer	*/

#define ANCHOR_LINES_SPAN 64
extern int tfed_anchorPatchIdx;
extern char** tfed_anchorPatch[];
extern int tfed_anchorInP;

extern TFPic* dunselPic;

extern XTextItem xcharitem; /* used by drawChar() */

#define cursorWithinField(tf) ((tf->csr_py >= 0) && (tf->csr_py <= tf->yLR))

#define TFCCopy(tfcTo, tfcFrom)                                                                    \
    {                                                                                              \
        (tfcTo)->c = (tfcFrom)->c;                                                                 \
        (tfcTo)->tagID = (tfcFrom)->tagID;                                                         \
        (tfcTo)->fontID = (tfcFrom)->fontID;                                                       \
        (tfcTo)->flags = (tfcFrom)->flags;                                                         \
    }

/* Safe strlen for X11 - strings displayed on screen are always reasonable length */
static inline int safe_strlen_for_x11(const char* str) {
    size_t len = strlen(str);
    /* X11 text functions expect int; screen text is always < INT_MAX */
    return (len > INT_MAX) ? INT_MAX : (int)len;
}

#define textPixelWidth(fontID, FontFont) XTextWidth(FontFont(fontID), str, safe_strlen_for_x11(str))

#define TBUFFSIZE 1024 /*XXX maximum line length. Used by tfed_buildLines() */

#define TFWINDOW GET_window(tf->self)

typedef struct TFCBuildInfo {
    VObj* self;
    TFLineNode* currentp;
    TFLineNode* beginp;
    char* str;
    int fontID;
    int lineNodeCountp;
    int lineVisibleCountp;
    TFChar* tbuff;
    int tbuffi;
    TagInfo buffTagInfo[TAGINFO_SIZE];
    int buffTagID[TAGINFO_SIZE];
    int tagID;
    int flags;
    int maxFontHeight;
    int maxFontDescent;
    int vspan;
    int breaki;
    int px;
    int makeLinep;
    long format;
    long verbatim;
    TFPic* pics;
    int spaceWidth;
} TFCBuildInfo;

/*
 * forward declaration of all procedures refenced only within this file
 */
int TFCstrlen(TFChar tfcArray[]);
int TFCstrcat(TFChar tfcArrayTo[], TFChar tfcArrayFrom[]);
int str2EBuff(TFStruct* tf, char* str, int* fontID);
int TFC2StrStrcpy(char* strTo, TFChar* tfcArrayFrom);
ptrdiff_t TFCstrcpy(TFChar* tfcArrayTo, TFChar* tfcArrayFrom);
ptrdiff_t TFCstrncpy(TFChar*, TFChar*, int);

int translateCol2Px(TFChar*, int);
int translatePx2Col(TFChar*, int);

void placeCursorWithinStr(TFStruct* tf);
void placeCursor(TFStruct* tf);
int joinLine(TFStruct* tf);
int TFCInsertStr(void);
int moveOffset(TFStruct* tf, int dir, int* span);
int jumpLine(TFStruct*, unsigned long, int, int);
int tfed_scroll_delta(TFStruct* tf, int offsetdir);
int moveLine(TFStruct* tf, int dir);
int moveLineNode(TFStruct* tf, int dir);
int tfed_buildLines(TFCBuildInfo* buildInfo);
int splitLine(TFCBuildInfo* buildInfo, int split, int tagCarriage);
int deleteLineNode(TFStruct* tf);
TFLineNode* insertLineNode(TFStruct* tf, TFLineNode* currentp, int initLineP);
TFLineNode* insertBelowLineNode(TFStruct* tf, TFLineNode* currentp, int initLineP);
char* convertNodeLineToStr(void);
void freeNodeLines(TFStruct* tf);
void dumpNodeLines(TFStruct* tf);
int renderTF(TFStruct* tf);
long TimedDrawCursor(VObj* self, Packet argv[], int argc);
long TimedEraseCursor(VObj* self, Packet argv[], int argc);
void invertCursor(TFStruct*);
void drawCursor(TFStruct* tf);
void eraseCursor(TFStruct* tf);
void drawChar(TFStruct*, TFChar*, int, int);
int traverseToRightEdge(TFChar*, int, int*, int*);
int scrollLineForward(TFStruct* tf, int delta, int col);
int scrollLineBackward(TFStruct* tf, int delta, int col);
int scrollDownLowerPart(TFStruct*, int, int);
int scrollDownLowerPartNEW(TFStruct* tf, int offset, int span);
int scrollUpLowerPart(TFStruct* tf, int offset, int span);
int scrollUpLowerPartNEW(TFStruct*, int, int);
int lineSegWidth(TFStruct* tf, TFLineNode* currentp);
void drawLine(TFStruct*, TFLineNode*, int*);
int drawLineOffset(TFStruct* tf, int linesOffset, int clearBG);
int drawTextFieldCursor(void);
TFStruct* updateEStrUser(VObj*);
int TFCShiftStr(TFChar tfcArray[], int starti, int shift);
void TFCInsertChar(TFChar*, int, TFChar*);
int setBreaks(TFStruct* tf, TFLineNode* currentp);
int setCurrentFontID(TFStruct* tf);
int LogicOrTFCFlag(TFChar*, int, int, int);
int LogicAndTFCFlag(TFChar*, int, int, int);
char* rangeOperation(TFStruct* tf, int from_cx, int from_cy, int to_cx, int to_cy, int drawP, int underlineP, int mode);
