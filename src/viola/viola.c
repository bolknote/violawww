/*
 * Copyright 1990-93 Pei-Yuan Wei.	All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */
/*
 * viola.c
 *
 * Scott: reorganized the former viola main.c to smaller modules and
 *        put them here.
 */
/* Some extraneous includes, no doubt */
#include "ast.h"
#include "attr.h"
#include "cexec.h"
#include "cgen.h"
#include "class.h"
#include "classlist.h"
#include "event_x.h"
#include "file.h"
#include "glib.h"
#include "hash.h"
#include "ident.h"
#include "loader.h"
#include "membership.h"
#include "misc.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "slotaccess.h"
#include "utils.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <unistd.h>

extern int init_sys();
extern int init_obj();
extern int init_scanutils();
extern int init_tfed();
extern long init_cexec();
extern int init_html();
extern int SGMLInit();
extern long meth_generic_cli(VObj* self, Packet* result, int argc, Packet argv[]);
extern void tfed_FreeTmpFileToFree(int freeP);
extern void XtToolkitInitialize();

/* Forward declarations */
void freeViolaResources(void);

#define DFLT_USR_WWW_HOME "WWW" /* patched */

char* viola_version = "Viola=4.0 Beta";
/*= <geom>		.\n\n\*/
char* viola_usage = {"Usage:\n\n\
Standard X11 options:\n\n\
-geometry <geom>	geometry\n\
= <geom>		.\n\
-display <display>	display\n\n\
Viola-specific options:\n\n\
-cli			command line interface.\n\
-c			.\n\n\
-laf <mode>		(unsup	ported) look and feel mode (0 for expensive drawing).\n\
-LAF <mode>		.\n\
-l <mode>		.\n\n\
-obj <object name>	startup object (send \"render\" to it).\n\
-o <object name>	.\n\
-path <file path>	object file lookup path.\n\
-p <file path>		.\n\n\
-release		print release info.\n\
-r			.\n\
-V			.\n\n\
-snipet <statement>	script snipet to interpret.\n\
-s <statement>		.\n\n\
-verbose		verbose mode.\n\
-v			.\n\n\
-help			print this help message.\n\
-h			.\n\
--help			.\n\n\
-ar <path>		pass argument (path or URL).\n\n\
-mono			monochrome mode (no shading).\n\n\
-cmd_history		enable command history.\n\n\
-nocliprompt		disable CLI prompt.\n\n\
For debugging:\n\n\
-pa			print AST.\n\
-pc			print PCode.\n\
-pe			print PCode execution trace.\n\
-wt			window tracking.\n\
-at [<file>]		user action tracking (to file or stderr).\n\
-tagd			print tag delimiters.\n\
-lcs			load class scripts.\n\
-debug			debug flag.\n\
-z			sync events.\n\
-xsync			.\n\
\n\
"};

/*
(not yet...)\n\
For more help on these arguments, do\n\
        viola -o www -arg0 show -arg1 'xcf.berkeley.edu/ht/violaOptionsHelp'\n\
viola -o foo,erwhrwehwe,erewr,wrerwe,wre

viola -o hmml -0Sshow -1I234 -2CHello

-0 <mesg>		arg[0] to -o object.\n
-1 <mesg>		arg[1] \n
-2 <mesg>		arg[2] \n
-3 <mesg>		arg[3] \n
-4 <mesg>		arg[4] \n
-5 <mesg>		arg[5] \n
-6 <mesg>		arg[6] \n
-7 <mesg>		arg[7] \n
-8 <mesg>		arg[8] \n\n
-arg0 <message>		arg[0] to send to object specified by -o.\n\
-arg1 <message>		arg[1] to send to object specified by -o.\n\
-arg2 <message>		arg[2] to send to object specified by -o.\n\
...\n\
-argN <message>		arg[N] to send to object specified by -o.\n\
-argType <type>		arg[n] type modifiers:\n\

*/

#ifndef DEFAULT_VIOLA_PATH
#define DEFAULT_VIOLA_PATH "/usr/lib/apps"
#endif

#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

