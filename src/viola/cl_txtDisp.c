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
 * class	: txtDisp
 * superClass	: txt
 */
#include "cl_txtDisp.h"
#include "attr.h"
#include "cexec.h"
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
#include "sys.h"
#include "tfed.h"
#include "tfed_i.h"
#include "utils.h"
#include "vlist.h"
#include <ctype.h>

extern int replaceNodeLine(TFLineNode* to, TFLineNode* from, int freeOldSpaceP, MemoryGroup* mg);
#include "event_x.h"
#include "html2.h"
#include "sgml.h"

SlotInfo cl_txtDisp_NCSlots[] = {0};
SlotInfo cl_txtDisp_NPSlots[] = {{STR_cursor, LONG, 0},
                                 {STR_wrap, LONG | SLOT_RW, 1},
                                 {STR_verbatim, LONG | SLOT_RW, 0},
                                 {STR_format, LONG | SLOT_RW, FORMAT_NONE},
                                 {STR__TFStruct, TFLD, 0},
                                 {0}};
SlotInfo cl_txtDisp_CSlots[] = {{STR_class, PTRS | SLOT_RW, (long)"txtDisp"},
                                {
                                    STR_classScript,
                                    PTRS,
                                    (long)"\n\
		switch (arg[0]) {\n\
		case \"expose\":\n\
			expose(arg[1], arg[2], arg[3], arg[4]);\n\
			return;\n\
		break;\n\
		case \"enter\":\n\
		case \"leave\":\n\
		case \"keyPress\":\n\
		case \"mouseMove\":\n\
		case \"keyRelease\":\n\
		case \"buttonRelease\":\n\
			return;\n\
		break;\n\
		case \"shownPositionV\":\n\
			set(\"shownPositionV\", arg[1]);\n\
			return;\n\
		break;\n\
		case \"buttonPress\":\n\
			processMouseInput();\n\
			return;\n\
		break;\n\
		case \"render\":\n\
			render();\n\
			return;\n\
		break;\n\
		case \"visible\":\n\
			set(\"visible\", arg[1]);\n\
			return;\n\
		break;\n\
		case \"shownPositionH\":\n\
			set(\"shownPositionH\", arg[1]);\n\
			return;\n\
		break;\n\
		case \"scroll\":\n\
			if (arg[1] == \"down\") {\n\
				set(\"shownPositionV\",\n\
					get(\"shownPositionV\") -\n\
					get(\"shownSizeV\"));\n\
			} else if (arg[1] == \"up\") {\n\
				set(\"shownPositionV\",\n\
					get(\"shownPositionV\") +\n\
					get(\"shownSizeV\"));\n\
			}\n\
			return;\n\
		break;\n\
		case \"config\":\n\
			config(arg[1], arg[2], arg[3], arg[4]);\n\
			render();\n\
			return;\n\
		break;\n\
		case \"configSelf\":\n\
			config();\n\
			return;\n\
		break;\n\
		case \"key_up\":\n\
			send(parent(), \"key_up\");\n\
			return;\n\
		break;\n\
		case \"key_down\":\n\
			send(parent(), \"key_down\");\n\
			return;\n\
		break;\n\
		case \"raise\":\n\
			raise();\n\
			return;\n\
		break;\n\
		case \"focus\":\n\
			mousePos = mouse();\n\
			winPos = windowPosition();\n\
			mx = mousePos[0];\n\
			my = mousePos[1];\n\
			dx = ((winPos[0] + width() / 2) - mx) / 10.0;\n\
			dy = ((winPos[1] + height() / 2) - my) / 10.0;\n\
			for (i = 0; i < 10; i++) {\n\
				mx += dx;\n\
				my += dy;\n\
				setMouse(mx, my);\n\
			}\n\
			return;\n\
		break;\n\
		case \"info\":\n\
			info();\n\
			return;\n\
		break;\n\
		case \"clearSelection\":\n\
			clearSelection();\n\
			return;\n\
		break;\n\
		case \"init\":\n\
			initialize();\n\
			return;\n\
		break;\n\
		case \"freeSelf\":\n\
			freeSelf();\n\
			return;\n\
		break;\n\
		default:\n\
			print(\"unknown message, clsss = txtDisp, self = \",\n\
				self(), \", args: \");\n\
			for (i =0; i < arg[]; i++) print(arg[i], \", \");\n\
			print(\"\\n\");\n\
		break;\n\
		}\n\
	",
                                },
                                {0}};
