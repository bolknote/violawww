/*
 * Copyright 1990-93 Pei-Yuan Wei.	All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */
/*
 * glib_x.c
 *
 * Scott: added runInSubWindow flag
 */

#include "attr.h"
#include "error.h"
#include "file.h"
#include "hash.h"
#include "ident.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "scanutils.h"
#include "sys.h"
#include "utils.h"
#include "vlist.h"
#include <math.h>
#include <signal.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

#include "membership.h"

#include "class.h"
#include "classlist.h"
#include "event.h"
#include "glib.h"
#include "slotaccess.h"

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
/*#include <X11/Shell.h>*/
#include <X11/extensions/shape.h>
#include <X11/extensions/Xrender.h>

#include "../libXPM/xpm.h"

#define USE_XLOADIMAGE_PACKAGE 1

#ifdef USE_XLOADIMAGE_PACKAGE
#include "../libIMG/copyright.h"

#define LIBIMG 1
#include "../libIMG/xloadimage.h"

#include "../libIMG/patchlevel"
/*#include "../libIMG/image.h"*/

/*#include <signal.h>*/
extern int initImgLib(void);
extern int loadImg(char*, void**, int*, int*);
extern int approximateColor(int, unsigned, unsigned);
extern void FatalError(char*);
extern int getVariable(Attr*, char*, Packet*);
extern int resolveFontSet(Attr*, char*);
extern long sendMessage1(VObj*, char*);
extern long callMeth(VObj*, Packet*, int, Packet*, long);
extern long meth_generic_HTTPGet(VObj*, Packet*, int, Packet*);
#endif
#ifdef USE_XGIF_PACKAGE
#include "../libGIF/xgif.h"
#endif

#include "img.h"
#include "misc.h"

#define RADIAN_TO_DEGREE_RATIO 0.017453293

/****************************************************************************
 * window stuff
 */
Display* display = NULL;
int screenNumber;
int screenDepth;
int displayWidth;
int displayHeight;
Window rootWindow;
XWindowAttributes rootWindowAttr;
int screenDPI;
static Atom wm_delete_window;
int sync_event = 0;

int noShading = 0;
int shadingP = 1;

/* modified by -display startup option */
char* startUpDisplay = NULL;

/* modified by -geometry startup option */
int startUpGeom_x = 0;
int startUpGeom_y = 0;
int startUpGeom_width = 0;
int startUpGeom_height = 0;

/* derived (ie: ripped off) from xgif_load.c
 */
int dc = 0;
XColor ctab[256];

HashTable* colorNameShareDB;

ImgNode* imgNodes = NULL;

EventMaskNameStruct eventMaskName[] = {Button1MotionMask,
                                       "button1Motion",
                                       ButtonPressMask,
                                       "buttonPress",
                                       ButtonReleaseMask,
                                       "buttonRelease",
                                       EnterWindowMask,
                                       "enterWindow",
                                       ExposureMask,
                                       "exposureMask",
                                       KeyPressMask,
                                       "keyPress",
                                       KeyReleaseMask,
                                       "keyRelease",
                                       LeaveWindowMask,
                                       "leaveWindow",
                                       StructureNotifyMask,
                                       "structureNotify",
                                       VisibilityChangeMask,
                                       "visibilityChange",
                                       PointerMotionMask,
                                       "pointerMotion",
                                       0,
                                       NULL};

int numberOfFontIDs = 0;
int fontFamilyDefaultOffset = 0;

int fontID_fixed = -1;

int fontID_normal = -1;
int fontID_normal_large = -1;
int fontID_normal_largest = -1;

int fontID_bold = -1;
int fontID_bold_large = -1;
int fontID_bold_largest = -1;

int fontID_italic = -1;
int fontID_italic_large = -1;
int fontID_italic_largest = -1;

int fontID_banner = -1;
int fontID_banner_large = -1;
int fontID_banner_largest = -1;

int fontID_symbol = -1;
int fontID_symbol_large = -1;
int fontID_symbol_largest = -1;

/****************************************************************************
 * color stuff
 */
Colormap colormap;
int numOfDisplayColors;
unsigned long FGPixel, BGPixel, BDPixel, CRPixel, InvertPixel;
unsigned long DefaultFGPixel, DefaultBGPixel, DefaultBDPixel, DefaultCRPixel;
unsigned long DefaultFGPixel_lighter, DefaultFGPixel_darker, DefaultFGPixel_darkest;
unsigned long DefaultBGPixel_lighter, DefaultBGPixel_darker, DefaultBGPixel_darkest;
unsigned long DefaultBDPixel_lighter, DefaultBDPixel_darker, DefaultBDPixel_darkest;
unsigned long DefaultBRPixel_lighter, DefaultCRPixel_darker, DefaultCRPixel_darkest;
int* colorReferenceTable;

/****************************************************************************
 * GC stuff
 */
GC gc;
GC gc_fg;
GC gc_bg;
GC gc_bg_default;
GC gc_bg_lighter;
GC gc_bg_darker;
GC gc_bg_darkest;
GC gc_bd;
GC gc_cr;
GC gc_invert;
GC gc_invert_dash;
GC gc_copy;
GC gc_copy0;
GC gc_or;
GC gc_dash;
GC gc_mesh;
GC gc_link;         /* color for unvisited links */
GC gc_link_visited; /* color for visited links */
GC gc_mark;         /* background color for CHANGED tag (LemonChiffon1) */
GC gc_subWindow;

/****************************************************************************
 * bitmap stuff
 */
Pixmap pixmap = 0;

#define mesh_width 2
#define mesh_height 2
static char mesh_bits[] = {0x01, 0x02};

Pixmap violaPixmap = 0;

Pixmap dunselPixmap = 0;

#define BITMAPDEPTH 1
#define TOO_SMALL 0
#define BIG_ENOUGH 1

static char menuXBM_bits[] = {0x00, 0xff, 0x7f, 0xbe, 0x5c, 0x28, 0x10, 0x00};
Pixmap menuPixmap = 0;

Pixmap togglePixmap_button0 = 0;
Pixmap togglePixmap_button1 = 0;
Pixmap togglePixmap_check0 = 0;
Pixmap togglePixmap_check1 = 0;
Pixmap togglePixmap_disc0 = 0;
Pixmap togglePixmap_disc1 = 0;

/*
 * toggle button style: boolean -- "0" protruding, "1" protruding
 */
#define toggleXBM_button0_width 16
#define toggleXBM_button0_height 16
static char toggleXBM_button0_bits[] = {
    0xf8, 0x0f, 0x08, 0x18, 0x88, 0x18, 0x88, 0x18, 0x88, 0x18, 0xff, 0x1f, 0x01, 0x30, 0xe1, 0x70,
    0x11, 0x71, 0x11, 0x71, 0x11, 0x71, 0xe1, 0x70, 0x01, 0x70, 0xff, 0x6f, 0xfe, 0x5f, 0xfc, 0x3f};
#define toggleXBM_button1_width 16
#define toggleXBM_button1_height 16
static char toggleXBM_button1_bits[] = {
    0xff, 0x1f, 0x01, 0x30, 0x41, 0x70, 0x41, 0x70, 0x41, 0x70, 0x41, 0x70, 0x41, 0x70, 0x01, 0x70,
    0xff, 0x6f, 0x0e, 0x5c, 0xcc, 0x34, 0x28, 0x0d, 0x28, 0x0d, 0xc8, 0x0c, 0x08, 0x0c, 0xf8, 0x0f};

/*
 * toggle button style: check -- unchecked box, checked box
 */
#define toggleXBM_check1_width 16
#define toggleXBM_check1_height 16
static char toggleXBM_check1_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xbf, 0x08, 0xc0, 0x08, 0x60, 0x08, 0x30, 0x08, 0x18,
    0x68, 0x2c, 0xc8, 0x26, 0x88, 0x23, 0x08, 0x21, 0x08, 0x20, 0xf8, 0x3f, 0x00, 0x00, 0x00, 0x00};

#define toggleXBM_check0_width 16
#define toggleXBM_check0_height 16
static char toggleXBM_check0_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x3f, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20,
    0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0xf8, 0x3f, 0x00, 0x00, 0x00, 0x00};

/*
 * toggle button style: disc -- empty circle, filled circle
 */
#define toggleXBM_disc0_width 16
#define toggleXBM_disc0_height 16
static char toggleXBM_disc0_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x60, 0x0c, 0x10, 0x10, 0x10, 0x10, 0x08, 0x20,
    0x08, 0x20, 0x08, 0x20, 0x10, 0x10, 0x10, 0x10, 0x60, 0x0c, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00};

#define toggleXBM_disc1_width 16
#define toggleXBM_disc1_height 16
static char toggleXBM_disc1_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0xe0, 0x0f, 0xf0, 0x1f, 0xf0, 0x1f, 0xf8, 0x3f,
    0xf8, 0x3f, 0xf8, 0x3f, 0xf0, 0x1f, 0xf0, 0x1f, 0xe0, 0x0f, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00};

/****************************************************************************
 * XPM stuff
 *
 * need these variables be persistant? investigate later...
 */
typedef struct _XpmIcon {
    Pixmap pixmap;
    Pixmap mask;
    XpmAttributes attributes;
} XpmIcon;
unsigned int xpm_numsymbols = 0;
XpmColorSymbol xpm_symbols[10];
unsigned long xpm_valuemask = 0;

/* A smugy fingerprint pixmap ...
 */
unsigned int thumbXPM_width;
unsigned int thumbXPM_height;
Pixmap thumbXPM;
static char* thumbXPM_src = {"/* XPM */\n\
static char * thumb [] = {\n\
\"16 16 3 1\",\n\
\" 	s None	c None\",\n\
\".	c green\",\n\
\"X	c black\",\n\
\"   ......       \",\n\
\"  .XXXXXX.      \",\n\
\" .X......XX.    \",\n\
\"   XXXXX...X.   \",\n\
\" .X     XX..X.  \",\n\
\"   ....X  XX.X  \",\n\
\" .. XXX...  X.  \",\n\
\" XX    XXXX. X. \",\n\
\".  .XXX    X. X \",\n\
\"  .X   XXX. X.X \",\n\
\"  X  ..   X. X  \",\n\
\" .X .XXX.  X X. \",\n\
\" . .X   X. X. X \",\n\
\" X .X    X. X X \",\n\
\"   .X     X   X \",\n\
\"                \"};\n\
"};

/****************************************************************************
 * GIF stuff
 */
/*Only from XGIF ??*/
Display* theDisp;
int theScreen, dispcells;
Colormap theCmap;
Window rootW, mainW;
GC theGC;
unsigned long fcol, bcol;
Font mfont;

XFontStruct* mfinfo; /*??*/

Visual* theVisual;
XImage *theImage, *expImage;
char* cmd;

#ifdef USE_XGIF_PACKAGE

/* global vars */
int iWIDE, iHIGH, eWIDE, eHIGH, expand, numcols, strip, nostrip, mono;
unsigned long cols[256];
XColor defs[256];
#endif

#ifdef USE_XLOADIMAGE_PACKAGE
/*Image *image;*/
#endif

/****************************************************************************
 * cursor stuff
 */
Cursor cursor_arrow;
Cursor cursor_watch;
int mouseCursorIsBusy = 0;

/****************************************************************************
 * styling
 */
int borderStyleThickness[BORDER_STYLE_COUNT];

XrmDatabase resDB;

int initDefaultColor(char* colorname, unsigned long defpixel, unsigned long* pixel, unsigned long* pixel_lighter, unsigned long* pixel_darker, unsigned long* pixel_darkest)
{
    XColor color, exactcolor;
    int stat = 1;

    if (XAllocNamedColor(display, colormap, colorname, &color, &exactcolor)) {
        *pixel = color.pixel;
    } else {
        int approxPixel;

        approxPixel = approximateColor(70 * 650, 70 * 650, 70 * 650);
        if (approxPixel) {
            *pixel = approxPixel;
        } else {
            *pixel = defpixel;
            *pixel_lighter = defpixel;
            *pixel_darker = defpixel;
            *pixel_darkest = defpixel;
            return stat;
        }
    }

    *pixel_lighter = GLShadeColor(color.red, color.green, color.blue, 1.4f);
    if (*pixel_lighter == -1)
        *pixel_lighter = *pixel;

    *pixel_darker = GLShadeColor(color.red, color.green, color.blue, 0.8f);
    if (*pixel_darker == -1)
        *pixel_darker = *pixel;

    *pixel_darkest = GLShadeColor(color.red, color.green, color.blue, 0.6f);
    if (*pixel_darkest == -1)
        *pixel_darkest = *pixel;

    return 1;
}

/* Flag to suppress X errors during cleanup (set by signal handler) */
extern volatile sig_atomic_t finish;

/*
 * X Error handler for ViolaWWW - overrides libIMG's handler
 */
static int violaXErrorHandler(Display* disp, XErrorEvent* error) {
    char errortext[BUFSIZ];
    char msg[256];
    
    /* Suppress BadWindow errors during cleanup - windows may already be destroyed.
     * Also suppress if finish flag is set (exiting due to signal).
     * BadWindow (error_code 3) is harmless during cleanup.
     */
    if (finish || error->error_code == BadWindow)
        return 0;
    
    XGetErrorText(disp, error->error_code, errortext, BUFSIZ);
    
    /* Use write() to avoid stdio buffering issues with signal handlers */
    snprintf(msg, sizeof(msg), "X Error: %s on 0x%lx\n", errortext, error->resourceid);
    write(STDERR_FILENO, msg, strlen(msg));
    
    return 0;
}

/*
 *
 */
