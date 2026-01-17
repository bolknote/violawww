/*
 * vw_stubs.c
 *
 * Stub implementations of vw functions for standalone viola binary
 * (without the vw Motif interface).
 * 
 * Includes persistent URL history storage in ~/.viola_history
 * and X11 security dialog.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#include <signal.h>
#include <sys/select.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

/* Finish flag from event_x.c */
extern volatile sig_atomic_t finish;

#include "../libWWW/HTParse.h"
#include "cl_cosmic.h"

/* X11 globals from glib_x.c */
extern Display* display;
extern int screenNumber;

/* Stub for docViews - not available in standalone viola */
void* docViews = NULL;

/* --- Persistent History Implementation --- */

#define MAX_HISTORY_URLS 4096
#define MAX_URL_LENGTH 2048
#define HISTORY_FILENAME ".viola_history"

static char* historyURLs[MAX_HISTORY_URLS];
static int historyCount = 0;
static int historyLoaded = 0;

/* Get path to history file (~/.viola_history) */
static char* getHistoryFilePath(void) {
    static char path[1024];
    const char* home = getenv("HOME");
    
    if (!home) {
        struct passwd* pw = getpwuid(getuid());
        if (pw) {
            home = pw->pw_dir;
        }
    }
    
    if (!home) {
        return NULL;
    }
    
    snprintf(path, sizeof(path), "%s/%s", home, HISTORY_FILENAME);
    return path;
}

/* Load history from file */
static void loadHistory(void) {
    FILE* fp;
    char* path;
    char line[MAX_URL_LENGTH];
    
    if (historyLoaded) {
        return;
    }
    historyLoaded = 1;
    
    path = getHistoryFilePath();
    if (!path) {
        return;
    }
    
    fp = fopen(path, "r");
    if (!fp) {
        return;
    }
    
    while (fgets(line, sizeof(line), fp) && historyCount < MAX_HISTORY_URLS) {
        /* Remove trailing newline */
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        
        if (len > 0) {
            historyURLs[historyCount] = strdup(line);
            if (historyURLs[historyCount]) {
                historyCount++;
            }
        }
    }
    
    fclose(fp);
}

/* Save a single URL to history file (append) */
static void saveURLToFile(const char* url) {
    FILE* fp;
    char* path;
    
    path = getHistoryFilePath();
    if (!path) {
        return;
    }
    
    fp = fopen(path, "a");
    if (!fp) {
        return;
    }
    
    fprintf(fp, "%s\n", url);
    fclose(fp);
}

/* Check if URL is in standalone history */
int isURLInHistory(void* dvi, char* url) {
    int i;
    char* canonicalURL;
    
    (void)dvi; /* Not used in standalone mode */
    
    if (!url || !*url) {
        return 0;
    }
    
    /* Ensure history is loaded */
    loadHistory();
    
    /* Check exact match first */
    for (i = 0; i < historyCount; i++) {
        if (historyURLs[i] && !strcmp(url, historyURLs[i])) {
            return 1;
        }
    }
    
    /* Try normalizing URL relative to each history entry */
    for (i = 0; i < historyCount; i++) {
        if (!historyURLs[i]) {
            continue;
        }
        
        canonicalURL = HTParse(url, historyURLs[i], PARSE_ALL);
        if (canonicalURL) {
            HTSimplify(canonicalURL);
            
            /* Check if canonical URL matches any history entry */
            int j;
            for (j = 0; j < historyCount; j++) {
                if (historyURLs[j] && !strcmp(canonicalURL, historyURLs[j])) {
                    free(canonicalURL);
                    return 1;
                }
            }
            free(canonicalURL);
        }
    }
    
    return 0;
}

