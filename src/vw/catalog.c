/*
 * catalog.c
 *
 * Personal URL Link Manager
 *
 */
/*
 * Copyright 1993 O'Reilly & Associates. All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */

#include <Xm/DrawingA.h>
#include <Xm/Form.h>
#include <Xm/Frame.h>
#include <Xm/Label.h>
#include <Xm/MessageB.h>
#include <Xm/PushB.h>
#include <Xm/ScrolledW.h>
#include <Xm/Text.h>
#include <Xm/TextF.h>
#include <Xm/Xm.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "callbacks.h"
#include "catalog.h"
#include "dialog.h"
#include "edit.h"
#include "menu.h"
#include "selection.h"
#include "vw.h"

#include "../viola/cexec.h"
#include "../viola/misc.h"
#include "../libXPM/xpm.h"

/* Forward declarations */
static void forceDeleteFolder(Folder* folder, Catalog* catalog);
static void forceDeleteLink(Link* link, Catalog* catalog);
static void catalogDeleteWindowEH(Widget w, XtPointer clientData, XEvent* event, Boolean* cont);
static void closeCatalogWindow(Catalog* catalog);

/* ---- XPM ICONS (embedded) ------------------------------------------- */

/* XPM */
/* 32x32 folder icon - scaled 2x from HTML__foldIcon folderClosed */
static char* folderIconXPM[] = {
"32 32 2 1",
"  c None",
". c black",
"                                ",
"                                ",
"                      ........  ",
"                      ........  ",
"        ..............        ..",
"        ..............        ..",
"      ..                      ..",
"      ..                      ..",
"      ......................  ..",
"      ......................  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                    ..  ..",
"    ..                      ....",
"    ..                      ....",
"      ........................  ",
"      ........................  ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                "};

/* XPM */
/* 30x32 link/document icon - scaled 2x from link.xpm */
static char* linkIconXPM[] = {
"30 32 3 1",
"  c black",
". c None",
"X c white",
"..............................",
"..............................",
"..                    ........",
"..                    ........",
"..  XXXXXXXXXXXXXX  XX  ......",
"..  XXXXXXXXXXXXXX  XX  ......",
"..  XX        XXXX  XXXX  ....",
"..  XX        XXXX  XXXX  ....",
"..  XXXXXXXXXXXXXX  XXXXXX  ..",
"..  XXXXXXXXXXXXXX  XXXXXX  ..",
"..  XX          XX          ..",
"..  XX          XX          ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XX                  XX  ..",
"..  XX                  XX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XX                  XX  ..",
"..  XX                  XX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XX                  XX  ..",
"..  XX                  XX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..  XXXXXXXXXXXXXXXXXXXXXX  ..",
"..                          ..",
"..                          ..",
"..............................",
".............................."};

/* ---- GLOBALS  ------------------------------------------------------- */

static Pixmap defaultFolderIcon = 0;
static Pixmap defaultFolderMask = 0;
static short defaultFolderWidth = 32;
static short defaultFolderHeight = 32;

static Pixmap defaultLinkIcon = 0;
static Pixmap defaultLinkMask = 0;
static short defaultLinkWidth = 30;
static short defaultLinkHeight = 32;

static XmFontList catalogFontList = NULL;
static int iconsInitialized = 0;

/* Global catalog instance (singleton for now) */
static Catalog* theCatalog = NULL;

/* ---- FORWARD DECLARATIONS ------------------------------------------- */

static void openSelectedItemsCB(Widget widget, XtPointer clientData, XtPointer callData);
static void addCurrentPageCB(Widget widget, XtPointer clientData, XtPointer callData);
static void newFolderCB(Widget widget, XtPointer clientData, XtPointer callData);
static void newLinkCB(Widget widget, XtPointer clientData, XtPointer callData);
static void deleteSelectedCB(Widget widget, XtPointer clientData, XtPointer callData);
static void saveCatalogCB(Widget widget, XtPointer clientData, XtPointer callData);
static void goUpFolderCB(Widget widget, XtPointer clientData, XtPointer callData);
static void selectAllCB(Widget widget, XtPointer clientData, XtPointer callData);
static void aboutCatalogCB(Widget widget, XtPointer clientData, XtPointer callData);
static void calculateCellWidth(Catalog* catalog);

/* ---- LABEL WRAPPING ------------------------------------------------- */

#define MAX_LABEL_WIDTH 80
#define MAX_LABEL_LINES 3

/* Canvas minimum size - slightly smaller than ScrolledWindow to avoid scrollbars */
#define CANVAS_MIN_WIDTH  396
#define CANVAS_MIN_HEIGHT 246

/*
 * Wrap text into multiple lines for display under icons.
 * - Lines 1-2: word-wrap within MAX_LABEL_WIDTH
 * - Line 3: remainder without wrapping (will be clipped)
 * Returns newly allocated string with \n separators.
 */
static char* wrapLabelText(const char* text, XmFontList fontList) {
    if (!text || !fontList) return text ? strdup(text) : NULL;
    
    /* Check if text already fits */
    XmString testXms = XmStringCreateLocalized((char*)text);
    Dimension textWidth = XmStringWidth(fontList, testXms);
    XmStringFree(testXms);
    
    if (textWidth <= MAX_LABEL_WIDTH) {
        return strdup(text);
    }
    
    /* Need to wrap - allocate result buffer */
    size_t len = strlen(text);
    char* result = (char*)malloc(len + MAX_LABEL_LINES + 1);  /* extra space for \n */
    if (!result) return strdup(text);
    result[0] = '\0';
    
    char* textCopy = strdup(text);
    if (!textCopy) { free(result); return strdup(text); }
    
    char* word;
    char* saveptr = NULL;
    char currentLine[256] = "";
    int lineNum = 0;
    
    word = strtok_r(textCopy, " ", &saveptr);
    while (word && lineNum < MAX_LABEL_LINES) {
        char testLine[256];
        
        if (currentLine[0] == '\0') {
            strcpy(testLine, word);
        } else {
            snprintf(testLine, sizeof(testLine), "%s %s", currentLine, word);
        }
        
        /* Measure test line width */
        XmString xms = XmStringCreateLocalized(testLine);
        Dimension lineWidth = XmStringWidth(fontList, xms);
        XmStringFree(xms);
        
        if (lineWidth <= MAX_LABEL_WIDTH || currentLine[0] == '\0') {
            /* Word fits or it's the first word on line */
            strcpy(currentLine, testLine);
            word = strtok_r(NULL, " ", &saveptr);
        } else {
            /* Word doesn't fit - finish current line */
            if (result[0] != '\0') strcat(result, "\n");
            strcat(result, currentLine);
            lineNum++;
            
            if (lineNum >= MAX_LABEL_LINES - 1) {
                /* Line 3: append all remaining text without wrapping */
                currentLine[0] = '\0';
                strcpy(currentLine, word);
                word = strtok_r(NULL, " ", &saveptr);
                while (word) {
                    strcat(currentLine, " ");
                    strcat(currentLine, word);
                    word = strtok_r(NULL, " ", &saveptr);
                }
            } else {
                currentLine[0] = '\0';
            }
        }
    }
    
    /* Append last line if not empty */
    if (currentLine[0] != '\0') {
        if (result[0] != '\0') strcat(result, "\n");
        strcat(result, currentLine);
    }
    
    free(textCopy);
    return result;
}

/*
 * Create XmString from text, wrapping if necessary.
 */
static XmString createWrappedLabel(const char* text, XmFontList fontList) {
    char* wrapped = wrapLabelText(text, fontList);
    XmString xms = XmStringCreateLtoR(wrapped, XmFONTLIST_DEFAULT_TAG);
    free(wrapped);
    return xms;
}

/*
 * Update canvas size to fit all items (enables scrolling only when needed)
 */
static void updateCanvasSize(Catalog* catalog) {
    if (!catalog || !catalog->canvas || !catalog->currentFolder) return;
    
    Folder* folder = catalog->currentFolder;
    int contentHeight = 20;  /* minimum padding */
    int contentWidth = 20;
    
    /* Find the extent of all items */
    for (int i = 0; i < folder->nItems; i++) {
        Item* item = folder->items[i];
        int itemBottom = item->y + CATALOG_GRID_Y;
        int itemRight = item->x + CATALOG_GRID_X;
        if (itemBottom > contentHeight) contentHeight = itemBottom;
        if (itemRight > contentWidth) contentWidth = itemRight;
    }
    
    /* Canvas must fill visible area but not exceed it unless content requires */
    if (contentWidth < CANVAS_MIN_WIDTH) contentWidth = CANVAS_MIN_WIDTH;
    if (contentHeight < CANVAS_MIN_HEIGHT) contentHeight = CANVAS_MIN_HEIGHT;
    
    XtVaSetValues(catalog->canvas, XmNheight, contentHeight, XmNwidth, contentWidth, NULL);
}

/* ---- MENUS  -------------------------------------------------------- */

