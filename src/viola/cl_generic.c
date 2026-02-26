/*
 * Copyright 1991 Pei-Yuan Wei.  All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */
/*
 * cl_generic.c
 *
 * class	: generic
 * superClass	: cosmic
 */
#include "cl_generic.h"
#include "ast.h"
#include "attr.h"
#include "cl_cosmic.h"
#include "discovery.h"
#include "cexec.h"
#include "cgen.h"
#include "cl_txtDisp.h"
#include "class.h"
#include "classlist.h"
#include "error.h"
#include "event.h"
#include "file.h"
#include "glib.h"
#include "hash.h"
#include "htmath.h"
#include "html.h"
#include "html2.h"
#include "ident.h"
#include "loader.h"
#include "membership.h"
#include "method.h"
#include "misc.h"
#include "msgHandler.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "scanutils.h"
#include "sgml.h"
#include "slib.h"
#include "slotaccess.h"
#include "sys.h"
#include "tfed.h"
#include "utils.h"
#include "vlist.h"
#include <ctype.h>

/* For isURLVisited - access to document history */
#include "history_api.h"
#include <math.h>
#include <stdlib.h>
#include <sys/file.h>
#include <unistd.h>

#include "../libWWW/HTParse.h"
#include "../libWWW/HTTP.h"
#include "../libWWW/HTUU.h"
#include "stgcall.h"

#ifdef hpux
#include <time.h>
#else // hpux
#include <sys/time.h>
#endif // hpux

#include "HTML_share.h"

extern int notSecure(VObj*);

extern double cos(double), sin(double);
int flag_cliprompt = 1;

#define RADIAN_TO_DEGREE_RATIO 0.017453293f

struct StrInfo init_obj_script; /* initialized in class.c */

SlotInfo cl_generic_NCSlots[] = {{0}};
SlotInfo cl_generic_NPSlots[] = {
    [0] = {
        .id = STR_name,
        .flags = PTRS | SLOT_RW,
        .val = (long)""
    },
    [1] = {
        .id = STR_parent,
        .flags = PTRS | SLOT_RW,
        .val = (long)""
    },
    [2] = {
        .id = STR__parent,
        .flags = OBJP,
        .val = 0
    },
    [3] = {
        .id = STR_children,
        .flags = PTRS | SLOT_RW,
        .val = (long)""
    },
    [4] = {
        .id = STR__children,
        .flags = OBJL,
        .val = 0
    },
    [5] = {
        .id = STR_security,
        .flags = LONG,
        .val = 0,
    },
    [6] = {
        .id = STR_script,
        .flags = STRI | SLOT_RW,
        /*	(long)&init_obj_script,*/
        .val = (long)"usual();"
    },
    [7] = {
        .id = STR__script,
        .flags = PCOD,
        .val = 0,
    },
    [8] = {
        .id = STR__varList,
        .flags = ATTR,
        .val = 0
    },
    [9] = {
        .id = STR__argAttr,
        .flags = ATTR,
        .val = 0
    },
    [10] = {
        .id = STR__classScriptVV,
        .flags = PTRV,
        .val = 0
    },
    [11] = {
        .id = STR__scriptVV,
        .flags = PTRV,
        .val = 0
    },
    [12] = {
        .id = STR__tempScriptVV,
        .flags = PTRV,
        .val = 0
    },
    [13] = {
        .id = STR_active,
        .flags = LONG | SLOT_RW,
        .val = (long)0
    },
    [14] = {0}
};
SlotInfo cl_generic_CSlots[] = {/* COMMON SLOTS */
                                [0] = {
                                    .id = STR_class,
                                    .flags = PTRS | SLOT_RW,
                                    .val = (long)"generic"
                                },
                                [1] = {0}};
SlotInfo cl_generic_PSlots[] = {/* PRIVATE SLOTS */
                                [0] = {
                                    .id = STR__classInfo,
                                    .flags = CLSI,
                                    .val = (long)&class_generic
                                },
                                [1] = {0}};

SlotInfo* slots_generic[] = {(SlotInfo*)cl_generic_NCSlots, (SlotInfo*)cl_generic_NPSlots,
                             (SlotInfo*)cl_generic_CSlots, (SlotInfo*)cl_generic_PSlots};

MethodInfo meths_generic[] = {
    {STR_GB_copy, meth_generic_GB_copy},
    {STR_GB_data, meth_generic_GB_data},
    {STR_GB_char, meth_generic_GB_char},
    {STR_GB_count, meth_generic_GB_count},
    {STR_GB_create, meth_generic_GB_create},
    {STR_GB_decChar, meth_generic_GB_decChar},
    {STR_GB_decChar1, meth_generic_GB_decChar1},
    {STR_GB_decLine, meth_generic_GB_decLine},
    {STR_GB_free, meth_generic_GB_free},
    {STR_GB_herePtr, meth_generic_GB_herePtr},
    {STR_GB_incChar, meth_generic_GB_incChar},
    {STR_GB_incChar1, meth_generic_GB_incChar1},
    {STR_GB_incLine, meth_generic_GB_incLine},
    {STR_GB_line, meth_generic_GB_line},
    {STR_GB_moveToChar, meth_generic_GB_moveToChar},
    {STR_GB_moveToLine, meth_generic_GB_moveToLine},
    {STR_GB_moveToStart, meth_generic_GB_moveToStart},
    {STR_GB_nthChar, meth_generic_GB_nthChar},
    {STR_GB_nthLine, meth_generic_GB_nthLine},
    {STR_GB_set, meth_generic_GB_set},
    {STR_GB_setCopy, meth_generic_GB_setCopy},
    {
        STR_HTTPCanonicalURL,
        meth_generic_HTTPCanonicalURL,
    },
    {
        STR_HTTPCurrentDocAddr,
        meth_generic_HTTPCurrentDocAddr,
    },
    {
        STR_HTTPCurrentDocAddrParsed,
        meth_generic_HTTPCurrentDocAddrParsed,
    },
    {
        STR_HTTPCurrentDocAddrSet,
        meth_generic_HTTPCurrentDocAddrSet,
    },
    {STR_HTTPDecodeURL, meth_generic_HTTPDecodeURL},
    {STR_HTTPEncodeURL, meth_generic_HTTPEncodeURL},
    {STR_Base64DecodeToFile, meth_generic_Base64DecodeToFile},
    {STR_HTTPGet, meth_generic_HTTPGet},
    {STR_HTTPGetNParse, meth_generic_HTTPGetNParse},
    {STR_HTTPPost, meth_generic_HTTPPost},
    {STR_HTTPSubmit, meth_generic_HTTPSubmit},
    {STR_HTTPHotListAdd, meth_generic_HTTPHotListAdd},
    {STR_HTTPHotListDelete, meth_generic_HTTPHotListDelete},
    {STR_HTTPHotListChange, meth_generic_HTTPHotListChange},
    {
        STR_HTTPHotListGet,
        meth_generic_HTTPHotListGet,
    },
    {
        STR_HTTPHotListLoad,
        meth_generic_HTTPHotListLoad,
    },
    {
        STR_HTTPHotListSave,
        meth_generic_HTTPHotListSave,
    },
    {STR_SGMLBuildDoc, meth_generic_SGMLBuildDoc},
    {STR_SGMLBuildDocB, meth_generic_SGMLBuildDocB},
    {
        STR_SGMLBuildDoc_flush,
        meth_generic_SGMLBuildDoc_flush,
    },
    {
        STR_SGMLBuildDoc_enterChanged,
        meth_generic_SGMLBuildDoc_enterChanged,
    },
    {
        STR_SGMLBuildDoc_leaveChanged,
        meth_generic_SGMLBuildDoc_leaveChanged,
    },
    {
        STR_SGMLBuildDoc_insertObj,
        meth_generic_SGMLBuildDoc_insertObj,
    },
    {
        STR_SGMLBuildDoc_setBuff,
        meth_generic_SGMLBuildDoc_setBuff,
    },
    {
        STR_SGMLBuildDoc_setColors,
        meth_generic_SGMLBuildDoc_setColors,
    },
    {
        STR_SGMLBuildDoc_span,
        meth_generic_SGMLBuildDoc_span,
    },
    {STR_SGMLFindAnchorOffset, meth_generic_SGMLFindAnchorOffset},
    {
        STR_SGMLMathFormater,
        meth_generic_SGMLMathFormater,
    },
    {STR_SGMLTileDoc, meth_generic_SGMLTileDoc},
    {STR_SGMLReBuildDoc, meth_generic_SGMLReBuildDoc},
    {
        STR_SGMLGetStyle,
        meth_generic_SGMLGetStyle,
    },
    {
        STR_SGMLSetStyle,
        meth_generic_SGMLSetStyle,
    },
    {STR_HTMLMathUpdateWindow, meth_generic_HTMLMathUpdateWindow},
    {
        STR_SGMLTableFormater,
        meth_generic_SGMLTableFormater,
    },
    {STR_STGInfo, meth_generic_STGInfo},
    {STR_STG_tagPtr, meth_generic_STG_tagPtr},
    {STR_STG_tagPtrDepth, meth_generic_STG_tagPtrDepth},
    {STR_STG_attr, meth_generic_STG_attr},
    {STR_STG_attrEx, meth_generic_STG_attrEx},
    {STR_STG_clean, meth_generic_STG_clean},
    {STR_accessible, meth_generic_accessible},
    {STR_activeHelp, meth_generic_activeHelp},
    {STR_addPicFromFile, meth_generic_addPicFromFile},
    {STR_after, meth_generic_after},
    {STR_append, meth_generic_append},
    {STR_argument, meth_generic_argument},
    {STR_ascii, meth_generic_ascii},
    {STR_asciiVal, meth_generic_asciiVal},
    {STR_bell, meth_generic_bell},
    {STR_bellVolume, meth_generic_bellVolume},
    {STR_discoverySetPage, meth_generic_discoverySetPage},
    {STR_discoveryEnable, meth_generic_discoveryEnable},
    {STR_discoveryReset, meth_generic_discoveryReset},
    {STR_discoveryBroadcast, meth_generic_discoveryBroadcast},
    {STR_discoveryIsRemote, meth_generic_discoveryIsRemote},
    {STR_char, meth_generic_char},
    {STR_charHeight, meth_generic_charHeight},
    {STR_clear, meth_generic_clear},
    {STR_cli, meth_generic_cli},
    {STR_clone, meth_generic_clone},
    {STR_clone2, meth_generic_clone2},
    {STR_compressSpaces, meth_generic_compressSpaces},
    {STR_concatenate, meth_generic_concatenate},
    {STR_concat, /* alias */
     meth_generic_concatenate},
    {STR_concatList, meth_generic_concatList},
    {STR_cos, meth_generic_cos},
    {STR_countChars, /* alias */
     meth_generic_strlen},
    {STR_countChildren, meth_generic_countChildren},
    {STR_countItems, meth_generic_countItems},
    {STR_countLines, meth_generic_countLines},
    {STR_countWords, meth_generic_countWords},
    {STR_ctrlKeyP, meth_generic_ctrlKeyP},
    {STR_cursorShape, meth_generic_cursorShape},
    {STR_date, meth_generic_date},
    {STR_deepObjectListSend, meth_generic_deepObjectListSend},
    {STR_defineNewFont, meth_generic_defineNewFont},
    {STR_delay, meth_generic_delay},
    {STR_deleteFile, meth_generic_deleteFile},
    {
        STR_deleteSubStr,
        meth_generic_deleteSubStr,
    },
    {
        STR_deleteSubStrQ,
        meth_generic_deleteSubStrQ,
    },
    {STR_depth, meth_generic_depth},
    {STR_destroyVariable, meth_generic_destroyVariable},
    {STR_environVar, meth_generic_environVar},
    {STR_execScript, meth_generic_execScript},
    {
        STR_filter,
        meth_generic_filter,
    },
    {
        STR_findPattern,
        meth_generic_findPattern,
    },
    {STR_float, meth_generic_float},
    {
        STR_format,
        meth_generic_format,
    },
    {STR_freeSelf, meth_generic_freeSelf},
    {STR_geta, meth_generic_get},
    {STR_getResource, meth_generic_getResource},
    {STR_getSelection, meth_generic_getSelection},
    {STR_getVariable, meth_generic_getVariable},
    {STR_gravity, meth_generic_gravity},
    {STR_hash, meth_generic_hash},
    {STR_height, meth_generic_height},
    {STR_initialize, meth_generic_initialize},
    {STR_int, meth_generic_int},
    {STR_intToAlpha, meth_generic_intToAlpha},
    {STR_intToRoman, meth_generic_intToRoman},
    {STR_item, meth_generic_item},
    {STR_isBlank, meth_generic_isBlank},
    {STR_key, meth_generic_key},
    {STR_listAllObjects, meth_generic_listAllObjects},
    {STR_loadFile, meth_generic_loadFile},
    {STR_loadSTG, meth_generic_loadSTG},
    {STR_makeTempFile, meth_generic_makeTempFile},
    {STR_not, meth_generic_not},
    {STR_nthChar, meth_generic_nthChar},
    {STR_nthChild, meth_generic_nthChild},
    {STR_nthItem, meth_generic_nthItem},
    {STR_nthLine, meth_generic_nthLine},
    {
        STR_nthObjectInList,
        meth_generic_nthObjectInList,
    },
    {STR_nthSibling, meth_generic_nthSibling},
    {STR_nthWord, meth_generic_nthWord},
    {STR_objectListAppend, meth_generic_objectListAppend},
    {STR_objectListAppend_children, meth_generic_objectListAppend_children},
    {STR_objectListCount, meth_generic_objectListCount},
    {STR_objectListCount_children, meth_generic_objectListCount_children},
    {STR_objectListDelete, meth_generic_objectListDelete},
    {STR_objectListDelete_children, meth_generic_objectListDelete_children},
    {STR_objectListPrepend, meth_generic_objectListPrepend},
    {STR_objectListPrepend_children, meth_generic_objectListPrepend_children},
    {STR_objectListSend, meth_generic_objectListSend},
    {STR_objectListSend_children, meth_generic_objectListSend_children},
    {STR_objectPosition, meth_generic_objectPosition},
    {STR_parent, meth_generic_parent},
    {STR_pipe, meth_generic_pipe},
    {STR_prepend, meth_generic_prepend},
    {STR_print, meth_generic_print},
    {STR_printf, meth_generic_printf},
    {STR_random, meth_generic_random},
    {STR_replaceChar, meth_generic_replaceChar},
    {STR_replaceCharQ, meth_generic_replaceCharQ},
    {STR_replaceStr, meth_generic_replaceStr},
    {STR_replaceStrQ, meth_generic_replaceStrQ},
    {STR_saveFile, meth_generic_saveFile},
    {
        STR_scanf,
        meth_generic_scanf,
    },
    {
        STR_securityMode,
        meth_generic_securityMode,
    },
    {STR_self, meth_generic_self},
    {STR_selectionInfo, meth_generic_selectionInfo},
    {STR_sendToInterface, meth_generic_sendToInterface},
    {STR_isURLVisited, meth_generic_isURLVisited},
    {STR_setLinkColor, meth_generic_setLinkColor},
    {STR_setLinkVisitedColor, meth_generic_setLinkVisitedColor},
    {STR_resetLinkColors, meth_generic_resetLinkColors},
    {STR_addURLToHistory, meth_generic_addURLToHistory},
    {STR_setDefaultFontFamily, meth_generic_setDefaultFontFamily},
    {STR_getDefaultFontFamily, meth_generic_getDefaultFontFamily},
    {STR_seta, meth_generic_set},
    {STR_setMouse, meth_generic_setMouse},
    {STR_setResource, meth_generic_setResource},
    {STR_setSelection, meth_generic_setSelection},
    {STR_setVariable, meth_generic_setVariable},
    {STR_shiftKeyP, meth_generic_shiftKeyP},
    {STR_sin, meth_generic_sin},
    {STR_sleep, meth_generic_sleep},
    {STR_sprintf, meth_generic_sprintf},
    {STR_str, meth_generic_str},
    {STR_strlen, meth_generic_strlen},
    {STR_system, meth_generic_system},
    {STR_target, meth_generic_target},
    {STR_textWidth, meth_generic_textWidth},
    {STR_trimEdge, meth_generic_trimEdge},
    {STR_trimEdgeQ, meth_generic_trimEdgeQ},
    {STR_target, meth_generic_target},
    {STR_time, meth_generic_time},
    {STR_tool, meth_generic_tool},
    {STR_unhash, meth_generic_unhash},
    {STR_version, meth_generic_version},
    {STR_violaPath, meth_generic_violaPath},
    {STR_x, meth_generic_x},
    {STR_watch, meth_generic_watch},
    {STR_width, meth_generic_width},
    {
        STR_write, meth_generic_print /* alias */
    },
    {STR_writeln, meth_generic_writeln},
    {STR_y, meth_generic_y},
    {
        STR_code_HTML_txt,
        meth_generic_code_HTML_txt,
    },
    {
        STR_code_HTML_txtAnchor,
        meth_generic_code_HTML_txtAnchor,
    },
    {
        STR_code_HTML_header_large,
        meth_generic_code_HTML_header_large,
    },
    {
        STR_code_HTML_header_medium,
        meth_generic_code_HTML_header_medium,
    },
    {
        STR_code_HTML_header_small,
        meth_generic_code_HTML_header_small,
    },
    {0}};

ClassInfo class_generic = {
    helper_generic_get, helper_generic_set, slots_generic, /* class slot information	*/
    meths_generic,                                         /* class methods		*/
    STR_generic,                                           /* class identifier number	*/
    &class_cosmic,                                         /* super class info		*/
};

/**
 ** Note: the series of GB_* procedures that operate on Global Buffers.
 ** They're here for efficiency's sake. Use them with care!
 **/
/*
 * GB_copy(GBuffID)
 *
 * Result: a copy (malloc'ed) of the global buffer
 */