int GLInit(Display* dpy, Screen* scrn)
{
    Screen* screen;
    extern double pow(double x, double y);
    char dash_list[2];
    XGCValues gcvalues;
    char *screenResStr = NULL, *resManagerStr;
    XrmDatabase resManagerDB;
    int i;
    extern int runInSubWindow; /* Scott */

    if (runInSubWindow && dpy) {
        display = dpy;
    } else {
        if (!(display = XOpenDisplay(startUpDisplay))) {
            fprintf(stderr, "Can't open display! Aborting.\n");
            return 0;
        }
    }
    /* Force synchronous X mode to prevent race conditions where X requests
     * are buffered and sent after windows are destroyed (causes BadWindow errors).
     * This is slower but ensures correct operation. */
    XSynchronize(display, 1);

    /* Initialize X Toolkit for this display to ensure Xmu per-display
     * information is available. This is needed by Motif which depends on Xmu. */
    {
        static XtAppContext app_context = NULL;
        static int dummy_argc = 0;
        static char* dummy_argv[] = { NULL };
        if (!app_context) {
            XtToolkitInitialize();
            app_context = XtCreateApplicationContext();
        }
        if (!runInSubWindow || !dpy) {
            /* Only call XtDisplayInitialize for displays we opened */
            XtDisplayInitialize(app_context, display, "viola", "Viola", NULL, 0, &dummy_argc, dummy_argv);
        }
    }

    if (runInSubWindow && scrn) {
        screen = scrn;
        screenNumber = XScreenNumberOfScreen(scrn);
    } else {
        screenNumber = DefaultScreen(display);
        screen = ScreenOfDisplay(display, screenNumber);
    }

    screenDepth = DefaultDepthOfScreen(screen);
    rootWindow = RootWindow(display, screenNumber);

    if (!XGetWindowAttributes(display, rootWindow, &rootWindowAttr)) {
        fprintf(stderr, "failed to get root window attributes\n");
        exit(0);
    }
    displayWidth = rootWindowAttr.width;
    displayHeight = rootWindowAttr.height;

    wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);

    /*
     * Get X resources
     */
    XrmInitialize();

#ifndef X11R3
    /* R5 or later (is this the correct way to tell?) */
    screenResStr = XScreenResourceString(screen);
    if (screenResStr) {
        resDB = XrmGetStringDatabase(screenResStr);
    }
#endif

    resManagerStr = XResourceManagerString(display);
    if (resManagerStr) {
        resManagerDB = XrmGetStringDatabase(resManagerStr);
        if (resManagerDB) {
            XrmMergeDatabases(resManagerDB, &resDB);
            /*			XrmDestroyDatabase(resManagerDB);*/
        }
    }
    /* RESOURCE_MANAGER not set - this is normal on XQuartz/macOS */

    colorNameShareDB =
        initHashTable(1021, hash_str, cmp_str, NULL, NULL, getHashEntry_str, putHashEntry_str,
                      putHashEntry_replace_str, removeHashEntry_str);

    colormap = XDefaultColormapOfScreen(screen);
    numOfDisplayColors = pow(2.0, ((double)screenDepth));

    if (noShading) {
        shadingP = 0;
    } else if (numOfDisplayColors <= 2) {
        /* monochrome display */
        shadingP = 0;
    }

    FGPixel = XBlackPixelOfScreen(screen);
    BGPixel = XWhitePixelOfScreen(screen);
    BDPixel = XBlackPixelOfScreen(screen);
    CRPixel = XBlackPixelOfScreen(screen);

    /*
     * make a colormap reference table
     * table of all colors (by colormap index) allocated by viola
     */
    colorReferenceTable = (int*)malloc(sizeof(int) * numOfDisplayColors);
    for (i = 0; i < numOfDisplayColors; colorReferenceTable[i++] = 0)
        ;

    ++colorReferenceTable[BDPixel];
    ++colorReferenceTable[BGPixel];
    ++colorReferenceTable[FGPixel];
    ++colorReferenceTable[CRPixel];

    gc = DefaultGC(display, screenNumber);
    XSetState(display, gc, FGPixel, BGPixel, GXcopy, AllPlanes);

    borderStyleThickness[BORDER_NONE] = BORDER_NONE_THICKNESS;
    borderStyleThickness[BORDER_BOX] = BORDER_BOX_THICKNESS;
    borderStyleThickness[BORDER_FIELD] = BORDER_FIELD_THICKNESS;
    borderStyleThickness[BORDER_BUTTON] = BORDER_BUTTON_THICKNESS;
    borderStyleThickness[BORDER_THINBUTTON] = BORDER_THINBUTTON_THICKNESS;
    borderStyleThickness[BORDER_FRAME] = BORDER_FRAME_THICKNESS;
    borderStyleThickness[BORDER_BORDER] = BORDER_BORDER_THICKNESS;
    borderStyleThickness[BORDER_MENU] = BORDER_MENU_THICKNESS;
    borderStyleThickness[BORDER_SUBWINDOW] = BORDER_SUBWINDOW_THICKNESS;

    cursor_arrow = XCreateFontCursor(display, XC_top_left_arrow);
    cursor_watch = XCreateFontCursor(display, XC_watch);

    /* Initialize xgifload.c */
#ifdef USE_XGIF_PACKAGE
    expand = 1;
    strip = 0;
    nostrip = 1;
    mono = 0;
#endif
    theDisp = display;
#ifdef USE_XLOADIMAGE_PACKAGE
    initImgLib();
    /* Override libIMG's error handler with viola's own - this handler is
     * global for all X connections in the process */
    XSetErrorHandler(violaXErrorHandler);
#endif

    theScreen = screenNumber; /* Scott */

    theCmap = DefaultColormap(theDisp, theScreen);
    rootW = RootWindow(theDisp, theScreen);
    theGC = DefaultGC(theDisp, theScreen);
    fcol = WhitePixel(theDisp, theScreen);
    bcol = BlackPixel(theDisp, theScreen);
    theVisual = DefaultVisual(theDisp, theScreen);

    dispcells = DisplayCells(theDisp, theScreen);

    if (!dc) {
        int i;
        if (dispcells < 256)
            dc = dispcells;
        else
            dc = 256;
        /* read in the color table */
        for (i = 0; i < dc; i++)
            ctab[i].pixel = i;
    }
    XQueryColors(theDisp, theCmap, ctab, dc);

    if (shadingP) {
        char* colorname;
        int useDefault = 1;

        DefaultFGPixel = FGPixel;

        colorname = GLGetResource("Viola*background");
        if (colorname) {
            if (initDefaultColor(colorname, BGPixel, &DefaultBGPixel, &DefaultBGPixel_lighter,
                                 &DefaultBGPixel_darker, &DefaultBGPixel_darkest)) {
                useDefault = 0;
            } else {
                fprintf(stderr,
                        "warning, can't get default widget color resource. Using grey70.\n");
            }
        }
        if (useDefault) {
            if (initDefaultColor("grey70", BGPixel, &DefaultBGPixel, &DefaultBGPixel_lighter,
                                 &DefaultBGPixel_darker, &DefaultBGPixel_darkest)) {
                useDefault = 0;
            } else {
                fprintf(stderr, "warning, can't get default color grey70.\n");
            }
        }

        if (useDefault) {
            DefaultBGPixel = BGPixel;
            DefaultBGPixel_lighter = BGPixel;
            DefaultBGPixel_darker = BGPixel;
            DefaultBGPixel_darkest = BGPixel;
        }
        DefaultBDPixel = BDPixel;
        DefaultCRPixel = CRPixel;

    } else {
        DefaultFGPixel = FGPixel;

        DefaultBGPixel = BGPixel;
        DefaultBGPixel_lighter = BGPixel;
        DefaultBGPixel_darker = FGPixel;
        DefaultBGPixel_darkest = FGPixel;

        DefaultBDPixel = BDPixel;
        DefaultCRPixel = CRPixel;
    }
    InvertPixel = FGPixel ^ BGPixel;

    /* initialze GCs (do only once)
     */
    gcvalues.foreground = FGPixel;
    gcvalues.background = BGPixel;
    gcvalues.dash_offset = 1;
    gcvalues.line_style = LineOnOffDash;
    dash_list[0] = 1;
    dash_list[1] = 1;
    gc_dash = XCreateGC(display, rootWindow,
                        GCForeground | GCBackground | GCLineStyle | GCLineStyle, &gcvalues);

    XSetDashes(display, gc_dash, 2, dash_list, 2);

    /* gc_invert_dash */
    gcvalues.function = GXinvert;
    gcvalues.plane_mask = InvertPixel;
    gc_invert_dash = XCreateGC(display, rootWindow,
                               GCForeground | GCBackground | GCLineStyle | GCLineStyle |
                                   GCFunction | GCPlaneMask,
                               &gcvalues);
    XSetDashes(display, gc_invert_dash, 2, dash_list, 2);

    /* gc_fg */
    gcvalues.foreground = FGPixel;
    gcvalues.background = BGPixel;
    gc_fg = XCreateGC(display, rootWindow, GCForeground | GCBackground, &gcvalues);

    /* gc_bg */
    gcvalues.foreground = BGPixel;
    gcvalues.background = FGPixel;
    gc_bg = XCreateGC(display, rootWindow, GCForeground | GCBackground, &gcvalues);

    /* gc_bg_default */
    gcvalues.foreground = DefaultBGPixel;
    gc_bg_default = XCreateGC(display, rootWindow, GCForeground, &gcvalues);

    /* gc_bg_lighter */
    gcvalues.foreground = DefaultBGPixel_lighter;
    gc_bg_lighter = XCreateGC(display, rootWindow, GCForeground, &gcvalues);

    /* gc_bg_darker */
    gcvalues.foreground = DefaultBGPixel_darker;
    gc_bg_darker = XCreateGC(display, rootWindow, GCForeground, &gcvalues);

    /* gc_bg_darkest */
    gcvalues.foreground = DefaultBGPixel_darkest;
    gc_bg_darkest = XCreateGC(display, rootWindow, GCForeground, &gcvalues);

    /* gc_bd */
    gcvalues.foreground = BDPixel;
    gcvalues.background = BGPixel;
    gc_bd = XCreateGC(display, rootWindow, GCForeground | GCBackground, &gcvalues);

    /* gc_cr */
    gcvalues.foreground = CRPixel;
    gcvalues.background = BGPixel;
    gc_cr = XCreateGC(display, rootWindow, GCForeground | GCBackground, &gcvalues);

    /* gc_invert */
    gcvalues.function = GXinvert;
    gcvalues.plane_mask = InvertPixel;
    gc_invert = XCreateGC(display, rootWindow, GCFunction | GCPlaneMask, &gcvalues);

    /* gc_copy */
    gcvalues.foreground = BGPixel;
    gcvalues.background = FGPixel;
    gc_copy = XCreateGC(display, rootWindow, GCForeground | GCBackground, &gcvalues);

    /* gc_copy0 */
    gcvalues.foreground = BGPixel;
    gcvalues.background = FGPixel;
    gcvalues.graphics_exposures = False; /* to prevent extraneous events */
    gc_copy0 = XCreateGC(display, rootWindow, GCForeground | GCBackground | GCGraphicsExposures,
                         &gcvalues);

    /* gc_or */
    gcvalues.foreground = BGPixel;
    gcvalues.background = FGPixel;
    gcvalues.function = GXor;
    gc_or = XCreateGC(display, rootWindow, GCFunction | GCForeground | GCBackground, &gcvalues);

    /* gc_mesh */
    gcvalues.foreground = FGPixel;
    gcvalues.background = BGPixel;

    gcvalues.fill_style = FillOpaqueStippled;
    gcvalues.stipple =
        XCreateBitmapFromData(display, rootWindow, mesh_bits, mesh_width, mesh_height);

    gc_mesh = XCreateGC(display, rootWindow, GCForeground | GCBackground | GCFillStyle | GCStipple,
                        &gcvalues);

    /* gc_link - default black (same as gc_fg), STG can override via FGColor on A tag */
    gcvalues.foreground = FGPixel;
    gcvalues.background = BGPixel;
    gc_link = XCreateGC(display, rootWindow, GCForeground | GCBackground, &gcvalues);

    /* gc_link_visited - default black (same as gc_fg), STG can override via traversedForegroundColor */
    gcvalues.foreground = FGPixel;
    gcvalues.background = BGPixel;
    gc_link_visited = XCreateGC(display, rootWindow, GCForeground | GCBackground, &gcvalues);

    /* gc_mark - LemonChiffon1 background for CHANGED tag */
    {
        XColor markColor;
        if (XParseColor(display, colormap, "LemonChiffon1", &markColor) &&
            XAllocColor(display, colormap, &markColor)) {
            gcvalues.foreground = markColor.pixel;
        } else {
            /* Fallback to light yellow if LemonChiffon1 not available */
            gcvalues.foreground = BGPixel;
        }
        gcvalues.background = BGPixel;
        gc_mark = XCreateGC(display, rootWindow, GCForeground | GCBackground, &gcvalues);
    }

    /* subwindow */
    gcvalues.function = GXinvert;
    gcvalues.plane_mask = InvertPixel;
    gcvalues.subwindow_mode = IncludeInferiors;
    gcvalues.foreground = 1;
    gcvalues.background = 1;
    gcvalues.line_style = LineOnOffDash;
    gc_subWindow = XCreateGC(display, rootWindow,
                             GCFunction | GCPlaneMask | GCForeground | GCBackground | GCLineStyle |
                                 GCSubwindowMode,
                             &gcvalues);

    violaPixmap = XCreateBitmapFromData(display, rootWindow, violaIcon_bits, violaIcon_width,
                                        violaIcon_height);
    dunselPixmap = XCreateBitmapFromData(display, rootWindow, dunselIcon_bits, dunselIcon_width,
                                         dunselIcon_height);
    menuPixmap = XCreateBitmapFromData(display, rootWindow, menuXBM_bits, menuPixmap_width,
                                       menuPixmap_height);
    togglePixmap_button0 = XCreateBitmapFromData(display, rootWindow, toggleXBM_button0_bits,
                                                 togglePixmap_width, togglePixmap_height);
    togglePixmap_button1 = XCreateBitmapFromData(display, rootWindow, toggleXBM_button1_bits,
                                                 togglePixmap_width, togglePixmap_height);
    togglePixmap_check0 = XCreateBitmapFromData(display, rootWindow, toggleXBM_check0_bits,
                                                togglePixmap_width, togglePixmap_height);
    togglePixmap_check1 = XCreateBitmapFromData(display, rootWindow, toggleXBM_check1_bits,
                                                togglePixmap_width, togglePixmap_height);
    togglePixmap_disc0 = XCreateBitmapFromData(display, rootWindow, toggleXBM_disc0_bits,
                                               togglePixmap_width, togglePixmap_height);
    togglePixmap_disc1 = XCreateBitmapFromData(display, rootWindow, toggleXBM_disc1_bits,
                                               togglePixmap_width, togglePixmap_height);

    {
        int hotx, hoty;
        thumbXPM = GLMakeXPMFromASCII(rootWindow, thumbXPM_src, &thumbXPM_width, &thumbXPM_height,
                                      &hotx, &hoty);
    }

    screenDPI = 25.4 * WidthOfScreen(screen) / WidthMMOfScreen(screen);

    /*XXX wait, what's this doing here!? */
    if ((mfinfo = XLoadQueryFont(theDisp, "variable")) == NULL)
        FatalError("couldn't open 'variable' font\n");
    mfont = mfinfo->fid;
    XSetFont(theDisp, theGC, mfont);
    XSetForeground(theDisp, theGC, fcol);
    XSetBackground(theDisp, theGC, bcol);

    return 1;
}

