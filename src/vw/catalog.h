/*
 * catalog.h
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

#ifndef _CATALOG_H_
#define _CATALOG_H_

#include "menu.h"
#include "vw.h"

#define MAX_SELECTIONS 100
#define ITEM_ALLOC_CHUNK 32

/* Catalog file in user's home directory */
#define DEFAULT_CATALOG_FILE "~/.viola-catalog"

/* Grid spacing for icon layout */
#define CATALOG_GRID_X 100  /* Fixed cell width: MAX_LABEL_WIDTH(80) + padding(20) */
#define CATALOG_GRID_Y 90   /* Height for icon(32) + 3 lines of text + spacing */
#define CATALOG_ICON_SIZE 32

/* Double-click timeout in milliseconds */
#define DOUBLE_CLICK_TIME 300

/* Drag threshold in pixels */
#define DRAG_THRESHOLD 5

enum itemTypes { ITEM, FOLDER, LINK };
enum itemStates { NONE = 0, SELECTED };

typedef struct itemStruct {
    char type;
    char state;

    Pixmap icon;
    GC gc;
    char* iconFile;
    short x, y, w, h;

    char* name;
    XmString nameXMS;
    short nx, ny;

    char* commentURL;
} Item;

typedef struct folderStruct {
    char type;
    char state;

    Pixmap icon;
    GC gc;
    char* iconFile;
    short x, y, w, h;

    char* name;
    XmString nameXMS;
    short nx, ny;

    char* commentURL;
    Item** items;
    int nItems;
    int allocedItems;
    short cw, ch; /* size of folder canvas area (when open) */

    XmString nItemsXMS;
    short numx, numy;

    struct folderStruct* parent;  /* parent folder for navigation */
} Folder;

typedef struct linkStruct {
    char type;
    char state;

    Pixmap icon;
    GC gc;
    char* iconFile;
    short x, y, w, h;

    char* name;
    XmString nameXMS;
    short nx, ny;

    char* commentURL;
    char* url;
    char* comment;
    char* folderName;
    Folder* folder;
} Link;

/* Mouse interaction states */
enum dragStates { DRAG_NONE = 0, DRAG_PENDING, DRAG_ACTIVE, DRAG_SELECT_RECT };

typedef struct catalogStruct {
    Folder* topFolder;
    Folder* currentFolder;
    char* catalogFileName;

    char visible;
    char modified;  /* needs saving */

    GC gc;
    GC xorGC;       /* for rubber-band drawing */
    Widget shell;
    Widget canvas;
    Widget helpLabel;
    Widget folderNameText;
    Widget catalogTitleText;
    DocViewInfo* dvi;

    /* Selection tracking */
    Item* selectedItems[MAX_SELECTIONS];
    int nSelected;

    /* Mouse/drag state */
    char dragState;
    short dragStartX, dragStartY;
    short dragLastX, dragLastY;
    Time lastClickTime;
    Item* lastClickedItem;

    /* Selection rectangle */
    short selectRectX, selectRectY, selectRectW, selectRectH;
    
    /* Grid layout */
    short cellWidth;  /* calculated based on text width */
} Catalog;

typedef union ItemStruct {
    Item item;
    Link link;
    Folder folder;
} CatalogItem;

/* PROTOTYPES */
void showCatalogCB(Widget widget, XtPointer clientData, XtPointer callData);
void closeCatalogCB(Widget widget, XtPointer clientData, XtPointer callData);

/* Initialization and I/O */
int initCatalog(Widget shell, Catalog* catalog);
int readCatalog(Catalog* catalog, const char* filename);
int writeCatalog(Catalog* catalog, const char* filename);

/* Item operations */
Link* createNewLink(Catalog* catalog, const char* url, const char* name, const char* comment);
Folder* createNewFolder(Catalog* catalog, const char* name);
void openLink(Link* link, Catalog* catalog);
void openFolder(Folder* folder, Catalog* catalog);
void deleteSelectedItems(Catalog* catalog);

/* Selection */
void selectItem(Catalog* catalog, Item* item, int addToSelection);
void deselectAll(Catalog* catalog);
Item* findItemAt(Catalog* catalog, int x, int y);

/* Menu actions */
void cleanupFolder(Widget widget, XtPointer clientData, XtPointer callData);
void alphabetizeFolder(Widget widget, XtPointer clientData, XtPointer callData);

/* Drawing */
void redrawCatalog(Catalog* catalog);

/* Add current page from browser */
void addCurrentPageToCatalog(Catalog* catalog, DocViewInfo* dvi);

/* Callback for browser menu */
void addToCatalogCB(Widget widget, XtPointer clientData, XtPointer callData);

#endif /* _CATALOG_H_ */