long meth_generic_GB_copy(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* str;
    long bufferID;

    result->type = PKT_STR;
    if (argc != 1) {
        /* incorrect number of arguments */
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        fprintf(stderr, "unknown Global Buffer. id=%ld\n", bufferID);
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    if (GBuff[bufferID]) {
        result->info.s = SaveString(GBuff[bufferID]);
        result->canFree = PK_CANFREE_STR;
        return 1;
    } else {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
}

/*
 * GB_data(GBuffID)
 *
 * Result: the global buffer (no malloc occurs)
 */
long meth_generic_GB_data(VObj* self, Packet* result, int argc, Packet argv[]) {
    long bufferID = PkInfo2Int(&argv[0]);

    result->type = PKT_STR;
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        fprintf(stderr, "unknown Global Buffer. id=%ld\n", bufferID);
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    if (GBuff[bufferID]) {
        result->info.s = GBuff[bufferID];
        result->canFree = 0;
        return 1;
    } else {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
}

/*
 * GB_char(GBuffID)
 *
 * Result:  the character at the buffer's index
 */
long meth_generic_GB_char(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_CHR;
    result->canFree = 0;
    if (argc != 1) {
        /* incorrect number of arguments */
        result->info.c = '\0';
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        fprintf(stderr, "unknown Global Buffer. id=%ld\n", bufferID);
        result->info.c = '\0';
        return 0;
    }
    if (GBuff[bufferID]) {
        result->info.c = GBuff[bufferID][GBuffIdx[bufferID]];
        return 1;
    } else {
        result->info.c = '\0';
        return 0;
    }
}

/*
 * GB_count()
 *
 * Returns the number of currently allocated Global Buffers.
 *
 * Result: number of global buffers (int)
 * Return: 1 if successful
 *
 * Source: By analogy with other GB_* functions that check numOfGBuffs
 *         (viola940323/src/viola/cl_generic.c, mystrings.c)
 */
long meth_generic_GB_count(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern int numOfGBuffs;  /* defined in mystrings.c */

    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = numOfGBuffs;
    return 1;
}

long meth_generic_GB_create(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

/*
 * GB_decChar(GBuffID, n)
 *
 * Decrements index by n. by 1 if n isn't given.
 *
 * Result: char at index, '\0' on error
 */
long meth_generic_GB_decChar(VObj* self, Packet* result, int argc, Packet argv[]) {
    long n;

    result->type = PKT_CHR;
    result->canFree = 0;
    if (argc == 2) {
        n = PkInfo2Int(&argv[1]);
    } else {
        n = 1;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.c = '\0';
        return 0;
    }
    GBuffIdx[bufferID] -= n;
    result->info.c = GBuff[bufferID][GBuffIdx[bufferID]];
    return 1;
}

/*
 * GB_decChar1(GBuffID)
 *
 * Decrements index by 1.
 *
 * Result: char at index, '\0' on error
 */
long meth_generic_GB_decChar1(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_CHR;
    result->canFree = 0;
    if (argc != 1) {
        /* incorrect number of arguments */
        result->info.c = '\0';
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.c = '\0';
        return 0;
    }
    GBuffIdx[bufferID]--;
    result->info.c = GBuff[bufferID][GBuffIdx[bufferID]];
    return 1;
}

/*
 * GB_decLine(GBuffID, n)
 *
 * Decrements index back n lines. (1 means to beginning of previous line).
 * Decrements by 1 line if n isn't given.
 *
 * Result: index, -1 on error
 */
long meth_generic_GB_decLine(VObj* self, Packet* result, int argc, Packet argv[]) {
    long n;

    result->type = PKT_INT;
    result->canFree = 0;
    if (argc == 2) {
        n = PkInfo2Int(&argv[1]);
    } else {
        n = 1;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.i = -1;
        result->canFree = 0;
        return 0;
    }
    int idx = GBuffIdx[bufferID];
    char* cp = GBuff[bufferID] + idx;

    for (; idx >= 0; cp--, idx--)
        if (*cp == '\n') {
            cp--;
            idx--;
            for (; idx >= 0; cp--, idx--) {
                if (*cp == '\n') {
                    if (--n <= 0) {
                        cp++;
                        idx++;
                        result->info.i = GBuffIdx[bufferID] = idx;
                        result->canFree = 0;
                        return 1;
                    }
                }
            }
            break;
        }

    result->info.i = GBuffIdx[bufferID] = 0;
    result->canFree = 0;

    return 1;
}

/*
 * GB_free(GBuffID)
 *
 * Frees buffer memory. USE WITH CARE.
 *
 * Result: 0 on success, -1 on error
 */
long meth_generic_GB_free(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    if (argc != 1) {
        /* incorrect number of arguments */
        result->info.i = -1;
        result->canFree = 0;
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.i = -1;
        result->canFree = 0;
        return 0;
    }
    if (GBuff[bufferID])
        free(GBuff[bufferID]);

    result->info.i = GBuffIdx[bufferID] = -1;
    result->canFree = 0;

    return 1;
}
/*
 * GB_herePtr(GBuffID)
 *
 * Result:  string pointer at index position
 */
long meth_generic_GB_herePtr(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_STR;
    if (argc != 1) {
        /* incorrect number of arguments */
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    result->info.s = GBuff[bufferID] + GBuffIdx[bufferID];
    result->canFree = 0;
    return 1;
}

/*
 * GB_incChar(GBuffID, n)
 *
 * Increments index by n. by 1 if n isn't given.
 *
 * Result: char at index, '\0' on error
 */
long meth_generic_GB_incChar(VObj* self, Packet* result, int argc, Packet argv[]) {
    long n;

    result->type = PKT_CHR;
    result->canFree = 0;
    if (argc == 2) {
        n = PkInfo2Int(&argv[1]);
    } else {
        n = 1;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.c = '\0';
        return 0;
    }
    GBuffIdx[bufferID] += n;
    result->info.c = GBuff[bufferID][GBuffIdx[bufferID]];
    return 1;
}

/*
 * GB_incChar1(GBuffID)
 *
 * Decrements index by 1.
 *
 * Result: char at index, '\0' on error
 */
long meth_generic_GB_incChar1(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_CHR;
    result->canFree = 0;
    if (argc != 1) {
        /* incorrect number of arguments */
        result->info.c = '\0';
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.c = '\0';
        return 0;
    }
    GBuffIdx[bufferID]++;
    result->info.c = GBuff[bufferID][GBuffIdx[bufferID]];
    return 1;
}

/*
 * GB_incLine(GBuffID, n)
 *
 * Increments index to beginning of n next line. by 1 if n isn't given.
 *
 * Result:  current index. -1 on error.
 */
long meth_generic_GB_incLine(VObj* self, Packet* result, int argc, Packet argv[]) {
    long n;

    result->type = PKT_INT;
    result->canFree = 0;
    if (argc == 2) {
        n = PkInfo2Int(&argv[1]);
    } else {
        n = 1;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.i = -1;
        result->canFree = 0;
        return 0;
    }
    int idx = GBuffIdx[bufferID];
    char* cp = GBuff[bufferID] + idx;

    for (; *cp; cp++, idx++) {
        if (*cp == '\n') {
            if (--n <= 0) {
                idx++;
                break;
            }
        }
    }
    result->info.i = idx;
    result->canFree = 0;
    GBuffIdx[bufferID] = idx;

    return 1;
}

/*
 * GB_line(GBuffID)
 *
 * Retuns current line, and advances index to next line
 *
 * Result: the line at the buffer's index (from index to next '\n')
 *         "" on error
 */
long meth_generic_GB_line(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_STR;
    if (argc != 1) {
        /* incorrect number of arguments */
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    long bufferID = PkInfo2Int(&argv[0]);

    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    int idx = GBuffIdx[bufferID];
    char* cp = GBuff[bufferID] + idx;

    /*	for (; *cp; cp++, idx++) {
                    if (*cp == '\n') {
                            idx++;
                            break;
                    }
            }
    */
    char* ccp = cp;
    while (*cp) {
        if (*cp++ == '\n') {
            break;
        }
    }
    idx += cp - ccp;

    int len = idx - GBuffIdx[bufferID];
    result->info.s = (char*)malloc(sizeof(char) * len + 1);
    result->canFree = PK_CANFREE_STR;
    strncpy(result->info.s, GBuff[bufferID] + GBuffIdx[bufferID], len);
    result->info.s[len] = '\0';
    GBuffIdx[bufferID] = idx;

    return 1;
}

/*
 * GB_moveToStart(GBufferID)
 *
 * Return: index (0) on success, -1 on failure
 */
long meth_generic_GB_moveToStart(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    if (argc != 1) {
        /* incorrect number of arguments */
        result->info.i = -1;
        result->canFree = 0;
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.i = -1;
        result->canFree = 0;
        return 0;
    }
    GBuffIdx[bufferID] = 0;
    result->info.i = 0;
    result->canFree = 0;

    return 1;
}

/*
 * GB_moveToChar(GBufferID, idx)
 *
 * Return: index on success, -1 on failure
 */
long meth_generic_GB_moveToChar(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    if (argc != 2) {
        /* incorrect number of arguments */
        result->info.i = -1;
        result->canFree = 0;
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.i = -1;
        result->canFree = 0;
        return 0;
    }
    GBuffIdx[bufferID] = (int)PkInfo2Int(&argv[1]);
    result->info.i = GBuffIdx[bufferID];
    result->canFree = 0;
    return 1;
}

/*
 * GB_moveToLine(GBufferID, idx)
 *
 * Return: index if successful, -1 if error occured
 */
long meth_generic_GB_moveToLine(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    if (argc != 2) {
        /* incorrect number of arguments */
        result->info.i = -1;
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.i = -1;
        return 0;
    }
    GBuffIdx[bufferID] = (int)PkInfo2Int(&argv[1]);
    result->info.i = GBuffIdx[bufferID];

    GBuffIdx[bufferID] = 0;
    long n = PkInfo2Int(&argv[1]);

    if (n > 0) {
        for (char* cp = GBuff[bufferID]; *cp; cp++) {
            if (*cp == '\n' || !(*cp)) {
                GBuffIdx[bufferID]++;
                if (!(*cp))
                    break;
                if (++n <= 0)
                    break;
            }
        }
    }
    return 1;
}

/*
 * GB_nthChar(GBufferID, n1, [n2])
 *
 * Result: character range from n1 to n2, "" on error
 *
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_GB_nthChar(VObj* self, Packet* result, int argc, Packet argv[]) {
    long bufferID = PkInfo2Int(&argv[0]);

    result->type = PKT_CHR;
    result->canFree = 0;
    if (argc == 2) {
        long n = PkInfo2Int(&argv[1]);
        result->info.c = GBuff[bufferID][n];
        return 1;
    } else if (argc == 3) {
        long n1 = PkInfo2Int(&argv[1]);
        long n2 = PkInfo2Int(&argv[2]);
        char* str = GBuff[bufferID];
        char* cp = (char*)malloc(sizeof(char) * (n2 - n1 + 2));
        if (!cp) {
            result->info.s = "";
            result->canFree = 0;
            return 0;
        }
        int i;
        for (i = 0; n1 <= n2; n1++) {
            if (!str[n1])
                break;
            cp[i++] = str[n1];
        }
        cp[i] = '\0';
        result->info.s = cp;
        result->canFree = PK_CANFREE_STR;
        return 1;
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

/*
 * GB_nthLine(bufferID, n1 [,n2])
 *
 * Extracts the specified lines (from line n1 to n2) from the specified
 * global buffer
 *
 * Line numbering start from 0.
 *
 * Result: the specified line(s), "" on error
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_GB_nthLine(VObj* self, Packet* result, int argc, Packet argv[]) {
    long bufferID = PkInfo2Int(&argv[0]);

    result->type = PKT_STR;
    if (bufferID >= numOfGBuffs) {
        /* unknown buffer */
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    char* str = GBuff[bufferID];

    long li, hi;
    if (argc == 2) {
        li = hi = PkInfo2Int(&argv[1]);
    } else if (argc == 3) {
        li = PkInfo2Int(&argv[1]);
        hi = PkInfo2Int(&argv[2]);
    } else {
        /* incorrect number of arguments */
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    long size;
    char* cp = getLines(li, hi, str, &size);
    if (cp) {
        result->info.s = cp;
        result->canFree = PK_CANFREE_STR;
        return 1;
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

/*
 * GB_set(GBuffID, data)
 *
 * Sets global buffer as string!
 *
 * Result: GBufffID. -1 on error
 */
long meth_generic_GB_set(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    if (argc != 2) {
        /* incorrect number of arguments */
        result->info.i = -1;
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);

    if (bufferID > NUM_OF_GBUFFS) {
        fprintf(stderr, "Error: Trying to set GBuff[%d]. There's only %d Global Buffers.\n",
                NUM_OF_GBUFFS, NUM_OF_GBUFFS);
        result->info.i = -1;
        return 0;
    }
    numOfGBuffs++;
    GBuff[bufferID] = PkInfo2Str(&argv[1]);
    GBuffIdx[bufferID] = 0;
    result->info.i = bufferID;
    return 1;
}

/*
 * GB_setCopy(GBuffID, data)
 *
 * Sets global buffer as string (the malloc'ed copy)!
 *
 * Result: GBufffID. -1 on error
 */
long meth_generic_GB_setCopy(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    if (argc != 2) {
        /* incorrect number of arguments */
        result->info.i = -1;
        return 0;
    }
    long bufferID = PkInfo2Int(&argv[0]);

    if (bufferID > NUM_OF_GBUFFS) {
        fprintf(stderr, "Error: Trying to set GBuff[%d]. There's only %d Global Buffers.\n",
                NUM_OF_GBUFFS, NUM_OF_GBUFFS);
        result->info.i = -1;
        return 0;
    }
    numOfGBuffs++;
    GBuff[bufferID] = SaveString(PkInfo2Str(&argv[1]));
    GBuffIdx[bufferID] = 0;
    result->info.i = bufferID;
    return 1;
}

long meth_generic_HTTPCanonicalURL(VObj* self, Packet* result, int argc, Packet argv[]) {
    return 1;
}

/*
 * HTTPCurrentDocAddr()
 */
long meth_generic_HTTPCurrentDocAddr(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern char* current_addr;    /* from html.c */
    extern char* default_default; /* from html.c */

    char* parsed_addr = HTParse(current_addr, current_addr, PARSE_ALL);
    result->info.s = saveString(parsed_addr);
    free(parsed_addr);  /* Free the result from HTParse */
    result->type = PKT_STR;
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * HTTPCurrentDocAddrParsed([addr], [relative])
 * RENAME TO : HTTPParseDocAddr([addr], [relative])?
 *
 * Returns: 	[0] 	access scheme
 *		[1]	host
 *		[2]	path (not including file name)
 *		[3]	file
 *		[4]	anchor
 */
long meth_generic_HTTPCurrentDocAddrParsed(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern char* current_addr;    /* from html.c */
    extern char* default_default; /* from html.c */
    
    char *addr, *relative;

    if (argc >= 1)
        addr = PkInfo2Str(&argv[0]);
    else
        addr = current_addr;

    if (argc >= 2)
        relative = PkInfo2Str(&argv[1]);
    else
        relative = current_addr;

    if (!addr) {
        fprintf(stderr, "meth_generic_HTTPCurrentDocAddrParsed: addr == NULL\n");
        clearPacket(result);
        return 0;
    }

    Packet* packet0 = makePacket(); /* access */
    Packet* packet1 = makePacket(); /* host */
    Packet* packet2 = makePacket(); /* path (not including file name) */
    Packet* packet3 = makePacket(); /* file */
    Packet* packet4 = makePacket(); /* anchor */

    packet0->canFree = packet1->canFree = packet2->canFree = packet3->canFree = packet4->canFree =
        PK_CANFREE_STR;

    packet0->type = packet1->type = packet2->type = packet3->type = packet4->type = PKT_STR;

    char* parsed_access = HTParse(addr, relative, PARSE_ACCESS);
    char* parsed_host = HTParse(addr, relative, PARSE_HOST);
    packet0->info.s = saveString(parsed_access);
    packet1->info.s = saveString(parsed_host);
    free(parsed_access);  /* Free the result from HTParse */
    free(parsed_host);    /* Free the result from HTParse */
    char* path = HTParse(addr, relative, PARSE_PATH | PARSE_PUNCTUATION);

    for (size_t i = strlen(path); i-- > 0; ) {
        if (path[i] == '/') {
            strncpy(buff, path, i + 1);
            buff[i + 1] = '\0';
            packet2->info.s = saveString(buff);
            packet3->info.s = saveString(path + i + 1);
            goto lameLoopEsc;
        }
    }
    packet2->info.s = saveString("");
    packet3->info.s = saveString(path);
lameLoopEsc:

    char* anchor = HTParse(addr, relative, PARSE_ANCHOR);
    packet4->info.s = (anchor ? saveString(anchor) : saveString(""));

    Attr* attrp;
    result->type = PKT_ATR;
    result->info.a = attrp = makeAttr(0, (intptr_t)packet0);
    result->canFree = 0;
    attrp->next = makeAttr(1, (intptr_t)packet1);
    attrp->next->next = makeAttr(2, (intptr_t)packet2);
    attrp->next->next->next = makeAttr(3, (intptr_t)packet3);
    attrp->next->next->next->next = makeAttr(4, (intptr_t)packet4);

    return 1;
}

/*
 * HTTPCurrentDocAddrSet()
 * 
 * Security: Untrusted objects cannot set current_addr to a local path.
 * This prevents privilege escalation via loadObjFile spoofing.
 */
long meth_generic_HTTPCurrentDocAddrSet(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern char* current_addr; /* from html.c */
    char* newAddr;

    clearPacket(result);
    newAddr = PkInfo2Str(argv);
    
    /* Security check: untrusted object setting local address requires confirmation */
    if (self && GET_security(self) > 0 && newAddr && isLocalAddress(newAddr)) {
        if (notSecureWithPromptf(self, "set document address to local path: %s", newAddr)) {
            return 0;
        }
    }
    
    if (current_addr)
        free(current_addr);
    current_addr = saveString(newAddr);
    return 1;
}

/*
 * HTTPDecode()
 *
 */
long meth_generic_HTTPDecodeURL(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->info.s = decodeURL(PkInfo2Str(&argv[0]));
    result->canFree = PK_CANFREE_STR;
    result->type = PKT_STR;
    return 1;
}

/*
 * HTTPEncodeURL()
 *
 */
long meth_generic_HTTPEncodeURL(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->info.s = encodeURL(PkInfo2Str(&argv[0]));
    result->canFree = PK_CANFREE_STR;
    result->type = PKT_STR;
    return 1;
}

/*
 * Base64DecodeToFile(base64_data, extension)
 *
 * Decodes Base64 encoded data and writes it to a temp file with specified extension.
 * Handles binary data correctly (with null bytes).
 * Extension is optional and defaults to empty if not provided.
 *
 * Security: filename is generated internally, caller cannot specify arbitrary path.
 *
 * Result: path to temp file on success, "" on error
 */
long meth_generic_Base64DecodeToFile(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* base64_data;
    char* extension = NULL;
    char* filename;
    unsigned char* decoded_data;
    int decoded_len;
    size_t input_len;
    FILE* fp;

    clearPacket(result);
    result->type = PKT_STR;
    result->canFree = 0;
    result->info.s = "";

    if (argc < 1) {
        return 0;
    }

    base64_data = PkInfo2Str(&argv[0]);

    if (!base64_data) {
        return 0;
    }

    if (argc >= 2) {
        extension = PkInfo2Str(&argv[1]);
    }

    /* Skip leading whitespace (including newlines) */
    while (*base64_data && (*base64_data == ' ' || *base64_data == '\t' || 
           *base64_data == '\n' || *base64_data == '\r')) {
        base64_data++;
    }

    input_len = strlen(base64_data);
    if (input_len == 0) {
        return 0;
    }

    /* Create secure temp file with specified extension */
    filename = sys_make_temp_file(extension);
    if (!filename) {
        return 0;
    }

    /* Allocate buffer for decoded data (decoded is always smaller than encoded) */
    decoded_data = (unsigned char*)malloc(input_len + 1);
    if (!decoded_data) {
        unlink(filename);
        free(filename);
        return 0;
    }

    /* Decode Base64 */
    decoded_len = HTUU_decode(base64_data, decoded_data, input_len);

    if (decoded_len <= 0) {
        free(decoded_data);
        unlink(filename);
        free(filename);
        return 0;
    }

    /* Write binary data to file (file already created by mkstemps) */
    fp = fopen(filename, "wb");
    if (!fp) {
        free(decoded_data);
        unlink(filename);
        free(filename);
        return 0;
    }

    if (fwrite(decoded_data, 1, decoded_len, fp) != (size_t)decoded_len) {
        fclose(fp);
        free(decoded_data);
        unlink(filename);
        free(filename);
        return 0;
    }

    fclose(fp);
    free(decoded_data);

    /* filename is already allocated by saveString in sys_make_temp_file */
    result->info.s = filename;
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * HTTPGet()
 *
 * it's user's responsibility to remove the temporary file after usage.
 *
 * Result: name of file containing the data
 *
 */
long meth_generic_HTTPGet(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* HTTPGet is the core of browser functionality - must be allowed for all objects.
     * Security is enforced on what the loaded content can DO (system, pipe, etc),
     * not on loading content itself.
     */
    char* src = PkInfo2Str(&argv[0]);

    /* Safety check: validate src */
    if (!src || (unsigned long)src < 0x1000) {
        fprintf(stderr, "ERROR: Invalid src pointer in HTTPGet: %p\n", src);
        clearPacket(result);
        return 0;
    }

    /* Find extension from URL - scan backwards for '.' before '/' */
    const char* ext = NULL;
    size_t len = strlen(src);
    for (const char* p = src + len; p >= src; p--) {
        if (*p == '.') {
            ext = p; /* Found extension (e.g., ".html") */
            break;
        }
        if (*p == '/') {
            break; /* Hit path separator, no extension */
        }
    }

    /* Create secure temp file with extension */
    char* tfn = sys_make_temp_file(ext);
    if (!tfn) {
        fprintf(stderr, "ERROR: Failed to create temporary file\n");
        clearPacket(result);
        return 0;
    }

    FILE* fp = fopen(tfn, "w");
    if (fp) {
        char *simpleAddress, *anchorSearch;
        if (html_fetchDocument(self, src, &simpleAddress, &anchorSearch, fp)) {
            fclose(fp);
            result->canFree = PK_CANFREE_STR;
            result->info.s = tfn;
            result->type = PKT_STR;
            return 1;
        }
        fclose(fp);
    } else {
        fprintf(stderr, "ERROR: Failed to open temporary file %s\n", tfn);
    }
    
    unlink(tfn);
    free(tfn);
    clearPacket(result);
    return 0;
}

long int helper_buildingHTML(Packet* result, VObj* obj, char* url, long width, int method,
                             char* dataToPost) {
    /*	struct timeval time1, time2;*/
    clearPacket(result);

    /*	gettimeofday(&time1, (struct timezone*)NULL);*/

    if (notSecureWithPromptf(obj, "build HTML document: %s", url ? url : "(null)"))
        return 0;

    char *simpleAddress, *anchorSearch;
    VObj* newObj =
        html2_parseHTMLDocument(obj, url, &simpleAddress, &anchorSearch, width, method, dataToPost);
    /*
            gettimeofday(&time2, (struct timezone*)NULL);
            printf("**** duration=%d secs to for %s\n",
                    time2.tv_sec - time1.tv_sec, url);
    */

    result->info.o = newObj;
    result->canFree = 0;
    result->type = PKT_OBJ;
    return 1;
}

/*
 * HTTPGetNParse(url, parentForBuiltObjs, width)
 *
 * it's user's responsibility to remove the temporary file after usage.
 *
 * Result: name of file containing the data
 *
 */
long meth_generic_HTTPGetNParse(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* Core browser functionality - allowed for all objects */
    return helper_buildingHTML(result, PkInfo2Obj(&argv[1]), PkInfo2Str(&argv[0]),
                               PkInfo2Int(&argv[2]), HTTP_METHOD_GET, NULL);
}

/*
 * HTTPPost(url, parentForBuiltObjs, width, post-data)
 */
long meth_generic_HTTPPost(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* Core browser functionality - allowed for all objects */
    return helper_buildingHTML(result, PkInfo2Obj(&argv[1]), PkInfo2Str(&argv[0]),
                               PkInfo2Int(&argv[2]), HTTP_METHOD_POST, PkInfo2Str(&argv[3]));
}

/* XXX NOT YET WORKING */
/*
 * HTTPPost(url, parentForBuiltObjs, width, post-data)
 */
long meth_generic_HTTPSubmit(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* Core browser functionality - allowed for all objects */
    return helper_buildingHTML(result, PkInfo2Obj(&argv[1]), PkInfo2Str(&argv[0]),
                               PkInfo2Int(&argv[2]), HTTP_METHOD_SUBMIT, PkInfo2Str(&argv[3]));
}

long meth_generic_HTTPHotListAdd(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* url, comment, date */
    if (notSecureWithPromptf(self, "add to hotlist: %s", PkInfo2Str(&argv[0])))
        return 0;
    return addHotListItem(saveString(PkInfo2Str(&argv[0])), saveString(PkInfo2Str(&argv[1])),
                          saveString(PkInfo2Str(&argv[2])));
}

long meth_generic_HTTPHotListDelete(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPromptf(self, "delete from hotlist: item #%ld", PkInfo2Int(&argv[0])))
        return 0;
    return deleteHotListItem(PkInfo2Int(&argv[0]));
}

/* arg[0]	0	returns URL
 * arg[0]	1	returns Comment
 * arg[0]	2	returns all URLs in one big string
 * arg[0]	3	returns all Comments in one big string
 * arg[1]	n	nth item in the hotlist
 */
long meth_generic_HTTPHotListGet(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPrompt(self, "read hotlist"))
        return 0;

    HotListItem* hip;
    switch (PkInfo2Int(&argv[0])) {
    case 0:
        hip = getNthHotListItem(PkInfo2Int(&argv[1]));
        if (!hip)
            return 0;
        if (!hip->url)
            return 0;
        result->info.s = hip->url;
        break;
    case 1:
        hip = getNthHotListItem(PkInfo2Int(&argv[1]));
        if (!hip)
            return 0;
        if (!hip->comment)
            return 0;
        result->info.s = hip->comment;
        break;
    case 2:
        result->info.s = dumpHotList(0);
        break;
    case 3:
        result->info.s = dumpHotList(1);
        break;
    default:
        clearPacket(result);
        return 0;
    }
    result->type = PKT_STR;
    result->canFree = 0;

    return 1;
}

/* arg[0]	0	change URL
 * arg[0]	1	change Comment
 * arg[1]	n	nth item in the hotlist
 * arg[2]	str	new data
 */
long meth_generic_HTTPHotListChange(VObj* self, Packet* result, int argc, Packet argv[]) {
    HotListItem* hip;

    if (notSecureWithPrompt(self, "modify hotlist entry"))
        return 0;

    switch (PkInfo2Int(&argv[0])) {
    case 0: /* change url */
        hip = getNthHotListItem(PkInfo2Int(&argv[1]));
        if (!hip)
            return 0;
        if (!hip->url)
            return 0;
        free(hip->url);
        hip->url = saveString(PkInfo2Str(&argv[2]));
        break;
    case 1: /* change comment */
        hip = getNthHotListItem(PkInfo2Int(&argv[1]));
        if (!hip)
            return 0;
        if (!hip->comment)
            return 0;
        free(hip->comment);
        hip->comment = saveString(PkInfo2Str(&argv[2]));
        break;
    default:
        return 0;
    }
    return 1;
}

long meth_generic_HTTPHotListLoad(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPrompt(self, "load hotlist from file"))
        return 0;
    clearPacket(result);
    result->info.i = initHotList();
    result->type = PKT_INT;
    return 0;
}

long meth_generic_HTTPHotListSave(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPrompt(self, "save hotlist to file"))
        return 0;
    return saveHotList();
}

/*
 * SGMLBuildDoc(url, parent, name, width)
 *
 * Result: document object
 */
long meth_generic_SGMLBuildDoc(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj* newObj;

    if (notSecureWithPrompt(self, "build SGML document"))
        return 0;
    if (argc != 6) {
        /* incorrect number of arguments */
        result->type = PKT_OBJ;
        result->canFree = 0;
        result->info.o = NULL;
        return 0;
    }
    newObj = SGMLBuildDoc(PkInfo2Str(&argv[0]),  /* source */
                          PkInfo2Str(&argv[1]),  /* URL */
                          PkInfo2Obj(&argv[2]),  /* parent */
                          PkInfo2Str(&argv[3]),  /* name */
                          PkInfo2Int(&argv[4]),  /* width */
                          PkInfo2Str(&argv[5])); /* anchor */
    result->info.o = newObj;
    result->type = PKT_OBJ;
    result->canFree = 0;
    return 1;
}

/*
 * SGMLBuildDocB(url, parent, name, width)
 *
 * Result: document object
 */
long meth_generic_SGMLBuildDocB(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj* newObj;

    if (notSecureWithPrompt(self, "build SGML document"))
        return 0;
    if (argc != 6) {
        /* incorrect number of arguments */
        result->type = PKT_OBJ;
        result->canFree = 0;
        result->info.o = NULL;
        return 0;
    }
    newObj = SGMLBuildDoc_B(PkInfo2Str(&argv[0]),  /* source */
                            PkInfo2Str(&argv[1]),  /* URL */
                            PkInfo2Obj(&argv[2]),  /* parent */
                            PkInfo2Str(&argv[3]),  /* name */
                            PkInfo2Int(&argv[4]),  /* width */
                            PkInfo2Str(&argv[5])); /* anchor */
    result->info.o = newObj;
    result->type = PKT_OBJ;
    result->canFree = 0;
    return 1;
}

/*
 * SGMLBuildDoc_setBuff()
 */
long meth_generic_SGMLBuildDoc_setBuff(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* SGML buffer is internal parser operation - not dangerous */
    clearPacket(result);
    result->info.i = SGMLBuildDoc_setBuff(self, PkInfo2Int(&argv[0]));
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 * SGMLBuildDoc_setColors()
 * equivalent to:

       color = getResource("Viola.background_doc");
       if (color) set("BGColor", color);
       color = getResource("Viola.foreground_doc");
       if (color) set("FGColor", color);
 */
long meth_generic_SGMLBuildDoc_setColors(VObj* self, Packet* result, int argc, Packet argv[]) {
    static Packet largv[2];
    static char* BG_DOC;
    static char* FG_DOC;
    static int init = 0;
    long (*setFunc)(VObj*, Packet*, int, Packet*, long) = GET__classInfo(self)->slotSetMeth;

    if (!init) {
        BG_DOC = GLGetResource("Viola.background_doc");
        if (BG_DOC)
            BG_DOC = saveString(BG_DOC);
        FG_DOC = GLGetResource("Viola.foreground_doc");
        if (FG_DOC)
            FG_DOC = saveString(FG_DOC);
        largv[1].type = PKT_STR;
        largv[1].canFree = 0;
        init = 1;
    }
    if (BG_DOC) {
        largv[1].info.s = BG_DOC;
        setFunc(self, result, 2, largv, STR_BGColor);
    }
    if (FG_DOC) {
        largv[1].info.s = FG_DOC;
        setFunc(self, result, 2, largv, STR_FGColor);
    }
    return 1;
}

long meth_generic_SGMLBuildDoc_span(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern int SGMLBuildDoc_span;

    clearPacket(result);
    result->info.i = SGMLBuildDoc_span;
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

long meth_generic_SGMLBuildDoc_flush(VObj* self, Packet* result, int argc, Packet argv[]) {
    SGMLBuildDoc_flush();
    clearPacket(result);
    return 1;
}

long meth_generic_SGMLBuildDoc_enterChanged(VObj* self, Packet* result, int argc, Packet argv[]) {
    SGMLBuildDoc_enterChanged();
    clearPacket(result);
    return 1;
}

long meth_generic_SGMLBuildDoc_leaveChanged(VObj* self, Packet* result, int argc, Packet argv[]) {
    SGMLBuildDoc_leaveChanged();
    clearPacket(result);
    return 1;
}

long meth_generic_SGMLBuildDoc_insertObj(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc == 1) {
        SGMLBuildDoc_insertObj(PkInfo2Obj(&argv[0]), -1);
    } else if (argc == 2) {
        SGMLBuildDoc_insertObj(PkInfo2Obj(&argv[0]), PkInfo2Int(&argv[1]));
    }
    result->info.i = 1;
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 * SGMLFindAnchorOffset(width)
 *
 * Result: vspan
 */
long meth_generic_SGMLFindAnchorOffset(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    if (argc != 1) {
        /* incorrect number of arguments */
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = 0;
        return 0;
    }
    result->info.i = SGMLFindAnchorOffset(self, PkInfo2Str(&argv[0]));
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

long meth_generic_SGMLMathFormater(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc == 3) {
        return HTMLMathFormater(self, &argv[0], &argv[1], (int)PkInfo2Int(&argv[2]));
    }
    return 0;
}

long meth_generic_HTMLMathUpdateWindow(VObj* self, Packet* result, int argc, Packet argv[]) {
    return HTMLMathUpdateWindow(self);
}

/*
 * SGMLReBuildDoc(url, parent, name, width)
 *
 * Result: document object
 */
long meth_generic_SGMLReBuildDoc(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPrompt(self, "rebuild SGML document"))
        return 0;
    if (argc != 6) {
        /* incorrect number of arguments */
        result->type = PKT_OBJ;
        result->canFree = 0;
        result->info.o = NULL;
        return 0;
    }
    result->info.o = SGMLBuildDoc_B(PkInfo2Str(&argv[0]),  /* source */
                                    PkInfo2Str(&argv[1]),  /* URL */
                                    PkInfo2Obj(&argv[2]),  /* parent */
                                    PkInfo2Str(&argv[3]),  /* name */
                                    PkInfo2Int(&argv[4]),  /* width */
                                    PkInfo2Str(&argv[5])); /* anchor */
    result->type = PKT_OBJ;
    result->canFree = 0;
    return 1;
}

/*
 * SGMLTileDoc(width)
 *
 * Result: vspan
 */
long meth_generic_SGMLTileDoc(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc != 2) {
        /* incorrect number of arguments */
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = 0;
        return 0;
    }
    result->info.i = SGMLTileDoc(self, PkInfo2Int(&argv[0]), PkInfo2Int(&argv[1]));
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 * SGMLGetStyle(dtd, tagName, attrName)
 *
 * Result: attribute value
 */
long meth_generic_SGMLGetStyle(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc == 2)
        return getSGMLStyle(PkInfo2Str(&argv[0]), PkInfo2Str(&argv[1]), NULL, result);
    else if (argc == 3)
        return getSGMLStyle(PkInfo2Str(&argv[0]), PkInfo2Str(&argv[1]), PkInfo2Str(&argv[2]),
                            result);
    return 0;
}

long meth_generic_STGInfo(VObj* self, Packet* result, int argc, Packet argv[]) {
    return getSTGInfo(PkInfo2Str(&argv[0]), PkInfo2Str(&argv[1]), result);
}

long meth_generic_STG_tagPtr(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* superTagName = NULL;
    char* styleAttr = NULL;
    
    if (argc >= 2)
        superTagName = PkInfo2Str(&argv[1]);
    if (argc >= 3)
        styleAttr = PkInfo2Str(&argv[2]);
    
    if (styleAttr) {
        return getSTGInfo_tagPtrWithStyle(result, PkInfo2Str(&argv[0]), superTagName, styleAttr);
    } else {
        return getSTGInfo_tagPtr(result, PkInfo2Str(&argv[0]), superTagName);
    }
}

/*
 * STG_tagPtrDepth(tagName, superTagName, depth)
 *
 * Like STG_tagPtr but builds a deeper context by repeating the
 * tagName/superTagName pair `depth` times. This allows the STG engine
 * to distinguish nesting levels for nested lists.
 *
 * Example: STG_tagPtrDepth("LI", "OL", 2) builds context
 *          [LI, OL, LI, OL] which matches (OL (LI (OL (LI ...))))
 */
long meth_generic_STG_tagPtrDepth(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* tagName = PkInfo2Str(&argv[0]);
    char* superTagName = PkInfo2Str(&argv[1]);
    int depth = PkInfo2Int(&argv[2]);
    return getSTGInfo_tagPtrWithDepth(result, tagName, superTagName, depth);
}

long meth_generic_STG_attr(VObj* self, Packet* result, int argc, Packet argv[]) {
    long tagPtr = PkInfo2Int(&argv[0]);
    
    /* Always use old API - it's safe and works with STGMajor* */
    /* New API with minors is accessed through STG_attrEx separately */
    return getSTGInfo_attr((STGMajor*)tagPtr, PkInfo2Str(&argv[1]), result);
}

long meth_generic_STG_attrEx(VObj* self, Packet* result, int argc, Packet argv[]) {
    long tagPtr = PkInfo2Int(&argv[0]);
    
    /* New API - expects STGResult* from STG_tagPtr with style attribute */
    return getSTGInfo_attrFromResult(tagPtr, PkInfo2Str(&argv[1]), result);
}

long meth_generic_STG_clean(VObj* self, Packet* result, int argc, Packet argv[]) {
    return getSTGInfo_clean((STGMajor*)PkInfo2Int(&argv[0]));
}

/* NOT FULLY IMPLEMENTED
 *
 * SGMLSetStyle(dtd, tagName, attrName, value)
 *
 * Result: attribute value
 */
long meth_generic_SGMLSetStyle(VObj* self, Packet* result, int argc, Packet argv[]) {
    return setSGMLStyle(PkInfo2Str(&argv[0]), PkInfo2Str(&argv[1]), PkInfo2Str(&argv[2]), &argv[2]);
}

long meth_generic_SGMLTableFormater(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc == 2) {
        return HTMLTableFormater(self, PkInfo2Obj(&argv[0]), PkInfo2Int(&argv[1]));
    } else {
        return HTMLTableFormater(self, NULL, 0);
    }
}

/*
 * accessible(filepath)
 *
 * Determine the accessibility of a file.
 *
 * Result: full file path on success, or "" on failure
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_accessible(VObj* self, Packet* result, int argc, Packet argv[]) {
    int accessible;
    char* path;
    if (notSecureWithPromptf(self, "check file: %s", argv[0].info.s ? argv[0].info.s : "(null)"))
        return 0;
    result->type = PKT_STR;
    if ((path = SaveString(vl_expandPath(argv[0].info.s, buff)))) {
        accessible = access(path, R_OK);
        if ((accessible & R_OK) == 0) {
            result->info.s = path;
            result->canFree = PK_CANFREE_STR;
            return 1;
        }
        free(path);
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

/* send message to VW motif active help field
 */
long meth_generic_activeHelp(VObj* self, Packet* result, int argc, Packet argv[]) {
#define VW
#ifdef VW
    extern void showHelpMessageInMainWindow(char* message);
    extern void blankHelpHandlerInMainWindow(void);
    char* str;

    if (argc == 0) {
        blankHelpHandlerInMainWindow();
    } else {
        showHelpMessageInMainWindow(PkInfo2Str(&argv[0]));
    }
#endif
    return 1;
}

/*
 * after(milliseconds, object, [message list])
 *
 * Schedule to send messages to an object after a period of time.
 *
 * Result/Return: 1 if successful, 0 if error occured
 */
long meth_generic_after(VObj* self, Packet* result, int argc, Packet argv[]) {
    long msec;
    VObj* obj;
    Packet* messages;
    int i, j, size;

    result->type = PKT_INT;
    result->canFree = 0;

    msec = PkInfo2Int(&argv[0]);
    obj = PkInfo2Obj(&argv[1]);

    if (!msec || !obj) {
        result->info.i = 0;
        return 0;
    }

    size = sizeof(struct Packet) * (argc - 2);
    messages = (Packet*)malloc(size);
    if (!messages)
        return 0;

    for (i = 0, j = 2; j < argc; j++, i++) {
        nullPacket(&messages[i]);
        copyPacket(&messages[i], &argv[j]);
    }

    /* it's event loop's responsibility to free the message list */

    if (scheduleEvent(msec, sendMessagePackets, obj, argc - 2, messages)) {
        result->info.i = 1;
        return 1;
    }
    result->info.i = 1;
    return 0;
}

/*
 * append(<list>, id, value)
 *
 * Append item to list
 *
 * Result:
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_append(VObj* self, Packet* result, int argc, Packet argv[]) {
#ifdef NOTYET
    attrp = NULL;
    for (attrp2 = packetp->info.a; attrp2; attrp2 = attrp2->next) {
        if (attrp2->id == i) {
            attrp = attrp2;
            break;
        }
    }
    if (!attrp) {
        /* make the new list node */
        attrp = makeAttr(i, (intptr_t)makePacket());
        prependAttr(&(packetp->info.a), attrp);
    }
    packetp = (Packet*)attrp->val;
    copyPacket(&reg1, &execStack[stackExecIdx]);
    clearPacket(&execStack[stackExecIdx]);
    --stackExecIdx;
    copyPacket(packetp, &reg1);
#endif
    return 0;
}

/*
 * argument();
 *
 * Return the string following the -ar option.
 *
 * Result: version string
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_argument(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern char* passthru_argument; /* defined in cexec.c */
    result->info.s = passthru_argument ? passthru_argument : "";
    result->type = PKT_STR;
    result->canFree = 0;
    return 1;
}

/*
 * ascii(ASCII code)
 *
 * Result: corresponding ASCII character
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_ascii(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_CHR;
    result->canFree = 0;
    result->info.c = (char)argv[0].info.i;
    return 1;
}

/*
 * asciiVal(ASCII character)
 *
 * Result: corresponding ASCII code
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_asciiVal(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = (int)argv[0].info.c;
    return 1;
}

/*
 * intToRoman(n)
 *
 * Converts an integer to a Roman numeral string.
 * Values 1-3999 produce standard subtractive notation (I, IV, IX, XL, etc.).
 * Out-of-range values are returned as decimal strings.
 *
 * Result: string (e.g. "I", "IV", "XIV", "XLII")
 * Return: 1 if successful, 0 if error occured
 *
 * Defined in: Stylesheet RFC, Oct 23 1993 (numStyle=roman)
 */
long meth_generic_intToRoman(VObj* self, Packet* result, int argc, Packet argv[]) {
    static const int values[]    = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static const char *symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int n;
    int i;
    char tempBuf[32];
    char *p;

    result->type = PKT_STR;
    n = PkInfo2Int(&argv[0]);

    if (n < 1 || n > 3999) {
        /* Out of range for Roman numerals: return as decimal */
        sprintf(tempBuf, "%d", n);
        result->info.s = SaveString(tempBuf);
        result->canFree = PK_CANFREE_STR;
        return 1;
    }

    p = tempBuf;
    for (i = 0; i < 13; i++) {
        while (n >= values[i]) {
            const char *s = symbols[i];
            while (*s) *p++ = *s++;
            n -= values[i];
        }
    }
    *p = '\0';

    result->info.s = SaveString(tempBuf);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * intToAlpha(n)
 *
 * Converts an integer to a lowercase alphabetic string.
 * 1->"a", 2->"b", ..., 26->"z", 27->"aa", 28->"ab", etc.
 *
 * Result: string (e.g. "a", "b", "z", "aa", "ab")
 * Return: 1 if successful, 0 if error occured
 *
 * Defined in: Stylesheet RFC, Oct 23 1993 (numStyle=alpha)
 */
long meth_generic_intToAlpha(VObj* self, Packet* result, int argc, Packet argv[]) {
    int n;
    char tempBuf[16];
    char revBuf[16];
    int len = 0;
    int i;

    result->type = PKT_STR;
    n = PkInfo2Int(&argv[0]);

    if (n < 1) {
        sprintf(tempBuf, "%d", n);
        result->info.s = SaveString(tempBuf);
        result->canFree = PK_CANFREE_STR;
        return 1;
    }

    /* Build the string in reverse: n=1->"a", n=27->"aa", n=28->"ab" */
    while (n > 0) {
        n--;  /* make 0-based */
        revBuf[len++] = 'a' + (n % 26);
        n /= 26;
    }

    /* Reverse into tempBuf */
    for (i = 0; i < len; i++) {
        tempBuf[i] = revBuf[len - 1 - i];
    }
    tempBuf[len] = '\0';

    result->info.s = SaveString(tempBuf);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * bell();
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_bell(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    SLBell();
    return 1;
}

/*
 * bellVolume(0-100);
 *
 * Result: volume value
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_bellVolume(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = SLBellVolume(PkInfo2Int(argv));
    return 1;
}

/*
 * discoverySetPage(<url>)
 *
 * Notify peer discovery service of current page URL.
 * Used for detecting when multiple browsers view the same page.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_discoverySetPage(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* url;
    
    clearPacket(result);
    if (argc < 1) return 0;
    
    url = PkInfo2Str(&argv[0]);
    if (url && *url) {
        discovery_set_page(url);
    }
    return 1;
}

/*
 * discoveryEnable()
 * Enable peer discovery for the current page (called when SC attribute is found)
 */
long meth_generic_discoveryEnable(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    discovery_enable();
    return 1;
}

/*
 * discoveryReset()
 * Reset discovery enabled flag (called at start of new page load)
 */
long meth_generic_discoveryReset(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    discovery_reset();
    return 1;
}

/*
 * discoveryBroadcast(id, func, arg1, arg2, ...)
 * Broadcast a sync message to peers viewing the same page
 */
long meth_generic_discoveryBroadcast(VObj* self, Packet* result, int argc, Packet argv[]) {
    char args_buf[256] = "";
    char* id;
    char* func;
    int i;
    
    clearPacket(result);
    /* Discovery broadcast is internal ViolaWWW sync - not dangerous */
    
    if (argc < 2) return 0;
    
    id = PkInfo2Str(&argv[0]);
    func = PkInfo2Str(&argv[1]);
    
    /* Build pipe-separated args string */
    for (i = 2; i < argc && i < 8; i++) {
        if (i > 2) strcat(args_buf, "|");
        strcat(args_buf, PkInfo2Str(&argv[i]));
    }
    
    discovery_broadcast(id, func, args_buf);
    return 1;
}

/*
 * discoveryIsRemote()
 * Returns 1 if currently processing a remote sync message, 0 otherwise
 */
long meth_generic_discoveryIsRemote(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->type = PKT_INT;
    result->info.i = discovery_is_remote();
    result->canFree = 0;
    return 1;
}

/*
 * char(<ASCII value>)
 */
long meth_generic_char(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_CHR;
    result->info.c = (char)PkInfos2Str(argc, argv)[0];
    result->canFree = 0;
    return 1;
}

/*
 * charHeight(fontID)
 * Returns the maximum height of the specified font.
 */
long meth_generic_charHeight(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.i = FontMaxHeight(PkInfo2Int(&argv[0]));
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 * XXX
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_clear(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

/*
 * cli();
 *
 * Invoke Command Line Interface to Viola language interpreter
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_cli(VObj* self, Packet* result, int argc, Packet argv[]) {
#define LINE_LENGTH 300
    int c;
    char cmdLine[LINE_LENGTH];
    int i, balance, finish = 0;

    if (notSecureWithPrompt(self, "command line interface"))
        return 0;

    do {

        if (flag_cliprompt)
            printf("<%s>: ", GET_name(VCurrentObj));
        i = 0;
        balance = 0;

        for (;;) {
            c = getchar();
            if (i < LINE_LENGTH - 1) {
                cmdLine[i++] = (char)c;
            }
            if (c == ';' && (balance == 0)) {
                cmdLine[i] = '\0';
                break;
            } else if (c == '{' || c == '(') {
                balance++;
            } else if (c == '}' || c == ')') {
                balance--;
            } else if (c == EOF) {
                cmdLine[--i] = '\0';
                finish = 1;
                break;
            }
        }
        /*		printf(">>>%s<<<\n", cmdLine);*/

        if (!AllBlank(cmdLine)) {
            result = execScript(VCurrentObj, result, cmdLine);

            if (flag_cliprompt && result) {
                dumpPacket(result);
                printf("\n");
            }
        }
    } while (!finish);

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
long meth_generic_clone(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj* cloneObj;

    if (!meth_generic_clone2(self, result, argc, argv))
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

long meth_generic_clone2(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj *cloneObj, *obj;
    VObjList *olist, *newolist;
    union PCode* pcode;
    size_t size;  /* Changed from int to size_t for 64-bit safety */

    if (!meth_cosmic_clone2(self, result, argc, argv))
        return 0;
    cloneObj = result->info.o;

    /* Note: clone() now sets all OBJL slots to NULL, so _children is already NULL */

    newolist = NULL;
    olist = GET__children(self);
    if (olist) {
        Packet lresult;

        nullPacket(&lresult);
        for (; olist; olist = olist->next) {
            if (!olist->o) {
                continue;
            }
            /* Check if child object is still valid before cloning.
             * Objects may have been freed if clone windows were closed. */
            if (!validObjectP(olist->o)) {
                /* Try to get info about unregistered object - be careful with memory */
                VObj* childObj = olist->o;
                ClassInfo* cip = GET__classInfo(childObj);
                if (cip) {
                    /* Object exists but wasn't registered - might be a template */
                    fprintf(stderr, "clone: child object %p NOT REGISTERED (class=%s, name=%s) - skipping\n",
                            (void*)childObj,
                            GET_class(childObj) ? GET_class(childObj) : "(null)",
                            GET_name(childObj) ? GET_name(childObj) : "(null)");
                } else {
                    /* Object was freed (classInfo is NULL) */
                    fprintf(stderr, "clone: child object %p WAS FREED - skipping\n", (void*)childObj);
                }
                continue;
            }
            if (!callMeth(olist->o, &lresult, argc, argv, STR_clone2)) {
                fprintf(stderr, "clone (at children cloning) failed for %s\n", 
                        GET_name(olist->o) ? GET_name(olist->o) : "(null)");

                clearPacket(&lresult);
                return 0;
            }
            /* CRITICAL: Verify clone2 returned a different object, not the original */
            if (lresult.info.o == olist->o) {
                fprintf(stderr, "clone2 returned original object instead of clone for %s (class %s)\n",
                        GET_name(olist->o) ? GET_name(olist->o) : "(null)",
                        GET_class(olist->o) ? GET_class(olist->o) : "(null)");
                /* Skip this object - don't add original to clone's children */
                continue;
            }
            if (!lresult.info.o) {
                fprintf(stderr, "clone2 returned NULL for %s\n",
                        GET_name(olist->o) ? GET_name(olist->o) : "(null)");
                continue;
            }
            newolist = appendObjToList(newolist, lresult.info.o);
            SET__parent(lresult.info.o, cloneObj);
            SET_parent(lresult.info.o, VSaveString(GET__memoryGroup(lresult.info.o), GET_name(cloneObj)));
        }
        clearPacket(&lresult);
        SET_children(cloneObj, VSaveString(GET__memoryGroup(cloneObj), OListToStr(newolist)));
    } else {
        SET_children(cloneObj, VSaveString(GET__memoryGroup(cloneObj), ""));
    }
    SET__children(cloneObj, newolist);

    SET__varList(cloneObj, NULL);

    GET_script(self)->refc++;
    SET_script(cloneObj, GET_script(self));

    pcode = GET__script(self);
    if (pcode) {
        pcode[PCODE_IDX_REFC].i++;
        size = sizeof(union PCode) * (pcode[PCODE_IDX_INSTR].i + pcode[PCODE_IDX_SIZE].i);
        SET__script(cloneObj, pcode);
    }

    SET__argAttr(cloneObj, NULL);
    if (!makeArgAttr(cloneObj)) {
        fprintf(stderr, "makeArgAttr() failed\n");
    }

    SET__scriptVV(cloneObj, NULL);
    SET__classScriptVV(cloneObj, NULL);
    SET__tempScriptVV(cloneObj, NULL);

    result->type = PKT_OBJ;
    result->canFree = 0;
    result->info.o = cloneObj;

    return 1;
}

/* change to: collapseSpaces
 */
long meth_generic_compressSpaces(VObj* self, Packet* result, int argc, Packet argv[]) {
    char c, *src, *e, *p1, *p2, *p3;

    freePossibleDangler(result);
    src = PkInfo2Str(&argv[0]);
    e = p1 = src;
    for (;;) {
        if (*p1 == '\0') {
            goto done;

        } else if (isspace((unsigned char)*p1)) {
            p2 = p1;
            while (c = *p2, isspace((unsigned char)c) && (c != '\0'))
                p2++;
            if (*p2 == '\0')
                goto done;

            for (p3 = p2;; p3++) {
                if (*p3 == '\0')
                    break;
                if (c = *p3, isspace((unsigned char)c)) {
                    if (isspace((unsigned char)*(p3 + 1)) && *(p3 + 1) != '\0') {
                        p3 = p3 + 1;
                        break;
                    }
                }
            }
            while (p2 < p3)
                *e++ = *p2++;
            if (!*p3)
                goto done;
            p1 = p3;

        } else {
            for (;;) {
                if (e == p1) {
                    while (c = *p1, !isspace((unsigned char)c) && (c != '\0'))
                        ++p1;
                    e = p1;
                } else {
                    while (c = *p1, !isspace((unsigned char)c) && (*p1 != '\0'))
                        *e++ = *p1++;
                }
                if (*p1 == '\0')
                    goto done;
                if (*(p1 + 1) == '\0')
                    goto done;
                *e++ = *p1++;
                if (isspace((unsigned char)*p1))
                    break;
            }
        }
    }
done:
    *e = '\0';

    result->type = PKT_STR;
    result->info.s = saveString(src);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * concatenate(arglist)
 *
 * Result: concatenation of arguments as strings
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_concatenate(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;

    clearPacket(result);

    result->type = PKT_STR;
    cp = PkInfos2Str(argc, argv);
    result->canFree = PK_CANFREE_STR;
    if ((result->info.s = SaveString(cp)))
        return 1;
    return 0;
}

/*
 * concatList(arglist)
 *
 * Result: concatenation of list items to one string
 * Return: 1 if successful, 0 if error occured
 */
#define REVERSERBUFF 1000
char* reverserBuff[REVERSERBUFF];
long meth_generic_concatList(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;
    Attr* attrp;
    Attr* hattrp;
    size_t totalLength = 0;
    int li = 0;

    hattrp = (Attr*)argv[0].info.a;

    result->type = PKT_STR;
    if (!hattrp) {
        clearPacket(result);
        return 0;
    }
    for (attrp = hattrp; attrp; attrp = attrp->next) {
        cp = ((Packet*)(attrp->val))->info.s;
        totalLength += strlen(cp);
        if (li < REVERSERBUFF)
            reverserBuff[li++] = cp;
    }
    if (li >= REVERSERBUFF) {
        fprintf(stderr, "ERROR: a feeble fixed sized buffer has been exceeded.\n. Error not "
                        "recovered."); /*XXX*/
        /* do something to expand buffer... */
        clearPacket(result);
        return 0;
    }
    cp = (char*)malloc(sizeof(char) * (totalLength + 1));
    cp[0] = '\0';
    while (--li >= 0)
        strcat(cp, reverserBuff[li]);
    result->info.s = cp;
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * cos(degree)
 *
 * Cosine at the given degree.
 *
 * Result: cosine value at given degree
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_cos(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_FLT;
    result->info.f = cosf(PkInfo2Flt(&argv[0]) * RADIAN_TO_DEGREE_RATIO);
    return 1;
}

/*
 * countChildren();
 *
 * Equivalent to objectListCount("children")
 *
 * Result: number of children
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_countChildren(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = GET__children(self);
    int i;

    result->type = PKT_INT;
    result->canFree = 0;
    if (olist) {
        for (i = 0; olist; olist = olist->next, i++)
            ;
        result->info.i = i;
        return 1;
    }
    result->info.i = 0;
    return 0;
}

/*
 * countItems(str)
 *
 * Comma seperate items.
 *
 * Result: number of items
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_countItems(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp = PkInfo2Str(&argv[0]);

    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = numOfChar(cp, ',') + 1;

    return 1;
}

/*
 * countLines(str)
 *
 * Counts number of '\n' charcters.
 *
 * Result: number of lines
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_countLines(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp = PkInfo2Str(&argv[0]);

    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = numOfChar(cp, '\n');

    return 1;
}

/*
 * countWords(str)
 *
 * Counts the number of words in a string.
 * Words are separated by whitespace (spaces, tabs, newlines).
 *
 * Result: number of words
 * Return: 1 if successful, 0 if error occured
 *
 * Source: Wayback Machine archived documentation
 * https://web.archive.org/web/20050122165617/http://www.xcf.berkeley.edu/~wei/viola/book/methods/all2.html
 */
long meth_generic_countWords(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *cp;
    int count = 0;
    int inWord = 0;

    result->type = PKT_INT;
    result->canFree = 0;

    if (argc < 1) {
        result->info.i = 0;
        return 0;
    }

    cp = PkInfo2Str(&argv[0]);
    if (!cp) {
        result->info.i = 0;
        return 0;
    }

    /* Count words by detecting transitions from non-word to word */
    while (*cp) {
        if (*cp == ' ' || *cp == '\t' || *cp == '\n' || *cp == '\r') {
            inWord = 0;
        } else {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        }
        cp++;
    }

    result->info.i = count;
    return 1;
}

/*
 * ctrlKeyP()
 *
 *
 * Result: control key state
 * Return: 1
 */
long meth_generic_ctrlKeyP(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->info.i = keyStat_control;
    result->canFree = 0;
    return 1;
}

/*
 * cursorShape([busy|idle])
 *
 * Change cursor shape.
 *
 * Result: current cursor shape
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_cursorShape(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* shape = PkInfo2Str(argv);

    result->type = PKT_STR;

    if (argc == 0 || !GET_window(self)) {
        result->info.s = "?";
        result->canFree = 0;
        return 0;
    }

    result->canFree = 0;
    if (!strcmp(shape, "busy")) {
        result->info.s = "busy";
        GLChangeToBusyMouseCursor(GET_window(self));
    } else {
        result->info.s = "idle";
        GLChangeToNormalMouseCursor(GET_window(self));
    }
    return 1;
}

/*
 * date()
 *
 * Result: date string, like ``Sat Feb 16 19:59:04 1991''
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_date(VObj* self, Packet* result, int argc, Packet argv[]) {
    time_t theTime;
    time(&theTime);
    char* timeStr = ctime(&theTime);
    /* remove newline from ctime result if present */
    size_t len = strlen(timeStr);
    if (len > 0 && timeStr[len - 1] == '\n') {
        timeStr[len - 1] = '\0';
    }
    result->info.s = SaveString(timeStr);
    result->type = PKT_STR;
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/* deepObjectListSend(objectListName, arg1, arg2, ..., argn)
 *
 * Recursively send the arguments to each objects in the object list.
 *
 * Result: cleared
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_deepObjectListSend(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = NULL;
    char* listName;

    listName = PkInfo2Str(&argv[0]);
    if (!strcmp(listName, "children")) {
        olist = GET__children(self);
    }
    while (olist) {
        if (olist->o) {
            sendMessagePackets(olist->o, &argv[1], argc - 1);
            callMeth(olist->o, result, argc, argv, STR_deepObjectListSend);
        } else {
            /* error */
        }
        olist = olist->next;
    }
    return 1;
}

/*
 * was test 2
 * defineNewFont(font#, fontName, XFontName)
 */
long meth_generic_defineNewFont(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* Font definitions are needed for rendering - not dangerous */
    clearPacket(result);
    result->info.i =
        GLDefineNewFont(fontInfo, PkInfo2Int(&argv[0]), PkInfo2Str(&argv[1]), PkInfo2Str(&argv[2]));
    result->type = PKT_INT;
    return 1;
}

/*
 * setDefaultFontFamily(offset)
 * Sets the default font family offset (0 = sans-serif, 14 = serif)
 */
long meth_generic_setDefaultFontFamily(VObj* self, Packet* result, int argc, Packet argv[]) {
    int offset = PkInfo2Int(&argv[0]);
    clearPacket(result);
    if (offset < 0 || offset + 14 > MAXFONTS) {
        fprintf(stderr, "setDefaultFontFamily: invalid offset %d (max %d)\n",
                offset, MAXFONTS - 14);
        result->info.i = fontFamilyDefaultOffset;
        result->type = PKT_INT;
        return 0;
    }
    fontFamilyDefaultOffset = offset;
    result->info.i = fontFamilyDefaultOffset;
    result->type = PKT_INT;
    return 1;
}

/*
 * getDefaultFontFamily()
 * Returns the default font family offset (0 = sans-serif, 14 = serif)
 */
long meth_generic_getDefaultFontFamily(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->info.i = fontFamilyDefaultOffset;
    result->type = PKT_INT;
    return 1;
}

/*
 * XXX
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_delay(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->type = PKT_INT;
    result->info.i = sleep((unsigned)PkInfo2Int(&argv[0]));
    return 1;
}

long meth_generic_deleteFile(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* path = PkInfo2Str(&argv[0]);
    
    clearPacket(result);
    result->type = PKT_INT;
    
    /* Allow deletion of temp files without prompt */
    if (path && (strncmp(path, "/tmp/", 5) == 0 || 
                 strncmp(path, "/var/tmp/", 9) == 0 ||
                 strncmp(path, "/var/folders/", 13) == 0)) {
        /* Block path traversal in temp paths */
        if (strstr(path, "..") != NULL) {
            fprintf(stderr, "Security: path traversal blocked in deleteFile\n");
            result->info.i = -1;
            return 0;
        }
        result->info.i = unlink(path);
        return 1;
    }
    
    /* Non-temp files require user confirmation */
    if (notSecureWithPromptf(self, "delete file: %s", path ? path : "(unknown)"))
        return 0;
    
    result->info.i = unlink(path);
    return 1;
}

/*
 * deleteSubStr(str, start, end)
 *
 * Deletes characters from position start to end (inclusive).
 * Uses 0-based indexing.
 *
 * Result: new string with substring removed
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_deleteSubStr(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *str, *newStr;
    long start, end, len, newLen;

    result->type = PKT_STR;

    if (argc < 3) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    str = PkInfo2Str(&argv[0]);
    start = PkInfo2Int(&argv[1]);
    end = PkInfo2Int(&argv[2]);

    if (!str) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    len = (long)strlen(str);

    /* Validate bounds */
    if (start < 0) start = 0;
    if (end >= len) end = len - 1;
    if (start > end || start >= len) {
        /* Nothing to delete, return copy of original */
        result->info.s = SaveString(str);
        result->canFree = PK_CANFREE_STR;
        return 1;
    }

    /* Calculate new length: original minus deleted portion */
    newLen = len - (end - start + 1);
    newStr = (char*)malloc(newLen + 1);
    if (!newStr) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    /* Copy part before start */
    if (start > 0) {
        strncpy(newStr, str, start);
    }
    /* Copy part after end */
    strcpy(newStr + start, str + end + 1);

    result->info.s = newStr;
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * deleteSubStrQ(str, start, end)
 *
 * Deletes characters from position start to end (inclusive).
 * Uses 0-based indexing. Modifies string in-place (without copying).
 *
 * Result: modified original string
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_deleteSubStrQ(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *str;
    long start, end, len;

    result->type = PKT_STR;

    if (argc < 3) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    str = PkInfo2Str(&argv[0]);
    start = PkInfo2Int(&argv[1]);
    end = PkInfo2Int(&argv[2]);

    if (!str) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    len = (long)strlen(str);

    /* Validate bounds */
    if (start < 0) start = 0;
    if (end >= len) end = len - 1;
    if (start > end || start >= len) {
        /* Nothing to delete */
        result->info.s = str;
        result->canFree = 0;
        return 1;
    }

    /* Move the tail over the deleted portion (including null terminator) */
    memmove(str + start, str + end + 1, len - end);

    result->info.s = str;
    result->canFree = 0;
    return 1;
}

/*
 * XXX
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_depth(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

/*
 * destroy(object name)
 *
 * Result:
 * Return:
 */
long meth_generic_destroy(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    Vfree(GET__memoryGroup(self), GET_name(self));
    return 0;
}

/*
 * destroyVariable(name)
 *
 * Removes a named variable from the object's variable list.
 *
 * Result: 1 if variable was found and removed, 0 otherwise
 * Return: 1 if successful, 0 if error occured
 *
 * Source: By analogy with getVariable/setVariable
 */
long meth_generic_destroyVariable(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *varName;
    Attr *varlist, *newVarlist;

    result->type = PKT_INT;
    result->canFree = 0;

    if (argc < 1) {
        result->info.i = 0;
        return 0;
    }

    varName = PkInfo2Str(&argv[0]);
    if (!varName) {
        result->info.i = 0;
        return 0;
    }

    varlist = GET__varList(self);
    newVarlist = destroyVariable_internal(varlist, varName);
    SET__varList(self, newVarlist);

    /* Return 1 if the list changed (variable was removed) */
    result->info.i = (varlist != newVarlist) ? 1 : 0;
    return 1;
}

/*
 * environVar(attribute)
 *
 * Get environment variable.
 *
 * Result: the gotten attribute
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_environVar(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern char** environ;
    char *varName;
    char reasonBuf[256];

    varName = PkInfo2Str(&argv[0]);
    if (varName && strlen(varName) > 200) {
        snprintf(reasonBuf, sizeof(reasonBuf), "read environment variable: %.200s...", varName);
    } else {
        snprintf(reasonBuf, sizeof(reasonBuf), "read environment variable: %s",
                 varName ? varName : "(null)");
    }
    if (notSecureWithPrompt(self, reasonBuf))
        return 0;

    result->type = PKT_STR;
    if (getEnvironVars(environ, varName, buff)) {
        result->info.s = SaveString(buff);
        result->canFree = PK_CANFREE_STR;
        return 1;
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

/*
 * execScript(scriptCode)
 *
 * Execute a Viola script from a string.
 * Used for ACTION/SCRIPT tags in VRML-style graphics.
 *
 * Return: result of script execution
 */
long meth_generic_execScript(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* scriptCode;
    /* execScript is needed for objects to function.
     * Security is enforced at individual dangerous method level (system, pipe, etc). */
    if (argc < 1) {
        result->type = PKT_INT;
        result->info.i = 0;
        result->canFree = 0;
        return 0;
    }
    
    scriptCode = PkInfo2Str(&argv[0]);
    if (!scriptCode || !*scriptCode) {
        result->type = PKT_INT;
        result->info.i = 0;
        result->canFree = 0;
        return 0;
    }
    
    /* Execute the script in the context of self */
    return execScript(self, result, scriptCode) ? 1 : 0;
}

/*
 * XXX
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_field(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

/*
 * XXX
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_fieldList(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

/*
 * filter(text)
 *
 * Result: replaces escape code into escape char
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_filter(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* inStr = PkInfo2Str(&argv[0]);
    char* outStr;
    char c, *cp;

    outStr = SaveString(inStr);
    cp = outStr;

    result->info.s = outStr;
    result->type = PKT_STR;
    result->canFree = PK_CANFREE_STR;

    while ((c = *inStr++)) {
        if (c == '\\') {
            switch (c = *inStr++) {
            case 'n':
                *cp++ = '\n'; /* newline */
                continue;
            case 't':
                *cp++ = '\t'; /* horizontal tab */
                continue;
            case 'b':
                *cp++ = '\b'; /* backspace */
                continue;
            case 'r':
                *cp++ = '\r'; /* carriage */
                continue;
            case 'f':
                *cp++ = '\f'; /* form feed */
                continue;
            case '\\':
                *cp++ = '\\'; /* backslash */
                continue;
            case '\'':
                *cp++ = '\''; /* single quote */
                continue;
            case '\"':
                *cp++ = '\"';
                continue;
            case EOF:
                continue;
            default:
                *cp++ = '\\';
                *cp++ = c;
            }
        } else {
            *cp++ = c;
        }
    }
    *cp = '\0';
    return 1;
}