int init_fonts() {
    Attr* varlist;
    Attr* attrp;
    Attr* fattrp;
    Packet fontsPk;
    Packet* packetp;
    char* fontSet;
    int i, n, idx;

    nullPacket(&fontsPk);

    if (!VFontResourceObj) {
        fprintf(stderr, "init_fonts(): no font resource found\n");
        return 0;
    }
    varlist = GET__varList(VFontResourceObj);
    numberOfFontIDs = 0;

    if (!getVariable(varlist, "fonts", &fontsPk)) {
        fprintf(stderr, "init_fonts(): can't find fonts ID/name list.\n");
        return 0;
    }
    /* dumpVarList(fontsPk.info.a);*/

    fattrp = fontsPk.info.a;
    for (attrp = fattrp, n = 0; attrp; attrp = attrp->next)
        n++;

    for (idx = 0; idx < n; idx++) {

        numberOfFontIDs = idx;

        for (attrp = fattrp; attrp; attrp = attrp->next) {
            if (attrp->id == idx) {
                packetp = (Packet*)attrp->val;
                /*
                                        printf("fonts[%d]=", numberOfFontIDs);
                                        dumpPacket(packetp);
                                        printf("\n");
                */
                fontSet = saveString(PkInfo2Str(packetp));

                if (resolveFontSet(varlist, fontSet) < 0) {
                    /* use any font
                     */
                    fprintf(
                        stderr,
                        "Warning: failed to use fonts in set \"%s\". Trying any font (\"*\").\n",
                        fontSet);

                    /* XXX Should be using default gc font
                     */
                    if (!GLDefineNewFont(fontInfo, numberOfFontIDs, fontSet, "*")) {
                        fprintf(stderr, "Good grief.. not even \"*\" worked.\n");
                        return 0;
                    }
                }

                FontRef(numberOfFontIDs) = fontSet;

                if (!strcmp(fontSet, "fixed")) {
                    fontID_fixed = numberOfFontIDs;

                } else if (!strcmp(fontSet, "normal")) {
                    fontID_normal = numberOfFontIDs;
                } else if (!strcmp(fontSet, "normal_large")) {
                    fontID_normal_large = numberOfFontIDs;
                } else if (!strcmp(fontSet, "normal_largest")) {
                    fontID_normal_largest = numberOfFontIDs;

                } else if (!strcmp(fontSet, "bold")) {
                    fontID_bold = numberOfFontIDs;
                } else if (!strcmp(fontSet, "bold_large")) {
                    fontID_bold_large = numberOfFontIDs;
                } else if (!strcmp(fontSet, "bold_largest")) {
                    fontID_bold_largest = numberOfFontIDs;

                } else if (!strcmp(fontSet, "italic")) {
                    fontID_italic = numberOfFontIDs;
                } else if (!strcmp(fontSet, "italic_large")) {
                    fontID_italic_large = numberOfFontIDs;
                } else if (!strcmp(fontSet, "italic_largest")) {
                    fontID_italic_largest = numberOfFontIDs;

                } else if (!strcmp(fontSet, "banner")) {
                    fontID_banner = numberOfFontIDs;
                } else if (!strcmp(fontSet, "banner_large")) {
                    fontID_banner_large = numberOfFontIDs;
                } else if (!strcmp(fontSet, "banner_largest")) {
                    fontID_banner_largest = numberOfFontIDs;

                } else if (!strcmp(fontSet, "symbol")) {
                    fontID_symbol = numberOfFontIDs;
                } else if (!strcmp(fontSet, "symbol_large")) {
                    fontID_symbol_large = numberOfFontIDs;
                } else if (!strcmp(fontSet, "symbol_largest")) {
                    fontID_symbol_largest = numberOfFontIDs;
                }
            }
        }
    }

    if (fontID_fixed == -1) {
        fprintf(stderr, "warning: ``fixed'' font not specified.\n");
        fontID_fixed = 0; /*XXX unsafe */
    }
    if (fontID_normal == -1) {
        fprintf(stderr, "warning: ``normal'' font not specified.\n");
        fontID_normal = fontID_fixed;
    }
    if (fontID_bold == -1) {
        fprintf(stderr, "warning: ``bold font not specified.\n");
        fontID_bold = fontID_normal;
    }
    if (fontID_normal_large == -1) {
        fprintf(stderr, "warning: ``normal_large'' font not specified.\n");
        fontID_normal_large = fontID_normal;
    }
    if (fontID_bold_large == -1) {
        fprintf(stderr, "warning: ``bold_large'' font not specified.\n");
        fontID_bold_large = fontID_bold;
    }
    if (fontID_normal_largest == -1) {
        fprintf(stderr, "warning: ``normal_largest'' font not specified.\n");
        fontID_normal_largest = fontID_normal_large;
    }
    if (fontID_bold_largest == -1) {
        fprintf(stderr, "warning: ``bold_largest'' font not specified.\n");
        fontID_bold_largest = fontID_bold_large;
    }
    return 1;
}

void free_fonts() {
    int i;

    for (i = 0; i < numberOfFontIDs; i++) {
        if (verbose)
            fprintf(stderr, "Freeing fonts[%d]\n", i);
        XFreeFont(display, FontFontStruct(i));
    }
}

int resolveFontSet(Attr* varlist, char* fontSet)
{
    Packet pk, *packetp;
    Attr *attrp, *fattrp;
    char* xspec;
    int n, i, idx;

    nullPacket(&pk);

    if (!getVariable(varlist, fontSet, &pk)) {
        fprintf(stderr, "init_fonts(): can't find font set list '%s.\n", fontSet);
        return 0;
    }

    fattrp = pk.info.a;

    for (attrp = fattrp, n = 0; attrp; attrp = attrp->next)
        n++;

    for (idx = 0; idx < n; idx++) {
        attrp = fattrp;
        for (i = 0; i < n; i++) {
            if (attrp->id == idx) {
                packetp = (Packet*)(attrp->val);
                xspec = PkInfo2Str(packetp);
                if (xspec[0] != '\0') {
                    if (GLDefineNewFont(fontInfo, numberOfFontIDs, fontSet, xspec)) {
                        if (verbose)
                            fprintf(stderr, "Font used: %s[%d] = \"%s\"\n", fontSet, idx, xspec);
                        return idx;
                    }
                }
            }
            attrp = attrp->next;
        }
    }

    return -1;
}

/*
** window procedures
**
*/

Window GLOpenWindow(VObj* self, int x, int y, int width, int height, int isGlass)
{
    Window w, parentWindow = 0;
    int borderThickness;
    XSetWindowAttributes attrs;
    int inputOnlyWindowP = 0;
    char* window_name;
    char* argv = "viola";
    int argc = 1;
    extern Window topWindow;   /* Scott */
    extern int runInSubWindow; /* spider hack */

    if (width == 0)
        width = 1;
    if (height == 0)
        height = 1;

    borderThickness = borderStyleThickness[GET_border(self)];

    parentWindow = bossWindow(self);
    if (parentWindow == 0)
        parentWindow = rootWindow;

    /* Check if this is a popup dialog that should appear as a separate top-level window.
     * Dialog objects start with "res.dialog" and should not be confined to topWindow.
     */
    {
        const char* name = GET_name(self);
        int isPopupDialog = (name && strncmp(name, "res.dialog", 10) == 0);
        
        if (parentWindow == rootWindow && runInSubWindow && !isPopupDialog)
            parentWindow = topWindow;
    }

    if (isGlass) {
        attrs.event_mask = GET__eventMask(self);
        w = XCreateWindow(display, parentWindow, x, y, width, height, 0, /* border thickness */
                          0,                                             /* depth */
                          InputOnly,                                     /* class */
                          0,                                             /* visual*/
                          CWEventMask, &attrs);
    } else {
        ClassInfo* cip = GET__classInfo(self);
        if (cip == &class_slider) {
            if (shadingP)
                attrs.background_pixel = DefaultBGPixel_darkest;
            else
                attrs.background_pixel = FGPixel;
        } else {
            attrs.background_pixel = BGPixel;
        }
        attrs.border_pixel = BDPixel;
        attrs.event_mask = GET__eventMask(self);
        attrs.bit_gravity = StaticGravity;
        attrs.backing_store = NotUseful;
        attrs.cursor = 0;
        /* X11 border is drawn OUTSIDE the window, so reduce window size to fit */
        w = XCreateWindow(display, parentWindow, x, y, 
                          width - (borderThickness * 2), 
                          height - (borderThickness * 2), 
                          borderThickness,
                          CopyFromParent, CopyFromParent, CopyFromParent,
                          CWBorderPixel | CWEventMask | CWBackPixel | CWBitGravity | CWCursor,
                          &attrs);
    }
    if (!w)
        return 0;

    /* maybe the following stuff isn't necessary for
     * non-shell windows
     */
    if (parentWindow == rootWindow) {
        char* icon_name = "viola";
        XClassHint classHints;
        XSizeHints sizeHints;
        XWMHints wmHints;

#ifdef X11R3
        sizeHints.flags = PPosition | PSize | PMinSize | PMaxSize;
        sizeHints.x = x;
        sizeHints.y = y;
        sizeHints.width = width;
        sizeHints.height = height;
#else /* X11R4 or later */
        sizeHints.flags = USPosition | USSize | PMinSize | PMaxSize;
#endif
        sizeHints.min_width = GET_minWidth(self);
        sizeHints.min_height = GET_minHeight(self);
        sizeHints.max_width = GET_maxWidth(self);
        sizeHints.max_height = GET_maxHeight(self);

        if (!AllBlank(GET_label(self)))
            window_name = GET_label(self);
        else
            window_name = "viola";

#ifdef X11R3
        /* set Properties for window manager (always before mapping) */
        XSetStandardProperties(display, w, window_name, icon_name, violaPixmap, &argv, argc,
                               &sizeHints);
#else /* X11R4 or later */
        {
            /* format of the window name and icon name
             * arguments has changed in R4 */
            XTextProperty windowName, iconName;

            /* These calls store window_name and icon_name into
             * XTextProperty structures and set their other
             * fields properly. */
            if (!XStringListToTextProperty(&window_name, 1, &windowName)) {
                fprintf(stderr, "GLOpenWindow(): structure allocation for windowName failed.\n");
                exit(-1);
            }
            if (!XStringListToTextProperty(&icon_name, 1, &iconName)) {
                fprintf(stderr, "GLOpenWindow(): structure allocation for iconName failed.\n");
                exit(-1);
            }

            wmHints.initial_state = NormalState;
            wmHints.input = True;
            wmHints.icon_pixmap = violaPixmap;
            wmHints.flags = StateHint | IconPixmapHint | InputHint;

            classHints.res_name = GET_name(self);
            classHints.res_class = "Viola";

            XSetWMProperties(display, w, &windowName, &iconName, &argv, argc, &sizeHints, &wmHints,
                             &classHints);
            XSetClassHint(display, w, &classHints);
            XSetWMProtocols(display, w, &wm_delete_window, 1);

            sizeHints.x = x;
            sizeHints.y = y;
            sizeHints.width = width;
            sizeHints.height = height;
            sizeHints.min_width = GET_minWidth(self);
            sizeHints.min_height = GET_minHeight(self);
            sizeHints.max_width = GET_maxWidth(self);
            sizeHints.max_height = GET_maxHeight(self);
            sizeHints.flags = USPosition | USSize | PMinSize | PMaxSize;

            XSetWMNormalHints(display, w, &sizeHints);
        }
#endif
    }

    XMapWindow(display, w);

    SET_window(self, w);
    SET_visible(self, 0);

    if (!putHashEntry_replace(window2Obj, (intptr_t)w, (intptr_t)self)) {
        /* error recovery */
    }

    return w;
}

/*
 * GLRaiseWindow - raise window to top of stack
 * On macOS/XQuartz, XRaiseWindow alone may not be enough,
 * so we also use XMapRaised and XFlush.
 */
void GLRaiseWindow(Window w)
{
    if (w) {
        XMapRaised(display, w);
        XRaiseWindow(display, w);
        XFlush(display);
    }
}

/*
 */
void GLCloseWindow(Window w)
{
    if (w)
        XUnmapWindow(display, w);
}

int GLDestroyWindow(Window w)
{
    /* printf("destroyWindow (w = 0x%x = %ld)\n", w, w);*/
    XDestroyWindow(display, w);
    return 1;
}

