/*
 * Copyright 1990 1991 Pei-Yuan Wei.  All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */
/*
 * class        : cosmic
 * superClass	: NULL
 */
#include "cl_cosmic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cexec.h"
#include "class.h"
#include "classlist.h"
#include "event_x.h"
#include "glib_x.h"
#include "hash.h"
#include "ident.h"
#include "misc.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "slotaccess.h"

/* test4, for math */
#include "htmath.h"

#include "cgen.h"
#include "html2.h"
#include "loader.h"
#include "method.h"
#include "viola.h"

/*
 * Security dialog callback - registered by VW frontend.
 * Returns 1 if user allows, 0 if user denies.
 */
static SecurityDialogCallback g_securityDialogCallback = NULL;

/* Trusted documents list - URLs that user has approved */
#define MAX_TRUSTED_DOCS 64
static char* trustedDocs[MAX_TRUSTED_DOCS];
static int trustedDocsCount = 0;

/*
 * isLocalAddress() - check if address refers to local filesystem.
 * 
 * Returns 1 if address is local:
 *   1. Starts with "file://"
 *   2. Starts with "/" (absolute Unix path)
 *   3. Has no ":" before first "/" or no ":" at all (relative path, no protocol)
 * 
 * Returns 0 if address is remote (has protocol like http://, ftp://, gopher://, etc.)
 */
int isLocalAddress(const char* addr)
{
    const char* colon;
    const char* slash;
    
    if (!addr || !*addr) return 0;
    
    /* 1. Explicit file:// protocol */
    if (strncmp(addr, "file://", 7) == 0) return 1;
    
    /* 2. Absolute Unix path */
    if (addr[0] == '/') return 1;
    
    /* 3. Check for protocol: if ":" exists, it must be after first "/" */
    colon = strchr(addr, ':');
    if (colon == NULL) {
        /* No colon = no protocol = relative local path */
        return 1;
    }
    
    slash = strchr(addr, '/');
    if (slash == NULL) {
        /* Colon exists but no slash - could be "C:" on Windows or protocol without path */
        /* Treat as protocol (e.g., "mailto:foo") - not local */
        return 0;
    }
    
    /* If colon comes after first slash, it's not a protocol (e.g., "/path/to:file") */
    if (colon > slash) return 1;
    
    /* Colon before slash = protocol (e.g., "http://...") */
    return 0;
}

static int isDocumentTrusted(const char* url)
{
    int i;
    if (!url) return 0;
    for (i = 0; i < trustedDocsCount; i++) {
        if (trustedDocs[i] && strcmp(trustedDocs[i], url) == 0)
            return 1;
    }
    return 0;
}

static void addTrustedDocument(const char* url)
{
    if (!url || trustedDocsCount >= MAX_TRUSTED_DOCS) return;
    if (isDocumentTrusted(url)) return;  /* already trusted */
    trustedDocs[trustedDocsCount++] = strdup(url);
}

void ViolaRegisterSecurityCallback(SecurityDialogCallback callback)
{
    g_securityDialogCallback = callback;
}

/*
 * notSecure() - check if object has restricted security level.
 * Returns 1 if untrusted (operation should be blocked), 0 if trusted.
 * Does NOT prompt user - use notSecureWithPrompt() for that.
 */
int notSecure(VObj* self)
{
    /* NULL object is treated as untrusted */
    if (self == NULL) return 1;
    
    if (GET_security(self) > 0) {
        return 1;
    }
    return 0;
}

/*
 * notSecureWithPrompt() - check security with user confirmation dialog.
 * If object is untrusted and callback is registered, asks user for permission.
 * Returns 1 if operation should be blocked, 0 if allowed.
 */