SlotInfo cl_txtDisp_PSlots[] = {
    {STR__classInfo, CLSI, (long)&class_txtDisp}, {STR_border, LONG | SLOT_RW, BORDER_NONE}, {0}};

SlotInfo* slots_txtDisp[] = {(SlotInfo*)cl_txtDisp_NCSlots, (SlotInfo*)cl_txtDisp_NPSlots,
                             (SlotInfo*)cl_txtDisp_CSlots, (SlotInfo*)cl_txtDisp_PSlots};

MethodInfo meths_txtDisp[] = {
    /* local methods */
    {STR__getSelection, meth_txtDisp__getSelection},
    {STR_append, meth_txtDisp_append},
    {STR_building_maxFontDescent, meth_txtDisp_building_maxFontDescent},
    {STR_building_maxFontHeight, meth_txtDisp_building_maxFontHeight},
    {STR_building_vspan, meth_txtDisp_building_vspan},
    {STR_charMask, meth_txtDisp_charMask},
    {STR_charButtonMask, meth_txtDisp_charButtonMask},
    {STR_charHighLiteMask, meth_txtDisp_charHighLiteMask},
    {STR_charUnderlineMask, meth_txtDisp_charUnderlineMask},
    {STR_clearSelection, meth_txtDisp_clearSelection},
    {STR_clone, meth_txtDisp_clone},
    {STR_clone2, meth_txtDisp_clone2},
    {STR_config, meth_txtDisp_config},
    {STR_currentChar, meth_txtDisp_currentChar},
    {STR_currentLine, meth_txtDisp_currentLine},
    {STR_currentTag, meth_txtDisp_currentTag},
    {STR_currentWord, meth_txtDisp_currentWord},
    {
        STR_cursorColumn,
        meth_txtDisp_cursorColumn,
    },
    {
        STR_cursorRow,
        meth_txtDisp_cursorRow,
    },
    {
        STR_drawCursor,
        meth_txtDisp_drawCursor,
    },
    {
        STR_deHighLight,
        meth_txtDisp_deHighLight,
    },
    {
        STR_eraseCursor,
        meth_txtDisp_eraseCursor,
    },
    {
        STR_expose,
        meth_txtDisp_expose,
    },
    {
        STR_freeSelf,
        meth_txtDisp_freeSelf,
    },
    {
        STR_geta,
        meth_txtDisp_get,
    },
    {
        STR_highLight,
        meth_txtDisp_highLight,
    },
    {STR_initialize, meth_txtDisp_initialize},
    {STR_insert, meth_txtDisp_insert},
    {
        STR_lineRowOffset,
        meth_txtDisp_lineRowOffset,
    },
    {STR_nextTag, meth_txtDisp_nextTag},
    {STR_numberOfLinesDisplayed, meth_txtDisp_numberOfLinesDisplayed},
    {STR_previousTag, meth_txtDisp_previousTag},
    {
        STR_processInput,
        meth_txtDisp_processInput,
    },
    {
        STR_processKeyInput,
        meth_txtDisp_processKeyInput,
    },
    {
        STR_processMouseInput,
        meth_txtDisp_processMouseInput,
    },
    {
        STR_processMouseMove,
        meth_txtDisp_processMouseMove,
    },
    {STR_render, meth_txtDisp_render},
    {STR_shownDepend, meth_txtDisp_shownDepend},
    {STR_selectionInfo, meth_txtDisp_selectionInfo},
    {STR_seta, meth_txtDisp_set},
    {STR_setSelection, meth_txtDisp_setSelection},
    {STR_setRevVideoFlag, meth_txtDisp_setRevVideoFlag},
    {STR_totalLineCount, meth_txtDisp_totalLineCount},
    {0}};

ClassInfo class_txtDisp = {
    helper_txtDisp_get, helper_txtDisp_set, slots_txtDisp, /* class slot information	*/
    meths_txtDisp,                                         /* class methods		*/
    STR_txtDisp,                                           /* class identifier number	*/
    &class_txt,                                            /* super class info		*/
};

/*
 * _getSelection()
 *
 * Result: content of the selection buffer
 * Return: 1 if successful, 0 if error occured
 */