int GLWindowSize(Window w, int * height, int * width)
{
    XWindowAttributes xwa;

    if (!w)
        return 0;
    if (XGetWindowAttributes(display, w, &xwa) == 0) {
        sprintf(buff, "windowSize(): XGetWindowAttributes() failed.\n");
        messageToUser(NULL, MESSAGE_ERROR, buff);
        *height = *width = 0;
    } else {
        *height = xwa.height;
        *width = xwa.width;
        return 1;
    }
    return 0;
}

int GLSetWindowName(Window w, char* windowName)
{
    if (XStoreName(display, w, windowName))
        return 1;
    return 0;
}

int GLSetIconName(Window w, char* iconName)
{
    extern int runInSubWindow; /* spider hack */

#ifdef X11R3
    /* how to do this in R3? does anyone care? */
    return 0;

#else /* X11R4 or later */
    if (!runInSubWindow) { /* Scott */
        XTextProperty iconNamep;
        if (XStringListToTextProperty(&iconName, 1, &iconNamep)) {
            XSetWMIconName(display, w, &iconNamep);
            return 1;
        }
    }
    return 0;
#endif
}

Window GLQueryWindow() {
    Window rootw, childw, w = rootWindow;
    unsigned int mask;
    int i; /* dummy */

    for (;;) {
        XQueryPointer(display, w, &rootw, &childw, &i, &i, &i, &i, &mask);
        if (!childw)
            return w;
        w = childw;
    }
}

/*
 * calculate an object's position relative to the root window
 */
void GLRootPosition(Window w, int *root_xp, int *root_yp)
{
    Window rw, pw, *cw;
    unsigned int i;

    if (w) {
        unsigned int dum;
        int x, y;

        /* probably not the best call to use */
        XQueryTree(display, w, &rw, &pw, &cw, &i);
        XFree(cw);
        XGetGeometry(display, w, &rw, &x, &y, &dum, &dum, &dum, &dum);
        if (pw == rw) {
            *root_xp = x; /* Should take into account border width*/
            *root_yp = y;
        } else {
            GLRootPosition(pw, root_xp, root_yp);
            *root_xp += x;
            *root_yp += y;
        }
    } else {
        *root_xp = 0;
        *root_yp = 0;
    }
}

Window GLQueryMouse(Window w, int * rootx, int * rooty, int * wx, int * wy)
{
    Window rootw, childw;
    unsigned int mask;

    XQueryPointer(display, w, &rootw, &childw, rootx, rooty, wx, wy, &mask);
    return childw;
}

/*
 *
 */
void GLChangeToBusyMouseCursor(Window w)
{
    /* using this mouseCursorIsBusy flag prevents different top-level windows
       from cross states
     */
    /*	if (mouseCursorIsBusy == 1) return;*/
    XDefineCursor(display, w, cursor_watch);
    XFlush(display);
    mouseCursorIsBusy = 1;
}

/*
 *
 */
void GLChangeToNormalMouseCursor(Window w)
{
    /*	if (mouseCursorIsBusy == 0) return;*/
    XDefineCursor(display, w, cursor_arrow);
    XFlush(display);
    mouseCursorIsBusy = 0;
}

/*
** line
**
*/
int GLPaintLine(Window w, GC gc, int x1, int y1, int x2, int y2)
{
    XDrawLine(display, w, gc, x1, y1, x2, y2);
    return 1;
}

/*
** Rectangle
**
*/
int GLPaintRect(Window w, GC gc, int x1, int y1, int x2, int y2)
{
    XPoint pts[5];

    pts[0].x = x1;
    pts[0].y = y1;
    pts[1].x = x2;
    pts[1].y = y1;
    pts[2].x = x2;
    pts[2].y = y2;
    pts[3].x = x1;
    pts[3].y = y2;
    pts[4].x = x1;
    pts[4].y = y1;

    XDrawLines(display, w, gc, pts, 5, CoordModeOrigin);
    return 1;
}

/*
 * paints the rectangle with opposite corners (x0,y0) and (x1,y1)
 * to background in w.
 */
int GLPaintFillRect(Window w, GC gc, int x0, int y0, int x1, int y1)
{
    XFillRectangle(display, w, gc, x0, y0, x1 - x0 + 1, y1 - y0 + 1);
    return 1;
}

/*
** filled polygon (for rotated rectangles, ellipses, etc)
*/
int GLPaintFillPolygon(Window w, GC gc, int* px, int* py, int npoints)
{
    XPoint points[256];  /* Support up to 256 points for smooth curves */
    int i;
    int shape = Convex;  /* Assume convex by default */
    
    if (npoints > 256) npoints = 256;
    
    /* Use Complex hint for many-sided polygons (ellipse approximations) */
    if (npoints > 8) {
        shape = Complex;
    }
    
    for (i = 0; i < npoints; i++) {
        points[i].x = px[i];
        points[i].y = py[i];
    }
    XFillPolygon(display, w, gc, points, npoints, shape, CoordModeOrigin);
    return 1;
}

/*
** circle/oval
**
*/
int GLPaintOval(Window w, GC gc, int x, int y, int width, int height)
{
    XDrawArc(display, w, gc, x, y, width, height, 90 * 64, 360 * 64);
    return 1;
}

int GLPaintFillOval(Window w, GC gc, int x, int y, int width, int height)
{
    XFillArc(display, w, gc, x, y, width, height, 90 * 64, 360 * 64);
    return 1;
}

int GLPaintFillArc(Window w, GC gc, int x, int y, int width, int height, int degree1, int degree2)
{
    XFillArc(display, w, gc, x, y, width, height, degree1 * 64, degree2 * 64);
    return 1;
}

/*
** text
**
*/
int GLDefineNewFont(FontInfo* fontInfo, int id, char* fontReferenceName, char* fontPatternName)
{
    Font font;
    int i;
    char** clist;

    if (id < 0 || id >= MAXFONTS) {
        sprintf(buff, "GLDefineNewFont: Illegal font number %d.\n", id);
        messageToUser(NULL, MESSAGE_ERROR, buff);
        return 0;
    }
    /* first see if the font is already loaded, to reduce X calls */
    /* XXX
     * ToDo:
     * 	For fonts, don't load until actually needed...
     * 	Slso, check to see if the font is already loaded under another
     * 	name...
     */

    clist = XListFonts(display, fontPatternName, 1, &i);
    if (i > 0) {
        if ((font = XLoadFont(display, clist[0]))) {
            FontFont(id) = font;
            FontRef(id) = saveString(fontReferenceName);
            FontSpec(id) = saveString(clist[0]);
            GLUpdateFontInfo(fontInfo, id);
            XFreeFontNames(clist);
            return 1;
        }
        XFreeFontNames(clist);
    }
    {
        char mbuff[256];
        sprintf(mbuff, "Couldn't load any font matching \"%s\"\n", fontPatternName);
        messageToUser(NULL, MESSAGE_WARNING, mbuff);
    }
    return 0;
}

int GLUpdateFontInfo(FontInfo* fontInfo, int id)
{
    static XFontStruct* xfontStruct = NULL;
    int i;

    /* Font is X11 XID (opaque uint), not a pointer; 0 means unloaded. */
    if (id < 0 || id >= MAXFONTS || FontFont(id) == (Font)0) {
        sprintf(buff, "setFontInfo(id=%d): Invalid font id.\n", id);
        messageToUser(NULL, MESSAGE_ERROR, buff);
        return 0;
    }
    xfontStruct = XQueryFont(display, FontFont(id));
    if (!xfontStruct)
        return 0;

    FontFontStruct(id) = xfontStruct;
    FontMaxWidth(id) = xfontStruct->max_bounds.width;
    FontMaxHeight(id) = xfontStruct->ascent + xfontStruct->descent;
    FontDescent(id) = xfontStruct->descent;

    if (!FontWidths(id))
        FontWidths(id) = (int*)malloc(sizeof(int) * 400);
    if (!FontWidths(id))
        return 0;

    if (xfontStruct->per_char) {
        int min_char = xfontStruct->min_char_or_byte2;
        int max_char = xfontStruct->max_char_or_byte2;

        for (i = 0; i < min_char; i++) {
            FontWidths(id)[i] = 0;
        }
        for (; i < 400; i++) {
            /* Check if character is within font's range */
            if (i >= min_char && i <= max_char) {
                int idx = i - min_char;
                FontWidths(id)[i] = xfontStruct->per_char[idx].width;
            } else if (i >= 32 && i < 255) {
                /* Character outside font range - use max_bounds width */
                FontWidths(id)[i] = xfontStruct->max_bounds.width;
            } else {
                FontWidths(id)[i] = 1;
            }
        }
    } else {
        for (i = 0; i < 255; i++)
            FontWidths(id)[i] = xfontStruct->min_bounds.width;
        for (; i < 400; i++)
            FontWidths(id)[i] = 1; /*XXX still gross */
    }
    /*	printf("\n");*/

    /* XXX just a safty check. Remove after confirmation */
    if (FontWidths(id)[' '] == 0) {
        fprintf(stderr,
                "Font initialization error #1. font id = %d. Please report this to "
                "viola-bugs@xcf.berkeley.edu\n",
                id);
        FontWidths(id)[' '] = xfontStruct->per_char[i - xfontStruct->min_char_or_byte2].width;
        if (FontWidths(id)[' '] == 0) {
            FontWidths(id)[' '] = FontWidths(id)['n'];
            fprintf(stderr,
                    "Font initialization error #2. font id = %d. Please report this to "
                    "viola-bugs@xcf.berkeley.edu\n",
                    id);
        }
    }

    /*FontDescent(id) = FontDescent(id) = fontStruct->max_bounds.descent;*/
    /*XFreeFontNames(clist);*/

    return 1;
}

/* currently assumes that all fonts are of equal width */
int GLTextWidth(int fontID, char* str)
{
    return XTextWidth(FontFontStruct(fontID), str, (int)strlen(str));
}

int GLTextHeight(int fontID, char* str)
{
    return FontMaxHeight(fontID);
}

int GLPaintText(Window w, GC gc, int fontID, int x0, int y0, char* str)
{
    XTextItem item;
    item.chars = str;
    item.nchars = (int)strlen(str);
    item.delta = 0;
    item.font = FontFont(fontID);

    XDrawText(display, w, gc, x0, y0 + FontMaxHeight(fontID) - FontDescent(fontID), &item, 1);
    return 1;
}

int GLPaintTextLength(Window w, GC gc, int fontID, int x0, int y0, char* str, int length)
{
    XTextItem item;
    item.chars = str;
    item.nchars = length;
    item.delta = 0;
    item.font = FontFont(fontID);

    XDrawText(display, w, gc, x0, y0 + FontMaxHeight(fontID) - FontDescent(fontID), &item, 1);
    return 1;
}

/*
 * GLPaintTextTransformed - Draw text with rotation and scaling using XRender
 * rotZ is in degrees, scaleX/scaleY are scale factors (1.0 = normal)
 * axisX/axisY: rotation center (0,0 = use text center)
 */
