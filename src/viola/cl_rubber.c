/*XXXX No classScript specified, thus pcode may be incorrectly generated */
/*
 * Copyright 1990 Pei-Yuan Wei.	All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */
/*
 * class	: rubber
 * superClass	: field
 */
#include "cl_rubber.h"
#include "class.h"
#include "classlist.h"
#include "error.h"
#include "glib.h"
#include "hash.h"
#include "ident.h"
#include "membership.h"
#include "misc.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "scanutils.h"
#include "slotaccess.h"
#include "utils.h"
#include <ctype.h>

SlotInfo cl_rubber_NCSlots[] = {{0}};
SlotInfo cl_rubber_NPSlots[] = {{0}};
SlotInfo cl_rubber_CSlots[] = {{STR_class, PTRS | SLOT_RW, (long)"rubber"}, {{0}}};
SlotInfo cl_rubber_PSlots[] = {{STR__classInfo, CLSI, (long)&class_rubber}, {{0}}};

SlotInfo* slots_rubber[] = {(SlotInfo*)cl_rubber_NCSlots, (SlotInfo*)cl_rubber_NPSlots,
                            (SlotInfo*)cl_rubber_CSlots, (SlotInfo*)cl_rubber_PSlots};

MethodInfo meths_rubber[] = {
    /* local methods */
    {STR_config, meth_rubber_config},
    {STR_initialize, meth_rubber_initialize},
    {STR_render, meth_rubber_render},
    {{0}}};

ClassInfo class_rubber = {
    helper_field_get, helper_field_set, slots_rubber, /* class slot information	*/
    meths_rubber,                                     /* class methods		*/
    STR_rubber,                                       /* class identifier number	*/
    &class_field,                                     /* super class info		*/
};

void helper_rubber_config(VObj* self, int oldWidth, int oldHeight) {
    float xratio, yratio;
    int x, y, width, height;
    VObjList *olist, *children = GET__children(self);
    Window w;

    xratio = GET_width(self) / oldWidth;
    yratio = GET_height(self) / oldHeight;

    for (olist = children; olist; olist = olist->next) {
        x = xratio * (float)GET_x(olist->o);
        y = yratio * (float)GET_y(olist->o);
        width = xratio * (float)GET_width(olist->o);
        height = yratio * (float)GET_height(olist->o);
        if (GET_window(self) && GET_visible(self))
            GLUpdateGeometry(0, GET_window(olist->o), x, y, width, height);
    }
}

long meth_rubber_config(VObj* self, Packet* result, int argc, Packet argv[]) {
    int oldWidth, oldHeight;

    oldWidth = GET_width(self);
    oldHeight = GET_height(self);

    if (!meth_field_config(self, result, argc, argv))
        return 0;

    if (GET__children(self))
        helper_rubber_config(self, oldWidth, oldHeight);

    return 1;
}

long meth_rubber_initialize(VObj* self, Packet* result, int argc, Packet argv[]) {
    return meth_field_initialize(self, result, argc, argv);
}

long meth_rubber_render(VObj* self, Packet* result, int argc, Packet argv[]) {
    Window w = GET_window(self);

    if (!w)
        if (!(w = GLOpenWindow(self, GET_x(self), GET_y(self), GET_width(self), GET_height(self),
                               0)))
            return 0;
    GLDrawBorder(w, 0, 0, GET_width(self), GET_height(self), GET_border(self), 1);
    return 1;
}
