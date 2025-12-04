/*
 * history.c
 *
 * Routines and data structures for handling document traversal history.
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

#include <stdio.h>
#include <stdlib.h>

#include <Xm/DialogS.h>
#include <Xm/Form.h>
#include <Xm/Label.h>
#include <Xm/List.h>
#include <Xm/MessageB.h>
#include <Xm/PushB.h>
#include <Xm/ScrolledW.h>
#include <Xm/Xm.h>

#include "../viola/cexec.h"
#include "callbacks.h"
#include "cursor.h"
#include "history.h"
#include "vw.h"

void printHistoryList(DocViewInfo* dvi) {
    int i;

    fprintf(stderr, "\nHistory List (%d items, %d = current):\n", dvi->nHistoryItems,
            dvi->currentHistoryItem);

    for (i = 0; i < dvi->nHistoryItems; i++)
        fprintf(stderr, "%s\n", dvi->historyList[i]);
    fprintf(stderr, "\n");
}

void historyPrev(DocViewInfo* dvi) {
    dvi->currentHistoryItem--;
    if (dvi->historyListWidget) {
        XmListDeselectAllItems(dvi->historyListWidget);
        XmListSelectPos(dvi->historyListWidget, dvi->currentHistoryItem + 1, FALSE);
    }
}

void historyNext(DocViewInfo* dvi) {
    dvi->currentHistoryItem++;
    if (dvi->historyListWidget) {
        XmListDeselectAllItems(dvi->historyListWidget);
        XmListSelectPos(dvi->historyListWidget, dvi->currentHistoryItem + 1, FALSE);
    }
}

void historyBackUp(DocViewInfo* dvi) {
    int end, i;

    if (dvi->currentHistoryItem == 0) {
        XBell(XtDisplay(dvi->shell), 50);
        return;
    }

    if (dvi->historyListWidget)
        XmListDeletePos(dvi->historyListWidget, dvi->nHistoryItems);

    dvi->nHistoryItems--;
    free(dvi->historyList[dvi->nHistoryItems]);

    if (dvi->currentHistoryItem > dvi->nHistoryItems - 1)
        dvi->currentHistoryItem = dvi->nHistoryItems - 1;

    if (dvi->historyListWidget) {
        XmListDeselectAllItems(dvi->historyListWidget);
        XmListSelectPos(dvi->historyListWidget, dvi->currentHistoryItem + 1, FALSE);
    }
    /*printHistoryList(dvi);*/
}

void historyAdd(DocViewInfo* dvi, char* newItem) {
    int i, nitems;
    char** tmpList;
    XmString itemXMS;

    nitems = dvi->nHistoryItems;
    tmpList = dvi->historyList;

    if (dvi->nHistoryItems == dvi->historySize)
        growHistoryList(dvi);

    dvi->historyList[dvi->nHistoryItems] = makeString(newItem);
    dvi->nHistoryItems++;
    dvi->currentHistoryItem = dvi->nHistoryItems - 1;

    if (dvi->historyListWidget) {
        itemXMS = XmStringCreateSimple(newItem);
        XmListAddItem(dvi->historyListWidget, itemXMS, 0);
        XmStringFree(itemXMS);

        XmListDeselectAllItems(dvi->historyListWidget);
        XmListSelectPos(dvi->historyListWidget, dvi->currentHistoryItem + 1, FALSE);
    }
}

void historySelect(DocViewInfo* dvi, char* url) {
    /*printHistoryList(dvi);*/
    /*
        int i, nitems=dvi->nHistoryItems;

        for (i=nitems-1; i>=0; i--)
            if (!strcmp(url, dvi->historyList[i])) {
                dvi->currentHistoryItem = i;
                if (dvi->historyListWidget) {
                    XmListDeselectAllItems(dvi->historyListWidget);
                    XmListSelectPos(dvi->historyListWidget, i+1, FALSE);
                }
                break;
            }
    */
}

int isURLInHistory(DocViewInfo* dvi, char* url) {
    int i;
    size_t urlLen, histLen;
    
    if (!dvi || !url || !dvi->historyList)
        return 0;
    
    urlLen = strlen(url);
    
    for (i = 0; i < dvi->nHistoryItems; i++) {
        if (!dvi->historyList[i])
            continue;
            
        /* Exact match */
        if (!strcmp(url, dvi->historyList[i])) {
            return 1;
        }
        
        /* For relative URLs, check if history entry ends with the URL */
        /* e.g. url="page.html" matches "file://host/path/page.html" */
        histLen = strlen(dvi->historyList[i]);
        if (histLen > urlLen) {
            char* suffix = dvi->historyList[i] + histLen - urlLen;
            /* Check that URL matches the end and is preceded by '/' */
            if (!strcmp(url, suffix) && *(suffix - 1) == '/') {
                return 1;
            }
        }
    }
    return 0;
}

