/*
 * glib_x.h
 */
#include <X11/Xlib.h>
#include <X11/Xresource.h>
#include <X11/Xutil.h>
/*#include <X11/Xmu/Xmu.h>*/
#include <X11/Xatom.h>
#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

/* Forward declarations */
typedef long VObj;

/* Forward declaration for FontInfo */
typedef struct FontInfo FontInfo;

#define eventWindow(e) ((e).xany.window)
#define eventType(e) ((e).type)
/*
 * Safe accessors: EXPECT a pointer to XEvent (XEvent*).
 */
#define mouseX(ep) ((int)((const XButtonEvent*)(ep))->x)
#define mouseY(ep) ((int)((const XButtonEvent*)(ep))->y)
#define rootX(ep) ((int)((const XButtonEvent*)(ep))->x_root)
#define rootY(ep) ((int)((const XButtonEvent*)(ep))->y_root)
#define buttonNumber(ep) ((int)((const XButtonEvent*)(ep))->button)
#define eventRegionX(e) ((e).eventSpecific.exposure.regionX)
#define eventExposeX(e) (int)((e).xexpose.x)
#define eventExposeY(e) (int)((e).xexpose.y)
#define eventExposeWidth(e) (int)((e).xexpose.width)
#define eventExposeHeight(e) (int)((e).xexpose.height)
#define eventExposeCount(e) (int)((e).xexpose.count)
#define eventExposeSerial(e) (int)((e).xexpose.serial)
#define eventRegionY(e) ((e).eventSpecific.exposure.regionY)
#define eventRegionHeight(e) ((e).eventSpecific.exposure.height)
#define eventRegionWidth(e) ((e).eventSpecific.exposure.width)

typedef struct EventMaskNameStruct {
    int mask;
    char* name;
} EventMaskNameStruct;

extern EventMaskNameStruct eventMaskName[];

#define ANYWINDOW ((Window)NULL)

#define FG_COLOR "white"
#define BG_COLOR "black"
#define BD_COLOR "white"
#define CR_COLOR "white"

typedef int InkColor;

#ifdef BEFORE_SHARING_COLOR_INFO_________________________________________
typedef struct ColorStruct {
    char* name;
    XColor xcolor;
} ColorStruct;

typedef struct ColorInfoStruct {
    ColorStruct bg; /* background color */
    ColorStruct fg; /* foreground color */
    ColorStruct bd; /* border color */
    ColorStruct cr; /* cursor color */
} ColorInfo;
#endif /* BEFORE_SHARING_COLOR_INFO_________________________________________ */

typedef struct ColorStruct {
    XColor xcolor;
    char* name;
    int refc;
} ColorStruct;

typedef struct ColorInfoStruct {
    ColorStruct* bg; /* background color */
    ColorStruct* fg; /* foreground color */
    ColorStruct* bd; /* border color */
    ColorStruct* cr; /* cursor color */
} ColorInfo;

#define BDColorName(visual) ((colorInfo)->bd ? (colorInfo)->bd->name : NULL)
#define BGColorName(visual) ((colorInfo)->bg ? (colorInfo)->bg->name : NULL)
#define CRColorName(visual) ((colorInfo)->cr ? (colorInfo)->cr->name : NULL)
#define FGColorName(visual) ((colorInfo)->fg ? (colorInfo)->fg->name : NULL)

extern char* startUpDisplay;
extern int startUpGeom_x;
extern int startUpGeom_y;
extern int startUpGeom_width;
extern int startUpGeom_height;
extern XEvent e;
extern char keybuf[];
extern Display* display;
extern int screen_number;
extern Screen* screen;
int displayWidth;
int displayHeight;

extern unsigned long FGPixel, BGPixel, BDPixel, CRPixel, InvertPixel;
extern GC gc;
extern GC gc_fg;
extern GC gc_bg;
extern GC gc_bg_default;
extern GC gc_bg_lighter;
extern GC gc_bg_darker;
extern GC gc_bg_darkest;
extern GC gc_bd;
extern GC gc_cr;
extern GC gc_invert;
extern GC gc_invert_dash;
extern GC gc_copy;
extern GC gc_copy0;
extern GC gc_or;
extern GC gc_dash;
extern GC gc_mesh;
extern GC gc_link;         /* color for unvisited links */
extern GC gc_link_visited; /* color for visited links */
extern GC gc_subWindow;