/*
 * findPattern(text, pattern)
 *
 * Result: position where the matching string pattern ends, or -1 if not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_findPattern(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;
    char *inStr, *patStr;
    int ii = 0, pi = 0;
    size_t inLength, patLength;

    inStr = PkInfo2Str(&argv[0]);
    patStr = PkInfo2Str(&argv[1]);

    result->type = PKT_INT;
    result->canFree = 0;
    if (!inStr || !patStr) {
        result->info.i = -1;
        return 0;
    }
    inLength = strlen(inStr);
    patLength = strlen(patStr);

    for (cp = inStr; *cp; cp++) {
        if (*cp == patStr[pi]) {
            if (++pi >= patLength) {
                result->info.i = ii;
                return 1;
            }
            if (ii >= inLength) {
                result->info.i = -1;
                return 0;
            }
        } else {
            pi = 0;
        }
        ii++;
    }
    result->info.i = -1;
    return 0;
}

/*
 * float(argument)
 *
 * Convert argument to floating point type.
 *
 * Result: arguement in float
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_float(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_FLT;
    result->info.f = PkInfo2Flt(argv);
    return 1;
}

/*
 * format(text, style [,style info])
 *
 * Simple text formatting kludge
 *
 * Result: arguement in float
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_format(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (!strcmp(PkInfo2Str(&argv[1]), "split")) {
    }
    /*
            result->type = PKT_STR;
            result->info.s = PkInfo2Flt(argv);
            return 1;
    */
    clearPacket(result);
    return 0;
}