int notSecureWithPrompt(VObj* self, const char* operation)
{
    extern char* current_addr;  /* from html.c */
    const char* objName;
    int userAllowed;
    int secLevel;
    
    /* Check if document is already trusted */
    if (current_addr && isDocumentTrusted(current_addr)) {
        return 0;  /* Document trusted - allow */
    }
    
    /* NULL object is treated as untrusted */
    if (self == NULL) {
        objName = "(null)";
        secLevel = 1;
    } else {
        secLevel = GET_security(self);
        objName = GET_name(self);
        
        if (secLevel == 0) {
            return 0;  /* Trusted - allow */
        }
    }
    
    /* Object is untrusted - ask user if callback is registered */
    if (g_securityDialogCallback) {
        userAllowed = g_securityDialogCallback(
            "Privilege Elevation Request",
            NULL,  /* message built in dialog.c */
            operation,
            objName);
        
        if (userAllowed) {
            /* Trust the entire document, not just this object */
            if (current_addr) {
                addTrustedDocument(current_addr);
            }
            /* Also elevate privileges for this object */
            if (self) {
                SET_security(self, 0);
            }
            return 0;  /* User allowed - don't block */
        }
    }
    
    /* No callback or user denied - block */
    return 1;
}

SlotInfo cl_cosmic_NCSlots[] = {{STR_class, PTRS | SLOT_RW, (long)"cosmic"},
                                {
                                    STR_classScript,
                                    PTRS,
                                    (long)"\n\
		switch (arg[0]) {\n\
		case \"config\":\n\
			config(arg[1], arg[2], arg[3], arg[4]);\n\
		break;\n\
		case \"expose\":\n\
		case \"render\":\n\
			expose(arg[1], arg[2], arg[3], arg[4]);\n\
			render();\n\
		break;\n\
		case \"init\":\n\
			initialize();\n\
		break;\n\
		case \"freeSelf\":\n\
			freeSelf();\n\
		break;\n\
		default:\n\
			print(\"unknown message, clsss = cosmic: args: \");\n\
			for (i =0; i < arg[]; i++) print(arg[i], \", \");\n\
			print(\"\\n\");\n\
			break;\n\
		}\n\
	",
                                },
                                {
                                    STR__classScript,
                                    PCOD,
                                    0,
                                },
                                {0}};
SlotInfo cl_cosmic_NPSlots[] = {{STR__classInfo, CLSI, (long)&class_cosmic},
                                {
                                    STR__memoryGroup,
                                    PTRV,
                                    0,
                                },
                                {0}};
SlotInfo cl_cosmic_CSlots[] = {0};
SlotInfo cl_cosmic_PSlots[] = {0};

SlotInfo* slots_cosmic[] = {(SlotInfo*)cl_cosmic_NCSlots, (SlotInfo*)cl_cosmic_NPSlots,
                            (SlotInfo*)cl_cosmic_CSlots, (SlotInfo*)cl_cosmic_PSlots};

MethodInfo meths_cosmic[] = {{STR_clone, meth_cosmic_clone},
                             {STR_clone2, meth_cosmic_clone2},
                             {STR_cloneID, meth_cosmic_cloneID},
                             {STR_create, meth_cosmic_create},
                             {STR_debug, meth_cosmic_debug},
                             {STR_detach, meth_cosmic_detach},
                             {STR_destroy, meth_cosmic_destroy},
                             {STR_exit, meth_cosmic_exit},
                             {STR_exist, meth_cosmic_exist},
                             {STR_freeSelf, meth_cosmic_freeSelf},
                             {STR_info, meth_cosmic_info},
                             {STR_interpret, meth_cosmic_interpret},
                             {STR_loadObjFile, meth_cosmic_loadObjFile},
                             {STR_modalExit, meth_cosmic_modalExit},
                             {STR_object, meth_cosmic_object},
                             {STR_pop, meth_cosmic_pop},
                             {STR_push, meth_cosmic_push},
                             {STR_quit, meth_cosmic_quit},
                             {STR_save, meth_cosmic_save},
                             {STR_saveAs, meth_cosmic_saveAs},
                             {STR_send, meth_cosmic_send},
                             {STR_test1, meth_cosmic_test1},
                             {STR_test2, meth_cosmic_test2},
                             {STR_test3, meth_cosmic_test3},
                             {STR_test4, meth_cosmic_test4},
                             {STR_tweak, meth_cosmic_tweak},
                             {STR_usual, meth_cosmic_usual},
                             {0}};

ClassInfo class_cosmic = {
    helper_cosmic_get,
    helper_cosmic_set,
    slots_cosmic, /* class slot information	*/
    meths_cosmic, /* class methods		*/
    STR_cosmic,   /* class identifier number	*/
    NULL,         /* super class			*/
};

int global_cloneID = 0;