/* Try to find viola path relative to executable */
static char* findViolaPathFromExecutable(void) {
    static char exePath[1024];
    static char violaDir[1024];
    char* lastSlash;
    
#ifdef __APPLE__
    uint32_t size = sizeof(exePath);
    if (_NSGetExecutablePath(exePath, &size) != 0) {
        return NULL;
    }
    /* Resolve symlinks */
    char* resolved = realpath(exePath, NULL);
    if (resolved) {
        strncpy(exePath, resolved, sizeof(exePath) - 1);
        free(resolved);
    }
#elif defined(__linux__)
    ssize_t len = readlink("/proc/self/exe", exePath, sizeof(exePath) - 1);
    if (len == -1) {
        return NULL;
    }
    exePath[len] = '\0';
#else
    return NULL;
#endif

    /* exePath is like /path/to/violawww2/src/vw/vw */
    /* We want /path/to/violawww2/src/viola */
    lastSlash = strrchr(exePath, '/');
    if (!lastSlash) return NULL;
    *lastSlash = '\0';  /* /path/to/violawww2/src/vw */
    
    lastSlash = strrchr(exePath, '/');
    if (!lastSlash) return NULL;
    *lastSlash = '\0';  /* /path/to/violawww2/src */
    
    snprintf(violaDir, sizeof(violaDir), "%s/viola", exePath);
    
    /* Check if this path exists */
    if (access(violaDir, F_OK) == 0) {
        return violaDir;
    }
    return NULL;
}

/* Try to find sgml path relative to executable */
static char* findSgmlPathFromExecutable(void) {
    static char exePath[1024];
    static char sgmlDir[1024];
    char* lastSlash;
    
#ifdef __APPLE__
    uint32_t size = sizeof(exePath);
    if (_NSGetExecutablePath(exePath, &size) != 0) {
        return NULL;
    }
    char* resolved = realpath(exePath, NULL);
    if (resolved) {
        strncpy(exePath, resolved, sizeof(exePath) - 1);
        free(resolved);
    }
#elif defined(__linux__)
    ssize_t len = readlink("/proc/self/exe", exePath, sizeof(exePath) - 1);
    if (len == -1) {
        return NULL;
    }
    exePath[len] = '\0';
#else
    return NULL;
#endif

    /* exePath is like /path/to/violawww2/src/vw/vw */
    /* We want /path/to/violawww2/res */
    lastSlash = strrchr(exePath, '/');
    if (!lastSlash) return NULL;
    *lastSlash = '\0';  /* /path/to/violawww2/src/vw */
    
    lastSlash = strrchr(exePath, '/');
    if (!lastSlash) return NULL;
    *lastSlash = '\0';  /* /path/to/violawww2/src */
    
    lastSlash = strrchr(exePath, '/');
    if (!lastSlash) return NULL;
    *lastSlash = '\0';  /* /path/to/violawww2 */
    
    snprintf(sgmlDir, sizeof(sgmlDir), "%s/res", exePath);
    
    /* Check if this path exists */
    if (access(sgmlDir, F_OK) == 0) {
        return sgmlDir;
    }
    return NULL;
}

/* intefers with normal events, used only for http progress reports */
int perishableActiveHelp = 0;

Window topWindow;       /* Sub-Window that Viola is supposed to run in. */
int runInSubWindow = 0; /* Set to 1 when Viola is run in library mode. */

void parseCommandLine(int, char*[], char*[], int*, char**, int*, char**);

/* Scott */
/*
 * Intended to be called by programs that use Viola as a library.
 *
 * The calling program must supply a script file name, an open Display,
 * the proper Screen pointer, and a window in which Viola is to run.
 *
 * The calling program must thereafter call violaProcessEvent() whenever
 * there is an event in Viola's window and must periodically call
 * violaIdleEvent() when there are no events to process and nothing
 * better to do otherwise.
 */