long int meth_txtDisp__getSelection(VObj* self, Packet* result, int argc, Packet argv[])
{
    result->type = PKT_STR;
    result->canFree = PK_CANFREE_STR;
    result->info.s = saveString(tfed_getSelection(self));
    return 1;
}

long int meth_txtDisp_append(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    int i;

    for (i = 0; i < argc; i++)
        if (!tfed_append(tf, PkInfo2Str(&argv[i])))
            return 0;

    return 1;
}

long int meth_txtDisp_building_maxFontDescent(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = tf->building_maxFontDescent;
    return 1;
}

long int meth_txtDisp_building_maxFontHeight(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = tf->building_maxFontHeight;
    return 1;
}

long int meth_txtDisp_building_vspan(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tf->building_vspan + tf->yUL;
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}

long int meth_txtDisp_charMask(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tfed_get_charMask(tf);
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}

long int meth_txtDisp_charButtonMask(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tfed_get_charMask(tf) & MASK_BUTTON;
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}

long int meth_txtDisp_charHighLiteMask(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tfed_get_charMask(tf) & MASK_REVERSE;
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}

long int meth_txtDisp_charUnderlineMask(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    result->type = PKT_INT;
    result->canFree = 0;
    /*
    TEMPORARILY OUT OF COMISSION
            if (tf) {
                    result->info.i = tfed_get_charMask(tf) & MASK_UNDER;
                    return 1;
            } else {
                    result->info.i = -1;
                    return 0;
            }
    */
    result->info.i = -1;
    return 0;
}

/*
 * clearSelection()
 *
 * Result: 1 if successful, 0 if error occured
 * Return: 1 if successful, 0 if error occured
 */
long int meth_txtDisp_clearSelection(VObj* self, Packet* result, int argc, Packet argv[])
{
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = tfed_clearSelection(self);
    return 1;
}

/*
 * clone(clone name suffix)
 *
 * Make a clone self
 *
 * Result: clone object, and optinally name it
 * Return: 1 if successful, 0 if error occured
 */
long int meth_txtDisp_clone(VObj* self, Packet* result, int argc, Packet argv[])
{
    VObj* cloneObj;

    if (!meth_txtDisp_clone2(self, result, argc, argv))
        return 0;
    cloneObj = result->info.o;

    result->type = PKT_OBJ;
    result->canFree = 0;
    if (cloneObj) {
        sendInitToChildren(cloneObj);
        result->info.o = cloneObj;
        return 1;
    }
    result->info.o = NULL;
    return 0;
}

/* Helper: update inset object names in content string by adding suffix.
 * Inset markers look like: \x1fo(objectname)
 * Returns new string allocated with VSaveString, or NULL if no changes needed.
 */
static char* updateContentInsetNames(VObj* clone, char* content, char* suffix)
{
    char* result;
    char* src;
    char* dst;
    char* newContent;
    size_t contentLen, suffixLen, extraLen;
    int insetCount = 0;
    
    if (!content || !suffix || !*suffix)
        return NULL;
    
    suffixLen = strlen(suffix);
    contentLen = strlen(content);
    
    /* First pass: count inset markers to calculate new size */
    for (src = content; *src; src++) {
        if (*src == '\x1f' && *(src+1) == 'o' && *(src+2) == '(') {
            /* Found inset marker, check if object exists */
            char* nameStart = src + 3;
            char* nameEnd = strchr(nameStart, ')');
            if (nameEnd) {
                size_t nameLen = nameEnd - nameStart;
                char nameBuf[256];
                if (nameLen < sizeof(nameBuf)) {
                    strncpy(nameBuf, nameStart, nameLen);
                    nameBuf[nameLen] = '\0';
                    /* Only add suffix if original object exists */
                    if (getObject(nameBuf)) {
                        insetCount++;
                    }
                }
            }
        }
    }
    
    if (insetCount == 0)
        return NULL;
    
    /* Allocate new content with space for suffixes */
    extraLen = insetCount * suffixLen;
    newContent = Vmalloc(GET__memoryGroup(clone), contentLen + extraLen + 1);
    if (!newContent)
        return NULL;
    
    /* Second pass: copy content and add suffixes */
    src = content;
    dst = newContent;
    while (*src) {
        if (*src == '\x1f' && *(src+1) == 'o' && *(src+2) == '(') {
            char* nameStart = src + 3;
            char* nameEnd = strchr(nameStart, ')');
            if (nameEnd) {
                size_t nameLen = nameEnd - nameStart;
                char nameBuf[256];
                if (nameLen < sizeof(nameBuf)) {
                    strncpy(nameBuf, nameStart, nameLen);
                    nameBuf[nameLen] = '\0';
                    if (getObject(nameBuf)) {
                        /* Copy marker prefix and name */
                        *dst++ = *src++;  /* \x1f */
                        *dst++ = *src++;  /* o */
                        *dst++ = *src++;  /* ( */
                        while (src < nameEnd) {
                            *dst++ = *src++;
                        }
                        /* Add suffix before closing paren */
                        strcpy(dst, suffix);
                        dst += suffixLen;
                        *dst++ = *src++;  /* ) */
                        continue;
                    }
                }
            }
        }
        *dst++ = *src++;
    }
    *dst = '\0';
    
    return newContent;
}

