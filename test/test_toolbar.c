/*
 * test_toolbar.c - EXACT copy of ViolaWWW header area
 * 
 * Row 1: [Globe in black frame] | [Title + URL]
 * Row 2: [Viola][HOME][BACK][PREV][NEXT][RELOAD][CLONE]
 * ----- black line appears here during resize -----
 * Content area
 */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <Xm/Xm.h>
#include <Xm/Form.h>
#include <Xm/Frame.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static String fallback_resources[] = {
    "*background: antiqueWhite4",
    "*foreground: black",
    NULL,
};

static Display* dpy;
static unsigned long bgPixel;
static unsigned long blackPixel;

/* Row 1: Title area with globe */
static Window titleRowWin;      /* Container for row 1 */
static Window globeWin;         /* Globe icon - black background! */
static Window titleTextWin;     /* Title + URL text */

/* Row 2: Toolbar */
static Window toolbarRowWin;    /* Container for row 2 */

#define BORDER_THICKNESS 1
#define GLOBE_WIDTH 90
#define ROW1_HEIGHT 70
#define ROW2_HEIGHT 38

static void clearWindowTree(Window win)
{
    Window root, parent;
    Window* children = NULL;
    unsigned int nchildren = 0;
    unsigned int i;
    
    XClearArea(dpy, win, 0, 0, 0, 0, True);
    
    if (XQueryTree(dpy, win, &root, &parent, &children, &nchildren)) {
        for (i = 0; i < nchildren; i++) {
            clearWindowTree(children[i]);
        }
        if (children) XFree(children);
    }
}

static void drawGlobe(Window win)
{
    XWindowAttributes attrs;
    GC gc;
    
    XGetWindowAttributes(dpy, win, &attrs);
    gc = XCreateGC(dpy, win, 0, NULL);
    
    /* Black background like original */
    XSetForeground(dpy, gc, blackPixel);
    XFillRectangle(dpy, win, gc, 0, 0, attrs.width, attrs.height);
    
    /* Draw circle for globe */
    XSetForeground(dpy, gc, bgPixel);
    XFillArc(dpy, win, gc, 10, 5, 50, 50, 0, 360*64);
    
    XFreeGC(dpy, gc);
}

static void drawTitleText(Window win)
{
    XWindowAttributes attrs;
    GC gc;
    
    XGetWindowAttributes(dpy, win, &attrs);
    gc = XCreateGC(dpy, win, 0, NULL);
    
    XSetForeground(dpy, gc, bgPixel);
    XFillRectangle(dpy, win, gc, 0, 0, attrs.width, attrs.height);
    
    XSetForeground(dpy, gc, blackPixel);
    XDrawString(dpy, win, gc, 20, 30, "The World Wide Web project", 26);
    XDrawString(dpy, win, gc, 20, 50, "http://info.cern.ch/hypertext/WWW/TheProject.html", 49);
    
    /* Border */
    XDrawRectangle(dpy, win, gc, 0, 0, attrs.width - 1, attrs.height - 1);
    
    XFreeGC(dpy, gc);
}

static void drawToolbar(Window win)
{
    XWindowAttributes attrs;
    GC gc;
    
    XGetWindowAttributes(dpy, win, &attrs);
    gc = XCreateGC(dpy, win, 0, NULL);
    
    XSetForeground(dpy, gc, bgPixel);
    XFillRectangle(dpy, win, gc, 0, 0, attrs.width, attrs.height);
    
    XSetForeground(dpy, gc, blackPixel);
    XDrawString(dpy, win, gc, 5, 25, "[Viola] [HOME] [BACK] [PREV] [NEXT] [RELOAD] [CLONE]", 51);
    
    XFreeGC(dpy, gc);
}

static void handleExpose(XExposeEvent* ev)
{
    if (ev->window == globeWin) {
        drawGlobe(ev->window);
    } else if (ev->window == titleTextWin) {
        drawTitleText(ev->window);
    } else if (ev->window == toolbarRowWin) {
        drawToolbar(ev->window);
    } else if (ev->window == titleRowWin) {
        /* Just fill with bg */
        GC gc = XCreateGC(dpy, ev->window, 0, NULL);
        XWindowAttributes attrs;
        XGetWindowAttributes(dpy, ev->window, &attrs);
        XSetForeground(dpy, gc, bgPixel);
        XFillRectangle(dpy, ev->window, gc, 0, 0, attrs.width, attrs.height);
        XFreeGC(dpy, gc);
    }
}

static void resizeHandler(Widget w, XtPointer clientData, XEvent *event, Boolean *cont)
{
    if (event->type == ConfigureNotify) {
        clearWindowTree(XtWindow(w));
        XSync(dpy, False);
    }
}

static void formResizeEH(Widget w, XtPointer clientData, XEvent* event, Boolean* cont)
{
    Dimension width, height;
    
    if (event->type != ConfigureNotify) return;
    if (!titleRowWin) return;
    
    XtVaGetValues(w, XmNwidth, &width, XmNheight, &height, NULL);
    
    /* Row 1: Title area */
    XMoveResizeWindow(dpy, titleRowWin, 0, 0, width, ROW1_HEIGHT);
    XMoveResizeWindow(dpy, globeWin, 0, 0, GLOBE_WIDTH, ROW1_HEIGHT - 2);
    XMoveResizeWindow(dpy, titleTextWin, GLOBE_WIDTH + 2, 0, 
                      width - GLOBE_WIDTH - 4, ROW1_HEIGHT - 2);
    
    /* Row 2: Toolbar - BELOW row 1 */
    XMoveResizeWindow(dpy, toolbarRowWin, 0, ROW1_HEIGHT, width, ROW2_HEIGHT);
    
    /* Clear all */
    XClearArea(dpy, titleRowWin, 0, 0, 0, 0, True);
    XClearArea(dpy, globeWin, 0, 0, 0, 0, True);
    XClearArea(dpy, titleTextWin, 0, 0, 0, 0, True);
    XClearArea(dpy, toolbarRowWin, 0, 0, 0, 0, True);
    
    XSync(dpy, False);
}

