/*
 * test_nested_windows.c - Test app that mimics ViolaWWW structure:
 * Motif canvas with nested X windows inside (like Viola objects)
 */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <Xm/Xm.h>
#include <Xm/DrawingA.h>
#include <Xm/Form.h>
#include <Xm/Frame.h>
#include <Xm/Label.h>
#include <Xm/MainW.h>
#include <Xm/RowColumn.h>
#include <stdio.h>
#include <stdlib.h>

static String fallback_resources[] = {
    "*background: antiqueWhite4",
    "*foreground: black",
    NULL,
};

static Display* dpy;
static Window innerWindow1, innerWindow2, innerWindow3;
static unsigned long bgPixel;

/* Draw content in inner window */
static void drawInnerWindow(Window win, int width, int height, const char* text)
{
    GC gc = XCreateGC(dpy, win, 0, NULL);
    
    /* Fill with background */
    XSetForeground(dpy, gc, bgPixel);
    XFillRectangle(dpy, win, gc, 0, 0, width, height);
    
    /* Draw text */
    XSetForeground(dpy, gc, BlackPixel(dpy, DefaultScreen(dpy)));
    XDrawString(dpy, win, gc, 10, 20, text, strlen(text));
    
    /* Draw border */
    XDrawRectangle(dpy, win, gc, 0, 0, width - 1, height - 1);
    
    XFreeGC(dpy, gc);
}

/* Expose handler for inner windows */
static void handleInnerExpose(XExposeEvent* ev)
{
    XWindowAttributes attrs;
    const char* text = "Inner Window";
    
    if (ev->window == innerWindow1) text = "Header Area";
    else if (ev->window == innerWindow2) text = "Toolbar";
    else if (ev->window == innerWindow3) text = "Content Area";
    
    XGetWindowAttributes(dpy, ev->window, &attrs);
    drawInnerWindow(ev->window, attrs.width, attrs.height, text);
}

/* Recursively clear all windows */
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

/* Resize handler for shell */
static void resizeHandler(Widget w, XtPointer clientData, XEvent *event, Boolean *cont)
{
    if (event->type == ConfigureNotify) {
        Window shellWin = XtWindow(w);
        
        clearWindowTree(shellWin);
        XSync(dpy, False);
        
        printf("Resize: %dx%d\n", event->xconfigure.width, event->xconfigure.height);
    }
}

/* Resize inner windows when canvas resizes */
static void canvasResizeCB(Widget w, XtPointer clientData, XtPointer callData)
{
    Dimension width, height;
    Window canvasWin;
    
    /* Skip if inner windows not created yet */
    if (!innerWindow1) return;
    
    canvasWin = XtWindow(w);
    XtVaGetValues(w, XmNwidth, &width, XmNheight, &height, NULL);
    
    /* First clear canvas to avoid black areas showing through */
    if (canvasWin) {
        XClearArea(dpy, canvasWin, 0, 0, 0, 0, True);
    }
    
    /* Resize inner windows to match canvas - no gaps */
    XMoveResizeWindow(dpy, innerWindow1, 0, 0, width, 60);
    XClearArea(dpy, innerWindow1, 0, 0, 0, 0, True);
    
    XMoveResizeWindow(dpy, innerWindow2, 0, 60, width, 40);
    XClearArea(dpy, innerWindow2, 0, 0, 0, 0, True);
    
    XMoveResizeWindow(dpy, innerWindow3, 0, 100, width, height - 100);
    XClearArea(dpy, innerWindow3, 0, 0, 0, 0, True);
    
    XSync(dpy, False);
}