static MenuItem catalogFileMenuItems[] = {
    {"Open Selected", &xmPushButtonWidgetClass, 'O', "Ctrl<Key>O", "Ctrl-O",
     openSelectedItemsCB, NULL, "Open the selected folder or link.", TRUE, (MenuItem*)NULL},
    {"Add Current Page", &xmPushButtonWidgetClass, 'A', NULL, NULL,
     addCurrentPageCB, NULL, "Add the current browser page to this folder.", TRUE, (MenuItem*)NULL},
    {"", &xmSeparatorGadgetClass, (char)0, NULL, NULL, NULL, NULL, NULL, TRUE, (MenuItem*)NULL},
    {"New Folder", &xmPushButtonWidgetClass, 'N', "Ctrl<Key>N", "Ctrl-N",
     newFolderCB, NULL, "Create a new folder.", TRUE, (MenuItem*)NULL},
    {"New Link", &xmPushButtonWidgetClass, 'L', "Ctrl<Key>L", "Ctrl-L",
     newLinkCB, NULL, "Create a new link.", TRUE, (MenuItem*)NULL},
    {"Delete", &xmPushButtonWidgetClass, 'D', "<Key>Delete", "Delete",
     deleteSelectedCB, NULL, "Delete selected items.", TRUE, (MenuItem*)NULL},
    {"", &xmSeparatorGadgetClass, (char)0, NULL, NULL, NULL, NULL, NULL, TRUE, (MenuItem*)NULL},
    {"Go Up", &xmPushButtonWidgetClass, 'U', "<Key>BackSpace", "Backspace",
     goUpFolderCB, NULL, "Go to parent folder.", TRUE, (MenuItem*)NULL},
    {"", &xmSeparatorGadgetClass, (char)0, NULL, NULL, NULL, NULL, NULL, TRUE, (MenuItem*)NULL},
    {"Save", &xmPushButtonWidgetClass, 'S', "Ctrl<Key>S", "Ctrl-S",
     saveCatalogCB, NULL, "Save the catalog.", TRUE, (MenuItem*)NULL},
    {"Close", &xmPushButtonWidgetClass, 'C', "Ctrl<Key>W", "Ctrl-W",
     closeCatalogCB, NULL, "Close this catalog window.", TRUE, (MenuItem*)NULL},
    NULL,
};

static void renameCB(Widget widget, XtPointer clientData, XtPointer callData);

static MenuItem catalogEditMenuItems[] = {
    {"Select All", &xmPushButtonWidgetClass, 'A', "Ctrl<Key>A", "Ctrl-A",
     selectAllCB, NULL, "Select all items in folder.", TRUE, (MenuItem*)NULL},
    {"Edit Label...", &xmPushButtonWidgetClass, 'E', "Ctrl<Key>E", "Ctrl-E",
     renameCB, NULL, "Edit the label of the selected item.", TRUE, (MenuItem*)NULL},
    NULL,
};

static MenuItem catalogCatalogMenuItems[] = {
    {"Clean Up Window", &xmPushButtonWidgetClass, 'C', NULL, NULL,
     cleanupFolder, NULL, "Neatly organize the icons in the current folder.", TRUE, (MenuItem*)NULL},
    {"Alphabetize", &xmPushButtonWidgetClass, 'l', NULL, NULL,
     alphabetizeFolder, NULL, "Organize icons alphabetically.", TRUE, (MenuItem*)NULL},
    NULL,
};

static MenuItem catalogHelpMenuItems[] = {
    {"About Catalog", &xmPushButtonWidgetClass, 'A', NULL, NULL,
     aboutCatalogCB, NULL, "About the Personal URL Catalog.", TRUE, (MenuItem*)NULL},
    NULL,
};

static Menu catalogMenus[] = {
    {"File", 'F', catalogFileMenuItems},
    {"Edit", 'E', catalogEditMenuItems},
    {"Organize", 'O', catalogCatalogMenuItems},
    NULL,
};

/* ---- UTILITY FUNCTIONS ---------------------------------------------- */

static char* expandPath(const char* path) {
    static char expanded[1024];
    if (path[0] == '~') {
        char* home = getenv("HOME");
        if (home) {
            snprintf(expanded, sizeof(expanded), "%s%s", home, path + 1);
            return expanded;
        }
    }
    strncpy(expanded, path, sizeof(expanded) - 1);
    expanded[sizeof(expanded) - 1] = '\0';
    return expanded;
}

static char* duplicateString(const char* s) {
    if (!s) return NULL;
    char* dup = malloc(strlen(s) + 1);
    if (dup) strcpy(dup, s);
    return dup;
}

