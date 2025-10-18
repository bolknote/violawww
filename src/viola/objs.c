#include "objs.h"

static char _slotValue_res0[] = "res";
static char _slotValue_res1[] = "generic";
static char _slotValue_res2[] = "\n\
\n\
/*\n\
xx = \"\\n\
\\n\
\\\\p(ht.lines.small.gif)\";\n\
print(\"before {\", xx, \"}\\n\
\");\n\
print(\"after {\", trimEdgeQ(xx), \"}\\n\
\");\n\
exit(0);\n\
\n\
url = \"http://pebble/vdoc\";\n\
print(\">>>>>>>>>>>>>>>>>>>>>>>>>URL=\", url, \"\\n\
\");\n\
x = HTTPGet(url);\n\
normURL = send(\"normalizeURL\", \"normalizeURL\", url);\n\
print(\">>>>>>>>>>>>>>>>>>>>>>>>>URL=\", url, \"\\n\
\");\n\
print(\">>>>>>>>>>>>>>>>>>>>>>>>>normURL=\", normURL, \"\\n\
\");\n\
\n\
url = \"http://pebble\";\n\
print(\">>>>>>>>>>>>>>>>>>>>>>>>>URL=\", url, \"\\n\
\");\n\
x = HTTPGet(url);\n\
normURL = send(\"normalizeURL\", \"normalizeURL\", url);\n\
print(\">>>>>>>>>>>>>>>>>>>>>>>>>URL=\", url, \"\\n\
\");\n\
print(\">>>>>>>>>>>>>>>>>>>>>>>>>normURL=\", normURL, \"\\n\
\");\n\
\n\
exit(0);\n\
*/\n\
/*\n\
print(\"start-------\\n\
\");\n\
for (i = 0; i < 1000; i++) {\n\
	lappend(i, 0);\n\
	xxx n[i] = 0;\n\
}\n\
\n\
print(\"end---------\\n\
\");\n\
exit(0);\n\
*/\n\
	switch (arg[0]) {\n\
	case \"targetSet\":\n\
		shell(\"targetSet\");\n\
		return;\n\
	break;\n\
	case \"incAppCount\":\n\
		++appCount;\n\
		return;\n\
	break;\n\
	case \"decAppCount\":\n\
	case \"quit\":\n\
		--appCount;\n\
		if (appCount <= 0) quit();\n\
		return;\n\
	break;\n\
/*\n\
	case \"fifi\":\n\
		x += 10;\n\
		return x;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		x = 1;\n\
		send(self(), \"foo\", x, x += 100,\n\
			send(self(), \"fifi\"));\n\
	break;\n\
	case \"foo\":\n\
		print(\"FOO:\\n\
\");\n\
		print(\"arg[1]=\", arg[1], \"\\n\
\");\n\
		print(\"arg[2]=\", arg[2], \"\\n\
\");\n\
		print(\"arg[3]=\", arg[3], \"\\n\
\");\n\
		return;\n\
	break;\n\
*/\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_res[] = {
    {"name", _slotValue_res0},
    {"class", _slotValue_res1},
    {"script", _slotValue_res2},
    {(char*)0, (char*)0},
};

static char _slotValue_res_font0[] = "res.font";
static char _slotValue_res_font1[] = "generic";
static char _slotValue_res_font2[] = "\n\
 	/*\n\
	** Font resource object\n\
 	*/\n\
	switch (arg[0]) {\n\
	case \"id\":\n\
		return interpret(\"return \" + arg[1] + \";\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		/*\n\
		 * font ID/name inventory list\n\
		 */\n\
		fonts[0] = \"fixed\";\n\
		fonts[1] = \"normal\";\n\
		fonts[2] = \"normal_large\";\n\
		fonts[3] = \"normal_largest\";\n\
		fonts[4] = \"bold\";\n\
		fonts[5] = \"bold_large\";\n\
		fonts[6] = \"bold_largest\";\n\
		fonts[7] = \"italic\";\n\
		fonts[8] = \"italic_large\";\n\
		fonts[9] = \"italic_largest\";\n\
/*		fonts[10] = \"symbol\";*/\n\
		fonts[10] = \"banner\";\n\
		fonts[11] = \"banner_large\";\n\
		fonts[12] = \"banner_largest\";\n\
		fonts[13] = \"any\";\n\
\n\
	/* \n\
	 * font fall-back lists\n\
	 */\n\
\n\
	fixed[0]	= \"-misc-fixed-medium-r-*-*-14-*-*-*-*-*-*-*\";\n\
	fixed[1]	= \"-misc-fixed-*-*-*-*-*-*-*-*-*-*-*-*\";\n\
	fixed[3]	= \"-misc-fixed-*\";\n\
\n\
	normal[0]	= \"-adobe-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
	normal[1]	= \"-*-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
	normal[2]	= \"-*-*-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
	normal[3]	= \"-misc-fixed-*\";\n\
\n\
	normal_large[0]	= \"-adobe-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\
	normal_large[1]	= \"-*-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\
	normal_large[2]	= \"-*-*-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
	normal_large[3]	= \"-misc-fixed-*\";\n\
\n\
	normal_largest[0] =\"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	normal_largest[1] = \"-*-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	normal_largest[2] = \"-*-*-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	normal_largest[3] = \"-misc-fixed-*\";\n\
\n\
	bold[0]		= \"-adobe-helvetica-bold-r-*-*-14-*-*-*-p-*-*-*\";\n\
	bold[1]		= \"-*-helvetica-bold-r-*-*-14-*-*-*-p-*-*-*\";\n\
	bold[2]		= \"-*-*-bold-r-*-*-14-*-*-*-p-*-*-*\";\n\
	bold[3]		= \"-misc-fixed-*\";\n\
\n\
	bold_large[1]	= \"-adobe-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\
	bold_large[1]	= \"-*-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\
	bold_large[2]	= \"-*-*-bold-r-*-*-27-*-*-*-p-*-*-*\";\n\
	bold_large[3]	= \"-misc-fixed-*\";\n\
\n\
	bold_largest[0]	= \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	bold_largest[1]	= \"-*-helvetica-bold-r-*-*-24-*-*-*-p-*-*-*\";\n\
	bold_largest[2]	= \"-*-*-bold-r-*-*-24-*-*-*-p-*-*-*\";\n\
	bold_largest[3]	= \"-misc-fixed-*\";\n\
\n\
	banner[0]	= \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner[1]	= \"-*-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner[2]	= \"-*-*-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner[3]	= \"-misc-fixed-*\";\n\
\n\
	banner_large[0]	= \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner_large[1]	= \"-*-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner_large[2]	= \"-*-*-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner_large[3]	= \"-misc-fixed-*-\";\n\
\n\
	banner_largest[0] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner_largest[1] = \"-*-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner_largest[2] = \"-*-*-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
	banner_largest[3] = \"-misc-fixed-*\";\n\
\n\
	italic[0]	= \"-adobe-helvetica-medium-*-*-*-14-*-*-*-p-*-*-*\";\n\
	italic[1]	= \"-*-helvetica-medium-i-*-*-14-*-*-*-p-*-*-*\";\n\
	italic[2]	= \"-*-*-medium-i-*-*-14-*-*-*-p-*-*-*\";\n\
	italic[3]	= \"-misc-fixed-*\";\n\
\n\
	italic_large[0]	= \"-adobe-helvetica-medium-i-*-*-17-*-*-*-p-*-*-*\";\n\
	italic_large[1]	= \"-*-helvetica-medium-i-*-*-17-*-*-*-p-*-*-*\";\n\
	italic_large[2]	= \"-*-*-medium-i-*-*-17-*-*-*-p-*-*-*\";\n\
	italic_large[3]	= \"-misc-fixed-*\";\n\
\n\
	italic_largest[0] = \"-adobe-helvetica-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\
	italic_largest[1] = \"-*-helvetica-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\
	italic_largest[2] = \"-*-*-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\
	italic_largest[3] = \"-misc-fixed-*\";\n\
\n\
	symbol[0] = \"-*-symbol-medium-r-*-*-14-*-*-*-*-*-*-*\";\n\
	symbol[1] = \"-misc-fixed-*\";\n\
\n\
	any[0]		= \"-misc-fixed-medium-r-*-*-14-*-*-*-*-*-*-*\";\n\
	any[1]		= \"-*-*-medium-*-*-*-*-*-*-*-*-*-*-*\";\n\
	any[2]		= \"-misc-fixed-*\";\n\
\n\
/* for violaWWW */\n\
fonts_HelveticaSmall[0] = \"-misc-fixed-medium-r-*-*-14-*-*-*-*-*-*-*\";\n\
fonts_HelveticaSmall[1] = \"-adobe-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[2] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[3] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[4] = \"-adobe-helvetica-bold-r-*-*-14-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[5] = \"-adobe-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[6] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[7] = \"-adobe-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[8] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[9] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[10] = \"-adobe-helvetica-medium-r-*-*-16-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[11] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[12] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaSmall[13] = \"-adobe-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
\n\
fonts_HelveticaMedium[0] = \"-misc-fixed-medium-r-*-*-16-*-*-*-*-*-*-*\";\n\
fonts_HelveticaMedium[1] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[2] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[3] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[4] = \"-adobe-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[5] = \"-adobe-helvetica-bold-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[6] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[7] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[8] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[9] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[10] = \"-adobe-helvetica-medium-i-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[11] = \"-adobe-helvetica-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[12] = \"-adobe-helvetica-medium-i-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_HelveticaMedium[13] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
\n\
fonts_HelveticaLarge[0] = \"-misc-fixed-medium-r-*-*-20-*-*-*-*-*-*-*\";\n\
fonts_HelveticaLarge[1] = \"-adobe-helvetica-medium-r-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[2] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[3] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[4] = \"-adobe-helvetica-bold-r-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[5] = \"-adobe-helvetica-bold-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[6] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[7] = \"-adobe-helvetica-medium-r-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[8] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[9] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[10] = \"-adobe-helvetica-medium-i-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[11] = \"-adobe-helvetica-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[12] = \"-adobe-helvetica-medium-i-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_HelveticaLarge[13] = \"-adobe-helvetica-medium-r-*-*-20-*-*-*-p-*-*-*\";\n\
\n\
fonts_TimesSmall[0] = \"-misc-fixed-medium-r-*-*-14-*-*-*-*-*-*-*\";\n\
fonts_TimesSmall[1] = \"-adobe-times-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[2] = \"-adobe-times-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[3] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[4] = \"-adobe-times-bold-r-*-*-14-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[5] = \"-adobe-times-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[6] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[7] = \"-adobe-times-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[8] = \"-adobe-times-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[9] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[10] = \"-adobe-times-medium-i-*-*-17-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[11] = \"-adobe-times-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[12] = \"-adobe-times-medium-i-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesSmall[13] = \"-adobe-times-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\
\n\
fonts_TimesMedium[0] = \"-misc-fixed-medium-r-*-*-20-*-*-*-*-*-*-*\";\n\
fonts_TimesMedium[1] = \"-adobe-times-medium-r-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[2] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[3] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[4] = \"-adobe-times-bold-r-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[5] = \"-adobe-times-bold-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[6] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[7] = \"-adobe-times-medium-r-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[8] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[9] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[10] = \"-adobe-times-medium-i-*-*-20-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[11] = \"-adobe-times-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[12] = \"-adobe-times-medium-i-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesMedium[13] = \"-adobe-times-medium-r-*-*-20-*-*-*-p-*-*-*\";\n\
\n\
fonts_TimesLarge[0] = \"-adobe-courier-medium-r-*-*-24-*-*-*-*-*-*-*\";\n\
fonts_TimesLarge[1] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[2] = \"-adobe-times-medium-r-*-*-27-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[3] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[4] = \"-adobe-times-bold-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[5] = \"-adobe-times-bold-r-*-*-27-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[6] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[7] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[8] = \"-adobe-times-medium-r-*-*-27-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[9] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[10] = \"-adobe-times-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[11] = \"-adobe-times-medium-i-*-*-27-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[12] = \"-adobe-times-medium-i-*-*-34-*-*-*-p-*-*-*\";\n\
fonts_TimesLarge[13] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\
\n\
	return 1;\n\
	break;\n\
	case \"useHelveticaSmallFonts\":\n\
		for (i = fonts[] - 1; i >= 0; i--)\n\
			defineNewFont(i, fonts[i], fonts_HelveticaSmall[i]);\n\
		return;\n\
	break;\n\
	case \"useHelveticaMediumFonts\":\n\
		for (i = fonts[] - 1; i >= 0; i--)\n\
			defineNewFont(i, fonts[i], fonts_HelveticaMedium[i]);\n\
		return;\n\
	break;\n\
	case \"useHelveticaLargeFonts\":\n\
		for (i = fonts[] - 1; i >= 0; i--)\n\
			defineNewFont(i, fonts[i], fonts_HelveticaLarge[i]);\n\
		return;\n\
	break;\n\
	case \"useTimesSmallFonts\":\n\
		for (i = fonts[] - 1; i >= 0; i--)\n\
			defineNewFont(i, fonts[i], fonts_TimesSmall[i]);\n\
		return;\n\
	break;\n\
	case \"useTimesMediumFonts\":\n\
		for (i = fonts[] - 1; i >= 0; i--)\n\
			defineNewFont(i, fonts[i], fonts_TimesMedium[i]);\n\
		return;\n\
	break;\n\
	case \"useTimesLargeFonts\":\n\
		for (i = fonts[] - 1; i >= 0; i--)\n\
			defineNewFont(i, fonts[i], fonts_TimesLarge[i]);\n\
		return;\n\
	break;\n\
	case \"useAllFixedFonts\":\n\
		for (i = fonts[] - 1; i >= 0; i--)\n\
			defineNewFont(i, fonts[i], \"-misc-fixed-medium-*\");\n\
		return;\n\
	break;\n\
	case \"queryFontID\":\n\
		return getVariable(arg[1]);\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_res_font[] = {
    {"name", _slotValue_res_font0},
    {"class", _slotValue_res_font1},
    {"script", _slotValue_res_font2},
    {(char*)0, (char*)0},
};

static char _slotValue_res_HTMLStyle0[] = "res.HTMLStyle";
static char _slotValue_res_HTMLStyle1[] = "generic";
static char _slotValue_res_HTMLStyle2[] = "";
static char _slotValue_res_HTMLStyle3[] = "\n\
send(\"SGML_vobjf\", \"init\");\n\
/*\n\
send(\"SGML_vobjf\", 'D');\n\
print(\"1000 % 7=\", 1000 % 7, \"...............\\n\
\");\n\
\n\
print(\"=Hi there!=========================================\\n\
\");\n\
x = 199;\n\
y = 41;\n\
Lucifer[666] = \"evil\";\n\
print(\"x=\", x, \"<<<\\n\
\");\n\
print(\"y=\", y, \"<<<\\n\
\");\n\
print(\"Luci=\", Lucifer[666], \"<<<\\n\
\");\n\
print(\"Arg[0]=\", arg[0], \"<<<\\n\
\");\n\
print(\"=goodbye!=========================================\\n\
\");\n\
*/\n\
	/**\n\
 	*** A makeshift HTML Style sheet resource object\n\
 	**/\n\
	switch (arg[0]) {\n\
	case \"id\":\n\
/*\n\
		print(\"=BEGIN============================================\\n\
\");\n\
		foo = get(\"name\");\n\
		print(\"=END==============================================\\n\
\");\n\
		return interpret(\"return \" + arg[1] + \";\");\n\
*/\n\
	break;\n\
	case \"init\":\n\
	/*      tag                             wrap first   right  after\n\
	 *               font           align     free   left    before\n\
	 */\n\
\n\
		S       = \"normal        left   1 1  0   0   0   0  0\";\n\
		P       = \"normal        left   1 0  24  24  24  0  1\";\n\
		OL      = \"normal        left   1 0  24  24  8   0  0\";\n\
		UL      = \"normal        left   1 0  24  24  8   0  0\";\n\
		ULC     = \"normal        left   1 0  24  24  24  0  0\";\n\
		DL      = \"normal        left   1 0  24  150 24  0  1\";\n\
		DLC     = \"normal        left   1 0  24  150 8   0  1\";\n\
		LI      = \"normal        left   1 0  24  24  24  0  1\";\n\
		DIR     = \"normal        left   1 0  24  24  24  1  0\";\n\
		MENU    = \"normal        left   1 0  24  24  24  1  0\";\n\
		HP      = \"normal        left   1 0  0   0   0   1  0\";\n\
		XMP     = \"fixed         left   0 1  0   0   1   1  0\";\n\
		XMPA    = \"fixed         left   0 1  0   0   1   1  0\";\n\
		PRE     = \"fixed         left   0 1  0   0   1   1  1\";\n\
		LISTING = \"normal        left   0 1  0   0   1   1  0\";\n\
		ADDRESS = \"bold_largest  right  0 0  0   0   24  1  1\";\n\
		H1      = \"bold_large    left   0 0  0   0   10   0  0\";\n\
		H2      = \"bold          left   1 0  0   0   8   0  0\";\n\
		H3      = \"bold          left   1 0  24  24  0   0  0\";\n\
		H4      = \"bold          left   1 0  24  24  0   0  0\";\n\
		H5      = \"bold          left   1 0  64  64  0   0  0\";\n\
		H6      = \"bold          left   1 0  128 128 0   0  0\";\n\
		H7      = \"bold          left   1 0  160 170 0   0  0\";\n\
	return 1;\n\
	break;\n\
	case \"queryFontID\":\n\
		return getVariable(arg[1]);\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_res_HTMLStyle[] = {
    {"name", _slotValue_res_HTMLStyle0},
    {"class", _slotValue_res_HTMLStyle1},
    {"parent", _slotValue_res_HTMLStyle2},
    {"script", _slotValue_res_HTMLStyle3},
    {(char*)0, (char*)0},
};

static char _slotValue_res_dialogWithButtons0[] = "vpane";
static char _slotValue_res_dialogWithButtons1[] = "res.dialogWithButtons";
static char _slotValue_res_dialogWithButtons2[] = "600";
static char _slotValue_res_dialogWithButtons3[] = "100";
static char _slotValue_res_dialogWithButtons4[] = "3";
static char _slotValue_res_dialogWithButtons5[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		newDialogBox = clone(id);\n\
		++id;\n\
\n\
		windowName(\"Please respond to this dialog box.\");\n\
\n\
		send(newDialogBox, \"show_mesg\", arg[1]);\n\
		for (argi = 2; argi < arg[]; argi += 2)\n\
			send(newDialogBox, \"adopt\", arg[argi], arg[argi + 1]);\n\
		send(newDialogBox, \"visible\", 1);\n\
\n\
		return newDialogBox;\n\
	break;\n\
	case \"showAt\":\n\
		set(\"x\", arg[1]);\n\
		set(\"y\", arg[2]);\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
\n\
		newDialogBox = clone(id);\n\
		++id;\n\
\n\
		windowName(\"Please respond to this dialog box.\");\n\
\n\
		send(newDialogBox, \"show_mesg\", arg[5]);\n\
		for (argi = 6; argi < arg[]; argi += 2)\n\
			send(newDialogBox, \"adopt\", arg[argi], arg[argi + 1]);\n\
		send(newDialogBox, \"visible\", 1);\n\
\n\
		return newDialogBox;\n\
	break;\n\
	case \"adopt\":\n\
		return send(nthChild(1), \"adopt\", arg[1], arg[2]);\n\
	break;\n\
	case \"show_mesg\":\n\
		return send(nthChild(0), \"show\", arg[1]);\n\
	break;\n\
	case \"done\":\n\
		set(\"visible\", 0);\n\
		after(1000, self(), \"freeSelf\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_dialogWithButtons6[] = "res.dialogWithButtons.mesg res.dialogWithButtons.buttons";
/* END OF OBJ */

static char _slotValue_res_dialogWithButtons8[] = "txtDisp";
static char _slotValue_res_dialogWithButtons9[] = "res.dialogWithButtons.mesg";
static char _slotValue_res_dialogWithButtons10[] = "res.dialogWithButtons";
static char _slotValue_res_dialogWithButtons11[] = "4";
static char _slotValue_res_dialogWithButtons12[] = "4";
static char _slotValue_res_dialogWithButtons13[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"buttonRelease\":\n\
		res.dialogWithButtons.buttons(\"cinfo\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_dialogWithButtons14[] = "normal";
/* END OF OBJ */

static char _slotValue_res_dialogWithButtons16[] = "hpane";
static char _slotValue_res_dialogWithButtons17[] = "res.dialogWithButtons.buttons";
static char _slotValue_res_dialogWithButtons18[] = "res.dialogWithButtons";
static char _slotValue_res_dialogWithButtons19[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
/*		print(\"----------------------------------GGG\\n\
\");\n\
		for (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\
		print(\"\\n\
\");\n\
*/\n\
	break;\n\
	case \"cinfo\":\n\
		objectListSend(\"children\", \"info\");\n\
	break;\n\
	case \"done\":\n\
		send(parent(), arg[0]);\n\
		set(\"children\", \"\");\n\
/*		after(1111, self(), \"rip\");*/\n\
		return;\n\
	break;\n\
	case \"rip\":\n\
/*		objectListSend(\"children\", \"freeSelf\");*/\n\
		set(\"children\", \"\");\n\
		return;\n\
	break;\n\
	case \"adopt\":\n\
		/* arg[1] = <label>\n\
		 * arg[2] = <action script>\n\
		 */\n\
/*\n\
		print(\"----------------------------------\\n\
\");\n\
		print(\"arg[1]>>>>\", arg[1], \"<<\\n\
\");\n\
		print(\"arg[2]>>>>\", arg[2], \"<<\\n\
\");\n\
*/\n\
		cname = concat(\"foo\", countChildren() + 1);\n\
/*		print(\"cname>>>>\", cname, \"<<\\n\
\");\n\
*/\n\
		cscript = concat(\"if (arg[0] == \\\"buttonRelease\\\") {\", \n\
					arg[2], \n\
					\"\\n\
 send(parent(), \\\"done\\\");}\\n\
\",\n\
					\"usual();\");\n\
/*		print(\"cscript>>>>\", cscript, \"<<\\n\
\");\n\
*/\n\
		newobj = create(\"name\", cname,\n\
				\"class\", \"txtButton\",\n\
				\"parent\", self(),\n\
				\"label\", arg[1],\n\
				\"script\", cscript,\n\
				\"width\", \"50\",\n\
				\"height\", \"50\",\n\
				\"font\", \"any\",\n\
				\"gapH\", \"10\");\n\
\n\
		set(\"children\", concat(get(\"children\"), \" \", newobj));\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_dialogWithButtons20[] = "25";
static char _slotValue_res_dialogWithButtons21[] = "4";
static char _slotValue_res_dialogWithButtons22[] = "4";
/* END OF FILE */

static SlotStruct objDesc_res_dialogWithButtons[] = {
    {"class", _slotValue_res_dialogWithButtons0},
    {"name", _slotValue_res_dialogWithButtons1},
    {"width", _slotValue_res_dialogWithButtons2},
    {"height", _slotValue_res_dialogWithButtons3},
    {"border", _slotValue_res_dialogWithButtons4},
    {"script", _slotValue_res_dialogWithButtons5},
    {"children", _slotValue_res_dialogWithButtons6},
    {(char*)0, (char*)1},
    {"class", _slotValue_res_dialogWithButtons8},
    {"name", _slotValue_res_dialogWithButtons9},
    {"parent", _slotValue_res_dialogWithButtons10},
    {"gapH", _slotValue_res_dialogWithButtons11},
    {"gapV", _slotValue_res_dialogWithButtons12},
    {"script", _slotValue_res_dialogWithButtons13},
    {"font", _slotValue_res_dialogWithButtons14},
    {(char*)0, (char*)1},
    {"class", _slotValue_res_dialogWithButtons16},
    {"name", _slotValue_res_dialogWithButtons17},
    {"parent", _slotValue_res_dialogWithButtons18},
    {"script", _slotValue_res_dialogWithButtons19},
    {"maxHeight", _slotValue_res_dialogWithButtons20},
    {"gapV", _slotValue_res_dialogWithButtons21},
    {"gapH", _slotValue_res_dialogWithButtons22},
    {(char*)0, (char*)0},
};

static char _slotValue_res_getLineEntry0[] = "vpane";
static char _slotValue_res_getLineEntry1[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry2[] = "";
static char _slotValue_res_getLineEntry3[] = "400";
static char _slotValue_res_getLineEntry4[] = "85";
static char _slotValue_res_getLineEntry5[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		/* arg[1]	display message\n\
		 * arg[2]	default entry\n\
		 * arg[3]	caller, the obj to return result to\n\
		 * arg[4]	returning message token\n\
		 * arg[5]	optional x position\n\
		 * arg[6]	optional y position\n\
		 */\n\
		newObj = clone(id);\n\
		id++;\n\
		if (arg[] > 5)\n\
		  return send(newObj, \"_show\", arg[1], arg[2], arg[3], arg[4],\n\
				arg[5], arg[6]);\n\
		else \n\
		  return send(newObj, \"_show\", arg[1], arg[2], arg[3], arg[4]);\n\
	break;\n\
	case \"_show\":\n\
		if (arg[] > 5) {\n\
			set(\"x\", arg[5]);\n\
			set(\"y\", arg[6]);\n\
		}\n\
		send(nthChild(0), \"show\", arg[1]);\n\
		send(nthChild(1), \"show\", arg[2]);\n\
		caller = arg[3];\n\
		returnMessage = arg[4];\n\
\n\
		windowName(\"Attention, please...\");\n\
		send(newObj, \"visible\", 1);\n\
		set(\"visible\", 1);\n\
		return self();\n\
	break;\n\
	case \"_ok\":\n\
		set(\"visible\", 0);\n\
		send(caller, returnMessage, send(nthChild(1), \"contentP\"));\n\
		return;\n\
	break;\n\
	case \"_cancel\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_getLineEntry6[] = "res.getLineEntry.mesg res.getLineEntry.entry res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry7[] = "6";
/* END OF OBJ */

static char _slotValue_res_getLineEntry9[] = "txtDisp";
static char _slotValue_res_getLineEntry10[] = "res.getLineEntry.mesg";
static char _slotValue_res_getLineEntry11[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry12[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_getLineEntry13[] = "2";
static char _slotValue_res_getLineEntry14[] = "2";
static char _slotValue_res_getLineEntry15[] = "normal";
/* END OF OBJ */

static char _slotValue_res_getLineEntry17[] = "txtEdit";
static char _slotValue_res_getLineEntry18[] = "res.getLineEntry.entry";
static char _slotValue_res_getLineEntry19[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry20[] = "\n\
	switch (arg[0]) {\n\
	case \"keyPress\":\n\
		c = key();\n\
		if (c == '\\r' || c == '\\n\
') {\n\
			send(parent(), \"_ok\");\n\
			return;\n\
		} else {\n\
			insert(c);\n\
			return;\n\
		}\n\
	break;\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"contentP\":\n\
		return get(\"content\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_getLineEntry21[] = "4";
static char _slotValue_res_getLineEntry22[] = "4";
static char _slotValue_res_getLineEntry23[] = "normal";
/* END OF OBJ */

static char _slotValue_res_getLineEntry25[] = "hpane";
static char _slotValue_res_getLineEntry26[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry27[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry28[] = "res.getLineEntry.buttons.ok res.getLineEntry.buttons.cancel";
static char _slotValue_res_getLineEntry29[] = "\n\
	switch (arg[0]) {\n\
	case \"_cancel\":\n\
	case \"_ok\":\n\
		send(parent(), arg[0]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_getLineEntry30[] = "22";
static char _slotValue_res_getLineEntry31[] = "3";
/* END OF OBJ */

static char _slotValue_res_getLineEntry33[] = "txtButton";
static char _slotValue_res_getLineEntry34[] = "OK";
static char _slotValue_res_getLineEntry35[] = "res.getLineEntry.buttons.ok";
static char _slotValue_res_getLineEntry36[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry37[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(parent(), \"_ok\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_getLineEntry38[] = "10";
/* END OF OBJ */

static char _slotValue_res_getLineEntry40[] = "txtButton";
static char _slotValue_res_getLineEntry41[] = "Cancel";
static char _slotValue_res_getLineEntry42[] = "res.getLineEntry.buttons.cancel";
static char _slotValue_res_getLineEntry43[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry44[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(parent(), \"_cancel\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_res_getLineEntry45[] = "10";
/* END OF FILE */

static SlotStruct objDesc_res_getLineEntry[] = {
    {"class", _slotValue_res_getLineEntry0},
    {"name", _slotValue_res_getLineEntry1},
    {"parent", _slotValue_res_getLineEntry2},
    {"width", _slotValue_res_getLineEntry3},
    {"height", _slotValue_res_getLineEntry4},
    {"script", _slotValue_res_getLineEntry5},
    {"children", _slotValue_res_getLineEntry6},
    {"border", _slotValue_res_getLineEntry7},
    {(char*)0, (char*)1},
    {"class", _slotValue_res_getLineEntry9},
    {"name", _slotValue_res_getLineEntry10},
    {"parent", _slotValue_res_getLineEntry11},
    {"script", _slotValue_res_getLineEntry12},
    {"gapH", _slotValue_res_getLineEntry13},
    {"gapV", _slotValue_res_getLineEntry14},
    {"font", _slotValue_res_getLineEntry15},
    {(char*)0, (char*)1},
    {"class", _slotValue_res_getLineEntry17},
    {"name", _slotValue_res_getLineEntry18},
    {"parent", _slotValue_res_getLineEntry19},
    {"script", _slotValue_res_getLineEntry20},
    {"gapH", _slotValue_res_getLineEntry21},
    {"gapV", _slotValue_res_getLineEntry22},
    {"font", _slotValue_res_getLineEntry23},
    {(char*)0, (char*)1},
    {"class", _slotValue_res_getLineEntry25},
    {"name", _slotValue_res_getLineEntry26},
    {"parent", _slotValue_res_getLineEntry27},
    {"children", _slotValue_res_getLineEntry28},
    {"script", _slotValue_res_getLineEntry29},
    {"maxHeight", _slotValue_res_getLineEntry30},
    {"gapV", _slotValue_res_getLineEntry31},
    {(char*)0, (char*)1},
    {"class", _slotValue_res_getLineEntry33},
    {"label", _slotValue_res_getLineEntry34},
    {"name", _slotValue_res_getLineEntry35},
    {"parent", _slotValue_res_getLineEntry36},
    {"script", _slotValue_res_getLineEntry37},
    {"gapH", _slotValue_res_getLineEntry38},
    {(char*)0, (char*)1},
    {"class", _slotValue_res_getLineEntry40},
    {"label", _slotValue_res_getLineEntry41},
    {"name", _slotValue_res_getLineEntry42},
    {"parent", _slotValue_res_getLineEntry43},
    {"script", _slotValue_res_getLineEntry44},
    {"gapH", _slotValue_res_getLineEntry45},
    {(char*)0, (char*)0},
};

static char _slotValue_shell0[] = "shell";
static char _slotValue_shell1[] = "vpane";
static char _slotValue_shell2[] = "";
static char _slotValue_shell3[] = "1";
static char _slotValue_shell4[] = "500";
static char _slotValue_shell5[] = "200";
static char _slotValue_shell6[] = "\n\
	switch (arg[0]) {\n\
	case \"targetSet\":\n\
		shell.obj.entry(\"show\");\n\
		return;\n\
	break;\n\
	case \"raise\":\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"dismiss\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_shell7[] = "shell.top shell.obj shell.in shell.out shell.mesg";
static char _slotValue_shell8[] = "3";
/* END OF OBJ */

static char _slotValue_shell10[] = "shell.top";
static char _slotValue_shell11[] = "hpane";
static char _slotValue_shell12[] = "shell";
static char _slotValue_shell13[] = "1";
static char _slotValue_shell14[] = "shell.top.tools shell.top.ops shell.top.attrs shell.top.title shell.top.dismiss";
static char _slotValue_shell15[] = "25";
static char _slotValue_shell16[] = "2";
static char _slotValue_shell17[] = "2";
static char _slotValue_shell18[] = "3";
/* END OF OBJ */

static char _slotValue_shell20[] = "shell.top.tools";
static char _slotValue_shell21[] = "menu";
static char _slotValue_shell22[] = "shell.top";
static char _slotValue_shell23[] = "Tools";
static char _slotValue_shell24[] = "1";
static char _slotValue_shell25[] = "\n\
	switch (arg[0]) {\n\
	case \"tool\":\n\
		tool(arg[1]);\n\
		shell.mesg(\"show\", concatenate(\"current tool: \", arg[1]));\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_shell26[] = "\n\
.	{Action}		{shell.top.tools(\"tool\", \"action\");}\n\
.	{Target}		{shell.top.tools(\"tool\", \"target\");}\n\
.	{Move}			{shell.top.tools(\"tool\", \"move\");}\n\
.	{Resize}		{shell.top.tools(\"tool\", \"resize\");}\n\
.	{Reparent}		{shell.top.tools(\"tool\", \"reparent\");}\n\
";
static char _slotValue_shell27[] = "normal";
static char _slotValue_shell28[] = "70";
static char _slotValue_shell29[] = "3";
static char _slotValue_shell30[] = "2";
/* END OF OBJ */

static char _slotValue_shell32[] = "shell.top.ops";
static char _slotValue_shell33[] = "menu";
static char _slotValue_shell34[] = "shell.top";
static char _slotValue_shell35[] = "Operations";
static char _slotValue_shell36[] = "1";
static char _slotValue_shell37[] = "\n\
	switch (arg[0]) {\n\
	case \"cloneTarget\":\n\
		new = tweak(target(), \"clone(1);\");\n\
		print(\"newobj=\", new, \"\\n\
\");\n\
		tweak(new, \"set(\\\"parent\\\", \\\"\\\");\");\n\
		send(new, \"info\");\n\
		send(new, \"visible\", 1);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_shell38[] = "\n\
.	{Target parent}		{target(tweak(target(), \"get(\\\"parent\\\");\"));}\n\
.	{Clone target}		{shell.top.tools(\"cloneTarget\");}\n\
.	{Info target}		{tweak(target(), \"info();\");}\n\
.	{Save target}		{tweak(target(), \"save();\");}\n\
.	{}\n\
.	{Create object}		{op_create(\"visible\", 1);}\n\
.	{}\n\
.	{Vicon}			{vicon(\"visible\", 1);}\n\
.	{save dump}		{saveAs(\"foo\");}\n\
.	{save command text}	{shell.in.tf(\"saveText\");}\n\
.	{load command text}	{shell.in.tf(\"loadText\");}\n\
.	{Quit}			{quit();}\n\
";
static char _slotValue_shell39[] = "normal";
static char _slotValue_shell40[] = "100";
static char _slotValue_shell41[] = "2";
static char _slotValue_shell42[] = "2";
/* END OF OBJ */

static char _slotValue_shell44[] = "shell.top.attrs";
static char _slotValue_shell45[] = "menu";
static char _slotValue_shell46[] = "shell.top";
static char _slotValue_shell47[] = "Attributes";
static char _slotValue_shell48[] = "1";
static char _slotValue_shell49[] = "\n\
.	{content}		{ed_TE(\"edit\", target(), \"content\");}\n\
.	{script}		{ed_TE(\"edit\", target(), \"script\");}\n\
.	{label}			{ed_label(\"edit\", target());}\n\
.	{BDColor}		{ed_BDColor(\"visible\", 1);}\n\
.	{BGColor}		{ed_BGColor(\"visible\", 1);}\n\
.	{FGColor}		{ed_FGColor(\"visible\", 1);}\n\
.	{CRColor}		{ed_CRColor(\"visible\", 1);}\n\
.	{content}		{ed_content(\"visible\", 1);}\n\
.	{menuConfig}		{ed_menuConfig(\"visible\", 1);}\n\
.	{geometry}		{ed_geometry(\"visible\", 1);}\n\
.	{script}		{ed_script(\"visible\", 1);}\n\
";
static char _slotValue_shell50[] = "normal";
static char _slotValue_shell51[] = "100";
static char _slotValue_shell52[] = "2";
static char _slotValue_shell53[] = "2";
/* END OF OBJ */

static char _slotValue_shell55[] = "shell.top.title";
static char _slotValue_shell56[] = "field";
static char _slotValue_shell57[] = "shell.top";
static char _slotValue_shell58[] = "1";
static char _slotValue_shell59[] = "2";
/* END OF OBJ */

static char _slotValue_shell61[] = "shell.top.dismiss";
static char _slotValue_shell62[] = "txtButton";
static char _slotValue_shell63[] = "shell.top";
static char _slotValue_shell64[] = "1";
static char _slotValue_shell65[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"shell\", \"dismiss\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_shell66[] = "100";
static char _slotValue_shell67[] = "Dismiss";
static char _slotValue_shell68[] = "5";
static char _slotValue_shell69[] = "2";
/* END OF OBJ */

static char _slotValue_shell71[] = "shell.obj";
static char _slotValue_shell72[] = "hpane";
static char _slotValue_shell73[] = "shell";
static char _slotValue_shell74[] = "shell.obj.label shell.obj.entry";
static char _slotValue_shell75[] = "20";
static char _slotValue_shell76[] = "1";
static char _slotValue_shell77[] = "3";
static char _slotValue_shell78[] = "2";
/* END OF OBJ */

static char _slotValue_shell80[] = "shell.obj.label";
static char _slotValue_shell81[] = "txtLabel";
static char _slotValue_shell82[] = "shell.obj";
static char _slotValue_shell83[] = "Object:";
static char _slotValue_shell84[] = "80";
static char _slotValue_shell85[] = "1";
/* END OF OBJ */

static char _slotValue_shell87[] = "shell.obj.entry";
static char _slotValue_shell88[] = "txtEdit";
static char _slotValue_shell89[] = "shell.obj";
static char _slotValue_shell90[] = "1";
static char _slotValue_shell91[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", target());\n\
		if (get(\"window\")) render();\n\
		return;\n\
	break;\n\
	case \"keyPress\":\n\
		c = key();\n\
		if (c == '\\r') {\n\
			if (isBlank(target())) target(\"res\");\n\
			target(currentLine());\n\
			shell.obj.entry(\"show\");\n\
			return;\n\
		} else {\n\
			insert(c);\n\
			return;\n\
		}\n\
	break;\n\
	case \"init\":\n\
		set(\"content\", target());\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_shell93[] = "shell.in";
static char _slotValue_shell94[] = "hpane";
static char _slotValue_shell95[] = "shell";
static char _slotValue_shell96[] = "1";
static char _slotValue_shell97[] = "shell.in.sb shell.in.tf";
static char _slotValue_shell98[] = "3";
/* END OF OBJ */

static char _slotValue_shell100[] = "shell.in.sb";
static char _slotValue_shell101[] = "slider";
static char _slotValue_shell102[] = "shell.in";
static char _slotValue_shell103[] = "1";
static char _slotValue_shell104[] = "shell.in.tf";
static char _slotValue_shell105[] = "15";
/* END OF OBJ */

static char _slotValue_shell107[] = "shell.in.tf";
static char _slotValue_shell108[] = "txtEdit";
static char _slotValue_shell109[] = "shell.in";
static char _slotValue_shell110[] = "1";
static char _slotValue_shell111[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonPress\":\n\
/*		print(\"DUMPING CONTENT\\n\
 {\", get(\"content\"), \"}\\n\
\");*/\n\
	break;\n\
	case \"keyPress\":\n\
		c = key();\n\
		if (c == '\\r') {\n\
			print(\"issue command:\", currentLine(), \"\\n\
\");\n\
			if (isBlank(target())) target(\"res\");\n\
			ret = tweak(target(), currentLine());\n\
			shell.obj.entry(\"show\");\n\
			insert('\\r');\n\
			shell.out.tf(\"insert\", ret);\n\
			return;\n\
		} else {\n\
			insert(c);\n\
			return;\n\
		}\n\
	break;\n\
	case \"saveText\":\n\
		saveFile(\".shellCmds\", get(\"content\"));\n\
		return;\n\
	break;\n\
	case \"loadText\":\n\
		path = accessible(\".shellCmds\");\n\
		if (path != \"\") {\n\
			set(\"content\", loadFile(path));\n\
			render();\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		path = accessible(\".shellCmds\");\n\
		if (path != \"\") {\n\
			set(\"content\", loadFile(path));\n\
		}\n\
		if (isBlank(target())) target(\"res\");\n\
	break;\n\
	case \"expose\":\n\
		usual();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_shell112[] = "shell.in.sb";
static char _slotValue_shell113[] = "1";
static char _slotValue_shell114[] = "fixed";
/* END OF OBJ */

static char _slotValue_shell116[] = "shell.out";
static char _slotValue_shell117[] = "hpane";
static char _slotValue_shell118[] = "shell";
static char _slotValue_shell119[] = "1";
static char _slotValue_shell120[] = "shell.out.sb shell.out.tf";
static char _slotValue_shell121[] = "3";
/* END OF OBJ */

static char _slotValue_shell123[] = "shell.out.sb";
static char _slotValue_shell124[] = "slider";
static char _slotValue_shell125[] = "shell.out";
static char _slotValue_shell126[] = "1";
static char _slotValue_shell127[] = "shell.out.tf";
static char _slotValue_shell128[] = "15";
/* END OF OBJ */

static char _slotValue_shell130[] = "shell.out.tf";
static char _slotValue_shell131[] = "shell.out";
static char _slotValue_shell132[] = "txtEdit";
static char _slotValue_shell133[] = "1";
static char _slotValue_shell134[] = "\n\
	switch (arg[0]) {\n\
	case \"insert\":\n\
		print(\"ret = \", arg[1], \"\\n\
\");\n\
		insert(arg[1]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_shell135[] = "shell.out.sb";
static char _slotValue_shell136[] = "1";
static char _slotValue_shell137[] = "fixed";
/* END OF OBJ */

static char _slotValue_shell139[] = "shell.mesg";
static char _slotValue_shell140[] = "txtDisp";
static char _slotValue_shell141[] = "shell";
static char _slotValue_shell142[] = "1";
static char _slotValue_shell143[] = "\n\
	if (arg[0] == \"show\") {\n\
		set(\"content\", arg[1]);\n\
		render();\n\
		return;\n\
	}\n\
	usual();\n\
";
static char _slotValue_shell144[] = "Messages";
static char _slotValue_shell145[] = "usual_small";
static char _slotValue_shell146[] = "20";
static char _slotValue_shell147[] = "3";
static char _slotValue_shell148[] = "3";
/* END OF FILE */

static SlotStruct objDesc_shell[] = {
    {"name", _slotValue_shell0},
    {"class", _slotValue_shell1},
    {"parent", _slotValue_shell2},
    {"lock", _slotValue_shell3},
    {"width", _slotValue_shell4},
    {"height", _slotValue_shell5},
    {"script", _slotValue_shell6},
    {"children", _slotValue_shell7},
    {"border", _slotValue_shell8},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell10},
    {"class", _slotValue_shell11},
    {"parent", _slotValue_shell12},
    {"lock", _slotValue_shell13},
    {"children", _slotValue_shell14},
    {"maxHeight", _slotValue_shell15},
    {"gapV", _slotValue_shell16},
    {"gapH", _slotValue_shell17},
    {"border", _slotValue_shell18},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell20},
    {"class", _slotValue_shell21},
    {"parent", _slotValue_shell22},
    {"label", _slotValue_shell23},
    {"lock", _slotValue_shell24},
    {"script", _slotValue_shell25},
    {"menuConfig", _slotValue_shell26},
    {"font", _slotValue_shell27},
    {"maxWidth", _slotValue_shell28},
    {"gapH", _slotValue_shell29},
    {"gapV", _slotValue_shell30},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell32},
    {"class", _slotValue_shell33},
    {"parent", _slotValue_shell34},
    {"label", _slotValue_shell35},
    {"lock", _slotValue_shell36},
    {"script", _slotValue_shell37},
    {"menuConfig", _slotValue_shell38},
    {"font", _slotValue_shell39},
    {"maxWidth", _slotValue_shell40},
    {"gapH", _slotValue_shell41},
    {"gapV", _slotValue_shell42},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell44},
    {"class", _slotValue_shell45},
    {"parent", _slotValue_shell46},
    {"label", _slotValue_shell47},
    {"lock", _slotValue_shell48},
    {"menuConfig", _slotValue_shell49},
    {"font", _slotValue_shell50},
    {"maxWidth", _slotValue_shell51},
    {"gapH", _slotValue_shell52},
    {"gapV", _slotValue_shell53},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell55},
    {"class", _slotValue_shell56},
    {"parent", _slotValue_shell57},
    {"lock", _slotValue_shell58},
    {"gapV", _slotValue_shell59},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell61},
    {"class", _slotValue_shell62},
    {"parent", _slotValue_shell63},
    {"lock", _slotValue_shell64},
    {"script", _slotValue_shell65},
    {"maxWidth", _slotValue_shell66},
    {"label", _slotValue_shell67},
    {"gapH", _slotValue_shell68},
    {"gapV", _slotValue_shell69},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell71},
    {"class", _slotValue_shell72},
    {"parent", _slotValue_shell73},
    {"children", _slotValue_shell74},
    {"maxHeight", _slotValue_shell75},
    {"lock", _slotValue_shell76},
    {"gapH", _slotValue_shell77},
    {"gapV", _slotValue_shell78},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell80},
    {"class", _slotValue_shell81},
    {"parent", _slotValue_shell82},
    {"label", _slotValue_shell83},
    {"maxWidth", _slotValue_shell84},
    {"lock", _slotValue_shell85},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell87},
    {"class", _slotValue_shell88},
    {"parent", _slotValue_shell89},
    {"lock", _slotValue_shell90},
    {"script", _slotValue_shell91},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell93},
    {"class", _slotValue_shell94},
    {"parent", _slotValue_shell95},
    {"lock", _slotValue_shell96},
    {"children", _slotValue_shell97},
    {"gapH", _slotValue_shell98},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell100},
    {"class", _slotValue_shell101},
    {"parent", _slotValue_shell102},
    {"lock", _slotValue_shell103},
    {"shownNotify", _slotValue_shell104},
    {"maxWidth", _slotValue_shell105},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell107},
    {"class", _slotValue_shell108},
    {"parent", _slotValue_shell109},
    {"lock", _slotValue_shell110},
    {"script", _slotValue_shell111},
    {"shownDepend", _slotValue_shell112},
    {"verbatim", _slotValue_shell113},
    {"font", _slotValue_shell114},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell116},
    {"class", _slotValue_shell117},
    {"parent", _slotValue_shell118},
    {"lock", _slotValue_shell119},
    {"children", _slotValue_shell120},
    {"gapH", _slotValue_shell121},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell123},
    {"class", _slotValue_shell124},
    {"parent", _slotValue_shell125},
    {"lock", _slotValue_shell126},
    {"shownNotify", _slotValue_shell127},
    {"maxWidth", _slotValue_shell128},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell130},
    {"parent", _slotValue_shell131},
    {"class", _slotValue_shell132},
    {"lock", _slotValue_shell133},
    {"script", _slotValue_shell134},
    {"shownDepend", _slotValue_shell135},
    {"verbatim", _slotValue_shell136},
    {"font", _slotValue_shell137},
    {(char*)0, (char*)1},
    {"name", _slotValue_shell139},
    {"class", _slotValue_shell140},
    {"parent", _slotValue_shell141},
    {"lock", _slotValue_shell142},
    {"script", _slotValue_shell143},
    {"content", _slotValue_shell144},
    {"font", _slotValue_shell145},
    {"maxHeight", _slotValue_shell146},
    {"gapH", _slotValue_shell147},
    {"gapV", _slotValue_shell148},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_fail0[] = "txtDisp";
static char _slotValue_VWHandler_fail1[] = "VWHandler_fail";
static char _slotValue_VWHandler_fail2[] = "\n\
	switch (arg[0]) {\n\
	case \"report\":\n\
		reason = arg[1];\n\
/*print(\"############### FAILURE REPORT ##############\\n\
\",\n\
reason, \"\\n\
#############################################\\n\
\");\n\
*/\n\
		return;\n\
	break;\n\
	case \"reportP\":\n\
		return reason;\n\
	break;\n\
	case \"make\":\n\
		set(\"parent\", arg[1]);	\n\
		set(\"name\", arg[2]);\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
\n\
		/* reason of failure assume to be previously reported by\n\
		 * the failure detection point\n\
		 */\n\
		set(\"content\", VWHandler_fail(\"reportP\"));\n\
		reason = \"Cause of failure unreported.\"; /* reset */\n\
\n\
		return self();\n\
	break;\n\
	case \"clone\":\n\
		return clone(arg[1]);\n\
	break;\n\
	case 'T':\n\
		/* arg[1] = y\n\
		 * arg[2] = width\n\
		 */\n\
		h = get(\"height\");\n\
		parentHeight = send(parent(), \"heightP\");\n\
		heightDiff = h - parentHeight;\n\
		if (heightDiff > 0) {\n\
			heightRatio =  float(heightDiff) / -100.0;\n\
		} else {\n\
			heightRatio = 0;\n\
			h = parentHeight;\n\
			set(\"height\", h);\n\
		}\n\
		prevWidth = arg[2];\n\
		prevHeight = parentHeight;\n\
		return h;\n\
	break;\n\
	case \"nameAndURL\":\n\
		docName = arg[1];\n\
		docURL = arg[2];\n\
		return;		\n\
	break;\n\
	case \"queryAddress\":\n\
		return docURL;\n\
	break;\n\
	case \"queryTitle\":\n\
		return \"Access Failure\";\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return 0;\n\
	break;\n\
	case \"historyRecord\":\n\
		wwwHistory(\"add\", docName, docURL);\n\
		return;\n\
	break;\n\
	case \"raise\":\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"show\":\n\
		set(\"visible\", 1);\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		raise();\n\
		if (arg[1] != prevWidth) {\n\
			/* need to re-format */\n\
			send(self(), \"resize\", arg[1], arg[2]);\n\
		} else if (arg[2] != prevHeight) {\n\
			/* just adjust window height */\n\
			send(self(), \"resize\", arg[1], arg[2]);\n\
		}\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
		return self();\n\
	break;\n\
	case \"yP\":\n\
		return y();\n\
	break;\n\
	case \"y\":\n\
		return set(\"y\", arg[1]);\n\
	break;\n\
	case \"heightP\":\n\
	case \"vspan\":\n\
		return height();\n\
	break;\n\
	case \"VW_relay\":\n\
		relay_obj[relayIdx] = arg[1];\n\
		relay_event[relayIdx] = arg[2];\n\
	 	relayIdx= relayIdx + 1;\n\
		return 1;\n\
	break;\n\
	case \"VW_event\":\n\
		event = arg[1];\n\
		for (i = 0; i < relayIdx; i = i + 1) {\n\
			if (relay_event[i] = event) {\n\
				send(relay_obj[i], event);\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_fail3[] = "fixed";
static char _slotValue_VWHandler_fail4[] = "grey75";
static char _slotValue_VWHandler_fail5[] = "LemonChiffon1";
static char _slotValue_VWHandler_fail6[] = "black";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_fail[] = {
    {"class", _slotValue_VWHandler_fail0},   {"name", _slotValue_VWHandler_fail1},
    {"script", _slotValue_VWHandler_fail2},  {"font", _slotValue_VWHandler_fail3},
    {"BDColor", _slotValue_VWHandler_fail4}, {"BGColor", _slotValue_VWHandler_fail5},
    {"FGColor", _slotValue_VWHandler_fail6}, {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_gif0[] = "generic";
static char _slotValue_VWHandler_gif1[] = "VWHandler_gif";
static char _slotValue_VWHandler_gif2[] = "\n\
	switch (arg[0]) {\n\
	case \"build\":\n\
		/* arg[1]	sourcefile\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 * ret		documentObject or 0\n\
		 */\n\
		docObj = VWHandler_gif.gif(\"clone\");\n\
		send(docObj, \"build\", arg[1], arg[2], arg[3], arg[4]);\n\
\n\
		if (isBlank(docObj) == 1) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
			  concat(\"VWHandler_gif:\\n\
failed to access: \", \n\
				arg[1], \"\\n\
\"));\n\
\n\
			www.mesg.tf(\"show\", \n\
				    concatenate(\"Failed to get \", arg[1]));\n\
			cursorShape(\"idle\");\n\
			return 0;\n\
		} else {\n\
			www.mesg.tf(\"show\", \"\");\n\
			www.udi.tf(\"show\", arg[1]);\n\
\n\
			www.doc.ctrl.label(\"index\", 0);\n\
			www.doc.ctrl.tf(\"index\", 0);\n\
\n\
			cursorShape(\"idle\");\n\
			return docObj;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_VWHandler_gif4[] = "GIF";
static char _slotValue_VWHandler_gif5[] = "VWHandler_gif.gif";
static char _slotValue_VWHandler_gif6[] = "\n\
	switch (arg[0]) {\n\
	case \"y\":\n\
		set(\"y\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		if (width() != arg[3]) {\n\
			loadDoc = 1;\n\
		} else if (height() != arg[4]) {\n\
			loadDoc = 1;\n\
		} else {\n\
			loadDoc = 0;\n\
		}\n\
		if (loadDoc == 1) {\n\
			clearWindow();\n\
			set(\"width\", arg[3]);\n\
			set(\"height\", arg[4]);\n\
			render();\n\
		}\n\
		return;\n\
	break;\n\
	case \"yP\":\n\
		return y();\n\
	break;\n\
	case \"heightP\":\n\
		return height();\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	sourcefile\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 */\n\
		docURL = arg[1];\n\
		docName = arg[3];\n\
		set(\"parent\", arg[2]);\n\
		set(\"name\", docName);\n\
\n\
		prevWidth = arg[4];\n\
		prevHeight = send(parent(), \"heightP\");\n\
\n\
		localFile = HTTPGet(docURL);\n\
		if (isBlank(localFile) == 1) {\n\
			www.mesg.tf(\"show\", \n\
				    concatenate(\"Failed to get \", arg[1]));\n\
			cursorShape(\"idle\");\n\
			return 0;\n\
		} else {\n\
			set(\"width\", 0);\n\
			set(\"height\", 0);\n\
			set(\"label\", localFile);\n\
			cursorShape(\"idle\");\n\
			return get(\"name\");\n\
		}\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		raise();\n\
		if (arg[1] != prevWidth) {\n\
			prevWidth = arg[1];\n\
			set(\"width\", prevWidth);\n\
		} else if (arg[2] != prevHeight) {\n\
			prevHeight = arg[2];\n\
			set(\"height\", prevHeight);\n\
		}\n\
		return;\n\
	break;\n\
	case \"historyRecord\":\n\
		wwwHistory(\"add\", docName, docURL);\n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		set(\"label\", localFile);\n\
		render();\n\
		return;\n\
	break;\n\
	case \"save\":\n\
		bell(1);\n\
		return;\n\
	break;\n\
	case \"queryAddress\":\n\
		return docURL;\n\
	break;\n\
	case \"queryTitle\":\n\
		return docName;\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return 0;\n\
	break;\n\
	case \"tree\":\n\
		/* produce a n-level anchors tree by recursively fetching\n\
		 * anchor links \n\
		 */\n\
		return;\n\
	break;\n\
	case \"showSrc\":\n\
/*\n\
		VWHANDLER_GIF_EDITOR = \"xv\";\n\
		system(concat(VWHANDLER_GIF_EDITOR, \" \", localFile));\n\
		set(\"label\", localFile);\n\
		render();\n\
*/\n\
		res.dialogWithButtons(\"show\", \n\
				    concat(\"For source, please refer to:\\n\
\",\n\
						 \"docName: \", docName, \n\
						 \"\\n\
Doc URL: \", docURL),\n\
					\"OK\", \"\");\n\
		return;\n\
	break;\n\
	case \"outlineSrc\":\n\
		www.mesg.tf(\"show\", \n\
			    concatenate(\"Outliner not available for GIF\\n\
\"));\n\
		return;\n\
	break;\n\
	case \"print\":\n\
		www.mesg.tf(\"show\", \n\
		    concat(\"Printing facillity not available for GIF.\\n\
\"));\n\
		return;\n\
 	break;\n\
	case \"torn\":\n\
		isTorn = 1;\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
		set(\"cursor\", 0); \n\
		return;\n\
	break;\n\
	case \"raise\":\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(0);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_gif7[] = "grey45";
static char _slotValue_VWHandler_gif8[] = "LemonChiffon1";
static char _slotValue_VWHandler_gif9[] = "black";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_gif[] = {
    {"class", _slotValue_VWHandler_gif0},
    {"name", _slotValue_VWHandler_gif1},
    {"script", _slotValue_VWHandler_gif2},
    {(char*)0, (char*)1},
    {"class", _slotValue_VWHandler_gif4},
    {"name", _slotValue_VWHandler_gif5},
    {"script", _slotValue_VWHandler_gif6},
    {"BDColor", _slotValue_VWHandler_gif7},
    {"BGColor", _slotValue_VWHandler_gif8},
    {"FGColor", _slotValue_VWHandler_gif9},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_hmml0[] = "generic";
static char _slotValue_VWHandler_hmml1[] = "VWHandler_hmml";
static char _slotValue_VWHandler_hmml2[] = "\n\
	switch (arg[0]) {\n\
	case 'I':\n\
		/* returns ID for new HMML Internal Object */\n\
		objID = objID + 1;\n\
		return concat(\"IObj_hmml\", objID);\n\
	break;\n\
	case 'B':\n\
		/* arg[1]	URL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 * arg[5]	anchor\n\
		 * ret		documentObject or 0\n\
		 */\n\
/*\n\
		print(\"################\\n\
\");\n\
		print(\"##### HMML #####\\n\
\");\n\
		print(\"################\\n\
\");\n\
*/\n\
		sourceFile = arg[1];\n\
		localFile = HTTPGet(sourceFile);\n\
		docName = arg[3];\n\
/*\n\
		print(\"sourceFile='\", sourceFile, \"'\\n\
\");\n\
		print(\"localFile='\", localFile, \"'\\n\
\");\n\
*/\n\
		if (localFile == 0) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
	   concat(\"VWHandler_hmml:\\n\
failed to fetch source : \", sourceFile));\n\
			return 0;\n\
		}\n\
		if (arg[] < 5) {\n\
			arg[4] = send(\"VWHandler_hmml.doc.view\", \"widthP\");\n\
		}\n\
/*\n\
		print(\"1 tmpFile=\", tmpFile, \"\\n\
\");\n\
		print(\"1 sourceFile = {\", sourceFile, \"}\\n\
\");\n\
*/\n\
		tmpFile = makeTempFile();\n\
\n\
/*\n\
		print(\"exec: \", concat(sgmlsA2BPath, \" HMML \", localFile, \n\
						\" > \", tmpFile), \"\\n\
\");\n\
		print(\"############ sgmls'ing ########\\n\
\");\n\
		stat = system(concat(sgmlsA2BPath, \" HMML \", localFile, \n\
					\" > \", tmpFile));\n\
*/\n\
/*\n\
		print(\"exec: \", concat(\"sgmls \", localFile, \n\
						\" > \", tmpFile), \"\\n\
\");\n\
		print(\"############ sgmls'ing ########\\n\
\");\n\
*/\n\
		stat = system(concat(\"sgmls \", localFile, \n\
					\" > \", tmpFile));\n\
\n\
/*		print(\"stat=\", stat, \"\\n\
\");*/\n\
\n\
/*		system(concat(\"rm -f \", localFile));*/\n\
\n\
		if (stat == -1) {\n\
			send(\"VWHandler_fail\", \"reason\", \n\
		   concat(\"VWHandler_hmml:\\n\
Failed to convert document from HMML to HMMLB.\\n\
\",\n\
\"Possibly due to viola unable to find the programs: sgmlsA2B and/or sgmls\"));\n\
\n\
			return 0;\n\
		}\n\
/*\n\
		print(\"2 tmpFile=\", tmpFile, \"\\n\
\");\n\
		print(\"2 localFile = {\", localFile, \"}\\n\
\");\n\
		print(\"2 sourceFile = {\", sourceFile, \"}\\n\
\");\n\
		print(\"############ building docObj ########\\n\
\");\n\
		print(\"url='\", arg[1], \"'\\n\
\");\n\
*/\n\
		HTTPCurrentDocAddrSet(sourceFile);\n\
\n\
		docObj = SGMLBuildDoc(UNUSED,\n\
			    tmpFile, arg[2], docName, arg[4], arg[5]);\n\
\n\
		send(docObj, \"nameAndURL\", docName, sourceFile);\n\
\n\
		tweak(docObj, concat(\"set(\\\"name\\\", \\\"\", docName, \"\\\");\"));\n\
\n\
		system(concat(\"rm -f \", tmpFile));\n\
\n\
		return docName;\n\
	break;\n\
	case \"out\":\n\
		for (i = 1; i < arg[]; i = i + 1) {\n\
			print(\"#### \", arg[i]);\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		/* use sgmlsA2B to genereate binary format \n\
		 */\n\
		sgmlsA2BPath = \"sgmlsA2B\";\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_hmml[] = {
    {"class", _slotValue_VWHandler_hmml0},
    {"name", _slotValue_VWHandler_hmml1},
    {"script", _slotValue_VWHandler_hmml2},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_hmml_fail0[] = "txtDisp";
static char _slotValue_VWHandler_hmml_fail1[] = "VWHandler_fail";
static char _slotValue_VWHandler_hmml_fail2[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		set(\"content\", arg[1]);		\n\
		set(\"width\", arg[2]);		\n\
		set(\"height\", arg[3]);		\n\
		return self();\n\
	break;\n\
	case \"clone\":\n\
		return clone(arg[1]);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_hmml_fail3[] = "red";
static char _slotValue_VWHandler_hmml_fail4[] = "white";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_hmml_fail[] = {
    {"class", _slotValue_VWHandler_hmml_fail0},   {"name", _slotValue_VWHandler_hmml_fail1},
    {"script", _slotValue_VWHandler_hmml_fail2},  {"BGColor", _slotValue_VWHandler_hmml_fail3},
    {"FGColor", _slotValue_VWHandler_hmml_fail4}, {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_hmmlb0[] = "generic";
static char _slotValue_VWHandler_hmmlb1[] = "VWHandler_hmmlb";
static char _slotValue_VWHandler_hmmlb2[] = "";
static char _slotValue_VWHandler_hmmlb3[] = "\n\
	switch (arg[0]) {\n\
	case 'I':\n\
		/* returns ID for new HMMLB Internal Object */\n\
		objID = objID + 1;\n\
		return concat(\"IObj_hmmlb\", objID);\n\
	break;\n\
	case 'B':\n\
		/* arg[1]	URL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 * arg[5]	anchor\n\
		 * ret		documentObject or 0\n\
		 */\n\
\n\
		if (arg[] < 5) {\n\
			arg[4] = send(\"VWHandler_hmmlbb.doc.view\", \"widthP\");\n\
		}\n\
/*\n\
		print(\"################\\n\
\");\n\
		print(\"##### HMMLB ####\\n\
\");\n\
		print(\"################\\n\
\");\n\
		print(\"############ building docObj ########\\n\
\");\n\
		print(\"url='\", arg[1], \"'\\n\
\");\n\
*/\n\
		sourceFile = arg[1];\n\
		localFile = HTTPGet(sourceFile);\n\
		docName = arg[3];\n\
\n\
		if (isBlank(localFile)) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
			  concat(\"VWHandler_hmmlb:\\n\
failed to access: \", \n\
				sourceFile, \"\\n\
\"));\n\
			return 0;\n\
		}\n\
\n\
		HTTPCurrentDocAddrSet(sourceFile);\n\
\n\
		docObj = SGMLBuildDocB(UNUSED,\n\
			    localFile, arg[2], docName, arg[4], arg[5]);\n\
\n\
		send(docObj, \"nameAndURL\", docName, arg[1]);\n\
		tweak(docObj, concat(\"set(\\\"name\\\", \\\"\", docName, \"\\\");\"));\n\
\n\
		system(concat(\"rm -f \", localFile));\n\
		return docName;\n\
	break;\n\
	case \"out\":\n\
		for (i = 1; i < arg[]; i = i + 1) {\n\
			print(\"#### \", arg[i]);\n\
		}\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_hmmlb[] = {
    {"class", _slotValue_VWHandler_hmmlb0},
    {"name", _slotValue_VWHandler_hmmlb1},
    {"parent", _slotValue_VWHandler_hmmlb2},
    {"script", _slotValue_VWHandler_hmmlb3},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_html0[] = "generic";
static char _slotValue_VWHandler_html1[] = "VWHandler_html";
static char _slotValue_VWHandler_html2[] = "\n\
	switch (arg[0]) {\n\
	case 'B':\n\
		/* arg[1]	URL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 * ret		documentObject or 0\n\
		 */\n\
\n\
		docName = arg[3];\n\
		docObj = VWHandler_html.tf(\"clone\");\n\
\n\
		if (docObj == 0) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
			  concat(\"VWHandler_html:\\n\
failed to clone, for: \", \n\
				arg[1], \"\\n\
\"));\n\
			return 0;\n\
		}\n\
\n\
		HTTPCurrentDocAddrSet(arg[1]);\n\
\n\
		docObj = send(docObj,\n\
				\"build\", arg[1], arg[2], arg[3], arg[4]);\n\
\n\
		if (docObj == 0) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
			  concat(\"VWHandler_html:\\n\
failed to access: \", \n\
				arg[1], \"\\n\
\"));\n\
			return 0;\n\
		}\n\
\n\
		return docObj;\n\
\n\
		if (status == 0) {\n\
			/* better destroy the useless clone */\n\
			send(docObj, \"freeSelf\");\n\
			return 0;\n\
		} else {\n\
			return docObj;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_VWHandler_html4[] = "HTML";
static char _slotValue_VWHandler_html5[] = "VWHandler_html.tf";
static char _slotValue_VWHandler_html6[] = "\n\
	/* reminder: get rid of obsolete cases\n\
	 */\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		set(\"y\", arg[1] * heightRatio);\n\
		return;\n\
	break;\n\
	case \"resize\":\n\
		/* arg[1]	width\n\
		 * arg[2]	height\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"HTML\");\n\
		set(\"y\", style[0]);\n\
		set(\"width\", arg[1] - x() - style[3]);\n\
\n\
		parentHeight = send(get(\"parent\"), \"heightP\");\n\
		if (vspan >= parentHeight) {\n\
			set(\"height\", vspan);\n\
		} else {\n\
			set(\"height\", parentHeight);\n\
		}\n\
		return get(\"height\");\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		set(\"visible\", 1);\n\
		if (get(\"window\")) raise();\n\
		if (arg[1] != prevWidth) {\n\
			/* need to re-format */\n\
			send(self(), \"resize\", arg[1], arg[2]);\n\
		} else if (arg[2] != prevHeight) {\n\
			/* just adjust window height */\n\
			send(self(), \"resize\", arg[1], arg[2]);\n\
		}\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		vspan = building_vspan();\n\
		return;\n\
	break;\n\
	case 'T':\n\
		/* arg[1] = y\n\
		 * arg[2] = width\n\
		 */\n\
		h = get(\"height\");\n\
		parentHeight = send(parent(), \"heightP\");\n\
		heightDiff = h - parentHeight;\n\
		if (heightDiff > 0) {\n\
			heightRatio =  float(heightDiff) / -100.0;\n\
		} else {\n\
			heightRatio = 0;\n\
			h = parentHeight;\n\
			set(\"height\", h);\n\
		}\n\
		prevWidth = arg[2];\n\
		prevHeight = parentHeight;\n\
		return h;\n\
	break;\n\
	case \"buttonRelease\":\n\
		return HTML_txt(arg);\n\
	break;\n\
	case \"yP\":\n\
		return y();\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"heightP\":\n\
		return height();\n\
	break;\n\
	case \"reportTitle\":\n\
		docTitle = arg[1];\n\
		return;\n\
	break;\n\
	case \"vspan\":\n\
		return vspan;\n\
	break;\n\
	case \"y\":\n\
		return set(\"y\", arg[1]);\n\
	break;\n\
	case \"heightP\":\n\
	case \"vspan\":\n\
		return height();\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	sourcefile\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 */\n\
		docURL = arg[1];\n\
		docName = arg[3];\n\
\n\
		set(\"parent\", arg[2]);\n\
		set(\"name\", arg[3]);\n\
		set(\"width\", arg[4]);\n\
\n\
		stat = set(\"HTMLAddress\", docURL);\n\
\n\
		if (stat == 0) return 0;\n\
\n\
/*		set(\"children\", docObj);*/\n\
/*		send(docObj, \"nameAndURL\", docName, docURL);*/\n\
/*		tweak(docObj, concat(\"set(\\\"name\\\", \\\"\", docName, \"\\\");\"));*/\n\
/*		vspan = send(docObj, \"vspan\");*/\n\
\n\
		/* this is a temporary kludge, where the HTML object's window\n\
		 * is as big as the document vspan. \n\
		 */\n\
		vspan = building_vspan();\n\
		set(\"height\", vspan);\n\
\n\
		return self();\n\
	break;\n\
	case \"historyRecord\":\n\
		wwwHistory(\"add\", get(\"HTMLTitle\"), get(\"HTMLAddress\"));\n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		clearWindow();\n\
		purgeCache(self());\n\
		set(\"HTMLAddress\", get(\"HTMLAddress\"));\n\
		render();\n\
		return;\n\
	break;\n\
	case \"search\":\n\
		cursorShape(\"busy\");\n\
		search(arg[1]);\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"keyPress\":\n\
/*		www.doc.ctrl.tf(\"focus\");*/\n\
		return;\n\
	break;\n\
	case \"save\":\n\
		tmp = \"/tmp/out.html\";	/* later, use dialog box */\n\
		cmd = concat(\"www -n \", \n\
				get(\"HTMLAddress\"), \" > \", \n\
				tmp);\n\
		system(cmd);\n\
		return;\n\
	break;\n\
	case \"queryAddress\":\n\
		return get(\"HTMLAddress\");\n\
	break;\n\
	case \"queryTitle\":\n\
		return get(\"HTMLTitle\");\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return get(\"HTMLIsIndex\");\n\
	break;\n\
	case \"tree\":\n\
		/* produce a n-level anchors tree by recursively fetching\n\
		 * anchor links \n\
		 */\n\
		return;\n\
	break;\n\
	case \"showSrc\":\n\
		wwwSrc(\"showByURL\", get(\"HTMLAddress\"));\n\
/*		wwwHTMLSrc(\"show\", \n\
			get(\"name\"), get(\"HTMLAddress\"), get(\"HTMLSource\"));\n\
*/\n\
		return;\n\
	break;\n\
	case \"updateSrc\":\n\
		/* arg[1]	new HTMLSource\n\
		 */\n\
		tmp = concat(makeTempFile(), \".html\");\n\
		saveFile(tmp, arg[1]);\n\
		set(\"HTMLAddress\", tmp);\n\
		render();\n\
		return;\n\
	break;\n\
	case \"outlineSrc\":\n\
		www.mesg.tf(\"show\", \"Outliner not available for HTML.\");\n\
		return;\n\
	break;\n\
	case \"print\":\n\
		/* This facility could be much better. But for now...\n\
		 * Todo:\n\
		 *	convert to TeX\n\
		 * 	  or generate postscript (use variable width font)\n\
		 * 	use internal formatter (no need to call www)\n\
		 * 	use cached HTMLSource (no need to fetch html file)\n\
		 */\n\
		lprCmd = environVar(\"WWW_LPR\");\n\
		if (isBlank(lprCmd)) lprCmd = \"lpr \";\n\
		tmp = concat(makeTempFile(), \".html\");\n\
		www.mesg.tf(\"flash\", \n\
			concat(\"Printing command: \", lprCmd));\n\
		system(concat(\"www -n \", get(\"HTMLAddress\"), \" > \", tmp));\n\
		system(concat(lprCmd, \" \", tmp));\n\
		system(concat(\"rm -f \", tmp));\n\
		return;\n\
 	break;\n\
	case \"output2File\":\n\
		res.getLineEntry(\"show\", \n\
			\"Enter file name to save to document source to:\", \n\
				\"/tmp/out.html\",\n\
				self(), \"gotOutputFileName\");\n\
		return;\n\
 	break;\n\
	case \"gotOutputFileName\":\n\
		dumpFile = HTTPGet(docURL);\n\
		system(concat(\"mv \", dumpFile, \" \", arg[1]));\n\
		www.mesg.tf(\"show\", \n\
			concat(\"Source saved to file: \", arg[1]));\n\
		return;\n\
 	break;\n\
	case \"torn\":\n\
		vspan = building_vspan();\n\
		isTorn = 1;\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
		set(\"cursor\", 0); \n\
		return;\n\
	break;\n\
	case \"raise\":\n\
		if (get(\"window\")) raise();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		id = id + 1;\n\
		return clone(id);\n\
	break;\n\
	case \"freeSelf\":\n\
		freeSelf();\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		eventMask(\"-enterWindow -leaveWindow -keyPress -keyRelease\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_html7[] = "grey75";
static char _slotValue_VWHandler_html8[] = "LemonChiffon1";
static char _slotValue_VWHandler_html9[] = "black";
static char _slotValue_VWHandler_html10[] = "freeForm";
static char _slotValue_VWHandler_html11[] = "usual_medium";
static char _slotValue_VWHandler_html12[] = "9999";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_html[] = {
    {"class", _slotValue_VWHandler_html0},       {"name", _slotValue_VWHandler_html1},
    {"script", _slotValue_VWHandler_html2},      {(char*)0, (char*)1},
    {"class", _slotValue_VWHandler_html4},       {"name", _slotValue_VWHandler_html5},
    {"script", _slotValue_VWHandler_html6},      {"BDColor", _slotValue_VWHandler_html7},
    {"BGColor", _slotValue_VWHandler_html8},     {"FGColor", _slotValue_VWHandler_html9},
    {"paneConfig", _slotValue_VWHandler_html10}, {"font", _slotValue_VWHandler_html11},
    {"height", _slotValue_VWHandler_html12},     {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_html20[] = "generic";
static char _slotValue_VWHandler_html21[] = "VWHandler_html2";
static char _slotValue_VWHandler_html22[] = "\n\
	switch (arg[0]) {\n\
	case 'B':\n\
		/* arg[1]	URL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 * arg[5]	anchor\n\
		 * arg[6]	doPost\n\
		 * arg[7]	postData\n\
		 * ret		documentObject or 0\n\
		 */\n\
		doPost = arg[6];\n\
		sourceFile = arg[1];\n\
		docName = arg[3];\n\
\n\
		send(\"www.mesg.tf\", \"show\", \"Connecting to data provider...\");\n\
\n\
		if (doPost) {\n\
			docObj = HTTPPost(sourceFile, arg[2], arg[4], arg[7]);\n\
		} else {\n\
			docObj = HTTPGetNParse(sourceFile, arg[2], arg[4]);\n\
		}\n\
\n\
		if (exist(docObj) == 0) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
			  concat(\"VWHandler_html2:\\n\
failed to access: \", \n\
				sourceFile, \"\\n\
\"));\n\
			return 0;\n\
		}\n\
\n\
		docName = trimEdge(docName);\n\
\n\
		send(docObj, \"nameAndURL\", docName, sourceFile);\n\
\n\
		tweak(docObj, concat(\"set(\\\"name\\\", \\\"\", docName, \"\\\");\"));\n\
\n\
		return docName;\n\
	break;\n\
	case \"out\":\n\
		for (i = 1; i < arg[]; i++) print(\"#### \", arg[i]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_html2[] = {
    {"class", _slotValue_VWHandler_html20},
    {"name", _slotValue_VWHandler_html21},
    {"script", _slotValue_VWHandler_html22},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_plaintext0[] = "generic";
static char _slotValue_VWHandler_plaintext1[] = "VWHandler_plaintext";
static char _slotValue_VWHandler_plaintext2[] = "\n\
	switch (arg[0]) {\n\
	case \"build\":\n\
		/* arg[1]	docURL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 * ret		documentObject or 0\n\
		 */\n\
		docObj = VWHandler_plaintext.tf(\"clone\");\n\
		send(docObj, \"build\", arg[1], arg[2], arg[3], arg[4]);\n\
\n\
		if (isBlank(docObj)) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
			  concat(\"VWHandler_plaintext:\\n\
failed to access: \", \n\
				arg[1], \"\\n\
\"));\n\
			cursorShape(\"idle\");\n\
			return 0;\n\
		} else {\n\
			return docObj;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_VWHandler_plaintext4[] = "txtDisp";
static char _slotValue_VWHandler_plaintext5[] = "VWHandler_plaintext.tf";
static char _slotValue_VWHandler_plaintext6[] = "\n\
/*\n\
print(\"VWHandler_plaintext.tf: self=\", self(), \": \");\n\
for (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");print(\"...end\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		return set(\"shownPositionV\", arg[1]);\n\
	break;\n\
	case \"tile\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		if (width() != arg[2]) {\n\
			loadDoc = 1;\n\
		} else if (height() != arg[3]) {\n\
			loadDoc = 1;\n\
		} else {\n\
			loadDoc = 0;\n\
		}\n\
		if (loadDoc == 1) {\n\
			set(\"y\", arg[1]);\n\
\n\
			prevWidth = arg[2];\n\
			prevHeight = arg[3];\n\
			set(\"width\", arg[2]);\n\
			set(\"height\", arg[3]);\n\
			render();\n\
		}\n\
		return;\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		set(\"visible\", 1);\n\
		set(\"width\", arg[1]);\n\
		set(\"height\", arg[2]);\n\
		render();\n\
		return;\n\
	break;\n\
	case \"resize\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		set(\"width\", arg[1]);\n\
		set(\"height\", arg[2]);\n\
		return;\n\
	break;\n\
	case \"buttonRelease\":\n\
		if (charButtonMask() > 0) {\n\
			/* has pressed inside a ``button'' */\n\
			tag = nextTag();\n\
			if (tag) {\n\
				if (nthChar(tag, 1) == '*') {\n\
					interpret(tag);\n\
				} else {\n\
					www(\"raise\");\n\
					if (www(\"show\", tag))\n\
						www(\"historyRecord\");\n\
				}\n\
			} else {\n\
				bell();\n\
				www.mesg.tf(\"warn\", \n\
				    \"Try clicking the ending parts.\");\n\
			}\n\
		} else {\n\
			/* lets user complete cut/paste */\n\
		}\n\
		return;\n\
	break;\n\
	case \"yP\":\n\
		return get(\"y\");\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"vspan\":\n\
		return vspan;\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	docURL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 */\n\
		docURL = arg[1];\n\
		localFile = HTTPGet(docURL);\n\
		docName = arg[3];\n\
\n\
		set(\"parent\", arg[2]);\n\
		set(\"name\", docName);\n\
\n\
		if (localFile == 0) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
   concat(\"VWHandler_plaintext:\\n\
failed to fetch source : \", docURL));\n\
			return 0;\n\
		}\n\
		addrInfo = HTTPCurrentDocAddrParsed(docURL);\n\
\n\
		if (accessible(localFile) == 0) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
				concat(\"Unable to find (local) file: \",\n\
					localFile));\n\
			return 0;\n\
		}\n\
\n\
		if (arg[] < 5) {\n\
			arg[4] = send(\"VWHandler_hmml.doc.view\", \"widthP\");\n\
		}\n\
		set(\"width\", arg[4]);\n\
		data = loadFile(localFile);\n\
		if (isBlank(data) == 1) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
   concat(\"VWHandler_plaintext:\\n\
failed to get: \", arg[1]));\n\
			return 0;\n\
		} else {\n\
			set(\"content\", data);\n\
			render();\n\
			data = 0;/* clear variable*/\n\
			vspan = building_vspan();\n\
			return docName;\n\
		}\n\
	break;\n\
	case \"historyRecord\":\n\
		wwwHistory(\"add\", docURL, docURL); \n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		set(\"content\", loadFile(docURL));\n\
		render();\n\
		return;\n\
	break;\n\
	case \"search\":\n\
		cursorShape(\"busy\");\n\
		search(arg[1]);\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"keyPress\":\n\
		return;\n\
	break;\n\
	case \"save\":\n\
		tmp = \"/tmp/out.VWHandler_plaintext\";\n\
		saveFile(tmp, get(\"content\"));\n\
		cmd = concat(\"lpr \", tmp);\n\
		system(cmd);\n\
		return;\n\
	break;\n\
	case \"queryAddress\":\n\
		return docURL;\n\
	break;\n\
	case \"queryTitle\":\n\
		return docURL;\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return 0;\n\
	break;\n\
	case \"tree\":\n\
		/* produce a n-level anchors tree by recursively fetching\n\
		 * anchor links \n\
		 */\n\
		return;\n\
	break;\n\
	case \"showSrc\":\n\
		wwwSrc(\"showByURL\", docURL);\n\
		return;\n\
	break;\n\
	case \"output2File\":\n\
		res.getLineEntry(\"show\", \n\
			\"Enter file name to save to document source to:\", \n\
				\"/tmp/out.txt\",\n\
				self(), \"gotOutputFileName\");\n\
		return;\n\
 	break;\n\
	case \"gotOutputFileName\":\n\
		dumpFile = HTTPGet(docURL);\n\
		system(concat(\"mv \", dumpFile, \" \", arg[1]));\n\
		www.mesg.tf(\"show\", \n\
			concat(\"Source saved to file: \", arg[1], \"\\n\
\"));\n\
		return;\n\
 	break;\n\
	case \"outlineSrc\":\n\
		www.mesg.tf(\"show\",\n\
		  \"Outliner not available for VWHandler_plaintext\\n\
\");\n\
		return;\n\
	break;\n\
	case \"print\":\n\
		tmp = \"/tmp/out.txt\";\n\
		saveFile(tmp, get(\"content\"));\n\
		lprCmd = environVar(\"WWW_LPR\");\n\
		cmd = concat(lprCmd, tmp);\n\
		system(cmd);\n\
		www.mesg.tf(\"flash\", concat(\"Printing command: \", cmd));\n\
		system(concat(\"rm -f \", tmp));\n\
		return;\n\
 	break;\n\
	case \"torn\":\n\
		isTorn = 1;\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
		set(\"cursor\", 0); \n\
		return;\n\
	break;\n\
	case \"render\":\n\
		return set(\"visible\", 1);\n\
	break;\n\
	case \"VIEW_ON\":\n\
	case \"VIEW_OFF\":\n\
		return;\n\
	break;\n\
	case \"raise\":\n\
		if (get(\"window\")) raise();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola.background_doc\");\n\
		if (color) {\n\
			set(\"BDColor\", color);\n\
			set(\"BGColor\", color);\n\
		}\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"FGColor\", color);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_plaintext7[] = "grey75";
static char _slotValue_VWHandler_plaintext8[] = "LemonChiffon1";
static char _slotValue_VWHandler_plaintext9[] = "black";
static char _slotValue_VWHandler_plaintext10[] = "fixed";
static char _slotValue_VWHandler_plaintext11[] = "30";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_plaintext[] = {
    {"class", _slotValue_VWHandler_plaintext0},
    {"name", _slotValue_VWHandler_plaintext1},
    {"script", _slotValue_VWHandler_plaintext2},
    {(char*)0, (char*)1},
    {"class", _slotValue_VWHandler_plaintext4},
    {"name", _slotValue_VWHandler_plaintext5},
    {"script", _slotValue_VWHandler_plaintext6},
    {"BDColor", _slotValue_VWHandler_plaintext7},
    {"BGColor", _slotValue_VWHandler_plaintext8},
    {"FGColor", _slotValue_VWHandler_plaintext9},
    {"font", _slotValue_VWHandler_plaintext10},
    {"height", _slotValue_VWHandler_plaintext11},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_vobj0[] = "vpane";
static char _slotValue_VWHandler_vobj1[] = "VWHandler_vobj";
static char _slotValue_VWHandler_vobj2[] = "\n\
	switch (arg[0]) {\n\
	case \"build\":\n\
		/* arg[1]	doc URL		\n\
		 * arg[2]	doc name	(internal ref)\n\
		 * arg[3]	parent\n\
		 * arg[4]	width\n\
		 * arg[5]	height\n\
		 */\n\
		n = n + 1;\n\
		return send(clone(n), \"make\", \n\
				arg[1], arg[2], arg[3], arg[4], arg[5]);\n\
	break;\n\
	case \"render\":\n\
		usual();\n\
		objectListSend(\"children\", \"render\");\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		docURL = get(\"label\");\n\
		docName = arg[2];\n\
\n\
		localFile = HTTPGet(docURL);\n\
\n\
		addrInfo = HTTPCurrentDocAddrParsed(localFile);\n\
\n\
		if (nthChar(addrInfo[2], 0) == '/') {\n\
			path = addrInfo[2];\n\
		} else {\n\
			path = concat(\"/\", addrInfo[2]);\n\
		}\n\
		objFileName = addrInfo[3];\n\
\n\
		addrInfo = HTTPCurrentDocAddrParsed(docURL);\n\
		objName = nthChar(addrInfo[3], 0, strlen(addrInfo[3]) - 3);\n\
\n\
		stat = loadObjFile(path, objFileName);\n\
\n\
		system(concat(\"rm -f \", localFile));\n\
\n\
		if (stat <= 0) {\n\
			print(\"failed to load obj file {\", objFileName,\n\
				\"} in {\", path, \"}\\n\
\");\n\
			\n\
			new = send(\"HMML_fail\", \"clone\");\n\
			set(\"children\", new);\n\
			vspan = send(new, \"make\", self(), width(),\n\
				     concat(\"Insert failed here: \", docURL));\n\
			return vspan;\n\
		}\n\
		send(objName, \"init\");\n\
		set(\"children\", objName);\n\
\n\
		set(\"name\", docName);\n\
		set(\"parent\", arg[3]);\n\
		set(\"width\", arg[4]);\n\
		set(\"height\", arg[5]);\n\
\n\
		tweak(objName, concat(\"set(\\\"parent\\\",\\\"\", self(), \"\\\");\"));\n\
\n\
		return self();\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		raise();\n\
		set(\"width\", arg[1]);\n\
		set(\"height\", arg[2]);\n\
		return;\n\
	break;\n\
	case \"resize\":\n\
		/* to change window sizes */\n\
		set(\"width\", arg[1]);\n\
		set(\"height\", arg[2]);\n\
\n\
		/* to trigger geometry manager */\n\
		send(self(), \"config\", 0, 0, arg[1], arg[2]);\n\
\n\
		return;\n\
	break;\n\
	case \"vspan\":\n\
		return 0;\n\
	break;\n\
	case \"queryAddress\":\n\
		return docURL;\n\
	break;\n\
	case \"queryTitle\":\n\
		return nthChild(0);\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return 0;\n\
	break;\n\
	case \"historyRecord\":\n\
		wwwHistory(\"add\", nthChild(0), docURL);\n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		print(\"reload for *.v format not yet implemented\\n\
\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_vobj3[] = "grey45";
static char _slotValue_VWHandler_vobj4[] = "999";
static char _slotValue_VWHandler_vobj5[] = "999";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_vobj[] = {
    {"class", _slotValue_VWHandler_vobj0},
    {"name", _slotValue_VWHandler_vobj1},
    {"script", _slotValue_VWHandler_vobj2},
    {"BGColor", _slotValue_VWHandler_vobj3},
    {"width", _slotValue_VWHandler_vobj4},
    {"height", _slotValue_VWHandler_vobj5},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_vobjf0[] = "vpane";
static char _slotValue_VWHandler_vobjf1[] = "VWHandler_vobjf";
static char _slotValue_VWHandler_vobjf2[] = "\n\
	switch (arg[0]) {\n\
	case \"build\":\n\
		/* arg[1]	URL		\n\
		 * arg[2]	doc name	(internal ref)\n\
		 * arg[3]	parent\n\
		 * arg[4]	width\n\
		 * arg[5]	height\n\
		 */\n\
		n = n + 1;\n\
		return send(clone(n), \"make\", \n\
				arg[1], arg[2], arg[3], arg[4], arg[5]);\n\
	break;\n\
	case \"render\":\n\
		usual();\n\
		objectListSend(\"children\", \"render\");\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		docURL = arg[1];\n\
		docName = arg[2];\n\
\n\
		localFile = HTTPGet(docURL);\n\
\n\
		addrInfo = HTTPCurrentDocAddrParsed(localFile);\n\
\n\
		if (nthChar(addrInfo[2], 0) == '/') {\n\
			path = addrInfo[2];\n\
		} else {\n\
			path = concat(\"/\", addrInfo[2]);\n\
		}\n\
		objFileName = addrInfo[3];\n\
\n\
		addrInfo = HTTPCurrentDocAddrParsed(docURL);\n\
		objName = nthChar(addrInfo[3], 0, strlen(addrInfo[3]) - 3);\n\
\n\
		stat = loadObjFile(path, objFileName);\n\
\n\
		system(concat(\"rm -f \", localFile));\n\
\n\
		if (stat <= 0) {\n\
			print(\"failed to load obj file {\", objFileName,\n\
				\"} in {\", path, \"}\\n\
\");\n\
			\n\
			new = send(\"HMML_fail\", \"clone\");\n\
			set(\"children\", new);\n\
			vspan = send(new, \"make\", self(), width(),\n\
				     concat(\"Insert failed here: \", docURL));\n\
			return vspan;\n\
		}\n\
		send(objName, \"init\");\n\
		set(\"children\", objName);\n\
\n\
		set(\"name\", docName);\n\
		set(\"parent\", arg[3]);\n\
		set(\"width\", arg[4]);\n\
		set(\"height\", arg[5]);\n\
\n\
		tweak(objName, concat(\"set(\\\"parent\\\",\\\"\", self(), \"\\\");\"));\n\
\n\
		return self();\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		raise();\n\
		set(\"width\", arg[1]);\n\
		set(\"height\", arg[2]);\n\
		return;\n\
	break;\n\
	case \"resize\":\n\
		/* to change window sizes */\n\
		set(\"width\", arg[1]);\n\
		set(\"height\", arg[2]);\n\
\n\
		/* to trigger geometry manager */\n\
		send(self(), \"config\", 0, 0, arg[1], arg[2]);\n\
\n\
		return;\n\
	break;\n\
	case \"vspan\":\n\
		return 0;\n\
	break;\n\
	case \"queryAddress\":\n\
		return docURL;\n\
	break;\n\
	case \"queryTitle\":\n\
		return nthChild(0);\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return 0;\n\
	break;\n\
	case \"historyRecord\":\n\
		wwwHistory(\"add\", nthChild(0), docURL);\n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		print(\"reload for *.v format not yet implemented\\n\
\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_vobjf3[] = "grey45";
static char _slotValue_VWHandler_vobjf4[] = "999";
static char _slotValue_VWHandler_vobjf5[] = "999";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_vobjf[] = {
    {"class", _slotValue_VWHandler_vobjf0},
    {"name", _slotValue_VWHandler_vobjf1},
    {"script", _slotValue_VWHandler_vobjf2},
    {"BGColor", _slotValue_VWHandler_vobjf3},
    {"width", _slotValue_VWHandler_vobjf4},
    {"height", _slotValue_VWHandler_vobjf5},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_xbm0[] = "generic";
static char _slotValue_VWHandler_xbm1[] = "VWHandler_xbm";
static char _slotValue_VWHandler_xbm2[] = "\n\
	switch (arg[0]) {\n\
	case \"build\":\n\
		/* arg[1]	sourcefile\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 * ret		documentObject or 0\n\
		 */\n\
		docObj = VWHandler_xbm.xbm(\"clone\");\n\
		send(docObj, \"build\", arg[1], arg[2], arg[3], arg[4]);\n\
\n\
		if (isBlank(docObj) == 1) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
			  concat(\"VWHandler_xbm:\\n\
failed to access: \", \n\
				arg[1], \"\\n\
\"));\n\
\n\
			www.mesg.tf(\"show\", \n\
				    concatenate(\"Failed to get \", arg[1]));\n\
			cursorShape(\"idle\");\n\
			return 0;\n\
		} else {\n\
			www.mesg.tf(\"show\", \"\");\n\
			www.udi.tf(\"show\", arg[1]);\n\
\n\
			www.doc.ctrl.label(\"index\", 0);\n\
			www.doc.ctrl.tf(\"index\", 0);\n\
\n\
			cursorShape(\"idle\");\n\
			return docObj;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_VWHandler_xbm4[] = "XBM";
static char _slotValue_VWHandler_xbm5[] = "VWHandler_xbm.xbm";
static char _slotValue_VWHandler_xbm6[] = "\n\
	switch (arg[0]) {\n\
	case \"y\":\n\
		set(\"y\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		if (width() != arg[3]) {\n\
			loadDoc = 1;\n\
		} else if (height() != arg[4]) {\n\
			loadDoc = 1;\n\
		} else {\n\
			loadDoc = 0;\n\
		}\n\
		if (loadDoc == 1) {\n\
			clearWindow();\n\
			set(\"width\", arg[3]);\n\
			set(\"height\", arg[4]);\n\
/*\n\
			data = loadFile(arg[1]);\n\
			set(\"label\", data);\n\
			send(parent(), \"update\", vspan);\n\
			vspan = get(\"height\");\n\
			parentHeight = send(parent(), \"heightP\");\n\
			if (vspan >= parentHeight) {\n\
				set(\"height\", vspan);\n\
			} else {\n\
				set(\"height\", parentHeight);\n\
			}\n\
*/\n\
			render();\n\
		}\n\
		return;\n\
	break;\n\
	case \"yP\":\n\
		return y();\n\
	break;\n\
	case \"heightP\":\n\
		return height();\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	docURL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 */\n\
		docURL = arg[1];\n\
		docName = arg[3];\n\
		set(\"parent\", arg[2]);\n\
		set(\"name\", docName);\n\
\n\
		prevWidth = arg[4];\n\
		prevHeight = send(parent(), \"heightP\");\n\
\n\
		localFile = HTTPGet(docURL);\n\
		data = loadFile(localFile);\n\
		system(concat(\"rm -f \", localFile));\n\
\n\
		if (isBlank(data) == 1) {\n\
			www.mesg.tf(\"show\", \n\
				    concat(\"Failed to get \", docURL));\n\
			cursorShape(\"idle\");\n\
			return 0;\n\
		} else {\n\
			set(\"label\", data);\n\
			set(\"width\", prevWidth);\n\
			set(\"height\", prevHeight);\n\
			cursorShape(\"idle\");\n\
			return get(\"name\");\n\
		}\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		raise();\n\
		if (arg[1] != prevWidth) {\n\
			prevWidth = arg[1];\n\
			set(\"width\", prevWidth);\n\
		} else if (arg[2] != prevHeight) {\n\
			prevHeight = arg[2];\n\
			set(\"height\", prevHeight);\n\
		}\n\
		return;\n\
	break;\n\
	case \"historyRecord\":\n\
		wwwHistory(\"add\", docName, docURL);\n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		localPath = HTTPGet(docURL);\n\
		set(\"label\", loadFile(localPath));\n\
		render();\n\
		return;\n\
	break;\n\
	case \"save\":\n\
		bell(1);\n\
		return;\n\
	break;\n\
	case \"queryAddress\":\n\
		return docURL;\n\
	break;\n\
	case \"queryTitle\":\n\
		return docName;\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return 0;\n\
	break;\n\
	case \"tree\":\n\
		/* produce a n-level anchors tree by recursively fetching\n\
		 * anchor links \n\
		 */\n\
		return;\n\
	break;\n\
	case \"showSrc\":\n\
		VWHANDLER_XBM_EDITOR = \"bitmap\";\n\
		tmp = concatenate(makeTempFile(), \".xbm\");\n\
		saveFile(tmp, get(\"label\"));\n\
		system(concatenate(VWHANDLER_XBM_EDITOR, \" \", tmp));\n\
		set(\"label\", loadFile(tmp));\n\
		render();\n\
		system(concat(\"rm -f \", tmp));\n\
		return;\n\
	break;\n\
	case \"outlineSrc\":\n\
		www.mesg.tf(\"show\", \n\
			\"Outliner not available for VWHANDLER_XBM\\n\
\");\n\
		return;\n\
	break;\n\
	case \"cycleColors\":\n\
		cycleColors(1);\n\
		render();\n\
		return;\n\
 	break;\n\
	case \"reverseVideo\":\n\
		cycleColors(1);\n\
		cycleColors(1);\n\
		render();\n\
		return;\n\
	break;\n\
	case \"colorsBGFGBD\":\n\
		set(\"BGColor\", arg[1]);\n\
		set(\"FGColor\", arg[2]);\n\
		set(\"BDColor\", arg[3]);\n\
		render();\n\
		return;\n\
 	break;\n\
	case \"torn\":\n\
		isTorn = 1;\n\
		return;\n\
	break;\n\
	case \"raise\":\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(0);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola*background\");\n\
		if (color) {\n\
			set(\"BGColor\", color);\n\
		}\n\
		color = getResource(\"Viola*foreground\");\n\
		if (color) {\n\
			set(\"BDColor\", color);\n\
			set(\"FGColor\", color);\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_xbm7[] = "grey45";
static char _slotValue_VWHandler_xbm8[] = "LemonChiffon1";
static char _slotValue_VWHandler_xbm9[] = "black";
static char _slotValue_VWHandler_xbm10[] = "9999";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_xbm[] = {
    {"class", _slotValue_VWHandler_xbm0},   {"name", _slotValue_VWHandler_xbm1},
    {"script", _slotValue_VWHandler_xbm2},  {(char*)0, (char*)1},
    {"class", _slotValue_VWHandler_xbm4},   {"name", _slotValue_VWHandler_xbm5},
    {"script", _slotValue_VWHandler_xbm6},  {"BDColor", _slotValue_VWHandler_xbm7},
    {"BGColor", _slotValue_VWHandler_xbm8}, {"FGColor", _slotValue_VWHandler_xbm9},
    {"height", _slotValue_VWHandler_xbm10}, {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_xpm0[] = "generic";
static char _slotValue_VWHandler_xpm1[] = "VWHandler_xpm";
static char _slotValue_VWHandler_xpm2[] = "\n\
	switch (arg[0]) {\n\
	case \"build\":\n\
		/* arg[1]	docURL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 * ret		documentObject or 0\n\
		 */\n\
		docObj = VWHandler_xpm.xpm(\"clone\");\n\
		send(docObj, \"build\", arg[1], arg[2], arg[3], arg[4]);\n\
\n\
		if (isBlank(docObj) == 1) {\n\
			send(\"VWHandler_fail\", \"report\", \n\
			  concat(\"VWHandler_xpm:\\n\
failed to access: \", \n\
				arg[1], \"\\n\
\"));\n\
\n\
			www.mesg.tf(\"show\", \n\
				    concatenate(\"Failed to get \", arg[1]));\n\
			cursorShape(\"idle\");\n\
			return 0;\n\
		} else {\n\
			www.mesg.tf(\"show\", \"\");\n\
			www.udi.tf(\"show\", arg[1]);\n\
\n\
			www.doc.ctrl.label(\"index\", 0);\n\
			www.doc.ctrl.tf(\"index\", 0);\n\
\n\
			cursorShape(\"idle\");\n\
			return docObj;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_VWHandler_xpm4[] = "XPM";
static char _slotValue_VWHandler_xpm5[] = "VWHandler_xpm.xpm";
static char _slotValue_VWHandler_xpm6[] = "\n\
	switch (arg[0]) {\n\
	case \"y\":\n\
		set(\"y\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		if (width() != arg[3]) {\n\
			loadDoc = 1;\n\
		} else if (height() != arg[4]) {\n\
			loadDoc = 1;\n\
		} else {\n\
			loadDoc = 0;\n\
		}\n\
		if (loadDoc == 1) {\n\
			clearWindow();\n\
			set(\"width\", arg[3]);\n\
			set(\"height\", arg[4]);\n\
			render();\n\
		}\n\
		return;\n\
	break;\n\
	case \"yP\":\n\
		return y();\n\
	break;\n\
	case \"heightP\":\n\
		return height();\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	docURL\n\
		 * arg[2]	parent\n\
		 * arg[3]	name\n\
		 * arg[4]	width\n\
		 */\n\
		docURL = arg[1];\n\
		docName = arg[3];\n\
		set(\"parent\", arg[2]);\n\
		set(\"name\", docName);\n\
\n\
		prevWidth = arg[4];\n\
		prevHeight = send(parent(), \"heightP\");\n\
\n\
		localFile = HTTPGet(docURL);\n\
		data = loadFile(localFile);\n\
		system(concat(\"rm -f \", localFile));\n\
\n\
		if (isBlank(data) == 1) {\n\
			www.mesg.tf(\"show\", \n\
				    concatenate(\"Failed to get \", arg[1]));\n\
			cursorShape(\"idle\");\n\
			return 0;\n\
		} else {\n\
			set(\"label\", data);\n\
			set(\"width\", prevWidth);\n\
			set(\"height\", prevHeight);\n\
			cursorShape(\"idle\");\n\
			return get(\"name\");\n\
		}\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		raise();\n\
		if (arg[1] != prevWidth) {\n\
			prevWidth = arg[1];\n\
			set(\"width\", prevWidth);\n\
		} else if (arg[2] != prevHeight) {\n\
			prevHeight = arg[2];\n\
			set(\"height\", prevHeight);\n\
		}\n\
		return;\n\
	break;\n\
	case \"historyRecord\":\n\
		wwwHistory(\"add\", docName, docURL);\n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		localPath = HTTPGet(docURL);\n\
		data = loadFile(localPath);\n\
		set(\"label\", data);\n\
		render();\n\
		system(concat(\"rm \", tmp));\n\
		return;\n\
	break;\n\
	case \"search\":\n\
		cursorShape(\"busy\");\n\
		search(arg[1]);\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"save\":\n\
		bell(1);\n\
		return;\n\
	break;\n\
	case \"queryAddress\":\n\
		return docURL;\n\
	break;\n\
	case \"queryTitle\":\n\
		return docName;\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return 0;\n\
	break;\n\
	case \"tree\":\n\
		/* produce a n-level anchors tree by recursively fetching\n\
		 * anchor links \n\
		 */\n\
		return;\n\
	break;\n\
	case \"showSrc\":\n\
		VWHANDLER_XPM_EDITOR = \"pixmap\";\n\
		tmp = concatenate(makeTempFile(), \".xpm\");\n\
		saveFile(tmp, get(\"label\"));\n\
		system(concat(VWHANDLER_XPM_EDITOR, \" -filename \", tmp, \n\
						\" >& /dev/null\"));\n\
		set(\"label\", loadFile(tmp));\n\
		system(concat(\"rm -f \", tmp));\n\
		render();\n\
		clearWindow();\n\
		return;\n\
	break;\n\
	case \"outlineSrc\":\n\
		www.mesg.tf(\"show\", \n\
			    concatenate(\"Outliner not available for XPM\\n\
\"));\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		isTorn = 1;\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
		set(\"cursor\", 0); \n\
		return;\n\
	break;\n\
	case \"raise\":\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(0);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_VWHandler_xpm7[] = "grey45";
static char _slotValue_VWHandler_xpm8[] = "LemonChiffon1";
static char _slotValue_VWHandler_xpm9[] = "black";
static char _slotValue_VWHandler_xpm10[] = "9999";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_xpm[] = {
    {"class", _slotValue_VWHandler_xpm0},   {"name", _slotValue_VWHandler_xpm1},
    {"script", _slotValue_VWHandler_xpm2},  {(char*)0, (char*)1},
    {"class", _slotValue_VWHandler_xpm4},   {"name", _slotValue_VWHandler_xpm5},
    {"script", _slotValue_VWHandler_xpm6},  {"BDColor", _slotValue_VWHandler_xpm7},
    {"BGColor", _slotValue_VWHandler_xpm8}, {"FGColor", _slotValue_VWHandler_xpm9},
    {"height", _slotValue_VWHandler_xpm10}, {(char*)0, (char*)0},
};

static char _slotValue_WWWEMailHandler0[] = "generic";
static char _slotValue_WWWEMailHandler1[] = "WWWTelnetHandler";
static char _slotValue_WWWEMailHandler2[] = "\n\
	switch (arg[0]) {\n\
	case \"connect\":\n\
		/* forms:\n\
		 *	telnetaddress=	telnet://[user@]hostport\n\
		 *	hostport=	host[:port]\n\
		 *\n\
		 * returns a shell command\n\
		 */\n\
		tt = nthChar(arg[1], 9, 999);\n\
\n\
		/* to get rid of the mysterious '/' at end of string??? */\n\
		if (nthChar(tt, strlen(tt) - 1) == '/') {\n\
			tt = nthChar(tt, 0, strlen(tt) - 2);\n\
		}\n\
\n\
		ati = findPattern(tt, \"@\");\n\
		if (ati != -1) {\n\
			/* form:	telnet://user@host\n\
			 */\n\
			user = nthChar(tt, 0, ati - 1);\n\
			host = nthChar(tt, ati + 1, 999);\n\
\n\
			cmd = concat(\"xterm -e 'rlogin \", \n\
					host, \" -l \", user, \"' &\");\n\
			return cmd;\n\
		}\n\
\n\
		ati = findPattern(tt, \":\");\n\
		if (ati != -1) {\n\
			/* form:	telnet://host:port\n\
			 */\n\
			host = nthChar(tt, 0, ati - 1);\n\
			port = nthChar(tt, ati + 1, 999);\n\
			cmd = concat(\"xterm -e 'telnet \", \n\
					host, \" \", port, \"' &\");\n\
			return cmd;\n\
\n\
		} else {\n\
			/* form:	telnet://host\n\
			 */\n\
			cmd = concat(\"xterm -e 'telnet \", tt, \"' &\");\n\
			return cmd;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_WWWEMailHandler[] = {
    {"class", _slotValue_WWWEMailHandler0},
    {"name", _slotValue_WWWEMailHandler1},
    {"script", _slotValue_WWWEMailHandler2},
    {(char*)0, (char*)0},
};

static char _slotValue_WWWTelnetHandler0[] = "generic";
static char _slotValue_WWWTelnetHandler1[] = "WWWTelnetHandler";
static char _slotValue_WWWTelnetHandler2[] = "\n\
	switch (arg[0]) {\n\
	case \"connect\":\n\
		/* forms:\n\
		 *	telnetaddress=	telnet://[user@]hostport\n\
		 *	hostport=	host[:port]\n\
		 *\n\
		 * returns a shell command\n\
		 */\n\
		tt = nthChar(arg[1], 9, 999);\n\
\n\
		/* to get rid of the mysterious '/' at end of string??? */\n\
		if (nthChar(tt, strlen(tt) - 1) == '/') {\n\
			tt = nthChar(tt, 0, strlen(tt) - 2);\n\
		}\n\
\n\
		ati = findPattern(tt, \"@\");\n\
		if (ati != -1) {\n\
			/* form:	telnet://user@host\n\
			 */\n\
			user = nthChar(tt, 0, ati - 1);\n\
			host = nthChar(tt, ati + 1, 999);\n\
\n\
			cmd = concat(\"xterm -e 'rlogin \", \n\
						host, \" -l \", user, \"' &\");\n\
			return cmd;\n\
		}\n\
\n\
		ati = findPattern(tt, \":\");\n\
		if (ati != -1) {\n\
			/* form:	telnet://host:port\n\
			 */\n\
			host = nthChar(tt, 0, ati - 1);\n\
			port = nthChar(tt, ati + 1, 999);\n\
			cmd = concat(\"xterm -e 'telnet \", \n\
					host, \" \", port, \"' &\");\n\
			return cmd;\n\
\n\
		} else {\n\
			/* form:	telnet://host\n\
			 */\n\
			cmd = concat(\"xterm -e 'telnet \", tt, \"' &\");\n\
			return cmd;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_WWWTelnetHandler[] = {
    {"class", _slotValue_WWWTelnetHandler0},
    {"name", _slotValue_WWWTelnetHandler1},
    {"script", _slotValue_WWWTelnetHandler2},
    {(char*)0, (char*)0},
};

static char _slotValue_normalizeURL0[] = "normalizeURL";
static char _slotValue_normalizeURL1[] = "generic";
static char _slotValue_normalizeURL2[] = "\n\
/*\n\
print(\"normalizeURL: \");\n\
for (i=0; i < arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");\n\
print(\"\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"normalizeURL\":\n\
		/* arg[1]	url\n\
		 * arg[2]	context\n\
		 */\n\
		/* URL of this form \"foo/bar/\" ending with '/' \n\
		 * can lead to badness like \"//muu\" \n\
		 * What was this about??? sheesh.\n\
		 */\n\
/*		if (nthChar(arg[1], strlen(arg[1])-1) == '/')\n\
			arg[1] = nthChar(arg[1], 0, strlen(arg[1])-2);\n\
*/\n\
		if (arg[] == 3) {\n\
			/* set current document directory context.*/\n\
			HTTPCurrentDocAddrSet(arg[2]);\n\
			addrInfo = HTTPCurrentDocAddrParsed(arg[1], arg[2]);\n\
		} else {\n\
			addrInfo = HTTPCurrentDocAddrParsed(arg[1]);\n\
		}\n\
\n\
		if (nthChar(addrInfo[2], 0) == '/') {\n\
			if (isBlank(addrInfo[1])) hostComponent = \"\";\n\
			else hostComponent = concat(\"//\", addrInfo[1]);\n\
		} else {\n\
			if (addrInfo[0] == \"news\") {\n\
			   hostComponent = \"\";\n\
			} else {\n\
			  if (isBlank(addrInfo[1])) hostComponent = '/';\n\
			  else hostComponent = concat(\"//\", addrInfo[1], '/');\n\
			}\n\
		}\n\
		normURL = concat(addrInfo[0], \":\", hostComponent,\n\
					addrInfo[2], addrInfo[3]);\n\
\n\
		if (addrInfo[4] != \"\")\n\
			normURL = concat(normURL, '#', addrInfo[4]);\n\
\n\
		return normURL;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_normalizeURL[] = {
    {"name", _slotValue_normalizeURL0},
    {"class", _slotValue_normalizeURL1},
    {"script", _slotValue_normalizeURL2},
    {(char*)0, (char*)0},
};

static char _slotValue_parseHTTPAddress0[] = "generic";
static char _slotValue_parseHTTPAddress1[] = "parseHTTPAddress";
static char _slotValue_parseHTTPAddress2[] = "\n\
	switch (arg[0]) {\n\
	case \"name\":\n\
		dd = arg[1];\n\
		doP = 1;\n\
		nameEnd = findPattern(dd, \".html\");/*XXX*/\n\
		if (nameEnd == -1) nameEnd = strlen(dd);\n\
\n\
		nameBegin = 0;\n\
		for (i = 0; doP ; i++) {\n\
			c = nthChar(dd, i);\n\
			switch (c) {\n\
			case '\\0':\n\
				doP = 0;\n\
			break;\n\
			case '.':\n\
				if (findPattern(nthChar(dd, i + 1, 999),\n\
						\".\") == -1) {\n\
					suffixi = i - 1;\n\
					doP = 0;\n\
				}\n\
			break;\n\
			case '/':\n\
				lastSlash = i;\n\
				nameBegin = i + 1;\n\
			break;\n\
			case '#':\n\
				lastHash = i;\n\
				suffixi = i - 1;\n\
				doP = 0;\n\
			break;\n\
			}\n\
		}\n\
		name = nthChar(dd, nameBegin, suffixi);\n\
		return name;\n\
	break;\n\
	case \"anchor\":\n\
		dd = arg[1];\n\
		doP = 1;\n\
		anchorBegin = findPattern(dd, \"#\");\n\
		if (anchorBegin == -1) return \"\";\n\
\n\
		anchorBegin = anchorBegin + 1;\n\
		for (i = anchorBegin; doP ; i++) {\n\
			c = nthChar(dd, i);\n\
			switch (c) {\n\
			case '\\0':\n\
				doP = 0;\n\
				suffixi = i - 1;\n\
			break;\n\
			case '.':\n\
				suffixi = i - 1;\n\
				doP = 0;\n\
			break;\n\
			}\n\
		}\n\
		anchor = nthChar(dd, anchorBegin, suffixi);\n\
		return anchor;\n\
	break;\n\
	case \"stripIndex\":\n\
		anchorBegin = findPattern(arg[1], \"?\");\n\
		if (anchorBegin == -1) return arg[1];\n\
		return nthChar(arg[1], 1, idx);\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_parseHTTPAddress[] = {
    {"class", _slotValue_parseHTTPAddress0},
    {"name", _slotValue_parseHTTPAddress1},
    {"script", _slotValue_parseHTTPAddress2},
    {(char*)0, (char*)0},
};

static char _slotValue_www0[] = "3";
static char _slotValue_www1[] = "vpane";
static char _slotValue_www2[] = "www";
static char _slotValue_www3[] = "";
static char _slotValue_www4[] = "www.top www.doc www.url www.mesg";
static char _slotValue_www5[] = "0";
static char _slotValue_www6[] = "0";
static char _slotValue_www7[] = "625";
static char _slotValue_www8[] = "750";
static char _slotValue_www9[] = "\n\
/*\n\
print(\"www: \");\n\
for (i=0; i < arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");\n\
print(\"\\n\
\");\n\
*/\n\
	/* Application: ViolaWWW\n\
	 * Author: 	Pei Y. Wei\n\
	 *\n\
	 */\n\
	/* URL port configurtion.\n\
	 * \n\
	URLPort = 8081;\n\
	URLListen = \"/usr/work/viola/src/viola/listen\";\n\
	 */\n\
\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
	case \"post\":\n\
		cursorShape(\"busy\");\n\
		if (arg[] == 2)\n\
			stat = send(\"www.doc.view.pane\", arg[0], arg[1]);\n\
		else if (arg[] == 3)\n\
			stat = send(\"www.doc.view.pane\", arg[0], arg[1], \n\
							 arg[2]);\n\
		else\n\
			stat = send(\"www.doc.view.pane\", arg[0], arg[1], \n\
							 arg[2], arg[3]);\n\
		cursorShape(\"idle\");\n\
		return stat;\n\
	break;\n\
	case \"showDoc\":\n\
	case \"showHistoryDoc\":\n\
		cursorShape(\"busy\");\n\
		if (arg[] == 2)\n\
			stat = send(\"www.doc.view.pane\", \"show\", arg[1]);\n\
		else if (arg[] == 3)\n\
			stat = send(\"www.doc.view.pane\", \"show\", arg[1], \n\
							 arg[2]);\n\
		else\n\
			stat = send(\"www.doc.view.pane\", \"show\", arg[1], \n\
							 arg[2], arg[3]);\n\
		send(\"www.doc.view.pane\", \"historyRecord\");\n\
		cursorShape(\"idle\");\n\
		return stat;\n\
	break;\n\
	case \"addToHistory\":\n\
		send(\"wwwHistory\", \"add\", arg[1], arg[2]);\n\
		return;\n\
	break;\n\
	case \"group\":\n\
/*		send(\"www.doc.title.icon\", \"group\", arg[1]);*/\n\
		return;\n\
	break;\n\
	case \"showSrc\":\n\
	case \"clonePage\":\n\
	case \"destroyDoc\":\n\
		return send(\"www.doc.view.pane\", arg[0]);\n\
	break;\n\
	case \"search\":\n\
		return send(\"www.doc.view.pane\", \"search\", arg[1]);\n\
	break;\n\
	case \"olAdd\":\n\
/*		olObj[olIdx] = arg[1];*/\n\
		olData[olIdx] = arg[2];\n\
		olIdx++;\n\
		return;\n\
	break;\n\
	case \"olReset\":\n\
		olIdx = 0;\n\
		return;\n\
	break;\n\
	case \"olData\":\n\
		tt = \"\";\n\
		for (i = 0; i < olIdx; i++) tt = concat(tt, olData[i], \"\\n\
\");\n\
		return tt;\n\
	break;\n\
	case \"showButNoRecord\":\n\
		send(\"www.doc.view.pane\", \"show\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"CE_change\":\n\
		/* arg[1] 	CE objPath\n\
		 * arg[2]	CE newData\n\
		 */\n\
		return send(\"www.doc.view.pane\", arg[0], arg[1], arg[2]);\n\
	break;\n\
	case \"CE_lock\":\n\
	case \"CE_unlock\":\n\
		/* arg[1] 	CE objPath\n\
		 */\n\
		return send(\"www.doc.view.pane\", arg[0], arg[1]);\n\
	break;\n\
	case \"about\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://berkeley.ora.com/proj/viola/vw/about_3.3.html\");\n\
		return;\n\
	break;\n\
	case \"help\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://berkeley.ora.com/proj/viola/vw/help_xvw_3.3.html\");\n\
		return;\n\
	break;\n\
	case \"demos\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://berkeley.ora.com/proj/viola/violaCentral.html\");\n\
		return;\n\
	break;\n\
	case \"metaCenters\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://berkeley.ora.com/proj/viola/metaCenters.html\");\n\
		return;\n\
	break;\n\
	case \"home\":\n\
		send(\"www\", \"showHistoryDoc\", homeDoc);\n\
		return;\n\
	break;\n\
	case \"prev\":\n\
		cursorShape(\"busy\");\n\
		wantIt = wwwHistory(\"prev\");\n\
		if (isBlank(wantIt))\n\
			send(\"www.mesg.tf\", \"alert\", \n\
				\"No ``previous'' document to go to.\");\n\
		else send(\"www.doc.view.pane\", \"show\", wantIt);\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"next\":\n\
		cursorShape(\"busy\");\n\
		wantIt = send(\"wwwHistory\", \"next\");\n\
		if (isBlank(wantIt))\n\
			send(\"www.mesg.tf\", \"alert\", \n\
				\"No ``next'' document to go to.\");\n\
		else send(\"www.doc.view.pane\", \"show\", wantIt);\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"back\":\n\
		cursorShape(\"busy\");\n\
		wantIt = send(\"wwwHistory\", \"back\");\n\
		if (isBlank(wantIt))\n\
			send(\"www.mesg.tf\", \"alert\", \n\
				    \"No Previous document to go back to.\");\n\
		else send(\"www.doc.view.pane\", \"show\", wantIt);\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		cursorShape(\"busy\");\n\
		send(\"www.doc.view.pane\", arg[0]);\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"tear\":\n\
		cursorShape(\"busy\");\n\
		send(nthChild(1), \"tear\");\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"authorContact\":\n\
		send(\"www.doc.view.pane\", \"mailToAuthor\");\n\
		return;\n\
	break;\n\
	case \"raise\":\n\
		raise();\n\
		if (get(\"window\")) windowName(\"violaWWW\");\n\
		return;\n\
	break;\n\
	case \"busy\":\n\
	case \"idle\":\n\
		cursorShape(arg[0]);\n\
		return;\n\
	break;\n\
	case \"quit\":\n\
		quit();\n\
/*\n\
		res(\"decAppCount\");\n\
		demo(\"visible\", 0);\n\
*/\n\
		return;\n\
	break;\n\
	case \"openURL\":\n\
		winPos = windowPosition();\n\
		x = winPos[0] + 20;\n\
		y = winPos[1] + 170;\n\
		w = width() - 40;\n\
		h = 80;\n\
		send(\"wwwURL\", \"open\", lastURLOpened, self(), x, y, w, h);\n\
		return;\n\
	break;\n\
	case \"gotURLToOpen\":\n\
		cursorShape(\"busy\");\n\
		lastURLOpened = arg[1];\n\
		send(\"www\", \"show\", lastURLOpened);\n\
		send(\"www.doc.view.pane\", \"historyRecord\");\n\
		cursorShape(\"idle\");\n\
		return;\n\
 	break;\n\
	case \"searchByTag\":\n\
		send(\"www.doc.view.pane\", \"searchByTag\", arg[1], arg[2]);\n\
		return;\n\
	break;\n\
	case \"homeDocP\":\n\
		return homeDoc;\n\
	break;\n\
	case \"changeFonts\":\n\
		send(\"res.font\", arg[1]);\n\
		/* bug: only main viewer is told of the font change */\n\
		send(\"www.doc.view.pane\", \"configSelf\");\n\
		return;\n\
	break;\n\
	case \"visible\":\n\
		if (arg[1] == 1) res(\"incAppCount\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		t = getResource(\"Viola.x\");\n\
		if (isBlank(t) == 0) set(\"x\", t);\n\
		t = getResource(\"Viola.y\");\n\
		if (isBlank(t) == 0) set(\"y\", t);\n\
		t = getResource(\"Viola.width\");\n\
		if (isBlank(t) == 0) set(\"width\", t);\n\
		t = getResource(\"Viola.height\");\n\
		if (isBlank(t) == 0) set(\"height\", t);\n\
		\n\
		res(\"incAppCount\");\n\
\n\
		homeDoc = argument();\n\
		if (isBlank(homeDoc) == 1)\n\
			homeDoc = environVar(\"WWW_HOME\");\n\
		if (isBlank(homeDoc) == 1) \n\
			homeDoc = \"http://info.cern.ch/hypertext/WWW/TheProject.html\";\n\
		if (nthChar(homeDoc, 0) == '/')\n\
			homeDoc = concat(\"file:\", homeDoc);\n\
\n\
		after(10, \"www\", \"show\", homeDoc);\n\
\n\
		if (URLPort > 0) {\n\
			print(\"WARNING: port number \", URLPort,\n\
			\" is now being used to accept URL fetch directives.\");\n\
			if (send(\"wwwDocuPort\", \"listen\", URLPort, URLListen)){\n\
				print(\"ERROR: Sorry, failed to open port \",\n\
				URLPort, \" for listening to URL fetches\\n\
\");\n\
			}\n\
		}\n\
		HTTPHotListLoad();\n\
		lastURLOpened = \"\";\n\
\n\
		/* start up in edit mode */\n\
/*		after(1000, \"www\", \"editMode\", 1); */\n\
\n\
		return;\n\
	break;\n\
	case \"showHotFolder\":\n\
		send(\"wwwHotFolder\", \"render\");\n\
		return;\n\
	break;\n\
	case \"addCurrentToHotFolder\":\n\
		send(\"wwwHotFolder\", \"addCurrent\");\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		send(\"www.doc.view.pane\", \"outputSGML\");\n\
		return;\n\
	break;\n\
	case \"getCurrentDocURL\":\n\
	case \"getCurrentDocTitle\":\n\
		send(\"www.doc.view.pane\", arg[0]);\n\
		return;\n\
	break;\n\
	case \"editMode\":\n\
		send(\"www.doc.view.pane\", arg[0], arg[1]);\n\
		return;\n\
	break;\n\
	case \"version\":\n\
		return \"Version 3.3 (95/01/01)\";\n\
	break;\n\
	case \"winPosition\":\n\
		return windowPosition();\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_www11[] = "hpane";
static char _slotValue_www12[] = "www.top";
static char _slotValue_www13[] = "www";
static char _slotValue_www14[] = "www.top.ops www.top.navigate www.top.guide www.top.gap www.top.help";
static char _slotValue_www15[] = "3";
static char _slotValue_www16[] = "27";
static char _slotValue_www17[] = "1";
static char _slotValue_www18[] = "1";
/* END OF OBJ */

static char _slotValue_www20[] = "menu";
static char _slotValue_www21[] = "4";
static char _slotValue_www22[] = "3";
static char _slotValue_www23[] = "www.top.ops";
static char _slotValue_www24[] = "www.top";
static char _slotValue_www25[] = "Operations";
static char _slotValue_www26[] = "\n\
	switch (arg[0]) {\n\
	case \"quit\":\n\
		send(\"www\", \"quit\");\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Click to see some general project information.\";\n\
	break;\n\
	}\n\
	usual();\n\
/*\n\
Unreliable feature\n\
.{\\\\}\n\
.{Fonts}\n\
..{Helvetica Small} {www(\"changeFonts\", \"useHelveticaSmallFonts\");}\n\
..{Helvetica Medium} {www(\"changeFonts\", \"useHelveticaMediumFonts\");}\n\
..{Helvetica Large} {www(\"changeFonts\", \"useHelveticaLargeFonts\");}\n\
..{\\\\}\n\
..{Times Small} {www(\"changeFonts\", \"useTimesSmallFonts\");}\n\
..{Times Medium} {www(\"changeFonts\", \"useTimesMediumFonts\");}\n\
..{Times Large} {www(\"changeFonts\", \"useTimesLargeFonts\");}\n\
.{\\\\}\n\
.{Expermental}\n\
..{OUTPUT SGML} {send(\"www\", \"outputSGML\");}\n\
..{Edit On} {send(\"www\", \"editMode\", 1);}\n\
..{Edit Off} {send(\"www\", \"editMode\", 0);}\n\
..{LBar On 10} {send(\"www.doc.view\", \"lbarConfig\", \"on\", 10);}\n\
..{LBar On 20} {send(\"www.doc.view\", \"lbarConfig\", \"on\", 20);}\n\
..{LBar On 50} {send(\"www.doc.view\", \"lbarConfig\", \"on\", 50);}\n\
..{LBar Off} {send(\"www.doc.view\", \"lbarConfig\", \"off\");}\n\
.{Clone Page} {send(\"www\", \"tear\");}\n\
*/\n\
";
static char _slotValue_www27[] = "\n\
.{Open URL (Uniform Resource Location)} {send(\"www\", \"openURL\");}\n\
.{Follow URL in Selection Buffer} {www(\"showHistoryDoc\", trimEdge(getSelection()));}\n\
.{\\\\}\n\
.{Show Document Source} {send(\"www\", \"showSrc\");}\n\
.{Show Document Author Info} {www(\"authorContact\");}\n\
.{\\\\}\n\
.{Software Version Info} {wwwAbout(\"visible\", 1);}\n\
.{\\\\}\n\
.{Quit} {send(self(), \"quit\");}\n\
";
static char _slotValue_www28[] = "90";
static char _slotValue_www29[] = "normal";
static char _slotValue_www30[] = "4";
/* END OF OBJ */

static char _slotValue_www32[] = "menu";
static char _slotValue_www33[] = "4";
static char _slotValue_www34[] = "3";
static char _slotValue_www35[] = "www.top.navigate";
static char _slotValue_www36[] = "www.top";
static char _slotValue_www37[] = "Navigation";
static char _slotValue_www38[] = "\n\
.{Back} {send(\"www\", \"back\");}\n\
.{\\\\}\n\
.{Home} {send(\"www\", \"home\")};\n\
.{Prev} {send(\"www\", \"prev\");}\n\
.{Next} {send(\"www\", \"next\");}\n\
.{\\\\}\n\
.{History List} {wwwHistory(\"render\");}\n\
.{\\\\}\n\
.{Hot List} {send(\"www\", \"showHotFolder\");}\n\
.{Add To Hot List} {send(\"www\", \"addCurrentToHotFolder\");}\n\
";
static char _slotValue_www39[] = "80";
static char _slotValue_www40[] = "90";
static char _slotValue_www41[] = "normal";
static char _slotValue_www42[] = "1";
/* END OF OBJ */

static char _slotValue_www44[] = "field";
static char _slotValue_www45[] = "www.top.gap";
static char _slotValue_www46[] = "www.top";
static char _slotValue_www47[] = "4";
/* END OF OBJ */

static char _slotValue_www49[] = "menu";
static char _slotValue_www50[] = "www.top.help";
static char _slotValue_www51[] = "www.top";
static char _slotValue_www52[] = "Help";
static char _slotValue_www53[] = "\n.{About ViolaWWW} {www(\"about\");}\n.{Help...} {www(\"help\");}\n.{Demo...} {www(\"demos\");}\n";
static char _slotValue_www54[] = "50";
static char _slotValue_www55[] = "4";
static char _slotValue_www56[] = "10";
static char _slotValue_www57[] = "normal";
/* END OF OBJ */

static char _slotValue_www59[] = "menu";
static char _slotValue_www60[] = "www.top.guide";
static char _slotValue_www61[] = "www.top";
static char _slotValue_www62[] = "Guides";
static char _slotValue_www63[] = "\n\
.{GNN's Whole Internet Catalog} {www(\"showHistoryDoc\", \"http://nearnet.gnn.com/wic/newrescat.toc.html\");}\n\
.{CERN's Web Servers Catalog} {www(\"showHistoryDoc\", \"http://info.cern.ch/hypertext/DataSources/WWW/Servers.html\");}\n\
.{More Meta Centers...} {www(\"metaCenters\");}\n\
";
static char _slotValue_www64[] = "90";
static char _slotValue_www65[] = "4";
static char _slotValue_www66[] = "10";
static char _slotValue_www67[] = "normal";
/* END OF OBJ */

static char _slotValue_www69[] = "vpane";
static char _slotValue_www70[] = "www.doc";
static char _slotValue_www71[] = "www";
static char _slotValue_www72[] = "www.doc.tools www.doc.title www.doc.view";
static char _slotValue_www73[] = "\n\
	switch (arg[0]) {\n\
	case \"tear\":\n\
		tearPageID = tearPageID + 1;\n\
		new = clone(tearPageID);\n\
		tweak(new, \"set(\\\"parent\\\", \\\"\\\");\");\n\
		send(new, \"torn\", send(nthChild(2), \"whichPageP\"));\n\
		send(new, \"render\");\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		set(\"label\", \n\
			send(send(nthChild(2), \"whichPageP\"), \"queryAddress\"));\n\
		objectListSend_children(\"torn\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		tearPageID = 0;\n\
	break;\n\
	case \"addTool\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(nthChild(0), arg[0], arg[1]);\n\
	break;\n\
	case \"whichPageP\":\n\
		return send(nthChild(2), \"whichPageP\");\n\
	break;\n\
	case \"outliner\":\n\
		if (arg[1]) {\n\
			set(\"children\", \n\
				\"www.doc.title www.doc.view www.doc.ol\");\n\
			send(self(), \"configSelf\");\n\
			olP = 1;\n\
		} else {\n\
			set(\"children\", \n\
				\"www.doc.title www.doc.view\");\n\
			send(self(), \"configSelf\");\n\
			olP = 0;\n\
		}\n\
		return;\n\
	break;\n\
	case \"quit\":\n\
		set(\"visible\", 0);\n\
		freeSelf();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www74[] = "2";
/* END OF OBJ */

static char _slotValue_www76[] = "hpane";
static char _slotValue_www77[] = "www.doc.title";
static char _slotValue_www78[] = "www.doc";
static char _slotValue_www79[] = "www.doc.title.tf";
static char _slotValue_www80[] = "\n\
	switch (arg[0]) {\n\
	case \"whichPageP\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"torn\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www81[] = "38";
static char _slotValue_www82[] = "2";
/* END OF OBJ */

static char _slotValue_www84[] = "txtDisp";
static char _slotValue_www85[] = "www.doc.title.tf";
static char _slotValue_www86[] = "www.doc.title";
static char _slotValue_www87[] = "\n\
	switch (arg[0]) {\n\
	case \"enter\":\n\
	case \"leave\":\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Document title. Click to reload document.\";\n\
	break;\n\
	case \"show\":\n\
		if (isBlank(arg[1])) {\n\
			set(\"content\", \"\");\n\
		} else {\n\
			if (textWidth(6/*bold_largest*/, arg[1])+10 \n\
			    < width()) {\n\
				/*set(\"font\", \"bold_largest\");*/\n\
				set(\"content\", concat(\"\\\\f(6)\", arg[1]));\n\
			} else {\n\
				/*set(\"font\", \"bold\");*/\n\
				set(\"content\", concat(\"\\\\f(5)\", arg[1]));\n\
			}\n\
		}\n\
		render();\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www88[] = "Welcome to Viola WorldWideWeb";
static char _slotValue_www89[] = "6";
static char _slotValue_www90[] = "black";
static char _slotValue_www91[] = "2";
static char _slotValue_www92[] = "3";
static char _slotValue_www93[] = "bold_largest";
static char _slotValue_www94[] = "1";
/* END OF OBJ */

static char _slotValue_www96[] = "hpane";
static char _slotValue_www97[] = "www.doc";
static char _slotValue_www98[] = "www.doc.tools";
static char _slotValue_www99[] = "www.doc.tools.httpStat www.doc.tools.sys www.doc.tools.dyna";
static char _slotValue_www100[] = "\n\
	switch (arg[0]) {\n\
	case \"addTool\":\n\
	case \"addTool_sticky\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(nthChild(2), arg[0], arg[1]);\n\
	break;\n\
	case \"clear\":\n\
		return send(nthChild(2), arg[0]);\n\
	break;\n\
	case \"torn\":\n\
		set(\"border\", 6);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www101[] = "2";
static char _slotValue_www102[] = "39";
/* END OF OBJ */

static char _slotValue_www104[] = "hpane";
static char _slotValue_www105[] = "www.doc.tools.dyna";
static char _slotValue_www106[] = "www.doc.tools";
static char _slotValue_www107[] = "\n\
	switch (arg[0]) {\n\
	case \"addTool\":\n\
	case \"addTool_sticky\":\n\
		new = object(arg[1]);\n\
		for (i = objectListCount_children(); i >= 0; i--)\n\
			if (nthChild(i) == new) return 1;\n\
		objectListAppend(\"children\", new);\n\
		tweak(new, concat(\"set(\\\"parent\\\", \\\"\", self(), \"\\\");\"));\n\
		send(new, \"visible\", 1);\n\
		config();\n\
		return 1;\n\
	break;\n\
	case \"removeTool\":\n\
		new = object(arg[1]);\n\
		objectListDelete(\"children\", new);\n\
		send(new, \"visible\", 0);\n\
		config();\n\
		return 1;\n\
	break;\n\
	case \"destroyTool\":\n\
		new = object(arg[1]);\n\
		objectListDelete(\"children\", new);\n\
		send(new, \"visible\", 0);\n\
		send(new, \"freeSelf\");\n\
		config();\n\
		return 1;\n\
	break;\n\
	case \"clear\":\n\
		set(\"children\", \"\");\n\
		return;\n\
	break;\n\
	case \"go_url\":\n\
		return send(\"www\", \"show\", arg[1]);\n\
	break;\n\
	case \"go_home\":\n\
		return send(\"www\", \"home\");\n\
	break;\n\
	case \"go_prev\":\n\
		return send(\"www\", \"prev\");\n\
	break;\n\
	case \"go_next\":\n\
		return send(\"www\", \"next\");\n\
	break;\n\
	case \"go_back\":\n\
		return send(\"www\", \"back\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www108[] = "2";
static char _slotValue_www109[] = "2";
/* END OF OBJ */

static char _slotValue_www111[] = "hpane";
static char _slotValue_www112[] = "www.doc.tools.sys";
static char _slotValue_www113[] = "www.doc.tools";
static char _slotValue_www114[] = "www.doc.tools.sys.home www.doc.tools.sys.back www.doc.tools.sys.prev \n\
www.doc.tools.sys.next www.doc.tools.sys.reload";
static char _slotValue_www115[] = "171";
static char _slotValue_www116[] = "32";
static char _slotValue_www117[] = "0";
static char _slotValue_www118[] = "2";
/* END OF OBJ */

static char _slotValue_www120[] = "XPMButton";
static char _slotValue_www121[] = "www.doc.tools.sys.home";
static char _slotValue_www122[] = "www.doc.tools.sys";
static char _slotValue_www123[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonPress\":\n\
		copyArea(0,0,width(),height(),1,1);\n\
		return;\n\
	break;\n\
	case \"buttonRelease\":\n\
		send(\"www\",\"home\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Click the house icon to visit home page.\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www124[] = "/* XPM */\n\
static char * home [] = {\n\
\"32 32 9 1\",\n\
\" 	c black\",\n\
\".	c white\",\n\
\"X	c grey75\",\n\
\"o	c gray30\",\n\
\"O	c red\",\n\
\"+	c #E0E0D0D0B0B0\",\n\
\"@	c lightyellow\",\n\
\"#	c gray\",\n\
\"$	c gray50\",\n\
\"                                \",\n\
\" .............................  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\
\" .XXXXXXXXXX       XXXXXXXXXXo  \",\n\
\" .XXXXXXXXX OOOOOOO XXXXXXXXXo  \",\n\
\" .XXXXXXXX O+@OOOOOO XXXXXXXXo  \",\n\
\" .XXXXXXXX O+@@OOOOOO XXXXXXXo  \",\n\
\" .XXXXXXX O+@@@OOOOOOO XXXXXXo  \",\n\
\" .XXXXXX O+@@@@@OOOOOOO XXXXXo  \",\n\
\" .XXXXX O+@@@@@@@OOOOOOO XXXXo  \",\n\
\" .XXXXX O+@@@@@@@@OOOOOOO XXXo  \",\n\
\" .XXXX O+@@@@@@@@@OOOOOOOO XXo  \",\n\
\" .XXX O+@@@#####@@@OOOO++ XXXo  \",\n\
\" .XXXX  @@@#   #@@@@+++++ XXXo  \",\n\
\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\
\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\
\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\
\" .XXXXX @@@#   #@@@@++++  XXXo  \",\n\
\" .XXXXX @@@#   #@@@@++  XXXXXo  \",\n\
\" .XXXXXX             XXXXXXXXo  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\
\" .XXXX XX X$  $X XXX X   XXXXo  \",\n\
\" .XXXX XX X XX X  X  X XXXXXXo  \",\n\
\" .XXXX    X XX X $ $ X  XXXXXo  \",\n\
\" .XXXX XX X XX X X X X XXXXXXo  \",\n\
\" .XXXX XX X XX X XXX X XXXXXXo  \",\n\
\" .XXXX XX X$  $X XXX X   XXXXo  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\
\" .oooooooooooooooooooooooooooo  \",\n\
\"                                \",\n\
\"                                \"};\n\
";
static char _slotValue_www125[] = "32";
static char _slotValue_www126[] = "1";
static char _slotValue_www127[] = "2";
/* END OF OBJ */

static char _slotValue_www129[] = "XPMButton";
static char _slotValue_www130[] = "www.doc.tools.sys.prev";
static char _slotValue_www131[] = "www.doc.tools.sys";
static char _slotValue_www132[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"www\", \"prev\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\
		encounter = enconter + 1;\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return concat(\"Click to visit the previous document = \",\n\
				wwwHistory(\"peek_prev\"));\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www133[] = "/* XPM */\n\
static char * prev [] = {\n\
\"32 32 6 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c grey75\",\n\
\"O	c gray30\",\n\
\"+	c gray50\",\n\
\"..............................  \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".Xoooooooooooooooooo..oooooooO  \",\n\
\".Xoooooooooooooooo..++.ooooooO  \",\n\
\".Xoooooooooooooo..++++.ooooooO  \",\n\
\".Xoooooooooooo..++++++.ooooooO  \",\n\
\".Xoooooooooo..++++++++.ooooooO  \",\n\
\".Xoooooooo..++++++++++.ooooooO  \",\n\
\".Xooooooo.++++++++++++.ooooooO  \",\n\
\".Xooooo.++++++++++++++.ooooooO  \",\n\
\".Xoooooo..++++++++++++.ooooooO  \",\n\
\".Xoooooooo..++++++++++.ooooooO  \",\n\
\".Xoooooooooo..++++++++.ooooooO  \",\n\
\".Xoooooooooooo..++++++.ooooooO  \",\n\
\".Xoooooooooooooo..++++.ooooooO  \",\n\
\".Xoooooooooooooooo..++.ooooooO  \",\n\
\".Xoooooooooooooooooo..oooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".Xoooo...+o...+o...o.ooo.ooooO  \",\n\
\".Xoooo.oo.o.oo.o.ooo.ooo.ooooO  \",\n\
\".Xoooo.oo.o...+o..oo.+o+.ooooO  \",\n\
\".Xoooo...+o.o.oo.oooo.o.oooooO  \",\n\
\".Xoooo.oooo.oo.o.oooo.+.oooooO  \",\n\
\".Xoooo.oooo.oo.o...ooo.ooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\
\"                                \",\n\
\"                                \"};\n\
";
static char _slotValue_www134[] = "32";
static char _slotValue_www135[] = "1";
static char _slotValue_www136[] = "2";
/* END OF OBJ */

static char _slotValue_www138[] = "XPMButton";
static char _slotValue_www139[] = "www.doc.tools.sys.back";
static char _slotValue_www140[] = "www.doc.tools.sys";
static char _slotValue_www141[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"www\",\"back\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return concat(\"Click to go back. document = \",\n\
				send(\"wwwHistory\", \"peek_back\"));\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www142[] = "/* XPM */\n\
static char * back [] = {\n\
\"32 32 7 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c gray\",\n\
\"O	c gray30\",\n\
\"+	c gray50\",\n\
\"@	c grey75\",\n\
\"..............................  \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".Xooooooooooooo.oooooooooooooO  \",\n\
\".Xoooooooooooo.+.ooooooooooooO  \",\n\
\".Xoooooooooooo.+.ooooooooooooO  \",\n\
\".Xooooooooooo.+++.oooooooooooO  \",\n\
\".Xooooooooooo.+++.oooooooooooO  \",\n\
\".Xoooooooooo.+++++.ooooooooooO  \",\n\
\".Xoooooooooo.+++++.ooooooooooO  \",\n\
\".Xooooooooo.+++++++.oooooooooO  \",\n\
\".Xooooooooo.+++++++.oooooooooO  \",\n\
\".Xoooooooo.+++++++++.ooooooooO  \",\n\
\".Xoooooooo.+++++++++.ooooooooO  \",\n\
\".Xooooooo.+++++++++++.oooooooO  \",\n\
\".Xooooooo.+++++++++++.oooooooO  \",\n\
\".Xoooooo.+++++++++++++.ooooooO  \",\n\
\".Xoooooo.+++++++++++++.ooooooO  \",\n\
\".Xooooooo.............oooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".Xoooo...oooo.oooo..o.oo.ooooO  \",\n\
\".Xoooo.o.ooo.o.oo.ooo.o.oooooO  \",\n\
\".Xoooo....oo...oo.ooo..ooooooO  \",\n\
\".Xoooo.oo.o.ooo.o.ooo.@.oooooO  \",\n\
\".Xoooo...oo.ooo.oo..o.oo.ooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\
\"                                \",\n\
\"                                \"};";
static char _slotValue_www143[] = "32";
static char _slotValue_www144[] = "1";
static char _slotValue_www145[] = "2";
/* END OF OBJ */

static char _slotValue_www147[] = "XPMButton";
static char _slotValue_www148[] = "www.doc.tools.sys.next";
static char _slotValue_www149[] = "www.doc.tools.sys";
static char _slotValue_www150[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonPress\":\n\
		copyArea(0,0,width(),height(),1,1);\n\
		return;\n\
	break;\n\
	case \"buttonRelease\":\n\
		www(\"next\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return concat(\"Click to visit the next document = \",\n\
				wwwHistory(\"peek_next\"));\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www151[] = "/* XPM */\n\
static char * next [] = {\n\
\"32 32 6 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c grey75\",\n\
\"O	c gray30\",\n\
\"+	c gray50\",\n\
\"..............................  \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".Xoooooooo..oooooooooooooooooO  \",\n\
\".Xooooooo.++..oooooooooooooooO  \",\n\
\".Xooooooo.++++..oooooooooooooO  \",\n\
\".Xooooooo.++++++..oooooooooooO  \",\n\
\".Xooooooo.++++++++..oooooooooO  \",\n\
\".Xooooooo.++++++++++..oooooooO  \",\n\
\".Xooooooo.++++++++++++..oooooO  \",\n\
\".Xooooooo.++++++++++++++.ooooO  \",\n\
\".Xooooooo.++++++++++++..oooooO  \",\n\
\".Xooooooo.++++++++++..oooooooO  \",\n\
\".Xooooooo.++++++++..oooooooooO  \",\n\
\".Xooooooo.++++++..oooooooooooO  \",\n\
\".Xooooooo.++++..oooooooooooooO  \",\n\
\".Xooooooo.++..oooooooooooooooO  \",\n\
\".Xoooooooo..oooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".Xooo.+oo.o...o.ooo.o.....oooO  \",\n\
\".Xooo..+o.o.ooo+.o.+ooo.oooooO  \",\n\
\".Xooo.o.+.o..+oo+.+oooo.oooooO  \",\n\
\".Xooo.oo..o.oooo+.+oooo.oooooO  \",\n\
\".Xooo.ooo.o.ooo+.o.+ooo.oooooO  \",\n\
\".Xooo.ooo.o...o.ooo.ooo.oooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\
\"                                \",\n\
\"                                \"};\n\
";
static char _slotValue_www152[] = "32";
static char _slotValue_www153[] = "1";
static char _slotValue_www154[] = "2";
/* END OF OBJ */

static char _slotValue_www156[] = "XPMButton";
static char _slotValue_www157[] = "www.doc.tools.sys.reload";
static char _slotValue_www158[] = "www.doc.tools.sys";
static char _slotValue_www159[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"www\", \"reload\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Click to reload the document\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www160[] = "/* XPM */\n\
static char * reload [] = {\n\
\"32 32 6 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c gray\",\n\
\"O	c gray30\",\n\
\"+	c red\",\n\
\" .............................  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\
\" .XooooooooooooooooooooooooooO  \",\n\
\" .XooooooooooooooooooooooooooO  \",\n\
\" .Xooooooo...........ooooooooO  \",\n\
\" .Xooooooo.XXXXXXXX.X.oooooooO  \",\n\
\" .Xoooo+++.X......X.XX.ooooooO  \",\n\
\" .Xoooo+++.XXXXXXXX.XXX.oooooO  \",\n\
\" .Xoooo+...X......X.....oooooO  \",\n\
\" .Xoooo+++.XXXXXXXXXXXX.oooooO  \",\n\
\" .Xoooo+...X.........XX.oooooO  \",\n\
\" .Xoooo+++.XXXXXXXXXXXX.oooooO  \",\n\
\" .Xoooo+...X.........XX.oooooO  \",\n\
\" .Xoooo+++.XXXXXXXXXXXX.oooooO  \",\n\
\" .Xoooo+...X.........XX.oooooO  \",\n\
\" .Xoooo+++.XXXXXXXXXXXX.oooooO  \",\n\
\" .Xoooo+................oooooO  \",\n\
\" .Xoooo++++++++++++++ooooooooO  \",\n\
\" .Xoooo+...........++ooooooooO  \",\n\
\" .Xoooo++++++++++++++ooooooooO  \",\n\
\" .XooooooooooooooooooooooooooO  \",\n\
\" .XooooooooooooooooooooooooooO  \",\n\
\" .Xoo...Oo...o.ooO.OoO.Oo..ooO  \",\n\
\" .Xoo.oo.o.ooo.oo.o.o.O.o.o.oO  \",\n\
\" .Xoo...Oo..oo.oo.o.o.o.o.o.oO  \",\n\
\" .Xoo.o.oo.ooo.oo.o.o...o.o.oO  \",\n\
\" .Xoo.oo.o.ooo.oo.o.o.o.o.o.oO  \",\n\
\" .Xoo.oo.o...o..oO.Oo.o.o..ooO  \",\n\
\" .XooooooooooooooooooooooooooO  \",\n\
\" .XOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\
\"                                \",\n\
\"                                \"};";
static char _slotValue_www161[] = "32";
static char _slotValue_www162[] = "1";
static char _slotValue_www163[] = "2";
/* END OF OBJ */

static char _slotValue_www165[] = "XPMButton";
static char _slotValue_www166[] = "www.doc.tools.ops.clone";
static char _slotValue_www167[] = "www.doc.tools.ops";
static char _slotValue_www168[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"www\", \"tear\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Click to reload the document\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www169[] = "/* XPM */\n\
static char * clone [] = {\n\
\"32 32 5 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c gray\",\n\
\"O	c gray30\",\n\
\"..............................  \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".Xooo..........ooooooooooooooO  \",\n\
\".Xooo.XXXXXXX.X.oooooooooooooO  \",\n\
\".Xooo.X....XX.XX.ooooooooooooO  \",\n\
\".Xooo.XXXXXXX.XXX.oooooooooooO  \",\n\
\".Xooo.X.....X.....oooooooooooO  \",\n\
\".Xooo.XXXXXXXXXXX.oooooooooooO  \",\n\
\".Xooo.X......X.........ooooooO  \",\n\
\".Xooo.XXXXXXXX.XXXXXX.X.oooooO  \",\n\
\".Xooo.X......X.X...XX.XX.ooooO  \",\n\
\".Xooo.XXXXXXXX.XXXXXX.XXX.oooO  \",\n\
\".Xooo.X......X.X....X.....oooO  \",\n\
\".Xooo.XXXXXXXX.XXXXXXXXXX.oooO  \",\n\
\".Xooo.XXXXXXXX.X........X.oooO  \",\n\
\".Xooo..........XXXXXXXXXX.oooO  \",\n\
\".Xoooooooooooo.X........X.oooO  \",\n\
\".Xoooooooooooo.XXXXXXXXXX.oooO  \",\n\
\".Xoooooooooooo.XXXXXXXXXX.oooO  \",\n\
\".Xoooooooooooo............oooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".Xooooo..o.oo...o.Oo.o...ooooO  \",\n\
\".Xoooo.Ooo.oo.o.o..o.o.ooooooO  \",\n\
\".Xoooo.ooo.oo.o.o.o..o..oooooO  \",\n\
\".Xoooo.ooo.oo.o.o.oO.o.ooooooO  \",\n\
\".Xoooo.Ooo.oo.o.o.oo.o.ooooooO  \",\n\
\".Xooooo..o..o...o.oo.o...ooooO  \",\n\
\".XoooooooooooooooooooooooooooO  \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\
\"                                \",\n\
\"                                \"};";
static char _slotValue_www170[] = "32";
static char _slotValue_www171[] = "1";
static char _slotValue_www172[] = "2";
/* END OF OBJ */

static char _slotValue_www174[] = "hpane";
static char _slotValue_www175[] = "www.doc.tools.httpStat";
static char _slotValue_www176[] = "www.doc.tools";
static char _slotValue_www177[] = "www.doc.tools.httpStat.icon";
static char _slotValue_www178[] = "38";
static char _slotValue_www179[] = "32";
static char _slotValue_www180[] = "3";
static char _slotValue_www181[] = "2";
/* END OF OBJ */

static char _slotValue_www183[] = "XBMButton";
static char _slotValue_www184[] = "www.doc.tools.httpStat";
static char _slotValue_www185[] = "www.doc.tools.httpStat.icon";
static char _slotValue_www186[] = "\n\
	switch (arg[0]) {\n\
	case \"stat\":\n\
		if (inProgress == 0) {\n\
			clearWindow();\n\
			inProgress = 1;\n\
		}\n\
		fillArc(5, 2, w, h, 0, arg[1] * 3.6);\n\
		flush();\n\
		return;\n\
	break;\n\
	case \"clear\":\n\
		inProgress = 0;\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"config\":\n\
	case \"init\":\n\
		usual();\n\
		h = get(\"height\") - 5;\n\
		w = h;\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www187[] = "#define violaIcon2_width 36\n\
#define violaIcon2_height 30\n\
static char violaIcon2_bits[] = {\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00,\n\
   0x00, 0xe0, 0x30, 0x78, 0x00, 0x00, 0x30, 0x60, 0xcc, 0x01, 0x00, 0x18,\n\
   0xc0, 0x07, 0x03, 0x00, 0x08, 0x80, 0x01, 0x03, 0x00, 0x0c, 0x00, 0x00,\n\
   0x06, 0x00, 0x04, 0x00, 0x00, 0x46, 0x01, 0x04, 0x00, 0x00, 0x46, 0x01,\n\
   0x04, 0x80, 0xa4, 0xff, 0x03, 0x04, 0x0f, 0x00, 0x40, 0x01, 0x04, 0x0f,\n\
   0x00, 0x40, 0x01, 0x04, 0x0e, 0x04, 0x40, 0x01, 0x08, 0x0e, 0x04, 0x00,\n\
   0x00, 0x18, 0x1c, 0x04, 0x00, 0x00, 0x30, 0x1c, 0x02, 0x04, 0x00, 0xf0,\n\
   0x19, 0x0a, 0x74, 0x00, 0xe0, 0x39, 0x02, 0x84, 0x00, 0xc0, 0x31, 0xc9,\n\
   0x84, 0x00, 0x00, 0x20, 0x29, 0xe5, 0x00, 0x00, 0x60, 0x29, 0x95, 0x00,\n\
   0x00, 0xc0, 0x29, 0x95, 0x00, 0x00, 0xc0, 0xc8, 0xe4, 0x01, 0x00, 0x80,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_www188[] = "2";
static char _slotValue_www189[] = "31";
static char _slotValue_www190[] = "6";
/* END OF OBJ */

static char _slotValue_www192[] = "hpane";
static char _slotValue_www193[] = "www.doc.view";
static char _slotValue_www194[] = "www.doc";
static char _slotValue_www195[] = "www.doc.view.pane www.doc.view.sb";
static char _slotValue_www196[] = "2";
static char _slotValue_www197[] = "\n\
/*\n\
print(\"DOC>VIEW: \");\n\
for (i=0; i < arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");\n\
print(\"\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"config\":\n\
		if (lbarVisible == 1) {\n\
			send(nthChild(0), \"resetWidthConstraint\", arg[3]);\n\
		}\n\
	break;\n\
	case \"tear\":\n\
	case \"quit\":\n\
		send(get(\"parent\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		send(pagePane, \"torn\", arg[1]);\n\
		pagePane = get(\"content\");\n\
		return;\n\
	break;\n\
	case \"whichPageP\":\n\
		return send(pagePane, \"whichPageP\");\n\
	break;\n\
	case \"key_up\":\n\
		send(\"www.doc.view.sb.slider\", \"scroll\", \"up\");\n\
		return;\n\
	break;\n\
	case \"key_down\":\n\
		send(\"www.doc.view.sb.slider\", \"scroll\", \"down\");\n\
		return;\n\
	break;\n\
	case \"keyPress\":\n\
		c = key();\n\
		if (c == ' ')\n\
			send(\"www.doc.view.sb.slider\", \"scroll\", \"down\");\n\
		return;\n\
	break;\n\
	case \"addTool\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(parent(), arg[0], arg[1]);\n\
	break;\n\
	case \"linkSideBar\":\n\
		sideBarURL = arg[1];\n\
		sideBarRatio = arg[2];\n\
		sideBarMaxWidth = arg[3];\n\
		send(self(), \"lbarConfig\", \"on\", \n\
			sideBarURL, sideBarRatio, sideBarMaxWidth);\n\
		return;\n\
	break;\n\
	case \"lbarConfig\":\n\
		switch (arg[1]) {\n\
		case \"on\":\n\
			set(\"children\", \n\
			\"www.doc.view.lbar www.doc.view.pane www.doc.view.sb\");\n\
			send(nthChild(0), \"enable\", \n\
				arg[2], arg[3], arg[4], width());\n\
\n\
			send(self(), \"configSelf\");\n\
			if (lbarVisible == 0) send(nthChild(0), \"visible\", 1);\n\
			pagePane = nthChild(1);\n\
			lbarVisible = 1;\n\
		break;\n\
		case \"off\":\n\
			if (lbarVisible == 1) send(nthChild(0), \"disable\");\n\
			set(\"children\", \n\
			\"www.doc.view.pane www.doc.view.sb\");\n\
			lbarVisible = 0;\n\
			send(self(), \"configSelf\");\n\
			pagePane = nthChild(0);\n\
		break;\n\
		}\n\
		set(\"content\", pagePane);\n\
		return;\n\
	break;\n\
	case \"sliderConfig\":\n\
		switch (arg[1]) {\n\
		case \"left\":\n\
			set(\"children\", \"www.doc.view.sb www.doc.view.pane\");\n\
			send(self(), \"configSelf\");\n\
			send(\"www.doc.view.sTUb\", \"getLost\");\n\
			pagePane = nthChild(2);\n\
			send(\"www.doc.view.pane\", \"configSiderGeom\");\n\
		break;\n\
		case \"right\":\n\
			set(\"children\", \"www.doc.view.pane www.doc.view.sb\");\n\
			send(self(), \"configSelf\");\n\
			send(\"www.doc.view.sTUb\", \"getLost\");\n\
			pagePane = nthChild(1);\n\
			send(\"www.doc.view.pane\", \"configSiderGeom\");\n\
		break;\n\
		case \"none\":\n\
			set(\"children\", \"www.doc.view.pane www.doc.view.sTUb\");\n\
			send(\"www.doc.view.sTUb\", \"showYaSelf\");\n\
			send(self(), \"configSelf\");\n\
			pagePane = nthChild(1);\n\
		break;\n\
		}\n\
		set(\"content\", pagePane);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		/* default scrolbar at right side, lbar off */\n\
		pagePane = nthChild(0); \n\
		set(\"content\", pagePane);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_www199[] = "field";
static char _slotValue_www200[] = "www.doc.view.sTUb";
static char _slotValue_www201[] = "www.doc.view";
static char _slotValue_www202[] = "\n\
	switch (arg[0]) {\n\
	case \"showYaSelf\":\n\
		set(\"visible\", 1);\n\
		return;\n\
	break;\n\
	case \"getLost\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www203[] = "20";
/* END OF OBJ */

static char _slotValue_www205[] = "vpane";
static char _slotValue_www206[] = "www.doc.view.sb";
static char _slotValue_www207[] = "www.doc.view";
static char _slotValue_www208[] = "www.doc.view.sb.up www.doc.view.sb.slider www.doc.view.sb.down";
static char _slotValue_www209[] = "20";
/* END OF OBJ */

static char _slotValue_www211[] = "XBMButton";
static char _slotValue_www212[] = "www.doc.view.sb.up";
static char _slotValue_www213[] = "www.doc.view.sb";
static char _slotValue_www214[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(nthSibling(1), \"scroll\", \"up\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Click to scroll up one page.\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www215[] = "#define arrowUp_width 19\n\
#define arrowUp_height 19\n\
static char arrowUp_bits[] = {\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x07, 0x00, 0x80, 0x0f, 0x00,\n\
   0xc0, 0x1f, 0x00, 0xe0, 0x3f, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x07, 0x00,\n\
   0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_www216[] = "3";
static char _slotValue_www217[] = "17";
static char _slotValue_www218[] = "17";
static char _slotValue_www219[] = "17";
static char _slotValue_www220[] = "17";
/* END OF OBJ */

static char _slotValue_www222[] = "XBMButton";
static char _slotValue_www223[] = "www.doc.view.sb.down";
static char _slotValue_www224[] = "www.doc.view.sb";
static char _slotValue_www225[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(nthSibling(1), \"scroll\", \"down\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Click to scroll down one page.\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www226[] = "#define arrowDown_width 20\n\
#define arrowDown_height 20\n\
static char arrowDown_bits[] = {\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00,\n\
   0x00, 0x07, 0x00, 0xe0, 0x3f, 0x00, 0xe0, 0x3f, 0x00, 0xc0, 0x1f, 0x00,\n\
   0x80, 0x0f, 0x00, 0x00, 0x07, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_www227[] = "1";
static char _slotValue_www228[] = "1";
static char _slotValue_www229[] = "3";
static char _slotValue_www230[] = "17";
static char _slotValue_www231[] = "17";
static char _slotValue_www232[] = "17";
static char _slotValue_www233[] = "17";
/* END OF OBJ */

static char _slotValue_www235[] = "slider";
static char _slotValue_www236[] = "www.doc.view.sb.slider";
static char _slotValue_www237[] = "www.doc.view.sb";
static char _slotValue_www238[] = "www.doc.view.pane";
static char _slotValue_www239[] = "\n\
	switch (arg[0]) {\n\
	case \"setShownNotify\":\n\
		set(\"shownNotify\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"kludgeRender\":\n\
		/* This is a kludge to get around a BUG */\n\
		return after(1, self(), \"render\");\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_www241[] = "slider";
static char _slotValue_www242[] = "www.doc.view.lbar.sb";
static char _slotValue_www243[] = "www.doc.view";
static char _slotValue_www244[] = "www.doc.view.lbar.pane";
static char _slotValue_www245[] = "\n\
	switch (arg[0]) {\n\
	case \"setShownNotify\":\n\
		set(\"shownNotify\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"kludgeRender\":\n\
		/* This is a kludge to get around a BUG */\n\
		return after(1, self(), \"render\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www246[] = "left2right";
static char _slotValue_www247[] = "20";
/* END OF OBJ */

static char _slotValue_www249[] = "vpane";
static char _slotValue_www250[] = "www.doc.view";
static char _slotValue_www251[] = "www.doc.view.lbar";
static char _slotValue_www252[] = "www.doc.view.lbar.pane www.doc.view.lbar.ctrls";
static char _slotValue_www253[] = "\n\
	switch (arg[0]) {\n\
	case \"barScroll\":\n\
		return send(nthChild(0), arg[0], arg[1]);\n\
	break;\n\
	case \"enable\":\n\
		enable = 1;\n\
		barURL = arg[1];\n\
		barRatio = arg[2];\n\
		barMaxWidth = arg[3];\n\
		parentWidth = arg[4];\n\
\n\
		if (barMaxWidth != 0) {\n\
			barWidth = barMaxWidth;\n\
		} else {\n\
			barWidth = float(parentWidth) * \n\
					float(barRatio) / 100.0;\n\
		}\n\
		set(\"width\", barWidth);\n\
		set(\"maxWidth\", barWidth);\n\
		set(\"visible\", 1);\n\
		send(nthChild(0), \"show\", barURL, barWidth);\n\
		return;\n\
	break;\n\
	case \"disable\":\n\
		enable = 0;\n\
		set(\"visible\", 0);\n\
		set(\"y\", 999);/*???? why won't this window go away??*/\n\
		return;\n\
	break;\n\
	case \"lbarEnabledP\":\n\
		return enable;\n\
	break;\n\
	case \"resetWidthConstraint\":\n\
		parentWidth = arg[1];\n\
		barWidth = float(parentWidth) * float(barRatio) / 100.0;\n\
		set(\"width\", 99);/*lame way to force a re config */\n\
		set(\"maxWidth\", barWidth);\n\
		return;		\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www254[] = "100";
static char _slotValue_www255[] = "100";
static char _slotValue_www256[] = "3";
static char _slotValue_www257[] = "3";
static char _slotValue_www258[] = "100";
static char _slotValue_www259[] = "1";
static char _slotValue_www260[] = "2";
/* END OF OBJ */

static char _slotValue_www262[] = "hpane";
static char _slotValue_www263[] = "www.doc.view.lbar";
static char _slotValue_www264[] = "www.doc.view.lbar.ctrls";
static char _slotValue_www265[] = "www.doc.view.lbar.ctrls.up www.doc.view.lbar.ctrls.down";
static char _slotValue_www266[] = "\n\
	switch (arg[0]) {\n\
	case \"barScroll\":\n\
		return send(parent(), arg[0], arg[1]);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www267[] = "1";
static char _slotValue_www268[] = "20";
/* END OF OBJ */

static char _slotValue_www270[] = "txtButton";
static char _slotValue_www271[] = "www.doc.view.lbar.ctrls";
static char _slotValue_www272[] = "www.doc.view.lbar.ctrls.up";
static char _slotValue_www273[] = "Up";
static char _slotValue_www274[] = "\n	if (arg[0] == \"buttonRelease\") send(parent(), \"barScroll\", \"up\");\n	usual();\n";
static char _slotValue_www275[] = "normal";
static char _slotValue_www276[] = "2";
/* END OF OBJ */

static char _slotValue_www278[] = "txtButton";
static char _slotValue_www279[] = "www.doc.view.lbar.ctrls";
static char _slotValue_www280[] = "www.doc.view.lbar.ctrls.down";
static char _slotValue_www281[] = "Down";
static char _slotValue_www282[] = "\n	if (arg[0] == \"buttonRelease\") send(parent(), \"barScroll\", \"down\");\n	usual();\n";
static char _slotValue_www283[] = "normal";
static char _slotValue_www284[] = "1";
/* END OF OBJ */

static char _slotValue_www286[] = "field";
static char _slotValue_www287[] = "www.doc.view.lbar.pane";
static char _slotValue_www288[] = "www.doc.view.lbar";
static char _slotValue_www289[] = "www.doc.view.lbar.sb";
static char _slotValue_www290[] = "\n\
	switch (arg[0]) {\n\
	case \"shownPositionH\":\n\
	case \"shownPositionV\":\n\
		return send(docObj, \"shownPositionV\", arg[1]);\n\
	break;\n\
	case \"barScroll\":\n\
		if (arg[1] == \"down\") {\n\
			pgPosPct += 10;\n\
			if (pgPosPct > 100) pgPosPct = 100;\n\
		} else {\n\
			pgPosPct -= 10;\n\
			if (pgPosPct < 0) pgPosPct = 0;\n\
		}\n\
		return send(docObj, \"shownPositionV\", pgPosPct);\n\
	break;\n\
	case \"show\":\n\
		barURL = arg[1];\n\
		barWidth = arg[2];\n\
\n\
		set(\"width\", barWidth);\n\
\n\
		pgPosPct = 0;\n\
\n\
		handler = wwwFormatDetect(\"type\", barURL);\n\
		send(\"www.mesg.tf\", \"show\", \n\
			    concat(\"Getting sidebar from \", barURL));\n\
\n\
		docObj = send(\"wwwHandlerDispatch\", \n\
				\"dispatch\", handler,\n\
				0, barURL,\n\
				barURL, self(),\n\
				int(barWidth), 999,\n\
				\"\", 1, 0);\n\
\n\
		/* XXX kludgy stylesheet turn off */\n\
		STG_clean(0);\n\
\n\
		send(docObj, \"display\", barWidth, 999);\n\
		send(docObj, \"show\");\n\
\n\
		pageHeight = send(docObj, \"vspan\");\n\
		send(self(), \"configShare\");\n\
\n\
		return;\n\
	break;\n\
	case \"toDoInsert\":\n\
		insertObj[insertObjCount] = arg[1];\n\
		insertObjCount++;\n\
		return;\n\
	break;\n\
	case \"show_request_by_child\":\n\
	case \"post_request_by_child\":\n\
		send(\"www\", \"busy\");\n\
\n\
		if (arg[0] == \"post_request_by_child\") realMesg = \"post\";\n\
		else realMesg = \"show\";\n\
\n\
		if (torn == 1) destObj = self();\n\
		else destObj = object(\"www\");\n\
\n\
		if (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);\n\
		else stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);\n\
\n\
		if (stat) stat = send(\"www.doc.view.pane\", \"historyRecord\");\n\
\n\
		send(\"www\", \"idle\");\n\
		return stat;\n\
	break;\n\
	case \"setChildren\":\n\
		set(\"children\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"configShare\":\n\
		heightDiff = pageHeight - get(\"height\");\n\
		heightRatio =  float(heightDiff) / -100.0;\n\
		if (heightDiff > 0) {\n\
		  sliderSize = float(get(\"height\")) / float(pageHeight) * 100;\n\
		  sliderPos = float(pageYPos) / float(heightDiff) * -100;\n\
		} else {\n\
		  sliderSize = 100;\n\
		  sliderPos = 0;\n\
		}\n\
		objectListSend(\"shownDepend\", \"_shownInfoH\", \n\
				sliderPos, sliderSize);\n\
		objectListSend(\"shownDepend\", \"setShownNotify\", docObj);\n\
		return;\n\
	break;\n\
	case \"configSliderGeom\":\n\
		pageHeight = send(docObj, \"vspan\");\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"configSlider\":\n\
		/* arg[1]	pageYPos\n\
		 * arg[2]	pageHeight\n\
		 */\n\
		pageYPos = arg[1];\n\
		pageHeight = arg[2];\n\
		if (pageYPos + pageHeight < get(\"height\")) {\n\
			pageYPos = get(\"height\") - pageHeight;\n\
			if (pageYPos > 0) pageYPos = 0;\n\
			send(docObj, \"y\", pageYPos);\n\
		}\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		if (send(parent(), \"lbarEnabledP\") == 0) return;\n\
		usual();\n\
		/* ask page object to do the calculation */\n\
		send(docObj, \"resize\", get(\"width\"), get(\"height\"));\n\
		pageYPos = send(docObj, \"yP\");\n\
		pageHeight = send(docObj, \"vspan\");\n\
		if (pageYPos + pageHeight < get(\"height\")) {\n\
			pageYPos = get(\"height\") - pageHeight;\n\
			send(docObj, \"y\", pageYPos);\n\
		}\n\
		send(self(), \"configShare\");\n\
		configed = 1;\n\
		return;\n\
	break;\n\
	case \"update\":\n\
		pageObj = nthChild(0);\n\
		pageHeight = arg[1];\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"destroyDoc\":\n\
	case \"destroyDoc_qualified\":\n\
		send(pageObj, \"VW_event\", \"VIEW_OFF\");\n\
		send(pageObj, \"visible\", 0);\n\
		send(pageObj, \"freeSelf\");\n\
		pageObj = 0;\n\
		return;\n\
	break;\n\
	case \"addTool\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(parent(), arg[0], arg[1]);\n\
	break;\n\
	case \"showSrc\":\n\
	case \"reload\":\n\
	case \"clone\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	case \"whichPageP\":\n\
		return nthChild(0);\n\
	break;\n\
	case \"heightP\":\n\
		return height();\n\
	break;\n\
	case \"R\": /* happens sometimes. blah */\n\
	case \"reportNextID\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www291[] = "100";
static char _slotValue_www292[] = "999";
static char _slotValue_www293[] = "2";
static char _slotValue_www294[] = "2";
static char _slotValue_www295[] = "6";
/* END OF OBJ */

static char _slotValue_www297[] = "field";
static char _slotValue_www298[] = "www.doc.view.pane";
static char _slotValue_www299[] = "www.doc.view";
static char _slotValue_www300[] = "www.doc.view.sb.slider";
static char _slotValue_www301[] = "\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		return send(pageObj, \"shownPositionV\", arg[1]);\n\
	break;\n\
	case \"initKludge\":\n\
		return;\n\
	break;\n\
	case \"show\":\n\
	case \"post\":\n\
		if (configed == 0) {\n\
			after(1000, self(), arg[0], arg[1]);\n\
			return -1;\n\
		}\n\
\n\
		if (arg[0] == \"post\") {\n\
			doPost = 1;\n\
			postData = arg[3];\n\
		} else { \n\
			doPost = 0;\n\
			postData = 0;\n\
		}\n\
		if (torn == 1) {\n\
			if (arg[] == 2)\n\
				return send(\"www.doc.view.pane\", \n\
					    arg[0], arg[1]);\n\
			else if (arg[] == 3)\n\
				return send(\"www.doc.view.pane\", \n\
					    arg[0], arg[1], arg[2]);\n\
			else	return send(\"www.doc.view.pane\", \n\
					    arg[0], arg[1], arg[2], arg[3]);\n\
		}\n\
		if (nthChar(arg[1], 0) == '#') {	\n\
			pageYPos = send(pageObj, \"gotoAnchor\", \n\
					nthChar(arg[1], 1, 999));\n\
\n\
			pageHeight = send(pageObj, \"vspan\");\n\
			heightDiff = pageHeight - get(\"height\");\n\
			heightRatio =  float(heightDiff) / -100.0;\n\
\n\
			if (heightDiff > 0) {\n\
				sliderSize = float(get(\"height\")) / \n\
						float(pageHeight) * 100;\n\
				sliderPos = float(pageYPos) / \n\
						float(heightDiff) * 100;\n\
				if (sliderPos > 100) sliderPos = 100;\n\
			} else {\n\
				sliderSize = 100;\n\
				sliderPos = 0;\n\
			}\n\
			send(pageObj, \"shownPositionV\", sliderPos);\n\
			objectListSend(\"shownDepend\", \"_shownInfoV\", \n\
					sliderPos, sliderSize);\n\
			objectListSend(\"shownDepend\", \"setShownNotify\",\n\
					pageObj);\n\
		} else {\n\
			if (arg[] == 2) \n\
				normURL = send(\"normalizeURL\", \"normalizeURL\",\n\
						arg[1]);\n\
			else \n\
				normURL = send(\"normalizeURL\", \"normalizeURL\",\n\
						arg[1], arg[2]);\n\
\n\
			oldDocName = docName;\n\
			docName = normURL;\n\
			docURL = normURL;\n\
\n\
			if (findPattern(arg[1], \"telnet:\") != -1) {\n\
				cmd = send(\"WWWTelnetHandler\", \"connect\", \n\
						normURL);\n\
				www.mesg.tf(\"warn\", cmd);\n\
				system(cmd);\n\
				return normURL;\n\
			} else if (findPattern(arg[1], \"mailto:\") != -1) {\n\
				subject = concat(\"WWW mail from: \", \n\
						ormalizedURL);\n\
				tt = arg[1];\n\
				i = findPattern(tt, \"/\");\n\
				if (i == -1) {\n\
					address = nthChar(tt, 7, 999);\n\
					content = concat(\n\
				\"This mail was generated by WWW URL:\\n\
\",\n\
						   tt, \"\\n\
\");\n\
				} else {\n\
					address = nthChar(tt, 7, i-1);\n\
					content = concat(nthChar(tt, io1, 999),\n\
							 \"\\n\
\");\n\
				}\n\
				tmpFile = makeTempFile();\n\
				saveFile(tmpFile, content);\n\
\n\
				cmd = concat(\"mail -s \\\"\", subject,\n\
					     \"\\\" \", address, \" < \", tmpFile);\n\
				system(cmd);\n\
				system(concat(\"rm \", tmpFile));\n\
				return normURL;\n\
			}\n\
			anchor = parseHTTPAddress(\"anchor\", normURL);\n\
\n\
			if (exist(pageObj) == 1) send(pageObj, \"undisplay\");\n\
\n\
			if (exist(docName) == 1) {\n\
				set(\"children\", docName);\n\
				if (anchor != \"\")  {\n\
					if (findPattern(docURL, \".hmml\") > -1){\n\
						pageYPos = send(docName, \n\
								\"gotoAnchor\",\n\
								 anchor) * -1;\n\
						send(docName, \"y\", pageYPos);\n\
					}\n\
				} else {\n\
					pageYPos = send(docName, \"yP\");\n\
				}\n\
				if (send(docName, \"configSideBar\") == 1) {\n\
					send(parent(), \"linkSideBar\", \n\
				  sideBarURL, sideBarRatio, sideBarMaxWidth);\n\
				} else {\n\
					send(parent(), \"lbarConfig\", \"off\");\n\
				}\n\
				send(docName, \"display\", width(), height());\n\
			} else {\n\
				/* a rough guess at the document type */\n\
				handler = wwwFormatDetect(\"type\", docURL);\n\
				send(\"www.mesg.tf\", \"show\", \n\
					    concat(\"Getting \", docURL));\n\
\n\
				if (torn == 1) paneObj = \"www.doc.view.pane\";\n\
				else paneObj = self();\n\
\n\
				docObj = send(\"wwwHandlerDispatch\", \n\
						\"dispatch\", handler,\n\
						doPost, docURL,\n\
						docName, paneObj,\n\
						get(\"width\"), get(\"height\"),\n\
						anchor, 1, postData);\n\
\n\
				/* XXX kludgy stylesheet turn off */\n\
				STG_clean(0);\n\
\n\
				if (docObj == 0) {\n\
					if (exist(\"www.mesg.tf\"))\n\
						www.mesg.tf(\"show\",\n\
						 concat(\"Failed \", docURL));\n\
					winPos = windowPosition();\n\
					res.dialogWithButtons(\"showAt\", \n\
						winPos[0] + 20, winPos[1] + 20,\n\
						500, 80,\n\
						concat(\"Failed to access\\n\
\", \n\
							docURL),\n\
						\"Dismiss\", \"\");\n\
					return 0;\n\
				} else if (docObj == 1) {\n\
		/* It's OK.. no doc object generated but wasn't an error \n\
		 * (ie: to be rendered by external viewer) */\n\
					return 0;\n\
				}\n\
\n\
				if (send(docName, \"configSideBar\") == 1) {\n\
					send(parent(), \"linkSideBar\", \n\
				  sideBarURL, sideBarRatio, sideBarMaxWidth);\n\
				} else {\n\
					send(parent(), \"lbarConfig\", \"off\");\n\
				}\n\
\n\
				if (insertObjCount > 0) {\n\
					for (i = 0; i < insertObjCount; i++)\n\
						send(insertObj[i], \"insert\");\n\
					insertObjCount = 0;\n\
					send(self(), \"R\", \n\
						get(\"y\"), get(\"width\"));\n\
				}\n\
				send(docObj, \"display\", \n\
						get(\"width\"), get(\"height\"));\n\
				send(docObj, \"show\");\n\
				pageYPos = send(docObj, \"yP\");\n\
\n\
			}\n\
			oo = object(docName);\n\
			if (oldDocName != docName) {\n\
				if (pageObj) {\n\
					send(pageObj, \"VW_event\", \"VIEW_OFF\");\n\
				}\n\
				pageObj = oo;\n\
				send(pageObj, \"VW_event\", \"VIEW_ON\");\n\
			} else {\n\
				pageObj = oo;\n\
			}\n\
\n\
			pageHeight = send(pageObj, \"vspan\");\n\
			send(self(), \"configShare\");\n\
		}\n\
\n\
		title = send(pageObj, \"queryTitle\");\n\
		if (isBlank(title)) title = pageObj;\n\
		www.doc.title.tf(\"show\", title);\n\
\n\
		www.url.tf(\"show\", send(pageObj, \"queryAddress\"));\n\
\n\
		if (notYetRecordedInitDocInHistory) {\n\
			/* this special case for the initial document\n\
			 */\n\
			notYetRecordedInitDocInHistory = 0;\n\
			send(\"www.doc.view.pane\", \"historyRecord\");\n\
		}\n\
\n\
		return docName;\n\
	break;\n\
	case \"toDoInsert\":\n\
		insertObj[insertObjCount] = arg[1];\n\
		insertObjCount++;\n\
		return;\n\
	break;\n\
	case \"show_request_by_child\":\n\
	case \"post_request_by_child\":\n\
		send(\"www\", \"busy\");\n\
\n\
		if (arg[0] == \"post_request_by_child\") realMesg = \"post\";\n\
		else realMesg = \"show\";\n\
\n\
		if (torn == 1) destObj = self();\n\
		else destObj = object(\"www\");\n\
\n\
		if (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);\n\
		else stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);\n\
\n\
		if (stat) stat = send(\"www.doc.view.pane\", \"historyRecord\");\n\
\n\
		send(\"www\", \"idle\");\n\
		return stat;\n\
	break;\n\
	case \"hintOn\":\n\
		www.mesg.tf(\"show\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"hintOff\":\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"setChildren\":\n\
		set(\"children\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"configShare\":\n\
		heightDiff = pageHeight - get(\"height\");\n\
		heightRatio =  float(heightDiff) / -100.0;\n\
		if (heightDiff > 0) {\n\
		  sliderSize = float(get(\"height\")) / float(pageHeight) * 100;\n\
		  sliderPos = float(pageYPos) / float(heightDiff) * -100;\n\
		} else {\n\
		  sliderSize = 100;\n\
		  sliderPos = 0;\n\
		}\n\
		objectListSend(\"shownDepend\", \"_shownInfoV\", \n\
				sliderPos, sliderSize);\n\
		objectListSend(\"shownDepend\", \"setShownNotify\", pageObj);\n\
		return;\n\
	break;\n\
	case \"configSliderGeom\":\n\
		pageHeight = send(pageObj, \"vspan\");\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"configSlider\":\n\
		/* arg[1]	pageYPos\n\
		 * arg[2]	pageHeight\n\
		 */\n\
		pageYPos = arg[1];\n\
		pageHeight = arg[2];\n\
		if (pageYPos + pageHeight < get(\"height\")) {\n\
			pageYPos = get(\"height\") - pageHeight;\n\
			if (pageYPos > 0) pageYPos = 0;\n\
			send(pageObj, \"y\", pageYPos);\n\
		}\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		usual();\n\
		if (send(pageObj, \"viewP\") == 1) {\n\
			/* when switching from a sidebar'ed document to\n\
			 * a non-sidebar document, this object will be\n\
			 * 'configed' (and before the new document gets\n\
			 * configed... so we don't want to bother \n\
			 * that document (pageObj) until it is ready\n\
			 * (when viewP == 1).\n\
			 */\n\
			/* ask page object to do the calculation */\n\
			send(pageObj, \"resize\", get(\"width\"), get(\"height\"));\n\
			pageYPos = send(pageObj, \"yP\");\n\
			pageHeight = send(pageObj, \"vspan\");\n\
			if (pageYPos + pageHeight < get(\"height\")) {\n\
				pageYPos = get(\"height\") - pageHeight;\n\
				send(pageObj, \"y\", pageYPos);\n\
			}\n\
			send(self(), \"configShare\");\n\
		}\n\
		/* this call should not be necessary... what was it for? */\n\
		/*objectListSend(\"shownDepend\", \"kludgeRender\");*/\n\
\n\
		configed = 1;\n\
		return;\n\
	break;\n\
	case \"update\":\n\
		pageObj = nthChild(0);\n\
		pageHeight = arg[1];\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"destroyDoc\":\n\
	case \"destroyDoc_qualified\":\n\
		send(pageObj, \"VW_event\", \"VIEW_OFF\");\n\
		send(pageObj, \"visible\", 0);\n\
		send(pageObj, \"freeSelf\");\n\
		pageObj = 0;\n\
		return;\n\
	break;\n\
	case \"addTool\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(parent(), arg[0], arg[1]);\n\
	break;\n\
	case \"CE_change\":\n\
		/* arg[1] 	CE objPath\n\
		 * arg[2]	CE newData\n\
		 */\n\
		return send(pageObj, arg[0], arg[1], arg[2]);\n\
	break;\n\
	case \"CE_lock\":  /* arg[1] 	CE objPath */\n\
	case \"CE_unlock\":\n\
	case \"editMode\":\n\
	case \"search\":\n\
		return send(pageObj, arg[0], arg[1]);\n\
	break;\n\
	case \"searchByTag\":\n\
		/* arg[1]	english desc of searching field\n\
		 * arg[2]	tag(set)\n\
		 */\n\
		send(\"res.getLineEntry\", \"show\", \n\
			concat(\"Enter keyword to search in \", arg[1], '.'),\n\
			\"\", self(), \"searchByTag_specified\");\n\
		return;\n\
	break;\n\
	case \"searchByTag_specified\":\n\
		/* arg[1]	tag\n\
		 * arg[2]	keyword\n\
		 */\n\
		return send(pageObj, \"searchByTag\", arg[1], arg[2]);\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"-------------\\n\
THIS FACILITY IS NOT YET WORKING\\n\
\");\n\
		send(pageObj, \"outputSGML\");\n\
		print(\"-------------\\n\
\");\n\
		return;\n\
	break;\n\
	case \"mailToAuthor\":\n\
		contactURL = send(pageObj, \"queryAuthor\");\n\
		if (contactURL) {\n\
			res.dialogWithButtons(\"show\", \n\
			 concat(\"The declared author contact is:\\n\
\", \n\
				contactURL),\n\
			 \"Dismiss\", \"\");\n\
		} else {\n\
			res.dialogWithButtons(\"show\", \n\
			 \"Sorry, no author contact declared in the document.\",\n\
			 \"Dismiss\", \"\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"linkSideBar\":\n\
		sideBarURL = arg[1];\n\
		sideBarRatio = arg[2];\n\
		sideBarMaxWidth = arg[3];\n\
		return;\n\
	break;\n\
	case \"showSrc\":\n\
	case \"reload\":\n\
	case \"clone\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	case \"whichPageP\":\n\
		return nthChild(0);\n\
	break;\n\
	case \"heightP\":\n\
		return height();\n\
	break;\n\
	case \"expose\":\n\
/* Trap this event to inhibit the default behavior to re-arrange geometry\n\
 * which would cause uncessary reloading of HTML docs (b/c children would\n\
 * get config messages). We still want to use hpane here because we do want to\n\
 * reload (to reformat) HTML docs if width is changed.\n\
 */\n\
		if (todo) {\n\
			homeDoc = www(\"homeDocP\");\n\
			www(\"show\", homeDoc);\n\
			todo = 0;\n\
		}\n\
		return;\n\
	break;\n\
	case \"historyRecord\":\n\
		send(pageObj, \"historyRecord\");\n\
		return;\n\
	break;\n\
	case \"R\": /* happens sometimes. blah */\n\
	case \"reportNextID\":\n\
		return;\n\
	break;\n\
	case \"getCurrentDocURL\":\n\
		return docURL;\n\
	break;\n\
	case \"getCurrentDocTitle\":\n\
		return title;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		notYetRecordedInitDocInHistory = 1;\n\
		configed = 0;\n\
		todo = 0;\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		/* arg[1]	orig object */\n\
		torn = 1;\n\
		send(nthChild(0), \"torn\", arg[1]);\n\
		pageObj = nthChild(0);\n\
		/* make self reset variables */\n\
		send(self(), \"update\", send(pageObj, \"vspan\"));\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www302[] = "6";
static char _slotValue_www303[] = "black";
static char _slotValue_www304[] = "3";
static char _slotValue_www305[] = "3";
/* END OF OBJ */

static char _slotValue_www307[] = "hpane";
static char _slotValue_www308[] = "www.mesg";
static char _slotValue_www309[] = "www";
static char _slotValue_www310[] = "www.mesg.tf www.ahelp.label";
static char _slotValue_www311[] = "22";
static char _slotValue_www312[] = "2";
static char _slotValue_www313[] = "4";
/* END OF OBJ */

static char _slotValue_www315[] = "txtDisp";
static char _slotValue_www316[] = "www.mesg.tf";
static char _slotValue_www317[] = "www.mesg";
static char _slotValue_www318[] = "\n\
	switch (arg[0]) {\n\
	case \"suggest\":\n\
		if (suggest == 0) return;\n\
		if (get(\"visible\")) {\n\
			if (arg[2] == \"leave\") {\n\
				set(\"content\", \"\");\n\
				render();\n\
				flush();\n\
			} else {\n\
				hint = send(arg[1], \"hint\");\n\
				if (isBlank(hint) == 0) {\n\
					set(\"content\", hint);\n\
					render();\n\
					flush();\n\
				}\n\
			}\n\
			isCleared = 0;\n\
		}\n\
		return;\n\
	break;\n\
	case \"show_progress\":\n\
		/* arg[1]	percent\n\
		 * arg[2]	bytes so far\n\
		 */\n\
		set(\"content\", \n\
			concat(\"Retrieved \", arg[2], \" bytes, \", arg[1], \"%\"));\n\
		send(\"www.doc.tools.httpStat.icon\", \"stat\", arg[1]);\n\
		isCleared = 0;\n\
		return;\n\
	break;\n\
	case \"alert\":\n\
	case \"flash\":\n\
	case \"show\":\n\
	case \"warn\":\n\
		set(\"content\", arg[1]);\n\
		render();\n\
		flush();\n\
		isCleared = 0;\n\
		return;\n\
	break;\n\
	case \"dialog_confirm\":\n\
		/* arg[1] message \n\
		 * ret: yes(1) or no(0)\n\
		 */\n\
		return wwwDialog_confirm(\"confirm\", arg[1]);\n\
	break;\n\
	case \"dialog_prompt_default\":\n\
		/* arg[1] message \n\
		 * arg[2] default\n\
		 * ret: modification of the 'default' string.\n\
		 */\n\
		return wwwDialog_prompt_default(\"prompt\", arg[1], arg[2]);\n\
	break;\n\
	case \"dialog_prompt_password\":\n\
		/* arg[1] message \n\
		 * ret: password\n\
		 */\n\
		return wwwDialog_prompt_password(\"prompt\", arg[1]);\n\
	break;\n\
	case \"dialog_prompt_username_and_password\":\n\
		/* arg[1] message\n\
		 * ret: username'\\n\
'password\n\
		 */\n\
		return wwwDialog_prompt_username_and_password(\"prompt\", arg[1]);\n\
	break;\n\
	case \"clear\":\n\
		if (isCleared == 0) {\n\
			set(\"content\", \"\");\n\
			render();\n\
			flush();\n\
			isCleared = 1;\n\
		}\n\
/*XXX many needless operations*/\n\
		send(\"www.doc.tools.httpStat.icon\", \"clear\");\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
		set(\"cursor\", 0);\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"The active hints/message text field....\";\n\
	break;\n\
	case \"keyPress\":\n\
		return;\n\
	break;\n\
	case \"turnOffSuggest\":\n\
		suggest = 0;\n\
		www.mesg.tf(\"warn\", \"Active help is now off.\");\n\
		return;\n\
	break;\n\
	case \"toggleSuggest\":\n\
		if (suggest == 1) {\n\
			suggest = 0;\n\
			www.mesg.tf(\"warn\", \"Active help is now off.\");\n\
		} else {\n\
			suggest = 1;\n\
			www.mesg.tf(\"warn\", \"Active help is now on.\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
/*		after(50000, \"www.mesg.tf\", \"clear\");*/\n\
		suggest = 0;\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www319[] = "2";
static char _slotValue_www320[] = "1";
static char _slotValue_www321[] = "fixed";
/* END OF OBJ */

static char _slotValue_www323[] = "field";
static char _slotValue_www324[] = "www.progress";
static char _slotValue_www325[] = "www";
static char _slotValue_www326[] = "\n\
	switch (arg[0]) {\n\
	case \"stat\":\n\
		if (arg[1] == -1) xxx = width();\n\
		else xxx = float(arg[1]) / 100.0 * width();\n\
		clearWindow();\n\
		drawFillRect(0, 1, xxx, 3);\n\
		flush();\n\
		return;\n\
	break;\n\
	case \"buttonRelease\":\n\
		print(\"IIIIIIIIIIIIII INTERRUPT TTTTTTTTTTT... sorry, you can't. yet.\\n\
\");\n\
	break;\n\
	case \"clear\":\n\
		xxx = 0;\n\
		clearWindow();\n\
		flush();\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		if (xxx) drawFillRect(0, 1, xxx, 3);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www327[] = "5";
/* END OF OBJ */

static char _slotValue_www329[] = "XBMButton";
static char _slotValue_www330[] = "www.ahelp.label";
static char _slotValue_www331[] = "www.mesg";
static char _slotValue_www332[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		xx = get(\"label\");\n\
		set(\"label\", get(\"content\"));\n\
		set(\"content\", xx);\n\
		render();\n\
		www.mesg.tf(\"toggleSuggest\");\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Click to toggle active helper.\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www333[] = "#define bubble1_width 16\n\
#define bubble1_height 16\n\
static char bubble1_bits[] = {\n\
   0x00, 0x00, 0xe0, 0x07, 0xf8, 0x1f, 0xfc, 0x3f, 0x8c, 0x36, 0xae, 0x74,\n\
   0xae, 0x74, 0xae, 0x72, 0xae, 0x72, 0xac, 0x36, 0x8c, 0x36, 0xf8, 0x1f,\n\
   0xe0, 0x07, 0x78, 0x00, 0x06, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_www334[] = "#define bubble0_width 16\n\
#define bubble0_height 16\n\
static char bubble0_bits[] = {\n\
   0x00, 0x00, 0xe0, 0x07, 0xf8, 0x1f, 0xfc, 0x3f, 0x8c, 0x24, 0xae, 0x76,\n\
   0xae, 0x64, 0xae, 0x76, 0xae, 0x76, 0xac, 0x36, 0x8c, 0x36, 0xf8, 0x1f,\n\
   0xe0, 0x07, 0x78, 0x00, 0x06, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_www335[] = "3";
static char _slotValue_www336[] = "19";
static char _slotValue_www337[] = "16";
static char _slotValue_www338[] = "2";
/* END OF OBJ */

static char _slotValue_www340[] = "hpane";
static char _slotValue_www341[] = "www.url";
static char _slotValue_www342[] = "www";
static char _slotValue_www343[] = "www.url.label www.url.tf www.url.setURL";
static char _slotValue_www344[] = "4";
static char _slotValue_www345[] = "22";
/* END OF OBJ */

static char _slotValue_www347[] = "txtLabel";
static char _slotValue_www348[] = "www.url.label";
static char _slotValue_www349[] = "www.url";
static char _slotValue_www350[] = "URL:";
static char _slotValue_www351[] = "40";
static char _slotValue_www352[] = "any";
static char _slotValue_www353[] = "eastToWest";
/* END OF OBJ */

static char _slotValue_www355[] = "txtEdit";
static char _slotValue_www356[] = "www.url.tf";
static char _slotValue_www357[] = "www.url";
static char _slotValue_www358[] = "\n\
	switch (arg[0]) {\n\
	case \"keyPress\":\n\
		c = key();\n\
		if (c == '\\r') {\n\
			send(\"www\", \"showHistoryDoc\", trimEdge(currentLine()));\n\
			render();\n\
		} else {\n\
			insert(c);\n\
		}\n\
		return;\n\
	break;\n\
	case \"getURLFromClipBuffer\":\n\
		send(\"www\", \"showHistoryDoc\", trimEdge(getSelection()));\n\
		return;\n\
	break;\n\
	case \"appendURLToHome\":\n\
		www.mesg.tf(\"alert\", \n\
			    \"Sorry, can't yet append to home page.\");\n\
		return;\n\
	break;\n\
	case \"show\":\n\
		set(\"content\", trimEdge(arg[1]));\n\
		render();\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		usual();\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"The current document address. Can edit URL there, then press return to follow.\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www359[] = "fixed";
/* END OF OBJ */

static char _slotValue_www361[] = "XBMButton";
static char _slotValue_www362[] = "www.url.setURL";
static char _slotValue_www363[] = "www.url";
static char _slotValue_www364[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		www.url.tf(\"getURLFromClipBuffer\");\n\
	break;\n\
	case \"enter\":\n\
	case \"leave\":\n\
		www.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"hint\":\n\
		return \"Click to read and follow URL from X selection buffer.\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_www365[] = "#define cut_width 16\n\
#define cut_height 16\n\
static char cut_bits[] = {\n\
   0x00, 0x00, 0x10, 0x00, 0x18, 0x00, 0xfc, 0x03, 0x18, 0x0c, 0x10, 0x10,\n\
   0x00, 0x00, 0x38, 0x00, 0x44, 0x78, 0x44, 0xfe, 0x78, 0x0f, 0xc0, 0x00,\n\
   0x78, 0x0f, 0x44, 0xfe, 0x44, 0x78, 0x38, 0x00};\n\
";
static char _slotValue_www366[] = "19";
static char _slotValue_www367[] = "3";
/* END OF OBJ */

static char _slotValue_www369[] = "socket";
static char _slotValue_www370[] = "www_com";
static char _slotValue_www371[] = "\n\
	switch (arg[0]) {\n\
	case \"input\":\n\
		ss = input();\n\
		print(\">>>> input={\", ss, \"}\\n\
\");\n\
		cmd = nthWord(ss, 1);\n\
		print(\">>>> cmd={\", cmd, \"}\\n\
\");\n\
\n\
		if (cmd == \"SAID\") {\n\
			subCmd = nthWord(ss, 3);\n\
			print(\">>>> subCmd={\", subCmd, \"}\\n\
\");\n\
			if (subCmd == \"CEObj\") {\n\
				CEObjPath = nthWord(ss, 4, 999);\n\
				print(\">>>> CEObjPath={\", CEObjPath, \"}\\n\
\");\n\
			} else if (subCmd == \"CENewData\") {\n\
				CENewData = nthWord(ss, 4, 999);\n\
				print(\">>>> CENewData={\", CENewData, \"}\\n\
\");\n\
				print(\">>>> decoded CENewData={\", \n\
					HTTPDecodeURL(CENewData), \"}\\n\
\");\n\
				send(\"www\", \"CE_change\", \n\
					CEObjPath, HTTPDecodeURL(CENewData));\n\
			} else if (subCmd == \"CEObjLock\") {\n\
				CEObjPath = nthWord(ss, 4, 999);\n\
				print(\">>>> CEObjPath={\", CEObjPath, \"}\\n\
\");\n\
				send(\"www\", \"CE_lock\", \n\
					CEObjPath, HTTPDecodeURL(CENewData));\n\
			} else if (subCmd == \"CEObjUnLock\") {\n\
				CEObjPath = nthWord(ss, 4, 999);\n\
				print(\">>>> CEObjPath={\", CEObjPath, \"}\\n\
\");\n\
				send(\"www\", \"CE_unlock\", \n\
					CEObjPath, HTTPDecodeURL(CENewData));\n\
			} else {\n\
				print(\"www_com: unknown sub command\", \n\
					subCmd, \"\\n\
\");\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"output_change\":\n\
		/* arg[1]	newObjPlacePath\n\
		 * arg[2]	newData\n\
		 */\n\
		print(\">>>>>>>>>>>>>>>>>>>>\\n\
\");\n\
		out = concat(\"SAY CEObj: \", arg[1]);\n\
		print(\">>>> output'ing={\", out, \"}\\n\
\");\n\
		output(out);\n\
		out = concat(\"SAY CENewData: \", HTTPEncodeURL(arg[2]));\n\
		print(\">>>> output'ing={\", out, \"}\\n\
\");\n\
		output(out);\n\
		print(\">>>>>>>>>>>>>>>>>>>>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"output_lock\":\n\
		/* arg[1]	newObjPlacePath\n\
		 */\n\
		out = concat(\"SAY CEObjLock: \", arg[1]);\n\
		print(\">>>> output'ing={\", out, \"}\\n\
\");\n\
		output(out);\n\
		return;\n\
	break;\n\
	case \"output_unlock\":\n\
		/* arg[1]	newObjPlacePath\n\
		 */\n\
		out = concat(\"SAY CEObjUnLock: \", arg[1]);\n\
		print(\">>>> output'ing={\", out, \"}\\n\
\");\n\
		output(out);\n\
		return;\n\
	break;\n\
	case \"output\":\n\
		print(\">>>> output'ing={\", arg[1], \"}\\n\
\");\n\
		output(arg[1]);\n\
		return;\n\
	break;\n\
	case \"connect\":\n\
		print(\">>>> connecting to host={\", arg[1], \"}\\n\
\");\n\
		print(\">>>> connecting to port={\", arg[2], \"}\\n\
\");\n\
		set(\"host\", arg[1]);\n\
		set(\"port\", arg[2]);\n\
		set(\"outDelimStr\", \"\\r\\n\
\");\n\
		set(\"inDelimStr1\", '\\n\
');\n\
		startClient();\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
/*		send(self(), \"connect\", \"localhost\", 80);*/\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_www[] = {
    {"border", _slotValue_www0},
    {"class", _slotValue_www1},
    {"name", _slotValue_www2},
    {"parent", _slotValue_www3},
    {"children", _slotValue_www4},
    {"x", _slotValue_www5},
    {"y", _slotValue_www6},
    {"width", _slotValue_www7},
    {"height", _slotValue_www8},
    {"script", _slotValue_www9},
    {(char*)0, (char*)1},
    {"class", _slotValue_www11},
    {"name", _slotValue_www12},
    {"parent", _slotValue_www13},
    {"children", _slotValue_www14},
    {"border", _slotValue_www15},
    {"maxHeight", _slotValue_www16},
    {"gapH", _slotValue_www17},
    {"gapV", _slotValue_www18},
    {(char*)0, (char*)1},
    {"class", _slotValue_www20},
    {"gapV", _slotValue_www21},
    {"gapH", _slotValue_www22},
    {"name", _slotValue_www23},
    {"parent", _slotValue_www24},
    {"label", _slotValue_www25},
    {"script", _slotValue_www26},
    {"menuConfig", _slotValue_www27},
    {"maxWidth", _slotValue_www28},
    {"font", _slotValue_www29},
    {"gapH", _slotValue_www30},
    {(char*)0, (char*)1},
    {"class", _slotValue_www32},
    {"gapV", _slotValue_www33},
    {"gapH", _slotValue_www34},
    {"name", _slotValue_www35},
    {"parent", _slotValue_www36},
    {"label", _slotValue_www37},
    {"menuConfig", _slotValue_www38},
    {"minWidth", _slotValue_www39},
    {"maxWidth", _slotValue_www40},
    {"font", _slotValue_www41},
    {"gapH", _slotValue_www42},
    {(char*)0, (char*)1},
    {"class", _slotValue_www44},
    {"name", _slotValue_www45},
    {"parent", _slotValue_www46},
    {"gapV", _slotValue_www47},
    {(char*)0, (char*)1},
    {"class", _slotValue_www49},
    {"name", _slotValue_www50},
    {"parent", _slotValue_www51},
    {"label", _slotValue_www52},
    {"menuConfig", _slotValue_www53},
    {"maxWidth", _slotValue_www54},
    {"gapV", _slotValue_www55},
    {"gapH", _slotValue_www56},
    {"font", _slotValue_www57},
    {(char*)0, (char*)1},
    {"class", _slotValue_www59},
    {"name", _slotValue_www60},
    {"parent", _slotValue_www61},
    {"label", _slotValue_www62},
    {"menuConfig", _slotValue_www63},
    {"maxWidth", _slotValue_www64},
    {"gapV", _slotValue_www65},
    {"gapH", _slotValue_www66},
    {"font", _slotValue_www67},
    {(char*)0, (char*)1},
    {"class", _slotValue_www69},
    {"name", _slotValue_www70},
    {"parent", _slotValue_www71},
    {"children", _slotValue_www72},
    {"script", _slotValue_www73},
    {"gapH", _slotValue_www74},
    {(char*)0, (char*)1},
    {"class", _slotValue_www76},
    {"name", _slotValue_www77},
    {"parent", _slotValue_www78},
    {"children", _slotValue_www79},
    {"script", _slotValue_www80},
    {"maxHeight", _slotValue_www81},
    {"gapH", _slotValue_www82},
    {(char*)0, (char*)1},
    {"class", _slotValue_www84},
    {"name", _slotValue_www85},
    {"parent", _slotValue_www86},
    {"script", _slotValue_www87},
    {"content", _slotValue_www88},
    {"border", _slotValue_www89},
    {"BDColor", _slotValue_www90},
    {"gapV", _slotValue_www91},
    {"gapH", _slotValue_www92},
    {"font", _slotValue_www93},
    {"format", _slotValue_www94},
    {(char*)0, (char*)1},
    {"class", _slotValue_www96},
    {"parent", _slotValue_www97},
    {"name", _slotValue_www98},
    {"children", _slotValue_www99},
    {"script", _slotValue_www100},
    {"gapH", _slotValue_www101},
    {"maxHeight", _slotValue_www102},
    {(char*)0, (char*)1},
    {"class", _slotValue_www104},
    {"name", _slotValue_www105},
    {"parent", _slotValue_www106},
    {"script", _slotValue_www107},
    {"gapH", _slotValue_www108},
    {"gapV", _slotValue_www109},
    {(char*)0, (char*)1},
    {"class", _slotValue_www111},
    {"name", _slotValue_www112},
    {"parent", _slotValue_www113},
    {"children", _slotValue_www114},
    {"maxWidth", _slotValue_www115},
    {"minHeight", _slotValue_www116},
    {"gapH", _slotValue_www117},
    {"gapV", _slotValue_www118},
    {(char*)0, (char*)1},
    {"class", _slotValue_www120},
    {"name", _slotValue_www121},
    {"parent", _slotValue_www122},
    {"script", _slotValue_www123},
    {"label", _slotValue_www124},
    {"minWidth", _slotValue_www125},
    {"gapH", _slotValue_www126},
    {"gapV", _slotValue_www127},
    {(char*)0, (char*)1},
    {"class", _slotValue_www129},
    {"name", _slotValue_www130},
    {"parent", _slotValue_www131},
    {"script", _slotValue_www132},
    {"label", _slotValue_www133},
    {"minWidth", _slotValue_www134},
    {"gapH", _slotValue_www135},
    {"gapV", _slotValue_www136},
    {(char*)0, (char*)1},
    {"class", _slotValue_www138},
    {"name", _slotValue_www139},
    {"parent", _slotValue_www140},
    {"script", _slotValue_www141},
    {"label", _slotValue_www142},
    {"minWidth", _slotValue_www143},
    {"gapH", _slotValue_www144},
    {"gapV", _slotValue_www145},
    {(char*)0, (char*)1},
    {"class", _slotValue_www147},
    {"name", _slotValue_www148},
    {"parent", _slotValue_www149},
    {"script", _slotValue_www150},
    {"label", _slotValue_www151},
    {"minWidth", _slotValue_www152},
    {"gapH", _slotValue_www153},
    {"gapV", _slotValue_www154},
    {(char*)0, (char*)1},
    {"class", _slotValue_www156},
    {"name", _slotValue_www157},
    {"parent", _slotValue_www158},
    {"script", _slotValue_www159},
    {"label", _slotValue_www160},
    {"minWidth", _slotValue_www161},
    {"gapH", _slotValue_www162},
    {"gapV", _slotValue_www163},
    {(char*)0, (char*)1},
    {"class", _slotValue_www165},
    {"name", _slotValue_www166},
    {"parent", _slotValue_www167},
    {"script", _slotValue_www168},
    {"label", _slotValue_www169},
    {"minWidth", _slotValue_www170},
    {"gapH", _slotValue_www171},
    {"gapV", _slotValue_www172},
    {(char*)0, (char*)1},
    {"class", _slotValue_www174},
    {"name", _slotValue_www175},
    {"parent", _slotValue_www176},
    {"children", _slotValue_www177},
    {"maxWidth", _slotValue_www178},
    {"minHeight", _slotValue_www179},
    {"gapH", _slotValue_www180},
    {"gapV", _slotValue_www181},
    {(char*)0, (char*)1},
    {"class", _slotValue_www183},
    {"parent", _slotValue_www184},
    {"name", _slotValue_www185},
    {"script", _slotValue_www186},
    {"label", _slotValue_www187},
    {"gapV", _slotValue_www188},
    {"maxHeight", _slotValue_www189},
    {"border", _slotValue_www190},
    {(char*)0, (char*)1},
    {"class", _slotValue_www192},
    {"name", _slotValue_www193},
    {"parent", _slotValue_www194},
    {"children", _slotValue_www195},
    {"gapH", _slotValue_www196},
    {"script", _slotValue_www197},
    {(char*)0, (char*)1},
    {"class", _slotValue_www199},
    {"name", _slotValue_www200},
    {"parent", _slotValue_www201},
    {"script", _slotValue_www202},
    {"maxWidth", _slotValue_www203},
    {(char*)0, (char*)1},
    {"class", _slotValue_www205},
    {"name", _slotValue_www206},
    {"parent", _slotValue_www207},
    {"children", _slotValue_www208},
    {"maxWidth", _slotValue_www209},
    {(char*)0, (char*)1},
    {"class", _slotValue_www211},
    {"name", _slotValue_www212},
    {"parent", _slotValue_www213},
    {"script", _slotValue_www214},
    {"label", _slotValue_www215},
    {"border", _slotValue_www216},
    {"width", _slotValue_www217},
    {"height", _slotValue_www218},
    {"maxWidth", _slotValue_www219},
    {"maxHeight", _slotValue_www220},
    {(char*)0, (char*)1},
    {"class", _slotValue_www222},
    {"name", _slotValue_www223},
    {"parent", _slotValue_www224},
    {"script", _slotValue_www225},
    {"label", _slotValue_www226},
    {"gapH", _slotValue_www227},
    {"gapV", _slotValue_www228},
    {"border", _slotValue_www229},
    {"width", _slotValue_www230},
    {"height", _slotValue_www231},
    {"maxWidth", _slotValue_www232},
    {"maxHeight", _slotValue_www233},
    {(char*)0, (char*)1},
    {"class", _slotValue_www235},
    {"name", _slotValue_www236},
    {"parent", _slotValue_www237},
    {"shownNotify", _slotValue_www238},
    {"script", _slotValue_www239},
    {(char*)0, (char*)1},
    {"class", _slotValue_www241},
    {"name", _slotValue_www242},
    {"parent", _slotValue_www243},
    {"shownNotify", _slotValue_www244},
    {"script", _slotValue_www245},
    {"direction", _slotValue_www246},
    {"maxHeight", _slotValue_www247},
    {(char*)0, (char*)1},
    {"class", _slotValue_www249},
    {"parent", _slotValue_www250},
    {"name", _slotValue_www251},
    {"children", _slotValue_www252},
    {"script", _slotValue_www253},
    {"width", _slotValue_www254},
    {"height", _slotValue_www255},
    {"x", _slotValue_www256},
    {"y", _slotValue_www257},
    {"width", _slotValue_www258},
    {"gapH", _slotValue_www259},
    {"gapV", _slotValue_www260},
    {(char*)0, (char*)1},
    {"class", _slotValue_www262},
    {"parent", _slotValue_www263},
    {"name", _slotValue_www264},
    {"children", _slotValue_www265},
    {"script", _slotValue_www266},
    {"gapH", _slotValue_www267},
    {"maxHeight", _slotValue_www268},
    {(char*)0, (char*)1},
    {"class", _slotValue_www270},
    {"parent", _slotValue_www271},
    {"name", _slotValue_www272},
    {"label", _slotValue_www273},
    {"script", _slotValue_www274},
    {"font", _slotValue_www275},
    {"gapH", _slotValue_www276},
    {(char*)0, (char*)1},
    {"class", _slotValue_www278},
    {"parent", _slotValue_www279},
    {"name", _slotValue_www280},
    {"label", _slotValue_www281},
    {"script", _slotValue_www282},
    {"font", _slotValue_www283},
    {"gapH", _slotValue_www284},
    {(char*)0, (char*)1},
    {"class", _slotValue_www286},
    {"name", _slotValue_www287},
    {"parent", _slotValue_www288},
    {"shownDepend", _slotValue_www289},
    {"script", _slotValue_www290},
    {"width", _slotValue_www291},
    {"height", _slotValue_www292},
    {"gapH", _slotValue_www293},
    {"gapV", _slotValue_www294},
    {"border", _slotValue_www295},
    {(char*)0, (char*)1},
    {"class", _slotValue_www297},
    {"name", _slotValue_www298},
    {"parent", _slotValue_www299},
    {"shownDepend", _slotValue_www300},
    {"script", _slotValue_www301},
    {"border", _slotValue_www302},
    {"BDColor", _slotValue_www303},
    {"gapH", _slotValue_www304},
    {"gapV", _slotValue_www305},
    {(char*)0, (char*)1},
    {"class", _slotValue_www307},
    {"name", _slotValue_www308},
    {"parent", _slotValue_www309},
    {"children", _slotValue_www310},
    {"maxHeight", _slotValue_www311},
    {"gapH", _slotValue_www312},
    {"gapV", _slotValue_www313},
    {(char*)0, (char*)1},
    {"class", _slotValue_www315},
    {"name", _slotValue_www316},
    {"parent", _slotValue_www317},
    {"script", _slotValue_www318},
    {"gapH", _slotValue_www319},
    {"verbatim", _slotValue_www320},
    {"font", _slotValue_www321},
    {(char*)0, (char*)1},
    {"class", _slotValue_www323},
    {"name", _slotValue_www324},
    {"parent", _slotValue_www325},
    {"script", _slotValue_www326},
    {"maxHeight", _slotValue_www327},
    {(char*)0, (char*)1},
    {"class", _slotValue_www329},
    {"name", _slotValue_www330},
    {"parent", _slotValue_www331},
    {"script", _slotValue_www332},
    {"content", _slotValue_www333},
    {"label", _slotValue_www334},
    {"border", _slotValue_www335},
    {"maxWidth", _slotValue_www336},
    {"maxHeight", _slotValue_www337},
    {"gapH", _slotValue_www338},
    {(char*)0, (char*)1},
    {"class", _slotValue_www340},
    {"name", _slotValue_www341},
    {"parent", _slotValue_www342},
    {"children", _slotValue_www343},
    {"gapH", _slotValue_www344},
    {"maxHeight", _slotValue_www345},
    {(char*)0, (char*)1},
    {"class", _slotValue_www347},
    {"name", _slotValue_www348},
    {"parent", _slotValue_www349},
    {"label", _slotValue_www350},
    {"maxWidth", _slotValue_www351},
    {"font", _slotValue_www352},
    {"paneConfig", _slotValue_www353},
    {(char*)0, (char*)1},
    {"class", _slotValue_www355},
    {"name", _slotValue_www356},
    {"parent", _slotValue_www357},
    {"script", _slotValue_www358},
    {"font", _slotValue_www359},
    {(char*)0, (char*)1},
    {"class", _slotValue_www361},
    {"name", _slotValue_www362},
    {"parent", _slotValue_www363},
    {"script", _slotValue_www364},
    {"label", _slotValue_www365},
    {"maxWidth", _slotValue_www366},
    {"border", _slotValue_www367},
    {(char*)0, (char*)1},
    {"class", _slotValue_www369},
    {"name", _slotValue_www370},
    {"script", _slotValue_www371},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwAbout0[] = "hpane";
static char _slotValue_wwwAbout1[] = "wwwAbout";
static char _slotValue_wwwAbout2[] = "wwwAbout.icon wwwAbout.fld";
static char _slotValue_wwwAbout3[] = "\n\
	switch (arg[0]) {\n\
	case \"visible\":\n\
		if (arg[1] == 1) {\n\
			if (get(\"visible\") == 1) {\n\
				set(\"visible\", 0);\n\
				return;\n\
			}\n\
			vwWinPos = send(\"www\", \"winPosition\");\n\
			set(\"x\", vwWinPos[0] + 20);\n\
			set(\"y\", vwWinPos[1] + 130);\n\
			send(\"wwwAbout.fld.states\", \"inView\", 1);\n\
			send(\"wwwAbout.fld.states\", \"tic\");\n\
		}\n\
	break;\n\
	case \"dismiss\":\n\
		send(\"wwwAbout.fld.states\", \"inView\", 0);\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwAbout4[] = "500";
static char _slotValue_wwwAbout5[] = "300";
static char _slotValue_wwwAbout6[] = "500";
static char _slotValue_wwwAbout7[] = "500";
static char _slotValue_wwwAbout8[] = "300";
static char _slotValue_wwwAbout9[] = "300";
static char _slotValue_wwwAbout10[] = "3";
/* END OF OBJ */

static char _slotValue_wwwAbout12[] = "XBM";
static char _slotValue_wwwAbout13[] = "wwwAbout.icon";
static char _slotValue_wwwAbout14[] = "wwwAbout";
static char _slotValue_wwwAbout15[] = "#define violaDemo_width 104\n\
#define violaDemo_height 132\n\
static char violaDemo_bits[] = {\n\
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x16,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0x80,0x5e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0xba,0xaf,0x6e,0x00,0x00,0x00,0x00,0xa0,0x00,0x00,0x00,0x00,\n\
 0x00,0xee,0xff,0xfb,0x00,0x00,0x00,0x00,0x60,0x01,0x00,0x00,0x00,0x00,0xff,\n\
 0xff,0x7f,0x01,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0xba,0x5f,0xb7,\n\
 0x00,0x00,0x00,0x00,0xe8,0x02,0x00,0x00,0x00,0x00,0xa4,0xae,0x54,0x01,0x00,\n\
 0xba,0xbb,0xfb,0x00,0x00,0x00,0x00,0x00,0x88,0x1e,0x01,0x00,0x00,0xee,0xee,\n\
 0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x00,0x00,0x00,0xff,0xff,0x7f,0x01,\n\
 0x00,0x00,0x00,0x00,0x80,0x2e,0x24,0x00,0x80,0xba,0x7f,0xfb,0x02,0x00,0x00,\n\
 0x00,0x00,0xbe,0xdf,0x55,0x01,0xa0,0xa2,0xaf,0xea,0x00,0x00,0x00,0x00,0x00,\n\
 0xf5,0x7e,0x7f,0x00,0x60,0x09,0x1d,0xf8,0x00,0x00,0x00,0x00,0x00,0xff,0xff,\n\
 0xff,0x01,0xf0,0x00,0x0f,0xe0,0x02,0x00,0x00,0x00,0x00,0xac,0xbf,0x55,0x00,\n\
 0xd0,0x02,0x2d,0xd0,0x00,0x00,0x00,0x00,0x00,0xaa,0xaf,0xaa,0x00,0xf0,0x00,\n\
 0x0f,0xf0,0x02,0x00,0x00,0x00,0x00,0x40,0x2e,0x00,0x00,0xe0,0x02,0x2e,0xd0,\n\
 0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x70,0x81,0x0e,0xf0,0x01,0x00,\n\
 0x00,0x00,0x00,0x00,0x2e,0x00,0x00,0xe0,0x00,0x2a,0xa4,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x17,0x00,0x00,0xf0,0x02,0xaa,0x55,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x0d,0x00,0x00,0xd0,0x00,0xe8,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x00,\n\
 0x00,0xf0,0x02,0xd0,0x2f,0x00,0x00,0x00,0x00,0x00,0x00,0x0d,0x00,0x00,0xa0,\n\
 0x00,0x60,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x2f,0x00,0x00,0x40,0x00,0x50,\n\
 0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0x2f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x40,0x0d,0x00,0x00,0x28,0x00,0x40,0x4a,0x00,0x00,0x00,0x00,0xa0,\n\
 0x5b,0x2f,0x00,0x00,0xaa,0xf7,0x5e,0x55,0x00,0x00,0x00,0x00,0xe0,0xfe,0x0f,\n\
 0x00,0x00,0xfd,0xde,0xfb,0x7f,0x01,0x00,0x00,0x00,0xf0,0xff,0x2f,0x00,0x00,\n\
 0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0xe8,0xff,0x0f,0x00,0x00,0xaa,0xb5,\n\
 0x56,0x55,0x01,0x00,0x00,0xa0,0xfb,0xff,0x0f,0x00,0x00,0xaa,0xaa,0xaa,0xaa,\n\
 0x00,0x00,0x00,0xe0,0xfe,0xff,0x2f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0xf0,0xff,0xff,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe8,\n\
 0xdf,0xde,0x2f,0x00,0x00,0x00,0x00,0xaa,0x02,0x00,0x00,0x00,0xfa,0x5f,0x51,\n\
 0x0f,0x00,0x00,0x00,0x00,0x55,0x0d,0x00,0x00,0x00,0xfe,0x2f,0x04,0x0d,0x00,\n\
 0x00,0x00,0x00,0xf6,0x16,0x00,0x00,0x00,0xff,0x0f,0x00,0x1f,0x00,0x00,0x00,\n\
 0x80,0xfe,0x0f,0x00,0x00,0x00,0xdd,0x16,0x00,0x0d,0x00,0x00,0x00,0x80,0x6e,\n\
 0x57,0x00,0x00,0x00,0xaf,0x02,0x00,0x2f,0x00,0x00,0x00,0x50,0xa9,0x54,0x01,\n\
 0x00,0x00,0x1e,0x08,0x00,0x0e,0x00,0x00,0x00,0xe0,0x02,0x68,0x00,0x00,0x00,\n\
 0x0d,0x00,0x80,0x2e,0x00,0x00,0x00,0xe8,0x00,0xd0,0x01,0x00,0x80,0x2e,0x00,\n\
 0x00,0x0a,0x00,0x00,0x00,0x70,0x01,0xf0,0x00,0x00,0xa0,0x0f,0x00,0x00,0x12,\n\
 0x00,0x00,0x00,0xe0,0x00,0xd0,0x01,0x00,0xe0,0x2f,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0xf0,0x01,0xf0,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x50,\n\
 0x01,0xd0,0x02,0x00,0xd0,0x15,0x00,0x00,0x04,0x00,0x00,0x00,0xe0,0x24,0x69,\n\
 0x01,0x00,0xf0,0x05,0x00,0x00,0x0a,0x00,0x00,0x00,0x20,0xab,0x2a,0x00,0x00,\n\
 0x60,0x01,0x00,0x00,0x15,0x00,0x00,0x00,0x80,0xde,0x97,0x00,0x00,0xd0,0x02,\n\
 0x00,0x00,0x0f,0x00,0x00,0x00,0x00,0xfd,0x0f,0x00,0x00,0xf0,0x00,0x00,0x00,\n\
 0x14,0x00,0x00,0x00,0x00,0x76,0x2b,0x00,0x00,0xe0,0x01,0x00,0x00,0x0a,0x00,\n\
 0x00,0x00,0x00,0x54,0x05,0x00,0x00,0x70,0x01,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0xf0,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x4a,0x4a,0x00,\n\
 0x00,0xe0,0x05,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xaa,0x2a,0x00,0x00,0xf0,\n\
 0x2f,0x00,0x00,0x00,0x00,0x00,0x60,0xd1,0xfb,0xf7,0x02,0x00,0xe0,0x17,0x00,\n\
 0x00,0x00,0x00,0x00,0xf0,0xf0,0xff,0xff,0x00,0x00,0xd0,0x2e,0x00,0x00,0x00,\n\
 0x00,0x00,0xa0,0xa0,0x5d,0x5d,0x01,0x00,0x40,0x5f,0x00,0x00,0x16,0xa0,0xbb,\n\
 0x40,0xa1,0x52,0xa5,0x00,0x00,0x80,0xfe,0x00,0x00,0x05,0xd0,0x6e,0x01,0x00,\n\
 0x04,0x10,0x00,0x00,0x00,0xff,0x02,0x00,0x1e,0xf0,0xff,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0xfa,0x00,0x00,0x05,0xa0,0x7b,0x25,0x01,0x00,0x00,0x00,0x00,\n\
 0x00,0xea,0x02,0x00,0x2a,0x40,0x4a,0xd5,0x16,0x00,0x00,0x00,0x00,0x00,0xf8,\n\
 0x00,0x00,0x00,0x80,0x00,0xbf,0x0d,0x00,0x00,0x00,0x00,0x00,0x60,0x01,0x00,\n\
 0x00,0x00,0x80,0xfe,0x2f,0x00,0x00,0x00,0x00,0x00,0xd0,0x01,0x00,0x00,0x00,\n\
 0x00,0xea,0x0b,0x84,0x04,0x00,0x00,0x00,0xf0,0x07,0x00,0x00,0x00,0x00,0x14,\n\
 0xda,0xb5,0x0a,0x00,0x00,0x00,0xd0,0x2d,0x00,0x00,0x00,0x00,0xa0,0xb0,0xef,\n\
 0x17,0x00,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,0x00,0xe0,0xff,0x0f,0x00,\n\
 0x00,0x00,0xe0,0x2f,0x00,0x00,0x00,0x00,0x00,0xd0,0xba,0x5f,0x00,0x00,0x00,\n\
 0xf0,0x0f,0x00,0x06,0x00,0x00,0x00,0xa0,0x4a,0xb7,0x17,0x00,0x00,0xd0,0x2f,\n\
 0x00,0x2d,0x00,0x00,0x00,0x00,0xa0,0x7e,0x05,0x00,0x00,0xf0,0x0f,0x00,0x0e,\n\
 0x00,0x00,0x00,0x00,0x00,0xfd,0x1f,0x00,0x00,0xe8,0x17,0x00,0x15,0x00,0x00,\n\
 0x00,0x00,0x00,0xff,0x07,0x00,0x00,0xfa,0x02,0x00,0x0a,0x00,0x00,0x00,0x00,\n\
 0xd0,0xff,0x0a,0x00,0x00,0xfd,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xff,\n\
 0x01,0x00,0x00,0x7f,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xe8,0xff,0x00,0x00,\n\
 0x80,0xde,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xf2,0xbb,0x00,0x00,0xa0,0x2f,\n\
 0x00,0x00,0x00,0x00,0x00,0x00,0x5e,0xed,0x26,0x01,0x00,0xe0,0x2e,0x00,0x00,\n\
 0x00,0x00,0x00,0x00,0xf5,0xfb,0x41,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0xff,0xff,0x00,0x00,0x00,0xe8,0x2b,0x00,0x00,0x00,0x00,0x00,0x40,\n\
 0xfd,0x5e,0x01,0x00,0x00,0xfa,0x0a,0x00,0x00,0x00,0x00,0xe0,0x5e,0xff,0x51,\n\
 0x00,0x00,0x00,0xfe,0x02,0x00,0x00,0x00,0x00,0x50,0xbb,0xff,0x02,0x00,0x00,\n\
 0x00,0x7f,0x01,0x00,0x00,0x00,0x00,0xf0,0xff,0xff,0x00,0x00,0x00,0x00,0xdd,\n\
 0x00,0x00,0x00,0x00,0x00,0xe8,0xff,0xbf,0x02,0x00,0x00,0x00,0x2f,0x00,0x00,\n\
 0x00,0xa0,0xbb,0xfb,0xff,0x5f,0x00,0x00,0x00,0x00,0x9e,0x00,0x00,0x00,0xe0,\n\
 0xee,0xee,0xff,0x2f,0x00,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,0xf0,0xff,0xff,\n\
 0xff,0x0f,0x00,0x00,0x00,0x00,0x2f,0x00,0x00,0x00,0xd0,0xff,0xff,0xff,0x0b,\n\
 0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0xf0,0xff,0xff,0x1f,0x0a,0x00,0x00,\n\
 0x00,0x00,0x0f,0x00,0x00,0x00,0xe0,0xff,0xff,0xaf,0x00,0x00,0x00,0x00,0x00,\n\
 0x1d,0x00,0x00,0x00,0xf0,0xff,0xff,0x0f,0x00,0x00,0x00,0x00,0x00,0x17,0x00,\n\
 0x00,0x00,0xd0,0xff,0xff,0x0b,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,\n\
 0xf0,0xff,0x1f,0x0a,0x00,0x00,0x00,0x00,0x00,0x2f,0x00,0x00,0x00,0xe0,0xff,\n\
 0xaf,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0xf0,0xff,0x0f,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0x17,0x00,0x00,0x00,0xe0,0xff,0x0b,0x40,0x40,0x00,\n\
 0x00,0x00,0x00,0x2e,0x00,0x00,0x00,0xf0,0x1f,0x0a,0x50,0x5f,0x00,0x00,0x00,\n\
 0x00,0x0f,0x00,0x00,0x00,0xd0,0xaf,0x00,0xe0,0xba,0x01,0x00,0x00,0x00,0x2d,\n\
 0x00,0x00,0x00,0xf0,0x0f,0x00,0xd0,0xff,0x00,0x00,0x00,0x00,0x1f,0x00,0x00,\n\
 0x00,0xa0,0x0b,0x00,0xf0,0xff,0x02,0x00,0x00,0x00,0x6e,0x00,0x00,0x00,0x40,\n\
 0x0a,0x00,0xd0,0xff,0x00,0x00,0x00,0x00,0xbf,0x01,0x00,0x00,0x80,0x00,0x00,\n\
 0xf0,0xff,0x02,0x00,0x00,0x00,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xff,\n\
 0x00,0x00,0x00,0x00,0xff,0x02,0x00,0x00,0x00,0x00,0x00,0xf0,0xff,0x02,0x00,\n\
 0x00,0x00,0xfd,0x00,0x00,0x00,0x00,0x00,0x00,0xd0,0xff,0x00,0x00,0x00,0x00,\n\
 0xff,0x02,0x00,0x00,0x00,0x00,0x00,0xf0,0xff,0x02,0x00,0x00,0x00,0xfe,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0xe0,0xff,0x00,0x00,0x00,0x00,0xfd,0x01,0x00,0x00,\n\
 0x00,0x00,0x00,0xf8,0x7f,0x01,0x00,0x00,0x00,0xf4,0x16,0x00,0x00,0x00,0x00,\n\
 0x00,0xea,0x5f,0x00,0x00,0x00,0x00,0xe8,0x07,0x00,0x00,0x00,0x00,0x00,0xfd,\n\
 0x2f,0x00,0x00,0x00,0x00,0xd0,0x1f,0x00,0x00,0x00,0x00,0x00,0xff,0x0f,0x00,\n\
 0x00,0x00,0x00,0xe0,0x2f,0x00,0x00,0x00,0x00,0x80,0xfe,0x17,0x00,0x00,0x00,\n\
 0x00,0x20,0x5f,0x00,0x00,0x00,0x00,0xa0,0xff,0x09,0x00,0x00,0x00,0x00,0x80,\n\
 0xfe,0x00,0x00,0x00,0x00,0xd0,0xff,0x02,0x00,0x00,0x00,0x00,0x00,0x7d,0x01,\n\
 0x00,0x00,0x00,0xf0,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x05,0x00,0x00,\n\
 0x00,0xe8,0x6d,0x01,0x00,0x00,0x00,0x00,0x00,0xe9,0x75,0x00,0x00,0x00,0xfa,\n\
 0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xaf,0x01,0x00,0x00,0xee,0x82,0x00,\n\
 0x00,0x00,0x00,0x00,0x00,0xe8,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,\n\
 0x00,0x00,0x00,0xa0,0xfa,0x05,0x00,0x80,0xba,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0x00,0x40,0xf5,0xb5,0xbb,0xbb,0x52,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n\
 0xe8,0xef,0xee,0x6e,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xff,\n\
 0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd0,0xff,0xff,0xff,\n\
 0x02,0x00,0x00,0x00,0x00,0x00};\n\
";
static char _slotValue_wwwAbout16[] = "106";
static char _slotValue_wwwAbout17[] = "5";
static char _slotValue_wwwAbout18[] = "5";
static char _slotValue_wwwAbout19[] = "6";
static char _slotValue_wwwAbout20[] = "black";
/* END OF OBJ */

static char _slotValue_wwwAbout22[] = "vpane";
static char _slotValue_wwwAbout23[] = "wwwAbout.fld";
static char _slotValue_wwwAbout24[] = "wwwAbout";
static char _slotValue_wwwAbout25[] = "wwwAbout.fld.top wwwAbout.fld.bar1 wwwAbout.fld.help wwwAbout.fld.bar2 wwwAbout.fld.states";
static char _slotValue_wwwAbout26[] = "5";
static char _slotValue_wwwAbout27[] = "5";
/* END OF OBJ */

static char _slotValue_wwwAbout29[] = "hpane";
static char _slotValue_wwwAbout30[] = "wwwAbout.fld.top";
static char _slotValue_wwwAbout31[] = "wwwAbout.fld";
static char _slotValue_wwwAbout32[] = "wwwAbout.fld.top.txt wwwAbout.fld.top.dismiss";
static char _slotValue_wwwAbout33[] = "170";
static char _slotValue_wwwAbout34[] = "5";
static char _slotValue_wwwAbout35[] = "10";
/* END OF OBJ */

static char _slotValue_wwwAbout37[] = "txtDisp";
static char _slotValue_wwwAbout38[] = "wwwAbout.fld.top";
static char _slotValue_wwwAbout39[] = "wwwAbout.fld.top.txt";
static char _slotValue_wwwAbout40[] = "normal";
static char _slotValue_wwwAbout41[] = "\\f(2)Viola World Wide Web \n\
Hypermedia Toolkit & Browser\\f(1)\n\
\n\
Version 3.3\n\
\n\
By Pei Y. Wei (\\f(0)wei@ora.com\\f(1)), \n\
O'Reilly & Associates, Inc.\n\
\n\
Copyright 1989-1995, all rights reserved.\n\
";
/* END OF OBJ */

static char _slotValue_wwwAbout43[] = "txtButton";
static char _slotValue_wwwAbout44[] = "wwwAbout.fld.top";
static char _slotValue_wwwAbout45[] = "wwwAbout.fld.top.dismiss";
static char _slotValue_wwwAbout46[] = "OK";
static char _slotValue_wwwAbout47[] = "normal";
static char _slotValue_wwwAbout48[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"wwwAbout\", \"dismiss\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwAbout49[] = "80";
static char _slotValue_wwwAbout50[] = "25";
static char _slotValue_wwwAbout51[] = "25";
/* END OF OBJ */

static char _slotValue_wwwAbout53[] = "field";
static char _slotValue_wwwAbout54[] = "wwwAbout.fld";
static char _slotValue_wwwAbout55[] = "wwwAbout.fld.bar1";
static char _slotValue_wwwAbout56[] = "grey45";
static char _slotValue_wwwAbout57[] = "black";
static char _slotValue_wwwAbout58[] = "1";
static char _slotValue_wwwAbout59[] = "1";
static char _slotValue_wwwAbout60[] = "6";
/* END OF OBJ */

static char _slotValue_wwwAbout62[] = "txtDisp";
static char _slotValue_wwwAbout63[] = "wwwAbout.fld";
static char _slotValue_wwwAbout64[] = "wwwAbout.fld.help";
static char _slotValue_wwwAbout65[] = "Contact \\f(0)viola@ora.com\\f(1) for support on this software.";
static char _slotValue_wwwAbout66[] = "normal";
static char _slotValue_wwwAbout67[] = "18";
static char _slotValue_wwwAbout68[] = "5";
static char _slotValue_wwwAbout69[] = "7";
/* END OF OBJ */

static char _slotValue_wwwAbout71[] = "field";
static char _slotValue_wwwAbout72[] = "wwwAbout.fld";
static char _slotValue_wwwAbout73[] = "wwwAbout.fld.bar2";
static char _slotValue_wwwAbout74[] = "grey45";
static char _slotValue_wwwAbout75[] = "black";
static char _slotValue_wwwAbout76[] = "1";
static char _slotValue_wwwAbout77[] = "1";
static char _slotValue_wwwAbout78[] = "6";
/* END OF OBJ */

static char _slotValue_wwwAbout80[] = "txtDisp";
static char _slotValue_wwwAbout81[] = "wwwAbout.fld";
static char _slotValue_wwwAbout82[] = "wwwAbout.fld.states";
static char _slotValue_wwwAbout83[] = "Beta Release Status.";
static char _slotValue_wwwAbout84[] = "\n\
	switch (arg[0]) {\n\
	case \"tic\":\n\
		if (inView == 0) return;\n\
		set(\"FGColor\", \"black\");\n\
		render();\n\
		after(1000, self(), \"toc\");\n\
		return;\n\
	break;\n\
	case \"toc\":\n\
		if (inView == 0) return;\n\
		set(\"FGColor\", \"white\");\n\
		render();\n\
		after(1000, self(), \"tic\");\n\
		return;\n\
	break;\n\
	case \"inView\":\n\
		inView = arg[1];\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwAbout85[] = "normal";
static char _slotValue_wwwAbout86[] = "5";
static char _slotValue_wwwAbout87[] = "7";
/* END OF FILE */

static SlotStruct objDesc_wwwAbout[] = {
    {"class", _slotValue_wwwAbout0},
    {"name", _slotValue_wwwAbout1},
    {"children", _slotValue_wwwAbout2},
    {"script", _slotValue_wwwAbout3},
    {"width", _slotValue_wwwAbout4},
    {"height", _slotValue_wwwAbout5},
    {"maxWidth", _slotValue_wwwAbout6},
    {"minWidth", _slotValue_wwwAbout7},
    {"maxHeight", _slotValue_wwwAbout8},
    {"minHeight", _slotValue_wwwAbout9},
    {"border", _slotValue_wwwAbout10},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout12},
    {"name", _slotValue_wwwAbout13},
    {"parent", _slotValue_wwwAbout14},
    {"label", _slotValue_wwwAbout15},
    {"maxWidth", _slotValue_wwwAbout16},
    {"gapH", _slotValue_wwwAbout17},
    {"gapV", _slotValue_wwwAbout18},
    {"border", _slotValue_wwwAbout19},
    {"BDColor", _slotValue_wwwAbout20},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout22},
    {"name", _slotValue_wwwAbout23},
    {"parent", _slotValue_wwwAbout24},
    {"children", _slotValue_wwwAbout25},
    {"gapH", _slotValue_wwwAbout26},
    {"gapV", _slotValue_wwwAbout27},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout29},
    {"name", _slotValue_wwwAbout30},
    {"parent", _slotValue_wwwAbout31},
    {"children", _slotValue_wwwAbout32},
    {"minHeight", _slotValue_wwwAbout33},
    {"gapH", _slotValue_wwwAbout34},
    {"gapV", _slotValue_wwwAbout35},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout37},
    {"parent", _slotValue_wwwAbout38},
    {"name", _slotValue_wwwAbout39},
    {"font", _slotValue_wwwAbout40},
    {"content", _slotValue_wwwAbout41},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout43},
    {"parent", _slotValue_wwwAbout44},
    {"name", _slotValue_wwwAbout45},
    {"label", _slotValue_wwwAbout46},
    {"font", _slotValue_wwwAbout47},
    {"script", _slotValue_wwwAbout48},
    {"maxWidth", _slotValue_wwwAbout49},
    {"maxHeight", _slotValue_wwwAbout50},
    {"height", _slotValue_wwwAbout51},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout53},
    {"parent", _slotValue_wwwAbout54},
    {"name", _slotValue_wwwAbout55},
    {"BDColor", _slotValue_wwwAbout56},
    {"BGColor", _slotValue_wwwAbout57},
    {"height", _slotValue_wwwAbout58},
    {"maxHeight", _slotValue_wwwAbout59},
    {"border", _slotValue_wwwAbout60},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout62},
    {"parent", _slotValue_wwwAbout63},
    {"name", _slotValue_wwwAbout64},
    {"content", _slotValue_wwwAbout65},
    {"font", _slotValue_wwwAbout66},
    {"maxHeight", _slotValue_wwwAbout67},
    {"gapH", _slotValue_wwwAbout68},
    {"gapV", _slotValue_wwwAbout69},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout71},
    {"parent", _slotValue_wwwAbout72},
    {"name", _slotValue_wwwAbout73},
    {"BDColor", _slotValue_wwwAbout74},
    {"BGColor", _slotValue_wwwAbout75},
    {"height", _slotValue_wwwAbout76},
    {"maxHeight", _slotValue_wwwAbout77},
    {"border", _slotValue_wwwAbout78},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwAbout80},
    {"parent", _slotValue_wwwAbout81},
    {"name", _slotValue_wwwAbout82},
    {"content", _slotValue_wwwAbout83},
    {"script", _slotValue_wwwAbout84},
    {"font", _slotValue_wwwAbout85},
    {"gapH", _slotValue_wwwAbout86},
    {"gapV", _slotValue_wwwAbout87},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwDialog_confirm0[] = "vpane";
static char _slotValue_wwwDialog_confirm1[] = "wwwDialog_confirm";
static char _slotValue_wwwDialog_confirm2[] = "\n	switch (arg[0]) {\n	case \"confirm\":\n	break;\n	}\n	usual();\n";
static char _slotValue_wwwDialog_confirm3[] = "300";
static char _slotValue_wwwDialog_confirm4[] = "200";
/* END OF FILE */

static SlotStruct objDesc_wwwDialog_confirm[] = {
    {"class", _slotValue_wwwDialog_confirm0},  {"name", _slotValue_wwwDialog_confirm1},
    {"script", _slotValue_wwwDialog_confirm2}, {"width", _slotValue_wwwDialog_confirm3},
    {"height", _slotValue_wwwDialog_confirm4}, {(char*)0, (char*)0},
};

static char _slotValue_wwwDocuPort0[] = "wwwDocuPort";
static char _slotValue_wwwDocuPort1[] = "TTY";
static char _slotValue_wwwDocuPort2[] = "/usr/work/viola/src/viola/listen";
static char _slotValue_wwwDocuPort3[] = "8083";
static char _slotValue_wwwDocuPort4[] = "\n\
	switch (arg[0]) {\n\
	case \"listen\":\n\
		port = arg[1];\n\
		path = arg[2];\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		initialize();\n\
                set(\"inDelimStr1\", \"\\r\");\n\
                set(\"inDelimStr2\", \"\\n\
\");\n\
/*                startClient();*/\n\
		return;\n\
	break;\n\
	case \"input\":\n\
		in = input();\n\
		if (isBlank(in)) { \n\
			print(\"www.listen: bad input = ``\", in, \"''\\n\
\");\n\
		} else {\n\
			docID = nthChar(in, 0, strlen(in)); \n\
			print(\"www.listen: input = ``\", docID, \"''\\n\
\");\n\
			www(\"show\", docID);\n\
		}\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_wwwDocuPort[] = {
    {"name", _slotValue_wwwDocuPort0},   {"class", _slotValue_wwwDocuPort1},
    {"path", _slotValue_wwwDocuPort2},   {"args", _slotValue_wwwDocuPort3},
    {"script", _slotValue_wwwDocuPort4}, {(char*)0, (char*)0},
};

static char _slotValue_wwwFormatDetect0[] = "generic";
static char _slotValue_wwwFormatDetect1[] = "wwwFormatDetect";
static char _slotValue_wwwFormatDetect2[] = "\n\
	switch (arg[0]) {\n\
	case \"type\":\n\
		docURL = arg[1];\n\
		if (findPattern(docURL, \".pgp\") > -1) {\n\
			handler = \"VWHandler_pgp\";\n\
		} else if (findPattern(docURL, \".html\") > -1) {\n\
/*			handler = \"VWHandler_html\";*/\n\
			handler = \"VWHandler_html2\";\n\
		} else if (findPattern(docURL, \".hmmlb\") > -1) {\n\
			handler = \"VWHandler_hmmlb\";\n\
		} else if (findPattern(docURL, \".hmml\") > -1) {\n\
			handler = \"VWHandler_hmml\";\n\
		} else if (findPattern(docURL, \".au\") > -1) {\n\
			handler = \"VWHandler_au\";\n\
		} else if (findPattern(docURL, \".gif\") > -1) {\n\
			handler = \"VWHandler_gif\";\n\
		} else if (findPattern(docURL, \".csh\") > -1) {\n\
			handler = \"VWHandler_csh\";\n\
		} else if (findPattern(docURL, \".ps\") > -1) {\n\
			handler = \"VWHandler_postscript\";\n\
		} else if (findPattern(docURL, \".xbm\") > -1) {\n\
			handler = \"VWHandler_xbm\";\n\
		} else if (findPattern(docURL, \".xpm\") > -1) {\n\
			handler = \"VWHandler_xpm\";\n\
		} else if (findPattern(docURL, \".v\") > -1) {\n\
			handler = \"VWHandler_vobjf\";\n\
\n\
/*needs better recognition!!!! \n\
		} else if (findPattern(docURL, \"index\") > -1) {\n\
			handler = \"waisDB\";\n\
*/\n\
		} else if (findPattern(docURL, \".txt\") > -1) {\n\
			handler = \"VWHandler_plaintext\";\n\
		} else if (findPattern(docURL, \".text\") > -1) {\n\
			handler = \"VWHandler_plaintext\";\n\
		} else {\n\
/*			print(\"WARNING: format unknown: \",\n\
				docURL, \". Treating as HTML.\\n\
\");\n\
			handler = \"VWHandler_html\";\n\
*/\n\
			handler = \"VWHandler_html2\";\n\
		}\n\
		return handler;\n\
		break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_wwwFormatDetect[] = {
    {"class", _slotValue_wwwFormatDetect0},
    {"name", _slotValue_wwwFormatDetect1},
    {"script", _slotValue_wwwFormatDetect2},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwHandlerDispatch0[] = "wwwHandlerDispatch";
static char _slotValue_wwwHandlerDispatch1[] = "generic";
static char _slotValue_wwwHandlerDispatch2[] = "\n\
/*XXX this object is a mess\n\
print(\"wwwHandlerDispatch: \");\n\
for (i=0; i < arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");\n\
print(\"\\n\
\");\n\
*/\n\
\n\
	switch (arg[0]) {\n\
	case \"dispatch\":\n\
		/* arg[1]	handler\n\
		 * arg[2]	doPost\n\
		 * arg[3]	docURL\n\
		 * arg[4]	docName\n\
		 * arg[5]	paneObj\n\
		 * arg[6]	paneWidth\n\
		 * arg[7]	paneHeight\n\
		 * arg[8]	anchor\n\
		 * arg[9]	message user?\n\
		 * arg[10]	postData\n\
		 */\n\
		handler = arg[1];\n\
		doPost = arg[2];\n\
		docURL = arg[3];\n\
		docName = arg[4];\n\
		paneObj = arg[5];\n\
		paneWidth = arg[6];\n\
		paneHeight = arg[7];\n\
		anchor = arg[8];\n\
		messageUserP = arg[9];\n\
		postData = arg[10];\n\
\n\
/*		print(\"SHOW: handler=\", handler, \n\
				\"; name=\", docName, \"\\n\
\");*/\n\
\n\
		switch (handler) {\n\
		case \"VWHandler_html2\":\n\
			docObj = send(handler, \n\
					'B', docURL,\n\
					paneObj, docName,\n\
					paneWidth, anchor, doPost, postData);\n\
			if (docObj == 0) {\n\
				if (messageUserP) www.mesg.tf(\"clear\");\n\
				return 0;\n\
			}\n\
\n\
/*\n\
		print(\"wwwHandlerDispatch: calling docObj=\", docObj, \n\
				\"; paneWidth=\", paneWidth, \"\\n\
\");\n\
*/\n\
			send(docObj, 'T', 0, paneWidth);\n\
\n\
			send(paneObj, \"setChildren\", docObj);\n\
\n\
			if (anchor != \"\") {\n\
				if (messageUserP) \n\
					www.mesg.tf(\"show\", \n\
						\"Going to anchor...\");\n\
\n\
				pageYPos = send(docName, \"gotoAnchor\", \n\
						anchor) * -1;\n\
			} else {\n\
				pageYPos = 0;\n\
			}\n\
			send(docName, \"y\", pageYPos);\n\
\n\
			if (messageUserP) www.mesg.tf(\"show\", \"Rendering...\");\n\
			if (messageUserP) www.mesg.tf(\"clear\");\n\
\n\
			return docObj;\n\
		break;\n\
		case \"VWHandler_html\":\n\
		case \"VWHandler_hmml\":\n\
			docObj = send(handler, \n\
					'B', docURL,\n\
					paneObj, docName,\n\
					paneWidth, anchor);\n\
			if (docObj == 0) {\n\
				if (messageUserP) www.mesg.tf(\"clear\");\n\
				return 0;\n\
			}\n\
\n\
			send(docObj, 'T', 0, paneWidth);\n\
\n\
			send(paneObj, \"setChildren\", docObj);\n\
\n\
			if (anchor != \"\") {\n\
				if (messageUserP) \n\
					www.mesg.tf(\"show\", \n\
						\"Going to anchor...\");\n\
\n\
				pageYPos = send(docName, \"gotoAnchor\", \n\
						anchor) * -1;\n\
			} else {\n\
				pageYPos = 0;\n\
			}\n\
			send(docName, \"y\", pageYPos);\n\
\n\
			if (messageUserP) www.mesg.tf(\"show\", \"Rendering...\");\n\
\n\
			send(docName, \"show\");\n\
\n\
			tweak(docName, \"raise();\");\n\
			/* questionable. will windoiw be created by now? */\n\
\n\
			if (messageUserP) www.mesg.tf(\"clear\");\n\
\n\
			return docObj;\n\
		break;\n\
		case \"VWHandler_hmmlb\":\n\
\n\
			/* inform the new page of: \n\
			 * 	sourcefile, parent, name, width\n\
			 */\n\
			docObj = send(handler, \n\
					'B', docURL,\n\
					paneObj, docName,\n\
					paneWidth, anchor);\n\
			if (docObj == 0) {\n\
				if (messageUserP) www.mesg.tf(\"clear\");\n\
				return 0;\n\
			}\n\
\n\
			send(docObj, 'T', 0, paneWidth);\n\
\n\
			send(paneObj, \"setChildren\", docObj);\n\
			/*print(\"SHOW: HMML docObj=\", docObj, \"\\n\
\");*/\n\
			if (anchor != \"\") {\n\
				www.mesg.tf(\"show\", \n\
					\"Going to anchor...\");\n\
				pageYPos = send(docName, \"gotoAnchor\", \n\
						anchor) * -1;\n\
			} else {\n\
				pageYPos = 0;\n\
			}\n\
			send(docName, \"y\", pageYPos);\n\
\n\
			www.mesg.tf(\"show\", \"Rendering...\");\n\
\n\
			send(docName, \"show\");\n\
			tweak(docName, \"raise();\");\n\
\n\
			if (messageUserP) www.mesg.tf(\"clear\");\n\
			return docObj;\n\
		break;\n\
		case \"VWHandler_vobjf\":\n\
			docObj = VWHandler_vobjf(\"build\", \n\
					docURL, docName, paneObj,\n\
					paneWidth, paneHeight);\n\
			if (docObj == 0) {\n\
				if (messageUserP) www.mesg.tf(\"clear\");\n\
				return 0;\n\
			}\n\
\n\
			send(paneObj, \"setChildren\", docObj);\n\
\n\
			send(docObj, \"visible\", 1);\n\
\n\
			send(docObj, \"render\");\n\
\n\
			tweak(docObj, \"raise();\");\n\
\n\
			send(docObj, \"config\", \n\
				0, 0, paneWidth, paneHeight);\n\
\n\
			if (messageUserP) www.mesg.tf(\"clear\");\n\
			return docObj;\n\
		break;\n\
		case \"VWHandler_plaintext\":\n\
		case \"waisDB\":\n\
			/* inform the new page of: \n\
			 * 	sourcefile, parent, name, width\n\
			 */\n\
			docObj = send(handler, \n\
					\"build\", docURL,\n\
					paneObj, docName, \n\
					paneWidth);\n\
			if (docObj == 0) {\n\
				if (messageUserP) www.mesg.tf(\"clear\");\n\
				return 0;\n\
			}\n\
			send(docObj, \"tile\", 0, paneWidth, paneHeight);\n\
\n\
			tweak(docObj, concat(\"set(\\\"parent\\\",\\\"\",\n\
						paneObj, \"\\\");\"));\n\
			send(paneObj, \"setChildren\", docObj);\n\
\n\
			send(docObj, \"render\");\n\
			send(docObj, \"raise\");\n\
\n\
			if (messageUserP) www.mesg.tf(\"clear\");\n\
			return docObj;\n\
		break;\n\
/*		case \"VWHandler_xbm\":\n\
		case \"VWHandler_xpm\":\n\
			* inform the new page of: \n\
			 * 	sourcefile, parent, name, width\n\
			 *\n\
			docObj = send(handler,\n\
					\"build\", docURL,\n\
					paneObj, docName, \n\
					paneWidth);\n\
			if (docObj == 0) {\n\
				if (messageUserP) www.mesg.tf(\"clear\");\n\
				return 0;\n\
			}\n\
\n\
			send(docObj, \"tile\", 0, paneWidth, paneHeight);\n\
\n\
			tweak(docObj, concat(\"set(\\\"parent\\\",\\\"\",\n\
						paneObj, \"\\\");\"));\n\
			send(paneObj, \"setChildren\", docObj);\n\
\n\
			send(docName, \"render\");\n\
\n\
			if (messageUserP) www.mesg.tf(\"clear\");\n\
			return docObj;\n\
		break;\n\
*/\n\
		case \"VWHandler_gif\":\n\
		case \"VWHandler_xbm\":\n\
		case \"VWHandler_xpm\":\n\
			/* invoke xv or something...\n\
			 * later, wrap this part into a \n\
			 * VWHandler_* object, so as not to \n\
			 * complicate it here\n\
			 */\n\
/*			DISP_METH = \"inView\";*/\n\
			DISP_METH = \"extView\";\n\
\n\
			switch (DISP_METH) {\n\
			case \"inView\":\n\
				docObj = send(handler,\n\
						\"build\", docURL,\n\
						paneObj, docName, \n\
						paneWidth);\n\
				if (docObj == 0) return 0;\n\
\n\
				send(docObj, \"tile\", 0, paneWidth, paneHeight);\n\
\n\
				tweak(docObj, concat(\"set(\\\"parent\\\",\\\"\",\n\
							paneObj, \"\\\");\"));\n\
				send(paneObj, \"setChildren\", docObj);\n\
\n\
				send(docName, \"render\");\n\
\n\
				if (messageUserP) www.mesg.tf(\"clear\");\n\
				return docObj;\n\
			break;\n\
			case \"extView\":\n\
				localFile = HTTPGet(docURL);\n\
				system(concat(\"xv \", localFile, \" &\"));\n\
			break;\n\
			}\n\
			return 1;/*OK*/\n\
		break;\n\
		case \"VWHandler_au\":\n\
			sourceFile = HTTPGet(docURL);\n\
\n\
			/* a hack. don't know where play usually \n\
			 * lives..\n\
			 */\n\
			print(concat(environVar(\"VIOLA\"),\n\
					\"/play \", sourceFile, \"\\n\
\"));\n\
			system(concat(environVar(\"VIOLA\"),\n\
					\"/play \", sourceFile, \"&\"));\n\
			return 1;/*OK*/\n\
		break;\n\
		case \"VWHandler_pgp\":\n\
			sourceFile = HTTPGet(docURL);\n\
\n\
print(\"VWHandlerDispatch: PGP: sourceFile={\", sourceFile, \"}\\n\
\");\n\
\n\
			/* to fix: should not use absolute path to pgp\n\
			 * \n\
			 */\n\
			system(concat(\"cd /usr/users/pei/pgpTest/test;ls -al;/usr/local/bin/pgp \", sourceFile));\n\
			newSourceFile = nthChar(sourceFile, 0, strlen(sourceFile) - 5);\n\
print(\"VWHandlerDispatch: PGP: newSourceFile={\", newSourceFile, \"}\\n\
\");\n\
\n\
			return send(self(), \"dispatch\", \"VWHandler_html2\",\n\
				    arg[2], newSourceFile, arg[4], arg[5],\n\
				    arg[6], arg[7], arg[8], arg[9], arg[10]);\n\
		break;\n\
		default:\n\
			/*print(\"SHOW: Unknown handler, treat as plaintext: \",\n\
				docName, \"\\n\
\");*/\n\
\n\
			/* inform the new page of: \n\
			 * 	sourcefile, parent, name, width\n\
			 */\n\
			docObj = send(\"plaintext\", \n\
					\"build\", docURL,\n\
					paneObj, docName, \n\
					paneWidth);\n\
			if (docObj == 0) {\n\
				if (messageUserP) www.mesg.tf(\"clear\");\n\
				return 0;\n\
			}\n\
			if (isBlank(docObj)) return 0;\n\
\n\
			send(paneObj, \"setChildren\", docObj);\n\
\n\
			send(docName, \"render\");\n\
\n\
			if (messageUserP) www.mesg.tf(\"clear\");\n\
			return docObj;\n\
		break;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_wwwHandlerDispatch[] = {
    {"name", _slotValue_wwwHandlerDispatch0},
    {"class", _slotValue_wwwHandlerDispatch1},
    {"script", _slotValue_wwwHandlerDispatch2},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwHistory0[] = "wwwHistory";
static char _slotValue_wwwHistory1[] = "vpane";
static char _slotValue_wwwHistory2[] = "";
static char _slotValue_wwwHistory3[] = "\n\
/*\n\
  	print(\"wwwHistory: \");\n\
	for (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\
	print(\"\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"add\":\n\
		wwwHistory.list.tf(\"add\", arg[1], arg[2]);\n\
		return;\n\
	break;\n\
	case \"back\":\n\
	case \"prev\":\n\
	case \"next\":\n\
	case \"peek_prev\":\n\
	case \"peek_next\":\n\
	case \"toggle\":\n\
	case \"peek_back\":\n\
		wwwHistory.list.tf(arg[0]);\n\
		return;\n\
	break;\n\
	case \"historyQuery\":\n\
		wwwHistory.list.tf(arg[0], arg[1]);\n\
		return;\n\
	break;\n\
	case \"visible\":\n\
		set(\"visible\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"dismiss\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	case \"render\":\n\
		set(\"visible\", 1);\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		windowName(\"ViolaWWW Travelal History\");\n\
	break;\n\
	case \"raise\":\n\
		raise();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHistory4[] = "550";
static char _slotValue_wwwHistory5[] = "168";
static char _slotValue_wwwHistory6[] = "wwwHistory.top wwwHistory.list";
static char _slotValue_wwwHistory7[] = "3";
/* END OF OBJ */

static char _slotValue_wwwHistory9[] = "wwwHistory.top";
static char _slotValue_wwwHistory10[] = "hpane";
static char _slotValue_wwwHistory11[] = "wwwHistory";
static char _slotValue_wwwHistory12[] = "wwwHistory.top.prev wwwHistory.top.back wwwHistory.top.next wwwHistory.top.title wwwHistory.top.dismiss";
static char _slotValue_wwwHistory13[] = "20";
static char _slotValue_wwwHistory14[] = "5";
static char _slotValue_wwwHistory15[] = "5";
/* END OF OBJ */

static char _slotValue_wwwHistory17[] = "wwwHistory.top.prev";
static char _slotValue_wwwHistory18[] = "txtButton";
static char _slotValue_wwwHistory19[] = "wwwHistory.top";
static char _slotValue_wwwHistory20[] = "Prev";
static char _slotValue_wwwHistory21[] = "normal";
static char _slotValue_wwwHistory22[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		cursorShape(\"busy\");\n\
		docAddr = wwwHistory.list.tf(\"prev\");\n\
		if (isBlank(docAddr) != 1) www(\"show\", docAddr);\n\
		cursorShape(\"idle\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHistory23[] = "70";
static char _slotValue_wwwHistory24[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory26[] = "wwwHistory.top.back";
static char _slotValue_wwwHistory27[] = "txtButton";
static char _slotValue_wwwHistory28[] = "wwwHistory.top";
static char _slotValue_wwwHistory29[] = "Back";
static char _slotValue_wwwHistory30[] = "normal";
static char _slotValue_wwwHistory31[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		cursorShape(\"busy\");\n\
		docAddr = wwwHistory.list.tf(\"back\");\n\
		if (isBlank(docAddr) != 1) www(\"showButNoRecord\", docAddr);\n\
		cursorShape(\"idle\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHistory32[] = "70";
static char _slotValue_wwwHistory33[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory35[] = "wwwHistory.top.next";
static char _slotValue_wwwHistory36[] = "txtButton";
static char _slotValue_wwwHistory37[] = "wwwHistory.top";
static char _slotValue_wwwHistory38[] = "Next";
static char _slotValue_wwwHistory39[] = "normal";
static char _slotValue_wwwHistory40[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		cursorShape(\"busy\");\n\
		docAddr = wwwHistory.list.tf(\"next\");\n\
		if (isBlank(docAddr) != 1) www(\"showButNoRecord\", docAddr);\n\
		cursorShape(\"idle\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHistory41[] = "70";
static char _slotValue_wwwHistory42[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory44[] = "wwwHistory.top.title";
static char _slotValue_wwwHistory45[] = "txtLabel";
static char _slotValue_wwwHistory46[] = "wwwHistory.top";
static char _slotValue_wwwHistory47[] = "World Wide Web Travels";
static char _slotValue_wwwHistory48[] = "bold";
static char _slotValue_wwwHistory49[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		wwwHistory.list.tf(\"dump\");\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_wwwHistory51[] = "wwwHistory.top.dismiss";
static char _slotValue_wwwHistory52[] = "txtButton";
static char _slotValue_wwwHistory53[] = "wwwHistory.top";
static char _slotValue_wwwHistory54[] = "Dismiss";
static char _slotValue_wwwHistory55[] = "normal";
static char _slotValue_wwwHistory56[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		wwwHistory(\"dismiss\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHistory57[] = "70";
static char _slotValue_wwwHistory58[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory60[] = "wwwHistory.list";
static char _slotValue_wwwHistory61[] = "hpane";
static char _slotValue_wwwHistory62[] = "wwwHistory";
static char _slotValue_wwwHistory63[] = "wwwHistory.list.tf wwwHistory.list.sb";
static char _slotValue_wwwHistory64[] = "4";
static char _slotValue_wwwHistory65[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory67[] = "wwwHistory.list.sb";
static char _slotValue_wwwHistory68[] = "slider";
static char _slotValue_wwwHistory69[] = "wwwHistory.list";
static char _slotValue_wwwHistory70[] = "wwwHistory.list.tf";
static char _slotValue_wwwHistory71[] = "20";
/* END OF OBJ */

static char _slotValue_wwwHistory73[] = "wwwHistory.list.tf";
static char _slotValue_wwwHistory74[] = "wwwHistory.list";
static char _slotValue_wwwHistory75[] = "txtEdit";
static char _slotValue_wwwHistory76[] = "\n\
/*\n\
	print(\"wwwHistory.tf: \");\n\
	for (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\
	print(\"\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		if (isBlank(currentLine()) == 1) {\n\
			bell();\n\
		} else {\n\
			deHighLight(index);\n\
			previousDocIndx = index;\n\
			/*index = lineRowOffset() + cursorRow();*/\n\
			index = cursorRow();\n\
			highLight(index);\n\
			if (get(\"window\")) render();\n\
		}\n\
		www(\"showButNoRecord\", docAddr[index]);\n\
	break;\n\
	case \"prev\":\n\
		if (index > 0) {\n\
			deHighLight(index);\n\
			previousDocIndx = index;\n\
			index--;\n\
			highLight(index);\n\
			if (get(\"window\")) render();\n\
			return docAddr[index];\n\
		} else {\n\
			bell();\n\
			return \"\";\n\
		}\n\
	break;\n\
	case \"peek_prev\":\n\
		if (index > 0) return docTitle[index - 1];\n\
		else return \"none\";\n\
	break;\n\
	case \"next\":\n\
		if (index < count - 1) {\n\
			deHighLight(index);\n\
			previousDocIndx = index;\n\
			index++;\n\
			highLight(index);\n\
			if (get(\"window\")) render();\n\
			return docAddr[index];\n\
		} else {\n\
			bell();\n\
			return \"\";\n\
		}\n\
	break;\n\
	case \"peek_next\":\n\
		if (index + 1 < count) return docTitle[index + 1];\n\
		else return \"none\";\n\
	break;\n\
	case \"toggle\":\n\
		if (previousDocIndx == -1) {\n\
			return \"\";\n\
		} else {\n\
			deHighLight(index);\n\
			temp = index;\n\
			index = previousDocIndx;\n\
			previousDocIndx = temp;\n\
			highLight(index);\n\
			if (get(\"window\")) render();\n\
			return docAddr[index];\n\
		}\n\
	break;\n\
	case \"peek_back\":\n\
		if (index > 0) return docTitle[index - 1];\n\
		else return \"none\";\n\
	break;\n\
	case \"add\":\n\
		deHighLight(index);\n\
		previousDocIndx = index;\n\
		index = count;\n\
		if (isBlank(arg[1]) == 1) {\n\
			docTitle[count] = \"no title\";\n\
		} else {\n\
			/* make sure we're storing string representation,\n\
			 * rather than possibly object pointer which can\n\
			 * get us into trouble if that object is destroyed\n\
			 * and we reference it.\n\
			 */\n\
			docTitle[index] = str(arg[1]);\n\
		}\n\
		docAddr[index] = arg[2];\n\
\n\
		count++;\n\
\n\
		victimIdx = count - killLatency;\n\
		if (victimIdx >= 0) {\n\
			victim = docAddr[victimIdx];\n\
			if (victim != arg[2]) {\n\
				send(victim, \"visible\", 0);\n\
				send(victim, \"freeSelf\");\n\
			}\n\
		}\n\
		tt = \"\";\n\
		for (i = 0; i < count; i++)\n\
			tt = concat(tt, docTitle[i], '\\n\
');\n\
		set(\"content\", tt);\n\
		highLight(index);\n\
		if (get(\"window\")) render();\n\
		return;\n\
	break;\n\
	case \"back\":\n\
		/* delete last line */\n\
/*\n\
print(\"count<=1\", count <= 1, \"\\n\
\");\n\
p = count <= 1;\n\
print(\"count<=1p \", p, \"\\n\
\");\n\
*/\n\
		if (count <= 1) {\n\
			bell();\n\
		} else {\n\
/*\n\
print(\"NOW DESTROY index=\", index, \": {\", docAddr[index], \"}<<<<<<<<<<<,\\n\
\");\n\
*/\n\
			www(\"destroyDoc\", docAddr[index]);\n\
\n\
			deHighLight(index);\n\
			count--;\n\
			if (index > -1) index--;\n\
			previousDocIndx = index;\n\
/*set(\"content\", nthLine(get(\"content\"), 0, count - 1));*/\n\
/*GROSSY*/		tt = \"\";\n\
			for (i = 0; i < count; i++)\n\
				tt = concat(tt, docTitle[i], '\\n\
');\n\
			set(\"content\", tt);\n\
			highLight(index);\n\
			if (get(\"window\")) render();\n\
\n\
		}\n\
/*\n\
print(\"NOW WANT index=\",index, \": {\", docAddr[index], \"}\\n\
\");\n\
print(\"count=\", count, \"\\n\
\");\n\
print(\"HISTORY NOW:{\", tt, \"}\\n\
\");\n\
*/\n\
		return docAddr[index];\n\
	break;\n\
	case \"config\":\n\
		/* this is necessary due to the bug where content can't be\n\
		 * set until the object has been configured... and this is\n\
		 * a problem because a document may be \"added\" here before\n\
		 * the widgets are configured.\n\
		 */\n\
		usual();\n\
		set(\"content\", tt);\n\
		return;\n\
	break;\n\
	case \"historyQuery\":\n\
		/* arg[1]	cookie\n\
		 */\n\
		wwwHistory_report(arg[1], docTitle);\n\
		return;\n\
	break;\n\
	case \"query\": /* query(n) -> text on line n */\n\
		return nthLine(get(\"content\"), arg[1]);\n\
	break;\n\
	case \"clear\":\n\
		set(\"content\", \"\");\n\
	break;\n\
	case \"dump\":\n\
		for (i = 0; i < count; i++)\n\
			print(\"[\", i, \"]\	 docTitle={\", docTitle[i], \"}\",\n\
				\"\	docAddr={\", docAddr[i], \"}\\n\
\");\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
	case \"release\":\n\
	case \"keyPress\":\n\
		return; \n\
	break;\n\
	case \"enter\":\n\
		set(\"cursor\", 0); \n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		previousDocIndx = -1;\n\
		index = -1;\n\
		count = 0;\n\
		killLatency = 10;\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHistory77[] = "wwwHistory.list.sb";
static char _slotValue_wwwHistory78[] = "fixed";
/* END OF FILE */

static SlotStruct objDesc_wwwHistory[] = {
    {"name", _slotValue_wwwHistory0},
    {"class", _slotValue_wwwHistory1},
    {"parent", _slotValue_wwwHistory2},
    {"script", _slotValue_wwwHistory3},
    {"width", _slotValue_wwwHistory4},
    {"height", _slotValue_wwwHistory5},
    {"children", _slotValue_wwwHistory6},
    {"border", _slotValue_wwwHistory7},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory9},
    {"class", _slotValue_wwwHistory10},
    {"parent", _slotValue_wwwHistory11},
    {"children", _slotValue_wwwHistory12},
    {"maxHeight", _slotValue_wwwHistory13},
    {"gapV", _slotValue_wwwHistory14},
    {"gapH", _slotValue_wwwHistory15},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory17},
    {"class", _slotValue_wwwHistory18},
    {"parent", _slotValue_wwwHistory19},
    {"label", _slotValue_wwwHistory20},
    {"font", _slotValue_wwwHistory21},
    {"script", _slotValue_wwwHistory22},
    {"maxWidth", _slotValue_wwwHistory23},
    {"gapH", _slotValue_wwwHistory24},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory26},
    {"class", _slotValue_wwwHistory27},
    {"parent", _slotValue_wwwHistory28},
    {"label", _slotValue_wwwHistory29},
    {"font", _slotValue_wwwHistory30},
    {"script", _slotValue_wwwHistory31},
    {"maxWidth", _slotValue_wwwHistory32},
    {"gapH", _slotValue_wwwHistory33},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory35},
    {"class", _slotValue_wwwHistory36},
    {"parent", _slotValue_wwwHistory37},
    {"label", _slotValue_wwwHistory38},
    {"font", _slotValue_wwwHistory39},
    {"script", _slotValue_wwwHistory40},
    {"maxWidth", _slotValue_wwwHistory41},
    {"gapH", _slotValue_wwwHistory42},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory44},
    {"class", _slotValue_wwwHistory45},
    {"parent", _slotValue_wwwHistory46},
    {"label", _slotValue_wwwHistory47},
    {"font", _slotValue_wwwHistory48},
    {"script", _slotValue_wwwHistory49},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory51},
    {"class", _slotValue_wwwHistory52},
    {"parent", _slotValue_wwwHistory53},
    {"label", _slotValue_wwwHistory54},
    {"font", _slotValue_wwwHistory55},
    {"script", _slotValue_wwwHistory56},
    {"maxWidth", _slotValue_wwwHistory57},
    {"gapH", _slotValue_wwwHistory58},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory60},
    {"class", _slotValue_wwwHistory61},
    {"parent", _slotValue_wwwHistory62},
    {"children", _slotValue_wwwHistory63},
    {"gapH", _slotValue_wwwHistory64},
    {"gapV", _slotValue_wwwHistory65},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory67},
    {"class", _slotValue_wwwHistory68},
    {"parent", _slotValue_wwwHistory69},
    {"shownNotify", _slotValue_wwwHistory70},
    {"maxWidth", _slotValue_wwwHistory71},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHistory73},
    {"parent", _slotValue_wwwHistory74},
    {"class", _slotValue_wwwHistory75},
    {"script", _slotValue_wwwHistory76},
    {"shownDepend", _slotValue_wwwHistory77},
    {"font", _slotValue_wwwHistory78},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwHTMLSrc0[] = "wwwHTMLSrc";
static char _slotValue_wwwHTMLSrc1[] = "vpane";
static char _slotValue_wwwHTMLSrc2[] = "";
static char _slotValue_wwwHTMLSrc3[] = "wwwHTMLSrc.top wwwHTMLSrc.list wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc4[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		/* arg[1]	call back object\n\
		 * arg[2]	HTMLAddress\n\
		 * arg[3]	HTMLSource\n\
		 */\n\
		cloneID = cloneID + 1;\n\
		new = clone(cloneID);\n\
		send(new, \"show_clone\", arg[1], arg[2], arg[3]);\n\
		send(new, \"render\");\n\
		return;\n\
	break;\n\
	case \"show_clone\":\n\
		caller = arg[1];\n\
		HTMLAddress = arg[2];\n\
		HTMLSource = arg[3];\n\
		send(nthChild(0), \"show\", HTMLAddress);\n\
		send(nthChild(1), \"show\", HTMLSource);\n\
		return;\n\
	break;\n\
	case \"apply\":\n\
		send(caller, \"updateSrc\", send(nthChild(1), \"contentP\"));\n\
		return;\n\
	break;\n\
	case \"store\":\n\
/*\n\
		tmp = makeTempFile();\n\
		saveFile(tmp, send(nthChild(1), \"contentP\"));\n\
		print(\"ERROR: Sorry, source update feature doesn't yet exist. The changed document is saved in \", tmp, \".\\n\
\");\n\
*/\n\
		res.getLineEntry(\"show\", \n\
			\"Enter file name to save to document source to:\", \n\
				\"/tmp/out.html\",\n\
				self(), \"gotOutputFileName\");\n\
		return;\n\
	break;\n\
	case \"gotOutputFileName\":\n\
		if (saveFile(arg[1], send(nthChild(1), \"contentP\"))) {\n\
			www.mesg.tf(\"show\", \n\
				concatenate(\"Source saved to file: \",\n\
					arg[1], \"\\n\
\"));\n\
		} else {\n\
			www.mesg.tf(\"show\", \n\
				concatenate(\"Failed to save source to file: \",\n\
					arg[1], \"\\n\
\"));\n\
		}\n\
		return;\n\
 	break;\n\
	case \"dismiss\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		cloneID = 0;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHTMLSrc5[] = "600";
static char _slotValue_wwwHTMLSrc6[] = "400";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc8[] = "wwwHTMLSrc.top";
static char _slotValue_wwwHTMLSrc9[] = "txtDisp";
static char _slotValue_wwwHTMLSrc10[] = "wwwHTMLSrc";
static char _slotValue_wwwHTMLSrc11[] = "normal";
static char _slotValue_wwwHTMLSrc12[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"label\", arg[1]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHTMLSrc13[] = "20";
static char _slotValue_wwwHTMLSrc14[] = "black";
static char _slotValue_wwwHTMLSrc15[] = "LemonChiffon3";
static char _slotValue_wwwHTMLSrc16[] = "black";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc18[] = "wwwHTMLSrc.list";
static char _slotValue_wwwHTMLSrc19[] = "hpane";
static char _slotValue_wwwHTMLSrc20[] = "wwwHTMLSrc";
static char _slotValue_wwwHTMLSrc21[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		send(nthChild(0), \"show\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"contentP\":\n\
		return send(nthChild(0), \"contentP\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHTMLSrc22[] = "wwwHTMLSrc.list.tf wwwHTMLSrc.list.sb";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc24[] = "wwwHTMLSrc.list.sb";
static char _slotValue_wwwHTMLSrc25[] = "slider";
static char _slotValue_wwwHTMLSrc26[] = "wwwHTMLSrc.list";
static char _slotValue_wwwHTMLSrc27[] = "wwwHTMLSrc.list.tf";
static char _slotValue_wwwHTMLSrc28[] = "grey45";
static char _slotValue_wwwHTMLSrc29[] = "grey45";
static char _slotValue_wwwHTMLSrc30[] = "white";
static char _slotValue_wwwHTMLSrc31[] = "20";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc33[] = "wwwHTMLSrc.list.tf";
static char _slotValue_wwwHTMLSrc34[] = "wwwHTMLSrc.list";
static char _slotValue_wwwHTMLSrc35[] = "txtEdit";
static char _slotValue_wwwHTMLSrc36[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"contentP\":\n\
		return get(\"content\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHTMLSrc37[] = "wwwHTMLSrc.list.sb";
static char _slotValue_wwwHTMLSrc38[] = "fixed";
static char _slotValue_wwwHTMLSrc39[] = "grey24";
static char _slotValue_wwwHTMLSrc40[] = "70 90 70";
static char _slotValue_wwwHTMLSrc41[] = "1";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc43[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc44[] = "hpane";
static char _slotValue_wwwHTMLSrc45[] = "wwwHTMLSrc";
static char _slotValue_wwwHTMLSrc46[] = "20";
static char _slotValue_wwwHTMLSrc47[] = "wwwHTMLSrc.ctrl.apply wwwHTMLSrc.ctrl.store wwwHTMLSrc.ctrl.dismiss";
static char _slotValue_wwwHTMLSrc48[] = "\n\
	switch (arg[0]) {\n\
	case \"apply\":\n\
	case \"store\":\n\
	case \"dismiss\":\n\
		send(get(\"parent\"), arg[0]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHTMLSrc49[] = "1";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc51[] = "wwwHTMLSrc.ctrl.apply";
static char _slotValue_wwwHTMLSrc52[] = "txtButton";
static char _slotValue_wwwHTMLSrc53[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc54[] = "normal";
static char _slotValue_wwwHTMLSrc55[] = "Apply Changes";
static char _slotValue_wwwHTMLSrc56[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(get(\"parent\"), \"apply\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHTMLSrc57[] = "grey45";
static char _slotValue_wwwHTMLSrc58[] = "white";
static char _slotValue_wwwHTMLSrc59[] = "white";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc61[] = "wwwHTMLSrc.ctrl.store";
static char _slotValue_wwwHTMLSrc62[] = "txtButton";
static char _slotValue_wwwHTMLSrc63[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc64[] = "normal";
static char _slotValue_wwwHTMLSrc65[] = "Store Changes";
static char _slotValue_wwwHTMLSrc66[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(get(\"parent\"), \"store\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHTMLSrc67[] = "grey45";
static char _slotValue_wwwHTMLSrc68[] = "white";
static char _slotValue_wwwHTMLSrc69[] = "white";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc71[] = "wwwHTMLSrc.ctrl.dismiss";
static char _slotValue_wwwHTMLSrc72[] = "txtButton";
static char _slotValue_wwwHTMLSrc73[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc74[] = "normal";
static char _slotValue_wwwHTMLSrc75[] = "Dismiss";
static char _slotValue_wwwHTMLSrc76[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(get(\"parent\"), \"dismiss\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHTMLSrc77[] = "grey45";
static char _slotValue_wwwHTMLSrc78[] = "white";
static char _slotValue_wwwHTMLSrc79[] = "white";
/* END OF FILE */

static SlotStruct objDesc_wwwHTMLSrc[] = {
    {"name", _slotValue_wwwHTMLSrc0},
    {"class", _slotValue_wwwHTMLSrc1},
    {"parent", _slotValue_wwwHTMLSrc2},
    {"children", _slotValue_wwwHTMLSrc3},
    {"script", _slotValue_wwwHTMLSrc4},
    {"width", _slotValue_wwwHTMLSrc5},
    {"height", _slotValue_wwwHTMLSrc6},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHTMLSrc8},
    {"class", _slotValue_wwwHTMLSrc9},
    {"parent", _slotValue_wwwHTMLSrc10},
    {"font", _slotValue_wwwHTMLSrc11},
    {"script", _slotValue_wwwHTMLSrc12},
    {"maxHeight", _slotValue_wwwHTMLSrc13},
    {"BDColor", _slotValue_wwwHTMLSrc14},
    {"BGColor", _slotValue_wwwHTMLSrc15},
    {"FGColor", _slotValue_wwwHTMLSrc16},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHTMLSrc18},
    {"class", _slotValue_wwwHTMLSrc19},
    {"parent", _slotValue_wwwHTMLSrc20},
    {"script", _slotValue_wwwHTMLSrc21},
    {"children", _slotValue_wwwHTMLSrc22},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHTMLSrc24},
    {"class", _slotValue_wwwHTMLSrc25},
    {"parent", _slotValue_wwwHTMLSrc26},
    {"shownNotify", _slotValue_wwwHTMLSrc27},
    {"BDColor", _slotValue_wwwHTMLSrc28},
    {"BGColor", _slotValue_wwwHTMLSrc29},
    {"FGColor", _slotValue_wwwHTMLSrc30},
    {"maxWidth", _slotValue_wwwHTMLSrc31},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHTMLSrc33},
    {"parent", _slotValue_wwwHTMLSrc34},
    {"class", _slotValue_wwwHTMLSrc35},
    {"script", _slotValue_wwwHTMLSrc36},
    {"shownDepend", _slotValue_wwwHTMLSrc37},
    {"font", _slotValue_wwwHTMLSrc38},
    {"BGColor", _slotValue_wwwHTMLSrc39},
    {"FGColor", _slotValue_wwwHTMLSrc40},
    {"verbatim", _slotValue_wwwHTMLSrc41},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHTMLSrc43},
    {"class", _slotValue_wwwHTMLSrc44},
    {"parent", _slotValue_wwwHTMLSrc45},
    {"maxHeight", _slotValue_wwwHTMLSrc46},
    {"children", _slotValue_wwwHTMLSrc47},
    {"script", _slotValue_wwwHTMLSrc48},
    {"gapV", _slotValue_wwwHTMLSrc49},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHTMLSrc51},
    {"class", _slotValue_wwwHTMLSrc52},
    {"parent", _slotValue_wwwHTMLSrc53},
    {"font", _slotValue_wwwHTMLSrc54},
    {"label", _slotValue_wwwHTMLSrc55},
    {"script", _slotValue_wwwHTMLSrc56},
    {"BGColor", _slotValue_wwwHTMLSrc57},
    {"BDColor", _slotValue_wwwHTMLSrc58},
    {"FGColor", _slotValue_wwwHTMLSrc59},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHTMLSrc61},
    {"class", _slotValue_wwwHTMLSrc62},
    {"parent", _slotValue_wwwHTMLSrc63},
    {"font", _slotValue_wwwHTMLSrc64},
    {"label", _slotValue_wwwHTMLSrc65},
    {"script", _slotValue_wwwHTMLSrc66},
    {"BGColor", _slotValue_wwwHTMLSrc67},
    {"BDColor", _slotValue_wwwHTMLSrc68},
    {"FGColor", _slotValue_wwwHTMLSrc69},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHTMLSrc71},
    {"class", _slotValue_wwwHTMLSrc72},
    {"parent", _slotValue_wwwHTMLSrc73},
    {"font", _slotValue_wwwHTMLSrc74},
    {"label", _slotValue_wwwHTMLSrc75},
    {"script", _slotValue_wwwHTMLSrc76},
    {"BGColor", _slotValue_wwwHTMLSrc77},
    {"BDColor", _slotValue_wwwHTMLSrc78},
    {"FGColor", _slotValue_wwwHTMLSrc79},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwHotFolder0[] = "wwwHotFolder";
static char _slotValue_wwwHotFolder1[] = "vpane";
static char _slotValue_wwwHotFolder2[] = "";
static char _slotValue_wwwHotFolder3[] = "\n\
/*\n\
  	print(\"wwwHotFolder: \");\n\
	for (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\
	print(\"\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"addCurrent\":\n\
		send(\"wwwHotFolder.list.tf\", \"add\");\n\
		return;\n\
	break;\n\
	case \"add\":\n\
		wwwHotFolder.list.tf(\"add\", arg[1], arg[2]);\n\
		return;\n\
	break;\n\
	case \"toggle\":\n\
		wwwHotFolder.list.tf(arg[0]);\n\
		return;\n\
	break;\n\
	case \"historyQuery\":\n\
		wwwHotFolder.list.tf(arg[0], arg[1]);\n\
		return;\n\
	break;\n\
	case \"visible\":\n\
		set(\"visible\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"dismiss\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	case \"render\":\n\
		set(\"visible\", 1);\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"busy\":\n\
		cursorShape(\"busy\");\n\
		return;\n\
	break;\n\
	case \"idle\":\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		windowName(\"ViolaWWW Hot Lists\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHotFolder4[] = "550";
static char _slotValue_wwwHotFolder5[] = "168";
static char _slotValue_wwwHotFolder6[] = "wwwHotFolder.top wwwHotFolder.list";
static char _slotValue_wwwHotFolder7[] = "3";
/* END OF OBJ */

static char _slotValue_wwwHotFolder9[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder10[] = "hpane";
static char _slotValue_wwwHotFolder11[] = "wwwHotFolder";
static char _slotValue_wwwHotFolder12[] = "wwwHotFolder.top.goto wwwHotFolder.top.add wwwHotFolder.top.delete wwwHotFolder.top.edit wwwHotFolder.top.title wwwHotFolder.top.dismiss";
static char _slotValue_wwwHotFolder13[] = "20";
static char _slotValue_wwwHotFolder14[] = "5";
static char _slotValue_wwwHotFolder15[] = "5";
/* END OF OBJ */

static char _slotValue_wwwHotFolder17[] = "wwwHotFolder.top.goto";
static char _slotValue_wwwHotFolder18[] = "txtButton";
static char _slotValue_wwwHotFolder19[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder20[] = "Goto";
static char _slotValue_wwwHotFolder21[] = "normal";
static char _slotValue_wwwHotFolder22[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		cursorShape(\"busy\");\n\
		send(\"wwwHotFolder.list.tf\", \"goto\");\n\
		cursorShape(\"idle\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHotFolder23[] = "70";
static char _slotValue_wwwHotFolder24[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder26[] = "wwwHotFolder.top.add";
static char _slotValue_wwwHotFolder27[] = "txtButton";
static char _slotValue_wwwHotFolder28[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder29[] = "Add";
static char _slotValue_wwwHotFolder30[] = "normal";
static char _slotValue_wwwHotFolder31[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		cursorShape(\"busy\");\n\
		send(\"wwwHotFolder.list.tf\", \"add\");\n\
		cursorShape(\"idle\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHotFolder32[] = "70";
static char _slotValue_wwwHotFolder33[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder35[] = "wwwHotFolder.top.delete";
static char _slotValue_wwwHotFolder36[] = "txtButton";
static char _slotValue_wwwHotFolder37[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder38[] = "Delete";
static char _slotValue_wwwHotFolder39[] = "normal";
static char _slotValue_wwwHotFolder40[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		cursorShape(\"busy\");\n\
		send(\"wwwHotFolder.list.tf\", \"delete\");\n\
		cursorShape(\"idle\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHotFolder41[] = "70";
static char _slotValue_wwwHotFolder42[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder44[] = "wwwHotFolder.top.edit";
static char _slotValue_wwwHotFolder45[] = "txtButton";
static char _slotValue_wwwHotFolder46[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder47[] = "Edit";
static char _slotValue_wwwHotFolder48[] = "normal";
static char _slotValue_wwwHotFolder49[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		cursorShape(\"busy\");\n\
		send(\"wwwHotFolder.list.tf\", \"editComment\");\n\
		cursorShape(\"idle\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHotFolder50[] = "70";
/* END OF OBJ */

static char _slotValue_wwwHotFolder52[] = "wwwHotFolder.top.title";
static char _slotValue_wwwHotFolder53[] = "txtLabel";
static char _slotValue_wwwHotFolder54[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder55[] = "Hot List";
static char _slotValue_wwwHotFolder56[] = "bold";
static char _slotValue_wwwHotFolder57[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		wwwHotFolder.list.tf(\"dump\");\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_wwwHotFolder59[] = "wwwHotFolder.top.dismiss";
static char _slotValue_wwwHotFolder60[] = "txtButton";
static char _slotValue_wwwHotFolder61[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder62[] = "Dismiss";
static char _slotValue_wwwHotFolder63[] = "normal";
static char _slotValue_wwwHotFolder64[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		wwwHotFolder(\"dismiss\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHotFolder65[] = "70";
static char _slotValue_wwwHotFolder66[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHotFolder68[] = "wwwHotFolder.list";
static char _slotValue_wwwHotFolder69[] = "hpane";
static char _slotValue_wwwHotFolder70[] = "wwwHotFolder";
static char _slotValue_wwwHotFolder71[] = "wwwHotFolder.list.tf wwwHotFolder.list.sb";
static char _slotValue_wwwHotFolder72[] = "5";
static char _slotValue_wwwHotFolder73[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHotFolder75[] = "wwwHotFolder.list.sb";
static char _slotValue_wwwHotFolder76[] = "slider";
static char _slotValue_wwwHotFolder77[] = "wwwHotFolder.list";
static char _slotValue_wwwHotFolder78[] = "wwwHotFolder.list.tf";
static char _slotValue_wwwHotFolder79[] = "20";
/* END OF OBJ */

static char _slotValue_wwwHotFolder81[] = "wwwHotFolder.list.tf";
static char _slotValue_wwwHotFolder82[] = "wwwHotFolder.list";
static char _slotValue_wwwHotFolder83[] = "txtEdit";
static char _slotValue_wwwHotFolder84[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		if (isBlank(currentLine()) == 1) {\n\
			bell();\n\
		} else {\n\
			oldIndex = index;\n\
			deHighLight(index);\n\
			index = cursorRow();\n\
			highLight(index);\n\
			if (get(\"window\")) render();\n\
/*\n\
		print(\"Selected: currentLine=\", currentLine(), \"\\n\
\");\n\
		print(\"Selected: index=\", index, \"\\n\
\");\n\
		print(\"Selected: url=\", HTTPHotListGet(0, index), \"\\n\
\");\n\
		print(\"Selected: comment=\", HTTPHotListGet(1, index), \"\\n\
\");\n\
*/\n\
			if (oldIndex == index) { /* cheezy double click*/\n\
				send(\"wwwHotFolder\", \"busy\");\n\
				send(\"www\", \"show\", HTTPHotListGet(0, index));\n\
				send(\"wwwHotFolder\", \"idle\");\n\
				oldIndex = -1;\n\
			}\n\
		}\n\
	break;\n\
	case \"goto\":\n\
		if (index > -1) {\n\
			send(\"wwwHotFolder\", \"busy\");\n\
			send(\"www\", \"show\", HTTPHotListGet(0, index));\n\
			send(\"wwwHotFolder\", \"idle\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		/* this is necessary due to the bug where content can't be\n\
		 * set until the object has been configured... and this is\n\
		 * a problem because a document may be \"added\" here before\n\
		 * the widgets are configured.\n\
		 */\n\
		usual();\n\
		send(self(), \"load\");\n\
		return;\n\
	break;\n\
	case \"save\":\n\
		HTTPHotListSave();\n\
		return;\n\
	break;\n\
	case \"load\":\n\
		tt = HTTPHotListGet(3);\n\
		set(\"content\", tt);\n\
		if (get(\"window\")) render();\n\
		index = -1;\n\
		return;\n\
	break;\n\
	case \"add\":\n\
		url = send(\"www\", \"getCurrentDocURL\");\n\
		comment = send(\"www\", \"getCurrentDocTitle\");\n\
		HTTPHotListAdd(url, comment, date());\n\
		HTTPHotListSave();\n\
		send(self(), \"load\");\n\
		return;\n\
	break;\n\
	case \"delete\":\n\
		if (index != -1) {\n\
			HTTPHotListDelete(index);\n\
			HTTPHotListSave();\n\
			send(self(), \"load\");\n\
		} else {\n\
			send(\"prompt\", \"show\",\n\
				\"First select a hot list item, then delete.\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"editComment\":\n\
		if (index != -1) {\n\
			winPos = windowPosition();\n\
			send(\"res.getLineEntry\", \"show\", \n\
				\"Enter new URL comment\",\n\
				HTTPHotListGet(1, index),\n\
				self(),\n\
				\"newComment\",\n\
				winPos[0] + 20, winPos[1] + 20);\n\
		} else {\n\
			send(\"prompt\", \"show\",\n\
				\"First select a hot list item, then edit.\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"newComment\":\n\
		HTTPHotListChange(1/*comment*/, index, arg[1]);\n\
		HTTPHotListSave();\n\
		send(self(), \"load\");\n\
		return;\n\
	break;\n\
	case \"keyPress\":\n\
	case \"enter\":\n\
	case \"leave\":\n\
		return; \n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		previousDocIndx = -1;\n\
		index = -1;\n\
		count = 0;\n\
		send(self(), \"load\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwHotFolder85[] = "wwwHotFolder.list.sb";
static char _slotValue_wwwHotFolder86[] = "fixed";
/* END OF FILE */

static SlotStruct objDesc_wwwHotFolder[] = {
    {"name", _slotValue_wwwHotFolder0},
    {"class", _slotValue_wwwHotFolder1},
    {"parent", _slotValue_wwwHotFolder2},
    {"script", _slotValue_wwwHotFolder3},
    {"width", _slotValue_wwwHotFolder4},
    {"height", _slotValue_wwwHotFolder5},
    {"children", _slotValue_wwwHotFolder6},
    {"border", _slotValue_wwwHotFolder7},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder9},
    {"class", _slotValue_wwwHotFolder10},
    {"parent", _slotValue_wwwHotFolder11},
    {"children", _slotValue_wwwHotFolder12},
    {"maxHeight", _slotValue_wwwHotFolder13},
    {"gapV", _slotValue_wwwHotFolder14},
    {"gapH", _slotValue_wwwHotFolder15},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder17},
    {"class", _slotValue_wwwHotFolder18},
    {"parent", _slotValue_wwwHotFolder19},
    {"label", _slotValue_wwwHotFolder20},
    {"font", _slotValue_wwwHotFolder21},
    {"script", _slotValue_wwwHotFolder22},
    {"maxWidth", _slotValue_wwwHotFolder23},
    {"gapH", _slotValue_wwwHotFolder24},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder26},
    {"class", _slotValue_wwwHotFolder27},
    {"parent", _slotValue_wwwHotFolder28},
    {"label", _slotValue_wwwHotFolder29},
    {"font", _slotValue_wwwHotFolder30},
    {"script", _slotValue_wwwHotFolder31},
    {"maxWidth", _slotValue_wwwHotFolder32},
    {"gapH", _slotValue_wwwHotFolder33},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder35},
    {"class", _slotValue_wwwHotFolder36},
    {"parent", _slotValue_wwwHotFolder37},
    {"label", _slotValue_wwwHotFolder38},
    {"font", _slotValue_wwwHotFolder39},
    {"script", _slotValue_wwwHotFolder40},
    {"maxWidth", _slotValue_wwwHotFolder41},
    {"gapH", _slotValue_wwwHotFolder42},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder44},
    {"class", _slotValue_wwwHotFolder45},
    {"parent", _slotValue_wwwHotFolder46},
    {"label", _slotValue_wwwHotFolder47},
    {"font", _slotValue_wwwHotFolder48},
    {"script", _slotValue_wwwHotFolder49},
    {"maxWidth", _slotValue_wwwHotFolder50},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder52},
    {"class", _slotValue_wwwHotFolder53},
    {"parent", _slotValue_wwwHotFolder54},
    {"label", _slotValue_wwwHotFolder55},
    {"font", _slotValue_wwwHotFolder56},
    {"script", _slotValue_wwwHotFolder57},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder59},
    {"class", _slotValue_wwwHotFolder60},
    {"parent", _slotValue_wwwHotFolder61},
    {"label", _slotValue_wwwHotFolder62},
    {"font", _slotValue_wwwHotFolder63},
    {"script", _slotValue_wwwHotFolder64},
    {"maxWidth", _slotValue_wwwHotFolder65},
    {"gapH", _slotValue_wwwHotFolder66},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder68},
    {"class", _slotValue_wwwHotFolder69},
    {"parent", _slotValue_wwwHotFolder70},
    {"children", _slotValue_wwwHotFolder71},
    {"gapH", _slotValue_wwwHotFolder72},
    {"gapV", _slotValue_wwwHotFolder73},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder75},
    {"class", _slotValue_wwwHotFolder76},
    {"parent", _slotValue_wwwHotFolder77},
    {"shownNotify", _slotValue_wwwHotFolder78},
    {"maxWidth", _slotValue_wwwHotFolder79},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwHotFolder81},
    {"parent", _slotValue_wwwHotFolder82},
    {"class", _slotValue_wwwHotFolder83},
    {"script", _slotValue_wwwHotFolder84},
    {"shownDepend", _slotValue_wwwHotFolder85},
    {"font", _slotValue_wwwHotFolder86},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwPref0[] = "vpane";
static char _slotValue_wwwPref1[] = "wwwPref";
static char _slotValue_wwwPref2[] = "wwwPref.scroll wwwPref.UDI wwwPref.lprCmd wwwPref.bkm";
/* END OF OBJ */

static char _slotValue_wwwPref4[] = "vpane";
static char _slotValue_wwwPref5[] = "wwwPref.scroll";
/* END OF OBJ */

static char _slotValue_wwwPref7[] = "wwwPref.scroll wwwPref.UDI wwwPref.lprCmd wwwPref.bkm";
/* END OF FILE */

static SlotStruct objDesc_wwwPref[] = {
    {"class", _slotValue_wwwPref0},
    {"name", _slotValue_wwwPref1},
    {"children", _slotValue_wwwPref2},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwPref4},
    {"name", _slotValue_wwwPref5},
    {(char*)0, (char*)1},
    {"children", _slotValue_wwwPref7},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwSecurity0[] = "generic";
static char _slotValue_wwwSecurity1[] = "wwwSecurity";
static char _slotValue_wwwSecurity2[] = "\n\
	/* this security wall is terribly lay back now */\n\
\n\
	switch (arg[0]) {\n\
	case \"rmTmpFile\":\n\
		/* need to check that the file is indeed a temporary\n\
		 * file created by viola...\n\
		 */\n\
		if (findPattern(arg[1], \"/tmp/\") != -1) { /* very feeble */\n\
			deleteFile(arg[1]);\n\
			return 1;\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"getDocAndMoveItToSpecifiedPlace\":\n\
		/* this is call by HTML__doc. Need a way to autheticate\n\
		 * that it's indeed HTML__doc that's calling ...\n\
		 */\n\
		/* arg[1]	docURL\n\
		 * arg[2]	destination\n\
		 */\n\
		if (access(arg[2])) {\n\
			/* should query to confirm */\n\
			print(\"Warning: overwriting \", arg[2], \"...\\n\
\");\n\
		}\n\
		dumpFile = HTTPGet(arg[1]);\n\
		system(concat(\"mv \", dumpFile, \" \", arg[2]));\n\
		return 1;\n\
	break;\n\
	case \"mailFileContentTo,rmFile\":\n\
		/* arg[1]	email address\n\
		 * arg[2]	subject line\n\
		 * arg[3]	tmpFileName\n\
		 */\n\
		cmd = concat(\"mail -s \\\"\", arg[2],\n\
				\"\\\" \", arg[1], \" < \", arg[3]);\n\
		/*print(\"CMD >>\", cmd, \"<<\\n\
\");*/\n\
		system(cmd);\n\
		deleteFile(tmpFile);\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_wwwSecurity[] = {
    {"class", _slotValue_wwwSecurity0},
    {"name", _slotValue_wwwSecurity1},
    {"script", _slotValue_wwwSecurity2},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwSrc0[] = "wwwSrc";
static char _slotValue_wwwSrc1[] = "vpane";
static char _slotValue_wwwSrc2[] = "";
static char _slotValue_wwwSrc3[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		cloneID++;\n\
		new = clone(cloneID);\n\
		send(new, \"show_clone\", arg[1], arg[2]);\n\
		send(new, \"visible\", 1);\n\
		return;\n\
	break;\n\
	case \"showByURL\":\n\
		cloneID++;\n\
		new = clone(cloneID);\n\
		send(new, \"show_cloneByURL\", arg[1]);\n\
		send(new, \"visible\", 1);\n\
		return;\n\
	break;\n\
	case \"show_clone\":\n\
		send(nthChild(1), \"show\", arg[1]);\n\
		send(nthChild(2), \"show\", arg[2]);\n\
		return;\n\
	break;\n\
	case \"show_cloneByURL\":\n\
		send(nthChild(1), \"show\", arg[1]);\n\
		send(nthChild(2), \"getAndShow\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"apply\":\n\
	case \"saveAs\":\n\
		return send(nthChild(2), arg[0]);\n\
	break;\n\
	case \"dismiss\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		cloneID = 0;\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwSrc4[] = "600";
static char _slotValue_wwwSrc5[] = "400";
static char _slotValue_wwwSrc6[] = "wwwSrc.ctrl wwwSrc.top wwwSrc.list";
static char _slotValue_wwwSrc7[] = "3";
/* END OF OBJ */

static char _slotValue_wwwSrc9[] = "wwwSrc.ctrl";
static char _slotValue_wwwSrc10[] = "hpane";
static char _slotValue_wwwSrc11[] = "wwwSrc";
static char _slotValue_wwwSrc12[] = "normal";
static char _slotValue_wwwSrc13[] = "wwwSrc.ctrl.ops wwwSrc.ctrl.title wwwSrc.ctrl.dismiss";
static char _slotValue_wwwSrc14[] = "25";
static char _slotValue_wwwSrc15[] = "\n\
	switch (arg[0]) {\n\
	case \"dismiss\":\n\
	case \"saveAs\":\n\
	case \"print\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwSrc16[] = "4";
static char _slotValue_wwwSrc17[] = "3";
/* END OF OBJ */

static char _slotValue_wwwSrc19[] = "wwwSrc.ctrl.ops";
static char _slotValue_wwwSrc20[] = "menu";
static char _slotValue_wwwSrc21[] = "wwwSrc.ctrl";
static char _slotValue_wwwSrc22[] = "File";
static char _slotValue_wwwSrc23[] = "\n\
. {Save as} {send(parent(), \"saveAs\");}\n\
. {Print   (not yet)}\n\
. {\\\\}\n\
. {Dismiss} {send(parent(), \"dismiss\");}\n\
";
static char _slotValue_wwwSrc24[] = "3";
static char _slotValue_wwwSrc25[] = "normal";
static char _slotValue_wwwSrc26[] = "100";
static char _slotValue_wwwSrc27[] = "1";
static char _slotValue_wwwSrc28[] = "2";
/* END OF OBJ */

static char _slotValue_wwwSrc30[] = "wwwSrc.ctrl.title";
static char _slotValue_wwwSrc31[] = "txtLabel";
static char _slotValue_wwwSrc32[] = "wwwSrc.ctrl";
static char _slotValue_wwwSrc33[] = "Document Source";
static char _slotValue_wwwSrc34[] = "normal";
static char _slotValue_wwwSrc35[] = "2";
static char _slotValue_wwwSrc36[] = "2";
/* END OF OBJ */

static char _slotValue_wwwSrc38[] = "wwwSrc.ctrl.dismiss";
static char _slotValue_wwwSrc39[] = "txtButton";
static char _slotValue_wwwSrc40[] = "wwwSrc.ctrl";
static char _slotValue_wwwSrc41[] = "Dismiss";
static char _slotValue_wwwSrc42[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(parent(), \"dismiss\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwSrc43[] = "normal";
static char _slotValue_wwwSrc44[] = "100";
static char _slotValue_wwwSrc45[] = "2";
static char _slotValue_wwwSrc46[] = "2";
/* END OF OBJ */

static char _slotValue_wwwSrc48[] = "wwwSrc.top";
static char _slotValue_wwwSrc49[] = "txtDisp";
static char _slotValue_wwwSrc50[] = "wwwSrc";
static char _slotValue_wwwSrc51[] = "fixed";
static char _slotValue_wwwSrc52[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwSrc53[] = "30";
static char _slotValue_wwwSrc54[] = "5";
/* END OF OBJ */

static char _slotValue_wwwSrc56[] = "wwwSrc.list";
static char _slotValue_wwwSrc57[] = "hpane";
static char _slotValue_wwwSrc58[] = "wwwSrc";
static char _slotValue_wwwSrc59[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
	case \"getAndShow\":\n\
		return send(nthChild(0), arg[0], arg[1]);\n\
	break;\n\
	case \"contentP\":\n\
	case \"print\":\n\
	case \"saveAs\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwSrc60[] = "wwwSrc.list.tf wwwSrc.list.sb";
static char _slotValue_wwwSrc61[] = "4";
static char _slotValue_wwwSrc62[] = "5";
/* END OF OBJ */

static char _slotValue_wwwSrc64[] = "wwwSrc.list.sb";
static char _slotValue_wwwSrc65[] = "slider";
static char _slotValue_wwwSrc66[] = "wwwSrc.list";
static char _slotValue_wwwSrc67[] = "wwwSrc.list.tf";
static char _slotValue_wwwSrc68[] = "20";
/* END OF OBJ */

static char _slotValue_wwwSrc70[] = "wwwSrc.list.tf";
static char _slotValue_wwwSrc71[] = "wwwSrc.list";
static char _slotValue_wwwSrc72[] = "txtEdit";
static char _slotValue_wwwSrc73[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"enter\":\n\
	case \"keyPress\":\n\
	case \"leave\":\n\
		return;\n\
	break;\n\
	case \"getAndShow\":\n\
		cursorShape(\"busy\");\n\
		localFile = HTTPGet(arg[1]);\n\
		set(\"content\", loadFile(localFile));\n\
		system(concat(\"rm -f \", localFile));\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"saveAs\":\n\
		send(\"res.getLineEntry\", \"show\", \n\
			\"Enter file path to save source HTML into:\",\n\
			\"\", self(), \"saveIntoThisFile\");\n\
		return;\n\
	break;\n\
	case \"saveIntoThisFile\":\n\
		if (saveFile(trimEdge(arg[1]), get(\"content\")) == 0) {\n\
			winPos = windowPosition();\n\
			res.dialogWithButtons(\"showAt\", \n\
				winPos[0] + 20, winPos[1] + 20,\n\
				500, 80,\n\
				concat(\"Failed to save source in file:\\n\
\", \n\
					trimEdge(arg[1])),\n\
				\"Dismiss\", \"\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"print\":\n\
		tempf = makeTempFile();\n\
		saveFile(tmpf, get(\"content\"));\n\
		/* need to get printing command */\n\
		system(concat(\"lpr \", tempf));\n\
		return;\n\
	break;\n\
	case \"contentP\":\n\
		return get(\"content\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwSrc74[] = "wwwSrc.list.sb";
static char _slotValue_wwwSrc75[] = "fixed";
static char _slotValue_wwwSrc76[] = "1";
static char _slotValue_wwwSrc77[] = "2";
static char _slotValue_wwwSrc78[] = "7";
/* END OF FILE */

static SlotStruct objDesc_wwwSrc[] = {
    {"name", _slotValue_wwwSrc0},
    {"class", _slotValue_wwwSrc1},
    {"parent", _slotValue_wwwSrc2},
    {"script", _slotValue_wwwSrc3},
    {"width", _slotValue_wwwSrc4},
    {"height", _slotValue_wwwSrc5},
    {"children", _slotValue_wwwSrc6},
    {"border", _slotValue_wwwSrc7},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwSrc9},
    {"class", _slotValue_wwwSrc10},
    {"parent", _slotValue_wwwSrc11},
    {"font", _slotValue_wwwSrc12},
    {"children", _slotValue_wwwSrc13},
    {"maxHeight", _slotValue_wwwSrc14},
    {"script", _slotValue_wwwSrc15},
    {"gapH", _slotValue_wwwSrc16},
    {"gapV", _slotValue_wwwSrc17},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwSrc19},
    {"class", _slotValue_wwwSrc20},
    {"parent", _slotValue_wwwSrc21},
    {"label", _slotValue_wwwSrc22},
    {"menuConfig", _slotValue_wwwSrc23},
    {"border", _slotValue_wwwSrc24},
    {"font", _slotValue_wwwSrc25},
    {"maxWidth", _slotValue_wwwSrc26},
    {"gapV", _slotValue_wwwSrc27},
    {"gapH", _slotValue_wwwSrc28},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwSrc30},
    {"class", _slotValue_wwwSrc31},
    {"parent", _slotValue_wwwSrc32},
    {"label", _slotValue_wwwSrc33},
    {"font", _slotValue_wwwSrc34},
    {"gapV", _slotValue_wwwSrc35},
    {"gapH", _slotValue_wwwSrc36},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwSrc38},
    {"class", _slotValue_wwwSrc39},
    {"parent", _slotValue_wwwSrc40},
    {"label", _slotValue_wwwSrc41},
    {"script", _slotValue_wwwSrc42},
    {"font", _slotValue_wwwSrc43},
    {"maxWidth", _slotValue_wwwSrc44},
    {"gapV", _slotValue_wwwSrc45},
    {"gapH", _slotValue_wwwSrc46},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwSrc48},
    {"class", _slotValue_wwwSrc49},
    {"parent", _slotValue_wwwSrc50},
    {"font", _slotValue_wwwSrc51},
    {"script", _slotValue_wwwSrc52},
    {"maxHeight", _slotValue_wwwSrc53},
    {"gapH", _slotValue_wwwSrc54},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwSrc56},
    {"class", _slotValue_wwwSrc57},
    {"parent", _slotValue_wwwSrc58},
    {"script", _slotValue_wwwSrc59},
    {"children", _slotValue_wwwSrc60},
    {"gapH", _slotValue_wwwSrc61},
    {"gapV", _slotValue_wwwSrc62},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwSrc64},
    {"class", _slotValue_wwwSrc65},
    {"parent", _slotValue_wwwSrc66},
    {"shownNotify", _slotValue_wwwSrc67},
    {"maxWidth", _slotValue_wwwSrc68},
    {(char*)0, (char*)1},
    {"name", _slotValue_wwwSrc70},
    {"parent", _slotValue_wwwSrc71},
    {"class", _slotValue_wwwSrc72},
    {"script", _slotValue_wwwSrc73},
    {"shownDepend", _slotValue_wwwSrc74},
    {"font", _slotValue_wwwSrc75},
    {"verbatim", _slotValue_wwwSrc76},
    {"gapH", _slotValue_wwwSrc77},
    {"border", _slotValue_wwwSrc78},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwURL0[] = "vpane";
static char _slotValue_wwwURL1[] = "wwwURL";
static char _slotValue_wwwURL2[] = "\n\
	switch (arg[0]) {\n\
	case \"open\":\n\
		/* arg[1]	default entry\n\
		 * arg[2]	caller, the obj to return result to\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 * arg[5]	width\n\
		 * arg[6]	height\n\
		 */\n\
		newObj = clone(id);\n\
		id++;\n\
		return send(newObj, \"_open\", \n\
			    arg[1], arg[2], arg[3], arg[4], arg[5], arg[6]);\n\
	break;\n\
	case \"_open\":\n\
		caller = arg[2];\n\
\n\
		set(\"x\", arg[3]);\n\
		set(\"y\", arg[4]);\n\
		set(\"width\", arg[5]);\n\
		set(\"height\", arg[6]);\n\
\n\
		windowName(\"Attention, please...\");\n\
		send(newObj, \"visible\", 1);\n\
		set(\"visible\", 1);\n\
		send(nthChild(1), \"show\", arg[1]);\n\
		return self();\n\
	break;\n\
	case \"_cut\":\n\
	case \"_clear\":\n\
		send(nthChild(1), arg[0]);\n\
		return;\n\
	break;\n\
	case \"_ok\":\n\
		set(\"visible\", 0);\n\
		send(caller, \"gotURLToOpen\", send(nthChild(1), \"contentP\"));\n\
		return;\n\
	break;\n\
	case \"_cancel\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwURL3[] = "wwwURL.mesg wwwURL.entry wwwURL.buttons";
static char _slotValue_wwwURL4[] = "3";
/* END OF OBJ */

static char _slotValue_wwwURL6[] = "txtDisp";
static char _slotValue_wwwURL7[] = "wwwURL.mesg";
static char _slotValue_wwwURL8[] = "wwwURL";
static char _slotValue_wwwURL9[] = "20";
static char _slotValue_wwwURL10[] = "5";
static char _slotValue_wwwURL11[] = "4";
static char _slotValue_wwwURL12[] = "Enter URL to Open:";
static char _slotValue_wwwURL13[] = "normal";
/* END OF OBJ */

static char _slotValue_wwwURL15[] = "txtEdit";
static char _slotValue_wwwURL16[] = "wwwURL.entry";
static char _slotValue_wwwURL17[] = "wwwURL";
static char _slotValue_wwwURL18[] = "\n\
	switch (arg[0]) {\n\
	case \"keyPress\":\n\
		c = key();\n\
		if (c == '\\r') send(parent(), \"_ok\");\n\
		else insert(c);\n\
		return;\n\
	break;\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"contentP\":\n\
		return get(\"content\");\n\
	break;\n\
	case \"_cut\":\n\
		set(\"content\", trimEdge(getSelection()));\n\
		render();\n\
		return;\n\
	break;\n\
	case \"_clear\":\n\
		set(\"content\", \"\");\n\
		render();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwURL19[] = "5";
static char _slotValue_wwwURL20[] = "1";
static char _slotValue_wwwURL21[] = "fixed";
/* END OF OBJ */

static char _slotValue_wwwURL23[] = "hpane";
static char _slotValue_wwwURL24[] = "wwwURL.buttons";
static char _slotValue_wwwURL25[] = "wwwURL";
static char _slotValue_wwwURL26[] = "wwwURL.buttons.ok wwwURL.buttons.cancel wwwURL.buttons.cut wwwURL.buttons.clear";
static char _slotValue_wwwURL27[] = "\n\
	switch (arg[0]) {\n\
	case \"_cancel\":\n\
	case \"_ok\":\n\
	case \"_cut\":\n\
	case \"_clear\":\n\
		send(parent(), arg[0]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwURL28[] = "25";
static char _slotValue_wwwURL29[] = "4";
static char _slotValue_wwwURL30[] = "3";
/* END OF OBJ */

static char _slotValue_wwwURL32[] = "txtButton";
static char _slotValue_wwwURL33[] = "Use Selected";
static char _slotValue_wwwURL34[] = "wwwURL.buttons.cut";
static char _slotValue_wwwURL35[] = "wwwURL.buttons";
static char _slotValue_wwwURL36[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(parent(), \"_cut\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwURL37[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL39[] = "txtButton";
static char _slotValue_wwwURL40[] = "Clear";
static char _slotValue_wwwURL41[] = "wwwURL.buttons.clear";
static char _slotValue_wwwURL42[] = "wwwURL.buttons";
static char _slotValue_wwwURL43[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(parent(), \"_clear\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwURL44[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL46[] = "txtButton";
static char _slotValue_wwwURL47[] = "OK";
static char _slotValue_wwwURL48[] = "wwwURL.buttons.ok";
static char _slotValue_wwwURL49[] = "wwwURL.buttons";
static char _slotValue_wwwURL50[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(parent(), \"_ok\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwURL51[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL53[] = "txtButton";
static char _slotValue_wwwURL54[] = "Cancel";
static char _slotValue_wwwURL55[] = "wwwURL.buttons.cancel";
static char _slotValue_wwwURL56[] = "wwwURL.buttons";
static char _slotValue_wwwURL57[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(parent(), \"_cancel\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_wwwURL58[] = "10";
/* END OF FILE */

static SlotStruct objDesc_wwwURL[] = {
    {"class", _slotValue_wwwURL0},
    {"name", _slotValue_wwwURL1},
    {"script", _slotValue_wwwURL2},
    {"children", _slotValue_wwwURL3},
    {"border", _slotValue_wwwURL4},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwURL6},
    {"name", _slotValue_wwwURL7},
    {"parent", _slotValue_wwwURL8},
    {"maxHeight", _slotValue_wwwURL9},
    {"gapH", _slotValue_wwwURL10},
    {"gapV", _slotValue_wwwURL11},
    {"content", _slotValue_wwwURL12},
    {"font", _slotValue_wwwURL13},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwURL15},
    {"name", _slotValue_wwwURL16},
    {"parent", _slotValue_wwwURL17},
    {"script", _slotValue_wwwURL18},
    {"gapH", _slotValue_wwwURL19},
    {"gapV", _slotValue_wwwURL20},
    {"font", _slotValue_wwwURL21},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwURL23},
    {"name", _slotValue_wwwURL24},
    {"parent", _slotValue_wwwURL25},
    {"children", _slotValue_wwwURL26},
    {"script", _slotValue_wwwURL27},
    {"maxHeight", _slotValue_wwwURL28},
    {"gapH", _slotValue_wwwURL29},
    {"gapV", _slotValue_wwwURL30},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwURL32},
    {"label", _slotValue_wwwURL33},
    {"name", _slotValue_wwwURL34},
    {"parent", _slotValue_wwwURL35},
    {"script", _slotValue_wwwURL36},
    {"gapH", _slotValue_wwwURL37},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwURL39},
    {"label", _slotValue_wwwURL40},
    {"name", _slotValue_wwwURL41},
    {"parent", _slotValue_wwwURL42},
    {"script", _slotValue_wwwURL43},
    {"gapH", _slotValue_wwwURL44},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwURL46},
    {"label", _slotValue_wwwURL47},
    {"name", _slotValue_wwwURL48},
    {"parent", _slotValue_wwwURL49},
    {"script", _slotValue_wwwURL50},
    {"gapH", _slotValue_wwwURL51},
    {(char*)0, (char*)1},
    {"class", _slotValue_wwwURL53},
    {"label", _slotValue_wwwURL54},
    {"name", _slotValue_wwwURL55},
    {"parent", _slotValue_wwwURL56},
    {"script", _slotValue_wwwURL57},
    {"gapH", _slotValue_wwwURL58},
    {(char*)0, (char*)0},
};

static char _slotValue_mvw0[] = "vpane";
static char _slotValue_mvw1[] = "mvw";
static char _slotValue_mvw2[] = "mvw.doc";
static char _slotValue_mvw3[] = "\n\
/*for(i=0; i<arg[]; i++) print(\"MVW arg[\",i,\"]={\", arg[i], \"}\\n\
\");*/\n\
\n\
	/* This is a GUI-less version of www.v, which the Motif frontend\n\
	 * wraps around of.\n\
	 *\n\
	 * Author: 	Pei Y. Wei\n\
	 */\n\
\n\
	/* URL port configurtion. 0 == off.\n\
	 */\n\
	URLPort = 0;\n\
\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		/* message from Motif interface shell */\n\
		return send(\"mvw.doc.view.pane\", arg[0], arg[1]);\n\
     	break;\n\
	case \"historyList_selectedItem\":\n\
		return send(\"mvwHistory\", arg[0], arg[1]);\n\
     	break;\n\
	case \"hotlistList_add\":\n\
		url = send(\"mvw\", \"getCurrentDocURL\");\n\
		comment = send(\"mvw\", \"getCurrentDocTitle\");\n\
		HTTPHotListAdd(url, comment, date());\n\
		return comment;\n\
	break;\n\
	case \"hotlistList_goto\":\n\
		return send(\"mvw\", \"show\", HTTPHotListGet(0, arg[1]));\n\
	break;\n\
	case \"hotlistList_delete\":\n\
		url = send(\"mvw\", \"getCurrentDocURL\");\n\
		comment = send(\"mvw\", \"getCurrentDocTitle\");\n\
		return 0;\n\
	break;\n\
	case \"hotlistList_edit\":\n\
		url = send(\"mvw\", \"getCurrentDocURL\");\n\
		comment = send(\"mvw\", \"getCurrentDocTitle\");\n\
		return 0;\n\
     	break;\n\
	case \"cloneApp\":\n\
		/* arg[1]	cookie -- is a unique token to be passed back\n\
		 */\n\
		new = clone(cookie);\n\
		return sendToInterface(\"showAppClone\", cookie, new);\n\
	break;\n\
	case \"clonePage\":\n\
	case \"saveAs\":\n\
		/* arg[1]	cookie\n\
		 */\n\
		return send(nthChild(0), arg[0], arg[1]);\n\
	break;\n\
	case \"reload\":\n\
	case \"showSource\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	case \"historyQuery\":\n\
		/* arg[1]	cookie\n\
		 */\n\
		return mvwHistory(\"historyQuery\", arg[1]);\n\
	break;\n\
	case \"showPageClone_return\":\n\
		/* arg[1] must be the cookie */\n\
		return sendToInterface(\"showPageClone\", arg[1], arg[2]);\n\
	break;\n\
	case \"show\":\n\
	case \"post\":\n\
		if (arg[] == 2)\n\
			stat = send(\"mvw.doc.view.pane\", arg[0], arg[1]);\n\
		else if (arg[] == 3)\n\
			stat = send(\"mvw.doc.view.pane\", arg[0], arg[1], \n\
							 arg[2]);\n\
		else	stat = send(\"mvw.doc.view.pane\", arg[0], arg[1], \n\
							 arg[2], arg[3]);\n\
		if (stat) stat = send(\"mvw.doc.view.pane\", \"historyRecord\");\n\
		return stat;\n\
	break;\n\
	case \"show_URL_in_selectionBuffer\":\n\
		return send(\"mvw.doc.view.pane\", \"show\",\n\
				trimEdge(getSelection()));\n\
	break;\n\
	case \"showDoc\":\n\
	case \"showHistoryDoc\":\n\
		if (arg[] == 2) {\n\
			stat = send(\"mvw.doc.view.pane\", \"show\", arg[1]);\n\
		} else {\n\
			stat = send(\"mvw.doc.view.pane\", \"show\", arg[1],\n\
					arg[2]);\n\
		}\n\
		send(\"www.doc.view.pane\", \"historyRecord\");/*XXX*/\n\
		return stat;\n\
	break;\n\
	case \"showHistory\":\n\
		/* arg[1]	cookie\n\
		 * arg[2]	position in history list\n\
		 */\n\
		return mvwHistory(\"showByPosition\", arg[1], arg[2]);\n\
	break;\n\
	case \"addToHistory\":\n\
		send(\"mvwHistory\", \"add\", arg[1], arg[2]);\n\
		return;\n\
	break;\n\
	case \"changeFonts\":\n\
		send(\"res.font\", arg[1]);\n\
		/* bug: only main viewer is told of the font change */\n\
		send(\"mvw.doc.view.pane\", \"configSelf\");\n\
		return;\n\
	break;\n\
	case \"group\":\n\
		mvw.doc.title.icon(\"group\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"destroyDoc\":\n\
		return mvw.doc.view.pane(\"destroyDoc\");\n\
	break;\n\
	case \"search\":\n\
		mvw.doc.view.pane(\"search\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"showButNoRecord\":\n\
		mvw.doc.view.pane(\"show\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"get_infoOnViolaWWW\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://berkeley.ora.com/proj/viola/vw/about_3.3.html\");\n\
		return;\n\
	break;\n\
	case \"get_helpOnViolaWWW\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://berkeley.ora.com/proj/viola/vw/help_xvw_3.3.html\");\n\
		return;\n\
	break;\n\
	case \"get_demoForViolaWWW\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://berkeley.ora.com/proj/viola/violaCentral.html\");\n\
		return;\n\
	break;\n\
	case \"get_gnnWIC\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://nearnet.gnn.com/wic/newrescat.toc.html\");\n\
		return;\n\
	break;\n\
	case \"get_cern\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://info.cern.ch/hypertext/DataSources/WWW/Servers.html\");\n\
		return;\n\
	break;\n\
	case \"get_moreServers\":\n\
		send(\"www\", \"showHistoryDoc\", \n\
		 \"http://berkeley.ora.com/proj/viola/metaCenters.html\");\n\
		return;\n\
	break;\n\
	case \"printDoc\":\n\
		/* arg[1]	printCmd\n\
		 */\n\
		return;\n\
	break;\n\
	case \"saveDoc\":\n\
		/* arg[1]	file path\n\
		 */\n\
		return;\n\
	break;\n\
	case \"saveSource\":\n\
		return;\n\
	break;\n\
	case \"queryDocSecurity\":\n\
		/* for interface to get doc level security level */\n\
	break;\n\
	case \"setSecurityClearence\":\n\
		/* coming from interace */\n\
	break;\n\
	case \"querySecurityClearence\":\n\
		/* send to interface */\n\
	break;\n\
	case \"home\":\n\
		cursorShape(\"busy\");\n\
		mvw.doc.view.pane(\"showHistoryDoc\", homeDoc);\n\
		mvw.doc.view.pane(\"historyRecord\");\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"prev\":\n\
		cursorShape(\"busy\");\n\
		wantIt = mvwHistory(\"prev\");\n\
		if (isBlank(wantIt) == 0) {\n\
			mvw.doc.view.pane(\"showHistoryDoc\", wantIt);\n\
			sendToInterface(\"prev\", cookie);\n\
		}\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"next\":\n\
		cursorShape(\"busy\");\n\
		wantIt = mvwHistory(\"next\");\n\
		if (isBlank(wantIt) == 0) {\n\
			mvw.doc.view.pane(\"showHistoryDoc\", wantIt);\n\
			sendToInterface(\"next\", cookie);\n\
		}\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"back\":\n\
		cursorShape(\"busy\");\n\
		wantIt = mvwHistory(\"back\");\n\
		if (isBlank(wantIt) == 0) {\n\
			mvw.doc.view.pane(\"showHistoryDoc\", wantIt);\n\
			sendToInterface(\"back\", cookie);\n\
		}\n\
		cursorShape(\"idle\");\n\
		return;\n\
	break;\n\
	case \"busy\":\n\
		sendToInterface(\"busyCursor\", cookie);\n\
		return cursorShape(arg[0]);\n\
	break;\n\
	case \"idle\":\n\
		sendToInterface(\"idleCursor\", cookie);\n\
		return cursorShape(arg[0]);\n\
	break;\n\
	case \"quit\":\n\
		quit();\n\
	break;\n\
	case \"homeDocP\":\n\
		return homeDoc;\n\
	break;\n\
	case \"getCurrentDocURL\":\n\
	case \"getCurrentDocTitle\":\n\
		send(\"mvw.doc.view.pane\", arg[0]);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
\n\
		homeDoc = environVar(\"WWW_HOME\");\n\
		if (isBlank(homeDoc) == 1)\n\
			homeDoc = \"http://info.cern.ch/hypertext/WWW/TheProject.html\";\n\
		if (nthChar(homeDoc, 0) == '/')\n\
			homeDoc = concat(\"file:\", homeDoc);\n\
\n\
		HTTPHotListLoad();\n\
\n\
		if (URLPort > 0) {\n\
			print(\"WARNING: port number \", URLPort,\n\
			\" is now being used to accept URL fetch directives.\");\n\
			if (send(mvwDocuPort(\"listen\", URLPort))) {\n\
				print(\"ERROR: Sorry, failed to open port \",\n\
				URLPort, \" for listening to URL fetches\\n\
\");\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		send(\"mvw.doc.view.pane\", \"outputSGML\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_mvw5[] = "generic";
static char _slotValue_mvw6[] = "www";
static char _slotValue_mvw7[] = "\n\
	/* message forwarding service */\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
	case \"post\":\n\
		if (arg[] == 2) \n\
			return send(\"mvw\", arg[0], arg[1]);\n\
		else if (arg[] == 3) \n\
			return send(\"mvw\", arg[0], arg[1], arg[2]);\n\
		else\n\
			return send(\"mvw\", arg[0], arg[1], arg[2], arg[3]);\n\
	break;\n\
	case \"home\":\n\
	case \"prev\":\n\
	case \"next\":\n\
	case \"showDoc\":\n\
	case \"showHistoryDoc\":\n\
	case \"destroyDoc\":\n\
		return send(\"mvw\", arg[0], arg[1]);\n\
	break;\n\
	case \"addToHistory\":\n\
		return send(\"mvwHistory\", \"add\", arg[1], arg[2]);\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_mvw9[] = "vpane";
static char _slotValue_mvw10[] = "mvw.doc";
static char _slotValue_mvw11[] = "mvw";
static char _slotValue_mvw12[] = "mvw.doc.url mvw.doc.title mvw.doc.view";
static char _slotValue_mvw13[] = "\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		return send(nthChild(2), arg[0], arg[1]);\n\
	break;\n\
	case \"addTool\":\n\
	case \"addTool_sticky\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(\"mvwTools\", arg[0], arg[1]);\n\
	break;\n\
	case \"clear\":\n\
		return send(\"mvwTools\", arg[0]);\n\
	break;\n\
	case \"reload\":\n\
	case \"showSource\":\n\
		return send(nthChild(2), arg[0]);\n\
	break;\n\
	case \"saveAs\":\n\
		return send(nthChild(2), arg[0], arg[1]);\n\
	break;\n\
	case \"clonePage\":\n\
		/* arg[1]	cookie\n\
		 */\n\
		send(nthChild(2), \"clonePage\");\n\
		tearPageID = tearPageID + 1;\n\
		new = clone(tearPageID);\n\
		tweak(new, \"set(\\\"parent\\\", \\\"\\\");\");\n\
		send(new, \"torn\", send(nthChild(2), \"whichPageP\"), arg[1]);\n\
		send(parent(), \"showPageClone_return\", arg[1], new);\n\
		return;\n\
	break;\n\
	case \"tear\":\n\
		tearPageID = tearPageID + 1;\n\
		new = clone(tearPageID);\n\
		tweak(new, \"set(\\\"parent\\\", \\\"\\\");\");\n\
		send(new, \"torn\", send(nthChild(2), \"whichPageP\"));\n\
		send(new, \"render\");\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		set(\"label\", \n\
			send(send(nthChild(2), \"whichPageP\"), \"queryAddress\"));\n\
		objectListSend_children(\"torn\", arg[1], arg[2]);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		tearPageID = 0;\n\
		return;\n\
	break;\n\
	case \"whichPageP\":\n\
		return send(nthChild(2), \"whichPageP\");\n\
	break;\n\
	case \"quit\":\n\
		set(\"visible\", 0);\n\
		/*XXX should destroy */\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_mvw15[] = "txtDisp";
static char _slotValue_mvw16[] = "mvw.doc.url";
static char _slotValue_mvw17[] = "mvw.doc";
static char _slotValue_mvw18[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", arg[1]);\n\
		render();\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw19[] = "6";
static char _slotValue_mvw20[] = "black";
static char _slotValue_mvw21[] = "fixed";
static char _slotValue_mvw22[] = "20";
static char _slotValue_mvw23[] = "3";
static char _slotValue_mvw24[] = "2";
/* END OF OBJ */

static char _slotValue_mvw26[] = "hpane";
static char _slotValue_mvw27[] = "mvwTools";
static char _slotValue_mvw28[] = "mvw.doc.tools.httpStat mvw.doc.tools.sys mvw.doc.tools.dyna";
static char _slotValue_mvw29[] = "\n\
	switch (arg[0]) {\n\
	case \"addTool\":\n\
	case \"addTool_sticky\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(nthChild(2), arg[0], arg[1]);\n\
	break;\n\
	case \"clear\":\n\
		return send(nthChild(2), arg[0]);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw30[] = "45";
/* END OF OBJ */

static char _slotValue_mvw32[] = "hpane";
static char _slotValue_mvw33[] = "mvw.doc.tools.dyna";
static char _slotValue_mvw34[] = "mvwTools";
static char _slotValue_mvw35[] = "\n\
	switch (arg[0]) {\n\
	case \"addTool\":\n\
	case \"addTool_sticky\":\n\
		new = object(arg[1]);\n\
		for (i = objectListCount_children(); i >= 0; i--) \n\
			if (nthChild(i) == new) return 1;\n\
		objectListAppend(\"children\", new);\n\
		tweak(new, concat(\"set(\\\"parent\\\", \\\"\", self(), \"\\\");\"));\n\
		send(new, \"visible\", 1);\n\
		config();\n\
		return 1;\n\
	break;\n\
	case \"removeTool\":\n\
		new = object(arg[1]);\n\
		objectListDelete(\"children\", new);\n\
		send(new, \"visible\", 0);\n\
		config();\n\
		return 1;\n\
	break;\n\
	case \"destroyTool\":\n\
		new = object(arg[1]);\n\
		objectListDelete(\"children\", new);\n\
		send(new, \"visible\", 0);\n\
		send(new, \"freeSelf\");\n\
		config();\n\
		return 1;\n\
	break;\n\
	case \"clear\":\n\
		set(\"children\", \"\");\n\
		return;\n\
	break;\n\
	case \"go_url\":\n\
		return send(\"mvw\", \"show\", arg[1]);\n\
	break;\n\
	case \"go_home\":\n\
		return send(\"mvw\", \"home\");\n\
	break;\n\
	case \"go_prev\":\n\
		return send(\"mvw\", \"prev\");\n\
	break;\n\
	case \"go_next\":\n\
		return send(\"mvw\", \"next\");\n\
	break;\n\
	case \"go_back\":\n\
		return send(\"mvw\", \"back\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw36[] = "2";
/* END OF OBJ */

static char _slotValue_mvw38[] = "hpane";
static char _slotValue_mvw39[] = "mvw.doc.tools.sys";
static char _slotValue_mvw40[] = "mvwTools";
static char _slotValue_mvw41[] = "mvw.doc.tools.sys.home mvw.doc.tools.sys.back mvw.doc.tools.sys.prev mvw.doc.tools.sys.next mvw.doc.tools.sys.reload";
static char _slotValue_mvw42[] = "171";
/* END OF OBJ */

static char _slotValue_mvw44[] = "XPMButton";
static char _slotValue_mvw45[] = "mvw.doc.tools.sys.home";
static char _slotValue_mvw46[] = "mvw.doc.tools.sys";
static char _slotValue_mvw47[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"mvw\",\"home\");\n\
	break;\n\
	case \"enter\":\n\
		send(\"www.mesg.tf\", \"suggest\", \n\
			\"Click the house icon to visit home page.\");\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"clear\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw48[] = "/* XPM */\n\
static char * home [] = {\n\
\"32 32 9 1\",\n\
\" 	c black\",\n\
\".	c white\",\n\
\"X	c grey75\",\n\
\"o	c gray30\",\n\
\"O	c red\",\n\
\"+	c #E0E0D0D0B0B0\",\n\
\"@	c lightyellow\",\n\
\"#	c gray\",\n\
\"$	c gray50\",\n\
\"                                \",\n\
\" .............................  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\
\" .XXXXXXXXXX       XXXXXXXXXXo  \",\n\
\" .XXXXXXXXX OOOOOOO XXXXXXXXXo  \",\n\
\" .XXXXXXXX O+@OOOOOO XXXXXXXXo  \",\n\
\" .XXXXXXXX O+@@OOOOOO XXXXXXXo  \",\n\
\" .XXXXXXX O+@@@OOOOOOO XXXXXXo  \",\n\
\" .XXXXXX O+@@@@@OOOOOOO XXXXXo  \",\n\
\" .XXXXX O+@@@@@@@OOOOOOO XXXXo  \",\n\
\" .XXXXX O+@@@@@@@@OOOOOOO XXXo  \",\n\
\" .XXXX O+@@@@@@@@@OOOOOOOO XXo  \",\n\
\" .XXX O+@@@#####@@@OOOO++ XXXo  \",\n\
\" .XXXX  @@@#   #@@@@+++++ XXXo  \",\n\
\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\
\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\
\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\
\" .XXXXX @@@#   #@@@@++++  XXXo  \",\n\
\" .XXXXX @@@#   #@@@@++  XXXXXo  \",\n\
\" .XXXXXX             XXXXXXXXo  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\
\" .XXXX XX X$  $X XXX X   XXXXo  \",\n\
\" .XXXX XX X XX X  X  X XXXXXXo  \",\n\
\" .XXXX    X XX X $ $ X  XXXXXo  \",\n\
\" .XXXX XX X XX X X X X XXXXXXo  \",\n\
\" .XXXX XX X XX X XXX X XXXXXXo  \",\n\
\" .XXXX XX X$  $X XXX X   XXXXo  \",\n\
\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\
\" .oooooooooooooooooooooooooooo  \",\n\
\"                                \",\n\
\"                                \"};\n\
";
static char _slotValue_mvw49[] = "32";
static char _slotValue_mvw50[] = "1";
static char _slotValue_mvw51[] = "2";
/* END OF OBJ */

static char _slotValue_mvw53[] = "XPMButton";
static char _slotValue_mvw54[] = "mvw.doc.tools.sys.back";
static char _slotValue_mvw55[] = "mvw.doc.tools.sys";
static char _slotValue_mvw56[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"mvw\", \"back\");\n\
	break;\n\
	case \"enter\":\n\
		send(\"www.mesg.tf\", \"suggest\", \n\
			\"Click to go roll back the history list (destructive back up).\");\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"clear\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw57[] = "/* XPM */\n\
static char * back [] = {\n\
\"32 32 7 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c gray\",\n\
\"O	c gray30\",\n\
\"+	c gray50\",\n\
\"@	c grey75\",\n\
\"............................... \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xooooooooooooo.oooooooooooooO. \",\n\
\".Xoooooooooooo.+.ooooooooooooO. \",\n\
\".Xoooooooooooo.+.ooooooooooooO. \",\n\
\".Xooooooooooo.+++.oooooooooooO. \",\n\
\".Xooooooooooo.+++.oooooooooooO. \",\n\
\".Xoooooooooo.+++++.ooooooooooO. \",\n\
\".Xoooooooooo.+++++.ooooooooooO. \",\n\
\".Xooooooooo.+++++++.oooooooooO. \",\n\
\".Xooooooooo.+++++++.oooooooooO. \",\n\
\".Xoooooooo.+++++++++.ooooooooO. \",\n\
\".Xoooooooo.+++++++++.ooooooooO. \",\n\
\".Xooooooo.+++++++++++.oooooooO. \",\n\
\".Xooooooo.+++++++++++.oooooooO. \",\n\
\".Xoooooo.+++++++++++++.ooooooO. \",\n\
\".Xoooooo.+++++++++++++.ooooooO. \",\n\
\".Xooooooo.............oooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xoooo...+oo+.+oo+..o.oo.ooooO. \",\n\
\".Xoooo.oo.oo.o.oo.ooo.o.oooooO. \",\n\
\".Xoooo...ooo.o.oo.ooo..ooooooO. \",\n\
\".Xoooo.oo.o+...+o.ooo..ooooooO. \",\n\
\".Xoooo.oo.o.+o+.o.ooo.@.oooooO. \",\n\
\".Xoooo...+o.ooo.o+..o.oo.ooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\
\"............................... \",\n\
\"                                \"};\n\
";
static char _slotValue_mvw58[] = "32";
static char _slotValue_mvw59[] = "1";
static char _slotValue_mvw60[] = "2";
/* END OF OBJ */

static char _slotValue_mvw62[] = "XPMButton";
static char _slotValue_mvw63[] = "mvw.doc.tools.sys.prev";
static char _slotValue_mvw64[] = "mvw.doc.tools.sys";
static char _slotValue_mvw65[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"mvw\", \"prev\");\n\
	break;\n\
	case \"enter\":\n\
		send(\"www.mesg.tf\", \"suggest\",\n\
			\"Click to visit the previous document.\");\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"clear\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw66[] = "/* XPM */\n\
static char * prev [] = {\n\
\"32 32 6 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c grey75\",\n\
\"O	c gray30\",\n\
\"+	c gray50\",\n\
\"............................... \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xoooooooooooooooooo..oooooooO. \",\n\
\".Xoooooooooooooooo..++.ooooooO. \",\n\
\".Xoooooooooooooo..++++.ooooooO. \",\n\
\".Xoooooooooooo..++++++.ooooooO. \",\n\
\".Xoooooooooo..++++++++.ooooooO. \",\n\
\".Xoooooooo..++++++++++.ooooooO. \",\n\
\".Xooooooo.++++++++++++.ooooooO. \",\n\
\".Xooooo.++++++++++++++.ooooooO. \",\n\
\".Xoooooo..++++++++++++.ooooooO. \",\n\
\".Xoooooooo..++++++++++.ooooooO. \",\n\
\".Xoooooooooo..++++++++.ooooooO. \",\n\
\".Xoooooooooooo..++++++.ooooooO. \",\n\
\".Xoooooooooooooo..++++.ooooooO. \",\n\
\".Xoooooooooooooooo..++.ooooooO. \",\n\
\".Xoooooooooooooooooo..oooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xoooo...+o...+o...o.ooo.ooooO. \",\n\
\".Xoooo.oo.o.oo.o.ooo.ooo.ooooO. \",\n\
\".Xoooo.oo.o...+o..oo.+o+.ooooO. \",\n\
\".Xoooo...+o.o.oo.oooo.o.oooooO. \",\n\
\".Xoooo.oooo.oo.o.oooo.+.oooooO. \",\n\
\".Xoooo.oooo.oo.o...ooo.ooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\
\"............................... \",\n\
\"                                \"};\n\
";
static char _slotValue_mvw67[] = "32";
static char _slotValue_mvw68[] = "1";
static char _slotValue_mvw69[] = "2";
/* END OF OBJ */

static char _slotValue_mvw71[] = "XPMButton";
static char _slotValue_mvw72[] = "mvw.doc.tools.sys.next";
static char _slotValue_mvw73[] = "mvw.doc.tools.sys";
static char _slotValue_mvw74[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"mvw\", \"next\");\n\
	break;\n\
	case \"enter\":\n\
		send(\"www.mesg.tf\", \"suggest\",\n\
			\"Click to visit the next document.\");\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"clear\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw75[] = "/* XPM */\n\
static char * next [] = {\n\
\"32 32 6 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c grey75\",\n\
\"O	c gray30\",\n\
\"+	c gray50\",\n\
\"............................... \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xoooooooo..oooooooooooooooooO. \",\n\
\".Xooooooo.++..oooooooooooooooO. \",\n\
\".Xooooooo.++++..oooooooooooooO. \",\n\
\".Xooooooo.++++++..oooooooooooO. \",\n\
\".Xooooooo.++++++++..oooooooooO. \",\n\
\".Xooooooo.++++++++++..oooooooO. \",\n\
\".Xooooooo.++++++++++++..oooooO. \",\n\
\".Xooooooo.++++++++++++++.ooooO. \",\n\
\".Xooooooo.++++++++++++..oooooO. \",\n\
\".Xooooooo.++++++++++..oooooooO. \",\n\
\".Xooooooo.++++++++..oooooooooO. \",\n\
\".Xooooooo.++++++..oooooooooooO. \",\n\
\".Xooooooo.++++..oooooooooooooO. \",\n\
\".Xooooooo.++..oooooooooooooooO. \",\n\
\".Xoooooooo..oooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xooo.+oo.o...o.ooo.o.....oooO. \",\n\
\".Xooo..+o.o.ooo+.o.+ooo.oooooO. \",\n\
\".Xooo.o.+.o..+oo+.+oooo.oooooO. \",\n\
\".Xooo.oo..o.oooo+.+oooo.oooooO. \",\n\
\".Xooo.ooo.o.ooo+.o.+ooo.oooooO. \",\n\
\".Xooo.ooo.o...o.ooo.ooo.oooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\
\"............................... \",\n\
\"                                \"};\n\
";
static char _slotValue_mvw76[] = "32";
static char _slotValue_mvw77[] = "1";
static char _slotValue_mvw78[] = "2";
/* END OF OBJ */

static char _slotValue_mvw80[] = "XPMButton";
static char _slotValue_mvw81[] = "mvw.doc.tools.sys.reload";
static char _slotValue_mvw82[] = "mvw.doc.tools.sys";
static char _slotValue_mvw83[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(\"mvw\", \"reload\");\n\
	break;\n\
	case \"enter\":\n\
		send(\"www.mesg.tf\", \"suggest\", \"Click to reload the document\");\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"clear\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw84[] = "/* XPM */\n\
static char * reload [] = {\n\
\"32 32 6 1\",\n\
\" 	c black\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c gray\",\n\
\"O	c gray30\",\n\
\"+	c red\",\n\
\"............................... \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xooooooo...........oooooooooO. \",\n\
\".Xooooooo.XXXXXXXX.X.ooooooooO. \",\n\
\".Xoooo+++.X......X.XX.oooooooO. \",\n\
\".Xoooo+++.XXXXXXXX.XXX.ooooooO. \",\n\
\".Xoooo+...X......X.....ooooooO. \",\n\
\".Xoooo+++.XXXXXXXXXXXX.ooooooO. \",\n\
\".Xoooo+...X.........XX.ooooooO. \",\n\
\".Xoooo+++.XXXXXXXXXXXX.ooooooO. \",\n\
\".Xoooo+...X.........XX.ooooooO. \",\n\
\".Xoooo+++.XXXXXXXXXXXX.ooooooO. \",\n\
\".Xoooo+...X.........XX.ooooooO. \",\n\
\".Xoooo+++.XXXXXXXXXXXX.ooooooO. \",\n\
\".Xoooo+................ooooooO. \",\n\
\".Xoooo++++++++++++++oooooooooO. \",\n\
\".Xoooo+...........++oooooooooO. \",\n\
\".Xoooo++++++++++++++oooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xoo...Oo...o.ooO.OoO.Oo..oooO. \",\n\
\".Xoo.oo.o.ooo.oo.o.o.O.o.o.ooO. \",\n\
\".Xoo...Oo..oo.oo.o.o.o.o.o.ooO. \",\n\
\".Xoo.o.oo.ooo.oo.o.o...o.o.ooO. \",\n\
\".Xoo.oo.o.ooo.oo.o.o.o.o.o.ooO. \",\n\
\".Xoo.oo.o...o..oO.Oo.o.o..oooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\
\"............................... \",\n\
\"                                \"};\n\
";
static char _slotValue_mvw85[] = "32";
static char _slotValue_mvw86[] = "1";
static char _slotValue_mvw87[] = "2";
/* END OF OBJ */

static char _slotValue_mvw89[] = "XPMButton";
static char _slotValue_mvw90[] = "mvw.doc.tools.ops.clone";
static char _slotValue_mvw91[] = "mvw.doc.tools.ops";
static char _slotValue_mvw92[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		sendToInterface(\"clone\");\n\
	break;\n\
	case \"enter\":\n\
		send(\"www.mesg.tf\", \"suggest\", \"Click to clone the document\");\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		send(\"www.mesg.tf\", \"clear\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw93[] = "/* XPM */\n\
static char * clone [] = {\n\
\"32 32 5 1\",\n\
\" 	s None	c None\",\n\
\".	c black\",\n\
\"X	c white\",\n\
\"o	c gray\",\n\
\"O	c gray30\",\n\
\"............................... \",\n\
\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xooo..........ooooooooooooooO. \",\n\
\".Xooo.XXXXXXX.X.oooooooooooooO. \",\n\
\".Xooo.X....XX.XX.ooooooooooooO. \",\n\
\".Xooo.XXXXXXX.XXX.oooooooooooO. \",\n\
\".Xooo.X.....X.....oooooooooooO. \",\n\
\".Xooo.XXXXXXXXXXX.oooooooooooO. \",\n\
\".Xooo.X......X.........ooooooO. \",\n\
\".Xooo.XXXXXXXX.XXXXXX.X.oooooO. \",\n\
\".Xooo.X......X.X...XX.XX.ooooO. \",\n\
\".Xooo.XXXXXXXX.XXXXXX.XXX.oooO. \",\n\
\".Xooo.X......X.X....X.....oooO. \",\n\
\".Xooo.XXXXXXXX.XXXXXXXXXX.oooO. \",\n\
\".Xooo.XXXXXXXX.X........X.oooO. \",\n\
\".Xooo..........XXXXXXXXXX.oooO. \",\n\
\".Xoooooooooooo.X........X.oooO. \",\n\
\".Xoooooooooooo.XXXXXXXXXX.oooO. \",\n\
\".Xoooooooooooo.XXXXXXXXXX.oooO. \",\n\
\".Xoooooooooooo............oooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".Xooooo..o.oo...o.Oo.o...ooooO. \",\n\
\".Xoooo.Ooo.oo.o.o..o.o.ooooooO. \",\n\
\".Xoooo.ooo.oo.o.o.o..o..oooooO. \",\n\
\".Xoooo.ooo.oo.o.o.oO.o.ooooooO. \",\n\
\".Xoooo.Ooo.oo.o.o.oo.o.ooooooO. \",\n\
\".Xooooo..o..o...o.oo.o...ooooO. \",\n\
\".XoooooooooooooooooooooooooooO. \",\n\
\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\
\"............................... \",\n\
\"                                \"};\n\
";
static char _slotValue_mvw94[] = "32";
static char _slotValue_mvw95[] = "1";
static char _slotValue_mvw96[] = "2";
/* END OF OBJ */

/* END OF OBJ */

static char _slotValue_mvw99[] = "hpane";
static char _slotValue_mvw100[] = "mvwTools";
static char _slotValue_mvw101[] = "mvw.doc.tools.httpStat";
static char _slotValue_mvw102[] = "mvw.doc.tools.httpStat.icon";
static char _slotValue_mvw103[] = "38";
static char _slotValue_mvw104[] = "32";
static char _slotValue_mvw105[] = "3";
static char _slotValue_mvw106[] = "1";
/* END OF OBJ */

static char _slotValue_mvw108[] = "XBMButton";
static char _slotValue_mvw109[] = "mvw.doc.tools.httpStat";
static char _slotValue_mvw110[] = "mvw.doc.tools.httpStat.icon";
static char _slotValue_mvw111[] = "\n\
	switch (arg[0]) {\n\
	case \"stat\":\n\
		if (inProgress == 0) {\n\
			clearWindow();\n\
			inProgress = 1;\n\
		}\n\
		fillArc(5, 2, w, h, 0, arg[1] * 3.6);\n\
		flush();\n\
		return;\n\
	break;\n\
	case \"clear\":\n\
		inProgress = 0;\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"config\":\n\
	case \"init\":\n\
		usual();\n\
		h = get(\"height\") - 5;\n\
		w = h;\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw112[] = "#define violaIcon2_width 36\n\
#define violaIcon2_height 30\n\
static char violaIcon2_bits[] = {\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00,\n\
   0x00, 0xe0, 0x30, 0x78, 0x00, 0x00, 0x30, 0x60, 0xcc, 0x01, 0x00, 0x18,\n\
   0xc0, 0x07, 0x03, 0x00, 0x08, 0x80, 0x01, 0x03, 0x00, 0x0c, 0x00, 0x00,\n\
   0x06, 0x00, 0x04, 0x00, 0x00, 0x46, 0x01, 0x04, 0x00, 0x00, 0x46, 0x01,\n\
   0x04, 0x80, 0xa4, 0xff, 0x03, 0x04, 0x0f, 0x00, 0x40, 0x01, 0x04, 0x0f,\n\
   0x00, 0x40, 0x01, 0x04, 0x0e, 0x04, 0x40, 0x01, 0x08, 0x0e, 0x04, 0x00,\n\
   0x00, 0x18, 0x1c, 0x04, 0x00, 0x00, 0x30, 0x1c, 0x02, 0x04, 0x00, 0xf0,\n\
   0x19, 0x0a, 0x74, 0x00, 0xe0, 0x39, 0x02, 0x84, 0x00, 0xc0, 0x31, 0xc9,\n\
   0x84, 0x00, 0x00, 0x20, 0x29, 0xe5, 0x00, 0x00, 0x60, 0x29, 0x95, 0x00,\n\
   0x00, 0xc0, 0x29, 0x95, 0x00, 0x00, 0xc0, 0xc8, 0xe4, 0x01, 0x00, 0x80,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_mvw113[] = "1";
static char _slotValue_mvw114[] = "32";
static char _slotValue_mvw115[] = "6";
/* END OF OBJ */

static char _slotValue_mvw117[] = "txtDisp";
static char _slotValue_mvw118[] = "mvw.doc.title";
static char _slotValue_mvw119[] = "mvw.doc";
static char _slotValue_mvw120[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		if (isBlank(arg[1])) {\n\
/*			set(\"content\", \"<No Title>\");*/\n\
			set(\"content\", \"\");\n\
		} else {\n\
			if (textWidth(6/*bold_largest*/, arg[1])+10 \n\
			    < width()) {\n\
				/*set(\"font\", \"bold_largest\");*/\n\
				set(\"content\", concat(\"\\\\f(6)\", arg[1]));\n\
			} else {\n\
				/*set(\"font\", \"bold\");*/\n\
				set(\"content\", concat(\"\\\\f(5)\", arg[1]));\n\
			}\n\
		}\n\
		render();\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw121[] = "this is where the page title goes";
static char _slotValue_mvw122[] = "38";
static char _slotValue_mvw123[] = "0";
static char _slotValue_mvw124[] = "2";
static char _slotValue_mvw125[] = "bold_large";
static char _slotValue_mvw126[] = "1";
static char _slotValue_mvw127[] = "6";
/* END OF OBJ */

static char _slotValue_mvw129[] = "hpane";
static char _slotValue_mvw130[] = "mvw.doc.view";
static char _slotValue_mvw131[] = "mvw.doc";
static char _slotValue_mvw132[] = "1";
static char _slotValue_mvw133[] = "0";
static char _slotValue_mvw134[] = "mvw.doc.view.pane";
static char _slotValue_mvw135[] = "\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		return send(nthChild(0), arg[0], arg[1]);\n\
	break;\n\
	case \"config\":\n\
		if (lbarVisible == 1) {\n\
			send(nthChild(0), \"resetWidthConstraint\", arg[3]);\n\
		}\n\
	break;\n\
	case \"reload\":\n\
	case \"showSource\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	case \"saveAs\":\n\
		return send(nthChild(0), arg[0], arg[1]);\n\
	break;\n\
	case \"tear\":\n\
	case \"quit\":\n\
		send(get(\"parent\"), arg[0]);\n\
		return;\n\
	break;\n\
	case \"clonePage\":\n\
		pagePane = get(\"content\");\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		objectListSend_children(\"torn\", arg[1], arg[2]);\n\
		pagePane = get(\"content\");\n\
		return;\n\
	break;\n\
	case \"whichPageP\":\n\
		return send(pagePane, \"whichPageP\");\n\
	break;\n\
	case \"key_up\":\n\
	case \"key_down\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	case \"addTool\":\n\
	case \"addTool_sticky\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(parent(), arg[0], arg[1]);\n\
	break;\n\
	case \"linkSideBar\":\n\
		sideBarURL = arg[1];\n\
		sideBarRatio = arg[2];\n\
		sideBarMaxWidth = arg[3];\n\
		send(self(), \"lbarConfig\", \"on\", \n\
			sideBarURL, sideBarRatio, sideBarMaxWidth);\n\
		return;\n\
	break;\n\
	case \"lbarConfig\":\n\
		switch (arg[1]) {\n\
		case \"on\":\n\
			set(\"children\", \n\
			\"mvw.doc.view.lbar mvw.doc.view.pane\");\n\
			send(nthChild(0), \"enable\", \n\
				arg[2], arg[3], arg[4], width());\n\
\n\
			send(self(), \"configSelf\");\n\
			if (lbarVisible == 0) send(nthChild(0), \"visible\", 1);\n\
			pagePane = nthChild(1);\n\
			lbarVisible = 1;\n\
		break;\n\
		case \"off\":\n\
			if (lbarVisible == 1) send(nthChild(0), \"disable\");\n\
			set(\"children\",\n\
			\"mvw.doc.view.pane\");\n\
			lbarVisible = 0;\n\
			send(self(), \"configSelf\");\n\
			pagePane = nthChild(0);\n\
		break;\n\
		}\n\
		set(\"content\", pagePane);\n\
		return;\n\
	break;\n\
	case \"sliderConfig\":\n\
		send(self(), \"configSelf\");\n\
		pagePane = nthChild(0);\n\
		set(\"content\", pagePane);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		pagePane = nthChild(0); /* default scrolbar at right side */\n\
		set(\"content\", pagePane);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_mvw137[] = "vpane";
static char _slotValue_mvw138[] = "mvw.doc.view";
static char _slotValue_mvw139[] = "mvw.doc.view.lbar";
static char _slotValue_mvw140[] = "mvw.doc.view.lbar.pane mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw141[] = "\n\
	switch (arg[0]) {\n\
	case \"barScroll\":\n\
		return send(nthChild(0), arg[0], arg[1]);\n\
	break;\n\
	case \"enable\":\n\
		enable = 1;\n\
		barURL = arg[1];\n\
		barRatio = arg[2];\n\
		barMaxWidth = arg[3];\n\
		parentWidth = arg[4];\n\
\n\
		if (barMaxWidth != 0) {\n\
			barWidth = barMaxWidth;\n\
		} else {\n\
			barWidth = float(parentWidth) * \n\
					float(barRatio) / 100.0;\n\
		}\n\
		set(\"width\", barWidth);\n\
		set(\"maxWidth\", barWidth);\n\
		set(\"visible\", 1);\n\
		send(nthChild(0), \"show\", barURL, barWidth);\n\
		return;\n\
	break;\n\
	case \"disable\":\n\
		enable = 0;\n\
		set(\"visible\", 0);\n\
		set(\"y\", 999);/*???? why won't this window go away??*/\n\
		return;\n\
	break;\n\
	case \"lbarEnabledP\":\n\
		return enable;\n\
	break;\n\
	case \"resetWidthConstraint\":\n\
		parentWidth = arg[1];\n\
		barWidth = float(parentWidth) * float(barRatio) / 100.0;\n\
		set(\"width\", 99);/*lame way to force a re config */\n\
		set(\"maxWidth\", barWidth);\n\
		return;		\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw142[] = "100";
static char _slotValue_mvw143[] = "100";
static char _slotValue_mvw144[] = "3";
static char _slotValue_mvw145[] = "3";
static char _slotValue_mvw146[] = "100";
static char _slotValue_mvw147[] = "1";
static char _slotValue_mvw148[] = "2";
/* END OF OBJ */

static char _slotValue_mvw150[] = "hpane";
static char _slotValue_mvw151[] = "mvw.doc.view.lbar";
static char _slotValue_mvw152[] = "mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw153[] = "mvw.doc.view.lbar.ctrls.up mvw.doc.view.lbar.ctrls.down";
static char _slotValue_mvw154[] = "\n\
	switch (arg[0]) {\n\
	case \"barScroll\":\n\
		return send(parent(), arg[0], arg[1]);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw155[] = "1";
static char _slotValue_mvw156[] = "20";
/* END OF OBJ */

static char _slotValue_mvw158[] = "txtButton";
static char _slotValue_mvw159[] = "mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw160[] = "mvw.doc.view.lbar.ctrls.up";
static char _slotValue_mvw161[] = "Up";
static char _slotValue_mvw162[] = "\n	if (arg[0] == \"buttonRelease\") send(parent(), \"barScroll\", \"up\");\n	usual();\n";
static char _slotValue_mvw163[] = "normal";
static char _slotValue_mvw164[] = "2";
/* END OF OBJ */

static char _slotValue_mvw166[] = "txtButton";
static char _slotValue_mvw167[] = "mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw168[] = "mvw.doc.view.lbar.ctrls.down";
static char _slotValue_mvw169[] = "Down";
static char _slotValue_mvw170[] = "\n	if (arg[0] == \"buttonRelease\") send(parent(), \"barScroll\", \"down\");\n	usual();\n";
static char _slotValue_mvw171[] = "normal";
static char _slotValue_mvw172[] = "1";
/* END OF OBJ */

static char _slotValue_mvw174[] = "field";
static char _slotValue_mvw175[] = "mvw.doc.view.lbar.pane";
static char _slotValue_mvw176[] = "mvw.doc.view.lbar";
static char _slotValue_mvw177[] = "mvw.doc.view.lbar.sb";
static char _slotValue_mvw178[] = "\n\
	switch (arg[0]) {\n\
	case \"shownPositionH\":\n\
	case \"shownPositionV\":\n\
		return send(docObj, \"shownPositionV\", arg[1]);\n\
	break;\n\
	case \"barScroll\":\n\
		if (arg[1] == \"down\") {\n\
			pgPosPct += 10;\n\
			if (pgPosPct > 100) pgPosPct = 100;\n\
		} else {\n\
			pgPosPct -= 10;\n\
			if (pgPosPct < 0) pgPosPct = 0;\n\
		}\n\
		return send(docObj, \"shownPositionV\", pgPosPct);\n\
	break;\n\
	case \"show\":\n\
		barURL = arg[1];\n\
		barWidth = arg[2];\n\
\n\
		set(\"width\", barWidth);\n\
\n\
		pgPosPct = 0;\n\
\n\
		handler = wwwFormatDetect(\"type\", barURL);\n\
		send(\"www.mesg.tf\", \"show\", \n\
			    concat(\"Getting sidebar from \", barURL));\n\
\n\
		docObj = send(\"wwwHandlerDispatch\", \n\
				\"dispatch\", handler,\n\
				0, barURL,\n\
				barURL, self(),\n\
				int(barWidth), 999,\n\
				\"\", 1, 0);\n\
\n\
		/* XXX kludgy stylesheet turn off */\n\
		STG_clean(0);\n\
\n\
		send(docObj, \"display\", barWidth, 999);\n\
		send(docObj, \"show\");\n\
\n\
		pageHeight = send(docObj, \"vspan\");\n\
		send(self(), \"configShare\");\n\
\n\
		return;\n\
	break;\n\
	case \"toDoInsert\":\n\
		insertObj[insertObjCount] = arg[1];\n\
		insertObjCount++;\n\
		return;\n\
	break;\n\
	case \"show_request_by_child\":\n\
	case \"post_request_by_child\":\n\
		sendToInterface(\"busyCursor\", cookie);\n\
		cursorShape(\"busy\");\n\
\n\
		if (arg[0] == \"post_request_by_child\") realMesg = \"post\";\n\
		else realMesg = \"show\";\n\
\n\
		if (torn == 1) destObj = self();\n\
		else destObj = object(\"mvw\");\n\
\n\
		if (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);\n\
		else stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);\n\
\n\
		if (stat) stat = send(\"mvw.doc.view.pane\", \"historyRecord\");\n\
\n\
		sendToInterface(\"idleCursor\", cookie);\n\
		cursorShape(\"idle\");\n\
		return stat;\n\
	break;\n\
	case \"setChildren\":\n\
		set(\"children\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"configShare\":\n\
		heightDiff = pageHeight - get(\"height\");\n\
		heightRatio =  float(heightDiff) / -100.0;\n\
		if (heightDiff > 0) {\n\
		  sliderSize = float(get(\"height\")) / float(pageHeight) * 100;\n\
		  sliderPos = float(pageYPos) / float(heightDiff) * -100;\n\
		} else {\n\
		  sliderSize = 100;\n\
		  sliderPos = 0;\n\
		}\n\
		objectListSend(\"shownDepend\", \"_shownInfoH\", \n\
				sliderPos, sliderSize);\n\
		objectListSend(\"shownDepend\", \"setShownNotify\", docObj);\n\
		return;\n\
	break;\n\
	case \"configSliderGeom\":\n\
		pageHeight = send(docObj, \"vspan\");\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"configSlider\":\n\
		/* arg[1]	pageYPos\n\
		 * arg[2]	pageHeight\n\
		 */\n\
		pageYPos = arg[1];\n\
		pageHeight = arg[2];\n\
		if (pageYPos + pageHeight < get(\"height\")) {\n\
			pageYPos = get(\"height\") - pageHeight;\n\
			if (pageYPos > 0) pageYPos = 0;\n\
			send(docObj, \"y\", pageYPos);\n\
		}\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		if (send(parent(), \"lbarEnabledP\") == 0) return;\n\
		usual();\n\
		/* ask page object to do the calculation */\n\
		send(docObj, \"resize\", get(\"width\"), get(\"height\"));\n\
		pageYPos = send(docObj, \"yP\");\n\
		pageHeight = send(docObj, \"vspan\");\n\
		if (pageYPos + pageHeight < get(\"height\")) {\n\
			pageYPos = get(\"height\") - pageHeight;\n\
			send(docObj, \"y\", pageYPos);\n\
		}\n\
		send(self(), \"configShare\");\n\
		configed = 1;\n\
		return;\n\
	break;\n\
	case \"update\":\n\
		pageObj = nthChild(0);\n\
		pageHeight = arg[1];\n\
		send(self(), \"configShare\");\n\
		return;\n\
	break;\n\
	case \"destroyDoc\":\n\
	case \"destroyDoc_qualified\":\n\
		send(pageObj, \"VW_event\", \"VIEW_OFF\");\n\
		send(pageObj, \"visible\", 0);\n\
		send(pageObj, \"freeSelf\");\n\
		pageObj = 0;\n\
		return;\n\
	break;\n\
	case \"addTool\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(parent(), arg[0], arg[1]);\n\
	break;\n\
	case \"showSrc\":\n\
	case \"reload\":\n\
	case \"clone\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	case \"whichPageP\":\n\
		return nthChild(0);\n\
	break;\n\
	case \"heightP\":\n\
		return height();\n\
	break;\n\
	case \"R\": /* happens sometimes. blah */\n\
	case \"reportNextID\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw179[] = "100";
static char _slotValue_mvw180[] = "999";
static char _slotValue_mvw181[] = "2";
static char _slotValue_mvw182[] = "2";
static char _slotValue_mvw183[] = "6";
/* END OF OBJ */

static char _slotValue_mvw185[] = "field";
static char _slotValue_mvw186[] = "mvw.doc.view.pane";
static char _slotValue_mvw187[] = "mvw.doc.view";
static char _slotValue_mvw188[] = "\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		sliderPos = arg[1];\n\
		return send(pageObj, arg[0], sliderPos);\n\
	break;\n\
	case \"key_up\":\n\
		return send(pageObj, \"scrollPageDown\");\n\
	break;\n\
	case \"key_down\":\n\
		return send(pageObj, \"scrollPageUp\");\n\
	break;\n\
	case \"procratinate_show\":\n\
		if (hasConfiged) {\n\
			stat = send(\"mvw.doc.view.pane\", \"show\", arg[1]);\n\
			send(\"mvw.doc.view.pane\", \"historyRecord\");\n\
		} else {\n\
/* wait after the window has opened and configured to the correct size */\n\
			after(1000, self(), \"procratinate_show\", arg[1]);\n\
		}\n\
		return;\n\
	break;\n\
	case \"show\":\n\
	case \"post\":\n\
	case \"showDoc\":\n\
	case \"showHistoryDoc\":\n\
		sendToInterface(\"busyCursor\", cookie);\n\
		cursorShape(\"busy\");\n\
		if (arg[0] == \"post\") {\n\
			doPost = 1;\n\
			postData = arg[3];\n\
		} else { \n\
			doPost = 0;\n\
			postData = 0;\n\
		}\n\
		if (torn == 1) {\n\
			if (arg[] == 2) \n\
				stat = send(\"mvw.doc.view.pane\", arg[0], arg[1]);\n\
			else if (arg[] == 3) \n\
				stat = send(\"mvw.doc.view.pane\", arg[0], arg[1], arg[2]);\n\
			else	stat = send(\"mvw.doc.view.pane\", arg[0], arg[1], arg[2], arg[3]);\n\
			sendToInterface(\"idleCursor\", cookie);\n\
			cursorShape(\"idle\");\n\
			return stat;\n\
		}\n\
		if (nthChar(arg[1], 0) == '#') {\n\
			pageYPos = send(pageObj, \"gotoAnchor\", \n\
					nthChar(arg[1], 1, 999));\n\
\n\
			pageHeight = send(pageObj, \"vspan\");\n\
			heightDiff = pageHeight - get(\"height\");\n\
			heightRatio =  float(heightDiff) / -100.0;\n\
\n\
			if (heightDiff > 0) {\n\
				sliderSize = float(get(\"height\")) / float(pageHeight) * 100;\n\
				sliderPos = float(pageYPos) / float(heightDiff) * 100;\n\
				if (sliderPos > 100) sliderPos = 100;\n\
			} else {\n\
				sliderSize = 100;\n\
				sliderPos = 0;\n\
			}\n\
			send(pageObj, \"shownPositionV\", sliderPos);\n\
		} else {\n\
			if (arg[] == 2)\n\
			  normURL = send(\"normalizeURL\", \"normalizeURL\", arg[1]);\n\
			else \n\
			  normURL = send(\"normalizeURL\", \"normalizeURL\", arg[1], arg[2]);\n\
\n\
			if (hasConfiged == 0) {\n\
				docToRenderAfterConfigure = normURL;\n\
				sendToInterface(\"idleCursor\", cookie);\n\
				cursorShape(\"idle\");\n\
				return 0;\n\
			}\n\
			docName = normURL;\n\
			docURL = normURL;\n\
\n\
			if (findPattern(arg[1], \"telnet:\") != -1) {\n\
				stat = send(\"mvw.delegationHandler\", \n\
						\"doTelnet\", normURL);\n\
				sendToInterface(\"idleCursor\", cookie);\n\
				cursorShape(\"idle\");\n\
				return stat;\n\
			} else if (findPattern(arg[1], \"mailto:\") != -1) {\n\
				stat = send(\"mvw.delegationHandler\", \n\
						\"doMailTo\", normURL);\n\
				sendToInterface(\"idleCursor\", cookie);\n\
				cursorShape(\"idle\");\n\
				return stat;\n\
			}\n\
\n\
			anchor = parseHTTPAddress(\"anchor\", normURL);\n\
\n\
			if (exist(pageObj) == 1) send(pageObj, \"undisplay\");\n\
\n\
			if (exist(docName) == 1) {\n\
				set(\"children\", docName);\n\
				if (anchor != \"\")  {\n\
					pageYPos = send(docName, \n\
						\"gotoAnchor\", anchor) * -1;\n\
					send(docName, \"y\", pageYPos);\n\
				} else {\n\
					pageYPos = send(docName, \"yP\");\n\
				}\n\
				if (send(docName, \"configSideBar\") == 1) {\n\
					send(parent(), \"linkSideBar\", \n\
				  sideBarURL, sideBarRatio, sideBarMaxWidth);\n\
				} else {\n\
					send(parent(), \"lbarConfig\", \"off\");\n\
				}\n\
				send(docName, \"display\", width(), height());\n\
\n\
				send(docName, \"raise\");/*necessary?*/\n\
			} else {\n\
				/* a rough guess at the document type */\n\
				handler = wwwFormatDetect(\"type\", docURL);\n\
				docObj = send(\"wwwHandlerDispatch\", \n\
					\"dispatch\", handler, doPost, docURL, \n\
					docName, self(), get(\"width\"), get(\"height\"),\n\
					anchor, 1, postData);\n\
\n\
				/* XXX kludgy stylesheet turn off */\n\
				STG_clean(0);\n\
\n\
				cursorShape(\"idle\");\n\
				if (docObj == 0) {\n\
					sendToInterface(\"warningDialog\",\n\
						cookie, concat(\"Failed to access\\n\
\", docURL));\n\
					sendToInterface(\"idleCursor\", cookie);\n\
					cursorShape(\"idle\");\n\
					return 0;\n\
				} else if (docObj == 1) {\n\
					/* It's OK.. no doc object generated\n\
					 * but wasn't an error (ie: to be \n\
					 * rendered by external viewer)\n\
					 */\n\
					cursorShape(\"idle\");\n\
					return 0;\n\
				}\n\
\n\
				if (send(docName, \"configSideBar\") == 1) {\n\
					send(parent(), \"linkSideBar\", \n\
				  sideBarURL, sideBarRatio, sideBarMaxWidth);\n\
				} else {\n\
					send(parent(), \"lbarConfig\", \"off\");\n\
				}\n\
\n\
				if (insertObjCount > 0) {\n\
					for (i = 0; i < insertObjCount; i++)\n\
						send(insertObj[i], \"insert\");\n\
					insertObjCount = 0;\n\
					send(self(), \"R\", \n\
						get(\"y\"),get(\"width\"));\n\
				}\n\
				send(docName, \"display\", \n\
					get(\"width\"), get(\"height\"));\n\
				send(docName, \"show\");\n\
				pageYPos = send(docName, \"yP\");\n\
			}\n\
			oo = object(docName);\n\
			if (oldDocName != docName) {\n\
				if (pageObj) {\n\
					send(pageObj, \"VW_event\", \"VIEW_OFF\");\n\
				}\n\
				pageObj = oo;\n\
				send(pageObj, \"VW_event\", \"VIEW_ON\");\n\
			} else {\n\
				pageObj = oo;\n\
			}\n\
\n\
			pageHeight = send(pageObj, \"vspan\");\n\
			send(self(), \"configShare\");\n\
		}\n\
		if (docObj != 0) {\n\
			title = send(pageObj, \"queryTitle\");\n\
			if (isBlank(title)) title = pageObj;\n\
\n\
			mvw.doc.title(\"show\", title);\n\
			mvw.doc.url(\"show\", docURL);\n\
\n\
			if (arg[0] == \"show\") {\n\
			  if (isBlank(title))\n\
				sendToInterface(\"newDocument\", cookie, docURL);\n\
			  else\n\
				sendToInterface(\"newDocument\", cookie, docURL, title);\n\
			} else { /* arg[0] == \"showHistoryDoc\" */\n\
			    if (isBlank(title))\n\
			    	sendToInterface(\"historyDocument\", cookie, docURL);\n\
			    else\n\
			    	sendToInterface(\"historyDocument\", cookie, docURL, title);\n\
			}\n\
			sendToInterface(\"sliderConfig\", cookie, sliderPos, sliderSize);\n\
		\n\
			indexP = send(pageObj, \"queryIsIndex\");\n\
			if (indexP == 0) {\n\
				sendToInterface(\"searchOff\", cookie);\n\
			} else {\n\
				/* plain ISINDEX, or ISINDEX ACTION=...*/\n\
				sendToInterface(\"searchOn\", cookie);\n\
			}\n\
			\n\
		}\n\
		sendToInterface(\"idleCursor\", cookie);\n\
		cursorShape(\"idle\");\n\
		return docName;\n\
	break;\n\
	case \"toDoInsert\":\n\
		insertObj[insertObjCount] = arg[1];\n\
		insertObjCount++;\n\
		return;\n\
	break;\n\
	case \"show_request_by_child\":\n\
	case \"post_request_by_child\":\n\
		if (arg[0] == \"post_request_by_child\") realMesg = \"post\";\n\
		else realMesg = \"show\";\n\
\n\
		if (torn == 1) destObj = self();\n\
		else destObj = object(\"mvw\");\n\
\n\
		if (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);\n\
		else stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);\n\
		return stat;\n\
	break;\n\
	case \"hintOn\":\n\
	case \"hintOff\":\n\
		return;\n\
	break;\n\
	case \"setChildren\":\n\
		set(\"children\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"configShare\":\n\
		heightDiff = pageHeight - get(\"height\");\n\
		heightRatio =  float(heightDiff) / -100.0;\n\
		/* not working right... should maintain proportional offset */\n\
		if (heightDiff > 0) {\n\
			sliderSize = float(height()) / float(pageHeight) * 100;\n\
			sliderPos = float(pageYPos) / float(heightDiff) * -100;\n\
		} else {\n\
			sliderSize = 100;\n\
			sliderPos = 0;\n\
		}\n\
		return;\n\
	break;\n\
	case \"configSlider\":\n\
		/* arg[1]	pageYPos\n\
		 * arg[2]	pageHeight\n\
		 */\n\
		pageYPos = arg[1];\n\
		pageHeight = arg[2];\n\
		if (pageYPos + pageHeight < get(\"height\")) {\n\
			pageYPos = get(\"height\") - pageHeight;\n\
			if (pageYPos > 0) pageYPos = 0;\n\
			send(pageObj, \"y\", pageYPos);\n\
		}\n\
		send(self(), \"configShare\");\n\
		sendToInterface(\"sliderConfig\", cookie, sliderPos, sliderSize);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		usual();\n\
		if (send(pageObj, \"viewP\") == 1) {\n\
			/* when switching from a sidebar'ed document to\n\
			 * a non-sidebar document, this object will be\n\
			 * 'configed' (and before the new document gets\n\
			 * configed... so we don't want to bother \n\
			 * that document (pageObj) until it is ready\n\
			 * (when viewP == 1).\n\
			 */\n\
			/* ask page object to do the calculation */\n\
			send(pageObj, \"resize\", get(\"width\"), get(\"height\"));\n\
			pageYPos = send(pageObj, \"yP\");\n\
			pageHeight = send(pageObj, \"vspan\");\n\
			if (pageYPos + pageHeight < get(\"height\")) {\n\
				pageYPos = get(\"height\") - pageHeight;\n\
				send(pageObj, \"y\", pageYPos);\n\
			}\n\
			send(self(), \"configShare\");\n\
		}\n\
		/* this call should not be necessary... what was it for? */\n\
		/*objectListSend(\"shownDepend\", \"kludgeRender\");*/\n\
\n\
		configed = 1;\n\
\n\
		/*XXX a bit tweetchy??????? */\n\
		sendToInterface(\"sliderConfig\", cookie, sliderPos, sliderSize);\n\
		if (hasConfiged == 0) {\n\
			hasConfiged = 1;\n\
			if (docToRenderAfterConfigure) {\n\
				stat = send(self(), \"show\", \n\
					docToRenderAfterConfigure);\n\
				if (stat) send(self(), \"historyRecord\");\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"update\":\n\
		pageObj = nthChild(0);\n\
		pageHeight = arg[1];\n\
		heightDiff = pageHeight - get(\"height\");\n\
		heightRatio =  float(heightDiff) / -100.0;\n\
		if (heightDiff > 0) h = arg[1];\n\
		else h = get(\"height\");\n\
		return h;\n\
	break;\n\
	case \"destroyDoc\":\n\
	case \"destroyDoc_qualified\":\n\
		send(pageObj, \"freeSelf\");\n\
		pageObj = 0;\n\
		return;\n\
	break;\n\
	case \"addTool\":\n\
	case \"addTool_sticky\":\n\
	case \"removeTool\":\n\
	case \"destroyTool\":\n\
		return send(parent(), arg[0], arg[1]);\n\
	break;\n\
	case \"search\":\n\
		return send(pageObj, \"search\", arg[1]);\n\
	break;\n\
	case \"outputSGML\":\n\
		return send(pageObj, \"outputSGML\");\n\
	break;\n\
	case \"mailToAuthor\":\n\
		contactURL = send(pageObj, \"queryAuthor\");\n\
		if (contactURL) {\n\
			res.dialogWithButtons(\"show\", \n\
			 concat(\"The declared author contact is:\\n\
\", \n\
				contactURL),\n\
			 \"Dismiss\", \"\");\n\
		} else {\n\
			res.dialogWithButtons(\"show\", \n\
			 \"Sorry, no author contact declared in the document.\",\n\
			 \"Dismiss\", \"\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"linkSideBar\":\n\
		sideBarURL = arg[1];\n\
		sideBarRatio = arg[2];\n\
		sideBarMaxWidth = arg[3];\n\
		return;\n\
	break;\n\
	case \"reload\":\n\
		/* is a problem if reloading 'URL#anchor' ? */\n\
		sendToInterface(\"sliderConfig\", cookie, 0, sliderSize);\n\
		return send(pageObj, \"reload\");\n\
	break;\n\
	case \"whichPageP\":\n\
		return nthChild(0);\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"expose\":\n\
		if (todo) {\n\
			homeDoc = mvw(\"homeDocP\");\n\
			mvw(\"show\", homeDoc);\n\
			todo = 0;\n\
		}\n\
		return;\n\
	break;\n\
	case \"reportNextID\":\n\
	case 'R':\n\
		return;\n\
	break;\n\
	case \"historyRecord\":\n\
		send(pageObj, \"historyRecord\");\n\
		return;\n\
	break;\n\
	case \"showSource\":\n\
		/* return temporary file */\n\
		sendToInterface(\"showSourceFile\", cookie, \n\
				HTTPGet(docURL), \"editable\"); \n\
		return;\n\
	break;\n\
	case \"saveAs\":\n\
		/* return temporary file */\n\
		sendToInterface(\"saveAs\", cookie, HTTPGet(docURL), arg[1]);\n\
		return;\n\
	break;\n\
	case \"getCurrentDocURL\":\n\
		return docURL;\n\
	break;\n\
	case \"getCurrentDocTitle\":\n\
		return title;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		todo = 0;\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		cookie = arg[2];\n\
		torn = 1;\n\
		send(nthChild(0), \"torn\", arg[1]);\n\
		pageObj = nthChild(0);\n\
		/* make self reset variables */\n\
		send(self(), \"update\", send(pageObj, \"vspan\"));\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_mvw189[] = "595";
static char _slotValue_mvw190[] = "400";
/* END OF OBJ */

static char _slotValue_mvw192[] = "mvw.delegationHandler";
static char _slotValue_mvw193[] = "generic";
static char _slotValue_mvw194[] = "\n\
	switch (arg[0]) {\n\
	case \"doTelnet\":\n\
		/* arg[1]	normalized URL\n\
		 */\n\
		cmd = send(\"WWWTelnetHandler\", \"connect\", arg[1]);\n\
		system(cmd);\n\
		return 1;\n\
	break;\n\
	case \"doMailTo\":\n\
		/* arg[1]	normalized URL\n\
		 */\n\
		subject = concat(\"WWW mail from: \", arg[1]);\n\
		tt = arg[1];\n\
		i = findPattern(tt, \"/\");\n\
		if (i == -1) {\n\
			address = nthChar(tt, 7, 999);\n\
			content = concat(\"This mail was generated by URL:\\n\
\",\n\
					 tt, \"\\n\
\");\n\
		} else {\n\
			address = nthChar(tt, 7, i-1);\n\
			content = concat(nthChar(tt, i+1, 999), \"\\n\
\");\n\
		}\n\
		tmpFile = makeTempFile();\n\
		saveFile(tmpFile, content);\n\
\n\
		cmd = concat(\"mail -s \\\"\", subject,\n\
				 \"\\\" \", address, \" < \", tmpFile);\n\
		system(cmd);\n\
		system(concat(\"rm \", tmpFile));\n\
		return 1;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_mvw196[] = "generic";
static char _slotValue_mvw197[] = "www.mesg.tf";
static char _slotValue_mvw198[] = "\n\
	switch (arg[0]) {\n\
	case \"clear\":\n\
		if (isCleared == 0) {\n\
			activeHelp();\n\
			isCleared = 1;\n\
		}\n\
/*XXX many needless operations*/\n\
		send(\"mvw.doc.tools.httpStat.icon\", \"clear\");\n\
		return;\n\
	break;\n\
	case \"show\":\n\
	case \"flash\":\n\
	case \"suggest\":\n\
		isCleared = 0;\n\
		return activeHelp(arg[1]);\n\
	break;\n\
	case \"show_progress\":\n\
		/* arg[1]	percent\n\
		 * arg[2]	bytes so far\n\
		 */\n\
		activeHelp(concat(\"Retrieved \", arg[2], \" bytes, \", \n\
				  arg[1], \"%\"));\n\
		send(\"mvw.doc.tools.httpStat.icon\", \"stat\", arg[1]);\n\
		isCleared = 0;\n\
		return;\n\
	break;\n\
	case \"alert\":\n\
	case \"warn\":\n\
	case \"error\":\n\
		isCleared = 0;\n\
		sendToInterface(\"modalErrorDialog\",\n\
				0, /* may be on top of the wrong shell--\n\
				    * now always go on main shell */\n\
				arg[1]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_mvw[] = {
    {"class", _slotValue_mvw0},
    {"name", _slotValue_mvw1},
    {"children", _slotValue_mvw2},
    {"script", _slotValue_mvw3},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw5},
    {"name", _slotValue_mvw6},
    {"script", _slotValue_mvw7},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw9},
    {"name", _slotValue_mvw10},
    {"parent", _slotValue_mvw11},
    {"children", _slotValue_mvw12},
    {"script", _slotValue_mvw13},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw15},
    {"name", _slotValue_mvw16},
    {"parent", _slotValue_mvw17},
    {"script", _slotValue_mvw18},
    {"border", _slotValue_mvw19},
    {"BDColor", _slotValue_mvw20},
    {"font", _slotValue_mvw21},
    {"maxHeight", _slotValue_mvw22},
    {"gapV", _slotValue_mvw23},
    {"gapH", _slotValue_mvw24},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw26},
    {"name", _slotValue_mvw27},
    {"children", _slotValue_mvw28},
    {"script", _slotValue_mvw29},
    {"maxHeight", _slotValue_mvw30},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw32},
    {"name", _slotValue_mvw33},
    {"parent", _slotValue_mvw34},
    {"script", _slotValue_mvw35},
    {"gapH", _slotValue_mvw36},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw38},
    {"name", _slotValue_mvw39},
    {"parent", _slotValue_mvw40},
    {"children", _slotValue_mvw41},
    {"maxWidth", _slotValue_mvw42},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw44},
    {"name", _slotValue_mvw45},
    {"parent", _slotValue_mvw46},
    {"script", _slotValue_mvw47},
    {"label", _slotValue_mvw48},
    {"maxWidth", _slotValue_mvw49},
    {"gapH", _slotValue_mvw50},
    {"gapV", _slotValue_mvw51},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw53},
    {"name", _slotValue_mvw54},
    {"parent", _slotValue_mvw55},
    {"script", _slotValue_mvw56},
    {"label", _slotValue_mvw57},
    {"maxWidth", _slotValue_mvw58},
    {"gapH", _slotValue_mvw59},
    {"gapV", _slotValue_mvw60},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw62},
    {"name", _slotValue_mvw63},
    {"parent", _slotValue_mvw64},
    {"script", _slotValue_mvw65},
    {"label", _slotValue_mvw66},
    {"maxWidth", _slotValue_mvw67},
    {"gapH", _slotValue_mvw68},
    {"gapV", _slotValue_mvw69},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw71},
    {"name", _slotValue_mvw72},
    {"parent", _slotValue_mvw73},
    {"script", _slotValue_mvw74},
    {"label", _slotValue_mvw75},
    {"maxWidth", _slotValue_mvw76},
    {"gapH", _slotValue_mvw77},
    {"gapV", _slotValue_mvw78},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw80},
    {"name", _slotValue_mvw81},
    {"parent", _slotValue_mvw82},
    {"script", _slotValue_mvw83},
    {"label", _slotValue_mvw84},
    {"minWidth", _slotValue_mvw85},
    {"gapH", _slotValue_mvw86},
    {"gapV", _slotValue_mvw87},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw89},
    {"name", _slotValue_mvw90},
    {"parent", _slotValue_mvw91},
    {"script", _slotValue_mvw92},
    {"label", _slotValue_mvw93},
    {"minWidth", _slotValue_mvw94},
    {"gapH", _slotValue_mvw95},
    {"gapV", _slotValue_mvw96},
    {(char*)0, (char*)1},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw99},
    {"parent", _slotValue_mvw100},
    {"name", _slotValue_mvw101},
    {"children", _slotValue_mvw102},
    {"maxWidth", _slotValue_mvw103},
    {"minHeight", _slotValue_mvw104},
    {"gapH", _slotValue_mvw105},
    {"gapV", _slotValue_mvw106},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw108},
    {"parent", _slotValue_mvw109},
    {"name", _slotValue_mvw110},
    {"script", _slotValue_mvw111},
    {"label", _slotValue_mvw112},
    {"gapV", _slotValue_mvw113},
    {"maxHeight", _slotValue_mvw114},
    {"border", _slotValue_mvw115},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw117},
    {"name", _slotValue_mvw118},
    {"parent", _slotValue_mvw119},
    {"script", _slotValue_mvw120},
    {"content", _slotValue_mvw121},
    {"maxHeight", _slotValue_mvw122},
    {"gapV", _slotValue_mvw123},
    {"gapH", _slotValue_mvw124},
    {"font", _slotValue_mvw125},
    {"format", _slotValue_mvw126},
    {"border", _slotValue_mvw127},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw129},
    {"name", _slotValue_mvw130},
    {"parent", _slotValue_mvw131},
    {"gapV", _slotValue_mvw132},
    {"gapH", _slotValue_mvw133},
    {"children", _slotValue_mvw134},
    {"script", _slotValue_mvw135},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw137},
    {"parent", _slotValue_mvw138},
    {"name", _slotValue_mvw139},
    {"children", _slotValue_mvw140},
    {"script", _slotValue_mvw141},
    {"width", _slotValue_mvw142},
    {"height", _slotValue_mvw143},
    {"x", _slotValue_mvw144},
    {"y", _slotValue_mvw145},
    {"width", _slotValue_mvw146},
    {"gapH", _slotValue_mvw147},
    {"gapV", _slotValue_mvw148},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw150},
    {"parent", _slotValue_mvw151},
    {"name", _slotValue_mvw152},
    {"children", _slotValue_mvw153},
    {"script", _slotValue_mvw154},
    {"gapH", _slotValue_mvw155},
    {"maxHeight", _slotValue_mvw156},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw158},
    {"parent", _slotValue_mvw159},
    {"name", _slotValue_mvw160},
    {"label", _slotValue_mvw161},
    {"script", _slotValue_mvw162},
    {"font", _slotValue_mvw163},
    {"gapH", _slotValue_mvw164},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw166},
    {"parent", _slotValue_mvw167},
    {"name", _slotValue_mvw168},
    {"label", _slotValue_mvw169},
    {"script", _slotValue_mvw170},
    {"font", _slotValue_mvw171},
    {"gapH", _slotValue_mvw172},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw174},
    {"name", _slotValue_mvw175},
    {"parent", _slotValue_mvw176},
    {"shownDepend", _slotValue_mvw177},
    {"script", _slotValue_mvw178},
    {"width", _slotValue_mvw179},
    {"height", _slotValue_mvw180},
    {"gapH", _slotValue_mvw181},
    {"gapV", _slotValue_mvw182},
    {"border", _slotValue_mvw183},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw185},
    {"name", _slotValue_mvw186},
    {"parent", _slotValue_mvw187},
    {"script", _slotValue_mvw188},
    {"width", _slotValue_mvw189},
    {"height", _slotValue_mvw190},
    {(char*)0, (char*)1},
    {"name", _slotValue_mvw192},
    {"class", _slotValue_mvw193},
    {"script", _slotValue_mvw194},
    {(char*)0, (char*)1},
    {"class", _slotValue_mvw196},
    {"name", _slotValue_mvw197},
    {"script", _slotValue_mvw198},
    {(char*)0, (char*)0},
};

static char _slotValue_mvwHistory0[] = "mvwHistory";
static char _slotValue_mvwHistory1[] = "generic";
static char _slotValue_mvwHistory2[] = "\n\
	switch (arg[0]) {\n\
	case \"prev\":\n\
		if (index > 0) {\n\
			index--;\n\
			return docAddr[index];\n\
		} else {\n\
			bell();\n\
			return \"\";\n\
		}\n\
	break;\n\
	case \"next\":\n\
		if (index < count - 1) {\n\
			index++;\n\
			return docAddr[index];\n\
		} else {\n\
			bell();\n\
			return \"\";\n\
		}\n\
	break;\n\
	case \"add\":\n\
		index = count;\n\
/*\n\
print(\"HISTORY add: arg[1] {\", arg[1], \"}++++++++++++++++++++++++++\\n\
\");\n\
print(\"             arg[2] {\", arg[2], \"}++++++++++++++++++++++++++\\n\
\");\n\
*/\n\
		if (isBlank(arg[1]) == 1) {\n\
			docTitle[count] = \"no title\";\n\
		} else {\n\
			/* make sure we're storing string representation,\n\
			 * rather than possibly object pointer which can\n\
			 * get us into trouble if that object is destroyed\n\
			 * and we reference it.\n\
			 */\n\
			docTitle[index] = str(arg[1]);\n\
		}\n\
		docAddr[index] = arg[2];\n\
		count++;\n\
		victimIdx = count - killLatency;\n\
		if (victimIdx >= 0) {\n\
			victim = docAddr[victimIdx];\n\
			if (victim != arg[2]) {\n\
/*print(\"KILLING idx=\", victimIdx,\"{\", victim, \"}\\n\
\");*/\n\
				send(victim, \"visible\", 0);\n\
				send(victim, \"freeSelf\");\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"historyList_selectedItem\":\n\
		index = arg[1];\n\
		return;\n\
     	break;\n\
	case \"back\":\n\
		/* delete last line */\n\
		if (count > 1) {\n\
			mvw(\"destroyDoc\", docAddr[index]);\n\
			count--;\n\
			/* move index only if at bottom of history list */\n\
			if (index >= count) index--;\n\
			return docAddr[index];\n\
		} else {\n\
			return docAddr[0];\n\
		}\n\
	break;\n\
	case \"dump\":\n\
		for (i = 0; i < count; i++)\n\
			print(\"[\", i, \"]\	 docTitle={\", docTitle[i], \"}\",\n\
				\"\	docAddr={\", docAddr[i], \"}\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		index = -1;\n\
		count = 0;\n\
		killLatency = 4;\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_mvwHistory[] = {
    {"name", _slotValue_mvwHistory0},
    {"class", _slotValue_mvwHistory1},
    {"script", _slotValue_mvwHistory2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML__box0[] = "field";
static char _slotValue_HTML__box1[] = "HTML__txtBox";
static char _slotValue_HTML__box2[] = "HTML__txtBox.icon";
static char _slotValue_HTML__box3[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	insertObj\n\
		 * arg[2]	width to use\n\
		 * arg[3]	height to use\n\
		 */\n\
		set(\"width\", arg[2]);\n\
		set(\"height\", arg[3]);\n\
		objectListAppend_children(arg[1]);\n\
		return self();\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__box4[] = "100";
static char _slotValue_HTML__box5[] = "8";
static char _slotValue_HTML__box6[] = "blue";
static char _slotValue_HTML__box7[] = "red";
/* END OF OBJ */

static char _slotValue_HTML__box9[] = "field";
static char _slotValue_HTML__box10[] = "HTML__txtBox";
static char _slotValue_HTML__box11[] = "HTML__txtBox.icon";
static char _slotValue_HTML__box12[] = "\n	switch (arg[0]) {\n	case \"make\":\n	break;\n	}\n	usual();\n";
static char _slotValue_HTML__box13[] = "10";
static char _slotValue_HTML__box14[] = "10";
/* END OF FILE */

static SlotStruct objDesc_HTML__box[] = {
    {"class", _slotValue_HTML__box0},
    {"name", _slotValue_HTML__box1},
    {"children", _slotValue_HTML__box2},
    {"script", _slotValue_HTML__box3},
    {"width", _slotValue_HTML__box4},
    {"height", _slotValue_HTML__box5},
    {"BGColor", _slotValue_HTML__box6},
    {"BDColor", _slotValue_HTML__box7},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__box9},
    {"parent", _slotValue_HTML__box10},
    {"name", _slotValue_HTML__box11},
    {"script", _slotValue_HTML__box12},
    {"width", _slotValue_HTML__box13},
    {"height", _slotValue_HTML__box14},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML__doc0[] = "txtDisp";
static char _slotValue_HTML__doc1[] = "HTML__doc";
static char _slotValue_HTML__doc2[] = "\n\
/*\n\
print(\"HTML__doc: self=\", self(), \": \");\n\
for (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");print(\"...end\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		if (viewP == 0) return;\n\
		usual();\n\
		if (isHTML) render();\n\
		return;\n\
	break;\n\
	case \"shownPositionV\":\n\
		if (isHTML) return set(\"y\", arg[1] * heightRatio);\n\
		else return set(\"shownPositionV\", arg[1]);\n\
	break;\n\
	case \"inAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"scrollPageUp\":\n\
		if (isHTML) {\n\
			y = get(\"y\") - parentHeight;\n\
			if (y < parentHeight - get(\"height\"))\n\
				y = parentHeight - get(\"height\");\n\
			set(\"y\", y);\n\
		} else {\n\
			/* not yet implemented */\n\
		}\n\
		return;\n\
	break;\n\
	case \"scrollPageDown\":\n\
		if (isHTML) {\n\
			y = get(\"y\") + parentHeight;\n\
			if (y > 0) y = 0;\n\
			set(\"y\", y);\n\
		} else {\n\
			/* not yet implemented */\n\
		}\n\
		return;\n\
	break;\n\
	case \"F\": /* flush */\n\
		h = 0;\n\
		send(self(), \"setStyles\");\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		h = get(\"height\");\n\
		send(self(), \"setStyles\");\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(), \n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
\n\
		/* IMPORTANT KLUDGE: this is how this object knows whether \n\
		 * to behave like a single textfield (for ascii only text),\n\
		 * or as container (for compound HTML objects).\n\
		 */\n\
		set(\"height\", h);\n\
/*after(1000, \"www\", \"editMode\", 1);*/\n\
		return h;\n\
	break;\n\
	case \"data\":\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"inPreP\":\n\
		return 0;\n\
	break;\n\
	case 'T':\n\
		/* arg[1] = y\n\
		 * arg[2] = width\n\
		 *\n\
		 * put this check here rather than \"D\" since it may \"D\" time\n\
		 * may not occur.\n\
		 */\n\
		if (objectListCount(\"children\") > 0) {\n\
			isHTML = 1;\n\
			h = get(\"height\");\n\
			parentHeight = send(parent(), \"heightP\");\n\
			heightDiff = h - parentHeight;\n\
			if (heightDiff > 0) {\n\
				heightRatio = float(heightDiff) / -100.0;\n\
			} else {\n\
				heightRatio = 0;\n\
				h = parentHeight;\n\
			}\n\
			set(\"height\", h);\n\
			prevHeight = h;\n\
		} else {\n\
			prevHeight = get(\"height\");\n\
			h = building_vspan();\n\
		}\n\
		vspan = h;\n\
		prevWidth = arg[2];\n\
		return vspan;\n\
	break;\n\
	case \"nameAndURL\":\n\
		docName = arg[1];\n\
		docURL = arg[2];\n\
		return;		\n\
	break;\n\
	case \"setAnchor\":\n\
		makeAnchor = arg[1];\n\
		return;\n\
	break;\n\
	case \"query_docName\":\n\
		return docName;\n\
	break;\n\
	case \"query_docURL\":\n\
		return docURL;\n\
	break;\n\
	case \"searchAnchor\":\n\
		n = countChildren();\n\
		if (n > 0) \n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return 0; /* special case */\n\
		n = countChildren();\n\
		if (n > 0)\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i),\n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset;\n\
			}\n\
		return 0;\n\
	break;\n\
	case \"follow_href\":\n\
		return send(parent(), \"show_request_by_child\", arg[1], docURL);\n\
	break;\n\
	case \"post_href_n_data\":\n\
		return send(parent(), \"post_request_by_child\", arg[1], docURL,\n\
							arg[2]);\n\
	break;\n\
	case \"hintOn\":\n\
		return send(parent(), \"hintOn\", arg[1]);\n\
	break;\n\
	case \"hintOff\":\n\
		return send(parent(), \"hintOff\");\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		set(\"y\", 0);\n\
		send(self(), \"resize\", arg[2], send(parent(), \"heightP\")); \n\
		return h;\n\
	break;\n\
	case \"resize\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (..)\n\
		 * Note: prevWidth & prevHeight also refers to viewer sizes\n\
		 */\n\
		set(\"width\", arg[1]);\n\
		if (isHTML) {\n\
			n = countChildren();\n\
			if (n) {\n\
				xx = arg[1] - 5;\n\
				h = 0;\n\
				for (i = 0; i < n; i++)\n\
					h += send(nthChild(i), \"R\", h, xx);\n\
				vspan = h;\n\
			} else {\n\
				vspan = 1;\n\
			}\n\
			parentHeight = send(parent(), \"heightP\");\n\
			if (vspan < parentHeight) vspan = parentHeight;\n\
\n\
			heightDiff = vspan - parentHeight;\n\
			if (heightDiff > 0) {\n\
				heightRatio = float(heightDiff) / -100.0;\n\
			} else {\n\
				heightRatio = 0;\n\
				vspan = parentHeight;\n\
			}\n\
			set(\"height\", vspan);\n\
		} else {\n\
			set(\"height\", arg[2]);\n\
			set(\"content\", get(\"content\"));\n\
			render();\n\
			vspan = building_vspan();\n\
		}\n\
		prevWidth = arg[1];\n\
		prevHeight = arg[2];\n\
		return;\n\
	break;\n\
	case \"resizeSelf\":\n\
		send(self(), \"resize\", \n\
			get(\"width\"), send(parent(), \"heightP\"));\n\
		send(parent(), \"configSlider\", get(\"y\"), get(\"height\"));\n\
		return;\n\
	break;\n\
	case \"VIEW_ON\":\n\
		for (i = 0; i < toolsCount; i++) send(tools[i], \"visible\", 1);\n\
		return;\n\
	break;\n\
	case \"display\":\n\
		/* arg[1]	width (of viewer window)\n\
		 * arg[2]	height (of viewer window)\n\
		 */\n\
		viewP = 1;\n\
		send(self(), \"resize\", arg[1], arg[2]);\n\
		set(\"visible\", 1);\n\
		if (get(\"window\")) raise();\n\
\n\
		deepObjectListSend(\"children\", \"visible\", 1);\n\
\n\
		for (i = 0; i < toolsCount; i++) {\n\
			send(get(\"parent\"), \"addTool\", tools[i]);\n\
			send(tools[i], \"visible\", 1);\n\
		}\n\
		return;\n\
	break;\n\
	case \"undisplay\":\n\
		viewP = 0;\n\
		return;\n\
	break;\n\
	case \"viewP\":\n\
		return viewP;\n\
	break;\n\
	case \"configSelf\":\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
		return self();\n\
	break;\n\
	case \"placeID\":\n\
		/* this is clumsy. should be simplified with a primitive f() */\n\
		/* find the caller (child) object's place in the obj list */\n\
		cobj = arg[1];\n\
		objPlace = -1;\n\
		for (i = objectListCount_children() - 1; i >= 0; i--) {\n\
			print(\"##/// i=\", i, \"  cobj=\",  cobj, \n\
				\"  nc=\", nthChild(i), \"\\n\
\");\n\
			nobj = nthChild(i);\n\
			if (cobj == nobj) {\n\
				objPlace = i;\n\
				print(\"#### objPlace = \",  i, \"\\n\
\");\n\
			}\n\
		}\n\
		objPlacePath = concat(objPlace, \" \", arg[2]);\n\
		print(\"#### objPlacePath = {\",  objPlacePath, \"}\\n\
\");\n\
		return objPlacePath;\n\
	break;\n\
	case \"change\":\n\
/*\n\
print(\"!!############ obj = \",  arg[1], \"\\n\
\");\n\
print(\"!!############ objPlacePath = {\",  arg[2], \"}\\n\
\");\n\
print(\"!!############ new data = {\",  arg[3], \"}\\n\
\");\n\
*/\n\
		objPlacePath = arg[2];\n\
		newData = arg[3];\n\
\n\
		cpa = nthWord(objPlacePath, 1);\n\
/*print(\"!!############ childPosToAffect = {\",  cpa, \"}\\n\
\");*/\n\
		newObjPlacePath = nthWord(objPlacePath, 2, 99);\n\
/*print(\"!!############ new objPlacePath = {\", newObjPlacePath, \"}\\n\
\");*/\n\
\n\
		send(nthChild(cpa), \"change\", newObjPlacePath, newData);\n\
		send(\"www_com\", \"output_change\", objPlacePath, newData);\n\
\n\
		return;\n\
	break;\n\
	case \"wedge_before\":\n\
		/* arg[1]	child \n\
		 * arg[2]	obj to insert after child\n\
		 */\n\
		objN = arg[1];\n\
		objN1 = arg[2];\n\
\n\
		ooi = 0;\n\
		n = countChildren();\n\
		for (i = 0; i < n; i++) {\n\
			co = nthChild(i);\n\
			if (co == objN) {\n\
				oo[ooi] = objN1;\n\
				ooi++;\n\
			}\n\
			oo[ooi] = co;\n\
			ooi++;\n\
		}\n\
		for (i = ooi - 1; i >= 0; i--)\n\
			objectListDelete_children(oo[i]);\n\
		for (i = ooi - 1; i >= 0; i--)\n\
			objectListPrepend_children(oo[i]);\n\
		return;\n\
	break;\n\
	case \"wedge_after\":\n\
		/* arg[1]	child \n\
		 * arg[2]	obj to insert after child\n\
		 */\n\
		objN = arg[1];\n\
		objN1 = arg[2];\n\
\n\
		ooi = 0;\n\
		n = countChildren();\n\
		for (i = 0; i < n; i++) {\n\
			co = nthChild(i);\n\
			oo[ooi] = co;\n\
			ooi++;\n\
			if (co == objN) {\n\
				oo[ooi] = objN1;\n\
				ooi++;\n\
			}\n\
		}\n\
		print(\"old children list: \", get(\"children\"), \"\\n\
\");\n\
		/* IDIOTIC WAY TO DELETE LIST */\n\
		/*set(\"children\", \"\");*/\n\
		for (i = ooi - 1; i >= 0; i--) {\n\
			print(\"delete OBJ from children list\", oo[i], \"\\n\
\");\n\
			objectListDelete_children(oo[i]);\n\
		}\n\
		/* re set list in right order */\n\
		for (i = ooi - 1; i >= 0; i--) {\n\
			objectListPrepend_children(oo[i]);\n\
		}\n\
		print(\"new children list: \", get(\"children\"), \"\\n\
\");\n\
		info();\n\
		return;\n\
	break;\n\
	case \"deleteChild\":\n\
		return objectListDelete_children(arg[1]);\n\
	break;\n\
	case \"wedgeMeIn\":\n\
		/* arg[1]	object to wedge in\n\
		 * arg[2]	side (0=upper, 1=lower)\n\
		 */\n\
		if (selectedObj) {\n\
			print(\"#### selected Obj = \",  selectedObj, \"\\n\
\");\n\
			print(\"#### to wedge into Obj = \",  arg[1], \"\\n\
\");\n\
			send(selectedObj, \"runAwayFromHome\");\n\
			if (arg[2] == 0) {\n\
				print(\"#### upper side (wedge before)\\n\
\");\n\
				send(self(), \"wedge_before\", \n\
					arg[1], selectedObj);\n\
			} else {\n\
				print(\"#### lower side (wedge after)\\n\
\");\n\
				send(self(), \"wedge_after\", \n\
					arg[1], selectedObj);\n\
			}\n\
			selectedObj = 0;\n\
			send(self(), \"resizeSelf\");\n\
		} else {\n\
			selectedObj = arg[1];\n\
			print(\"#### selected Obj = \",  selectedObj, \"\\n\
\");\n\
		}\n\
		return;\n\
	break;\n\
\n\
	case \"CE_change\":\n\
		/* arg[1] 	CE objPath\n\
		 * arg[2]	CE newData\n\
		 */\n\
		objPlacePath = arg[1];\n\
		cpa = nthWord(objPlacePath, 1);\n\
		newObjPlacePath = nthWord(objPlacePath, 2, 99);\n\
/*\n\
print(\"!!!!!!!!!!############ objPlacePath = {\", objPlacePath, \"}\\n\
\");\n\
print(\"!!!!!!!!!!############ childPosToAffect = {\",  cpa, \"}\\n\
\");\n\
print(\"!!!!!!!!!!############ new objPlacePath = {\", newObjPlacePath, \"}\\n\
\");\n\
print(\"!!!!!!!!!!############ data = {\", arg[2], \"}\\n\
\");\n\
*/\n\
		send(nthChild(cpa), \"CE_change\", newObjPlacePath, arg[2]);\n\
		return;\n\
	break;\n\
	case \"lock\":\n\
/*\n\
print(\"!!############ obj = \",  arg[1], \"\\n\
\");\n\
print(\"!!############ objPlacePath = {\",  arg[2], \"}\\n\
\");\n\
*/\n\
		objPlacePath = arg[2];\n\
		send(\"www_com\", \"output_lock\", objPlacePath);\n\
		return;\n\
	break;\n\
	case \"unlock\":\n\
/*\n\
print(\"!!############ obj = \",  arg[1], \"\\n\
\");\n\
print(\"!!############ objPlacePath = {\",  arg[2], \"}\\n\
\");\n\
*/\n\
		objPlacePath = arg[2];\n\
		send(\"www_com\", \"output_unlock\", objPlacePath);\n\
		return;\n\
	break;\n\
	case \"CE_lock\":\n\
	case \"CE_unlock\":\n\
		/* arg[1] 	CE objPath\n\
		 */\n\
		objPlacePath = arg[1];\n\
		cpa = nthWord(objPlacePath, 1);\n\
		newObjPlacePath = nthWord(objPlacePath, 2, 99);\n\
		send(nthChild(cpa), arg[0], newObjPlacePath);\n\
		return;\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"reportTitle\":\n\
		docTitle = arg[1];\n\
		return;\n\
	break;\n\
	case \"yP\":\n\
		return get(\"y\");\n\
	break;\n\
	case \"y\":\n\
		return set(\"y\", arg[1]);\n\
	break;\n\
	case \"vspan\":\n\
		if (isHTML) return get(\"height\");\n\
		return vspan;\n\
	break;\n\
	case \"reload\":\n\
		set(\"name\", \"dunsel\");\n\
		for (i = 0; i < toolsCount; i++)\n\
			send(parent(), \"destroyTool\", tools[i]);\n\
		send(\"www\", \"show\", docURL);\n\
		after(10000, self(), \"visible\", 0);\n\
		after(10001, self(), \"freeSelf\");\n\
		return 0;\n\
	break;\n\
	case \"compact\": /* just to handle bad HTML... */\n\
	case \"L\": /*...*/\n\
		/* should signal detection of bad HTML */\n\
		return 0;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"show\":\n\
		set(\"visible\", 1);\n\
		render();\n\
		if (get(\"window\")) raise();\n\
\n\
		for (i = 0; i < toolsCount; i++) send(tools[i], \"visible\", 1);\n\
\n\
		relay_obj[relayIdx] = self();\n\
		relay_event[relayIdx++] = \"VIEW_OFF\";\n\
\n\
		return;\n\
	break;\n\
	case \"search\":\n\
		if (isIndex == 0) {\n\
			/* error cond, but do it anyway */ actionURL = docURL;\n\
		} else if (isIndex == 1) {\n\
			actionURL = docURL;\n\
		} else {\n\
			actionURL = isIndex;\n\
		}\n\
		cleanURL = send(\"parseHTTPAddress\", \"stripIndex\", actionURL);\n\
		return send(parent(), \"show_request_by_child\", \n\
				concat(cleanURL, '?', arg[1]), docURL);\n\
	break;\n\
	case \"VIEW_OFF\":\n\
		for (i = 0; i < toolsCount; i++)\n\
			send(parent(), \"removeTool\", tools[i]);\n\
		return;\n\
	break;\n\
	case \"blank\":\n\
		set(\"visible\", 0);\n\
		send(self(), \"VIEW_OFF\");\n\
		return;\n\
	break;\n\
	case \"queryAddress\":\n\
		return docURL;\n\
	break;\n\
	case \"queryTitle\":\n\
		if (docTitle) return docTitle;\n\
		return docName;\n\
	break;\n\
	case \"isIndex\":\n\
		isIndex = 1;\n\
		return;\n\
	break;\n\
	case \"isIndexURL\":\n\
		isIndex = arg[1];\n\
		return;\n\
	break;\n\
	case \"queryIsIndex\":\n\
		return isIndex;\n\
	break;\n\
	case \"historyRecord\":\n\
		send(\"www\", \"addToHistory\", docName, docURL);\n\
		return;\n\
	break;\n\
	case \"toDoInsert\":\n\
		send(parent(), \"toDoInsert\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"torn\":\n\
		/* Variable do not get cloned. So, set variables, \n\
		 * ie: parentHeight, hightDiff.. \n\
		 */\n\
		orig = arg[1];\n\
\n\
		docName = send(orig, \"query_docName\");\n\
		docURL = send(orig, \"query_docURL\");\n\
\n\
		send(self(), 'T', 0, get(\"width\")); \n\
		return;\n\
	break;\n\
	case \"output2File\":\n\
		send(\"res.getLineEntry\", \"show\", \n\
			\"Enter file name to save to document source to:\", \n\
				\"/tmp/out.html\",\n\
				self(), \"gotOutputFileName\");\n\
		return;\n\
 	break;\n\
	case \"gotOutputFileName\":\n\
		send(\"wwwSecurity\", \"getDocAndMoveItToSpecifiedPlace\",\n\
				docURL, arg[1]);\n\
		send(\"www.mesg.tf\", \"show\", \n\
			concat(\"Source saved to file: \", arg[1], \"\\n\
\"));\n\
		return;\n\
 	break;\n\
	case \"showSrc\":\n\
		wwwSrc(\"showByURL\", docURL);\n\
		return;\n\
 	break;\n\
	case \"reportAuthor\":\n\
		author = arg[1];\n\
		return;\n\
	break;\n\
	case \"configSideBar\":\n\
		if (sideBarURL != 0) {\n\
			send(parent(), \"linkSideBar\",\n\
				 sideBarURL, sideBarRatio, sideBarMaxWidth);\n\
			return 1;\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"linkSideBar\":\n\
		hasSideBarP = 1;\n\
		sideBarURL = arg[1];\n\
		sideBarRatio = arg[2];\n\
		sideBarMaxWidth = arg[3];\n\
		return;\n\
	break;\n\
	case \"queryAuthor\":\n\
		if (author == \"\") return 0;\n\
		return author;\n\
	break;\n\
	case \"editMode\":\n\
		editMode = arg[1];\n\
		print(\"HTML__DOC: editMode=\", editMode, \"\\n\
\");\n\
		n = countChildren();\n\
		for (i = 0; i < n; i++) {\n\
			anchor = send(nthChild(i), \"editMode\", editMode);\n\
		}\n\
		return;\n\
	break;\n\
	case \"outlineSrc\":\n\
		send(\"www.mesg.tf\", \"show\", \n\
			\"Outliner not available for HTML\\n\
\");\n\
		return;\n\
	break;\n\
	case \"print\":\n\
/*\n\
1 - the URL of those documents contain \";\" telling the shell that\n\
the instruction ended. you have to go out of viola, and enclose\n\
it in quotation marks.\n\
*/\n\
		send(\"www.mesg.tf\", \"show\", \n\
		    \"Printing facillity not available for HTML.\\n\
\");\n\
		return;\n\
 	break;\n\
	case \"freeSelf\":\n\
		/* tools should be freed only when an object really is\n\
		 * going away, and when the doc object is named 'dunsel'\n\
		 * the doc is being reloaded.\n\
		 */\n\
/*		if (self() != \"dunsel\")\n\
			for (i = 0; i < toolsCount; i++)\n\
				send(tools[i], \"freeSelf\");\n\
*/\n\
		freeSelf();\n\
		return;\n\
	break;\n\
	case \"VW_relay\":\n\
		relay_obj[relayIdx] = arg[1];\n\
		relay_event[relayIdx++] = arg[2];\n\
		return 1;\n\
	break;\n\
	case \"VW_event\":\n\
		event = arg[1];\n\
		for (i = 0; i < relayIdx; i++)\n\
			if (relay_event[i] == event) send(relay_obj[i], event);\n\
		return;\n\
	break;\n\
	case \"addTool\":\n\
		tools[toolsCount] = arg[1];\n\
		toolsCount++;\n\
		return;\n\
	break;\n\
	case \"addTool_sticky\":\n\
		return send(parent(), \"addTool\", arg[1]);\n\
	break;\n\
	case \"setStyles\":\n\
		tagPtr = STG_tagPtr(\"BODY\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
			i = STG_attr(tagPtr, \"fontSlant\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<HTML>\\n\
\");\n\
		n = countChildren();\n\
		if (n) for (i = 0; i < n; i++)\n\
				send(nthChild(i), \"outputSGML\");\n\
		print(\"</HTML>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
/*\\width {590}*/\n\
/*\\height {200}*/\n\
";
static char _slotValue_HTML__doc3[] = "1";
static char _slotValue_HTML__doc4[] = "fixed";
/* END OF FILE */

static SlotStruct objDesc_HTML__doc[] = {
    {"class", _slotValue_HTML__doc0},  {"name", _slotValue_HTML__doc1},
    {"script", _slotValue_HTML__doc2}, {"verbatim", _slotValue_HTML__doc3},
    {"font", _slotValue_HTML__doc4},   {(char*)0, (char*)0},
};

static char _slotValue_HTML__foldIcon0[] = "XBM";
static char _slotValue_HTML__foldIcon1[] = "HTML__foldIcon";
static char _slotValue_HTML__foldIcon2[] = "\n\
	switch (arg[0]) {\n\
	/* terrible hack */\n\
	case \"folderOpenXBM\":\n\
		return \"#define folderOpen_width 16\n\
#define folderOpen_height 16\n\
static char folderOpen_bits[] = {\n\
   0x00, 0x00, 0x00, 0x78, 0xf0, 0x87, 0x08, 0x80, 0x08, 0x80, 0xfc, 0x87,\n\
   0x02, 0x88, 0x02, 0x88, 0x04, 0x90, 0x04, 0x90, 0x08, 0xa0, 0x08, 0xa0,\n\
   0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\";\n\
	break;\n\
	case \"folderClosedXBM\":\n\
		return \"#define folderClosed_width 16\n\
#define folderClosed_height 16\n\
static char folderClosed_bits[] = {\n\
   0x00, 0x00, 0x00, 0x78, 0xf0, 0x87, 0x08, 0x80, 0xf8, 0xbf, 0x04, 0xa0,\n\
   0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xc0,\n\
   0xf8, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\";\n\
	break;\n\
	case \"buttonRelease\":\n\
		folded = send(parent(), \"toggleFolded\");\n\
		if (folded)\n\
			set(\"label\", send(\"HTML__foldIcon\", \"folderClosedXBM\"));\n\
		else\n\
			set(\"label\", send(\"HTML__foldIcon\", \"folderOpenXBM\"));\n\
		render();\n\
	break;\n\
	case \"setFolded\":\n\
		folded = arg[1];\n\
		if (folded)\n\
			set(\"label\", send(\"HTML__foldIcon\", \"folderClosedXBM\"));\n\
		else\n\
			set(\"label\", send(\"HTML__foldIcon\", \"folderOpenXBM\"));\n\
		render();\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		return send(clone(cloneID()), \"parent\", arg[1]);\n\
	break;\n\
	case \"parent\":\n\
		set(\"parent\", arg[1]);\n\
		return self();\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		foldInfo = 1;\n\
		set(\"label\", send(\"HTML__foldIcon\", \"folderOpenXBM\"));\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__foldIcon3[] = "5";
static char _slotValue_HTML__foldIcon4[] = "16";
static char _slotValue_HTML__foldIcon5[] = "16";
/* END OF FILE */

static SlotStruct objDesc_HTML__foldIcon[] = {
    {"class", _slotValue_HTML__foldIcon0},
    {"name", _slotValue_HTML__foldIcon1},
    {"script", _slotValue_HTML__foldIcon2},
    {"x", _slotValue_HTML__foldIcon3},
    {"width", _slotValue_HTML__foldIcon4},
    {"height", _slotValue_HTML__foldIcon5},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML__txtBox0[] = "field";
static char _slotValue_HTML__txtBox1[] = "HTML__txtBox";
static char _slotValue_HTML__txtBox2[] = "HTML__txtBox.txt HTML__txtBox.icon";
static char _slotValue_HTML__txtBox3[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	txt\n\
		 * arg[3]	width to use\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3]);\n\
		h = send(nthChild(0), \"make\", arg[2], arg[3]);\n\
		set(\"height\", h);\n\
		return h + 5;\n\
	break;\n\
	case \"R\": /* resize */\n\
		set(\"width\", arg[1]);\n\
		h = send(nthChild(0), \"R\", arg[1]);\n\
		set(\"height\", h);\n\
		return h + 5;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		color = getResource(\"Viola.borderColor_doc\");\n\
		if (color) set(\"BDColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox4[] = "100";
static char _slotValue_HTML__txtBox5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox7[] = "txtDisp";
static char _slotValue_HTML__txtBox8[] = "HTML__txtBox";
static char _slotValue_HTML__txtBox9[] = "HTML__txtBox.txt";
static char _slotValue_HTML__txtBox10[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	txt\n\
		 * arg[2]	width to use\n\
		 */\n\
		txt = arg[1];\n\
		set(\"width\", arg[2] - 50);\n\
		set(\"content\", txt);\n\
		set(\"height\", building_vspan());\n\
		return height() + 5;\n\
	break;\n\
	case \"R\": /* resize */\n\
		clearWindow();\n\
		set(\"width\", arg[1] - 50);\n\
		set(\"content\", txt);\n\
		vspan = set(\"height\", building_vspan());\n\
		render();\n\
		return vspan + 4;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox11[] = "50";
static char _slotValue_HTML__txtBox12[] = "10";
static char _slotValue_HTML__txtBox13[] = "10";
static char _slotValue_HTML__txtBox14[] = "normal";
static char _slotValue_HTML__txtBox15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox17[] = "XBM";
static char _slotValue_HTML__txtBox18[] = "HTML__txtBox";
static char _slotValue_HTML__txtBox19[] = "HTML__txtBox.icon";
static char _slotValue_HTML__txtBox20[] = "#define info_width 34\n\
#define info_height 33\n\
static char info_bits[] = {\n\
   0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0xe0, 0x0f, 0x00, 0xfc, 0x00, 0x7c,\n\
   0x7c, 0x00, 0xfc, 0x00, 0x1f, 0xf0, 0x01, 0xfc, 0x80, 0x0f, 0xe0, 0x03,\n\
   0xfc, 0xc0, 0x0f, 0xe0, 0x07, 0xfc, 0xe0, 0x07, 0xc0, 0x0f, 0xfc, 0xf0,\n\
   0x07, 0xc0, 0x1f, 0xfc, 0xf8, 0x07, 0xc0, 0x3f, 0xfc, 0xf8, 0x0f, 0xe0,\n\
   0x3f, 0xfc, 0xfc, 0x0f, 0xe0, 0x7f, 0xfc, 0xfc, 0x1f, 0xf0, 0x7f, 0xfc,\n\
   0xfc, 0xff, 0xfe, 0x7f, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xfe, 0x1f,\n\
   0xf0, 0xff, 0xfc, 0xfe, 0x1f, 0xf0, 0xff, 0xfc, 0xfe, 0x1f, 0xf0, 0xff,\n\
   0xfc, 0xfe, 0x1f, 0xf0, 0xff, 0xfc, 0xfe, 0x1f, 0xf0, 0xff, 0xfc, 0xfe,\n\
   0x1f, 0xf0, 0xff, 0xfc, 0xfc, 0x1f, 0xf0, 0x7f, 0xfc, 0xfc, 0x1f, 0xf0,\n\
   0x7f, 0xfc, 0xfc, 0x1f, 0xf0, 0x7f, 0xfc, 0xf8, 0x1f, 0xf0, 0x3f, 0xfc,\n\
   0xf8, 0x1f, 0xf0, 0x3f, 0xfc, 0xf0, 0x1f, 0xf0, 0x1f, 0xfc, 0xe0, 0x1f,\n\
   0xf0, 0x0f, 0xfc, 0xc0, 0x1f, 0xf0, 0x07, 0xfc, 0x80, 0x1f, 0xf0, 0x03,\n\
   0xfc, 0x00, 0x1f, 0xf0, 0x01, 0xfc, 0x00, 0xfc, 0x7f, 0x00, 0xfc, 0x00,\n\
   0xe0, 0x0f, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xfc};\n\
";
static char _slotValue_HTML__txtBox21[] = "5";
static char _slotValue_HTML__txtBox22[] = "5";
static char _slotValue_HTML__txtBox23[] = "34";
static char _slotValue_HTML__txtBox24[] = "34";
/* END OF FILE */

static SlotStruct objDesc_HTML__txtBox[] = {
    {"class", _slotValue_HTML__txtBox0},
    {"name", _slotValue_HTML__txtBox1},
    {"children", _slotValue_HTML__txtBox2},
    {"script", _slotValue_HTML__txtBox3},
    {"width", _slotValue_HTML__txtBox4},
    {"height", _slotValue_HTML__txtBox5},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox7},
    {"parent", _slotValue_HTML__txtBox8},
    {"name", _slotValue_HTML__txtBox9},
    {"script", _slotValue_HTML__txtBox10},
    {"x", _slotValue_HTML__txtBox11},
    {"width", _slotValue_HTML__txtBox12},
    {"height", _slotValue_HTML__txtBox13},
    {"font", _slotValue_HTML__txtBox14},
    {"format", _slotValue_HTML__txtBox15},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox17},
    {"parent", _slotValue_HTML__txtBox18},
    {"name", _slotValue_HTML__txtBox19},
    {"label", _slotValue_HTML__txtBox20},
    {"x", _slotValue_HTML__txtBox21},
    {"y", _slotValue_HTML__txtBox22},
    {"width", _slotValue_HTML__txtBox23},
    {"height", _slotValue_HTML__txtBox24},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML__txtBox_alert0[] = "field";
static char _slotValue_HTML__txtBox_alert1[] = "HTML__txtBox_alert";
static char _slotValue_HTML__txtBox_alert2[] = "HTML__txtBox_alert.txt HTML__txtBox_alert.icon";
static char _slotValue_HTML__txtBox_alert3[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	txt\n\
		 * arg[3]	width to use\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3] - 2);\n\
		h = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\
		set(\"height\", h);\n\
		after(2000, nthChild(1), \"tic\");\n\
		return h + 2;\n\
	break;\n\
	case \"R\": /* resize */\n\
		set(\"width\", arg[1] - 2);\n\
		h = send(nthChild(0), \"R\", arg[1]) + 3;\n\
		set(\"height\", h);\n\
		return h + 2;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML__txtBox_alert4[] = "100";
static char _slotValue_HTML__txtBox_alert5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_alert7[] = "txtDisp";
static char _slotValue_HTML__txtBox_alert8[] = "HTML__txtBox_alert";
static char _slotValue_HTML__txtBox_alert9[] = "HTML__txtBox_alert.txt";
static char _slotValue_HTML__txtBox_alert10[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	txt\n\
		 * arg[2]	width to use\n\
		 */\n\
		txt = arg[1];\n\
		set(\"width\", arg[2] - 50);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		return h + 2;\n\
	break;\n\
	case \"R\": /* resize */\n\
		clearWindow();\n\
		set(\"width\", arg[1] - 50);\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		render();\n\
		return h + 2;\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML__txtBox_alert11[] = "50";
static char _slotValue_HTML__txtBox_alert12[] = "10";
static char _slotValue_HTML__txtBox_alert13[] = "10";
static char _slotValue_HTML__txtBox_alert14[] = "normal";
static char _slotValue_HTML__txtBox_alert15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_alert17[] = "XBM";
static char _slotValue_HTML__txtBox_alert18[] = "HTML__txtBox_alert";
static char _slotValue_HTML__txtBox_alert19[] = "HTML__txtBox_alert.icon";
static char _slotValue_HTML__txtBox_alert20[] = "\n\
	switch (arg[0]) {\n\
	case \"tic\":\n\
		invertLine(15,18, x, y);\n\
		second = float(nthWord(date(), 6));\n\
		d = second * 6.0 - 90.0;\n\
		x = 8 * cos(d) + 15;\n\
		y = 8 * sin(d) + 18;\n\
		invertLine(15,18, x, y);\n\
		after(500, self(), \"tic\");\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		usual();\n\
		invertLine(15,18, x, y);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		d = 270;\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox_alert21[] = "#define hand2_width 32\n\
#define hand2_height 32\n\
static char hand2_bits[] = {\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00,\n\
   0x80, 0x7f, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x00, 0xf0, 0xff, 0x01, 0x00,\n\
   0xf8, 0xff, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x3f,\n\
   0xfe, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0x3f,\n\
   0xfe, 0x3f, 0x00, 0x00, 0xfe, 0xdf, 0x3f, 0x00, 0xfe, 0xef, 0x7f, 0x00,\n\
   0xfe, 0xef, 0x7f, 0x00, 0xfe, 0xef, 0x3f, 0x00, 0xfe, 0x3f, 0x00, 0x00,\n\
   0xfe, 0xdf, 0x3f, 0x00, 0xfe, 0xef, 0x7f, 0x00, 0xfe, 0xef, 0x7f, 0x00,\n\
   0xfe, 0xef, 0x3f, 0x00, 0xf8, 0x3f, 0x00, 0x00, 0xf0, 0xdf, 0x1f, 0x00,\n\
   0xc0, 0xdf, 0x1f, 0x00, 0x00, 0xde, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_HTML__txtBox_alert22[] = "5";
static char _slotValue_HTML__txtBox_alert23[] = "2";
static char _slotValue_HTML__txtBox_alert24[] = "40";
static char _slotValue_HTML__txtBox_alert25[] = "40";
/* END OF FILE */

static SlotStruct objDesc_HTML__txtBox_alert[] = {
    {"class", _slotValue_HTML__txtBox_alert0},
    {"name", _slotValue_HTML__txtBox_alert1},
    {"children", _slotValue_HTML__txtBox_alert2},
    {"script", _slotValue_HTML__txtBox_alert3},
    {"width", _slotValue_HTML__txtBox_alert4},
    {"height", _slotValue_HTML__txtBox_alert5},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_alert7},
    {"parent", _slotValue_HTML__txtBox_alert8},
    {"name", _slotValue_HTML__txtBox_alert9},
    {"script", _slotValue_HTML__txtBox_alert10},
    {"x", _slotValue_HTML__txtBox_alert11},
    {"width", _slotValue_HTML__txtBox_alert12},
    {"height", _slotValue_HTML__txtBox_alert13},
    {"font", _slotValue_HTML__txtBox_alert14},
    {"format", _slotValue_HTML__txtBox_alert15},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_alert17},
    {"parent", _slotValue_HTML__txtBox_alert18},
    {"name", _slotValue_HTML__txtBox_alert19},
    {"script", _slotValue_HTML__txtBox_alert20},
    {"label", _slotValue_HTML__txtBox_alert21},
    {"x", _slotValue_HTML__txtBox_alert22},
    {"y", _slotValue_HTML__txtBox_alert23},
    {"width", _slotValue_HTML__txtBox_alert24},
    {"height", _slotValue_HTML__txtBox_alert25},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML__txtBox_caution0[] = "field";
static char _slotValue_HTML__txtBox_caution1[] = "HTML__txtBox_caution";
static char _slotValue_HTML__txtBox_caution2[] = "HTML__txtBox_caution.txt HTML__txtBox_caution.icon";
static char _slotValue_HTML__txtBox_caution3[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	txt\n\
		 * arg[3]	width to use\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3]-2);\n\
		h = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\
		set(\"height\", h);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		return h + 2;\n\
	break;\n\
	case \"R\": /* resize */\n\
		set(\"width\", arg[1]-2);\n\
		h = send(nthChild(0), \"R\", arg[1]) + 3;\n\
		set(\"height\", h);\n\
		return h + 2;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox_caution4[] = "100";
static char _slotValue_HTML__txtBox_caution5[] = "8";
static char _slotValue_HTML__txtBox_caution6[] = "6";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_caution8[] = "txtDisp";
static char _slotValue_HTML__txtBox_caution9[] = "HTML__txtBox_caution";
static char _slotValue_HTML__txtBox_caution10[] = "HTML__txtBox_caution.txt";
static char _slotValue_HTML__txtBox_caution11[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	txt\n\
		 * arg[2]	width to use\n\
		 */\n\
		txt = arg[1];\n\
		set(\"width\", arg[2] - 50);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'R': /* resize */\n\
		clearWindow();\n\
		set(\"width\", arg[1] - 50);\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		render();\n\
		return h;\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		/*processMouseMove();*/\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML__txtBox_caution12[] = "50";
static char _slotValue_HTML__txtBox_caution13[] = "10";
static char _slotValue_HTML__txtBox_caution14[] = "10";
static char _slotValue_HTML__txtBox_caution15[] = "normal";
static char _slotValue_HTML__txtBox_caution16[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_caution18[] = "XBM";
static char _slotValue_HTML__txtBox_caution19[] = "HTML__txtBox_caution";
static char _slotValue_HTML__txtBox_caution20[] = "HTML__txtBox_caution.icon";
static char _slotValue_HTML__txtBox_caution21[] = "\n\
	switch (arg[0]) {\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox_caution22[] = "#define caution_width 34\n\
#define caution_height 31\n\
static char caution_bits[] = {\n\
 0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0xfc,0xf8,0xff,0xff,0x7f,0xfc,\n\
 0xf8,0xff,0xff,0x7f,0xfc,0xfc,0xff,0xff,0xff,0xfc,0xfc,0xff,0xfc,0xff,0xfc,\n\
 0xf8,0x7f,0xf8,0x7f,0xfc,0xf8,0x7f,0xf8,0x7f,0xfc,0xf0,0x7f,0xf8,0x3f,0xfc,\n\
 0xf0,0x7f,0xf8,0x3f,0xfc,0xe0,0x7f,0xf8,0x1f,0xfc,0xe0,0x7f,0xf8,0x1f,0xfc,\n\
 0xc0,0x7f,0xf8,0x0f,0xfc,0xc0,0x7f,0xf8,0x0f,0xfc,0x80,0xff,0xfc,0x07,0xfc,\n\
 0x00,0xff,0xfc,0x03,0xfc,0x00,0xff,0xfc,0x03,0xfc,0x00,0xfe,0xfc,0x01,0xfc,\n\
 0x00,0xfe,0xff,0x01,0xfc,0x00,0xfc,0xff,0x00,0xfc,0x00,0xfc,0xfc,0x00,0xfc,\n\
 0x00,0x78,0x78,0x00,0xfc,0x00,0xf8,0x7c,0x00,0xfc,0x00,0xf0,0x3f,0x00,0xfc,\n\
 0x00,0xe0,0x1f,0x00,0xfc,0x00,0xe0,0x1f,0x00,0xfc,0x00,0xc0,0x0f,0x00,0xfc,\n\
 0x00,0xc0,0x0f,0x00,0xfc,0x00,0x80,0x07,0x00,0xfc,0x00,0x00,0x00,0x00,0xfc,\n\
 0x00,0x00,0x00,0x00,0xfc};\n\
";
static char _slotValue_HTML__txtBox_caution23[] = "5";
static char _slotValue_HTML__txtBox_caution24[] = "34";
static char _slotValue_HTML__txtBox_caution25[] = "32";
/* END OF FILE */

static SlotStruct objDesc_HTML__txtBox_caution[] = {
    {"class", _slotValue_HTML__txtBox_caution0},
    {"name", _slotValue_HTML__txtBox_caution1},
    {"children", _slotValue_HTML__txtBox_caution2},
    {"script", _slotValue_HTML__txtBox_caution3},
    {"width", _slotValue_HTML__txtBox_caution4},
    {"height", _slotValue_HTML__txtBox_caution5},
    {"border", _slotValue_HTML__txtBox_caution6},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_caution8},
    {"parent", _slotValue_HTML__txtBox_caution9},
    {"name", _slotValue_HTML__txtBox_caution10},
    {"script", _slotValue_HTML__txtBox_caution11},
    {"x", _slotValue_HTML__txtBox_caution12},
    {"width", _slotValue_HTML__txtBox_caution13},
    {"height", _slotValue_HTML__txtBox_caution14},
    {"font", _slotValue_HTML__txtBox_caution15},
    {"format", _slotValue_HTML__txtBox_caution16},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_caution18},
    {"parent", _slotValue_HTML__txtBox_caution19},
    {"name", _slotValue_HTML__txtBox_caution20},
    {"script", _slotValue_HTML__txtBox_caution21},
    {"label", _slotValue_HTML__txtBox_caution22},
    {"x", _slotValue_HTML__txtBox_caution23},
    {"width", _slotValue_HTML__txtBox_caution24},
    {"height", _slotValue_HTML__txtBox_caution25},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML__txtBox_error0[] = "field";
static char _slotValue_HTML__txtBox_error1[] = "HTML__txtBox_error";
static char _slotValue_HTML__txtBox_error2[] = "HTML__txtBox_error.txt HTML__txtBox_error.icon";
static char _slotValue_HTML__txtBox_error3[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	txt\n\
		 * arg[3]	width to use\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3]);\n\
		h = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\
		set(\"height\", h);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		return h + 2;\n\
	break;\n\
	case \"R\": /* resize */\n\
		set(\"width\", arg[1]);\n\
		h = send(nthChild(0), \"R\", arg[1]) + 3;\n\
		set(\"height\", h);\n\
		return h + 2;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML__txtBox_error4[] = "100";
static char _slotValue_HTML__txtBox_error5[] = "8";
static char _slotValue_HTML__txtBox_error6[] = "6";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_error8[] = "txtDisp";
static char _slotValue_HTML__txtBox_error9[] = "HTML__txtBox_error";
static char _slotValue_HTML__txtBox_error10[] = "HTML__txtBox_error.txt";
static char _slotValue_HTML__txtBox_error11[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	txt\n\
		 * arg[2]	width to use\n\
		 */\n\
		txt = arg[1];\n\
		set(\"width\", arg[2] - 50);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		return h + 2;\n\
	break;\n\
	case \"R\": /* resize */\n\
		clearWindow();\n\
		set(\"width\", arg[1] - 50);\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		render();\n\
		return h + 2;\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		/*processMouseMove();*/\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML__txtBox_error12[] = "50";
static char _slotValue_HTML__txtBox_error13[] = "10";
static char _slotValue_HTML__txtBox_error14[] = "10";
static char _slotValue_HTML__txtBox_error15[] = "normal";
static char _slotValue_HTML__txtBox_error16[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_error18[] = "XBM";
static char _slotValue_HTML__txtBox_error19[] = "HTML__txtBox_error";
static char _slotValue_HTML__txtBox_error20[] = "HTML__txtBox_error.icon";
static char _slotValue_HTML__txtBox_error21[] = "\n\
	switch (arg[0]) {\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox_error22[] = "#define error_width 32\n\
#define error_height 29\n\
static char error_bits[] = {\n\
 0x00,0xfe,0x7f,0x00,0x00,0xff,0xff,0x00,0x80,0xff,0xff,0x01,0xc0,0xff,0xff,\n\
 0x03,0xe0,0xff,0xff,0x07,0xf0,0xff,0xff,0x0f,0xf8,0xff,0xff,0x1f,0xfc,0xff,\n\
 0xff,0x3f,0xfe,0xff,0xff,0x7f,0x0e,0x31,0xce,0x78,0xee,0xad,0xb5,0x76,0xee,\n\
 0xad,0xb5,0x76,0xee,0xad,0xb5,0x76,0x8e,0x31,0xb6,0x78,0xee,0x39,0xb7,0x7c,\n\
 0xee,0xb5,0xb6,0x7a,0xee,0xb5,0xb6,0x7a,0xee,0xa5,0xb5,0x76,0x0e,0xad,0xcd,\n\
 0x76,0xfe,0xff,0xff,0x7f,0xfc,0xff,0xff,0x3f,0xf8,0xff,0xff,0x1f,0xf0,0xff,\n\
 0xff,0x0f,0xe0,0xff,0xff,0x07,0xc0,0xff,0xff,0x03,0x80,0xff,0xff,0x01,0x00,\n\
 0xff,0xff,0x00,0x00,0xfe,0x7f,0x00,0x00,0x00,0x00,0x00};\n\
";
static char _slotValue_HTML__txtBox_error23[] = "5";
static char _slotValue_HTML__txtBox_error24[] = "2";
static char _slotValue_HTML__txtBox_error25[] = "32";
static char _slotValue_HTML__txtBox_error26[] = "32";
/* END OF FILE */

static SlotStruct objDesc_HTML__txtBox_error[] = {
    {"class", _slotValue_HTML__txtBox_error0},    {"name", _slotValue_HTML__txtBox_error1},
    {"children", _slotValue_HTML__txtBox_error2}, {"script", _slotValue_HTML__txtBox_error3},
    {"width", _slotValue_HTML__txtBox_error4},    {"height", _slotValue_HTML__txtBox_error5},
    {"border", _slotValue_HTML__txtBox_error6},   {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_error8},    {"parent", _slotValue_HTML__txtBox_error9},
    {"name", _slotValue_HTML__txtBox_error10},    {"script", _slotValue_HTML__txtBox_error11},
    {"x", _slotValue_HTML__txtBox_error12},       {"width", _slotValue_HTML__txtBox_error13},
    {"height", _slotValue_HTML__txtBox_error14},  {"font", _slotValue_HTML__txtBox_error15},
    {"format", _slotValue_HTML__txtBox_error16},  {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_error18},   {"parent", _slotValue_HTML__txtBox_error19},
    {"name", _slotValue_HTML__txtBox_error20},    {"script", _slotValue_HTML__txtBox_error21},
    {"label", _slotValue_HTML__txtBox_error22},   {"x", _slotValue_HTML__txtBox_error23},
    {"y", _slotValue_HTML__txtBox_error24},       {"width", _slotValue_HTML__txtBox_error25},
    {"height", _slotValue_HTML__txtBox_error26},  {(char*)0, (char*)0},
};

static char _slotValue_HTML__txtBox_note0[] = "field";
static char _slotValue_HTML__txtBox_note1[] = "HTML__txtBox_note";
static char _slotValue_HTML__txtBox_note2[] = "HTML__txtBox_note.txt HTML__txtBox_note.icon";
static char _slotValue_HTML__txtBox_note3[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	txt\n\
		 * arg[3]	width to use\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3] - 2);\n\
		h = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\
		set(\"height\", h);\n\
		return h + 2;\n\
	break;\n\
	case \"R\": /* resize */\n\
		set(\"width\", arg[1] - 2);\n\
		h = send(nthChild(0), \"R\", arg[1]) + 3;\n\
		set(\"height\", h);\n\
		return h + 2;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML__txtBox_note4[] = "100";
static char _slotValue_HTML__txtBox_note5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_note7[] = "txtDisp";
static char _slotValue_HTML__txtBox_note8[] = "HTML__txtBox_note";
static char _slotValue_HTML__txtBox_note9[] = "HTML__txtBox_note.txt";
static char _slotValue_HTML__txtBox_note10[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	txt\n\
		 * arg[2]	width to use\n\
		 */\n\
		txt = arg[1];\n\
		set(\"width\", arg[2] - 50);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		return h + 2;\n\
	break;\n\
	case \"R\": /* resize */\n\
		clearWindow();\n\
		set(\"width\", arg[1] - 50);\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		render();\n\
		return h + 2;\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		/*processMouseMove();*/\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML__txtBox_note11[] = "50";
static char _slotValue_HTML__txtBox_note12[] = "10";
static char _slotValue_HTML__txtBox_note13[] = "10";
static char _slotValue_HTML__txtBox_note14[] = "normal";
static char _slotValue_HTML__txtBox_note15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_note17[] = "XBM";
static char _slotValue_HTML__txtBox_note18[] = "HTML__txtBox_note";
static char _slotValue_HTML__txtBox_note19[] = "HTML__txtBox_note.icon";
static char _slotValue_HTML__txtBox_note20[] = "\n\
	switch (arg[0]) {\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox_note21[] = "#define info_width 32\n\
#define info_height 32\n\
static char info_bits[] = {\n\
   0x00, 0xf0, 0x07, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0x80, 0xff, 0xff, 0x00,\n\
   0xc0, 0xff, 0xff, 0x01, 0xe0, 0x3f, 0xfe, 0x03, 0xf0, 0x1f, 0xfc, 0x07,\n\
   0xf8, 0x0f, 0xf8, 0x0f, 0xfc, 0x0f, 0xf8, 0x1f, 0xfc, 0x0f, 0xf8, 0x1f,\n\
   0xfe, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f, 0xfe, 0x3f, 0xfe, 0xff, 0xff, 0x3f,\n\
   0xff, 0x0f, 0xfc, 0x7f, 0xff, 0x0f, 0xfc, 0x7f, 0xff, 0x1f, 0xfc, 0x7f,\n\
   0xff, 0x1f, 0xfc, 0x7f, 0xff, 0x1f, 0xfc, 0x7f, 0xff, 0x1f, 0xfc, 0x7f,\n\
   0xff, 0x1f, 0xfc, 0x7f, 0xfe, 0x1f, 0xfc, 0x3f, 0xfe, 0x1f, 0xfc, 0x3f,\n\
   0xfe, 0x1f, 0xfc, 0x3f, 0xfc, 0x1f, 0xfc, 0x1f, 0xfc, 0x07, 0xf0, 0x1f,\n\
   0xf8, 0x07, 0xf0, 0x0f, 0xf0, 0x07, 0xf0, 0x07, 0xe0, 0xff, 0xff, 0x03,\n\
   0xc0, 0xff, 0xff, 0x01, 0x80, 0xff, 0xff, 0x00, 0x00, 0xfe, 0x3f, 0x00,\n\
   0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_HTML__txtBox_note22[] = "5";
static char _slotValue_HTML__txtBox_note23[] = "2";
static char _slotValue_HTML__txtBox_note24[] = "32";
static char _slotValue_HTML__txtBox_note25[] = "32";
/* END OF FILE */

static SlotStruct objDesc_HTML__txtBox_note[] = {
    {"class", _slotValue_HTML__txtBox_note0},
    {"name", _slotValue_HTML__txtBox_note1},
    {"children", _slotValue_HTML__txtBox_note2},
    {"script", _slotValue_HTML__txtBox_note3},
    {"width", _slotValue_HTML__txtBox_note4},
    {"height", _slotValue_HTML__txtBox_note5},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_note7},
    {"parent", _slotValue_HTML__txtBox_note8},
    {"name", _slotValue_HTML__txtBox_note9},
    {"script", _slotValue_HTML__txtBox_note10},
    {"x", _slotValue_HTML__txtBox_note11},
    {"width", _slotValue_HTML__txtBox_note12},
    {"height", _slotValue_HTML__txtBox_note13},
    {"font", _slotValue_HTML__txtBox_note14},
    {"format", _slotValue_HTML__txtBox_note15},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_note17},
    {"parent", _slotValue_HTML__txtBox_note18},
    {"name", _slotValue_HTML__txtBox_note19},
    {"script", _slotValue_HTML__txtBox_note20},
    {"label", _slotValue_HTML__txtBox_note21},
    {"x", _slotValue_HTML__txtBox_note22},
    {"y", _slotValue_HTML__txtBox_note23},
    {"width", _slotValue_HTML__txtBox_note24},
    {"height", _slotValue_HTML__txtBox_note25},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML__txtBox_time0[] = "field";
static char _slotValue_HTML__txtBox_time1[] = "HTML__txtBox_time";
static char _slotValue_HTML__txtBox_time2[] = "HTML__txtBox_time.txt HTML__txtBox_time.icon";
static char _slotValue_HTML__txtBox_time3[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	txt\n\
		 * arg[3]	width to use\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3]);\n\
		h = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\
		set(\"height\", h);\n\
		after(2000, nthChild(1), \"tic\");\n\
		return h;\n\
	break;\n\
	case 'R': /* resize */\n\
		set(\"width\", arg[1]);\n\
		h = send(nthChild(0), 'R', arg[1]) + 3;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox_time4[] = "100";
static char _slotValue_HTML__txtBox_time5[] = "100";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_time7[] = "txtDisp";
static char _slotValue_HTML__txtBox_time8[] = "HTML__txtBox_time";
static char _slotValue_HTML__txtBox_time9[] = "HTML__txtBox_time.txt";
static char _slotValue_HTML__txtBox_time10[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	txt\n\
		 * arg[2]	width to use\n\
		 */\n\
		txt = arg[1];\n\
		set(\"width\", arg[2] - 50);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'R': /* resize */\n\
		clearWindow();\n\
		set(\"width\", arg[1] - 50);\n\
		set(\"content\", txt);\n\
		h = building_vspan();\n\
		if (h < 32) h = 32;\n\
		set(\"height\", h);\n\
		render();\n\
		return h;\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML__txtBox_time11[] = "50";
static char _slotValue_HTML__txtBox_time12[] = "10";
static char _slotValue_HTML__txtBox_time13[] = "10";
static char _slotValue_HTML__txtBox_time14[] = "normal";
static char _slotValue_HTML__txtBox_time15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_time17[] = "XBM";
static char _slotValue_HTML__txtBox_time18[] = "HTML__txtBox_time";
static char _slotValue_HTML__txtBox_time19[] = "HTML__txtBox_time.icon";
static char _slotValue_HTML__txtBox_time20[] = "\n\
	switch (arg[0]) {\n\
	case \"tic\":\n\
		invertLine(15,18, x, y);\n\
		second = float(nthWord(date(), 6));\n\
		d = second * 6.0 - 90.0;\n\
		x = 8 * cos(d) + 15;\n\
		y = 8 * sin(d) + 18;\n\
		invertLine(15,18, x, y);\n\
		after(500, self(), \"tic\");\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		usual();\n\
		invertLine(15,18, x, y);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		d = 270;\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML__txtBox_time21[] = "#define timer_width 32\n\
#define timer_height 32\n\
static char timer_bits[] = {\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x00, 0x08, 0x0a, 0x00,\n\
   0x00, 0xf8, 0x0f, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x40, 0x01, 0x00,\n\
   0x00, 0xf0, 0x07, 0x00, 0x00, 0x0c, 0x18, 0x00, 0x00, 0xf3, 0x67, 0x00,\n\
   0x80, 0xfc, 0x9f, 0x00, 0x40, 0xfe, 0xbf, 0x01, 0x40, 0xff, 0x7f, 0x01,\n\
   0xa0, 0xff, 0xff, 0x02, 0xa0, 0xff, 0xff, 0x02, 0xd0, 0xff, 0xff, 0x05,\n\
   0xd0, 0xff, 0xff, 0x07, 0xd0, 0xff, 0xff, 0x05, 0xd0, 0xff, 0xff, 0x07,\n\
   0xd0, 0xff, 0xff, 0x05, 0xd0, 0xff, 0xff, 0x05, 0xd0, 0xff, 0xff, 0x07,\n\
   0xa0, 0xff, 0xff, 0x02, 0xa0, 0xff, 0xff, 0x03, 0x40, 0xff, 0x7f, 0x01,\n\
   0x40, 0xfe, 0xff, 0x01, 0x80, 0xfc, 0xdf, 0x00, 0x00, 0xf3, 0x6f, 0x00,\n\
   0x00, 0x0c, 0x18, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,\n\
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_HTML__txtBox_time22[] = "5";
static char _slotValue_HTML__txtBox_time23[] = "5";
static char _slotValue_HTML__txtBox_time24[] = "40";
static char _slotValue_HTML__txtBox_time25[] = "40";
/* END OF FILE */

static SlotStruct objDesc_HTML__txtBox_time[] = {
    {"class", _slotValue_HTML__txtBox_time0},
    {"name", _slotValue_HTML__txtBox_time1},
    {"children", _slotValue_HTML__txtBox_time2},
    {"script", _slotValue_HTML__txtBox_time3},
    {"width", _slotValue_HTML__txtBox_time4},
    {"height", _slotValue_HTML__txtBox_time5},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_time7},
    {"parent", _slotValue_HTML__txtBox_time8},
    {"name", _slotValue_HTML__txtBox_time9},
    {"script", _slotValue_HTML__txtBox_time10},
    {"x", _slotValue_HTML__txtBox_time11},
    {"width", _slotValue_HTML__txtBox_time12},
    {"height", _slotValue_HTML__txtBox_time13},
    {"font", _slotValue_HTML__txtBox_time14},
    {"format", _slotValue_HTML__txtBox_time15},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML__txtBox_time17},
    {"parent", _slotValue_HTML__txtBox_time18},
    {"name", _slotValue_HTML__txtBox_time19},
    {"script", _slotValue_HTML__txtBox_time20},
    {"label", _slotValue_HTML__txtBox_time21},
    {"x", _slotValue_HTML__txtBox_time22},
    {"y", _slotValue_HTML__txtBox_time23},
    {"width", _slotValue_HTML__txtBox_time24},
    {"height", _slotValue_HTML__txtBox_time25},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_address0[] = "field";
static char _slotValue_HTML_address1[] = "HTML_address";
static char _slotValue_HTML_address2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		h = 0;\n\
/*		SGMLBuildDoc_setBuff(-1);*/\n\
		send(self(), \"setStyles\");\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[2], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor, paneConfig);\n\
			makeAnchor = 0;\n\
		} \n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\": /* done */\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		send(self(), \"setStyles\");\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[2], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor, paneConfig);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		case \"ALIGN\":\n\
			switch (arg[2]) {\n\
			case \"center\":\n\
				paneConfig = \"center\";\n\
			break;\n\
			case \"left\":\n\
				paneConfig = \"westToEast\";\n\
			break;\n\
			case \"right\":\n\
				paneConfig = \"eastToWest\";\n\
			break;\n\
			}\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"ADDRESS\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = width();\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1] + 20;\n\
		return vspan;\n\
	break;\n\
	case 'T':\n\
		/* arg[1] = y\n\
		 * arg[2] = width\n\
		 */\n\
		h = get(\"height\");\n\
		parentHeight = send(parent(), \"heightP\");\n\
		heightDiff = h - parentHeight;\n\
		if (heightDiff > 0) {\n\
			heightRatio =  float(heightDiff) / -100.0;\n\
		} else {\n\
			heightRatio = 0;\n\
			h = parentHeight;\n\
			set(\"height\", h);\n\
		}\n\
		prevWidth = arg[2];\n\
		prevHeight = parentHeight;\n\
\n\
		return h;\n\
	break;\n\
	case \"inAnchor\":\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"setAnchor\":\n\
		makeAnchor = arg[1];\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"styleSheet\":\n\
		return tagPtr;\n\
	break;\n\
	case \"setStyles\":\n\
		if (tagPtr == 0) tagPtr = STG_tagPtr(\"ADDRESS\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
			i = STG_attr(tagPtr, \"fontSlant\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<ADDRESS\");\n\
		if (tagID) print(\" NAME=\\\"\", tagID, \"\\\">\\n\
\");\n\
		else print(\">\\n\
\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i),\n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset;\n\
			}\n\
		}\n\
		print(\"</ADDRESS>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_address3[] = "100";
static char _slotValue_HTML_address4[] = "10";
/* END OF FILE */

static SlotStruct objDesc_HTML_address[] = {
    {"class", _slotValue_HTML_address0},  {"name", _slotValue_HTML_address1},
    {"script", _slotValue_HTML_address2}, {"width", _slotValue_HTML_address3},
    {"height", _slotValue_HTML_address4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_attr0[] = "field";
static char _slotValue_HTML_attr1[] = "HTML_attr";
static char _slotValue_HTML_attr2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (tagID) {\n\
			send(parent(), \"setAnchor\", tagID);\n\
			tagID = 0;\n\
		}\n\
		if (url) {\n\
			t = concat(\" \\\\b(\", compressSpaces(get(\"label\")),\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
			url = 0;\n\
			return t;\n\
		} else {\n\
			return compressSpaces(get(\"label\"));\n\
		}\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"HREF\":\n\
			url = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		set(\"content2\", self());/*a kludge to deal with cloning*/\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		vspan = 1;\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
			  vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		return vspan;\n\
	break;\n\
	case \"copyObj\":\n\
		url = send(arg[1], \"url\");\n\
		return 0;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"inAnchor\":\n\
/* trouble is, once attr is copied, 'url' and other info in variables\n\
are lost. Solution send message to this object to have itself copied\n\
(including the appropriate variables).\n\
*/\n\
		return url;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"url\":\n\
		/* for <img ismap...> to ask */\n\
		return url;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"findForm\":\n\
		return send(parent(), \"findForm\");\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_attr[] = {
    {"class", _slotValue_HTML_attr0},
    {"name", _slotValue_HTML_attr1},
    {"script", _slotValue_HTML_attr2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_author0[] = "field";
static char _slotValue_HTML_author1[] = "HTML_author";
static char _slotValue_HTML_author2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		send(send(parent(), \"findTop\"), \"reportAuthor\", href);\n\
		href = 0;\n\
		return -1;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"HREF\":\n\
			href = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case 'R':\n\
		return 1;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"AI\":\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_author[] = {
    {"class", _slotValue_HTML_author0},
    {"name", _slotValue_HTML_author1},
    {"script", _slotValue_HTML_author2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_base0[] = "field";
static char _slotValue_HTML_base1[] = "HTML_base";
static char _slotValue_HTML_base2[] = "\n\
        switch (arg[0]) {\n\
        case \"D\":\n\
                return -1;\n\
        break;\n\
        case \"config\":\n\
	case \"AI\":\n\
                return;\n\
        break;\n\
        case 'R':\n\
                return 0;\n\
        break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"HREF\":\n\
	                send(send(parent(), \"findTop\"), \"baseURL\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
        case \"gotoAnchor\":\n\
                return \"\";\n\
        break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break; \n\
	}\n\
        usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_base[] = {
    {"class", _slotValue_HTML_base0},
    {"name", _slotValue_HTML_base1},
    {"script", _slotValue_HTML_base2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_body0[] = "field";
static char _slotValue_HTML_body1[] = "HTML_body";
static char _slotValue_HTML_body2[] = "\n\
/*\n\
print(\"HTML_BODY: self=\", self(), \": \");\n\
for (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");print(\"...end\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"F\": /* flush */\n\
		h = 0;\n\
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\
		send(self(), \"setStyles\");\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(), \n\
				compressSpaces(get(\"label\")), \n\
				style_p[2], \n\
				get(\"width\") - style_p[2] - style_p[3],\n\
				SGMLBuildDoc_span() + style_p[0],\n\
				makeAnchor) + style_p[1];\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\": /* done */\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\", self());\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[2], \n\
				get(\"width\") - style_p[2], \n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"BODY\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"BODY\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"placeID\":\n\
		/* this is clumsy. should be simplified with a primitive f() */\n\
		/* find the caller (child) object's place in the obj list */\n\
		cobj = arg[1];\n\
		objPlace = -1;\n\
\n\
		for (i = objectListCount_children() - 1; i >= 0; i--) {\n\
			nobj = nthChild(i);/*bug: can't inline into == XXX*/\n\
			if (cobj == nobj) {\n\
				objPlace = i;\n\
			}\n\
		}\n\
		objPlacePath = concat(objPlace, \" \", arg[2]);\n\
		return send(parent(), \"placeID\", self(), objPlacePath);\n\
	break;\n\
	case \"CE_change\":\n\
		return send(nthChild(nthWord(arg[1], 1)), arg[0],\n\
				nthWord(arg[1], 2, 99), arg[2]);\n\
	break;\n\
	case \"CE_lock\":\n\
	case \"CE_unlock\":\n\
		return send(nthChild(nthWord(arg[1], 1)), arg[0], \n\
				nthWord(arg[1], 2, 99));\n\
	break;\n\
	case \"inPreP\":\n\
	case \"inAnchor\":\n\
	case \"L\": /*???*/\n\
	case \"compact\":\n\
		return 0;\n\
	break;\n\
	case \"setAnchor\":\n\
		makeAnchor = arg[1];\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<BODY>\\n\
\");\n\
		n = countChildren();\n\
		if (n) {\n\
			for (i = 0; i < n; i++)\n\
				send(nthChild(i), \"outputSGML\");\n\
		}\n\
		print(\"</BODY>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"setStyles\":\n\
		useTagInfo_align = 1;\n\
		tagPtr = STG_tagPtr(\"BODY\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
			i = STG_attr(tagPtr, \"border\");\n\
			if (i) {\n\
				set(\"border\", 6);\n\
				set(\"BDColor\", get(\"FGColor\"));/*XXX*/\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola.background_doc\");\n\
		if (color) set(\"BGColor\", color);\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"FGColor\", color);\n\
		color = getResource(\"Viola.borderColor_doc\");\n\
		if (color) set(\"BDColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_body[] = {
    {"class", _slotValue_HTML_body0},
    {"name", _slotValue_HTML_body1},
    {"script", _slotValue_HTML_body2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_box0[] = "field";
static char _slotValue_HTML_box1[] = "HTML_box";
static char _slotValue_HTML_box2[] = "\n\
\n\
print(\"HTML_box: self=\", self(), \": \");\n\
for (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");\n\
print(\"^^^^^^^end\\n\
\");\n\
\n\
	switch (arg[0]) {\n\
	case \"entity\":\n\
print(\"ENTITY FLUSH MATH label>>>>>\", get(\"label\"), \"<<<\\n\
\");\n\
		if (isBlank(get(\"label\"))) return 0;\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = get(\"label\");\n\
		tokCount++;\n\
\n\
		entity_number = arg[1];\n\
		if (entity_number == 50) {/*infin*/\n\
		} else if (entity_number == 51) { /*integral*/\n\
			tok[tokCount] = 19; /*MINFO_INTEGRAL*/\n\
			data[tokCount] = \"\";\n\
			tokCount++;\n\
		} else if (entity_number == 65) { /*sigma*/\n\
			tok[tokCount] = 20; /*MINFO_SUM*/\n\
			data[tokCount] = \"\";\n\
			tokCount++;\n\
		}\n\
		return;\n\
	break;\n\
	case \"tok&data\":\n\
		/* arg[1]	token\n\
		 * arg[2]	data\n\
		 */\n\
		tok[tokCount] = arg[1];\n\
		data[tokCount] = arg[2];\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		/* arg[1]	data\n\
		 */\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = arg[1];\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"tok\":\n\
		/* arg[1]	token type\n\
		 */\n\
		tok[tokCount] = arg[1];\n\
		data[tokCount] = \"\";\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"over\":\n\
		tok[tokCount] = 4;\n\
		data[tokCount] = \"\";\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"F\":\n\
print(\"F BOX--- label-{\", get(\"label\"), \"}\\n\
\");\n\
		if (isBlank(get(\"label\"))) return -1;\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = get(\"label\");\n\
		tokCount++;\n\
		return -1;\n\
	break;\n\
	case \"D\":\n\
		SGMLBuildDoc_setBuff(0);\n\
print(\"D BOX--- label-{\", get(\"label\"), \"}\\n\
\");\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			tok[tokCount] = 2;\n\
			data[tokCount] = get(\"label\");\n\
			tokCount++;\n\
		}\n\
\n\
		send(parent(), \"tok\", 5/*BOX_BEGIN*/);\n\
\n\
		for (i = 0; i < tokCount; i++) {\n\
			print(\"XXX box_tok \", i, \":   type=\", tok[i], \n\
				\"  data={\", data[i], \"}\\n\
\");\n\
		}\n\
\n\
		for (i = 0; i < tokCount; i++) {\n\
			send(parent(), \"tok&data\", tok[i], data[i]);\n\
		}\n\
		send(parent(), \"tok\", 6/*BOX_END*/);\n\
		tokCount = 0;\n\
\n\
		return 0;/*destroy self*/\n\
	break;\n\
	case \"R\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_box[] = {
    {"class", _slotValue_HTML_box0},
    {"name", _slotValue_HTML_box1},
    {"script", _slotValue_HTML_box2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_bulletItem0[] = "txtDisp";
static char _slotValue_HTML_bulletItem1[] = "1";
static char _slotValue_HTML_bulletItem2[] = "HTML_listSep";
static char _slotValue_HTML_bulletItem3[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		return expose();\n\
	break;\n\
	case \"D\":\n\
		txt = send(parent(), \"data\");\n\
		if (isBlank(txt)) {\n\
			return 0;\n\
		} else {\n\
			set(\"content\", txt);\n\
			return (building_vspan() + 2);\n\
		}\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		/* arg[2]	data\n\
		 * arg[3]	x\n\
		 * arg[4]	width\n\
		 * arg[5]	y\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"x\", arg[3]);\n\
		set(\"y\", arg[5]);\n\
		set(\"width\", arg[4]);\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", arg[2]);\n\
		h = building_vspan() + 4;\n\
		set(\"height\", h);\n\
		set(\"maxHeight\", h);\n\
		h += 4;\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		return h;\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"R\":\n\
	case \"clone\":\n\
	case \"buttonRelease\":\n\
	case \"config\":\n\
	case \"gotoAnchor\":\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_bulletItem4[] = "100";
static char _slotValue_HTML_bulletItem5[] = "30";
static char _slotValue_HTML_bulletItem6[] = "normal";
static char _slotValue_HTML_bulletItem7[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_bulletItem[] = {
    {"class", _slotValue_HTML_bulletItem0},
    {"scurity", _slotValue_HTML_bulletItem1},
    {"name", _slotValue_HTML_bulletItem2},
    {"script", _slotValue_HTML_bulletItem3},
    {"width", _slotValue_HTML_bulletItem4},
    {"height", _slotValue_HTML_bulletItem5},
    {"font", _slotValue_HTML_bulletItem6},
    {"format", _slotValue_HTML_bulletItem7},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_caution0[] = "txtDisp";
static char _slotValue_HTML_caution1[] = "HTML_caution";
static char _slotValue_HTML_caution2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"D\": /* done */\n\
		inPreP = send(parent(), \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", get(\"label\"));\n\
		return (building_vspan() + 2);\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		style = SGMLGetStyle(\"HTML\", \"CAUTION\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		style = SGMLGetStyle(\"HTML\", \"CAUTION\");\n\
		vspan = style[0];\n\
		set(\"width\", get(\"width\") - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"BDColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_caution3[] = "100";
static char _slotValue_HTML_caution4[] = "30";
static char _slotValue_HTML_caution5[] = "normal";
static char _slotValue_HTML_caution6[] = "1";
static char _slotValue_HTML_caution7[] = "6";
/* END OF FILE */

static SlotStruct objDesc_HTML_caution[] = {
    {"class", _slotValue_HTML_caution0},
    {"name", _slotValue_HTML_caution1},
    {"script", _slotValue_HTML_caution2},
    {"width", _slotValue_HTML_caution3},
    {"height", _slotValue_HTML_caution4},
    {"font", _slotValue_HTML_caution5},
    {"format", _slotValue_HTML_caution6},
    {"border", _slotValue_HTML_caution7},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_change0[] = "field";
static char _slotValue_HTML_change1[] = "HTML_base";
static char _slotValue_HTML_change2[] = "\n\
        switch (arg[0]) {\n\
        case \"D\":\n\
                return -1;\n\
        break;\n\
        case \"config\":\n\
	case \"AI\":\n\
                return;\n\
        break;\n\
        case 'R':\n\
                return 0;\n\
        break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"HREF\":\n\
	                send(send(parent(), \"findTop\"), \"baseURL\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
        case \"gotoAnchor\":\n\
                return \"\";\n\
        break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break; \n\
	}\n\
        usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_change[] = {
    {"class", _slotValue_HTML_change0},
    {"name", _slotValue_HTML_change1},
    {"script", _slotValue_HTML_change2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_changed0[] = "field";
static char _slotValue_HTML_changed1[] = "HTML_changed";
static char _slotValue_HTML_changed2[] = "\n\
        switch (arg[0]) {\n\
        case \"D\":\n\
                return -1;\n\
        break;\n\
        case \"config\":\n\
	case \"AI\":\n\
                return;\n\
        break;\n\
        case 'R':\n\
                return 0;\n\
        break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"IDREF\":\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
        case \"gotoAnchor\":\n\
                return \"\";\n\
        break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola.background_doc\");\n\
		if (color) {\n\
			set(\"BGColor\", color);\n\
			set(\"BDColor\", color);\n\
		}\n\
		return;\n\
	break; \n\
	}\n\
        usual();\n\
";
static char _slotValue_HTML_changed3[] = "LemonChiffon1";
static char _slotValue_HTML_changed4[] = "LemonChiffon1";
/* END OF FILE */

static SlotStruct objDesc_HTML_changed[] = {
    {"class", _slotValue_HTML_changed0},   {"name", _slotValue_HTML_changed1},
    {"script", _slotValue_HTML_changed2},  {"BGColor", _slotValue_HTML_changed3},
    {"BDColor", _slotValue_HTML_changed4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_cmd0[] = "field";
static char _slotValue_HTML_cmd1[] = "HTML_txtAnchor";
static char _slotValue_HTML_cmd2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
/*		send(parent(), 'A', get(\"label\"));\n\
*/\n\
		return 0;\n\
	break;\n\
	case \"data\":\n\
		return get(\"label\");\n\
	break;\n\
	case \"ref\":\n\
		return ref;\n\
	break;\n\
	case \"setRef\":\n\
		ref = arg[1];\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_cmd[] = {
    {"class", _slotValue_HTML_cmd0},
    {"name", _slotValue_HTML_cmd1},
    {"script", _slotValue_HTML_cmd2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_col20[] = "field";
static char _slotValue_HTML_col21[] = "HTML_col2";
static char _slotValue_HTML_col22[] = "\n\
	switch (arg[0]) {\n\
	case \"F\": /* flush */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = SGMLBuildDoc_span();\n\
\n\
			xx = get(\"width\") / 2;\n\
			col = _col % 2;\n\
			indent = col * xx;\n\
\n\
			txtH = send(txtObj, \"make\", self(), \n\
				compressSpaces(get(\"label\")),\n\
				indent, xx, h, 0);\n\
			if (col == 1) {\n\
				set(\"height\", h + txtH);\n\
			} else {\n\
				set(\"height\", h);\n\
				return -1;\n\
			}\n\
		}\n\
		return get(\"height\");\n\
	break;\n\
	case \"D\":\n\
		h = send(self(), 'R', get(\"y\"), get(\"width\"));\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'L':\n\
		return \"D\";\n\
	break;\n\
	case \"col\":\n\
		_col++; /* for listSep to query, to know its place */\n\
		return (_col - 1) % 2;		/*XXX dude, implement++ */\n\
	break;\n\
	case \"colEnd\":\n\
		return 1;\n\
	break;\n\
	case \"inPreP\":\n\
		return 0; /* little point account for PRE here */\n\
	break;\n\
	case \"itemWidth\":\n\
		return get(\"width\") / 2;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"DIR\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		set(\"x\", style[2]);\n\
\n\
		_col = 0;\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\") / 2;\n\
			for (i = 0; i < n;) {\n\
				col = i % 2;\n\
				indent = col * xx;\n\
				h = send(nthChild(i), 'R', vspan, xx, indent);\n\
				i++;\n\
				if ((col == 1) || (i == n)) vspan += h;\n\
			}\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
/*		SGMLBuildDoc_setBuff(-1);*/\n\
		return get(\"label\");\n\
	break;\n\
	case \"compact\":\n\
		return 1;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagIDCount > 0)\n\
			for (i = 0; i < tagIDCount; i++)\n\
				if (tagIDs[i] == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagIDCount > 0)\n\
			for (i = 0; i < tagIDCount; i++)\n\
				if (tagIDs[i] == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_col23[] = "100";
static char _slotValue_HTML_col24[] = "2";
/* END OF FILE */

static SlotStruct objDesc_HTML_col2[] = {
    {"class", _slotValue_HTML_col20},  {"name", _slotValue_HTML_col21},
    {"script", _slotValue_HTML_col22}, {"width", _slotValue_HTML_col23},
    {"height", _slotValue_HTML_col24}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_col30[] = "field";
static char _slotValue_HTML_col31[] = "HTML_col3";
static char _slotValue_HTML_col32[] = "\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		set(\"y\", arg[1] * heightRatio);\n\
		return;\n\
	break;\n\
	case \"F\": /* flush */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_li == 0)\n\
				style_li = SGMLGetStyle(\"HTML\", \"LI\");\n\
			txtObj = HTML_listSep(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = SGMLBuildDoc_span();\n\
\n\
			xx = get(\"width\") / 3;\n\
			col = _col % 3;\n\
			indent = col * xx;\n\
\n\
			txtH = send(txtObj, \"make\", self(), \n\
				get(\"label\"), indent, xx, h);\n\
			if (col == 2) {\n\
				set(\"height\", h + txtH);\n\
			} else {\n\
				set(\"height\", h);\n\
				return -1;\n\
			}\n\
		}\n\
		return get(\"height\");\n\
	break;\n\
	case \"D\": /* done */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_li == 0) \n\
				style_li = SGMLGetStyle(\"HTML\", \"LI\");\n\
			txtObj = HTML_listSep(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = SGMLBuildDoc_span();\n\
\n\
			xx = get(\"width\") / 3;\n\
			col = _col % 3;\n\
			indent = col * xx;\n\
\n\
			txtH = send(txtObj, \"make\", self(), \n\
				get(\"label\"), indent, xx, h);\n\
			if (col == 2) {\n\
				set(\"height\", h + txtH);\n\
			} else {\n\
				set(\"height\", h + txtH); /* the end */\n\
			}\n\
		}\n\
		return get(\"height\");\n\
	break;\n\
	case 'L':\n\
		return \"D\";\n\
	break;\n\
	case \"inPreP\":\n\
		return 0; /* little point account for PRE here */\n\
	break;\n\
	case \"col\":\n\
		_col++; /* for listSep to query, to know its place */\n\
		return (_col - 1) % 3;		/*XXX dude, implement++ */\n\
	break;\n\
	case \"colEnd\":\n\
		return 2;\n\
	break;\n\
	case \"itemWidth\":\n\
		return get(\"width\") / 3;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"COL3\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		set(\"x\", style[2]);\n\
\n\
		_col = 0;\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\") / 3;\n\
			for (i = 0; i < n;) {\n\
				col = i % 3;\n\
				indent = col * xx;\n\
				h = send(nthChild(i), 'R', vspan, xx, indent);\n\
				i++;\n\
				if ((col == 2) || (i == n)) vspan += h;\n\
			}\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
/*		SGMLBuildDoc_setBuff(-1);*/\n\
		return get(\"label\");\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (get(\"content2\") == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (get(\"content2\") == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_col33[] = "100";
static char _slotValue_HTML_col34[] = "2";
/* END OF FILE */

static SlotStruct objDesc_HTML_col3[] = {
    {"class", _slotValue_HTML_col30},  {"name", _slotValue_HTML_col31},
    {"script", _slotValue_HTML_col32}, {"width", _slotValue_HTML_col33},
    {"height", _slotValue_HTML_col34}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_col40[] = "field";
static char _slotValue_HTML_col41[] = "HTML_col4";
static char _slotValue_HTML_col42[] = "\n\
	switch (arg[0]) {\n\
	case \"shownPositionV\":\n\
		set(\"y\", arg[1] * heightRatio);\n\
		return;\n\
	break;\n\
	case \"F\": /* flush */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
\n\
			if (style_li) style_li = SGMLGetStyle(\"HTML\", \"LI\");\n\
			txtObj = HTML_listSep(\"clone\", self());\n\
			objectListAppend_children(txtObj);\n\
			h = SGMLBuildDoc_span();\n\
\n\
			xx = get(\"width\") / 4;\n\
			col = n % 4;\n\
			indent = col * xx;\n\
\n\
			txtH = send(txtObj, \"make\", self(), \n\
				get(\"label\"), indent, xx, h);\n\
			if (col == 3) {\n\
				set(\"height\", h + txtH);\n\
			} else {\n\
				set(\"height\", h);\n\
				return -1;\n\
			}\n\
		}\n\
		return get(\"height\");\n\
	break;\n\
	case \"D\": /* done */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
\n\
			if (style_li) style_li = SGMLGetStyle(\"HTML\", \"LI\");\n\
			txtObj = HTML_listSep(\"clone\", self());\n\
			objectListAppend_children(txtObj);\n\
			h = SGMLBuildDoc_span();\n\
\n\
			xx = get(\"width\") / 4;\n\
			col = n % 4;\n\
			indent = col * xx;\n\
\n\
			txtH = send(txtObj, \"make\", self(), \n\
				get(\"label\"), indent, xx, h);\n\
			if (col == 3) {\n\
				set(\"height\", h + txtH);\n\
			} else {\n\
				set(\"height\", h + txtH); /* the end */\n\
			}\n\
		}\n\
		return get(\"height\");\n\
	break;\n\
	case 'L':\n\
		return \"D\";\n\
	break;\n\
	case \"col\":\n\
		_col = _col + 1; /* for listSep to query, to know its place */\n\
		return (_col - 1) % 4;		/*XXX dude, implement++ */\n\
	break;\n\
	case \"colEnd\":\n\
		return 3;\n\
	break;\n\
	case \"itemWidth\":\n\
		return get(\"width\") / 4;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"COL4\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		set(\"x\", style[2]);\n\
\n\
		_col = 0;\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\") / 4;\n\
			for (i = 0; i < n;) {\n\
				col = i % 4;\n\
				indent = col * xx;\n\
				h = send(nthChild(i), 'R', vspan, xx, indent);\n\
				i++;\n\
				if ((col == 3) || (i == n)) vspan += h;\n\
			}\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
/*		SGMLBuildDoc_setBuff(-1);*/\n\
		return get(\"label\");\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (get(\"content2\") == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (get(\"content2\") == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_col43[] = "100";
static char _slotValue_HTML_col44[] = "2";
/* END OF FILE */

static SlotStruct objDesc_HTML_col4[] = {
    {"class", _slotValue_HTML_col40},  {"name", _slotValue_HTML_col41},
    {"script", _slotValue_HTML_col42}, {"width", _slotValue_HTML_col43},
    {"height", _slotValue_HTML_col44}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_defList0[] = "field";
static char _slotValue_HTML_defList1[] = "HTML_defList";
static char _slotValue_HTML_defList2[] = "\n\
	switch (arg[0]) {\n\
	case \"head\":\n\
	case \"body\":\n\
		toMake = arg[0];\n\
		txtObj = arg[1];\n\
		return;\n\
	break;\n\
	case \"F\": /* flush */\n\
		return send(self(), 'm', \"F\");\n\
	break;\n\
	case \"D\": /* done */\n\
		return send(self(), 'm', \"D\");\n\
	break;\n\
	case \"m\": /* make */\n\
		if (arg[1] == \"D\") SGMLBuildDoc_setBuff(0);\n\
		else SGMLBuildDoc_setBuff(-1);/*???*/\n\
		t = compressSpaces(get(\"label\"));\n\
		if (isBlank(t) == 1) {\n\
			if (arg[1] == \"F\") {\n\
				return 1;\n\
			} else if (arg[1] == \"D\") {\n\
				return get(\"height\");\n\
			} else {\n\
				return 1;\n\
			}\n\
		}\n\
\n\
		switch (toMake) {\n\
		default:/* in case the DefList doesn't start with either\n\
			 * <DT> or <DD>\n\
			 */\n\
		case \"head\":\n\
			if (styleDT == 0) styleDT = SGMLGetStyle(\"HTML\", \"DT\");\n\
			y = get(\"height\");\n\
			txtH = send(txtObj, \"make\", self(), \n\
				t, styleDT[2], \n\
				get(\"width\") - styleDT[3] - styleDT[2], y);\n\
		break;\n\
		case \"body\":\n\
			if (styleDD == 0) styleDD = SGMLGetStyle(\"HTML\", \"DD\");\n\
			y = get(\"height\");\n\
			txtH = send(txtObj, \"make\", self(), \n\
				t, styleDD[2], \n\
				get(\"width\") - styleDD[3] - styleDD[2], y);\n\
		break;\n\
		}\n\
		if (arg[1] == \"F\") h = set(\"height\", txtH);\n\
		else if (arg[1] == \"D\") h = set(\"height\", y + txtH);\n\
		else h = set(\"height\", txtH);\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"DL\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
		/* In case there is <P> in DefList */\n\
		return send(self(), \"m\", \"D\");\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"AI\":\n\
	case \"inAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_defList3[] = "3";
/* END OF FILE */

static SlotStruct objDesc_HTML_defList[] = {
    {"class", _slotValue_HTML_defList0},
    {"name", _slotValue_HTML_defList1},
    {"script", _slotValue_HTML_defList2},
    {"height", _slotValue_HTML_defList3},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_defListBody0[] = "field";
static char _slotValue_HTML_defListBody1[] = "HTML_defListBody";
static char _slotValue_HTML_defListBody2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		send(parent(), \"body\");\n\
		return \"\";\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_defListBody[] = {
    {"class", _slotValue_HTML_defListBody0},
    {"name", _slotValue_HTML_defListBody1},
    {"script", _slotValue_HTML_defListBody2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_defListBody_p0[] = "txtDisp";
static char _slotValue_HTML_defListBody_p1[] = "HTML_defListBody_p";
static char _slotValue_HTML_defListBody_p2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"D\":\n\
		send(parent(), \"body\", self());\n\
		/* just return something, and fill in data later. \n\
		 * But must be big enough (>2) so that textfield widget\n\
		 * won't wine at the height being too small and not\n\
		 * allow for formatting when the data comes.\n\
		 */\n\
		return 1;\n\
	break;\n\
	case 'R': /* resize */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"DD\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()+2) + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	data\n\
		 * arg[3]	x\n\
		 * arg[4]	width\n\
		 * arg[5]	y\n\
		 */\n\
		set(\"x\", arg[3]);\n\
		set(\"y\", arg[5]);\n\
		set(\"width\", arg[4]);\n\
		set(\"height\", 8);/* big enough to allow text to be put in */\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", arg[2]);\n\
		h = building_vspan();\n\
		set(\"height\", h);\n\
		set(\"maxHeight\", h);\n\
		h += 4;\n\
		return h;\n\
	break;\n\
	case \"config\":\n\
	case \"gotoAnchor\":\n\
	case \"buttonRelease\":\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_defListBody_p3[] = "10";
static char _slotValue_HTML_defListBody_p4[] = "normal";
static char _slotValue_HTML_defListBody_p5[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_defListBody_p[] = {
    {"class", _slotValue_HTML_defListBody_p0},
    {"name", _slotValue_HTML_defListBody_p1},
    {"script", _slotValue_HTML_defListBody_p2},
    {"height", _slotValue_HTML_defListBody_p3},
    {"font", _slotValue_HTML_defListBody_p4},
    {"format", _slotValue_HTML_defListBody_p5},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_defListHead0[] = "field";
static char _slotValue_HTML_defListHead1[] = "HTML_defListHead";
static char _slotValue_HTML_defListHead2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		send(parent(), \"head\");\n\
		return \"\";\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_defListHead[] = {
    {"class", _slotValue_HTML_defListHead0},
    {"name", _slotValue_HTML_defListHead1},
    {"script", _slotValue_HTML_defListHead2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_defListHead_p0[] = "txtDisp";
static char _slotValue_HTML_defListHead_p1[] = "HTML_defListHead_p";
static char _slotValue_HTML_defListHead_p2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"D\":\n\
		send(parent(), \"head\", self());\n\
		return 1;\n\
	break;\n\
	case 'R': /* resize */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"DT\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()+2) + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	data\n\
		 * arg[3]	x\n\
		 * arg[4]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"DT\");\n\
		vspan = style[0];\n\
		set(\"x\", arg[3]);\n\
		set(\"y\", arg[5]);\n\
		set(\"width\", arg[4]);\n\
		set(\"height\", 8);/* big enough to allow text to be put in */\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", arg[2]);\n\
		h = building_vspan();\n\
		set(\"height\", h+2);\n\
		set(\"maxHeight\", h);\n\
		h += vspan + style[1];\n\
		return h;\n\
	break;\n\
	case \"config\":\n\
	case \"gotoAnchor\":\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
\n\
	case \"buttonRelease\":\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_defListHead_p3[] = "normal";
static char _slotValue_HTML_defListHead_p4[] = "LemonChiffon1";
static char _slotValue_HTML_defListHead_p5[] = "LemonChiffon1";
static char _slotValue_HTML_defListHead_p6[] = "black";
static char _slotValue_HTML_defListHead_p7[] = "red";
static char _slotValue_HTML_defListHead_p8[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_defListHead_p[] = {
    {"class", _slotValue_HTML_defListHead_p0},   {"name", _slotValue_HTML_defListHead_p1},
    {"script", _slotValue_HTML_defListHead_p2},  {"font", _slotValue_HTML_defListHead_p3},
    {"BGColor", _slotValue_HTML_defListHead_p4}, {"BDColor", _slotValue_HTML_defListHead_p5},
    {"FGColor", _slotValue_HTML_defListHead_p6}, {"CRColor", _slotValue_HTML_defListHead_p7},
    {"format", _slotValue_HTML_defListHead_p8},  {(char*)0, (char*)0},
};

static char _slotValue_HTML_example0[] = "txtDisp";
static char _slotValue_HTML_example1[] = "HTML_example";
static char _slotValue_HTML_example2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		return expose(arg[1], arg[2], arg[3], arg[4]);\n\
	break;\n\
	case \"D\": /* done */\n\
		inPreP = send(parent(), \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		set(\"content\", get(\"label\"));\n\
		return (building_vspan() + 2);\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		style = SGMLGetStyle(\"HTML\", \"XMP\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		set(\"content\", trimEdgeQ(get(\"content\")));/*bug*/\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<XMP>\", get(\"content\"), \"</XMP>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_example3[] = "100";
static char _slotValue_HTML_example4[] = "30";
static char _slotValue_HTML_example5[] = "fixed";
static char _slotValue_HTML_example6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_example[] = {
    {"class", _slotValue_HTML_example0},    {"name", _slotValue_HTML_example1},
    {"script", _slotValue_HTML_example2},   {"width", _slotValue_HTML_example3},
    {"height", _slotValue_HTML_example4},   {"font", _slotValue_HTML_example5},
    {"verbatim", _slotValue_HTML_example6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_fail0[] = "txtDisp";
static char _slotValue_HTML_fail1[] = "HTML_fail";
static char _slotValue_HTML_fail2[] = "\n\
	/* Failure notice.\n\
	 * This object is used to display insertions that failed. \n\
	 * See HTML_vobjf.v for usage example.\n\
	 */\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		/* arg[2]	width\n\
		 * arg[3]	message\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[2]);\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", arg[3]);\n\
		set(\"height\", building_vspan());\n\
		return (building_vspan() + 2);\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		set(\"y\", arg[1]);\n\
		set(\"x\", 0);\n\
		set(\"width\", arg[2] - get(\"x\"));\n\
		set(\"content\", get(\"content\"));\n\
		vspan = set(\"height\", building_vspan());\n\
		render();\n\
		return get(\"height\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_fail3[] = "100";
static char _slotValue_HTML_fail4[] = "30";
static char _slotValue_HTML_fail5[] = "fixed";
static char _slotValue_HTML_fail6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_fail[] = {
    {"class", _slotValue_HTML_fail0},  {"name", _slotValue_HTML_fail1},
    {"script", _slotValue_HTML_fail2}, {"width", _slotValue_HTML_fail3},
    {"height", _slotValue_HTML_fail4}, {"font", _slotValue_HTML_fail5},
    {"format", _slotValue_HTML_fail6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_figa0[] = "field";
static char _slotValue_HTML_figa1[] = "HTML_figa";
static char _slotValue_HTML_figa2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		send(parent(), \"addFigA\", ref,\n\
			int(nthWord(area, 1)), int(nthWord(area, 2)),\n\
			int(nthWord(area, 3)), int(nthWord(area, 4)));\n\
		return -1;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"AREA\":\n\
			area = arg[2];\n\
		break;\n\
		case \"HREF\":\n\
			ref = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"AI\":\n\
		return 0;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_figa[] = {
    {"class", _slotValue_HTML_figa0},
    {"name", _slotValue_HTML_figa1},
    {"script", _slotValue_HTML_figa2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figa_actual0[] = "glass";
static char _slotValue_HTML_figa_actual1[] = "HTML_figa_actual";
static char _slotValue_HTML_figa_actual2[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		set(\"parent\", arg[1]);\n\
		ref = arg[2];\n\
		bx = arg[3];\n\
		by = arg[4];\n\
		bw = arg[5];\n\
		bh = arg[6];\n\
\n\
		set(\"x\", bx);\n\
		set(\"y\", by);\n\
		set(\"width\", bw);\n\
		set(\"height\", bh);\n\
/*\n\
		print(\"FIGA_ACTUAL: ref=\", ref, \"\\n\
\");\n\
		print(\"FIGA_ACTUAL: x=\", bx, \"\\n\
\");\n\
		print(\"FIGA_ACTUAL: y=\", by, \"\\n\
\");\n\
		print(\"FIGA_ACTUAL: w=\", bw, \"\\n\
\");\n\
		print(\"FIGA_ACTUAL: h=\", bh, \"\\n\
\");\n\
*/\n\
		/* document building routine turned them off by default,\n\
		 * for efficiency, but here we want to use it for hints.\n\
		 */\n\
		eventMask(\"+enterWindow +leaveWindow\");\n\
		return -1;\n\
	break;\n\
	case \"enter\":\n\
		send(parent(), \"invertBox\", bx, by, bx + bw, by + bh);\n\
		top = send(parent(), \"findTop\");\n\
		return send(top, \"hintOn\", \n\
			    concat(\"Entered hot spot for: \", ref));\n\
	break;\n\
	case \"leave\":\n\
		send(parent(), \"invertBox\", bx, by, bx + bw, by + bh);\n\
		return send(top, \"hintOff\");\n\
	break;\n\
	case \"buttonRelease\":\n\
		return send(top, \"follow_href\", ref);\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_figa_actual[] = {
    {"class", _slotValue_HTML_figa_actual0},
    {"name", _slotValue_HTML_figa_actual1},
    {"script", _slotValue_HTML_figa_actual2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figcap0[] = "txtDisp";
static char _slotValue_HTML_figcap1[] = "HTML_figcap";
static char _slotValue_HTML_figcap2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		inPreP = send(parent(), \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", get(\"label\"));\n\
		return (building_vspan() + 2);\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"FIGCAP\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"FIGCAP\");\n\
		vspan = style[0];\n\
		set(\"width\", get(\"width\") - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_figcap3[] = "100";
static char _slotValue_HTML_figcap4[] = "30";
static char _slotValue_HTML_figcap5[] = "normal";
static char _slotValue_HTML_figcap6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_figcap[] = {
    {"class", _slotValue_HTML_figcap0},  {"name", _slotValue_HTML_figcap1},
    {"script", _slotValue_HTML_figcap2}, {"width", _slotValue_HTML_figcap3},
    {"height", _slotValue_HTML_figcap4}, {"font", _slotValue_HTML_figcap5},
    {"format", _slotValue_HTML_figcap6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_figdata0[] = "field";
static char _slotValue_HTML_figdata1[] = "HTML_figdata";
static char _slotValue_HTML_figdata2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return 1;\n\
	break;\n\
	case 'i':\n\
		return get(\"label\");\n\
	break;\n\
	case \"gotoAnchor\":\n\
	case \"AI\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_figdata[] = {
    {"class", _slotValue_HTML_figdata0},
    {"name", _slotValue_HTML_figdata1},
    {"script", _slotValue_HTML_figdata2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figure0[] = "field";
static char _slotValue_HTML_figure1[] = "HTML_figure";
static char _slotValue_HTML_figure2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		return -1;\n\
	break;\n\
	case \"D\":\n\
/*		if (tagPtr == 0) tagPtr = STG_tagPtr(\"FIGURE\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		if (builtFig == 1) {\n\
			h = SGMLBuildDoc_span() + style[1];\n\
			set(\"height\", h);\n\
			builtFig = 0;\n\
			return h;\n\
		} else if (src != 0) {\n\
			builtFig = 1;\n\
\n\
			h = get(\"height\");\n\
\n\
			switch (bmType) {\n\
			case \"gif\":\n\
			case \"image/gif\":\n\
				figTemplate = \"HTML_giff\";\n\
			break;\n\
			case \"xbm\":\n\
			case \"image/xbm\":\n\
				figTemplate = \"HTML_xbmf\";\n\
			break;\n\
			case \"xpm\":\n\
			case \"image/xpm\":\n\
				figTemplate = \"HTML_xpmf\";\n\
			break;\n\
			case \"ps\":\n\
			case \"application/postscript\":\n\
				figTemplate = \"HTML_psf\";\n\
			break;\n\
			}\n\
			if (isBlank(figTemplate) == 1) {\n\
				/* unknown type */\n\
				return 0;\n\
			} else {\n\
				bitmapObj = send(figTemplate, \"clone\");\n\
				w = width() - 10;\n\
				h += send(bitmapObj, \"make\", self(), w, h,\n\
					 src, delayP, delayWidth, delayHeight,\n\
					 ismap);\n\
\n\
				objectListPrepend(\"children\", bitmapObj);\n\
\n\
				/* oh heck */\n\
				h = send(self(), 'R', get(\"y\"), get(\"width\"));\n\
				for (i = 0; i < figaCount; i++) {\n\
					send(bitmapObj, \"addFigA\", figaRef[i],\n\
						figaX[i], figaY[i],\n\
						figaW[i], figaH[i]);\n\
				}\n\
				if (style == 0)\n\
					style = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\
				return style[0] + h;\n\
			}\n\
		} else {\n\
			if (isBlank(get(\"label\")) == 1) return -1;\n\
\n\
			builtFig = 1;\n\
			h = SGMLBuildDoc_span();\n\
\n\
			switch (bmType) {\n\
			case \"gif\":\n\
			case \"image/gif\":\n\
			case \"image/GIF\":\n\
				figTemplate = \"HTML_gif\";\n\
			break;\n\
			case \"xbm\":\n\
			case \"image/xbm\":\n\
				figTemplate = \"HTML_xbm\";\n\
			break;\n\
			case \"xpm\":\n\
			case \"image/xpm\":\n\
				figTemplate = \"HTML_xpm\";\n\
			break;\n\
/*			case \"ps\":\n\
			case \"application/postscript\":\n\
				figTemplate = \"HTML_ps\";\n\
			break;\n\
*/\n\
			default:\n\
		print(\"HTML_figure.v: don't know what FIGURE TYPE is.\\n\
\");\n\
			break;\n\
			}\n\
\n\
			if (isBlank(figTemplate) == 1) {\n\
				/* unknown type */\n\
				return 0;\n\
			} else {\n\
				bitmapObj = send(figTemplate, \"clone\");\n\
				w = width() - 10;\n\
				h += send(bitmapObj, \"make\", self(), w, h,\n\
					 get(\"label\"), ismap);\n\
				objectListPrepend(\"children\", bitmapObj);\n\
\n\
				/* oh heck */\n\
				h = send(self(), 'R', get(\"y\"), get(\"width\"));\n\
\n\
				for (i = 0; i < figaCount; i++) {\n\
					send(bitmapObj, \"addFigA\", figaRef[i],\n\
						figaX[i], figaY[i],\n\
						figaW[i], figaH[i]);\n\
				}\n\
				if (style == 0)\n\
					style = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\
				return style[0] + h + style[1];\n\
			}\n\
		}\n\
	break;\n\
	case 'R': /* resize */\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	x (optional)\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
/*		SGMLBuildDoc_setBuff(-1);*/\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"AI\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"TYPE\":\n\
			bmType = arg[2];\n\
		break;\n\
		case \"ISMAP\":\n\
			ismap = 1;\n\
		break;\n\
		case \"SRC\":\n\
			src = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		case \"WIDTH\":\n\
			delayWidth = arg[2];\n\
		break;\n\
		case \"HEIGHT\":\n\
			delayHeight = arg[2];\n\
		break;\n\
		case \"MAYDELAY\":\n\
			delayP = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"addFigA\":\n\
		figaRef[figaCount] = arg[1];\n\
		figaX[figaCount] = arg[2];\n\
		figaY[figaCount] = arg[3];\n\
		figaW[figaCount] = arg[4];\n\
		figaH[figaCount] = arg[5];\n\
		++figaCount;\n\
		return;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(clone());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_figure3[] = "100";
static char _slotValue_HTML_figure4[] = "2";
/* END OF FILE */

static SlotStruct objDesc_HTML_figure[] = {
    {"class", _slotValue_HTML_figure0},  {"name", _slotValue_HTML_figure1},
    {"script", _slotValue_HTML_figure2}, {"width", _slotValue_HTML_figure3},
    {"height", _slotValue_HTML_figure4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_fld0[] = "field";
static char _slotValue_HTML_fld1[] = "HTML_fld";
static char _slotValue_HTML_fld2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		if (label) drawText(35, 1, 1, label);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"inAnchor\":\n\
	case \"compact\":\n\
	case \"L\":\n\
		return 0;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"D\":\n\
		set(\"content2\", self());/*a kludge to deal with cloning*/\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);/* necessary ...*/\n\
		send(self(), \"setStyles\");\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (canFold && folded) {\n\
			/* make the first list item go away,\n\
			 * to show the toggler */\n\
			send(nthChild(1), \"R\", 30, get(\"width\"));\n\
			send(nthChild(0), \"setFolded\", 1);\n\
			set(\"height\", 20);\n\
			return 20;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		if (foldInfo == 0) {\n\
			send(self(), \"reInit\");\n\
			if (label) drawText(35, 1, 1, label);\n\
		}\n\
\n\
		if (canFold) vspan += 18;\n\
		if (canFold == 0 || folded == 0) {\n\
			n = countChildren();\n\
			if (n > canFold) {\n\
				xx = get(\"width\");\n\
				for (i = canFold; i < n; i++)\n\
				  vspan += send(nthChild(i), \"R\", vspan, xx);\n\
			}\n\
		}\n\
\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"folded\":\n\
		if (foldInfo == 0) send(self(), \"reInit\");\n\
		folded = arg[1];\n\
		send(send(parent(), \"findTop\"), \"resizeSelf\");\n\
		return;\n\
	break;\n\
	case \"toggleFolded\":\n\
		if (foldInfo == 0) send(self(), \"reInit\");\n\
		if (folded) folded = 0;\n\
		else folded = 1;\n\
		send(send(parent(), \"findTop\"), \"resizeSelf\");\n\
		return folded;\n\
	break;\n\
	case \"folded?\":\n\
		return folded;\n\
	break;\n\
	case \"canFold?\":\n\
		return canFold;\n\
	break;\n\
	case \"label?\":\n\
		return label;\n\
	break;\n\
	case \"setAnchor\":\n\
		makeAnchor = arg[1];\n\
		return;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"editMode\":\n\
		editMode = arg[1];\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			for (i = canFold; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"editMode\", editMode);\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		case \"LABEL\":\n\
			label = arg[2];\n\
		break;\n\
		case \"FOLD\":\n\
			canFold = 1;\n\
			if (arg[2] == \"yes\" || arg[2] == \"YES\") folded = 1;\n\
			set(\"BDColor\", get(\"FGColor\"));\n\
			new = send(\"HTML__foldIcon\", \"make\", self());\n\
			set(\"children\", new);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			for (i = canFold; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			for (i = canFold; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"placeID\":\n\
		/* this is clumsy. should be simplified with a primitive f() */\n\
		/* find the caller (child) object's place in the obj list */\n\
		cobj = arg[1];\n\
		objPlace = -1;\n\
\n\
		for (i = objectListCount_children() - 1; i >= 0; i--) {\n\
			nobj = nthChild(i);/*bug: can't inline into == XXX*/\n\
			if (cobj == nobj) {\n\
				objPlace = i;\n\
			}\n\
		}\n\
		objPlacePath = concat(objPlace, \" \", arg[2]);\n\
		return send(parent(), \"placeID\", self(), objPlacePath);\n\
	break;\n\
	case \"edit_gotoPrev\":\n\
		cobj = arg[1];\n\
		objPlace = -1;\n\
		for (i = objectListCount_children() - 1; i >= 0; i--) {\n\
			nobj = nthChild(i);/*bug: can't inline into == XXX*/\n\
			if (cobj == nobj) {\n\
				objPlace = i;\n\
			}\n\
		}\n\
		send(nthChild(objPlace-1), \"edit_focus\");\n\
		return;\n\
	break;\n\
	case \"edit_gotoNext\":\n\
		cobj = arg[1];\n\
		objPlace = -1;\n\
\n\
		for (i = objectListCount_children() - 1; i >= 0; i--) {\n\
			nobj = nthChild(i);/*bug: can't inline into == XXX*/\n\
			if (cobj == nobj) {\n\
				objPlace = i;\n\
			}\n\
		}\n\
/*\n\
	if no next child, ask parent to goto next (then down to\n\
	suitable editable element)...\n\
print(\"CCCCCCCCCC objPlace=\", objPlace, \"\\n\
\");\n\
print(\"CCCCCCCCCC o(objPlace)=\", nthChild(objPlace), \"\\n\
\");\n\
print(\"CCCCCCCCCC o(objPlace+1)=\", nthChild(objPlace+1), \"\\n\
\");\n\
*/\n\
\n\
		send(nthChild(objPlace+1), \"edit_focus\");\n\
		return;\n\
	break;\n\
	case \"CE_change\":\n\
		return send(nthChild(nthWord(arg[1], 1)), arg[0],\n\
				nthWord(arg[1], 2, 99), arg[2]);\n\
	break;\n\
	case \"CE_lock\":\n\
	case \"CE_unlock\":\n\
		return send(nthChild(nthWord(arg[1], 1)), arg[0],\n\
				nthWord(arg[1], 2, 99));\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<SECTION>\\n\
\");\n\
		n = countChildren();\n\
		if (n) for (i = 0; i < n; i++)\n\
				send(nthChild(i), \"outputSGML\");\n\
		print(\"</SECTION>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"setStyles\":\n\
		tagPtr = STG_tagPtr(\"SECTION\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
			i = STG_attr(tagPtr, \"border\");\n\
			if (i) {\n\
				set(\"border\", 6);\n\
				set(\"BDColor\", get(\"FGColor\"));/*XXX*/\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"reInit\":\n\
		/*HIGH KLUDGE-- to know if clone has occured*/\n\
		foldInfo = 1;\n\
		o = object(get(\"content2\"));\n\
		if (o) {\n\
			canFold = send(o, \"canFold?\");\n\
			folded = send(o, \"folded?\");\n\
			label = send(o, \"label?\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		foldInfo = 1;\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_fld[] = {
    {"class", _slotValue_HTML_fld0},
    {"name", _slotValue_HTML_fld1},
    {"script", _slotValue_HTML_fld2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_footnote0[] = "HTML_footnote";
static char _slotValue_HTML_footnote1[] = "field";
static char _slotValue_HTML_footnote2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		new = send(\"HTML_footnote.ft\", \"clone\");\n\
		send(new, \"make\", get(\"label\"));\n\
		t = concat(\"\\\\o(\", new, \")\");\n\
		return t;\n\
	break;\n\
	case \"AI\":\n\
	case \"AA\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_HTML_footnote4[] = "HTML_footnote.ft";
static char _slotValue_HTML_footnote5[] = "XBM";
static char _slotValue_HTML_footnote6[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonPress\":\n\
		set(\"BDColor\", \"red\");\n\
	break;\n\
	case \"buttonRelease\":\n\
		res.dialogWithButtons(\"show\", get(\"content\"), \"OK\", \"\");\n\
		set(\"BDColor\", \"LemonChiffon1\");\n\
	break;\n\
	case \"make\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<FOOTNOTE>\", get(\"content\"), \"</FOOTNOTE>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		color = getResource(\"Viola.borderColor_doc\");\n\
		if (color) set(\"BDColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_footnote7[] = "\n\
#define ft_width 10\n\
#define ft_height 10\n\
static char ft_bits[] = {\n\
   0x1f, 0x00, 0x29, 0x00, 0x6f, 0x00, 0x89, 0x00, 0xff, 0x00, 0x81, 0x00,\n\
   0xff, 0x00, 0x81, 0x00, 0xff, 0x00, 0x00, 0x00};\n\
";
static char _slotValue_HTML_footnote8[] = "9";
static char _slotValue_HTML_footnote9[] = "9";
/* END OF FILE */

static SlotStruct objDesc_HTML_footnote[] = {
    {"name", _slotValue_HTML_footnote0},
    {"class", _slotValue_HTML_footnote1},
    {"script", _slotValue_HTML_footnote2},
    {(char*)0, (char*)1},
    {"name", _slotValue_HTML_footnote4},
    {"class", _slotValue_HTML_footnote5},
    {"script", _slotValue_HTML_footnote6},
    {"label", _slotValue_HTML_footnote7},
    {"width", _slotValue_HTML_footnote8},
    {"height", _slotValue_HTML_footnote9},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_form0[] = "field";
static char _slotValue_HTML_form1[] = "HTML_form";
static char _slotValue_HTML_form2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		h = 0;\n\
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			if (inPreP) txt = get(\"label\");\n\
			else txt = compressSpaces(get(\"label\"));\n\
			h = send(txtObj, \"make\", self(), txt,\n\
				 style[3], \n\
				 get(\"width\") - style[3] - style[2],\n\
				 SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			if (inPreP) txt = get(\"label\");\n\
			else txt = compressSpaces(get(\"label\"));\n\
			h += send(txtObj, \"make\", self(), txt,\n\
				 style[3], \n\
				 get(\"width\") - style[3] - style[2],\n\
				 h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
/*\n\
		tagPtr = STG_tagPtr(\"FORM\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
/*		new = send(\"HTML_form.op\", \"clone\", self());\n\
		hh = send(new, \"make\", self(), get(\"width\") - 4, h);\n\
		objectListAppend_children(new);\n\
		set(\"height\", h + hh);\n\
		return h + hh;\n\
*/\n\
		return h;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\") - 4;\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			id = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"METHOD\":\n\
			method = arg[2];\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		case \"ACTION\":\n\
			action = arg[2];\n\
		break;\n\
		case \"BORDER\":\n\
			set(\"BDColor\", get(\"FGColor\"));\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"regInputer\":\n\
		/* every input object within the form reports to the form,\n\
		 * so that at submission time, the form can query the input\n\
		 * objects for values.\n\
		 */\n\
		inputers[icount] = arg[1];\n\
/*		val = send(inputers[icount], \"value\");*/\n\
		icount++;\n\
		return icount - 1;\n\
	break;\n\
	case \"resetForm\":\n\
		for (i = 0; i < icount; i++) send(inputers[i], \"reset\");\n\
		return;\n\
	break;\n\
	case \"acceptForm\":\n\
		if (action != \"\") {\n\
			if (findPattern(action, \"mailto:\") != -1) {\n\
				/* EMail results\n\
				 */\n\
				url = subject = send(send(parent(),\n\
							\"findTop\"),\n\
							 \"query_docURL\");\n\
				subject = url;\n\
				address = nthChar(action, 7, 999);\n\
				content = concat(\"Form URL : \", url, \"\\n\
\\n\
\",\n\
						 \"Action   : \", action, \"\\n\
\");\n\
\n\
				for (i = 0; i < icount; i++) {\n\
					val = send(inputers[i], \"value\");\n\
					if (val != 0) \n\
					  content = concat(mh, '\\n\
', \n\
							   content, \n\
							   val, '\\n\
');\n\
				}\n\
				\n\
				tmpFile = makeTempFile();\n\
				saveFile(tmpFile, content);\n\
\n\
				wwwSecurity(\"mailFileContentTo,rmFile\",\n\
					    address, subject, tmpFile);\n\
			} else {\n\
				/* Compress results into one-liner. Ick!\n\
				 */\n\
				content = \"\";\n\
				for (i = 0; i < icount; i++) {\n\
					val = send(inputers[i], \"value\");\n\
/*print(\"FORM VALUE >>>>>>>\", val, \"<<<\\n\
\");*/\n\
					if (val != 0)\n\
					  if(i == 0) {\n\
						content = concat(content, \n\
						                 val);\n\
					  } else {\n\
						content = concat(content,\n\
								 '&', val);\n\
					  }\n\
				}\n\
				content = concat(content, \"\\n\
\");\n\
\n\
				if (method == \"POST\") {\n\
/*print(\"FORM POST HREF N DATA >>>>>>>\", concat(action, '?', content), \"<<<\\n\
\");\n\
*/\n\
					send(send(parent(), \"findTop\"), \n\
						\"post_href_n_data\",\n\
						action, content);\n\
				} else {\n\
/*print(\"FORM FOLLOW HREF >>>>>>>\", concat(action, '?', content), \"<<<\\n\
\");*/\n\
					send(send(parent(), \"findTop\"), \n\
						\"follow_href\", \n\
						concat(action, '?', content));\n\
				}\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"findForm\":\n\
		return self();\n\
	break;\n\
	case \"reportMailHeader\":\n\
		mh = arg[1];\n\
		return;\n\
	break;\n\
	case \"radioReg\":\n\
		/* arg[1]	name of radio group\n\
		 * arg[2]	radio (input) object to be added to group\n\
		 */\n\
		radioID[radioi] = arg[1];\n\
		radioObj[radioi] = arg[2];\n\
		radioi++;\n\
		return;\n\
	break;\n\
	case \"radioOnReq\":\n\
		/* arg[1]	radio group index\n\
		 * arg[2]	the radio (input) object to be turned ON\n\
		 */\n\
		radioGroupName = arg[1];\n\
		for (i = 0; i < radioi; i++)\n\
			if (radioID[i] == radioGroupName)\n\
				send(radioObj[i], \"radioOff\");\n\
		send(arg[2], \"radioOn\");\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<FORM\");\n\
		if (id) print(\" ID=\\\"\", id, \"\\\"\");\n\
		if (action) print(\" ACTION=\\\"\", action, \"\\\"\");\n\
		if (method) print(\" METHOD=\\\"\", method, \"\\\"\");\n\
		if (get(\"maxWidth\") < 9999) \n\
				print(\" MAXWIDTH=\", get(\"maxWidth\"));\n\
		if (get(\"minWidth\") < 9999) \n\
				print(\" MINWIDTH=\", get(\"minWidth\"));\n\
		print(\">\\n\
\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++)\n\
				send(nthChild(i), \"outputSGML\");\n\
		}\n\
		print(\"</FORM>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_form[] = {
    {"class", _slotValue_HTML_form0},
    {"name", _slotValue_HTML_form1},
    {"script", _slotValue_HTML_form2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_gif0[] = "GIF";
static char _slotValue_HTML_gif1[] = "HTML_gif";
static char _slotValue_HTML_gif2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		localFile = HTTPGet(get(\"label\"));\n\
		top = send(parent(), \"findTop\");\n\
		url = send(top, \"query_docURL\");\n\
\n\
		/* to get the gif in its natural dimension (lame) */\n\
		set(\"width\", 0);\n\
		set(\"height\", 0);\n\
\n\
		set(\"label\", localFile, url);\n\
		system(concat(\"rm -f \", localFile));\n\
\n\
		return get(\"height\");\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"IMG\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"label\", get(\"label\"), url);\n\
		vspan += get(\"height\") + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"buttonPress\":\n\
		xy = mouseLocal();\n\
		x0 = xy[0];\n\
		y0 = xy[1];\n\
		set(\"FGColor\", \"black\");\n\
		drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\
		drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\
		set(\"FGColor\", \"white\");\n\
		drawLine(x0, y0 - 5, x0, y0 + 5);\n\
		drawLine(x0 + 5, y0, x0 - 5, y0);\n\
	break;\n\
	case \"buttonRelease\":\n\
		xy = mouseLocal();\n\
		x1 = xy[0];\n\
		y1 = xy[1];\n\
		ref = concat(url, \"?\", x0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\
\n\
		set(\"FGColor\", \"black\");\n\
		drawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\
		drawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\
		set(\"FGColor\", \"white\");\n\
		drawLine(x1, y1 - 5, x1, y1 + 5);\n\
		drawLine(x1 + 5, y1, x1 - 5, y1);\n\
		send(top, \"follow_href\", ref);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_gif3[] = "100";
static char _slotValue_HTML_gif4[] = "100";
/* END OF FILE */

static SlotStruct objDesc_HTML_gif[] = {
    {"class", _slotValue_HTML_gif0},  {"name", _slotValue_HTML_gif1},
    {"script", _slotValue_HTML_gif2}, {"width", _slotValue_HTML_gif3},
    {"height", _slotValue_HTML_gif4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_giff0[] = "GIF";
static char _slotValue_HTML_giff1[] = "HTML_giff";
static char _slotValue_HTML_giff2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		set(\"y\", arg[1]);\n\
		style = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\
		vspan = style[0] + get(\"height\") + style[1];\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	w\n\
		 * arg[3]	y\n\
		 * arg[4]	docURL\n\
		 * arg[5]	delayP\n\
		 * arg[6]	delayWidth\n\
		 * arg[7]	delayHeight\n\
		 * arg[8]	ismap\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[2]);\n\
		set(\"y\", arg[3]);\n\
		ismap = arg[8];\n\
\n\
		urlParts = HTTPCurrentDocAddrParsed(arg[4]);\n\
		imgURL = concat(urlParts[0], \"://\", urlParts[1], \n\
				urlParts[2], urlParts[3]);\n\
\n\
		/* to get the gif in its natural dimension */\n\
		set(\"width\", 0);\n\
		set(\"height\", 0);\n\
\n\
		set(\"label\", imgURL, imgURL);\n\
		system(concat(\"rm -f \", localFile));\n\
\n\
		return get(\"height\");\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"addFigA\":\n\
		new = send(\"HTML_figa_actual\", \"clone\");\n\
		send(new, \"make\", self(), \n\
			arg[1], arg[2], arg[3], arg[4], arg[5]);\n\
		objectListAppend(\"children\", new);\n\
		return;\n\
	break;\n\
	case \"hintOn\":\n\
		return send(parent(), \"hintOn\", arg[1]);\n\
	break;\n\
	case \"hintOff\":\n\
		return send(parent(), \"hintOff\");\n\
	break;\n\
	case \"buttonPress\":\n\
		if (ismap) {\n\
			xy = mouseLocal();\n\
			x0 = xy[0];\n\
			y0 = xy[1];\n\
			set(\"FGColor\", \"black\");\n\
			drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\
			drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\
			set(\"FGColor\", \"white\");\n\
			drawLine(x0, y0 - 5, x0, y0 + 5);\n\
			drawLine(x0 + 5, y0, x0 - 5, y0);\n\
		}\n\
	break;\n\
	case \"buttonRelease\":\n\
		if (ismap) {\n\
			xy = mouseLocal();\n\
			x1 = xy[0];\n\
			y1 = xy[1];\n\
			if (top == 0) top = send(parent(), \"findTop\");\n\
			ref = concat(send(top, \"query_docURL\"), \"?\",\n\
					x0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\
			set(\"FGColor\", \"black\");\n\
			drawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\
			drawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\
			set(\"FGColor\", \"white\");\n\
			drawLine(x1, y1 - 5, x1, y1 + 5);\n\
			drawLine(x1 + 5, y1, x1 - 5, y1);\n\
			send(top, \"follow_href\", ref);\n\
		}\n\
	break;\n\
	case \"invertBox\":\n\
		invertRect(arg[1], arg[2], arg[3], arg[4]);\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_giff3[] = "100";
static char _slotValue_HTML_giff4[] = "100";
/* END OF FILE */

static SlotStruct objDesc_HTML_giff[] = {
    {"class", _slotValue_HTML_giff0},  {"name", _slotValue_HTML_giff1},
    {"script", _slotValue_HTML_giff2}, {"width", _slotValue_HTML_giff3},
    {"height", _slotValue_HTML_giff4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_head0[] = "field";
static char _slotValue_HTML_head1[] = "HTML_head";
static char _slotValue_HTML_head2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
	case \"F\":\n\
		return -1;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return get(\"label\");\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"HEAD\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = width();\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\": /* useless? */\n\
			tagID = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"inPreP\":\n\
	case \"inAnchor\":/*XXX*/\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_head[] = {
    {"class", _slotValue_HTML_head0},
    {"name", _slotValue_HTML_head1},
    {"script", _slotValue_HTML_head2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_header_big0[] = "txtDisp";
static char _slotValue_HTML_header_big1[] = "HTML_header_big";
static char _slotValue_HTML_header_big2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		return expose();\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"H1\");\n\
		vspan = style[0];\n\
		set(\"width\", width() - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		clearWindow();\n\
		render();/*may be extraneous */\n\
		vspan += set(\"height\", building_vspan()+2) + style[1];\n\
		return vspan;\n\
	break;\n\
	case \"inAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"setAnchor\":\n\
		tagID = arg[1];\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		if (tagIDCount > 0)\n\
			for (i = 0; i < tagIDCount; i++)\n\
				if (tagIDs[i] == arg[1]) return get(\"y\");\n\
		return 0;\n\
	break;\n\
	case \"D\": /* done */\n\
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\
		if (isBlank(get(\"label\"))) return 0;\n\
\n\
		send(self(), \"setStyles\");	/* stylesheet stuff */\n\
\n\
		url = send(parent(), \"inAnchor\");\n\
\n\
		inPreP = send(parent(), \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		if (url) {\n\
			t = concat(\" \\\\b(\", trimEdgeQ(get(\"label\")),\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
		} else {\n\
			t = trimEdgeQ(get(\"label\"));\n\
		}\n\
		set(\"content\", t);\n\
		set(\"label\", \"\");\n\
		return building_vspan()+2;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<H1\");\n\
		if (tagID) print(\" NAME=\\\"\", tagID, \"\\\">\");\n\
		else print(\">\");\n\
		print(get(\"content\"), \"</H1>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"ALIGN\":\n\
			switch (arg[2]) {\n\
			case \"center\":\n\
				set(\"paneConfig\", \"center\");\n\
			break;\n\
			case \"left\":\n\
				set(\"paneConfig\", \"westToEast\");\n\
			break;\n\
			case \"right\":\n\
				set(\"paneConfig\", \"eastToWest\");\n\
			break;\n\
			}\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"setStyles\":\n\
		useTagInfo_align = 1;\n\
		tagPtr = STG_tagPtr(\"H1\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
			i = STG_attr(tagPtr, \"fontSlant\");\n\
			if (i) {\n\
				switch (i) {\n\
				case \"italic\": 	set(\"font\", i);	break;\n\
				case \"bold\": 	set(\"font\", i);	break;\n\
				default:\n\
				case \"normal\":	set(\"font\", i);	break;\n\
				}\n\
			}\n\
			i = STG_attr(tagPtr, \"align\");\n\
			if (i) {\n\
				useTagInfo_align = 0;\n\
				switch (i) {\n\
				case \"center\":\n\
					set(\"paneConfig\", \"center\");\n\
				break;\n\
				case \"left\":\n\
					set(\"paneConfig\", \"westToEast\");\n\
				break;\n\
				case \"right\":\n\
					set(\"paneConfig\", \"eastToWest\");\n\
				break;\n\
				}\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		return code_HTML_txt(arg);\n\
	break;\n\
\n\
	case \"runAwayFromHome\":\n\
		return send(parent(), \"deleteChild\", self());\n\
	break;\n\
	case \"buttonPress\":\n\
		if (editMode) {\n\
		  if (mxy[0] < 3 && mxy[1] < 3) {\n\
			print(\"HTML_txt: GRAB\\n\
\");\n\
			if (top == 0) top = send(parent(), \"findTop\");\n\
			send(top, \"wedgeMeIn\", self());\n\
			return;\n\
		  } else {\n\
			if (top == 0) top = send(parent(), \"findTop\");\n\
			plid = send(parent(), \"placeID\", self(), \"\");\n\
			send(top, \"lock\", self(), plid);\n\
			if (lock == 1) {\n\
				/* unlock */\n\
				set(\"BDColor\", get(\"BGColor\"));\n\
				set(\"cursor\", 0);\n\
				lock = 0;\n\
				return;\n\
			} else {\n\
				/* lock */\n\
				set(\"BDColor\", \"red\");\n\
				set(\"cursor\", 1);\n\
				lock = 1;\n\
			}\n\
		  }\n\
		}\n\
	break;\n\
	case \"edit_focus\":\n\
		wxy = windowPosition();\n\
		setMouse(wxy[0] + 2, wxy[1] + 2);\n\
		return;\n\
	break;\n\
	case \"keyPress\":\n\
		if (editMode) {\n\
			c = key();\n\
			if (c == '\\r') {\n\
				insert(key());\n\
				set(\"content\", get(\"content\"));\n\
				h = building_vspan();\n\
				print(\"BUILDING_VSPAN=\", h, \"\\n\
\");\n\
				set(\"height\", h);\n\
				if (top == 0) top = send(parent(), \"findTop\");\n\
				send(top, \"resizeSelf\");\n\
				plid = send(parent(), \"placeID\", self(), \"\");\n\
\n\
				newTxt = get(\"content\");\n\
				set(\"content\", newTxt);\n\
\n\
				send(top, \"change\", self(), plid, newTxt);\n\
			} else if (c == '\	') {\n\
				if (shiftKeyP()) {\n\
					send(parent(), \"edit_gotoPrev\", \n\
						self());\n\
				} else {\n\
					send(parent(), \"edit_gotoNext\", \n\
						self());\n\
				}\n\
				/*\n\
				send(parent(),\n\
					either (shiftKeyP())\n\
						{\"edit_gotoPrev\"}\n\
						{\"edit_gotoNext\"},\n\
					self());\n\
				*/\n\
			} else {\n\
				insert(key());\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"CE_change\":\n\
		newData = arg[2];\n\
		set(\"content\", newData);\n\
		h = building_vspan();\n\
		print(\"RE_BUILDING_VSPAN=\", h, \"\\n\
\");\n\
		set(\"height\", h);\n\
		if (top == 0) top = send(parent(), \"findTop\");\n\
		send(top, \"resizeSelf\");\n\
		return;\n\
	break;\n\
	case \"CE_lock\":\n\
		if (lock == 0) {\n\
			set(\"BDColor\", \"yellow\");\n\
		}\n\
		return;		\n\
	break;\n\
	case \"CE_unlock\":\n\
		if (lock == 0) {\n\
			set(\"BDColor\", get(\"BGColor\"));\n\
		}\n\
		return;		\n\
	break;\n\
	case \"enter\":\n\
/*		if (editMode && lock) {\n\
			set(\"cursor\", 1);\n\
		}\n\
*/\n\
		if (editMode) {\n\
			set(\"cursor\", 1);\n\
		}\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
/*		if (editMode && lock) {*/\n\
		if (editMode) {\n\
			set(\"cursor\", 0);\n\
/*\n\
			set(\"BDColor\", get(\"BGColor\"));\n\
			set(\"cursor\", 0);\n\
			if (lock == 1) {\n\
				if (top == 0) top = send(parent(), \"findTop\");\n\
				plid = send(parent(), \"placeID\", self(), \"\");\n\
				send(top, \"unlock\", self(), plid);\n\
				lock = 0;\n\
			}\n\
*/\n\
		} else {\n\
			prevHint = 0;\n\
			www.mesg.tf(\"clear\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"editMode\":\n\
		editMode = arg[1];\n\
		return;\n\
	break;\n\
\n\
	}\n\
	return code_HTML_header_large(arg);\n\
";
static char _slotValue_HTML_header_big3[] = "100";
static char _slotValue_HTML_header_big4[] = "30";
static char _slotValue_HTML_header_big5[] = "bold_largest";
static char _slotValue_HTML_header_big6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_header_big[] = {
    {"class", _slotValue_HTML_header_big0},  {"name", _slotValue_HTML_header_big1},
    {"script", _slotValue_HTML_header_big2}, {"width", _slotValue_HTML_header_big3},
    {"height", _slotValue_HTML_header_big4}, {"font", _slotValue_HTML_header_big5},
    {"format", _slotValue_HTML_header_big6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_header_medium0[] = "txtDisp";
static char _slotValue_HTML_header_medium1[] = "HTML_header_medium";
static char _slotValue_HTML_header_medium2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		expose(arg[1], arg[2], arg[3], arg[4]);\n\
		return;\n\
	break;\n\
	case \"setAnchor\":\n\
		tagID = arg[1];\n\
		return;\n\
	break;\n\
	case \"inAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		if (tagIDCount > 0)\n\
			for (i = 0; i < tagIDCount; i++)\n\
				if (tagIDs[i] == arg[1]) return get(\"y\");\n\
		return 0;\n\
	break;\n\
	case \"D\": /* done */\n\
		if (isBlank(get(\"label\"))) return 0;\n\
		send(self(), \"setStyles\");	/* stylesheet stuff */\n\
		inPreP = send(parent(), \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		set(\"content\", trimEdgeQ(get(\"label\")));\n\
		set(\"label\", \"\");\n\
		return building_vspan()+2;	\n\
	break;\n\
	case \"setStyles\":\n\
		useTagInfo_align = 1;\n\
		tagPtr = STG_tagPtr(\"H2\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
			i = STG_attr(tagPtr, \"fontSlant\");\n\
			if (i) {\n\
				switch (i) {\n\
				case \"italic\": 	set(\"font\", i);	break;\n\
				case \"bold\": 	set(\"font\", i);	break;\n\
				default:\n\
				case \"normal\":	set(\"font\", i);	break;\n\
				}\n\
			}\n\
			i = STG_attr(tagPtr, \"align\");\n\
			if (i) {\n\
				useTagInfo_align = 0;\n\
				switch (i) {\n\
				case \"center\":\n\
					set(\"paneConfig\", \"center\");\n\
				break;\n\
				case \"left\":\n\
					set(\"paneConfig\", \"westToEast\");\n\
				break;\n\
				case \"right\":\n\
					set(\"paneConfig\", \"eastToWest\");\n\
				break;\n\
				}\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<H2\");\n\
		if (tagID) print(\" NAME=\\\"\", tagID, \"\\\"\");\n\
		print(\">\", get(\"content\"), \"</H2>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"ALIGN\":\n\
			switch (arg[2]) {\n\
			case \"center\":\n\
				set(\"paneConfig\", \"center\");\n\
			break;\n\
			case \"left\":\n\
				set(\"paneConfig\", \"westToEast\");\n\
			break;\n\
			case \"right\":\n\
				set(\"paneConfig\", \"eastToWest\");\n\
			break;\n\
			}\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	}\n\
	return code_HTML_header_medium(arg);\n\
";
static char _slotValue_HTML_header_medium3[] = "100";
static char _slotValue_HTML_header_medium4[] = "30";
static char _slotValue_HTML_header_medium5[] = "normal_large";
static char _slotValue_HTML_header_medium6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_header_medium[] = {
    {"class", _slotValue_HTML_header_medium0},  {"name", _slotValue_HTML_header_medium1},
    {"script", _slotValue_HTML_header_medium2}, {"width", _slotValue_HTML_header_medium3},
    {"height", _slotValue_HTML_header_medium4}, {"font", _slotValue_HTML_header_medium5},
    {"format", _slotValue_HTML_header_medium6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_header_small0[] = "txtDisp";
static char _slotValue_HTML_header_small1[] = "HTML_header_small";
static char _slotValue_HTML_header_small2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		return expose();\n\
	break;\n\
	case \"setAnchor\":\n\
		tagID = arg[1];\n\
		return;\n\
	break;\n\
	case \"inAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		if (tagIDCount > 0)\n\
			for (i = 0; i < tagIDCount; i++)\n\
				if (tagIDs[i] == arg[1]) return get(\"y\");\n\
		return 0;\n\
	break;\n\
	case \"D\": /* done */\n\
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\
		if (isBlank(get(\"label\"))) return 0;\n\
		send(self(), \"setStyles\");	/* stylesheet stuff */\n\
		inPreP = send(parent(), \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		set(\"content\", trimEdgeQ(get(\"label\")));\n\
		set(\"label\", \"\");\n\
		return building_vspan()+2;\n\
	break;\n\
	case \"setStyles\":\n\
		useTagInfo_align = 1;\n\
		tagPtr = STG_tagPtr(\"H3\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
			i = STG_attr(tagPtr, \"fontSlant\");\n\
			if (i) {\n\
				switch (i) {\n\
				case \"italic\": 	set(\"font\", i);	break;\n\
				case \"bold\": 	set(\"font\", i);	break;\n\
				default:\n\
				case \"normal\":	set(\"font\", i);	break;\n\
				}\n\
			}\n\
			i = STG_attr(tagPtr, \"align\");\n\
			if (i) {\n\
				useTagInfo_align = 0;\n\
				switch (i) {\n\
				case \"center\":\n\
					set(\"paneConfig\", \"center\");\n\
				break;\n\
				case \"left\":\n\
					set(\"paneConfig\", \"westToEast\");\n\
				break;\n\
				case \"right\":\n\
					set(\"paneConfig\", \"eastToWest\");\n\
				break;\n\
				}\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<H3\");\n\
		if (tagID) print(\" NAME=\\\"\", tagID, \"\\\"\");\n\
		print(\">\", get(\"content\"), \"</H3>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"ALIGN\":\n\
			switch (arg[2]) {\n\
			case \"center\":\n\
				set(\"paneConfig\", \"center\");\n\
			break;\n\
			case \"left\":\n\
				set(\"paneConfig\", \"westToEast\");\n\
			break;\n\
			case \"right\":\n\
				set(\"paneConfig\", \"eastToWest\");\n\
			break;\n\
			}\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	}\n\
	return code_HTML_header_small(arg);\n\
";
static char _slotValue_HTML_header_small3[] = "100";
static char _slotValue_HTML_header_small4[] = "30";
static char _slotValue_HTML_header_small5[] = "bold";
static char _slotValue_HTML_header_small6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_header_small[] = {
    {"class", _slotValue_HTML_header_small0},  {"name", _slotValue_HTML_header_small1},
    {"script", _slotValue_HTML_header_small2}, {"width", _slotValue_HTML_header_small3},
    {"height", _slotValue_HTML_header_small4}, {"font", _slotValue_HTML_header_small5},
    {"format", _slotValue_HTML_header_small6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_hpane0[] = "hpane";
static char _slotValue_HTML_hpane1[] = "HTML_hpane";
static char _slotValue_HTML_hpane2[] = "\n\
	switch (arg[0]) {\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"F\": /* flush */\n\
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			send(txtObj, \"make\", self(), \n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], width() - style_p[3] - style_p[2],\n\
				0, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		return -1;\n\
	break;\n\
	case \"D\":\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], width() - style_p[3] - style_p[2],\n\
				0, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
/*\n\
		tagPtr = STG_tagPtr(\"HPANE\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"HPANE\");\n\
		vspan = style[0];\n\
		config();\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = (get(\"width\") - 10) / 2;\n\
			cy = style[1];\n\
			for (i = 0; i < n; i++) {\n\
				h = send(nthChild(i), 'r');\n\
				if (h > vspan) vspan = h;\n\
			}\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"HPANE\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		config();\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = (get(\"width\") - 10) / 2;\n\
			cy = style[1];\n\
			for (i = 0; i < n; i++) {\n\
				h = send(nthChild(i), \"r\");\n\
				if (h > vspan) vspan = h;\n\
			}\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"r\":\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"HPANE\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_hpane[] = {
    {"class", _slotValue_HTML_hpane0},
    {"name", _slotValue_HTML_hpane1},
    {"script", _slotValue_HTML_hpane2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_hr0[] = "field";
static char _slotValue_HTML_hr1[] = "HTML_hr";
static char _slotValue_HTML_hr2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
	case \"D\":\n\
		return 1;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"HR\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		vspan += get(\"height\") + style[1];\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<HR>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"BGColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_hr3[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_hr[] = {
    {"class", _slotValue_HTML_hr0},  {"name", _slotValue_HTML_hr1}, {"script", _slotValue_HTML_hr2},
    {"height", _slotValue_HTML_hr3}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_ignore0[] = "field";
static char _slotValue_HTML_ignore1[] = "HTML_ignore";
static char _slotValue_HTML_ignore2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		return \"\";\n\
	break;\n\
	case \"AA\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_ignore[] = {
    {"class", _slotValue_HTML_ignore0},
    {"name", _slotValue_HTML_ignore1},
    {"script", _slotValue_HTML_ignore2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_img0[] = "field";
static char _slotValue_HTML_img1[] = "HTML_img";
static char _slotValue_HTML_img2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return 0;\n\
	break;\n\
	case 'i':\n\
		/*local_src = cache_cheat(\"local\", src);*/\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\
\n\
		if (src) {\n\
			if (ismap) {\n\
				new = send(\"HTML__img\", \"clone\");\n\
				if (exist(\"HTML_txtAnchor\"))\n\
				  actionURL = send(\"HTML_txtAnchor\", \"url\");\n\
				else\n\
				  actionURL = 0;\n\
				send(new, \"make\", self(), src, actionURL);\n\
				ret = concat(\"\\\\o(\", new, \")\");\n\
				ismap = 0;\n\
			} else {\n\
				ret = concat(\"\\\\p(\", src, ')');\n\
			}\n\
		} else {\n\
			ret = \"\";\n\
		}\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\
		return ret;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"SRC\":\n\
			rel_url = arg[2];\n\
			urlParts = HTTPCurrentDocAddrParsed(rel_url);\n\
			src = concat(urlParts[0], \"://\", urlParts[1], \n\
				urlParts[2], urlParts[3]);\n\
		break;\n\
		case \"HREF\":\n\
			href = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		case \"ISMAP\":\n\
			ismap = 1;\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"AI\":\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"config\":\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_HTML_img4[] = "GIF";
static char _slotValue_HTML_img5[] = "HTML__img";
static char _slotValue_HTML_img6[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		return expose();\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	img url\n\
		 * arg[3]	action url\n\
		 */\n\
		actionURL = arg[3];\n\
\n\
		set(\"parent\", arg[1]);\n\
\n\
		/* to get the gif in its natural dimension */\n\
		set(\"width\", 0);\n\
		set(\"height\", 0);\n\
\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\
\n\
		urlParts = HTTPCurrentDocAddrParsed(arg[2]);\n\
		imgURL = concat(urlParts[0], \"://\", urlParts[1], \n\
				urlParts[2], urlParts[3]);\n\
\n\
		set(\"label\", imgURL, imgURL);\n\
		set(\"height\", get(\"height\"));\n\
\n\
		send(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\
		return self();\n\
	break;\n\
	case \"buttonPress\":\n\
		xy = mouseLocal();\n\
		x0 = xy[0];\n\
		y0 = xy[1];\n\
		set(\"FGColor\", \"red\");\n\
		drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\
		drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\
		set(\"FGColor\", \"white\");\n\
		drawLine(x0, y0 - 5, x0, y0 + 5);\n\
		drawLine(x0 + 5, y0, x0 - 5, y0);\n\
		if (actionURL != 0) {\n\
			send(\"www\", \"show\", \n\
				concat(actionURL, \"?\", x0, \",\", y0));\n\
		} else {\n\
			if (top == 0) top = send(parent(), \"findTop\");\n\
			ref = concat(send(top, \"query_docURL\"), \"?\",\n\
					x0, \",\", y0);\n\
			send(top, \"follow_href\", ref);\n\
		}\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_img7[] = "3";
static char _slotValue_HTML_img8[] = "100";
static char _slotValue_HTML_img9[] = "100";
/* END OF FILE */

static SlotStruct objDesc_HTML_img[] = {
    {"class", _slotValue_HTML_img0},
    {"name", _slotValue_HTML_img1},
    {"script", _slotValue_HTML_img2},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML_img4},
    {"name", _slotValue_HTML_img5},
    {"script", _slotValue_HTML_img6},
    {"border", _slotValue_HTML_img7},
    {"width", _slotValue_HTML_img8},
    {"height", _slotValue_HTML_img9},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input0[] = "HTML_input";
static char _slotValue_HTML_input1[] = "field";
static char _slotValue_HTML_input2[] = "\n\
/*\n\
print(\"HTML_input: self=\", self(), \"\\n\
\");\n\
for(i=0;i<arg[];i++) print(\"arg[\",i,\"]={\",arg[i],\"}\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		new = send(self(), \"clone\");\n\
		if (defaultRows == 0) defaultRows = 1;\n\
		if (inputObj == 0) inputObj = \"HTML_input_str\";\n\
		if (objWidth == 0) objWidth = 300;\n\
		/* inlined objects don't instantiate clones and have\n\
		 * the clone inserted in the holding object's children list\n\
		 * as usual objects do. So, need to tell parent to adopt\n\
		 * the clone that is created here ... don't work. b/c not\n\
		 * all parents are created then...\n\
		 */\n\
		send(new, \"make\", inputObj, tagID, defaultVal, \n\
			defaultRows, objWidth, objHeight, isRadio, \n\
			checked, disabled, checkWidth, src);\n\
		t = concat(\"\\\\o(\", new, \")\");\n\
\n\
		/* reset defaults */\n\
		tagID = \"\";\n\
		inputObj = \"HTML_input_str\";\n\
		defaultVal = \"\";\n\
		defaultRows = 1;\n\
		objWidth = 0;\n\
		objHeight = 22;\n\
		isRadio = 0;\n\
		checked = 0;\n\
		disabled = 0;\n\
		checkWidth = 0;\n\
		src = 0;\n\
		return t;\n\
	break;\n\
	case \"make\":\n\
		inputObj = arg[1];\n\
		tagID = arg[2];\n\
		defaultVal = arg[3];\n\
		defaultRows = arg[4];\n\
		set(\"width\", arg[5]);\n\
		set(\"height\", arg[6]);\n\
		isRadio = arg[7];\n\
		checked = arg[8];\n\
		disabled = arg[9];\n\
		checkWidth = arg[10];\n\
		src = arg[11];\n\
/*\n\
		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		if (defaultVal == 0) defaultVal = \"\";/* could be a bad idea*/\n\
\n\
		if (checked) defaultVal = 1;\n\
\n\
		if (inputObj == -1) return 0; /* ignore */\n\
		if (inputObj == 0) inputObj = \"HTML_input_str\";\n\
\n\
		/* width should really be fed back from the input widgets\n\
		 */\n\
		if (checkWidth) {\n\
			set(\"width\", textWidth(1, defaultVal) + 10);\n\
		}\n\
\n\
		new = send(inputObj, \"clone\");\n\
		objectListAppend_children(new);\n\
		h = send(new, \"make\", self(), defaultVal,\n\
			get(\"width\") - 2, defaultRows * 22,\n\
			checked, disabled);\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
\n\
		if (inputObj == \"HTML_input_image\")\n\
			set(\"width\", send(new, \"width?\") + 2);\n\
\n\
		if (form == 0) form = send(parent(), \"findForm\");\n\
		if (form == 0) {\n\
			print(\"HTML_input: can't find form. self=\",\n\
				self(), \"\\n\
\");\n\
		} else {\n\
			if (inputObj != \"HTML_input_submit\" &&\n\
			    inputObj != \"HTML_input_reset\")\n\
				send(form, \"regInputer\", self());\n\
		}\n\
		if (isRadio) {\n\
			send(form, \"radioReg\", tagID, self());\n\
		}\n\
		if (checked) {\n\
			send(nthChild(0), \"buttonPress\");\n\
			send(nthChild(0), \"buttonRelease\");\n\
		}\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"INPUT\");\n\
		vspan = style_p[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		ww = arg[2] - get(\"x\") - style_p[3];\n\
		set(\"width\", ww);\n\
		h = send(nthChild(0), \"R\", arg[1], ww - 2);\n\
		return vspan + set(\"height\", h) + style_p[1];\n\
	break;\n\
	case \"r\":\n\
		set(\"width\", get(\"width\") - 10);\n\
		h = send(nthChild(0), \"R\", 0, get(\"width\"));\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"AI\":\n\
		switch (arg[1]) {\n\
		case \"TYPE\":\n\
			inputObj = \"HTML_input_str\";\n\
		break;\n\
		case \"VALUE\":\n\
			defaultVal = \"\";\n\
		break;\n\
		case \"SIZE\":\n\
			defaultRows = 1;\n\
			set(\"height\", 29);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"TYPE\":\n\
			inputType = arg[1];\n\
			switch (arg[2]) {\n\
			case \"int\":\n\
			case \"float\":\n\
				inputObj = \"HTML_input_int\";\n\
				defWidth = 50;\n\
			break;\n\
			case \"percent\":\n\
				inputObj = \"HTML_input_percent\";\n\
				defWidth = 300;\n\
			break;\n\
			case \"boolean\":\n\
			case \"check\":\n\
			case \"checkbox\":\n\
				inputObj = \"HTML_input_check\";\n\
				defWidth = 18;\n\
			break;\n\
			case \"radio\":\n\
				inputObj = \"HTML_input_radio\";\n\
				isRadio = 1;\n\
				defWidth = 18;\n\
			break;\n\
			case \"doodle\":\n\
			case \"scribble\":\n\
				inputObj = \"HTML_input_doodle\";\n\
				isRadio = 1;\n\
				defWidth = 300;\n\
			break;\n\
			case \"text\":/* multiline*/\n\
				inputObj = \"HTML_input_text\";\n\
				defWidth = 300;\n\
			break;\n\
			case \"image\":\n\
				inputObj = \"HTML_input_image\";\n\
			break;\n\
			case \"hidden\":\n\
				inputObj = \"HTML_input_hidden\";\n\
				defWidth = 0;\n\
			break;\n\
			case \"submit\":\n\
				inputObj = \"HTML_input_submit\";\n\
				defaultRows = 2;\n\
				defWidth = 100;\n\
			break;\n\
			case \"reset\":\n\
				inputObj = \"HTML_input_reset\";\n\
				defaultRows = 2;\n\
				defWidth = 100;\n\
			break;\n\
			case \"str\":\n\
			case \"date\":\n\
				inputObj = \"HTML_input_str\";\n\
				defWidth = 300;\n\
			break;\n\
			case \"password\":\n\
				inputObj = \"HTML_input_password\";\n\
				defWidth = 300;\n\
			break;\n\
			case \"audio\":\n\
			default:\n\
				inputObj = \"HTML_input_fail\";\n\
				defWidth = 300;\n\
			break;\n\
			}\n\
			if (objWidth == 0) objWidth = defWidth;\n\
		break;\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"VALUE\":\n\
			defaultVal = arg[2];\n\
		break;\n\
		case \"DISABLED\":\n\
			disabled = 1;\n\
		break;\n\
		case \"ENVVAR\":\n\
			defaultVal = environVar(arg[2]);\n\
		break;\n\
		case \"SRC\":\n\
			src = arg[2];\n\
		break;\n\
		case \"SIZE\":\n\
			i = findPattern(arg[2], ',');\n\
			if (i == -1) {\n\
				size_cols = int(arg[2]);\n\
				/* extra size to allow for scrollbar */\n\
				objWidth = size_cols * textWidth(0, \"n\") + 20;\n\
			} else {\n\
				size_cols = int(nthChar(arg[2], 0, i-1));\n\
				defaultRows = int(nthChar(arg[2], i + 1, 99));\n\
				objWidth = size_cols * textWidth(0, 'n');\n\
				objHeight = defaultRows * 22;\n\
			}\n\
		break;\n\
		case \"CHECKED\":\n\
			checked = 1;\n\
		break;\n\
		case \"MINCHARS\":\n\
			minChars = arg[2];\n\
		break;\n\
		case \"MAXCHARS\":\n\
			maxChars = arg[2];\n\
		break;\n\
		case \"CHARS\":\n\
			maxChars = minChars = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"value\":\n\
		/* push this down another level */\n\
		if (inputObj == \"HTML_input_image\") {\n\
			return send(nthChild(0), \"packValue\", tagID);\n\
		} else if (inputObj == \"HTML_input_radio\") {\n\
			return send(nthChild(0), \"packValue\", tagID);\n\
		} else if (inputObj == \"HTML_input_check\") {\n\
			return send(nthChild(0), \"packValue\", tagID);\n\
		} else {\n\
			return concat(HTTPEncodeURL(tagID), '=',\n\
				HTTPEncodeURL(send(nthChild(0), \"value\")));\n\
		}\n\
	break;\n\
	case \"reset\":\n\
		return send(nthChild(0), \"reset\");\n\
	break;\n\
	case \"radioOnReq\":\n\
		/* tell form that this radio button wants to be ON */\n\
		return send(form, \"radioOnReq\", tagID, self());\n\
	break;\n\
	case \"radioOff\":\n\
		/* form calls back to tell this radio button to be OFF*/\n\
		send(nthChild(0), \"toggleTo\", 0);\n\
		return;\n\
	break;\n\
	case \"radioOn\":\n\
		/* form calls back to say that this radio button can be ON */\n\
		send(nthChild(0), \"toggleTo\", 1);\n\
		return;\n\
	break;\n\
	case \"acceptForm\":\n\
	case \"resetForm\":\n\
		return send(form, arg[0]);\n\
	break;\n\
	case \"minChars?\":\n\
		return minChars;\n\
	break;\n\
	case \"maxChars?\":\n\
		return maxChars;\n\
	break;\n\
	case \"setWidth\":\n\
		/* kludge. this is called by child obj, to ask for \n\
		 * width readjustment */\n\
		set(\"width\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"src?\":\n\
		print(\"input self=\", self(), \"\\n\
\");\n\
		print(\"input src=\", src, \"\\n\
\");\n\
		return src;\n\
	break;\n\
	case \"regInputer\":\n\
		return send(form, arg[0], arg[1]);\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<INPUT\");\n\
		if (tagID) print(\" NAME=\\\"\", tagID, \"\\\"\");\n\
		if (type) print(\" TYPE=\\\"\", inputType, \"\\\"\");\n\
		if (checked) print(\" CHECKED\");\n\
		if (get(\"maxWidth\") < 9999) \n\
			print(\" MAXWIDTH=\", get(\"maxWidth\"));\n\
		if (get(\"minWidth\") < 9999) \n\
			print(\" MINWIDTH=\", get(\"minWidth\"));\n\
		print(\">\\n\
\");\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input3[] = "25";
static char _slotValue_HTML_input4[] = "22";
/* END OF FILE */

static SlotStruct objDesc_HTML_input[] = {
    {"name", _slotValue_HTML_input0},   {"class", _slotValue_HTML_input1},
    {"script", _slotValue_HTML_input2}, {"width", _slotValue_HTML_input3},
    {"height", _slotValue_HTML_input4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_check0[] = "HTML_input_check";
static char _slotValue_HTML_input_check1[] = "toggle";
static char _slotValue_HTML_input_check2[] = "\n\
	switch (arg[0]) {\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		return get(\"height\");\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		set(\"parent\", arg[1]);\n\
		valDefault = arg[2];\n\
		return get(\"height\");\n\
	break;\n\
	case \"buttonPress\":\n\
	case \"buttonRelease\":\n\
		usual();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"packValue\":\n\
		if (get(\"toggleState\")) \n\
			return concat(HTTPEncodeURL(arg[1]), '=',\n\
				HTTPEncodeURL(valDefault));\n\
		return 0;\n\
	break;\n\
	case \"value\":\n\
		return get(\"toggleState\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_check3[] = "3";
static char _slotValue_HTML_input_check4[] = "1";
static char _slotValue_HTML_input_check5[] = "17";
static char _slotValue_HTML_input_check6[] = "17";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_check[] = {
    {"name", _slotValue_HTML_input_check0},   {"class", _slotValue_HTML_input_check1},
    {"script", _slotValue_HTML_input_check2}, {"border", _slotValue_HTML_input_check3},
    {"y", _slotValue_HTML_input_check4},      {"width", _slotValue_HTML_input_check5},
    {"height", _slotValue_HTML_input_check6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_doodle0[] = "HTML_input_doodle";
static char _slotValue_HTML_input_doodle1[] = "";
static char _slotValue_HTML_input_doodle2[] = "vpane";
static char _slotValue_HTML_input_doodle3[] = "HTML_input_doodle.ctrl HTML_input_doodle.canvas";
static char _slotValue_HTML_input_doodle4[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		set(\"width\", arg[2]);\n\
		deepObjectListSend(\"children\", \"configSelf\");\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		set(\"parent\", arg[1]);\n\
		val = arg[2];\n\
		set(\"width\", arg[3]);\n\
		config();\n\
		send(nthChild(1), \"setup\");\n\
		return get(\"height\");\n\
	break;\n\
	case \"value\":\n\
		return send(nthChild(1), \"getVar\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"relay1\":\n\
		return send(nthChild(1), arg[1]);\n\
	break;\n\
	case \"relay2\":\n\
		return send(nthChild(1), arg[1], arg[2]);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola.background_doc\");\n\
		if (color) set(\"BGColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_doodle5[] = "100";
static char _slotValue_HTML_input_doodle6[] = "100";
/* END OF OBJ */

static char _slotValue_HTML_input_doodle8[] = "txtButton";
static char _slotValue_HTML_input_doodle9[] = "HTML_input_doodle.ctrl";
static char _slotValue_HTML_input_doodle10[] = "HTML_input_doodle";
static char _slotValue_HTML_input_doodle11[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(parent(), \"relay1\", \"clear\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_doodle12[] = "Clear pad";
static char _slotValue_HTML_input_doodle13[] = "20";
static char _slotValue_HTML_input_doodle14[] = "100";
static char _slotValue_HTML_input_doodle15[] = "2";
static char _slotValue_HTML_input_doodle16[] = "2";
/* END OF OBJ */

static char _slotValue_HTML_input_doodle18[] = "field";
static char _slotValue_HTML_input_doodle19[] = "HTML_input_doodle.canvas";
static char _slotValue_HTML_input_doodle20[] = "HTML_input_doodle";
static char _slotValue_HTML_input_doodle21[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		if (penDownP) {\n\
			x0 = x1;\n\
			y0 = y1;\n\
			x1 = arg[1];\n\
			y1 = arg[2];\n\
			drawLine(x0, y0, x1, y1);\n\
\n\
			segments[count] = 0;	/* sickie language flaw */\n\
			seg = segments[count];\n\
			seg[0] = x0;\n\
			seg[1] = y0;\n\
			seg[2] = x1;\n\
			seg[3] = y1;\n\
			segments[count] = seg;\n\
\n\
			count++;\n\
			return;\n\
		}\n\
	break;\n\
	case \"buttonPress\":\n\
		penDownP = 1;\n\
		x0 = mouseX();\n\
		y0 = mouseY();\n\
		x1 = x0;\n\
		y1 = y0;\n\
	break;\n\
	case \"buttonRelease\":\n\
		penDownP = 0;\n\
	break;\n\
	case \"clear\":\n\
		count = 0;\n\
		clearWindow();\n\
		return;\n\
	break;\n\
	case \"dump\":\n\
		for (i = 0; i < count; i++) {\n\
			seg = segments[i];\n\
			print(i, \":\", seg[0], \",\", seg[1], \n\
				\" \",  seg[2], \",\", seg[3],\n\
				\"\\n\
\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"getVar\":\n\
		tt = \"\";\n\
		for (i = 0; i < count; i++) {\n\
			seg = segments[i];\n\
			tt = concat(tt, seg[0], \",\", seg[1], \n\
				    \",\",  seg[2], \",\", seg[3],\n\
				    \";\\n\
\");\n\
		}\n\
		return tt;\n\
	break;\n\
	case \"expose\":\n\
		for (i = 0; i < count; i++) {\n\
			seg = segments[i];\n\
			drawLine(seg[0], seg[1], seg[2], seg[3]);\n\
		}\n\
		return;\n\
	break;\n\
	case \"setup\":\n\
		penDownP = 0;\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		penDownP = 0;\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) {\n\
			set(\"BDColor\", color);\n\
			set(\"FGColor\", color);\n\
		}\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_doodle22[] = "2";
static char _slotValue_HTML_input_doodle23[] = "2";
static char _slotValue_HTML_input_doodle24[] = "6";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_doodle[] = {
    {"name", _slotValue_HTML_input_doodle0},      {"parent", _slotValue_HTML_input_doodle1},
    {"class", _slotValue_HTML_input_doodle2},     {"children", _slotValue_HTML_input_doodle3},
    {"script", _slotValue_HTML_input_doodle4},    {"width", _slotValue_HTML_input_doodle5},
    {"height", _slotValue_HTML_input_doodle6},    {(char*)0, (char*)1},
    {"class", _slotValue_HTML_input_doodle8},     {"name", _slotValue_HTML_input_doodle9},
    {"parent", _slotValue_HTML_input_doodle10},   {"script", _slotValue_HTML_input_doodle11},
    {"label", _slotValue_HTML_input_doodle12},    {"maxHeight", _slotValue_HTML_input_doodle13},
    {"maxWidth", _slotValue_HTML_input_doodle14}, {"gapH", _slotValue_HTML_input_doodle15},
    {"gapV", _slotValue_HTML_input_doodle16},     {(char*)0, (char*)1},
    {"class", _slotValue_HTML_input_doodle18},    {"name", _slotValue_HTML_input_doodle19},
    {"parent", _slotValue_HTML_input_doodle20},   {"script", _slotValue_HTML_input_doodle21},
    {"gapH", _slotValue_HTML_input_doodle22},     {"gapV", _slotValue_HTML_input_doodle23},
    {"border", _slotValue_HTML_input_doodle24},   {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_fail0[] = "HTML_input_fail";
static char _slotValue_HTML_input_fail1[] = "txtDisp";
static char _slotValue_HTML_input_fail2[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"width\", arg[2] - 2);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"value\":\n\
		return get(\"content\");\n\
	break;\n\
	case \"reset\":\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_fail3[] = "fixed";
static char _slotValue_HTML_input_fail4[] = "Unknown Input Type";
static char _slotValue_HTML_input_fail5[] = "1";
static char _slotValue_HTML_input_fail6[] = "200";
static char _slotValue_HTML_input_fail7[] = "33";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_fail[] = {
    {"name", _slotValue_HTML_input_fail0},
    {"class", _slotValue_HTML_input_fail1},
    {"script", _slotValue_HTML_input_fail2},
    {"font", _slotValue_HTML_input_fail3},
    {"content", _slotValue_HTML_input_fail4},
    {"verbatim", _slotValue_HTML_input_fail5},
    {"width", _slotValue_HTML_input_fail6},
    {"height", _slotValue_HTML_input_fail7},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_hidden0[] = "HTML_input_hidden";
static char _slotValue_HTML_input_hidden1[] = "generic";
static char _slotValue_HTML_input_hidden2[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		return 0;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		defaultVal = arg[2];\n\
		return 0;\n\
	break;\n\
	case \"value\":\n\
		return defaultVal;\n\
	break;\n\
	case \"reset\":\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_hidden[] = {
    {"name", _slotValue_HTML_input_hidden0},
    {"class", _slotValue_HTML_input_hidden1},
    {"script", _slotValue_HTML_input_hidden2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_hook0[] = "field";
static char _slotValue_HTML_input_hook1[] = "HTML_input_hook";
static char _slotValue_HTML_input_hook2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (tagID) {\n\
			send(parent(), \"setAnchor\", tagID);\n\
			tagID = 0;\n\
		}\n\
		if (url) {\n\
			t = concat(\"\\\\b(\", compressSpaces(get(\"label\")),\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
			url = 0;\n\
			return t;\n\
		} else {\n\
			return compressSpaces(get(\"label\"));\n\
		}\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"HREF\":\n\
			url = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_hook[] = {
    {"class", _slotValue_HTML_input_hook0},
    {"name", _slotValue_HTML_input_hook1},
    {"script", _slotValue_HTML_input_hook2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_image0[] = "HTML_input_image";
static char _slotValue_HTML_input_image1[] = "GIF";
static char _slotValue_HTML_input_image2[] = "\n\
	/* RIGHT NOW LIMITED TO GIF */\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"width\", arg[2] - 2);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		set(\"parent\", arg[1]);\n\
		defaultVal = arg[2];\n\
		set(\"content\", defaultVal);\n\
		set(\"width\", 0);\n\
		set(\"height\", 0);\n\
\n\
		value = \"\";\n\
\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\
		src = send(parent(), \"src?\");\n\
		localFile = HTTPGet(src);\n\
		print(\"input_image src=\", src, \"\\n\
\");\n\
		print(\"input_image localFile=\", localFile, \"\\n\
\");\n\
		set(\"label\", localFile);\n\
		set(\"width\", get(\"width\"));\n\
		set(\"height\", get(\"height\"));\n\
		print(\"input_image height=\", get(\"height\"), \"\\n\
\");\n\
\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\
/*\n\
		send(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\
*/\n\
		return get(\"height\") + 1;\n\
	break;\n\
	case \"buttonPress\":\n\
		xy = mouseLocal();\n\
		x0 = xy[0];\n\
		y0 = xy[1];\n\
		set(\"FGColor\", \"red\");\n\
		drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\
		drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\
		set(\"FGColor\", \"white\");\n\
		drawLine(x0, y0 - 5, x0, y0 + 5);\n\
		drawLine(x0 + 5, y0, x0 - 5, y0);\n\
\n\
		send(parent(), \"acceptForm\");\n\
	break;\n\
	case \"value\":\n\
		return concat(x0, \",\", y0);\n\
	break;\n\
	case \"packValue\":\n\
		id = HTTPEncodeURL(arg[1]);\n\
		return concat(id, \".x=\", HTTPEncodeURL(x0), '&',\n\
				id, \".y=\", HTTPEncodeURL(y0));\n\
	break;\n\
	case \"width?\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"reset\":\n\
		set(\"content\", defaultVal);\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_image3[] = "6";
static char _slotValue_HTML_input_image4[] = "red";
static char _slotValue_HTML_input_image5[] = "100";
static char _slotValue_HTML_input_image6[] = "33";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_image[] = {
    {"name", _slotValue_HTML_input_image0},    {"class", _slotValue_HTML_input_image1},
    {"script", _slotValue_HTML_input_image2},  {"border", _slotValue_HTML_input_image3},
    {"BDColor", _slotValue_HTML_input_image4}, {"width", _slotValue_HTML_input_image5},
    {"height", _slotValue_HTML_input_image6},  {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_int0[] = "HTML_input_int";
static char _slotValue_HTML_input_int1[] = "txtEdit";
static char _slotValue_HTML_input_int2[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		set(\"width\", arg[2]);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*\n\
		tagPtr = STG_tagPtr(\"HPANE\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		set(\"parent\", arg[1]);\n\
		defaultVal = arg[2];\n\
		set(\"content\", defaultVal);\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
/*\n\
		send(parent(), \"regInputer\", self());\n\
		maxChars = send(parent(), \"maxChars?\");\n\
		if (maxChars) checkChars = 1;\n\
		minChars = send(parent(), \"minChars?\");\n\
		if (minChars) checkChars = 1;\n\
*/\n\
		return get(\"height\");\n\
	break;\n\
	case \"keyPress\":\n\
		c = key();\n\
		if (c == '\\r' || c == '\\n\
') {\n\
			if (checkChars) send(self(), \"checkChars\");\n\
			return;\n\
		}\n\
	break;\n\
	case \"leave\":\n\
/*		send(parent(), \"setFormVar\", get(\"content\"));*/\n\
		if (checkChars) send(self(), \"checkChars\");\n\
	break;\n\
	case \"checkChars\":\n\
		length = strlen(get(\"content\"));\n\
		if (minChars > 0) {\n\
			if (length < minChars) {\n\
				send(\"www.mesg.tf\", \"suggest\", \n\
concat(\"Warning, you have entered less digits than suggested\\n\
\"));\n\
			}\n\
		}\n\
		if (maxChars > 0) {\n\
			if (length < maxChars) {\n\
				send(\"www.mesg.tf\", \"suggest\", \n\
		\"Warning, you have entered more digits than suggested\\n\
\");\n\
			}\n\
		}\n\
	break;\n\
	case \"value\":\n\
		return get(\"content\");\n\
	break;\n\
	case \"reset\":\n\
		set(\"content\", defaultVal);\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_int3[] = "fixed";
static char _slotValue_HTML_input_int4[] = "100";
static char _slotValue_HTML_input_int5[] = "17";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_int[] = {
    {"name", _slotValue_HTML_input_int0},
    {"class", _slotValue_HTML_input_int1},
    {"script", _slotValue_HTML_input_int2},
    {"font", _slotValue_HTML_input_int3},
    {"width", _slotValue_HTML_input_int4},
    {"height", _slotValue_HTML_input_int5},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_password0[] = "HTML_input_password";
static char _slotValue_HTML_input_password1[] = "txtEdit";
static char _slotValue_HTML_input_password2[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"width\", arg[2] - 2);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 * ...\n\
		 * arg[7]	disabled\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		if (arg[6]) disabled = 1;\n\
\n\
		set(\"parent\", arg[1]);\n\
		defaultVal = arg[2];\n\
		set(\"content\", defaultVal);\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"enter\":\n\
		if (disabled) return;\n\
	break;\n\
	case \"keyPress\":\n\
		if (disabled) {\n\
			bell();\n\
			send(\"www.mesg.tf\", \"suggest\", \n\
				\"This field has been disabled\\n\
\");\n\
			return;\n\
		} else {\n\
			c = key();\n\
\n\
			if (c >= ' ' &&  c <= '~') {\n\
				passwd[sl] = c;\n\
				sl++;\n\
			} else {\n\
				if (c == '\\r' || c == '\\n\
') {\n\
					return;\n\
				} else if (c == '\\8') {\n\
				  /* 8==Backspace. surely not the way?*/\n\
					if (sl > 0) sl--;\n\
				}\n\
			}\n\
			send(self(), \"setScreen\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"setScreen\":\n\
		if (sl == 0) set(\"content\", \"\");\n\
		else set(\"content\", \n\
			nthChar(\"****************************************\",\n\
				1, sl));\n\
		render();\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		if (checkChars) send(self(), \"checkChars\");\n\
	break;\n\
	case \"value\":\n\
		passwdStr = \"\";\n\
		for (i = 0; i < sl; i++)\n\
			passwdStr = concat(passwdStr, passwd[i]);\n\
		return passwdStr;\n\
	break;\n\
	case \"reset\":\n\
		set(\"content\", defaultVal);\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_password3[] = "fixed";
static char _slotValue_HTML_input_password4[] = "1";
static char _slotValue_HTML_input_password5[] = "100";
static char _slotValue_HTML_input_password6[] = "19";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_password[] = {
    {"name", _slotValue_HTML_input_password0},     {"class", _slotValue_HTML_input_password1},
    {"script", _slotValue_HTML_input_password2},   {"font", _slotValue_HTML_input_password3},
    {"verbatim", _slotValue_HTML_input_password4}, {"width", _slotValue_HTML_input_password5},
    {"height", _slotValue_HTML_input_password6},   {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_percent0[] = "HTML_input_percent";
static char _slotValue_HTML_input_percent1[] = "hpane";
static char _slotValue_HTML_input_percent2[] = "HTML_input_percent.v HTML_input_percent.s";
static char _slotValue_HTML_input_percent3[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		set(\"width\", arg[2]);\n\
		config();\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		set(\"parent\", arg[1]);\n\
		val = arg[2];\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
		config();\n\
		objectListSend(\"children\", \"_setVar\", val);\n\
		return get(\"height\");\n\
	break;\n\
	case \"value\":\n\
		return send(nthChild(1), \"getVar\");\n\
	break;\n\
	case \"setVar.v\":\n\
		val = arg[1];\n\
		send(nthChild(1), \"setVar\", val);\n\
		return;\n\
	break;\n\
	case \"setVar.s\":\n\
		val = arg[1];\n\
		send(nthChild(0), \"setVar\", val);\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_percent4[] = "100";
static char _slotValue_HTML_input_percent5[] = "17";
/* END OF OBJ */

static char _slotValue_HTML_input_percent7[] = "HTML_input_percent";
static char _slotValue_HTML_input_percent8[] = "HTML_input_percent.v";
static char _slotValue_HTML_input_percent9[] = "txtEdit";
static char _slotValue_HTML_input_percent10[] = "HTML_input_percent.s";
static char _slotValue_HTML_input_percent11[] = "\n\
	switch (arg[0]) {\n\
	case \"setVar\":\n\
	case \"shownPositionH\":\n\
		set(\"content\", arg[1]);\n\
		render();\n\
		return;\n\
	break;\n\
	case \"_setVar\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"keyPress\":\n\
		if (key() == '\\r') {\n\
			v = get(\"content\");\n\
			if (v > 100) {\n\
				v = 100;\n\
				set(\"content\", 100);\n\
				render();\n\
			}\n\
			return;\n\
		}\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_percent12[] = "30";
/* END OF OBJ */

static char _slotValue_HTML_input_percent14[] = "slider";
static char _slotValue_HTML_input_percent15[] = "HTML_input_percent";
static char _slotValue_HTML_input_percent16[] = "HTML_input_percent.s";
static char _slotValue_HTML_input_percent17[] = "HTML_input_percent.v";
static char _slotValue_HTML_input_percent18[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	defaultValue\n\
		 */\n\
		set(\"shownPositionH\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"setVar\":\n\
		set(\"shownPositionH\", arg[1]);\n\
		render();\n\
		return;\n\
	break;\n\
	case \"_setVar\":\n\
		set(\"shownPositionH\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"getVar\":\n\
		return get(\"shownPositionH\");\n\
	break;\n\
	case \"buttonRelease\":\n\
		send(parent(), \"setVar.s\", get(\"content\"));\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_percent19[] = "10";
static char _slotValue_HTML_input_percent20[] = "left2right";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_percent[] = {
    {"name", _slotValue_HTML_input_percent0},
    {"class", _slotValue_HTML_input_percent1},
    {"children", _slotValue_HTML_input_percent2},
    {"script", _slotValue_HTML_input_percent3},
    {"width", _slotValue_HTML_input_percent4},
    {"height", _slotValue_HTML_input_percent5},
    {(char*)0, (char*)1},
    {"parent", _slotValue_HTML_input_percent7},
    {"name", _slotValue_HTML_input_percent8},
    {"class", _slotValue_HTML_input_percent9},
    {"shownDepend", _slotValue_HTML_input_percent10},
    {"script", _slotValue_HTML_input_percent11},
    {"maxWidth", _slotValue_HTML_input_percent12},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML_input_percent14},
    {"parent", _slotValue_HTML_input_percent15},
    {"name", _slotValue_HTML_input_percent16},
    {"shownNotify", _slotValue_HTML_input_percent17},
    {"script", _slotValue_HTML_input_percent18},
    {"shownSizeH", _slotValue_HTML_input_percent19},
    {"direction", _slotValue_HTML_input_percent20},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_radio0[] = "HTML_input_radio";
static char _slotValue_HTML_input_radio1[] = "radio";
static char _slotValue_HTML_input_radio2[] = "disc";
static char _slotValue_HTML_input_radio3[] = "\n\
	switch (arg[0]) {\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		return get(\"height\");\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	tagID\n\
		 * arg[2]	valDefault\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 * arg[5]	checked\n\
		 * arg[6]	disabled\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		set(\"parent\", arg[1]);\n\
		valDefault = arg[2];\n\
		checked = arg[5];\n\
		return get(\"height\");\n\
	break;\n\
	case \"buttonRelease\":\n\
		send(parent(), \"radioOnReq\");\n\
		return;\n\
	break;\n\
	case \"packValue\":\n\
		if (get(\"toggleState\")) \n\
			return concat(HTTPEncodeURL(arg[1]), '=',\n\
				HTTPEncodeURL(valDefault));\n\
		return 0;\n\
	break;\n\
	case \"value\":\n\
		return get(\"toggleState\");\n\
	break;\n\
	case \"reset\":\n\
		if (get(\"toggleState\")) {\n\
			if (checked == 0) {\n\
				set(\"toggleState\", 0);\n\
				clearWindow();\n\
				render();\n\
			}\n\
		} else {\n\
			if (checked == 1) {\n\
				set(\"toggleState\", 1);\n\
				clearWindow();\n\
				render();\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola.background_doc\");\n\
		if (color) set(\"BGColor\", color);\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"FGColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_radio4[] = "1";
static char _slotValue_HTML_input_radio5[] = "3";
static char _slotValue_HTML_input_radio6[] = "17";
static char _slotValue_HTML_input_radio7[] = "17";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_radio[] = {
    {"name", _slotValue_HTML_input_radio0},
    {"class", _slotValue_HTML_input_radio1},
    {"toggleStyle", _slotValue_HTML_input_radio2},
    {"script", _slotValue_HTML_input_radio3},
    {"y", _slotValue_HTML_input_radio4},
    {"border", _slotValue_HTML_input_radio5},
    {"width", _slotValue_HTML_input_radio6},
    {"height", _slotValue_HTML_input_radio7},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_reset0[] = "HTML_input_reset";
static char _slotValue_HTML_input_reset1[] = "txtButton";
static char _slotValue_HTML_input_reset2[] = "\n\
	switch (arg[0]) {\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"width\", arg[2] - 2);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		set(\"parent\", arg[1]);\n\
		if (isBlank(arg[2]) == 0) set(\"label\", arg[2]);\n\
		w = textWidth(1, get(\"label\")) + 20;\n\
		set(\"width\", w);\n\
		send(parent(), \"setWidth\", w+2);\n\
		return get(\"height\");\n\
	break;\n\
	case \"buttonRelease\":\n\
		send(parent(), \"resetForm\");\n\
	break;\n\
	case \"reset\":\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_reset3[] = "Reset";
static char _slotValue_HTML_input_reset4[] = "normal";
static char _slotValue_HTML_input_reset5[] = "1";
static char _slotValue_HTML_input_reset6[] = "1";
static char _slotValue_HTML_input_reset7[] = "100";
static char _slotValue_HTML_input_reset8[] = "20";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_reset[] = {
    {"name", _slotValue_HTML_input_reset0},   {"class", _slotValue_HTML_input_reset1},
    {"script", _slotValue_HTML_input_reset2}, {"label", _slotValue_HTML_input_reset3},
    {"font", _slotValue_HTML_input_reset4},   {"verbatim", _slotValue_HTML_input_reset5},
    {"gapV", _slotValue_HTML_input_reset6},   {"width", _slotValue_HTML_input_reset7},
    {"height", _slotValue_HTML_input_reset8}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_str0[] = "HTML_input_str";
static char _slotValue_HTML_input_str1[] = "txtEdit";
static char _slotValue_HTML_input_str2[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"width\", arg[2] - 2);\n\
		return get(\"height\");\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 * arg[5]	checked\n\
		 * arg[6]	disabled\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		if (arg[6]) disabled = 1;\n\
\n\
		set(\"parent\", arg[1]);\n\
		defaultVal = arg[2];\n\
		set(\"content\", defaultVal);\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
		return get(\"height\");\n\
	break;\n\
	case \"enter\":\n\
		if (disabled == 1) return;\n\
	break;\n\
	case \"keyPress\":\n\
		if (disabled == 1) {\n\
			bell();\n\
			send(\"www.mesg.tf\", \"suggest\", \n\
				\"This field has been disabled\\n\
\");\n\
			return;\n\
		} else {\n\
			c = key();\n\
			if (c == '\\r' || c == '\\n\
') {\n\
				if (checkChars) send(self(), \"checkChars\");\n\
				return;\n\
			}\n\
		}\n\
	break;\n\
	case \"checkChars\":\n\
		length = strlen(get(\"content\"));\n\
		if (minChars > 0) {\n\
			if (length < minChars) {\n\
				send(\"www.mesg.tf\", \"suggest\", \n\
	\"Warning, you have entered less characters than suggested\\n\
\");\n\
			}\n\
		}\n\
		if (maxChars > 0) {\n\
			if (length < maxChars) {\n\
				send(\"www.mesg.tf\", \"suggest\", \n\
	\"Warning, you have entered more characters than suggested\\n\
\");\n\
			}\n\
		}\n\
	break;\n\
	case \"leave\":\n\
		if (checkChars) send(self(), \"checkChars\");\n\
	break;\n\
	case \"value\":\n\
		return trimEdge(get(\"content\"));\n\
	break;\n\
	case \"reset\":\n\
		set(\"content\", defaultVal);\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_str3[] = "fixed";
static char _slotValue_HTML_input_str4[] = "100";
static char _slotValue_HTML_input_str5[] = "17";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_str[] = {
    {"name", _slotValue_HTML_input_str0},
    {"class", _slotValue_HTML_input_str1},
    {"script", _slotValue_HTML_input_str2},
    {"font", _slotValue_HTML_input_str3},
    {"width", _slotValue_HTML_input_str4},
    {"height", _slotValue_HTML_input_str5},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_submit0[] = "HTML_input_submit";
static char _slotValue_HTML_input_submit1[] = "txtButton";
static char _slotValue_HTML_input_submit2[] = "\n\
	switch (arg[0]) {\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"width\", arg[2] - 2);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		set(\"parent\", arg[1]);\n\
		if (isBlank(arg[2]) == 0) set(\"label\", arg[2]);\n\
		w = textWidth(1, get(\"label\")) + 20;\n\
		set(\"width\", w);\n\
		send(parent(), \"setWidth\", w+2);\n\
		return get(\"height\");\n\
	break;\n\
	case \"buttonRelease\":\n\
		send(parent(), \"acceptForm\");\n\
	break;\n\
	case \"reset\":\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_submit3[] = "Submit";
static char _slotValue_HTML_input_submit4[] = "normal";
static char _slotValue_HTML_input_submit5[] = "1";
static char _slotValue_HTML_input_submit6[] = "1";
static char _slotValue_HTML_input_submit7[] = "100";
static char _slotValue_HTML_input_submit8[] = "20";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_submit[] = {
    {"name", _slotValue_HTML_input_submit0},   {"class", _slotValue_HTML_input_submit1},
    {"script", _slotValue_HTML_input_submit2}, {"label", _slotValue_HTML_input_submit3},
    {"font", _slotValue_HTML_input_submit4},   {"verbatim", _slotValue_HTML_input_submit5},
    {"gapV", _slotValue_HTML_input_submit6},   {"width", _slotValue_HTML_input_submit7},
    {"height", _slotValue_HTML_input_submit8}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_text0[] = "HTML_input_text";
static char _slotValue_HTML_input_text1[] = "HTML_input_text.tf HTML_input_text.sb";
static char _slotValue_HTML_input_text2[] = "hpane";
static char _slotValue_HTML_input_text3[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"width\", arg[2] - 2);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
		config();\n\
		send(nthChild(0), \"make\", arg[2], arg[6]);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"value\":\n\
	case \"reset\":\n\
		return send(nthChild(0), arg[0], arg[1]);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_HTML_input_text5[] = "HTML_input_text.tf";
static char _slotValue_HTML_input_text6[] = "txtEdit";
static char _slotValue_HTML_input_text7[] = "HTML_input_text.sb";
static char _slotValue_HTML_input_text8[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"width\", arg[2] - 2);\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"enter\":\n\
		if (disabled) return;\n\
	break;\n\
	case \"keyPress\":\n\
		if (disabled) {\n\
			bell();\n\
			send(\"www.mesg.tf\", \"suggest\", \n\
				\"This field has been disabled\\n\
\");\n\
			return;\n\
		}\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	disabled\n\
		 */\n\
/*		tagPtr = STG_tagPtr(\"INPUT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		defaultVal = arg[1];\n\
		set(\"content\", defaultVal);\n\
		if (arg[2]) disabled = 1;\n\
\n\
		return;\n\
	break;\n\
	case \"value\":\n\
		return get(\"content\");\n\
	break;\n\
	case \"reset\":\n\
		set(\"content\", defaultVal);\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_input_text9[] = "fixed";
static char _slotValue_HTML_input_text10[] = "100";
static char _slotValue_HTML_input_text11[] = "33";
/* END OF OBJ */

static char _slotValue_HTML_input_text13[] = "HTML_input_text.sb";
static char _slotValue_HTML_input_text14[] = "slider";
static char _slotValue_HTML_input_text15[] = "15";
static char _slotValue_HTML_input_text16[] = "HTML_input_text.tf";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_text[] = {
    {"name", _slotValue_HTML_input_text0},
    {"children", _slotValue_HTML_input_text1},
    {"class", _slotValue_HTML_input_text2},
    {"script", _slotValue_HTML_input_text3},
    {(char*)0, (char*)1},
    {"name", _slotValue_HTML_input_text5},
    {"class", _slotValue_HTML_input_text6},
    {"shownDepend", _slotValue_HTML_input_text7},
    {"script", _slotValue_HTML_input_text8},
    {"font", _slotValue_HTML_input_text9},
    {"width", _slotValue_HTML_input_text10},
    {"height", _slotValue_HTML_input_text11},
    {(char*)0, (char*)1},
    {"name", _slotValue_HTML_input_text13},
    {"class", _slotValue_HTML_input_text14},
    {"maxWidth", _slotValue_HTML_input_text15},
    {"shownNotify", _slotValue_HTML_input_text16},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_insert0[] = "field";
static char _slotValue_HTML_insert1[] = "HTML_insert";
static char _slotValue_HTML_insert2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
/*RAW		tmpf = HTTPGet(docURL);\n\
		if (tmpf == 0) {\n\
			set(\"content\", \n\
				concat(\"Failed to include \", docURL));\n\
			set(\"BGColor\", \"red\");\n\
			set(\"FGColor\", \"white\");\n\
		} else {\n\
			set(\"content\", loadFile(tmpf));\n\
		}\n\
		h = building_vspan();\n\
		set(\"height\", h);\n\
*/\n\
		eventMask(\"+pointerMotion +leaveWindow +buttonRelease\");\n\
		docURL = send(\"normalizeURL\", \"normalizeURL\", docURL);\n\
		h = 10;\n\
		send(send(parent(), \"findTop\"), \"toDoInsert\", self());\n\
		return h;\n\
	break;\n\
	case \"reinsert\":\n\
		set(\"height\", 0);/*to prevent padding*/\n\
\n\
		oldObj = nthChild(0);\n\
		objectListDelete_children(oldObj);\n\
\n\
		handler = wwwFormatDetect(\"type\", docURL);\n\
		paneObj = self();\n\
		cursorShape(\"busy\");\n\
					/* just to generate unique name */\n\
		docName = concat(self(), makeTempFile());\n\
		docObj = send(\"wwwHandlerDispatch\", \"dispatch\",\n\
				handler, 0 /* no do post */,\n\
				docURL, docName, paneObj,\n\
				get(\"width\"), 9999999,\n\
				anchor, 1, 0 /* no post data */);\n\
		h = send(docObj, \"vspan\");\n\
		set(\"children\", docObj);\n\
		send(docObj, \"visible\", 1);\n\
		set(\"height\", h);\n\
		cursorShape(\"busy\");\n\
		if (prevHeight != h)\n\
			send(send(parent(), \"findTop\"), \"resizeSelf\");\n\
		prevHeight = h;\n\
\n\
		send(oldObj, \"freeSelf\");\n\
		after(reInsertDelay, self(), \"reinsert\");\n\
		return;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"INSERT\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		if (nthChild(0) != 0) {\n\
			vspan += send(nthChild(0), 'R', 0, width() - 4);\n\
			set(\"height\", vspan);\n\
		}\n\
		prevHeight = vspan;\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"HREF\":\n\
			docURL = arg[2];\n\
		break;\n\
		case \"BORDER\":\n\
			set(\"BDColor\", \"black\");\n\
		break;\n\
		case \"ASIS\":\n\
			raw = 1;\n\
		break;\n\
		case \"AFTER\":\n\
			reInsertDelay = int(arg[2]);\n\
			after(reInsertDelay, self(), \"reinsert\");\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"insert\":\n\
		handler = wwwFormatDetect(\"type\", docURL);\n\
		paneObj = self();\n\
					/* just to generate unique name */\n\
		docName = concat(self(), makeTempFile());\n\
		docObj = send(\"wwwHandlerDispatch\", \"dispatch\",\n\
				handler,\n\
				0 /* no do post */,\n\
				docURL,\n\
				docName,\n\
				paneObj,\n\
				get(\"width\"),\n\
				get(\"height\"),\n\
				anchor,\n\
				1, \n\
				0 /* no post data */);\n\
		h = send(nthChild(0), \"vspan\");\n\
		set(\"height\", h);\n\
		return;\n\
	break;\n\
	case \"toDoInsert\":\n\
		/* relay for nested <insert>s */\n\
		send(send(parent(), \"findTop\"), \"toDoInsert\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"setChildren\":\n\
		set(\"children\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_insert3[] = "300";
static char _slotValue_HTML_insert4[] = "100";
/* END OF FILE */

static SlotStruct objDesc_HTML_insert[] = {
    {"class", _slotValue_HTML_insert0},  {"name", _slotValue_HTML_insert1},
    {"script", _slotValue_HTML_insert2}, {"width", _slotValue_HTML_insert3},
    {"height", _slotValue_HTML_insert4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_insertTest0[] = "field";
static char _slotValue_HTML_insertTest1[] = "HTML_insertTest";
static char _slotValue_HTML_insertTest2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		container = HTML_insertee(\"clone\");\n\
		w = width() - 40;\n\
		y = SGMLBuildDoc_span();\n\
		send(container, \"make\", self(), 30, y, w);\n\
		SGMLBuildDoc_insertObj(container, w);\n\
\n\
		return -1;\n\
	break;\n\
	case \"D\":\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style[3], width() - style[3] - style[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = width();\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = width();\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"data\":\n\
/*		SGMLBuildDoc_setBuff(-1);*/\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_insertTest[] = {
    {"class", _slotValue_HTML_insertTest0},
    {"name", _slotValue_HTML_insertTest1},
    {"script", _slotValue_HTML_insertTest2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_insertee0[] = "field";
static char _slotValue_HTML_insertee1[] = "HTML_insertee";
static char _slotValue_HTML_insertee2[] = "\n\
	print(\"@@@@@@ HTML_insertee clsss = field: args: \");\n\
	for (i =0; i < arg[]; i++) print(arg[i], \", \");\n\
	print(\"====================\\n\
\");\n\
	print(\"insertee self=\", self(), \"\\n\
\");\n\
\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
/*print(\"insertee: D height=\", height(), \"\\n\
\");*/\n\
		h = SGMLBuildDoc_span();\n\
		set(\"height\", h);\n\
print(\"insertee: D h=\", h, \"\\n\
\");\n\
		return h;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		vspan = -1;\n\
		set(\"x\", 30);		/*XXX*/\n\
		set(\"y\", arg[1]);\n\
		set(\"width\", arg[2] - x());\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = width();\n\
			for (i = 0; i < n; i++) {\n\
print(\"insertee: child=\", nthChild(i), \"\\n\
\");\n\
print(\"insertee: before vspan=\", vspan, \"\\n\
\");\n\
				vspan = vspan \n\
					+ send(nthChild(i), 'R', vspan, xx);\n\
print(\"insertee: after vspan=\", vspan, \"\\n\
\");\n\
			}\n\
		}\n\
		set(\"height\", vspan);\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	x\n\
		 * arg[3]	y\n\
		 * arg[4]	width\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"x\", arg[2]);\n\
		set(\"y\", arg[3]);\n\
		set(\"width\", arg[4]);\n\
	print(\"insertee height=\", height(), \"\\n\
\");\n\
		return;\n\
	break;\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (id == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (id == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_insertee3[] = "blue";
static char _slotValue_HTML_insertee4[] = "red";
/* END OF FILE */

static SlotStruct objDesc_HTML_insertee[] = {
    {"class", _slotValue_HTML_insertee0},   {"name", _slotValue_HTML_insertee1},
    {"script", _slotValue_HTML_insertee2},  {"BGColor", _slotValue_HTML_insertee3},
    {"BDColor", _slotValue_HTML_insertee4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_isIndex0[] = "hpane";
static char _slotValue_HTML_isIndex1[] = "HTML_isIndex";
static char _slotValue_HTML_isIndex2[] = "HTML_isIndex.label HTML_isIndex.tf";
static char _slotValue_HTML_isIndex3[] = "\n\
	switch (arg[0]) {\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"y\", arg[1]);\n\
		set(\"width\", arg[2] - 2);\n\
		config();\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"D\":\n\
		send(send(parent(), \"findTop\"), \"isIndex\");\n\
		return get(\"height\")+2;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"LABEL\":\n\
			send(nthChild(0), \"setLabel\", arg[2]);\n\
		break;\n\
		case \"VALUE\":\n\
			defaultVal = arg[2];\n\
		break;\n\
		}\n\
	break;\n\
	case \"clone\":\n\
		return clone(arg[1]);\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"search\":\n\
		send(send(parent(), \"findTop\"), \"search\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_isIndex4[] = "3";
static char _slotValue_HTML_isIndex5[] = "2";
static char _slotValue_HTML_isIndex6[] = "2";
static char _slotValue_HTML_isIndex7[] = "250";
static char _slotValue_HTML_isIndex8[] = "23";
/* END OF OBJ */

static char _slotValue_HTML_isIndex10[] = "txtDisp";
static char _slotValue_HTML_isIndex11[] = "HTML_isIndex.label";
static char _slotValue_HTML_isIndex12[] = "HTML_isIndex";
static char _slotValue_HTML_isIndex13[] = "normal";
static char _slotValue_HTML_isIndex14[] = "\n\
	switch (arg[0]) {\n\
	case \"setLabel\":\n\
		set(\"content\", arg[1]);\n\
		set(\"maxWidth\", textWidth(1, argp[1]) + 10);\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_isIndex15[] = "Index entry:";
static char _slotValue_HTML_isIndex16[] = "2";
static char _slotValue_HTML_isIndex17[] = "2";
static char _slotValue_HTML_isIndex18[] = "20";
static char _slotValue_HTML_isIndex19[] = "90";
static char _slotValue_HTML_isIndex20[] = "90";
/* END OF OBJ */

static char _slotValue_HTML_isIndex22[] = "txtEdit";
static char _slotValue_HTML_isIndex23[] = "HTML_isIndex.tf";
static char _slotValue_HTML_isIndex24[] = "HTML_isIndex";
static char _slotValue_HTML_isIndex25[] = "\n\
	switch (arg[0]) {\n\
	case \"keyPress\":\n\
		if (key() == '\\r') {\n\
			send(parent(), \"search\", currentLine());\n\
			return;\n\
		}\n\
	break;\n\
	case \"enter\":\n\
		www.mesg.tf(\"show\", \"An indexing keyword entry field.\");\n\
	break;\n\
	case \"leave\":\n\
		www.mesg.tf(\"clear\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_isIndex26[] = "fixed";
static char _slotValue_HTML_isIndex27[] = "17";
static char _slotValue_HTML_isIndex28[] = "2";
static char _slotValue_HTML_isIndex29[] = "4";
/* END OF FILE */

static SlotStruct objDesc_HTML_isIndex[] = {
    {"class", _slotValue_HTML_isIndex0},
    {"name", _slotValue_HTML_isIndex1},
    {"children", _slotValue_HTML_isIndex2},
    {"script", _slotValue_HTML_isIndex3},
    {"border", _slotValue_HTML_isIndex4},
    {"gapH", _slotValue_HTML_isIndex5},
    {"gapV", _slotValue_HTML_isIndex6},
    {"width", _slotValue_HTML_isIndex7},
    {"height", _slotValue_HTML_isIndex8},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML_isIndex10},
    {"name", _slotValue_HTML_isIndex11},
    {"parent", _slotValue_HTML_isIndex12},
    {"font", _slotValue_HTML_isIndex13},
    {"script", _slotValue_HTML_isIndex14},
    {"content", _slotValue_HTML_isIndex15},
    {"gapH", _slotValue_HTML_isIndex16},
    {"gapV", _slotValue_HTML_isIndex17},
    {"height", _slotValue_HTML_isIndex18},
    {"width", _slotValue_HTML_isIndex19},
    {"maxWidth", _slotValue_HTML_isIndex20},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML_isIndex22},
    {"name", _slotValue_HTML_isIndex23},
    {"parent", _slotValue_HTML_isIndex24},
    {"script", _slotValue_HTML_isIndex25},
    {"font", _slotValue_HTML_isIndex26},
    {"height", _slotValue_HTML_isIndex27},
    {"gapV", _slotValue_HTML_isIndex28},
    {"gapH", _slotValue_HTML_isIndex29},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_ititle0[] = "hpane";
static char _slotValue_HTML_ititle1[] = "HTML_ititle";
static char _slotValue_HTML_ititle2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
/*\n\
		listItemObj = HTML_txtListItem(\"clone\");\n\
		h = send(listItemObj, \"make\", self(), 20, width() - 20);\n\
		set(\"children\", listItemObj);\n\
\n\
		h = send(listItemObj, \"make\", self(), 20, width() - 20);\n\
		print(\"*>>>>>>> h = \", h, \"\\n\
\");\n\
*/		\n\
		return h;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (get(\"content2\") == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (get(\"content2\") == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_ititle3[] = "#define ol_width 16\n\
#define ol_height 16\n\
static char ol_bits[] = {\n\
   0x00, 0x00, 0x00, 0x74, 0x00, 0x7a, 0x00, 0x3d, 0x80, 0x1e, 0x00, 0x0f,\n\
   0xe0, 0x06, 0xf0, 0x01, 0xb0, 0x01, 0xd8, 0x01, 0xe8, 0x00, 0x3c, 0x00,\n\
   0x0c, 0x04, 0x02, 0x03, 0xf8, 0x00, 0x00, 0x00};\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_ititle[] = {
    {"class", _slotValue_HTML_ititle0},
    {"name", _slotValue_HTML_ititle1},
    {"script", _slotValue_HTML_ititle2},
    {"label", _slotValue_HTML_ititle3},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_label0[] = "txtDisp";
static char _slotValue_HTML_label1[] = "HTML_label";
static char _slotValue_HTML_label2[] = "\n\
	switch (arg[0]) {\n\
	case \"T\":\n\
		/* arg[1] = y\n\
		 * arg[2] = width\n\
		 */\n\
		w = get(\"window\");\n\
		set(\"window\", 0);\n\
		set(\"width\", arg[2] - 15);\n\
		if (height() < 3) {\n\
			print(\"height = \", height(), \"\\n\
\");\n\
			set(\"height\", 999);\n\
		}\n\
		set(\"x\", 10);\n\
		set(\"window\", w);\n\
		set(\"content\", get(\"label\"));\n\
		set(\"y\", arg[1]);\n\
		h = building_vspan() + 3;\n\
		set(\"height\", h);\n\
		h += 6;\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		set(\"y\", arg[1]);\n\
		set(\"width\", arg[2]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan = building_vspan();\n\
		set(\"height\", vspan);\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_label3[] = "100";
static char _slotValue_HTML_label4[] = "30";
static char _slotValue_HTML_label5[] = "normal_largest";
static char _slotValue_HTML_label6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_label[] = {
    {"class", _slotValue_HTML_label0},  {"name", _slotValue_HTML_label1},
    {"script", _slotValue_HTML_label2}, {"width", _slotValue_HTML_label3},
    {"height", _slotValue_HTML_label4}, {"font", _slotValue_HTML_label5},
    {"format", _slotValue_HTML_label6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_link0[] = "field";
static char _slotValue_HTML_link1[] = "HTML_link";
static char _slotValue_HTML_link2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		switch (rel) {\n\
		case \"made\":\n\
			send(send(parent(), \"findTop\"), \"reportAuthor\", href);\n\
		break;\n\
		case \"style\":\n\
			STG_clean(0/*useless arg*/);\n\
			localFile = HTTPGet(href);\n\
			loadSTG(localFile);\n\
			oarg = 0;\n\
			oargc = 0;\n\
		break;\n\
		case \"sidebar\":\n\
			/* Rule to be... can't do because of parser bug\n\
			 * if 'maxWidth' is given, that's used.\n\
			 * if not then 'ratio' is used, if it is given.\n\
			barRatio = 0;\n\
			barMaxWidth = 0;\n\
\n\
/**** a parser bug prevents multiple instances of the same attributes!!!\n\
\n\
			flag = 0;\n\
			for (i = 0; i < oargc; i++) {\n\
				if (flag == 0) flag = oarg[i];\n\
				else {\n\
					if (flag == \"maxWidth\") \n\
						barMaxWidth = oarg[i];\n\
					else if (flag == \"ratio\") \n\
						barRatio = oarg[i];\n\
					flag = 0;\n\
				}\n\
			}\n\
*/\n\
			barRatio = oarg[0];\n\
/*\n\
print(\"Bar ratio=\", barRatio, \"\\n\
\");\n\
print(\"Bar maxWidth=\", barMaxWidth, \"\\n\
\");\n\
*/\n\
			send(send(parent(), \"findTop\"), \"linkSideBar\", \n\
				href, barRatio, barMaxWidth);\n\
			oarg = 0;\n\
			oargc = 0;\n\
		break;\n\
		case \"tool\":\n\
			localFile = HTTPGet(href);\n\
			addrInfo = HTTPCurrentDocAddrParsed(localFile);\n\
\n\
			if (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];\n\
			else path = concat('/', addrInfo[2]);\n\
			objFileName = addrInfo[3];\n\
\n\
			addrInfo = HTTPCurrentDocAddrParsed(href);\n\
			objName = nthChar(addrInfo[3], 0, \n\
					strlen(addrInfo[3]) - 3);\n\
			if (exist(objName)) {\n\
				send(send(parent(), \"findTop\"), \"addTool\", \n\
					objName);\n\
				return \"\";\n\
			}\n\
\n\
			stat = loadObjFile(path, objFileName);\n\
\n\
			send(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\
\n\
			if (stat <= 0) {\n\
				print(\"failed to load obj file {\", objFileName,\n\
					\"} in {\", path, \"}\\n\
\");\n\
			}\n\
			securityMode(1); \n\
			send(objName, \"init\"); /* make new object(s) */\n\
			securityMode(0);\n\
\n\
			send(send(parent(), \"findTop\"), \"addTool\", objName,\n\
				oarg, oargc);\n\
			oarg = 0;\n\
			oargc = 0;\n\
		break;\n\
		case \"vobj\":\n\
			localFile = HTTPGet(href);\n\
			addrInfo = HTTPCurrentDocAddrParsed(localFile);\n\
\n\
			if (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];\n\
			else path = concat('/', addrInfo[2]);\n\
			objFileName = addrInfo[3];\n\
\n\
			addrInfo = HTTPCurrentDocAddrParsed(href);\n\
			objName = nthChar(addrInfo[3], 0, \n\
					strlen(addrInfo[3]) - 3);\n\
\n\
			stat = loadObjFile(path, objFileName);\n\
\n\
			send(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\
\n\
			if (stat <= 0) {\n\
				print(\"failed to load obj file {\", objFileName,\n\
					\"} in {\", path, \"}\\n\
\");\n\
			}\n\
			securityMode(1); \n\
			send(objName, \"init\"); /* make new object(s) */\n\
			securityMode(0);\n\
/*\n\
print(\"HTML_LINK load vobj=>>>>>>\", objName, \"<<\\n\
\");\n\
			for(i=0; i<oargc; i++) {\n\
print(\"HTML_LINK oarg[\", i, \"]= >\", oarg[i], \"<\\n\
\");\n\
			}\n\
*/\n\
			if (oarg[] >= 1)\n\
				h = send(objName, \"make\", self(), oarg[0]);\n\
\n\
			after(1, objName, \"configSelf\");\n\
			oarg = 0;\n\
			oargc = 0;\n\
			rel = 0;\n\
			href = 0;\n\
			t = concat(\"\\\\o(\", objName, \")\");\n\
			return t;\n\
		break;\n\
		}\n\
		rel = 0;\n\
		href = 0;\n\
		return \"\";\n\
	break;\n\
	case \"config\":\n\
	case \"R\":\n\
		return 0;\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ARG\":\n\
			oarg[oargc++] = arg[2];\n\
\n\
/*It appears the HTML parser won't handle multiple same attrs.\n\
print(\"HTML_LINK ADDING oarg[\", oargc - 1, \"]= >\", oarg[oargc - 1], \"<\\n\
\");\n\
*/\n\
		break;\n\
		case \"REL\":\n\
			rel = arg[2];\n\
		break;\n\
		case \"HREF\":\n\
			href = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_link[] = {
    {"class", _slotValue_HTML_link0},
    {"name", _slotValue_HTML_link1},
    {"script", _slotValue_HTML_link2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_list0[] = "field";
static char _slotValue_HTML_list1[] = "HTML_list";
static char _slotValue_HTML_list2[] = "\n\
/*XXX Because clone() doesn't copy variables, the foldInfo hassle exists.\n\
 */\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		if (label) drawText(35, 1, 1, label);\n\
		return;\n\
	break;\n\
	case \"D\":\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			/* to deal with idiotic cases like\n\
			 * <UL>foobar</UL>\n\
			 * <UL><UL>foobar</UL></UL>\n\
			 */\n\
			h = 0;\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3],\n\
				get(\"width\") - style_p[3] - 30 - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
			if (h == 0) return 1;\n\
			set(\"height\", h);\n\
			return h;\n\
		}\n\
\n\
		set(\"content2\", self());/*a kludge to deal with cloning*/\n\
		if (canFold) {\n\
			if (folded) {\n\
				/* make the first list item go away,\n\
				 * to show the toggler */\n\
				send(nthChild(1), \"R\", 30, get(\"width\"));\n\
				send(nthChild(0), \"setFolded\", 1);\n\
				return get(\"height\") + 20;\n\
			} else {\n\
				return 20;\n\
			}\n\
		}\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"OL\");\n\
		return get(\"height\") + style[1];\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3],\n\
				get(\"width\") - style_p[3] - 30 - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'L':\n\
		return 'U';\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"UL\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		if (foldInfo == 0) {\n\
			send(self(), \"reInit\");\n\
			if (label) drawText(35, 1, 1, label);\n\
		}\n\
\n\
		if (canFold) vspan += 18;\n\
		if (canFold == 0 || folded == 0) {\n\
			n = countChildren();\n\
			if (n > canFold/*XXX warning: logic/numeral mix*/) {\n\
				xx = get(\"width\");\n\
				for (i = canFold; i < n; i++)\n\
				  vspan += send(nthChild(i), 'R', vspan, xx);\n\
			}\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1] + 7; /*xxx should affect in style */\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"UL\");\n\
		vspan = style[0];\n\
		set(\"width\", get(\"width\") - style[3]);\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			xx = get(\"width\");\n\
			for (i = canFold; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"folded\":\n\
		if (foldInfo == 0) send(self(), \"reInit\");\n\
		folded = arg[1];\n\
		send(send(parent(), \"findTop\"), \"resizeSelf\");\n\
		return;\n\
	break;\n\
	case \"toggleFolded\":\n\
		if (foldInfo == 0) send(self(), \"reInit\");\n\
		if (folded) folded = 0;\n\
		else folded = 1;\n\
		send(send(parent(), \"findTop\"), \"resizeSelf\");\n\
		return folded;\n\
	break;\n\
	case \"data\":\n\
		return get(\"label\");\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"COMPACT\":\n\
			compact = 1;\n\
		break;\n\
		case \"LABEL\":\n\
			label = arg[2];\n\
		break;\n\
		case \"FOLD\":\n\
			canFold = 1;\n\
			if (arg[2] == \"yes\" || arg[2] == \"YES\") folded = 1;\n\
			set(\"BDColor\", get(\"FGColor\"));\n\
			new = send(\"HTML__foldIcon\", \"make\", self());\n\
			set(\"children\", new);\n\
		break;\n\
		case \"BORDER\":\n\
			set(\"BDColor\", \"black\");\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"compact\":\n\
		return compact;\n\
	break;\n\
	case \"folded?\":\n\
		return folded;\n\
	break;\n\
	case \"canFold?\":\n\
		return canFold;\n\
	break;\n\
	case \"label?\":\n\
		return label;\n\
	break;\n\
	case \"setAnchor\":\n\
		makeAnchor = arg[1];\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			for (i = canFold; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			for (i = canFold; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findForm\":\n\
	case \"findTop\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"reInit\":\n\
		/*HIGH KLUDGE-- to know if clone has occured*/\n\
		foldInfo = 1;\n\
		o = object(get(\"content2\"));\n\
		if (o) {\n\
			canFold = send(o, \"canFold?\");\n\
			folded = send(o, \"folded?\");\n\
			label = send(o, \"label?\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		foldInfo = 1;\n\
		SGMLBuildDoc_setColors();\n\
		color = getResource(\"Viola.background_doc\");\n\
		if (color) set(\"BDColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_list3[] = "100";
static char _slotValue_HTML_list4[] = "2";
static char _slotValue_HTML_list5[] = "6";
/* END OF FILE */

static SlotStruct objDesc_HTML_list[] = {
    {"class", _slotValue_HTML_list0},
    {"name", _slotValue_HTML_list1},
    {"script", _slotValue_HTML_list2},
    {"width", _slotValue_HTML_list3},
    {"height", _slotValue_HTML_list4},
    {"border", _slotValue_HTML_list5},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_listBullet0[] = "field";
static char _slotValue_HTML_listBullet1[] = "HTML_listBullet";
static char _slotValue_HTML_listBullet2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	label\n\
		 */\n\
		return send(clone(cloneID()), \"parent\", arg[1]);\n\
	break;\n\
	case \"parent\":\n\
		set(\"parent\", arg[1]);\n\
		return self();\n\
	break;\n\
	case \"noBullet\":\n\
		return freeSelf();\n\
	break;\n\
	case \"R\":\n\
	case \"config\":\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"BGColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_listBullet3[] = "6";
static char _slotValue_HTML_listBullet4[] = "7";
static char _slotValue_HTML_listBullet5[] = "6";
static char _slotValue_HTML_listBullet6[] = "6";
/* END OF FILE */

static SlotStruct objDesc_HTML_listBullet[] = {
    {"class", _slotValue_HTML_listBullet0},  {"name", _slotValue_HTML_listBullet1},
    {"script", _slotValue_HTML_listBullet2}, {"x", _slotValue_HTML_listBullet3},
    {"y", _slotValue_HTML_listBullet4},      {"width", _slotValue_HTML_listBullet5},
    {"height", _slotValue_HTML_listBullet6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_listC0[] = "field";
static char _slotValue_HTML_listC1[] = "HTML_listC";
static char _slotValue_HTML_listC2[] = "\n\
/*	print(\"@@@@@@ HTML_listC clsss = txtDisp: args: \");\n\
	for (i =0; i < arg[]; i++) print(arg[i], \", \");\n\
	print(\"\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return height();\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
/*		SGMLBuildDoc_setBuff(-1);*/\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], width() - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'L':\n\
		return 'U';\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"ULC\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = width();\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"ULC\");\n\
		vspan = style[0];\n\
		set(\"width\", width() - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
		return get(\"label\");\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"COMPACT\":\n\
			compact = 1;\n\
		break;\n\
		case \"BORDER\":\n\
			set(\"BDColor\", \"black\");\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"compact\":\n\
		return 1;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"inPreP\":\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_listC3[] = "100";
static char _slotValue_HTML_listC4[] = "2";
/* END OF FILE */

static SlotStruct objDesc_HTML_listC[] = {
    {"class", _slotValue_HTML_listC0},  {"name", _slotValue_HTML_listC1},
    {"script", _slotValue_HTML_listC2}, {"width", _slotValue_HTML_listC3},
    {"height", _slotValue_HTML_listC4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_listItem0[] = "field";
static char _slotValue_HTML_listItem1[] = "HTML_listItem";
static char _slotValue_HTML_listItem2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		h = SGMLBuildDoc_span();\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		vspan = -1;\n\
		set(\"x\", 30);		/*XXX*/\n\
		set(\"y\", arg[1]);\n\
		set(\"width\", arg[2] - get(\"x\"));\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	x\n\
		 * arg[3]	y\n\
		 * arg[4]	width\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"x\", arg[2]);\n\
		set(\"y\", arg[3]);\n\
		set(\"width\", arg[4]);\n\
\n\
		h = 1;\n\
\n\
		/* in case there's text before <LI> */\n\
		SGMLBuildDoc_setBuff(-1);\n\
		/* ^ needed for this case due to the inserting of this object\n\
		 * by HTML_listSep (at its Flush time).\n\
		 */\n\
\n\
		txt = get(\"label\");\n\
		if (isBlank(txt) == 0) {\n\
			new = HTML_txt(\"clone\");\n\
			w = get(\"width\");\n\
			h = send(new, \"make\", self(),\n\
				compressSpaces(txt), 0, w, 0, 0);\n\
			objectListAppend_children(new);\n\
			send(parent(), \"specialInsertOccured\");\n\
		}\n\
		return h;\n\
	break;\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (id == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (id == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"L\":\n\
	case \"compact\":\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"C\":/* useless-- but keep to keep viola quiet */\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_listItem[] = {
    {"class", _slotValue_HTML_listItem0},
    {"name", _slotValue_HTML_listItem1},
    {"script", _slotValue_HTML_listItem2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_listMenu0[] = "txtDisp";
static char _slotValue_HTML_listMenu1[] = "HTML_listMenu";
static char _slotValue_HTML_listMenu2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	label\n\
		 */\n\
		return send(clone(cloneID()), \"parent\", arg[1]);\n\
	break;\n\
	case \"parent\":\n\
		set(\"parent\", arg[1]);\n\
		return self();\n\
	break;\n\
	case \"label\":\n\
		set(\"content\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_listMenu3[] = "28";
static char _slotValue_HTML_listMenu4[] = "18";
/* END OF FILE */

static SlotStruct objDesc_HTML_listMenu[] = {
    {"class", _slotValue_HTML_listMenu0},  {"name", _slotValue_HTML_listMenu1},
    {"script", _slotValue_HTML_listMenu2}, {"width", _slotValue_HTML_listMenu3},
    {"height", _slotValue_HTML_listMenu4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_listNum0[] = "txtLabel";
static char _slotValue_HTML_listNum1[] = "HTML_listNum";
static char _slotValue_HTML_listNum2[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	label\n\
		 */\n\
		return send(clone(cloneID()), \"parent\", arg[1]);\n\
	break;\n\
	case \"parent\":\n\
		set(\"parent\", arg[1]);\n\
		return self();\n\
	break;\n\
	case \"label\":\n\
		set(\"label\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"noBullet\":\n\
		set(\"label\", \"\");\n\
		clearWindow();\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_listNum3[] = "28";
static char _slotValue_HTML_listNum4[] = "17";
/* END OF FILE */

static SlotStruct objDesc_HTML_listNum[] = {
    {"class", _slotValue_HTML_listNum0},  {"name", _slotValue_HTML_listNum1},
    {"script", _slotValue_HTML_listNum2}, {"width", _slotValue_HTML_listNum3},
    {"height", _slotValue_HTML_listNum4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_listNum_oval0[] = "txtLabel";
static char _slotValue_HTML_listNum_oval1[] = "HTML_listNum_oval";
static char _slotValue_HTML_listNum_oval2[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	label\n\
		 */\n\
		return send(clone(cloneID()), \"parent\", arg[1]);\n\
	break;\n\
	case \"parent\":\n\
		set(\"parent\", arg[1]);\n\
		return self();\n\
	break;\n\
	case \"R\":\n\
		return 0;\n\
	break;\n\
	case \"label\":\n\
		set(\"label\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"noBullet\":\n\
		set(\"label\", \"\");\n\
		clearWindow();\n\
		return;\n\
	break;\n\
	case \"render\":\n\
	case \"expose\":\n\
		usual();\n\
		drawOval(0, 0, 27, 17); /* XXX make this flexible */\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_listNum_oval3[] = "28";
static char _slotValue_HTML_listNum_oval4[] = "18";
/* END OF FILE */

static SlotStruct objDesc_HTML_listNum_oval[] = {
    {"class", _slotValue_HTML_listNum_oval0},  {"name", _slotValue_HTML_listNum_oval1},
    {"script", _slotValue_HTML_listNum_oval2}, {"width", _slotValue_HTML_listNum_oval3},
    {"height", _slotValue_HTML_listNum_oval4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_listNumbered0[] = "field";
static char _slotValue_HTML_listNumbered1[] = "HTML_listNumbered";
static char _slotValue_HTML_listNumbered2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		if (label) drawText(35, 1, 1, label);\n\
		return;\n\
	break;\n\
	case \"D\":\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				itemN++;\n\
				send(nthChild(i), \"itemN\", itemN);\n\
			}\n\
		}\n\
		set(\"content2\", self());/*a kludge to deal with cloning*/\n\
		if (canFold) {\n\
			if (folded) {\n\
				/* make the first list item go away,\n\
				 * to show the toggler */\n\
				send(nthChild(1), \"R\", 30, get(\"width\"));\n\
				send(nthChild(0), \"setFolded\", 1);\n\
				return get(\"height\") + 20;\n\
			} else {\n\
				return 20;\n\
			}\n\
		}\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"OL\");\n\
		return get(\"height\") + style[1];\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
/*		SGMLBuildDoc_setBuff(-1);*/\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'L':\n\
		return 'O';\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"OL\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		if (foldInfo == 0) {\n\
			send(self(), \"reInit\");\n\
			if (label) drawText(35, 1, 1, label);\n\
		}\n\
\n\
		if (canFold) vspan += 18;\n\
		if (canFold == 0 || folded == 0) {\n\
			n = countChildren();\n\
			if (n > canFold/*XXX warning: logic/numeral mix*/) {\n\
				xx = get(\"width\");\n\
				for (i = canFold; i < n; i++)\n\
				  vspan += send(nthChild(i), 'R', vspan, xx);\n\
			}\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"OL\");\n\
		vspan = style[0];\n\
		set(\"width\", get(\"width\") - style[3]);\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			xx = get(\"width\");\n\
			for (i = canFold; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"folded\":\n\
		if (foldInfo == 0) send(self(), \"reInit\");\n\
		folded = arg[1];\n\
		send(send(parent(), \"findTop\"), \"resizeSelf\");\n\
		return;\n\
	break;\n\
	case \"toggleFolded\":\n\
		if (foldInfo == 0) send(self(), \"reInit\");\n\
		if (folded) folded = 0;\n\
		else folded = 1;\n\
		send(send(parent(), \"findTop\"), \"resizeSelf\");\n\
		return folded;\n\
	break;\n\
	case \"data\":\n\
		return get(\"label\");\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"COMPACT\":\n\
			compact = 1;\n\
		break;\n\
		case \"LABEL\":\n\
			label = arg[2];\n\
		break;\n\
		case \"FOLD\":\n\
			canFold = 1;\n\
			if (arg[2] == \"yes\" || arg[2] == \"YES\") folded = 1;\n\
			set(\"BDColor\", get(\"FGColor\"));\n\
			new = send(\"HTML__foldIcon\", \"make\", self());\n\
			set(\"children\", new);\n\
		break;\n\
		case \"BORDER\":\n\
			set(\"BDColor\", \"black\");\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"compact\":\n\
		return compact;\n\
	break;\n\
	case \"folded?\":\n\
		return folded;\n\
	break;\n\
	case \"canFold?\":\n\
		return canFold;\n\
	break;\n\
	case \"label?\":\n\
		return label;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			for (i = canFold; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > canFold) {\n\
			for (i = canFold; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"findForm\":\n\
		return send(parent(), \"findForm\");\n\
	break;\n\
	case \"reInit\":\n\
		/*HIGH KLUDGE-- to know if clone has occured*/\n\
		foldInfo = 1;\n\
		o = object(get(\"content2\"));\n\
		if (o) {\n\
			canFold = send(o, \"canFold?\");\n\
			folded = send(o, \"folded?\");\n\
			label = send(o, \"label?\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		foldInfo = 1;\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_listNumbered3[] = "100";
static char _slotValue_HTML_listNumbered4[] = "2";
/* END OF FILE */

static SlotStruct objDesc_HTML_listNumbered[] = {
    {"class", _slotValue_HTML_listNumbered0},  {"name", _slotValue_HTML_listNumbered1},
    {"script", _slotValue_HTML_listNumbered2}, {"width", _slotValue_HTML_listNumbered3},
    {"height", _slotValue_HTML_listNumbered4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_listNumberedC0[] = "field";
static char _slotValue_HTML_listNumberedC1[] = "HTML_listNumberedC";
static char _slotValue_HTML_listNumberedC2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"OLC\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				itemN++;\n\
				send(nthChild(i), \"itemN\", itemN);\n\
			}\n\
		}\n\
		return height() + style[1];\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], width() - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'L':\n\
		return 'O';\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"OLC\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = width();\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"OLC\");\n\
		vspan = style[0];\n\
		set(\"width\", width() - style[3]);\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = width();\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
		return get(\"label\");\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"COMPACT\":\n\
			compact = 1;\n\
		break;\n\
		case \"BORDER\":\n\
			set(\"BDColor\", \"black\");\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"compact\":\n\
		return 1;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_listNumberedC3[] = "100";
static char _slotValue_HTML_listNumberedC4[] = "2";
/* END OF FILE */

static SlotStruct objDesc_HTML_listNumberedC[] = {
    {"class", _slotValue_HTML_listNumberedC0},  {"name", _slotValue_HTML_listNumberedC1},
    {"script", _slotValue_HTML_listNumberedC2}, {"width", _slotValue_HTML_listNumberedC3},
    {"height", _slotValue_HTML_listNumberedC4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_listSep0[] = "field";
static char _slotValue_HTML_listSep1[] = "HTML_listSep";
static char _slotValue_HTML_listSep2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		return;\n\
	break;\n\
	case \"D\":\n\
		if (send(parent(), \"compact\")) saveSpace = 3;\n\
		if (specialInsertOccured == 1) {\n\
			h = send(self(), 'R', get(\"y\"), get(\"width\"), \n\
				 get(\"x\")) - saveSpace;\n\
		} else {\n\
			h = get(\"height\") - saveSpace;\n\
		}\n\
		SGMLBuildDoc_setBuff(0);\n\
		/*^^ necessary, else the \"First item\" will appear twice in */\n\
		/*\n\
		<UL>\n\
		<LI>First item\n\
		<P>\n\
		<LI>Second item\n\
		</UL>\n\
		*/\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			listType = send(parent(), 'L');\n\
			if (first == 0) {\n\
				first = 1;\n\
				switch (listType) {\n\
				case 'U':	/* UL */\n\
					bulletObj = HTML_listBullet(\"make\", \n\
								    self());\n\
					objectListAppend_children(bulletObj);\n\
					x_offset = 30;\n\
					objResizeSkip = 1;\n\
				break;\n\
				case 'O':	/* OL */\n\
					/*bulletObj = HTML_listNum_oval(\"make\",\n\
							      self());*/\n\
					bulletObj = HTML_listNum(\"make\",self());\n\
					objectListAppend_children(bulletObj);\n\
					x_offset = 30;\n\
					objResizeSkip = 1;\n\
				break;\n\
				default:\n\
					x_offset = 35;\n\
				break;\n\
				}\n\
			}\n\
			if (listTxt_style == 0) \n\
				listTxt_style = SGMLGetStyle(\"HTML\", \n\
							     \"P_in_listSep\");\n\
			txtObj = HTML_listTxt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				x_offset,\n\
				get(\"width\") - x_offset - listTxt_style[3],\n\
				h, 0);\n\
		}\n\
		set(\"height\", h + 2);\n\
		return h;\n\
	break;\n\
	case \"F\":\n\
		/* create and set insertObject before \"D\", so flush this obj\n\
		 */\n\
		if (parent() == 0) return;\n\
		listType = send(parent(), 'L');\n\
		y = SGMLBuildDoc_span();\n\
		if (first == 0) {\n\
			first = 1;\n\
			switch (listType) {\n\
			case 'U':	/* UL */\n\
				bulletObj = HTML_listBullet(\"make\", self());\n\
				objectListAppend_children(bulletObj);\n\
				x_offset = 30;\n\
				objResizeSkip = 1;\n\
			break;\n\
			case 'O':	/* OL */\n\
				bulletObj = HTML_listNum(\"make\", self());\n\
			/*bulletObj = HTML_listNum_oval(\"make\", self());*/\n\
				objectListAppend_children(bulletObj);\n\
				x_offset = 30;\n\
				objResizeSkip = 1;\n\
			break;\n\
			default:\n\
				x_offset = 30;\n\
			break;\n\
			}\n\
		}\n\
		switch (listType) {\n\
		case 'U':	/* UL */\n\
			listItemContainer = HTML_listItem(\"clone\");\n\
			w = get(\"width\") - 30;\n\
			txtH = send(listItemContainer, \"make\", self(), \n\
					30, y, w);\n\
			SGMLBuildDoc_insertObj(listItemContainer, w);\n\
\n\
			return -1;\n\
		break;\n\
		case 'O':	/* OL */\n\
			listItemContainer = HTML_listItem(\"clone\");\n\
			w = get(\"width\") - 40;\n\
			txtH = send(listItemContainer, \"make\", self(), \n\
					30, y, w);\n\
			SGMLBuildDoc_insertObj(listItemContainer, w);\n\
\n\
			return -1;\n\
		break;\n\
		case 'D':	/* DIR */\n\
			listItemContainer = HTML_listItem(\"clone\");\n\
			w = get(\"width\") - 30;\n\
			txtH = send(listItemContainer, \"make\", self(), \n\
					30, h, w);\n\
			SGMLBuildDoc_insertObj(listItemContainer, w);\n\
\n\
			return -1;\n\
		break;\n\
		case 'M':	/* MENU */\n\
		default:\n\
			listItemContainer = HTML_listItem(\"clone\");\n\
			w = get(\"width\") - 30;\n\
			txtH = send(listItemContainer, \"make\", self(), \n\
					30, h, w);\n\
			SGMLBuildDoc_insertObj(listItemContainer, w);\n\
			return -1;\n\
		break;\n\
		}\n\
	break;\n\
	case 'R': /* resize */\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	x (optional)\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"LI\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - style[3]);\n\
		if (arg[] == 4) set(\"x\", arg[3]);\n\
		h = 0;\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = objResizeSkip; i < n; i++)\n\
				h += send(nthChild(i), 'R', h, xx) - saveSpace;\n\
		}\n\
		vspan += h;\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"AA\":\n\
	case \"AI\":\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"itemN\":\n\
		send(nthChild(0), \"label\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"specialInsertOccured\":\n\
		specialInsertOccured = 1;\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"setAnchor\":\n\
		return send(parent(), \"setAnchor\", arg[1]);\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_listSep[] = {
    {"class", _slotValue_HTML_listSep0},
    {"name", _slotValue_HTML_listSep1},
    {"script", _slotValue_HTML_listSep2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_listTxt0[] = "txtDisp";
static char _slotValue_HTML_listTxt1[] = "HTML_listTxt";
static char _slotValue_HTML_listTxt2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		www.mesg.tf(\"clear\");\n\
		prevHint = 0;\n\
		return;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P_in_listSep\");\n\
		vspan = style[0];\n\
		set(\"width\", get(\"width\") - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		clearWindow();\n\
		render();/*may be extraneous */\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		return vspan;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P_in_listSep\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		clearWindow();\n\
		vspan += set(\"height\", building_vspan()+2) + style[1];\n\
		render(); /* render() affects building_vspan() ? */\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
	 	/* arg[1]	parent\n\
	 	 * arg[2]	data\n\
	 	 * arg[3]	x\n\
	 	 * arg[4]	width\n\
	 	 * arg[5]	y\n\
	 	 */\n\
	 	set(\"parent\", arg[1]);\n\
	 	set(\"x\", arg[3]);\n\
	 	set(\"y\", arg[5]);\n\
	 	set(\"width\", arg[4]);\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
	 	set(\"content\", arg[2]);\n\
	 	h = building_vspan();\n\
	 	set(\"height\", h);\n\
	 	set(\"maxHeight\", h);\n\
	 	if (style == 0) style = SGMLGetStyle(\"HTML\", \"P_in_listSep\");\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
	 	return style[0] + h + style[1];\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML_listTxt3[] = "8";
static char _slotValue_HTML_listTxt4[] = "normal";
static char _slotValue_HTML_listTxt5[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_listTxt[] = {
    {"class", _slotValue_HTML_listTxt0},
    {"name", _slotValue_HTML_listTxt1},
    {"script", _slotValue_HTML_listTxt2},
    {"height", _slotValue_HTML_listTxt3},
    {"font", _slotValue_HTML_listTxt4},
    {"format", _slotValue_HTML_listTxt5},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_listing0[] = "txtDisp";
static char _slotValue_HTML_listing1[] = "HTML_listing";
static char _slotValue_HTML_listing2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		expose(arg[1], arg[2], arg[3], arg[4]);\n\
		return;\n\
	break;\n\
	case \"D\": /* done */\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		set(\"content\", get(\"label\"));\n\
		return building_vspan();\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"LISTING\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_listing3[] = "100";
static char _slotValue_HTML_listing4[] = "30";
static char _slotValue_HTML_listing5[] = "fixed";
static char _slotValue_HTML_listing6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_listing[] = {
    {"class", _slotValue_HTML_listing0},  {"name", _slotValue_HTML_listing1},
    {"script", _slotValue_HTML_listing2}, {"width", _slotValue_HTML_listing3},
    {"height", _slotValue_HTML_listing4}, {"font", _slotValue_HTML_listing5},
    {"format", _slotValue_HTML_listing6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_math0[] = "field";
static char _slotValue_HTML_math1[] = "HTML_math";
static char _slotValue_HTML_math2[] = "\n\
print(\"HTML_math: self=\", self(), \"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\\n\
\");\n\
for(i=0;i<arg[];i++) print(\"arg[\",i,\"]={\",arg[i],\"}\\n\
\");\n\
\n\
	switch (arg[0]) {\n\
	case \"config\":\n\
print(\"CAUGHT CONFIG\\n\
\");\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
		test4();\n\
		return;\n\
	break;\n\
	case \"flush\":\n\
		if (isBlank(get(\"label\"))) return -1;\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = get(\"label\");\n\
		tokCount++;\n\
\n\
		return -1;\n\
	break;\n\
	case \"entity\":\n\
print(\"ENTITY FLUSH MATH label>>>>>\", get(\"label\"), \"<<<\\n\
\");\n\
\n\
		if (isBlank(get(\"label\"))) return 0;\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = get(\"label\");\n\
		tokCount++;\n\
\n\
		entity_number = arg[1];\n\
		if (entity_number == 50) {/*infin*/\n\
		} else if (entity_number == 51) { /*integral*/\n\
			tok[tokCount] = 19; /*MINFO_INTEGRAL*/\n\
			data[tokCount] = \"\";\n\
			tokCount++;\n\
		} else if (entity_number == 65) { /*sigma*/\n\
			tok[tokCount] = 20; /*MINFO_SUM*/\n\
			data[tokCount] = \"\";\n\
			tokCount++;\n\
		}\n\
		return;\n\
	break;\n\
	case \"tok&data\":\n\
		/* arg[1]	token\n\
		 * arg[2]	data\n\
		 */\n\
		tok[tokCount] = arg[1];\n\
		data[tokCount] = arg[2];\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		/* arg[1]	data\n\
		 */\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = arg[1];\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"tok\":\n\
		/* arg[1]	token type\n\
		 */\n\
		tok[tokCount] = arg[1];\n\
		data[tokCount] = \"\";\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"F\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		if (isBlank(get(\"label\"))) return -1;\n\
/*print(\"F MATH label>>>>>\", get(\"label\"), \"<<<\\n\
\");\n\
*/\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = get(\"label\");\n\
		tokCount++;\n\
\n\
		return -1;\n\
	break;\n\
	case \"D\":\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			tok[tokCount] = 2;\n\
			data[tokCount] = get(\"label\");\n\
			tokCount++;\n\
		}\n\
\n\
		for (i = 0; i < tokCount; i++) {\n\
			print(\"math_tok \", i, \":   type=\", tok[i], \n\
				\"data={\", data[i], \"}\\n\
\");\n\
		}\n\
\n\
/*		tagPtr = STG_tagPtr(\"MATH\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		SGMLMathFormater(tok, data, tokCount);\n\
print(\"MATH: D after1 width=\", width(),\"\\n\
\");\n\
print(\"MATH: D after1 height=\", height(),\"\\n\
\");\n\
		set(\"width\", get(\"width\"));\n\
		set(\"height\", get(\"height\"));\n\
print(\"MATH: D after2 width=\", width(),\"\\n\
\");\n\
print(\"MATH: D after2 height=\", height(),\"\\n\
\");\n\
/*		tokCount = 0;\n\
*/\n\
		return get(\"height\");\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"MATH\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
print(\"MATH: R before  width=\", width(),\"\\n\
\");\n\
print(\"MATH: R before  height=\", height(),\"\\n\
\");\n\
		SGMLMathFormater(tok, data, tokCount);\n\
\n\
		vspan += set(\"height\", get(\"height\")) + style[1];\n\
print(\"MATH: R after  width=\", width(),\"\\n\
\");\n\
print(\"MATH: R after  height=\", height(),\"\\n\
\");\n\
print(\"MATH: R result vspan=\", vspan,\"\\n\
\");\n\
		return vspan;\n\
	break;\n\
	case 'b':\n\
		return border;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"MATH\");\n\
		vspan = style[0];\n\
\n\
		SGMLMathFormater(tok, data, tokCount);\n\
\n\
		set(\"height\", vspan + get(\"height\") + style[1]);\n\
		return get(\"height\");\n\
	break;\n\
	case \"inPreP\":\n\
		return 0;\n\
	break;\n\
	case \"reportTitle\":\n\
		title = arg[1];\n\
		titleAtTopP = arg[2];\n\
		titleAlign = arg[3];\n\
		return;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"BORDER\":\n\
			border = 1;\n\
		break;\n\
		case \"COMPACT\":\n\
			compact = 1; 	/* NOT USED YET */\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
/*		SGMLBuildDoc_setColors();*/\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_math3[] = "white";
static char _slotValue_HTML_math4[] = "red";
static char _slotValue_HTML_math5[] = "200";
static char _slotValue_HTML_math6[] = "200";
/* END OF FILE */

static SlotStruct objDesc_HTML_math[] = {
    {"class", _slotValue_HTML_math0},   {"name", _slotValue_HTML_math1},
    {"script", _slotValue_HTML_math2},  {"FGColor", _slotValue_HTML_math3},
    {"BGColor", _slotValue_HTML_math4}, {"width", _slotValue_HTML_math5},
    {"height", _slotValue_HTML_math6},  {(char*)0, (char*)0},
};

static char _slotValue_HTML_menu0[] = "field";
static char _slotValue_HTML_menu1[] = "HTML_menu";
static char _slotValue_HTML_menu2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\": /* flush */\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_li == 0)\n\
				style_li = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			y = SGMLBuildDoc_span();\n\
			h = send(txtObj, \"make\", self(), get(\"label\"),\n\
				style_li[2], \n\
				get(\"width\") - style_li[2], y, 'M');\n\
		} \n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\": /* done */\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_li == 0)\n\
				style_li = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			y = get(\"height\");\n\
			h += send(txtObj, \"make\", self(), get(\"label\"),\n\
				style_li[2], \n\
				get(\"width\") - style_li[2], y, 'M');\n\
		} \n\
		set(\"height\", h);\n\
		return get(\"height\");\n\
	break;\n\
	case 'L':\n\
		return 'M';\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"MENU\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return get(\"label\");\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		}\n\
	break;\n\
	case \"compact\":\n\
		return 1;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_menu3[] = "3";
static char _slotValue_HTML_menu4[] = "100";
static char _slotValue_HTML_menu5[] = "2";
/* END OF FILE */

static SlotStruct objDesc_HTML_menu[] = {
    {"class", _slotValue_HTML_menu0},
    {"name", _slotValue_HTML_menu1},
    {"script", _slotValue_HTML_menu2},
    {"border", _slotValue_HTML_menu3},
    {"width", _slotValue_HTML_menu4},
    {"height", _slotValue_HTML_menu5},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_menuSep0[] = "field";
static char _slotValue_HTML_menuSep1[] = "HTML_listSep";
static char _slotValue_HTML_menuSep2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		txt = send(parent(), \"data\");\n\
		if (isBlank(txt)) {\n\
			return 0;\n\
		} else {\n\
			listItemObj = HTML_txtListItem(\"clone\");\n\
\n\
			set(\"children\", listItemObj);\n\
\n\
			h = send(listItemObj, \"make\", self(), txt,\n\
					40, width() - 40);\n\
\n\
			/* to number or not? */\n\
			if (send(parent(), 'N')) {\n\
				bulletObj = HTML_listNum(\"make\", self());\n\
			} else {\n\
				bulletObj = HTML_listBullet(\"make\", self());\n\
			}\n\
			objectListAppend_children(bulletObj);\n\
\n\
			return h;\n\
		}\n\
	break;\n\
	case 'R': /* resize */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"LI\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		vspan = send(nthChild(0), \"R\", vspan, width() - 40);\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		/* arg[2]	data\n\
		 * arg[3]	x\n\
		 * arg[4]	width\n\
		 * arg[5]	y\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"x\", arg[3]);\n\
		set(\"y\", arg[5]);\n\
\n\
		txt = arg[2];\n\
\n\
		listItemObj = HTML_txtListItem(\"clone\");\n\
\n\
		set(\"children\", listItemObj);\n\
\n\
		h = send(listItemObj, \"make\", self(), txt,\n\
				40, arg[4] - 40);\n\
\n\
		/* to number or not? */\n\
		if (send(parent(), 'N')) {\n\
			bulletObj = HTML_listNum(\"make\", self());\n\
		} else {\n\
			bulletObj = HTML_listBullet(\"make\", self());\n\
		}\n\
		objectListAppend_children(bulletObj);\n\
\n\
		set(\"width\", arg[4]);\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"itemN\":\n\
		send(nthChild(1), \"label\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"noBullet\":\n\
		w = width();\n\
		set(\"label\", \"\");\n\
		clearWindow();\n\
		set(\"width\", w);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_menuSep3[] = "100";
static char _slotValue_HTML_menuSep4[] = "40";
/* END OF FILE */

static SlotStruct objDesc_HTML_menuSep[] = {
    {"class", _slotValue_HTML_menuSep0},  {"name", _slotValue_HTML_menuSep1},
    {"script", _slotValue_HTML_menuSep2}, {"width", _slotValue_HTML_menuSep3},
    {"height", _slotValue_HTML_menuSep4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_mh0[] = "field";
static char _slotValue_HTML_mh1[] = "HTML_mh";
static char _slotValue_HTML_mh2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		text = get(\"label\");\n\
		send(parent(), \"reportMailHeader\", text);\n\
		return -1;\n\
	break;\n\
	case \"config\":\n\
	case \"R\":\n\
		return 0;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_mh[] = {
    {"class", _slotValue_HTML_mh0},
    {"name", _slotValue_HTML_mh1},
    {"script", _slotValue_HTML_mh2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_nextID0[] = "field";
static char _slotValue_HTML_nextID1[] = "HTML_nextID";
static char _slotValue_HTML_nextID2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		return -1;\n\
	break;\n\
	case \"D\":\n\
/*		text = get(\"label\");\n\
		send(send(parent(), \"findTop\"), \"reportNextID\", text);\n\
*/\n\
		return -1;\n\
	break;\n\
	case \"R\":\n\
		return 0;\n\
	break;\n\
	case \"config\":\n\
	case \"AA\":\n\
	case \"AI\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_nextID[] = {
    {"class", _slotValue_HTML_nextID0},
    {"name", _slotValue_HTML_nextID1},
    {"script", _slotValue_HTML_nextID2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_option0[] = "field";
static char _slotValue_HTML_option1[] = "HTML_option";
static char _slotValue_HTML_option2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		send(parent(), \"option\", varDefault, get(\"label\"), checked);\n\
		varDefault = \"\";\n\
		checked = 0;\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
	case \"AI\":\n\
		return 0;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"VALUE\":\n\
			varDefault = arg[2];\n\
		break;\n\
		case \"SELECTED\":\n\
		case \"CHECKED\":\n\
			checked = 1;\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<OPTION\");\n\
		if (varDefault) print(\" VALUE=\\\"\", varDefault, \"\\\"\");\n\
		if (checked) print(\" SELECTED\");\n\
		print(\">\\n\
\");\n\
		print(get(\"content\"));\n\
		print(\"\\n\
\");\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_option[] = {
    {"class", _slotValue_HTML_option0},
    {"name", _slotValue_HTML_option1},
    {"script", _slotValue_HTML_option2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_over0[] = "field";
static char _slotValue_HTML_over1[] = "HTML_over";
static char _slotValue_HTML_over2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		set(\"y\", -10);\n\
		send(parent(), \"over\");\n\
		return 0;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_over3[] = "-10";
/* END OF FILE */

static SlotStruct objDesc_HTML_over[] = {
    {"class", _slotValue_HTML_over0},
    {"name", _slotValue_HTML_over1},
    {"script", _slotValue_HTML_over2},
    {"y", _slotValue_HTML_over3},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_plain0[] = "txtDisp";
static char _slotValue_HTML_plain1[] = "HTML_plain";
static char _slotValue_HTML_plain2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"D\": /* done */\n\
		set(\"content\", get(\"label\"));\n\
		return (building_vspan() + 2);\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"EXAMPLE\");/*XXX*/\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_plain3[] = "100";
static char _slotValue_HTML_plain4[] = "10";
static char _slotValue_HTML_plain5[] = "fixed";
/* END OF FILE */

static SlotStruct objDesc_HTML_plain[] = {
    {"class", _slotValue_HTML_plain0},
    {"name", _slotValue_HTML_plain1},
    {"script", _slotValue_HTML_plain2},
    {"width", _slotValue_HTML_plain3},
    {"height", _slotValue_HTML_plain4},
    {"font", _slotValue_HTML_plain5},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_plaintext0[] = "txtDisp";
static char _slotValue_HTML_plaintext1[] = "HTML_plaintext";
static char _slotValue_HTML_plaintext2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"D\": /* done */\n\
		set(\"content\", get(\"label\"));\n\
		return (building_vspan() + 2);\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_plaintext3[] = "100";
static char _slotValue_HTML_plaintext4[] = "30";
static char _slotValue_HTML_plaintext5[] = "fixed";
static char _slotValue_HTML_plaintext6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_plaintext[] = {
    {"class", _slotValue_HTML_plaintext0},    {"name", _slotValue_HTML_plaintext1},
    {"script", _slotValue_HTML_plaintext2},   {"width", _slotValue_HTML_plaintext3},
    {"height", _slotValue_HTML_plaintext4},   {"font", _slotValue_HTML_plaintext5},
    {"verbatim", _slotValue_HTML_plaintext6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_pre0[] = "field";
static char _slotValue_HTML_pre1[] = "HTML_pre";
static char _slotValue_HTML_pre2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		return;\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_preTxt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				get(\"label\"),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_preTxt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				get(\"label\"),\n\
				style_p[3],\n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"PRE\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"r\":\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"PRE\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"inPreP\":\n\
		return 1;\n\
	break;\n\
	case \"setAnchor\":\n\
		makeAnchor = arg[1];\n\
		return;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return get(\"label\");\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"findForm\":\n\
		return send(parent(), \"findForm\");\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<SECTION>\\n\
\");\n\
		n = countChildren();\n\
		if (n) {\n\
			for (i = 0; i < n; i++)\n\
				send(nthChild(i), \"outputSGML\");\n\
		}\n\
		print(\"</SECTION>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_pre[] = {
    {"class", _slotValue_HTML_pre0},
    {"name", _slotValue_HTML_pre1},
    {"script", _slotValue_HTML_pre2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_preTxt0[] = "txtDisp";
static char _slotValue_HTML_preTxt1[] = "HTML_preTxt";
static char _slotValue_HTML_preTxt2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		expose(arg[1], arg[2], arg[3], arg[4]);\n\
		return;\n\
	break;\n\
	case \"D\": /* done */\n\
		if (isBlank(get(\"label\"))) return 0;\n\
		if (deco) {\n\
			box = send(deco, \"clone\");\n\
			objectListAppend_children(box);\n\
			h = send(box, \"make\", self(), \n\
				get(\"label\"), get(\"width\"));\n\
			return h + 2;\n\
			/* +2 for hot-link-indicator border around IMGs */\n\
		} else {\n\
			inPreP = send(parent(), \"inPreP\");\n\
			if (inPreP) set(\"format\", 0);\n\
			set(\"content\", get(\"label\"));\n\
			set(\"label\", \"\");\n\
			isHTML = 1;\n\
			return building_vspan()+2;\n\
			/* +2 for hot-link-indicator border around IMGs */\n\
		}\n\
	break;\n\
	case \"F\": /* flush */\n\
		return 1;\n\
	break;\n\
	case 'R': /* resize */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		w = arg[2] - get(\"x\") - style[3];\n\
		set(\"width\", w);\n\
		if (deco) {\n\
			h = send(nthChild(0), \"R\", w);\n\
			set(\"height\", h);\n\
			return h + style[1];\n\
		} else {\n\
			set(\"content\", trimEdgeQ(get(\"content\")));\n\
			clearWindow();\n\
			vspan += set(\"height\", building_vspan()+2) + style[1];\n\
			/* +2 for hot-link-indicator border around IMGs */\n\
			render();\n\
			return vspan;\n\
		}\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
		vspan = style[0];\n\
		set(\"width\", get(\"width\") - style[3]);\n\
		set(\"content\", trimEdgeQ(get(\"content\")));\n\
		clearWindow();\n\
		render();\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		return vspan;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagIDs[tagIDCount] = arg[2];\n\
			tagIDCount = tagIDCount + 1;\n\
		break;\n\
		case \"STYLE\":\n\
			switch (arg[2]) {\n\
			case \"QUOTE\":\n\
			break;\n\
			case \"MARGIN\":\n\
			break;\n\
			case \"NOTE\":\n\
				deco = \"HTML__txtBox_note\";\n\
			break;\n\
			case \"CAUTION\":\n\
				deco = \"HTML__txtBox_caution\";\n\
			break;\n\
			case \"WARNING\":\n\
				set(\"BDColor\", \"darkOrange\");\n\
				deco = \"HTML__txtBox_caution\";\n\
			break;\n\
			case \"ERROR\":\n\
				set(\"BDColor\", \"red\");\n\
				deco = \"HTML__txtBox_error\";\n\
			break;\n\
			case \"TIMED\": /*just for fun*/\n\
				deco = \"HTML__txtBox_time\";\n\
			break;\n\
			case \"NORMAL\":\n\
			default:\n\
			break;\n\
			}\n\
		break;\n\
		case \"COMPACT\":\n\
			compact = 1; 	/* NOT USED YET */\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"setAnchor\":\n\
		tagIDs[tagIDCount] = arg[1];\n\
		tagIDCount++;\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagIDCount > 0)\n\
			for (i = 0; i < tagIDCount; i++)\n\
				if (tagIDs[i] == arg[1]) return get(\"y\");\n\
		return 0;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"config\":\n\
		/* necessary in case of HPANE triggered resizes */\n\
		clearWindow();\n\
		usual();		\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<P>\", get(\"content\"), \"\\n\
\");\n\
/*\n\
		n = anchor....\n\
		if (n) {\n\
			for (i = 0; i < n; i++)\n\
				send(nthChild(i), \"outputSGML\");\n\
		}\n\
*/\n\
		print(\"</P>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML_preTxt3[] = "-99";
static char _slotValue_HTML_preTxt4[] = "100";
static char _slotValue_HTML_preTxt5[] = "8";
static char _slotValue_HTML_preTxt6[] = "fixed";
/* END OF FILE */

static SlotStruct objDesc_HTML_preTxt[] = {
    {"class", _slotValue_HTML_preTxt0},  {"name", _slotValue_HTML_preTxt1},
    {"script", _slotValue_HTML_preTxt2}, {"y", _slotValue_HTML_preTxt3},
    {"width", _slotValue_HTML_preTxt4},  {"height", _slotValue_HTML_preTxt5},
    {"font", _slotValue_HTML_preTxt6},   {(char*)0, (char*)0},
};

static char _slotValue_HTML_psep0[] = "field";
static char _slotValue_HTML_psep1[] = "HTML_psep";
static char _slotValue_HTML_psep2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return 0;\n\
	break;\n\
	case 'i':\n\
		send(parent(), \"makeTxt\");\n\
		return \"\";\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_psep3[] = "100";
static char _slotValue_HTML_psep4[] = "30";
/* END OF FILE */

static SlotStruct objDesc_HTML_psep[] = {
    {"class", _slotValue_HTML_psep0},  {"name", _slotValue_HTML_psep1},
    {"script", _slotValue_HTML_psep2}, {"width", _slotValue_HTML_psep3},
    {"height", _slotValue_HTML_psep4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_psf0[] = "GIF";
static char _slotValue_HTML_psf1[] = "HTML_psf";
static char _slotValue_HTML_psf2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		style = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		vspan += get(\"height\") + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	w\n\
		 * arg[3]	y\n\
		 * arg[4]	src\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[2]);\n\
		style = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\
		set(\"y\", style[0]);\n\
		set(\"x\", arg[3] + style[2]);\n\
\n\
/*bleh*/	localSource = HTTPGet(arg[4]);\n\
		fnNoExt = parseHTTPAddress(\"name\", concat(localSource, \".ps\"));\n\
		system(concat(\"mv \", localSource, \" /tmp/\", fnNoExt, \".ps\"));\n\
		localSource = concat(\"/tmp/\", fnNoExt, \".ps\");\n\
/*\n\
print(\"arg[4]={\", arg[4], \"}\\n\
\");\n\
print(\"localSource={\", localSource, \"}\\n\
\");\n\
print(\"fnNoExt={\", fnNoExt, \"}\\n\
\");\n\
*/\n\
		if (arg[5] > 0) {\n\
			after(arg[5], self(), \n\
				\"loadData\", localSource, arg[6], arg[7]);\n\
			set(\"width\", arg[6]);\n\
			set(\"height\", arg[7]);\n\
			return height();\n\
		} else {\n\
			BITPLANES = 1;\n\
			system(\"rm -f /tmp/ps2gif.tmp\");\n\
			saveFile(\"/tmp/ps2gif.tmp\",\n\
			   concat(\"(pstoppm.ps) run\\n\
\",\n\
				  \"80 80 ppmsetdensity\\n\
\",\n\
				  \"(/tmp/) ppmsetprefix\\n\
\",\n\
				  \"(\", fnNoExt, \") ppm\", BITPLANES, \"run\\n\
\",\n\
				  \"80 80 ppmsetdensity\\n\
\"));\n\
			system(\"cd /tmp; gs -DNODISPLAY -dSAFER -q < /tmp/ps2gif.tmp\");\n\
\n\
/*			system(concat(\"rm -f /tmp/\", fnNoExt));\n\
*/\n\
			localFile = concat(\"/tmp/\", fnNoExt, \".gif\");\n\
/*\n\
print(\"localFile={\", localFile, \"}\\n\
\");\n\
print(\"fnNoExt={\", fnNoExt, \"}\\n\
\");\n\
*/\n\
			system(concat(\"ppmtogif < /tmp/\", \n\
					fnNoExt, \".ppm > \", localFile));\n\
\n\
			system(concat(\"rm -f /tmp/\", fnNoExt, \".ppm\"));\n\
			system(\"rm -f /tmp/ps2gif.tmp\");\n\
\n\
			/* to get the gif in its natural dimension */\n\
			set(\"width\", 0);\n\
			set(\"height\", 0);\n\
\n\
			set(\"label\", localFile);\n\
\n\
			return height();\n\
		}\n\
	break;\n\
	case \"loadData\":\n\
		set(\"label\", loadFile(arg[1]));\n\
		render();\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_psf3[] = "100";
static char _slotValue_HTML_psf4[] = "30";
/* END OF FILE */

static SlotStruct objDesc_HTML_psf[] = {
    {"class", _slotValue_HTML_psf0},  {"name", _slotValue_HTML_psf1},
    {"script", _slotValue_HTML_psf2}, {"width", _slotValue_HTML_psf3},
    {"height", _slotValue_HTML_psf4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_quote0[] = "txtDisp";
static char _slotValue_HTML_quote1[] = "HTML_quote";
static char _slotValue_HTML_quote2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"D\":\n\
		text = get(\"label\");\n\
		set(\"content\", text);\n\
		return (building_vspan() + 1);\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_quote3[] = "100";
static char _slotValue_HTML_quote4[] = "30";
static char _slotValue_HTML_quote5[] = "normal";
static char _slotValue_HTML_quote6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_quote[] = {
    {"class", _slotValue_HTML_quote0},  {"name", _slotValue_HTML_quote1},
    {"script", _slotValue_HTML_quote2}, {"width", _slotValue_HTML_quote3},
    {"height", _slotValue_HTML_quote4}, {"font", _slotValue_HTML_quote5},
    {"format", _slotValue_HTML_quote6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_script0[] = "field";
static char _slotValue_HTML_script1[] = "HTML_script";
static char _slotValue_HTML_script2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return 0;\n\
	break;\n\
	case 'i':\n\
		print(\"WARNING: INTERPRETING SCRIPT >>\", get(\"label\"), \"<<\\n\
\");\n\
		ss = interpret(get(\"label\"));\n\
		print(\"INTERPRETION RESULT >>\", ss, \"<<\\n\
\");\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_script[] = {
    {"class", _slotValue_HTML_script0},
    {"name", _slotValue_HTML_script1},
    {"script", _slotValue_HTML_script2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_select0[] = "HTML_select";
static char _slotValue_HTML_select1[] = "menu";
static char _slotValue_HTML_select2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"option\":\n\
		/* arg[1]	select value\n\
		 * arg[2]	select label\n\
		 * arg[3]	checked?\n\
		 */\n\
		optVal[optCount] = arg[1];\n\
		optLabel[optCount] = compressSpaces(arg[2]);\n\
		if (arg[3] == 1) checkedItem = optCount + 1;\n\
		optCount++;\n\
		return;\n\
	break;\n\
	case \"pick\":\n\
		set(\"label\", optLabel[arg[1]]);\n\
		value = optLabel[arg[1]];\n\
		return;\n\
	break;\n\
	case 'i':\n\
		new = send(self(), \"clone\");\n\
		send(new, \"make\", tagID, defaultVal, \n\
			optVal, optLabel, optCount, checkedItem);\n\
		t = concat(\"\\\\o(\", new, \")\");\n\
\n\
		tagID = \"\";\n\
		defaultVal = \"\";\n\
		optVal = 0;\n\
		optLabel = 0;\n\
		optCount = 0;\n\
		checkedItem = 0;\n\
\n\
		return t;\n\
	break;\n\
	case \"make\":\n\
		tagID = arg[1];\n\
		defaultVal = arg[2];\n\
		optVal = arg[3];\n\
		optLabel = arg[4];\n\
		optCount = arg[5];\n\
		checkedItem = arg[6];\n\
\n\
		/* cheexy way to set width */\n\
		maxLength = 0;\n\
		for (i = 0; i < optCount; i++) {\n\
			/* 1== fontID for \"normal\"*/\n\
			n = textWidth(1, optLabel[i]);\n\
			if (n > maxLength) maxLength = n;\n\
		}\n\
	 	maxLength = maxLength + 33;\n\
		set(\"width\", maxLength);\n\
\n\
/*		tagPtr = STG_tagPtr(\"SELECT\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		if (form == 0) form = send(parent(), \"findForm\");\n\
		if (form == 0) {\n\
			print(\"HTML_select: can't find form. self=\",\n\
				self(), \"\\n\
\");\n\
		} else {\n\
			send(form, \"regInputer\", self());\n\
		}\n\
\n\
		if (checkedItem == 0) checkedItem = 1;\n\
\n\
		set(\"label\", optLabel[checkedItem - 1]);\n\
		value = optLabel[checkedItem - 1];\n\
\n\
		txt = \"\";\n\
		for (i = 0; i < optCount; i++) {\n\
			txt = concat(txt, \".{\", optLabel[i], \n\
				\"} {send(self(), \\\"pick\\\", \", i, \");}\\n\
\");\n\
		}\n\
		set(\"menuConfig\", txt);\n\
\n\
		return get(\"height\");\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"y\", arg[1] + 2);\n\
		set(\"width\", arg[2] - 10);\n\
		return height();\n\
	break;\n\
	case 'r':\n\
		set(\"width\", width() - 10);\n\
/*BUG.. somehow, right before this point, height is set to 1.\n\
		print(\"HTML_select: r height={\", get(\"height\"), \"}\\n\
\");\n\
*/\n\
		set(\"height\", 20);\n\
		return get(\"height\");\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"VALUE\":\n\
			defaultVal = arg[2];\n\
		break;\n\
		case \"ENVVAR\":\n\
			defaultVal = environVar(arg[2]);\n\
			/* attrlist ordering might make a difference */\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"value\":\n\
		return concat(HTTPEncodeURL(tagID), '=', HTTPEncodeURL(value));\n\
	break;\n\
	case \"reset\":\n\
		set(\"label\", optLabel[checkedItem - 1]);\n\
		value = optLabel[checkedItem - 1];\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_select3[] = "3";
static char _slotValue_HTML_select4[] = "normal";
static char _slotValue_HTML_select5[] = "100";
static char _slotValue_HTML_select6[] = "22";
static char _slotValue_HTML_select7[] = "22";
/* END OF FILE */

static SlotStruct objDesc_HTML_select[] = {
    {"name", _slotValue_HTML_select0},
    {"class", _slotValue_HTML_select1},
    {"script", _slotValue_HTML_select2},
    {"border", _slotValue_HTML_select3},
    {"font", _slotValue_HTML_select4},
    {"width", _slotValue_HTML_select5},
    {"height", _slotValue_HTML_select6},
    {"maxHeight", _slotValue_HTML_select7},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_sub0[] = "field";
static char _slotValue_HTML_sub1[] = "HTML_sub";
static char _slotValue_HTML_sub2[] = "\n\
/*\n\
print(\"HTML_sub: self=\", self(), \": \");\n\
for (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");\n\
print(\"^^^^^^^end\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (findPattern(parent(), \"box\") != -1 ||\n\
		    findPattern(parent(), \"math\") != -1) {\n\
			SGMLBuildDoc_setBuff(0);\n\
			if (isBlank(get(\"label\")) == 0) {\n\
				tok[tokCount] = 2;\n\
				data[tokCount] = get(\"label\");\n\
				tokCount++;\n\
			}\n\
			test3();\n\
			send(parent(), \"flush\");\n\
			send(parent(), \"tok\", 9/*S_SUB*/);\n\
/*\n\
			for (i = 0; i < tokCount; i++) {\n\
				print(\"sub_tok \", i, \":   type=\", tok[i], \n\
					\"  data={\", data[i], \"}\\n\
\");\n\
			}\n\
*/\n\
			for (i = 0; i < tokCount; i++) {\n\
				send(parent(), \"tok&data\", tok[i], data[i]);\n\
			}\n\
			send(parent(), \"tok\", 10/*E_SUB*/);\n\
			tokCount = 0;\n\
			return \"\";\n\
		} else {\n\
			pn = str(parent());\n\
			tt = compressSpaces(get(\"label\"));\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(1)\");\n\
		}\n\
	break;\n\
	case \"tok&data\":\n\
		/* arg[1]	token\n\
		 * arg[2]	data\n\
		 */\n\
		tok[tokCount] = arg[1];\n\
		data[tokCount] = arg[2];\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		/* arg[1]	data\n\
		 */\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = arg[1];\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"tok\":\n\
		/* arg[1]	token type\n\
		 */\n\
		tok[tokCount] = arg[1];\n\
		data[tokCount] = \"\";\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"over\":\n\
		tok[tokCount] = 4;\n\
		data[tokCount] = \"\";\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_sub[] = {
    {"class", _slotValue_HTML_sub0},
    {"name", _slotValue_HTML_sub1},
    {"script", _slotValue_HTML_sub2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_sup0[] = "field";
static char _slotValue_HTML_sup1[] = "HTML_sup";
static char _slotValue_HTML_sup2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (findPattern(parent(), \"box\") != -1 ||\n\
		    findPattern(parent(), \"math\") != -1) {\n\
			SGMLBuildDoc_setBuff(0);\n\
			if (isBlank(get(\"label\")) == 0) {\n\
				tok[tokCount] = 2;\n\
				data[tokCount] = get(\"label\");\n\
				tokCount++;\n\
			}\n\
			test3();\n\
			send(parent(), \"flush\");\n\
			send(parent(), \"tok\", 12/*S_SUP*/);\n\
/*			for (i = 0; i < tokCount; i++) {\n\
				print(\"sup_tok \", i, \":   type=\", tok[i], \n\
					\"  data={\", data[i], \"}\\n\
\");\n\
			}\n\
*/\n\
			for (i = 0; i < tokCount; i++) {\n\
				send(parent(), \"tok&data\", tok[i], data[i]);\n\
			}\n\
			send(parent(), \"tok\", 13/*E_SUP*/);\n\
			tokCount = 0;\n\
			return \"\";\n\
		} else {\n\
			pn = str(parent());\n\
			tt = compressSpaces(get(\"label\"));\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(1)\");\n\
		}\n\
	break;\n\
	case \"tok&data\":\n\
		/* arg[1]	token\n\
		 * arg[2]	data\n\
		 */\n\
		tok[tokCount] = arg[1];\n\
		data[tokCount] = arg[2];\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		/* arg[1]	data\n\
		 */\n\
		tok[tokCount] = 2;\n\
		data[tokCount] = arg[1];\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"tok\":\n\
		/* arg[1]	token type\n\
		 */\n\
		tok[tokCount] = arg[1];\n\
		data[tokCount] = \"\";\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"over\":\n\
		tok[tokCount] = 4;\n\
		data[tokCount] = \"\";\n\
		tokCount++;\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_sup[] = {
    {"class", _slotValue_HTML_sup0},
    {"name", _slotValue_HTML_sup1},
    {"script", _slotValue_HTML_sup2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_table0[] = "field";
static char _slotValue_HTML_table1[] = "HTML_table";
static char _slotValue_HTML_table2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		return -1;\n\
	break;\n\
	case \"D\":\n\
/*		tagPtr = STG_tagPtr(\"TABLE\");\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
		}\n\
*/\n\
		if (title) {\n\
			new = send(\"HTML_tableCap\", \"clone\");\n\
			objectListAppend_children(new);\n\
			h = send(new, \"make\", self(), title,\n\
					get(\"width\") - 2, titleAlign);\n\
			SGMLTableFormater(new, titleAtTopP);\n\
		} else {\n\
			SGMLTableFormater();\n\
		}\n\
		return get(\"height\");\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"TABLE\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		if (title) SGMLTableFormater(new, titleAtTopP);\n\
		else SGMLTableFormater();\n\
		vspan += set(\"height\", get(\"height\")) + style[1];\n\
		return vspan;\n\
	break;\n\
	case 'b':\n\
		return border;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"TABLE\");\n\
		vspan = style[0];\n\
\n\
		if (title) SGMLTableFormater(new, titleAtTopP);\n\
		else SGMLTableFormater();\n\
\n\
		set(\"height\", vspan + get(\"height\") + style[1]);\n\
		return get(\"height\");\n\
	break;\n\
	case \"inPreP\":\n\
		return 0;\n\
	break;\n\
	case \"reportTitle\":\n\
		title = arg[1];\n\
		titleAtTopP = arg[2];\n\
		titleAlign = arg[3];\n\
		return;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"BORDER\":\n\
			border = 1;\n\
			set(\"border\", 6);\n\
		break;\n\
		case \"COMPACT\":\n\
			compact = 1; 	/* NOT USED YET */\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + y();\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findForm\":\n\
	case \"findTop\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"BDColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_table[] = {
    {"class", _slotValue_HTML_table0},
    {"name", _slotValue_HTML_table1},
    {"script", _slotValue_HTML_table2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tableCap0[] = "txtLabel";
static char _slotValue_HTML_tableCap1[] = "HTML_tableCap";
static char _slotValue_HTML_tableCap2[] = "\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		cellType = 32; /* TABLE_CELL_TYPE_TCAP == 32 */\n\
\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[3]);\n\
		set(\"label\", arg[2]);\n\
		set(\"paneConfig\", arg[4]);\n\
		set(\"height\", 20);\n\
\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"expose\":\n\
		usual();\n\
		if (doneP == 0) {\n\
			render();\n\
			doneP = 1;\n\
		}\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		usual();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"BDColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
";
static char _slotValue_HTML_tableCap3[] = "100";
static char _slotValue_HTML_tableCap4[] = "30";
static char _slotValue_HTML_tableCap5[] = "bold";
static char _slotValue_HTML_tableCap6[] = "1";
static char _slotValue_HTML_tableCap7[] = "6";
/* END OF FILE */

static SlotStruct objDesc_HTML_tableCap[] = {
    {"class", _slotValue_HTML_tableCap0},
    {"name", _slotValue_HTML_tableCap1},
    {"script", _slotValue_HTML_tableCap2},
    {"width", _slotValue_HTML_tableCap3},
    {"height", _slotValue_HTML_tableCap4},
    {"font", _slotValue_HTML_tableCap5},
    {"format", _slotValue_HTML_tableCap6},
    {"border", _slotValue_HTML_tableCap7},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tableVPane0[] = "vpane";
static char _slotValue_HTML_tableVPane1[] = "HTML_tableVPane";
static char _slotValue_HTML_tableVPane2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		config();\n\
		return -1;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	children list\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"children\", arg[2]);\n\
		set(\"height\", arg[3]);\n\
		return 0;\n\
	break;\n\
	case \"clone\":\n\
		return clone(arg[1]);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_tableVPane[] = {
    {"class", _slotValue_HTML_tableVPane0},
    {"name", _slotValue_HTML_tableVPane1},
    {"script", _slotValue_HTML_tableVPane2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tb0[] = "field";
static char _slotValue_HTML_tb1[] = "HTML_tb";
static char _slotValue_HTML_tb2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		cellType = 4; /* TABLE_CELL_TYPE_TB == 4 */\n\
		set(\"y\", -10);	/* out of the way!!! */\n\
		return 1;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_tb[] = {
    {"class", _slotValue_HTML_tb0},
    {"name", _slotValue_HTML_tb1},
    {"script", _slotValue_HTML_tb2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tcap0[] = "field";
static char _slotValue_HTML_tcap1[] = "HTML_tcap";
static char _slotValue_HTML_tcap2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		text = get(\"label\");\n\
		if (align == 0) align = \"center\";\n\
		send(parent(), \"reportTitle\", text, topP, align);\n\
		return -1;\n\
	break;\n\
	case \"config\":\n\
	case \"R\":\n\
		return 0;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"TOP\":\n\
			topP = 1;\n\
		break;\n\
		case \"ALIGN\":\n\
			switch (arg[2]) {\n\
			case \"left\":\n\
				align = \"westToEast\";\n\
			break;\n\
			case \"right\":\n\
				align = \"eastToWest\";\n\
			break;\n\
			case \"top\":\n\
				align = \"northToSouth\";\n\
			break;\n\
			case \"bottom\":\n\
				align = \"southToNorth\";\n\
			break;\n\
			case \"center\":\n\
			default:\n\
				align = \"center\";\n\
			break;\n\
			}\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"AI\":\n\
		switch (arg[1]) {\n\
		case \"TOP\":\n\
			topP = 0;\n\
		break;\n\
		case \"ALIGN\":\n\
			align = \"center\";\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_tcap[] = {
    {"class", _slotValue_HTML_tcap0},
    {"name", _slotValue_HTML_tcap1},
    {"script", _slotValue_HTML_tcap2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_td0[] = "field";
static char _slotValue_HTML_td1[] = "HTML_td";
static char _slotValue_HTML_td2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		return;\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3],\n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
\n\
		cellType = 16; /* TABLE_CELL_TYPE_TD == 16 */\n\
		if (send(parent(), 'b')) set(\"border\", 6);\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"TD\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"TD\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"COLSPAN\":\n\
			colSpan = arg[2];\n\
		break;\n\
		case \"ROWSPAN\":\n\
			rowSpan = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) set(\"BDColor\", color);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_td[] = {
    {"class", _slotValue_HTML_td0},
    {"name", _slotValue_HTML_td1},
    {"script", _slotValue_HTML_td2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_textarea0[] = "HTML_textarea";
static char _slotValue_HTML_textarea1[] = "field";
static char _slotValue_HTML_textarea2[] = "\n\
/* must have no children obj since this obj is spec'ed as\n\
 * an inlined object in the HTML_style.c.\n\
 */\n\
/*\n\
print(\">>> HTML_textarea: self=\", self(), \": \");\n\
for (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");\n\
print(\"...end\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case 'i':\n\
		new = send(\"HTML__textarea\", \"clone\");\n\
		send(new, \"make\", tagID, get(\"label\"), objWidth, objHeight);\n\
		t = concat(\"\\\\o(\", new, \")\");\n\
\n\
		tagID = \"\";\n\
		objWidth = 300;\n\
		objHeight = 100;\n\
\n\
		return t;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"SIZE\":\n\
			i = findPattern(arg[2], ',');\n\
			if (i == -1) {\n\
				size_cols = int(arg[2]);\n\
				/* extra size to allow for scrollbar */\n\
				objWidth = size_cols * textWidth(0, \"n\") + 20;\n\
				objHeight = 100;\n\
			} else {\n\
				size_cols = int(nthChar(arg[2], 0, i-1));\n\
				objWidth = size_cols * textWidth(0, 'n');\n\
\n\
				defaultRows = int(nthChar(arg[2], i+1, 99));\n\
				objHeight = defaultRows * 15;\n\
\n\
/*				set(\"width\", objWidth);\n\
				set(\"height\", defaultRows * 15);\n\
*/\n\
			}\n\
/*\n\
print(\"TEXTAREA SET: objWidth=\", objWidth, \"\\n\
\");\n\
print(\"TEXTAREA SET: objHeight=\", objHeight, \"\\n\
\");\n\
*/\n\
		break;\n\
		case \"COL\":\n\
		case \"COLS\":\n\
			objWidth = (int(arg[2]) * textWidth(0, \"n\")) + 20;\n\
/*print(\"TEXTAREA SET: objWidth=\", objWidth, \"\\n\
\");\n\
*/\n\
		break;\n\
		case \"ROW\":\n\
		case \"ROWS\":\n\
/*print(\"TEXTAREA SET:----------\\n\
\");\n\
*/\n\
			objHeight = int(arg[2]) * 15; /*iffy*/\n\
/*\n\
print(\"TEXTAREA SET: arg[2]=\", arg[2], \"\\n\
\");\n\
print(\"TEXTAREA SET: objHeight=\", objHeight, \"\\n\
\");\n\
*/\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"y\", arg[1]);\n\
		set(\"width\", arg[2] - 2);\n\
		config();\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case 'r':/* BROKEN */\n\
		set(\"width\", width() - 10);\n\
		set(\"content\", get(\"content\"));\n\
		h = building_vspan();\n\
		if (h < heightByRows) h = heightByRows;\n\
		vspan += set(\"height\", h) + style[1];\n\
		render();\n\
		return vspan + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	tagID\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*\n\
print(\"TEXTAREA MAKE: arg width=\", arg[3], \"\\n\
\");\n\
print(\"TEXTAREA MAKE: arg height=\", arg[4], \"\\n\
\");\n\
*/\n\
		tagID = arg[1];\n\
		defaultVal = arg[2];\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
		config();\n\
\n\
		send(nthChild(0), \"make\", arg[2]);\n\
\n\
		if (form == 0) form = send(parent(), \"findForm\");\n\
		if (form == 0) {\n\
			print(\"HTML_select: can't find form. self=\",\n\
				self(), \"\\n\
\");\n\
		} else {\n\
			send(form, \"regInputer\", self());\n\
		}\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"value\":\n\
		return concat(HTTPEncodeURL(tagID), \"=\",\n\
				HTTPEncodeURL(send(nthChild(0), \"value\")));\n\
	break;\n\
	case \"reset\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		objWidth = 300;\n\
		objHeight = 150;\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_HTML_textarea4[] = "HTML__textarea";
static char _slotValue_HTML_textarea5[] = "HTML__textarea.tf HTML__textarea.sb";
static char _slotValue_HTML_textarea6[] = "hpane";
static char _slotValue_HTML_textarea7[] = "\n\
/*\n\
print(\">>> HTML__textarea: self=\", self(), \": \");\n\
for (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");\n\
print(\"...end\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	height\n\
		 */\n\
		set(\"y\", arg[1]);\n\
		set(\"width\", arg[2] - 2);\n\
		config();\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case 'r':/* BROKEN */\n\
		set(\"width\", width() - 10);\n\
		set(\"content\", get(\"content\"));\n\
		h = building_vspan();\n\
		if (h < heightByRows) h = heightByRows;\n\
		vspan += set(\"height\", h) + style[1];\n\
		render();\n\
		return vspan + 2;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	tagID\n\
		 * arg[2]	defaultValue\n\
		 * arg[3]	width\n\
		 * arg[4]	height\n\
		 */\n\
/*		set(\"parent\", arg[1]);*/\n\
\n\
		tagID = arg[1];\n\
		defaultVal = arg[2];\n\
		set(\"width\", arg[3]);\n\
		set(\"height\", arg[4]);\n\
\n\
		config();\n\
\n\
		send(nthChild(0), \"make\", arg[2]);\n\
\n\
		if (form == 0) form = send(parent(), \"findForm\");\n\
		if (form == 0) {\n\
			print(\"HTML_select: can't find form. self=\",\n\
				self(), \"\\n\
\");\n\
		} else {\n\
			send(form, \"regInputer\", self());\n\
		}\n\
		return get(\"height\") + 2;\n\
	break;\n\
	case \"value\":\n\
		return concat(HTTPEncodeURL(tagID), \"=\",\n\
				HTTPEncodeURL(send(nthChild(0), \"value\")));\n\
	break;\n\
	case \"reset\":\n\
		return send(nthChild(0), arg[0]);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		objWidth = 300;\n\
		objHeight = 150;\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_textarea8[] = "300";
static char _slotValue_HTML_textarea9[] = "150";
/* END OF OBJ */

static char _slotValue_HTML_textarea11[] = "txtEdit";
static char _slotValue_HTML_textarea12[] = "HTML__textarea";
static char _slotValue_HTML_textarea13[] = "HTML__textarea.tf";
static char _slotValue_HTML_textarea14[] = "HTML__textarea.sb";
static char _slotValue_HTML_textarea15[] = "\n\
/*\n\
print(\">>>> HTML_textarea.tf: self=\", self(), \": \");\n\
for (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\
\");print(\"...end\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"make\":\n\
		/* arg[1]	defaultVal\n\
		 */\n\
		defaultVal = arg[1];\n\
		if (defaultVal != 0) set(\"content\", defaultVal);\n\
		else set(\"content\", \"\");\n\
\n\
		eventMask(\"+enterWindow +leaveWindow\");\n\
		return;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"TEXTAREA\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		h = building_vspan();\n\
		if (h < heightByRows) h = heightByRows;\n\
		vspan += set(\"height\", h) + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"value\":\n\
		return get(\"content\");\n\
	break;\n\
	case \"reset\":\n\
		set(\"content\", defaultVal);\n\
		clearWindow();\n\
		render();\n\
		return;\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<TEXTAREA\");\n\
		if (tagID) print(\" NAME=\\\"\", tagID, \"\\\"\");\n\
		if (type) print(\" TYPE=\\\"\", inputType, \"\\\"\");\n\
		if (checked) print(\" CHECKED\");\n\
		if (get(\"maxWidth\") < 9999) \n\
			print(\" MAXWIDTH=\", get(\"maxWidth\"));\n\
		if (get(\"minWidth\") < 9999) \n\
			print(\" MINWIDTH=\", get(\"minWidth\"));\n\
		print(\">\", get(\"content\"), \"<TEXTAREA>\\n\
\");\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_textarea16[] = "fixed";
static char _slotValue_HTML_textarea17[] = "1";
/* END OF OBJ */

static char _slotValue_HTML_textarea19[] = "HTML__textarea.sb";
static char _slotValue_HTML_textarea20[] = "HTML__textarea";
static char _slotValue_HTML_textarea21[] = "slider";
static char _slotValue_HTML_textarea22[] = "15";
static char _slotValue_HTML_textarea23[] = "HTML__textarea.tf";
/* END OF FILE */

static SlotStruct objDesc_HTML_textarea[] = {
    {"name", _slotValue_HTML_textarea0},
    {"class", _slotValue_HTML_textarea1},
    {"script", _slotValue_HTML_textarea2},
    {(char*)0, (char*)1},
    {"name", _slotValue_HTML_textarea4},
    {"children", _slotValue_HTML_textarea5},
    {"class", _slotValue_HTML_textarea6},
    {"script", _slotValue_HTML_textarea7},
    {"width", _slotValue_HTML_textarea8},
    {"height", _slotValue_HTML_textarea9},
    {(char*)0, (char*)1},
    {"class", _slotValue_HTML_textarea11},
    {"parent", _slotValue_HTML_textarea12},
    {"name", _slotValue_HTML_textarea13},
    {"shownDepend", _slotValue_HTML_textarea14},
    {"script", _slotValue_HTML_textarea15},
    {"font", _slotValue_HTML_textarea16},
    {"verbatim", _slotValue_HTML_textarea17},
    {(char*)0, (char*)1},
    {"name", _slotValue_HTML_textarea19},
    {"parent", _slotValue_HTML_textarea20},
    {"class", _slotValue_HTML_textarea21},
    {"maxWidth", _slotValue_HTML_textarea22},
    {"shownNotify", _slotValue_HTML_textarea23},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_th0[] = "field";
static char _slotValue_HTML_th1[] = "HTML_th";
static char _slotValue_HTML_th2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		return;\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor, \n\
				paneConfig);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3],\n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor, \n\
				paneConfig);\n\
			makeAnchor = 0;\n\
		}\n\
\n\
		cellType = 8; /* TABLE_CELL_TYPE_TH == 8 */\n\
		if (send(parent(), 'b')) set(\"border\", 6);\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"TH\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"TH\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"ALIGN\":\n\
			switch (arg[2]) {\n\
			case \"center\":\n\
				paneConfig = \"center\";\n\
			break;\n\
			case \"left\":\n\
				paneConfig = \"westToEast\";\n\
			break;\n\
			case \"right\":\n\
				paneConfig = \"eastToWest\";\n\
			break;\n\
			case \"top\":\n\
				paneConfig = \"northToSouth\";\n\
			break;\n\
			case \"bottom\":\n\
				paneConfig = \"southToNorth\";\n\
			break;\n\
			}\n\
		break;\n\
		case \"COLSPAN\":\n\
			colSpan = arg[2];\n\
		break;\n\
		case \"ROWSPAN\":\n\
			rowSpan = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"findForm\":\n\
		return send(parent(), \"findForm\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		color = getResource(\"Viola.background_doc\");\n\
		if (color) set(\"BGColor\", color);\n\
		color = getResource(\"Viola.foreground_doc\");\n\
		if (color) {\n\
			set(\"FGColor\", color);\n\
			set(\"BDColor\", color);\n\
		}\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_th[] = {
    {"class", _slotValue_HTML_th0},
    {"name", _slotValue_HTML_th1},
    {"script", _slotValue_HTML_th2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_title0[] = "field";
static char _slotValue_HTML_title1[] = "HTML_title";
static char _slotValue_HTML_title2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		text = get(\"label\");\n\
		send(send(parent(), \"findTop\"), \"reportTitle\", text);\n\
		return -1;\n\
	break;\n\
	case 'R':\n\
		return 1;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_title[] = {
    {"class", _slotValue_HTML_title0},
    {"name", _slotValue_HTML_title1},
    {"script", _slotValue_HTML_title2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tr0[] = "field";
static char _slotValue_HTML_tr1[] = "HTML_tr";
static char _slotValue_HTML_tr2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		cellType = 2; /* TABLE_CELL_TYPE_TR == 2 */\n\
		set(\"y\", -10);	/* out of the way!!! */\n\
		return 1;\n\
	break;\n\
	case \"R\":\n\
	case \"r\":\n\
		return 1;\n\
	break;\n\
	case \"config\":\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_tr[] = {
    {"class", _slotValue_HTML_tr0},
    {"name", _slotValue_HTML_tr1},
    {"script", _slotValue_HTML_tr2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txt0[] = "txtDisp";
static char _slotValue_HTML_txt1[] = "HTML_txt";
static char _slotValue_HTML_txt2[] = "\n\
/*\n\
print(\"HTML_txt: self=\", self(), \"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\\n\
\");\n\
for(i=0;i<arg[];i++) print(\"arg[\",i,\"]={\",arg[i],\"}\\n\
\");\n\
print(\"HTML_txt: editMode=\", editMode, \"\\n\
\");\n\
print(\"HTML_txt: lock=\", lock, \"\\n\
\");\n\
*/\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
		return expose();\n\
	break;\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"inPreP\":\n\
		return 0;\n\
	break;\n\
	case \"fitIn?\":\n\
		/* arg[1]	x\n\
		 * arg[2]	y\n\
		 */\n\
		x = arg[1];\n\
		y = arg[2];\n\
	break;\n\
	case \"runAwayFromHome\":\n\
		return send(parent(), \"deleteChild\", self());\n\
	break;\n\
	case \"buttonPress\":\n\
		if (editMode) {\n\
		  mxy = mouseLocal();\n\
		  if (mxy[0] < 10) {\n\
			print(\"HTML_txt: GRAB\\n\
\");\n\
			my = mxy[1];\n\
			if (my < (height() / 2)) side = 0;\n\
			else side = 1;\n\
			if (top == 0) top = send(parent(), \"findTop\");\n\
			send(top, \"wedgeMeIn\", self(), side);\n\
			return;\n\
		  } else {\n\
			if (top == 0) top = send(parent(), \"findTop\");\n\
			plid = send(parent(), \"placeID\", self(), \"\");\n\
			send(top, \"lock\", self(), plid);\n\
			if (lock == 1) {\n\
				/* unlock */\n\
				set(\"BGColor\", bgcolor);\n\
				render();\n\
				set(\"cursor\", 0);\n\
				lock = 0;\n\
				return;\n\
			} else {\n\
				/* lock */\n\
				bgcolor = get(\"BGColor\");\n\
				set(\"BGColor\", \"yellow\");\n\
				render();\n\
				set(\"cursor\", 1);\n\
				lock = 1;\n\
			}\n\
		  }\n\
		}\n\
	break;\n\
	case \"edit_focus\":\n\
		wxy = windowPosition();\n\
		setMouse(wxy[0] + 2, wxy[1] + 2);\n\
		return;\n\
	break;\n\
	case \"keyPress\":\n\
		if (editMode) {\n\
			c = key();\n\
			if (c == '\\r') {\n\
				insert(key());\n\
				set(\"content\", get(\"content\"));\n\
				h = building_vspan();\n\
				print(\"BUILDING_VSPAN=\", h, \"\\n\
\");\n\
				set(\"height\", h);\n\
				if (top == 0) top = send(parent(), \"findTop\");\n\
				send(top, \"resizeSelf\");\n\
				plid = send(parent(), \"placeID\", self(), \"\");\n\
\n\
				newTxt = get(\"content\");\n\
				set(\"content\", newTxt);\n\
\n\
				send(top, \"change\", self(), plid, newTxt);\n\
			} else if (c == '\	') {\n\
				if (shiftKeyP()) {\n\
					send(parent(), \"edit_gotoPrev\", \n\
						self());\n\
				} else {\n\
					send(parent(), \"edit_gotoNext\", \n\
						self());\n\
				}\n\
				/*\n\
				send(parent(),\n\
					either (shiftKeyP())\n\
						{\"edit_gotoPrev\"}\n\
						{\"edit_gotoNext\"},\n\
					self());\n\
				*/\n\
			} else {\n\
				insert(key());\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"CE_change\":\n\
		newData = arg[2];\n\
		set(\"content\", newData);\n\
		h = building_vspan();\n\
		print(\"RE_BUILDING_VSPAN=\", h, \"\\n\
\");\n\
		set(\"height\", h);\n\
		if (top == 0) top = send(parent(), \"findTop\");\n\
		send(top, \"resizeSelf\");\n\
		return;\n\
	break;\n\
	case \"CE_lock\":\n\
		if (lock == 0) {\n\
			set(\"BGColor\", \"red\");\n\
			render();\n\
		}\n\
		return;		\n\
	break;\n\
	case \"CE_unlock\":\n\
		if (lock == 0) {\n\
			set(\"BGColor\", bgcolor);\n\
			render();\n\
		}\n\
		return;		\n\
	break;\n\
	case \"enter\":\n\
		if (editMode && lock) {\n\
			set(\"cursor\", 1);\n\
		}\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		if (editMode && lock) {\n\
			set(\"cursor\", 0);\n\
/*\n\
			set(\"BDColor\", get(\"BGColor\"));\n\
			set(\"cursor\", 0);\n\
			if (lock == 1) {\n\
				if (top == 0) top = send(parent(), \"findTop\");\n\
				plid = send(parent(), \"placeID\", self(), \"\");\n\
				send(top, \"unlock\", self(), plid);\n\
				lock = 0;\n\
			}\n\
*/\n\
		} else {\n\
			prevHint = 0;\n\
			www.mesg.tf(\"clear\");\n\
		}\n\
		return;\n\
	break;\n\
	case \"D\": /* done */\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(parent(), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		SGMLBuildDoc_setBuff(0);/* necessary ...*/\n\
\n\
		if (isBlank(get(\"label\"))) {\n\
			/*XXXXX there is something... \\o's..\n\
			 *	Question: how to determine height?\n\
			 */\n\
			if (nthChild(0)) return 20;\n\
\n\
			/* no text in this para object. But, there might\n\
			 * be an inlined object containing other objects...\n\
			 * Ie: <P><A><H2>Hozer markup</H2></A>\n\
			 */\n\
/*\n\
			vspan = 0;\n\
			if (nthChild(0)) {\n\
print(\"TXT: has child!:\", nthChild(0), \"\\n\
\");\n\
				n = countChildren();\n\
print(\"TXT: n=\", n, \"\\n\
\");\n\
				xx = get(\"width\");\n\
				for (i = 0; i < n; i++) {\n\
				  vspan += send(nthChild(i), \"R\", vspan, xx);\n\
				}\n\
print(\"TXT: vspan=\", vspan, \"................................\\n\
\");\n\
				set(\"height\", vspan+10);\n\
\n\
print(\"TXT: height=\", get(\"height\"), \"................................\\n\
\");\n\
				return (vspan + 10);\n\
			}\n\
			return 0;\n\
*/\n\
		}\n\
\n\
		send(self(), \"setStyles\", parent());\n\
\n\
		if (deco) {\n\
			box = send(deco, \"clone\");\n\
			objectListAppend_children(box);\n\
			if (inPreP) \n\
			  h = send(box, \"make\", self(), \n\
				   get(\"label\"), get(\"width\"));\n\
			else \n\
			  h = send(box, \"make\", self(), \n\
				   trimEdgeQ(get(\"label\")), get(\"width\"));\n\
			return h + 2;\n\
			/* +2 for hot-link-indicator border around IMGs */\n\
		} else {\n\
			if (inPreP) {\n\
				set(\"format\", 0);\n\
				set(\"font\", \"fixed\");\n\
				set(\"_font\", 0);\n\
				set(\"content\", get(\"label\"));\n\
			} else {\n\
				set(\"content\", trimEdgeQ(get(\"label\")));\n\
			}\n\
			set(\"label\", \"\");\n\
			isHTML = 1;\n\
			return building_vspan()+2;\n\
			/* +2 for hot-link-indicator border around IMGs */\n\
		}\n\
	break;\n\
	case \"F\": /* flush */\n\
		return 1;\n\
	break;\n\
	case \"R\": /* resize */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		w = arg[2] - get(\"x\") - style[3];\n\
		set(\"width\", w);\n\
		if (deco) {\n\
			h = send(nthChild(0), \"R\", w);\n\
			set(\"height\", h);\n\
			return h + style[1];\n\
		} else {\n\
			/* check to see if this Para object has children\n\
			 * objects. This can happen, ie, with this markup\n\
			 * <P><A><H2>foo</H2>\n\
			 */\n\
/*			if (nthChild(0)) {\n\
				n = countChildren();\n\
				xx = get(\"width\");\n\
				for (i = 0; i < n; i++)\n\
				  vspan += send(nthChild(i), \"R\", vspan, xx);\n\
				set(\"height\", vspan+1);\n\
				return vspan+1;\n\
			} \n\
*/\n\
/*print(\"HTML_txt R: label={\",get(\"content\"), \"}\\n\
\");*/\n\
				set(\"content\", get(\"content\"));\n\
				clearWindow();\n\
				vspan += set(\"height\", building_vspan()+2)\n\
					 + style[1];\n\
				/* +2 for hot-link-indicator border around IMGs */\n\
				render();\n\
				return vspan;\n\
		}\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
		vspan = style[0];\n\
		set(\"width\", get(\"width\") - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		clearWindow();\n\
		render();\n\
		vspan += set(\"height\", building_vspan()) + style[1];\n\
		return vspan;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagIDs[tagIDCount] = arg[2];\n\
			tagIDCount++;\n\
		break;\n\
		case \"STYLE\":\n\
			switch (arg[2]) {\n\
			case \"NOTE\":\n\
				deco = \"HTML__txtBox_note\";\n\
			break;\n\
			case \"CAUTION\":\n\
				deco = \"HTML__txtBox_caution\";\n\
			break;\n\
			case \"WARNING\":\n\
				set(\"BDColor\", \"darkOrange\");\n\
				deco = \"HTML__txtBox_caution\";\n\
			break;\n\
			case \"ERROR\":\n\
				set(\"BDColor\", \"red\");\n\
				deco = \"HTML__txtBox_error\";\n\
			break;\n\
			case \"TIMED\": /*just for fun*/\n\
				deco = \"HTML__txtBox_time\";\n\
			break;\n\
			case \"QUOTE\":\n\
			case \"MARGIN\":\n\
			case \"NORMAL\":\n\
			default:\n\
			break;\n\
			}\n\
		break;\n\
		case \"ALIGN\":\n\
			switch (arg[2]) {\n\
			case \"center\":\n\
				set(\"paneConfig\", \"center\");\n\
			break;\n\
			case \"left\":\n\
				set(\"paneConfig\", \"westToEast\");\n\
			break;\n\
			case \"right\":\n\
				set(\"paneConfig\", \"eastToWest\");\n\
			break;\n\
			}\n\
		break;\n\
		case \"COMPACT\":\n\
			compact = 1; 	/* NOT USED YET */\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"make\":\n\
		send(self(), \"setStyles\", arg[1]);\n\
\n\
		tagIDs[tagIDCount] = arg[6];\n\
		tagIDCount++;\n\
\n\
		if (useTagInfo_align)\n\
			if (arg[] > 7) set(\"paneConfig\", arg[7]);\n\
\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	case \"setStyles\":\n\
		useTagInfo_align = 1;\n\
\n\
		if (findPattern(arg[1], \"address\") != -1) {\n\
			/*tagPtr = send(arg[1], \"styleSheet\");*/\n\
			tagPtr = STG_tagPtr(\"P\", \"ADDRESS\");\n\
		} else {\n\
			tagPtr = STG_tagPtr(\"P\");\n\
		}\n\
		if (tagPtr) {\n\
			i = STG_attr(tagPtr, \"BGColor\");\n\
			if (i) set(\"BGColor\", i);\n\
			i = STG_attr(tagPtr, \"FGColor\");\n\
			if (i) set(\"FGColor\", i);\n\
			i = STG_attr(tagPtr, \"BDColor\");\n\
			if (i) set(\"BDColor\", i);\n\
			i = STG_attr(tagPtr, \"fontSlant\");\n\
			if (i) {\n\
				switch (i) {\n\
				case \"italic\": 	set(\"font\", i);	break;\n\
				case \"bold\": 	set(\"font\", i);	break;\n\
				default:\n\
				case \"normal\":	set(\"font\", i);	break;\n\
				}\n\
			}\n\
			i = STG_attr(tagPtr, \"align\");\n\
			if (i) {\n\
				useTagInfo_align = 0;\n\
				switch (i) {\n\
				case \"center\":\n\
					set(\"paneConfig\", \"center\");\n\
				break;\n\
				case \"left\":\n\
					set(\"paneConfig\", \"westToEast\");\n\
				break;\n\
				case \"right\":\n\
					set(\"paneConfig\", \"eastToWest\");\n\
				break;\n\
				}\n\
			}\n\
			i = STG_attr(tagPtr, \"blink\");\n\
			if (i) {\n\
				blinkRate = i;\n\
				fgc = get(\"FGColor\");\n\
				bclr0 = STG_attr(tagPtr, \"blinkColorOn\");\n\
				bclr1 = STG_attr(tagPtr, \"blinkColorOff\");\n\
				after(i, self(), \"blink\");\n\
			}\n\
		}\n\
		return;\n\
	break;\n\
	case \"blink\":\n\
		if (blinkOn) {\n\
			blinkOn = 0;\n\
			set(\"FGColor\", bclr1);\n\
		} else {\n\
			set(\"FGColor\", bclr0);\n\
			blinkOn = 1;\n\
		}\n\
		render();\n\
		after(blinkRate, self(), \"blink\");\n\
		return;\n\
	break;\n\
	case \"itemN\":\n\
		/*??? it happens. Just here to quiet it*/\n\
		return;\n\
	break;\n\
	case \"setAnchor\":\n\
		tagIDs[tagIDCount] = arg[1];\n\
		tagIDCount++;\n\
/*		for (i = 0; i < tagIDCount; i++)\n\
			print(\"######\", tagIDs[i], \"\\n\
\");\n\
*/\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagIDCount > 0)\n\
			for (i = 0; i < tagIDCount; i++)\n\
				if (tagIDs[i] == arg[1]) return get(\"y\");\n\
		return 0;\n\
	break;\n\
	case \"editMode\":\n\
		editMode = arg[1];\n\
		return;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"config\":\n\
		/* let 'R' do the resizing */\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<P>\", get(\"content\"), \"\\n\
\");\n\
/*\n\
		n = anchor....\n\
		if (n) {\n\
			for (i = 0; i < n; i++)\n\
				send(nthChild(i), \"outputSGML\");\n\
		}\n\
*/\n\
		print(\"</P>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	return code_HTML_txt(arg);\n\
";
static char _slotValue_HTML_txt3[] = "-99";
static char _slotValue_HTML_txt4[] = "100";
static char _slotValue_HTML_txt5[] = "8";
static char _slotValue_HTML_txt6[] = "normal";
static char _slotValue_HTML_txt7[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_txt[] = {
    {"class", _slotValue_HTML_txt0},
    {"name", _slotValue_HTML_txt1},
    {"script", _slotValue_HTML_txt2},
    {"y", _slotValue_HTML_txt3},
    {"width", _slotValue_HTML_txt4},
    {"height", _slotValue_HTML_txt5},
    {"font", _slotValue_HTML_txt6},
    {"format", _slotValue_HTML_txt7},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtAnchor0[] = "field";
static char _slotValue_HTML_txtAnchor1[] = "HTML_txtAnchor";
static char _slotValue_HTML_txtAnchor2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (tagID) {\n\
			send(parent(), \"setAnchor\", tagID);\n\
			tagID = 0;\n\
		}\n\
		if (nthChild(0)) {\n\
			return concat(\"\\\\o(\", self(), \")\");\n\
		} else {\n\
			if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
			else tt = compressSpaces(get(\"label\"));\n\
\n\
			if (url) {\n\
				t = concat(\"\\\\b(\", tt,\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
				url = 0;\n\
				return t;\n\
			} else {\n\
				return tt;\n\
			}\n\
		}\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"HREF\":\n\
			url = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = send(\"HTML_txt\", \"clone\");\n\
			objectListAppend_children(txtObj);\n\
\n\
			if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
			else tt = compressSpaces(get(\"label\"));\n\
\n\
			h = send(txtObj, \"make\", self(),\n\
				tt, style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		set(\"content2\", self());/*a kludge to deal with cloning*/\n\
		h = get(\"height\");\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = send(\"HTML_txt\", \"clone\");\n\
			objectListAppend_children(txtObj);\n\
\n\
			if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
			else tt = compressSpaces(get(\"label\"));\n\
\n\
			h += send(txtObj, \"make\", self(),\n\
				tt, style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		vspan = 1;\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
			  vspan += send(nthChild(i), \"R\", vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		return vspan;\n\
	break;\n\
	case \"copyObj\":\n\
		url = send(arg[1], \"url\");\n\
		return 0;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"inAnchor\":\n\
/* trouble is, once txtAnchor is copied, 'url' and other info in variables\n\
are lost. Solution send message to this object to have itself copied\n\
(including the appropriate variables).\n\
*/\n\
		return url;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"url\":\n\
		/* for <img ismap...> to ask */\n\
		return url;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtAnchor[] = {
    {"class", _slotValue_HTML_txtAnchor0},
    {"name", _slotValue_HTML_txtAnchor1},
    {"script", _slotValue_HTML_txtAnchor2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtBold0[] = "field";
static char _slotValue_HTML_txtBold1[] = "HTML_txtBold";
static char _slotValue_HTML_txtBold2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		/*XXX this is so so sincerely cheezy */\n\
		if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
		else tt = compressSpaces(get(\"label\"));\n\
\n\
		pn = str(parent());\n\
		if (findPattern(pn, \"pre\") != -1) {\n\
			return concat(\"\\\\f(4)\", tt, \"\\\\f(0)\");\n\
		} else if (findPattern(pn, \"example\") != -1) {\n\
			return concat(\"\\\\f(4)\", tt, \"\\\\f(0)\");\n\
		} else if (findPattern(pn, \"header_medium\") != -1) {\n\
			return concat(\"\\\\f(5)\", tt, \"\\\\f(2)\");\n\
		} else {\n\
			return concat(\"\\\\f(4)\", tt, \"\\\\f(1)\");\n\
		}\n\
	break;\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case \"inPreP\":\n\
		return send(get(\"parent\"), \"inPreP\");\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtBold[] = {
    {"class", _slotValue_HTML_txtBold0},
    {"name", _slotValue_HTML_txtBold1},
    {"script", _slotValue_HTML_txtBold2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtBullet0[] = "field";
static char _slotValue_HTML_txtBullet1[] = "HTML_txtBullet";
static char _slotValue_HTML_txtBullet2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return 0;\n\
	break;\n\
	case 'i':\n\
		return concat(\"\\\\f(0)*\\\\f(1)\", compressSpaces(get(\"label\")));\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtBullet[] = {
    {"class", _slotValue_HTML_txtBullet0},
    {"name", _slotValue_HTML_txtBullet1},
    {"script", _slotValue_HTML_txtBullet2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtCommand0[] = "field";
static char _slotValue_HTML_txtCommand1[] = "HTML_txtCommand";
static char _slotValue_HTML_txtCommand2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
		else tt = compressSpaces(get(\"label\"));\n\
		return concat(\"\\\\f(0)\", tt, \"\\\\f(1)\");\n\
	break;\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtCommand[] = {
    {"class", _slotValue_HTML_txtCommand0},
    {"name", _slotValue_HTML_txtCommand1},
    {"script", _slotValue_HTML_txtCommand2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtDD0[] = "field";
static char _slotValue_HTML_txtDD1[] = "HTML_txtDD";
static char _slotValue_HTML_txtDD2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			if (url = send(parent(), \"inAnchor\"))\n\
				txt = concat(\"\\\\b(\", \n\
					compressSpaces(get(\"label\")),\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
			else\n\
				txt = compressSpaces(get(\"label\"));\n\
			h = send(txtObj, \"make\", self(),\n\
				txt, style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			if (url = send(parent(), \"inAnchor\"))\n\
				txt = concat(\"\\\\b(\", \n\
					compressSpaces(get(\"label\")),\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
			else\n\
				txt = compressSpaces(get(\"label\"));\n\
			h += send(txtObj, \"make\", self(),\n\
				txt, style_p[3],\n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"DD\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"setAnchor\":\n\
		makeAnchor = arg[1];\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return get(\"y\");\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtDD[] = {
    {"class", _slotValue_HTML_txtDD0},
    {"name", _slotValue_HTML_txtDD1},
    {"script", _slotValue_HTML_txtDD2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtDT0[] = "field";
static char _slotValue_HTML_txtDT1[] = "HTML_txtDT";
static char _slotValue_HTML_txtDT2[] = "\n\
	switch (arg[0]) {\n\
	case \"F\":\n\
		h = 0;\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			if (url = send(parent(), \"inAnchor\"))\n\
				txt = concat(\"\\\\b(\", \n\
					compressSpaces(get(\"label\")),\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
			else\n\
				txt = compressSpaces(get(\"label\"));\n\
			h = send(txtObj, \"make\", self(),\n\
				txt, style_p[3],\n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			if (url = send(parent(), \"inAnchor\"))\n\
				txt = concat(\"\\\\b(\", \n\
					compressSpaces(get(\"label\")),\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
			else\n\
				txt = compressSpaces(get(\"label\"));\n\
			h += send(txtObj, \"make\", self(),\n\
				txt, style_p[3],\n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"DT\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - get(\"x\") - style[3]);\n\
\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\
		vspan = style[0];\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
				vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"heightP\":\n\
		return get(\"height\");\n\
	break;\n\
	case \"widthP\":\n\
		return get(\"width\");\n\
	break;\n\
	case \"AI\":\n\
	case \"noBullet\":\n\
		return;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"ID\":\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"data\":\n\
		SGMLBuildDoc_setBuff(-1);\n\
		return compressSpaces(get(\"label\"));\n\
	break;\n\
	case \"setAnchor\":\n\
		makeAnchor = arg[1];\n\
		return;\n\
	break;\n\
	case \"searchAnchor\":\n\
		if (tagID == arg[1]) return self();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		if (tagID == arg[1]) return y();\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				offset = send(nthChild(i), \n\
						\"gotoAnchor\", arg[1]);\n\
				if (offset > 0) return offset + get(\"y\");\n\
			}\n\
		}\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtDT[] = {
    {"class", _slotValue_HTML_txtDT0},
    {"name", _slotValue_HTML_txtDT1},
    {"script", _slotValue_HTML_txtDT2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtEmphasis0[] = "field";
static char _slotValue_HTML_txtEmphasis1[] = "HTML_txtEmphasis";
static char _slotValue_HTML_txtEmphasis2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		/*XXX this is so so cheezy-- stop gap solution */\n\
		if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
		else tt = compressSpaces(get(\"label\"));\n\
		pn = str(parent());\n\
		if (findPattern(pn, \"pre\") != -1) {\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(0)\");\n\
		} else if (findPattern(pn, \"example\") != -1) {\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(0)\");\n\
		} else if (findPattern(pn, \"header_big\") != -1) {\n\
			return concat(\"\\\\f(9)\", tt, \"\\\\f(6)\");\n\
		} else if (findPattern(pn, \"header_medium\") != -1) {\n\
			return concat(\"\\\\f(8)\", tt, \"\\\\f(5)\");\n\
		} else if (findPattern(pn, \"header_small\") != -1) {\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(4)\");\n\
		} else {\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(1)\");\n\
		}\n\
	break;\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"AA\":\n\
		/* need to handle arg[1]=TT arg[2]=tt, \n\
		 * arg[1]=B arg[2]=b\n\
		 */\n\
		return;\n\
	break;\n\
	case \"R\":\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtEmphasis[] = {
    {"class", _slotValue_HTML_txtEmphasis0},
    {"name", _slotValue_HTML_txtEmphasis1},
    {"script", _slotValue_HTML_txtEmphasis2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtItalic0[] = "field";
static char _slotValue_HTML_txtItalic1[] = "HTML_txtItalic";
static char _slotValue_HTML_txtItalic2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		/*XXX this is so so cheezy-- stop gap solution */\n\
		if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
		else tt = compressSpaces(get(\"label\"));\n\
\n\
		pn = str(parent());\n\
		if (findPattern(pn, \"pre\") != -1) {\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(0)\");\n\
		} else if (findPattern(pn, \"example\") != -1) {\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(0)\");\n\
		} else if (findPattern(pn, \"header_big\") != -1) {\n\
			return concat(\"\\\\f(9)\", tt, \"\\\\f(6)\");\n\
		} else if (findPattern(pn, \"header_medium\") != -1) {\n\
			return concat(\"\\\\f(8)\", tt, \"\\\\f(5)\");\n\
		} else if (findPattern(pn, \"header_small\") != -1) {\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(4)\");\n\
		} else {\n\
			return concat(\"\\\\f(7)\", tt, \"\\\\f(1)\");\n\
		}\n\
	break;\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case \"inPreP\":\n\
		if (doneSetInPreP == 0) {\n\
			inPreP = send(get(\"parent\"), \"inPreP\");\n\
			doneSetInPreP = 1;\n\
		}\n\
		return inPreP;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"configSelf\":\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtItalic[] = {
    {"class", _slotValue_HTML_txtItalic0},
    {"name", _slotValue_HTML_txtItalic1},
    {"script", _slotValue_HTML_txtItalic2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtList0[] = "XBM";
static char _slotValue_HTML_txtList1[] = "HTML_txtList";
static char _slotValue_HTML_txtList2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		listItemObj = HTML_txtListItem(\"clone\", self());\n\
		h = send(listItemObj, \"make\", self(), 20, get(\"width\") - 20);\n\
		set(\"children\", listItemObj);\n\
		return h;\n\
	break;\n\
	case \"searchAnchor\":\n\
		n = countChildren();\n\
		if (n > 0) {\n\
			for (i = 0; i < n; i++) {\n\
				anchor = send(nthChild(i), \n\
						\"searchAnchor\", arg[1]);\n\
				if (anchor != \"\") return anchor;\n\
			}\n\
		}\n\
		return \"\";\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return code_HTML_txt(arg);\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_txtList3[] = "#define ol_width 16\n\
#define ol_height 16\n\
static char ol_bits[] = {\n\
   0x00, 0x00, 0x00, 0x74, 0x00, 0x7a, 0x00, 0x3d, 0x80, 0x1e, 0x00, 0x0f,\n\
   0xe0, 0x06, 0xf0, 0x01, 0xb0, 0x01, 0xd8, 0x01, 0xe8, 0x00, 0x3c, 0x00,\n\
   0x0c, 0x04, 0x02, 0x03, 0xf8, 0x00, 0x00, 0x00};\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtList[] = {
    {"class", _slotValue_HTML_txtList0},
    {"name", _slotValue_HTML_txtList1},
    {"script", _slotValue_HTML_txtList2},
    {"label", _slotValue_HTML_txtList3},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtListItem0[] = "txtDisp";
static char _slotValue_HTML_txtListItem1[] = "HTML_txtListItem";
static char _slotValue_HTML_txtListItem2[] = "\n\
	switch (arg[0]) {\n\
	case \"mouseMove\":\n\
		hint = processMouseMove();\n\
		if (prevHint != hint) {\n\
			if (isBlank(hint)) www.mesg.tf(\"clear\");\n\
			else www.mesg.tf(\"show\", hint);\n\
		}\n\
		prevHint = hint;\n\
		return;\n\
	break;\n\
	case \"leave\":\n\
		prevHint = 0;\n\
		www.mesg.tf(\"clear\");\n\
		return;\n\
	break;\n\
	case \"D\":\n\
		set(\"width\", send(parent(), \"wP\"));\n\
		inPreP = send(parent, \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		set(\"content\", text);\n\
		h = building_vspan() + 3;\n\
		set(\"height\", h);\n\
		set(\"maxHeight\", h);\n\
		h += 6; /* allow for gapH/V & border*/\n\
		return h;\n\
	break;\n\
	case \"R\": /* resize */\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 * arg[3]	x (optional)\n\
		 */\n\
		clearWindow();\n\
		set(\"y\", arg[1]);\n\
		set(\"width\", arg[2]);\n\
		set(\"content\", get(\"content\"));\n\
		h = set(\"height\", building_vspan() + 4);\n\
		render();\n\
		return h;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	data\n\
		 * arg[3]	x\n\
		 * arg[4]	width\n\
		 * arg[5]	listType\n\
		 */\n\
		set(\"parent\", arg[1]);\n\
		set(\"x\", arg[3]);\n\
		set(\"width\", arg[4]);\n\
		inPreP = send(arg[1], \"inPreP\");\n\
		if (inPreP) set(\"format\", 0);\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		set(\"content\", arg[2]);\n\
		h = building_vspan() + 4;\n\
		set(\"height\", h);\n\
		set(\"maxHeight\", h);\n\
		if (arg[5] == 'D') set(\"BGColor\", \"LemonChiffon2\");\n\
		h += 4;\n\
		eventMask(\"+pointerMotion +leaveWindow\");\n\
		return h;\n\
	break;\n\
	case 'i':\n\
		if (text) text = concat(text, get(\"label\"));\n\
		else text = get(\"label\");\n\
		return;\n\
	break;\n\
	case 'A':\n\
		/* arg[1]	object to absorb\n\
		 */\n\
		if (text) text = concat(text, send(arg[1], 'i'));\n\
		else text = send(arg[1], 'i');\n\
		return 0;\n\
	break;\n\
	case 'P':\n\
		set(\"parent\", arg[1]);\n\
		return h;\n\
	break;\n\
	case \"buttonRelease\":\n\
		usual();\n\
		if (charButtonMask() > 0) {\n\
			ref = HTTPDecodeURL(nextTag());\n\
			if (ref) {\n\
				if (shiftKeyP()) {\n\
					www.mesg.tf(\"show\",\n\
						concat(\"Dest: \", ref));\n\
				} else {\n\
					setRevVideoFlag(1);\n\
					send(send(parent(), \"findTop\"), \n\
						\"follow_href\", ref);\n\
					setRevVideoFlag(0);\n\
				}\n\
			}\n\
		} else {\n\
			/* lets user complete cut/paste */\n\
		}\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"findTop\":\n\
	case \"findForm\":\n\
		return send(parent(), arg[0]);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_txtListItem3[] = "100";
static char _slotValue_HTML_txtListItem4[] = "30";
static char _slotValue_HTML_txtListItem5[] = "normal";
static char _slotValue_HTML_txtListItem6[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtListItem[] = {
    {"class", _slotValue_HTML_txtListItem0},  {"name", _slotValue_HTML_txtListItem1},
    {"script", _slotValue_HTML_txtListItem2}, {"width", _slotValue_HTML_txtListItem3},
    {"height", _slotValue_HTML_txtListItem4}, {"font", _slotValue_HTML_txtListItem5},
    {"format", _slotValue_HTML_txtListItem6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtProtrude0[] = "field";
static char _slotValue_HTML_txtProtrude1[] = "HTML_txtProtrude";
static char _slotValue_HTML_txtProtrude2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
		else tt = compressSpaces(get(\"label\"));\n\
		return concat(\"\\\\f(3)\", tt, \"\\\\f(1)\");\n\
	break;\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtProtrude[] = {
    {"class", _slotValue_HTML_txtProtrude0},
    {"name", _slotValue_HTML_txtProtrude1},
    {"script", _slotValue_HTML_txtProtrude2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtUnderline0[] = "field";
static char _slotValue_HTML_txtUnderline1[] = "HTML_txtUnderline";
static char _slotValue_HTML_txtUnderline2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\
		else tt = compressSpaces(get(\"label\"));\n\
		return tt;\n\
		/*(\"\\\\u(\", tt, \")\") underline no longer supported in tfed*/\n\
	break;\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtUnderline[] = {
    {"class", _slotValue_HTML_txtUnderline0},
    {"name", _slotValue_HTML_txtUnderline1},
    {"script", _slotValue_HTML_txtUnderline2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vinsert0[] = "field";
static char _slotValue_HTML_vinsert1[] = "HTML_vinsert";
static char _slotValue_HTML_vinsert2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return 0;\n\
	break;\n\
	case 'i':\n\
		print(\"WARNING: INTERPRETING SCRIPT >>\", get(\"label\"), \"<<\\n\
\");\n\
		ss = interpret(get(\"label\"));\n\
		print(\"INTERPRETION RESULT >>\", ss, \"<<\\n\
\");\n\
		return ss;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_vinsert[] = {
    {"class", _slotValue_HTML_vinsert0},
    {"name", _slotValue_HTML_vinsert1},
    {"script", _slotValue_HTML_vinsert2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vobj0[] = "field";
static char _slotValue_HTML_vobj1[] = "HTML_vobj";
static char _slotValue_HTML_vobj2[] = "\n\
	switch (arg[0]) {\n\
	case 'i':\n\
		if (tagID) {\n\
			send(parent(), \"setAnchor\", tagID);\n\
			tagID = 0;\n\
		}\n\
		if (url) {\n\
			t = concat(\" \\\\b(\", compressSpaces(get(\"label\")),\n\
					\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\
			url = 0;\n\
			return t;\n\
		} else {\n\
			return compressSpaces(get(\"label\"));\n\
		}\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"NAME\":\n\
			tagID = arg[2];\n\
		break;\n\
		case \"HREF\":\n\
			url = arg[2];\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"F\":\n\
		h = 0;\n\
/*		SGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h = send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				SGMLBuildDoc_span(), makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		if (h == 0) return 1;\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"D\":\n\
		set(\"content2\", self());/*a kludge to deal with cloning*/\n\
		h = get(\"height\");\n\
		SGMLBuildDoc_setBuff(0);\n\
		if (isBlank(get(\"label\")) == 0) {\n\
			if (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\
			txtObj = HTML_txt(\"clone\");\n\
			objectListAppend_children(txtObj);\n\
			h += send(txtObj, \"make\", self(),\n\
				compressSpaces(get(\"label\")),\n\
				style_p[3], \n\
				get(\"width\") - style_p[3] - style_p[2],\n\
				h, makeAnchor);\n\
			makeAnchor = 0;\n\
		}\n\
		set(\"height\", h);\n\
		return h;\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
\n\
		vspan = 1;\n\
		n = countChildren();\n\
		if (n) {\n\
			xx = get(\"width\");\n\
			for (i = 0; i < n; i++)\n\
			  vspan += send(nthChild(i), 'R', vspan, xx);\n\
		}\n\
		set(\"height\", vspan);\n\
		return vspan;\n\
	break;\n\
	case \"copyObj\":\n\
		url = send(arg[1], \"url\");\n\
		return 0;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"expose\":\n\
	case \"render\":\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_vobj[] = {
    {"class", _slotValue_HTML_vobj0},
    {"name", _slotValue_HTML_vobj1},
    {"script", _slotValue_HTML_vobj2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vobjf0[] = "field";
static char _slotValue_HTML_vobjf1[] = "HTML_vobjf";
static char _slotValue_HTML_vobjf2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		docURL = violaSrc;\n\
\n\
		localFile = HTTPGet(docURL);\n\
\n\
		addrInfo = HTTPCurrentDocAddrParsed(localFile);\n\
\n\
		if (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];\n\
		else path = concat('/', addrInfo[2]);\n\
		objFileName = addrInfo[3];\n\
\n\
		addrInfo = HTTPCurrentDocAddrParsed(docURL);\n\
		objName = nthChar(addrInfo[3], 0, strlen(addrInfo[3]) - 3);\n\
\n\
		stat = loadObjFile(path, objFileName);\n\
\n\
		send(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\
\n\
		if (stat <= 0) {\n\
			print(\"failed to load obj file {\", objFileName,\n\
				\"} in {\", path, \"}\\n\
\");\n\
\n\
			new = send(\"HTML_fail\", \"clone\");\n\
			set(\"children\", new);\n\
			vspan = send(new, \"make\", self(), get(\"width\"),\n\
				     concat(\"Insert failed here: \", docURL));\n\
			return vspan;\n\
		}\n\
\n\
		/* from now on, newly made objects are declared unsecure */\n\
		securityMode(1); \n\
		send(objName, \"init\"); /* make new object(s) */\n\
		securityMode(0);\n\
		/* back to normal */\n\
\n\
		set(\"children\", objName);\n\
		tweak(objName, concat(\"set(\\\"parent\\\", \\\"\", self(), \"\\\");\"));\n\
\n\
		/* kludge */\n\
		after(1, objName, \"configSelf\");\n\
/*\n\
		after(1, self(), \"config\", x(), y(), width(), height()+2);\n\
		deepObjectListSend(\"children\", \"configSelf\");\n\
*/\n\
		vspan = tweak(nthChild(0), \"height();\") + 2;\n\
		return vspan;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"VOBJF\");\n\
		vspan = style[0];\n\
		set(\"x\", style[2]);\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		vspan = tweak(nthChild(0), \"height();\") + 2;\n\
		set(\"height\", vspan);\n\
		vspan += style[1];\n\
		return vspan;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"VOBJF\");\n\
		set(\"width\", get(\"width\") - style[3]);\n\
		vspan = tweak(nthChild(0), \"height();\") + 2;\n\
		return vspan;\n\
	break;\n\
	case \"AA\":\n\
		switch (arg[1]) {\n\
		case \"HREF\":\n\
			violaSrc = arg[2];\n\
		break;\n\
		case \"ARG\":\n\
			arg = arg[2];\n\
		break;\n\
		case \"MAXWIDTH\":\n\
			set(\"maxWidth\", arg[2]);\n\
		break;\n\
		case \"MINWIDTH\":\n\
			set(\"minWidth\", arg[2]);\n\
		break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"AI\":\n\
		return;\n\
	break;\n\
	case \"findTop\":\n\
		return send(parent(), \"findTop\");\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_vobjf[] = {
    {"class", _slotValue_HTML_vobjf0},
    {"name", _slotValue_HTML_vobjf1},
    {"script", _slotValue_HTML_vobjf2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vr0[] = "field";
static char _slotValue_HTML_vr1[] = "HTML_vr";
static char _slotValue_HTML_vr2[] = "\n\
	switch (arg[0]) {\n\
	case \"expose\":\n\
	case \"D\":\n\
		return 1;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"VR\");\n\
		set(\"y\", arg[1] + style[0]);\n\
		return 10;\n\
	break;\n\
	case 'r':\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"VR\");\n\
		after(1, self(), \"fixHeight\");\n\
		return 10;\n\
	break;\n\
	case \"fixHeight\":\n\
		ph = send(parent(), \"heightP\");\n\
		set(\"height\", ph - style[0] - style[1]);\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"outputSGML\":\n\
		print(\"<VR>\\n\
\");\n\
		return;\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_vr3[] = "1";
static char _slotValue_HTML_vr4[] = "2";
static char _slotValue_HTML_vr5[] = "1";
static char _slotValue_HTML_vr6[] = "10";
/* END OF FILE */

static SlotStruct objDesc_HTML_vr[] = {
    {"class", _slotValue_HTML_vr0},  {"name", _slotValue_HTML_vr1},
    {"script", _slotValue_HTML_vr2}, {"maxWidth", _slotValue_HTML_vr3},
    {"gapH", _slotValue_HTML_vr4},   {"width", _slotValue_HTML_vr5},
    {"height", _slotValue_HTML_vr6}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_vview0[] = "field";
static char _slotValue_HTML_vview1[] = "HTML_vview";
static char _slotValue_HTML_vview2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		text = get(\"label\");\n\
		send(send(parent(), \"findTop\"), \"VW_relay\", self(),\"VIEW_ON\");\n\
		send(send(parent(), \"findTop\"), \"VW_relay\", self(),\"VIEW_OFF\");\n\
		return -1;\n\
	break;\n\
	case \"VIEW_ON\":\n\
		print(\"interpreting: {\", text, \"}\\n\
\");\n\
		interpret(text);\n\
		return;\n\
	break;\n\
	case \"VIEW_OFF\":\n\
	case \"config\":\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_HTML_vview[] = {
    {"class", _slotValue_HTML_vview0},
    {"name", _slotValue_HTML_vview1},
    {"script", _slotValue_HTML_vview2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_xbm0[] = "XBM";
static char _slotValue_HTML_xbm1[] = "HTML_xbm";
static char _slotValue_HTML_xbm2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		set(\"label\", get(\"label\"));\n\
		return get(\"height\");\n\
	break;\n\
	case \"R\":\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"XBM\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		set(\"content\", get(\"content\"));\n\
		vspan += get(\"height\") + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"buttonPress\":\n\
		xy = mouseLocal();\n\
		x0 = xy[0];\n\
		y0 = xy[1];\n\
		set(\"FGColor\", \"black\");\n\
		drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\
		drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\
		set(\"FGColor\", \"white\");\n\
		drawLine(x0, y0 - 5, x0, y0 + 5);\n\
		drawLine(x0 + 5, y0, x0 - 5, y0);\n\
	break;\n\
	case \"buttonRelease\":\n\
		xy = mouseLocal();\n\
		x1 = xy[0];\n\
		y1 = xy[1];\n\
		top = send(parent(), \"findTop\");\n\
		ref = concat(send(top, \"query_docURL\"), \"?\",\n\
				x0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\
\n\
		set(\"FGColor\", \"black\");\n\
		drawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\
		drawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\
		set(\"FGColor\", \"white\");\n\
		drawLine(x1, y1 - 5, x1, y1 + 5);\n\
		drawLine(x1 + 5, y1, x1 - 5, y1);\n\
		send(top, \"follow_href\", ref);\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_xbm3[] = "100";
static char _slotValue_HTML_xbm4[] = "30";
/* END OF FILE */

static SlotStruct objDesc_HTML_xbm[] = {
    {"class", _slotValue_HTML_xbm0},  {"name", _slotValue_HTML_xbm1},
    {"script", _slotValue_HTML_xbm2}, {"width", _slotValue_HTML_xbm3},
    {"height", _slotValue_HTML_xbm4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_xbmf0[] = "XBM";
static char _slotValue_HTML_xbmf1[] = "HTML_xbmf";
static char _slotValue_HTML_xbmf2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		style = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		vspan += get(\"height\") + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	w\n\
		 * arg[3]	y\n\
		 * arg[4]	docURL\n\
		 * arg[5]	delayP\n\
		 * arg[6]	delayWidth\n\
		 * arg[7]	delayHeight\n\
		 * arg[8]	ismap\n\
		 */\n\
\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[2]);\n\
		style = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\
		set(\"y\", style[0]);\n\
		set(\"x\", arg[3] + style[2]);\n\
		ismap = arg[8];\n\
\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\
		localFile = HTTPGet(arg[4]);\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\
\n\
		if (arg[5] > 0) {\n\
			after(arg[5], self(), \n\
				\"loadData\", localFile, arg[6], arg[7]);\n\
			set(\"width\", arg[6]);\n\
			set(\"height\", arg[7]);\n\
			return height();\n\
		} else {\n\
			set(\"label\", loadFile(localFile));\n\
			send(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\
			return height();\n\
		}\n\
	break;\n\
	case \"loadData\":\n\
		set(\"label\", loadFile(arg[1]));\n\
		send(\"wwwSecurity\", \"rmTmpFile\", arg[1]);\n\
		render();\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"buttonPress\":\n\
		if (ismap) {\n\
			xy = mouseLocal();\n\
			x0 = xy[0];\n\
			y0 = xy[1];\n\
			set(\"FGColor\", \"black\");\n\
			drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\
			drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\
			set(\"FGColor\", \"white\");\n\
			drawLine(x0, y0 - 5, x0, y0 + 5);\n\
			drawLine(x0 + 5, y0, x0 - 5, y0);\n\
		}\n\
	break;\n\
	case \"buttonRelease\":\n\
		if (ismap) {\n\
			xy = mouseLocal();\n\
			x1 = xy[0];\n\
			y1 = xy[1];\n\
			if (top == 0) top = send(parent(), \"findTop\");\n\
			ref = concat(send(top, \"query_docURL\"), \"?\",\n\
					x0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\
\n\
			set(\"FGColor\", \"black\");\n\
			drawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\
			drawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\
			set(\"FGColor\", \"white\");\n\
			drawLine(x1, y1 - 5, x1, y1 + 5);\n\
			drawLine(x1 + 5, y1, x1 - 5, y1);\n\
			send(top, \"follow_href\", ref);\n\
		}\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_xbmf3[] = "100";
static char _slotValue_HTML_xbmf4[] = "30";
/* END OF FILE */

static SlotStruct objDesc_HTML_xbmf[] = {
    {"class", _slotValue_HTML_xbmf0},  {"name", _slotValue_HTML_xbmf1},
    {"script", _slotValue_HTML_xbmf2}, {"width", _slotValue_HTML_xbmf3},
    {"height", _slotValue_HTML_xbmf4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_xpm0[] = "XPM";
static char _slotValue_HTML_xpm1[] = "HTML_xpm";
static char _slotValue_HTML_xpm2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		set(\"label\", get(\"label\"));\n\
		return get(\"height\");\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		if (style == 0) style = SGMLGetStyle(\"HTML\", \"XPM\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		vspan += get(\"height\") + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return 0;\n\
	break;\n\
	case \"buttonPress\":\n\
		xy = mouseLocal();\n\
		x0 = xy[0];\n\
		y0 = xy[1];\n\
		set(\"FGColor\", \"black\");\n\
		drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\
		drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\
		set(\"FGColor\", \"white\");\n\
		drawLine(x0, y0 - 5, x0, y0 + 5);\n\
		drawLine(x0 + 5, y0, x0 - 5, y0);\n\
	break;\n\
	case \"buttonRelease\":\n\
		xy = mouseLocal();\n\
		x1 = xy[0];\n\
		y1 = xy[1];\n\
		top = send(parent(), \"findTop\");\n\
		ref = concat(send(top, \"query_docURL\"), \"?\",\n\
				x0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\
\n\
		set(\"FGColor\", \"black\");\n\
		drawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\
		drawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\
		set(\"FGColor\", \"white\");\n\
		drawLine(x1, y1 - 5, x1, y1 + 5);\n\
		drawLine(x1 + 5, y1, x1 - 5, y1);\n\
		send(top, \"follow_href\", ref);\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_xpm3[] = "100";
static char _slotValue_HTML_xpm4[] = "30";
/* END OF FILE */

static SlotStruct objDesc_HTML_xpm[] = {
    {"class", _slotValue_HTML_xpm0},  {"name", _slotValue_HTML_xpm1},
    {"script", _slotValue_HTML_xpm2}, {"width", _slotValue_HTML_xpm3},
    {"height", _slotValue_HTML_xpm4}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_xpmf0[] = "XPM";
static char _slotValue_HTML_xpmf1[] = "HTML_xpmf";
static char _slotValue_HTML_xpmf2[] = "\n\
	switch (arg[0]) {\n\
	case \"D\":\n\
		return -1;\n\
	break;\n\
	case 'R':\n\
		/* arg[1]	y\n\
		 * arg[2]	width\n\
		 */\n\
		clearWindow();\n\
		style = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\
		vspan = style[0];\n\
		set(\"y\", arg[1] + vspan);\n\
		set(\"x\", style[2]);\n\
		set(\"width\", arg[2] - x() - style[3]);\n\
		set(\"label\", get(\"label\"));\n\
		vspan += get(\"height\") + style[1];\n\
		render();\n\
		return vspan;\n\
	break;\n\
	case \"make\":\n\
		/* arg[1]	parent\n\
		 * arg[2]	w\n\
		 * arg[3]	y\n\
		 * arg[4]	src\n\
		 * arg[5]	delayP\n\
		 * arg[6]	delayWidth\n\
		 * arg[7]	delayHeight\n\
		 * arg[8]	ismap\n\
		 */\n\
		style = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\
		set(\"y\", arg[3] + style[0]);\n\
		set(\"x\", style[2]);\n\
		set(\"parent\", arg[1]);\n\
		set(\"width\", arg[2]);\n\
		ismap = arg[8];\n\
\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\
\n\
		localFile = HTTPGet(arg[4]);\n\
\n\
		send(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\
\n\
		if (arg[5] > 0) {\n\
			after(arg[5], self(), \"loadData\", localFile);\n\
			return 50; /*XXX*/\n\
		} else {\n\
			set(\"label\", loadFile(localFile));\n\
			send(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\
			return height();\n\
		}\n\
	break;\n\
	case \"loadData\":\n\
		set(\"label\", localFile);\n\
		system(concat(\"rm -f \", localFile));\n\
		return;\n\
	break;\n\
	case \"config\":\n\
		return;\n\
	break;\n\
	case \"gotoAnchor\":\n\
		return \"\";\n\
	break;\n\
	case \"buttonPress\":\n\
		if (ismap) {\n\
			xy = mouseLocal();\n\
			x0 = xy[0];\n\
			y0 = xy[1];\n\
			set(\"FGColor\", \"black\");\n\
			drawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\
			drawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\
			set(\"FGColor\", \"white\");\n\
			drawLine(x0, y0 - 5, x0, y0 + 5);\n\
			drawLine(x0 + 5, y0, x0 - 5, y0);\n\
		}\n\
	break;\n\
	case \"buttonRelease\":\n\
		if (ismap) {\n\
			xy = mouseLocal();\n\
			x1 = xy[0];\n\
			y1 = xy[1];\n\
			top = send(parent(), \"findTop\");\n\
			ref = concat(send(top, \"query_docURL\"), \"?\",\n\
					x0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\
\n\
			set(\"FGColor\", \"black\");\n\
			drawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\
			drawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\
			set(\"FGColor\", \"white\");\n\
			drawLine(x1, y1 - 5, x1, y1 + 5);\n\
			drawLine(x1 + 5, y1, x1 - 5, y1);\n\
			send(top, \"follow_href\", ref);\n\
		}\n\
	break;\n\
	case \"clone\":\n\
		return clone(cloneID());\n\
	break;\n\
	case \"init\":\n\
		usual();\n\
		SGMLBuildDoc_setColors();\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_HTML_xpmf3[] = "100";
static char _slotValue_HTML_xpmf4[] = "30";
/* END OF FILE */

static SlotStruct objDesc_HTML_xpmf[] = {
    {"class", _slotValue_HTML_xpmf0},  {"name", _slotValue_HTML_xpmf1},
    {"script", _slotValue_HTML_xpmf2}, {"width", _slotValue_HTML_xpmf3},
    {"height", _slotValue_HTML_xpmf4}, {(char*)0, (char*)0},
};

static char _slotValue_invokeExample0[] = "invokeExample";
static char _slotValue_invokeExample1[] = "vpane";
static char _slotValue_invokeExample2[] = "";
static char _slotValue_invokeExample3[] = "\n\
	switch (arg[0]) {\n\
	case \"render\":\n\
		set(\"visible\", 1);\n\
		render();\n\
		raise();\n\
		return;\n\
	break;\n\
	case \"invoke\":\n\
		data = tweak(arg[1], \"get(\\\"content\\\");\");\n\
\n\
		/* get rid of font-directive from likes of:\n\
		 *	\\f(7)telnet madlab.sprl.umich.edu\\f(1) port \\f(7)3000\n\
		 */\n\
\n\
		/* this is pretty messed up. remember to implement substr() */\n\
		clearP = 1;\n\
		while (clearP) {\n\
			at = findPattern(data, \"\\\\f\");\n\
			if (at == -1) clearP = 0;\n\
			else {\n\
				if (at == 1) {\n\
					data = nthChar(data, 5, strlen(data));\n\
				} else {\n\
					data = concat(nthChar(data, 0, at - 2),\n\
						nthChar(data, at + 4, \n\
							strlen(data)));\n\
				}\n\
			}\n\
		}\n\
\n\
		semiAt = findPattern(data, \";\");\n\
		if (semiAt == -1) {\n\
			stmt = nthLine(data, 0);\n\
			stmt = trimEdge(nthChar(stmt, 0, 999));\n\
		} else {\n\
			stmt = trimEdge(nthChar(data, 0, semiAt - 1));\n\
		}\n\
		print(\"stmt={\", stmt, \"}\\n\
\");\n\
\n\
		switch (nthWord(stmt, 1)) {\n\
		case \"finger\":\n\
			tmp = makeTempFile();\n\
			system(concat(stmt, \" > \", tmp));\n\
			set(\"visible\", 1);\n\
			render();\n\
			deepObjectListSend(\"children\", \"render\");\n\
			raise();\n\
			send(nthChild(1), \"show\", tmp);\n\
			send(nthChild(0), \"show\", stmt);\n\
			system(concat(\"rm -f \", tmp));\n\
		break;\n\
		case \"telnet\":\n\
			/* can't handle this, pop up a shell */\n\
\n\
			replaceCharQ(stmt, ';', '\\0');\n\
			p0 = findPattern(stmt, \" port \");\n\
			print(\">>\", stmt, \"<<< p0=\", p0, \".\\n\
\");\n\
\n\
			if (p0 != -1) {\n\
				/* Rid of \"port\", b/c it probably looks like:\n\
				 * telnet eve.assumption.edu port 5000 \n\
				 */\n\
\n\
				port = nthChar(stmt, p0 + 6, 999);\n\
				print(\" port=>>>\", port, \"<<\\n\
\");\n\
\n\
				hostName = nthWord(stmt, 2, 9);\n\
\n\
				print(\" hostname=>>>\", hostName, \"<<\\n\
\");\n\
\n\
				print(\">>\", concat(\"xterm \", \n\
					\"-title \\\"\", hostName, \"\\\" \"),\n\
					\"-e \", stmt, \" \", port, \" &\",\n\
					\"<<\\n\
\");\n\
				system(concat(\"xterm \", \n\
					\"-title \\\"\", hostName, \"\\\" \",\n\
					\"-e \", stmt, \" \", port, \" &\"));\n\
			} else {\n\
				login = \"\";\n\
				l0 = findPattern(stmt, \"login\");\n\
				if (l0 != -1) {\n\
					login = nthChar(stmt, l0 + 6, 999);\n\
				}\n\
				replaceCharQ(stmt, ';', '\\0');\n\
				replaceCharQ(stmt, '\\\\', '\\0');\n\
				hostName = nthWord(stmt, 2, 9);\n\
\n\
				if (login) {\n\
					print(\">>\", concat(\"xterm \", \n\
						\"-title \\\"\", hostName, \"\\\" \"),\n\
						\"-e \", stmt, \" &\",\n\
						\"<<\\n\
\");\n\
					system(concat(\"xterm \", \n\
						\"-title \\\"\", hostName, \"\\\" \",\n\
						\"-e \", stmt, \" &\"));\n\
				} else {\n\
					print(\">>\", concat(\"xterm \", \n\
						\"-title \\\"\", hostName, \"\\\" \"),\n\
						\"-e \", stmt,\n\
						\" -l \", login, \" &\",\n\
						\"<<\\n\
\");\n\
					system(concat(\"xterm \", \n\
						\"-title \\\"\", hostName, \"\\\" \",\n\
						\"-e \", stmt,\n\
						\" -l \", login, \" &\"));\n\
				}\n\
			}\n\
			break;\n\
		}\n\
		return;\n\
	break;\n\
	case \"finger\":\n\
		tmp = makeTempFile();\n\
		system(concat(\"finger nasanews@space.mit.edu > \", tmp));\n\
		send(nthChild(1), \"show\", tmp);\n\
		system(concat(\"rm -f \", tmp));\n\
		return;\n\
	break;\n\
	case \"dismiss\":\n\
		set(\"visible\", 0);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_invokeExample4[] = "600";
static char _slotValue_invokeExample5[] = "400";
static char _slotValue_invokeExample6[] = "invokeExample.top invokeExample.list invokeExample.ctrl";
/* END OF OBJ */

static char _slotValue_invokeExample8[] = "invokeExample.top";
static char _slotValue_invokeExample9[] = "txtLabel";
static char _slotValue_invokeExample10[] = "invokeExample";
static char _slotValue_invokeExample11[] = "normal";
static char _slotValue_invokeExample12[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"label\", arg[1]);\n\
		return;\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_invokeExample13[] = "Finger Info Viewer";
static char _slotValue_invokeExample14[] = "40";
static char _slotValue_invokeExample15[] = "bold_largest";
/* END OF OBJ */

static char _slotValue_invokeExample17[] = "invokeExample.list";
static char _slotValue_invokeExample18[] = "hpane";
static char _slotValue_invokeExample19[] = "invokeExample";
static char _slotValue_invokeExample20[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		send(nthChild(0), \"show\", arg[1]);\n\
		return;\n\
	break;\n\
	case \"contentP\":\n\
		return send(nthChild(0), \"contentP\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_invokeExample21[] = "invokeExample.list.tf invokeExample.list.sb";
/* END OF OBJ */

static char _slotValue_invokeExample23[] = "invokeExample.list.sb";
static char _slotValue_invokeExample24[] = "slider";
static char _slotValue_invokeExample25[] = "invokeExample.list";
static char _slotValue_invokeExample26[] = "invokeExample.list.tf";
static char _slotValue_invokeExample27[] = "15";
/* END OF OBJ */

static char _slotValue_invokeExample29[] = "invokeExample.list.tf";
static char _slotValue_invokeExample30[] = "invokeExample.list";
static char _slotValue_invokeExample31[] = "txtDisp";
static char _slotValue_invokeExample32[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
		set(\"content\", loadFile(arg[1]));\n\
/*\n\
print(\"loading file >>>>>>>\", arg[1], \"<<<\\n\
\");\n\
print(\"content >>>>>>>\", get(\"content\"), \"<<<\\n\
\");\n\
*/\n\
		return;\n\
	break;\n\
	case \"contentP\":\n\
		return get(\"content\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_invokeExample33[] = "invokeExample.list.sb";
static char _slotValue_invokeExample34[] = "fixed";
static char _slotValue_invokeExample35[] = "1";
/* END OF OBJ */

static char _slotValue_invokeExample37[] = "invokeExample.ctrl";
static char _slotValue_invokeExample38[] = "hpane";
static char _slotValue_invokeExample39[] = "invokeExample";
static char _slotValue_invokeExample40[] = "20";
static char _slotValue_invokeExample41[] = "invokeExample.ctrl.dismiss";
static char _slotValue_invokeExample42[] = "\n\
	switch (arg[0]) {\n\
	case \"show\":\n\
	case \"dismiss\":\n\
		send(get(\"parent\"), arg[0]);\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_invokeExample44[] = "invokeExample.ctrl.finger";
static char _slotValue_invokeExample45[] = "txtButton";
static char _slotValue_invokeExample46[] = "invokeExample.ctrl";
static char _slotValue_invokeExample47[] = "normal";
static char _slotValue_invokeExample48[] = "Finger nasanews@space.mit.edu";
static char _slotValue_invokeExample49[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(get(\"parent\"), \"show\");\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF OBJ */

static char _slotValue_invokeExample51[] = "invokeExample.ctrl.dismiss";
static char _slotValue_invokeExample52[] = "txtButton";
static char _slotValue_invokeExample53[] = "invokeExample.ctrl";
static char _slotValue_invokeExample54[] = "normal";
static char _slotValue_invokeExample55[] = "Dismiss";
static char _slotValue_invokeExample56[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		send(get(\"parent\"), \"dismiss\");\n\
	break;\n\
	}\n\
	usual();\n\
";
/* END OF FILE */

static SlotStruct objDesc_invokeExample[] = {
    {"name", _slotValue_invokeExample0},
    {"class", _slotValue_invokeExample1},
    {"parent", _slotValue_invokeExample2},
    {"script", _slotValue_invokeExample3},
    {"width", _slotValue_invokeExample4},
    {"height", _slotValue_invokeExample5},
    {"children", _slotValue_invokeExample6},
    {(char*)0, (char*)1},
    {"name", _slotValue_invokeExample8},
    {"class", _slotValue_invokeExample9},
    {"parent", _slotValue_invokeExample10},
    {"font", _slotValue_invokeExample11},
    {"script", _slotValue_invokeExample12},
    {"label", _slotValue_invokeExample13},
    {"maxHeight", _slotValue_invokeExample14},
    {"font", _slotValue_invokeExample15},
    {(char*)0, (char*)1},
    {"name", _slotValue_invokeExample17},
    {"class", _slotValue_invokeExample18},
    {"parent", _slotValue_invokeExample19},
    {"script", _slotValue_invokeExample20},
    {"children", _slotValue_invokeExample21},
    {(char*)0, (char*)1},
    {"name", _slotValue_invokeExample23},
    {"class", _slotValue_invokeExample24},
    {"parent", _slotValue_invokeExample25},
    {"shownNotify", _slotValue_invokeExample26},
    {"maxWidth", _slotValue_invokeExample27},
    {(char*)0, (char*)1},
    {"name", _slotValue_invokeExample29},
    {"parent", _slotValue_invokeExample30},
    {"class", _slotValue_invokeExample31},
    {"script", _slotValue_invokeExample32},
    {"shownDepend", _slotValue_invokeExample33},
    {"font", _slotValue_invokeExample34},
    {"verbatim", _slotValue_invokeExample35},
    {(char*)0, (char*)1},
    {"name", _slotValue_invokeExample37},
    {"class", _slotValue_invokeExample38},
    {"parent", _slotValue_invokeExample39},
    {"maxHeight", _slotValue_invokeExample40},
    {"children", _slotValue_invokeExample41},
    {"script", _slotValue_invokeExample42},
    {(char*)0, (char*)1},
    {"name", _slotValue_invokeExample44},
    {"class", _slotValue_invokeExample45},
    {"parent", _slotValue_invokeExample46},
    {"font", _slotValue_invokeExample47},
    {"label", _slotValue_invokeExample48},
    {"script", _slotValue_invokeExample49},
    {(char*)0, (char*)1},
    {"name", _slotValue_invokeExample51},
    {"class", _slotValue_invokeExample52},
    {"parent", _slotValue_invokeExample53},
    {"font", _slotValue_invokeExample54},
    {"label", _slotValue_invokeExample55},
    {"script", _slotValue_invokeExample56},
    {(char*)0, (char*)0},
};

static char _slotValue_invokeFinger0[] = "txtButton";
static char _slotValue_invokeFinger1[] = "invokeFinger";
static char _slotValue_invokeFinger2[] = "";
static char _slotValue_invokeFinger3[] = "GO";
static char _slotValue_invokeFinger4[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		invokeExample(\"invoke\", caller);\n\
	break;\n\
	case \"new\":\n\
		/* arg[1]	caller\n\
		 * arg[2]	parent\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 */\n\
		return send(clone(cloneID()), \"build\", \n\
				arg[1], arg[2], arg[3], arg[4]);\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	caller\n\
		 * arg[2]	parent\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 */\n\
		caller = arg[1];\n\
		set(\"parent\", arg[2]);\n\
		set(\"x\", arg[3] + 2);\n\
		set(\"y\", arg[4]);\n\
		set(\"visible\", 1);\n\
		return get(\"name\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_invokeFinger5[] = "fixed";
static char _slotValue_invokeFinger6[] = "20";
static char _slotValue_invokeFinger7[] = "17";
static char _slotValue_invokeFinger8[] = "17";
/* END OF FILE */

static SlotStruct objDesc_invokeFinger[] = {
    {"class", _slotValue_invokeFinger0},     {"name", _slotValue_invokeFinger1},
    {"parent", _slotValue_invokeFinger2},    {"label", _slotValue_invokeFinger3},
    {"script", _slotValue_invokeFinger4},    {"font", _slotValue_invokeFinger5},
    {"width", _slotValue_invokeFinger6},     {"height", _slotValue_invokeFinger7},
    {"maxHeight", _slotValue_invokeFinger8}, {(char*)0, (char*)0},
};

static char _slotValue_invokeGopher0[] = "txtButton";
static char _slotValue_invokeGopher1[] = "invokeGopher";
static char _slotValue_invokeGopher2[] = "";
static char _slotValue_invokeGopher3[] = "GO";
static char _slotValue_invokeGopher4[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		invokeExample(\"invoke\", caller);\n\
	break;\n\
	case \"new\":\n\
		/* arg[1]	caller\n\
		 * arg[2]	parent\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 */\n\
		return send(clone(cloneID()), \"build\", \n\
				arg[1], arg[2], arg[3], arg[4]);\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	caller\n\
		 * arg[2]	parent\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 */\n\
		caller = arg[1];\n\
		set(\"parent\", arg[2]);\n\
		set(\"x\", arg[3] + 2);\n\
		set(\"y\", arg[4]);\n\
		set(\"visible\", 1);\n\
		return get(\"name\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_invokeGopher5[] = "fixed";
static char _slotValue_invokeGopher6[] = "20";
static char _slotValue_invokeGopher7[] = "17";
static char _slotValue_invokeGopher8[] = "17";
/* END OF FILE */

static SlotStruct objDesc_invokeGopher[] = {
    {"class", _slotValue_invokeGopher0},     {"name", _slotValue_invokeGopher1},
    {"parent", _slotValue_invokeGopher2},    {"label", _slotValue_invokeGopher3},
    {"script", _slotValue_invokeGopher4},    {"font", _slotValue_invokeGopher5},
    {"width", _slotValue_invokeGopher6},     {"height", _slotValue_invokeGopher7},
    {"maxHeight", _slotValue_invokeGopher8}, {(char*)0, (char*)0},
};

static char _slotValue_invokeTelnet0[] = "txtButton";
static char _slotValue_invokeTelnet1[] = "invokeTelnet";
static char _slotValue_invokeTelnet2[] = "";
static char _slotValue_invokeTelnet3[] = "GO";
static char _slotValue_invokeTelnet4[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		invokeExample(\"invoke\", caller);\n\
	break;\n\
	case \"new\":\n\
		/* arg[1]	caller\n\
		 * arg[2]	parent\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 */\n\
		return send(clone(cloneID(), \"build\", \n\
				arg[1], arg[2], arg[3], arg[4]);\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	caller\n\
		 * arg[2]	parent\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 */\n\
		caller = arg[1];\n\
		set(\"parent\", arg[2]);\n\
		set(\"x\", arg[3] + 2);\n\
		set(\"y\", arg[4]);\n\
		set(\"visible\", 1);\n\
		return get(\"name\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_invokeTelnet5[] = "fixed";
static char _slotValue_invokeTelnet6[] = "20";
static char _slotValue_invokeTelnet7[] = "17";
static char _slotValue_invokeTelnet8[] = "17";
/* END OF FILE */

static SlotStruct objDesc_invokeTelnet[] = {
    {"class", _slotValue_invokeTelnet0},     {"name", _slotValue_invokeTelnet1},
    {"parent", _slotValue_invokeTelnet2},    {"label", _slotValue_invokeTelnet3},
    {"script", _slotValue_invokeTelnet4},    {"font", _slotValue_invokeTelnet5},
    {"width", _slotValue_invokeTelnet6},     {"height", _slotValue_invokeTelnet7},
    {"maxHeight", _slotValue_invokeTelnet8}, {(char*)0, (char*)0},
};

static char _slotValue_invokeWAIS0[] = "txtButton";
static char _slotValue_invokeWAIS1[] = "invokeWAIS";
static char _slotValue_invokeWAIS2[] = "GO";
static char _slotValue_invokeWAIS3[] = "\n\
	switch (arg[0]) {\n\
	case \"buttonRelease\":\n\
		invokeExample(\"invoke\", caller);\n\
	break;\n\
	case \"new\":\n\
		/* arg[1]	caller\n\
		 * arg[2]	parent\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 */\n\
		return send(clone(cloneID()), \"build\", \n\
				arg[1], arg[2], arg[3], arg[4]);\n\
	break;\n\
	case \"build\":\n\
		/* arg[1]	caller\n\
		 * arg[2]	parent\n\
		 * arg[3]	x\n\
		 * arg[4]	y\n\
		 */\n\
		caller = arg[1];\n\
		set(\"parent\", arg[2]);\n\
		set(\"x\", arg[3] + 2);\n\
		set(\"y\", arg[4]);\n\
		set(\"visible\", 1);\n\
		return get(\"name\");\n\
	break;\n\
	}\n\
	usual();\n\
";
static char _slotValue_invokeWAIS4[] = "fixed";
static char _slotValue_invokeWAIS5[] = "20";
static char _slotValue_invokeWAIS6[] = "17";
static char _slotValue_invokeWAIS7[] = "17";
/* END OF FILE */

static SlotStruct objDesc_invokeWAIS[] = {
    {"class", _slotValue_invokeWAIS0},
    {"name", _slotValue_invokeWAIS1},
    {"label", _slotValue_invokeWAIS2},
    {"script", _slotValue_invokeWAIS3},
    {"font", _slotValue_invokeWAIS4},
    {"width", _slotValue_invokeWAIS5},
    {"height", _slotValue_invokeWAIS6},
    {"maxHeight", _slotValue_invokeWAIS7},
    {(char*)0, (char*)0},
};

ObjsNamesStruct objsNames[] = {"HTML__box.v",
                               objDesc_HTML__box,
                               "HTML__doc.v",
                               objDesc_HTML__doc,
                               "HTML__foldIcon.v",
                               objDesc_HTML__foldIcon,
                               "HTML__txtBox.v",
                               objDesc_HTML__txtBox,
                               "HTML__txtBox_alert.v",
                               objDesc_HTML__txtBox_alert,
                               "HTML__txtBox_caution.v",
                               objDesc_HTML__txtBox_caution,
                               "HTML__txtBox_error.v",
                               objDesc_HTML__txtBox_error,
                               "HTML__txtBox_note.v",
                               objDesc_HTML__txtBox_note,
                               "HTML__txtBox_time.v",
                               objDesc_HTML__txtBox_time,
                               "HTML_address.v",
                               objDesc_HTML_address,
                               "HTML_attr.v",
                               objDesc_HTML_attr,
                               "HTML_author.v",
                               objDesc_HTML_author,
                               "HTML_base.v",
                               objDesc_HTML_base,
                               "HTML_body.v",
                               objDesc_HTML_body,
                               "HTML_box.v",
                               objDesc_HTML_box,
                               "HTML_bulletItem.v",
                               objDesc_HTML_bulletItem,
                               "HTML_caution.v",
                               objDesc_HTML_caution,
                               "HTML_change.v",
                               objDesc_HTML_change,
                               "HTML_changed.v",
                               objDesc_HTML_changed,
                               "HTML_cmd.v",
                               objDesc_HTML_cmd,
                               "HTML_col2.v",
                               objDesc_HTML_col2,
                               "HTML_col3.v",
                               objDesc_HTML_col3,
                               "HTML_col4.v",
                               objDesc_HTML_col4,
                               "HTML_defList.v",
                               objDesc_HTML_defList,
                               "HTML_defListBody.v",
                               objDesc_HTML_defListBody,
                               "HTML_defListBody_p.v",
                               objDesc_HTML_defListBody_p,
                               "HTML_defListHead.v",
                               objDesc_HTML_defListHead,
                               "HTML_defListHead_p.v",
                               objDesc_HTML_defListHead_p,
                               "HTML_example.v",
                               objDesc_HTML_example,
                               "HTML_fail.v",
                               objDesc_HTML_fail,
                               "HTML_figa.v",
                               objDesc_HTML_figa,
                               "HTML_figa_actual.v",
                               objDesc_HTML_figa_actual,
                               "HTML_figcap.v",
                               objDesc_HTML_figcap,
                               "HTML_figdata.v",
                               objDesc_HTML_figdata,
                               "HTML_figure.v",
                               objDesc_HTML_figure,
                               "HTML_fld.v",
                               objDesc_HTML_fld,
                               "HTML_footnote.v",
                               objDesc_HTML_footnote,
                               "HTML_form.v",
                               objDesc_HTML_form,
                               "HTML_gif.v",
                               objDesc_HTML_gif,
                               "HTML_giff.v",
                               objDesc_HTML_giff,
                               "HTML_head.v",
                               objDesc_HTML_head,
                               "HTML_header_big.v",
                               objDesc_HTML_header_big,
                               "HTML_header_medium.v",
                               objDesc_HTML_header_medium,
                               "HTML_header_small.v",
                               objDesc_HTML_header_small,
                               "HTML_hpane.v",
                               objDesc_HTML_hpane,
                               "HTML_hr.v",
                               objDesc_HTML_hr,
                               "HTML_ignore.v",
                               objDesc_HTML_ignore,
                               "HTML_img.v",
                               objDesc_HTML_img,
                               "HTML_input.v",
                               objDesc_HTML_input,
                               "HTML_input_check.v",
                               objDesc_HTML_input_check,
                               "HTML_input_doodle.v",
                               objDesc_HTML_input_doodle,
                               "HTML_input_fail.v",
                               objDesc_HTML_input_fail,
                               "HTML_input_hidden.v",
                               objDesc_HTML_input_hidden,
                               "HTML_input_hook.v",
                               objDesc_HTML_input_hook,
                               "HTML_input_image.v",
                               objDesc_HTML_input_image,
                               "HTML_input_int.v",
                               objDesc_HTML_input_int,
                               "HTML_input_password.v",
                               objDesc_HTML_input_password,
                               "HTML_input_percent.v",
                               objDesc_HTML_input_percent,
                               "HTML_input_radio.v",
                               objDesc_HTML_input_radio,
                               "HTML_input_reset.v",
                               objDesc_HTML_input_reset,
                               "HTML_input_str.v",
                               objDesc_HTML_input_str,
                               "HTML_input_submit.v",
                               objDesc_HTML_input_submit,
                               "HTML_input_text.v",
                               objDesc_HTML_input_text,
                               "HTML_insert.v",
                               objDesc_HTML_insert,
                               "HTML_insertTest.v",
                               objDesc_HTML_insertTest,
                               "HTML_insertee.v",
                               objDesc_HTML_insertee,
                               "HTML_isIndex.v",
                               objDesc_HTML_isIndex,
                               "HTML_ititle.v",
                               objDesc_HTML_ititle,
                               "HTML_label.v",
                               objDesc_HTML_label,
                               "HTML_link.v",
                               objDesc_HTML_link,
                               "HTML_list.v",
                               objDesc_HTML_list,
                               "HTML_listBullet.v",
                               objDesc_HTML_listBullet,
                               "HTML_listC.v",
                               objDesc_HTML_listC,
                               "HTML_listItem.v",
                               objDesc_HTML_listItem,
                               "HTML_listMenu.v",
                               objDesc_HTML_listMenu,
                               "HTML_listNum.v",
                               objDesc_HTML_listNum,
                               "HTML_listNum_oval.v",
                               objDesc_HTML_listNum_oval,
                               "HTML_listNumbered.v",
                               objDesc_HTML_listNumbered,
                               "HTML_listNumberedC.v",
                               objDesc_HTML_listNumberedC,
                               "HTML_listSep.v",
                               objDesc_HTML_listSep,
                               "HTML_listTxt.v",
                               objDesc_HTML_listTxt,
                               "HTML_listing.v",
                               objDesc_HTML_listing,
                               "HTML_math.v",
                               objDesc_HTML_math,
                               "HTML_menu.v",
                               objDesc_HTML_menu,
                               "HTML_menuSep.v",
                               objDesc_HTML_menuSep,
                               "HTML_mh.v",
                               objDesc_HTML_mh,
                               "HTML_nextID.v",
                               objDesc_HTML_nextID,
                               "HTML_option.v",
                               objDesc_HTML_option,
                               "HTML_over.v",
                               objDesc_HTML_over,
                               "HTML_plain.v",
                               objDesc_HTML_plain,
                               "HTML_plaintext.v",
                               objDesc_HTML_plaintext,
                               "HTML_pre.v",
                               objDesc_HTML_pre,
                               "HTML_preTxt.v",
                               objDesc_HTML_preTxt,
                               "HTML_psep.v",
                               objDesc_HTML_psep,
                               "HTML_psf.v",
                               objDesc_HTML_psf,
                               "HTML_quote.v",
                               objDesc_HTML_quote,
                               "HTML_script.v",
                               objDesc_HTML_script,
                               "HTML_select.v",
                               objDesc_HTML_select,
                               "HTML_sub.v",
                               objDesc_HTML_sub,
                               "HTML_sup.v",
                               objDesc_HTML_sup,
                               "HTML_table.v",
                               objDesc_HTML_table,
                               "HTML_tableCap.v",
                               objDesc_HTML_tableCap,
                               "HTML_tableVPane.v",
                               objDesc_HTML_tableVPane,
                               "HTML_tb.v",
                               objDesc_HTML_tb,
                               "HTML_tcap.v",
                               objDesc_HTML_tcap,
                               "HTML_td.v",
                               objDesc_HTML_td,
                               "HTML_textarea.v",
                               objDesc_HTML_textarea,
                               "HTML_th.v",
                               objDesc_HTML_th,
                               "HTML_title.v",
                               objDesc_HTML_title,
                               "HTML_tr.v",
                               objDesc_HTML_tr,
                               "HTML_txt.v",
                               objDesc_HTML_txt,
                               "HTML_txtAnchor.v",
                               objDesc_HTML_txtAnchor,
                               "HTML_txtBold.v",
                               objDesc_HTML_txtBold,
                               "HTML_txtBullet.v",
                               objDesc_HTML_txtBullet,
                               "HTML_txtCommand.v",
                               objDesc_HTML_txtCommand,
                               "HTML_txtDD.v",
                               objDesc_HTML_txtDD,
                               "HTML_txtDT.v",
                               objDesc_HTML_txtDT,
                               "HTML_txtEmphasis.v",
                               objDesc_HTML_txtEmphasis,
                               "HTML_txtItalic.v",
                               objDesc_HTML_txtItalic,
                               "HTML_txtList.v",
                               objDesc_HTML_txtList,
                               "HTML_txtListItem.v",
                               objDesc_HTML_txtListItem,
                               "HTML_txtProtrude.v",
                               objDesc_HTML_txtProtrude,
                               "HTML_txtUnderline.v",
                               objDesc_HTML_txtUnderline,
                               "HTML_vinsert.v",
                               objDesc_HTML_vinsert,
                               "HTML_vobj.v",
                               objDesc_HTML_vobj,
                               "HTML_vobjf.v",
                               objDesc_HTML_vobjf,
                               "HTML_vr.v",
                               objDesc_HTML_vr,
                               "HTML_vview.v",
                               objDesc_HTML_vview,
                               "HTML_xbm.v",
                               objDesc_HTML_xbm,
                               "HTML_xbmf.v",
                               objDesc_HTML_xbmf,
                               "HTML_xpm.v",
                               objDesc_HTML_xpm,
                               "HTML_xpmf.v",
                               objDesc_HTML_xpmf,
                               "VWHandler_fail.v",
                               objDesc_VWHandler_fail,
                               "VWHandler_gif.v",
                               objDesc_VWHandler_gif,
                               "VWHandler_hmml.v",
                               objDesc_VWHandler_hmml,
                               "VWHandler_hmml_fail.v",
                               objDesc_VWHandler_hmml_fail,
                               "VWHandler_hmmlb.v",
                               objDesc_VWHandler_hmmlb,
                               "VWHandler_html.v",
                               objDesc_VWHandler_html,
                               "VWHandler_html2.v",
                               objDesc_VWHandler_html2,
                               "VWHandler_plaintext.v",
                               objDesc_VWHandler_plaintext,
                               "VWHandler_vobj.v",
                               objDesc_VWHandler_vobj,
                               "VWHandler_vobjf.v",
                               objDesc_VWHandler_vobjf,
                               "VWHandler_xbm.v",
                               objDesc_VWHandler_xbm,
                               "VWHandler_xpm.v",
                               objDesc_VWHandler_xpm,
                               "WWWEMailHandler.v",
                               objDesc_WWWEMailHandler,
                               "WWWTelnetHandler.v",
                               objDesc_WWWTelnetHandler,
                               "invokeExample.v",
                               objDesc_invokeExample,
                               "invokeFinger.v",
                               objDesc_invokeFinger,
                               "invokeGopher.v",
                               objDesc_invokeGopher,
                               "invokeTelnet.v",
                               objDesc_invokeTelnet,
                               "invokeWAIS.v",
                               objDesc_invokeWAIS,
                               "mvw.v",
                               objDesc_mvw,
                               "mvwHistory.v",
                               objDesc_mvwHistory,
                               "normalizeURL.v",
                               objDesc_normalizeURL,
                               "parseHTTPAddress.v",
                               objDesc_parseHTTPAddress,
                               "res.HTMLStyle.v",
                               objDesc_res_HTMLStyle,
                               "res.dialogWithButtons.v",
                               objDesc_res_dialogWithButtons,
                               "res.font.v",
                               objDesc_res_font,
                               "res.getLineEntry.v",
                               objDesc_res_getLineEntry,
                               "res.v",
                               objDesc_res,
                               "shell.v",
                               objDesc_shell,
                               "www.v",
                               objDesc_www,
                               "wwwAbout.v",
                               objDesc_wwwAbout,
                               "wwwDialog_confirm.v",
                               objDesc_wwwDialog_confirm,
                               "wwwDocuPort.v",
                               objDesc_wwwDocuPort,
                               "wwwFormatDetect.v",
                               objDesc_wwwFormatDetect,
                               "wwwHTMLSrc.v",
                               objDesc_wwwHTMLSrc,
                               "wwwHandlerDispatch.v",
                               objDesc_wwwHandlerDispatch,
                               "wwwHistory.v",
                               objDesc_wwwHistory,
                               "wwwHotFolder.v",
                               objDesc_wwwHotFolder,
                               "wwwPref.v",
                               objDesc_wwwPref,
                               "wwwSecurity.v",
                               objDesc_wwwSecurity,
                               "wwwSrc.v",
                               objDesc_wwwSrc,
                               "wwwURL.v",
                               objDesc_wwwURL,
                               (char*)0,
                               (char**)0};