/*
 * freeSelf()
 *
 * Free object attributes and.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_freeSelf(VObj* self, Packet* result, int argc, Packet argv[]) {
    HashEntry* entry;
    union PCode* pcode;
    VObjList* olist;
    Attr* varlist;
    VObj* parent;

    /* PROTECTION: Don't free an object if its parent is still alive and not being freed.
     * This prevents scripts from accidentally freeing original objects
     * when they should only affect clones. */
    parent = GET__parent(self);
    if (parent && validObjectP(parent)) {
        ClassInfo* parentClassInfo = GET__classInfo(parent);
        if (parentClassInfo != NULL) {
            /* Parent is alive and not being freed - block this free */
            clearPacket(result);
            return 0;
        }
    }

    /* Debug: show what's being freed */
#if 0 /* DEBUG_CLONE */
    {
        char* selfName = GET_name(self);
        int childCount = 0;
        for (olist = GET__children(self); olist; olist = olist->next)
            if (olist->o) childCount++;
        fprintf(stderr, "FREE: '%s' ptr=%p (%d children)\n",
                selfName ? selfName : "(null)", (void*)self, childCount);
    }
#endif

    if (!exitingViola) {
        objID2Obj->remove(objID2Obj, getIdent(GET_name(self)));
        symStr2ID->remove(symStr2ID, (long)GET_name(self));
        objObj2ExistP->remove(objObj2ExistP, (long)self);
        /*
                if (entry = symStr2ID->get(symStr2ID, GET_name(self))) {
                        print("FREESELF: in symStr2ID >>>%s<<\n", entry->label);
                }
                if (entry = objID2Obj->get(objID2Obj, getIdent(GET_name(self)))) {
                        print("FREESELF: in objID2Obj >>>%s<<\n", entry->label);
                }
                if (entry = objObj2ExistP->get(objObj2ExistP, (long)self)) {
                        print("FREESELF: in objObj2ExistP val=%d\n", entry->val);
                }
        */
        Vfree(GET__memoryGroup(self), GET_name(self));

        GET_script(self)->refc--;
        if (GET_script(self)->refc <= 0) {
            Vfree(GET__memoryGroup(self), GET_script(self)->s);
            Vfree(GET__memoryGroup(self), GET_script(self));
        }

        pcode = GET__script(self);
        if (pcode)
            if (--pcode[PCODE_IDX_REFC].i <= 0)
                Vfree(GET__memoryGroup(self), GET__script(self));

        /* free variables */
        varlist = GET__varList(self);
        freeVarList(varlist);
    }

    /* free children */
    for (olist = GET__children(self); olist; olist = olist->next) {
        if (olist->o) {
            if (validObjectP(olist->o)) {
                Packet freePk;
                nullPacket(&freePk);
                callMeth(olist->o, &freePk, 0, NULL, STR_freeSelf);
                clearPacket(&freePk);
            }
        }
    }

    meth_cosmic_freeSelf(self, result, argc, argv);
    return 1;
}

