/*
 * test_motif_resize.c - Motif app with nested widgets to test resize artifacts
 */
#include <X11/Xlib.h>
#include <Xm/Xm.h>
#include <Xm/DrawingA.h>
#include <Xm/Form.h>
#include <Xm/Frame.h>
#include <Xm/Label.h>
#include <Xm/MainW.h>
#include <Xm/PanedW.h>
#include <Xm/PushB.h>
#include <Xm/RowColumn.h>
#include <Xm/ScrolledW.h>
#include <Xm/Text.h>
#include <Xm/TextF.h>
#include <stdio.h>
#include <stdlib.h>

static String fallback_resources[] = {
    "*background: antiqueWhite4",
    "*foreground: black",
    NULL,
};

static int clearCount = 0;

/* Recursively clear all windows in tree */
static void clearWindowTree(Display *dpy, Window win)
{
    Window root, parent;
    Window *children = NULL;
    unsigned int nchildren = 0;
    unsigned int i;
    
    clearCount++;
    XClearArea(dpy, win, 0, 0, 0, 0, True);
    
    if (XQueryTree(dpy, win, &root, &parent, &children, &nchildren)) {
        for (i = 0; i < nchildren; i++) {
            clearWindowTree(dpy, children[i]);
        }
        if (children) XFree(children);
    }
}

/* Resize handler */
static void resizeHandler(Widget w, XtPointer clientData, XEvent *event, Boolean *cont)
{
    if (event->type == ConfigureNotify) {
        Display *dpy = XtDisplay(w);
        Window win = XtWindow(w);
        
        clearCount = 0;
        clearWindowTree(dpy, win);
        XSync(dpy, False);
        
        printf("Resize: %dx%d, cleared %d windows\n", 
               event->xconfigure.width, event->xconfigure.height, clearCount);
    }
}

/* Expose callback for DrawingArea - draws colored rectangles */
static void drawingExposeCB(Widget w, XtPointer clientData, XtPointer callData)
{
    Display *dpy = XtDisplay(w);
    Window win = XtWindow(w);
    GC gc = XCreateGC(dpy, win, 0, NULL);
    Dimension width, height;
    
    XtVaGetValues(w, XmNwidth, &width, XmNheight, &height, NULL);
    
    /* Draw some colored rectangles */
    XSetForeground(dpy, gc, WhitePixelOfScreen(XtScreen(w)));
    XFillRectangle(dpy, win, gc, 0, 0, width, height);
    
    XSetForeground(dpy, gc, BlackPixelOfScreen(XtScreen(w)));
    XDrawRectangle(dpy, win, gc, 5, 5, width - 10, height - 10);
    XDrawString(dpy, win, gc, 20, 30, "DrawingArea", 11);
    
    XFreeGC(dpy, gc);
}

