/*
 * callbacks.h
 *
 * Prototype for button and menu callbacks.
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

#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

#include "vw.h"

void genericCallback(Widget thing, XtPointer clientData, XtPointer callData);
void okCallback(Widget button, XtPointer clientData, XtPointer callData);
void quitCallback(Widget widget, XtPointer client, XtPointer call);
void quitOk(Widget widget, XtPointer clientData, XtPointer call);
void openDocument(Widget widget, XtPointer clientD, XtPointer callData);
void searchCallback(Widget textField, XtPointer clientData, XtPointer callData);
void vwSaveAsCB(Widget button, XtPointer clientData, XtPointer callData);
void saveAsMH(char* arg[], int argc, void* clientData);
void printFile(Widget widget, XtPointer clientData, XtPointer callData);
void reloadDoc(DocViewInfo* dvi);
void reloadDocCB(Widget widget, XtPointer clientData, XtPointer callData);
void oneMessageCB(Widget widget, XtPointer clientData, XtPointer callData);

void clonePage(DocViewInfo* parentDocViewInfo); /* clone page for navigation */
void clonePageMH(char* arg[], int argc, void* clientData);
void clonePageCB(Widget widget, XtPointer clientData, XtPointer callData);
void pageCloneMapped(Widget canvas, XtPointer clientData, XEvent* event, Boolean* continueDispatch);
void showPageClone(char* arg[], int argc, void* clientData);
void closePageCB(Widget button, XtPointer clientData, XtPointer callData);
void closePageShell(DocViewInfo* dvi);
void cloneApp(Widget widget, XtPointer clientData, XtPointer callData); /* clone app */
void appCloneMapped(Widget canvas, XtPointer clientData, XEvent* event, Boolean* continueDispatch);
void showAppClone(char* arg[], int argc, void* clientData);
void closeThisShell(Widget button, XtPointer clientData, XtPointer callData);

void flipGlobe(XtPointer clientData, XtIntervalId* intervalID);
void showHelpMessage(Widget widget, char* message);
void showHelpMessageInMainWindow(char* message);
void helpHandler(Widget widget, XtPointer clientData, XEvent* event, Boolean* cont);
void blankHelpHandler(Widget widget, XtPointer clientData, XEvent* event, Boolean* cont);
void blankHelpMessageInMainWindow(void);

void navigateBackUp(Widget widget, XtPointer clientData, XtPointer callData);
void navigateNext(Widget widget, XtPointer clientData, XtPointer callData);
void navigatePrev(Widget widget, XtPointer clientData, XtPointer callData);
void navigateHome(Widget widget, XtPointer clientData, XtPointer callData);
void navigateHomeEH(Widget widget, XtPointer clientData, XEvent* event, Boolean* cont);

void changeFonts(Widget widget, XtPointer clientData, XtPointer callData);

void oneWordMessageCB(Widget widget, XtPointer clientData, XtPointer callData);

void titleButtonEH(Widget w, XtPointer clientData, XEvent* evt, Boolean* cont);
void editorTitleButtonEH(Widget w, XtPointer clientData, XEvent* evt, Boolean* cont);

void newDocument(char* arg[], int argc, void* clientData);
void searchModeMH(char* arg[], int argc, void* clientData);
void sliderConfig(char* arg[], int argc, void* clientData);

void doViolaEvent(Widget widget, XtPointer clientData, XEvent* event, Boolean* continueDispatch);
Boolean doViolaIdle(XtPointer clientData);
void resizeViola(Widget widget, XtPointer clientData, XEvent* event, Boolean* continueDispatch);

void scrollBarValueChanged(Widget sbar, XtPointer clientData, XtPointer callData);
void mouseWheelScrollEH(Widget w, XtPointer clientData, XEvent* evt, Boolean* cont);
void scrollBarDrag(Widget sbar, XtPointer clientData, XtPointer callData);

void printTest(void);

#endif /* _CALLBACKS_H_ */
