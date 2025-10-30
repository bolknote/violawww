/*
 * selection.h
 *
 * Code for getting the selection and for handling selection requests.
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

#ifndef _SELECTION_H_
#define _SELECTION_H_

#include <Xm/Xm.h>
#include "vw.h"

extern DocViewInfo* selectionOwner;

void getTheSelection(void);
void urlSelectionRequest(void);
void urlSelectionClear(void);

/* Routines that use Toolkit selection mechanism: */
Boolean urlDoSelectionRequest(Widget widget, Atom* selection, Atom* target, Atom* type_return, XtPointer* value_return, unsigned long* length_return, int* format_return);
void urlLoseSelection(Widget widget, Atom* selection);
void urlFinishSelection(Widget widget, Atom* selection, Atom* target);
void urlToggleSelection(Widget widget, DocViewInfo* dvi);
void urlGetSelection(Widget widget, DocViewInfo* dvi);
void urlGiveUpSelection(Widget widget);

#endif // _SELECTION_H_
