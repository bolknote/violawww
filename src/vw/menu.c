/*
 * menu.c
 *
 * Constructs pulldown menus.
 * Copied from O'Reilly's "Motif Programming Manual".
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
#include "menu.h"
#include "callbacks.h"
#include "dialog.h"
#include "history.h"
#include "vw.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>

static KeySym mnemonicToKeySym(char mnemonic)
{
    if (mnemonic == '\0')
        return NoSymbol;

    char buffer[2] = { mnemonic, '\0' };
    KeySym keySym = XStringToKeysym(buffer);

    if (keySym != NoSymbol)
        return keySym;

    if (islower((unsigned char)mnemonic)) {
        buffer[0] = (char)toupper((unsigned char)mnemonic);
        keySym = XStringToKeysym(buffer);
    }

    return keySym;
}

Widget buildPulldownMenu(Widget parent, char* menuTitle, char* menuMnemonic, MenuItem* items, Widget helpLabel, void* shellInfo)
{

    Widget pullDown, cascade, widget;
    int i;
    XmString str;

    pullDown = XmCreatePulldownMenu(parent, menuTitle, NULL, 0);

    str = XmStringCreateSimple(menuTitle);
    KeySym cascadeMnemonic = (menuMnemonic ? mnemonicToKeySym(*menuMnemonic) : NoSymbol);
    if (cascadeMnemonic != NoSymbol) {
        cascade = XtVaCreateManagedWidget(menuTitle, xmCascadeButtonWidgetClass, parent,
                                          XmNsubMenuId, pullDown,
                                          XmNlabelString, str,
                                          XmNmnemonic, cascadeMnemonic,
                                          NULL);
    } else {
        cascade = XtVaCreateManagedWidget(menuTitle, xmCascadeButtonWidgetClass, parent,
                                          XmNsubMenuId, pullDown,
                                          XmNlabelString, str,
                                          NULL);
    }
    XmStringFree(str);

    for (i = 0; items[i].label != NULL; i++) {
        if (items[i].subMenu)
            widget =
                buildPulldownMenu(pullDown, items[i].label, &items[i].mnemonic, items[i].subMenu, helpLabel, shellInfo);
        else
            widget = XtVaCreateManagedWidget(items[i].label, *items[i].class, pullDown, NULL);

        if (!items[i].sensitive)
            XtVaSetValues(widget, XmNsensitive, FALSE, NULL);

        KeySym itemMnemonic = mnemonicToKeySym(items[i].mnemonic);
        if (itemMnemonic != NoSymbol)
            XtVaSetValues(widget, XmNmnemonic, itemMnemonic, NULL);

        if (items[i].accelerator) {
            str = XmStringCreateSimple(items[i].accelText);
            XtVaSetValues(widget, XmNaccelerator, items[i].accelerator, XmNacceleratorText, str,
                          NULL);
            XmStringFree(str);
        }

        if (items[i].callback) {
            /*
             * Note: This is a (small) memory leak for every clone that is
             * created and then destroyed.  These ClientData structures are
             * not freed.
             */
            ClientData* clientData = (ClientData*)malloc(sizeof(ClientData));
            if (!clientData) {
                fprintf(stderr, "Out of memory in buildPulldownMenu()!\n");
                exit(1);
            }
            clientData->data = items[i].clientData;
            clientData->shellInfo = shellInfo;
            XtAddCallback(widget, XmNactivateCallback, items[i].callback, (XtPointer)clientData);
        }

        if (items[i].helpText)
            setHelp(widget, helpLabel, items[i].helpText);
    }
    return cascade;
}

Widget buildMenus(Menu* menus, MenuItem* helpMenuItems, Widget parent, Widget helpLabel, void* shellInfo)
{
    int i;
    Widget menuBar, menu;

    menuBar = XmCreateMenuBar(parent, "menuBar", NULL, 0);

    for (i = 0; menus[i].title != NULL; i++)
        (void)buildPulldownMenu(menuBar, menus[i].title, &menus[i].mnemonic, menus[i].menuItems,
                                helpLabel, shellInfo);

    if (helpMenuItems) {
        char helpMnemonic = 'H';
        menu =
            buildPulldownMenu(menuBar, "Help", &helpMnemonic, helpMenuItems, helpLabel, shellInfo);
        XtVaSetValues(menuBar, XmNmenuHelpWidget, menu, NULL);
    }

    XtManageChild(menuBar);
    return (menuBar);
}