int GLPaintTextTransformed(Window w, GC gc, int fontID, int x0, int y0, 
                           char* str, double rotZ, double scaleX, double scaleY,
                           int axisX, int axisY)
{
    if (!str || !*str) return 0;
    
    int textWidth = GLTextWidth(fontID, str);
    int textHeight = FontMaxHeight(fontID);
    
    /* If no transformation needed, use simple text drawing */
    if ((rotZ < 0.001 && rotZ > -0.001) && 
        (scaleX > 0.999 && scaleX < 1.001) && 
        (scaleY > 0.999 && scaleY < 1.001)) {
        return GLPaintText(w, gc, fontID, x0, y0, str);
    }
    
    /* Create a pixmap with alpha channel for transformed text */
    /* Need space for diagonal (rotation) and scale */
    double diagonal = sqrt((double)(textWidth * textWidth + textHeight * textHeight));
    double maxScale = (scaleX > scaleY) ? scaleX : scaleY;
    if (maxScale < 1.0) maxScale = 1.0;
    int pixSize = (int)(diagonal * maxScale * 1.5) + 40;
    if (pixSize < (int)(textWidth * maxScale) + 40) pixSize = (int)(textWidth * maxScale) + 40;
    if (pixSize < 1) pixSize = 1;
    if (pixSize > 1000) pixSize = 1000;  /* Reasonable limit */
    
    /* Find ARGB32 format for alpha support */
    XRenderPictFormat* argbFormat = XRenderFindStandardFormat(display, PictStandardARGB32);
    XRenderPictFormat* rgbFormat = XRenderFindVisualFormat(display, 
        DefaultVisual(display, screenNumber));
    if (!argbFormat || !rgbFormat) {
        return GLPaintText(w, gc, fontID, x0, y0, str);  /* Fallback */
    }
    
    /* Create 32-bit pixmap for alpha */
    Pixmap textPix = XCreatePixmap(display, w, pixSize, pixSize, 32);
    if (!textPix) {
        return GLPaintText(w, gc, fontID, x0, y0, str);  /* Fallback */
    }
    
    /* Create picture with ARGB format */
    XRenderPictureAttributes pa;
    memset(&pa, 0, sizeof(pa));
    Picture srcPic = XRenderCreatePicture(display, textPix, argbFormat, 0, &pa);
    if (!srcPic) {
        XFreePixmap(display, textPix);
        return GLPaintText(w, gc, fontID, x0, y0, str);
    }
    
    /* Clear to transparent (alpha=0) */
    XRenderColor transColor = {0, 0, 0, 0};
    XRenderFillRectangle(display, PictOpSrc, srcPic, &transColor, 0, 0, pixSize, pixSize);
    
    /* Get current foreground color for text */
    XGCValues gcv;
    XGetGCValues(display, gc, GCForeground, &gcv);
    XColor xcolor;
    xcolor.pixel = gcv.foreground;
    XQueryColor(display, DefaultColormap(display, screenNumber), &xcolor);
    
    /* Draw text as solid color with full alpha */
    XRenderColor textColor;
    textColor.red = xcolor.red;
    textColor.green = xcolor.green;
    textColor.blue = xcolor.blue;
    textColor.alpha = 0xFFFF;
    
    /* Create a solid color picture for the text color */
    XRenderPictureAttributes solidPa;
    solidPa.repeat = True;
    Pixmap solidPix = XCreatePixmap(display, w, 1, 1, 32);
    Picture solidPic = XRenderCreatePicture(display, solidPix, argbFormat, CPRepeat, &solidPa);
    XRenderFillRectangle(display, PictOpSrc, solidPic, &textColor, 0, 0, 1, 1);
    
    /* Create 1-bit mask from text */
    Pixmap maskPix = XCreatePixmap(display, w, pixSize, pixSize, 1);
    GC maskGC = XCreateGC(display, maskPix, 0, NULL);
    XSetForeground(display, maskGC, 0);
    XFillRectangle(display, maskPix, maskGC, 0, 0, pixSize, pixSize);
    XSetForeground(display, maskGC, 1);
    
    /* Draw text into mask, centered */
    int tx = pixSize / 2 - textWidth / 2;
    int ty = pixSize / 2 - textHeight / 2 + textHeight - FontDescent(fontID);
    XSetFont(display, maskGC, FontFont(fontID));
    XDrawString(display, maskPix, maskGC, tx, ty, str, (int)strlen(str));
    XFreeGC(display, maskGC);
    
    /* Create mask picture (A1 format) */
    XRenderPictFormat* a1Format = XRenderFindStandardFormat(display, PictStandardA1);
    Picture maskPicture = XRenderCreatePicture(display, maskPix, a1Format, 0, NULL);
    
    /* Composite: solid color through text mask onto srcPic */
    XRenderComposite(display, PictOpOver, solidPic, maskPicture, srcPic,
                     0, 0, 0, 0, 0, 0, pixSize, pixSize);
    
    XRenderFreePicture(display, solidPic);
    XRenderFreePicture(display, maskPicture);
    XFreePixmap(display, solidPix);
    XFreePixmap(display, maskPix);
    
    /* Now apply rotation transform to srcPic */
    /* Rotation around axis point, or center if axis not specified */
    double radians = rotZ * M_PI / 180.0;
    double cosR = cos(radians);
    double sinR = sin(radians);
    double cx, cy;
    if (axisX != 0 || axisY != 0) {
        /* Convert screen axis to pixmap coordinates
         * Text top-left in pixmap is at (pixSize/2 - textWidth/2, pixSize/2 - textHeight/2)
         * Screen (x0, y0) maps to that point
         */
        cx = axisX - x0 + (pixSize / 2.0 - textWidth / 2.0);
        cy = axisY - y0 + (pixSize / 2.0 - textHeight / 2.0);
    } else {
        /* Default: center of pixmap (center of text) */
        cx = pixSize / 2.0;
        cy = pixSize / 2.0;
    }
    
    /* Transform: translate to origin, scale, rotate, translate back */
    /* XRender transform is inverse (dst->src), so we use inverse operations */
    /* Combined matrix for scale + rotation around (cx,cy):
     * Scale factors are inverted (1/scale) because of inverse transform
     */
    double invSX = 1.0 / scaleX;
    double invSY = 1.0 / scaleY;
    
    /* Matrix: translate(-cx,-cy) * rotate(-angle) * scale(1/sx,1/sy) * translate(cx,cy) */
    double a = cosR * invSX;
    double b = sinR * invSX;
    double c = -sinR * invSY;
    double d = cosR * invSY;
    double trX = cx - cx * a - cy * c;
    double trY = cy - cx * b - cy * d;
    
    XTransform xform = {{
        { XDoubleToFixed(a), XDoubleToFixed(c), XDoubleToFixed(trX) },
        { XDoubleToFixed(b), XDoubleToFixed(d), XDoubleToFixed(trY) },
        { XDoubleToFixed(0), XDoubleToFixed(0), XDoubleToFixed(1) }
    }};
    XRenderSetPictureTransform(display, srcPic, &xform);
    
    /* Create destination picture */
    Picture dstPic = XRenderCreatePicture(display, w, rgbFormat, 0, NULL);
    
    /* Composite rotated text to destination
     * Position matching GLPaintText: top-left at (x0, y0)
     * So text center should be at (x0 + textWidth/2, y0 + textHeight/2)
     */
    int destX = x0 + textWidth / 2 - pixSize / 2;
    int destY = y0 + textHeight / 2 - pixSize / 2;
    
    XRenderComposite(display, PictOpOver, srcPic, None, dstPic,
                     0, 0, 0, 0, destX, destY, pixSize, pixSize);
    
    /* Cleanup */
    XRenderFreePicture(display, srcPic);
    XRenderFreePicture(display, dstPic);
    XFreePixmap(display, textPix);
    
    return 1;
}
/* End of GLPaintTextTransformed */

/*
** bitmap
**
*/
Pixmap GLMakeXBMFromASCII(Window w, char* bitmapStr, unsigned int* width, unsigned int* height,
                          int* hotx, int* hoty) {
    Pixmap bitmap;
    static char* tmpfile = NULL;

    /* Use file-based approach on all platforms to avoid XmuReadBitmapData issues
     * peter@hpkslx.mayfield.HP.COM */
    if (!tmpfile) {
        tmpfile = saveString("/tmp/violaXXXXXX");
        int fd = mkstemp(tmpfile);
        if (fd == -1) {
            free(tmpfile);
            tmpfile = NULL;
            return 0;
        }
        close(fd);
    }
    if (saveFile(tmpfile, bitmapStr) != 0) {
        unlink(tmpfile);
        return 0;
    }
    if (XReadBitmapFile(display, w, tmpfile, width, height, &bitmap, hotx, hoty) == 0) {
        unlink(tmpfile);
        return bitmap;
    }
    unlink(tmpfile);
    return 0;
}

Pixmap GLMakeXPMFromASCII(Window w, char* bitmapStr, unsigned int* width, unsigned int* height,
                          int* hotx, int* hoty) {
    static char* tmpFile = NULL;
    XpmAttributes* attributes;
    Pixmap pixmap, mask;
    int status;

    /* Allocate XpmAttributes on heap to avoid stack corruption */
    attributes = (XpmAttributes*)malloc(sizeof(XpmAttributes));
    if (!attributes) {
        *width = 1;
        *height = 1;
        *hotx = 0;
        *hoty = 0;
        return 0;
    }

    /* Initialize XpmAttributes structure */
    memset(attributes, 0, sizeof(XpmAttributes));
    attributes->valuemask = 0;
    attributes->colorsymbols = xpm_symbols;
    attributes->numsymbols = xpm_numsymbols;
    attributes->valuemask = xpm_valuemask;

    /* Set visual, colormap and depth for proper color rendering on 64-bit */
    attributes->visual = DefaultVisual(display, DefaultScreen(display));
    attributes->colormap = DefaultColormap(display, DefaultScreen(display));
    attributes->depth = (unsigned int)DefaultDepth(display, DefaultScreen(display));
    attributes->valuemask |= XpmVisual | XpmColormap | XpmDepth;

    attributes->valuemask |= XpmReturnInfos;
    attributes->valuemask |= XpmReturnPixels;

    if (!tmpFile) {
        /* should be able to avoid this kludge soon, when
         * XPM functions take as data string or file pointer...
         */
        tmpFile = saveString("/tmp/violaXXXXXX");
        int fd = mkstemp(tmpFile);
        if (fd == -1) {
            free(attributes);
            free(tmpFile);
            tmpFile = NULL;
            return 0;
        }
        close(fd);
    }
    if (saveFile(tmpFile, bitmapStr) != 0) {
        unlink(tmpFile);
        free(attributes);
        return 0;
    }

    status = XpmReadFileToPixmap(display, w, tmpFile, &pixmap, &mask, attributes);
    unlink(tmpFile);
    if (status != XpmSuccess) {
        free(attributes);
        *width = 1;
        *height = 1;
        *hotx = 0;
        *hoty = 0;
        return 0;
    }
    *width = attributes->width;
    *height = attributes->height;
    *hotx = attributes->x_hotspot;
    *hoty = attributes->y_hotspot;

    free(attributes);
    return pixmap;
}

int GLDisplayXBMFromASCII(Window w, int x, int y, char* bitmapStr)
{
    Pixmap bitmap;
    unsigned int width, height;
    int hotx, hoty;

    if (!w || !bitmapStr)
        return 0;

    bitmap = GLMakeXBMFromASCII(w, bitmapStr, &width, &height, &hotx, &hoty);
    if (!bitmap)
        return 0;
    XSetBackground(display, gc_fg, BGPixel); /* this is convoluted */
    XCopyPlane(display, bitmap, w, gc_fg, 0, 0, width, height, x, y, (unsigned long)1);
    return 1;
}

int GLDisplayXPMFromASCII(Window w, int x, int y, char* bitmapStr)
{
    Pixmap bitmap;
    unsigned int width, height;
    int hotx, hoty;

    if (!w || !bitmapStr)
        return 0;

    bitmap = GLMakeXPMFromASCII(w, bitmapStr, &width, &height, &hotx, &hoty);
    if (!bitmap)
        return 0;
    XCopyPlane(display, bitmap, w, gc_fg, 0, 0, width, height, x, y, (unsigned long)1);
    return 1;
}

int GLDisplayXBM(Window w, int x, int y, int width, int height, Pixmap bitmap)
{
    if (!w || !bitmap)
        return 0;

    XSetBackground(display, gc_fg, BGPixel); /* this is convoluted */
    XCopyPlane(display, bitmap, w, gc_fg, 0, 0, width, height, x, y, (unsigned long)1);
    return 1;
}

int GLDisplayXBMBG(Window w, int x, int y, int width, int height, Pixmap bitmap, int bitmapWidth, int bitmapHeight)
{
    Pixmap pix;

    if (!w || !bitmap)
        return 0;

    pix = XCreatePixmap(display, w, bitmapWidth, bitmapHeight, (unsigned long)screenDepth);
    XCopyPlane(display, bitmap, pix, gc_copy, 0, 0, bitmapWidth, bitmapHeight, 0, 0,
               (unsigned long)1);
    XSetWindowBackgroundPixmap(display, w, pix);

    XFreePixmap(display, pix);

    return 1;
}

int GLDisplayXPM(Window w, int x, int y, int width, int height, Pixmap bitmap)
{
    if (!w || !bitmap)
        return 0;
    XCopyArea(display, bitmap, w, gc_copy, 0, 0, width, height, 0, 0);
    return 1;
}

int GLDisplayXPMBG(Window w, int x, int y, int width, int height, Pixmap bitmap)
{
    if (!w || !bitmap)
        return 0;
    XSetWindowBackgroundPixmap(display, w, bitmap);
#ifdef DEBUG_XCLEARAREA
    XClearWindow(display, w);
    XFlush(display);
#endif
    return 1;
}

int GLFreeXBM(Pixmap bitmap)
{
    XFreePixmap(display, bitmap);
    return 1;
}

int GLFreeXPM(Pixmap bitmap)
{
    /*	XFreePixmap(display, bitmap);*/
    return 1;
}

XImage* GLReadBitmapImage(Window w, XImage* image, char* filename)
{
    unsigned int width, height;
    int x_hot, y_hot;
    int status;
    Pixmap pixmap;

    status = XReadBitmapFile(display, w, filename, &width, &height, &pixmap, &x_hot, &y_hot);
    if (status != BitmapSuccess) {
        sprintf(buff, "XReadBitmapFile(\"%s\",...) failed with status %d.\n", filename, status);
        messageToUser(NULL, MESSAGE_ERROR, buff);
        return 0;
    }
    image->format = XYBitmap;
    image->width = width;
    image->height = height;
    image->bytes_per_line = (width + 7) / 8;
    return image;
}

/*
** widget drawings
**
*/
void GLDrawBorder(Window w, int x1, int y1, int x2, int y2, int style, int relief)
{
    GC ltGC, dkGC;

    switch (style) {
    case BORDER_NONE:
    case BORDER_BORDER:
    case BORDER_FIELD:
    case BORDER_MENU:
        break;

    case BORDER_BUTTON: {
        if (shadingP) {
            ltGC = gc_bg_lighter;
            dkGC = gc_bg_darker;
        } else {
            ltGC = gc_mesh;
            dkGC = gc_fg;
        }
        /* left edge */
        XDrawLine(display, w, ltGC, x1, y1, x1, y2);
        XDrawLine(display, w, ltGC, x1 + 1, y1, x1 + 1, y2 - 1);

        /* top edge */
        XDrawLine(display, w, ltGC, x1, y1, x2, y1);
        XDrawLine(display, w, ltGC, x1, y1 + 1, x2 - 1, y1 + 1);

        /* right edge */
        XDrawLine(display, w, dkGC, x2, y1 + 1, x2, y2);
        XDrawLine(display, w, dkGC, x2 - 1, y1 + 2, x2 - 1, y2);

        /* bottom edge */
        XDrawLine(display, w, dkGC, x1 + 1, y2, x2, y2);
        XDrawLine(display, w, dkGC, x1 + 2, y2 - 1, x2, y2 - 1);
        /*
                        XSetForeground(display, gc_mesh, BDPixel);
                        XSetBackground(display, gc_mesh, BGPixel);
                        XDrawRectangle(display, w, gc_mesh, x1, y2-1, x2-x1-1, 1);
                        XDrawRectangle(display, w, gc_mesh, x2-1, y1, 1, y2-y1-1);
                        XDrawLine(display, w, gc_bd, x1, y1, x2-1, y1);
                        XDrawLine(display, w, gc_bd, x1+1, y1+1, x2-1, y1+1);
                        XDrawLine(display, w, gc_bd, x1, y1, x1, y2-1);
                        XDrawLine(display, w, gc_bd, x1+1, y1+1, x1+1, y2-1);
        */
    } break;

    case BORDER_THINBUTTON: {
        XSetForeground(display, gc_dash, BDPixel);
        XDrawLine(display, w, gc_bd, x1, y1, x2 - 1, y1);
        XDrawLine(display, w, gc_dash, x1, y2 - 1, x2 - 1, y2 - 1);
        XDrawLine(display, w, gc_bd, x1, y1, x1, y2 - 1);
        XDrawLine(display, w, gc_dash, x2 - 1, y1, x2 - 1, y2 - 1);
    } break;

    case BORDER_SUBWINDOW:
        XDrawLine(display, w, gc_subWindow, x1, y1, x2, y1);
        XDrawLine(display, w, gc_subWindow, x1, y1, x1, y2);
        XDrawLine(display, w, gc_subWindow, x1 - 1, y2, x2 - 1, y2);
        XDrawLine(display, w, gc_subWindow, x2, y1 - 1, x2, y2 - 1);
        break;

    case BORDER_SINK:
        if (shadingP) {
            ltGC = gc_bg_lighter;
            dkGC = gc_bg_darker;
        } else {
            ltGC = gc_mesh;
            dkGC = gc_fg;
        }
        /* left edge */
        XDrawLine(display, w, dkGC, x1, y1, x1, y2);
        XDrawLine(display, w, dkGC, x1 + 1, y1, x1 + 1, y2 - 1);

        /* top edge */
        XDrawLine(display, w, dkGC, x1, y1, x2, y1);
        XDrawLine(display, w, dkGC, x1, y1 + 1, x2 - 1, y1 + 1);

        /* right edge */
        XDrawLine(display, w, ltGC, x2, y1 + 1, x2, y2);
        XDrawLine(display, w, ltGC, x2 - 1, y1 + 2, x2 - 1, y2);

        /* bottom edge */
        XDrawLine(display, w, ltGC, x1 + 1, y2, x2, y2);
        XDrawLine(display, w, ltGC, x1 + 2, y2 - 1, x2, y2 - 1);
        break;

    default:
    case BORDER_BOX:
        XDrawLine(display, w, gc_bd, x1, y1, x2, y1);
        XDrawLine(display, w, gc_bd, x1, y1, x1, y2);
        XDrawLine(display, w, gc_bd, x1 - 1, y2, x2 - 1, y2);
        XDrawLine(display, w, gc_bd, x2, y1 - 1, x2, y2 - 1);
        break;
    }
}