char* initViola(int argc, char* argv[], char* vObjFile, Display* display, Screen* screen, Window parentWindow)
{
    extern char** environ;
    Packet* result;
    HashEntry* entry;
    int i = 0;
    int startWithCommandLineInterpreter = 0;
    char* defaultViolaPath = DEFAULT_VIOLA_PATH;
    char* violaPath;
    char* scriptSnipet = NULL;
    char* startObj[32];
    int startObjCount = 0;
    char topVObjName[256];
    VObj* obj;
    void scanTopObjName(char*, char*);
    extern char* sgmlPath;

    /* Scott */
    if (parentWindow) {
        runInSubWindow = 1;
        topWindow = parentWindow;
    }

    if (vObjFile)
        startObj[startObjCount++] = vObjFile;

    if ((violaPath = getEnvironVars(environ, "VIOLA_PATH", buff)))
        violaPath = saveString(violaPath);

    if ((sgmlPath = getEnvironVars(environ, "VIOLA_SGML", buff)))
        sgmlPath = saveString(sgmlPath);

    parseCommandLine(argc, argv, startObj, &startObjCount, &violaPath,
                     &startWithCommandLineInterpreter, &scriptSnipet);

    /* Try to find paths relative to executable if not specified */
    if (!violaPath) {
        char* autoPath = findViolaPathFromExecutable();
        if (autoPath) {
            violaPath = saveString(autoPath);
            if (verbose)
                fprintf(stderr, "Auto-detected VIOLA_PATH=``%s''\n", violaPath);
        }
    }
    
    if (!sgmlPath) {
        char* autoPath = findSgmlPathFromExecutable();
        if (autoPath) {
            sgmlPath = saveString(autoPath);
            if (verbose)
                fprintf(stderr, "Auto-detected VIOLA_SGML=``%s''\n", sgmlPath);
        }
    }

    /* initUserWWW(DFLT_USR_WWW_HOME); */ /*PATCHED*/

    if (!init_sys())
        exit(2);
    if (!init_ident())
        exit(4);
    if (!init_class())
        exit(5);
    if (!init_obj())
        exit(6);
    if (!init_scanutils())
        exit(7);
    if (!init_ast())
        exit(8);
    if (!init_packet())
        exit(9);
    if (!init_glib(display, screen))
        exit(10);
    if (!init_tfed())
        exit(1);
    if (!init_event())
        exit(11);
    if (!init_cexec())
        exit(12);
    if (!init_html())
        exit(13);
    if (!SGMLInit())
        exit(14);

#ifdef USE_SSL
    /* Initialize SSL/TLS support for HTTPS */
    {
        extern int HTSSL_init(void);
        if (HTSSL_init() < 0) {
            fprintf(stderr, "Warning: Failed to initialize SSL/TLS. HTTPS will not be available.\n");
        } else if (verbose) {
            fprintf(stderr, "SSL/TLS initialized for HTTPS support.\n");
        }
    }
#endif

    /* Initialize HTTP/HTTPS keep-alive connection pool */
    {
        extern void HTKeepAlive_init(void);
        extern void HTKeepAlive_cleanup(void);
        HTKeepAlive_init();
        atexit(HTKeepAlive_cleanup);
        if (verbose) {
            fprintf(stderr, "HTTP/HTTPS keep-alive connection pool initialized.\n");
        }
    }

    if (violaPath) {
        if (init_loader(violaPath)) {
            if (verbose)
                fprintf(stderr, "Using VIOLA_PATH=``%s''\n", violaPath);
        }
    } else if (init_loader(defaultViolaPath)) {
        if (verbose)
            fprintf(stderr, "Using default violaPath=``%s''\n", defaultViolaPath);
    } else {
        fprintf(stderr, "Can't find application files. Check VIOLA_PATH.\n");
        exit(20);
    }

    /*	if (!setHTMLStyle()) exit(14);*/

    load_object("res.font.v", NULL);
    entry = objID2Obj->get(objID2Obj, storeIdent("res.font"));
    if (!entry) {
        fprintf(stderr, "can't find: font resource file (\"res.font.v\").\n");
        exit(21);
    }
    if (verbose)
        fprintf(stderr, "loaded: font resource file (\"res.font.v\").\n");

    VFontResourceObj = (VObj*)entry->val;

    if (!init_fonts()) {
        fprintf(stderr, "aborting due to font related problem.\n");
        exit(23);
    }

    if (verbose)
        fprintf(stderr, "initialized font resources.\n");

    /* always instantiate object "res" */

    load_object("res.v", NULL);
    entry = objID2Obj->get(objID2Obj, storeIdent("res"));
    if (!entry) {
        fprintf(stderr, "can't find: resource file (\"res.v\").\n");
        exit(24);
    }
    if (!(entry->val)) {
        fprintf(stderr, "can't find: resource file (\"res.v\").\n");
        exit(25);
    }
    obj = (VObj*)entry->val;
    if (obj) {
        VPrevObj = VTargetObj = VResourceObj = VCurrentObj = obj;
        /*			sendMessage1(obj, "init");*/
    } else {
        fprintf(stderr, "Failed to instantiate res! Bye.\n");
        exit(99);
    }

    for (i = 0; i < startObjCount; i++) {
        char objFileName[100];

        sprintf(objFileName, "%s.v", startObj[i]);
        load_object(objFileName, NULL);
        entry = objID2Obj->get(objID2Obj, storeIdent(startObj[i]));
        if (!entry) {
            fprintf(stderr, "can't find: start up file (\"%s\").\n", objFileName);
            exit(22);
        }
        obj = (VObj*)entry->val;
        if (obj) {
            VPrevObj = VTargetObj = VCurrentObj = obj;
            /*sendMessage1(obj, "init");*/
            sendMessage1(obj, "render");
        } else {
            fprintf(stderr, "No start up object! Bye.\n");
            exit(27);
        }
    }

    result = borrowPacket();

    if (startWithCommandLineInterpreter)
        meth_generic_cli(VCurrentObj, result, 0, 0);

    sendMessage1N1int(VCurrentObj, "visible", 1);
    /*	sendMessage1(VCurrentObj, "render");*/

    if (scriptSnipet) {
        execScript(VCurrentObj, result, scriptSnipet);
    }

    if (verbose)
        fprintf(stderr, "entering event loop.\n");

    /* Scott: don't enter viola's eventLoop if motif's running */
    if (!runInSubWindow)
        eventLoop();

    returnPacket();

    if (user_action_tracking)
        if (user_action_tracking != stderr)
            fclose(user_action_tracking);

    if (!runInSubWindow) {
        freeViolaResources();
        exit(0);
    }

    /* Scott */
    if (vObjFile) {
        char* name;

        scanTopObjName(vObjFile, topVObjName);
        name = malloc(strlen(topVObjName) + 1);
        strcpy(name, topVObjName);
        return (name);
    } else {
        return (NULL);
    }
    XtToolkitInitialize(); /* just to make sure Xt is linked??*/
}