void sendInitToChildren(VObj* self) {
    Packet* result = borrowPacket();
    VObjList* olist;

    if (!callMeth(self, result, 0, NULL, STR_initialize)) {
        fprintf(stderr, "clone ``%s''not properly initialized\n", GET_name(self));
        /* error */
    }
    for (olist = GET__children(self); olist; olist = olist->next)
        if (olist->o)
            sendInitToChildren(olist->o);

    returnPacket();
}

long helper_cosmic_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {
    return 0;
}

long helper_cosmic_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {
    return 0;
}

/*
 * clone(clone name suffix)
 *
 * Make a clone self
 *
 * Result: clone object, and optinally name it
 * Return: 1 if successful, 0 if error occured
 */
long meth_cosmic_clone(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj* cloneObj;

    if (!meth_cosmic_clone2(self, result, argc, argv))
        return 0;
    cloneObj = result->info.o;
    if (cloneObj) {
        sendInitToChildren(cloneObj);
        result->type = PKT_OBJ;
        result->info.o = cloneObj;
        result->canFree = 0;
        return 1;
    }
    result->type = PKT_OBJ;
    result->info.o = NULL;
    result->canFree = 0;
    return 0;
}

/* Debug flag for clone/freeSelf tracing */
#define DEBUG_CLONE 0

long meth_cosmic_clone2(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* suffix;
    VObj* cloneObj;
    char *sp1, *sp2, newName[255];

    cloneObj = clone(self);

    suffix = PkInfo2Str(&argv[0]);
    if (!cloneObj || !suffix) {
        result->type = PKT_OBJ;
        result->info.o = NULL;
        result->canFree = 0;
        return 0;
    }

    /*XXX later, put class mg size in class public space */
    /*	SET__memoryGroup(cloneObj, newMemoryGroup(512));
     */
    /*sprintf(newName, "%s%s", GET_name(cloneObj), suffix);
     */
    for (sp1 = newName, sp2 = GET_name(cloneObj); *sp2;)
        *sp1++ = *sp2++;
    for (sp2 = suffix; *sp2;)
        *sp1++ = *sp2++;
    *sp1++ = '\0';

    SET_name(cloneObj, saveStringN(newName, (int)(sp1 - newName)));

    objID2Obj->put_replace(objID2Obj, storeIdent(saveString(GET_name(cloneObj))), (long)cloneObj);

    objObj2ExistP->put_replace(objObj2ExistP, (long)cloneObj, (int)1);

#if DEBUG_CLONE
    fprintf(stderr, "CLONE: '%s' -> '%s' (orig=%p, clone=%p)\n",
            GET_name(self) ? GET_name(self) : "(null)",
            newName,
            (void*)self, (void*)cloneObj);
#endif

    result->type = PKT_OBJ;
    result->info.o = cloneObj;
    result->canFree = 0;
    return 1;
}

long meth_cosmic_cloneID(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.i = global_cloneID++;
    result->type = PKT_INT;
    result->canFree = 0;
    return 1;
}

/*
 * create(<attributes list>)
 *
 * Result: created object
 * Return: 1 if successful, 0 if error occured
 */
long meth_cosmic_create(VObj* self, Packet* result, int argc, Packet argv[]) {
    long slotv[100][2];
    int slotc = 0, i;
    char* cp;
    HashEntry* entry;
    VObj* obj;

    result->type = PKT_OBJ;
    result->info.o = NULL;

    for (slotc = 0, i = 0; i < argc; slotc++, i += 2) {
        cp = PkInfo2Str(&argv[i]);
        if (!cp) {
            printf("create(): unknown attribute:");
            dumpPacket(&argv[i]);
            printf("\n");
            return 0;
        }
        entry = symStr2ID->get(symStr2ID, (long)cp);
        if (!entry) {
            printf("create(): unknown attribute: \"%s\"\n", cp);
            return 0;
        }
        slotv[slotc][0] = (long)(entry->val);
        slotv[slotc][1] = (long)saveString(PkInfo2Str(&argv[i + 1]));
    }
    if (slotc <= 0)
        return 0;

    if ((obj = instantiateObj(&slotv, &slotc))) {
        objID2Obj->put_replace(objID2Obj, storeIdent(saveString(GET_name(obj))), (long)obj);
        objObj2ExistP->put_replace(objObj2ExistP, (long)obj, 1);
        /*		SET__memoryGroup(obj, newMemoryGroup(1024));
         */
        sendMessage1(obj, "init");
        freePossibleDangler(result);
        result->type = PKT_OBJ;
        result->info.o = obj;
        result->canFree = 0;
        return 1;
    } else {
        fprintf(stderr, "create(): failed to create object.\n");
        return 0;
    }
}