void setHistoryList(DocViewInfo* dvi, char* newList[], int numItems) {
    int i;
    XmStringTable listItems = NULL;

    if (!newList || !numItems)
        return;

    /*
     * Allocate the new items in the history list.
     */
    freeHistoryList(dvi);
    dvi->historySize = (numItems + HISTORY_CHUNK);
    dvi->historyList = (char**)malloc((size_t)dvi->historySize * sizeof(char*));
    for (i = 0; i < numItems; i++)
        dvi->historyList[i] = makeString(newList[i]);
    dvi->nHistoryItems = numItems;

    /*
     * Set the items in the history list widget.
     */
    if (dvi->historyListWidget) {
        listItems = (XmStringTable)malloc((size_t)numItems * sizeof(XmString));
        for (i = 0; i < numItems; i++)
            listItems[i] = XmStringCreateSimple(newList[i]);
        XtVaSetValues(dvi->historyListWidget, XmNitemCount, numItems, XmNitems, listItems, NULL);
        free(listItems);
    }
}

void freeHistoryList(DocViewInfo* dvi) {
    int i;

    for (i = 0; i < dvi->nHistoryItems; i++)
        free(dvi->historyList[i]);
    if (dvi->historyList)
        free(dvi->historyList);

    dvi->historyList = (char**)NULL;
    dvi->nHistoryItems = 0;
    dvi->historySize = 0;
}

void growHistoryList(DocViewInfo* dvi) {
    int i;
    char** newList = (char**)malloc((size_t)(dvi->historySize + HISTORY_CHUNK) * sizeof(char*));
    dvi->historySize += HISTORY_CHUNK;

    for (i = 0; i < dvi->nHistoryItems; i++)
        newList[i] = dvi->historyList[i];

    free(dvi->historyList);
    dvi->historyList = newList;
}

Widget createHistoryDialog(DocViewInfo* dvi) {
    Widget dlog, form, list, doneButton, label1, label2, labelForm;
    Arg args[16];
    int n = 0, i;
    XmString labelXMS;
    XmStringTable xmsList;

    XtSetArg(args[n], XmNborderWidth, 2);
    n++;
    XtSetArg(args[n], XmNhorizontalSpacing, 4);
    n++;
    XtSetArg(args[n], XmNverticalSpacing, 4);
    n++;
    XtSetArg(args[n], XmNautoUnmanage, FALSE);
    n++;

    form = XmCreateFormDialog(dvi->shell, "historyDialog", args, (Cardinal)n);
    XtVaSetValues(form, XmNhorizontalSpacing, 6, XmNverticalSpacing, 6, NULL);
    
    /* Set window title for the dialog shell */
    XtVaSetValues(XtParent(form), XmNtitle, "History Manager", NULL);

    labelForm = XtVaCreateManagedWidget(
        "labelForm", xmFormWidgetClass, form, XmNhorizontalSpacing, 4, XmNverticalSpacing, 4,
        XmNshadowThickness, 2, XmNshadowType, XmSHADOW_ETCHED_IN, XmNtopAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_FORM, XmNrightAttachment, XmATTACH_FORM, NULL);

    labelXMS = XmStringCreateLtoR("History Manager", "largeFont");
    label1 = XtVaCreateManagedWidget("History Manager", xmLabelWidgetClass, labelForm, XmNalignment,
                                     XmALIGNMENT_BEGINNING, XmNtopAttachment, XmATTACH_FORM,
                                     XmNleftAttachment, XmATTACH_FORM, XmNrightAttachment,
                                     XmATTACH_FORM, XmNlabelString, labelXMS, NULL);
    XmStringFree(labelXMS);

    labelXMS = XmStringCreateLtoR("Below is a list of documents you have previously viewed.\nClick "
                                  "on a document name to reload that document.",
                                  "plainFont");
    label2 = XtVaCreateManagedWidget(
        "historyInstructions", xmLabelWidgetClass, labelForm, XmNalignment, XmALIGNMENT_BEGINNING,
        XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, label1, XmNbottomAttachment, XmATTACH_FORM,
        XmNleftAttachment, XmATTACH_FORM, XmNrightAttachment, XmATTACH_FORM, XmNlabelString,
        labelXMS, NULL);
    XmStringFree(labelXMS);

    doneButton = XtVaCreateManagedWidget("Hide", xmPushButtonWidgetClass, form, XmNleftAttachment,
                                         XmATTACH_FORM, XmNrightAttachment, XmATTACH_FORM,
                                         XmNbottomAttachment, XmATTACH_FORM, XmNleftOffset, 4,
                                         XmNrightOffset, 4, XmNbottomOffset, 4, NULL);
    XtAddCallback(doneButton, XmNactivateCallback, hideHistory, (XtPointer)dvi);

    n = 0;
    if (dvi->nHistoryItems) {
        xmsList = (XmStringTable)malloc((size_t)dvi->nHistoryItems * sizeof(XmString));
        for (i = 0; i < dvi->nHistoryItems; i++)
            xmsList[i] = XmStringCreateSimple(dvi->historyList[i]);
        XtSetArg(args[n], XmNitems, xmsList);
        n++;
        XtSetArg(args[n], XmNitemCount, dvi->nHistoryItems);
        n++;
    }
    XtSetArg(args[n], XmNtopAttachment, XmATTACH_WIDGET);
    n++;
    XtSetArg(args[n], XmNtopWidget, labelForm);
    n++;
    XtSetArg(args[n], XmNleftAttachment, XmATTACH_FORM);
    n++;
    XtSetArg(args[n], XmNrightAttachment, XmATTACH_FORM);
    n++;
    XtSetArg(args[n], XmNbottomAttachment, XmATTACH_WIDGET);
    n++;
    XtSetArg(args[n], XmNbottomWidget, doneButton);
    n++;
    XtSetArg(args[n], XmNtopOffset, 4);
    n++;
    XtSetArg(args[n], XmNleftOffset, 4);
    n++;
    XtSetArg(args[n], XmNrightOffset, 4);
    n++;
    XtSetArg(args[n], XmNselectionPolicy, XmBROWSE_SELECT);
    n++;
    XtSetArg(args[n], XmNheight, 100);
    n++;
    XtSetArg(args[n], XmNwidth, 550);
    n++;
    XtSetArg(args[n], XmNlistSizePolicy, XmCONSTANT);
    n++;
    dvi->historyListWidget = list = XmCreateScrolledList(form, "historyList", args, (Cardinal)n);
    XtAddCallback(list, XmNsingleSelectionCallback, historySelectCB, (XtPointer)dvi);
    XtAddCallback(list, XmNdefaultActionCallback, historySelectCB, (XtPointer)dvi);
    XtManageChild(list);

    XtManageChild(form);

    if (dvi->nHistoryItems)
        XmListSelectPos(dvi->historyListWidget, dvi->currentHistoryItem + 1, FALSE);

    return (XtParent(form));
}