static char* trimWhitespace(char* str) {
    char* end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

/* ---- ICON INITIALIZATION -------------------------------------------- */

int initCatalog(Widget shell, Catalog* catalog) {
    Display* display = XtDisplay(shell);
    Screen* screen = XtScreen(shell);
    Colormap cmap = DefaultColormapOfScreen(screen);
    XpmAttributes attrs;
    int status;

    if (iconsInitialized)
        return 1;

    memset(&attrs, 0, sizeof(attrs));
    attrs.valuemask = XpmColormap | XpmDepth | XpmVisual;
    attrs.colormap = cmap;
    attrs.depth = DefaultDepthOfScreen(screen);
    attrs.visual = DefaultVisualOfScreen(screen);

    /* Create folder icon */
    status = XpmCreatePixmapFromData(display, RootWindowOfScreen(screen),
                                     folderIconXPM, &defaultFolderIcon,
                                     &defaultFolderMask, &attrs);
    if (status != XpmSuccess) {
        fprintf(stderr, "Catalog: Could not create folder icon (status=%d)\n", status);
        defaultFolderIcon = 0;
    }

    /* Create link icon */
    status = XpmCreatePixmapFromData(display, RootWindowOfScreen(screen),
                                     linkIconXPM, &defaultLinkIcon,
                                     &defaultLinkMask, &attrs);
    if (status != XpmSuccess) {
        fprintf(stderr, "Catalog: Could not create link icon (status=%d)\n", status);
        defaultLinkIcon = 0;
    }

    /* Create font list for drawing text */
    if (!catalogFontList) {
        XmFontListEntry entry = XmFontListEntryLoad(display, "fixed",
                                                    XmFONT_IS_FONT, "catalogFont");
        if (entry) {
            catalogFontList = XmFontListAppendEntry(NULL, entry);
            XmFontListEntryFree(&entry);
        }
    }

    /* Create XOR GC for rubber-band drawing */
    if (catalog) {
        XGCValues gcv;
        gcv.function = GXxor;
        gcv.foreground = WhitePixelOfScreen(screen) ^ BlackPixelOfScreen(screen);
        gcv.line_style = LineOnOffDash;
        catalog->xorGC = XCreateGC(display, RootWindowOfScreen(screen),
                                   GCFunction | GCForeground | GCLineStyle, &gcv);

        /* Create normal GC */
        gcv.function = GXcopy;
        gcv.foreground = BlackPixelOfScreen(screen);
        gcv.background = WhitePixelOfScreen(screen);
        catalog->gc = XCreateGC(display, RootWindowOfScreen(screen),
                                GCFunction | GCForeground | GCBackground, &gcv);
    }

    iconsInitialized = 1;
    return 1;
}

/* ---- SERIALIZATION -------------------------------------------------- */

static void writeFolder(FILE* fp, Folder* folder, int indent);

static void writeItem(FILE* fp, Item* item, int indent) {
    char indentStr[64];
    int i;
    for (i = 0; i < indent && i < 62; i++) indentStr[i] = ' ';
    indentStr[i] = '\0';

    if (item->type == LINK) {
        Link* link = (Link*)item;
        fprintf(fp, "%sLINK:%s|%s|%s|%d,%d\n",
                indentStr,
                link->url ? link->url : "",
                link->name ? link->name : "",
                link->comment ? link->comment : "",
              (int)link->x, (int)link->y);
    } else if (item->type == FOLDER) {
        writeFolder(fp, (Folder*)item, indent);
    }
}

static void writeFolder(FILE* fp, Folder* folder, int indent) {
    char indentStr[64];
    int i;
    for (i = 0; i < indent && i < 62; i++) indentStr[i] = ' ';
    indentStr[i] = '\0';

    fprintf(fp, "%sFOLDER:%s|%d,%d\n", indentStr,
            folder->name ? folder->name : "Unnamed",
            (int)folder->x, (int)folder->y);

    for (i = 0; i < folder->nItems; i++) {
        writeItem(fp, folder->items[i], indent + 2);
    }

    fprintf(fp, "%sEND_FOLDER\n", indentStr);
}

int writeCatalog(Catalog* catalog, const char* filename) {
    FILE* fp;
    char* path = expandPath(filename);

    fp = fopen(path, "w");
    if (!fp) {
        fprintf(stderr, "Error: Could not open catalog file for writing: %s\n", path);
        return 0;
    }

    fprintf(fp, "viola-catalog-format-1\n");
    fprintf(fp, "Personal URL Catalog\n");
    fprintf(fp, "---\n");

    if (catalog->topFolder) {
        for (int i = 0; i < catalog->topFolder->nItems; i++) {
            writeItem(fp, catalog->topFolder->items[i], 0);
        }
    }

    fclose(fp);
    catalog->modified = 0;
    return 1;
}

static Folder* parseFolder(FILE* fp, char* line, Catalog* catalog);

static Item* parseLine(FILE* fp, char* line, Catalog* catalog) {
    char* trimmed = trimWhitespace(line);

    if (strncmp(trimmed, "FOLDER:", 7) == 0) {
        return (Item*)parseFolder(fp, trimmed + 7, catalog);
    } else if (strncmp(trimmed, "LINK:", 5) == 0) {
        /* Parse: url|name|comment|x,y */
        char* data = trimmed + 5;
        char* url = strtok(data, "|");
        char* name = strtok(NULL, "|");
        char* comment = strtok(NULL, "|");
        char* pos = strtok(NULL, "|");
        int x = 50, y = 50;

        if (pos) {
            sscanf(pos, "%d,%d", &x, &y);
        }

        Link* link = (Link*)calloc(1, sizeof(Link));
        link->type = LINK;
        link->state = NONE;
        link->url = url ? duplicateString(url) : NULL;
        link->name = name ? duplicateString(name) : duplicateString(url);
        link->comment = comment ? duplicateString(comment) : NULL;
        link->x = (short)x;
        link->y = (short)y;
        link->w = defaultLinkWidth;
        link->h = defaultLinkHeight;
        link->icon = defaultLinkIcon;
        link->gc = catalog->gc;

        if (link->name) {
            link->nameXMS = catalogFontList ? createWrappedLabel(link->name, catalogFontList) 
                                            : XmStringCreateLocalized(link->name);
            link->nx = link->x;
            link->ny = (short)(link->y + link->h + 4);
        }

        return (Item*)link;
    }

    return NULL;
}

static Folder* parseFolder(FILE* fp, char* headerData, Catalog* catalog) {
    char line[1024];
    char* name;
    char* pos;
    int x = 50, y = 50;

    /* Parse header: name|x,y */
    name = strtok(headerData, "|");
    pos = strtok(NULL, "|");
    if (pos) {
        sscanf(pos, "%d,%d", &x, &y);
    }

    Folder* folder = (Folder*)calloc(1, sizeof(Folder));
    folder->type = FOLDER;
    folder->state = NONE;
    folder->name = name ? duplicateString(name) : duplicateString("Unnamed");
    folder->x = (short)x;
    folder->y = (short)y;
    folder->w = defaultFolderWidth;
    folder->h = defaultFolderHeight;
    folder->icon = defaultFolderIcon;
    folder->gc = catalog->gc;
    folder->items = (Item**)calloc(ITEM_ALLOC_CHUNK, sizeof(Item*));
    folder->nItems = 0;
    folder->allocedItems = ITEM_ALLOC_CHUNK;

    if (folder->name) {
        folder->nameXMS = catalogFontList ? createWrappedLabel(folder->name, catalogFontList)
                                          : XmStringCreateLocalized(folder->name);
        folder->nx = folder->x;
        folder->ny = (short)(folder->y + folder->h + 4);
    }

    /* Read folder contents until END_FOLDER */
    while (fgets(line, sizeof(line), fp)) {
        char* trimmed = trimWhitespace(line);
        if (strncmp(trimmed, "END_FOLDER", 10) == 0) {
        break;
        }

        Item* item = parseLine(fp, line, catalog);
        if (item) {
            if (folder->nItems >= folder->allocedItems) {
                folder->allocedItems += ITEM_ALLOC_CHUNK;
                folder->items = (Item**)realloc(folder->items,
                                                folder->allocedItems * sizeof(Item*));
            }
            folder->items[folder->nItems++] = item;
        }
    }

    /* Update item count string */
    char countStr[16];
    snprintf(countStr, sizeof(countStr), "%d", folder->nItems);
    folder->nItemsXMS = XmStringCreateLocalized(countStr);
    folder->numx = (short)(folder->x + folder->w / 2 - 10);  /* Center in 20px width */
    folder->numy = (short)(folder->y + folder->h / 2 - 6);   /* Above center */

    return folder;
}

int readCatalog(Catalog* catalog, const char* filename) {
    FILE* fp;
    char line[1024];
    char* path = expandPath(filename);

    fp = fopen(path, "r");
    if (!fp) {
        /* .viola-catalog doesn't exist, try importing from Mosaic Hot List */
        char* hotlistPath = expandPath("~/.mosaic-hotlist-default");
        FILE* hotlistFp = fopen(hotlistPath, "r");
        
        /* Create default structure first */
        catalog->topFolder = (Folder*)calloc(1, sizeof(Folder));
        catalog->topFolder->type = FOLDER;
        catalog->topFolder->name = duplicateString("Root");
        catalog->topFolder->items = (Item**)calloc(ITEM_ALLOC_CHUNK, sizeof(Item*));
        catalog->topFolder->allocedItems = ITEM_ALLOC_CHUNK;
        catalog->topFolder->nItems = 0;
        catalog->currentFolder = catalog->topFolder;
        catalog->catalogFileName = duplicateString(filename);
        
        if (hotlistFp) {
            /* Try to import from Mosaic Hot List */
            char urlLine[1024], descLine[1024];
            
            /* Read and verify header */
            if (fgets(line, sizeof(line), hotlistFp) && 
                strncmp(line, "ncsa-xmosaic-hotlist-format-1", 29) == 0) {
                
                /* Skip title line (e.g., "Default") */
                fgets(line, sizeof(line), hotlistFp);
                
                /* Read URL/description pairs */
                int x = 20, y = 20;
                int itemCount = 0;
                
                while (fgets(urlLine, sizeof(urlLine), hotlistFp)) {
                    /* Remove newline */
                    size_t len = strlen(urlLine);
                    if (len > 0 && urlLine[len-1] == '\n') urlLine[len-1] = '\0';
                    if (urlLine[0] == '\0') continue;
                    
                    /* Extract URL (before first space) and date (after) */
                    char* url = urlLine;
                    char* space = strchr(urlLine, ' ');
                    if (space) *space = '\0';  /* Truncate at space to get URL only */
                    
                    /* Read description line */
                    if (!fgets(descLine, sizeof(descLine), hotlistFp)) break;
                    len = strlen(descLine);
                    if (len > 0 && descLine[len-1] == '\n') descLine[len-1] = '\0';
                    
                    /* Create link */
                    Link* link = (Link*)calloc(1, sizeof(Link));
                    link->type = LINK;
                    link->state = NONE;
                    link->url = duplicateString(url);
                    link->name = duplicateString(descLine[0] ? descLine : url);
                    link->w = defaultLinkWidth;
                    link->h = defaultLinkHeight;
                    link->icon = defaultLinkIcon;
                    link->gc = catalog->gc;
                    link->x = (short)x;
                    link->y = (short)y;
                    link->nx = link->x;
                    link->ny = (short)(link->y + link->h + 4);
                    
                    if (link->name) {
                        link->nameXMS = catalogFontList ? createWrappedLabel(link->name, catalogFontList)
                                                        : XmStringCreateLocalized(link->name);
                    }
                    
                    /* Add to folder */
                    if (catalog->topFolder->nItems >= catalog->topFolder->allocedItems) {
                        catalog->topFolder->allocedItems += ITEM_ALLOC_CHUNK;
                        catalog->topFolder->items = (Item**)realloc(
                            catalog->topFolder->items,
                            catalog->topFolder->allocedItems * sizeof(Item*));
                    }
                    catalog->topFolder->items[catalog->topFolder->nItems++] = (Item*)link;
                    
                    /* Grid layout */
                    x += CATALOG_GRID_X;
                    if (x > 350) {
                        x = 20;
                        y += CATALOG_GRID_Y;
                    }
                    itemCount++;
                }
                
                if (itemCount > 0) {
                    catalog->modified = 1;  /* Mark for save to .viola-catalog */
                }
            }
            fclose(hotlistFp);
        }
        
        return 1;
    }

    /* Read header */
    if (!fgets(line, sizeof(line), fp) || strncmp(line, "viola-catalog-format-1", 22) != 0) {
        fprintf(stderr, "Warning: Invalid catalog format, creating new catalog\n");
        fclose(fp);
        catalog->topFolder = (Folder*)calloc(1, sizeof(Folder));
        catalog->topFolder->type = FOLDER;
        catalog->topFolder->name = duplicateString("Root");
        catalog->topFolder->items = (Item**)calloc(ITEM_ALLOC_CHUNK, sizeof(Item*));
        catalog->topFolder->allocedItems = ITEM_ALLOC_CHUNK;
        catalog->currentFolder = catalog->topFolder;
        catalog->catalogFileName = duplicateString(filename);
        return 1;
    }

    /* Skip title line */
    fgets(line, sizeof(line), fp);
    /* Skip separator */
    fgets(line, sizeof(line), fp);

    /* Create root folder */
    catalog->topFolder = (Folder*)calloc(1, sizeof(Folder));
    catalog->topFolder->type = FOLDER;
    catalog->topFolder->name = duplicateString("Root");
    catalog->topFolder->items = (Item**)calloc(ITEM_ALLOC_CHUNK, sizeof(Item*));
    catalog->topFolder->allocedItems = ITEM_ALLOC_CHUNK;
    catalog->topFolder->nItems = 0;
    catalog->topFolder->gc = catalog->gc;

    /* Read items */
    while (fgets(line, sizeof(line), fp)) {
        Item* item = parseLine(fp, line, catalog);
        if (item) {
            if (catalog->topFolder->nItems >= catalog->topFolder->allocedItems) {
                catalog->topFolder->allocedItems += ITEM_ALLOC_CHUNK;
                catalog->topFolder->items = (Item**)realloc(
                    catalog->topFolder->items,
                    catalog->topFolder->allocedItems * sizeof(Item*));
            }
            catalog->topFolder->items[catalog->topFolder->nItems++] = item;
        }
    }

    fclose(fp);

    catalog->currentFolder = catalog->topFolder;
    catalog->catalogFileName = duplicateString(filename);
    catalog->modified = 0;

    return 1;
}

/* ---- DRAWING -------------------------------------------------------- */

static void drawItem(Widget canvas, Item* item, Catalog* catalog, int selected) {
    Display* display;
    Window window;
    GC gc;

    if (!canvas || !item || !catalog) return;

    display = XtDisplay(canvas);
    window = XtWindow(canvas);
    gc = catalog->gc;

    if (!window || !gc) return;

    /* Draw icon - must check icon is valid pixmap (non-zero) */
    if (item->icon != 0 && item->w > 0 && item->h > 0) {
        /* Use mask for transparency */
        Pixmap mask = (item->type == FOLDER) ? defaultFolderMask : defaultLinkMask;
        if (mask) {
            XSetClipMask(display, gc, mask);
            XSetClipOrigin(display, gc, (int)item->x, (int)item->y);
        }
        XCopyArea(display, item->icon, window, gc, 0, 0,
                  (unsigned int)item->w, (unsigned int)item->h,
                  (int)item->x, (int)item->y);
        if (mask) {
            XSetClipMask(display, gc, None);
        }
    } else {
        /* Draw placeholder rectangle when icon not available */
        XDrawRectangle(display, window, gc, item->x, item->y,
                       (unsigned int)(item->w > 0 ? item->w : 32),
                       (unsigned int)(item->h > 0 ? item->h : 32));
    }

    /* Draw name centered under icon */
    if (item->nameXMS && catalogFontList) {
        /* Use cellWidth if set, otherwise fall back to CATALOG_GRID_X */
        int cellW = (catalog && catalog->cellWidth > 0) ? catalog->cellWidth : CATALOG_GRID_X;
        /* Center text under icon */
        int textX = item->x - (cellW - item->w) / 2;
        XmStringDraw(display, window, catalogFontList, item->nameXMS, gc,
                     textX, item->ny, cellW,
                     XmALIGNMENT_CENTER, XmSTRING_DIRECTION_L_TO_R, NULL);
    }

    /* Draw selection highlight */
    if (selected || item->state == SELECTED) {
        /* Calculate selection box to encompass icon and text */
        int selX, selY, selW, selH;
        Dimension textWidth = 0, textHeight = 0;
        
        if (item->nameXMS && catalogFontList) {
            XmStringExtent(catalogFontList, item->nameXMS, &textWidth, &textHeight);
        }
        
        /* Use max of icon width and text width */
        int contentWidth = (textWidth > item->w) ? textWidth : item->w;
        
        /* Center the selection box */
        selX = item->x + item->w / 2 - contentWidth / 2 - 2;
        selY = item->y - 2;
        selW = contentWidth + 4;
        selH = item->h + textHeight + 8;  /* icon + actual text height + padding */
        
        XDrawRectangle(display, window, gc, selX, selY,
                       (unsigned int)selW, (unsigned int)selH);
    }

    /* For folders only, draw item count inside the icon */
    if (item->type == FOLDER) {
        Folder* folder = (Folder*)item;
        if (folder->nItemsXMS && catalogFontList) {
            XmStringDraw(display, window, catalogFontList, folder->nItemsXMS, gc,
                         folder->numx, folder->numy, 20,
                         XmALIGNMENT_CENTER, XmSTRING_DIRECTION_L_TO_R, NULL);
        }
    }
}

void redrawCatalog(Catalog* catalog) {
    if (!catalog || !catalog->canvas || !catalog->currentFolder)
        return;

    Window window = XtWindow(catalog->canvas);
    if (!window) return;

    Display* display = XtDisplay(catalog->canvas);

    /* Clear canvas */
    XClearWindow(display, window);

    /* Draw all items */
    for (int i = 0; i < catalog->currentFolder->nItems; i++) {
        Item* item = catalog->currentFolder->items[i];
        int selected = 0;
        for (int j = 0; j < catalog->nSelected; j++) {
            if (catalog->selectedItems[j] == item) {
                selected = 1;
        break;
            }
        }
        drawItem(catalog->canvas, item, catalog, selected);
    }
}

/* ---- SELECTION ------------------------------------------------------ */

Item* findItemAt(Catalog* catalog, int x, int y) {
    if (!catalog || !catalog->currentFolder) return NULL;

    for (int i = catalog->currentFolder->nItems - 1; i >= 0; i--) {
        Item* item = catalog->currentFolder->items[i];
        /* Check icon bounds */
        if (x >= item->x && x < item->x + item->w &&
            y >= item->y && y < item->y + item->h + 16) {
            return item;
        }
    }
    return NULL;
}

void deselectAll(Catalog* catalog) {
    for (int i = 0; i < catalog->nSelected; i++) {
        catalog->selectedItems[i]->state = NONE;
    }
    catalog->nSelected = 0;
}

void selectItem(Catalog* catalog, Item* item, int addToSelection) {
    if (!addToSelection) {
        deselectAll(catalog);
    }

    /* Check if already selected */
    for (int i = 0; i < catalog->nSelected; i++) {
        if (catalog->selectedItems[i] == item) {
            if (addToSelection) {
                /* Deselect it */
                item->state = NONE;
                for (int j = i; j < catalog->nSelected - 1; j++) {
                    catalog->selectedItems[j] = catalog->selectedItems[j + 1];
                }
                catalog->nSelected--;
            }
            return;
        }
    }

    /* Add to selection */
    if (catalog->nSelected < MAX_SELECTIONS) {
        catalog->selectedItems[catalog->nSelected++] = item;
        item->state = SELECTED;
    }
}

/* ---- MOUSE HANDLERS ------------------------------------------------- */

static void catalogButtonDownEH(Widget widget, XtPointer clientData, XEvent* event, Boolean* cont) {
    Catalog* catalog = (Catalog*)clientData;
    XButtonEvent* be = (XButtonEvent*)event;

    if (be->button != Button1) return;

    Item* item = findItemAt(catalog, be->x, be->y);

    catalog->dragStartX = (short)be->x;
    catalog->dragStartY = (short)be->y;
    catalog->dragLastX = (short)be->x;
    catalog->dragLastY = (short)be->y;

    if (item) {
        /* Check for double-click */
        if (be->time - catalog->lastClickTime < DOUBLE_CLICK_TIME &&
            item == catalog->lastClickedItem) {
            /* Double click - open item */
            if (item->type == FOLDER) {
                openFolder((Folder*)item, catalog);
            } else if (item->type == LINK) {
                openLink((Link*)item, catalog);
            }
            catalog->lastClickTime = 0;
            catalog->lastClickedItem = NULL;
        return;
        }

        catalog->lastClickTime = be->time;
        catalog->lastClickedItem = item;

        /* Handle selection */
        if (be->state & ShiftMask) {
            selectItem(catalog, item, 1);
        } else {
            int alreadySelected = 0;
            for (int i = 0; i < catalog->nSelected; i++) {
                if (catalog->selectedItems[i] == item) {
                    alreadySelected = 1;
                    break;
                }
            }
            if (!alreadySelected) {
                selectItem(catalog, item, 0);
            }
        }

        catalog->dragState = DRAG_PENDING;
    } else {
        /* Click in empty space - start selection rectangle */
        deselectAll(catalog);
        catalog->dragState = DRAG_SELECT_RECT;
        catalog->selectRectX = (short)be->x;
        catalog->selectRectY = (short)be->y;
        catalog->selectRectW = 0;
        catalog->selectRectH = 0;
    }

    redrawCatalog(catalog);
}

static void catalogButtonUpEH(Widget widget, XtPointer clientData, XEvent* event, Boolean* cont) {
    Catalog* catalog = (Catalog*)clientData;
    XButtonEvent* be = (XButtonEvent*)event;

    if (be->button != Button1) return;

    if (catalog->dragState == DRAG_ACTIVE) {
        /* Move selected items */
        int dx = be->x - catalog->dragStartX;
        int dy = be->y - catalog->dragStartY;

        for (int i = 0; i < catalog->nSelected; i++) {
            Item* item = catalog->selectedItems[i];
            item->x = (short)(item->x + dx);
            item->y = (short)(item->y + dy);
            item->nx = item->x;
            item->ny = (short)(item->y + item->h + 4);
            if (item->type == FOLDER) {
                Folder* f = (Folder*)item;
                f->numx = (short)(f->x + f->w / 2 - 10);
                f->numy = (short)(f->y + f->h / 2 - 6);
            }
        }
        catalog->modified = 1;
    } else if (catalog->dragState == DRAG_SELECT_RECT && catalog->xorGC) {
        /* Erase selection rectangle (normalize coordinates) */
        Display* display = XtDisplay(widget);
        Window window = XtWindow(widget);
        if (window) {
            int eraseX = catalog->selectRectX;
            int eraseY = catalog->selectRectY;
            int eraseW = catalog->selectRectW;
            int eraseH = catalog->selectRectH;
            if (eraseW < 0) { eraseX += eraseW; eraseW = -eraseW; }
            if (eraseH < 0) { eraseY += eraseH; eraseH = -eraseH; }
            XDrawRectangle(display, window, catalog->xorGC, eraseX, eraseY,
                           (unsigned int)eraseW, (unsigned int)eraseH);
        }

        /* Select all items within rectangle */
        int rx1 = catalog->selectRectX;
        int ry1 = catalog->selectRectY;
        int rx2 = rx1 + catalog->selectRectW;
        int ry2 = ry1 + catalog->selectRectH;
        if (rx1 > rx2) { int t = rx1; rx1 = rx2; rx2 = t; }
        if (ry1 > ry2) { int t = ry1; ry1 = ry2; ry2 = t; }

        for (int i = 0; i < catalog->currentFolder->nItems; i++) {
            Item* item = catalog->currentFolder->items[i];
            int ix = item->x + item->w / 2;
            int iy = item->y + item->h / 2;
            if (ix >= rx1 && ix <= rx2 && iy >= ry1 && iy <= ry2) {
                selectItem(catalog, item, 1);
            }
        }
    }

    catalog->dragState = DRAG_NONE;
    redrawCatalog(catalog);
}

static void catalogButtonMotionEH(Widget widget, XtPointer clientData, XEvent* event, Boolean* cont) {
    Catalog* catalog = (Catalog*)clientData;
    XMotionEvent* me = (XMotionEvent*)event;

    if (!(me->state & Button1Mask)) return;

    if (catalog->dragState == DRAG_PENDING) {
        int dx = me->x - catalog->dragStartX;
        int dy = me->y - catalog->dragStartY;
        if (dx * dx + dy * dy > DRAG_THRESHOLD * DRAG_THRESHOLD) {
            catalog->dragState = DRAG_ACTIVE;
        }
    }

    if (catalog->dragState == DRAG_SELECT_RECT && catalog->xorGC) {
        Display* display = XtDisplay(widget);
        Window window = XtWindow(widget);

        if (window) {
            /* Erase old rectangle (normalize coordinates for proper XOR erase) */
            int oldX = catalog->selectRectX;
            int oldY = catalog->selectRectY;
            int oldW = catalog->selectRectW;
            int oldH = catalog->selectRectH;
            if (oldW < 0) { oldX += oldW; oldW = -oldW; }
            if (oldH < 0) { oldY += oldH; oldH = -oldH; }
            XDrawRectangle(display, window, catalog->xorGC, oldX, oldY, (unsigned int)oldW, (unsigned int)oldH);

            /* Update rectangle */
            catalog->selectRectW = (short)(me->x - catalog->selectRectX);
            catalog->selectRectH = (short)(me->y - catalog->selectRectY);

            /* Draw new rectangle (normalize coordinates) */
            int x = catalog->selectRectX;
            int y = catalog->selectRectY;
            int w = catalog->selectRectW;
            int h = catalog->selectRectH;
            if (w < 0) { x += w; w = -w; }
            if (h < 0) { y += h; h = -h; }
            XDrawRectangle(display, window, catalog->xorGC, x, y, (unsigned int)w, (unsigned int)h);
        }
    }

    catalog->dragLastX = (short)me->x;
    catalog->dragLastY = (short)me->y;
}

static void catalogExposureEH(Widget widget, XtPointer clientData, XEvent* event, Boolean* cont) {
    Catalog* catalog = (Catalog*)clientData;
    redrawCatalog(catalog);
}

/* ---- ITEM OPERATIONS ------------------------------------------------ */

static void findOpenLocation(Folder* folder, int* x, int* y) {
    /* Grid-based placement using actual canvas width */
    int gridX = CATALOG_GRID_X;
    int gridY = CATALOG_GRID_Y;
    int col = 0, row = 0;
    
    /* Calculate maxCols based on canvas width */
    Dimension canvasWidth = 400;  /* default */
    if (theCatalog && theCatalog->canvas) {
        XtVaGetValues(theCatalog->canvas, XmNwidth, &canvasWidth, NULL);
    }
    int maxCols = (canvasWidth - 20) / gridX;
    if (maxCols < 1) maxCols = 1;

    /* Find first empty grid position */
    for (row = 0; row < 100; row++) {
        for (col = 0; col < maxCols; col++) {
            int testX = 20 + col * gridX;
            int testY = 20 + row * gridY;
            int occupied = 0;

            for (int i = 0; i < folder->nItems; i++) {
                Item* item = folder->items[i];
                if (abs(item->x - testX) < gridX / 2 && abs(item->y - testY) < gridY / 2) {
                    occupied = 1;
                    break;
                }
            }

            if (!occupied) {
                *x = testX;
                *y = testY;
        return;
            }
        }
    }

    *x = 20;
    *y = 20;
}

Link* createNewLink(Catalog* catalog, const char* url, const char* name, const char* comment) {
    if (!catalog || !catalog->currentFolder || !url) return NULL;

    Link* link = (Link*)calloc(1, sizeof(Link));
    link->type = LINK;
    link->state = NONE;
    link->url = duplicateString(url);
    link->name = duplicateString(name ? name : url);
    link->comment = duplicateString(comment);
    link->w = defaultLinkWidth;
    link->h = defaultLinkHeight;
    link->icon = defaultLinkIcon;
    link->gc = catalog->gc;

        int x, y;
    findOpenLocation(catalog->currentFolder, &x, &y);
    link->x = (short)x;
    link->y = (short)y;
    link->nx = link->x;
    link->ny = (short)(link->y + link->h + 4);

    if (link->name) {
        link->nameXMS = catalogFontList ? createWrappedLabel(link->name, catalogFontList)
                                        : XmStringCreateLocalized(link->name);
    }

    /* Add to current folder */
    Folder* folder = catalog->currentFolder;
    if (folder->nItems >= folder->allocedItems) {
        folder->allocedItems += ITEM_ALLOC_CHUNK;
        folder->items = (Item**)realloc(folder->items, folder->allocedItems * sizeof(Item*));
    }
    folder->items[folder->nItems++] = (Item*)link;

    /* Update folder item count */
    if (folder->nItemsXMS) XmStringFree(folder->nItemsXMS);
    char countStr[16];
    snprintf(countStr, sizeof(countStr), "%d", folder->nItems);
    folder->nItemsXMS = XmStringCreateLocalized(countStr);

    catalog->modified = 1;
    return link;
}

Folder* createNewFolder(Catalog* catalog, const char* name) {
    if (!catalog || !catalog->currentFolder) return NULL;

    Folder* folder = (Folder*)calloc(1, sizeof(Folder));
    folder->type = FOLDER;
    folder->state = NONE;
    folder->name = duplicateString(name ? name : "New Folder");
    folder->w = defaultFolderWidth;
    folder->h = defaultFolderHeight;
    folder->icon = defaultFolderIcon;
    folder->gc = catalog->gc;
    folder->items = (Item**)calloc(ITEM_ALLOC_CHUNK, sizeof(Item*));
    folder->allocedItems = ITEM_ALLOC_CHUNK;
    folder->nItems = 0;

    int x, y;
    findOpenLocation(catalog->currentFolder, &x, &y);
    folder->x = (short)x;
    folder->y = (short)y;
    folder->nx = folder->x;
    folder->ny = (short)(folder->y + folder->h + 4);
    folder->numx = (short)(folder->x + folder->w / 2 - 10);
    folder->numy = (short)(folder->y + folder->h / 2 - 6);

    if (folder->name) {
        folder->nameXMS = catalogFontList ? createWrappedLabel(folder->name, catalogFontList)
                                          : XmStringCreateLocalized(folder->name);
    }
    folder->nItemsXMS = XmStringCreateLocalized("0");

    /* Add to current folder */
    Folder* parent = catalog->currentFolder;
    if (parent->nItems >= parent->allocedItems) {
        parent->allocedItems += ITEM_ALLOC_CHUNK;
        parent->items = (Item**)realloc(parent->items, parent->allocedItems * sizeof(Item*));
    }
    parent->items[parent->nItems++] = (Item*)folder;

    /* Update parent item count */
    if (parent->nItemsXMS) XmStringFree(parent->nItemsXMS);
    char countStr[16];
    snprintf(countStr, sizeof(countStr), "%d", parent->nItems);
    parent->nItemsXMS = XmStringCreateLocalized(countStr);

    catalog->modified = 1;
    return folder;
}

void openLink(Link* link, Catalog* catalog) {
    if (!link || !link->url || !catalog || !catalog->dvi) return;

    /* Send URL to browser */
    if (catalog->dvi->violaDocViewObj) {
        sendMessage1N1str(catalog->dvi->violaDocViewObj, "show", link->url);
    }
}

void openFolder(Folder* folder, Catalog* catalog) {
    if (!folder || !catalog) return;

    folder->parent = catalog->currentFolder;  /* Store parent reference */
    catalog->currentFolder = folder;

    /* Update folder name display */
    if (catalog->folderNameText) {
        XmString xms = XmStringCreateLocalized(folder->name ? folder->name : "Root");
        XtVaSetValues(catalog->folderNameText, XmNlabelString, xms, NULL);
        XmStringFree(xms);
    }

    calculateCellWidth(catalog);
    deselectAll(catalog);
    updateCanvasSize(catalog);
    redrawCatalog(catalog);
}

void deleteSelectedItems(Catalog* catalog) {
    if (!catalog || catalog->nSelected == 0) return;

    Folder* folder = catalog->currentFolder;

    for (int s = 0; s < catalog->nSelected; s++) {
        Item* item = catalog->selectedItems[s];

        /* Find and remove from folder */
        for (int i = 0; i < folder->nItems; i++) {
            if (folder->items[i] == item) {
                /* Free item */
                if (item->type == LINK) {
                    Link* link = (Link*)item;
                    if (link->url) free(link->url);
                    if (link->name) free(link->name);
                    if (link->comment) free(link->comment);
                    if (link->nameXMS) XmStringFree(link->nameXMS);
                    free(link);
                } else if (item->type == FOLDER) {
                    /* Recursively free folder contents */
            forceDeleteFolder((Folder*)item, catalog);
                }

                /* Remove from array */
                for (int j = i; j < folder->nItems - 1; j++) {
                    folder->items[j] = folder->items[j + 1];
                }
                folder->nItems--;
                break;
            }
        }
    }

    catalog->nSelected = 0;
    catalog->modified = 1;

    /* Update folder item count */
    if (folder->nItemsXMS) XmStringFree(folder->nItemsXMS);
    char countStr[16];
    snprintf(countStr, sizeof(countStr), "%d", folder->nItems);
    folder->nItemsXMS = XmStringCreateLocalized(countStr);

    updateCanvasSize(catalog);
    redrawCatalog(catalog);
}

/* ---- MENU CALLBACKS ------------------------------------------------- */

static void openSelectedItemsCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog || catalog->nSelected == 0) return;

    Item* item = catalog->selectedItems[0];
    if (item->type == FOLDER) {
        openFolder((Folder*)item, catalog);
    } else if (item->type == LINK) {
        openLink((Link*)item, catalog);
    }
}