long meth_txtDisp_clone2(VObj* self, Packet* result, int argc, Packet argv[])
{
    VObj* cloneObj;
    TFStruct *oldtf, *clonetf;

    if (!meth_txt_clone2(self, result, argc, argv))
        return 0;
    cloneObj = result->info.o;
    if (cloneObj) {
        char* suffix = (argc > 0) ? PkInfo2Str(&argv[0]) : NULL;
        
        /* Update content to reference cloned inset objects */
        if (suffix && GET_content(cloneObj)) {
            char* newContent = updateContentInsetNames(cloneObj, GET_content(cloneObj), suffix);
            if (newContent) {
                Vfree(GET__memoryGroup(cloneObj), GET_content(cloneObj));
                SET_content(cloneObj, newContent);
            }
        }
        
        if (GET__TFStruct(self)) {
            clonetf = tfed_clone(self, cloneObj, suffix);
            if (!clonetf)
                return 0;
            SET__TFStruct(cloneObj, clonetf);
            clonetf->w = GET_window(cloneObj);
            clonetf->self = cloneObj;
        } else {
            SET__TFStruct(cloneObj, NULL);
        }
    }
    result->type = PKT_OBJ;
    result->canFree = 0;
    result->info.o = cloneObj;
    return 1;
}

long int meth_txtDisp_config(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf;

    if (!meth_txt_config(self, result, argc, argv))
        return 0;

    /*XXX optimize */
    tf = updateEStrUser(self);
    if (tf) {
        tf->height = (int)GET_height(self);
        tf->yLR = tf->height - 2;
        tf->width = (int)GET_width(self);
        tf->xLR = tf->width - 2;

        if (tf->firstp) {
            extern TFLineNode* theEditLN;
            if (tf->editableP) {
                replaceNodeLine(tf->currentp, theEditLN, 1, tf->mg);
                SET_content(self, convertNodeLinesToStr(self, tf->firstp));
            }
            /* For non-editable fields, don't update content - use original */
        }
    }
    if (!tfed_updateTFStruct(self, GET_content(self)))
        return 0;

    return 1;
}

long int meth_txtDisp_currentChar(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    char c;

    result->type = PKT_CHR;
    result->canFree = 0;
    if (tf) {
        tfed_get_currentChar(tf, &c);
        result->info.c = c;
        return 1;
    }
    result->info.c = '\0';
    return 0;
}