/* Add URL to standalone history (persistent) */
void addURLToStandaloneHistory(const char* url) {
    int i;
    char* urlCopy;
    
    if (!url || !*url) {
        return;
    }
    
    /* Ensure history is loaded */
    loadHistory();
    
    /* Check if already exists */
    for (i = 0; i < historyCount; i++) {
        if (historyURLs[i] && !strcmp(url, historyURLs[i])) {
            return; /* Already in history */
        }
    }
    
    /* Add to memory */
    if (historyCount < MAX_HISTORY_URLS) {
        urlCopy = strdup(url);
        if (urlCopy) {
            historyURLs[historyCount++] = urlCopy;
            /* Also save to file */
            saveURLToFile(url);
        }
    }
}

/* Stub for compareDocViewCloneID - not used in standalone */
int compareDocViewCloneID(void* vkey, void* vdata) {
    (void)vkey;
    (void)vdata;
    return 0;
}

/* Stub for registerSyncSocket - no Xt in standalone viola */
void registerSyncSocket(int fd) {
    (void)fd;
    /* In standalone viola, sync processing happens via polling in event loop */
}

/* Stub for wakeUpEventLoop - no Xt in standalone viola */
void wakeUpEventLoop(void) {
    /* No-op in standalone mode */
}

#ifdef __APPLE__
/* Stub for vw_start_wakeup_timer - no need in standalone viola */
void vw_start_wakeup_timer(void) {
    /* No-op in standalone mode - no XQuartz event loop issues */
}
#endif

/* --- X11 Security Dialog --- */

/* Button geometry */
#define BTN_WIDTH   100
#define BTN_HEIGHT  30
#define BTN_MARGIN  20
#define DIALOG_WIDTH  500
#define DIALOG_HEIGHT 280

/* Draw a 3D-style button */
static void drawButton(Display* dpy, Window win, GC gc, 
                       int x, int y, int w, int h, 
                       const char* label, int highlighted)
{
    XFontStruct* font = XQueryFont(dpy, XGContextFromGC(gc));
    int textWidth, textX, textY;
    
    /* Button background */
    if (highlighted) {
        XSetForeground(dpy, gc, WhitePixel(dpy, DefaultScreen(dpy)));
    } else {
        XSetForeground(dpy, gc, 0xE0E0E0);  /* Light gray */
    }
    XFillRectangle(dpy, win, gc, x, y, w, h);
    
    /* Button border - 3D effect */
    XSetForeground(dpy, gc, 0xFFFFFF);  /* White - top/left highlight */
    XDrawLine(dpy, win, gc, x, y, x + w - 1, y);
    XDrawLine(dpy, win, gc, x, y, x, y + h - 1);
    
    XSetForeground(dpy, gc, 0x808080);  /* Dark gray - bottom/right shadow */
    XDrawLine(dpy, win, gc, x + w - 1, y, x + w - 1, y + h - 1);
    XDrawLine(dpy, win, gc, x, y + h - 1, x + w - 1, y + h - 1);
    
    /* Button text */
    XSetForeground(dpy, gc, BlackPixel(dpy, DefaultScreen(dpy)));
    if (font) {
        textWidth = XTextWidth(font, label, (int)strlen(label));
        textX = x + (w - textWidth) / 2;
        textY = y + (h + font->ascent - font->descent) / 2;
    } else {
        textX = x + 10;
        textY = y + h / 2 + 5;
    }
    XDrawString(dpy, win, gc, textX, textY, label, (int)strlen(label));
}

/* Check if point is inside rectangle */
static int pointInRect(int px, int py, int x, int y, int w, int h)
{
    return px >= x && px < x + w && py >= y && py < y + h;
}

/*
 * x11SecurityDialog() - X11 modal security confirmation dialog.
 * Shows a window with Trust/Don't Trust buttons.
 * Returns: 1 = user allowed, 0 = user denied
 */