static void addCurrentPageCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog || !catalog->dvi) return;

    addCurrentPageToCatalog(catalog, catalog->dvi);
}

void addCurrentPageToCatalog(Catalog* catalog, DocViewInfo* dvi) {
    if (!catalog || !dvi) return;

    /* Get URL and title directly from DocViewInfo */
    const char* url = dvi->URL;
    const char* title = dvi->docName;

    if (!url || strlen(url) == 0) {
        /* No URL available */
        return;
    }

    /* Use title if available, otherwise use URL as name */
    const char* name = (title && strlen(title) > 0) ? title : url;

    createNewLink(catalog, url, name, NULL);
    updateCanvasSize(catalog);
    redrawCatalog(catalog);
}

/* Dialog callback data for new folder */
typedef struct {
    Catalog* catalog;
    Widget nameField;
    Widget dialog;
} NewFolderDialogData;

static void newFolderOkCB(Widget widget, XtPointer clientData, XtPointer callData) {
    NewFolderDialogData* data = (NewFolderDialogData*)clientData;

    char* name = XmTextFieldGetString(data->nameField);

    if (name && strlen(name) > 0) {
        createNewFolder(data->catalog, name);
    } else {
        createNewFolder(data->catalog, "New Folder");
    }
    updateCanvasSize(data->catalog);
    redrawCatalog(data->catalog);

    if (name) XtFree(name);

    XtDestroyWidget(XtParent(data->dialog));
    free(data);
}