/*
 * detach()
 *
 *
 * Result:
 * Return:
 */
long meth_cosmic_detach(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

/*
 * debug()
 *
 * Used to turn on/off various debugging flags.
 *
 * Result:
 * Return:
 */
long meth_cosmic_debug(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    if (!strcmp(PkInfo2Str(&argv[0]), "pa")) {
        extern int flag_printAST;
        flag_printAST = (int)PkInfo2Int(&argv[1]);
    } else if (!strcmp(PkInfo2Str(&argv[0]), "pc")) {
        extern int flag_printPCode;
        flag_printPCode = (int)PkInfo2Int(&argv[1]);
    } else if (!strcmp(PkInfo2Str(&argv[0]), "pe")) {
        extern int flag_printExec;
        flag_printExec = (int)PkInfo2Int(&argv[1]);
    } else if (!strcmp(PkInfo2Str(&argv[0]), "dumpPCode")) {
        long pc = 0;
        union PCode* pcode = GET__script(self);

        printPCode(&pcode[PCODE_IDX_INSTR], &pc, pcode[PCODE_IDX_SIZE].i);
    }
    return 1;
}

/*
 * destroy()
 *
 *
 * Result:
 * Return:
 */
long meth_cosmic_destroy(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPrompt(self, "destroy object"))
        return 0;
    clearPacket(result);
    free(self);
    /* and remove from object list...*/
    return 1;
}

/*
 * exit(value)
 *
 * Exit viola with specified value.
 *
 * Result: n/a
 * Return: n/a
 */
long meth_cosmic_exit(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPrompt(self, "exit application"))
        return 0;

    exit((int)PkInfo2Int(&argv[0]));
}

/*
 * exist(<obj name>)
 *
 * Determines whether if an object is currently loaded.
 *
 * Result:
 * Return:
 */
long meth_cosmic_exist(VObj* self, Packet* result, int argc, Packet argv[]) {
    HashEntry* entry;
    VObj* obj = PkInfo2Obj(&argv[0]);

    result->type = PKT_INT;
    result->canFree = 0;

    if (obj) {
        if ((entry = objObj2ExistP->get(objObj2ExistP, (long)obj))) {
            result->info.i = 1;
            return 1;
        }
    }
    /*
            char *objName;
            if (entry = objID2Obj->get(objID2Obj, (int)getIdent(objName))) {
                    if (entry = symStr2ID->get(symStr2ID, (long)objName)) {
                            if (findObject(entry->val)) {
                                    result->info.i = 1;
                                    return 1;
                            }
                    }
            }
    */
    result->info.i = 0;
    return 1;
}

/*
 * freeSelf()
 *
 *
 * Result:
 * Return:
 */
long meth_cosmic_freeSelf(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;

    /* NOTE: Do NOT access GET_name(self) here - it may already be freed
     * by meth_generic_freeSelf which calls us AFTER freeing the name. */

    for (i = 0; i < callObjStackIdx; i++) {
        if (callObjStack[i].obj == self)
            callObjStack[i].destroyed = 1;
    }
    if (!exitingViola) {
        cancelEventByObject(self); /* in case an event is coming */

        /* quite vain */
        SET__classInfo(self, NULL);

        free(self);
        /* and remove from object list...*/
    }
    clearPacket(result);
    return 1;
}

/*
 * info(<info flag>)
 *
 * Info flags:
 * 	<none>
 *		Print to stdout slot values for the calling object.
 *	"listAllMethods"
 *		Print to stdout name of methods in all classes.
 *	"listMethods"
 *		Print to stdout name of methods in calling obj's class.
 *	"listSlotsRW"
 *	"listSlotsR"
 *	"listSlotsW"
 *		Print to stdout slot values for the calling object,
 *		filterd by SLOT_R/W flags.
 *	"listAllObjects"
 *		List to stdout name of all loaded objects.
 *
 * Result:
 * Return:
 */