static int x11SecurityDialog(const char* title, const char* message,
                              const char* operation, const char* objectName)
{
    extern char* current_addr;  /* from html.c */
    Window dialogWin;
    GC gc;
    XEvent event;
    XSetWindowAttributes attrs;
    int result = 0;
    int done = 0;
    const char* docURL;
    char line1[256], line2[256], line3[256], line4[256];
    int trustBtnX, dontTrustBtnX, btnY;
    int highlightTrust = 0, highlightDontTrust = 0;
    XSizeHints hints;
    XTextProperty windowName;
    const char* titleStr = "Security Warning";
    
    (void)title;
    (void)message;
    
    /* Check if display is available */
    if (!display) {
        fprintf(stderr, "Security: No X11 display available, denying access\n");
        return 0;
    }
    
    /* Get document URL */
    docURL = current_addr;
    if (!docURL || !*docURL) {
        docURL = "(unknown)";
    }
    
    /* Prepare text lines */
    snprintf(line1, sizeof(line1), "Document: %.60s", docURL);
    if (strlen(docURL) > 60) {
        snprintf(line2, sizeof(line2), "    ...%s", docURL + strlen(docURL) - 35);
    } else {
        line2[0] = '\0';
    }
    snprintf(line3, sizeof(line3), "Object: %s", objectName ? objectName : "(null)");
    snprintf(line4, sizeof(line4), "Action: %s", operation ? operation : "perform restricted operation");
    
    /* Button positions */
    trustBtnX = DIALOG_WIDTH / 2 - BTN_WIDTH - BTN_MARGIN / 2;
    dontTrustBtnX = DIALOG_WIDTH / 2 + BTN_MARGIN / 2;
    btnY = DIALOG_HEIGHT - BTN_HEIGHT - BTN_MARGIN;
    
    /* Create dialog window */
    attrs.override_redirect = False;
    attrs.background_pixel = 0xF0F0F0;  /* Light gray background */
    attrs.event_mask = ExposureMask | ButtonPressMask | ButtonReleaseMask | 
                       PointerMotionMask | KeyPressMask | StructureNotifyMask;
    
    dialogWin = XCreateWindow(display, RootWindow(display, screenNumber),
                              100, 100, DIALOG_WIDTH, DIALOG_HEIGHT, 2,
                              CopyFromParent, InputOutput, CopyFromParent,
                              CWOverrideRedirect | CWBackPixel | CWEventMask,
                              &attrs);
    
    /* Set window title */
    XStringListToTextProperty((char**)&titleStr, 1, &windowName);
    XSetWMName(display, dialogWin, &windowName);
    XFree(windowName.value);
    
    /* Set size hints - non-resizable */
    hints.flags = PMinSize | PMaxSize;
    hints.min_width = hints.max_width = DIALOG_WIDTH;
    hints.min_height = hints.max_height = DIALOG_HEIGHT;
    XSetWMNormalHints(display, dialogWin, &hints);
    
    /* Create GC */
    gc = XCreateGC(display, dialogWin, 0, NULL);
    
    /* Map window */
    XMapRaised(display, dialogWin);
    XFlush(display);
    
    /* Modal event loop - non-blocking to allow signal handling */
    {
        int xfd = ConnectionNumber(display);
        
        while (!done && !finish) {
            /* Check for pending events without blocking */
            if (XPending(display)) {
                XNextEvent(display, &event);
            } else {
                /* Wait with timeout so we can check finish flag */
                fd_set readfds;
                struct timeval tv = {0, 50000};  /* 50ms timeout */
                
                FD_ZERO(&readfds);
                FD_SET(xfd, &readfds);
                select(xfd + 1, &readfds, NULL, NULL, &tv);
                continue;  /* Loop back to check finish and XPending */
            }
        
        switch (event.type) {
        case Expose:
            if (event.xexpose.count == 0) {
                int y = 30;
                
                /* Title */
                XSetForeground(display, gc, 0xCC0000);  /* Dark red */
                {
                    const char* title = "SECURITY WARNING - Privilege Request";
                    XDrawString(display, dialogWin, gc, 20, y, title, (int)strlen(title));
                }
                
                /* Document info */
                y += 35;
                XSetForeground(display, gc, BlackPixel(display, screenNumber));
                XDrawString(display, dialogWin, gc, 20, y, line1, (int)strlen(line1));
                if (line2[0]) {
                    y += 18;
                    XDrawString(display, dialogWin, gc, 20, y, line2, (int)strlen(line2));
                }
                y += 25;
                XDrawString(display, dialogWin, gc, 20, y, line3, (int)strlen(line3));
                y += 18;
                XDrawString(display, dialogWin, gc, 20, y, line4, (int)strlen(line4));
                
                /* Warning text */
                y += 35;
                XSetForeground(display, gc, 0xCC0000);  /* Dark red */
                XDrawString(display, dialogWin, gc, 20, y, 
                           "WARNING: Trusted documents can:", 31);
                y += 18;
                XSetForeground(display, gc, BlackPixel(display, screenNumber));
                XDrawString(display, dialogWin, gc, 30, y, 
                           "- read and write files on your system", 37);
                y += 18;
                XDrawString(display, dialogWin, gc, 30, y, 
                           "- execute system commands", 25);
                y += 18;
                XDrawString(display, dialogWin, gc, 30, y, 
                           "- load and run arbitrary code", 29);
                
                /* Buttons */
                drawButton(display, dialogWin, gc, 
                          trustBtnX, btnY, BTN_WIDTH, BTN_HEIGHT, 
                          "Trust", highlightTrust);
                drawButton(display, dialogWin, gc, 
                          dontTrustBtnX, btnY, BTN_WIDTH, BTN_HEIGHT, 
                          "Don't Trust", highlightDontTrust);
            }
            break;
            
        case MotionNotify:
            {
                int newHighlightTrust = pointInRect(event.xmotion.x, event.xmotion.y,
                                                    trustBtnX, btnY, BTN_WIDTH, BTN_HEIGHT);
                int newHighlightDontTrust = pointInRect(event.xmotion.x, event.xmotion.y,
                                                        dontTrustBtnX, btnY, BTN_WIDTH, BTN_HEIGHT);
                if (newHighlightTrust != highlightTrust || newHighlightDontTrust != highlightDontTrust) {
                    highlightTrust = newHighlightTrust;
                    highlightDontTrust = newHighlightDontTrust;
                    /* Redraw buttons */
                    drawButton(display, dialogWin, gc, 
                              trustBtnX, btnY, BTN_WIDTH, BTN_HEIGHT, 
                              "Trust", highlightTrust);
                    drawButton(display, dialogWin, gc, 
                              dontTrustBtnX, btnY, BTN_WIDTH, BTN_HEIGHT, 
                              "Don't Trust", highlightDontTrust);
                }
            }
            break;
            
        case ButtonRelease:
            if (pointInRect(event.xbutton.x, event.xbutton.y,
                           trustBtnX, btnY, BTN_WIDTH, BTN_HEIGHT)) {
                result = 1;  /* Trust */
                done = 1;
            } else if (pointInRect(event.xbutton.x, event.xbutton.y,
                                   dontTrustBtnX, btnY, BTN_WIDTH, BTN_HEIGHT)) {
                result = 0;  /* Don't Trust */
                done = 1;
            }
            break;
            
        case KeyPress:
            {
                KeySym keysym = XLookupKeysym(&event.xkey, 0);
                if (keysym == XK_Escape || keysym == XK_n || keysym == XK_N) {
                    result = 0;  /* Don't Trust */
                    done = 1;
                } else if (keysym == XK_Return || keysym == XK_y || keysym == XK_Y) {
                    result = 1;  /* Trust */
                    done = 1;
                }
            }
            break;
            
        case DestroyNotify:
            done = 1;
            result = 0;
            break;
        }
        }  /* end while */
    }  /* end block with xfd */
    
    /* Cleanup */
    XFreeGC(display, gc);
    XDestroyWindow(display, dialogWin);
    XFlush(display);
    
    return result;
}

/*
 * initX11SecurityCallback() - register X11 security dialog.
 * Call this once during standalone viola initialization.
 */
void initConsoleSecurityCallback(void)
{
    ViolaRegisterSecurityCallback(x11SecurityDialog);
}
