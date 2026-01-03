/*
 * test_title_component.c - Reproduce ViolaWWW title/url component EXACTLY (Motif widgets)
 *
 * From src/vw/vw.c:
 *   topForm (XmForm)
 *     titleIconFrame (XmFrame)
 *       titleIcon (XmLabel) background black, pixmap
 *     titleFrame (XmFrame) margins 4, left of titleIconFrame
 *       title (XmLabel) borderWidth=4, borderColor=bg
 */

#include <Xm/Xm.h>
#include <Xm/Form.h>
#include <Xm/Frame.h>
#include <Xm/Label.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static String fallback_resources[] = {
    "*background: antiqueWhite4",
    "*foreground: black",
    NULL,
};

static Display* g_dpy = NULL;

typedef struct {
    int no_content_frame;
    int no_icon;
    int no_frames;
    int no_frame_shadows;
    int no_label_border;
    int no_shell_clear;       /* disable our configure-time clear */
    int no_backing_store;     /* backing_store = NotUseful */
} Options;

static void parseOptions(int argc, char** argv, Options* opt)
{
    int i;
    memset(opt, 0, sizeof(*opt));

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--no-content") == 0) opt->no_content_frame = 1;
        else if (strcmp(argv[i], "--no-icon") == 0) opt->no_icon = 1;
        else if (strcmp(argv[i], "--no-frames") == 0) opt->no_frames = 1;
        else if (strcmp(argv[i], "--no-frame-shadows") == 0) opt->no_frame_shadows = 1;
        else if (strcmp(argv[i], "--no-label-border") == 0) opt->no_label_border = 1;
        else if (strcmp(argv[i], "--no-shell-clear") == 0) opt->no_shell_clear = 1;
        else if (strcmp(argv[i], "--no-backing-store") == 0) opt->no_backing_store = 1;
        else if (strcmp(argv[i], "--help") == 0) {
            fprintf(stderr,
                    "Usage: test_title_component [options]\n"
                    "Options:\n"
                    "  --no-content         remove bottom content frame\n"
                    "  --no-icon            remove left icon frame/label\n"
                    "  --no-frames          do not use XmFrame at all (attach labels directly)\n"
                    "  --no-frame-shadows   set XmNshadowThickness=0 on frames\n"
                    "  --no-label-border    set XmNborderWidth=0 on title label\n"
                    "  --no-shell-clear     disable clearWindowTree on ConfigureNotify\n"
                    "  --no-backing-store   set backing_store=NotUseful (default: Always)\n");
            exit(0);
        }
    }
}

static void setResizeAttrsTree(Display* dpy, Window win)
{
    Window root, parent;
    Window* children = NULL;
    unsigned int nchildren = 0;
    unsigned int i;
    XSetWindowAttributes attrs;

    if (!win) return;

    /* Critical for resize artifacts:
     * - ForgetGravity: do NOT copy old pixels when window grows/shrinks
     * - backing_store: try Always (keeps contents). We allow disabling via flag.
     */
    attrs.bit_gravity = ForgetGravity;
    attrs.backing_store = Always;
    XChangeWindowAttributes(dpy, win, CWBitGravity | CWBackingStore, &attrs);

    if (XQueryTree(dpy, win, &root, &parent, &children, &nchildren)) {
        for (i = 0; i < nchildren; i++) {
            setResizeAttrsTree(dpy, children[i]);
        }
        if (children) XFree(children);
    }
}

static void clearWindowTree(Display* dpy, Window win)
{
    Window root, parent;
    Window* children = NULL;
    unsigned int nchildren = 0;
    unsigned int i;

    if (!win) return;

    XClearArea(dpy, win, 0, 0, 0, 0, True);

    if (XQueryTree(dpy, win, &root, &parent, &children, &nchildren)) {
        for (i = 0; i < nchildren; i++) {
            clearWindowTree(dpy, children[i]);
        }
        if (children) XFree(children);
    }
}

static void logEH(const char* name, XEvent* ev)
{
    if (ev->type == Expose) {
        XExposeEvent* e = (XExposeEvent*)ev;
        fprintf(stderr, "%s: Expose x=%d y=%d w=%d h=%d count=%d\n",
                name, e->x, e->y, e->width, e->height, e->count);
    } else if (ev->type == ConfigureNotify) {
        XConfigureEvent* c = (XConfigureEvent*)ev;
        fprintf(stderr, "%s: Configure x=%d y=%d w=%d h=%d\n",
                name, c->x, c->y, c->width, c->height);
    }
}

static void shellEH(Widget w, XtPointer cd, XEvent* ev, Boolean* cont)
{
    Options* opt = (Options*)cd;
    (void)w; (void)cd; (void)cont;
    logEH("shell", ev);
    if (ev->type == ConfigureNotify) {
        Window win = XtWindow(w);
        if (g_dpy && win) {
            if (opt && opt->no_backing_store) {
                /* override backing store for whole tree */
                /* (we rely on setResizeAttrsTree below but force NotUseful) */
                XSetWindowAttributes attrs;
                attrs.backing_store = NotUseful;
                XChangeWindowAttributes(g_dpy, win, CWBackingStore, &attrs);
            } else {
                setResizeAttrsTree(g_dpy, win);
            }
            if (!(opt && opt->no_shell_clear)) {
                clearWindowTree(g_dpy, win);
                XSync(g_dpy, False);
            }
        }
    }
}