long meth_cosmic_info(VObj* self, Packet* result, int argc, Packet argv[]) {
    char* cp;
    /* extern int fprintf(); */

    clearPacket(result);
    if (argc == 0) {
        return dumpObj(self, (long (*)(FILE*, const char*, ...))fprintf, stdout, 0, 0);
    }
    cp = PkInfo2Str(&argv[0]);
    if (!strcmp(cp, "listMethods")) {
        ClassInfo* cip;
        MethodInfo* mip;
        FILE* fp;

        if (argc >= 2) {
            cip = getClassInfoByName(PkInfo2Str(&argv[1]));
        } else {
            cip = (ClassInfo*)GET_class(self);
        }
        if (argc == 3) {
            fp = fopen(PkInfo2Str(&argv[2]), "w");
            if (!fp)
                return 0;
            for (mip = cip->methods; mip->id; mip++)
                fprintf(fp, "%s\n", (char*)(symID2Str->get(symID2Str, mip->id)->val));
            fclose(fp);
        } else {
            char sbuff[255];

            buff[0] = '\0';
            for (mip = cip->methods; mip->id; mip++) {
                sprintf(sbuff, "%s\n", (char*)(symID2Str->get)(symID2Str, mip->id)->val);
                strcat(buff, " ");
                strcat(buff, sbuff);
            }
            result->info.s = saveString(buff);
            result->type = PKT_STR;
            result->canFree = PK_CANFREE_STR;
        }

    } else if (!strcmp(cp, "listNPSlots")) {
        ClassInfo* cip;
        SlotInfo* sip;
        int i;

        if (argc >= 2) {
            cip = getClassInfoByName(PkInfo2Str(&argv[1]));
        } else {
            cip = (ClassInfo*)GET_class(self);
        }
        buff[0] = '\0';
        sip = cip->slots[1]; /* section 1 is NPSlots */
        for (i = 0; sip[i].id; i++) {
            if (!(sip[i].flags & SLOT_RW))
                continue;
            strcat(buff, (char*)symID2Str->get(symID2Str, sip[i].id)->val);
            strcat(buff, "\n");
        }
        result->info.s = saveString(buff);
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;

    } else if (!strcmp(cp, "listNCSlots")) {
        ClassInfo* cip;
        SlotInfo* sip;
        int i;

        if (argc >= 2) {
            cip = getClassInfoByName(PkInfo2Str(&argv[1]));
        } else {
            cip = (ClassInfo*)GET_class(self);
        }
        buff[0] = '\0';
        sip = cip->slots[0]; /* section 0 is NCSlots */
        for (i = 0; sip[i].id; i++) {
            strcat(buff, (char*)symID2Str->get(symID2Str, sip[i].id)->val);
            strcat(buff, "\n");
        }
        result->info.s = saveString(buff);
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;

    } else if (!strcmp(cp, "listSlotsRW")) {
        return dumpObj(self, (long (*)(FILE*, const char*, ...))fprintf, stdout, SLOT_RW, 0);
    } else if (!strcmp(cp, "listSlotsR")) {
        return dumpObj(self, (long (*)(FILE*, const char*, ...))fprintf, stdout, SLOT_R, 0);
    } else if (!strcmp(cp, "listSlotsW")) {
        return dumpObj(self, (long (*)(FILE*, const char*, ...))fprintf, stdout, SLOT_W, 0);
    } else if (!strcmp(cp, "listAllObjects")) {

    } else if (!strcmp(cp, "listAllMethods")) {
        extern HashTable *symStr2ID, *symID2Str;
        ClassInfo *cip, *cip2;
        MethodInfo* mip;
        int i;

        for (i = 0; (cip = classList[i]); i++) {
            printf("\n%s :\n", (char*)symID2Str->get(symID2Str, cip->id)->val);
            for (cip2 = cip; cip2; cip2 = cip2->superClass) {
                for (mip = cip2->methods; mip->id; mip++) {
                    printf("%s\n", (char*)symID2Str->get(symID2Str, mip->id)->val);
                }
            }
            printf("\n");
        }
    }
    return 1;
}

/*
 * interpret(<script> [, ...])
 *
 * Evaluate the arguments as scripts.
 *
 * Result: as effected by script
 * Return: 1 if successful, 0 if error occured
 */
