/*
 * This is main for the binary program "viola".
 */
#include "cexec.h"
#include "obj.h"
#include "scanutils.h"
#include "viola.h"
#include <X11/Xlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    initViola(argc, argv, (char*)NULL, (Display*)NULL, (Screen*)NULL, (Window)0);
    return 0;
}

/* the libWWW calls these routines to report HTTP loading progress
 */
void showHelpMessageInMainWindow(char* message) {
    extern VObj* mesgObj;
    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj)
        sendMessage1N1str(mesgObj, "show", message);
}

void blankHelpHandlerInMainWindow(void) {
    extern VObj* mesgObj;
    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj)
        sendMessage1(mesgObj, "clear");
}