static void createWindows(Widget container)
{
    Window parentWin = XtWindow(container);
    XSetWindowAttributes attrs;
    Dimension width, height;
    
    XtVaGetValues(container, XmNwidth, &width, XmNheight, &height, NULL);
    
    /* Row 1: Title area container */
    attrs.background_pixel = bgPixel;
    attrs.border_pixel = bgPixel;
    attrs.event_mask = ExposureMask | StructureNotifyMask;
    attrs.backing_store = Always;
    
    titleRowWin = XCreateWindow(dpy, parentWin,
                                 0, 0, width, ROW1_HEIGHT,
                                 0,  /* no border on container */
                                 CopyFromParent, CopyFromParent, CopyFromParent,
                                 CWBackPixel | CWBorderPixel | CWEventMask | CWBackingStore,
                                 &attrs);
    
    /* Globe - BLACK background, in black frame */
    attrs.background_pixel = blackPixel;
    attrs.border_pixel = blackPixel;
    
    globeWin = XCreateWindow(dpy, titleRowWin,
                              0, 0, GLOBE_WIDTH, ROW1_HEIGHT - 2,
                              BORDER_THICKNESS,
                              CopyFromParent, CopyFromParent, CopyFromParent,
                              CWBackPixel | CWBorderPixel | CWEventMask | CWBackingStore,
                              &attrs);
    
    /* Title text area */
    attrs.background_pixel = bgPixel;
    attrs.border_pixel = bgPixel;
    
    titleTextWin = XCreateWindow(dpy, titleRowWin,
                                  GLOBE_WIDTH + 2, 0,
                                  width - GLOBE_WIDTH - 4, ROW1_HEIGHT - 2,
                                  BORDER_THICKNESS,
                                  CopyFromParent, CopyFromParent, CopyFromParent,
                                  CWBackPixel | CWBorderPixel | CWEventMask | CWBackingStore,
                                  &attrs);
    
    /* Row 2: Toolbar */
    toolbarRowWin = XCreateWindow(dpy, parentWin,
                                   0, ROW1_HEIGHT, width, ROW2_HEIGHT,
                                   0,
                                   CopyFromParent, CopyFromParent, CopyFromParent,
                                   CWBackPixel | CWBorderPixel | CWEventMask | CWBackingStore,
                                   &attrs);
    
    XMapWindow(dpy, titleRowWin);
    XMapWindow(dpy, globeWin);
    XMapWindow(dpy, titleTextWin);
    XMapWindow(dpy, toolbarRowWin);
    
    printf("Created:\n");
    printf("  Row1 (title): 0x%lx\n", titleRowWin);
    printf("    Globe: 0x%lx\n", globeWin);
    printf("    TitleText: 0x%lx\n", titleTextWin);
    printf("  Row2 (toolbar): 0x%lx\n", toolbarRowWin);
}

int main(int argc, char *argv[])
{
    XtAppContext app;
    Widget shell, form, headerArea, contentFrame;
    XEvent event;
    Pixel motifBg;
    
    XtSetLanguageProc(NULL, NULL, NULL);
    
    shell = XtVaAppInitialize(&app, "TestToolbar", NULL, 0,
                              &argc, argv, fallback_resources,
                              XmNwidth, 700,
                              XmNheight, 400,
                              NULL);
    
    dpy = XtDisplay(shell);
    blackPixel = BlackPixel(dpy, DefaultScreen(dpy));
    
    form = XtVaCreateManagedWidget("form", xmFormWidgetClass, shell, NULL);
    
    /* Header area containing both rows */
    headerArea = XtVaCreateManagedWidget("headerArea", xmFormWidgetClass, form,
                                          XmNtopAttachment, XmATTACH_FORM,
                                          XmNleftAttachment, XmATTACH_FORM,
                                          XmNrightAttachment, XmATTACH_FORM,
                                          XmNheight, ROW1_HEIGHT + ROW2_HEIGHT + 5,
                                          NULL);
    
    /* Content below */
    contentFrame = XtVaCreateManagedWidget("contentFrame", xmFrameWidgetClass, form,
                                            XmNtopAttachment, XmATTACH_WIDGET,
                                            XmNtopWidget, headerArea,
                                            XmNbottomAttachment, XmATTACH_FORM,
                                            XmNleftAttachment, XmATTACH_FORM,
                                            XmNrightAttachment, XmATTACH_FORM,
                                            XmNshadowThickness, 3,
                                            NULL);
    
    XtRealizeWidget(shell);
    
    XtVaGetValues(form, XmNbackground, &motifBg, NULL);
    bgPixel = motifBg;
    
    XSetWindowBackground(dpy, XtWindow(headerArea), bgPixel);
    
    createWindows(headerArea);
    
    XtAddEventHandler(shell, StructureNotifyMask, FALSE, resizeHandler, NULL);
    XtAddEventHandler(headerArea, StructureNotifyMask, FALSE, formResizeEH, NULL);
    
    printf("\nResize to see black stripe between rows.\n");
    
    while (1) {
        XtAppNextEvent(app, &event);
        
        if (event.type == Expose) {
            if (event.xexpose.window == titleRowWin ||
                event.xexpose.window == globeWin ||
                event.xexpose.window == titleTextWin ||
                event.xexpose.window == toolbarRowWin) {
                handleExpose(&event.xexpose);
                continue;
            }
        }
        
        XtDispatchEvent(&event);
    }
    
    return 0;
}