static void titleIconFrameEH(Widget w, XtPointer cd, XEvent* ev, Boolean* cont)
{
    (void)cd; (void)cont;
    logEH("titleIconFrame", ev);
    /* Optional: force XClearArea on resize to see if it fixes artifacts */
    if (ev->type == ConfigureNotify) {
        Window win = XtWindow(w);
        if (win) XClearArea(XtDisplay(w), win, 0, 0, 0, 0, True);
    }
}

static void titleFrameEH(Widget w, XtPointer cd, XEvent* ev, Boolean* cont)
{
    (void)cd; (void)cont;
    logEH("titleFrame", ev);
    if (ev->type == ConfigureNotify) {
        Window win = XtWindow(w);
        if (win) XClearArea(XtDisplay(w), win, 0, 0, 0, 0, True);
    }
}

static void titleEHEH(Widget w, XtPointer cd, XEvent* ev, Boolean* cont)
{
    (void)cd; (void)cont;
    logEH("titleLabel", ev);
    if (ev->type == ConfigureNotify) {
        Window win = XtWindow(w);
        if (win) XClearArea(XtDisplay(w), win, 0, 0, 0, 0, True);
    }
}

int main(int argc, char** argv)
{
    XtAppContext app;
    Options opt;
    Widget shell;
    Widget form;
    Widget topForm;
    Widget contentFrame;
    Widget titleIconFrame = NULL;
    Widget titleIcon = NULL;
    Widget titleFrame = NULL;
    Widget title = NULL;

    XtSetLanguageProc(NULL, NULL, NULL);
    setbuf(stderr, NULL);
    parseOptions(argc, argv, &opt);

    shell = XtVaAppInitialize(&app, "TestTitleComponent", NULL, 0,
                              &argc, argv, fallback_resources,
                              XmNwidth, 900,
                              XmNheight, 200,
                              NULL);
    g_dpy = XtDisplay(shell);

    form = XtVaCreateManagedWidget("form", xmFormWidgetClass, shell,
                                   XmNhorizontalSpacing, 2,
                                   XmNverticalSpacing, 2,
                                   NULL);

    topForm = XtVaCreateManagedWidget("topForm", xmFormWidgetClass, form,
                                      XmNtopAttachment, XmATTACH_FORM,
                                      XmNleftAttachment, XmATTACH_FORM,
                                      XmNrightAttachment, XmATTACH_FORM,
                                      XmNheight, 70,
                                      NULL);

    /* Fill the rest of the window so we can see if parents are black */
    if (!opt.no_content_frame) {
        contentFrame = XtVaCreateManagedWidget("contentFrame", xmFrameWidgetClass, form,
                                               XmNtopAttachment, XmATTACH_WIDGET,
                                               XmNtopWidget, topForm,
                                               XmNbottomAttachment, XmATTACH_FORM,
                                               XmNleftAttachment, XmATTACH_FORM,
                                               XmNrightAttachment, XmATTACH_FORM,
                                               XmNshadowThickness, 2,
                                               NULL);
    } else {
        contentFrame = NULL;
    }

    if (!opt.no_icon) {
        if (!opt.no_frames) {
            titleIconFrame = XtVaCreateManagedWidget("titleIconFrame", xmFrameWidgetClass, topForm,
                                                     XmNtopAttachment, XmATTACH_FORM,
                                                     XmNleftAttachment, XmATTACH_FORM,
                                                     XmNbottomAttachment, XmATTACH_FORM,
                                                     opt.no_frame_shadows ? XmNshadowThickness : (String)NULL, opt.no_frame_shadows ? 0 : 0,
                                                     NULL);
            if (opt.no_frame_shadows) {
                XtVaSetValues(titleIconFrame, XmNshadowThickness, 0, NULL);
            }
            titleIcon = XtVaCreateManagedWidget("titleIcon", xmLabelWidgetClass, titleIconFrame,
                                                XmNlabelString, XmStringCreateSimple(""),
                                                XmNrecomputeSize, False,
                                                XmNwidth, 64,
                                                XmNheight, 64,
                                                XmNbackground, BlackPixelOfScreen(XtScreen(shell)),
                                                NULL);
        } else {
            /* no frames: put icon label directly in topForm */
            titleIcon = XtVaCreateManagedWidget("titleIcon", xmLabelWidgetClass, topForm,
                                                XmNtopAttachment, XmATTACH_FORM,
                                                XmNleftAttachment, XmATTACH_FORM,
                                                XmNbottomAttachment, XmATTACH_FORM,
                                                XmNlabelString, XmStringCreateSimple(""),
                                                XmNrecomputeSize, False,
                                                XmNwidth, 64,
                                                XmNheight, 64,
                                                XmNbackground, BlackPixelOfScreen(XtScreen(shell)),
                                                NULL);
        }
    }

    if (!opt.no_frames) {
        titleFrame = XtVaCreateManagedWidget("titleFrame", xmFrameWidgetClass, topForm,
                                             XmNtopAttachment, XmATTACH_FORM,
                                             XmNbottomAttachment, XmATTACH_FORM,
                                             XmNleftAttachment, opt.no_icon ? XmATTACH_FORM : XmATTACH_WIDGET,
                                             XmNleftWidget, titleIconFrame ? titleIconFrame : titleIcon,
                                             XmNleftOffset, opt.no_icon ? 0 : 4,
                                             XmNrightAttachment, XmATTACH_FORM,
                                             XmNmarginWidth, 4,
                                             XmNmarginHeight, 4,
                                             NULL);
        if (opt.no_frame_shadows) {
            XtVaSetValues(titleFrame, XmNshadowThickness, 0, NULL);
        }
    }

    {
        XmString xms = XmStringCreateSimple("The World Wide Web project\nhttp://info.cern.ch/hypertext/WWW/TheProject.html");
        if (!opt.no_frames) {
            title = XtVaCreateManagedWidget("title", xmLabelWidgetClass, titleFrame,
                                            XmNlabelString, xms,
                                            XmNborderWidth, opt.no_label_border ? 0 : 4,
                                            XmNrecomputeSize, False,
                                            NULL);
        } else {
            /* no frames: attach title label directly */
            title = XtVaCreateManagedWidget("title", xmLabelWidgetClass, topForm,
                                            XmNtopAttachment, XmATTACH_FORM,
                                            XmNbottomAttachment, XmATTACH_FORM,
                                            XmNleftAttachment, opt.no_icon ? XmATTACH_FORM : XmATTACH_WIDGET,
                                            XmNleftWidget, titleIcon,
                                            XmNleftOffset, opt.no_icon ? 0 : 4,
                                            XmNrightAttachment, XmATTACH_FORM,
                                            XmNlabelString, xms,
                                            XmNborderWidth, opt.no_label_border ? 0 : 4,
                                            XmNrecomputeSize, False,
                                            NULL);
        }
        XmStringFree(xms);
    }

    XtRealizeWidget(shell);

    /* Match vw.c: set title borderColor to background */
    {
        Pixel bg;
        XtVaGetValues(title, XmNbackground, &bg, NULL);
        if (!opt.no_label_border) {
            XtVaSetValues(title, XmNborderColor, bg, NULL);
        }

        /* Also force X11 background for the involved widget windows */
        if (XtWindow(shell)) XSetWindowBackground(XtDisplay(shell), XtWindow(shell), bg);
        if (XtWindow(form)) XSetWindowBackground(XtDisplay(form), XtWindow(form), bg);
        if (XtWindow(topForm)) XSetWindowBackground(XtDisplay(topForm), XtWindow(topForm), bg);
        if (titleIconFrame && XtWindow(titleIconFrame)) XSetWindowBackground(XtDisplay(titleIconFrame), XtWindow(titleIconFrame), bg);
        if (titleFrame && XtWindow(titleFrame)) XSetWindowBackground(XtDisplay(titleFrame), XtWindow(titleFrame), bg);
        if (XtWindow(title)) XSetWindowBackground(XtDisplay(title), XtWindow(title), bg);
        if (contentFrame && XtWindow(contentFrame)) XSetWindowBackground(XtDisplay(contentFrame), XtWindow(contentFrame), bg);

        if (g_dpy && XtWindow(shell)) {
            XClearArea(g_dpy, XtWindow(shell), 0, 0, 0, 0, True);
            XSync(g_dpy, False);
        }
    }

    /* Log events on the exact widgets */
    XtAddEventHandler(shell, StructureNotifyMask | ExposureMask, False, shellEH, (XtPointer)&opt);
    if (titleIconFrame) XtAddEventHandler(titleIconFrame, StructureNotifyMask | ExposureMask, False, titleIconFrameEH, NULL);
    if (titleFrame) XtAddEventHandler(titleFrame, StructureNotifyMask | ExposureMask, False, titleFrameEH, NULL);
    XtAddEventHandler(title, StructureNotifyMask | ExposureMask, False, titleEHEH, NULL);

    fprintf(stderr,
            "Resize the window. Watching Expose/Configure for title components.\n"
            "Options: no_content=%d no_icon=%d no_frames=%d no_frame_shadows=%d no_label_border=%d "
            "no_shell_clear=%d no_backing_store=%d\n",
            opt.no_content_frame, opt.no_icon, opt.no_frames, opt.no_frame_shadows, opt.no_label_border,
            opt.no_shell_clear, opt.no_backing_store);
    XtAppMainLoop(app);
    return 0;
}