static void newFolderCancelCB(Widget widget, XtPointer clientData, XtPointer callData) {
    NewFolderDialogData* data = (NewFolderDialogData*)clientData;
    XtDestroyWidget(XtParent(data->dialog));
    free(data);
}

static void newFolderCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog) return;

    /* Create dialog */
    Widget dialog, form, nameLabel, nameField, okBtn, cancelBtn;
    Arg args[10];
    int n = 0;

    XtSetArg(args[n], XmNautoUnmanage, FALSE); n++;
    XtSetArg(args[n], XmNnoResize, TRUE); n++;
    XtSetArg(args[n], XmNdialogTitle, XmStringCreateLocalized("New Folder")); n++;
    dialog = XmCreateFormDialog(catalog->shell, "newFolder", args, (Cardinal)n);

    form = dialog;

    nameLabel = XtVaCreateManagedWidget("Name:", xmLabelWidgetClass, form,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_FORM,
        XmNtopOffset, 10, XmNleftOffset, 10, NULL);

    nameField = XtVaCreateManagedWidget("nameField", xmTextFieldWidgetClass, form,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, nameLabel,
        XmNrightAttachment, XmATTACH_FORM,
        XmNtopOffset, 10, XmNleftOffset, 10, XmNrightOffset, 10,
        XmNcolumns, 30, NULL);
    XmTextFieldSetString(nameField, "New Folder");

    NewFolderDialogData* data = (NewFolderDialogData*)malloc(sizeof(NewFolderDialogData));
    data->catalog = catalog;
    data->nameField = nameField;
    data->dialog = dialog;

    okBtn = XtVaCreateManagedWidget("OK", xmPushButtonWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, nameField,
        XmNleftAttachment, XmATTACH_FORM,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNtopOffset, 20, XmNleftOffset, 10, XmNbottomOffset, 10, NULL);
    XtAddCallback(okBtn, XmNactivateCallback, newFolderOkCB, (XtPointer)data);

    cancelBtn = XtVaCreateManagedWidget("Cancel", xmPushButtonWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, nameField,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, okBtn,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNtopOffset, 20, XmNleftOffset, 10, XmNbottomOffset, 10, NULL);
    XtAddCallback(cancelBtn, XmNactivateCallback, newFolderCancelCB, (XtPointer)data);

    XtManageChild(dialog);
}

