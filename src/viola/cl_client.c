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
 * class	: client
 * superClass	: field
 */
#include "cl_client.h"
#include "class.h"
#include "classlist.h"
#include "error.h"
#include "event.h"
#include "glib.h"
#include "hash.h"
#include "ident.h"
#include "membership.h"
#include "method.h"
#include "misc.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "scanutils.h"
#include "slotaccess.h"
#include "utils.h"
#include <string.h>
#include <unistd.h>

SlotInfo cl_client_NCSlots[] = {0};
SlotInfo cl_client_NPSlots[] = {{STR_inDelimStat, LONG, 0},
                                {
                                    STR_inDelimStr1,
                                    PTRS | SLOT_RW,
                                    (long)"",
                                },
                                {
                                    STR_inDelimStr2,
                                    PTRS | SLOT_RW,
                                    (long)"",
                                },
                                {
                                    STR_outDelimStr,
                                    PTRS | SLOT_RW,
                                    (long)"",
                                },
                                {STR_clientFD, LONG, -1},
                                {STR_clientFP, LONG, 0},
                                {0}};
SlotInfo cl_client_CSlots[] = {{STR_class, PTRS | SLOT_RW, (long)"client"},
                               {
                                   STR_classScript,
                                   PTRS,
                                   (long)"\n\
		switch (arg[0]) {\n\
		case \"config\":\n\
			config(arg[1], arg[2], arg[3], arg[4]);\n\
		break;\n\
		case \"configSelf\":\n\
			/* icky! but necessary to give script a chance to \n\
			 * intercept and do something...*/\n\
	        	send(self(), \"config\", \n\
				x(), y(), width(), height());\n\
		break;\n\
		case \"expose\":\n\
			expose(arg[1], arg[2], arg[3], arg[4]);\n\
		break;\n\
		case \"render\":\n\
			render();\n\
		break;\n\
		case \"visible\":\n\
			set(\"visible\", arg[1]);\n\
		break;\n\
		case \"mouseMove\":\n\
		case \"enter\":\n\
		case \"leave\":\n\
		case \"buttonPress\":\n\
		case \"buttonRelease\":\n\
		case \"keyPress\":\n\
		case \"keyRelease\":\n\
		case \"shownPositionH\":\n\
		case \"shownPositionV\":\n\
		case \"shownInfoV\":\n\
		case \"shownInfoH\":\n\
		break;\n\
		case \"focus\":\n\
			mousePos = mouse();\n\
			winPos = windowPosition();\n\
			mx = mousePos[0];\n\
			my = mousePos[1];\n\
			dx = ((winPos[0] + width() / 2) - mx) / 10.0;\n\
			dy = ((winPos[1] + height() / 2) - my) / 10.0;\n\
			for (i = 0; i < 10; i = i + 1) {\n\
				mx = mx + dx;\n\
				my = my + dy;\n\
				setMouse(mx, my);\n\
			}\n\
		break;\n\
		case \"key_up\":\n\
			send(parent(), \"key_up\");\n\
			return;\n\
		break;\n\
		case \"key_down\":\n\
			send(parent(), \"key_down\");\n\
			return;\n\
		break;\n\
		case \"init\":\n\
			initialize();\n\
		break;\n\
		case \"raise\":\n\
			raise();\n\
		break;\n\
		case \"info\":\n\
			info();\n\
		break;\n\
		case \"freeSelf\":\n\
			return freeSelf();\n\
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
SlotInfo cl_client_PSlots[] = {{STR__classInfo, CLSI, (long)&class_client}, {0}};

SlotInfo* slots_client[] = {(SlotInfo*)cl_client_NCSlots, (SlotInfo*)cl_client_NPSlots,
                            (SlotInfo*)cl_client_CSlots, (SlotInfo*)cl_client_PSlots};

MethodInfo meths_client[] = {
    /* local methods */
    {
        STR_endClient,
        meth_client_endClient,
    },
    {
        STR_freeSelf,
        meth_client_freeSelf,
    },
    {
        STR_geta,
        meth_client_get,
    },
    {STR_initialize, meth_client_initialize},
    {
        STR_input,
        meth_client_input,
    },
    {
        STR_inputn,
        meth_client_inputn,
    },
    {
        STR_output,
        meth_client_output,
    },
    {STR_seta, meth_client_set},
    {STR_startClient, meth_client_startClient},
    {0}};

ClassInfo class_client = {
    helper_client_get, helper_client_set, slots_client, /* class slot information	*/
    meths_client,                                       /* class methods		*/
    STR_client,                                         /* class identifier number	*/
    &class_field,                                       /* super class info		*/
};

long meth_client_endClient(VObj* self, Packet* result, int argc, Packet argv[]) {

    int fd = GET_clientFD(self);

    result->type = PKT_INT;
    result->canFree = 0;

    if (fd != -1) {
        objFDList[fd] = NULL;
        close(fd);
        SET_clientFD(self, -1);
        result->info.i = 0;
        return 0;
    }
    result->info.i = 1;
    return 1;
}

long meth_client_freeSelf(VObj* self, Packet* result, int argc, Packet argv[]) {

    char* cp;

    callMeth(self, result, 0, NULL, STR_endClient);

    if ((cp = GET_inDelimStr1(self)))
        free(cp);
    if ((cp = GET_inDelimStr2(self)))
        free(cp);
    if ((cp = GET_outDelimStr(self)))
        free(cp);

    meth_field_freeSelf(self, result, argc, argv);

    clearPacket(result);
    return 1;
}

long helper_client_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {

    switch (labelID) {
    case STR_clientFD:
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = GET_clientFD(self);
        return 1;

    case STR_clientFP:
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = GET_clientFP(self);
        return 1;

    case STR_inDelimStat:
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = GET_inDelimStat(self);
        return 1;

    case STR_inDelimStr1:
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        result->info.s = SaveString(GET_inDelimStr1(self));
        return 1;

    case STR_inDelimStr2:
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        result->info.s = SaveString(GET_inDelimStr2(self));
        return 1;
    }
    return helper_field_get(self, result, argc, argv, labelID);
}
long meth_client_get(VObj* self, Packet* result, int argc, Packet argv[]) {

    return helper_client_get(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

long meth_client_initialize(VObj* self, Packet* result, int argc, Packet argv[]) {

    meth_field_initialize(self, result, argc, argv);
    return 1;
}

/*
 * input([mode])
 *
 * if mode = 1, the inDelimStr is included.
 * (default) if mode = 0, the inDelimStr is stripped out.
 *
 * this procedure affects:
 * inDelimStat
 *	2	if matched with inDelimStr2
 *	1	if matched with inDelimStr1
 *	0	don't use (and if unexpected '\0' is encountered)
 *	-1	if fd is closed (fd == -1).
 *	-2	if fd is if (read() <= 0). are these stats even useful?
 *	-3	if fd is if (read() != 1).
 */
long meth_client_input(VObj* self, Packet* result, int argc, Packet argv[]) {

    int fd = GET_clientFD(self);
    int c, i = 0, n;
    ssize_t cc;
    char* inDelimStr1 = GET_inDelimStr1(self);
    char* inDelimStr2 = GET_inDelimStr2(self);
    long mode = 0;
    char cbuff[2];
    size_t mstrlen = strlen(inDelimStr1);
    size_t mstrlen2 = strlen(inDelimStr2);
    int mi = 0, mi2 = 0;

    if (fd == -1) {
        MERROR(self, "client input: fd is -1");
        SET_inDelimStat(self, -1);
        result->type = PKT_STR;
        result->canFree = 0;
        result->info.s = "";
        return 0;
    }
    if (argc > 0)
        mode = PkInfo2Int(&argv[0]);

    /* read from stdin (now receiving child's stdout) */
    for (c = 0;; ++c) {
        cc = read(fd, cbuff, 1);
        if (cc <= 0) {
            SET_inDelimStat(self, -2);

            /*			sendMessage1(self, "endClient");*/
            result->type = PKT_STR;
            result->canFree = 0;
            result->info.s = "";
            return 0;
        }
        if (cc != 1) {
            buff[c] = '\0';
            result->type = PKT_STR;
            result->canFree = PK_CANFREE_STR;
            result->info.s = SaveString(buff);
            SET_inDelimStat(self, -3);
            return 0;
        }
        if (cbuff[0] == '\0') {
            if (verbose)
                printf("unexpected NULL in fd = %d\n", fd);
            buff[c] = '\0';
            SET_inDelimStat(self, 0);
            result->type = PKT_STR;
            result->canFree = PK_CANFREE_STR;
            result->info.s = SaveString(buff);
            return 0;
        }
        if (cbuff[0] >= 0)
            buff[c] = cbuff[0];

        if (verbose)
            printf("[%c]%d \n", cbuff[0], (int)(cbuff[0]));

        if (cbuff[0] == inDelimStr1[mi]) {
            if (verbose)
                printf("match.\n");
            if (++mi >= mstrlen) {
                if (verbose)
                    printf("match all.\n");
                SET_inDelimStat(self, 1);
                if (mode) {
                    buff[c] = '\0';
                } else {
                    buff[c - mstrlen + 1] = '\0';
                }
                result->type = PKT_STR;
                result->canFree = PK_CANFREE_STR;
                result->info.s = SaveString(buff);
                return 1;
            }
        } else {
            if (verbose)
                printf("unmatch.\n");
            mi = 0;
        }
        if (cbuff[0] == inDelimStr2[mi2]) {
            if (verbose)
                printf("match2.\n");
            if (++mi2 >= mstrlen2) {
                if (verbose)
                    printf("match2 all.\n");
                SET_inDelimStat(self, 2);
                if (mode) {
                    buff[c] = '\0';
                } else {
                    buff[c - mstrlen2 + 1] = '\0';
                }
                result->type = PKT_STR;
                result->canFree = PK_CANFREE_STR;
                result->info.s = SaveString(buff);
                return 1;
            }
        } else {
            if (verbose)
                printf("unmatch2.\n");
            mi2 = 0;
        }
    }
}

long meth_client_inputn(VObj* self, Packet* result, int argc, Packet argv[]) {

    int fd = GET_clientFD(self);
    ssize_t cc;
    int i = 0;
    long n;

    if (fd == -1) {
        MERROR(self, "client inputn: fd is -1");
        result->type = PKT_STR;
        result->canFree = 0;
        result->info.s = "";
        return 0;
    }

    n = PkInfo2Int(&argv[0]);
    while (i < n) {
        cc = read(fd, &buff[i], n - i);

        if (cc <= 0) {
            /*			sendMessage1(self, "endClient");*/
        } else {
            i += cc;
        }
    }
    buff[i] = '\0';

    result->type = PKT_STR;
    result->canFree = PK_CANFREE_STR;
    result->info.s = SaveString(buff);

    return 1;
}

/*
 * result set to length of data if successful
 * returns 1 on success, 0 on failure
 */
long meth_client_output(VObj* self, Packet* result, int argc, Packet argv[]) {

    int i;
    ssize_t res;
    int fd = GET_clientFD(self);
    char *data, *outDelimStr = GET_outDelimStr(self);
    size_t length;

    length = 0;
    result->info.i = 0;
    result->type = PKT_INT;
    result->canFree = 0;

    for (i = 0; i < argc; i++) {

        data = PkInfo2Str(&argv[i]);

        if (fd == -1) {
            MERROR(self, "client output: file descriptor not open.");
            return 0;
        }
        data = PkInfo2Str(&argv[0]);
        length = (unsigned char)strlen(data);
        result->info.i += length;
        res = write(fd, data, length);
        if (res < 0) {
            MERROR(self, "write to client failed: failed.");
        }
        if (outDelimStr[0] != '\0') {
            res = write(fd, outDelimStr, strlen(outDelimStr));
        }
        if (res < 0) {
            MERROR(self, "writing outDelimStr to client failed.");
            return 0;
        }
    }
    return 1;
}

long meth_client_startClient(VObj* self, Packet* result, int argc, Packet argv[]) {

    int fd = GET_clientFD(self);
    long newfd;

    result->type = PKT_INT;
    result->canFree = 0;

    if (fd >= 0) {
        /* a connection already exists. close the existing
         * connection first */
        objFDList[fd] = NULL;
        close(fd);
        SET_clientFD(self, -1);
        printf("startClient: connection already exists. reconnecting.\n");
    }

    if (!callMeth(self, result, 0, NULL, STR__startClient)) {
        result->info.i = 0;
        return 0;
    }
    newfd = result->info.i;

    if (newfd < 0) {
        MERROR(self, "startClient: failed to start");
        return 0;
    } else {
        SET_clientFD(self, (int)newfd);
        objFDList[(int)newfd] = self;
        FD_SET(fd, &read_mask);
        return 1;
    }
}

long helper_client_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {

    switch (labelID) {
    case STR_inDelimStr1:
        result->info.s = SaveString(PkInfo2Str(&argv[1]));
        SET_inDelimStr1(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;

    case STR_inDelimStr2:
        result->info.s = SaveString(PkInfo2Str(&argv[1]));
        SET_inDelimStr2(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;

    case STR_outDelimStr:
        result->info.s = SaveString(PkInfo2Str(&argv[1]));
        SET_outDelimStr(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;

    case STR_inDelimStat:
        SET_inDelimStat(self, PkInfo2Int(&argv[1]));
        result->type = PKT_INT;
        result->canFree = 0;
        return 1;
    }
    return helper_field_set(self, result, argc, argv, labelID);
}
long meth_client_set(VObj* self, Packet* result, int argc, Packet argv[]) {

    return helper_client_set(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}