void GLEraseBorder(Window w, int x1, int y1, int x2, int y2, int style)
{

    switch (style) {
    case BORDER_FIELD:
    case BORDER_BORDER:
    case BORDER_NONE:
        break;

    case BORDER_BUTTON: {
        XDrawLine(display, w, gc_bg, x1, y1, x2 - 1, y1);
        XDrawLine(display, w, gc_bg, x1 + 1, y1 + 1, x2 - 2, y1 + 1);

        XDrawLine(display, w, gc_bg, x1 + 1, y2 - 2, x2 - 1, y2 - 2);
        XDrawLine(display, w, gc_bg, x1, y2 - 1, x2 - 1, y2 - 1);

        XDrawLine(display, w, gc_bg, x1, y1, x1, y2 - 1);
        XDrawLine(display, w, gc_bg, x1 + 1, y1 + 1, x1 + 1, y2 - 2);

        XDrawLine(display, w, gc_bg, x2 - 2, y1 + 1, x2 - 2, y2 - 2);
        XDrawLine(display, w, gc_bg, x2 - 1, y1, x2 - 1, y2 - 1);
    } break;

    default:
    case BORDER_BOX:
        XDrawLine(display, w, gc_bd, x1, y1, x2, y1);
        XDrawLine(display, w, gc_bd, x1, y1, x1, y2);
        XDrawLine(display, w, gc_bd, x1 - 1, y2, x2 - 1, y2);
        XDrawLine(display, w, gc_bd, x2, y1 - 1, x2, y2 - 1);
        break;
    }
}

int GLDrawRubberFrame(VObj* self, int x1, int y1, int x2, int y2)
{
    Window w = 0;
    if (GET__parent(self))
        w = bossWindow(GET__parent(self));
    if (w) {
        XDrawLine(display, w, gc_subWindow, x1, y1, x2, y1);
        XDrawLine(display, w, gc_subWindow, x1, y1, x1, y2);
        XDrawLine(display, w, gc_subWindow, x1, y2, x2, y2);
        XDrawLine(display, w, gc_subWindow, x2, y1, x2, y2);
    }
    return 1;
}

void GLDrawScrollBarH(Window w, int width, int start, int end, int thickness)
{
    /*
            if (BDPixel == BGPixel) {
                    XSetForeground(display, gc_dash, FGPixel);
                    XSetBackground(display, gc_dash, BGPixel);
                    XSetForeground(display, gc_bd, FGPixel);
            } else {
                    XSetForeground(display, gc_dash, BDPixel);
            }
    */
    XClearArea(display, w, 0, 0, start, thickness + 1, False);
    XClearArea(display, w, end, 0, width - end, thickness + 1, False);

    /* clear background for the dash lines...*/
    if (lookAndFeel == LAF_BARE) {
        XSetBackground(display, gc_mesh, BGPixel);
        XSetForeground(display, gc_mesh, FGPixel);
        XFillRectangle(display, w, gc_mesh, start, 3, end - start + 1, thickness - 5);

    } else {
        GC ltGC, dkGC;

        if (shadingP) {
            ltGC = gc_bg_lighter;
            XFillRectangle(display, w, gc_bg_default, start, 3, end - start, thickness - 4);
        } else {
            ltGC = gc_mesh;
            XFillRectangle(display, w, gc_bg, start, 3, end - start, thickness - 4);
        }

        /* outer top */
        XDrawLine(display, w, ltGC, start, 1, end - 1, 1);
        /* inner top */
        XDrawLine(display, w, ltGC, start + 1, 2, end - 2, 2);
        /* outer left */
        XDrawLine(display, w, ltGC, start, 1, start, thickness - 1);
        /* inner left */
        XDrawLine(display, w, ltGC, start + 1, 2, start + 1, thickness);
    }
#ifdef OLDMETHOD
    /*XXXXX use stippled rectangle for dashing... */
    XFillRectangle(display, w, gc_fg, start, 3, end - start, thickness - 4);

    /* outer top */
    XDrawLine(display, w, gc_bd, start, 1, end - 1, 1);
    /* inner top */
    XDrawLine(display, w, gc_bd, start + 1, 2, end - 2, 2);

    /* outer bottom */
    XDrawLine(display, w, gc_bd, start, thickness, end - 1, thickness);
    /* inner bottom */
    XDrawLine(display, w, gc_bd, start + 1, thickness - 1, end - 2, thickness - 1);

    /* outer left */
    XDrawLine(display, w, gc_bd, start, 1, start, thickness - 1);
    /* inner left */
    XDrawLine(display, w, gc_bd, start + 1, 2, start + 1, thickness);

    /* outer right */
    XDrawLine(display, w, gc_dash, end - 1, 1, end - 1, thickness);
    /* inner right */
    XDrawLine(display, w, gc_dash, end - 2, 2, end - 2, thickness - 1);

    XSetForeground(display, gc_dash, FGPixel);
    /* outer right (background) */
    XDrawLine(display, w, gc_dash, end - 1, 2, end - 1, thickness - 2);
    /* inner right (background) */
    XDrawLine(display, w, gc_dash, end - 2, 3, end - 2, thickness - 2);
    /* outer bottom (background) */
    XDrawLine(display, w, gc_dash, start + 1, thickness - 1, end - 2, thickness - 1);
#endif
}

void GLDrawScrollBarV(Window w, int height, int start, int end, int thickness)
{
    /*	if (BDPixel == BGPixel) {
                    XSetForeground(display, gc_dash, FGPixel);
                    XSetBackground(display, gc_dash, BGPixel);
            } else {
                    XSetForeground(display, gc_dash, BDPixel);
            }
            XSetForeground(display, gc_bd, BDPixel);
    */
    XClearArea(display, w, 0, 0, thickness, start, False);
    XClearArea(display, w, 0, end + 1, thickness, height - end, False);

    /* clear background for the dash lines...*/
    if (lookAndFeel == LAF_BARE) {

        XSetBackground(display, gc_mesh, BGPixel);
        XSetForeground(display, gc_mesh, FGPixel);
        XFillRectangle(display, w, gc_mesh, 2, start, thickness - 3, end - start + 1);
    } else {
        GC ltGC, dkGC;

        if (shadingP) {
            ltGC = gc_bg_lighter;
            /* bar */
            XFillRectangle(display, w, gc_bg_default, 4, start, thickness - 4, end - start);
        } else {
            ltGC = gc_mesh;
            /* bar */
            XFillRectangle(display, w, gc_bg, 4, start, thickness - 4, end - start);
        }

        /* outer top */
        XDrawLine(display, w, ltGC, 2, start, thickness, start);
        /* inner top */
        XDrawLine(display, w, ltGC, 3, start + 1, thickness - 1, start + 1);

        /* outer left */
        XDrawLine(display, w, ltGC, 2, start, 2, end);
        /* inner left */
        XDrawLine(display, w, ltGC, 3, start, 3, end - 1);
    }

#ifdef OLDMETHOD
    /*XXXXX use stippled rectangle for dashing... */
    XFillRectangle(display, w, gc_fg, 3, start, thickness - 5, end - start + 1);
    /* outer top */
    XDrawLine(display, w, gc_bd, 1, start, thickness - 1, start);
    /* inner top */
    XDrawLine(display, w, gc_bd, 2, start + 1, thickness - 2, start + 1);

    /* outer bottom */
    XDrawLine(display, w, gc_dash, 1, end, thickness - 1, end);
    /* inner bottom */
    XDrawLine(display, w, gc_dash, 2, end - 1, thickness - 2, end - 1);

    /* outer left */
    XDrawLine(display, w, gc_bd, 1, start, 1, end);
    /* inner left */
    XDrawLine(display, w, gc_bd, 2, start, 2, end - 1);

    /* outer right */
    XDrawLine(display, w, gc_dash, thickness - 1, start, thickness - 1, end);
    /* inner right */
    XDrawLine(display, w, gc_dash, thickness - 2, start + 1, thickness - 2, end - 1);

    XSetForeground(display, gc_dash, FGPixel);
    /* outer right (background) */
    XDrawLine(display, w, gc_dash, thickness - 1, start + 1, thickness - 1, end - 1);

    /* inner right (background) */
    XDrawLine(display, w, gc_dash, thickness - 2, start + 2, thickness - 2, end - 1);

    /* outer bottom (background) */
    XDrawLine(display, w, gc_dash, 2, end, thickness - 1, end);
#endif
}

void GLDrawDial(Window w, int x, int y, int radius, int degree, int style)
{
    int diameter;
    int tangent_x, tangent_y;
    int sx, sy;
    double theta;

    sx = x - radius;
    sy = y - radius;
    diameter = radius * 2;
    radius = radius - 2;
    theta = (double)(degree)*RADIAN_TO_DEGREE_RATIO;
    tangent_x = (int)(cos(theta) * (double)radius) + x;
    tangent_y = (int)(-sin(theta) * (double)radius) + y;

    XClearWindow(display, w);
#ifdef DEBUG_XCLEARAREA
    XFlush(display);
#endif

    /* draw the circle */
    XDrawArc(display, w, gc_fg, sx, sy, diameter, diameter, 90 * 64, 360 * 64);

    /* draw the degree indicator */
    XDrawLine(display, w, gc_fg, x, y, tangent_x, tangent_y);
}

/*
** widget geometry
*/
void GLUpdateGeometry(int parentWindowIsRoot, Window w, int x, int y, int width, int height)
{
    XWindowChanges wc;

    if (!w)
        return;

    /*	fprintf(stderr,
                    "GLUpdateGeometry: rootP=%d: %d %d %d %d\n",
                    parentWindowIsRoot, x, y, width, height);
    */
    wc.x = x;
    wc.y = y;

    wc.width = width;
    if (wc.width < 1)
        wc.width = 1;

    if (parentWindowIsRoot)
        wc.height = height - 20;
    else
        wc.height = height;
    if (wc.height < 1)
        wc.height = 1;

    XConfigureWindow(display, w, CWX | CWY | CWWidth | CWHeight, &wc);
}

void GLUpdatePosition(int parentWindowIsRoot, Window w, int x, int y)
{
    if (parentWindowIsRoot) {
        XSetWindowAttributes attrs;

        attrs.override_redirect = True;
        XChangeWindowAttributes(display, w, CWOverrideRedirect, &attrs);
        XMoveWindow(display, w, x, y);
        attrs.override_redirect = False;
        XChangeWindowAttributes(display, w, CWOverrideRedirect, &attrs);
    } else {
        XWindowChanges wc;

        wc.x = x;
        wc.y = y;
        XConfigureWindow(display, w, CWX | CWY, &wc);
    }
}

void GLUpdateSize(int parentWindowIsRoot, Window w, int width, int height)
{
    if (parentWindowIsRoot) {
        XSetWindowAttributes attrs;

        attrs.override_redirect = True;
        XChangeWindowAttributes(display, w, CWOverrideRedirect, &attrs);
        XResizeWindow(display, w, width, height);
        attrs.override_redirect = False;
        XChangeWindowAttributes(display, w, CWOverrideRedirect, &attrs);
    } else {
        XWindowChanges wc;

        wc.width = width;
        wc.height = height;
        XConfigureWindow(display, w, CWWidth | CWHeight, &wc);
    }
}

ColorInfo* GLInitColorInfo() {
    ColorInfo* colorInfo;

    if ((colorInfo = (ColorInfo*)malloc(sizeof(struct ColorInfoStruct)))) {
        colorInfo->fg = colorInfo->bg = colorInfo->cr = colorInfo->bd = NULL;
    }
    return colorInfo;
}