/* Dialog callback data for new link */
typedef struct {
    Catalog* catalog;
    Widget urlField;
    Widget nameField;
    Widget dialog;
} NewLinkDialogData;

static void newLinkOkCB(Widget widget, XtPointer clientData, XtPointer callData) {
    NewLinkDialogData* data = (NewLinkDialogData*)clientData;

    char* url = XmTextFieldGetString(data->urlField);
    char* name = XmTextFieldGetString(data->nameField);

    if (url && strlen(url) > 0) {
        createNewLink(data->catalog, url, name && strlen(name) > 0 ? name : url, NULL);
        updateCanvasSize(data->catalog);
        redrawCatalog(data->catalog);
    }

    if (url) XtFree(url);
    if (name) XtFree(name);

    XtDestroyWidget(XtParent(data->dialog));
    free(data);
}

static void newLinkCancelCB(Widget widget, XtPointer clientData, XtPointer callData) {
    NewLinkDialogData* data = (NewLinkDialogData*)clientData;
    XtDestroyWidget(XtParent(data->dialog));
    free(data);
}

static void newLinkCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog) return;

    /* Create dialog */
    Widget dialog, form, urlLabel, urlField, nameLabel, nameField, okBtn, cancelBtn;
    Arg args[10];
    int n = 0;

    XtSetArg(args[n], XmNautoUnmanage, FALSE); n++;
    XtSetArg(args[n], XmNnoResize, TRUE); n++;
    XtSetArg(args[n], XmNdialogTitle, XmStringCreateLocalized("Add New Link")); n++;
    dialog = XmCreateFormDialog(catalog->shell, "addLink", args, (Cardinal)n);

    form = dialog;

    urlLabel = XtVaCreateManagedWidget("URL:", xmLabelWidgetClass, form,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_FORM,
        XmNtopOffset, 10, XmNleftOffset, 10, NULL);

    urlField = XtVaCreateManagedWidget("urlField", xmTextFieldWidgetClass, form,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, urlLabel,
        XmNrightAttachment, XmATTACH_FORM,
        XmNtopOffset, 10, XmNleftOffset, 10, XmNrightOffset, 10,
        XmNcolumns, 40, NULL);

    nameLabel = XtVaCreateManagedWidget("Name:", xmLabelWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, urlField,
        XmNleftAttachment, XmATTACH_FORM,
        XmNtopOffset, 10, XmNleftOffset, 10, NULL);

    nameField = XtVaCreateManagedWidget("nameField", xmTextFieldWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, urlField,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, nameLabel,
        XmNrightAttachment, XmATTACH_FORM,
        XmNtopOffset, 10, XmNleftOffset, 10, XmNrightOffset, 10,
        XmNcolumns, 40, NULL);

    NewLinkDialogData* data = (NewLinkDialogData*)malloc(sizeof(NewLinkDialogData));
    data->catalog = catalog;
    data->urlField = urlField;
    data->nameField = nameField;
    data->dialog = dialog;

    okBtn = XtVaCreateManagedWidget("OK", xmPushButtonWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, nameField,
        XmNleftAttachment, XmATTACH_FORM,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNtopOffset, 20, XmNleftOffset, 10, XmNbottomOffset, 10, NULL);
    XtAddCallback(okBtn, XmNactivateCallback, newLinkOkCB, (XtPointer)data);

    cancelBtn = XtVaCreateManagedWidget("Cancel", xmPushButtonWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, nameField,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, okBtn,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNtopOffset, 20, XmNleftOffset, 10, XmNbottomOffset, 10, NULL);
    XtAddCallback(cancelBtn, XmNactivateCallback, newLinkCancelCB, (XtPointer)data);

    XtManageChild(dialog);
}

static void deleteSelectedCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog || catalog->nSelected == 0) return;

    deleteSelectedItems(catalog);
}

static void saveCatalogCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog) return;

    writeCatalog(catalog, catalog->catalogFileName);
}

static void goUpFolderCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog) return;

    /* Go to parent folder if not at root */
    if (catalog->currentFolder != catalog->topFolder &&
        catalog->currentFolder->parent != NULL) {
        catalog->currentFolder = catalog->currentFolder->parent;

        /* Update folder name display */
        if (catalog->folderNameText) {
            const char* name = catalog->currentFolder == catalog->topFolder
                ? "Root" : catalog->currentFolder->name;
            XmString xms = XmStringCreateLocalized((char*)(name ? name : "Root"));
            XtVaSetValues(catalog->folderNameText, XmNlabelString, xms, NULL);
            XmStringFree(xms);
        }

        calculateCellWidth(catalog);
        deselectAll(catalog);
        updateCanvasSize(catalog);
        redrawCatalog(catalog);
    }
}

static void selectAllCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog || !catalog->currentFolder) return;

    Folder* folder = catalog->currentFolder;
        int i;
    for (i = 0; i < folder->nItems; i++) {
        if (folder->items[i]) {
            folder->items[i]->state = SELECTED;
        }
    }
    redrawCatalog(catalog);
}

/* Rename dialog data */
typedef struct {
    Catalog* catalog;
    Item* item;
    Widget nameField;
    Widget urlField;  /* only for links */
    Widget dialog;
} RenameDialogData;

static void renameOkCB(Widget widget, XtPointer clientData, XtPointer callData) {
    RenameDialogData* data = (RenameDialogData*)clientData;
    char* newName = XmTextFieldGetString(data->nameField);

    if (newName && strlen(newName) > 0) {
        /* Update item name */
        if (data->item->name) free(data->item->name);
        data->item->name = strdup(newName);

        /* Update XmString */
        if (data->item->nameXMS) XmStringFree(data->item->nameXMS);
        data->item->nameXMS = catalogFontList ? createWrappedLabel(data->item->name, catalogFontList)
                                              : XmStringCreateLocalized(data->item->name);

        /* For links, also update URL if field exists */
        if (data->item->type == LINK && data->urlField) {
            char* newUrl = XmTextFieldGetString(data->urlField);
            if (newUrl && strlen(newUrl) > 0) {
                Link* link = (Link*)data->item;
                if (link->url) free(link->url);
                link->url = strdup(newUrl);
            }
            if (newUrl) XtFree(newUrl);
        }

        data->catalog->modified = 1;
        redrawCatalog(data->catalog);
    }

    if (newName) XtFree(newName);
    XtDestroyWidget(XtParent(data->dialog));
    free(data);
}

static void renameCancelCB(Widget widget, XtPointer clientData, XtPointer callData) {
    RenameDialogData* data = (RenameDialogData*)clientData;
    XtDestroyWidget(XtParent(data->dialog));
    free(data);
}