long meth_cosmic_interpret(VObj* self, Packet* result, int argc, Packet argv[]) {
    int i;
    char* cp;

    clearPacket(result);
    /* interpret is needed for objects to function.
     * Security is enforced at individual dangerous method level (system, pipe, etc). */
    for (i = 0; i < argc; i++) {
        cp = SaveString(PkInfo2Str(&argv[i]));
        if (cp)
            execScript(self, result, cp);
        else {
            printf("error: interpret(): argument %d is empty.\n", i);
        }
        free(cp);
    }

    return 1;
}

/* return new object count
 */
long meth_cosmic_loadObjFile(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern char* current_addr;  /* from html.c */
    extern long securityMode;   /* global security mode */
    char* path;
    char* fname = NULL;
    int securityLevel = 1;  /* Default: untrusted */

    /*
     * Security logic (defense in depth):
     * 1. If securityMode is set globally, use it (overrides everything)
     * 2. If calling object is untrusted, loaded objects MUST be untrusted
     *    (prevents privilege escalation via current_addr spoofing)
     * 3. Only if caller is trusted AND current_addr is local, trust loaded objects
     */
    
    if (securityMode > 0) {
        /* Global security mode overrides everything */
        securityLevel = securityMode;
    } else if (self && GET_security(self) > 0) {
        /* CRITICAL: Untrusted caller cannot create trusted objects */
        /* This prevents HTTPCurrentDocAddrSet spoofing attack */
        securityLevel = 1;
    } else if (current_addr && isLocalAddress(current_addr)) {
        /* Trusted caller loading from local source = trusted */
        securityLevel = 0;
    }
    /* Otherwise: securityLevel stays 1 (untrusted) */

    if (argc > 0) {
        path = PkInfo2Str(&argv[0]);
        if (argc > 1)
            fname = PkInfo2Str(&argv[1]);

        if (path && fname) {
            result->info.i = load_object_with_security(fname, path, securityLevel);
        } else {
            result->info.i = 0;
        }
    } else {
        result->info.i = 0;
    }
    result->type = PKT_INT;
    result->canFree = 0;

    return ((result->info.i == -1) ? 0 : 1);
}

long meth_cosmic_modalExit(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPrompt(self, "exit modal dialog"))
        return 0;
    modalState = 0;
    copyPacket(modalResult, &argv[0]);
    return 1;
}

/*
 * object(<object name>)
 *
 *
 *
 * Result:
 * Return:
 */
long meth_cosmic_object(VObj* self, Packet* result, int argc, Packet argv[]) {
    result->info.o = PkInfo2Obj(&argv[0]);
    result->type = PKT_OBJ;
    result->canFree = 0;
    return 1;
}

/*
 * pop()
 *
 *
 * Result:
 * Return:
 */