int approximateColor(int r, unsigned g, unsigned b)
{
    int i, d, mdist = 100000, close = -1;

    if (!dc) {
        if (dispcells < 256)
            dc = dispcells;
        else
            dc = 256;
        /* read in the color table */
        for (i = 0; i < dc; i++)
            ctab[i].pixel = i;
    }
    XQueryColors(theDisp, theCmap, ctab, dc);

    /* run through the used colors.  any used color that has a pixel
       value of 0xffff wasn't allocated.  for such colors, run through
       the entire X colormap and pick the closest color */

    for (i = 0; i < dc; i++) {
        d = abs(r - ctab[i].red) + abs(g - ctab[i].green) + abs(b - ctab[i].blue);
        /*		print("%d: %d %d %d   d=%d, mdist=%d\n", i,
                                ctab[i].red, ctab[i].green, ctab[i].blue, d, mdist);
        */
        if (d < mdist) {
            mdist = d;
            close = i;
        }
    }

    if (close >= 0) {
        /*
        print("glib_x: approximated RGB => [%d] %d %d %d ==> %d %d %d   mdist=%d\n",
        close, r, g, b, ctab[close].red, ctab[close].green, ctab[close].blue, mdist);
        */
        return (int)ctab[close].pixel;
    }
    return 0;
}
int callCount_GLSetColor = 0;

int GLSetColor(ColorStruct** colorpp, char* colorname, char* defaultColorName, long defaultPixel)
{
    ColorStruct* cs;
    XColor exactcolor;
    long oldIndex;
    char fc = colorname[0];
    int initP;

    ++callCount_GLSetColor;

    if (*colorpp == NULL)
        initP = 1;
    else
        initP = 0;

    if (!initP)
        oldIndex = (*colorpp)->xcolor.pixel;

    if (fc == '\0') {
        if (!initP)
            releaseColor(*colorpp);
        if (!(cs = getColorStruct(defaultColorName))) {
            *colorpp = addColorStructByString(saveString(defaultColorName));
            (*colorpp)->xcolor.pixel = defaultPixel;
        }
        if (!initP)
            GLUpdateColorReference(oldIndex, (*colorpp)->xcolor.pixel);
        return 1;
    }
    if (!initP)
        releaseColor(*colorpp);

    cs = getColorStruct(colorname);
    if (cs) {
        *colorpp = cs;
        cs->refc++;
        return 1;
    }
    cs = addColorStructByString(saveString(colorname));
    *colorpp = cs;

    if (fc >= '0' && fc <= '9') {
        /* color name should be of RGB format "<r> <g> <b>"
         * in percentages, ie: "100 0 0" for red.
         *
         * XXXX don't use extractWord which copies ...
         */
        extractWord(colorname, 1, 1, buff);
        cs->xcolor.red = atoi(buff) * 650;
        extractWord(colorname, 2, 2, buff);
        cs->xcolor.green = atoi(buff) * 650;
        extractWord(colorname, 3, 3, buff);
        cs->xcolor.blue = atoi(buff) * 650;

        cs->xcolor.flags = DoRed | DoGreen | DoBlue;

        if (XAllocColor(display, colormap, &(cs->xcolor))) {
            if (!initP)
                GLUpdateColorReference(oldIndex, cs->xcolor.pixel);
            return 1;
        } else {
            int approxColorPixel =
                approximateColor(cs->xcolor.red, cs->xcolor.green, cs->xcolor.blue);
            if (approxColorPixel && !initP) {
                GLUpdateColorReference(oldIndex, approxColorPixel);
                return 1;
            }
        }
    } else {
        if (XAllocNamedColor(display, colormap, colorname, &(cs->xcolor), &exactcolor)) {
            if (!initP)
                GLUpdateColorReference(oldIndex, cs->xcolor.pixel);
            return 1;
        } else {
            int approxColorPixel;

            if (!XParseColor(display, colormap, colorname, &(cs->xcolor))) {
                /* something messed up */
                return 0;
            }
            /*
                                    cs->xcolor.red = exactcolor.red;
                                    cs->xcolor.green = exactcolor.green;
                                    cs->xcolor.blue = exactcolor.blue;
            */
            approxColorPixel = approximateColor(cs->xcolor.red, cs->xcolor.green, cs->xcolor.blue);
            if (approxColorPixel && !initP) {
                GLUpdateColorReference(oldIndex, approxColorPixel);
                return 1;
            }
        }
    }

    sprintf(buff, "failed to allocate '%s' color. setting to default background color\n",
            colorname);
    messageToUser(NULL, MESSAGE_WARNING, buff);

    (*colorpp)->xcolor.pixel = defaultPixel;

    if (!initP)
        GLUpdateColorReference(oldIndex, (*colorpp)->xcolor.pixel);

    return 0;
}

int GLSetBDColor(VObj* self, char* colorname)
{
    Window w = GET_window(self);
    ColorInfo* colorInfo = GET__colorInfo(self);

    if (!colorInfo)
        return 0;
    if (!GLSetColor(&(colorInfo->bd), colorname, BD_COLOR, DefaultBDPixel))
        return 0;
    if (w)
        XSetWindowBorder(display, w, colorInfo->bd->xcolor.pixel);
    return 1;
}

int GLSetBGColor(VObj* self, char* colorname)
{
    Window w = GET_window(self);
    ColorInfo* colorInfo = GET__colorInfo(self);

    if (!colorInfo)
        return 0;
    if (!GLSetColor(&(colorInfo->bg), colorname, BG_COLOR, DefaultBGPixel))
        return 0;
    if (w)
        XSetWindowBackground(display, w, colorInfo->bg->xcolor.pixel);

    return 1;
}

int GLSetBGColorPixel(VObj* self, unsigned long pixel)
{
    Window w = GET_window(self);
    ColorInfo* colorInfo = GET__colorInfo(self);
    if (w)
        XSetWindowBackground(display, w, pixel);
    return 1;
}

int GLSetFGColor(VObj* self, char* colorname)
{
    ColorInfo* colorInfo = GET__colorInfo(self);

    if (!colorInfo)
        return 0;
    if (!GLSetColor(&(colorInfo->fg), colorname, FG_COLOR, DefaultFGPixel))
        return 0;

    return 1;
}

/* Reset link colors to default (black) - called when stylesheet is loaded */
void GLResetLinkColors(void)
{
    XSetForeground(display, gc_link, DefaultFGPixel);
    XSetForeground(display, gc_link_visited, DefaultFGPixel);
}

/* Set color for unvisited links from STG stylesheet */
void GLSetLinkColor(char* colorname)
{
    XColor linkColor;
    if (colorname && colorname[0] &&
        XParseColor(display, colormap, colorname, &linkColor) &&
        XAllocColor(display, colormap, &linkColor)) {
        XSetForeground(display, gc_link, linkColor.pixel);
    }
}

/* Set color for visited links from STG stylesheet */
void GLSetLinkVisitedColor(char* colorname)
{
    XColor visitedColor;
    if (colorname && colorname[0] &&
        XParseColor(display, colormap, colorname, &visitedColor) &&
        XAllocColor(display, colormap, &visitedColor)) {
        XSetForeground(display, gc_link_visited, visitedColor.pixel);
    }
}

int GLSetCRColor(VObj* self, char* colorname)
{
    ColorInfo* colorInfo = GET__colorInfo(self);

    if (!colorInfo)
        return 0;
    if (!GLSetColor(&(colorInfo->cr), colorname, CR_COLOR, DefaultCRPixel))
        return 0;

    return 1;
}

char* GLGetBDColor(VObj* self)
{
    ColorInfo* colorInfo = GET__colorInfo(self);
    return colorInfo->bd->name;
}

char* GLGetBGColor(VObj* self)
{
    ColorInfo* colorInfo = GET__colorInfo(self);
    return colorInfo->bg->name;
}

char* GLGetFGColor(VObj* self)
{
    ColorInfo* colorInfo = GET__colorInfo(self);
    return colorInfo->fg->name;
}

char* GLGetCRColor(VObj* self)
{
    ColorInfo* colorInfo = GET__colorInfo(self);
    return colorInfo->cr->name;
}

unsigned long prevBDPixel = ~0UL;
unsigned long prevBGPixel = ~0UL;
unsigned long prevCRPixel = ~0UL;
unsigned long prevFGPixel = ~0UL;

ColorInfo* GLPrepareObjColor(VObj* self)
{
    ColorInfo* colorInfo = GET__colorInfo(self);

    if (colorInfo == NULL)
        return NULL;

    if (colorInfo->bd)
        BDPixel = colorInfo->bd->xcolor.pixel;
    else
        BDPixel = DefaultBDPixel;

    if (colorInfo->bg)
        BGPixel = colorInfo->bg->xcolor.pixel;
    else
        BGPixel = DefaultBGPixel;

    if (colorInfo->fg)
        FGPixel = colorInfo->fg->xcolor.pixel;
    else
        FGPixel = DefaultFGPixel;

    if (colorInfo->cr)
        CRPixel = colorInfo->cr->xcolor.pixel;
    else
        CRPixel = DefaultCRPixel;

    /* sigh... this isn't right. so much for GCs!
     */
    if (BGPixel != prevBGPixel) {
        XSetForeground(display, gc_bg, BGPixel);
        XSetBackground(display, gc_copy, BGPixel);
    }
    if (FGPixel != prevFGPixel) {
        XSetForeground(display, gc_fg, FGPixel);
        XSetForeground(display, gc_copy, FGPixel);
        XSetForeground(display, gc_dash, FGPixel);
        XSetForeground(display, gc_copy0, FGPixel);
        XSetForeground(display, gc_mesh, FGPixel);
    }
    if (BDPixel != prevBDPixel) {
        XSetForeground(display, gc_bd, BDPixel);
    }
    if (CRPixel != prevCRPixel) {
        XSetForeground(display, gc_cr, CRPixel);
    }
    prevBDPixel = BDPixel;
    prevBGPixel = BGPixel;
    prevFGPixel = FGPixel;
    prevCRPixel = CRPixel;

    if (numOfDisplayColors > 2)
        return colorInfo;

    /*XXX NOT GOOD
     * precaution against displaying foreground to be same as
     * background color.
     */
    /*
            if ((colorInfo->fg != NULL) && (colorInfo->bg != NULL))
              if (colorInfo->fg->xcolor.pixel == colorInfo->bg->xcolor.pixel)
                    if (strcmp(colorInfo->fg->name, colorInfo->bg->name))
                            if (colorInfo->fg->xcolor.pixel == DefaultFGPixel)
                                    colorInfo->fg->xcolor.pixel = DefaultBGPixel;
                            else
                                    colorInfo->fg->xcolor.pixel = DefaultFGPixel;
    */
    return colorInfo;
}

void GLDumpColorRef() {
    int i;

    for (i = 0; i < numOfDisplayColors; i++)
        printf("%d: %d\n", i, colorReferenceTable[i]);
}

/*
 * keep count of color
 * if the object's current color is no longer needed
 */
void GLUpdateColorReference(long oldColorIndex, unsigned long newColorIndex)
{
    if (oldColorIndex != -1)
        --colorReferenceTable[oldColorIndex];
    ++colorReferenceTable[newColorIndex];

    if (oldColorIndex != -1) {
        if (colorReferenceTable[oldColorIndex] <= 0) {
            long pixarray[1];

            /*
             * since no other viola object is using this colormap
             * entry, try to free it, so other applications or
             * future viola objects can use it.
             */
            pixarray[0] = oldColorIndex;
            /*
                                    XFreeColors(display, colormap, pixarray, 1,
                                                    (unsigned long)0);
                                    printf("freed %ld\n", oldColorIndex);
            */
        }
    }
}

/*
** renounce selection duty
**
*/
void GLClearSelection() {
    extern VObj* xselectionObj;

    if (xselectionObj) {
        if (validObjectP(xselectionObj)) {
            /*printf("GLClearSelection: %s\n",
                    GET_name(xselectionObj));*/
            sendMessage1(xselectionObj, "clearSelection");
        } else {
            xselectionObj = NULL;
        }
    } else {
        if (sharedSelectionBuffer)
            free(sharedSelectionBuffer);
        sharedSelectionBuffer = NULL;
    }
    XSetSelectionOwner(display, XA_PRIMARY, None, CurrentTime);
}

/*
** get content of the X cut buffer
*/
int GLGetSelection(Packet* result)
{
    extern VObj* xselectionObj;
    int n;

    /*	printf("GLGetSelection: %s\n", GET_name(xselectionObj));*/
    if (xselectionObj) {
        if (validObjectP(xselectionObj)) {
            return callMeth(xselectionObj, result, 0, NULL, STR__getSelection);
        } else {
            xselectionObj = NULL;
        }
    }
    if (sharedSelectionBuffer) {
        result->info.s = SaveString(sharedSelectionBuffer);
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        return 1;
    }
    result->info.s = XFetchBuffer(display, &n, 0);
    result->type = PKT_STR;
    result->canFree = 0; /*?*/
    return 1;
}

/*
** set cut buffer
**
*/
int GLSetSelection(VObj* self, char* val)
{
    extern VObj* xselectionObj;
    Window w = GET_window(self);

    if (val) {
        if (sharedSelectionBuffer)
            free(sharedSelectionBuffer);
        sharedSelectionBuffer = val;
        xselectionObj = NULL;
    } else {
        xselectionObj = self;
        if (w) {
            /*printf("GLSetSelection: %s\n",
                            GET_name(xselectionObj));*/
            XSetSelectionOwner(display, XA_PRIMARY, w, CurrentTime);
            if (sharedSelectionBuffer)
                free(sharedSelectionBuffer);
            sharedSelectionBuffer = NULL;
            return 1;
        } else {
            xselectionObj = NULL;
            XSetSelectionOwner(display, XA_PRIMARY, None, CurrentTime);
        }
    }
    return 0;
}