static void renameCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog) return;

    /* Check selection */
    if (catalog->nSelected == 0) {
        /* No selection - do nothing */
            return;
    }

    if (catalog->nSelected > 1) {
        /* Multiple selection - show message */
        XmString msg = XmStringCreateLocalized("Please select only one item to rename.");
        Widget msgDialog;
        Arg args[3];
        int n = 0;

        XtSetArg(args[n], XmNmessageString, msg); n++;
        XtSetArg(args[n], XmNdialogType, XmDIALOG_INFORMATION); n++;
        XtSetArg(args[n], XmNnoResize, True); n++;

        msgDialog = XmCreateMessageDialog(catalog->shell, "renameMsg", args, n);
        if (msgDialog) {
            Widget btn = XmMessageBoxGetChild(msgDialog, XmDIALOG_CANCEL_BUTTON);
            if (btn) XtUnmanageChild(btn);
            btn = XmMessageBoxGetChild(msgDialog, XmDIALOG_HELP_BUTTON);
            if (btn) XtUnmanageChild(btn);
            XtManageChild(msgDialog);
        }
        XmStringFree(msg);
        return;
    }

    /* Single selection - show rename dialog */
    Item* item = catalog->selectedItems[0];
    if (!item) return;

    Widget dialog, form, nameLabel, nameField, urlLabel, urlField, okBtn, cancelBtn;
    Arg args[10];
    int n = 0;
    int isLink = (item->type == LINK);

    XtSetArg(args[n], XmNautoUnmanage, FALSE); n++;
    XtSetArg(args[n], XmNnoResize, TRUE); n++;
    XtSetArg(args[n], XmNdialogTitle, XmStringCreateLocalized("Edit Label")); n++;
    dialog = XmCreateFormDialog(catalog->shell, "renameDialog", args, n);

    form = dialog;

    nameLabel = XtVaCreateManagedWidget("Name:", xmLabelWidgetClass, form,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_FORM,
        XmNtopOffset, 10, XmNleftOffset, 10, NULL);

    nameField = XtVaCreateManagedWidget("nameField", xmTextFieldWidgetClass, form,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, nameLabel,
        XmNrightAttachment, XmATTACH_FORM,
        XmNtopOffset, 10, XmNleftOffset, 10, XmNrightOffset, 10,
        XmNcolumns, 30, NULL);
    if (item->name) XmTextFieldSetString(nameField, item->name);

    urlField = NULL;
    if (isLink) {
        Link* link = (Link*)item;

        urlLabel = XtVaCreateManagedWidget("URL:", xmLabelWidgetClass, form,
            XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, nameField,
            XmNleftAttachment, XmATTACH_FORM,
            XmNtopOffset, 10, XmNleftOffset, 10, NULL);

        urlField = XtVaCreateManagedWidget("urlField", xmTextFieldWidgetClass, form,
            XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, nameField,
            XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, urlLabel,
            XmNrightAttachment, XmATTACH_FORM,
            XmNtopOffset, 10, XmNleftOffset, 10, XmNrightOffset, 10,
            XmNcolumns, 30, NULL);
        if (link->url) XmTextFieldSetString(urlField, link->url);
    }

    RenameDialogData* data = (RenameDialogData*)malloc(sizeof(RenameDialogData));
    data->catalog = catalog;
    data->item = item;
    data->nameField = nameField;
    data->urlField = urlField;
    data->dialog = dialog;

    Widget attachTo = isLink ? urlField : nameField;

    okBtn = XtVaCreateManagedWidget("OK", xmPushButtonWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, attachTo,
        XmNleftAttachment, XmATTACH_FORM,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNtopOffset, 20, XmNleftOffset, 10, XmNbottomOffset, 10, NULL);
    XtAddCallback(okBtn, XmNactivateCallback, renameOkCB, (XtPointer)data);

    cancelBtn = XtVaCreateManagedWidget("Cancel", xmPushButtonWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, attachTo,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, okBtn,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNtopOffset, 20, XmNleftOffset, 10, XmNbottomOffset, 10, NULL);
    XtAddCallback(cancelBtn, XmNactivateCallback, renameCancelCB, (XtPointer)data);

    XtManageChild(dialog);
}

static void aboutCatalogCB(Widget widget, XtPointer clientData, XtPointer callData) {
    Widget dialog, button;
    Arg args[10];
    int n = 0;
    XmString message;

    /* Use global theCatalog */
    if (!theCatalog || !theCatalog->shell) {
        return;
    }

    message = XmStringCreateLtoR(
        "Personal URL Catalog\n\n"
        "A bookmark organizer for ViolaWWW.\n\n"
        "Organize your favorite URLs in folders.\n"
        "Drag and drop to rearrange items.",
        XmFONTLIST_DEFAULT_TAG);

    XtSetArg(args[n], XmNmessageString, message); n++;
    XtSetArg(args[n], XmNdialogType, XmDIALOG_INFORMATION); n++;
    XtSetArg(args[n], XmNnoResize, True); n++;

    dialog = XmCreateMessageDialog(theCatalog->shell, "aboutCatalog", args, n);

    if (dialog) {
        /* Hide Cancel and Help buttons - only need OK */
        button = XmMessageBoxGetChild(dialog, XmDIALOG_CANCEL_BUTTON);
        if (button) XtUnmanageChild(button);
        button = XmMessageBoxGetChild(dialog, XmDIALOG_HELP_BUTTON);
        if (button) XtUnmanageChild(button);

        XtManageChild(dialog);
    }

    XmStringFree(message);
}

/* ---- MENU FUNCTIONS ------------------------------------------------- */

static int compareItemsByName(const void* a, const void* b) {
    Item* itemA = *(Item**)a;
    Item* itemB = *(Item**)b;
    const char* nameA = itemA->name ? itemA->name : "";
    const char* nameB = itemB->name ? itemB->name : "";
    return strcasecmp(nameA, nameB);
}

/* Set fixed cellWidth - labels are now wrapped to MAX_LABEL_WIDTH */
static void calculateCellWidth(Catalog* catalog) {
    if (!catalog) return;
    /* Fixed width: MAX_LABEL_WIDTH(80) + padding(20) = 100 */
    catalog->cellWidth = CATALOG_GRID_X;
}

void cleanupFolder(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog || !catalog->currentFolder) return;

    Folder* folder = catalog->currentFolder;
    
    /* Calculate cell width based on text widths */
    calculateCellWidth(catalog);
    int cellWidth = catalog->cellWidth;
    
    /* Calculate how many columns fit in the window */
    Dimension canvasWidth = 400;  /* default */
    if (catalog->canvas) {
        XtVaGetValues(catalog->canvas, XmNwidth, &canvasWidth, NULL);
    }
    int maxCols = (canvasWidth - 20) / cellWidth;
    if (maxCols < 1) maxCols = 1;
    
    int col = 0, row = 0;

    for (int i = 0; i < folder->nItems; i++) {
        Item* item = folder->items[i];
        /* Center icon in cell */
        int cellX = 20 + col * cellWidth;
        item->x = (short)(cellX + (cellWidth - item->w) / 2);
        item->y = (short)(20 + row * CATALOG_GRID_Y);
        /* Center text under icon */
        item->nx = (short)cellX;
        item->ny = (short)(item->y + item->h + 4);

        if (item->type == FOLDER) {
            Folder* f = (Folder*)item;
            f->numx = (short)(f->x + f->w / 2 - 10);
            f->numy = (short)(f->y + f->h / 2 - 6);
        }

        col++;
        if (col >= maxCols) {
            col = 0;
            row++;
        }
    }

    catalog->modified = 1;
    updateCanvasSize(catalog);
    redrawCatalog(catalog);
}

void alphabetizeFolder(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;

    if (!catalog || !catalog->currentFolder) return;

    Folder* folder = catalog->currentFolder;

    /* Sort items by name */
    qsort(folder->items, (size_t)folder->nItems, sizeof(Item*), compareItemsByName);

    /* Clean up positions after sorting */
    cleanupFolder(widget, clientData, callData);
}

/* ---- DELETE HELPERS ------------------------------------------------- */

static void forceDeleteLink(Link* link, Catalog* catalog) {
    if (!link) return;

    if (link->name) free(link->name);
    if (link->nameXMS) XmStringFree(link->nameXMS);
    if (link->commentURL) free(link->commentURL);
    if (link->url) free(link->url);
    if (link->comment) free(link->comment);
    if (link->iconFile) free(link->iconFile);
    free(link);
}

static void forceDeleteFolder(Folder* folder, Catalog* catalog) {
    if (!folder) return;

    for (int i = 0; i < folder->nItems; i++) {
        Item* item = folder->items[i];
        if (item->type == LINK) {
            forceDeleteLink((Link*)item, catalog);
        } else if (item->type == FOLDER) {
            forceDeleteFolder((Folder*)item, catalog);
        }
    }

    if (folder->items) free(folder->items);
    if (folder->iconFile) free(folder->iconFile);
    if (folder->commentURL) free(folder->commentURL);
    if (folder->name) free(folder->name);
    if (folder->nameXMS) XmStringFree(folder->nameXMS);
    if (folder->nItemsXMS) XmStringFree(folder->nItemsXMS);
    free(folder);
}

/* ---- MAIN WINDOW CREATION ------------------------------------------- */

Widget makeCatalogMenus(Widget mainWin, Widget helpLabel, Catalog* catalog) {
    return buildMenus(catalogMenus, catalogHelpMenuItems, mainWin, helpLabel, (void*)catalog);
}