/* Link color management for STG stylesheet */
void GLResetLinkColors(void);  /* Reset to default (black) */
void GLSetLinkColor(char* colorname);
void GLSetLinkVisitedColor(char* colorname);
extern int mouseCursorIsBusy;
extern short* bits;
extern int bits_width, bits_height;
extern int x_hot_spot, y_hot_spot;
extern Window rootWindow;
extern int pen_x, pen_y;
extern InkColor currentInkColor;
extern InkColor saveInkColor;
extern int screenDPI;
extern int sync_event;

extern XFontStruct* mfinfo;

extern int numberOfFontIDs;

#define menuPixmap_width 8
#define menuPixmap_height 8
extern Pixmap menuPixmap;

#include "violaIcon.xbm"
extern Pixmap violaPixmap;

#include "dunselIcon.xbm"
extern Pixmap dunselPixmap;

#define togglePixmap_width 16
#define togglePixmap_height 16
extern Pixmap togglePixmap_button0;
extern Pixmap togglePixmap_button1;
extern Pixmap togglePixmap_disc0;
extern Pixmap togglePixmap_disc1;
extern Pixmap togglePixmap_check0;
extern Pixmap togglePixmap_check1;

/****************************************************************************
 * procedures
 */
int init_fonts(void);
void free_fonts(void);

#define GLClearWindow(w) XClearWindow(display, w)
#define GLLowerWindow(w) XLowerWindow(display, w)
void GLRaiseWindow(Window w);

/* window
 */
Window GLOpenWindow(VObj*, int, int, int, int, int);
void GLCloseWindow(Window);
int GLDestroyWindow(Window);
int GLWindowSize(Window, int*, int*);
int GLSetWindowName(Window, char*);
int GLSetIconName(Window, char*);
Window GLQueryWindow(void);

/* cursor
 */
void GLRootPosition(Window, int*, int*);
Window GLQueryMouse(Window, int*, int*, int*, int*);
void GLChangeToBusyMouseCursor(Window);
void GLChangeToNormalMouseCursor(Window);

/* line
 */
int GLPaintLine(Window, GC, int, int, int, int);

#define GLDrawLine(w, x1, y1, x2, y2) GLPaintLine(w, gc_fg, x1, y1, x2, y2)

#define GLEraseLine(w, x1, y1, x2, y2) GLPaintLine(w, gc_bg, x1, y1, x2, y2)

#define GLInvertLine(w, x1, y1, x2, y2) GLPaintLine(w, gc_invert, x1, y1, x2, y2)

/* rectangle
 */
int GLPaintRect(Window, GC, int, int, int, int);

#define GLDrawRect(w, x1, y1, x2, y2) GLPaintRect(w, gc_fg, x1, y1, x2, y2)

#define GLEraseRect(w, x1, y1, x2, y2) GLPaintRect(w, gc_bg, x1, y1, x2, y2)

#define GLInvertRect(w, x1, y1, x2, y2) GLPaintRect(w, gc_invert, x1, y1, x2, y2)
int GLPaintFillRect(Window, GC, int, int, int, int);
ColorInfo* GLInitColorInfo(void);
int GLSetBGColorPixel(VObj*, unsigned long);

#define GLDrawFillRect(w, x1, y1, x2, y2) GLPaintFillRect(w, gc_fg, x1, y1, x2, y2)

#define GLEraseFillRect(w, x1, y1, x2, y2) GLPaintFillRect(w, gc_bg, x1, y1, x2, y2)

#define GLInvertFillRect(w, x1, y1, x2, y2) GLPaintFillRect(w, gc_invert, x1, y1, x2, y2)

/* circle/oval
 */
int GLPaintOval(Window, GC, int, int, int, int);

#define GLDrawOval(w, x, y, width, height) GLPaintOval(w, gc_fg, x, y, width, height)

#define GLEraseOval(w, x, y, width, height) GLPaintOval(w, gc_bg, x, y, width, height)

#define GLInvertOval(w, x, y, width, height) GLPaintOval(w, gc_invert, x, y, width, height)

int GLPaintFillOval(Window, GC, int, int, int, int);

int GLPaintFillOvalDegree(void);

int GLPaintFillArc(Window, GC, int, int, int, int, int, int);

#define GLDrawFillOval(w, x, y, width, height) GLPaintFillOval(w, gc_fg, x, y, width, height)

#define GLEraseFillOval(w, x, y, width, height) GLPaintFillOval(w, gc_bg, x, y, width, height)

