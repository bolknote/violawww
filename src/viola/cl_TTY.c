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
 * class	: tty
 * superClass	: client
 *
 * WARNING: this class nonfunctions if i386 is #defined
 */
/*
 * Contributors:
 *
 * Kurt Pires (kjpires@xcf): initial tty code.
 * Tor Lillqvist (tml@tik.vtt.fi): HP-UX compatibility.
 */
#include "cl_TTY.h"
#if defined(__APPLE__)
/*
 * macOS: Use openpty()/forkpty() for pseudo-terminal support.
 */
#include "cl_cosmic.h"
#include "slotaccess.h"
#include "class.h"
#include "classlist.h"
#include "error.h"
#include "ident.h"
#include "misc.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "scanutils.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <util.h>   /* macOS: openpty, forkpty */
#include <termios.h>

SlotInfo cl_TTY_NCSlots[] = {0};
SlotInfo cl_TTY_NPSlots[] = {{
                                 STR_path,
                                 PTRS | SLOT_RW,
                                 (long)"",
                             },
                             {
                                 STR_args,
                                 PTRS | SLOT_RW,
                                 (long)"",
                             },
                             {STR_pid, LONG, 0},
                             {0}};
SlotInfo cl_TTY_CSlots[] = {{STR_class, PTRS | SLOT_RW, (long)"TTY"},
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
SlotInfo cl_TTY_PSlots[] = {{STR__classInfo, CLSI, (long)&class_TTY}, {0}};

SlotInfo* slots_TTY[] = {(SlotInfo*)cl_TTY_NCSlots, (SlotInfo*)cl_TTY_NPSlots,
                         (SlotInfo*)cl_TTY_CSlots, (SlotInfo*)cl_TTY_PSlots};

MethodInfo meths_TTY[] = {
    /* local methods */
    {STR__startClient, meth_TTY__startClient},
    {
        STR_geta,
        meth_TTY_get,
    },
    {STR_seta, meth_TTY_set},
    {0}};

ClassInfo class_TTY = {
    helper_TTY_get, helper_TTY_set, slots_TTY, /* class slot information	*/
    meths_TTY,                                 /* class methods		*/
    STR_TTY,                                   /* class identifier number	*/
    &class_client,                             /* super class info		*/
};

long meth_TTY__startClient(VObj* self, Packet* result, int argc, Packet argv[]) {
    int master_fd;
    pid_t pid;
    char* args[16];
    int n;
    char *path;
    char msgbuf[256];

    result->type = PKT_INT;
    result->canFree = 0;

    /* Set up argument list */
    path = GET_path(self);
    
    if (!path || !*path) {
        MERROR(self, "startClient: 'path' attribute not set");
        result->info.i = -1;
        return 0;
    }

    /* Security: executing subprocess requires user permission */
    snprintf(msgbuf, sizeof(msgbuf), "execute subprocess: %s", path);
    if (notSecureWithPrompt(self, msgbuf)) {
        result->info.i = -1;
        return 0;
    }
    
    args[0] = path;
    n = makeArgv(&args[1], GET_args(self));
    args[n + 1] = NULL;

    /* Use forkpty which handles all the pty/tty setup */
    pid = forkpty(&master_fd, NULL, NULL, NULL);

    if (pid < 0) {
        MERROR(self, "startClient: forkpty failed");
        result->info.i = -1;
        return 0;
    }

    if (pid == 0) {
        /* Child process */
        execv(path, args);
        perror(path);
        _exit(-1);
    }

    /* Parent process */
    SET_pid(self, pid);
    SET_clientFD(self, master_fd);
    result->info.i = master_fd;
    return 1;
}

long helper_TTY_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {
    switch (labelID) {
    case STR_pid:
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = GET_pid(self);
        return 1;

    case STR_args:
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        result->info.s = SaveString(GET_args(self));
        return 1;

    case STR_path:
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        result->info.s = SaveString(GET_path(self));
        return 1;
    }
    return helper_client_get(self, result, argc, argv, labelID);
}
long meth_TTY_get(VObj* self, Packet* result, int argc, Packet argv[]) {
    return helper_TTY_get(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

long helper_TTY_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {
    switch (labelID) {
    case STR_args:
        result->info.s = SaveString(PkInfo2Str(&argv[1]));
        SET_args(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;

    case STR_path:
        result->info.s = SaveString(PkInfo2Str(&argv[1]));
        SET_path(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;
    }
    return helper_client_set(self, result, argc, argv, labelID);
}
long meth_TTY_set(VObj* self, Packet* result, int argc, Packet argv[]) {
    return helper_TTY_set(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

#else
#include "cl_cosmic.h"
#include "class.h"
#include "classlist.h"
#include "error.h"
#include "event.h"
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

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#ifdef _AIX
#include <sys/select.h>
#endif

#include <stdlib.h>
#include <strings.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <unistd.h>
#ifdef SYSV
#include <termio.h>
#endif

#ifdef __hpux
static char pty[] = "/dev/ptym/ptyXY";
static char tty[] = "/dev/pty/ttyXY";
#else
static char pty[] = "/dev/ptyXY";
static char tty[] = "/dev/ttyXY";
#endif

SlotInfo cl_TTY_NCSlots[] = {0};
SlotInfo cl_TTY_NPSlots[] = {{
                                 STR_path,
                                 PTRS | SLOT_RW,
                                 (long)"",
                             },
                             {
                                 STR_args,
                                 PTRS | SLOT_RW,
                                 (long)"",
                             },
                             {STR_pid, LONG, 0},
                             {0}};
SlotInfo cl_TTY_CSlots[] = {{STR_class, PTRS | SLOT_RW, (long)"TTY"},
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
SlotInfo cl_TTY_PSlots[] = {{STR__classInfo, CLSI, (long)&class_TTY}, {0}};

SlotInfo* slots_TTY[] = {(SlotInfo*)cl_TTY_NCSlots, (SlotInfo*)cl_TTY_NPSlots,
                         (SlotInfo*)cl_TTY_CSlots, (SlotInfo*)cl_TTY_PSlots};

MethodInfo meths_TTY[] = {
    /* local methods */
    {STR__startClient, meth_TTY__startClient},
    {
        STR_geta,
        meth_TTY_get,
    },
    {STR_seta, meth_TTY_set},
    {0}};

ClassInfo class_TTY = {
    helper_TTY_get, helper_TTY_set, slots_TTY, /* class slot information	*/
    meths_TTY,                                 /* class methods		*/
    STR_TTY,                                   /* class identifier number	*/
    &class_client,                             /* super class info		*/
};

long meth_TTY__startClient(VObj* self, Packet* result, int argc, Packet argv[]) {
#ifndef i386

    int fd, fd_client, pid, n;
    char* args[16];
    char *cp, *ptymajorp, *ptyminorp, *ttymajorp, *ttyminorp;
    char msgbuf[256];
    char* path;

#ifdef SYSV
    struct termio b;
#elif defined(VIOLA_DARWIN) || defined(VIOLA_LINUX)
    /* Skip BSD-style terminal I/O on macOS and Linux */
    /* Terminal setup handled by forkpty()/openpty() - no extra variables needed */
#else
    struct sgttyb b;
    struct tchars tc;
    struct ltchars lc;
#ifdef TIOCGWINSZ
    struct winsize win;
#endif
    int lb;
    int l;
#endif
#ifdef TIOCGWINSZ
    struct winsize win;
#endif

    result->type = PKT_INT;
    result->canFree = 0;

    /* Security: executing subprocess requires user permission */
    path = GET_path(self);
    snprintf(msgbuf, sizeof(msgbuf), "execute subprocess: %s", path ? path : "(unknown)");
    if (notSecureWithPrompt(self, msgbuf)) {
        result->info.i = -1;
        return 0;
    }

    ptymajorp = index(pty, 'X');
    ptyminorp = index(pty, 'Y');
    ttymajorp = index(tty, 'X');
    ttyminorp = index(tty, 'Y');

    if (ptymajorp == NULL) {
        MERROR(self, "startClient: Out of pty's.\n");
        result->info.i = 0;
        return 0;
    }

    for (*ptymajorp = 'p'; *ptymajorp <= 'z'; ++*ptymajorp) {
        for (cp = "0123456789abcdef"; *cp; cp++) {
            *ptyminorp = *cp;

            if ((fd = open(pty, O_RDWR)) >= 0) {
                *ttymajorp = *ptymajorp;
                *ttyminorp = *ptyminorp;

                if ((fd_client = open(tty, O_RDWR)) < 0) {
                    MERROR(self, "startClient: ");
                    perror(tty);
                    close(fd);
                    continue; /* Try next pty */
                }
#ifdef SYSV
                ioctl(0, TCGETA, (char*)&b);
                b.c_cc[VMIN] = 1;
                b.c_cc[VTIME] = 0;
                b.c_lflag &= ~(ICANON | ECHO);
                ioctl(fd_client, TCSETA, (char*)&b);
#elif defined(VIOLA_DARWIN) || defined(VIOLA_LINUX)
                /* Skip BSD-style terminal I/O on macOS and Linux */
                /* Terminal setup handled by forkpty()/openpty() */
#else
                ioctl(0, TIOCGETP, (char*)&b);
                b.sg_flags |= RAW;
                b.sg_flags &= ~ECHO;
                ioctl(fd_client, TIOCSETP, (char*)&b);
                ioctl(0, TIOCGETC, (char*)&tc);
                ioctl(fd_client, TIOCSETC, (char*)&tc);
                ioctl(0, TIOCGETD, (char*)&l);
                ioctl(fd_client, TIOCSLTC, (char*)&lc);
                ioctl(0, TIOCGLTC, (char*)&lc);
                ioctl(fd_client, TIOCLSET, (char*)&lb);
                ioctl(0, TIOCLGET, (char*)&lb);
                ioctl(fd_client, TIOCSETD, (char*)&l);
#endif
#ifdef TIOCGWINSZ
                ioctl(0, TIOCGWINSZ, (char*)&win);
                ioctl(fd_client, TIOCSWINSZ, (char*)&win);
#endif
                args[0] = GET_path(self);
                n = makeArgv(&args[1], GET_args(self));
                args[n + 1] = NULL;
                switch (pid = fork()) {
                case -1: /* Error */
                    MERROR(self, "startClient: ");
                    perror("fork failed");
                    close(fd_client);
                    close(fd);
                    result->info.i = -1;
                    return 0;

                case 0: /* Child */
                    close(fd);
                    if (fd_client != 0)
                        dup2(fd_client, 0);
                    if (fd_client != 1)
                        dup2(fd_client, 1);
                    /* ERROR to current screen */

                    /* not error */
                    if (fd_client <= 1)
                        close(fd_client);

                    execv(GET_path(self), args);
                    perror(GET_path(self));
                    _exit(-1);

                default:
                    close(fd_client);
                    SET_pid(self, pid);
                    SET_clientFD(self, fd);
                    result->info.i = fd;
                    return 1;
                }
            }
        }
    }
#endif // i386
    result->info.i = 0;
    return 0;
}

long helper_TTY_get(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {
    switch (labelID) {
    case STR_pid:
        result->type = PKT_INT;
        result->canFree = 0;
        result->info.i = GET_pid(self);
        return 1;

    case STR_args:
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        result->info.s = SaveString(GET_args(self));
        return 1;

    case STR_path:
        result->type = PKT_STR;
        result->canFree = PK_CANFREE_STR;
        result->info.s = SaveString(GET_path(self));
        return 1;
    }
    return helper_client_get(self, result, argc, argv, labelID);
}
long meth_TTY_get(VObj* self, Packet* result, int argc, Packet argv[]) {
    return helper_TTY_get(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}

long helper_TTY_set(VObj* self, Packet* result, int argc, Packet argv[], long labelID) {
    switch (labelID) {
    case STR_args:
        result->info.s = SaveString(PkInfo2Str(&argv[1]));
        SET_args(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;

    case STR_path:
        result->info.s = SaveString(PkInfo2Str(&argv[1]));
        SET_path(self, result->info.s);
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;
    }
    return helper_client_set(self, result, argc, argv, labelID);
}
long meth_TTY_set(VObj* self, Packet* result, int argc, Packet argv[]) {
    return helper_TTY_set(self, result, argc, argv, getIdent(PkInfo2Str(argv)));
}
#endif /* defined(__APPLE__) */
