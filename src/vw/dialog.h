/*
 * dialog.h
 *
 * Error and warning dialogs.
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

#ifndef _DIALOG_H_
#define _DIALOG_H_

#include "vw.h"

enum dlogType { INFO, WARNING, ERROR };

struct promptStruct {
    int* done;
    char* result;
    char *yesLabel, *noLabel, *cancelLabel;
    DocViewInfo* dvip;
};

struct lentryDlogStruct {
    Widget dlog;
    Widget lineText;
    char* data;
    DocViewInfo* dvi;
    void (*okCB)(struct lentryDlogStruct* lds);
};

#define infoDialog(dvip, msg) messageDialog(dvip, msg, INFO)
#define warningDialog(dvip, msg) messageDialog(dvip, msg, WARNING)
#define errorDialog(dvip, msg) messageDialog(dvip, msg, ERROR)

void messageDialog(DocViewInfo* dvip, char* msg, int type);
void modalErrorDialog(DocViewInfo* dvip, char* msg);
char* promptDialog(DocViewInfo* dvip, char *msg, char *defaultString);
char* questionDialog(DocViewInfo* dvip, char *question, char *defaultChoice, char *yesLabel, char *noLabel, char *cancelLabel);
char* fileSelectionDialog(DocViewInfo* dvi, char *message, char *helpMsg);

void infoDialogMH(char* arg[], int argc, void* clientData);
void warningDialogMH(char* arg[], int argc, void* clientData);
void modalErrorDialogMH(char* arg[], int argc, void* clientData);
void errorDialogMH(char* arg[], int argc, void* clientData);
void promptDialogMH(char* arg[], int argc, void* clientData);
void questionDialogMH(char* arg[], int argc, void* clientData);

void printDialog(DocViewInfo* dvi, char *data);
void openURLDialog(Widget widget, XtPointer clientData, XtPointer callData);
void simpleOpenURLDialog(Widget widget, XtPointer clientData, XtPointer callData);

void openURLInSelectionBuffer(Widget widget, XtPointer clientData, XtPointer callData);

char* openSimpleLineEntryDialog(DocViewInfo* dvi, char* title, char* defaultData, void (*okCB)());

/*
 * Security dialog - modal dialog asking user for permission.
 * Returns 1 if user allows, 0 if user denies.
 */
int securityQuestionDialog(const char* title, const char* message,
                           const char* operation, const char* objectName);

/* 
 * Initialize security dialog callback in viola engine.
 * Call this once during VW initialization.
 */
void initSecurityDialogCallback(void);

#endif /* _DIALOG_H_ */
