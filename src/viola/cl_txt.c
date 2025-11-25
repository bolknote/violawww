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
 * class	: txt
 * superClass	: pane
 */
#include "cl_txt.h"
#include "attr.h"
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
#include "vlist.h"
#include <ctype.h>
#include <string.h>

SlotInfo cl_txt_NCSlots[] = {0};
SlotInfo cl_txt_NPSlots[] = {{STR_font, /* font identifier */
                              PTRS | SLOT_RW, (long)"fixed"},
                             {STR__font, /* (internal) font id */
                              LONG, 0},
                             {0}};
SlotInfo cl_txt_CSlots[] = {{STR_class, PTRS | SLOT_RW, (long)"txt"},
                            {
                                STR_classScript,
                                PTRS,
                                (long)"\n\
		switch (arg[0]) {\n\
		case \"config\":\n\
			config(arg[1], arg[2], arg[3], arg[4]);\n\
		break;\n\
		case \"render\":\n\
			render();\n\
		break;\n\
		case \"configSelf\":\n\
	        	send(self(), \"config\", \n\
				x(), y(), width(), height());\n\
		break;\n\
		case \"visible\":\n\
			set(\"visible\", arg[1]);\n\
		break;\n\
		case \"expose\":\n\
		case \"mouseMove\":\n\
		case \"enter\":\n\
		case \"leave\":\n\
		case \"buttonPress\":\n\
		case \"buttonRelease\":\n\
		case \"keyPress\":\n\
		case \"keyRelease\":\n\
		case \"shownPositionH\":\n\
		case \"shownPositionV\":\n\
		break;\n\
		case \"freeSelf\":\n\
			freeSelf();\n\
		break;\n\
		case \"init\":\n\
			initialize();\n\
		break;\n\
		case \"info\":\n\
			info();\n\
		break;\n\
		default:\n\
			print(\"unknown message, clsss = \", get(\"class\"),\n\
				\": self = \", get(\"name\"), \" args: \");\n\
			for (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\
			print(\"\n\");\n\
		break;\n\
		}\n\
	",
                            },
                            {0}};
SlotInfo cl_txt_PSlots[] = {{STR__classInfo, CLSI, (long)&class_txt}, {0}};

SlotInfo* slots_txt[] = {(SlotInfo*)cl_txt_NCSlots, (SlotInfo*)cl_txt_NPSlots,
                         (SlotInfo*)cl_txt_CSlots, (SlotInfo*)cl_txt_PSlots};

MethodInfo meths_txt[] = {
    /* local methods */
    {STR_clone, meth_txt_clone},
    {STR_clone2, meth_txt_clone2},
    {STR_config, meth_txt_config},
    {STR_expose, meth_txt_expose},
    {
        STR_freeSelf,
        meth_txt_freeSelf,
    },
    {
        STR_geta,
        meth_txt_get,
    },
    {STR_initialize, meth_txt_initialize},
    {STR_render, meth_txt_render},
    {STR_seta, meth_txt_set},
    {0}};

ClassInfo class_txt = {
    helper_txt_get, helper_txt_set, slots_txt, /* class slot information	*/
    meths_txt,                                 /* class methods		*/
    STR_txt,                                   /* class identifier number	*/
    &class_pane,                               /* super class info		*/
};

/*
 * clone(clone name suffix)
 *
 * Make a clone self
 *
 * Result: clone object, and optinally name it
 * Return: 1 if successful, 0 if error occured
 */
long meth_txt_clone(VObj* self, Packet* result, int argc, Packet argv[])
{
    VObj* cloneObj;

    if (!meth_txt_clone2(self, result, argc, argv))
        return 0;
    cloneObj = result->info.o;
    if (cloneObj) {
        sendInitToChildren(cloneObj);
        result->type = PKT_OBJ;
        result->canFree = 0;
        result->info.o = cloneObj;
        return 1;
    }
    result->type = PKT_OBJ;
    result->canFree = 0;
    result->info.o = NULL;
    return 0;
}

long meth_txt_clone2(VObj* self, Packet* result, int argc, Packet argv[])
{
    if (!meth_pane_clone2(self, result, argc, argv))
        return 0;
    return 1;
}

long meth_txt_config(VObj* self, Packet* result, int argc, Packet argv[])
{
    /* set colors because configuring textfield might trigger redraws */
    GLPrepareObjColor(self);

    return meth_pane_config(self, result, argc, argv);
}

long meth_txt_expose(VObj* self, Packet* result, int argc, Packet argv[])
{
    return meth_pane_expose(self, result, argc, argv);
}

long meth_txt_freeSelf(VObj* self, Packet* result, int argc, Packet argv[])
{
    if (!exitingViola) {
        if (GET_font(self)) {
            free(GET_font(self));
        }
    }
    meth_field_freeSelf(self, result, argc, argv);
    return 1;
}

long helper_txt_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID)
{
    switch (labelID) {
    case STR_font:
        result->info.s = SaveString(GET_font(self));
        result->canFree = PK_CANFREE_STR;
        result->type = PKT_STR;
        return 1;

    case STR__font:
        result->info.i = GET__font(self);
        result->canFree = 0;
        result->type = PKT_INT;
        return 1;
    }
    return helper_pane_get(self, result, argc, argv, labelID);
}
long meth_txt_get(VObj* self, Packet* result, int argc, Packet argv[])
{
    return helper_txt_get(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

long meth_txt_initialize(VObj* self, Packet* result, int argc, Packet argv[])
{
    char* cp;
    int i;
    extern int numberOfFontIDs;

    if (!meth_pane_initialize(self, result, argc, argv))
        return 0;
    if (!VFontResourceObj) {
        return 0;
    }
    /*	if (getVariable(GET__varList(VFontResourceObj), GET_font(self), &cp)) {
     */
    if ((cp = GET_font(self))) {
        for (i = 0; i <= numberOfFontIDs; i++) {
            /*XXX gotta hash/tokenize this... */
            if (!strcmp(FontRef(i), cp)) {
                SET__font(self, i);
                return 1;
            }
        }
    }
    return 1; /* don't want to kill this object on account of bad font */
}

long meth_txt_render(VObj* self, Packet* result, int argc, Packet argv[])
{
    return meth_pane_render(self, result, argc, argv);
}

/*
 * returns non-zero if set operation succeded, zero otherwise.
 */
long helper_txt_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID)
{
    char* cp;
    int i;

    switch (labelID) {
    case STR_font:
        cp = PkInfo2Str(&argv[1]);
        for (i = 0; i <= numberOfFontIDs; i++) {
            /*XXX gotta hash/tokenize this... */
            if (!strcmp(FontRef(i), cp)) {
                SET__font(self, i);
                result->info.s = saveString(cp);
                SET_font(self, result->info.s);
                result->canFree = 0;
                result->type = PKT_STR;
                return 1;
            }
        }
        return 0;

    case STR__font:
        result->info.i = PkInfo2Int(&argv[1]);
        SET__font(self, result->info.i);
        result->canFree = 0;
        result->type = PKT_INT;
        return 1;
    }
    return helper_pane_set(self, result, argc, argv, labelID);
}
long meth_txt_set(VObj* self, Packet* result, int argc, Packet argv[])
{
    return helper_txt_set(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}