void historySelectCB(Widget list, XtPointer clientData, XtPointer callData) {
    DocViewInfo* dvi = (DocViewInfo*)clientData;
    XmListCallbackStruct* cbs = (XmListCallbackStruct*)callData;

    dvi->currentHistoryItem = cbs->item_position - 1;

    if (dvi->violaDocViewObj) {
        setBusyCursor(dvi);
        sendMessage1N1str(dvi->violaDocViewObj, "showHistoryDoc",
                          dvi->historyList[cbs->item_position - 1]);
        sendMessage1N1int(dvi->violaDocViewObj, "historyList_selectedItem", cbs->item_position - 1);
        setIdleCursor(dvi);
    }
}

void showHistoryCB(Widget widget, XtPointer clientData, XtPointer callData) {
    ClientData* cd = (ClientData*)clientData;
    DocViewInfo* dvi = (DocViewInfo*)cd->shellInfo;

    if (!dvi->historyDlog)
        dvi->historyDlog = createHistoryDialog(dvi);
    else
        XtPopup(dvi->historyDlog, XtGrabNone);
}

void showHistory(DocViewInfo* dvi) {
    if (!dvi->historyDlog)
        dvi->historyDlog = createHistoryDialog(dvi);
    else
        XtPopup(dvi->historyDlog, XtGrabNone);
}

void hideHistory(Widget button, XtPointer clientData, XtPointer callData) {
    DocViewInfo* dvi = (DocViewInfo*)clientData;

    XtPopdown(dvi->historyDlog);
}

void historyBackUpMH(char* arg[], int argc, void* clientData) {
    DocViewInfo* dvip = (DocViewInfo*)clientData;
    historyBackUp(dvip);
}

void historyPrevMH(char* arg[], int argc, void* clientData) {
    DocViewInfo* dvip = (DocViewInfo*)clientData;
    historyPrev(dvip);
}

void historyNextMH(char* arg[], int argc, void* clientData) {
    DocViewInfo* dvip = (DocViewInfo*)clientData;
    historyNext(dvip);
}

void historyAddMH(char* arg[], int argc, void* clientData) {
    DocViewInfo* dvip = (DocViewInfo*)clientData;

    if (argc < 3)
        return;

    if (dvip->cloneID != atol(arg[1]))
        return;

    historyAdd(dvip, arg[2]);
}

/*
 * arg[0] = "historyList"
 * arg[1] = cloneID
 * arg[2] - arg[argc-1] = list items
 */
void setHistoryListMH(char* arg[], int argc, void* clientData) {
    DocViewInfo* dvip = (DocViewInfo*)clientData;

    if (argc < 3)
        return;

    if (dvip->cloneID != atol(arg[1]))
        return;

    setHistoryList(dvip, (char**)&arg[2], argc - 2);
}