int main(int argc, char *argv[])
{
    XtAppContext app;
    Widget shell, mainWin, menuBar, fileMenu, fileCascade;
    Widget paned, topForm, bottomForm;
    Widget frame1, label1, frame2, textField;
    Widget scrolled, drawing;
    Widget innerForm, innerFrame1, innerLabel, innerFrame2, innerText;
    
    shell = XtVaAppInitialize(&app, "TestResize", NULL, 0,
                              &argc, argv, fallback_resources,
                              XmNwidth, 500,
                              XmNheight, 400,
                              NULL);
    
    /* MainWindow like ViolaWWW */
    mainWin = XtVaCreateManagedWidget("mainWin", xmMainWindowWidgetClass, shell, NULL);
    
    /* Menu bar */
    menuBar = XmCreateMenuBar(mainWin, "menuBar", NULL, 0);
    XtManageChild(menuBar);
    
    fileMenu = XmCreatePulldownMenu(menuBar, "fileMenu", NULL, 0);
    fileCascade = XtVaCreateManagedWidget("File", xmCascadeButtonWidgetClass, menuBar,
                                          XmNsubMenuId, fileMenu, NULL);
    XtVaCreateManagedWidget("Quit", xmPushButtonWidgetClass, fileMenu, NULL);
    
    /* PanedWindow - creates multiple nested windows */
    paned = XtVaCreateManagedWidget("paned", xmPanedWidgetClass, mainWin,
                                    XmNorientation, XmVERTICAL,
                                    NULL);
    
    /* Top pane */
    topForm = XtVaCreateManagedWidget("topForm", xmFormWidgetClass, paned,
                                      XmNpaneMinimum, 60,
                                      NULL);
    
    frame1 = XtVaCreateManagedWidget("frame1", xmFrameWidgetClass, topForm,
                                     XmNtopAttachment, XmATTACH_FORM,
                                     XmNleftAttachment, XmATTACH_FORM,
                                     XmNrightAttachment, XmATTACH_FORM,
                                     XmNshadowThickness, 2,
                                     NULL);
    
    label1 = XtVaCreateManagedWidget("Header Label in Frame",
                                     xmLabelWidgetClass, frame1, NULL);
    
    frame2 = XtVaCreateManagedWidget("frame2", xmFrameWidgetClass, topForm,
                                     XmNtopAttachment, XmATTACH_WIDGET,
                                     XmNtopWidget, frame1,
                                     XmNleftAttachment, XmATTACH_FORM,
                                     XmNrightAttachment, XmATTACH_FORM,
                                     XmNbottomAttachment, XmATTACH_FORM,
                                     XmNshadowThickness, 2,
                                     NULL);
    
    textField = XtVaCreateManagedWidget("textField", xmTextFieldWidgetClass, frame2,
                                        XmNvalue, "URL input field", NULL);
    
    /* Bottom pane - ScrolledWindow with DrawingArea (like Viola canvas) */
    bottomForm = XtVaCreateManagedWidget("bottomForm", xmFormWidgetClass, paned, NULL);
    
    scrolled = XtVaCreateManagedWidget("scrolled", xmScrolledWindowWidgetClass, bottomForm,
                                       XmNscrollingPolicy, XmAUTOMATIC,
                                       XmNtopAttachment, XmATTACH_FORM,
                                       XmNleftAttachment, XmATTACH_FORM,
                                       XmNrightAttachment, XmATTACH_FORM,
                                       XmNbottomAttachment, XmATTACH_FORM,
                                       NULL);
    
    /* Inner form with nested widgets */
    innerForm = XtVaCreateManagedWidget("innerForm", xmFormWidgetClass, scrolled,
                                        XmNwidth, 600,
                                        XmNheight, 500,
                                        NULL);
    
    innerFrame1 = XtVaCreateManagedWidget("innerFrame1", xmFrameWidgetClass, innerForm,
                                          XmNtopAttachment, XmATTACH_FORM,
                                          XmNleftAttachment, XmATTACH_FORM,
                                          XmNrightAttachment, XmATTACH_FORM,
                                          XmNshadowThickness, 2,
                                          NULL);
    
    innerLabel = XtVaCreateManagedWidget("Nested Label",
                                         xmLabelWidgetClass, innerFrame1, NULL);
    
    /* DrawingArea - like Viola's custom X windows */
    innerFrame2 = XtVaCreateManagedWidget("innerFrame2", xmFrameWidgetClass, innerForm,
                                          XmNtopAttachment, XmATTACH_WIDGET,
                                          XmNtopWidget, innerFrame1,
                                          XmNleftAttachment, XmATTACH_FORM,
                                          XmNrightAttachment, XmATTACH_FORM,
                                          XmNbottomAttachment, XmATTACH_FORM,
                                          XmNshadowThickness, 2,
                                          NULL);
    
    drawing = XtVaCreateManagedWidget("drawing", xmDrawingAreaWidgetClass, innerFrame2,
                                      XmNwidth, 400,
                                      XmNheight, 300,
                                      NULL);
    XtAddCallback(drawing, XmNexposeCallback, drawingExposeCB, NULL);
    
    XmMainWindowSetAreas(mainWin, menuBar, NULL, NULL, NULL, paned);
    
    XtRealizeWidget(shell);
    
    /* Register resize handler on shell */
    XtAddEventHandler(shell, StructureNotifyMask, FALSE, resizeHandler, NULL);
    
    printf("Resize the window and watch for black artifacts.\n");
    printf("Press Ctrl+C to exit.\n");
    
    XtAppMainLoop(app);
    
    return 0;
}