#define GLInvertFillOval(w, x, y, width, height) GLPaintFillOval(w, gc_invert, x, y, width, height)

/* text
 */
int GLDefineNewFont(FontInfo*, int, char*, char*);
int GLUpdateFontInfo(FontInfo*, int);
int GLTextWidth(int, char*);
int GLTextHeight(int, char*);

int GLPaintText(Window, GC, int, int, int, char*);
int GLPaintTextLength(Window, GC, int, int, int, char*, int);

#define GLDrawText(w, fontID, x0, y0, str) GLPaintText(w, gc_fg, fontID, x0, y0, str)
#define GLDrawTextLength(w, fontID, x0, y0, str, length)                                           \
    GLPaintTextLength(w, gc_fg, fontID, x0, y0, length);

#define GLEraseText(w, fontID, x0, y0, str) GLPaintText(w, gc_bg, fontID, x0, y0, str)
#define GLEraseTextLength(w, fontID, x0, y0, str, length)                                          \
    GLPaintTextLength(w, gc_bg, fontID, x0, y0, str, length)

#define GLInvertText(w, fontID, x0, y0, str) GLPaintText(w, gc_invert, fontID, x0, y0, str)
#define GLInvertTextLength(w, fontID, x0, y0, str, length)                                         \
    GLPaintTextLength(w, gc_invert, fontID, x0, y0, str, length)

/* bitmap
 */
Pixmap GLMakeXBMFromASCII(Window w, char* bitmapStr, unsigned int* width, unsigned int* height,
                          int* hotx, int* hoty);
Pixmap GLMakeXPMFromASCII(Window w, char* bitmapStr, unsigned int* width, unsigned int* height,
                          int* hotx, int* hoty);
int GLDisplayXBMFromASCII(Window, int, int, char*);
int GLDisplayXPMFromASCII(Window, int, int, char*);
int GLDisplayXBM(Window, int, int, int, int, Pixmap);
int GLDisplayXBMBG(Window, int, int, int, int, Pixmap, int, int);
int GLDisplayXPM(Window, int, int, int, int, Pixmap);
int GLDisplayXPMBG(Window, int, int, int, int, Pixmap);
int GLFreeXBM(Pixmap);
int GLFreeXPM(Pixmap);
XImage* GLReadBitmapImage(Window, XImage*, char*);

/* widget drawings
 */
void GLDrawBorder(Window, int, int, int, int, int, int);
void GLEraseBorder(Window, int, int, int, int, int);
int GLDrawRubberFrame(VObj*, int, int, int, int);
void GLDrawScrollBarH(Window, int, int, int, int);
void GLDrawScrollBarV(Window, int, int, int, int);
void GLDrawDial(Window, int, int, int, int, int);

/* widget geometry
 */
void GLUpdateGeometry(int, Window, int, int, int, int);
void GLUpdatePosition(int, Window, int, int);
void GLUpdateSize(int, Window, int, int);

/* widget color
 */
int GLSetColor(ColorStruct**, char*, char*, long);
int GLSetBDColor(VObj*, char*);
int GLSetBGColor(VObj*, char*);
int GLSetFGColor(VObj*, char*);
int GLSetCRColor(VObj*, char*);
char* GLGetBGColor(VObj*);
char* GLGetFGColor(VObj*);
char* GLGetBDColor(VObj*);
char* GLGetCRColor(VObj*);
void GLUpdateColorReference(long, unsigned long);
ColorInfo* GLPrepareObjColor(VObj* self);
void GLDumpColorRef(void);

/* GIF functions */
XImage* GLGIFLoad(char*, char*, Window, int, int, int, int, int*, int*, XImage**);
XImage* GLGIFResize(Window, int, int, int, int, XImage*, XImage*);
int GLGIFDraw(Window, XImage*, int, int, int, int);

#ifdef USE_XGIF_PACKAGE
#include "../libGIF/xgif.h"
#endif

/* cut buffer
 */
void GLClearSelection(void);
int GLGetSelection(struct Packet*);
int GLSetSelection(VObj*, char*);

/* access to X resources
 */
char* GLGetResource(char*);

void freeGLibResources(void);

ColorStruct* getColorStruct(char*);
ColorStruct* addColorStructByString(char*);
ColorStruct* addColorName(char*);
void releaseColor(ColorStruct*);
void releaseColorByString(char*);

int GLShadeColor(int orig_red, int orig_green, int orig_blue, float shade);