void showCatalog(char* catalogFile, DocViewInfo* parentDVI) {
    XmString xms;
    Catalog* catalog;
    Widget shell, mainWindow, form, helpLabel, titleFrame, folderNameLabel, folderNameText,
        catalogTitleLabel, catalogTitleText, catalogFileLabel, catalogFileText, menubar,
        canvasFrame, canvas;

    /* Create catalog structure */
    catalog = (Catalog*)calloc(1, sizeof(Catalog));
    catalog->dvi = parentDVI;

    /* Create shell - fixed size, non-resizable */
    shell = XtVaAppCreateShell("Personal URL Catalog", "ViolaCatalog",
                               applicationShellWidgetClass, XtDisplay(parentDVI->shell),
                               XmNborderWidth, 2, XmNiconPixmap, icon,
                               XmNdeleteResponse, XmDO_NOTHING,  /* Don't close app on window close */
                               NULL);

    catalog->shell = shell;

    /* Initialize icons and GCs */
    initCatalog(shell, catalog);

    /* Read catalog file */
    readCatalog(catalog, catalogFile);
    
    /* Calculate initial cell width for layout */
    calculateCellWidth(catalog);

    mainWindow = XmCreateMainWindow(shell, "mainWindow", NULL, 0);

    form = XtVaCreateManagedWidget("form", xmFormWidgetClass, mainWindow,
        XmNhorizontalSpacing, FORM_SPACING,
        XmNverticalSpacing, FORM_SPACING, NULL);

    /* Help/status label at bottom */
    xms = XmStringCreateLocalized("Double-click to open items. Drag to move.");
    helpLabel = XtVaCreateManagedWidget("helpLabel", xmLabelWidgetClass, form,
        XmNleftAttachment, XmATTACH_FORM,
        XmNrightAttachment, XmATTACH_FORM,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNborderWidth, 1,
        XmNrecomputeSize, FALSE,
        XmNlabelString, xms, NULL);
    XmStringFree(xms);
    catalog->helpLabel = helpLabel;

    /* Title frame at top */
    titleFrame = XtVaCreateManagedWidget("titleFrame", xmFormWidgetClass, form,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_FORM,
        XmNrightAttachment, XmATTACH_FORM,
        XmNshadowThickness, 1,
        XmNhorizontalSpacing, 4,
        XmNverticalSpacing, 4, NULL);

    /* Current folder label */
    xms = XmStringCreateLocalized("Folder:");
    folderNameLabel = XtVaCreateManagedWidget("folderNameLabel", xmLabelWidgetClass, titleFrame,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_FORM,
        XmNtopOffset, 4, XmNleftOffset, 4,
        XmNlabelString, xms, NULL);
    XmStringFree(xms);

    xms = XmStringCreateLocalized("Root");
    folderNameText = XtVaCreateManagedWidget("folderNameText", xmLabelWidgetClass, titleFrame,
        XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, folderNameLabel,
        XmNrightAttachment, XmATTACH_FORM,
        XmNtopOffset, 4, XmNleftOffset, 4, XmNrightOffset, 4,
        XmNalignment, XmALIGNMENT_BEGINNING,
        XmNlabelString, xms, NULL);
    XmStringFree(xms);
    catalog->folderNameText = folderNameText;

    /* Catalog file label */
    char* expandedPath = expandPath(catalogFile);
    xms = XmStringCreateLocalized("File:");
    catalogFileLabel = XtVaCreateManagedWidget("catalogFileLabel", xmLabelWidgetClass, titleFrame,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, folderNameLabel,
        XmNleftAttachment, XmATTACH_FORM,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNtopOffset, 4, XmNleftOffset, 4, XmNbottomOffset, 4,
        XmNlabelString, xms, NULL);
    XmStringFree(xms);

    xms = XmStringCreateLocalized(expandedPath);
    catalogFileText = XtVaCreateManagedWidget("catalogFileText", xmLabelWidgetClass, titleFrame,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, folderNameLabel,
        XmNleftAttachment, XmATTACH_WIDGET, XmNleftWidget, catalogFileLabel,
        XmNrightAttachment, XmATTACH_FORM,
        XmNbottomAttachment, XmATTACH_FORM,
        XmNtopOffset, 4, XmNleftOffset, 4, XmNrightOffset, 4, XmNbottomOffset, 4,
        XmNalignment, XmALIGNMENT_BEGINNING,
        XmNlabelString, xms, NULL);
    XmStringFree(xms);
    catalog->catalogTitleText = catalogFileText;

    /* Canvas - original from author, with automatic scrolling */
    canvasFrame = XtVaCreateManagedWidget("canvasFrame", xmScrolledWindowWidgetClass, form,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, titleFrame,
        XmNbottomAttachment, XmATTACH_WIDGET, XmNbottomWidget, helpLabel,
        XmNleftAttachment, XmATTACH_FORM,
        XmNrightAttachment, XmATTACH_FORM,
        XmNshadowThickness, 1,
        XmNscrollingPolicy, XmAUTOMATIC,
        XmNscrollBarDisplayPolicy, XmAS_NEEDED,
        XmNwidth, 400, XmNheight, 250, NULL);

    setHelp(canvasFrame, helpLabel, "Double click on a document or folder to open it.");

    /* Canvas uses default application background color */
    canvas = XtVaCreateManagedWidget("canvas", xmDrawingAreaWidgetClass, canvasFrame,
        XmNwidth, CANVAS_MIN_WIDTH, XmNheight, CANVAS_MIN_HEIGHT,
        XmNborderWidth, 0,
        NULL);
    catalog->canvas = canvas;

    /* Add event handlers for mouse interaction */
    XtAddEventHandler(canvas, ExposureMask, FALSE, catalogExposureEH, (XtPointer)catalog);
    XtAddEventHandler(canvas, ButtonPressMask, FALSE, catalogButtonDownEH, (XtPointer)catalog);
    XtAddEventHandler(canvas, ButtonReleaseMask, FALSE, catalogButtonUpEH, (XtPointer)catalog);
    XtAddEventHandler(canvas, Button1MotionMask, FALSE, catalogButtonMotionEH, (XtPointer)catalog);

    /* Create menus */
    menubar = makeCatalogMenus(mainWindow, helpLabel, catalog);

    XmMainWindowSetAreas(mainWindow, menubar, (Widget)0, (Widget)0, (Widget)0, form);
    XtManageChild(mainWindow);

    /* Store global reference */
    theCatalog = catalog;

    /* Set up WM_DELETE_WINDOW protocol handler so clicking the X button
     * calls closeCatalogCB instead of closing the entire browser */
    XtAddEventHandler(shell, 0L, TRUE, catalogDeleteWindowEH, (XtPointer)catalog);

    /* Realize the shell first */
    XtRealizeWidget(shell);
    
    /* Set backing_store = Always to prevent black artifacts during resize */
    setBackingStoreTree(XtDisplay(shell), XtWindow(shell));
    
    /* Register resize handler to clear windows on resize */
    XtAddEventHandler(shell, StructureNotifyMask, FALSE, resizeShell, NULL);

    /* Register WM_DELETE_WINDOW protocol */
    {
        Atom wm_protocols = XInternAtom(XtDisplay(shell), "WM_PROTOCOLS", False);
        Atom wm_delete_window = XInternAtom(XtDisplay(shell), "WM_DELETE_WINDOW", False);
        if (wm_protocols != None && wm_delete_window != None) {
            XSetWMProtocols(XtDisplay(shell), XtWindow(shell), &wm_delete_window, 1);
        }
    }

    /* Make window non-resizable by setting min/max size to same value */
    {
        XSizeHints hints;
        Dimension width, height;
        
        XtVaGetValues(shell, XmNwidth, &width, XmNheight, &height, NULL);
        
        hints.flags = PMinSize | PMaxSize;
        hints.min_width = hints.max_width = width;
        hints.min_height = hints.max_height = height;
        XSetWMNormalHints(XtDisplay(shell), XtWindow(shell), &hints);
    }

    /* If catalog was imported (modified flag set), clean up layout */
    if (catalog->modified) {
        Folder* folder = catalog->currentFolder;
        if (folder) {
            calculateCellWidth(catalog);
            int cellWidth = catalog->cellWidth;
            int maxCols = (400 - 20) / cellWidth;
            if (maxCols < 1) maxCols = 1;
            
            int col = 0, row = 0;
            for (int i = 0; i < folder->nItems; i++) {
                Item* item = folder->items[i];
                int cellX = 20 + col * cellWidth;
                item->x = (short)(cellX + (cellWidth - item->w) / 2);
                item->y = (short)(20 + row * CATALOG_GRID_Y);
                item->nx = (short)cellX;
                item->ny = (short)(item->y + item->h + 4);
                
                col++;
                if (col >= maxCols) {
                    col = 0;
                    row++;
                }
            }
        }
    }

    /* Size canvas to fit content */
    updateCanvasSize(catalog);

    XtPopup(shell, XtGrabNone);
}

void showCatalogCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    DocViewInfo* dvi = (DocViewInfo*)cd->shellInfo;

    /* If catalog already open, just raise it */
    if (theCatalog && theCatalog->shell) {
        XRaiseWindow(XtDisplay(theCatalog->shell), XtWindow(theCatalog->shell));
        return;
    }

    showCatalog(DEFAULT_CATALOG_FILE, dvi);
}

/*
 * Internal function to close catalog window and clean up.
 */
static void closeCatalogWindow(Catalog* catalog) {
    if (!catalog) return;

    /* Save if modified */
    if (catalog->modified) {
        writeCatalog(catalog, catalog->catalogFileName);
    }

    /* Clean up */
    if (catalog->topFolder) {
        forceDeleteFolder(catalog->topFolder, catalog);
    }
    if (catalog->catalogFileName) {
        free(catalog->catalogFileName);
    }
    if (catalog->gc) {
        XFreeGC(XtDisplay(catalog->shell), catalog->gc);
    }
    if (catalog->xorGC) {
        XFreeGC(XtDisplay(catalog->shell), catalog->xorGC);
    }

    XtDestroyWidget(catalog->shell);

    if (theCatalog == catalog) {
        theCatalog = NULL;
    }

    /* Reset icons flag so they get recreated on next open */
    iconsInitialized = 0;

    free(catalog);
}

/*
 * Event handler for WM_DELETE_WINDOW protocol message.
 * Called when user clicks the window close button (X).
 */
static void catalogDeleteWindowEH(Widget w, XtPointer clientData, XEvent* event, Boolean* cont) {
    if (event->type == ClientMessage) {
        XClientMessageEvent* cm = (XClientMessageEvent*)event;
        Atom wm_delete_window = XInternAtom(XtDisplay(w), "WM_DELETE_WINDOW", False);
        
        if (cm->message_type == XInternAtom(XtDisplay(w), "WM_PROTOCOLS", False) &&
            (Atom)cm->data.l[0] == wm_delete_window) {
            /* User clicked the window close button */
            Catalog* catalog = (Catalog*)clientData;
            closeCatalogWindow(catalog);
            *cont = False; /* Don't continue processing */
        }
    }
}

void closeCatalogCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    Catalog* catalog = (Catalog*)cd->shellInfo;
    closeCatalogWindow(catalog);
}

/* Callback for browser menu "Add to Catalog" */
void addToCatalogCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    DocViewInfo* dvi = (DocViewInfo*)cd->shellInfo;

    /* Open catalog if not already open */
    if (!theCatalog) {
        showCatalog(DEFAULT_CATALOG_FILE, dvi);
    }

    /* Add current page */
    if (theCatalog) {
        addCurrentPageToCatalog(theCatalog, dvi);
        redrawCatalog(theCatalog);
    }
}