long meth_cosmic_pop(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

/*
 * ()
 *
 *
 * Result:
 * Return:
 */
long meth_cosmic_push(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    return 0;
}

/*
 * quit();
 *
 * Save stack and exit.
 *
 * Result: unaffected
 * Return: 1 if successful, 0 if error occured
 */
long meth_cosmic_quit(VObj* self, Packet* result, int argc, Packet argv[]) {
    if (notSecureWithPrompt(self, "quit application"))
        return 0;
    /*	methodMembershipProfile();*/
    exitingViola = 1;
    freeViolaResources();
    exit(0);
}

/*
 * save();
 *
 * Save the calling object's cluster in the top object's name with ".v"
 * appended.
 *
 * Result: file name under which the objects were saved in
 * Return:
 */
long meth_cosmic_save(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj *parent, *obj = self;
    char fileName[100];
    FILE* fp;
    int stat;

    if (notSecureWithPrompt(self, "save object to file"))
        return 0;

    while ((parent = GET__parent(obj)))
        obj = parent;

    strcpy(fileName, GET_name(obj));
    strcat(fileName, ".v");

    fp = fopen(fileName, "w");
    if (fp) {
        stat = saveSelfAndChildren(obj, fp);
        fclose(fp);
        if (stat) {
            result->type = PKT_STR;
            result->info.s = saveString(fileName);
            result->canFree = PK_CANFREE_STR;
            return 1;
        }
    }
    clearPacket(result);
    return 0;
}

/*
 * saveAs(filePath);
 *
 * Save the calling object's cluster in the specified file path.
 *
 * Result:
 * Return:
 */
long meth_cosmic_saveAs(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj *parent, *obj = self;
    char *cp, fileName[100];
    FILE* fp;
    int stat;

    if (notSecureWithPrompt(self, "save object to file"))
        return 0;

    if (argc != 1)
        return 0;

    while ((parent = GET__parent(obj)))
        obj = parent;

    cp = PkInfo2Str(&argv[0]);
    if (!cp)
        return 0;

    strcpy(fileName, cp);

    fp = fopen(cp, "w");
    if (fp) {
        stat = saveSelfAndChildren(obj, fp);
        fclose(fp);
        if (stat) {
            result->type = PKT_STR;
            result->info.s = saveString(fileName);
            result->canFree = PK_CANFREE_STR;
            return 1;
        }
    }
    clearPacket(result);
    return stat;
}

/*
 * send(<object name>, <message list ...>)
 *
 * Send a message for the target object's script to handle.
 *
 * Result:
 * Return:
 */
long meth_cosmic_send(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj* obj = PkInfo2Obj(&argv[0]);

    if (obj)
        if (validObjectP(obj)) {
            if (sendMessagePackets_result(obj, &argv[1], argc - 1, result)) {
                return 1;
            }
        }
    clearPacket(result);
    return 0;
}

/*
 */
long meth_cosmic_test1(VObj* self, Packet* result, int argc, Packet argv[]) {
    /*	clearPacket(result);
            result->info.i = user_message_confirm(PkInfo2Str(&argv[0]));
            result->type = PKT_INT;
    */
    return 1;
}

/*
 */
long meth_cosmic_test2(VObj* self, Packet* result, int argc, Packet argv[]) {
    clearPacket(result);
    result->info.s = user_prompt_default(PkInfo2Str(&argv[0]), PkInfo2Str(&argv[1]));
    result->type = PKT_STR;
    return 1;
}

/*
 */
long meth_cosmic_test3(VObj* self, Packet* result, int argc, Packet argv[]) {
    /* cuts off the dataBuff at the caller's string's beginning
     * this is useful if the caller wants to get the parent to
     * do something with its (parent's) data before the caller
     * itself exist.
     * example: <SUP> telling <MATH> to collect tokens...
     */
    nullifyCallerDataBuff();
    return 0;
}

long meth_cosmic_test4(VObj* self, Packet* result, int argc, Packet argv[]) {
    HTMLMathDraw(self);
    return 0;
}

/*
 * tweak(object name, command string)
 *
 * Execute command string in context of the target object, bypassing
 * the target object's script.
 *
 * Result:
 * Return:
 */
long meth_cosmic_tweak(VObj* self, Packet* result, int argc, Packet argv[]) {
    VObj* obj;
    int i;
    size_t len;
    char *cp, *script;

    /* Security check: untrusted object trying to execute code in another object's context */
    if (notSecureWithPrompt(self, "execute script in another object's context"))
        return 0;

    obj = PkInfo2Obj(&argv[0]);
    if (obj) {
        for (i = 1; i < argc; i++) {
            script = PkInfo2Str(&argv[i]);
            if (script) {
                len = strlen(script);
                /* extra space to let yylook safely
                 * overwriting array boundary */
                cp = (char*)malloc(sizeof(char) * (len + 2));
                if (cp) {
                    strcpy(cp, script);
                    execScript(obj, result, cp);
                    free(cp);
                }
            }
        }
        return 1;
    }
    clearPacket(result);
    return 0;
}

/*
 * usual()
 *
 * Execute the default class script for the class of the calling object.
 *
 * Result: result of the class script
 * Return:
 */
long meth_cosmic_usual(VObj* self, Packet* result, int argc, Packet argv[]) {
    extern int stackExecIdx;
    extern int stackBaseIdx;
    int save_stackExecIdx;
    int save_stackBaseIdx;

    save_stackExecIdx = stackExecIdx;
    save_stackBaseIdx = stackBaseIdx;

    stackBaseIdx = stackExecIdx;
    execObjClassScript(self, result);

    stackExecIdx = save_stackExecIdx;
    stackBaseIdx = save_stackBaseIdx;

    return 1;
}
