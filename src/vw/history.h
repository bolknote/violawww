/*
 * history.h
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

#ifndef _HISTORY_H_
#define _HISTORY_H_

/* CONSTANTS */
#define HISTORY_CHUNK 256

/* PROTOTYPES */
void historyPrev(DocViewInfo* dvi);
void historyNext(DocViewInfo* dvi);
void historyBackUp(DocViewInfo* dvi);

void historyPrevMH(char* arg[], int argc, void* clientData);
void historyNextMH(char* arg[], int argc, void* clientData);
void historyBackUpMH(char* arg[], int argc, void* clientData);

void historyAdd(DocViewInfo* dvi, char* newItem);
void historyAddMH(char* arg[], int argc, void* clientData);
void setHistoryList(DocViewInfo* dvi, char* newList[], int numItems);
void setHistoryListMH(char* arg[], int argc, void* clientData);

void freeHistoryList(DocViewInfo* dvi);
void growHistoryList(DocViewInfo* dvi);

Widget createHistoryDialog(DocViewInfo* dvi);
void showHistory(DocViewInfo* dvi);
void showHistoryCB(Widget widget, XtPointer clientData, XtPointer callData);
void hideHistory(Widget button, XtPointer clientData, XtPointer callData);
void historySelect(DocViewInfo* dvi, char* url);
void historySelectCB(Widget list, XtPointer clientData, XtPointer callData);
int isURLInHistory(DocViewInfo* dvi, char* url);

#endif /* _HISTORY_H_ */
