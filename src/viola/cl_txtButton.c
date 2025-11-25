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
 * class	: txtButton
 * superClass	: txt
 */
#include "cl_txtButton.h"
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

SlotInfo cl_txtButton_NCSlots[] = {0};
SlotInfo cl_txtButton_NPSlots[] = {0};
SlotInfo cl_txtButton_CSlots[] = {{STR_class, PTRS | SLOT_RW, (long)"txtButton"},
                                  {
                                      STR_classScript,
                                      PTRS,
                                      (long)"\n\
		switch (arg[0]) {\n\
		case \"mouseMove\":\n\
		case \"enter\":\n\
		case \"leave\":\n\
		case \"keyPress\":\n\
		case \"keyRelease\":\n\
		break;\n\
		case \"buttonPress\":\n\
			copyArea(0,0,width(),height(),1,1);\n\
			/*smudge();*/\n\
		break;\n\
		case \"buttonRelease\":\n\
			render();/*clean();*/\n\
		break;\n\
		case \"expose\":\n\
			render();\n\
		break;\n\
		case \"render\":\n\
			render();\n\
		break;\n\
		case \"visible\":\n\
			set(\"visible\", arg[1]);\n\
		break;\n\
		case \"config\":\n\
			config(arg[1], arg[2], arg[3], arg[4]);\n\
			render();\n\
		break;\n\
		case \"configSelf\":\n\
			config();\n\
		break;\n\
		case \"key_up\":\n\
			send(parent(), \"key_up\");\n\
			return;\n\
		break;\n\
		case \"key_down\":\n\
			send(parent(), \"key_down\");\n\
			return;\n\
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
		case \"init\":\n\
			initialize();\n\
		break;\n\
		case \"info\":\n\
			info();\n\
		break;\n\
		case \"interpret\":\n\
			interpret(arg[1]);\n\
		break;\n\
		case \"freeSelf\":\n\
			freeSelf();\n\
		break;\n\
		default:\n\
			print(\"unknown message, clsss = txtButton: args: \");\n\
			for (i =0; i < arg[]; i++) print(arg[i], \", \");\n\
			print(\"\\n\");\n\
			break;\n\
		}\n\
	",
                                  },
                                  {0}};
SlotInfo cl_txtButton_PSlots[] = {{STR__classInfo, CLSI, (long)&class_txtButton},
                                  {STR_border, LONG | SLOT_RW, BORDER_BUTTON},
                                  {0}};

SlotInfo* slots_txtButton[] = {(SlotInfo*)cl_txtButton_NCSlots, (SlotInfo*)cl_txtButton_NPSlots,
                               (SlotInfo*)cl_txtButton_CSlots, (SlotInfo*)cl_txtButton_PSlots};

MethodInfo meths_txtButton[] = {
    /* local methods */
    {STR_initialize, meth_txtButton_initialize},
    {STR_render, meth_txtButton_render},
    {0}};

ClassInfo class_txtButton = {
    helper_txt_get,  helper_txt_set, slots_txtButton, /* class slot information	*/
    meths_txtButton,                                  /* class methods		*/
    STR_txtButton,                                    /* class identifier number	*/
    &class_txt,                                       /* super class info		*/
};

long int meth_txtButton_initialize(VObj* self, Packet* result, int argc, Packet argv[])
{
    return meth_txt_initialize(self, result, argc, argv);
}

long int meth_txtButton_render(VObj* self, Packet* result, int argc, Packet argv[])
{
    if (meth_txt_render(self, result, argc, argv)) {
        long fontID = GET__font(self);
        char* str = GET_label(self);
        Window w = GET_window(self);

        if (!str)
            str = "Unlabeled";
        if (w && GET_visible(self)) {
            return GLDrawText(w, fontID, (GET_width(self) - GLTextWidth(fontID, str)) / 2,
                              (GET_height(self) - GLTextHeight(fontID, str)) / 2, str);
        }
    }
    return 0;
}