void freeViolaResources() {
#ifdef USE_SSL
    /* Shutdown SSL/TLS */
    {
        extern void HTSSL_shutdown(void);
        HTSSL_shutdown();
    }
#endif
    tfed_FreeTmpFileToFree(0);
    free_fonts();
    freeAllObjects();
    freeGLibResources();
    
    /* Free packet concatenation buffer */
    {
        extern void cleanup_pkinfo_concat(void);
        cleanup_pkinfo_concat();
    }
}

/* Scott: moved this code from the former main.c into this file
 */
void parseCommandLine(int argc, char* argv[], char* startObj[],
                      int* startObjCount, char** violaPath,
                      int* startWithCommandLineInterpreter, char** scriptSnipet)
{
    int i = 0;

    if (argc)
        while (argv[++i]) {
            /*fprintf(stderr, "arg[%d]=%s\n", i, argv[i]);*/

            if (!strcasecmp(argv[i], "-ar")) {

                /* Convert relative paths to absolute paths */
                char* absolutePath = makeAbsolutePath(argv[++i]);
                /* Free old value if any */
                if (passthru_argument)
                    free(passthru_argument);
                if (absolutePath) {
                    passthru_argument = absolutePath; /* takes ownership */
                } else {
                    passthru_argument = saveString(argv[i]);
                }

            } else if (!strcasecmp(argv[i], "-cli") || !strcasecmp(argv[i], "-c")) {

                if (!runInSubWindow)
                    *startWithCommandLineInterpreter = 1;

            } else if (!strcasecmp(argv[i], "-cmd_history")) {

                cmd_history = 1;

            } else if (!strcasecmp(argv[i], "-mono")) {
                extern int noShading;
                noShading = 1;

            } else if (!strcasecmp(argv[i], "-geometry") || !strcasecmp(argv[i], "=")) {

                /* Scott */
                if (!runInSubWindow)
                    XParseGeometry(argv[++i], &startUpGeom_x, &startUpGeom_y, &startUpGeom_width,
                                   &startUpGeom_height);

            } else if (!strcasecmp(argv[i], "-display")) {

                startUpDisplay = argv[++i];

            } else if (!strcasecmp(argv[i], "-nocliprompt")) {
                extern int flag_cliprompt;

                if (!runInSubWindow) /* Scott */
                    flag_cliprompt = 0;

            } else if (!strcasecmp(argv[i], "-obj") || !strcasecmp(argv[i], "-o")) {

                startObj[*startObjCount] = argv[++i];
                *startObjCount += 1;

            } else if (!strcasecmp(argv[i], "-pa")) {

                flag_printAST = 1;

            } else if (!strcasecmp(argv[i], "-pc")) {

                flag_printPCode = 1;

            } else if (!strcasecmp(argv[i], "-pe")) {

                flag_printExec = 1;

            } else if (!strcasecmp(argv[i], "-z") || !strcasecmp(argv[i], "-xsync")) {

                sync_event = 1;

            } else if (!strcasecmp(argv[i], "-LAF") || !strcasecmp(argv[i], "-laf") ||
                       !strcasecmp(argv[i], "-l")) {

                if (!argv[++i]) {
                    /* assume simple mode (1) */
                    lookAndFeel = 1;
                } else {
                    lookAndFeel = atoi(argv[i]);
                }

            } else if (!strcasecmp(argv[i], "-noarg")) {

            } else if (!strcasecmp(argv[i], "-path") || !strcasecmp(argv[i], "-p")) {

                /* Scott */
                *violaPath = argv[++i];

            } else if (!strcasecmp(argv[i], "-help") || !strcasecmp(argv[i], "-h") ||
                       !strcasecmp(argv[i], "--help")) {

                fputs(viola_usage, stderr);
                exit(0);

            } else if (!strcasecmp(argv[i], "-release") || !strcasecmp(argv[i], "-r")) {

                fprintf(stderr, "%s\n", viola_version);

            } else if (!strcmp(argv[i], "-V")) {

                fprintf(stderr, "%s\n", viola_version);

            } else if (!strcasecmp(argv[i], "-snipet") || !strcasecmp(argv[i], "-s")) {

                /* Scott */
                *scriptSnipet = argv[++i];

            } else if (!strcasecmp(argv[i], "-verbose") || !strcasecmp(argv[i], "-v")) {

                verbose = 1;

            } else if (!strcasecmp(argv[i], "-tagd")) {

                extern int printTagDelims;

                printTagDelims = 1;

            } else if (!strcasecmp(argv[i], "-wt")) {

                flag_window_tracking = 1;

            } else if (!strcasecmp(argv[i], "-at")) {

                if (argv[i + 1][0] != '-') {
                    user_action_tracking = fopen(argv[++i], "w");
                    if (!user_action_tracking) {
                        fprintf(
                            stderr,
                            "Failed to open file \"%s\" for user action tracking. Using stderr.\n",
                            argv[i]);
                        user_action_tracking = stderr;
                    }
                } else {
                    user_action_tracking = stderr;
                }

            } else if (!strcasecmp(argv[i], "-lcs")) {

                loadClassScriptsP = 1;

            } else if (!strcasecmp(argv[i], "-debug")) {

                /* Flag allows spider to print out diagnostic stuff. */;

            } else if (argv[i][0] == '-') {
                /* Unknown option starting with '-' */
                fputs(viola_usage, stderr);
                exit(0);
            } else {
                /* Convert relative paths to absolute paths */
                char* absolutePath = makeAbsolutePath(argv[i]);
                /* Free old value if any */
                if (passthru_argument)
                    free(passthru_argument);
                if (absolutePath) {
                    passthru_argument = absolutePath; /* takes ownership */
                } else {
                    passthru_argument = saveString(argv[i]);
                }
            }
            if (i >= argc)
                break;
        }

    /* for convenience, automatically start up www if no
     * application is specified
     */
    if (*startObjCount == 0) {
        startObj[0] = "www";
        *startObjCount = 1;
    }
}