/*
 * XXX
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_gravity(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

long meth_generic_hash(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->info.t = storeIdent(PkInfo2Str(&argv[0]));
    result->type = PKT_TOK;
    return 1;
}

/*
 * get(attribute)
 *
 * Get an attribute: active, children, class, message, name, parent, script.
 *
 * Result: the gotten attribute
 * Return: 1 if successful, 0 if error occured
 */
long helper_generic_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {
    switch (labelID) {
    case STR_name:
        result->info.s = SaveString(GET_name(self));
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        return 1;

    case STR_class:
        result->info.s = SaveString(GET_class(self));
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        return 1;

    case STR_classScript:
        result->info.s = SaveString(GET_classScript(self));
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        return 1;

    case STR_parent:
        result->info.s = SaveString(GET_parent(self));
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        return 1;

    case STR_children:
        result->info.s = SaveString(GET_children(self));
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        return 1;

    case STR_security:
        result->info.i = GET_security(self);
        result->type = PKT_INT;
        result->canFree = 0;
        return 1;

    case STR_script:
        result->info.s = SaveString(GET_script(self)->s);
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        return 1;

    case STR_active:
        result->info.i = GET_active(self);
        result->type = PKT_INT;
        result->canFree = 0;
        return 1;
    }
    return 0;
}
long meth_generic_get(VObj* self, Packet* result, int argc, Packet argv[]) {
    return helper_generic_get(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

long meth_generic_getResource(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* X11 resources are needed for fonts/colors - not dangerous */
    clearPacket(result);
    result->info.s = GLGetResource(PkInfo2Str(&argv[0]));
    result->canFree = 0;
    result->type = PKT_STR;
    return 1;
}

long meth_generic_getSelection(VObj* self, Packet* result, int argc, Packet argv[]) {
    return GLGetSelection(result);
}

/*
 * getVariable(variabel name)
 *
 * Get a named variable in the object.
 *
 * Result: the gotten attribute
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_getVariable(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp = PkInfo2Str(&argv[0]);

    /*	result->type = PKT_STR;*/
    if (!cp) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    /*	if (getVariable(GET__varList(self), cp, &(result->info.s))) {
                    return 1;
            }
    */
    if (getVariable(GET__varList(self), cp, result)) {
        return 1;
    }
    clearPacket(result);
    return 0;
}

/*
 * height()
 *
 * Result: self's height
 */
long meth_generic_height(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.i = GET_height(self);
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 * initialize()
 *
 * Initializes object.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_initialize(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;

    if (!makeArgAttr(self)) {
        fprintf(stderr, "makeArgAttr() failed\n");
    }

    /* make internal pointer link to parent object */
    if (!GET__parent(self)) {
        if ((cp = GET_parent(self)))
            if (*cp)
                SET__parent(self, findObject(getIdent(cp)));
    }

    /* make internal pointer link to children objects */
    if (!GET__children(self)) {
        cp = GET_children(self);
        if (cp)
            if (*cp)
                SET__children(self, strOListToOList(cp));
    }
    clearPacket(result);

    return 1;
}

/*
 * int(float|str)
 *
 * Convert single argument to integer.
 *
 * Result: integer type of the argument
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_int(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = PkInfo2Int(&argv[0]);
    return 1;
}

/*
 * isBlank(str)
 *
 *
 * Result: 1 or 0
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_isBlank(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = AllBlank(PkInfo2Str(&argv[0])) ? 1 : 0;
    return 1;
}

/*
 * item(str, n1 [,n2])
 *
 * Extract the item(s) ranged by n1 and n2. Comma (,) is the seperating
 * character. Item numbering starts from 1.
 *
 * Result: string containing the items
 * Return: 1 if successful, 0 if error occured
 *
 * Source: Original author's comment in cl_generic.c and archived documentation
 * https://web.archive.org/web/20040601221047/http://www.xcf.berkeley.edu/~wei/viola/book/appc.html
 */
long meth_generic_item(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *str, *cp, *start;
    long n1, n2;
    long itemNum = 1;
    int bi = 0;

    result->type = PKT_STR;

    if (argc < 2) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    str = PkInfo2Str(&argv[0]);
    if (!str) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    n1 = PkInfo2Int(&argv[1]);
    if (argc >= 3) {
        n2 = PkInfo2Int(&argv[2]);
    } else {
        n2 = n1;
    }

    /* Validate range */
    if (n1 < 1 || n2 < n1) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    buff[0] = '\0';
    start = str;

    for (cp = str; ; cp++) {
        if (*cp == ',' || *cp == '\0') {
            if (itemNum >= n1 && itemNum <= n2) {
                /* Copy this item */
                if (bi > 0) {
                    buff[bi++] = ','; /* Add comma between items */
                }
                while (start < cp) {
                    buff[bi++] = *start++;
                }
            }
            if (*cp == '\0' || itemNum >= n2) {
                break;
            }
            itemNum++;
            start = cp + 1;
        }
    }
    buff[bi] = '\0';

    result->info.s = SaveString(buff);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 *
 * Result: key
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_key(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.c = keyStat_key;
    result->type = PKT_CHR;
    result->canFree = 0;
    return 1;
}

/*
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_listAllObjects(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 1;
}

/*
 * objectListAppend(objList, obj)
 *
 * Append an object to a named object list.
 *
 * Result: object count, -1 if the list is not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListAppend(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* listName;
    VObjList* olist = NULL;

    result->type = PKT_OBJ;
    result->canFree = 0;
    listName = PkInfo2Str(&argv[0]);
    if (!strcmp(listName, "children")) {
        VObj* obj = PkInfo2Obj(&argv[1]);
        olist = GET__children(self);
        if (obj) {
            SET__children(self, appendObjToList(olist, obj));
            result->info.o = obj;
            return 1;
        }
    }
    result->info.o = NULL;
    return 0;
}
/*
 * objectListAppend_children(obj)
 *
 * Append an object to children list
 *
 * Result: object count, -1 if the list is not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListAppend_children(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = GET__children(self);
    VObj* obj = PkInfo2Obj(&argv[0]);

    result->type = PKT_OBJ;
    result->canFree = 0;
    if (obj) {
        SET__children(self, appendObjToList(olist, obj));
        result->info.o = obj;
        return 1;
    }
    result->info.o = NULL;
    return 0;
}

/*
 * objectListCount(objList)
 *
 * Count the number of objects in a named object list.
 *
 * Result: object count, -1 if the list is not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListCount(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;
    char* listName;
    VObjList* olist = NULL;

    listName = PkInfo2Str(&argv[0]);
    if (!strcmp(listName, "children")) {
        olist = GET__children(self);
    }
    result->type = PKT_INT;
    result->canFree = 0;
    if (olist) {
        for (i = 0; olist; olist = olist->next, i++)
            ;
        result->info.i = i;
        return 1;
    }
    result->info.i = -1;
    return 0;
}
/*
 * objectListCount_children()
 *
 * Count the number of children list
 *
 * Result: object count, -1 if the list is not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListCount_children(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;
    VObjList* olist = GET__children(self);

    result->type = PKT_INT;
    result->canFree = 0;
    if (olist) {
        for (i = 0; olist; olist = olist->next, i++)
            ;
        result->info.i = i;
        return 1;
    }
    result->info.i = -1;
    return 0;
}

/*
 * objectListDelete(objList, obj)
 *
 * Delte an object from a named object list.
 *
 * Result: object count, -1 if the list is not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListDelete(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = NULL;
    char* listName = PkInfo2Str(argv);

    clearPacket(result);
    if (!strcmp(listName, "children")) {
        VObj* obj = PkInfo2Obj(&argv[1]);
        olist = GET__children(self);
        if (olist && obj) {
            olist = removeVObjListNode(olist, (long)obj);
            SET__children(self, olist);
            return 1;
        }
    }
    return 0;
}

/*
 * objectListDelete_children(obj)
 *
 * Delte an object from children list
 *
 * Result: object count, -1 if the list is not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListDelete_children(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = GET__children(self);
    VObj* obj = PkInfo2Obj(&argv[0]);

    clearPacket(result);
    if (olist && obj) {
        olist = removeVObjListNode(olist, (long)obj);
        SET__children(self, olist);
        return 1;
    }
    return 0;
}

/*
 * objectListPrepend(objList, obj)
 *
 * Prepend an object to a named object list.
 *
 * Result: object count, -1 if the list is not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListPrepend(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* listName;
    VObjList* olist = NULL;

    result->type = PKT_OBJ;
    result->canFree = 0;
    listName = PkInfo2Str(&argv[0]);
    if (!strcmp(listName, "children")) {
        VObj* obj = PkInfo2Obj(&argv[1]);
        olist = GET__children(self);
        if (obj) {
            VObjList* node;
            node = (VObjList*)malloc(sizeof(VObjList));
            node->o = obj;
            if (olist)
                node->next = olist;
            else
                node->next = NULL;
            SET__children(self, node);
            result->info.o = obj;
            return 1;
        }
    }
    result->info.o = NULL;
    return 0;
}

/*
 * objectListPrepend_children(obj)
 *
 * Prepend an object to children list
 *
 * Result: object count, -1 if the list is not found
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListPrepend_children(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = GET__children(self);
    VObj* obj = PkInfo2Obj(&argv[0]);

    result->type = PKT_OBJ;
    result->canFree = 0;
    if (obj) {
        VObjList* node;
        node = (VObjList*)malloc(sizeof(VObjList));
        node->o = obj;
        if (olist)
            node->next = olist;
        else
            node->next = NULL;
        SET__children(self, node);
        result->info.o = obj;
        return 1;
    }
    result->info.o = NULL;
    return 0;
}

/*
 * objectListSend(objectListName, arg1, arg2, ..., argn)
 *
 * Send the arguments to each objects in the object list.
 *
 * Result: cleared
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListSend(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = NULL;
    char* listName;

    listName = PkInfo2Str(&argv[0]);
    if (!strcmp(listName, "children")) {
        olist = GET__children(self);
    }
    while (olist) {
        sendMessagePackets(olist->o, &argv[1], argc - 1);
        olist = olist->next;
    }
    clearPacket(result);
    return 1;
}

/*
 * objectListSend_children(arg1, arg2, ..., argn)
 *
 * Send the arguments to each objects in the children list.
 *
 * Result: cleared
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectListSend_children(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = GET__children(self);

    while (olist) {
        sendMessagePackets(olist->o, &argv[0], argc);
        olist = olist->next;
    }
    clearPacket(result);
    return 1;
}

/*
 * objectPosition(obj, objList)
 *
 * Return the position an object in the named object list.
 *
 * Result: position (starting from 0), -1 if object is not found in list
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_objectPosition(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObjList* olist = NULL;
    VObj* obj;
    char* listName;
    int i;

    obj = PkInfo2Obj(&argv[0]);
    listName = PkInfo2Str(&argv[1]);

    if (!strcmp(listName, "children")) {
        olist = GET__children(self);
    }

    result->type = PKT_INT;
    result->canFree = 0;
    for (i = 0; olist; olist = olist->next, i++) {
        if (olist->o == obj) {
            result->info.i = i;
            return 1;
        }
    }
    result->info.i = -1;
    return 0;
}

/*
 * loadFile(fileName)
 *
 * Loads a file and returns its content.
 *
 * Result: loaded file
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_loadFile(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *cp, *retStrp, *path;
    
    result->type = PKT_STR;
    cp = PkInfo2Str(&argv[0]);
    
    /* Security check - reading local files can leak sensitive data */
    if (cp && notSecureWithPromptf(self, "read file: %s", cp)) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
    if (!cp) {
        result->info.s = "";
        result->canFree = 0;
    }
    if ((cp = SaveString(vl_expandPath(cp, buff)))) {
        if (loadFile(cp, &retStrp) >= 0) {
            if (retStrp) {
                result->info.s = retStrp;
                result->canFree = PK_CANFREE_STR;
                free(cp);
                return 1;
            } else {
                sprintf(buff, "loadFile \"%s\" failed.\n", cp);
                messageToUser(self, MESSAGE_ERROR, buff);
            }
        } else {
            sprintf(buff, "Unable to open file '%s'. aborted.\n", cp);
            messageToUser(self, MESSAGE_ERROR, buff);
        }
        free(cp);
    } else {
        sprintf(buff, "no such file\n");
        messageToUser(self, MESSAGE_ERROR, buff);
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

long meth_generic_loadSTG(VObj* self, Packet* result, int argc, Packet argv[]) {
    return loadSTG(PkInfo2Str(&argv[0]));
}
/*
 * makeTempFile()
 * Creates a secure temp file using mkstemps().
 * Result: path to temp file, or "" on error
 */
long meth_generic_makeTempFile(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* path = sys_make_temp_file(NULL);
    
    result->type = PKT_STR;
    if (path) {
        result->info.s = path;
        result->canFree = PK_CANFREE_STR;
        return 1;
    } else {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }
}

/*
 * not(boolean)
 *
 * Returns the logical NOT of the argument.
 *
 * Result: logical NOT of argument (0 becomes 1, non-zero becomes 0)
 * Return: 1 if successful, 0 if error occured
 *
 * Source: Wayback Machine archived documentation
 * https://web.archive.org/web/20050122165617/http://www.xcf.berkeley.edu/~wei/viola/book/methods/all2.html
 */
long meth_generic_not(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;

    if (argc < 1) {
        result->info.i = 1; /* not(nothing) = true */
        return 1;
    }

    /* Get the boolean value and negate it */
    result->info.i = PkInfo2Int(&argv[0]) ? 0 : 1;
    return 1;
}

/*
 * nthChar(string, n1, [n2])
 *
 * Result: character range from n1 to n2
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_nthChar(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc == 2) {
        long n;
        char* s;

        result->type = PKT_CHR;
        result->canFree = 0;
        n = PkInfo2Int(&argv[1]);
        s = PkInfo2Str(&argv[0]);
        if (s)
            result->info.c = s[n];
        else
            result->info.c = '\0';

    } else if (argc == 3) {
        int i;
        long n1, n2;
        char *cp, *str;

        result->type = PKT_STR;
        str = PkInfo2Str(&argv[0]);
        n1 = PkInfo2Int(&argv[1]);
        n2 = PkInfo2Int(&argv[2]);
        cp = (char*)malloc(sizeof(char) * (n2 - n1 + 2));
        if (!cp) {
            result->info.s = "";
            result->canFree = 0;
            return 0;
        }
        if (str)
            for (i = 0; n1 <= n2; n1++) {
                if (!str[n1])
                    break;
                cp[i++] = str[n1];
            }
        cp[i] = '\0';
        result->info.s = cp;
        result->canFree = PK_CANFREE_STR;
    }
    return 1;
}

/*
 * nthChild(n)
 * Result:  the n'th object in self's children list.
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_nthChild(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i = 0;
    long n;
    char* listName;
    VObjList* olist;

    if (argc != 1) {
        clearPacket(result);
        return 0;
    }
    n = PkInfo2Int(&argv[0]);

    olist = GET__children(self);

    result->type = PKT_OBJ;
    result->canFree = 0;
    while (olist) {
        if (i++ >= n) {
            result->info.o = olist->o;
            return 1;
        }
        olist = olist->next;
    }
    result->info.o = NULL;
    return 0;
}

/*
 * nthItem(string, n)
 *
 * Returns the nth comma-separated item from the string.
 * Item numbering starts from 1.
 *
 * Result: the nth item as a string
 * Return: 1 if successful, 0 if error occured
 *
 * Source: By analogy with item() and nthWord()
 */
long meth_generic_nthItem(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *str, *cp, *start;
    long n;
    long itemNum = 1;
    int bi = 0;

    result->type = PKT_STR;

    if (argc < 2) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    str = PkInfo2Str(&argv[0]);
    if (!str) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    n = PkInfo2Int(&argv[1]);
    if (n < 1) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    start = str;

    for (cp = str; ; cp++) {
        if (*cp == ',' || *cp == '\0') {
            if (itemNum == n) {
                /* Copy this item */
                while (start < cp) {
                    buff[bi++] = *start++;
                }
                break;
            }
            if (*cp == '\0') {
                /* Item not found */
                result->info.s = "";
                result->canFree = 0;
                return 0;
            }
            itemNum++;
            start = cp + 1;
        }
    }
    buff[bi] = '\0';

    result->info.s = SaveString(buff);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * nthLine(str, n1 [,n2])
 *
 * Extracts the specified lines (from line n1 to n2) from the string.
 * Line numbering start from 0.
 *
 * Result: the specified line(s)
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_nthLine(VObj* self, Packet* result, int argc, Packet argv[]) {
    long li, hi;
    int lines;
    long size;
    char* str;

    result->type = PKT_STR;
    str = PkInfo2Str(&argv[0]);
    if (str) {
        if (argc == 2) {
            li = hi = PkInfo2Int(&argv[1]);
        } else if (argc == 3) {
            li = PkInfo2Int(&argv[1]);
            hi = PkInfo2Int(&argv[2]);
        } else {
            /* incorrect number of arguments */
            result->info.s = "";
            result->canFree = 0;
            return 0;
        }
        result->canFree = PK_CANFREE_STR;
        if ((result->info.s = getLines(li, hi, str, &size)))
            return 1;
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

/*
 * nthObjectInList(n, objectList)
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_nthObjectInList(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i = 0;
    long n;
    char* listName;
    VObjList* olist;

    if (argc != 2) {
        clearPacket(result);
        return 0;
    }
    n = PkInfo2Int(&argv[0]);
    listName = PkInfo2Str(&argv[1]);

    if (!strcmp(listName, "children")) {
        olist = GET__children(self);
    }

    result->type = PKT_OBJ;
    result->canFree = 0;
    while (olist) {
        if (i++ >= n) {
            result->info.o = olist->o;
            return 1;
        }
        olist = olist->next;
    }
    result->info.o = NULL;
    return 0;
}

/*
 * nthSibling(n)
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_nthSibling(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i = 0;
    long n;
    char* listName;
    VObjList* olist;
    VObj* parent;

    if (argc != 1) {
        clearPacket(result);
        return 0;
    }
    n = PkInfo2Int(&argv[0]);

    parent = GET__parent(self);
    if (parent) {
        olist = GET__children(parent);
        result->type = PKT_OBJ;
        result->canFree = 0;
        while (olist) {
            if (i++ >= n) {
                result->info.o = olist->o;
                return 1;
            }
            olist = olist->next;
        }
        result->info.o = NULL;
    }
    return 0;
}

/*
 * nthWord(str, n1, n2)
 *
 * Result: the word string if successful, or "" if failed.n
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_nthWord(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* str;
    long n1, n2;

    str = PkInfo2Str(&argv[0]);
    if (!str) {
        result->type = PKT_STR;
        result->info.s = "";
        result->canFree = 0;
        return 0;
    } else {
        str = SaveString(str);
        result->type = PKT_STR;
        if (argc == 2) {
            n1 = n2 = PkInfo2Int(&argv[1]);
        } else if (argc == 3) {
            n1 = PkInfo2Int(&argv[1]);
            n2 = PkInfo2Int(&argv[2]);
        } else {
            result->info.s = "";
            result->canFree = 0;
            return 0;
        }
        extractWord(str, n1, n2, buff);
        result->info.s = SaveString(buff);
        result->canFree = PK_CANFREE_STR;
        free(str); /* argh! */
    }
    return 1;
}

/*
 * parent()
 *
 * Result: parent object
 */
long meth_generic_parent(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.o = GET__parent(self);
    result->type = PKT_OBJ;
    result->canFree = 0;
    return 1;
}

long meth_generic_pipe(VObj* self, Packet* result, int argc, Packet argv[]) {
    int c;
    FILE* fp;
    char* buffp;
    char* cmd = (argc > 0) ? PkInfo2Str(&argv[0]) : "(no command)";

    clearPacket(result);

    /* Security: untrusted objects cannot execute shell commands via pipe */
    if (notSecureWithPromptf(self, "pipe(\"%s\")", cmd))
        return 0;

    fp = popen(PkInfo2Str(&argv[0]), PkInfo2Str(&argv[1]));
    if (!fp) {
        return 0;
    } else {
        buffp = buff;
        while ((c = fgetc(fp)) != EOF) {
            *buffp = (char)c;
            buffp++;
        }
        *buffp = '\0';
        pclose(fp);
        result->info.s = SaveString(buff);
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        return 1;
    }
}

/*
 * prepend(<list>, id, value)
 *
 * Prepend item to list
 *
 * Result:
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_prepend(VObj* self, Packet* result, int argc, Packet argv[]) { return 1; }

/*
 * print(argument> [, ...])
 *
 * Print arguments to standard output.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_print(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;

    clearPacket(result);
    for (i = 0; i < argc; i++) {
        switch (argv[i].type) {
        case PKT_OBJ:
            if (argv[i].info.o)
                printf("%s", GET_name(argv[i].info.o));
            else
                printf("(NULL)");
            continue;
        case PKT_INT:
            printf("%ld", argv[i].info.i);
            continue;
        case PKT_FLT:
            printf("%f", argv[i].info.f);
            continue;
        case PKT_CHR:
            printf("%c", argv[i].info.c);
            continue;
        case PKT_STR:
            if (argv[i].info.s)
                printf("%s", argv[i].info.s);
            else
                printf("(NULL)");
            continue;
        case PKT_ARY:
            if (argv[i].info.y) {
                int n;
                Array* array = argv[i].info.y;
                for (n = 0; n < array->size; n++)
                    printf("%ld ", array->info[n]);
            }
            continue;
        case PKT_ATR: {
            Attr* attrp;
            attrp = argv[i].info.a;
            for (; attrp; attrp = attrp->next) {
                printf("id=%ld val=%ld:", attrp->id, attrp->val);
                dumpPacket((Packet*)attrp->val);
                printf("\n");
            }
        }
            continue;
        default:
            printf("??");
            dumpPacket(&argv[i]);
            return 0;
        }
    }
    fflush(stdout);
    return 1;
}

/*
 * printf(argument [, ...])
 *
 * Print arguments to standard output.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_printf(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;

    clearPacket(result);
    for (i = 0; i < argc; i++) {
        switch (argv[i].type) {
        case PKT_OBJ:
            printf("%s", GET_name(argv[i].info.o));
            continue;
        case PKT_INT:
            printf("%ld", argv[i].info.i);
            continue;
        case PKT_FLT:
            printf("%f", argv[i].info.f);
            continue;
        case PKT_CHR:
            printf("%c", argv[i].info.c);
            continue;
        case PKT_STR:
            printf("%s", argv[i].info.s);
            continue;
        case PKT_ARY:
            if (argv[i].info.y) {
                int n;
                Array* array = argv[i].info.y;
                for (n = 0; n < array->size; n++)
                    printf("%ld ", array->info[n]);
            }
            continue;
        default:
            printf("??");
            dumpPacket(&argv[i]);
            return 0;
        }
    }
    return 1;
}

long meth_generic_random(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;

#if defined(SVR4)
    result->info.i = random((unsigned)PkInfo2Int(&argv[0]));
#else
#ifdef i386
    result->info.i = rand();
#else
    if (argc)
        srand((unsigned)PkInfo2Int(&argv[0]));
    result->info.i = rand();
#endif
#endif
    return 1;
}

/* replaceChar(originalStr, charToReplace, newChar)
 */
long meth_generic_replaceChar(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;
    char *inStr, patChar, repChar;

    inStr = SaveString(PkInfo2Str(&argv[0]));
    patChar = PkInfo2Char(&argv[1]);
    repChar = PkInfo2Char(&argv[2]);

    for (cp = inStr; *cp; cp++)
        if (*cp == patChar)
            *cp = repChar;

    result->type = PKT_STR;
    result->info.s = inStr;
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/* replaceCharQ(originalStr, charToReplace, newChar)
 */
long meth_generic_replaceCharQ(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;
    char *inStr, patChar, repChar;

    inStr = PkInfo2Str(&argv[0]);
    patChar = PkInfo2Char(&argv[1]);
    repChar = PkInfo2Char(&argv[2]);

    for (cp = inStr; *cp; cp++)
        if (*cp == patChar)
            *cp = repChar;

    result->type = PKT_STR;
    result->info.s = inStr;
    result->canFree = 0;
    return 1;
}

/* replaceStr(originalStr, pattern, patternReplaceStr)
 */
long meth_generic_replaceStr(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *cp, *lp;
    char *inStr, *patStr, *repStr;
    int ii = 0, pi = 0;
    size_t inLength, patLength, repLength;

    inStr = PkInfo2Str(&argv[0]);
    patStr = PkInfo2Str(&argv[1]);
    repStr = PkInfo2Str(&argv[3]);
    inLength = strlen(inStr);
    patLength = strlen(patStr);
    repLength = strlen(repStr);

    result->type = PKT_STR;
    lp = inStr;
    for (cp = inStr; *cp; cp++) {
        if (*cp == patStr[pi]) {
            if (++pi >= patLength) {
                strncat(buff, lp, cp - lp);
                lp = cp;
                strcat(buff, repStr);
            }
            if (ii >= inLength) {
                break;
            }
        } else {
            pi = 0;
        }
        ii++;
    }
    strncat(buff, lp, cp - lp);
    result->info.s = SaveString(buff);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * replaceStrQ(originalStr, pattern, patternReplaceStr)
 *
 * Replaces all occurrences of pattern with replacement string.
 * Works without copying - uses global buffer, does not allocate new memory.
 *
 * Result: string with replacements (in global buffer)
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_replaceStrQ(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *cp, *lp;
    char *inStr, *patStr, *repStr;
    int pi = 0;
    size_t patLength;

    result->type = PKT_STR;

    if (argc < 3) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    inStr = PkInfo2Str(&argv[0]);
    patStr = PkInfo2Str(&argv[1]);
    repStr = PkInfo2Str(&argv[2]);

    if (!inStr || !patStr || !repStr) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    patLength = strlen(patStr);
    if (patLength == 0) {
        /* Empty pattern - return original */
        result->info.s = inStr;
        result->canFree = 0;
        return 1;
    }

    buff[0] = '\0';
    lp = inStr;
    for (cp = inStr; *cp; cp++) {
        if (*cp == patStr[pi]) {
            if (++pi >= patLength) {
                /* Found pattern match */
                /* Copy chars before pattern (excluding matched chars) */
                size_t prefixLen = (cp - lp) - (patLength - 1);
                if (prefixLen > 0) {
                    strncat(buff, lp, prefixLen);
                }
                strcat(buff, repStr);
                lp = cp + 1;
                pi = 0;
            }
        } else {
            pi = 0;
        }
    }
    /* Copy remaining part */
    strcat(buff, lp);

    result->info.s = buff;
    result->canFree = 0;
    return 1;
}

/*
 * saveFile(fileName, str)
 *
 * Save a file and returns its content.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_saveFile(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;
    char* path = PkInfo2Str(&argv[0]);
    
    if (notSecureWithPromptf(self, "saveFile(\"%s\")", path ? path : "(unknown)"))
        return 0;

    result->type = PKT_INT;
    result->canFree = 0;
    if ((cp = SaveString(vl_expandPath(PkInfo2Str(&argv[0]), buff)))) {
        if (saveFile(cp, PkInfo2Str(&argv[1])) != -1) {
            free(cp);
            result->info.i = 1;
            return 1;
        }
    }
    sprintf(buff, "saveFile(\"%s\", data) failed.\n", cp);
    messageToUser(self, MESSAGE_ERROR, buff);
    result->info.i = 0;
    return 0;
}

/*
 * scan(argument [, ...])
 *
 * Print arguments to standard output.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_scan(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;
    clearPacket(result);
    return 0;
}

/*
 * scanf(argument [, ...])
 *
 * Print arguments to standard output.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_scanf(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;

    clearPacket(result);
    for (i = 0; i < argc; i++) {
        switch (argv[i].type) {
        case PKT_OBJ:
            printf("%s", GET_name(argv[i].info.o));
            continue;
        case PKT_INT:
            printf("%ld", argv[i].info.i);
            continue;
        case PKT_FLT:
            printf("%f", argv[i].info.f);
            continue;
        case PKT_CHR:
            printf("%c", argv[i].info.c);
            continue;
        case PKT_STR:
            printf("%s", argv[i].info.s);
            continue;
        case PKT_ARY:
            if (argv[i].info.y) {
                int n;
                Array* array = argv[i].info.y;
                for (n = 0; n < array->size; n++)
                    printf("%ld ", array->info[n]);
            }
            continue;
        default:
            printf("??");
            dumpPacket(&argv[i]);
            return 0;
        }
    }
    return 1;
}

/*
 * securityMode()
 *
 * forces security mode for newly created objects. all objects created
 * during the time when mode > 0 will have the security value set to
 * the mode value. Can alter securityMode value only if mode == 0;
 *
 * Result: mode
 */
long meth_generic_securityMode(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc > 0) {
        int newMode = PkInfo2Int(&argv[0]);
        if (newMode == 0) {
            /* Lowering securityMode: requires trust */
            if (GET_security(self) == 0) {
                securityMode = 0;
            } else if (!notSecureWithPrompt(self, "elevate to trusted status")) {
                securityMode = 0;
            }
            /* else: user denied, securityMode unchanged */
        } else {
            /* Raising securityMode: always allowed */
            securityMode = newMode;
        }
    }

    clearPacket(result);
    result->type = PKT_INT;
    result->info.i = securityMode;
    return 1;
}

/*
 * self()
 *
 * Result: self object
 */
long meth_generic_self(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.o = self;
    result->type = PKT_OBJ;
    result->canFree = 0;
    return 1;
}

/*
 * selectionInfo()
 *
 * Result: [0] object
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_selectionInfo(VObj* self, Packet* result, int argc, Packet argv[]) {
    Packet* packet0 = makePacket();
    Attr* attrp;
    result->type = PKT_ATR;
    result->info.a = attrp = makeAttr(0, (intptr_t)packet0);
    result->canFree = PK_CANFREE_STR;

    if (xselectionObj) {
        packet0->info.o = xselectionObj;
        packet0->type = PKT_OBJ;
        packet0->canFree = 0;
        return 1;
    } else {
        packet0->info.o = NULL;
        packet0->type = PKT_OBJ;
        packet0->canFree = 0;
        return 0;
    }
}

void helper_setSecurity(VObj* self, long level) {
    VObjList* olist;

    SET_security(self, level);
    for (olist = GET__children(self); olist; olist = olist->next)
        helper_setSecurity(olist->o, level);
}

/*
 * returns non-zero if set operation succeded, zero otherwise.
 *
 *
 * Result: ...
 * Return: 1 if successful, 0 if error occured
 */
long helper_generic_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {
    char* str;

    switch (labelID) {
    case STR_name:

        objID2Obj->remove(objID2Obj, getIdent(GET_name(self)));

        /* Until object names have their own name space,
         * don't remove them... lest risk deleting keywords
         */
        /*		symStr2ID->remove(symStr2ID, GET_name(self));*/

        if (GET_name(self))
            Vfree(GET__memoryGroup(self), GET_name(self));
        result->info.s = VSaveString(GET__memoryGroup(self), PkInfo2Str(&argv[1]));
        SET_name(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        objID2Obj->put_replace(objID2Obj, storeIdent(saveString(GET_name(self))), (long)self);
        return 1;

    case STR_parent: {
        HashEntry* entry;
        VObj* obj;

        if (GET_parent(self))
            Vfree(GET__memoryGroup(self), GET_parent(self));
        result->info.s = VSaveString(GET__memoryGroup(self), PkInfo2Str(&argv[1]));
        SET_parent(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        if ((entry = symStr2ID->get(symStr2ID, (long)result->info.s)))
            if ((obj = findObject(entry->val))) {
                SET__parent(self, obj);
                return 1;
            }
        SET__parent(self, NULL);
        return 1;
    }

    case STR_children: {
        char* cp;
        VObjList* objl;

        result->type = PKT_INT;
        result->canFree = 0;
        cp = VSaveString(GET__memoryGroup(self), PkInfo2Str(&argv[1]));
        if (cp) {
            objl = strOListToOList(cp);
        }
        if (objl) {
            /* free olist GET__children(); */
            SET_children(self, cp);
            SET__children(self, objl);
            result->info.i = 1;
            return 1;
        } else {
            SET_children(self, "");
            SET__children(self, NULL);
            result->info.i = 0;
            return 0;
        }
    }

    case STR_security: {
        long newLevel = PkInfo2Int(&argv[1]);
        long currentLevel = GET_security(self);
        
        /* Security: privilege escalation from untrusted (1) to trusted (0) requires user approval */
        if (currentLevel > 0 && newLevel == 0) {
            if (notSecureWithPrompt(self, "elevate to trusted status")) {
                result->info.i = currentLevel;
                result->type = PKT_INT;
                result->canFree = 0;
                return 0;
            }
        }
        
        result->info.i = newLevel;
        helper_setSecurity(self, newLevel);
        result->type = PKT_INT;
        result->canFree = 0;
        return 1;
    }

    case STR_script: {
        union PCode* pcode = GET__script(self);
        StrInfo* si;

        GET_script(self)->refc--;
        if (GET_script(self)->refc <= 0) {
            Vfree(GET__memoryGroup(self), GET_script(self)->s);
            Vfree(GET__memoryGroup(self), GET_script(self));
        }
        result->info.s = VSaveString(GET__memoryGroup(self), PkInfo2Str(&argv[1]));
        si = (StrInfo*)malloc(sizeof(struct StrInfo));
        si->s = result->info.s;
        si->refc = 1;
        SET_script(self, si);
        result->type = PKT_STR;
        result->canFree = 0;
        if (pcode) {
            Vfree(GET__memoryGroup(self), pcode);
            SET__script(self, NULL);
        }
        return 1;
    }

    case STR_active:
        result->info.i = PkInfo2Int(&argv[1]);
        SET_active(self, result->info.i);
        result->type = PKT_INT;
        result->canFree = 0;
        return 1;
    }
    clearPacket(result);
    return 0;
}
long meth_generic_set(VObj* self, Packet* result, int argc, Packet argv[]) {
    return helper_generic_set(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

/* Scott */
/*
 * This routine forwards a Viola script message to the program
 * interface via the MessageHandler mechanism.
 */
long meth_generic_sendToInterface(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;
    char** arg;
    /* UI messages are needed for normal operation - not dangerous */
    
    arg = (char**)malloc(argc * sizeof(char*));

    for (i = 0; i < argc; i++)
        arg[i] = saveString(PkInfo2Str(&argv[i]));

    ViolaInvokeMessageHandler(arg, argc);

    for (i = 0; i < argc; i++)
        free(arg[i]);
    free(arg);

    return 1;
}

/*
 * isURLVisited(url)
 *
 * Check if URL is in the browsing history (for traversed link color).
 * Returns 1 if visited, 0 if not.
 */
long meth_generic_isURLVisited(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* url;
    void* dvi;
    
    clearPacket(result);
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = 0;
    
    if (argc < 1)
        return 1;
    
    url = PkInfo2Str(&argv[0]);
    if (!url || !*url)
        return 1;
    
    /* Check all document views for this URL in history */
    if (docViews) {
        Box* bp = docViews;
        while (bp) {
            dvi = bp->data;
            if (dvi && isURLInHistory(dvi, url)) {
                result->info.i = 1;
                return 1;
            }
            bp = bp->next;
        }
    }
    
    /* For standalone viola, check file-based history */
    if (isURLInHistory(NULL, url)) {
        result->info.i = 1;
    }
    
    return 1;
}

/*
 * setLinkColor(colorname)
 *
 * Set the color for unvisited links.
 * Called from STG stylesheet processing.
 */
long meth_generic_setLinkColor(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* colorname;
    
    clearPacket(result);
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = 0;
    
    if (argc < 1)
        return 1;
    
    colorname = PkInfo2Str(&argv[0]);
    if (colorname && *colorname) {
        GLSetLinkColor(colorname);
        result->info.i = 1;
    }
    
    return 1;
}

/*
 * setLinkVisitedColor(colorname)
 *
 * Set the color for visited links.
 * Called from STG stylesheet processing.
 */
long meth_generic_setLinkVisitedColor(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* colorname;
    
    clearPacket(result);
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = 0;
    
    if (argc < 1)
        return 1;
    
    colorname = PkInfo2Str(&argv[0]);
    if (colorname && *colorname) {
        GLSetLinkVisitedColor(colorname);
        result->info.i = 1;
    }
    
    return 1;
}

/*
 * resetLinkColors()
 *
 * Reset link colors to default (black).
 * Called when loading a new stylesheet to clear previous colors.
 */
long meth_generic_resetLinkColors(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = 1;
    
    GLResetLinkColors();
    
    return 1;
}

/*
 * addURLToHistory(url)
 *
 * Add URL to browsing history.
 * In VW mode, this is a no-op (VW handles history via message handlers).
 * In standalone viola, this persists to ~/.viola_history.
 */
long meth_generic_addURLToHistory(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* url;
    
    clearPacket(result);
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = 0;
    
    if (argc < 1)
        return 1;
    
    url = PkInfo2Str(&argv[0]);
    if (url && *url) {
        /* In standalone mode (docViews is NULL), persist to file */
        if (!docViews) {
            addURLToStandaloneHistory(url);
        }
        result->info.i = 1;
    }
    
    return 1;
}

long meth_generic_setResource(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc > 0 && notSecureWithPromptf(self, "set X11 resource: %s", PkInfo2Str(&argv[0])))
        return 0;
    return 0; /* no can't do */
}

/*
 * setSelection(value)
 *
 * Result:
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_setSelection(VObj* self, Packet* result, int argc, Packet argv[]) {
    GLSetSelection(self, SaveString(PkInfo2Str(&argv[0])));
    return 1;
}

/*
 * setVariable(attribute, value)
 *
 * Result:
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_setVariable(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* varName;
    char* varValue;
    
    if (argc < 2) {
        clearPacket(result);
        return 0;
    }
    
    varName = PkInfo2Str(&argv[0]);
    varValue = PkInfo2Str(&argv[1]);
    
    if (!varName || !varValue) {
        clearPacket(result);
        return 0;
    }
    
    /* Copy the value string since setVariable_STR may store it */
    varValue = saveString(varValue);
    
    SET__varList(self, setVariable_STR(GET__varList(self), varName, varValue, 1));
    
    clearPacket(result);
    return 1;
}

/*
 * setMouse(x, y)
 *
 * Result: the root offset
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_setMouse(VObj* self, Packet* result, int argc, Packet argv[]) {
    /*	Window w = PkInfo2Int(argv);*/
    long x = PkInfo2Int(&argv[0]);
    long y = PkInfo2Int(&argv[1]);
    /*
            if (!w) {
                    w = rootWindow;
            }
    */
    /* relative to root */
    clearPacket(result);
    XWarpPointer(display, None, rootWindow, 0, 0, 0, 0, (int)x, (int)y);

    return 1;
}

/*
 * shiftKeyP()
 *
 *
 * Result: shift key state
 * Return: 1
 */
long meth_generic_shiftKeyP(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->info.i = keyStat_shift;
    result->canFree = 0;
    return 1;
}

/*
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_sin(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_FLT;
    result->info.f = sinf(PkInfo2Flt(&argv[0]) * RADIAN_TO_DEGREE_RATIO);
    return 1;
}

/*
 * sleep(sec)
 *
 * Result: seconds slept
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_sleep(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = sleep((unsigned int)PkInfo2Int(&argv[0]));
    return 1;
}

/*
 * sprintf(format, argument [, ...])
 *
 * format print
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_sprintf(VObj* self, Packet* result, int argc, Packet argv[]) {
    char *fmt, *cp;
    char tempBuff[256];
    int argIdx = 1;
    int specCount = 0;
    size_t outLen = 0;

    result->type = PKT_STR;

    if (argc < 1) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    fmt = PkInfo2Str(&argv[0]);
    if (!fmt) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    /* Count format specifiers for runtime validation */
    for (cp = fmt; *cp; cp++) {
        if (*cp == '%' && *(cp + 1)) {
            cp++;
            if (*cp != '%') { /* %% is not a specifier */
                specCount++;
            }
        }
    }

    /* Warn if argument count doesn't match specifier count */
    if (specCount > argc - 1) {
        fprintf(stderr, "sprintf: warning: format expects %d arguments, but only %d provided\n",
                specCount, argc - 1);
    } else if (specCount < argc - 1) {
        fprintf(stderr, "sprintf: warning: format expects %d arguments, but %d provided (extra ignored)\n",
                specCount, argc - 1);
    }

    buff[0] = '\0';

    for (cp = fmt; *cp; cp++) {
        if (*cp == '%' && *(cp + 1)) {
            cp++;
            switch (*cp) {
            case 's':
                if (argIdx < argc) {
                    char *s = PkInfo2Str(&argv[argIdx++]);
                    if (s) strcat(buff, s);
                } else {
                    strcat(buff, "(null)");
                }
                break;
            case 'd':
            case 'i':
                if (argIdx < argc) {
                    snprintf(tempBuff, sizeof(tempBuff), "%ld", 
                             PkInfo2Int(&argv[argIdx++]));
                    strcat(buff, tempBuff);
                } else {
                    strcat(buff, "0");
                }
                break;
            case 'f':
                if (argIdx < argc) {
                    snprintf(tempBuff, sizeof(tempBuff), "%f", 
                             PkInfo2Flt(&argv[argIdx++]));
                    strcat(buff, tempBuff);
                } else {
                    strcat(buff, "0.000000");
                }
                break;
            case 'c':
                if (argIdx < argc) {
                    char c = PkInfo2Char(&argv[argIdx++]);
                    outLen = strlen(buff);
                    buff[outLen] = c;
                    buff[outLen + 1] = '\0';
                } else {
                    strcat(buff, "?");
                }
                break;
            case '%':
                outLen = strlen(buff);
                buff[outLen] = '%';
                buff[outLen + 1] = '\0';
                break;
            default:
                /* Unknown format specifier - output as-is */
                outLen = strlen(buff);
                buff[outLen] = '%';
                buff[outLen + 1] = *cp;
                buff[outLen + 2] = '\0';
                break;
            }
        } else {
            outLen = strlen(buff);
            buff[outLen] = *cp;
            buff[outLen + 1] = '\0';
        }
    }

    result->info.s = SaveString(buff);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/*
 * str(argument [, ...])
 *
 * Result: arguments in string type
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_str(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_STR;
    result->info.s = PkInfos2Str(argc, argv);
    result->canFree = 0;
    return 1;
}

/*
 * strlen(str)
 */
/*
 * Result: strlen
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_strlen(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->type = PKT_INT;
    result->info.i = (long)strlen(PkInfos2Str(argc, argv));
    return 1;
}

/*
 * system(cmdline1 [, cmdline2 , ...])
 *
 * Call to the system(3) call.
 *
 * Result: return value from system()
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_system(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;
    char reasonBuf[1024];
    size_t pos = 0;

    pos = (size_t)snprintf(reasonBuf, sizeof(reasonBuf), "system(");
    for (i = 0; i < argc && pos < sizeof(reasonBuf) - 10; i++) {
        char* cmd = PkInfo2Str(&argv[i]);
        if (i > 0) pos += (size_t)snprintf(reasonBuf + pos, sizeof(reasonBuf) - pos, ", ");
        pos += (size_t)snprintf(reasonBuf + pos, sizeof(reasonBuf) - pos, "\"%s\"", cmd ? cmd : "");
    }
    snprintf(reasonBuf + pos, sizeof(reasonBuf) - pos, ")");
    
    if (notSecureWithPrompt(self, reasonBuf))
        return 0;

    clearPacket(result);
    result->type = PKT_INT;
    for (i = 0; i < argc; i++)
        result->info.i = system(PkInfo2Str(&argv[i]));

    return 1;
}

/*
 * target()
 *
 * Return the object that was mark()'ed.
 *
 * Result: target object
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_target(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;

    result->info.o = VTargetObj;
    result->type = PKT_OBJ;
    result->canFree = 0;
    if (argc == 0) {
        return 1;
    }
    cp = PkInfo2Str(&argv[0]);
    if (cp)
        if ((VTargetObj = findObject(getIdent(cp)))) {
            sendMessage1(VResourceObj, "targetSet");
            result->info.o = VTargetObj;
            result->type = PKT_OBJ;
            result->canFree = 0;
            return 1;
        }
    return 0;
}

long meth_generic_textWidth(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.i = GLTextWidth(PkInfo2Int(&argv[0]), PkInfo2Str(&argv[1]));
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

long meth_generic_trimEdge(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.s = trimEdgeSpaces(SaveString(PkInfo2Str(&argv[0])));
    result->type = PKT_STR;
    result->canFree = PK_CANFREE_STR;
    return 1;
}

long meth_generic_trimEdgeQ(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* NOTE: since the returned data isn't copied, argv can no longer
     * think this data may be canFree. Because, if that were so,
     * upon return to the interpreter, argv->info.s will be freed,
     * and that leaves result->info.s pointing to freed memory
     */
    /*	if (argv[0].canFree) {
                    printf("Potential leak!! in meth_generic_trimEdgeQ()\n");
            }
    */
    result->canFree = 0;
    argv[0].canFree = 0;

    result->info.s = trimEdgeSpaces(PkInfo2Str(&argv[0]));
    result->type = PKT_STR;

    return 1;
}

/*
 * time()
 *
 * Result: elapsed seconds since 00:00:00 GMT, January 1, 1970
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_time(VObj* self, Packet* result, int argc, Packet argv[]) {
    time_t theTime;
    result->info.i = time(&theTime);
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 * tool([tool name]);
 *
 * Tool name: "action", "move", "reparent", "resize", "target"
 * if no argument is given, the current tool is returned.
 *
 * Result: name of the selected/current tool
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_tool(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;
    char* cp;

    result->type = PKT_STR;
    if (argc == 0) {
        result->info.s = toolID2Str[currentTool];
        result->canFree = 0;
        return 1;
    }
    if ((cp = PkInfos2Str(argc, argv))) {
        for (i = 0; toolID2Str[i]; i++) {
            if (!strcmp(cp, toolID2Str[i])) {
                currentTool = i;
                result->info.s = toolID2Str[currentTool];
                result->canFree = 0;
                return 1;
            }
        }
    }
    result->info.s = "";
    result->canFree = 0;
    return 0;
}

long meth_generic_unhash(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPromptf(self, "get symbol name for ID: %ld", PkInfo2Int(&argv[0])))
        return 0;
    clearPacket(result);
    result->info.s = (char*)symID2Str->get(symID2Str, (PkInfo2Int(&argv[0])))->val;
    result->type = PKT_STR;
    result->canFree = 0;
    return 1;
}

/*
 * version();
 *
 * Return the Viola version identifier string.
 *
 * Result: version string
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_version(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern char* viola_version; /* defined in main.c */
    result->info.s = viola_version;
    result->type = PKT_STR;
    result->canFree = 0;
    return 1;
}

/*
 * violaPath(str)
 *
 * Set a new path for searching viola object files.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_violaPath(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (argc == 0) {
        int i = 0;
        extern char* viola_path[];

        result->type = PKT_STR;
        buff[0] = '\0';
        while (viola_path[i]) {
            strcat(buff, viola_path[i]);
            if (viola_path[++i])
                strcat(buff, " ");
        }
        result->info.s = SaveString(buff);
        result->canFree = PK_CANFREE_STR;
    } else if (argc == 1) {
        /* Security: untrusted objects cannot modify object search path */
        if (notSecureWithPromptf(self, "set object path: %s", PkInfo2Str(&argv[0])))
            return 0;
        result->type = PKT_INT;
        result->canFree = 0;
        if ((result->info.i = setViolaPath(PkInfo2Str(&argv[0]))) > 0)
            return 1;
    }
    return 0;
}

/*
 * x()
 *
 * Result: self's x position
 */
long meth_generic_x(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.i = GET_x(self);
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 * watch(flag)
 *
 * Specifies variable tracking flags. NOT YET IMPLEMENTED.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_watch(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern int flag_vwatch; /* defined in cexec.c */

    clearPacket(result);
    flag_vwatch = (int)PkInfo2Int(&argv[0]);

    return 1;
}

/*
 * width()
 *
 * Result: self's width
 */
long meth_generic_width(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.i = GET_width(self);
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 *
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_generic_writeln(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (meth_generic_print(self, result, argc, argv)) {
        printf("\n");
        return 1;
    } else {
        return 0;
    }
}

/*
 * y()
 *
 * Result: self's y position
 */
long meth_generic_y(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.i = GET_y(self);
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/* USE WITH EXTREME CAUTION. kludge for text-inlined images
 *
 * (obj)arg[0] 's __content us used to store pic list.
 * (char*)arg[1] is filepath of picture
 */
long meth_generic_addPicFromFile(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj* obj = PkInfo2Obj(&argv[0]);
    int picID;
    TFPic *pics, *pic;
    char* fname = PkInfo2Str(&argv[1]);

    /* Security check: untrusted object loading local file is dangerous */
    if (notSecure(self) && fname && isLocalAddress(fname)) {
        if (notSecureWithPromptf(self, "load local image: %s", fname)) {
            result->type = PKT_INT;
            result->canFree = 0;
            result->info.i = 0;
            return 0;
        }
    }

    pics = (TFPic*)GET__content(obj);
    pic = tfed_addPicFromFile(&pics, fname /*should be URL*/, fname);
    SET__content(obj, pics);

    picID = pic->id;

    result->type = PKT_INT;
    result->canFree = 0;
    result->info.i = picID;

    return 1;
}

/**
 ** Major ViolaWWW kludge .. er, optimization methods
 **/
/*
 * HTML_txt object script equivalent method
 */
long meth_generic_code_HTML_txt(VObj* self, Packet* result, int argc, Packet argv[]) {
    Packet* arg0 = (Packet*)((Attr*)(argv[0].info.a)->val);
    char* mesg;
    int vspan;
    SGMLTagMappingInfo* tmi;
    char *text, *s;

    if (arg0->type == PKT_INT /*XXX TOK*/) {

        if (arg0->info.i == STR_D) {

            /* Viola script:
             */
            /*************************************************************
             * switch (arg[0]) {
             * case 'D':
             *	txt = send(parent(), "data");
             *	if (isBlank(txt)) {
             *		style = SGMLGetStyle("HTML", "P");
             *		return (style[0] + style[1]);
             *	} else {
             *		set("content", txt);
             *		style = SGMLGetStyle("HTML", "P");
    NOT TRUE ANYMORE.
             *		return (style[0] + building_vspan() + style[1]);
    IS NOW: need to clean up.
             *		return building_vspan();
             *	}
             * break;
             ************************************************************/

            /* Equivalent C code:
             */
            TFStruct* tf = GET__TFStruct(self);
            Packet *pk, evalResult;

            nullPacket(&evalResult);

            if (GET__parent(self)) {
                sendMessage1_result(GET__parent(self), "data", &evalResult);
                text = evalResult.info.s;

                if (evalResult.type == PKT_INT) {
                    /* if it's a number, then no data, but offset-y
                     * to make insertion. kludge allert!XXX
                     */
                    SET_y(self, GET_y(self) + evalResult.info.i);

                    /* return some reasonable height for this
                     * empty paragraph... probably inserted (in
                     * HTML) to get vertical space. ...
                     */
                    freePossibleDangler(result);
                    result->info.i = 10;
                    result->type = PKT_INT;
                    return 1;
                }
                if (!text) {
                    return 0;
                }
                if ((evalResult.canFree & PK_CANFREE_STR) == 0) {
                    text = saveString(evalResult.info.s);
                }

                if (*text == '\0') {

                    tmi = (SGMLTagMappingInfo*)GET__content2(self);
                    freePossibleDangler(&evalResult);
                    result->info.i = tmi->top + tmi->bottom;
                    result->type = PKT_INT;

                } else {
                    if (GET_content(self))
                        Vfree(GET__memoryGroup(self), GET_content(self));

                    /* eliminate leading space */
                    for (s = text; *s; s++)
                        if (!isspace((unsigned char)*s))
                            break;

                    SET_content(self, s);
                    tf = tfed_updateTFStruct(self, s);
                    if (!tf)
                        return 0;

                    vspan = tf->building_vspan + tf->yUL + 2;

                    clearPacket(&evalResult);

                    tmi = (SGMLTagMappingInfo*)GET__content2(self);

                    result->info.i = tmi->top + vspan;

                    result->type = PKT_INT;
                }
                return 1;
            } else {
                return 0;
            }
        }

        /*************************************************************
         * usual();
         ************************************************************/
        return meth_cosmic_usual(self, result, 0, argv);
    }
    mesg = PkInfo2Str(arg0);

    if (*mesg == 'R') {

        /*************************************************************
         * case 'R':
         * 	clearWindow();
         * 	style = SGMLGetStyle("HTML", "P");
         *	vspan = style[0];
         *	set("y", arg[1] + vspan);
         *	set("x", style[2]);
         *	set("width", arg[2] - x() - style[3]);
         *	set("content", get("content"));
         *	vspan = vspan + set("height", building_vspan()) + style[1];
         *	render();
         *	return vspan;
         * break;
         ************************************************************/

        Packet* arg1 = (Packet*)((Attr*)(argv[0].info.a)->next->val);
        Packet* arg2 = (Packet*)((Attr*)(argv[0].info.a)->next->next->val);
        TFStruct* tf = GET__TFStruct(self);
        SGMLDocMappingInfo* dmi = NULL;
        XWindowChanges wc;

        tmi = (SGMLTagMappingInfo*)GET__content2(self);
        if (!tmi) {
            int i;
            for (i = 0; SGMLForms[i].DTDName; i++) {
                if (!strcmp(SGMLForms[i].DTDName, "HTML")) {
                    dmi = &SGMLForms[i];
                    break;
                }
            }
            tmi = findTMI(dmi, "P");
            SET__content2(self, tmi);
        }

        vspan = tmi->top;

        SET_y(self, arg1->info.i + vspan);
        SET_x(self, tmi->left);
        SET_width(self, arg2->info.i - tmi->left - tmi->right);

        tf = tfed_updateTFStruct(self, GET_content(self));
        if (!tf)
            return 0;

        SET_height(self, tf->building_vspan + tf->yUL);

        if (GET_window(self)) {
            wc.x = (int)GET_x(self);
            wc.y = (int)GET_y(self);
            wc.width = (int)GET_width(self);
            wc.height = (int)GET_height(self);
            XConfigureWindow(display, GET_window(self), CWX | CWY | CWWidth | CWHeight, &wc);
        }
        vspan += GET_height(self) + tmi->bottom;

        meth_txtDisp_render(self, result, 0, result);

        freePossibleDangler(result);
        result->info.i = vspan;
        result->type = PKT_INT;
        result->canFree = 0;
        return 1;

    } else if (!strcmp(mesg, "setRef")) {

        /*************************************************************
         * case "setRef":
         *	return;
         * break;
         ************************************************************/
        return 1;

    } else if (!strcmp(mesg, "make")) {

        /*************************************************************
         * case "make":
         *	 * arg[1]	parent
         *	 * arg[2]	data
         *	 * arg[3]	x
         *	 * arg[4]	width
         *	 * arg[5]	y
         *	 * arg[6]	anchorName
         *	 *
         *	set("parent", arg[1]);
         *	set("x", arg[3]);
         *	set("y", arg[5]);
         *	set("width", arg[4]);
         *	set("content", arg[2]);
         *	h = building_vspan();
         *	set("height", h);
         *	set("maxHeight", h);
         *	style = SGMLGetStyle("HTML", "P");
         *	h = style[0] + h + style[1];
         *	if (arg[6]) set("content2", arg[6]);
         *	return h;
         * break;
         ************************************************************/

        Packet *arg1, *arg2, *arg3, *arg4, *arg5, *arg6;
        TFStruct* tf = GET__TFStruct(self);
        SGMLDocMappingInfo* dmi = NULL;
        int vspan;
        Attr *attr, *varlist = GET__varList(self);
        Packet *pk, evalResult;
        long inPreP = 0;
        VObj* parent;
        int mask;

        nullPacket(&evalResult);

        attr = argv[0].info.a;
        arg1 = (Packet*)(attr->next->val);
        arg2 = (Packet*)(attr->next->next->val);
        arg3 = (Packet*)(attr->next->next->next->val);
        arg4 = (Packet*)(attr->next->next->next->next->val);
        arg5 = (Packet*)(attr->next->next->next->next->next->val);
        arg6 = (Packet*)(attr->next->next->next->next->next->next->val);

        parent = (VObj*)arg1->info.i;

        pk = (Packet*)getVariable_id(varlist, STR_inPreP);
        if (pk) {
            inPreP = PkInfo2Int(pk);
        } else {
            /* find out and set inPreP */
            if (parent) {
                sendMessage1_result(parent, "inPreP", &evalResult);
                inPreP = PkInfo2Int(&evalResult);
            } else {
                inPreP = 0;
            }
        }

        SET__parent(self, parent);

        SET_x(self, arg3->info.i);

        SET_y(self, arg5->info.i);

        SET_width(self, arg4->info.i);

        if (GET_content(self))
            Vfree(GET__memoryGroup(self), GET_content(self));

        if (arg2->canFree & PK_CANFREE_STR) {
            text = arg2->info.s;
            if (!inPreP) {
                /* eliminate leading space */
                for (; *text; text++)
                    if (!isspace((unsigned char)*text))
                        break;
            }
            arg2->canFree = 0;
            arg2->info.s = NULL;
        } else {
            /* eliminate leading space */
            s = arg2->info.s;
            if (!inPreP) {
                /* eliminate leading space */
                for (; *s; s++)
                    if (!isspace((unsigned char)*s))
                        break;
            }
            text = saveString(s);
        }
        SET_content(self, text);
        tf = tfed_updateTFStruct(self, text);
        if (!tf)
            return 0;

        vspan = tf->building_vspan + tf->yUL + 2;

        SET_height(self, vspan);
        SET_maxHeight(self, vspan);

        tmi = (SGMLTagMappingInfo*)GET__content2(self);
        if (!tmi) {
            int i;
            for (i = 0; SGMLForms[i].DTDName; i++) {
                if (!strcmp(SGMLForms[i].DTDName, "HTML")) {
                    dmi = &SGMLForms[i];
                    break;
                }
            }
            tmi = findTMI(dmi, "P");
            SET__content2(self, tmi);
        }

        mask = GET__eventMask(self) | PointerMotionMask;
        SET__eventMask(self, mask);

        vspan += tmi->top + tmi->bottom;

        if (arg6->info.s)
            SET_content2(self, arg6->info.s);

        result->info.i = vspan;
        result->type = PKT_INT;
        return 1;

    } else if (!strcmp(mesg, "config")) {

        /*************************************************************
         * case "config":
         *	return;
         * break;
         ************************************************************/
        return 1;

    } else if (!strcmp(mesg, "clone")) {

        return txtDisp_HTML_txt_clone(self, result, argv);

#ifdef NOT_CORRECT

    } else if (!strcmp(mesg, "gotoAnchor")) {

        /*************************************************************
XXXX INVALID
         * case "gotoAnchor":
         *	if (arg[1] == get("content2")) return y();
         * 	n = countChildren();
         *	if (n > 0) {
         *		for (i = 0; i < n; i = i + 1) {
         *			offset = send(nthChild(i),
         *					"gotoAnchor", arg[1]);
         *			if (offset > 0) return offset;
         *		}
         *	}
         *	return 0;
         * break;
         ************************************************************/

        Packet* arg1 = (Packet*)((Attr*)(argv[0].info.a)->next->val);
        VObjList* olist;
        long offset = 0;
        char* anchor = arg1->info.s;
        Packet evalResult;

        nullPacket(&evalResult);

        if (!strcmp(anchor, GET_content2(self))) {
            result->info.i = GET_y(self);
            result->type = PKT_INT;
            result->canFree = 0;
            return 1;
        }

        for (olist = GET__children(self); olist; olist = olist->next) {
            sendMessage1N1str(olist->o, "gotoAnchor", anchor);
            if (offset = PkInfo2Int(&evalResult))
                break;
        }
        clearPacket(&evalResult);
        result->info.i = offset;
        result->type = PKT_INT;
        result->canFree = 0;
        return 1;
#endif
    } else if (!strcmp(mesg, "follow_href")) {
        /* return send(parent(), "show_request_by_child",
         * 		arg[1], docURL);
         */
        Packet* arg1 = (Packet*)((Attr*)(argv[0].info.a)->next->val);
        Attr* varlist = GET__varList(self);
        Packet* pk;

        pk = (Packet*)getVariable_id(varlist, STR_docURL);
        if (pk) {
            if (pk->info.s && arg1->info.s) {
                sendMessage1N2str(GET__parent(self), "show_request_by_child", arg1->info.s,
                                  pk->info.s);
            }
        }
        return 1;

    } else if (!strcmp(mesg, "buttonRelease")) {

        return txtDisp_HTML_txt_buttonRelease(self, result, argv);

    } else if (!strcmp(mesg, "expose")) {
        /*************************************************************
         * just to cut thru usual() script etc... for faster response.
         ************************************************************/
        return txtDisp_HTML_txt_expose(self, result, argv);
    }

    /*************************************************************
     * usual();
     ************************************************************/
    return meth_cosmic_usual(self, result, 0, argv);
}

long meth_generic_code_HTML_txtAnchor(VObj* self, Packet* result, int argc, Packet argv[]) {
    return 1;
}

/*
 * HTML_header_large object script equivalent method
 */
long meth_generic_code_HTML_header_large(VObj* self, Packet* result, int argc, Packet argv[]) {
    Packet* arg0 = (Packet*)((Attr*)(argv[0].info.a)->val);
    char* mesg;
    int vspan;
    SGMLTagMappingInfo* tmi;
    char* text;

    if (arg0->type == PKT_INT) {
        if (arg0->info.i == STR_D) {
            return txtDisp_HTML_header_D(self, result, argv);
        } else if (arg0->info.i == STR_F) {
            freePossibleDangler(result);
            result->info.i = -1;
            result->type = PKT_INT;
            result->canFree = 0;
            return 1;
        }
        return meth_cosmic_usual(self, result, 0, argv);
    }

    mesg = PkInfo2Str(arg0);

    if (*mesg == 'R') {
        return txtDisp_HTML_header_R(self, result, argv, "H1");
    } else if (*mesg == 'A') {
        return txtDisp_HTML_header_A(self, result, argv);
    } else if (!strcmp(mesg, "clone")) {
        return txtDisp_HTML_txt_clone(self, result, argv);
    } else if (!strcmp(mesg, "setRef")) {
        return 1;
    } else if (*mesg == 'I') {
        return 1;
    } else if (!strcmp(mesg, "config")) {
        return 1;
    } else if (!strcmp(mesg, "gotoAnchor")) {
        return 0;
    } else if (!strcmp(mesg, "buttonRelease")) {
        return txtDisp_HTML_txt_buttonRelease(self, result, argv);
    } else if (!strcmp(mesg, "expose")) {
        /* just to cut thru usual() script etc for faster response */
        return txtDisp_HTML_txt_expose(self, result, argv);
    }
    return meth_cosmic_usual(self, result, 0, argv);
}

/*
 * HTML_header_medium object script equivalent method
 */
long meth_generic_code_HTML_header_medium(VObj* self, Packet* result, int argc, Packet argv[]) {
    return meth_generic_code_HTML_header_large(self, result, argc, argv);
}

/*
 * HTML_header_small object script equivalent method
 */
long meth_generic_code_HTML_header_small(VObj* self, Packet* result, int argc, Packet argv[]) {
    return meth_generic_code_HTML_header_large(self, result, argc, argv);
}