/* Create nested X windows inside canvas */
static void createInnerWindows(Widget canvas)
{
    Window canvasWin = XtWindow(canvas);
    XSetWindowAttributes attrs;
    Dimension width, height;
    Pixel canvasBg;
    
    XtVaGetValues(canvas, XmNwidth, &width, XmNheight, &height, 
                  XmNbackground, &canvasBg, NULL);
    
    /* Use same background as canvas */
    bgPixel = canvasBg;
    
    /* Common attributes */
    attrs.background_pixel = bgPixel;
    attrs.border_pixel = bgPixel;  /* Same as background to avoid black borders */
    attrs.event_mask = ExposureMask | StructureNotifyMask;
    attrs.backing_store = Always;
    
    /* Header area - like ViolaWWW title/URL area */
    innerWindow1 = XCreateWindow(dpy, canvasWin, 0, 0, width, 60, 0,
                                  CopyFromParent, CopyFromParent, CopyFromParent,
                                  CWBackPixel | CWBorderPixel | CWEventMask | CWBackingStore,
                                  &attrs);
    XMapWindow(dpy, innerWindow1);
    
    /* Toolbar - like ViolaWWW toolbar */
    innerWindow2 = XCreateWindow(dpy, canvasWin, 0, 60, width, 40, 0,
                                  CopyFromParent, CopyFromParent, CopyFromParent,
                                  CWBackPixel | CWBorderPixel | CWEventMask | CWBackingStore,
                                  &attrs);
    XMapWindow(dpy, innerWindow2);
    
    /* Content area - like ViolaWWW HTML content */
    innerWindow3 = XCreateWindow(dpy, canvasWin, 0, 100, width, height - 100, 0,
                                  CopyFromParent, CopyFromParent, CopyFromParent,
                                  CWBackPixel | CWBorderPixel | CWEventMask | CWBackingStore,
                                  &attrs);
    XMapWindow(dpy, innerWindow3);
    
    printf("Created inner windows: header=0x%lx, toolbar=0x%lx, content=0x%lx\n",
           innerWindow1, innerWindow2, innerWindow3);
}

int main(int argc, char *argv[])
{
    XtAppContext app;
    Widget shell, form, canvas;
    XEvent event;
    
    XtSetLanguageProc(NULL, NULL, NULL);
    
    shell = XtVaAppInitialize(&app, "TestNested", NULL, 0,
                              &argc, argv, fallback_resources,
                              XmNwidth, 600,
                              XmNheight, 400,
                              NULL);
    
    dpy = XtDisplay(shell);
    
    /* Simple form as container */
    form = XtVaCreateManagedWidget("form", xmFormWidgetClass, shell, NULL);
    
    /* Canvas - like ViolaWWW's violaCanvas */
    canvas = XtVaCreateManagedWidget("canvas", xmDrawingAreaWidgetClass, form,
                                     XmNtopAttachment, XmATTACH_FORM,
                                     XmNleftAttachment, XmATTACH_FORM,
                                     XmNrightAttachment, XmATTACH_FORM,
                                     XmNbottomAttachment, XmATTACH_FORM,
                                     NULL);
    
    XtAddCallback(canvas, XmNresizeCallback, canvasResizeCB, NULL);
    
    XtRealizeWidget(shell);
    
    /* Ensure canvas has correct X11 background (not black) */
    {
        Pixel canvasBg;
        XtVaGetValues(canvas, XmNbackground, &canvasBg, NULL);
        XSetWindowBackground(dpy, XtWindow(canvas), canvasBg);
        printf("Canvas background set to %lu\n", canvasBg);
    }
    
    /* Create inner X windows after widget is realized */
    createInnerWindows(canvas);
    
    /* Register resize handler on shell */
    XtAddEventHandler(shell, StructureNotifyMask, FALSE, resizeHandler, NULL);
    
    printf("Resize the window and watch for black artifacts.\n");
    printf("Press Ctrl+C to exit.\n");
    
    /* Custom event loop to handle inner window events */
    while (1) {
        XtAppNextEvent(app, &event);
        
        /* Handle Expose for our inner windows */
        if (event.type == Expose) {
            if (event.xexpose.window == innerWindow1 ||
                event.xexpose.window == innerWindow2 ||
                event.xexpose.window == innerWindow3) {
                handleInnerExpose(&event.xexpose);
                continue;
            }
        }
        
        XtDispatchEvent(&event);
    }
    
    return 0;
}