/* Bede McCall <bede@mitre.org> MITRE Corp
 */
#include <errno.h>
#include <pwd.h>

extern int errno;
/* sys_errlist/sys_nerr are deprecated, use strerror() instead */
#if !defined(VIOLA_DARWIN) && !defined(VIOLA_LINUX)
extern char* sys_errlist[];
extern int sys_nerr;
#endif

void initUserWWW(char* www)
{
    int Errno;
    char* cp;
    static char path[128];
    struct passwd* pw;

    Errno = 0;
    bzero(path, 128);

#if defined(i386) || defined(__APPLE__)
    pw = getpwuid(getuid());
#else
    {
        char* cuserid();
        struct passwd* getpwnam();

        cp = cuserid((char*)NULL);
        if (!cp)
            return;
        pw = getpwnam(cp);
    }
#endif
    (void)strcat(path, pw->pw_dir);
    (void)strcat(path, "/");
    (void)strcat(path, www);

    if (mkdir(path, 0x755)) {
        Errno = errno;
        if (verbose) {
#if defined(VIOLA_LINUX) || defined(VIOLA_DARWIN)
            (void)printf("mkdir(%s), error %d: %s\n", path, Errno, strerror(Errno));
#else
            if (Errno < sys_nerr)
                (void)printf("mkdir(%s), error %d: %s\n", path, Errno, sys_errlist[Errno]);
            else
                (void)printf("mkdir(%s), error %d\n", path, Errno);
#endif
        }
    } else if (verbose) {
        (void)printf("created %s\n", path);
    }
    (void)fflush(stdout);
}

/*
 * To get a Viola object name from a file path name.
 */
void scanTopObjName(char *fileName, char *returnName)
{
    char* cp;
    int len;

    if (!fileName) {
        *returnName = '\0';
        return;
    }
    len = strlen(fileName);

    if (!len) {
        *returnName = '\0';
        return;
    }

    cp = fileName + len - 1;

    while (cp != fileName && *cp != '/')
        cp--;
    if (*cp == '/')
        cp++;

    while (*cp && *cp != '.')
        *returnName++ = *cp++;
    *returnName = '\0';
}