long int meth_txtDisp_currentLine(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    result->type = PKT_STR;
    if (tf) {
        tfed_get_currentLine(tf, buff);
        result->canFree = PK_CANFREE_STR;
        result->info.s = SaveString(buff);
        return 1;
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

long int meth_txtDisp_currentTag(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    char* cp;

    result->type = PKT_STR;
    if (tf) {
        if ((cp = tfed_get_currentTag(tf))) {
            result->info.s = SaveString(cp);
            result->canFree = PK_CANFREE_STR;
        }
        return 1;
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

long int meth_txtDisp_currentWord(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    result->type = PKT_STR;
    if (tf) {
        tfed_get_currentWord(tf, buff);
        result->canFree = PK_CANFREE_STR;
        result->info.s = SaveString(buff);
        return 1;
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

long int meth_txtDisp_cursorColumn(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tfed_get_cursorColumn(tf);
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}

long int meth_txtDisp_cursorRow(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tfed_get_cursorRow(tf);
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}

long int meth_txtDisp_deHighLight(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    long ln = PkInfo2Int(&argv[0]);
    long cn = PkInfo2Int(&argv[1]);

    lineFlagSet(tf, ln, cn, MASK_REVERSE, -1);
    if ((ln >= tf->screen_row_offset) && (ln < tf->screen_row_offset + tf->num_of_lines)) {
        GLPrepareObjColor(self);
        drawLineOffset(tf, ln - tf->screen_row_offset, 1);
    }
    clearPacket(result);
    return 1;
}

long int meth_txtDisp_drawCursor(VObj* self, Packet* result, int argc, Packet argv[])
{
    return tfed_drawCursor(self);
}

long int meth_txtDisp_eraseCursor(VObj* self, Packet* result, int argc, Packet argv[])
{
    return tfed_eraseCursor(self);
}

long int meth_txtDisp_expose(VObj* self, Packet* result, int argc, Packet argv[])
{
    Window w = GET_window(self);
    int retval;
    
    /*XXX WATCH OUT. This is cheating and not calling super methods.
            meth_txt_expose(self, result, argc, argv);
    */
    GLPrepareObjColor(self);
    if (argc == 0) {
        retval = tfed_expose(self, 0, 0, GET_width(self), GET_height(self));
    } else {
        retval = tfed_expose(self, argv[0].info.i, argv[1].info.i, argv[2].info.i, argv[3].info.i);
    }
    
    /* Draw border if set */
    if (w && GET_border(self)) {
        GLDrawBorder(w, 0, 0, GET_width(self) - 1, GET_height(self) - 1, GET_border(self), 1);
    }
    
    return retval;
}

long int meth_txtDisp_freeSelf(VObj* self, Packet* result, int argc, Packet argv[])
{
    if (!exitingViola) {
        TFStruct* tf = GET__TFStruct(self);
        if (tf) {
            freeNodeLines(tf);
            Vfree(GET__memoryGroup(self), tf);

            /* purge cache. else the next tf gets toasted */
            updateEStrUser(NULL);
            /* clear dangling pointer to prevent UAF */
            SET__TFStruct(self, NULL);
        }
    }
    meth_txt_freeSelf(self, result, argc, argv);
    return 1;
}

long int helper_txtDisp_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID)
{
    char* str;
    extern TFLineNode* theEditLN;

    switch (labelID) {
    case STR_content: {
        TFStruct* tf = updateEStrUser(self);
        result->type = PKT_STR;
        result->canFree = 0;
        if (tf) {
            if (tf->editableP) {
                /* Editable field: user may have changed content, so convert from lines */
                replaceNodeLine(tf->currentp, theEditLN, 1, tf->mg);
                result->info.s = convertNodeLinesToStr(self, tf->firstp);
            } else {
                /* Non-editable: return original content to avoid round-trip conversion */
                result->info.s = GET_content(self) ? GET_content(self) : "";
            }
        } else {
            result->info.s = "";
        }
        return 1;
    }
    case STR_wrap: {
        TFStruct* tf = updateEStrUser(self);
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = tf->wrap;
        return 1;
    }
    case STR_verbatim: {
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = GET_verbatim(self);
        return 1;
    }
    case STR_format: {
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = GET_format(self);
        return 1;
    }
    }
    return helper_txt_get(self, result, argc, argv, labelID);
}
long int meth_txtDisp_get(VObj* self, Packet* result, int argc, Packet argv[])
{
    return helper_txtDisp_get(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

/*
 * highLight(lineNumber, charactersToHighLight)
 *
 */
long int meth_txtDisp_highLight(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    long ln = PkInfo2Int(&argv[0]);
    long cn = PkInfo2Int(&argv[1]);

    lineFlagSet(tf, ln, cn, MASK_REVERSE, 1);
    if ((ln >= tf->screen_row_offset) && (ln < tf->screen_row_offset + tf->num_of_lines)) {
        GLPrepareObjColor(self);
        drawLineOffset(tf, ln - tf->screen_row_offset, 1);
    }
    clearPacket(result);
    return 1;
}

long int meth_txtDisp_initialize(VObj* self, Packet* result, int argc, Packet argv[])
{
    VObjList* objl;

    if (!meth_txt_initialize(self, result, argc, argv))
        return 0;
    if (!tfed_setUpTFStruct(self, GET_content(self)))
        return 0;
    return 1;
}

long int meth_txtDisp_insert(VObj* self, Packet* result, int argc, Packet argv[])
{
    Window w = GET_window(self);

    GLPrepareObjColor(self);
    if (argv[0].type == PKT_CHR) {
        if (tfed_processKeyEvent(self, w, argv[0].info.c))
            return 1;
    } else {
        char *cp, *in = VSaveString(GET__memoryGroup(self), PkInfos2Str(argc, argv));
        if (in)
            for (cp = in; *cp; cp++)
                if (!tfed_processKeyEvent(self, w, *cp))
                    return 0;
        Vfree(GET__memoryGroup(self), in);
        return 1;
    }
    return 0;
}

long int meth_txtDisp_lineRowOffset(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tfed_get_lineRowOffset(tf);
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}

long int meth_txtDisp_nextTag(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    char* cp;

    result->type = PKT_STR;
    if (tf) {
        cp = tfed_get_nextTag(tf);
        if (cp) {
            result->info.s = SaveString(cp);
            result->canFree = PK_CANFREE_STR;
            return 1;
        }
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

long int meth_txtDisp_numberOfLinesDisplayed(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tfed_get_numberOfLinesDisplayed(tf);
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}

long int meth_txtDisp_previousTag(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    char* cp;

    result->type = PKT_STR;
    if (tf) {
        cp = tfed_get_previousTag(tf);
        if (cp) {
            result->info.s = SaveString(cp);
            result->canFree = PK_CANFREE_STR;
            return 1;
        }
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

long int meth_txtDisp_processInput(VObj* self, Packet* result, int argc, Packet argv[])
{
    return 0;
}

long int meth_txtDisp_processKeyInput(VObj* self, Packet* result, int argc, Packet argv[])
{
    return 0;
}

long int meth_txtDisp_processMouseInput(VObj* self, Packet* result, int argc, Packet argv[])
{
    return tfed_processMouseInput(self);
}

/* was test4*/
long int meth_txtDisp_processMouseMove(VObj* self, Packet* result, int argc, Packet argv[])
{
    char* url;
    url = tfed_processMouseMove(self);
    if (url)
        result->info.s = url;
    else
        result->info.s = "";
    result->canFree = 0;
    result->type = PKT_STR;
    return 1;
}

long int meth_txtDisp_render(VObj* self, Packet* result, int argc, Packet argv[])
{
    if (meth_txt_render(self, result, argc, argv)) {
        TFStruct* tf = GET__TFStruct(self);
        VObjList* objl;

        /* if the super render methods have newly opened up a window,
         * then update the tf structure.
         */
        if (!tf)
            return 0;
        if (!tf->w) {
            if (GET_window(self)) {
                tf->w = GET_window(self);
                if (tf)
                    tf->isRenderAble =
                        (tf->w && GET_width(self) > 2 && GET_height(self) > 2) ? 1 : 0;
            } else {
                return 0;
            }
        }
        if (tf->isRenderAble)
            if (tfed_render(self)) {
                /* may be quite redundantly useless */
                helper_txtDisp_updateShownInfo(tf);
                for (objl = GET__shownDepend(self); objl; objl = objl->next) {
                    if (objl->o) {
                        sendMessage1N2int(objl->o, "shownInfoV", GET_shownPositionV(self),
                                          GET_shownSizeV(self));
                    }
                }
                return 1;
            }
    }
    return 0;
}

/*
 * setSelection()
 *
 * Result: content of the selection buffer
 * Return: 1 if successful, 0 if error occured
 */
long int meth_txtDisp_setSelection(VObj* self, Packet* result, int argc, Packet argv[])
{
    if (argc > 0)
        GLSetSelection(self, saveString(PkInfo2Str(&argv[0])));
    else
        GLSetSelection(self, NULL);
    return 1;
}

/*
 * selectionInfo()
 *
 * Result: [0] object, [1] from_x, [2] from_y, [3] to_x, [4] to_y
 * Return: 1 if successful, 0 if error occured
 */
long int meth_txtDisp_selectionInfo(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    Packet* packet0 = makePacket();
    Attr* attrp;

    result->type = PKT_ATR;
    result->canFree = PK_CANFREE_STR;
    result->info.a = attrp = makeAttr(0, (intptr_t)packet0);

    if (tf) {
        Packet* packet1 = makePacket();
        Packet* packet2 = makePacket();
        Packet* packet3 = makePacket();
        Packet* packet4 = makePacket();
        Packet* packet5 = makePacket();

        packet1->info.o = self;
        packet1->type = PKT_OBJ;
        packet1->canFree = 0;
        packet2->info.i = tf->highLiteFrom_cx;
        packet2->type = PKT_INT;
        packet2->canFree = 0;
        packet3->info.i = tf->highLiteFrom_cy;
        packet3->type = PKT_INT;
        packet3->canFree = 0;
        packet4->info.i = tf->highLiteTo_cy;
        packet4->type = PKT_INT;
        packet4->canFree = 0;
        packet5->info.i = tf->highLiteTo_cy;
        packet5->type = PKT_INT;
        packet5->canFree = 0;

        attrp->next = makeAttr(0, (intptr_t)packet1);
        attrp->next->next = makeAttr(1, (intptr_t)packet2);
        attrp->next->next->next = makeAttr(2, (intptr_t)packet3);
        attrp->next->next->next->next = makeAttr(3, (intptr_t)packet4);
        attrp->next->next->next->next->next = makeAttr(4, (intptr_t)packet5);
        return 1;
    } else {
        packet0->info.o = NULL;
        packet0->type = PKT_OBJ;
        packet0->canFree = 0;
        return 0;
    }
}

long int meth_txtDisp_shownDepend(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    if (!tf)
        return 0;
    if (helper_txtDisp_updateShownInfo(tf)) {
        VObjList* objl;
        for (objl = GET__shownDepend(self); objl; objl = objl->next) {
            if (objl->o) {
                sendMessage1N2int(objl->o, "shownInfoV", GET_shownPositionV(self),
                                  GET_shownSizeV(self));
            }
        }
    }
    return 1;
}

int help_txtDisp_shownPositionV(VObj* self, int newPosition)
{
    TFStruct* tf = updateEStrUser(self);
    int oldDestLine, destLine;
    int position = GET_shownPositionV(self);
    VObjList* objl;

    if (newPosition < 0)
        newPosition = 0;
    else if (newPosition > 100)
        newPosition = 100;

    if (!tf)
        return 0;
    /*
            printf("HSP: position=%d, newPosition=%d\n", position, newPosition);
            printf(".. lineVisibleCount=%d, lineNodeCount=%d, num_of_lines=%d\n",
                    tf->lineVisibleCount, tf->lineNodeCount, tf->num_of_lines);
    */
    /* to minimize unnecessary update, check for sameness */
    if (position == newPosition)
        return newPosition;

    /* new position may not be visibly significant */
    destLine = (float)(tf->lineVisibleCount - tf->num_of_lines) / (float)(tf->lineVisibleCount) *
               ((float)(tf->lineNodeCount) * ((float)newPosition / 100.0));
    oldDestLine = (float)(tf->lineVisibleCount - tf->num_of_lines) / (float)(tf->lineVisibleCount) *
                  ((float)(tf->lineNodeCount) * ((float)position / 100.0));
    /*
            printf("HSP: destLine=%d, oldDestLine=%d\n", destLine, oldDestLine);
    */
    if (destLine == oldDestLine)
        return newPosition;
    /* textFieldJumpToLine(self, destLine);*/
    GLPrepareObjColor(self);
    tfed_jumpToOffsetLine(self, destLine);

    SET_shownPositionV(self, newPosition);

    return newPosition;
}

/*
 * returns non-zero if set operation succeded, zero otherwise.
 */
long int helper_txtDisp_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID)
{
    char* str;

    switch (labelID) {
    case STR_height: {
        TFStruct* tf;
        if (!helper_txt_set(self, result, argc, argv, labelID))
            return 0;
        tf = updateEStrUser(self);
        if (tf) {
            tf->height = (int)GET_height(self);
            tf->yLR = tf->height - 2;
        }
        return 1;
    }
    case STR_width: {
        TFStruct* tf;
        if (!helper_txt_set(self, result, argc, argv, labelID))
            return 0;
        tf = updateEStrUser(self);
        if (tf) {
            tf->width = (int)GET_width(self);
            tf->xLR = tf->width - 2;
        }
        return 1;
    }
    case STR_shownPositionV:
        return help_txtDisp_shownPositionV(self, (int)PkInfo2Int(&argv[1]));

    case STR_content: {
        VObjList* objl;
        TFStruct* tf;

        result->info.s = VSaveString(GET__memoryGroup(self), PkInfo2Str(&argv[1]));
        result->type = PKT_STR;
        result->canFree = 0;
        if (GET_content(self))
            Vfree(GET__memoryGroup(self), GET_content(self));
        SET_content(self, result->info.s);
        tf = tfed_updateTFStruct(self, result->info.s);

        if (!tf)
            return 0;
        scanVerticalMetrics(tf);
        if (!helper_txtDisp_updateShownInfo(tf))
            return 0;
        for (objl = GET__shownDepend(self); objl; objl = objl->next) {
            if (objl->o) {
                sendMessage1N2int(objl->o, "shownInfoV", GET_shownPositionV(self),
                                  GET_shownSizeV(self));
            }
        }
        return 1;
    }
    case STR_cursor:
        if (SET_cursor(self, PkInfo2Int(&argv[1])))
            tfed_drawCursor(self);
        else
            tfed_eraseCursor(self);
        return 1;

    case STR_cursorBlinkDelay:
        return tfed_setCursorBlinkDelay(self, PkInfo2Int(&argv[1]));

    case STR_offset:
        return tfed_jumpToOffsetLine(self, PkInfo2Int(&argv[1]));

    case STR_visible:
        if (helper_txt_set(self, result, argc, argv, labelID)) {
            TFStruct* tf = GET__TFStruct(self);
            if (tf) {
                tf->isRenderAble =
                    (GET_window(self) && GET_width(self) > 2 && GET_height(self) > 2) ? 1 : 0;
                tf->w = GET_window(self);
            }
            return 1;
        } else {
            return 0;
        }
    case STR_wrap: {
        TFStruct* tf = updateEStrUser(self);
        SET_wrap(self, PkInfo2Int(&argv[1]));
        return tfed_set_wrap(tf, GET_wrap(self));
    }
    case STR_verbatim: {
        SET_verbatim(self, PkInfo2Int(&argv[1]));
        return GET_verbatim(self);
    }
    case STR_format: {
        SET_format(self, PkInfo2Int(&argv[1]));
        return GET_format(self);
    }
    case STR_paneConfig: {
        if (helper_pane_set(self, result, argc, argv, labelID)) {
            TFStruct* tf = GET__TFStruct(self);
            if (tf)
                tf->align = (int)GET__paneConfig(self);
            return 1;
        } else {
            return 0;
        }
    }
    }
    return helper_txt_set(self, result, argc, argv, labelID);
}
long int meth_txtDisp_set(VObj* self, Packet* result, int argc, Packet argv[])
{
    return helper_txtDisp_set(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

long int meth_txtDisp_setRevVideoFlag(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);

    GLPrepareObjColor(self);
    tfed_setReverseMaskInButtonRange(tf, PkInfo2Int(&argv[0]));
    drawLineOffset(tf, tf->current_row - tf->screen_row_offset, 1);
    XFlush(display);

    return 1;
}

/*
 *
 */
long int helper_txtDisp_updateShownInfo(TFStruct* tf)
{
    if (tf->lineVisibleCount) {
        int thumbPositionV, thumbSizeV, ldiff;

        ldiff = tf->lineVisibleCount - tf->num_of_lines;
        if (ldiff) {

            /*
                            printf("self=%s :lineVisibleCount=%d, num_of_lines=%d\n",
                                    GET_name(tf->self), tf->lineVisibleCount, tf->num_of_lines);
            */
            thumbPositionV = (float)(tf->screen_row_offset) / (float)(ldiff) * 100.0;
        } else {
            thumbPositionV = 0;
        }
        if (ldiff > 0) {
            thumbSizeV = (float)(tf->num_of_lines + 1.0) / (float)(tf->lineVisibleCount) * 100.0;
        } else {
            thumbSizeV = 100;
        }
        if (GET_shownPositionV(tf->self) != thumbPositionV)
            SET_shownPositionV(tf->self, thumbPositionV);
        if (GET_shownSizeV(tf->self) != thumbSizeV)
            SET_shownSizeV(tf->self, thumbSizeV);
        return 1;
    }
    return 0;
}

long int meth_txtDisp_totalLineCount(VObj* self, Packet* result, int argc, Packet argv[])
{
    TFStruct* tf = updateEStrUser(self);
    result->type = PKT_INT;
    result->canFree = 0;
    if (tf) {
        result->info.i = tfed_get_totalLineCount(tf);
        return 1;
    } else {
        result->info.i = -1;
        return 0;
    }
}