XImage* GLGIFLoad(char* id, char* fname, Window w, int x, int y, int width, int height, int * actual_w, int * actual_h, XImage** theImgp)
{
#ifdef USE_XGIF_PACKAGE
    XImage* expImg;

    theImage = NULL;
    gif_reset();
    LoadGIF(fname);
    *theImgp = theImage;

    if (!theImage)
        return NULL;

    iWIDE = theImage->width;
    iHIGH = theImage->height;
    *actual_w = theImage->width;
    *actual_h = theImage->height;

    /* how goofy... this is how to get the picture in its natural size */
    if (width == 0 || width == 1)
        eWIDE = iWIDE * expand;
    else
        eWIDE = width;
    if (height == 0 || height == 1)
        eHIGH = iHIGH * expand;
    else
        eHIGH = height;

    if (eWIDE > displayWidth)
        eWIDE = displayWidth;
    if (eHIGH > displayHeight)
        eHIGH = displayHeight;

    expImg = GLGIFResize(w, eWIDE, eHIGH, *actual_w, *actual_h, theImage, NULL);
    return expImg;
#endif
#ifdef USE_XLOADIMAGE_PACKAGE
    /*	Image *image;*/
    XImageInfo* ximageinfo;
    ImgNode* inp;

    /*	stat = loadImg(fname, &ximageinfo, actual_w, actual_h);*/

    inp = imgNodeRefInc(id, fname);

    if (inp == NULL) {
        *actual_w = 0;
        *actual_h = 0;
        *theImgp = NULL;
        return NULL;
    }
    /*printf("GLGIFLoad(%s) STAT(imp)=%x\n", fname, inp);*/
    if (inp == 0)
        return NULL;
    ximageinfo = inp->ximageinfo;
    if (!ximageinfo)
        return NULL;

    *theImgp = ximageinfo->ximage;
    *actual_w = inp->width;
    *actual_h = inp->height;

    /*	printf("MADE image (%d,%d)\n", *actual_w, *actual_h);*/

    return ximageinfo->ximage;
#endif
}

XImage* GLGIFResize(Window win, int w, int h, int actual_w, int actual_h, XImage* theImg, XImage* expImg)
{
#ifdef USE_XGIF_PACKAGE
    int ix, iy, ex, ey;
    byte *ximag, *ilptr, *ipptr, *elptr, *epptr;
    static char* rstr = "Resizing Image.  Please wait...";

    iWIDE = actual_w;
    iHIGH = actual_h;

    /* warning:  this code'll only run machines where int=32-bits */

    if (w == iWIDE && h == iHIGH) { /* very special case */
        if (expImg != theImg) {
            if (expImg)
                XDestroyImage(expImg);
            expImg = theImg;
            eWIDE = iWIDE;
            eHIGH = iHIGH;
        }
    }

    else { /* have to do some work */
           /* if it's a big image, this'll take a while.  mention it */
        if (win) {
            if (w * h > (500 * 500)) {
                XDrawImageString(display, win, gc, CENTERX(mfinfo, w / 2, rstr),
                                 CENTERY(mfinfo, h / 2), rstr, strlen(rstr));
                XFlush(display);
            }
        }
        /* first, kill the old expImg, if one exists */
        if (expImg && expImg != theImg) {
            free(expImg->data);
            expImg->data = NULL;
            XDestroyImage(expImg);
        }

        /* create expImg of the appropriate size */

        eWIDE = w;
        eHIGH = h;
        ximag = (byte*)malloc(w * h);

        if (dispcells <= 2)
            expImg = XCreateImage(theDisp, theVisual, 1, ZPixmap, 0, ximag, eWIDE, eHIGH, 8, eWIDE);
        else
            expImg = XCreateImage(theDisp, theVisual, 8, ZPixmap, 0, ximag, eWIDE, eHIGH, 8, eWIDE);

        if (!ximag || !expImg) {
            fprintf(stderr, "ERROR: unable to create a %dx%d image\n", w, h);
            exit(0);
        }

        elptr = epptr = (byte*)expImg->data;

        for (ey = 0; ey < eHIGH; ey++, elptr += eWIDE) {
            extern byte* Image; /*XXX ICK*/

            iy = (iHIGH * ey) / eHIGH;
            epptr = elptr;
            /*ilptr = (byte *) theImg->data + (iy * iWIDE);*/
            ilptr = (byte*)Image + (iy * iWIDE);
            for (ex = 0; ex < eWIDE; ex++, epptr++) {
                ix = (iWIDE * ex) / eWIDE;
                ipptr = ilptr + ix;
                *epptr = *ipptr;
                if (dispcells <= 2) {
                    XPutPixel(expImg, ex, ey, (unsigned long)*ipptr);
                }
            }
        }
    }
    return expImg;
#endif
#ifdef USE_XLOADIMAGE_PACKAGE
    printf("GLResize() called. Not supported\n");

    return theImg;
#endif
}

int GLGIFDraw(Window w, XImage* img, int x, int y, int width, int height)
{
    int draw_width, draw_height;
    
    /* Limit drawing to actual image size to avoid reading beyond buffer */
    if (img) {
        draw_width = (width > img->width) ? img->width : width;
        draw_height = (height > img->height) ? img->height : height;
        
        /* If window is bigger than image, clear the window first to avoid garbage */
        if (width > img->width || height > img->height) {
            XClearArea(display, w, x, y, width, height, False);
        }
    } else {
        draw_width = width;
        draw_height = height;
    }
    
    XSetBackground(display, gc, BGPixel); /* XXXX LAME and INEFFICIENT */
    XSetForeground(display, gc, FGPixel);
    return XPutImage(display, w, gc, img, 0, 0, x, y, draw_width, draw_height);
}

/*
 * may be called by ../libGIF/xloadgif.c
 */
void FatalError(char* identifier)
{
    if (verbose)
        fprintf(stderr, "libGIF: %s: %s\n", cmd, identifier);
}

#ifdef NEED_A_CLUE
/*
 * For some reason, the linker can't find XtMalloc in libXt...?
 */
XtMalloc(x) int x;
{
    return malloc(x);
}
#endif

char xresourceBuff[1000];
/*
 * caller must not alter or free returned string.
 * (can't alter because of value from XGetDefault() is owned by xlib)
 */
char* GLGetResource(char* name)
{
    int status;
    char* strType[20];
    char class[80];
    XrmValue val;

    if (resDB) {
        status = XrmGetResource(resDB, name, name, strType, &val);
        if (status) {
            strncpy(xresourceBuff, val.addr, (int)val.size);
            return xresourceBuff;
        }
        strcpy(class, name);
        if (class[0] >= 'a' && class[0] <= 'z')
            class[0] -= 'a' - 'A';
        status = XrmGetResource(resDB, name, class, strType, &val);
        if (status) {
            strncpy(xresourceBuff, val.addr, (int)val.size);
            return xresourceBuff;
        }
    }
    return XGetDefault(display, "Viola", name);
}

void freeGLibResources() {
    if (resDB)
        XrmDestroyDatabase(resDB);
}

ColorStruct* getColorStruct(char* str)
{
    HashEntry* entry;

    if ((entry = colorNameShareDB->get(colorNameShareDB, (long)str)))
        return (ColorStruct*)entry->val;

    return NULL;
}

ColorStruct* addColorStructByString(char* str)
{
    HashEntry* entry;
    ColorStruct* cs;

    entry = colorNameShareDB->put(colorNameShareDB, (long)str, 0);
    if (!entry)
        return NULL;
    cs = (ColorStruct*)malloc(sizeof(struct ColorStruct));
    entry->val = (long)cs;
    cs->refc = 1;
    cs->name = saveString(str);
    return cs;
}

ColorStruct* addColorName(char* str)
{
    HashEntry* entry;
    ColorStruct* cs;

    entry = colorNameShareDB->get(colorNameShareDB, (long)str);
    if (!entry) {
        entry = colorNameShareDB->put(colorNameShareDB, (long)str, 0);
        if (!entry)
            return NULL;
        cs = (ColorStruct*)entry->val;
        cs = (ColorStruct*)entry->val;
        cs->refc = 1;
        cs->name = saveString(str);
    } else {
        cs = (ColorStruct*)entry->val;
        cs->refc++;
    }
    return cs;
}

void releaseColor(ColorStruct* colorp)
{
    if (--(colorp->refc) <= 0) {
        HashEntry* entry;
        ColorStruct* cs;

        colorNameShareDB->remove(colorNameShareDB, (long)(colorp->name));
        /*free the color struct*/
    }
}

void releaseColorByString(char* name)
{
    HashEntry* entry;
    ColorStruct* cs;

    entry = colorNameShareDB->get(colorNameShareDB, (long)name);
    if (!entry)
        return;

    cs = (ColorStruct*)entry->val;
    cs->refc--;
    if (cs->refc <= 0) {
        /*free the color struct*/
    }
}

void purgeImg() {
    ImgNode* ip = imgNodes;

    for (ip = imgNodes; ip; ip = ip->next) {
        /* free ximageinfo */
        ip->ximageinfo = NULL;
    }
}

ImgNode* imgNodeRefInc(char* id, char* filename)
{
    ImgNode* ip = imgNodes;
    int stat;
    char* localFilePath;
    Packet result, argv;

    /*
      printf("imgNodeRefInc: id='%s' filename='%s'\n",
            (id?id:"<none>"),(filename?filename:"<none>"));
    */

    if (ip) {
        for (; ip; ip = ip->next) {
            if (!strcmp(id, ip->id)) {
                /*printf("imgNodeRefInc: ip->id='%s'\n", ip->id);*/
                if (ip->ximageinfo == NULL) {

                    /*printf("imgNodeRefInc: BINGO ip->id='%s'  filename(already local)='%s'\n",
                             ip->id, ip->filename);
                    */
                    stat = loadImg(ip->filename, &(ip->ximageinfo), &(ip->width), &(ip->height));
                    if (stat == 0)
                        return NULL;
                }
                ip->refc++;
                return ip;
            }
        }
    }
    /* determine if id-URL is local... if not, do HTTP */
    /* If id starts with '/', it's already a local file path - use directly */
    if (id[0] == '/') {
        localFilePath = id;
    } else {
        nullPacket(&result);
        nullPacket(&argv);
        argv.info.s = id;
        argv.type = PKT_STR;
        meth_generic_HTTPGet(NULL, &result, 1, &argv);
        localFilePath = result.info.s;
        if (localFilePath == NULL)
            return NULL;
    }

    /* make new node */
    ip = (ImgNode*)malloc(sizeof(struct ImgNode));
    ip->id = saveString(id);
    ip->filename = saveString(localFilePath);
    ip->ximageinfo = NULL;
    ip->refc = 1;
    if (imgNodes) {
        ip->next = imgNodes;
    } else {
        ip->next = NULL;
    }
    
    /* Check if this is an XPM file (by checking original id, not temp file) - try direct load with libXPM first */
    char* ext = strrchr(id, '.');
    if (ext && !strcmp(ext, ".xpm")) {
        /* Try loading XPM format 3 directly using XpmReadFileToImage */
        XpmAttributes attributes;
        XImage *ximage = NULL, *shapemask = NULL;
        int status;
        
        memset(&attributes, 0, sizeof(XpmAttributes));
        attributes.valuemask = XpmReturnPixels | XpmReturnInfos;
        
        status = XpmReadFileToImage(display, localFilePath, &ximage, &shapemask, &attributes);
        
        if (status == XpmSuccess && ximage) {
            /* XPM format 3 loaded successfully via libXPM */
            ip->ximageinfo = (XImageInfo*)malloc(sizeof(XImageInfo));
            ip->ximageinfo->ximage = ximage;
            ip->width = attributes.width;
            ip->height = attributes.height;
            
            XpmFreeAttributes(&attributes);
            if (shapemask)
                XDestroyImage(shapemask);
            
            imgNodes = ip;
            return ip;
        } else {
            /* XpmReadFileToImage failed (possibly XPM format 1) - try via loadImg */
            XpmFreeAttributes(&attributes);
            /* Don't free ip yet, we'll try the standard path below */
        }
    }
    
    /* Load other formats through loadImg */
    stat = loadImg(ip->filename, &(ip->ximageinfo), &(ip->width), &(ip->height));
    if (stat == 0) {
        free(ip->id);
        free(ip->filename);
        free(ip);
        return NULL;
    }
    imgNodes = ip;
    return ip;
}

int imgNodeRefDec(char* id)
{
    ImgNode *last_ip = NULL, *ip, *next_ip;

    for (ip = imgNodes; ip; ip = ip->next) {
        if (!strcmp(id, ip->id)) {
            if (--(ip->refc) <= 0) {
                next_ip = ip->next;
                /* destroy ip*/
                /* free ip->ximageinfo*/
                free(ip->id);
                free(ip->filename);
                free(ip);
                if (last_ip)
                    last_ip->next = next_ip;
                else
                    imgNodes = NULL;
                return 0;
            }
        }
        last_ip = ip;
    }
    return 0;
}

int GLShadeColor(int orig_red, int orig_green, int orig_blue, float shade)
{
    XColor xcolor;
    int newPixel;

    /*	printf("orig rgb= %d, %d, %d   shade=%f\n",
                    orig_red, orig_green, orig_blue, shade);
    */
    orig_red *= shade;
    xcolor.red = (orig_red < 64000) ? orig_red : 64000;
    orig_green *= shade;
    xcolor.green = (orig_green < 64000) ? orig_green : 64000;
    orig_blue *= shade;
    xcolor.blue = (orig_blue < 64000) ? orig_blue : 64000;
    /*
            printf("want rgb= %d, %d, %d\n",
                    xcolor.red, xcolor.green, xcolor.blue);
    */
    if (XAllocColor(display, colormap, &xcolor)) {
        newPixel = xcolor.pixel;
        /*		printf("result pixel=%d  (%d %d %d)\n",
                                xcolor.pixel, xcolor.red, xcolor.green, xcolor.blue);
        */
        return newPixel;
    } else {
        printf("can't allocate shaded color. approximating.\n");
        newPixel = approximateColor(70 * 650, 70 * 650, 70 * 650);
        if (!newPixel)
            return -1;
        return newPixel;
    }
}
