#include "objs.h"

static char _slotValue_res0[] = "res";
static char _slotValue_res1[] = "generic";
static char _slotValue_res2[] = "\n\n/*\nxx = \"\\n\\n\\\\p(ht.lines.small.gif)\";\nprint(\"before {\", xx, \"}\\n\");\nprint(\"after {\", trimEdgeQ(xx), \"}\\n\");\nexit(0);\n\nurl = \"http://pebble/vdoc\";\nprint(\">>>>>>>>>>>>>>>>>>>>>>>>>URL=\", url, \"\\n\");\nx = HTTPGet(url);\nnormURL = send(\"normalizeURL\", \"normalizeURL\", url);\nprint(\">>>>>>>>>>>>>>>>>>>>>>>>>URL=\", url, \"\\n\");\nprint(\">>>>>>>>>>>>>>>>>>>>>>>>>normURL=\", normURL, \"\\n\");\n\nurl = \"http://pebble\";\nprint(\">>>>>>>>>>>>>>>>>>>>>>>>>URL=\", url, \"\\n\");\nx = HTTPGet(url);\nnormURL = send(\"normalizeURL\", \"normalizeURL\", url);\nprint(\">>>>>>>>>>>>>>>>>>>>>>>>>URL=\", url, \"\\n\");\nprint(\">>>>>>>>>>>>>>>>>>>>>>>>>normURL=\", normURL, \"\\n\");\n\nexit(0);\n*/\n/*\nprint(\"start-------\\n\");\nfor (i = 0; i < 1000; i++) {\n\tlappend(i, 0);\n\txxx n[i] = 0;\n}\n\nprint(\"end---------\\n\");\nexit(0);\n*/\n\tswitch (arg[0]) {\n\tcase \"targetSet\":\n\t\tshell(\"targetSet\");\n\t\treturn;\n\tbreak;\n\tcase \"incAppCount\":\n\t\t++appCount;\n\t\treturn;\n\tbreak;\n\tcase \"decAppCount\":\n\tcase \"quit\":\n\t\t--appCount;\n\t\tif (appCount <= 0) quit();\n\t\treturn;\n\tbreak;\n/*\n\tcase \"fifi\":\n\t\tx += 10;\n\t\treturn x;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tx = 1;\n\t\tsend(self(), \"foo\", x, x += 100,\n\t\t\tsend(self(), \"fifi\"));\n\tbreak;\n\tcase \"foo\":\n\t\tprint(\"FOO:\\n\");\n\t\tprint(\"arg[1]=\", arg[1], \"\\n\");\n\t\tprint(\"arg[2]=\", arg[2], \"\\n\");\n\t\tprint(\"arg[3]=\", arg[3], \"\\n\");\n\t\treturn;\n\tbreak;\n*/\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_res[] = {
    {"name", _slotValue_res0},
    {"class", _slotValue_res1},
    {"script", _slotValue_res2},
    {(char*)0, (char*)0},
};

static char _slotValue_res_font0[] = "res.font";
static char _slotValue_res_font1[] = "generic";
static char _slotValue_res_font2[] = "\n \t/*\n\t** Font resource object\n \t*/\n\tswitch (arg[0]) {\n\tcase \"id\":\n\t\treturn interpret(\"return \" + arg[1] + \";\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\t/*\n\t\t * font ID/name inventory list\n\t\t */\n\t\tfonts[0] = \"fixed\";\n\t\tfonts[1] = \"normal\";\n\t\tfonts[2] = \"normal_large\";\n\t\tfonts[3] = \"normal_largest\";\n\t\tfonts[4] = \"bold\";\n\t\tfonts[5] = \"bold_large\";\n\t\tfonts[6] = \"bold_largest\";\n\t\tfonts[7] = \"italic\";\n\t\tfonts[8] = \"italic_large\";\n\t\tfonts[9] = \"italic_largest\";\n/*\t\tfonts[10] = \"symbol\";*/\n\t\tfonts[10] = \"banner\";\n\t\tfonts[11] = \"banner_large\";\n\t\tfonts[12] = \"banner_largest\";\n\t\tfonts[13] = \"any\";\n\n\t/* \n\t * font fall-back lists\n\t */\n\n\tfixed[0]\t= \"-misc-fixed-medium-r-*-*-14-*-*-*-*-*-*-*\";\n\tfixed[1]\t= \"-misc-fixed-*-*-*-*-*-*-*-*-*-*-*-*\";\n\tfixed[3]\t= \"-misc-fixed-*\";\n\n\tnormal[0]\t= \"-adobe-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\tnormal[1]\t= \"-*-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\tnormal[2]\t= \"-*-*-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\tnormal[3]\t= \"-misc-fixed-*\";\n\n\tnormal_large[0]\t= \"-adobe-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\tnormal_large[1]\t= \"-*-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\tnormal_large[2]\t= \"-*-*-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\tnormal_large[3]\t= \"-misc-fixed-*\";\n\n\tnormal_largest[0] =\"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tnormal_largest[1] = \"-*-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tnormal_largest[2] = \"-*-*-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tnormal_largest[3] = \"-misc-fixed-*\";\n\n\tbold[0]\t\t= \"-adobe-helvetica-bold-r-*-*-14-*-*-*-p-*-*-*\";\n\tbold[1]\t\t= \"-*-helvetica-bold-r-*-*-14-*-*-*-p-*-*-*\";\n\tbold[2]\t\t= \"-*-*-bold-r-*-*-14-*-*-*-p-*-*-*\";\n\tbold[3]\t\t= \"-misc-fixed-*\";\n\n\tbold_large[1]\t= \"-adobe-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\tbold_large[1]\t= \"-*-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\n\tbold_large[2]\t= \"-*-*-bold-r-*-*-27-*-*-*-p-*-*-*\";\n\tbold_large[3]\t= \"-misc-fixed-*\";\n\n\tbold_largest[0]\t= \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbold_largest[1]\t= \"-*-helvetica-bold-r-*-*-24-*-*-*-p-*-*-*\";\n\tbold_largest[2]\t= \"-*-*-bold-r-*-*-24-*-*-*-p-*-*-*\";\n\tbold_largest[3]\t= \"-misc-fixed-*\";\n\n\tbanner[0]\t= \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner[1]\t= \"-*-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner[2]\t= \"-*-*-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner[3]\t= \"-misc-fixed-*\";\n\n\tbanner_large[0]\t= \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner_large[1]\t= \"-*-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner_large[2]\t= \"-*-*-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner_large[3]\t= \"-misc-fixed-*-\";\n\n\tbanner_largest[0] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner_largest[1] = \"-*-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner_largest[2] = \"-*-*-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\tbanner_largest[3] = \"-misc-fixed-*\";\n\n\titalic[0]\t= \"-adobe-helvetica-medium-*-*-*-14-*-*-*-p-*-*-*\";\n\titalic[1]\t= \"-*-helvetica-medium-i-*-*-14-*-*-*-p-*-*-*\";\n\titalic[2]\t= \"-*-*-medium-i-*-*-14-*-*-*-p-*-*-*\";\n\titalic[3]\t= \"-misc-fixed-*\";\n\n\titalic_large[0]\t= \"-adobe-helvetica-medium-i-*-*-17-*-*-*-p-*-*-*\";\n\titalic_large[1]\t= \"-*-helvetica-medium-i-*-*-17-*-*-*-p-*-*-*\";\n\titalic_large[2]\t= \"-*-*-medium-i-*-*-17-*-*-*-p-*-*-*\";\n\titalic_large[3]\t= \"-misc-fixed-*\";\n\n\titalic_largest[0] = \"-adobe-helvetica-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\titalic_largest[1] = \"-*-helvetica-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\titalic_largest[2] = \"-*-*-medium-i-*-*-24-*-*-*-p-*-*-*\";\n\titalic_largest[3] = \"-misc-fixed-*\";\n\n\tsymbol[0] = \"-*-symbol-medium-r-*-*-14-*-*-*-*-*-*-*\";\n\tsymbol[1] = \"-misc-fixed-*\";\n\n\tany[0]\t\t= \"-misc-fixed-medium-r-*-*-14-*-*-*-*-*-*-*\";\n\tany[1]\t\t= \"-*-*-medium-*-*-*-*-*-*-*-*-*-*-*\";\n\tany[2]\t\t= \"-misc-fixed-*\";\n\n/* for violaWWW */\nfonts_HelveticaSmall[0] = \"-misc-fixed-medium-r-*-*-14-*-*-*-*-*-*-*\";\nfonts_HelveticaSmall[1] = \"-adobe-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[2] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[3] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[4] = \"-adobe-helvetica-bold-r-*-*-14-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[5] = \"-adobe-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[6] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[7] = \"-adobe-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[8] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[9] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[10] = \"-adobe-helvetica-medium-r-*-*-16-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[11] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[12] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaSmall[13] = \"-adobe-helvetica-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\nfonts_HelveticaMedium[0] = \"-misc-fixed-medium-r-*-*-16-*-*-*-*-*-*-*\";\nfonts_HelveticaMedium[1] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[2] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[3] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[4] = \"-adobe-helvetica-bold-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[5] = \"-adobe-helvetica-bold-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[6] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[7] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[8] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[9] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[10] = \"-adobe-helvetica-medium-i-*-*-20-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[11] = \"-adobe-helvetica-medium-i-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[12] = \"-adobe-helvetica-medium-i-*-*-34-*-*-*-p-*-*-*\";\nfonts_HelveticaMedium[13] = \"-adobe-helvetica-medium-r-*-*-17-*-*-*-p-*-*-*\";\n\nfonts_HelveticaLarge[0] = \"-misc-fixed-medium-r-*-*-20-*-*-*-*-*-*-*\";\nfonts_HelveticaLarge[1] = \"-adobe-helvetica-medium-r-*-*-20-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[2] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[3] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[4] = \"-adobe-helvetica-bold-r-*-*-20-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[5] = \"-adobe-helvetica-bold-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[6] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[7] = \"-adobe-helvetica-medium-r-*-*-20-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[8] = \"-adobe-helvetica-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[9] = \"-adobe-helvetica-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[10] = \"-adobe-helvetica-medium-i-*-*-20-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[11] = \"-adobe-helvetica-medium-i-*-*-24-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[12] = \"-adobe-helvetica-medium-i-*-*-34-*-*-*-p-*-*-*\";\nfonts_HelveticaLarge[13] = \"-adobe-helvetica-medium-r-*-*-20-*-*-*-p-*-*-*\";\n\nfonts_TimesSmall[0] = \"-misc-fixed-medium-r-*-*-14-*-*-*-*-*-*-*\";\nfonts_TimesSmall[1] = \"-adobe-times-medium-r-*-*-14-*-*-*-p-*-*-*\";\nfonts_TimesSmall[2] = \"-adobe-times-medium-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_TimesSmall[3] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesSmall[4] = \"-adobe-times-bold-r-*-*-14-*-*-*-p-*-*-*\";\nfonts_TimesSmall[5] = \"-adobe-times-bold-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_TimesSmall[6] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesSmall[7] = \"-adobe-times-medium-r-*-*-14-*-*-*-p-*-*-*\";\nfonts_TimesSmall[8] = \"-adobe-times-medium-r-*-*-17-*-*-*-p-*-*-*\";\nfonts_TimesSmall[9] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesSmall[10] = \"-adobe-times-medium-i-*-*-17-*-*-*-p-*-*-*\";\nfonts_TimesSmall[11] = \"-adobe-times-medium-i-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesSmall[12] = \"-adobe-times-medium-i-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesSmall[13] = \"-adobe-times-medium-r-*-*-14-*-*-*-p-*-*-*\";\n\nfonts_TimesMedium[0] = \"-misc-fixed-medium-r-*-*-20-*-*-*-*-*-*-*\";\nfonts_TimesMedium[1] = \"-adobe-times-medium-r-*-*-20-*-*-*-p-*-*-*\";\nfonts_TimesMedium[2] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesMedium[3] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesMedium[4] = \"-adobe-times-bold-r-*-*-20-*-*-*-p-*-*-*\";\nfonts_TimesMedium[5] = \"-adobe-times-bold-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesMedium[6] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesMedium[7] = \"-adobe-times-medium-r-*-*-20-*-*-*-p-*-*-*\";\nfonts_TimesMedium[8] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesMedium[9] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesMedium[10] = \"-adobe-times-medium-i-*-*-20-*-*-*-p-*-*-*\";\nfonts_TimesMedium[11] = \"-adobe-times-medium-i-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesMedium[12] = \"-adobe-times-medium-i-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesMedium[13] = \"-adobe-times-medium-r-*-*-20-*-*-*-p-*-*-*\";\n\nfonts_TimesLarge[0] = \"-adobe-courier-medium-r-*-*-24-*-*-*-*-*-*-*\";\nfonts_TimesLarge[1] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesLarge[2] = \"-adobe-times-medium-r-*-*-27-*-*-*-p-*-*-*\";\nfonts_TimesLarge[3] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesLarge[4] = \"-adobe-times-bold-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesLarge[5] = \"-adobe-times-bold-r-*-*-27-*-*-*-p-*-*-*\";\nfonts_TimesLarge[6] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesLarge[7] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesLarge[8] = \"-adobe-times-medium-r-*-*-27-*-*-*-p-*-*-*\";\nfonts_TimesLarge[9] = \"-adobe-times-medium-r-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesLarge[10] = \"-adobe-times-medium-i-*-*-24-*-*-*-p-*-*-*\";\nfonts_TimesLarge[11] = \"-adobe-times-medium-i-*-*-27-*-*-*-p-*-*-*\";\nfonts_TimesLarge[12] = \"-adobe-times-medium-i-*-*-34-*-*-*-p-*-*-*\";\nfonts_TimesLarge[13] = \"-adobe-times-medium-r-*-*-24-*-*-*-p-*-*-*\";\n\n\treturn 1;\n\tbreak;\n\tcase \"useHelveticaSmallFonts\":\n\t\tfor (i = fonts[] - 1; i >= 0; i--)\n\t\t\tdefineNewFont(i, fonts[i], fonts_HelveticaSmall[i]);\n\t\treturn;\n\tbreak;\n\tcase \"useHelveticaMediumFonts\":\n\t\tfor (i = fonts[] - 1; i >= 0; i--)\n\t\t\tdefineNewFont(i, fonts[i], fonts_HelveticaMedium[i]);\n\t\treturn;\n\tbreak;\n\tcase \"useHelveticaLargeFonts\":\n\t\tfor (i = fonts[] - 1; i >= 0; i--)\n\t\t\tdefineNewFont(i, fonts[i], fonts_HelveticaLarge[i]);\n\t\treturn;\n\tbreak;\n\tcase \"useTimesSmallFonts\":\n\t\tfor (i = fonts[] - 1; i >= 0; i--)\n\t\t\tdefineNewFont(i, fonts[i], fonts_TimesSmall[i]);\n\t\treturn;\n\tbreak;\n\tcase \"useTimesMediumFonts\":\n\t\tfor (i = fonts[] - 1; i >= 0; i--)\n\t\t\tdefineNewFont(i, fonts[i], fonts_TimesMedium[i]);\n\t\treturn;\n\tbreak;\n\tcase \"useTimesLargeFonts\":\n\t\tfor (i = fonts[] - 1; i >= 0; i--)\n\t\t\tdefineNewFont(i, fonts[i], fonts_TimesLarge[i]);\n\t\treturn;\n\tbreak;\n\tcase \"useAllFixedFonts\":\n\t\tfor (i = fonts[] - 1; i >= 0; i--)\n\t\t\tdefineNewFont(i, fonts[i], \"-misc-fixed-medium-*\");\n\t\treturn;\n\tbreak;\n\tcase \"queryFontID\":\n\t\treturn getVariable(arg[1]);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_res_HTMLStyle3[] = "\nsend(\"SGML_vobjf\", \"init\");\n/*\nsend(\"SGML_vobjf\", 'D');\nprint(\"1000 % 7=\", 1000 % 7, \"...............\\n\");\n\nprint(\"=Hi there!=========================================\\n\");\nx = 199;\ny = 41;\nLucifer[666] = \"evil\";\nprint(\"x=\", x, \"<<<\\n\");\nprint(\"y=\", y, \"<<<\\n\");\nprint(\"Luci=\", Lucifer[666], \"<<<\\n\");\nprint(\"Arg[0]=\", arg[0], \"<<<\\n\");\nprint(\"=goodbye!=========================================\\n\");\n*/\n\t/**\n \t*** A makeshift HTML Style sheet resource object\n \t**/\n\tswitch (arg[0]) {\n\tcase \"id\":\n/*\n\t\tprint(\"=BEGIN============================================\\n\");\n\t\tfoo = get(\"name\");\n\t\tprint(\"=END==============================================\\n\");\n\t\treturn interpret(\"return \" + arg[1] + \";\");\n*/\n\tbreak;\n\tcase \"init\":\n\t/*      tag                             wrap first   right  after\n\t *               font           align     free   left    before\n\t */\n\n\t\tS       = \"normal        left   1 1  0   0   0   0  0\";\n\t\tP       = \"normal        left   1 0  24  24  24  0  1\";\n\t\tOL      = \"normal        left   1 0  24  24  8   0  0\";\n\t\tUL      = \"normal        left   1 0  24  24  8   0  0\";\n\t\tULC     = \"normal        left   1 0  24  24  24  0  0\";\n\t\tDL      = \"normal        left   1 0  24  150 24  0  1\";\n\t\tDLC     = \"normal        left   1 0  24  150 8   0  1\";\n\t\tLI      = \"normal        left   1 0  24  24  24  0  1\";\n\t\tDIR     = \"normal        left   1 0  24  24  24  1  0\";\n\t\tMENU    = \"normal        left   1 0  24  24  24  1  0\";\n\t\tHP      = \"normal        left   1 0  0   0   0   1  0\";\n\t\tXMP     = \"fixed         left   0 1  0   0   1   1  0\";\n\t\tXMPA    = \"fixed         left   0 1  0   0   1   1  0\";\n\t\tPRE     = \"fixed         left   0 1  0   0   1   1  1\";\n\t\tLISTING = \"normal        left   0 1  0   0   1   1  0\";\n\t\tADDRESS = \"bold_largest  right  0 0  0   0   24  1  1\";\n\t\tH1      = \"bold_large    left   0 0  0   0   10   0  0\";\n\t\tH2      = \"bold          left   1 0  0   0   8   0  0\";\n\t\tH3      = \"bold          left   1 0  24  24  0   0  0\";\n\t\tH4      = \"bold          left   1 0  24  24  0   0  0\";\n\t\tH5      = \"bold          left   1 0  64  64  0   0  0\";\n\t\tH6      = \"bold          left   1 0  128 128 0   0  0\";\n\t\tH7      = \"bold          left   1 0  160 170 0   0  0\";\n\treturn 1;\n\tbreak;\n\tcase \"queryFontID\":\n\t\treturn getVariable(arg[1]);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_res_dialogWithButtons5[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tnewDialogBox = clone(id);\n\t\t++id;\n\n\t\twindowName(\"Please respond to this dialog box.\");\n\n\t\tsend(newDialogBox, \"show_mesg\", arg[1]);\n\t\tfor (argi = 2; argi < arg[]; argi += 2)\n\t\t\tsend(newDialogBox, \"adopt\", arg[argi], arg[argi + 1]);\n\t\tsend(newDialogBox, \"visible\", 1);\n\n\t\treturn newDialogBox;\n\tbreak;\n\tcase \"showAt\":\n\t\tset(\"x\", arg[1]);\n\t\tset(\"y\", arg[2]);\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\n\t\tnewDialogBox = clone(id);\n\t\t++id;\n\n\t\twindowName(\"Please respond to this dialog box.\");\n\n\t\tsend(newDialogBox, \"show_mesg\", arg[5]);\n\t\tfor (argi = 6; argi < arg[]; argi += 2)\n\t\t\tsend(newDialogBox, \"adopt\", arg[argi], arg[argi + 1]);\n\t\tsend(newDialogBox, \"visible\", 1);\n\n\t\treturn newDialogBox;\n\tbreak;\n\tcase \"adopt\":\n\t\treturn send(nthChild(1), \"adopt\", arg[1], arg[2]);\n\tbreak;\n\tcase \"show_mesg\":\n\t\treturn send(nthChild(0), \"show\", arg[1]);\n\tbreak;\n\tcase \"done\":\n\t\tset(\"visible\", 0);\n\t\tafter(1000, self(), \"freeSelf\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_res_dialogWithButtons6[] = "res.dialogWithButtons.mesg res.dialogWithButtons.buttons";
/* END OF OBJ */

static char _slotValue_res_dialogWithButtons8[] = "txtDisp";
static char _slotValue_res_dialogWithButtons9[] = "res.dialogWithButtons.mesg";
static char _slotValue_res_dialogWithButtons10[] = "res.dialogWithButtons";
static char _slotValue_res_dialogWithButtons11[] = "4";
static char _slotValue_res_dialogWithButtons12[] = "4";
static char _slotValue_res_dialogWithButtons13[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tres.dialogWithButtons.buttons(\"cinfo\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_res_dialogWithButtons14[] = "normal";
/* END OF OBJ */

static char _slotValue_res_dialogWithButtons16[] = "hpane";
static char _slotValue_res_dialogWithButtons17[] = "res.dialogWithButtons.buttons";
static char _slotValue_res_dialogWithButtons18[] = "res.dialogWithButtons";
static char _slotValue_res_dialogWithButtons19[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n/*\t\tprint(\"----------------------------------GGG\\n\");\n\t\tfor (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\t\tprint(\"\\n\");\n*/\n\tbreak;\n\tcase \"cinfo\":\n\t\tobjectListSend(\"children\", \"info\");\n\tbreak;\n\tcase \"done\":\n\t\tsend(parent(), arg[0]);\n\t\tset(\"children\", \"\");\n/*\t\tafter(1111, self(), \"rip\");*/\n\t\treturn;\n\tbreak;\n\tcase \"rip\":\n/*\t\tobjectListSend(\"children\", \"freeSelf\");*/\n\t\tset(\"children\", \"\");\n\t\treturn;\n\tbreak;\n\tcase \"adopt\":\n\t\t/* arg[1] = <label>\n\t\t * arg[2] = <action script>\n\t\t */\n/*\n\t\tprint(\"----------------------------------\\n\");\n\t\tprint(\"arg[1]>>>>\", arg[1], \"<<\\n\");\n\t\tprint(\"arg[2]>>>>\", arg[2], \"<<\\n\");\n*/\n\t\tcname = concat(\"foo\", countChildren() + 1);\n/*\t\tprint(\"cname>>>>\", cname, \"<<\\n\");\n*/\n\t\tcscript = concat(\"if (arg[0] == \\\"buttonRelease\\\") {\", \n\t\t\t\t\targ[2], \n\t\t\t\t\t\"\\n send(parent(), \\\"done\\\");}\\n\",\n\t\t\t\t\t\"usual();\");\n/*\t\tprint(\"cscript>>>>\", cscript, \"<<\\n\");\n*/\n\t\tnewobj = create(\"name\", cname,\n\t\t\t\t\"class\", \"txtButton\",\n\t\t\t\t\"parent\", self(),\n\t\t\t\t\"label\", arg[1],\n\t\t\t\t\"script\", cscript,\n\t\t\t\t\"width\", \"50\",\n\t\t\t\t\"height\", \"50\",\n\t\t\t\t\"font\", \"any\",\n\t\t\t\t\"gapH\", \"10\");\n\n\t\tset(\"children\", concat(get(\"children\"), \" \", newobj));\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_res_getLineEntry5[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\t/* arg[1]\tdisplay message\n\t\t * arg[2]\tdefault entry\n\t\t * arg[3]\tcaller, the obj to return result to\n\t\t * arg[4]\treturning message token\n\t\t * arg[5]\toptional x position\n\t\t * arg[6]\toptional y position\n\t\t */\n\t\tnewObj = clone(id);\n\t\tid++;\n\t\tif (arg[] > 5)\n\t\t  return send(newObj, \"_show\", arg[1], arg[2], arg[3], arg[4],\n\t\t\t\targ[5], arg[6]);\n\t\telse \n\t\t  return send(newObj, \"_show\", arg[1], arg[2], arg[3], arg[4]);\n\tbreak;\n\tcase \"_show\":\n\t\tif (arg[] > 5) {\n\t\t\tset(\"x\", arg[5]);\n\t\t\tset(\"y\", arg[6]);\n\t\t}\n\t\tsend(nthChild(0), \"show\", arg[1]);\n\t\tsend(nthChild(1), \"show\", arg[2]);\n\t\tcaller = arg[3];\n\t\treturnMessage = arg[4];\n\n\t\twindowName(\"Attention, please...\");\n\t\tsend(newObj, \"visible\", 1);\n\t\tset(\"visible\", 1);\n\t\treturn self();\n\tbreak;\n\tcase \"_ok\":\n\t\tset(\"visible\", 0);\n\t\tsend(caller, returnMessage, send(nthChild(1), \"contentP\"));\n\t\treturn;\n\tbreak;\n\tcase \"_cancel\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_res_getLineEntry6[] = "res.getLineEntry.mesg res.getLineEntry.entry res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry7[] = "6";
/* END OF OBJ */

static char _slotValue_res_getLineEntry9[] = "txtDisp";
static char _slotValue_res_getLineEntry10[] = "res.getLineEntry.mesg";
static char _slotValue_res_getLineEntry11[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry12[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_res_getLineEntry13[] = "2";
static char _slotValue_res_getLineEntry14[] = "2";
static char _slotValue_res_getLineEntry15[] = "normal";
/* END OF OBJ */

static char _slotValue_res_getLineEntry17[] = "txtEdit";
static char _slotValue_res_getLineEntry18[] = "res.getLineEntry.entry";
static char _slotValue_res_getLineEntry19[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry20[] = "\n\tswitch (arg[0]) {\n\tcase \"keyPress\":\n\t\tc = key();\n\t\tif (c == '\\r' || c == '\\n') {\n\t\t\tsend(parent(), \"_ok\");\n\t\t\treturn;\n\t\t} else {\n\t\t\tinsert(c);\n\t\t\treturn;\n\t\t}\n\tbreak;\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"contentP\":\n\t\treturn get(\"content\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_res_getLineEntry21[] = "4";
static char _slotValue_res_getLineEntry22[] = "4";
static char _slotValue_res_getLineEntry23[] = "normal";
/* END OF OBJ */

static char _slotValue_res_getLineEntry25[] = "hpane";
static char _slotValue_res_getLineEntry26[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry27[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry28[] = "res.getLineEntry.buttons.ok res.getLineEntry.buttons.cancel";
static char _slotValue_res_getLineEntry29[] = "\n\tswitch (arg[0]) {\n\tcase \"_cancel\":\n\tcase \"_ok\":\n\t\tsend(parent(), arg[0]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_res_getLineEntry30[] = "22";
static char _slotValue_res_getLineEntry31[] = "3";
/* END OF OBJ */

static char _slotValue_res_getLineEntry33[] = "txtButton";
static char _slotValue_res_getLineEntry34[] = "OK";
static char _slotValue_res_getLineEntry35[] = "res.getLineEntry.buttons.ok";
static char _slotValue_res_getLineEntry36[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry37[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"_ok\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_res_getLineEntry38[] = "10";
/* END OF OBJ */

static char _slotValue_res_getLineEntry40[] = "txtButton";
static char _slotValue_res_getLineEntry41[] = "Cancel";
static char _slotValue_res_getLineEntry42[] = "res.getLineEntry.buttons.cancel";
static char _slotValue_res_getLineEntry43[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry44[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"_cancel\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_shell6[] = "\n\tswitch (arg[0]) {\n\tcase \"targetSet\":\n\t\tshell.obj.entry(\"show\");\n\t\treturn;\n\tbreak;\n\tcase \"raise\":\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"dismiss\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_shell25[] = "\n\tswitch (arg[0]) {\n\tcase \"tool\":\n\t\ttool(arg[1]);\n\t\tshell.mesg(\"show\", concatenate(\"current tool: \", arg[1]));\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_shell26[] = "\n.\t{Action}\t\t{shell.top.tools(\"tool\", \"action\");}\n.\t{Target}\t\t{shell.top.tools(\"tool\", \"target\");}\n.\t{Move}\t\t\t{shell.top.tools(\"tool\", \"move\");}\n.\t{Resize}\t\t{shell.top.tools(\"tool\", \"resize\");}\n.\t{Reparent}\t\t{shell.top.tools(\"tool\", \"reparent\");}\n";
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
static char _slotValue_shell37[] = "\n\tswitch (arg[0]) {\n\tcase \"cloneTarget\":\n\t\tnew = tweak(target(), \"clone(1);\");\n\t\tprint(\"newobj=\", new, \"\\n\");\n\t\ttweak(new, \"set(\\\"parent\\\", \\\"\\\");\");\n\t\tsend(new, \"info\");\n\t\tsend(new, \"visible\", 1);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_shell38[] = "\n.\t{Target parent}\t\t{target(tweak(target(), \"get(\\\"parent\\\");\"));}\n.\t{Clone target}\t\t{shell.top.tools(\"cloneTarget\");}\n.\t{Info target}\t\t{tweak(target(), \"info();\");}\n.\t{Save target}\t\t{tweak(target(), \"save();\");}\n.\t{}\n.\t{Create object}\t\t{op_create(\"visible\", 1);}\n.\t{}\n.\t{Vicon}\t\t\t{vicon(\"visible\", 1);}\n.\t{save dump}\t\t{saveAs(\"foo\");}\n.\t{save command text}\t{shell.in.tf(\"saveText\");}\n.\t{load command text}\t{shell.in.tf(\"loadText\");}\n.\t{Quit}\t\t\t{quit();}\n";
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
static char _slotValue_shell49[] = "\n.\t{content}\t\t{ed_TE(\"edit\", target(), \"content\");}\n.\t{script}\t\t{ed_TE(\"edit\", target(), \"script\");}\n.\t{label}\t\t\t{ed_label(\"edit\", target());}\n.\t{BDColor}\t\t{ed_BDColor(\"visible\", 1);}\n.\t{BGColor}\t\t{ed_BGColor(\"visible\", 1);}\n.\t{FGColor}\t\t{ed_FGColor(\"visible\", 1);}\n.\t{CRColor}\t\t{ed_CRColor(\"visible\", 1);}\n.\t{content}\t\t{ed_content(\"visible\", 1);}\n.\t{menuConfig}\t\t{ed_menuConfig(\"visible\", 1);}\n.\t{geometry}\t\t{ed_geometry(\"visible\", 1);}\n.\t{script}\t\t{ed_script(\"visible\", 1);}\n";
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
static char _slotValue_shell65[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"shell\", \"dismiss\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_shell91[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", target());\n\t\tif (get(\"window\")) render();\n\t\treturn;\n\tbreak;\n\tcase \"keyPress\":\n\t\tc = key();\n\t\tif (c == '\\r') {\n\t\t\tif (isBlank(target())) target(\"res\");\n\t\t\ttarget(currentLine());\n\t\t\tshell.obj.entry(\"show\");\n\t\t\treturn;\n\t\t} else {\n\t\t\tinsert(c);\n\t\t\treturn;\n\t\t}\n\tbreak;\n\tcase \"init\":\n\t\tset(\"content\", target());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_shell111[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonPress\":\n/*\t\tprint(\"DUMPING CONTENT\\n {\", get(\"content\"), \"}\\n\");*/\n\tbreak;\n\tcase \"keyPress\":\n\t\tc = key();\n\t\tif (c == '\\r') {\n\t\t\tprint(\"issue command:\", currentLine(), \"\\n\");\n\t\t\tif (isBlank(target())) target(\"res\");\n\t\t\tret = tweak(target(), currentLine());\n\t\t\tshell.obj.entry(\"show\");\n\t\t\tinsert('\\r');\n\t\t\tshell.out.tf(\"insert\", ret);\n\t\t\treturn;\n\t\t} else {\n\t\t\tinsert(c);\n\t\t\treturn;\n\t\t}\n\tbreak;\n\tcase \"saveText\":\n\t\tsaveFile(\".shellCmds\", get(\"content\"));\n\t\treturn;\n\tbreak;\n\tcase \"loadText\":\n\t\tpath = accessible(\".shellCmds\");\n\t\tif (path != \"\") {\n\t\t\tset(\"content\", loadFile(path));\n\t\t\trender();\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tpath = accessible(\".shellCmds\");\n\t\tif (path != \"\") {\n\t\t\tset(\"content\", loadFile(path));\n\t\t}\n\t\tif (isBlank(target())) target(\"res\");\n\tbreak;\n\tcase \"expose\":\n\t\tusual();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_shell134[] = "\n\tswitch (arg[0]) {\n\tcase \"insert\":\n\t\tprint(\"ret = \", arg[1], \"\\n\");\n\t\tinsert(arg[1]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_shell135[] = "shell.out.sb";
static char _slotValue_shell136[] = "1";
static char _slotValue_shell137[] = "fixed";
/* END OF OBJ */

static char _slotValue_shell139[] = "shell.mesg";
static char _slotValue_shell140[] = "txtDisp";
static char _slotValue_shell141[] = "shell";
static char _slotValue_shell142[] = "1";
static char _slotValue_shell143[] = "\n\tif (arg[0] == \"show\") {\n\t\tset(\"content\", arg[1]);\n\t\trender();\n\t\treturn;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_fail2[] = "\n\tswitch (arg[0]) {\n\tcase \"report\":\n\t\treason = arg[1];\n/*print(\"############### FAILURE REPORT ##############\\n\",\nreason, \"\\n#############################################\\n\");\n*/\n\t\treturn;\n\tbreak;\n\tcase \"reportP\":\n\t\treturn reason;\n\tbreak;\n\tcase \"make\":\n\t\tset(\"parent\", arg[1]);\t\n\t\tset(\"name\", arg[2]);\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\n\t\t/* reason of failure assume to be previously reported by\n\t\t * the failure detection point\n\t\t */\n\t\tset(\"content\", VWHandler_fail(\"reportP\"));\n\t\treason = \"Cause of failure unreported.\"; /* reset */\n\n\t\treturn self();\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(arg[1]);\n\tbreak;\n\tcase 'T':\n\t\t/* arg[1] = y\n\t\t * arg[2] = width\n\t\t */\n\t\th = get(\"height\");\n\t\tparentHeight = send(parent(), \"heightP\");\n\t\theightDiff = h - parentHeight;\n\t\tif (heightDiff > 0) {\n\t\t\theightRatio =  float(heightDiff) / -100.0;\n\t\t} else {\n\t\t\theightRatio = 0;\n\t\t\th = parentHeight;\n\t\t\tset(\"height\", h);\n\t\t}\n\t\tprevWidth = arg[2];\n\t\tprevHeight = parentHeight;\n\t\treturn h;\n\tbreak;\n\tcase \"nameAndURL\":\n\t\tdocName = arg[1];\n\t\tdocURL = arg[2];\n\t\treturn;\t\t\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryTitle\":\n\t\treturn \"Access Failure\";\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn 0;\n\tbreak;\n\tcase \"historyRecord\":\n\t\twwwHistory(\"add\", docName, docURL);\n\t\treturn;\n\tbreak;\n\tcase \"raise\":\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"show\":\n\t\tset(\"visible\", 1);\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\traise();\n\t\tif (arg[1] != prevWidth) {\n\t\t\t/* need to re-format */\n\t\t\tsend(self(), \"resize\", arg[1], arg[2]);\n\t\t} else if (arg[2] != prevHeight) {\n\t\t\t/* just adjust window height */\n\t\t\tsend(self(), \"resize\", arg[1], arg[2]);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn self();\n\tbreak;\n\tcase \"yP\":\n\t\treturn y();\n\tbreak;\n\tcase \"y\":\n\t\treturn set(\"y\", arg[1]);\n\tbreak;\n\tcase \"heightP\":\n\tcase \"vspan\":\n\t\treturn height();\n\tbreak;\n\tcase \"VW_relay\":\n\t\trelay_obj[relayIdx] = arg[1];\n\t\trelay_event[relayIdx] = arg[2];\n\t \trelayIdx= relayIdx + 1;\n\t\treturn 1;\n\tbreak;\n\tcase \"VW_event\":\n\t\tevent = arg[1];\n\t\tfor (i = 0; i < relayIdx; i = i + 1) {\n\t\t\tif (relay_event[i] = event) {\n\t\t\t\tsend(relay_obj[i], event);\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_gif2[] = "\n\tswitch (arg[0]) {\n\tcase \"build\":\n\t\t/* arg[1]\tsourcefile\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t * ret\t\tdocumentObject or 0\n\t\t */\n\t\tdocObj = VWHandler_gif.gif(\"clone\");\n\t\tsend(docObj, \"build\", arg[1], arg[2], arg[3], arg[4]);\n\n\t\tif (isBlank(docObj) == 1) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t  concat(\"VWHandler_gif:\\nfailed to access: \", \n\t\t\t\targ[1], \"\\n\"));\n\n\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t    concatenate(\"Failed to get \", arg[1]));\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn 0;\n\t\t} else {\n\t\t\twww.mesg.tf(\"show\", \"\");\n\t\t\twww.udi.tf(\"show\", arg[1]);\n\n\t\t\twww.doc.ctrl.label(\"index\", 0);\n\t\t\twww.doc.ctrl.tf(\"index\", 0);\n\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn docObj;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_VWHandler_gif4[] = "GIF";
static char _slotValue_VWHandler_gif5[] = "VWHandler_gif.gif";
static char _slotValue_VWHandler_gif6[] = "\n\tswitch (arg[0]) {\n\tcase \"y\":\n\t\tset(\"y\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tif (width() != arg[3]) {\n\t\t\tloadDoc = 1;\n\t\t} else if (height() != arg[4]) {\n\t\t\tloadDoc = 1;\n\t\t} else {\n\t\t\tloadDoc = 0;\n\t\t}\n\t\tif (loadDoc == 1) {\n\t\t\tclearWindow();\n\t\t\tset(\"width\", arg[3]);\n\t\t\tset(\"height\", arg[4]);\n\t\t\trender();\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"yP\":\n\t\treturn y();\n\tbreak;\n\tcase \"heightP\":\n\t\treturn height();\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tsourcefile\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t */\n\t\tdocURL = arg[1];\n\t\tdocName = arg[3];\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"name\", docName);\n\n\t\tprevWidth = arg[4];\n\t\tprevHeight = send(parent(), \"heightP\");\n\n\t\tlocalFile = HTTPGet(docURL);\n\t\tif (isBlank(localFile) == 1) {\n\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t    concatenate(\"Failed to get \", arg[1]));\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn 0;\n\t\t} else {\n\t\t\tset(\"width\", 0);\n\t\t\tset(\"height\", 0);\n\t\t\tset(\"label\", localFile);\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn get(\"name\");\n\t\t}\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\traise();\n\t\tif (arg[1] != prevWidth) {\n\t\t\tprevWidth = arg[1];\n\t\t\tset(\"width\", prevWidth);\n\t\t} else if (arg[2] != prevHeight) {\n\t\t\tprevHeight = arg[2];\n\t\t\tset(\"height\", prevHeight);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"historyRecord\":\n\t\twwwHistory(\"add\", docName, docURL);\n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\tset(\"label\", localFile);\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"save\":\n\t\tbell(1);\n\t\treturn;\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryTitle\":\n\t\treturn docName;\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn 0;\n\tbreak;\n\tcase \"tree\":\n\t\t/* produce a n-level anchors tree by recursively fetching\n\t\t * anchor links \n\t\t */\n\t\treturn;\n\tbreak;\n\tcase \"showSrc\":\n/*\n\t\tVWHANDLER_GIF_EDITOR = \"xv\";\n\t\tsystem(concat(VWHANDLER_GIF_EDITOR, \" \", localFile));\n\t\tset(\"label\", localFile);\n\t\trender();\n*/\n\t\tres.dialogWithButtons(\"show\", \n\t\t\t\t    concat(\"For source, please refer to:\\n\",\n\t\t\t\t\t\t \"docName: \", docName, \n\t\t\t\t\t\t \"\\nDoc URL: \", docURL),\n\t\t\t\t\t\"OK\", \"\");\n\t\treturn;\n\tbreak;\n\tcase \"outlineSrc\":\n\t\twww.mesg.tf(\"show\", \n\t\t\t    concatenate(\"Outliner not available for GIF\\n\"));\n\t\treturn;\n\tbreak;\n\tcase \"print\":\n\t\twww.mesg.tf(\"show\", \n\t\t    concat(\"Printing facillity not available for GIF.\\n\"));\n\t\treturn;\n \tbreak;\n\tcase \"torn\":\n\t\tisTorn = 1;\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\t\tset(\"cursor\", 0); \n\t\treturn;\n\tbreak;\n\tcase \"raise\":\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(0);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_hmml2[] = "\n\tswitch (arg[0]) {\n\tcase 'I':\n\t\t/* returns ID for new HMML Internal Object */\n\t\tobjID = objID + 1;\n\t\treturn concat(\"IObj_hmml\", objID);\n\tbreak;\n\tcase 'B':\n\t\t/* arg[1]\tURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t * arg[5]\tanchor\n\t\t * ret\t\tdocumentObject or 0\n\t\t */\n/*\n\t\tprint(\"################\\n\");\n\t\tprint(\"##### HMML #####\\n\");\n\t\tprint(\"################\\n\");\n*/\n\t\tsourceFile = arg[1];\n\t\tlocalFile = HTTPGet(sourceFile);\n\t\tdocName = arg[3];\n/*\n\t\tprint(\"sourceFile='\", sourceFile, \"'\\n\");\n\t\tprint(\"localFile='\", localFile, \"'\\n\");\n*/\n\t\tif (localFile == 0) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t   concat(\"VWHandler_hmml:\\nfailed to fetch source : \", sourceFile));\n\t\t\treturn 0;\n\t\t}\n\t\tif (arg[] < 5) {\n\t\t\targ[4] = send(\"VWHandler_hmml.doc.view\", \"widthP\");\n\t\t}\n/*\n\t\tprint(\"1 tmpFile=\", tmpFile, \"\\n\");\n\t\tprint(\"1 sourceFile = {\", sourceFile, \"}\\n\");\n*/\n\t\ttmpFile = makeTempFile();\n\n/*\n\t\tprint(\"exec: \", concat(sgmlsA2BPath, \" HMML \", localFile, \n\t\t\t\t\t\t\" > \", tmpFile), \"\\n\");\n\t\tprint(\"############ sgmls'ing ########\\n\");\n\t\tstat = system(concat(sgmlsA2BPath, \" HMML \", localFile, \n\t\t\t\t\t\" > \", tmpFile));\n*/\n/*\n\t\tprint(\"exec: \", concat(\"sgmls \", localFile, \n\t\t\t\t\t\t\" > \", tmpFile), \"\\n\");\n\t\tprint(\"############ sgmls'ing ########\\n\");\n*/\n\t\tstat = system(concat(\"sgmls \", localFile, \n\t\t\t\t\t\" > \", tmpFile));\n\n/*\t\tprint(\"stat=\", stat, \"\\n\");*/\n\n/*\t\tsystem(concat(\"rm -f \", localFile));*/\n\n\t\tif (stat == -1) {\n\t\t\tsend(\"VWHandler_fail\", \"reason\", \n\t\t   concat(\"VWHandler_hmml:\\nFailed to convert document from HMML to HMMLB.\\n\",\n\"Possibly due to viola unable to find the programs: sgmlsA2B and/or sgmls\"));\n\n\t\t\treturn 0;\n\t\t}\n/*\n\t\tprint(\"2 tmpFile=\", tmpFile, \"\\n\");\n\t\tprint(\"2 localFile = {\", localFile, \"}\\n\");\n\t\tprint(\"2 sourceFile = {\", sourceFile, \"}\\n\");\n\t\tprint(\"############ building docObj ########\\n\");\n\t\tprint(\"url='\", arg[1], \"'\\n\");\n*/\n\t\tHTTPCurrentDocAddrSet(sourceFile);\n\n\t\tdocObj = SGMLBuildDoc(UNUSED,\n\t\t\t    tmpFile, arg[2], docName, arg[4], arg[5]);\n\n\t\tsend(docObj, \"nameAndURL\", docName, sourceFile);\n\n\t\ttweak(docObj, concat(\"set(\\\"name\\\", \\\"\", docName, \"\\\");\"));\n\n\t\tsystem(concat(\"rm -f \", tmpFile));\n\n\t\treturn docName;\n\tbreak;\n\tcase \"out\":\n\t\tfor (i = 1; i < arg[]; i = i + 1) {\n\t\t\tprint(\"#### \", arg[i]);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\t/* use sgmlsA2B to genereate binary format \n\t\t */\n\t\tsgmlsA2BPath = \"sgmlsA2B\";\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_hmml[] = {
    {"class", _slotValue_VWHandler_hmml0},
    {"name", _slotValue_VWHandler_hmml1},
    {"script", _slotValue_VWHandler_hmml2},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_hmml_fail0[] = "txtDisp";
static char _slotValue_VWHandler_hmml_fail1[] = "VWHandler_fail";
static char _slotValue_VWHandler_hmml_fail2[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\tset(\"content\", arg[1]);\t\t\n\t\tset(\"width\", arg[2]);\t\t\n\t\tset(\"height\", arg[3]);\t\t\n\t\treturn self();\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(arg[1]);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_hmmlb3[] = "\n\tswitch (arg[0]) {\n\tcase 'I':\n\t\t/* returns ID for new HMMLB Internal Object */\n\t\tobjID = objID + 1;\n\t\treturn concat(\"IObj_hmmlb\", objID);\n\tbreak;\n\tcase 'B':\n\t\t/* arg[1]\tURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t * arg[5]\tanchor\n\t\t * ret\t\tdocumentObject or 0\n\t\t */\n\n\t\tif (arg[] < 5) {\n\t\t\targ[4] = send(\"VWHandler_hmmlbb.doc.view\", \"widthP\");\n\t\t}\n/*\n\t\tprint(\"################\\n\");\n\t\tprint(\"##### HMMLB ####\\n\");\n\t\tprint(\"################\\n\");\n\t\tprint(\"############ building docObj ########\\n\");\n\t\tprint(\"url='\", arg[1], \"'\\n\");\n*/\n\t\tsourceFile = arg[1];\n\t\tlocalFile = HTTPGet(sourceFile);\n\t\tdocName = arg[3];\n\n\t\tif (isBlank(localFile)) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t  concat(\"VWHandler_hmmlb:\\nfailed to access: \", \n\t\t\t\tsourceFile, \"\\n\"));\n\t\t\treturn 0;\n\t\t}\n\n\t\tHTTPCurrentDocAddrSet(sourceFile);\n\n\t\tdocObj = SGMLBuildDocB(UNUSED,\n\t\t\t    localFile, arg[2], docName, arg[4], arg[5]);\n\n\t\tsend(docObj, \"nameAndURL\", docName, arg[1]);\n\t\ttweak(docObj, concat(\"set(\\\"name\\\", \\\"\", docName, \"\\\");\"));\n\n\t\tsystem(concat(\"rm -f \", localFile));\n\t\treturn docName;\n\tbreak;\n\tcase \"out\":\n\t\tfor (i = 1; i < arg[]; i = i + 1) {\n\t\t\tprint(\"#### \", arg[i]);\n\t\t}\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_html2[] = "\n\tswitch (arg[0]) {\n\tcase 'B':\n\t\t/* arg[1]\tURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t * ret\t\tdocumentObject or 0\n\t\t */\n\n\t\tdocName = arg[3];\n\t\tdocObj = VWHandler_html.tf(\"clone\");\n\n\t\tif (docObj == 0) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t  concat(\"VWHandler_html:\\nfailed to clone, for: \", \n\t\t\t\targ[1], \"\\n\"));\n\t\t\treturn 0;\n\t\t}\n\n\t\tHTTPCurrentDocAddrSet(arg[1]);\n\n\t\tdocObj = send(docObj,\n\t\t\t\t\"build\", arg[1], arg[2], arg[3], arg[4]);\n\n\t\tif (docObj == 0) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t  concat(\"VWHandler_html:\\nfailed to access: \", \n\t\t\t\targ[1], \"\\n\"));\n\t\t\treturn 0;\n\t\t}\n\n\t\treturn docObj;\n\n\t\tif (status == 0) {\n\t\t\t/* better destroy the useless clone */\n\t\t\tsend(docObj, \"freeSelf\");\n\t\t\treturn 0;\n\t\t} else {\n\t\t\treturn docObj;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_VWHandler_html4[] = "HTML";
static char _slotValue_VWHandler_html5[] = "VWHandler_html.tf";
static char _slotValue_VWHandler_html6[] = "\n\t/* reminder: get rid of obsolete cases\n\t */\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\tset(\"y\", arg[1] * heightRatio);\n\t\treturn;\n\tbreak;\n\tcase \"resize\":\n\t\t/* arg[1]\twidth\n\t\t * arg[2]\theight\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"HTML\");\n\t\tset(\"y\", style[0]);\n\t\tset(\"width\", arg[1] - x() - style[3]);\n\n\t\tparentHeight = send(get(\"parent\"), \"heightP\");\n\t\tif (vspan >= parentHeight) {\n\t\t\tset(\"height\", vspan);\n\t\t} else {\n\t\t\tset(\"height\", parentHeight);\n\t\t}\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\tset(\"visible\", 1);\n\t\tif (get(\"window\")) raise();\n\t\tif (arg[1] != prevWidth) {\n\t\t\t/* need to re-format */\n\t\t\tsend(self(), \"resize\", arg[1], arg[2]);\n\t\t} else if (arg[2] != prevHeight) {\n\t\t\t/* just adjust window height */\n\t\t\tsend(self(), \"resize\", arg[1], arg[2]);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tvspan = building_vspan();\n\t\treturn;\n\tbreak;\n\tcase 'T':\n\t\t/* arg[1] = y\n\t\t * arg[2] = width\n\t\t */\n\t\th = get(\"height\");\n\t\tparentHeight = send(parent(), \"heightP\");\n\t\theightDiff = h - parentHeight;\n\t\tif (heightDiff > 0) {\n\t\t\theightRatio =  float(heightDiff) / -100.0;\n\t\t} else {\n\t\t\theightRatio = 0;\n\t\t\th = parentHeight;\n\t\t\tset(\"height\", h);\n\t\t}\n\t\tprevWidth = arg[2];\n\t\tprevHeight = parentHeight;\n\t\treturn h;\n\tbreak;\n\tcase \"buttonRelease\":\n\t\treturn HTML_txt(arg);\n\tbreak;\n\tcase \"yP\":\n\t\treturn y();\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"heightP\":\n\t\treturn height();\n\tbreak;\n\tcase \"reportTitle\":\n\t\tdocTitle = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"vspan\":\n\t\treturn vspan;\n\tbreak;\n\tcase \"y\":\n\t\treturn set(\"y\", arg[1]);\n\tbreak;\n\tcase \"heightP\":\n\tcase \"vspan\":\n\t\treturn height();\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tsourcefile\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t */\n\t\tdocURL = arg[1];\n\t\tdocName = arg[3];\n\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"name\", arg[3]);\n\t\tset(\"width\", arg[4]);\n\n\t\tstat = set(\"HTMLAddress\", docURL);\n\n\t\tif (stat == 0) return 0;\n\n/*\t\tset(\"children\", docObj);*/\n/*\t\tsend(docObj, \"nameAndURL\", docName, docURL);*/\n/*\t\ttweak(docObj, concat(\"set(\\\"name\\\", \\\"\", docName, \"\\\");\"));*/\n/*\t\tvspan = send(docObj, \"vspan\");*/\n\n\t\t/* this is a temporary kludge, where the HTML object's window\n\t\t * is as big as the document vspan. \n\t\t */\n\t\tvspan = building_vspan();\n\t\tset(\"height\", vspan);\n\n\t\treturn self();\n\tbreak;\n\tcase \"historyRecord\":\n\t\twwwHistory(\"add\", get(\"HTMLTitle\"), get(\"HTMLAddress\"));\n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\tclearWindow();\n\t\tpurgeCache(self());\n\t\tset(\"HTMLAddress\", get(\"HTMLAddress\"));\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"search\":\n\t\tcursorShape(\"busy\");\n\t\tsearch(arg[1]);\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"keyPress\":\n/*\t\twww.doc.ctrl.tf(\"focus\");*/\n\t\treturn;\n\tbreak;\n\tcase \"save\":\n\t\ttmp = \"/tmp/out.html\";\t/* later, use dialog box */\n\t\tcmd = concat(\"www -n \", \n\t\t\t\tget(\"HTMLAddress\"), \" > \", \n\t\t\t\ttmp);\n\t\tsystem(cmd);\n\t\treturn;\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn get(\"HTMLAddress\");\n\tbreak;\n\tcase \"queryTitle\":\n\t\treturn get(\"HTMLTitle\");\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn get(\"HTMLIsIndex\");\n\tbreak;\n\tcase \"tree\":\n\t\t/* produce a n-level anchors tree by recursively fetching\n\t\t * anchor links \n\t\t */\n\t\treturn;\n\tbreak;\n\tcase \"showSrc\":\n\t\twwwSrc(\"showByURL\", get(\"HTMLAddress\"));\n/*\t\twwwHTMLSrc(\"show\", \n\t\t\tget(\"name\"), get(\"HTMLAddress\"), get(\"HTMLSource\"));\n*/\n\t\treturn;\n\tbreak;\n\tcase \"updateSrc\":\n\t\t/* arg[1]\tnew HTMLSource\n\t\t */\n\t\ttmp = concat(makeTempFile(), \".html\");\n\t\tsaveFile(tmp, arg[1]);\n\t\tset(\"HTMLAddress\", tmp);\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"outlineSrc\":\n\t\twww.mesg.tf(\"show\", \"Outliner not available for HTML.\");\n\t\treturn;\n\tbreak;\n\tcase \"print\":\n\t\t/* This facility could be much better. But for now...\n\t\t * Todo:\n\t\t *\tconvert to TeX\n\t\t * \t  or generate postscript (use variable width font)\n\t\t * \tuse internal formatter (no need to call www)\n\t\t * \tuse cached HTMLSource (no need to fetch html file)\n\t\t */\n\t\tlprCmd = environVar(\"WWW_LPR\");\n\t\tif (isBlank(lprCmd)) lprCmd = \"lpr \";\n\t\ttmp = concat(makeTempFile(), \".html\");\n\t\twww.mesg.tf(\"flash\", \n\t\t\tconcat(\"Printing command: \", lprCmd));\n\t\tsystem(concat(\"www -n \", get(\"HTMLAddress\"), \" > \", tmp));\n\t\tsystem(concat(lprCmd, \" \", tmp));\n\t\tsystem(concat(\"rm -f \", tmp));\n\t\treturn;\n \tbreak;\n\tcase \"output2File\":\n\t\tres.getLineEntry(\"show\", \n\t\t\t\"Enter file name to save to document source to:\", \n\t\t\t\t\"/tmp/out.html\",\n\t\t\t\tself(), \"gotOutputFileName\");\n\t\treturn;\n \tbreak;\n\tcase \"gotOutputFileName\":\n\t\tdumpFile = HTTPGet(docURL);\n\t\tsystem(concat(\"mv \", dumpFile, \" \", arg[1]));\n\t\twww.mesg.tf(\"show\", \n\t\t\tconcat(\"Source saved to file: \", arg[1]));\n\t\treturn;\n \tbreak;\n\tcase \"torn\":\n\t\tvspan = building_vspan();\n\t\tisTorn = 1;\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\t\tset(\"cursor\", 0); \n\t\treturn;\n\tbreak;\n\tcase \"raise\":\n\t\tif (get(\"window\")) raise();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\tid = id + 1;\n\t\treturn clone(id);\n\tbreak;\n\tcase \"freeSelf\":\n\t\tfreeSelf();\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\teventMask(\"-enterWindow -leaveWindow -keyPress -keyRelease\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_html22[] = "\n\tswitch (arg[0]) {\n\tcase 'B':\n\t\t/* arg[1]\tURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t * arg[5]\tanchor\n\t\t * arg[6]\tdoPost\n\t\t * arg[7]\tpostData\n\t\t * ret\t\tdocumentObject or 0\n\t\t */\n\t\tdoPost = arg[6];\n\t\tsourceFile = arg[1];\n\t\tdocName = arg[3];\n\n\t\tsend(\"www.mesg.tf\", \"show\", \"Connecting to data provider...\");\n\n\t\tif (doPost) {\n\t\t\tdocObj = HTTPPost(sourceFile, arg[2], arg[4], arg[7]);\n\t\t} else {\n\t\t\tdocObj = HTTPGetNParse(sourceFile, arg[2], arg[4]);\n\t\t}\n\n\t\tif (exist(docObj) == 0) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t  concat(\"VWHandler_html2:\\nfailed to access: \", \n\t\t\t\tsourceFile, \"\\n\"));\n\t\t\treturn 0;\n\t\t}\n\n\t\tdocName = trimEdge(docName);\n\n\t\tsend(docObj, \"nameAndURL\", docName, sourceFile);\n\n\t\ttweak(docObj, concat(\"set(\\\"name\\\", \\\"\", docName, \"\\\");\"));\n\n\t\treturn docName;\n\tbreak;\n\tcase \"out\":\n\t\tfor (i = 1; i < arg[]; i++) print(\"#### \", arg[i]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_VWHandler_html2[] = {
    {"class", _slotValue_VWHandler_html20},
    {"name", _slotValue_VWHandler_html21},
    {"script", _slotValue_VWHandler_html22},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_plaintext0[] = "generic";
static char _slotValue_VWHandler_plaintext1[] = "VWHandler_plaintext";
static char _slotValue_VWHandler_plaintext2[] = "\n\tswitch (arg[0]) {\n\tcase \"build\":\n\t\t/* arg[1]\tdocURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t * ret\t\tdocumentObject or 0\n\t\t */\n\t\tdocObj = VWHandler_plaintext.tf(\"clone\");\n\t\tsend(docObj, \"build\", arg[1], arg[2], arg[3], arg[4]);\n\n\t\tif (isBlank(docObj)) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t  concat(\"VWHandler_plaintext:\\nfailed to access: \", \n\t\t\t\targ[1], \"\\n\"));\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn 0;\n\t\t} else {\n\t\t\treturn docObj;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_VWHandler_plaintext4[] = "txtDisp";
static char _slotValue_VWHandler_plaintext5[] = "VWHandler_plaintext.tf";
static char _slotValue_VWHandler_plaintext6[] = "\n/*\nprint(\"VWHandler_plaintext.tf: self=\", self(), \": \");\nfor (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");print(\"...end\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\treturn set(\"shownPositionV\", arg[1]);\n\tbreak;\n\tcase \"tile\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tif (width() != arg[2]) {\n\t\t\tloadDoc = 1;\n\t\t} else if (height() != arg[3]) {\n\t\t\tloadDoc = 1;\n\t\t} else {\n\t\t\tloadDoc = 0;\n\t\t}\n\t\tif (loadDoc == 1) {\n\t\t\tset(\"y\", arg[1]);\n\n\t\t\tprevWidth = arg[2];\n\t\t\tprevHeight = arg[3];\n\t\t\tset(\"width\", arg[2]);\n\t\t\tset(\"height\", arg[3]);\n\t\t\trender();\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\tset(\"visible\", 1);\n\t\tset(\"width\", arg[1]);\n\t\tset(\"height\", arg[2]);\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"resize\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\tset(\"width\", arg[1]);\n\t\tset(\"height\", arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tif (charButtonMask() > 0) {\n\t\t\t/* has pressed inside a ``button'' */\n\t\t\ttag = nextTag();\n\t\t\tif (tag) {\n\t\t\t\tif (nthChar(tag, 1) == '*') {\n\t\t\t\t\tinterpret(tag);\n\t\t\t\t} else {\n\t\t\t\t\twww(\"raise\");\n\t\t\t\t\tif (www(\"show\", tag))\n\t\t\t\t\t\twww(\"historyRecord\");\n\t\t\t\t}\n\t\t\t} else {\n\t\t\t\tbell();\n\t\t\t\twww.mesg.tf(\"warn\", \n\t\t\t\t    \"Try clicking the ending parts.\");\n\t\t\t}\n\t\t} else {\n\t\t\t/* lets user complete cut/paste */\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"yP\":\n\t\treturn get(\"y\");\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"vspan\":\n\t\treturn vspan;\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tdocURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t */\n\t\tdocURL = arg[1];\n\t\tlocalFile = HTTPGet(docURL);\n\t\tdocName = arg[3];\n\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"name\", docName);\n\n\t\tif (localFile == 0) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n   concat(\"VWHandler_plaintext:\\nfailed to fetch source : \", docURL));\n\t\t\treturn 0;\n\t\t}\n\t\taddrInfo = HTTPCurrentDocAddrParsed(docURL);\n\n\t\tif (accessible(localFile) == 0) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t\tconcat(\"Unable to find (local) file: \",\n\t\t\t\t\tlocalFile));\n\t\t\treturn 0;\n\t\t}\n\n\t\tif (arg[] < 5) {\n\t\t\targ[4] = send(\"VWHandler_hmml.doc.view\", \"widthP\");\n\t\t}\n\t\tset(\"width\", arg[4]);\n\t\tdata = loadFile(localFile);\n\t\tif (isBlank(data) == 1) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n   concat(\"VWHandler_plaintext:\\nfailed to get: \", arg[1]));\n\t\t\treturn 0;\n\t\t} else {\n\t\t\tset(\"content\", data);\n\t\t\trender();\n\t\t\tdata = 0;/* clear variable*/\n\t\t\tvspan = building_vspan();\n\t\t\treturn docName;\n\t\t}\n\tbreak;\n\tcase \"historyRecord\":\n\t\twwwHistory(\"add\", docURL, docURL); \n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\tset(\"content\", loadFile(docURL));\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"search\":\n\t\tcursorShape(\"busy\");\n\t\tsearch(arg[1]);\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"keyPress\":\n\t\treturn;\n\tbreak;\n\tcase \"save\":\n\t\ttmp = \"/tmp/out.VWHandler_plaintext\";\n\t\tsaveFile(tmp, get(\"content\"));\n\t\tcmd = concat(\"lpr \", tmp);\n\t\tsystem(cmd);\n\t\treturn;\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryTitle\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn 0;\n\tbreak;\n\tcase \"tree\":\n\t\t/* produce a n-level anchors tree by recursively fetching\n\t\t * anchor links \n\t\t */\n\t\treturn;\n\tbreak;\n\tcase \"showSrc\":\n\t\twwwSrc(\"showByURL\", docURL);\n\t\treturn;\n\tbreak;\n\tcase \"output2File\":\n\t\tres.getLineEntry(\"show\", \n\t\t\t\"Enter file name to save to document source to:\", \n\t\t\t\t\"/tmp/out.txt\",\n\t\t\t\tself(), \"gotOutputFileName\");\n\t\treturn;\n \tbreak;\n\tcase \"gotOutputFileName\":\n\t\tdumpFile = HTTPGet(docURL);\n\t\tsystem(concat(\"mv \", dumpFile, \" \", arg[1]));\n\t\twww.mesg.tf(\"show\", \n\t\t\tconcat(\"Source saved to file: \", arg[1], \"\\n\"));\n\t\treturn;\n \tbreak;\n\tcase \"outlineSrc\":\n\t\twww.mesg.tf(\"show\",\n\t\t  \"Outliner not available for VWHandler_plaintext\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"print\":\n\t\ttmp = \"/tmp/out.txt\";\n\t\tsaveFile(tmp, get(\"content\"));\n\t\tlprCmd = environVar(\"WWW_LPR\");\n\t\tcmd = concat(lprCmd, tmp);\n\t\tsystem(cmd);\n\t\twww.mesg.tf(\"flash\", concat(\"Printing command: \", cmd));\n\t\tsystem(concat(\"rm -f \", tmp));\n\t\treturn;\n \tbreak;\n\tcase \"torn\":\n\t\tisTorn = 1;\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\t\tset(\"cursor\", 0); \n\t\treturn;\n\tbreak;\n\tcase \"render\":\n\t\treturn set(\"visible\", 1);\n\tbreak;\n\tcase \"VIEW_ON\":\n\tcase \"VIEW_OFF\":\n\t\treturn;\n\tbreak;\n\tcase \"raise\":\n\t\tif (get(\"window\")) raise();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola.background_doc\");\n\t\tif (color) {\n\t\t\tset(\"BDColor\", color);\n\t\t\tset(\"BGColor\", color);\n\t\t}\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"FGColor\", color);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_vobj2[] = "\n\tswitch (arg[0]) {\n\tcase \"build\":\n\t\t/* arg[1]\tdoc URL\t\t\n\t\t * arg[2]\tdoc name\t(internal ref)\n\t\t * arg[3]\tparent\n\t\t * arg[4]\twidth\n\t\t * arg[5]\theight\n\t\t */\n\t\tn = n + 1;\n\t\treturn send(clone(n), \"make\", \n\t\t\t\targ[1], arg[2], arg[3], arg[4], arg[5]);\n\tbreak;\n\tcase \"render\":\n\t\tusual();\n\t\tobjectListSend(\"children\", \"render\");\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\tdocURL = get(\"label\");\n\t\tdocName = arg[2];\n\n\t\tlocalFile = HTTPGet(docURL);\n\n\t\taddrInfo = HTTPCurrentDocAddrParsed(localFile);\n\n\t\tif (nthChar(addrInfo[2], 0) == '/') {\n\t\t\tpath = addrInfo[2];\n\t\t} else {\n\t\t\tpath = concat(\"/\", addrInfo[2]);\n\t\t}\n\t\tobjFileName = addrInfo[3];\n\n\t\taddrInfo = HTTPCurrentDocAddrParsed(docURL);\n\t\tobjName = nthChar(addrInfo[3], 0, strlen(addrInfo[3]) - 3);\n\n\t\tstat = loadObjFile(path, objFileName);\n\n\t\tsystem(concat(\"rm -f \", localFile));\n\n\t\tif (stat <= 0) {\n\t\t\tprint(\"failed to load obj file {\", objFileName,\n\t\t\t\t\"} in {\", path, \"}\\n\");\n\t\t\t\n\t\t\tnew = send(\"HMML_fail\", \"clone\");\n\t\t\tset(\"children\", new);\n\t\t\tvspan = send(new, \"make\", self(), width(),\n\t\t\t\t     concat(\"Insert failed here: \", docURL));\n\t\t\treturn vspan;\n\t\t}\n\t\tsend(objName, \"init\");\n\t\tset(\"children\", objName);\n\n\t\tset(\"name\", docName);\n\t\tset(\"parent\", arg[3]);\n\t\tset(\"width\", arg[4]);\n\t\tset(\"height\", arg[5]);\n\n\t\ttweak(objName, concat(\"set(\\\"parent\\\",\\\"\", self(), \"\\\");\"));\n\n\t\treturn self();\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\traise();\n\t\tset(\"width\", arg[1]);\n\t\tset(\"height\", arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"resize\":\n\t\t/* to change window sizes */\n\t\tset(\"width\", arg[1]);\n\t\tset(\"height\", arg[2]);\n\n\t\t/* to trigger geometry manager */\n\t\tsend(self(), \"config\", 0, 0, arg[1], arg[2]);\n\n\t\treturn;\n\tbreak;\n\tcase \"vspan\":\n\t\treturn 0;\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryTitle\":\n\t\treturn nthChild(0);\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn 0;\n\tbreak;\n\tcase \"historyRecord\":\n\t\twwwHistory(\"add\", nthChild(0), docURL);\n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\tprint(\"reload for *.v format not yet implemented\\n\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_vobjf2[] = "\n\tswitch (arg[0]) {\n\tcase \"build\":\n\t\t/* arg[1]\tURL\t\t\n\t\t * arg[2]\tdoc name\t(internal ref)\n\t\t * arg[3]\tparent\n\t\t * arg[4]\twidth\n\t\t * arg[5]\theight\n\t\t */\n\t\tn = n + 1;\n\t\treturn send(clone(n), \"make\", \n\t\t\t\targ[1], arg[2], arg[3], arg[4], arg[5]);\n\tbreak;\n\tcase \"render\":\n\t\tusual();\n\t\tobjectListSend(\"children\", \"render\");\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\tdocURL = arg[1];\n\t\tdocName = arg[2];\n\n\t\tlocalFile = HTTPGet(docURL);\n\n\t\taddrInfo = HTTPCurrentDocAddrParsed(localFile);\n\n\t\tif (nthChar(addrInfo[2], 0) == '/') {\n\t\t\tpath = addrInfo[2];\n\t\t} else {\n\t\t\tpath = concat(\"/\", addrInfo[2]);\n\t\t}\n\t\tobjFileName = addrInfo[3];\n\n\t\taddrInfo = HTTPCurrentDocAddrParsed(docURL);\n\t\tobjName = nthChar(addrInfo[3], 0, strlen(addrInfo[3]) - 3);\n\n\t\tstat = loadObjFile(path, objFileName);\n\n\t\tsystem(concat(\"rm -f \", localFile));\n\n\t\tif (stat <= 0) {\n\t\t\tprint(\"failed to load obj file {\", objFileName,\n\t\t\t\t\"} in {\", path, \"}\\n\");\n\t\t\t\n\t\t\tnew = send(\"HMML_fail\", \"clone\");\n\t\t\tset(\"children\", new);\n\t\t\tvspan = send(new, \"make\", self(), width(),\n\t\t\t\t     concat(\"Insert failed here: \", docURL));\n\t\t\treturn vspan;\n\t\t}\n\t\tsend(objName, \"init\");\n\t\tset(\"children\", objName);\n\n\t\tset(\"name\", docName);\n\t\tset(\"parent\", arg[3]);\n\t\tset(\"width\", arg[4]);\n\t\tset(\"height\", arg[5]);\n\n\t\ttweak(objName, concat(\"set(\\\"parent\\\",\\\"\", self(), \"\\\");\"));\n\n\t\treturn self();\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\traise();\n\t\tset(\"width\", arg[1]);\n\t\tset(\"height\", arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"resize\":\n\t\t/* to change window sizes */\n\t\tset(\"width\", arg[1]);\n\t\tset(\"height\", arg[2]);\n\n\t\t/* to trigger geometry manager */\n\t\tsend(self(), \"config\", 0, 0, arg[1], arg[2]);\n\n\t\treturn;\n\tbreak;\n\tcase \"vspan\":\n\t\treturn 0;\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryTitle\":\n\t\treturn nthChild(0);\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn 0;\n\tbreak;\n\tcase \"historyRecord\":\n\t\twwwHistory(\"add\", nthChild(0), docURL);\n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\tprint(\"reload for *.v format not yet implemented\\n\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_xbm2[] = "\n\tswitch (arg[0]) {\n\tcase \"build\":\n\t\t/* arg[1]\tsourcefile\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t * ret\t\tdocumentObject or 0\n\t\t */\n\t\tdocObj = VWHandler_xbm.xbm(\"clone\");\n\t\tsend(docObj, \"build\", arg[1], arg[2], arg[3], arg[4]);\n\n\t\tif (isBlank(docObj) == 1) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t  concat(\"VWHandler_xbm:\\nfailed to access: \", \n\t\t\t\targ[1], \"\\n\"));\n\n\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t    concatenate(\"Failed to get \", arg[1]));\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn 0;\n\t\t} else {\n\t\t\twww.mesg.tf(\"show\", \"\");\n\t\t\twww.udi.tf(\"show\", arg[1]);\n\n\t\t\twww.doc.ctrl.label(\"index\", 0);\n\t\t\twww.doc.ctrl.tf(\"index\", 0);\n\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn docObj;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_VWHandler_xbm4[] = "XBM";
static char _slotValue_VWHandler_xbm5[] = "VWHandler_xbm.xbm";
static char _slotValue_VWHandler_xbm6[] = "\n\tswitch (arg[0]) {\n\tcase \"y\":\n\t\tset(\"y\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tif (width() != arg[3]) {\n\t\t\tloadDoc = 1;\n\t\t} else if (height() != arg[4]) {\n\t\t\tloadDoc = 1;\n\t\t} else {\n\t\t\tloadDoc = 0;\n\t\t}\n\t\tif (loadDoc == 1) {\n\t\t\tclearWindow();\n\t\t\tset(\"width\", arg[3]);\n\t\t\tset(\"height\", arg[4]);\n/*\n\t\t\tdata = loadFile(arg[1]);\n\t\t\tset(\"label\", data);\n\t\t\tsend(parent(), \"update\", vspan);\n\t\t\tvspan = get(\"height\");\n\t\t\tparentHeight = send(parent(), \"heightP\");\n\t\t\tif (vspan >= parentHeight) {\n\t\t\t\tset(\"height\", vspan);\n\t\t\t} else {\n\t\t\t\tset(\"height\", parentHeight);\n\t\t\t}\n*/\n\t\t\trender();\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"yP\":\n\t\treturn y();\n\tbreak;\n\tcase \"heightP\":\n\t\treturn height();\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tdocURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t */\n\t\tdocURL = arg[1];\n\t\tdocName = arg[3];\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"name\", docName);\n\n\t\tprevWidth = arg[4];\n\t\tprevHeight = send(parent(), \"heightP\");\n\n\t\tlocalFile = HTTPGet(docURL);\n\t\tdata = loadFile(localFile);\n\t\tsystem(concat(\"rm -f \", localFile));\n\n\t\tif (isBlank(data) == 1) {\n\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t    concat(\"Failed to get \", docURL));\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn 0;\n\t\t} else {\n\t\t\tset(\"label\", data);\n\t\t\tset(\"width\", prevWidth);\n\t\t\tset(\"height\", prevHeight);\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn get(\"name\");\n\t\t}\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\traise();\n\t\tif (arg[1] != prevWidth) {\n\t\t\tprevWidth = arg[1];\n\t\t\tset(\"width\", prevWidth);\n\t\t} else if (arg[2] != prevHeight) {\n\t\t\tprevHeight = arg[2];\n\t\t\tset(\"height\", prevHeight);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"historyRecord\":\n\t\twwwHistory(\"add\", docName, docURL);\n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\tlocalPath = HTTPGet(docURL);\n\t\tset(\"label\", loadFile(localPath));\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"save\":\n\t\tbell(1);\n\t\treturn;\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryTitle\":\n\t\treturn docName;\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn 0;\n\tbreak;\n\tcase \"tree\":\n\t\t/* produce a n-level anchors tree by recursively fetching\n\t\t * anchor links \n\t\t */\n\t\treturn;\n\tbreak;\n\tcase \"showSrc\":\n\t\tVWHANDLER_XBM_EDITOR = \"bitmap\";\n\t\ttmp = concatenate(makeTempFile(), \".xbm\");\n\t\tsaveFile(tmp, get(\"label\"));\n\t\tsystem(concatenate(VWHANDLER_XBM_EDITOR, \" \", tmp));\n\t\tset(\"label\", loadFile(tmp));\n\t\trender();\n\t\tsystem(concat(\"rm -f \", tmp));\n\t\treturn;\n\tbreak;\n\tcase \"outlineSrc\":\n\t\twww.mesg.tf(\"show\", \n\t\t\t\"Outliner not available for VWHANDLER_XBM\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"cycleColors\":\n\t\tcycleColors(1);\n\t\trender();\n\t\treturn;\n \tbreak;\n\tcase \"reverseVideo\":\n\t\tcycleColors(1);\n\t\tcycleColors(1);\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"colorsBGFGBD\":\n\t\tset(\"BGColor\", arg[1]);\n\t\tset(\"FGColor\", arg[2]);\n\t\tset(\"BDColor\", arg[3]);\n\t\trender();\n\t\treturn;\n \tbreak;\n\tcase \"torn\":\n\t\tisTorn = 1;\n\t\treturn;\n\tbreak;\n\tcase \"raise\":\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(0);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola*background\");\n\t\tif (color) {\n\t\t\tset(\"BGColor\", color);\n\t\t}\n\t\tcolor = getResource(\"Viola*foreground\");\n\t\tif (color) {\n\t\t\tset(\"BDColor\", color);\n\t\t\tset(\"FGColor\", color);\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_VWHandler_xpm2[] = "\n\tswitch (arg[0]) {\n\tcase \"build\":\n\t\t/* arg[1]\tdocURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t * ret\t\tdocumentObject or 0\n\t\t */\n\t\tdocObj = VWHandler_xpm.xpm(\"clone\");\n\t\tsend(docObj, \"build\", arg[1], arg[2], arg[3], arg[4]);\n\n\t\tif (isBlank(docObj) == 1) {\n\t\t\tsend(\"VWHandler_fail\", \"report\", \n\t\t\t  concat(\"VWHandler_xpm:\\nfailed to access: \", \n\t\t\t\targ[1], \"\\n\"));\n\n\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t    concatenate(\"Failed to get \", arg[1]));\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn 0;\n\t\t} else {\n\t\t\twww.mesg.tf(\"show\", \"\");\n\t\t\twww.udi.tf(\"show\", arg[1]);\n\n\t\t\twww.doc.ctrl.label(\"index\", 0);\n\t\t\twww.doc.ctrl.tf(\"index\", 0);\n\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn docObj;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_VWHandler_xpm4[] = "XPM";
static char _slotValue_VWHandler_xpm5[] = "VWHandler_xpm.xpm";
static char _slotValue_VWHandler_xpm6[] = "\n\tswitch (arg[0]) {\n\tcase \"y\":\n\t\tset(\"y\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tif (width() != arg[3]) {\n\t\t\tloadDoc = 1;\n\t\t} else if (height() != arg[4]) {\n\t\t\tloadDoc = 1;\n\t\t} else {\n\t\t\tloadDoc = 0;\n\t\t}\n\t\tif (loadDoc == 1) {\n\t\t\tclearWindow();\n\t\t\tset(\"width\", arg[3]);\n\t\t\tset(\"height\", arg[4]);\n\t\t\trender();\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"yP\":\n\t\treturn y();\n\tbreak;\n\tcase \"heightP\":\n\t\treturn height();\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tdocURL\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tname\n\t\t * arg[4]\twidth\n\t\t */\n\t\tdocURL = arg[1];\n\t\tdocName = arg[3];\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"name\", docName);\n\n\t\tprevWidth = arg[4];\n\t\tprevHeight = send(parent(), \"heightP\");\n\n\t\tlocalFile = HTTPGet(docURL);\n\t\tdata = loadFile(localFile);\n\t\tsystem(concat(\"rm -f \", localFile));\n\n\t\tif (isBlank(data) == 1) {\n\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t    concatenate(\"Failed to get \", arg[1]));\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn 0;\n\t\t} else {\n\t\t\tset(\"label\", data);\n\t\t\tset(\"width\", prevWidth);\n\t\t\tset(\"height\", prevHeight);\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn get(\"name\");\n\t\t}\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\traise();\n\t\tif (arg[1] != prevWidth) {\n\t\t\tprevWidth = arg[1];\n\t\t\tset(\"width\", prevWidth);\n\t\t} else if (arg[2] != prevHeight) {\n\t\t\tprevHeight = arg[2];\n\t\t\tset(\"height\", prevHeight);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"historyRecord\":\n\t\twwwHistory(\"add\", docName, docURL);\n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\tlocalPath = HTTPGet(docURL);\n\t\tdata = loadFile(localPath);\n\t\tset(\"label\", data);\n\t\trender();\n\t\tsystem(concat(\"rm \", tmp));\n\t\treturn;\n\tbreak;\n\tcase \"search\":\n\t\tcursorShape(\"busy\");\n\t\tsearch(arg[1]);\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"save\":\n\t\tbell(1);\n\t\treturn;\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryTitle\":\n\t\treturn docName;\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn 0;\n\tbreak;\n\tcase \"tree\":\n\t\t/* produce a n-level anchors tree by recursively fetching\n\t\t * anchor links \n\t\t */\n\t\treturn;\n\tbreak;\n\tcase \"showSrc\":\n\t\tVWHANDLER_XPM_EDITOR = \"pixmap\";\n\t\ttmp = concatenate(makeTempFile(), \".xpm\");\n\t\tsaveFile(tmp, get(\"label\"));\n\t\tsystem(concat(VWHANDLER_XPM_EDITOR, \" -filename \", tmp, \n\t\t\t\t\t\t\" >& /dev/null\"));\n\t\tset(\"label\", loadFile(tmp));\n\t\tsystem(concat(\"rm -f \", tmp));\n\t\trender();\n\t\tclearWindow();\n\t\treturn;\n\tbreak;\n\tcase \"outlineSrc\":\n\t\twww.mesg.tf(\"show\", \n\t\t\t    concatenate(\"Outliner not available for XPM\\n\"));\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\tisTorn = 1;\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\t\tset(\"cursor\", 0); \n\t\treturn;\n\tbreak;\n\tcase \"raise\":\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(0);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_WWWEMailHandler2[] = "\n\tswitch (arg[0]) {\n\tcase \"connect\":\n\t\t/* forms:\n\t\t *\ttelnetaddress=\ttelnet://[user@]hostport\n\t\t *\thostport=\thost[:port]\n\t\t *\n\t\t * returns a shell command\n\t\t */\n\t\ttt = nthChar(arg[1], 9, 999);\n\n\t\t/* to get rid of the mysterious '/' at end of string??? */\n\t\tif (nthChar(tt, strlen(tt) - 1) == '/') {\n\t\t\ttt = nthChar(tt, 0, strlen(tt) - 2);\n\t\t}\n\n\t\tati = findPattern(tt, \"@\");\n\t\tif (ati != -1) {\n\t\t\t/* form:\ttelnet://user@host\n\t\t\t */\n\t\t\tuser = nthChar(tt, 0, ati - 1);\n\t\t\thost = nthChar(tt, ati + 1, 999);\n\n\t\t\tcmd = concat(\"xterm -e 'rlogin \", \n\t\t\t\t\thost, \" -l \", user, \"' &\");\n\t\t\treturn cmd;\n\t\t}\n\n\t\tati = findPattern(tt, \":\");\n\t\tif (ati != -1) {\n\t\t\t/* form:\ttelnet://host:port\n\t\t\t */\n\t\t\thost = nthChar(tt, 0, ati - 1);\n\t\t\tport = nthChar(tt, ati + 1, 999);\n\t\t\tcmd = concat(\"xterm -e 'telnet \", \n\t\t\t\t\thost, \" \", port, \"' &\");\n\t\t\treturn cmd;\n\n\t\t} else {\n\t\t\t/* form:\ttelnet://host\n\t\t\t */\n\t\t\tcmd = concat(\"xterm -e 'telnet \", tt, \"' &\");\n\t\t\treturn cmd;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_WWWEMailHandler[] = {
    {"class", _slotValue_WWWEMailHandler0},
    {"name", _slotValue_WWWEMailHandler1},
    {"script", _slotValue_WWWEMailHandler2},
    {(char*)0, (char*)0},
};

static char _slotValue_WWWTelnetHandler0[] = "generic";
static char _slotValue_WWWTelnetHandler1[] = "WWWTelnetHandler";
static char _slotValue_WWWTelnetHandler2[] = "\n\tswitch (arg[0]) {\n\tcase \"connect\":\n\t\t/* forms:\n\t\t *\ttelnetaddress=\ttelnet://[user@]hostport\n\t\t *\thostport=\thost[:port]\n\t\t *\n\t\t * returns a shell command\n\t\t */\n\t\ttt = nthChar(arg[1], 9, 999);\n\n\t\t/* to get rid of the mysterious '/' at end of string??? */\n\t\tif (nthChar(tt, strlen(tt) - 1) == '/') {\n\t\t\ttt = nthChar(tt, 0, strlen(tt) - 2);\n\t\t}\n\n\t\tati = findPattern(tt, \"@\");\n\t\tif (ati != -1) {\n\t\t\t/* form:\ttelnet://user@host\n\t\t\t */\n\t\t\tuser = nthChar(tt, 0, ati - 1);\n\t\t\thost = nthChar(tt, ati + 1, 999);\n\n\t\t\tcmd = concat(\"xterm -e 'rlogin \", \n\t\t\t\t\t\thost, \" -l \", user, \"' &\");\n\t\t\treturn cmd;\n\t\t}\n\n\t\tati = findPattern(tt, \":\");\n\t\tif (ati != -1) {\n\t\t\t/* form:\ttelnet://host:port\n\t\t\t */\n\t\t\thost = nthChar(tt, 0, ati - 1);\n\t\t\tport = nthChar(tt, ati + 1, 999);\n\t\t\tcmd = concat(\"xterm -e 'telnet \", \n\t\t\t\t\thost, \" \", port, \"' &\");\n\t\t\treturn cmd;\n\n\t\t} else {\n\t\t\t/* form:\ttelnet://host\n\t\t\t */\n\t\t\tcmd = concat(\"xterm -e 'telnet \", tt, \"' &\");\n\t\t\treturn cmd;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_WWWTelnetHandler[] = {
    {"class", _slotValue_WWWTelnetHandler0},
    {"name", _slotValue_WWWTelnetHandler1},
    {"script", _slotValue_WWWTelnetHandler2},
    {(char*)0, (char*)0},
};

static char _slotValue_normalizeURL0[] = "normalizeURL";
static char _slotValue_normalizeURL1[] = "generic";
static char _slotValue_normalizeURL2[] = "\n/*\nprint(\"normalizeURL: \");\nfor (i=0; i < arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");\nprint(\"\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"normalizeURL\":\n\t\t/* arg[1]\turl\n\t\t * arg[2]\tcontext\n\t\t */\n\t\t/* URL of this form \"foo/bar/\" ending with '/' \n\t\t * can lead to badness like \"//muu\" \n\t\t * What was this about??? sheesh.\n\t\t */\n/*\t\tif (nthChar(arg[1], strlen(arg[1])-1) == '/')\n\t\t\targ[1] = nthChar(arg[1], 0, strlen(arg[1])-2);\n*/\n\t\tif (arg[] == 3) {\n\t\t\t/* set current document directory context.*/\n\t\t\tHTTPCurrentDocAddrSet(arg[2]);\n\t\t\taddrInfo = HTTPCurrentDocAddrParsed(arg[1], arg[2]);\n\t\t} else {\n\t\t\taddrInfo = HTTPCurrentDocAddrParsed(arg[1]);\n\t\t}\n\n\t\tif (nthChar(addrInfo[2], 0) == '/') {\n\t\t\tif (isBlank(addrInfo[1])) hostComponent = \"\";\n\t\t\telse hostComponent = concat(\"//\", addrInfo[1]);\n\t\t} else {\n\t\t\tif (addrInfo[0] == \"news\") {\n\t\t\t   hostComponent = \"\";\n\t\t\t} else {\n\t\t\t  if (isBlank(addrInfo[1])) hostComponent = '/';\n\t\t\t  else hostComponent = concat(\"//\", addrInfo[1], '/');\n\t\t\t}\n\t\t}\n\t\tnormURL = concat(addrInfo[0], \":\", hostComponent,\n\t\t\t\t\taddrInfo[2], addrInfo[3]);\n\n\t\tif (addrInfo[4] != \"\")\n\t\t\tnormURL = concat(normURL, '#', addrInfo[4]);\n\n\t\treturn normURL;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_normalizeURL[] = {
    {"name", _slotValue_normalizeURL0},
    {"class", _slotValue_normalizeURL1},
    {"script", _slotValue_normalizeURL2},
    {(char*)0, (char*)0},
};

static char _slotValue_parseHTTPAddress0[] = "generic";
static char _slotValue_parseHTTPAddress1[] = "parseHTTPAddress";
static char _slotValue_parseHTTPAddress2[] = "\n\tswitch (arg[0]) {\n\tcase \"name\":\n\t\tdd = arg[1];\n\t\tdoP = 1;\n\t\tnameEnd = findPattern(dd, \".html\");/*XXX*/\n\t\tif (nameEnd == -1) nameEnd = strlen(dd);\n\n\t\tnameBegin = 0;\n\t\tfor (i = 0; doP ; i++) {\n\t\t\tc = nthChar(dd, i);\n\t\t\tswitch (c) {\n\t\t\tcase '\\0':\n\t\t\t\tdoP = 0;\n\t\t\tbreak;\n\t\t\tcase '.':\n\t\t\t\tif (findPattern(nthChar(dd, i + 1, 999),\n\t\t\t\t\t\t\".\") == -1) {\n\t\t\t\t\tsuffixi = i - 1;\n\t\t\t\t\tdoP = 0;\n\t\t\t\t}\n\t\t\tbreak;\n\t\t\tcase '/':\n\t\t\t\tlastSlash = i;\n\t\t\t\tnameBegin = i + 1;\n\t\t\tbreak;\n\t\t\tcase '#':\n\t\t\t\tlastHash = i;\n\t\t\t\tsuffixi = i - 1;\n\t\t\t\tdoP = 0;\n\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tname = nthChar(dd, nameBegin, suffixi);\n\t\treturn name;\n\tbreak;\n\tcase \"anchor\":\n\t\tdd = arg[1];\n\t\tdoP = 1;\n\t\tanchorBegin = findPattern(dd, \"#\");\n\t\tif (anchorBegin == -1) return \"\";\n\n\t\tanchorBegin = anchorBegin + 1;\n\t\tfor (i = anchorBegin; doP ; i++) {\n\t\t\tc = nthChar(dd, i);\n\t\t\tswitch (c) {\n\t\t\tcase '\\0':\n\t\t\t\tdoP = 0;\n\t\t\t\tsuffixi = i - 1;\n\t\t\tbreak;\n\t\t\tcase '.':\n\t\t\t\tsuffixi = i - 1;\n\t\t\t\tdoP = 0;\n\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tanchor = nthChar(dd, anchorBegin, suffixi);\n\t\treturn anchor;\n\tbreak;\n\tcase \"stripIndex\":\n\t\tanchorBegin = findPattern(arg[1], \"?\");\n\t\tif (anchorBegin == -1) return arg[1];\n\t\treturn nthChar(arg[1], 1, idx);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_www9[] = "\n/*\nprint(\"www: \");\nfor (i=0; i < arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");\nprint(\"\\n\");\n*/\n\t/* Application: ViolaWWW\n\t * Author: \tPei Y. Wei\n\t *\n\t */\n\t/* URL port configurtion.\n\t * \n\tURLPort = 8081;\n\tURLListen = \"/usr/work/viola/src/viola/listen\";\n\t */\n\n\tswitch (arg[0]) {\n\tcase \"show\":\n\tcase \"post\":\n\t\tcursorShape(\"busy\");\n\t\tif (arg[] == 2)\n\t\t\tstat = send(\"www.doc.view.pane\", arg[0], arg[1]);\n\t\telse if (arg[] == 3)\n\t\t\tstat = send(\"www.doc.view.pane\", arg[0], arg[1], \n\t\t\t\t\t\t\t arg[2]);\n\t\telse\n\t\t\tstat = send(\"www.doc.view.pane\", arg[0], arg[1], \n\t\t\t\t\t\t\t arg[2], arg[3]);\n\t\tcursorShape(\"idle\");\n\t\treturn stat;\n\tbreak;\n\tcase \"showDoc\":\n\tcase \"showHistoryDoc\":\n\t\tcursorShape(\"busy\");\n\t\tif (arg[] == 2)\n\t\t\tstat = send(\"www.doc.view.pane\", \"show\", arg[1]);\n\t\telse if (arg[] == 3)\n\t\t\tstat = send(\"www.doc.view.pane\", \"show\", arg[1], \n\t\t\t\t\t\t\t arg[2]);\n\t\telse\n\t\t\tstat = send(\"www.doc.view.pane\", \"show\", arg[1], \n\t\t\t\t\t\t\t arg[2], arg[3]);\n\t\tsend(\"www.doc.view.pane\", \"historyRecord\");\n\t\tcursorShape(\"idle\");\n\t\treturn stat;\n\tbreak;\n\tcase \"addToHistory\":\n\t\tsend(\"wwwHistory\", \"add\", arg[1], arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"group\":\n/*\t\tsend(\"www.doc.title.icon\", \"group\", arg[1]);*/\n\t\treturn;\n\tbreak;\n\tcase \"showSrc\":\n\tcase \"clonePage\":\n\tcase \"destroyDoc\":\n\t\treturn send(\"www.doc.view.pane\", arg[0]);\n\tbreak;\n\tcase \"search\":\n\t\treturn send(\"www.doc.view.pane\", \"search\", arg[1]);\n\tbreak;\n\tcase \"olAdd\":\n/*\t\tolObj[olIdx] = arg[1];*/\n\t\tolData[olIdx] = arg[2];\n\t\tolIdx++;\n\t\treturn;\n\tbreak;\n\tcase \"olReset\":\n\t\tolIdx = 0;\n\t\treturn;\n\tbreak;\n\tcase \"olData\":\n\t\ttt = \"\";\n\t\tfor (i = 0; i < olIdx; i++) tt = concat(tt, olData[i], \"\\n\");\n\t\treturn tt;\n\tbreak;\n\tcase \"showButNoRecord\":\n\t\tsend(\"www.doc.view.pane\", \"show\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"CE_change\":\n\t\t/* arg[1] \tCE objPath\n\t\t * arg[2]\tCE newData\n\t\t */\n\t\treturn send(\"www.doc.view.pane\", arg[0], arg[1], arg[2]);\n\tbreak;\n\tcase \"CE_lock\":\n\tcase \"CE_unlock\":\n\t\t/* arg[1] \tCE objPath\n\t\t */\n\t\treturn send(\"www.doc.view.pane\", arg[0], arg[1]);\n\tbreak;\n\tcase \"about\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://berkeley.ora.com/proj/viola/vw/about_3.3.html\");\n\t\treturn;\n\tbreak;\n\tcase \"help\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://berkeley.ora.com/proj/viola/vw/help_xvw_3.3.html\");\n\t\treturn;\n\tbreak;\n\tcase \"demos\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://berkeley.ora.com/proj/viola/violaCentral.html\");\n\t\treturn;\n\tbreak;\n\tcase \"metaCenters\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://berkeley.ora.com/proj/viola/metaCenters.html\");\n\t\treturn;\n\tbreak;\n\tcase \"home\":\n\t\tsend(\"www\", \"showHistoryDoc\", homeDoc);\n\t\treturn;\n\tbreak;\n\tcase \"prev\":\n\t\tcursorShape(\"busy\");\n\t\twantIt = wwwHistory(\"prev\");\n\t\tif (isBlank(wantIt))\n\t\t\tsend(\"www.mesg.tf\", \"alert\", \n\t\t\t\t\"No ``previous'' document to go to.\");\n\t\telse send(\"www.doc.view.pane\", \"show\", wantIt);\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"next\":\n\t\tcursorShape(\"busy\");\n\t\twantIt = send(\"wwwHistory\", \"next\");\n\t\tif (isBlank(wantIt))\n\t\t\tsend(\"www.mesg.tf\", \"alert\", \n\t\t\t\t\"No ``next'' document to go to.\");\n\t\telse send(\"www.doc.view.pane\", \"show\", wantIt);\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"back\":\n\t\tcursorShape(\"busy\");\n\t\twantIt = send(\"wwwHistory\", \"back\");\n\t\tif (isBlank(wantIt))\n\t\t\tsend(\"www.mesg.tf\", \"alert\", \n\t\t\t\t    \"No Previous document to go back to.\");\n\t\telse send(\"www.doc.view.pane\", \"show\", wantIt);\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\tcursorShape(\"busy\");\n\t\tsend(\"www.doc.view.pane\", arg[0]);\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"tear\":\n\t\tcursorShape(\"busy\");\n\t\tsend(nthChild(1), \"tear\");\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"authorContact\":\n\t\tsend(\"www.doc.view.pane\", \"mailToAuthor\");\n\t\treturn;\n\tbreak;\n\tcase \"raise\":\n\t\traise();\n\t\tif (get(\"window\")) windowName(\"violaWWW\");\n\t\treturn;\n\tbreak;\n\tcase \"busy\":\n\tcase \"idle\":\n\t\tcursorShape(arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"quit\":\n\t\tquit();\n/*\n\t\tres(\"decAppCount\");\n\t\tdemo(\"visible\", 0);\n*/\n\t\treturn;\n\tbreak;\n\tcase \"openURL\":\n\t\twinPos = windowPosition();\n\t\tx = winPos[0] + 20;\n\t\ty = winPos[1] + 170;\n\t\tw = width() - 40;\n\t\th = 80;\n\t\tsend(\"wwwURL\", \"open\", lastURLOpened, self(), x, y, w, h);\n\t\treturn;\n\tbreak;\n\tcase \"gotURLToOpen\":\n\t\tcursorShape(\"busy\");\n\t\tlastURLOpened = arg[1];\n\t\tsend(\"www\", \"show\", lastURLOpened);\n\t\tsend(\"www.doc.view.pane\", \"historyRecord\");\n\t\tcursorShape(\"idle\");\n\t\treturn;\n \tbreak;\n\tcase \"searchByTag\":\n\t\tsend(\"www.doc.view.pane\", \"searchByTag\", arg[1], arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"homeDocP\":\n\t\treturn homeDoc;\n\tbreak;\n\tcase \"changeFonts\":\n\t\tsend(\"res.font\", arg[1]);\n\t\t/* bug: only main viewer is told of the font change */\n\t\tsend(\"www.doc.view.pane\", \"configSelf\");\n\t\treturn;\n\tbreak;\n\tcase \"visible\":\n\t\tif (arg[1] == 1) res(\"incAppCount\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tt = getResource(\"Viola.x\");\n\t\tif (isBlank(t) == 0) set(\"x\", t);\n\t\tt = getResource(\"Viola.y\");\n\t\tif (isBlank(t) == 0) set(\"y\", t);\n\t\tt = getResource(\"Viola.width\");\n\t\tif (isBlank(t) == 0) set(\"width\", t);\n\t\tt = getResource(\"Viola.height\");\n\t\tif (isBlank(t) == 0) set(\"height\", t);\n\t\t\n\t\tres(\"incAppCount\");\n\n\t\thomeDoc = argument();\n\t\tif (isBlank(homeDoc) == 1)\n\t\t\thomeDoc = environVar(\"WWW_HOME\");\n\t\tif (isBlank(homeDoc) == 1) \n\t\t\thomeDoc = \"http://berkeley.ora.com/proj/viola/violaStartUp.html\";\n\t\tif (nthChar(homeDoc, 0) == '/')\n\t\t\thomeDoc = concat(\"file:\", homeDoc);\n\n\t\tafter(10, \"www\", \"show\", homeDoc);\n\n\t\tif (URLPort > 0) {\n\t\t\tprint(\"WARNING: port number \", URLPort,\n\t\t\t\" is now being used to accept URL fetch directives.\");\n\t\t\tif (send(\"wwwDocuPort\", \"listen\", URLPort, URLListen)){\n\t\t\t\tprint(\"ERROR: Sorry, failed to open port \",\n\t\t\t\tURLPort, \" for listening to URL fetches\\n\");\n\t\t\t}\n\t\t}\n\t\tHTTPHotListLoad();\n\t\tlastURLOpened = \"\";\n\n\t\t/* start up in edit mode */\n/*\t\tafter(1000, \"www\", \"editMode\", 1); */\n\n\t\treturn;\n\tbreak;\n\tcase \"showHotFolder\":\n\t\tsend(\"wwwHotFolder\", \"render\");\n\t\treturn;\n\tbreak;\n\tcase \"addCurrentToHotFolder\":\n\t\tsend(\"wwwHotFolder\", \"addCurrent\");\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tsend(\"www.doc.view.pane\", \"outputSGML\");\n\t\treturn;\n\tbreak;\n\tcase \"getCurrentDocURL\":\n\tcase \"getCurrentDocTitle\":\n\t\tsend(\"www.doc.view.pane\", arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"editMode\":\n\t\tsend(\"www.doc.view.pane\", arg[0], arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"version\":\n\t\treturn \"Version 3.3 (95/01/01)\";\n\tbreak;\n\tcase \"winPosition\":\n\t\treturn windowPosition();\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_www26[] = "\n\tswitch (arg[0]) {\n\tcase \"quit\":\n\t\tsend(\"www\", \"quit\");\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Click to see some general project information.\";\n\tbreak;\n\t}\n\tusual();\n/*\nUnreliable feature\n.{\\\\}\n.{Fonts}\n..{Helvetica Small} {www(\"changeFonts\", \"useHelveticaSmallFonts\");}\n..{Helvetica Medium} {www(\"changeFonts\", \"useHelveticaMediumFonts\");}\n..{Helvetica Large} {www(\"changeFonts\", \"useHelveticaLargeFonts\");}\n..{\\\\}\n..{Times Small} {www(\"changeFonts\", \"useTimesSmallFonts\");}\n..{Times Medium} {www(\"changeFonts\", \"useTimesMediumFonts\");}\n..{Times Large} {www(\"changeFonts\", \"useTimesLargeFonts\");}\n.{\\\\}\n.{Expermental}\n..{OUTPUT SGML} {send(\"www\", \"outputSGML\");}\n..{Edit On} {send(\"www\", \"editMode\", 1);}\n..{Edit Off} {send(\"www\", \"editMode\", 0);}\n..{LBar On 10} {send(\"www.doc.view\", \"lbarConfig\", \"on\", 10);}\n..{LBar On 20} {send(\"www.doc.view\", \"lbarConfig\", \"on\", 20);}\n..{LBar On 50} {send(\"www.doc.view\", \"lbarConfig\", \"on\", 50);}\n..{LBar Off} {send(\"www.doc.view\", \"lbarConfig\", \"off\");}\n.{Clone Page} {send(\"www\", \"tear\");}\n*/\n";
static char _slotValue_www27[] = "\n.{Open URL (Uniform Resource Location)} {send(\"www\", \"openURL\");}\n.{Follow URL in Selection Buffer} {www(\"showHistoryDoc\", trimEdge(getSelection()));}\n.{\\\\}\n.{Show Document Source} {send(\"www\", \"showSrc\");}\n.{Show Document Author Info} {www(\"authorContact\");}\n.{\\\\}\n.{Software Version Info} {wwwAbout(\"visible\", 1);}\n.{\\\\}\n.{Quit} {send(self(), \"quit\");}\n";
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
static char _slotValue_www38[] = "\n.{Back} {send(\"www\", \"back\");}\n.{\\\\}\n.{Home} {send(\"www\", \"home\")};\n.{Prev} {send(\"www\", \"prev\");}\n.{Next} {send(\"www\", \"next\");}\n.{\\\\}\n.{History List} {wwwHistory(\"render\");}\n.{\\\\}\n.{Hot List} {send(\"www\", \"showHotFolder\");}\n.{Add To Hot List} {send(\"www\", \"addCurrentToHotFolder\");}\n";
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
static char _slotValue_www63[] = "\n.{GNN's Whole Internet Catalog} {www(\"showHistoryDoc\", \"http://nearnet.gnn.com/wic/newrescat.toc.html\");}\n.{CERN's Web Servers Catalog} {www(\"showHistoryDoc\", \"http://info.cern.ch/hypertext/DataSources/WWW/Servers.html\");}\n.{More Meta Centers...} {www(\"metaCenters\");}\n";
static char _slotValue_www64[] = "90";
static char _slotValue_www65[] = "4";
static char _slotValue_www66[] = "10";
static char _slotValue_www67[] = "normal";
/* END OF OBJ */

static char _slotValue_www69[] = "vpane";
static char _slotValue_www70[] = "www.doc";
static char _slotValue_www71[] = "www";
static char _slotValue_www72[] = "www.doc.tools www.doc.title www.doc.view";
static char _slotValue_www73[] = "\n\tswitch (arg[0]) {\n\tcase \"tear\":\n\t\ttearPageID = tearPageID + 1;\n\t\tnew = clone(tearPageID);\n\t\ttweak(new, \"set(\\\"parent\\\", \\\"\\\");\");\n\t\tsend(new, \"torn\", send(nthChild(2), \"whichPageP\"));\n\t\tsend(new, \"render\");\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\tset(\"label\", \n\t\t\tsend(send(nthChild(2), \"whichPageP\"), \"queryAddress\"));\n\t\tobjectListSend_children(\"torn\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\ttearPageID = 0;\n\tbreak;\n\tcase \"addTool\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(nthChild(0), arg[0], arg[1]);\n\tbreak;\n\tcase \"whichPageP\":\n\t\treturn send(nthChild(2), \"whichPageP\");\n\tbreak;\n\tcase \"outliner\":\n\t\tif (arg[1]) {\n\t\t\tset(\"children\", \n\t\t\t\t\"www.doc.title www.doc.view www.doc.ol\");\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tolP = 1;\n\t\t} else {\n\t\t\tset(\"children\", \n\t\t\t\t\"www.doc.title www.doc.view\");\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tolP = 0;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"quit\":\n\t\tset(\"visible\", 0);\n\t\tfreeSelf();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www74[] = "2";
/* END OF OBJ */

static char _slotValue_www76[] = "hpane";
static char _slotValue_www77[] = "www.doc.title";
static char _slotValue_www78[] = "www.doc";
static char _slotValue_www79[] = "www.doc.title.tf";
static char _slotValue_www80[] = "\n\tswitch (arg[0]) {\n\tcase \"whichPageP\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"torn\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www81[] = "38";
static char _slotValue_www82[] = "2";
/* END OF OBJ */

static char _slotValue_www84[] = "txtDisp";
static char _slotValue_www85[] = "www.doc.title.tf";
static char _slotValue_www86[] = "www.doc.title";
static char _slotValue_www87[] = "\n\tswitch (arg[0]) {\n\tcase \"enter\":\n\tcase \"leave\":\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Document title. Click to reload document.\";\n\tbreak;\n\tcase \"show\":\n\t\tif (isBlank(arg[1])) {\n\t\t\tset(\"content\", \"\");\n\t\t} else {\n\t\t\tif (textWidth(6/*bold_largest*/, arg[1])+10 \n\t\t\t    < width()) {\n\t\t\t\t/*set(\"font\", \"bold_largest\");*/\n\t\t\t\tset(\"content\", concat(\"\\\\f(6)\", arg[1]));\n\t\t\t} else {\n\t\t\t\t/*set(\"font\", \"bold\");*/\n\t\t\t\tset(\"content\", concat(\"\\\\f(5)\", arg[1]));\n\t\t\t}\n\t\t}\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_www100[] = "\n\tswitch (arg[0]) {\n\tcase \"addTool\":\n\tcase \"addTool_sticky\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(nthChild(2), arg[0], arg[1]);\n\tbreak;\n\tcase \"clear\":\n\t\treturn send(nthChild(2), arg[0]);\n\tbreak;\n\tcase \"torn\":\n\t\tset(\"border\", 6);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www101[] = "2";
static char _slotValue_www102[] = "39";
/* END OF OBJ */

static char _slotValue_www104[] = "hpane";
static char _slotValue_www105[] = "www.doc.tools.dyna";
static char _slotValue_www106[] = "www.doc.tools";
static char _slotValue_www107[] = "\n\tswitch (arg[0]) {\n\tcase \"addTool\":\n\tcase \"addTool_sticky\":\n\t\tnew = object(arg[1]);\n\t\tfor (i = objectListCount_children(); i >= 0; i--)\n\t\t\tif (nthChild(i) == new) return 1;\n\t\tobjectListAppend(\"children\", new);\n\t\ttweak(new, concat(\"set(\\\"parent\\\", \\\"\", self(), \"\\\");\"));\n\t\tsend(new, \"visible\", 1);\n\t\tconfig();\n\t\treturn 1;\n\tbreak;\n\tcase \"removeTool\":\n\t\tnew = object(arg[1]);\n\t\tobjectListDelete(\"children\", new);\n\t\tsend(new, \"visible\", 0);\n\t\tconfig();\n\t\treturn 1;\n\tbreak;\n\tcase \"destroyTool\":\n\t\tnew = object(arg[1]);\n\t\tobjectListDelete(\"children\", new);\n\t\tsend(new, \"visible\", 0);\n\t\tsend(new, \"freeSelf\");\n\t\tconfig();\n\t\treturn 1;\n\tbreak;\n\tcase \"clear\":\n\t\tset(\"children\", \"\");\n\t\treturn;\n\tbreak;\n\tcase \"go_url\":\n\t\treturn send(\"www\", \"show\", arg[1]);\n\tbreak;\n\tcase \"go_home\":\n\t\treturn send(\"www\", \"home\");\n\tbreak;\n\tcase \"go_prev\":\n\t\treturn send(\"www\", \"prev\");\n\tbreak;\n\tcase \"go_next\":\n\t\treturn send(\"www\", \"next\");\n\tbreak;\n\tcase \"go_back\":\n\t\treturn send(\"www\", \"back\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www108[] = "2";
static char _slotValue_www109[] = "2";
/* END OF OBJ */

static char _slotValue_www111[] = "hpane";
static char _slotValue_www112[] = "www.doc.tools.sys";
static char _slotValue_www113[] = "www.doc.tools";
static char _slotValue_www114[] = "www.doc.tools.sys.home www.doc.tools.sys.back www.doc.tools.sys.prev \nwww.doc.tools.sys.next www.doc.tools.sys.reload";
static char _slotValue_www115[] = "171";
static char _slotValue_www116[] = "32";
static char _slotValue_www117[] = "0";
static char _slotValue_www118[] = "2";
/* END OF OBJ */

static char _slotValue_www120[] = "XPMButton";
static char _slotValue_www121[] = "www.doc.tools.sys.home";
static char _slotValue_www122[] = "www.doc.tools.sys";
static char _slotValue_www123[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonPress\":\n\t\tcopyArea(0,0,width(),height(),1,1);\n\t\treturn;\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tsend(\"www\",\"home\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Click the house icon to visit home page.\";\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www124[] = "/* XPM */\nstatic char * home [] = {\n\"32 32 9 1\",\n\" \tc black\",\n\".\tc white\",\n\"X\tc grey75\",\n\"o\tc gray30\",\n\"O\tc red\",\n\"+\tc #E0E0D0D0B0B0\",\n\"@\tc lightyellow\",\n\"#\tc gray\",\n\"$\tc gray50\",\n\"                                \",\n\" .............................  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\" .XXXXXXXXXX       XXXXXXXXXXo  \",\n\" .XXXXXXXXX OOOOOOO XXXXXXXXXo  \",\n\" .XXXXXXXX O+@OOOOOO XXXXXXXXo  \",\n\" .XXXXXXXX O+@@OOOOOO XXXXXXXo  \",\n\" .XXXXXXX O+@@@OOOOOOO XXXXXXo  \",\n\" .XXXXXX O+@@@@@OOOOOOO XXXXXo  \",\n\" .XXXXX O+@@@@@@@OOOOOOO XXXXo  \",\n\" .XXXXX O+@@@@@@@@OOOOOOO XXXo  \",\n\" .XXXX O+@@@@@@@@@OOOOOOOO XXo  \",\n\" .XXX O+@@@#####@@@OOOO++ XXXo  \",\n\" .XXXX  @@@#   #@@@@+++++ XXXo  \",\n\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\" .XXXXX @@@#   #@@@@++++  XXXo  \",\n\" .XXXXX @@@#   #@@@@++  XXXXXo  \",\n\" .XXXXXX             XXXXXXXXo  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\" .XXXX XX X$  $X XXX X   XXXXo  \",\n\" .XXXX XX X XX X  X  X XXXXXXo  \",\n\" .XXXX    X XX X $ $ X  XXXXXo  \",\n\" .XXXX XX X XX X X X X XXXXXXo  \",\n\" .XXXX XX X XX X XXX X XXXXXXo  \",\n\" .XXXX XX X$  $X XXX X   XXXXo  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\" .oooooooooooooooooooooooooooo  \",\n\"                                \",\n\"                                \"};\n";
static char _slotValue_www125[] = "32";
static char _slotValue_www126[] = "1";
static char _slotValue_www127[] = "2";
/* END OF OBJ */

static char _slotValue_www129[] = "XPMButton";
static char _slotValue_www130[] = "www.doc.tools.sys.prev";
static char _slotValue_www131[] = "www.doc.tools.sys";
static char _slotValue_www132[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"www\", \"prev\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\t\tencounter = enconter + 1;\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn concat(\"Click to visit the previous document = \",\n\t\t\t\twwwHistory(\"peek_prev\"));\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www133[] = "/* XPM */\nstatic char * prev [] = {\n\"32 32 6 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc grey75\",\n\"O\tc gray30\",\n\"+\tc gray50\",\n\"..............................  \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".Xoooooooooooooooooo..oooooooO  \",\n\".Xoooooooooooooooo..++.ooooooO  \",\n\".Xoooooooooooooo..++++.ooooooO  \",\n\".Xoooooooooooo..++++++.ooooooO  \",\n\".Xoooooooooo..++++++++.ooooooO  \",\n\".Xoooooooo..++++++++++.ooooooO  \",\n\".Xooooooo.++++++++++++.ooooooO  \",\n\".Xooooo.++++++++++++++.ooooooO  \",\n\".Xoooooo..++++++++++++.ooooooO  \",\n\".Xoooooooo..++++++++++.ooooooO  \",\n\".Xoooooooooo..++++++++.ooooooO  \",\n\".Xoooooooooooo..++++++.ooooooO  \",\n\".Xoooooooooooooo..++++.ooooooO  \",\n\".Xoooooooooooooooo..++.ooooooO  \",\n\".Xoooooooooooooooooo..oooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".Xoooo...+o...+o...o.ooo.ooooO  \",\n\".Xoooo.oo.o.oo.o.ooo.ooo.ooooO  \",\n\".Xoooo.oo.o...+o..oo.+o+.ooooO  \",\n\".Xoooo...+o.o.oo.oooo.o.oooooO  \",\n\".Xoooo.oooo.oo.o.oooo.+.oooooO  \",\n\".Xoooo.oooo.oo.o...ooo.ooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\"                                \",\n\"                                \"};\n";
static char _slotValue_www134[] = "32";
static char _slotValue_www135[] = "1";
static char _slotValue_www136[] = "2";
/* END OF OBJ */

static char _slotValue_www138[] = "XPMButton";
static char _slotValue_www139[] = "www.doc.tools.sys.back";
static char _slotValue_www140[] = "www.doc.tools.sys";
static char _slotValue_www141[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"www\",\"back\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn concat(\"Click to go back. document = \",\n\t\t\t\tsend(\"wwwHistory\", \"peek_back\"));\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www142[] = "/* XPM */\nstatic char * back [] = {\n\"32 32 7 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc gray\",\n\"O\tc gray30\",\n\"+\tc gray50\",\n\"@\tc grey75\",\n\"..............................  \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".Xooooooooooooo.oooooooooooooO  \",\n\".Xoooooooooooo.+.ooooooooooooO  \",\n\".Xoooooooooooo.+.ooooooooooooO  \",\n\".Xooooooooooo.+++.oooooooooooO  \",\n\".Xooooooooooo.+++.oooooooooooO  \",\n\".Xoooooooooo.+++++.ooooooooooO  \",\n\".Xoooooooooo.+++++.ooooooooooO  \",\n\".Xooooooooo.+++++++.oooooooooO  \",\n\".Xooooooooo.+++++++.oooooooooO  \",\n\".Xoooooooo.+++++++++.ooooooooO  \",\n\".Xoooooooo.+++++++++.ooooooooO  \",\n\".Xooooooo.+++++++++++.oooooooO  \",\n\".Xooooooo.+++++++++++.oooooooO  \",\n\".Xoooooo.+++++++++++++.ooooooO  \",\n\".Xoooooo.+++++++++++++.ooooooO  \",\n\".Xooooooo.............oooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".Xoooo...oooo.oooo..o.oo.ooooO  \",\n\".Xoooo.o.ooo.o.oo.ooo.o.oooooO  \",\n\".Xoooo....oo...oo.ooo..ooooooO  \",\n\".Xoooo.oo.o.ooo.o.ooo.@.oooooO  \",\n\".Xoooo...oo.ooo.oo..o.oo.ooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\"                                \",\n\"                                \"};";
static char _slotValue_www143[] = "32";
static char _slotValue_www144[] = "1";
static char _slotValue_www145[] = "2";
/* END OF OBJ */

static char _slotValue_www147[] = "XPMButton";
static char _slotValue_www148[] = "www.doc.tools.sys.next";
static char _slotValue_www149[] = "www.doc.tools.sys";
static char _slotValue_www150[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonPress\":\n\t\tcopyArea(0,0,width(),height(),1,1);\n\t\treturn;\n\tbreak;\n\tcase \"buttonRelease\":\n\t\twww(\"next\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn concat(\"Click to visit the next document = \",\n\t\t\t\twwwHistory(\"peek_next\"));\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www151[] = "/* XPM */\nstatic char * next [] = {\n\"32 32 6 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc grey75\",\n\"O\tc gray30\",\n\"+\tc gray50\",\n\"..............................  \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".Xoooooooo..oooooooooooooooooO  \",\n\".Xooooooo.++..oooooooooooooooO  \",\n\".Xooooooo.++++..oooooooooooooO  \",\n\".Xooooooo.++++++..oooooooooooO  \",\n\".Xooooooo.++++++++..oooooooooO  \",\n\".Xooooooo.++++++++++..oooooooO  \",\n\".Xooooooo.++++++++++++..oooooO  \",\n\".Xooooooo.++++++++++++++.ooooO  \",\n\".Xooooooo.++++++++++++..oooooO  \",\n\".Xooooooo.++++++++++..oooooooO  \",\n\".Xooooooo.++++++++..oooooooooO  \",\n\".Xooooooo.++++++..oooooooooooO  \",\n\".Xooooooo.++++..oooooooooooooO  \",\n\".Xooooooo.++..oooooooooooooooO  \",\n\".Xoooooooo..oooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".Xooo.+oo.o...o.ooo.o.....oooO  \",\n\".Xooo..+o.o.ooo+.o.+ooo.oooooO  \",\n\".Xooo.o.+.o..+oo+.+oooo.oooooO  \",\n\".Xooo.oo..o.oooo+.+oooo.oooooO  \",\n\".Xooo.ooo.o.ooo+.o.+ooo.oooooO  \",\n\".Xooo.ooo.o...o.ooo.ooo.oooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\"                                \",\n\"                                \"};\n";
static char _slotValue_www152[] = "32";
static char _slotValue_www153[] = "1";
static char _slotValue_www154[] = "2";
/* END OF OBJ */

static char _slotValue_www156[] = "XPMButton";
static char _slotValue_www157[] = "www.doc.tools.sys.reload";
static char _slotValue_www158[] = "www.doc.tools.sys";
static char _slotValue_www159[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"www\", \"reload\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Click to reload the document\";\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www160[] = "/* XPM */\nstatic char * reload [] = {\n\"32 32 6 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc gray\",\n\"O\tc gray30\",\n\"+\tc red\",\n\" .............................  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\" .XooooooooooooooooooooooooooO  \",\n\" .XooooooooooooooooooooooooooO  \",\n\" .Xooooooo...........ooooooooO  \",\n\" .Xooooooo.XXXXXXXX.X.oooooooO  \",\n\" .Xoooo+++.X......X.XX.ooooooO  \",\n\" .Xoooo+++.XXXXXXXX.XXX.oooooO  \",\n\" .Xoooo+...X......X.....oooooO  \",\n\" .Xoooo+++.XXXXXXXXXXXX.oooooO  \",\n\" .Xoooo+...X.........XX.oooooO  \",\n\" .Xoooo+++.XXXXXXXXXXXX.oooooO  \",\n\" .Xoooo+...X.........XX.oooooO  \",\n\" .Xoooo+++.XXXXXXXXXXXX.oooooO  \",\n\" .Xoooo+...X.........XX.oooooO  \",\n\" .Xoooo+++.XXXXXXXXXXXX.oooooO  \",\n\" .Xoooo+................oooooO  \",\n\" .Xoooo++++++++++++++ooooooooO  \",\n\" .Xoooo+...........++ooooooooO  \",\n\" .Xoooo++++++++++++++ooooooooO  \",\n\" .XooooooooooooooooooooooooooO  \",\n\" .XooooooooooooooooooooooooooO  \",\n\" .Xoo...Oo...o.ooO.OoO.Oo..ooO  \",\n\" .Xoo.oo.o.ooo.oo.o.o.O.o.o.oO  \",\n\" .Xoo...Oo..oo.oo.o.o.o.o.o.oO  \",\n\" .Xoo.o.oo.ooo.oo.o.o...o.o.oO  \",\n\" .Xoo.oo.o.ooo.oo.o.o.o.o.o.oO  \",\n\" .Xoo.oo.o...o..oO.Oo.o.o..ooO  \",\n\" .XooooooooooooooooooooooooooO  \",\n\" .XOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\"                                \",\n\"                                \"};";
static char _slotValue_www161[] = "32";
static char _slotValue_www162[] = "1";
static char _slotValue_www163[] = "2";
/* END OF OBJ */

static char _slotValue_www165[] = "XPMButton";
static char _slotValue_www166[] = "www.doc.tools.ops.clone";
static char _slotValue_www167[] = "www.doc.tools.ops";
static char _slotValue_www168[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"www\", \"tear\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Click to reload the document\";\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www169[] = "/* XPM */\nstatic char * clone [] = {\n\"32 32 5 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc gray\",\n\"O\tc gray30\",\n\"..............................  \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".Xooo..........ooooooooooooooO  \",\n\".Xooo.XXXXXXX.X.oooooooooooooO  \",\n\".Xooo.X....XX.XX.ooooooooooooO  \",\n\".Xooo.XXXXXXX.XXX.oooooooooooO  \",\n\".Xooo.X.....X.....oooooooooooO  \",\n\".Xooo.XXXXXXXXXXX.oooooooooooO  \",\n\".Xooo.X......X.........ooooooO  \",\n\".Xooo.XXXXXXXX.XXXXXX.X.oooooO  \",\n\".Xooo.X......X.X...XX.XX.ooooO  \",\n\".Xooo.XXXXXXXX.XXXXXX.XXX.oooO  \",\n\".Xooo.X......X.X....X.....oooO  \",\n\".Xooo.XXXXXXXX.XXXXXXXXXX.oooO  \",\n\".Xooo.XXXXXXXX.X........X.oooO  \",\n\".Xooo..........XXXXXXXXXX.oooO  \",\n\".Xoooooooooooo.X........X.oooO  \",\n\".Xoooooooooooo.XXXXXXXXXX.oooO  \",\n\".Xoooooooooooo.XXXXXXXXXX.oooO  \",\n\".Xoooooooooooo............oooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".Xooooo..o.oo...o.Oo.o...ooooO  \",\n\".Xoooo.Ooo.oo.o.o..o.o.ooooooO  \",\n\".Xoooo.ooo.oo.o.o.o..o..oooooO  \",\n\".Xoooo.ooo.oo.o.o.oO.o.ooooooO  \",\n\".Xoooo.Ooo.oo.o.o.oo.o.ooooooO  \",\n\".Xooooo..o..o...o.oo.o...ooooO  \",\n\".XoooooooooooooooooooooooooooO  \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \",\n\"                                \",\n\"                                \"};";
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
static char _slotValue_www186[] = "\n\tswitch (arg[0]) {\n\tcase \"stat\":\n\t\tif (inProgress == 0) {\n\t\t\tclearWindow();\n\t\t\tinProgress = 1;\n\t\t}\n\t\tfillArc(5, 2, w, h, 0, arg[1] * 3.6);\n\t\tflush();\n\t\treturn;\n\tbreak;\n\tcase \"clear\":\n\t\tinProgress = 0;\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\tcase \"init\":\n\t\tusual();\n\t\th = get(\"height\") - 5;\n\t\tw = h;\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www187[] = "#define violaIcon2_width 36\n#define violaIcon2_height 30\nstatic char violaIcon2_bits[] = {\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00,\n   0x00, 0xe0, 0x30, 0x78, 0x00, 0x00, 0x30, 0x60, 0xcc, 0x01, 0x00, 0x18,\n   0xc0, 0x07, 0x03, 0x00, 0x08, 0x80, 0x01, 0x03, 0x00, 0x0c, 0x00, 0x00,\n   0x06, 0x00, 0x04, 0x00, 0x00, 0x46, 0x01, 0x04, 0x00, 0x00, 0x46, 0x01,\n   0x04, 0x80, 0xa4, 0xff, 0x03, 0x04, 0x0f, 0x00, 0x40, 0x01, 0x04, 0x0f,\n   0x00, 0x40, 0x01, 0x04, 0x0e, 0x04, 0x40, 0x01, 0x08, 0x0e, 0x04, 0x00,\n   0x00, 0x18, 0x1c, 0x04, 0x00, 0x00, 0x30, 0x1c, 0x02, 0x04, 0x00, 0xf0,\n   0x19, 0x0a, 0x74, 0x00, 0xe0, 0x39, 0x02, 0x84, 0x00, 0xc0, 0x31, 0xc9,\n   0x84, 0x00, 0x00, 0x20, 0x29, 0xe5, 0x00, 0x00, 0x60, 0x29, 0x95, 0x00,\n   0x00, 0xc0, 0x29, 0x95, 0x00, 0x00, 0xc0, 0xc8, 0xe4, 0x01, 0x00, 0x80,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n";
static char _slotValue_www188[] = "2";
static char _slotValue_www189[] = "31";
static char _slotValue_www190[] = "6";
/* END OF OBJ */

static char _slotValue_www192[] = "hpane";
static char _slotValue_www193[] = "www.doc.view";
static char _slotValue_www194[] = "www.doc";
static char _slotValue_www195[] = "www.doc.view.pane www.doc.view.sb";
static char _slotValue_www196[] = "2";
static char _slotValue_www197[] = "\n/*\nprint(\"DOC>VIEW: \");\nfor (i=0; i < arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");\nprint(\"\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"config\":\n\t\tif (lbarVisible == 1) {\n\t\t\tsend(nthChild(0), \"resetWidthConstraint\", arg[3]);\n\t\t}\n\tbreak;\n\tcase \"tear\":\n\tcase \"quit\":\n\t\tsend(get(\"parent\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\tsend(pagePane, \"torn\", arg[1]);\n\t\tpagePane = get(\"content\");\n\t\treturn;\n\tbreak;\n\tcase \"whichPageP\":\n\t\treturn send(pagePane, \"whichPageP\");\n\tbreak;\n\tcase \"key_up\":\n\t\tsend(\"www.doc.view.sb.slider\", \"scroll\", \"up\");\n\t\treturn;\n\tbreak;\n\tcase \"key_down\":\n\t\tsend(\"www.doc.view.sb.slider\", \"scroll\", \"down\");\n\t\treturn;\n\tbreak;\n\tcase \"keyPress\":\n\t\tc = key();\n\t\tif (c == ' ')\n\t\t\tsend(\"www.doc.view.sb.slider\", \"scroll\", \"down\");\n\t\treturn;\n\tbreak;\n\tcase \"addTool\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(parent(), arg[0], arg[1]);\n\tbreak;\n\tcase \"linkSideBar\":\n\t\tsideBarURL = arg[1];\n\t\tsideBarRatio = arg[2];\n\t\tsideBarMaxWidth = arg[3];\n\t\tsend(self(), \"lbarConfig\", \"on\", \n\t\t\tsideBarURL, sideBarRatio, sideBarMaxWidth);\n\t\treturn;\n\tbreak;\n\tcase \"lbarConfig\":\n\t\tswitch (arg[1]) {\n\t\tcase \"on\":\n\t\t\tset(\"children\", \n\t\t\t\"www.doc.view.lbar www.doc.view.pane www.doc.view.sb\");\n\t\t\tsend(nthChild(0), \"enable\", \n\t\t\t\targ[2], arg[3], arg[4], width());\n\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tif (lbarVisible == 0) send(nthChild(0), \"visible\", 1);\n\t\t\tpagePane = nthChild(1);\n\t\t\tlbarVisible = 1;\n\t\tbreak;\n\t\tcase \"off\":\n\t\t\tif (lbarVisible == 1) send(nthChild(0), \"disable\");\n\t\t\tset(\"children\", \n\t\t\t\"www.doc.view.pane www.doc.view.sb\");\n\t\t\tlbarVisible = 0;\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tpagePane = nthChild(0);\n\t\tbreak;\n\t\t}\n\t\tset(\"content\", pagePane);\n\t\treturn;\n\tbreak;\n\tcase \"sliderConfig\":\n\t\tswitch (arg[1]) {\n\t\tcase \"left\":\n\t\t\tset(\"children\", \"www.doc.view.sb www.doc.view.pane\");\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tsend(\"www.doc.view.sTUb\", \"getLost\");\n\t\t\tpagePane = nthChild(2);\n\t\t\tsend(\"www.doc.view.pane\", \"configSiderGeom\");\n\t\tbreak;\n\t\tcase \"right\":\n\t\t\tset(\"children\", \"www.doc.view.pane www.doc.view.sb\");\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tsend(\"www.doc.view.sTUb\", \"getLost\");\n\t\t\tpagePane = nthChild(1);\n\t\t\tsend(\"www.doc.view.pane\", \"configSiderGeom\");\n\t\tbreak;\n\t\tcase \"none\":\n\t\t\tset(\"children\", \"www.doc.view.pane www.doc.view.sTUb\");\n\t\t\tsend(\"www.doc.view.sTUb\", \"showYaSelf\");\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tpagePane = nthChild(1);\n\t\tbreak;\n\t\t}\n\t\tset(\"content\", pagePane);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\t/* default scrolbar at right side, lbar off */\n\t\tpagePane = nthChild(0); \n\t\tset(\"content\", pagePane);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_www199[] = "field";
static char _slotValue_www200[] = "www.doc.view.sTUb";
static char _slotValue_www201[] = "www.doc.view";
static char _slotValue_www202[] = "\n\tswitch (arg[0]) {\n\tcase \"showYaSelf\":\n\t\tset(\"visible\", 1);\n\t\treturn;\n\tbreak;\n\tcase \"getLost\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_www214[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(nthSibling(1), \"scroll\", \"up\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Click to scroll up one page.\";\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www215[] = "#define arrowUp_width 19\n#define arrowUp_height 19\nstatic char arrowUp_bits[] = {\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x07, 0x00, 0x80, 0x0f, 0x00,\n   0xc0, 0x1f, 0x00, 0xe0, 0x3f, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x07, 0x00,\n   0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n";
static char _slotValue_www216[] = "3";
static char _slotValue_www217[] = "17";
static char _slotValue_www218[] = "17";
static char _slotValue_www219[] = "17";
static char _slotValue_www220[] = "17";
/* END OF OBJ */

static char _slotValue_www222[] = "XBMButton";
static char _slotValue_www223[] = "www.doc.view.sb.down";
static char _slotValue_www224[] = "www.doc.view.sb";
static char _slotValue_www225[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(nthSibling(1), \"scroll\", \"down\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Click to scroll down one page.\";\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www226[] = "#define arrowDown_width 20\n#define arrowDown_height 20\nstatic char arrowDown_bits[] = {\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00,\n   0x00, 0x07, 0x00, 0xe0, 0x3f, 0x00, 0xe0, 0x3f, 0x00, 0xc0, 0x1f, 0x00,\n   0x80, 0x0f, 0x00, 0x00, 0x07, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n";
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
static char _slotValue_www239[] = "\n\tswitch (arg[0]) {\n\tcase \"setShownNotify\":\n\t\tset(\"shownNotify\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"kludgeRender\":\n\t\t/* This is a kludge to get around a BUG */\n\t\treturn after(1, self(), \"render\");\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_www241[] = "slider";
static char _slotValue_www242[] = "www.doc.view.lbar.sb";
static char _slotValue_www243[] = "www.doc.view";
static char _slotValue_www244[] = "www.doc.view.lbar.pane";
static char _slotValue_www245[] = "\n\tswitch (arg[0]) {\n\tcase \"setShownNotify\":\n\t\tset(\"shownNotify\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"kludgeRender\":\n\t\t/* This is a kludge to get around a BUG */\n\t\treturn after(1, self(), \"render\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www246[] = "left2right";
static char _slotValue_www247[] = "20";
/* END OF OBJ */

static char _slotValue_www249[] = "vpane";
static char _slotValue_www250[] = "www.doc.view";
static char _slotValue_www251[] = "www.doc.view.lbar";
static char _slotValue_www252[] = "www.doc.view.lbar.pane www.doc.view.lbar.ctrls";
static char _slotValue_www253[] = "\n\tswitch (arg[0]) {\n\tcase \"barScroll\":\n\t\treturn send(nthChild(0), arg[0], arg[1]);\n\tbreak;\n\tcase \"enable\":\n\t\tenable = 1;\n\t\tbarURL = arg[1];\n\t\tbarRatio = arg[2];\n\t\tbarMaxWidth = arg[3];\n\t\tparentWidth = arg[4];\n\n\t\tif (barMaxWidth != 0) {\n\t\t\tbarWidth = barMaxWidth;\n\t\t} else {\n\t\t\tbarWidth = float(parentWidth) * \n\t\t\t\t\tfloat(barRatio) / 100.0;\n\t\t}\n\t\tset(\"width\", barWidth);\n\t\tset(\"maxWidth\", barWidth);\n\t\tset(\"visible\", 1);\n\t\tsend(nthChild(0), \"show\", barURL, barWidth);\n\t\treturn;\n\tbreak;\n\tcase \"disable\":\n\t\tenable = 0;\n\t\tset(\"visible\", 0);\n\t\tset(\"y\", 999);/*???? why won't this window go away??*/\n\t\treturn;\n\tbreak;\n\tcase \"lbarEnabledP\":\n\t\treturn enable;\n\tbreak;\n\tcase \"resetWidthConstraint\":\n\t\tparentWidth = arg[1];\n\t\tbarWidth = float(parentWidth) * float(barRatio) / 100.0;\n\t\tset(\"width\", 99);/*lame way to force a re config */\n\t\tset(\"maxWidth\", barWidth);\n\t\treturn;\t\t\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_www266[] = "\n\tswitch (arg[0]) {\n\tcase \"barScroll\":\n\t\treturn send(parent(), arg[0], arg[1]);\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www267[] = "1";
static char _slotValue_www268[] = "20";
/* END OF OBJ */

static char _slotValue_www270[] = "txtButton";
static char _slotValue_www271[] = "www.doc.view.lbar.ctrls";
static char _slotValue_www272[] = "www.doc.view.lbar.ctrls.up";
static char _slotValue_www273[] = "Up";
static char _slotValue_www274[] = "\n\tif (arg[0] == \"buttonRelease\") send(parent(), \"barScroll\", \"up\");\n\tusual();\n";
static char _slotValue_www275[] = "normal";
static char _slotValue_www276[] = "2";
/* END OF OBJ */

static char _slotValue_www278[] = "txtButton";
static char _slotValue_www279[] = "www.doc.view.lbar.ctrls";
static char _slotValue_www280[] = "www.doc.view.lbar.ctrls.down";
static char _slotValue_www281[] = "Down";
static char _slotValue_www282[] = "\n\tif (arg[0] == \"buttonRelease\") send(parent(), \"barScroll\", \"down\");\n\tusual();\n";
static char _slotValue_www283[] = "normal";
static char _slotValue_www284[] = "1";
/* END OF OBJ */

static char _slotValue_www286[] = "field";
static char _slotValue_www287[] = "www.doc.view.lbar.pane";
static char _slotValue_www288[] = "www.doc.view.lbar";
static char _slotValue_www289[] = "www.doc.view.lbar.sb";
static char _slotValue_www290[] = "\n\tswitch (arg[0]) {\n\tcase \"shownPositionH\":\n\tcase \"shownPositionV\":\n\t\treturn send(docObj, \"shownPositionV\", arg[1]);\n\tbreak;\n\tcase \"barScroll\":\n\t\tif (arg[1] == \"down\") {\n\t\t\tpgPosPct += 10;\n\t\t\tif (pgPosPct > 100) pgPosPct = 100;\n\t\t} else {\n\t\t\tpgPosPct -= 10;\n\t\t\tif (pgPosPct < 0) pgPosPct = 0;\n\t\t}\n\t\treturn send(docObj, \"shownPositionV\", pgPosPct);\n\tbreak;\n\tcase \"show\":\n\t\tbarURL = arg[1];\n\t\tbarWidth = arg[2];\n\n\t\tset(\"width\", barWidth);\n\n\t\tpgPosPct = 0;\n\n\t\thandler = wwwFormatDetect(\"type\", barURL);\n\t\tsend(\"www.mesg.tf\", \"show\", \n\t\t\t    concat(\"Getting sidebar from \", barURL));\n\n\t\tdocObj = send(\"wwwHandlerDispatch\", \n\t\t\t\t\"dispatch\", handler,\n\t\t\t\t0, barURL,\n\t\t\t\tbarURL, self(),\n\t\t\t\tint(barWidth), 999,\n\t\t\t\t\"\", 1, 0);\n\n\t\t/* XXX kludgy stylesheet turn off */\n\t\tSTG_clean(0);\n\n\t\tsend(docObj, \"display\", barWidth, 999);\n\t\tsend(docObj, \"show\");\n\n\t\tpageHeight = send(docObj, \"vspan\");\n\t\tsend(self(), \"configShare\");\n\n\t\treturn;\n\tbreak;\n\tcase \"toDoInsert\":\n\t\tinsertObj[insertObjCount] = arg[1];\n\t\tinsertObjCount++;\n\t\treturn;\n\tbreak;\n\tcase \"show_request_by_child\":\n\tcase \"post_request_by_child\":\n\t\tsend(\"www\", \"busy\");\n\n\t\tif (arg[0] == \"post_request_by_child\") realMesg = \"post\";\n\t\telse realMesg = \"show\";\n\n\t\tif (torn == 1) destObj = self();\n\t\telse destObj = object(\"www\");\n\n\t\tif (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);\n\t\telse stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);\n\n\t\tif (stat) stat = send(\"www.doc.view.pane\", \"historyRecord\");\n\n\t\tsend(\"www\", \"idle\");\n\t\treturn stat;\n\tbreak;\n\tcase \"setChildren\":\n\t\tset(\"children\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"configShare\":\n\t\theightDiff = pageHeight - get(\"height\");\n\t\theightRatio =  float(heightDiff) / -100.0;\n\t\tif (heightDiff > 0) {\n\t\t  sliderSize = float(get(\"height\")) / float(pageHeight) * 100;\n\t\t  sliderPos = float(pageYPos) / float(heightDiff) * -100;\n\t\t} else {\n\t\t  sliderSize = 100;\n\t\t  sliderPos = 0;\n\t\t}\n\t\tobjectListSend(\"shownDepend\", \"_shownInfoH\", \n\t\t\t\tsliderPos, sliderSize);\n\t\tobjectListSend(\"shownDepend\", \"setShownNotify\", docObj);\n\t\treturn;\n\tbreak;\n\tcase \"configSliderGeom\":\n\t\tpageHeight = send(docObj, \"vspan\");\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"configSlider\":\n\t\t/* arg[1]\tpageYPos\n\t\t * arg[2]\tpageHeight\n\t\t */\n\t\tpageYPos = arg[1];\n\t\tpageHeight = arg[2];\n\t\tif (pageYPos + pageHeight < get(\"height\")) {\n\t\t\tpageYPos = get(\"height\") - pageHeight;\n\t\t\tif (pageYPos > 0) pageYPos = 0;\n\t\t\tsend(docObj, \"y\", pageYPos);\n\t\t}\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tif (send(parent(), \"lbarEnabledP\") == 0) return;\n\t\tusual();\n\t\t/* ask page object to do the calculation */\n\t\tsend(docObj, \"resize\", get(\"width\"), get(\"height\"));\n\t\tpageYPos = send(docObj, \"yP\");\n\t\tpageHeight = send(docObj, \"vspan\");\n\t\tif (pageYPos + pageHeight < get(\"height\")) {\n\t\t\tpageYPos = get(\"height\") - pageHeight;\n\t\t\tsend(docObj, \"y\", pageYPos);\n\t\t}\n\t\tsend(self(), \"configShare\");\n\t\tconfiged = 1;\n\t\treturn;\n\tbreak;\n\tcase \"update\":\n\t\tpageObj = nthChild(0);\n\t\tpageHeight = arg[1];\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"destroyDoc\":\n\tcase \"destroyDoc_qualified\":\n\t\tsend(pageObj, \"VW_event\", \"VIEW_OFF\");\n\t\tsend(pageObj, \"visible\", 0);\n\t\tsend(pageObj, \"freeSelf\");\n\t\tpageObj = 0;\n\t\treturn;\n\tbreak;\n\tcase \"addTool\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(parent(), arg[0], arg[1]);\n\tbreak;\n\tcase \"showSrc\":\n\tcase \"reload\":\n\tcase \"clone\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\tcase \"whichPageP\":\n\t\treturn nthChild(0);\n\tbreak;\n\tcase \"heightP\":\n\t\treturn height();\n\tbreak;\n\tcase \"R\": /* happens sometimes. blah */\n\tcase \"reportNextID\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_www301[] = "\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\treturn send(pageObj, \"shownPositionV\", arg[1]);\n\tbreak;\n\tcase \"initKludge\":\n\t\treturn;\n\tbreak;\n\tcase \"show\":\n\tcase \"post\":\n\t\tif (configed == 0) {\n\t\t\tafter(1000, self(), arg[0], arg[1]);\n\t\t\treturn -1;\n\t\t}\n\n\t\tif (arg[0] == \"post\") {\n\t\t\tdoPost = 1;\n\t\t\tpostData = arg[3];\n\t\t} else { \n\t\t\tdoPost = 0;\n\t\t\tpostData = 0;\n\t\t}\n\t\tif (torn == 1) {\n\t\t\tif (arg[] == 2)\n\t\t\t\treturn send(\"www.doc.view.pane\", \n\t\t\t\t\t    arg[0], arg[1]);\n\t\t\telse if (arg[] == 3)\n\t\t\t\treturn send(\"www.doc.view.pane\", \n\t\t\t\t\t    arg[0], arg[1], arg[2]);\n\t\t\telse\treturn send(\"www.doc.view.pane\", \n\t\t\t\t\t    arg[0], arg[1], arg[2], arg[3]);\n\t\t}\n\t\tif (nthChar(arg[1], 0) == '#') {\t\n\t\t\tpageYPos = send(pageObj, \"gotoAnchor\", \n\t\t\t\t\tnthChar(arg[1], 1, 999));\n\n\t\t\tpageHeight = send(pageObj, \"vspan\");\n\t\t\theightDiff = pageHeight - get(\"height\");\n\t\t\theightRatio =  float(heightDiff) / -100.0;\n\n\t\t\tif (heightDiff > 0) {\n\t\t\t\tsliderSize = float(get(\"height\")) / \n\t\t\t\t\t\tfloat(pageHeight) * 100;\n\t\t\t\tsliderPos = float(pageYPos) / \n\t\t\t\t\t\tfloat(heightDiff) * 100;\n\t\t\t\tif (sliderPos > 100) sliderPos = 100;\n\t\t\t} else {\n\t\t\t\tsliderSize = 100;\n\t\t\t\tsliderPos = 0;\n\t\t\t}\n\t\t\tsend(pageObj, \"shownPositionV\", sliderPos);\n\t\t\tobjectListSend(\"shownDepend\", \"_shownInfoV\", \n\t\t\t\t\tsliderPos, sliderSize);\n\t\t\tobjectListSend(\"shownDepend\", \"setShownNotify\",\n\t\t\t\t\tpageObj);\n\t\t} else {\n\t\t\tif (arg[] == 2) \n\t\t\t\tnormURL = send(\"normalizeURL\", \"normalizeURL\",\n\t\t\t\t\t\targ[1]);\n\t\t\telse \n\t\t\t\tnormURL = send(\"normalizeURL\", \"normalizeURL\",\n\t\t\t\t\t\targ[1], arg[2]);\n\n\t\t\toldDocName = docName;\n\t\t\tdocName = normURL;\n\t\t\tdocURL = normURL;\n\n\t\t\tif (findPattern(arg[1], \"telnet:\") != -1) {\n\t\t\t\tcmd = send(\"WWWTelnetHandler\", \"connect\", \n\t\t\t\t\t\tnormURL);\n\t\t\t\twww.mesg.tf(\"warn\", cmd);\n\t\t\t\tsystem(cmd);\n\t\t\t\treturn normURL;\n\t\t\t} else if (findPattern(arg[1], \"mailto:\") != -1) {\n\t\t\t\tsubject = concat(\"WWW mail from: \", \n\t\t\t\t\t\tormalizedURL);\n\t\t\t\ttt = arg[1];\n\t\t\t\ti = findPattern(tt, \"/\");\n\t\t\t\tif (i == -1) {\n\t\t\t\t\taddress = nthChar(tt, 7, 999);\n\t\t\t\t\tcontent = concat(\n\t\t\t\t\"This mail was generated by WWW URL:\\n\",\n\t\t\t\t\t\t   tt, \"\\n\");\n\t\t\t\t} else {\n\t\t\t\t\taddress = nthChar(tt, 7, i-1);\n\t\t\t\t\tcontent = concat(nthChar(tt, io1, 999),\n\t\t\t\t\t\t\t \"\\n\");\n\t\t\t\t}\n\t\t\t\ttmpFile = makeTempFile();\n\t\t\t\tsaveFile(tmpFile, content);\n\n\t\t\t\tcmd = concat(\"mail -s \\\"\", subject,\n\t\t\t\t\t     \"\\\" \", address, \" < \", tmpFile);\n\t\t\t\tsystem(cmd);\n\t\t\t\tsystem(concat(\"rm \", tmpFile));\n\t\t\t\treturn normURL;\n\t\t\t}\n\t\t\tanchor = parseHTTPAddress(\"anchor\", normURL);\n\n\t\t\tif (exist(pageObj) == 1) send(pageObj, \"undisplay\");\n\n\t\t\tif (exist(docName) == 1) {\n\t\t\t\tset(\"children\", docName);\n\t\t\t\tif (anchor != \"\")  {\n\t\t\t\t\tif (findPattern(docURL, \".hmml\") > -1){\n\t\t\t\t\t\tpageYPos = send(docName, \n\t\t\t\t\t\t\t\t\"gotoAnchor\",\n\t\t\t\t\t\t\t\t anchor) * -1;\n\t\t\t\t\t\tsend(docName, \"y\", pageYPos);\n\t\t\t\t\t}\n\t\t\t\t} else {\n\t\t\t\t\tpageYPos = send(docName, \"yP\");\n\t\t\t\t}\n\t\t\t\tif (send(docName, \"configSideBar\") == 1) {\n\t\t\t\t\tsend(parent(), \"linkSideBar\", \n\t\t\t\t  sideBarURL, sideBarRatio, sideBarMaxWidth);\n\t\t\t\t} else {\n\t\t\t\t\tsend(parent(), \"lbarConfig\", \"off\");\n\t\t\t\t}\n\t\t\t\tsend(docName, \"display\", width(), height());\n\t\t\t} else {\n\t\t\t\t/* a rough guess at the document type */\n\t\t\t\thandler = wwwFormatDetect(\"type\", docURL);\n\t\t\t\tsend(\"www.mesg.tf\", \"show\", \n\t\t\t\t\t    concat(\"Getting \", docURL));\n\n\t\t\t\tif (torn == 1) paneObj = \"www.doc.view.pane\";\n\t\t\t\telse paneObj = self();\n\n\t\t\t\tdocObj = send(\"wwwHandlerDispatch\", \n\t\t\t\t\t\t\"dispatch\", handler,\n\t\t\t\t\t\tdoPost, docURL,\n\t\t\t\t\t\tdocName, paneObj,\n\t\t\t\t\t\tget(\"width\"), get(\"height\"),\n\t\t\t\t\t\tanchor, 1, postData);\n\n\t\t\t\t/* XXX kludgy stylesheet turn off */\n\t\t\t\tSTG_clean(0);\n\n\t\t\t\tif (docObj == 0) {\n\t\t\t\t\tif (exist(\"www.mesg.tf\"))\n\t\t\t\t\t\twww.mesg.tf(\"show\",\n\t\t\t\t\t\t concat(\"Failed \", docURL));\n\t\t\t\t\twinPos = windowPosition();\n\t\t\t\t\tres.dialogWithButtons(\"showAt\", \n\t\t\t\t\t\twinPos[0] + 20, winPos[1] + 20,\n\t\t\t\t\t\t500, 80,\n\t\t\t\t\t\tconcat(\"Failed to access\\n\", \n\t\t\t\t\t\t\tdocURL),\n\t\t\t\t\t\t\"Dismiss\", \"\");\n\t\t\t\t\treturn 0;\n\t\t\t\t} else if (docObj == 1) {\n\t\t/* It's OK.. no doc object generated but wasn't an error \n\t\t * (ie: to be rendered by external viewer) */\n\t\t\t\t\treturn 0;\n\t\t\t\t}\n\n\t\t\t\tif (send(docName, \"configSideBar\") == 1) {\n\t\t\t\t\tsend(parent(), \"linkSideBar\", \n\t\t\t\t  sideBarURL, sideBarRatio, sideBarMaxWidth);\n\t\t\t\t} else {\n\t\t\t\t\tsend(parent(), \"lbarConfig\", \"off\");\n\t\t\t\t}\n\n\t\t\t\tif (insertObjCount > 0) {\n\t\t\t\t\tfor (i = 0; i < insertObjCount; i++)\n\t\t\t\t\t\tsend(insertObj[i], \"insert\");\n\t\t\t\t\tinsertObjCount = 0;\n\t\t\t\t\tsend(self(), \"R\", \n\t\t\t\t\t\tget(\"y\"), get(\"width\"));\n\t\t\t\t}\n\t\t\t\tsend(docObj, \"display\", \n\t\t\t\t\t\tget(\"width\"), get(\"height\"));\n\t\t\t\tsend(docObj, \"show\");\n\t\t\t\tpageYPos = send(docObj, \"yP\");\n\n\t\t\t}\n\t\t\too = object(docName);\n\t\t\tif (oldDocName != docName) {\n\t\t\t\tif (pageObj) {\n\t\t\t\t\tsend(pageObj, \"VW_event\", \"VIEW_OFF\");\n\t\t\t\t}\n\t\t\t\tpageObj = oo;\n\t\t\t\tsend(pageObj, \"VW_event\", \"VIEW_ON\");\n\t\t\t} else {\n\t\t\t\tpageObj = oo;\n\t\t\t}\n\n\t\t\tpageHeight = send(pageObj, \"vspan\");\n\t\t\tsend(self(), \"configShare\");\n\t\t}\n\n\t\ttitle = send(pageObj, \"queryTitle\");\n\t\tif (isBlank(title)) title = pageObj;\n\t\twww.doc.title.tf(\"show\", title);\n\n\t\twww.url.tf(\"show\", send(pageObj, \"queryAddress\"));\n\n\t\tif (notYetRecordedInitDocInHistory) {\n\t\t\t/* this special case for the initial document\n\t\t\t */\n\t\t\tnotYetRecordedInitDocInHistory = 0;\n\t\t\tsend(\"www.doc.view.pane\", \"historyRecord\");\n\t\t}\n\n\t\treturn docName;\n\tbreak;\n\tcase \"toDoInsert\":\n\t\tinsertObj[insertObjCount] = arg[1];\n\t\tinsertObjCount++;\n\t\treturn;\n\tbreak;\n\tcase \"show_request_by_child\":\n\tcase \"post_request_by_child\":\n\t\tsend(\"www\", \"busy\");\n\n\t\tif (arg[0] == \"post_request_by_child\") realMesg = \"post\";\n\t\telse realMesg = \"show\";\n\n\t\tif (torn == 1) destObj = self();\n\t\telse destObj = object(\"www\");\n\n\t\tif (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);\n\t\telse stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);\n\n\t\tif (stat) stat = send(\"www.doc.view.pane\", \"historyRecord\");\n\n\t\tsend(\"www\", \"idle\");\n\t\treturn stat;\n\tbreak;\n\tcase \"hintOn\":\n\t\twww.mesg.tf(\"show\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"hintOff\":\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"setChildren\":\n\t\tset(\"children\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"configShare\":\n\t\theightDiff = pageHeight - get(\"height\");\n\t\theightRatio =  float(heightDiff) / -100.0;\n\t\tif (heightDiff > 0) {\n\t\t  sliderSize = float(get(\"height\")) / float(pageHeight) * 100;\n\t\t  sliderPos = float(pageYPos) / float(heightDiff) * -100;\n\t\t} else {\n\t\t  sliderSize = 100;\n\t\t  sliderPos = 0;\n\t\t}\n\t\tobjectListSend(\"shownDepend\", \"_shownInfoV\", \n\t\t\t\tsliderPos, sliderSize);\n\t\tobjectListSend(\"shownDepend\", \"setShownNotify\", pageObj);\n\t\treturn;\n\tbreak;\n\tcase \"configSliderGeom\":\n\t\tpageHeight = send(pageObj, \"vspan\");\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"configSlider\":\n\t\t/* arg[1]\tpageYPos\n\t\t * arg[2]\tpageHeight\n\t\t */\n\t\tpageYPos = arg[1];\n\t\tpageHeight = arg[2];\n\t\tif (pageYPos + pageHeight < get(\"height\")) {\n\t\t\tpageYPos = get(\"height\") - pageHeight;\n\t\t\tif (pageYPos > 0) pageYPos = 0;\n\t\t\tsend(pageObj, \"y\", pageYPos);\n\t\t}\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tusual();\n\t\tif (send(pageObj, \"viewP\") == 1) {\n\t\t\t/* when switching from a sidebar'ed document to\n\t\t\t * a non-sidebar document, this object will be\n\t\t\t * 'configed' (and before the new document gets\n\t\t\t * configed... so we don't want to bother \n\t\t\t * that document (pageObj) until it is ready\n\t\t\t * (when viewP == 1).\n\t\t\t */\n\t\t\t/* ask page object to do the calculation */\n\t\t\tsend(pageObj, \"resize\", get(\"width\"), get(\"height\"));\n\t\t\tpageYPos = send(pageObj, \"yP\");\n\t\t\tpageHeight = send(pageObj, \"vspan\");\n\t\t\tif (pageYPos + pageHeight < get(\"height\")) {\n\t\t\t\tpageYPos = get(\"height\") - pageHeight;\n\t\t\t\tsend(pageObj, \"y\", pageYPos);\n\t\t\t}\n\t\t\tsend(self(), \"configShare\");\n\t\t}\n\t\t/* this call should not be necessary... what was it for? */\n\t\t/*objectListSend(\"shownDepend\", \"kludgeRender\");*/\n\n\t\tconfiged = 1;\n\t\treturn;\n\tbreak;\n\tcase \"update\":\n\t\tpageObj = nthChild(0);\n\t\tpageHeight = arg[1];\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"destroyDoc\":\n\tcase \"destroyDoc_qualified\":\n\t\tsend(pageObj, \"VW_event\", \"VIEW_OFF\");\n\t\tsend(pageObj, \"visible\", 0);\n\t\tsend(pageObj, \"freeSelf\");\n\t\tpageObj = 0;\n\t\treturn;\n\tbreak;\n\tcase \"addTool\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(parent(), arg[0], arg[1]);\n\tbreak;\n\tcase \"CE_change\":\n\t\t/* arg[1] \tCE objPath\n\t\t * arg[2]\tCE newData\n\t\t */\n\t\treturn send(pageObj, arg[0], arg[1], arg[2]);\n\tbreak;\n\tcase \"CE_lock\":  /* arg[1] \tCE objPath */\n\tcase \"CE_unlock\":\n\tcase \"editMode\":\n\tcase \"search\":\n\t\treturn send(pageObj, arg[0], arg[1]);\n\tbreak;\n\tcase \"searchByTag\":\n\t\t/* arg[1]\tenglish desc of searching field\n\t\t * arg[2]\ttag(set)\n\t\t */\n\t\tsend(\"res.getLineEntry\", \"show\", \n\t\t\tconcat(\"Enter keyword to search in \", arg[1], '.'),\n\t\t\t\"\", self(), \"searchByTag_specified\");\n\t\treturn;\n\tbreak;\n\tcase \"searchByTag_specified\":\n\t\t/* arg[1]\ttag\n\t\t * arg[2]\tkeyword\n\t\t */\n\t\treturn send(pageObj, \"searchByTag\", arg[1], arg[2]);\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"-------------\\nTHIS FACILITY IS NOT YET WORKING\\n\");\n\t\tsend(pageObj, \"outputSGML\");\n\t\tprint(\"-------------\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"mailToAuthor\":\n\t\tcontactURL = send(pageObj, \"queryAuthor\");\n\t\tif (contactURL) {\n\t\t\tres.dialogWithButtons(\"show\", \n\t\t\t concat(\"The declared author contact is:\\n\", \n\t\t\t\tcontactURL),\n\t\t\t \"Dismiss\", \"\");\n\t\t} else {\n\t\t\tres.dialogWithButtons(\"show\", \n\t\t\t \"Sorry, no author contact declared in the document.\",\n\t\t\t \"Dismiss\", \"\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"linkSideBar\":\n\t\tsideBarURL = arg[1];\n\t\tsideBarRatio = arg[2];\n\t\tsideBarMaxWidth = arg[3];\n\t\treturn;\n\tbreak;\n\tcase \"showSrc\":\n\tcase \"reload\":\n\tcase \"clone\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\tcase \"whichPageP\":\n\t\treturn nthChild(0);\n\tbreak;\n\tcase \"heightP\":\n\t\treturn height();\n\tbreak;\n\tcase \"expose\":\n/* Trap this event to inhibit the default behavior to re-arrange geometry\n * which would cause uncessary reloading of HTML docs (b/c children would\n * get config messages). We still want to use hpane here because we do want to\n * reload (to reformat) HTML docs if width is changed.\n */\n\t\tif (todo) {\n\t\t\thomeDoc = www(\"homeDocP\");\n\t\t\twww(\"show\", homeDoc);\n\t\t\ttodo = 0;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"historyRecord\":\n\t\tsend(pageObj, \"historyRecord\");\n\t\treturn;\n\tbreak;\n\tcase \"R\": /* happens sometimes. blah */\n\tcase \"reportNextID\":\n\t\treturn;\n\tbreak;\n\tcase \"getCurrentDocURL\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"getCurrentDocTitle\":\n\t\treturn title;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tnotYetRecordedInitDocInHistory = 1;\n\t\tconfiged = 0;\n\t\ttodo = 0;\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\t/* arg[1]\torig object */\n\t\ttorn = 1;\n\t\tsend(nthChild(0), \"torn\", arg[1]);\n\t\tpageObj = nthChild(0);\n\t\t/* make self reset variables */\n\t\tsend(self(), \"update\", send(pageObj, \"vspan\"));\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_www318[] = "\n\tswitch (arg[0]) {\n\tcase \"suggest\":\n\t\tif (suggest == 0) return;\n\t\tif (get(\"visible\")) {\n\t\t\tif (arg[2] == \"leave\") {\n\t\t\t\tset(\"content\", \"\");\n\t\t\t\trender();\n\t\t\t\tflush();\n\t\t\t} else {\n\t\t\t\thint = send(arg[1], \"hint\");\n\t\t\t\tif (isBlank(hint) == 0) {\n\t\t\t\t\tset(\"content\", hint);\n\t\t\t\t\trender();\n\t\t\t\t\tflush();\n\t\t\t\t}\n\t\t\t}\n\t\t\tisCleared = 0;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"show_progress\":\n\t\t/* arg[1]\tpercent\n\t\t * arg[2]\tbytes so far\n\t\t */\n\t\tset(\"content\", \n\t\t\tconcat(\"Retrieved \", arg[2], \" bytes, \", arg[1], \"%\"));\n\t\tsend(\"www.doc.tools.httpStat.icon\", \"stat\", arg[1]);\n\t\tisCleared = 0;\n\t\treturn;\n\tbreak;\n\tcase \"alert\":\n\tcase \"flash\":\n\tcase \"show\":\n\tcase \"warn\":\n\t\tset(\"content\", arg[1]);\n\t\trender();\n\t\tflush();\n\t\tisCleared = 0;\n\t\treturn;\n\tbreak;\n\tcase \"dialog_confirm\":\n\t\t/* arg[1] message \n\t\t * ret: yes(1) or no(0)\n\t\t */\n\t\treturn wwwDialog_confirm(\"confirm\", arg[1]);\n\tbreak;\n\tcase \"dialog_prompt_default\":\n\t\t/* arg[1] message \n\t\t * arg[2] default\n\t\t * ret: modification of the 'default' string.\n\t\t */\n\t\treturn wwwDialog_prompt_default(\"prompt\", arg[1], arg[2]);\n\tbreak;\n\tcase \"dialog_prompt_password\":\n\t\t/* arg[1] message \n\t\t * ret: password\n\t\t */\n\t\treturn wwwDialog_prompt_password(\"prompt\", arg[1]);\n\tbreak;\n\tcase \"dialog_prompt_username_and_password\":\n\t\t/* arg[1] message\n\t\t * ret: username'\\n'password\n\t\t */\n\t\treturn wwwDialog_prompt_username_and_password(\"prompt\", arg[1]);\n\tbreak;\n\tcase \"clear\":\n\t\tif (isCleared == 0) {\n\t\t\tset(\"content\", \"\");\n\t\t\trender();\n\t\t\tflush();\n\t\t\tisCleared = 1;\n\t\t}\n/*XXX many needless operations*/\n\t\tsend(\"www.doc.tools.httpStat.icon\", \"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\t\tset(\"cursor\", 0);\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"The active hints/message text field....\";\n\tbreak;\n\tcase \"keyPress\":\n\t\treturn;\n\tbreak;\n\tcase \"turnOffSuggest\":\n\t\tsuggest = 0;\n\t\twww.mesg.tf(\"warn\", \"Active help is now off.\");\n\t\treturn;\n\tbreak;\n\tcase \"toggleSuggest\":\n\t\tif (suggest == 1) {\n\t\t\tsuggest = 0;\n\t\t\twww.mesg.tf(\"warn\", \"Active help is now off.\");\n\t\t} else {\n\t\t\tsuggest = 1;\n\t\t\twww.mesg.tf(\"warn\", \"Active help is now on.\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n/*\t\tafter(50000, \"www.mesg.tf\", \"clear\");*/\n\t\tsuggest = 0;\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www319[] = "2";
static char _slotValue_www320[] = "1";
static char _slotValue_www321[] = "fixed";
/* END OF OBJ */

static char _slotValue_www323[] = "field";
static char _slotValue_www324[] = "www.progress";
static char _slotValue_www325[] = "www";
static char _slotValue_www326[] = "\n\tswitch (arg[0]) {\n\tcase \"stat\":\n\t\tif (arg[1] == -1) xxx = width();\n\t\telse xxx = float(arg[1]) / 100.0 * width();\n\t\tclearWindow();\n\t\tdrawFillRect(0, 1, xxx, 3);\n\t\tflush();\n\t\treturn;\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tprint(\"IIIIIIIIIIIIII INTERRUPT TTTTTTTTTTT... sorry, you can't. yet.\\n\");\n\tbreak;\n\tcase \"clear\":\n\t\txxx = 0;\n\t\tclearWindow();\n\t\tflush();\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\tif (xxx) drawFillRect(0, 1, xxx, 3);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www327[] = "5";
/* END OF OBJ */

static char _slotValue_www329[] = "XBMButton";
static char _slotValue_www330[] = "www.ahelp.label";
static char _slotValue_www331[] = "www.mesg";
static char _slotValue_www332[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\txx = get(\"label\");\n\t\tset(\"label\", get(\"content\"));\n\t\tset(\"content\", xx);\n\t\trender();\n\t\twww.mesg.tf(\"toggleSuggest\");\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Click to toggle active helper.\";\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www333[] = "#define bubble1_width 16\n#define bubble1_height 16\nstatic char bubble1_bits[] = {\n   0x00, 0x00, 0xe0, 0x07, 0xf8, 0x1f, 0xfc, 0x3f, 0x8c, 0x36, 0xae, 0x74,\n   0xae, 0x74, 0xae, 0x72, 0xae, 0x72, 0xac, 0x36, 0x8c, 0x36, 0xf8, 0x1f,\n   0xe0, 0x07, 0x78, 0x00, 0x06, 0x00, 0x00, 0x00};\n";
static char _slotValue_www334[] = "#define bubble0_width 16\n#define bubble0_height 16\nstatic char bubble0_bits[] = {\n   0x00, 0x00, 0xe0, 0x07, 0xf8, 0x1f, 0xfc, 0x3f, 0x8c, 0x24, 0xae, 0x76,\n   0xae, 0x64, 0xae, 0x76, 0xae, 0x76, 0xac, 0x36, 0x8c, 0x36, 0xf8, 0x1f,\n   0xe0, 0x07, 0x78, 0x00, 0x06, 0x00, 0x00, 0x00};\n";
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
static char _slotValue_www358[] = "\n\tswitch (arg[0]) {\n\tcase \"keyPress\":\n\t\tc = key();\n\t\tif (c == '\\r') {\n\t\t\tsend(\"www\", \"showHistoryDoc\", trimEdge(currentLine()));\n\t\t\trender();\n\t\t} else {\n\t\t\tinsert(c);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"getURLFromClipBuffer\":\n\t\tsend(\"www\", \"showHistoryDoc\", trimEdge(getSelection()));\n\t\treturn;\n\tbreak;\n\tcase \"appendURLToHome\":\n\t\twww.mesg.tf(\"alert\", \n\t\t\t    \"Sorry, can't yet append to home page.\");\n\t\treturn;\n\tbreak;\n\tcase \"show\":\n\t\tset(\"content\", trimEdge(arg[1]));\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\tusual();\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"The current document address. Can edit URL there, then press return to follow.\";\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www359[] = "fixed";
/* END OF OBJ */

static char _slotValue_www361[] = "XBMButton";
static char _slotValue_www362[] = "www.url.setURL";
static char _slotValue_www363[] = "www.url";
static char _slotValue_www364[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\twww.url.tf(\"getURLFromClipBuffer\");\n\tbreak;\n\tcase \"enter\":\n\tcase \"leave\":\n\t\twww.mesg.tf(\"suggest\", get(\"name\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"hint\":\n\t\treturn \"Click to read and follow URL from X selection buffer.\";\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_www365[] = "#define cut_width 16\n#define cut_height 16\nstatic char cut_bits[] = {\n   0x00, 0x00, 0x10, 0x00, 0x18, 0x00, 0xfc, 0x03, 0x18, 0x0c, 0x10, 0x10,\n   0x00, 0x00, 0x38, 0x00, 0x44, 0x78, 0x44, 0xfe, 0x78, 0x0f, 0xc0, 0x00,\n   0x78, 0x0f, 0x44, 0xfe, 0x44, 0x78, 0x38, 0x00};\n";
static char _slotValue_www366[] = "19";
static char _slotValue_www367[] = "3";
/* END OF OBJ */

static char _slotValue_www369[] = "socket";
static char _slotValue_www370[] = "www_com";
static char _slotValue_www371[] = "\n\tswitch (arg[0]) {\n\tcase \"input\":\n\t\tss = input();\n\t\tprint(\">>>> input={\", ss, \"}\\n\");\n\t\tcmd = nthWord(ss, 1);\n\t\tprint(\">>>> cmd={\", cmd, \"}\\n\");\n\n\t\tif (cmd == \"SAID\") {\n\t\t\tsubCmd = nthWord(ss, 3);\n\t\t\tprint(\">>>> subCmd={\", subCmd, \"}\\n\");\n\t\t\tif (subCmd == \"CEObj\") {\n\t\t\t\tCEObjPath = nthWord(ss, 4, 999);\n\t\t\t\tprint(\">>>> CEObjPath={\", CEObjPath, \"}\\n\");\n\t\t\t} else if (subCmd == \"CENewData\") {\n\t\t\t\tCENewData = nthWord(ss, 4, 999);\n\t\t\t\tprint(\">>>> CENewData={\", CENewData, \"}\\n\");\n\t\t\t\tprint(\">>>> decoded CENewData={\", \n\t\t\t\t\tHTTPDecodeURL(CENewData), \"}\\n\");\n\t\t\t\tsend(\"www\", \"CE_change\", \n\t\t\t\t\tCEObjPath, HTTPDecodeURL(CENewData));\n\t\t\t} else if (subCmd == \"CEObjLock\") {\n\t\t\t\tCEObjPath = nthWord(ss, 4, 999);\n\t\t\t\tprint(\">>>> CEObjPath={\", CEObjPath, \"}\\n\");\n\t\t\t\tsend(\"www\", \"CE_lock\", \n\t\t\t\t\tCEObjPath, HTTPDecodeURL(CENewData));\n\t\t\t} else if (subCmd == \"CEObjUnLock\") {\n\t\t\t\tCEObjPath = nthWord(ss, 4, 999);\n\t\t\t\tprint(\">>>> CEObjPath={\", CEObjPath, \"}\\n\");\n\t\t\t\tsend(\"www\", \"CE_unlock\", \n\t\t\t\t\tCEObjPath, HTTPDecodeURL(CENewData));\n\t\t\t} else {\n\t\t\t\tprint(\"www_com: unknown sub command\", \n\t\t\t\t\tsubCmd, \"\\n\");\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"output_change\":\n\t\t/* arg[1]\tnewObjPlacePath\n\t\t * arg[2]\tnewData\n\t\t */\n\t\tprint(\">>>>>>>>>>>>>>>>>>>>\\n\");\n\t\tout = concat(\"SAY CEObj: \", arg[1]);\n\t\tprint(\">>>> output'ing={\", out, \"}\\n\");\n\t\toutput(out);\n\t\tout = concat(\"SAY CENewData: \", HTTPEncodeURL(arg[2]));\n\t\tprint(\">>>> output'ing={\", out, \"}\\n\");\n\t\toutput(out);\n\t\tprint(\">>>>>>>>>>>>>>>>>>>>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"output_lock\":\n\t\t/* arg[1]\tnewObjPlacePath\n\t\t */\n\t\tout = concat(\"SAY CEObjLock: \", arg[1]);\n\t\tprint(\">>>> output'ing={\", out, \"}\\n\");\n\t\toutput(out);\n\t\treturn;\n\tbreak;\n\tcase \"output_unlock\":\n\t\t/* arg[1]\tnewObjPlacePath\n\t\t */\n\t\tout = concat(\"SAY CEObjUnLock: \", arg[1]);\n\t\tprint(\">>>> output'ing={\", out, \"}\\n\");\n\t\toutput(out);\n\t\treturn;\n\tbreak;\n\tcase \"output\":\n\t\tprint(\">>>> output'ing={\", arg[1], \"}\\n\");\n\t\toutput(arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"connect\":\n\t\tprint(\">>>> connecting to host={\", arg[1], \"}\\n\");\n\t\tprint(\">>>> connecting to port={\", arg[2], \"}\\n\");\n\t\tset(\"host\", arg[1]);\n\t\tset(\"port\", arg[2]);\n\t\tset(\"outDelimStr\", \"\\r\\n\");\n\t\tset(\"inDelimStr1\", '\\n');\n\t\tstartClient();\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n/*\t\tsend(self(), \"connect\", \"localhost\", 80);*/\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwAbout3[] = "\n\tswitch (arg[0]) {\n\tcase \"visible\":\n\t\tif (arg[1] == 1) {\n\t\t\tif (get(\"visible\") == 1) {\n\t\t\t\tset(\"visible\", 0);\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tvwWinPos = send(\"www\", \"winPosition\");\n\t\t\tset(\"x\", vwWinPos[0] + 20);\n\t\t\tset(\"y\", vwWinPos[1] + 130);\n\t\t\tsend(\"wwwAbout.fld.states\", \"inView\", 1);\n\t\t\tsend(\"wwwAbout.fld.states\", \"tic\");\n\t\t}\n\tbreak;\n\tcase \"dismiss\":\n\t\tsend(\"wwwAbout.fld.states\", \"inView\", 0);\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwAbout15[] = "#define violaDemo_width 104\n#define violaDemo_height 132\nstatic char violaDemo_bits[] = {\n 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,\n 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x16,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0x00,0x00,0x80,0x5e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0xba,0xaf,0x6e,0x00,0x00,0x00,0x00,0xa0,0x00,0x00,0x00,0x00,\n 0x00,0xee,0xff,0xfb,0x00,0x00,0x00,0x00,0x60,0x01,0x00,0x00,0x00,0x00,0xff,\n 0xff,0x7f,0x01,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x00,0xba,0x5f,0xb7,\n 0x00,0x00,0x00,0x00,0xe8,0x02,0x00,0x00,0x00,0x00,0xa4,0xae,0x54,0x01,0x00,\n 0xba,0xbb,0xfb,0x00,0x00,0x00,0x00,0x00,0x88,0x1e,0x01,0x00,0x00,0xee,0xee,\n 0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x17,0x00,0x00,0x00,0xff,0xff,0x7f,0x01,\n 0x00,0x00,0x00,0x00,0x80,0x2e,0x24,0x00,0x80,0xba,0x7f,0xfb,0x02,0x00,0x00,\n 0x00,0x00,0xbe,0xdf,0x55,0x01,0xa0,0xa2,0xaf,0xea,0x00,0x00,0x00,0x00,0x00,\n 0xf5,0x7e,0x7f,0x00,0x60,0x09,0x1d,0xf8,0x00,0x00,0x00,0x00,0x00,0xff,0xff,\n 0xff,0x01,0xf0,0x00,0x0f,0xe0,0x02,0x00,0x00,0x00,0x00,0xac,0xbf,0x55,0x00,\n 0xd0,0x02,0x2d,0xd0,0x00,0x00,0x00,0x00,0x00,0xaa,0xaf,0xaa,0x00,0xf0,0x00,\n 0x0f,0xf0,0x02,0x00,0x00,0x00,0x00,0x40,0x2e,0x00,0x00,0xe0,0x02,0x2e,0xd0,\n 0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x70,0x81,0x0e,0xf0,0x01,0x00,\n 0x00,0x00,0x00,0x00,0x2e,0x00,0x00,0xe0,0x00,0x2a,0xa4,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x17,0x00,0x00,0xf0,0x02,0xaa,0x55,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x0d,0x00,0x00,0xd0,0x00,0xe8,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x00,\n 0x00,0xf0,0x02,0xd0,0x2f,0x00,0x00,0x00,0x00,0x00,0x00,0x0d,0x00,0x00,0xa0,\n 0x00,0x60,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x2f,0x00,0x00,0x40,0x00,0x50,\n 0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,\n 0x00,0x00,0x00,0x00,0x00,0x2f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x40,0x0d,0x00,0x00,0x28,0x00,0x40,0x4a,0x00,0x00,0x00,0x00,0xa0,\n 0x5b,0x2f,0x00,0x00,0xaa,0xf7,0x5e,0x55,0x00,0x00,0x00,0x00,0xe0,0xfe,0x0f,\n 0x00,0x00,0xfd,0xde,0xfb,0x7f,0x01,0x00,0x00,0x00,0xf0,0xff,0x2f,0x00,0x00,\n 0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0xe8,0xff,0x0f,0x00,0x00,0xaa,0xb5,\n 0x56,0x55,0x01,0x00,0x00,0xa0,0xfb,0xff,0x0f,0x00,0x00,0xaa,0xaa,0xaa,0xaa,\n 0x00,0x00,0x00,0xe0,0xfe,0xff,0x2f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0xf0,0xff,0xff,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe8,\n 0xdf,0xde,0x2f,0x00,0x00,0x00,0x00,0xaa,0x02,0x00,0x00,0x00,0xfa,0x5f,0x51,\n 0x0f,0x00,0x00,0x00,0x00,0x55,0x0d,0x00,0x00,0x00,0xfe,0x2f,0x04,0x0d,0x00,\n 0x00,0x00,0x00,0xf6,0x16,0x00,0x00,0x00,0xff,0x0f,0x00,0x1f,0x00,0x00,0x00,\n 0x80,0xfe,0x0f,0x00,0x00,0x00,0xdd,0x16,0x00,0x0d,0x00,0x00,0x00,0x80,0x6e,\n 0x57,0x00,0x00,0x00,0xaf,0x02,0x00,0x2f,0x00,0x00,0x00,0x50,0xa9,0x54,0x01,\n 0x00,0x00,0x1e,0x08,0x00,0x0e,0x00,0x00,0x00,0xe0,0x02,0x68,0x00,0x00,0x00,\n 0x0d,0x00,0x80,0x2e,0x00,0x00,0x00,0xe8,0x00,0xd0,0x01,0x00,0x80,0x2e,0x00,\n 0x00,0x0a,0x00,0x00,0x00,0x70,0x01,0xf0,0x00,0x00,0xa0,0x0f,0x00,0x00,0x12,\n 0x00,0x00,0x00,0xe0,0x00,0xd0,0x01,0x00,0xe0,0x2f,0x00,0x00,0x00,0x00,0x00,\n 0x00,0xf0,0x01,0xf0,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x50,\n 0x01,0xd0,0x02,0x00,0xd0,0x15,0x00,0x00,0x04,0x00,0x00,0x00,0xe0,0x24,0x69,\n 0x01,0x00,0xf0,0x05,0x00,0x00,0x0a,0x00,0x00,0x00,0x20,0xab,0x2a,0x00,0x00,\n 0x60,0x01,0x00,0x00,0x15,0x00,0x00,0x00,0x80,0xde,0x97,0x00,0x00,0xd0,0x02,\n 0x00,0x00,0x0f,0x00,0x00,0x00,0x00,0xfd,0x0f,0x00,0x00,0xf0,0x00,0x00,0x00,\n 0x14,0x00,0x00,0x00,0x00,0x76,0x2b,0x00,0x00,0xe0,0x01,0x00,0x00,0x0a,0x00,\n 0x00,0x00,0x00,0x54,0x05,0x00,0x00,0x70,0x01,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0x00,0x00,0xd0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0xf0,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x4a,0x4a,0x00,\n 0x00,0xe0,0x05,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xaa,0x2a,0x00,0x00,0xf0,\n 0x2f,0x00,0x00,0x00,0x00,0x00,0x60,0xd1,0xfb,0xf7,0x02,0x00,0xe0,0x17,0x00,\n 0x00,0x00,0x00,0x00,0xf0,0xf0,0xff,0xff,0x00,0x00,0xd0,0x2e,0x00,0x00,0x00,\n 0x00,0x00,0xa0,0xa0,0x5d,0x5d,0x01,0x00,0x40,0x5f,0x00,0x00,0x16,0xa0,0xbb,\n 0x40,0xa1,0x52,0xa5,0x00,0x00,0x80,0xfe,0x00,0x00,0x05,0xd0,0x6e,0x01,0x00,\n 0x04,0x10,0x00,0x00,0x00,0xff,0x02,0x00,0x1e,0xf0,0xff,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0xfa,0x00,0x00,0x05,0xa0,0x7b,0x25,0x01,0x00,0x00,0x00,0x00,\n 0x00,0xea,0x02,0x00,0x2a,0x40,0x4a,0xd5,0x16,0x00,0x00,0x00,0x00,0x00,0xf8,\n 0x00,0x00,0x00,0x80,0x00,0xbf,0x0d,0x00,0x00,0x00,0x00,0x00,0x60,0x01,0x00,\n 0x00,0x00,0x80,0xfe,0x2f,0x00,0x00,0x00,0x00,0x00,0xd0,0x01,0x00,0x00,0x00,\n 0x00,0xea,0x0b,0x84,0x04,0x00,0x00,0x00,0xf0,0x07,0x00,0x00,0x00,0x00,0x14,\n 0xda,0xb5,0x0a,0x00,0x00,0x00,0xd0,0x2d,0x00,0x00,0x00,0x00,0xa0,0xb0,0xef,\n 0x17,0x00,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,0x00,0xe0,0xff,0x0f,0x00,\n 0x00,0x00,0xe0,0x2f,0x00,0x00,0x00,0x00,0x00,0xd0,0xba,0x5f,0x00,0x00,0x00,\n 0xf0,0x0f,0x00,0x06,0x00,0x00,0x00,0xa0,0x4a,0xb7,0x17,0x00,0x00,0xd0,0x2f,\n 0x00,0x2d,0x00,0x00,0x00,0x00,0xa0,0x7e,0x05,0x00,0x00,0xf0,0x0f,0x00,0x0e,\n 0x00,0x00,0x00,0x00,0x00,0xfd,0x1f,0x00,0x00,0xe8,0x17,0x00,0x15,0x00,0x00,\n 0x00,0x00,0x00,0xff,0x07,0x00,0x00,0xfa,0x02,0x00,0x0a,0x00,0x00,0x00,0x00,\n 0xd0,0xff,0x0a,0x00,0x00,0xfd,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xff,\n 0x01,0x00,0x00,0x7f,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xe8,0xff,0x00,0x00,\n 0x80,0xde,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xf2,0xbb,0x00,0x00,0xa0,0x2f,\n 0x00,0x00,0x00,0x00,0x00,0x00,0x5e,0xed,0x26,0x01,0x00,0xe0,0x2e,0x00,0x00,\n 0x00,0x00,0x00,0x00,0xf5,0xfb,0x41,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,\n 0x00,0x00,0xff,0xff,0x00,0x00,0x00,0xe8,0x2b,0x00,0x00,0x00,0x00,0x00,0x40,\n 0xfd,0x5e,0x01,0x00,0x00,0xfa,0x0a,0x00,0x00,0x00,0x00,0xe0,0x5e,0xff,0x51,\n 0x00,0x00,0x00,0xfe,0x02,0x00,0x00,0x00,0x00,0x50,0xbb,0xff,0x02,0x00,0x00,\n 0x00,0x7f,0x01,0x00,0x00,0x00,0x00,0xf0,0xff,0xff,0x00,0x00,0x00,0x00,0xdd,\n 0x00,0x00,0x00,0x00,0x00,0xe8,0xff,0xbf,0x02,0x00,0x00,0x00,0x2f,0x00,0x00,\n 0x00,0xa0,0xbb,0xfb,0xff,0x5f,0x00,0x00,0x00,0x00,0x9e,0x00,0x00,0x00,0xe0,\n 0xee,0xee,0xff,0x2f,0x00,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,0xf0,0xff,0xff,\n 0xff,0x0f,0x00,0x00,0x00,0x00,0x2f,0x00,0x00,0x00,0xd0,0xff,0xff,0xff,0x0b,\n 0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0xf0,0xff,0xff,0x1f,0x0a,0x00,0x00,\n 0x00,0x00,0x0f,0x00,0x00,0x00,0xe0,0xff,0xff,0xaf,0x00,0x00,0x00,0x00,0x00,\n 0x1d,0x00,0x00,0x00,0xf0,0xff,0xff,0x0f,0x00,0x00,0x00,0x00,0x00,0x17,0x00,\n 0x00,0x00,0xd0,0xff,0xff,0x0b,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,\n 0xf0,0xff,0x1f,0x0a,0x00,0x00,0x00,0x00,0x00,0x2f,0x00,0x00,0x00,0xe0,0xff,\n 0xaf,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0xf0,0xff,0x0f,0x00,\n 0x00,0x00,0x00,0x00,0x00,0x17,0x00,0x00,0x00,0xe0,0xff,0x0b,0x40,0x40,0x00,\n 0x00,0x00,0x00,0x2e,0x00,0x00,0x00,0xf0,0x1f,0x0a,0x50,0x5f,0x00,0x00,0x00,\n 0x00,0x0f,0x00,0x00,0x00,0xd0,0xaf,0x00,0xe0,0xba,0x01,0x00,0x00,0x00,0x2d,\n 0x00,0x00,0x00,0xf0,0x0f,0x00,0xd0,0xff,0x00,0x00,0x00,0x00,0x1f,0x00,0x00,\n 0x00,0xa0,0x0b,0x00,0xf0,0xff,0x02,0x00,0x00,0x00,0x6e,0x00,0x00,0x00,0x40,\n 0x0a,0x00,0xd0,0xff,0x00,0x00,0x00,0x00,0xbf,0x01,0x00,0x00,0x80,0x00,0x00,\n 0xf0,0xff,0x02,0x00,0x00,0x00,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xff,\n 0x00,0x00,0x00,0x00,0xff,0x02,0x00,0x00,0x00,0x00,0x00,0xf0,0xff,0x02,0x00,\n 0x00,0x00,0xfd,0x00,0x00,0x00,0x00,0x00,0x00,0xd0,0xff,0x00,0x00,0x00,0x00,\n 0xff,0x02,0x00,0x00,0x00,0x00,0x00,0xf0,0xff,0x02,0x00,0x00,0x00,0xfe,0x00,\n 0x00,0x00,0x00,0x00,0x00,0xe0,0xff,0x00,0x00,0x00,0x00,0xfd,0x01,0x00,0x00,\n 0x00,0x00,0x00,0xf8,0x7f,0x01,0x00,0x00,0x00,0xf4,0x16,0x00,0x00,0x00,0x00,\n 0x00,0xea,0x5f,0x00,0x00,0x00,0x00,0xe8,0x07,0x00,0x00,0x00,0x00,0x00,0xfd,\n 0x2f,0x00,0x00,0x00,0x00,0xd0,0x1f,0x00,0x00,0x00,0x00,0x00,0xff,0x0f,0x00,\n 0x00,0x00,0x00,0xe0,0x2f,0x00,0x00,0x00,0x00,0x80,0xfe,0x17,0x00,0x00,0x00,\n 0x00,0x20,0x5f,0x00,0x00,0x00,0x00,0xa0,0xff,0x09,0x00,0x00,0x00,0x00,0x80,\n 0xfe,0x00,0x00,0x00,0x00,0xd0,0xff,0x02,0x00,0x00,0x00,0x00,0x00,0x7d,0x01,\n 0x00,0x00,0x00,0xf0,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x05,0x00,0x00,\n 0x00,0xe8,0x6d,0x01,0x00,0x00,0x00,0x00,0x00,0xe9,0x75,0x00,0x00,0x00,0xfa,\n 0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xaf,0x01,0x00,0x00,0xee,0x82,0x00,\n 0x00,0x00,0x00,0x00,0x00,0xe8,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,\n 0x00,0x00,0x00,0xa0,0xfa,0x05,0x00,0x80,0xba,0x00,0x00,0x00,0x00,0x00,0x00,\n 0x00,0x40,0xf5,0xb5,0xbb,0xbb,0x52,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\n 0xe8,0xef,0xee,0x6e,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xff,\n 0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd0,0xff,0xff,0xff,\n 0x02,0x00,0x00,0x00,0x00,0x00};\n";
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
static char _slotValue_wwwAbout41[] = "\\f(2)Viola World Wide Web \nHypermedia Toolkit & Browser\\f(1)\n\nVersion 3.3\n\nBy Pei Y. Wei (\\f(0)wei@ora.com\\f(1)), \nO'Reilly & Associates, Inc.\n\nCopyright 1989-1995, all rights reserved.\n";
/* END OF OBJ */

static char _slotValue_wwwAbout43[] = "txtButton";
static char _slotValue_wwwAbout44[] = "wwwAbout.fld.top";
static char _slotValue_wwwAbout45[] = "wwwAbout.fld.top.dismiss";
static char _slotValue_wwwAbout46[] = "OK";
static char _slotValue_wwwAbout47[] = "normal";
static char _slotValue_wwwAbout48[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"wwwAbout\", \"dismiss\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwAbout84[] = "\n\tswitch (arg[0]) {\n\tcase \"tic\":\n\t\tif (inView == 0) return;\n\t\tset(\"FGColor\", \"black\");\n\t\trender();\n\t\tafter(1000, self(), \"toc\");\n\t\treturn;\n\tbreak;\n\tcase \"toc\":\n\t\tif (inView == 0) return;\n\t\tset(\"FGColor\", \"white\");\n\t\trender();\n\t\tafter(1000, self(), \"tic\");\n\t\treturn;\n\tbreak;\n\tcase \"inView\":\n\t\tinView = arg[1];\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwDialog_confirm2[] = "\n\tswitch (arg[0]) {\n\tcase \"confirm\":\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwDocuPort4[] = "\n\tswitch (arg[0]) {\n\tcase \"listen\":\n\t\tport = arg[1];\n\t\tpath = arg[2];\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tinitialize();\n                set(\"inDelimStr1\", \"\\r\");\n                set(\"inDelimStr2\", \"\\n\");\n/*                startClient();*/\n\t\treturn;\n\tbreak;\n\tcase \"input\":\n\t\tin = input();\n\t\tif (isBlank(in)) { \n\t\t\tprint(\"www.listen: bad input = ``\", in, \"''\\n\");\n\t\t} else {\n\t\t\tdocID = nthChar(in, 0, strlen(in)); \n\t\t\tprint(\"www.listen: input = ``\", docID, \"''\\n\");\n\t\t\twww(\"show\", docID);\n\t\t}\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_wwwDocuPort[] = {
    {"name", _slotValue_wwwDocuPort0},   {"class", _slotValue_wwwDocuPort1},
    {"path", _slotValue_wwwDocuPort2},   {"args", _slotValue_wwwDocuPort3},
    {"script", _slotValue_wwwDocuPort4}, {(char*)0, (char*)0},
};

static char _slotValue_wwwFormatDetect0[] = "generic";
static char _slotValue_wwwFormatDetect1[] = "wwwFormatDetect";
static char _slotValue_wwwFormatDetect2[] = "\n\tswitch (arg[0]) {\n\tcase \"type\":\n\t\tdocURL = arg[1];\n\t\tif (findPattern(docURL, \".pgp\") > -1) {\n\t\t\thandler = \"VWHandler_pgp\";\n\t\t} else if (findPattern(docURL, \".html\") > -1) {\n/*\t\t\thandler = \"VWHandler_html\";*/\n\t\t\thandler = \"VWHandler_html2\";\n\t\t} else if (findPattern(docURL, \".hmmlb\") > -1) {\n\t\t\thandler = \"VWHandler_hmmlb\";\n\t\t} else if (findPattern(docURL, \".hmml\") > -1) {\n\t\t\thandler = \"VWHandler_hmml\";\n\t\t} else if (findPattern(docURL, \".au\") > -1) {\n\t\t\thandler = \"VWHandler_au\";\n\t\t} else if (findPattern(docURL, \".gif\") > -1) {\n\t\t\thandler = \"VWHandler_gif\";\n\t\t} else if (findPattern(docURL, \".csh\") > -1) {\n\t\t\thandler = \"VWHandler_csh\";\n\t\t} else if (findPattern(docURL, \".ps\") > -1) {\n\t\t\thandler = \"VWHandler_postscript\";\n\t\t} else if (findPattern(docURL, \".xbm\") > -1) {\n\t\t\thandler = \"VWHandler_xbm\";\n\t\t} else if (findPattern(docURL, \".xpm\") > -1) {\n\t\t\thandler = \"VWHandler_xpm\";\n\t\t} else if (findPattern(docURL, \".v\") > -1) {\n\t\t\thandler = \"VWHandler_vobjf\";\n\n/*needs better recognition!!!! \n\t\t} else if (findPattern(docURL, \"index\") > -1) {\n\t\t\thandler = \"waisDB\";\n*/\n\t\t} else if (findPattern(docURL, \".txt\") > -1) {\n\t\t\thandler = \"VWHandler_plaintext\";\n\t\t} else if (findPattern(docURL, \".text\") > -1) {\n\t\t\thandler = \"VWHandler_plaintext\";\n\t\t} else {\n/*\t\t\tprint(\"WARNING: format unknown: \",\n\t\t\t\tdocURL, \". Treating as HTML.\\n\");\n\t\t\thandler = \"VWHandler_html\";\n*/\n\t\t\thandler = \"VWHandler_html2\";\n\t\t}\n\t\treturn handler;\n\t\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_wwwFormatDetect[] = {
    {"class", _slotValue_wwwFormatDetect0},
    {"name", _slotValue_wwwFormatDetect1},
    {"script", _slotValue_wwwFormatDetect2},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwHandlerDispatch0[] = "wwwHandlerDispatch";
static char _slotValue_wwwHandlerDispatch1[] = "generic";
static char _slotValue_wwwHandlerDispatch2[] = "\n/*XXX this object is a mess\nprint(\"wwwHandlerDispatch: \");\nfor (i=0; i < arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");\nprint(\"\\n\");\n*/\n\n\tswitch (arg[0]) {\n\tcase \"dispatch\":\n\t\t/* arg[1]\thandler\n\t\t * arg[2]\tdoPost\n\t\t * arg[3]\tdocURL\n\t\t * arg[4]\tdocName\n\t\t * arg[5]\tpaneObj\n\t\t * arg[6]\tpaneWidth\n\t\t * arg[7]\tpaneHeight\n\t\t * arg[8]\tanchor\n\t\t * arg[9]\tmessage user?\n\t\t * arg[10]\tpostData\n\t\t */\n\t\thandler = arg[1];\n\t\tdoPost = arg[2];\n\t\tdocURL = arg[3];\n\t\tdocName = arg[4];\n\t\tpaneObj = arg[5];\n\t\tpaneWidth = arg[6];\n\t\tpaneHeight = arg[7];\n\t\tanchor = arg[8];\n\t\tmessageUserP = arg[9];\n\t\tpostData = arg[10];\n\n/*\t\tprint(\"SHOW: handler=\", handler, \n\t\t\t\t\"; name=\", docName, \"\\n\");*/\n\n\t\tswitch (handler) {\n\t\tcase \"VWHandler_html2\":\n\t\t\tdocObj = send(handler, \n\t\t\t\t\t'B', docURL,\n\t\t\t\t\tpaneObj, docName,\n\t\t\t\t\tpaneWidth, anchor, doPost, postData);\n\t\t\tif (docObj == 0) {\n\t\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\t\treturn 0;\n\t\t\t}\n\n/*\n\t\tprint(\"wwwHandlerDispatch: calling docObj=\", docObj, \n\t\t\t\t\"; paneWidth=\", paneWidth, \"\\n\");\n*/\n\t\t\tsend(docObj, 'T', 0, paneWidth);\n\n\t\t\tsend(paneObj, \"setChildren\", docObj);\n\n\t\t\tif (anchor != \"\") {\n\t\t\t\tif (messageUserP) \n\t\t\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t\t\t\"Going to anchor...\");\n\n\t\t\t\tpageYPos = send(docName, \"gotoAnchor\", \n\t\t\t\t\t\tanchor) * -1;\n\t\t\t} else {\n\t\t\t\tpageYPos = 0;\n\t\t\t}\n\t\t\tsend(docName, \"y\", pageYPos);\n\n\t\t\tif (messageUserP) www.mesg.tf(\"show\", \"Rendering...\");\n\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\n\t\t\treturn docObj;\n\t\tbreak;\n\t\tcase \"VWHandler_html\":\n\t\tcase \"VWHandler_hmml\":\n\t\t\tdocObj = send(handler, \n\t\t\t\t\t'B', docURL,\n\t\t\t\t\tpaneObj, docName,\n\t\t\t\t\tpaneWidth, anchor);\n\t\t\tif (docObj == 0) {\n\t\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\t\treturn 0;\n\t\t\t}\n\n\t\t\tsend(docObj, 'T', 0, paneWidth);\n\n\t\t\tsend(paneObj, \"setChildren\", docObj);\n\n\t\t\tif (anchor != \"\") {\n\t\t\t\tif (messageUserP) \n\t\t\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t\t\t\"Going to anchor...\");\n\n\t\t\t\tpageYPos = send(docName, \"gotoAnchor\", \n\t\t\t\t\t\tanchor) * -1;\n\t\t\t} else {\n\t\t\t\tpageYPos = 0;\n\t\t\t}\n\t\t\tsend(docName, \"y\", pageYPos);\n\n\t\t\tif (messageUserP) www.mesg.tf(\"show\", \"Rendering...\");\n\n\t\t\tsend(docName, \"show\");\n\n\t\t\ttweak(docName, \"raise();\");\n\t\t\t/* questionable. will windoiw be created by now? */\n\n\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\n\t\t\treturn docObj;\n\t\tbreak;\n\t\tcase \"VWHandler_hmmlb\":\n\n\t\t\t/* inform the new page of: \n\t\t\t * \tsourcefile, parent, name, width\n\t\t\t */\n\t\t\tdocObj = send(handler, \n\t\t\t\t\t'B', docURL,\n\t\t\t\t\tpaneObj, docName,\n\t\t\t\t\tpaneWidth, anchor);\n\t\t\tif (docObj == 0) {\n\t\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\t\treturn 0;\n\t\t\t}\n\n\t\t\tsend(docObj, 'T', 0, paneWidth);\n\n\t\t\tsend(paneObj, \"setChildren\", docObj);\n\t\t\t/*print(\"SHOW: HMML docObj=\", docObj, \"\\n\");*/\n\t\t\tif (anchor != \"\") {\n\t\t\t\twww.mesg.tf(\"show\", \n\t\t\t\t\t\"Going to anchor...\");\n\t\t\t\tpageYPos = send(docName, \"gotoAnchor\", \n\t\t\t\t\t\tanchor) * -1;\n\t\t\t} else {\n\t\t\t\tpageYPos = 0;\n\t\t\t}\n\t\t\tsend(docName, \"y\", pageYPos);\n\n\t\t\twww.mesg.tf(\"show\", \"Rendering...\");\n\n\t\t\tsend(docName, \"show\");\n\t\t\ttweak(docName, \"raise();\");\n\n\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\treturn docObj;\n\t\tbreak;\n\t\tcase \"VWHandler_vobjf\":\n\t\t\tdocObj = VWHandler_vobjf(\"build\", \n\t\t\t\t\tdocURL, docName, paneObj,\n\t\t\t\t\tpaneWidth, paneHeight);\n\t\t\tif (docObj == 0) {\n\t\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\t\treturn 0;\n\t\t\t}\n\n\t\t\tsend(paneObj, \"setChildren\", docObj);\n\n\t\t\tsend(docObj, \"visible\", 1);\n\n\t\t\tsend(docObj, \"render\");\n\n\t\t\ttweak(docObj, \"raise();\");\n\n\t\t\tsend(docObj, \"config\", \n\t\t\t\t0, 0, paneWidth, paneHeight);\n\n\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\treturn docObj;\n\t\tbreak;\n\t\tcase \"VWHandler_plaintext\":\n\t\tcase \"waisDB\":\n\t\t\t/* inform the new page of: \n\t\t\t * \tsourcefile, parent, name, width\n\t\t\t */\n\t\t\tdocObj = send(handler, \n\t\t\t\t\t\"build\", docURL,\n\t\t\t\t\tpaneObj, docName, \n\t\t\t\t\tpaneWidth);\n\t\t\tif (docObj == 0) {\n\t\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tsend(docObj, \"tile\", 0, paneWidth, paneHeight);\n\n\t\t\ttweak(docObj, concat(\"set(\\\"parent\\\",\\\"\",\n\t\t\t\t\t\tpaneObj, \"\\\");\"));\n\t\t\tsend(paneObj, \"setChildren\", docObj);\n\n\t\t\tsend(docObj, \"render\");\n\t\t\tsend(docObj, \"raise\");\n\n\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\treturn docObj;\n\t\tbreak;\n/*\t\tcase \"VWHandler_xbm\":\n\t\tcase \"VWHandler_xpm\":\n\t\t\t* inform the new page of: \n\t\t\t * \tsourcefile, parent, name, width\n\t\t\t *\n\t\t\tdocObj = send(handler,\n\t\t\t\t\t\"build\", docURL,\n\t\t\t\t\tpaneObj, docName, \n\t\t\t\t\tpaneWidth);\n\t\t\tif (docObj == 0) {\n\t\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\t\treturn 0;\n\t\t\t}\n\n\t\t\tsend(docObj, \"tile\", 0, paneWidth, paneHeight);\n\n\t\t\ttweak(docObj, concat(\"set(\\\"parent\\\",\\\"\",\n\t\t\t\t\t\tpaneObj, \"\\\");\"));\n\t\t\tsend(paneObj, \"setChildren\", docObj);\n\n\t\t\tsend(docName, \"render\");\n\n\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\treturn docObj;\n\t\tbreak;\n*/\n\t\tcase \"VWHandler_gif\":\n\t\tcase \"VWHandler_xbm\":\n\t\tcase \"VWHandler_xpm\":\n\t\t\t/* invoke xv or something...\n\t\t\t * later, wrap this part into a \n\t\t\t * VWHandler_* object, so as not to \n\t\t\t * complicate it here\n\t\t\t */\n/*\t\t\tDISP_METH = \"inView\";*/\n\t\t\tDISP_METH = \"extView\";\n\n\t\t\tswitch (DISP_METH) {\n\t\t\tcase \"inView\":\n\t\t\t\tdocObj = send(handler,\n\t\t\t\t\t\t\"build\", docURL,\n\t\t\t\t\t\tpaneObj, docName, \n\t\t\t\t\t\tpaneWidth);\n\t\t\t\tif (docObj == 0) return 0;\n\n\t\t\t\tsend(docObj, \"tile\", 0, paneWidth, paneHeight);\n\n\t\t\t\ttweak(docObj, concat(\"set(\\\"parent\\\",\\\"\",\n\t\t\t\t\t\t\tpaneObj, \"\\\");\"));\n\t\t\t\tsend(paneObj, \"setChildren\", docObj);\n\n\t\t\t\tsend(docName, \"render\");\n\n\t\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\t\treturn docObj;\n\t\t\tbreak;\n\t\t\tcase \"extView\":\n\t\t\t\tlocalFile = HTTPGet(docURL);\n\t\t\t\tsystem(concat(\"xv \", localFile, \" &\"));\n\t\t\tbreak;\n\t\t\t}\n\t\t\treturn 1;/*OK*/\n\t\tbreak;\n\t\tcase \"VWHandler_au\":\n\t\t\tsourceFile = HTTPGet(docURL);\n\n\t\t\t/* a hack. don't know where play usually \n\t\t\t * lives..\n\t\t\t */\n\t\t\tprint(concat(environVar(\"VIOLA\"),\n\t\t\t\t\t\"/play \", sourceFile, \"\\n\"));\n\t\t\tsystem(concat(environVar(\"VIOLA\"),\n\t\t\t\t\t\"/play \", sourceFile, \"&\"));\n\t\t\treturn 1;/*OK*/\n\t\tbreak;\n\t\tcase \"VWHandler_pgp\":\n\t\t\tsourceFile = HTTPGet(docURL);\n\nprint(\"VWHandlerDispatch: PGP: sourceFile={\", sourceFile, \"}\\n\");\n\n\t\t\t/* to fix: should not use absolute path to pgp\n\t\t\t * \n\t\t\t */\n\t\t\tsystem(concat(\"cd /usr/users/pei/pgpTest/test;ls -al;/usr/local/bin/pgp \", sourceFile));\n\t\t\tnewSourceFile = nthChar(sourceFile, 0, strlen(sourceFile) - 5);\nprint(\"VWHandlerDispatch: PGP: newSourceFile={\", newSourceFile, \"}\\n\");\n\n\t\t\treturn send(self(), \"dispatch\", \"VWHandler_html2\",\n\t\t\t\t    arg[2], newSourceFile, arg[4], arg[5],\n\t\t\t\t    arg[6], arg[7], arg[8], arg[9], arg[10]);\n\t\tbreak;\n\t\tdefault:\n\t\t\t/*print(\"SHOW: Unknown handler, treat as plaintext: \",\n\t\t\t\tdocName, \"\\n\");*/\n\n\t\t\t/* inform the new page of: \n\t\t\t * \tsourcefile, parent, name, width\n\t\t\t */\n\t\t\tdocObj = send(\"plaintext\", \n\t\t\t\t\t\"build\", docURL,\n\t\t\t\t\tpaneObj, docName, \n\t\t\t\t\tpaneWidth);\n\t\t\tif (docObj == 0) {\n\t\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tif (isBlank(docObj)) return 0;\n\n\t\t\tsend(paneObj, \"setChildren\", docObj);\n\n\t\t\tsend(docName, \"render\");\n\n\t\t\tif (messageUserP) www.mesg.tf(\"clear\");\n\t\t\treturn docObj;\n\t\tbreak;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHistory3[] = "\n/*\n  \tprint(\"wwwHistory: \");\n\tfor (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\tprint(\"\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"add\":\n\t\twwwHistory.list.tf(\"add\", arg[1], arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"back\":\n\tcase \"prev\":\n\tcase \"next\":\n\tcase \"peek_prev\":\n\tcase \"peek_next\":\n\tcase \"toggle\":\n\tcase \"peek_back\":\n\t\twwwHistory.list.tf(arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"historyQuery\":\n\t\twwwHistory.list.tf(arg[0], arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"visible\":\n\t\tset(\"visible\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"dismiss\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\tcase \"render\":\n\t\tset(\"visible\", 1);\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\twindowName(\"ViolaWWW Travelal History\");\n\tbreak;\n\tcase \"raise\":\n\t\traise();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHistory22[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tcursorShape(\"busy\");\n\t\tdocAddr = wwwHistory.list.tf(\"prev\");\n\t\tif (isBlank(docAddr) != 1) www(\"show\", docAddr);\n\t\tcursorShape(\"idle\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHistory23[] = "70";
static char _slotValue_wwwHistory24[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory26[] = "wwwHistory.top.back";
static char _slotValue_wwwHistory27[] = "txtButton";
static char _slotValue_wwwHistory28[] = "wwwHistory.top";
static char _slotValue_wwwHistory29[] = "Back";
static char _slotValue_wwwHistory30[] = "normal";
static char _slotValue_wwwHistory31[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tcursorShape(\"busy\");\n\t\tdocAddr = wwwHistory.list.tf(\"back\");\n\t\tif (isBlank(docAddr) != 1) www(\"showButNoRecord\", docAddr);\n\t\tcursorShape(\"idle\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHistory32[] = "70";
static char _slotValue_wwwHistory33[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory35[] = "wwwHistory.top.next";
static char _slotValue_wwwHistory36[] = "txtButton";
static char _slotValue_wwwHistory37[] = "wwwHistory.top";
static char _slotValue_wwwHistory38[] = "Next";
static char _slotValue_wwwHistory39[] = "normal";
static char _slotValue_wwwHistory40[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tcursorShape(\"busy\");\n\t\tdocAddr = wwwHistory.list.tf(\"next\");\n\t\tif (isBlank(docAddr) != 1) www(\"showButNoRecord\", docAddr);\n\t\tcursorShape(\"idle\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHistory41[] = "70";
static char _slotValue_wwwHistory42[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory44[] = "wwwHistory.top.title";
static char _slotValue_wwwHistory45[] = "txtLabel";
static char _slotValue_wwwHistory46[] = "wwwHistory.top";
static char _slotValue_wwwHistory47[] = "World Wide Web Travels";
static char _slotValue_wwwHistory48[] = "bold";
static char _slotValue_wwwHistory49[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\twwwHistory.list.tf(\"dump\");\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_wwwHistory51[] = "wwwHistory.top.dismiss";
static char _slotValue_wwwHistory52[] = "txtButton";
static char _slotValue_wwwHistory53[] = "wwwHistory.top";
static char _slotValue_wwwHistory54[] = "Dismiss";
static char _slotValue_wwwHistory55[] = "normal";
static char _slotValue_wwwHistory56[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\twwwHistory(\"dismiss\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHistory76[] = "\n/*\n\tprint(\"wwwHistory.tf: \");\n\tfor (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\tprint(\"\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tif (isBlank(currentLine()) == 1) {\n\t\t\tbell();\n\t\t} else {\n\t\t\tdeHighLight(index);\n\t\t\tpreviousDocIndx = index;\n\t\t\t/*index = lineRowOffset() + cursorRow();*/\n\t\t\tindex = cursorRow();\n\t\t\thighLight(index);\n\t\t\tif (get(\"window\")) render();\n\t\t}\n\t\twww(\"showButNoRecord\", docAddr[index]);\n\tbreak;\n\tcase \"prev\":\n\t\tif (index > 0) {\n\t\t\tdeHighLight(index);\n\t\t\tpreviousDocIndx = index;\n\t\t\tindex--;\n\t\t\thighLight(index);\n\t\t\tif (get(\"window\")) render();\n\t\t\treturn docAddr[index];\n\t\t} else {\n\t\t\tbell();\n\t\t\treturn \"\";\n\t\t}\n\tbreak;\n\tcase \"peek_prev\":\n\t\tif (index > 0) return docTitle[index - 1];\n\t\telse return \"none\";\n\tbreak;\n\tcase \"next\":\n\t\tif (index < count - 1) {\n\t\t\tdeHighLight(index);\n\t\t\tpreviousDocIndx = index;\n\t\t\tindex++;\n\t\t\thighLight(index);\n\t\t\tif (get(\"window\")) render();\n\t\t\treturn docAddr[index];\n\t\t} else {\n\t\t\tbell();\n\t\t\treturn \"\";\n\t\t}\n\tbreak;\n\tcase \"peek_next\":\n\t\tif (index + 1 < count) return docTitle[index + 1];\n\t\telse return \"none\";\n\tbreak;\n\tcase \"toggle\":\n\t\tif (previousDocIndx == -1) {\n\t\t\treturn \"\";\n\t\t} else {\n\t\t\tdeHighLight(index);\n\t\t\ttemp = index;\n\t\t\tindex = previousDocIndx;\n\t\t\tpreviousDocIndx = temp;\n\t\t\thighLight(index);\n\t\t\tif (get(\"window\")) render();\n\t\t\treturn docAddr[index];\n\t\t}\n\tbreak;\n\tcase \"peek_back\":\n\t\tif (index > 0) return docTitle[index - 1];\n\t\telse return \"none\";\n\tbreak;\n\tcase \"add\":\n\t\tdeHighLight(index);\n\t\tpreviousDocIndx = index;\n\t\tindex = count;\n\t\tif (isBlank(arg[1]) == 1) {\n\t\t\tdocTitle[count] = \"no title\";\n\t\t} else {\n\t\t\t/* make sure we're storing string representation,\n\t\t\t * rather than possibly object pointer which can\n\t\t\t * get us into trouble if that object is destroyed\n\t\t\t * and we reference it.\n\t\t\t */\n\t\t\tdocTitle[index] = str(arg[1]);\n\t\t}\n\t\tdocAddr[index] = arg[2];\n\n\t\tcount++;\n\n\t\tvictimIdx = count - killLatency;\n\t\tif (victimIdx >= 0) {\n\t\t\tvictim = docAddr[victimIdx];\n\t\t\tif (victim != arg[2]) {\n\t\t\t\tsend(victim, \"visible\", 0);\n\t\t\t\tsend(victim, \"freeSelf\");\n\t\t\t}\n\t\t}\n\t\ttt = \"\";\n\t\tfor (i = 0; i < count; i++)\n\t\t\ttt = concat(tt, docTitle[i], '\\n');\n\t\tset(\"content\", tt);\n\t\thighLight(index);\n\t\tif (get(\"window\")) render();\n\t\treturn;\n\tbreak;\n\tcase \"back\":\n\t\t/* delete last line */\n/*\nprint(\"count<=1\", count <= 1, \"\\n\");\np = count <= 1;\nprint(\"count<=1p \", p, \"\\n\");\n*/\n\t\tif (count <= 1) {\n\t\t\tbell();\n\t\t} else {\n/*\nprint(\"NOW DESTROY index=\", index, \": {\", docAddr[index], \"}<<<<<<<<<<<,\\n\");\n*/\n\t\t\twww(\"destroyDoc\", docAddr[index]);\n\n\t\t\tdeHighLight(index);\n\t\t\tcount--;\n\t\t\tif (index > -1) index--;\n\t\t\tpreviousDocIndx = index;\n/*set(\"content\", nthLine(get(\"content\"), 0, count - 1));*/\n/*GROSSY*/\t\ttt = \"\";\n\t\t\tfor (i = 0; i < count; i++)\n\t\t\t\ttt = concat(tt, docTitle[i], '\\n');\n\t\t\tset(\"content\", tt);\n\t\t\thighLight(index);\n\t\t\tif (get(\"window\")) render();\n\n\t\t}\n/*\nprint(\"NOW WANT index=\",index, \": {\", docAddr[index], \"}\\n\");\nprint(\"count=\", count, \"\\n\");\nprint(\"HISTORY NOW:{\", tt, \"}\\n\");\n*/\n\t\treturn docAddr[index];\n\tbreak;\n\tcase \"config\":\n\t\t/* this is necessary due to the bug where content can't be\n\t\t * set until the object has been configured... and this is\n\t\t * a problem because a document may be \"added\" here before\n\t\t * the widgets are configured.\n\t\t */\n\t\tusual();\n\t\tset(\"content\", tt);\n\t\treturn;\n\tbreak;\n\tcase \"historyQuery\":\n\t\t/* arg[1]\tcookie\n\t\t */\n\t\twwwHistory_report(arg[1], docTitle);\n\t\treturn;\n\tbreak;\n\tcase \"query\": /* query(n) -> text on line n */\n\t\treturn nthLine(get(\"content\"), arg[1]);\n\tbreak;\n\tcase \"clear\":\n\t\tset(\"content\", \"\");\n\tbreak;\n\tcase \"dump\":\n\t\tfor (i = 0; i < count; i++)\n\t\t\tprint(\"[\", i, \"]\\t docTitle={\", docTitle[i], \"}\",\n\t\t\t\t\"\\tdocAddr={\", docAddr[i], \"}\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\tcase \"release\":\n\tcase \"keyPress\":\n\t\treturn; \n\tbreak;\n\tcase \"enter\":\n\t\tset(\"cursor\", 0); \n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tpreviousDocIndx = -1;\n\t\tindex = -1;\n\t\tcount = 0;\n\t\tkillLatency = 10;\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHTMLSrc4[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\t/* arg[1]\tcall back object\n\t\t * arg[2]\tHTMLAddress\n\t\t * arg[3]\tHTMLSource\n\t\t */\n\t\tcloneID = cloneID + 1;\n\t\tnew = clone(cloneID);\n\t\tsend(new, \"show_clone\", arg[1], arg[2], arg[3]);\n\t\tsend(new, \"render\");\n\t\treturn;\n\tbreak;\n\tcase \"show_clone\":\n\t\tcaller = arg[1];\n\t\tHTMLAddress = arg[2];\n\t\tHTMLSource = arg[3];\n\t\tsend(nthChild(0), \"show\", HTMLAddress);\n\t\tsend(nthChild(1), \"show\", HTMLSource);\n\t\treturn;\n\tbreak;\n\tcase \"apply\":\n\t\tsend(caller, \"updateSrc\", send(nthChild(1), \"contentP\"));\n\t\treturn;\n\tbreak;\n\tcase \"store\":\n/*\n\t\ttmp = makeTempFile();\n\t\tsaveFile(tmp, send(nthChild(1), \"contentP\"));\n\t\tprint(\"ERROR: Sorry, source update feature doesn't yet exist. The changed document is saved in \", tmp, \".\\n\");\n*/\n\t\tres.getLineEntry(\"show\", \n\t\t\t\"Enter file name to save to document source to:\", \n\t\t\t\t\"/tmp/out.html\",\n\t\t\t\tself(), \"gotOutputFileName\");\n\t\treturn;\n\tbreak;\n\tcase \"gotOutputFileName\":\n\t\tif (saveFile(arg[1], send(nthChild(1), \"contentP\"))) {\n\t\t\twww.mesg.tf(\"show\", \n\t\t\t\tconcatenate(\"Source saved to file: \",\n\t\t\t\t\targ[1], \"\\n\"));\n\t\t} else {\n\t\t\twww.mesg.tf(\"show\", \n\t\t\t\tconcatenate(\"Failed to save source to file: \",\n\t\t\t\t\targ[1], \"\\n\"));\n\t\t}\n\t\treturn;\n \tbreak;\n\tcase \"dismiss\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tcloneID = 0;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHTMLSrc5[] = "600";
static char _slotValue_wwwHTMLSrc6[] = "400";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc8[] = "wwwHTMLSrc.top";
static char _slotValue_wwwHTMLSrc9[] = "txtDisp";
static char _slotValue_wwwHTMLSrc10[] = "wwwHTMLSrc";
static char _slotValue_wwwHTMLSrc11[] = "normal";
static char _slotValue_wwwHTMLSrc12[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"label\", arg[1]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHTMLSrc13[] = "20";
static char _slotValue_wwwHTMLSrc14[] = "black";
static char _slotValue_wwwHTMLSrc15[] = "LemonChiffon3";
static char _slotValue_wwwHTMLSrc16[] = "black";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc18[] = "wwwHTMLSrc.list";
static char _slotValue_wwwHTMLSrc19[] = "hpane";
static char _slotValue_wwwHTMLSrc20[] = "wwwHTMLSrc";
static char _slotValue_wwwHTMLSrc21[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tsend(nthChild(0), \"show\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"contentP\":\n\t\treturn send(nthChild(0), \"contentP\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHTMLSrc36[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"contentP\":\n\t\treturn get(\"content\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHTMLSrc48[] = "\n\tswitch (arg[0]) {\n\tcase \"apply\":\n\tcase \"store\":\n\tcase \"dismiss\":\n\t\tsend(get(\"parent\"), arg[0]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHTMLSrc49[] = "1";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc51[] = "wwwHTMLSrc.ctrl.apply";
static char _slotValue_wwwHTMLSrc52[] = "txtButton";
static char _slotValue_wwwHTMLSrc53[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc54[] = "normal";
static char _slotValue_wwwHTMLSrc55[] = "Apply Changes";
static char _slotValue_wwwHTMLSrc56[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(get(\"parent\"), \"apply\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHTMLSrc57[] = "grey45";
static char _slotValue_wwwHTMLSrc58[] = "white";
static char _slotValue_wwwHTMLSrc59[] = "white";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc61[] = "wwwHTMLSrc.ctrl.store";
static char _slotValue_wwwHTMLSrc62[] = "txtButton";
static char _slotValue_wwwHTMLSrc63[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc64[] = "normal";
static char _slotValue_wwwHTMLSrc65[] = "Store Changes";
static char _slotValue_wwwHTMLSrc66[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(get(\"parent\"), \"store\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHTMLSrc67[] = "grey45";
static char _slotValue_wwwHTMLSrc68[] = "white";
static char _slotValue_wwwHTMLSrc69[] = "white";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc71[] = "wwwHTMLSrc.ctrl.dismiss";
static char _slotValue_wwwHTMLSrc72[] = "txtButton";
static char _slotValue_wwwHTMLSrc73[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc74[] = "normal";
static char _slotValue_wwwHTMLSrc75[] = "Dismiss";
static char _slotValue_wwwHTMLSrc76[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(get(\"parent\"), \"dismiss\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHotFolder3[] = "\n/*\n  \tprint(\"wwwHotFolder: \");\n\tfor (i = 0; i < arg[]; i++) print(arg[i], \", \");\n\tprint(\"\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"addCurrent\":\n\t\tsend(\"wwwHotFolder.list.tf\", \"add\");\n\t\treturn;\n\tbreak;\n\tcase \"add\":\n\t\twwwHotFolder.list.tf(\"add\", arg[1], arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"toggle\":\n\t\twwwHotFolder.list.tf(arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"historyQuery\":\n\t\twwwHotFolder.list.tf(arg[0], arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"visible\":\n\t\tset(\"visible\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"dismiss\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\tcase \"render\":\n\t\tset(\"visible\", 1);\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"busy\":\n\t\tcursorShape(\"busy\");\n\t\treturn;\n\tbreak;\n\tcase \"idle\":\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\twindowName(\"ViolaWWW Hot Lists\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHotFolder22[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tcursorShape(\"busy\");\n\t\tsend(\"wwwHotFolder.list.tf\", \"goto\");\n\t\tcursorShape(\"idle\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHotFolder23[] = "70";
static char _slotValue_wwwHotFolder24[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder26[] = "wwwHotFolder.top.add";
static char _slotValue_wwwHotFolder27[] = "txtButton";
static char _slotValue_wwwHotFolder28[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder29[] = "Add";
static char _slotValue_wwwHotFolder30[] = "normal";
static char _slotValue_wwwHotFolder31[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tcursorShape(\"busy\");\n\t\tsend(\"wwwHotFolder.list.tf\", \"add\");\n\t\tcursorShape(\"idle\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHotFolder32[] = "70";
static char _slotValue_wwwHotFolder33[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder35[] = "wwwHotFolder.top.delete";
static char _slotValue_wwwHotFolder36[] = "txtButton";
static char _slotValue_wwwHotFolder37[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder38[] = "Delete";
static char _slotValue_wwwHotFolder39[] = "normal";
static char _slotValue_wwwHotFolder40[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tcursorShape(\"busy\");\n\t\tsend(\"wwwHotFolder.list.tf\", \"delete\");\n\t\tcursorShape(\"idle\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHotFolder41[] = "70";
static char _slotValue_wwwHotFolder42[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder44[] = "wwwHotFolder.top.edit";
static char _slotValue_wwwHotFolder45[] = "txtButton";
static char _slotValue_wwwHotFolder46[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder47[] = "Edit";
static char _slotValue_wwwHotFolder48[] = "normal";
static char _slotValue_wwwHotFolder49[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tcursorShape(\"busy\");\n\t\tsend(\"wwwHotFolder.list.tf\", \"editComment\");\n\t\tcursorShape(\"idle\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwHotFolder50[] = "70";
/* END OF OBJ */

static char _slotValue_wwwHotFolder52[] = "wwwHotFolder.top.title";
static char _slotValue_wwwHotFolder53[] = "txtLabel";
static char _slotValue_wwwHotFolder54[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder55[] = "Hot List";
static char _slotValue_wwwHotFolder56[] = "bold";
static char _slotValue_wwwHotFolder57[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\twwwHotFolder.list.tf(\"dump\");\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_wwwHotFolder59[] = "wwwHotFolder.top.dismiss";
static char _slotValue_wwwHotFolder60[] = "txtButton";
static char _slotValue_wwwHotFolder61[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder62[] = "Dismiss";
static char _slotValue_wwwHotFolder63[] = "normal";
static char _slotValue_wwwHotFolder64[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\twwwHotFolder(\"dismiss\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwHotFolder84[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tif (isBlank(currentLine()) == 1) {\n\t\t\tbell();\n\t\t} else {\n\t\t\toldIndex = index;\n\t\t\tdeHighLight(index);\n\t\t\tindex = cursorRow();\n\t\t\thighLight(index);\n\t\t\tif (get(\"window\")) render();\n/*\n\t\tprint(\"Selected: currentLine=\", currentLine(), \"\\n\");\n\t\tprint(\"Selected: index=\", index, \"\\n\");\n\t\tprint(\"Selected: url=\", HTTPHotListGet(0, index), \"\\n\");\n\t\tprint(\"Selected: comment=\", HTTPHotListGet(1, index), \"\\n\");\n*/\n\t\t\tif (oldIndex == index) { /* cheezy double click*/\n\t\t\t\tsend(\"wwwHotFolder\", \"busy\");\n\t\t\t\tsend(\"www\", \"show\", HTTPHotListGet(0, index));\n\t\t\t\tsend(\"wwwHotFolder\", \"idle\");\n\t\t\t\toldIndex = -1;\n\t\t\t}\n\t\t}\n\tbreak;\n\tcase \"goto\":\n\t\tif (index > -1) {\n\t\t\tsend(\"wwwHotFolder\", \"busy\");\n\t\t\tsend(\"www\", \"show\", HTTPHotListGet(0, index));\n\t\t\tsend(\"wwwHotFolder\", \"idle\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\t/* this is necessary due to the bug where content can't be\n\t\t * set until the object has been configured... and this is\n\t\t * a problem because a document may be \"added\" here before\n\t\t * the widgets are configured.\n\t\t */\n\t\tusual();\n\t\tsend(self(), \"load\");\n\t\treturn;\n\tbreak;\n\tcase \"save\":\n\t\tHTTPHotListSave();\n\t\treturn;\n\tbreak;\n\tcase \"load\":\n\t\ttt = HTTPHotListGet(3);\n\t\tset(\"content\", tt);\n\t\tif (get(\"window\")) render();\n\t\tindex = -1;\n\t\treturn;\n\tbreak;\n\tcase \"add\":\n\t\turl = send(\"www\", \"getCurrentDocURL\");\n\t\tcomment = send(\"www\", \"getCurrentDocTitle\");\n\t\tHTTPHotListAdd(url, comment, date());\n\t\tHTTPHotListSave();\n\t\tsend(self(), \"load\");\n\t\treturn;\n\tbreak;\n\tcase \"delete\":\n\t\tif (index != -1) {\n\t\t\tHTTPHotListDelete(index);\n\t\t\tHTTPHotListSave();\n\t\t\tsend(self(), \"load\");\n\t\t} else {\n\t\t\tsend(\"prompt\", \"show\",\n\t\t\t\t\"First select a hot list item, then delete.\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"editComment\":\n\t\tif (index != -1) {\n\t\t\twinPos = windowPosition();\n\t\t\tsend(\"res.getLineEntry\", \"show\", \n\t\t\t\t\"Enter new URL comment\",\n\t\t\t\tHTTPHotListGet(1, index),\n\t\t\t\tself(),\n\t\t\t\t\"newComment\",\n\t\t\t\twinPos[0] + 20, winPos[1] + 20);\n\t\t} else {\n\t\t\tsend(\"prompt\", \"show\",\n\t\t\t\t\"First select a hot list item, then edit.\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"newComment\":\n\t\tHTTPHotListChange(1/*comment*/, index, arg[1]);\n\t\tHTTPHotListSave();\n\t\tsend(self(), \"load\");\n\t\treturn;\n\tbreak;\n\tcase \"keyPress\":\n\tcase \"enter\":\n\tcase \"leave\":\n\t\treturn; \n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tpreviousDocIndx = -1;\n\t\tindex = -1;\n\t\tcount = 0;\n\t\tsend(self(), \"load\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwSecurity2[] = "\n\t/* this security wall is terribly lay back now */\n\n\tswitch (arg[0]) {\n\tcase \"rmTmpFile\":\n\t\t/* need to check that the file is indeed a temporary\n\t\t * file created by viola...\n\t\t */\n\t\tif (findPattern(arg[1], \"/tmp/\") != -1) { /* very feeble */\n\t\t\tdeleteFile(arg[1]);\n\t\t\treturn 1;\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"getDocAndMoveItToSpecifiedPlace\":\n\t\t/* this is call by HTML__doc. Need a way to autheticate\n\t\t * that it's indeed HTML__doc that's calling ...\n\t\t */\n\t\t/* arg[1]\tdocURL\n\t\t * arg[2]\tdestination\n\t\t */\n\t\tif (access(arg[2])) {\n\t\t\t/* should query to confirm */\n\t\t\tprint(\"Warning: overwriting \", arg[2], \"...\\n\");\n\t\t}\n\t\tdumpFile = HTTPGet(arg[1]);\n\t\tsystem(concat(\"mv \", dumpFile, \" \", arg[2]));\n\t\treturn 1;\n\tbreak;\n\tcase \"mailFileContentTo,rmFile\":\n\t\t/* arg[1]\temail address\n\t\t * arg[2]\tsubject line\n\t\t * arg[3]\ttmpFileName\n\t\t */\n\t\tcmd = concat(\"mail -s \\\"\", arg[2],\n\t\t\t\t\"\\\" \", arg[1], \" < \", arg[3]);\n\t\t/*print(\"CMD >>\", cmd, \"<<\\n\");*/\n\t\tsystem(cmd);\n\t\tdeleteFile(tmpFile);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwSrc3[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tcloneID++;\n\t\tnew = clone(cloneID);\n\t\tsend(new, \"show_clone\", arg[1], arg[2]);\n\t\tsend(new, \"visible\", 1);\n\t\treturn;\n\tbreak;\n\tcase \"showByURL\":\n\t\tcloneID++;\n\t\tnew = clone(cloneID);\n\t\tsend(new, \"show_cloneByURL\", arg[1]);\n\t\tsend(new, \"visible\", 1);\n\t\treturn;\n\tbreak;\n\tcase \"show_clone\":\n\t\tsend(nthChild(1), \"show\", arg[1]);\n\t\tsend(nthChild(2), \"show\", arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"show_cloneByURL\":\n\t\tsend(nthChild(1), \"show\", arg[1]);\n\t\tsend(nthChild(2), \"getAndShow\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"apply\":\n\tcase \"saveAs\":\n\t\treturn send(nthChild(2), arg[0]);\n\tbreak;\n\tcase \"dismiss\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcloneID = 0;\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwSrc15[] = "\n\tswitch (arg[0]) {\n\tcase \"dismiss\":\n\tcase \"saveAs\":\n\tcase \"print\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwSrc16[] = "4";
static char _slotValue_wwwSrc17[] = "3";
/* END OF OBJ */

static char _slotValue_wwwSrc19[] = "wwwSrc.ctrl.ops";
static char _slotValue_wwwSrc20[] = "menu";
static char _slotValue_wwwSrc21[] = "wwwSrc.ctrl";
static char _slotValue_wwwSrc22[] = "File";
static char _slotValue_wwwSrc23[] = "\n. {Save as} {send(parent(), \"saveAs\");}\n. {Print   (not yet)}\n. {\\\\}\n. {Dismiss} {send(parent(), \"dismiss\");}\n";
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
static char _slotValue_wwwSrc42[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"dismiss\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwSrc43[] = "normal";
static char _slotValue_wwwSrc44[] = "100";
static char _slotValue_wwwSrc45[] = "2";
static char _slotValue_wwwSrc46[] = "2";
/* END OF OBJ */

static char _slotValue_wwwSrc48[] = "wwwSrc.top";
static char _slotValue_wwwSrc49[] = "txtDisp";
static char _slotValue_wwwSrc50[] = "wwwSrc";
static char _slotValue_wwwSrc51[] = "fixed";
static char _slotValue_wwwSrc52[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwSrc53[] = "30";
static char _slotValue_wwwSrc54[] = "5";
/* END OF OBJ */

static char _slotValue_wwwSrc56[] = "wwwSrc.list";
static char _slotValue_wwwSrc57[] = "hpane";
static char _slotValue_wwwSrc58[] = "wwwSrc";
static char _slotValue_wwwSrc59[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\tcase \"getAndShow\":\n\t\treturn send(nthChild(0), arg[0], arg[1]);\n\tbreak;\n\tcase \"contentP\":\n\tcase \"print\":\n\tcase \"saveAs\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwSrc73[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"enter\":\n\tcase \"keyPress\":\n\tcase \"leave\":\n\t\treturn;\n\tbreak;\n\tcase \"getAndShow\":\n\t\tcursorShape(\"busy\");\n\t\tlocalFile = HTTPGet(arg[1]);\n\t\tset(\"content\", loadFile(localFile));\n\t\tsystem(concat(\"rm -f \", localFile));\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"saveAs\":\n\t\tsend(\"res.getLineEntry\", \"show\", \n\t\t\t\"Enter file path to save source HTML into:\",\n\t\t\t\"\", self(), \"saveIntoThisFile\");\n\t\treturn;\n\tbreak;\n\tcase \"saveIntoThisFile\":\n\t\tif (saveFile(trimEdge(arg[1]), get(\"content\")) == 0) {\n\t\t\twinPos = windowPosition();\n\t\t\tres.dialogWithButtons(\"showAt\", \n\t\t\t\twinPos[0] + 20, winPos[1] + 20,\n\t\t\t\t500, 80,\n\t\t\t\tconcat(\"Failed to save source in file:\\n\", \n\t\t\t\t\ttrimEdge(arg[1])),\n\t\t\t\t\"Dismiss\", \"\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"print\":\n\t\ttempf = makeTempFile();\n\t\tsaveFile(tmpf, get(\"content\"));\n\t\t/* need to get printing command */\n\t\tsystem(concat(\"lpr \", tempf));\n\t\treturn;\n\tbreak;\n\tcase \"contentP\":\n\t\treturn get(\"content\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwURL2[] = "\n\tswitch (arg[0]) {\n\tcase \"open\":\n\t\t/* arg[1]\tdefault entry\n\t\t * arg[2]\tcaller, the obj to return result to\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t * arg[5]\twidth\n\t\t * arg[6]\theight\n\t\t */\n\t\tnewObj = clone(id);\n\t\tid++;\n\t\treturn send(newObj, \"_open\", \n\t\t\t    arg[1], arg[2], arg[3], arg[4], arg[5], arg[6]);\n\tbreak;\n\tcase \"_open\":\n\t\tcaller = arg[2];\n\n\t\tset(\"x\", arg[3]);\n\t\tset(\"y\", arg[4]);\n\t\tset(\"width\", arg[5]);\n\t\tset(\"height\", arg[6]);\n\n\t\twindowName(\"Attention, please...\");\n\t\tsend(newObj, \"visible\", 1);\n\t\tset(\"visible\", 1);\n\t\tsend(nthChild(1), \"show\", arg[1]);\n\t\treturn self();\n\tbreak;\n\tcase \"_cut\":\n\tcase \"_clear\":\n\t\tsend(nthChild(1), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"_ok\":\n\t\tset(\"visible\", 0);\n\t\tsend(caller, \"gotURLToOpen\", send(nthChild(1), \"contentP\"));\n\t\treturn;\n\tbreak;\n\tcase \"_cancel\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_wwwURL18[] = "\n\tswitch (arg[0]) {\n\tcase \"keyPress\":\n\t\tc = key();\n\t\tif (c == '\\r') send(parent(), \"_ok\");\n\t\telse insert(c);\n\t\treturn;\n\tbreak;\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"contentP\":\n\t\treturn get(\"content\");\n\tbreak;\n\tcase \"_cut\":\n\t\tset(\"content\", trimEdge(getSelection()));\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"_clear\":\n\t\tset(\"content\", \"\");\n\t\trender();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwURL19[] = "5";
static char _slotValue_wwwURL20[] = "1";
static char _slotValue_wwwURL21[] = "fixed";
/* END OF OBJ */

static char _slotValue_wwwURL23[] = "hpane";
static char _slotValue_wwwURL24[] = "wwwURL.buttons";
static char _slotValue_wwwURL25[] = "wwwURL";
static char _slotValue_wwwURL26[] = "wwwURL.buttons.ok wwwURL.buttons.cancel wwwURL.buttons.cut wwwURL.buttons.clear";
static char _slotValue_wwwURL27[] = "\n\tswitch (arg[0]) {\n\tcase \"_cancel\":\n\tcase \"_ok\":\n\tcase \"_cut\":\n\tcase \"_clear\":\n\t\tsend(parent(), arg[0]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwURL28[] = "25";
static char _slotValue_wwwURL29[] = "4";
static char _slotValue_wwwURL30[] = "3";
/* END OF OBJ */

static char _slotValue_wwwURL32[] = "txtButton";
static char _slotValue_wwwURL33[] = "Use Selected";
static char _slotValue_wwwURL34[] = "wwwURL.buttons.cut";
static char _slotValue_wwwURL35[] = "wwwURL.buttons";
static char _slotValue_wwwURL36[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"_cut\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwURL37[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL39[] = "txtButton";
static char _slotValue_wwwURL40[] = "Clear";
static char _slotValue_wwwURL41[] = "wwwURL.buttons.clear";
static char _slotValue_wwwURL42[] = "wwwURL.buttons";
static char _slotValue_wwwURL43[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"_clear\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwURL44[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL46[] = "txtButton";
static char _slotValue_wwwURL47[] = "OK";
static char _slotValue_wwwURL48[] = "wwwURL.buttons.ok";
static char _slotValue_wwwURL49[] = "wwwURL.buttons";
static char _slotValue_wwwURL50[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"_ok\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_wwwURL51[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL53[] = "txtButton";
static char _slotValue_wwwURL54[] = "Cancel";
static char _slotValue_wwwURL55[] = "wwwURL.buttons.cancel";
static char _slotValue_wwwURL56[] = "wwwURL.buttons";
static char _slotValue_wwwURL57[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"_cancel\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_mvw3[] = "\n/*for(i=0; i<arg[]; i++) print(\"MVW arg[\",i,\"]={\", arg[i], \"}\\n\");*/\n\n\t/* This is a GUI-less version of www.v, which the Motif frontend\n\t * wraps around of.\n\t *\n\t * Author: \tPei Y. Wei\n\t */\n\n\t/* URL port configurtion. 0 == off.\n\t */\n\tURLPort = 0;\n\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\t/* message from Motif interface shell */\n\t\treturn send(\"mvw.doc.view.pane\", arg[0], arg[1]);\n     \tbreak;\n\tcase \"historyList_selectedItem\":\n\t\treturn send(\"mvwHistory\", arg[0], arg[1]);\n     \tbreak;\n\tcase \"hotlistList_add\":\n\t\turl = send(\"mvw\", \"getCurrentDocURL\");\n\t\tcomment = send(\"mvw\", \"getCurrentDocTitle\");\n\t\tHTTPHotListAdd(url, comment, date());\n\t\treturn comment;\n\tbreak;\n\tcase \"hotlistList_goto\":\n\t\treturn send(\"mvw\", \"show\", HTTPHotListGet(0, arg[1]));\n\tbreak;\n\tcase \"hotlistList_delete\":\n\t\turl = send(\"mvw\", \"getCurrentDocURL\");\n\t\tcomment = send(\"mvw\", \"getCurrentDocTitle\");\n\t\treturn 0;\n\tbreak;\n\tcase \"hotlistList_edit\":\n\t\turl = send(\"mvw\", \"getCurrentDocURL\");\n\t\tcomment = send(\"mvw\", \"getCurrentDocTitle\");\n\t\treturn 0;\n     \tbreak;\n\tcase \"cloneApp\":\n\t\t/* arg[1]\tcookie -- is a unique token to be passed back\n\t\t */\n\t\tnew = clone(cookie);\n\t\treturn sendToInterface(\"showAppClone\", cookie, new);\n\tbreak;\n\tcase \"clonePage\":\n\tcase \"saveAs\":\n\t\t/* arg[1]\tcookie\n\t\t */\n\t\treturn send(nthChild(0), arg[0], arg[1]);\n\tbreak;\n\tcase \"reload\":\n\tcase \"showSource\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\tcase \"historyQuery\":\n\t\t/* arg[1]\tcookie\n\t\t */\n\t\treturn mvwHistory(\"historyQuery\", arg[1]);\n\tbreak;\n\tcase \"showPageClone_return\":\n\t\t/* arg[1] must be the cookie */\n\t\treturn sendToInterface(\"showPageClone\", arg[1], arg[2]);\n\tbreak;\n\tcase \"show\":\n\tcase \"post\":\n\t\tif (arg[] == 2)\n\t\t\tstat = send(\"mvw.doc.view.pane\", arg[0], arg[1]);\n\t\telse if (arg[] == 3)\n\t\t\tstat = send(\"mvw.doc.view.pane\", arg[0], arg[1], \n\t\t\t\t\t\t\t arg[2]);\n\t\telse\tstat = send(\"mvw.doc.view.pane\", arg[0], arg[1], \n\t\t\t\t\t\t\t arg[2], arg[3]);\n\t\tif (stat) stat = send(\"mvw.doc.view.pane\", \"historyRecord\");\n\t\treturn stat;\n\tbreak;\n\tcase \"show_URL_in_selectionBuffer\":\n\t\treturn send(\"mvw.doc.view.pane\", \"show\",\n\t\t\t\ttrimEdge(getSelection()));\n\tbreak;\n\tcase \"showDoc\":\n\tcase \"showHistoryDoc\":\n\t\tif (arg[] == 2) {\n\t\t\tstat = send(\"mvw.doc.view.pane\", \"show\", arg[1]);\n\t\t} else {\n\t\t\tstat = send(\"mvw.doc.view.pane\", \"show\", arg[1],\n\t\t\t\t\targ[2]);\n\t\t}\n\t\tsend(\"www.doc.view.pane\", \"historyRecord\");/*XXX*/\n\t\treturn stat;\n\tbreak;\n\tcase \"showHistory\":\n\t\t/* arg[1]\tcookie\n\t\t * arg[2]\tposition in history list\n\t\t */\n\t\treturn mvwHistory(\"showByPosition\", arg[1], arg[2]);\n\tbreak;\n\tcase \"addToHistory\":\n\t\tsend(\"mvwHistory\", \"add\", arg[1], arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"changeFonts\":\n\t\tsend(\"res.font\", arg[1]);\n\t\t/* bug: only main viewer is told of the font change */\n\t\tsend(\"mvw.doc.view.pane\", \"configSelf\");\n\t\treturn;\n\tbreak;\n\tcase \"group\":\n\t\tmvw.doc.title.icon(\"group\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"destroyDoc\":\n\t\treturn mvw.doc.view.pane(\"destroyDoc\");\n\tbreak;\n\tcase \"search\":\n\t\tmvw.doc.view.pane(\"search\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"showButNoRecord\":\n\t\tmvw.doc.view.pane(\"show\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"get_infoOnViolaWWW\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://berkeley.ora.com/proj/viola/vw/about_3.3.html\");\n\t\treturn;\n\tbreak;\n\tcase \"get_helpOnViolaWWW\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://berkeley.ora.com/proj/viola/vw/help_xvw_3.3.html\");\n\t\treturn;\n\tbreak;\n\tcase \"get_demoForViolaWWW\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://berkeley.ora.com/proj/viola/violaCentral.html\");\n\t\treturn;\n\tbreak;\n\tcase \"get_gnnWIC\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://nearnet.gnn.com/wic/newrescat.toc.html\");\n\t\treturn;\n\tbreak;\n\tcase \"get_cern\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://info.cern.ch/hypertext/DataSources/WWW/Servers.html\");\n\t\treturn;\n\tbreak;\n\tcase \"get_moreServers\":\n\t\tsend(\"www\", \"showHistoryDoc\", \n\t\t \"http://berkeley.ora.com/proj/viola/metaCenters.html\");\n\t\treturn;\n\tbreak;\n\tcase \"printDoc\":\n\t\t/* arg[1]\tprintCmd\n\t\t */\n\t\treturn;\n\tbreak;\n\tcase \"saveDoc\":\n\t\t/* arg[1]\tfile path\n\t\t */\n\t\treturn;\n\tbreak;\n\tcase \"saveSource\":\n\t\treturn;\n\tbreak;\n\tcase \"queryDocSecurity\":\n\t\t/* for interface to get doc level security level */\n\tbreak;\n\tcase \"setSecurityClearence\":\n\t\t/* coming from interace */\n\tbreak;\n\tcase \"querySecurityClearence\":\n\t\t/* send to interface */\n\tbreak;\n\tcase \"home\":\n\t\tcursorShape(\"busy\");\n\t\tmvw.doc.view.pane(\"showHistoryDoc\", homeDoc);\n\t\tmvw.doc.view.pane(\"historyRecord\");\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"prev\":\n\t\tcursorShape(\"busy\");\n\t\twantIt = mvwHistory(\"prev\");\n\t\tif (isBlank(wantIt) == 0) {\n\t\t\tmvw.doc.view.pane(\"showHistoryDoc\", wantIt);\n\t\t\tsendToInterface(\"prev\", cookie);\n\t\t}\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"next\":\n\t\tcursorShape(\"busy\");\n\t\twantIt = mvwHistory(\"next\");\n\t\tif (isBlank(wantIt) == 0) {\n\t\t\tmvw.doc.view.pane(\"showHistoryDoc\", wantIt);\n\t\t\tsendToInterface(\"next\", cookie);\n\t\t}\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"back\":\n\t\tcursorShape(\"busy\");\n\t\twantIt = mvwHistory(\"back\");\n\t\tif (isBlank(wantIt) == 0) {\n\t\t\tmvw.doc.view.pane(\"showHistoryDoc\", wantIt);\n\t\t\tsendToInterface(\"back\", cookie);\n\t\t}\n\t\tcursorShape(\"idle\");\n\t\treturn;\n\tbreak;\n\tcase \"busy\":\n\t\tsendToInterface(\"busyCursor\", cookie);\n\t\treturn cursorShape(arg[0]);\n\tbreak;\n\tcase \"idle\":\n\t\tsendToInterface(\"idleCursor\", cookie);\n\t\treturn cursorShape(arg[0]);\n\tbreak;\n\tcase \"quit\":\n\t\tquit();\n\tbreak;\n\tcase \"homeDocP\":\n\t\treturn homeDoc;\n\tbreak;\n\tcase \"getCurrentDocURL\":\n\tcase \"getCurrentDocTitle\":\n\t\tsend(\"mvw.doc.view.pane\", arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\n\t\thomeDoc = environVar(\"WWW_HOME\");\n\t\tif (isBlank(homeDoc) == 1)\n\t\t\thomeDoc = \"http://berkeley.ora.com/proj/viola/violaStartUp.html\";\n\t\tif (nthChar(homeDoc, 0) == '/')\n\t\t\thomeDoc = concat(\"file:\", homeDoc);\n\n\t\tHTTPHotListLoad();\n\n\t\tif (URLPort > 0) {\n\t\t\tprint(\"WARNING: port number \", URLPort,\n\t\t\t\" is now being used to accept URL fetch directives.\");\n\t\t\tif (send(mvwDocuPort(\"listen\", URLPort))) {\n\t\t\t\tprint(\"ERROR: Sorry, failed to open port \",\n\t\t\t\tURLPort, \" for listening to URL fetches\\n\");\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tsend(\"mvw.doc.view.pane\", \"outputSGML\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_mvw5[] = "generic";
static char _slotValue_mvw6[] = "www";
static char _slotValue_mvw7[] = "\n\t/* message forwarding service */\n\tswitch (arg[0]) {\n\tcase \"show\":\n\tcase \"post\":\n\t\tif (arg[] == 2) \n\t\t\treturn send(\"mvw\", arg[0], arg[1]);\n\t\telse if (arg[] == 3) \n\t\t\treturn send(\"mvw\", arg[0], arg[1], arg[2]);\n\t\telse\n\t\t\treturn send(\"mvw\", arg[0], arg[1], arg[2], arg[3]);\n\tbreak;\n\tcase \"home\":\n\tcase \"prev\":\n\tcase \"next\":\n\tcase \"showDoc\":\n\tcase \"showHistoryDoc\":\n\tcase \"destroyDoc\":\n\t\treturn send(\"mvw\", arg[0], arg[1]);\n\tbreak;\n\tcase \"addToHistory\":\n\t\treturn send(\"mvwHistory\", \"add\", arg[1], arg[2]);\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_mvw9[] = "vpane";
static char _slotValue_mvw10[] = "mvw.doc";
static char _slotValue_mvw11[] = "mvw";
static char _slotValue_mvw12[] = "mvw.doc.url mvw.doc.title mvw.doc.view";
static char _slotValue_mvw13[] = "\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\treturn send(nthChild(2), arg[0], arg[1]);\n\tbreak;\n\tcase \"addTool\":\n\tcase \"addTool_sticky\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(\"mvwTools\", arg[0], arg[1]);\n\tbreak;\n\tcase \"clear\":\n\t\treturn send(\"mvwTools\", arg[0]);\n\tbreak;\n\tcase \"reload\":\n\tcase \"showSource\":\n\t\treturn send(nthChild(2), arg[0]);\n\tbreak;\n\tcase \"saveAs\":\n\t\treturn send(nthChild(2), arg[0], arg[1]);\n\tbreak;\n\tcase \"clonePage\":\n\t\t/* arg[1]\tcookie\n\t\t */\n\t\tsend(nthChild(2), \"clonePage\");\n\t\ttearPageID = tearPageID + 1;\n\t\tnew = clone(tearPageID);\n\t\ttweak(new, \"set(\\\"parent\\\", \\\"\\\");\");\n\t\tsend(new, \"torn\", send(nthChild(2), \"whichPageP\"), arg[1]);\n\t\tsend(parent(), \"showPageClone_return\", arg[1], new);\n\t\treturn;\n\tbreak;\n\tcase \"tear\":\n\t\ttearPageID = tearPageID + 1;\n\t\tnew = clone(tearPageID);\n\t\ttweak(new, \"set(\\\"parent\\\", \\\"\\\");\");\n\t\tsend(new, \"torn\", send(nthChild(2), \"whichPageP\"));\n\t\tsend(new, \"render\");\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\tset(\"label\", \n\t\t\tsend(send(nthChild(2), \"whichPageP\"), \"queryAddress\"));\n\t\tobjectListSend_children(\"torn\", arg[1], arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\ttearPageID = 0;\n\t\treturn;\n\tbreak;\n\tcase \"whichPageP\":\n\t\treturn send(nthChild(2), \"whichPageP\");\n\tbreak;\n\tcase \"quit\":\n\t\tset(\"visible\", 0);\n\t\t/*XXX should destroy */\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_mvw15[] = "txtDisp";
static char _slotValue_mvw16[] = "mvw.doc.url";
static char _slotValue_mvw17[] = "mvw.doc";
static char _slotValue_mvw18[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", arg[1]);\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_mvw29[] = "\n\tswitch (arg[0]) {\n\tcase \"addTool\":\n\tcase \"addTool_sticky\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(nthChild(2), arg[0], arg[1]);\n\tbreak;\n\tcase \"clear\":\n\t\treturn send(nthChild(2), arg[0]);\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw30[] = "45";
/* END OF OBJ */

static char _slotValue_mvw32[] = "hpane";
static char _slotValue_mvw33[] = "mvw.doc.tools.dyna";
static char _slotValue_mvw34[] = "mvwTools";
static char _slotValue_mvw35[] = "\n\tswitch (arg[0]) {\n\tcase \"addTool\":\n\tcase \"addTool_sticky\":\n\t\tnew = object(arg[1]);\n\t\tfor (i = objectListCount_children(); i >= 0; i--) \n\t\t\tif (nthChild(i) == new) return 1;\n\t\tobjectListAppend(\"children\", new);\n\t\ttweak(new, concat(\"set(\\\"parent\\\", \\\"\", self(), \"\\\");\"));\n\t\tsend(new, \"visible\", 1);\n\t\tconfig();\n\t\treturn 1;\n\tbreak;\n\tcase \"removeTool\":\n\t\tnew = object(arg[1]);\n\t\tobjectListDelete(\"children\", new);\n\t\tsend(new, \"visible\", 0);\n\t\tconfig();\n\t\treturn 1;\n\tbreak;\n\tcase \"destroyTool\":\n\t\tnew = object(arg[1]);\n\t\tobjectListDelete(\"children\", new);\n\t\tsend(new, \"visible\", 0);\n\t\tsend(new, \"freeSelf\");\n\t\tconfig();\n\t\treturn 1;\n\tbreak;\n\tcase \"clear\":\n\t\tset(\"children\", \"\");\n\t\treturn;\n\tbreak;\n\tcase \"go_url\":\n\t\treturn send(\"mvw\", \"show\", arg[1]);\n\tbreak;\n\tcase \"go_home\":\n\t\treturn send(\"mvw\", \"home\");\n\tbreak;\n\tcase \"go_prev\":\n\t\treturn send(\"mvw\", \"prev\");\n\tbreak;\n\tcase \"go_next\":\n\t\treturn send(\"mvw\", \"next\");\n\tbreak;\n\tcase \"go_back\":\n\t\treturn send(\"mvw\", \"back\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_mvw47[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"mvw\",\"home\");\n\tbreak;\n\tcase \"enter\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", \n\t\t\t\"Click the house icon to visit home page.\");\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"clear\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw48[] = "/* XPM */\nstatic char * home [] = {\n\"32 32 9 1\",\n\" \tc black\",\n\".\tc white\",\n\"X\tc grey75\",\n\"o\tc gray30\",\n\"O\tc red\",\n\"+\tc #E0E0D0D0B0B0\",\n\"@\tc lightyellow\",\n\"#\tc gray\",\n\"$\tc gray50\",\n\"                                \",\n\" .............................  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\" .XXXXXXXXXX       XXXXXXXXXXo  \",\n\" .XXXXXXXXX OOOOOOO XXXXXXXXXo  \",\n\" .XXXXXXXX O+@OOOOOO XXXXXXXXo  \",\n\" .XXXXXXXX O+@@OOOOOO XXXXXXXo  \",\n\" .XXXXXXX O+@@@OOOOOOO XXXXXXo  \",\n\" .XXXXXX O+@@@@@OOOOOOO XXXXXo  \",\n\" .XXXXX O+@@@@@@@OOOOOOO XXXXo  \",\n\" .XXXXX O+@@@@@@@@OOOOOOO XXXo  \",\n\" .XXXX O+@@@@@@@@@OOOOOOOO XXo  \",\n\" .XXX O+@@@#####@@@OOOO++ XXXo  \",\n\" .XXXX  @@@#   #@@@@+++++ XXXo  \",\n\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\" .XXXXX @@@#   #@@@@+++++ XXXo  \",\n\" .XXXXX @@@#   #@@@@++++  XXXo  \",\n\" .XXXXX @@@#   #@@@@++  XXXXXo  \",\n\" .XXXXXX             XXXXXXXXo  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\" .XXXX XX X$  $X XXX X   XXXXo  \",\n\" .XXXX XX X XX X  X  X XXXXXXo  \",\n\" .XXXX    X XX X $ $ X  XXXXXo  \",\n\" .XXXX XX X XX X X X X XXXXXXo  \",\n\" .XXXX XX X XX X XXX X XXXXXXo  \",\n\" .XXXX XX X$  $X XXX X   XXXXo  \",\n\" .XXXXXXXXXXXXXXXXXXXXXXXXXXXo  \",\n\" .oooooooooooooooooooooooooooo  \",\n\"                                \",\n\"                                \"};\n";
static char _slotValue_mvw49[] = "32";
static char _slotValue_mvw50[] = "1";
static char _slotValue_mvw51[] = "2";
/* END OF OBJ */

static char _slotValue_mvw53[] = "XPMButton";
static char _slotValue_mvw54[] = "mvw.doc.tools.sys.back";
static char _slotValue_mvw55[] = "mvw.doc.tools.sys";
static char _slotValue_mvw56[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"mvw\", \"back\");\n\tbreak;\n\tcase \"enter\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", \n\t\t\t\"Click to go roll back the history list (destructive back up).\");\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"clear\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw57[] = "/* XPM */\nstatic char * back [] = {\n\"32 32 7 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc gray\",\n\"O\tc gray30\",\n\"+\tc gray50\",\n\"@\tc grey75\",\n\"............................... \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xooooooooooooo.oooooooooooooO. \",\n\".Xoooooooooooo.+.ooooooooooooO. \",\n\".Xoooooooooooo.+.ooooooooooooO. \",\n\".Xooooooooooo.+++.oooooooooooO. \",\n\".Xooooooooooo.+++.oooooooooooO. \",\n\".Xoooooooooo.+++++.ooooooooooO. \",\n\".Xoooooooooo.+++++.ooooooooooO. \",\n\".Xooooooooo.+++++++.oooooooooO. \",\n\".Xooooooooo.+++++++.oooooooooO. \",\n\".Xoooooooo.+++++++++.ooooooooO. \",\n\".Xoooooooo.+++++++++.ooooooooO. \",\n\".Xooooooo.+++++++++++.oooooooO. \",\n\".Xooooooo.+++++++++++.oooooooO. \",\n\".Xoooooo.+++++++++++++.ooooooO. \",\n\".Xoooooo.+++++++++++++.ooooooO. \",\n\".Xooooooo.............oooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xoooo...+oo+.+oo+..o.oo.ooooO. \",\n\".Xoooo.oo.oo.o.oo.ooo.o.oooooO. \",\n\".Xoooo...ooo.o.oo.ooo..ooooooO. \",\n\".Xoooo.oo.o+...+o.ooo..ooooooO. \",\n\".Xoooo.oo.o.+o+.o.ooo.@.oooooO. \",\n\".Xoooo...+o.ooo.o+..o.oo.ooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\"............................... \",\n\"                                \"};\n";
static char _slotValue_mvw58[] = "32";
static char _slotValue_mvw59[] = "1";
static char _slotValue_mvw60[] = "2";
/* END OF OBJ */

static char _slotValue_mvw62[] = "XPMButton";
static char _slotValue_mvw63[] = "mvw.doc.tools.sys.prev";
static char _slotValue_mvw64[] = "mvw.doc.tools.sys";
static char _slotValue_mvw65[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"mvw\", \"prev\");\n\tbreak;\n\tcase \"enter\":\n\t\tsend(\"www.mesg.tf\", \"suggest\",\n\t\t\t\"Click to visit the previous document.\");\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"clear\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw66[] = "/* XPM */\nstatic char * prev [] = {\n\"32 32 6 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc grey75\",\n\"O\tc gray30\",\n\"+\tc gray50\",\n\"............................... \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xoooooooooooooooooo..oooooooO. \",\n\".Xoooooooooooooooo..++.ooooooO. \",\n\".Xoooooooooooooo..++++.ooooooO. \",\n\".Xoooooooooooo..++++++.ooooooO. \",\n\".Xoooooooooo..++++++++.ooooooO. \",\n\".Xoooooooo..++++++++++.ooooooO. \",\n\".Xooooooo.++++++++++++.ooooooO. \",\n\".Xooooo.++++++++++++++.ooooooO. \",\n\".Xoooooo..++++++++++++.ooooooO. \",\n\".Xoooooooo..++++++++++.ooooooO. \",\n\".Xoooooooooo..++++++++.ooooooO. \",\n\".Xoooooooooooo..++++++.ooooooO. \",\n\".Xoooooooooooooo..++++.ooooooO. \",\n\".Xoooooooooooooooo..++.ooooooO. \",\n\".Xoooooooooooooooooo..oooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xoooo...+o...+o...o.ooo.ooooO. \",\n\".Xoooo.oo.o.oo.o.ooo.ooo.ooooO. \",\n\".Xoooo.oo.o...+o..oo.+o+.ooooO. \",\n\".Xoooo...+o.o.oo.oooo.o.oooooO. \",\n\".Xoooo.oooo.oo.o.oooo.+.oooooO. \",\n\".Xoooo.oooo.oo.o...ooo.ooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\"............................... \",\n\"                                \"};\n";
static char _slotValue_mvw67[] = "32";
static char _slotValue_mvw68[] = "1";
static char _slotValue_mvw69[] = "2";
/* END OF OBJ */

static char _slotValue_mvw71[] = "XPMButton";
static char _slotValue_mvw72[] = "mvw.doc.tools.sys.next";
static char _slotValue_mvw73[] = "mvw.doc.tools.sys";
static char _slotValue_mvw74[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"mvw\", \"next\");\n\tbreak;\n\tcase \"enter\":\n\t\tsend(\"www.mesg.tf\", \"suggest\",\n\t\t\t\"Click to visit the next document.\");\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"clear\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw75[] = "/* XPM */\nstatic char * next [] = {\n\"32 32 6 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc grey75\",\n\"O\tc gray30\",\n\"+\tc gray50\",\n\"............................... \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xoooooooo..oooooooooooooooooO. \",\n\".Xooooooo.++..oooooooooooooooO. \",\n\".Xooooooo.++++..oooooooooooooO. \",\n\".Xooooooo.++++++..oooooooooooO. \",\n\".Xooooooo.++++++++..oooooooooO. \",\n\".Xooooooo.++++++++++..oooooooO. \",\n\".Xooooooo.++++++++++++..oooooO. \",\n\".Xooooooo.++++++++++++++.ooooO. \",\n\".Xooooooo.++++++++++++..oooooO. \",\n\".Xooooooo.++++++++++..oooooooO. \",\n\".Xooooooo.++++++++..oooooooooO. \",\n\".Xooooooo.++++++..oooooooooooO. \",\n\".Xooooooo.++++..oooooooooooooO. \",\n\".Xooooooo.++..oooooooooooooooO. \",\n\".Xoooooooo..oooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xooo.+oo.o...o.ooo.o.....oooO. \",\n\".Xooo..+o.o.ooo+.o.+ooo.oooooO. \",\n\".Xooo.o.+.o..+oo+.+oooo.oooooO. \",\n\".Xooo.oo..o.oooo+.+oooo.oooooO. \",\n\".Xooo.ooo.o.ooo+.o.+ooo.oooooO. \",\n\".Xooo.ooo.o...o.ooo.ooo.oooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\"............................... \",\n\"                                \"};\n";
static char _slotValue_mvw76[] = "32";
static char _slotValue_mvw77[] = "1";
static char _slotValue_mvw78[] = "2";
/* END OF OBJ */

static char _slotValue_mvw80[] = "XPMButton";
static char _slotValue_mvw81[] = "mvw.doc.tools.sys.reload";
static char _slotValue_mvw82[] = "mvw.doc.tools.sys";
static char _slotValue_mvw83[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(\"mvw\", \"reload\");\n\tbreak;\n\tcase \"enter\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", \"Click to reload the document\");\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"clear\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw84[] = "/* XPM */\nstatic char * reload [] = {\n\"32 32 6 1\",\n\" \tc black\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc gray\",\n\"O\tc gray30\",\n\"+\tc red\",\n\"............................... \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xooooooo...........oooooooooO. \",\n\".Xooooooo.XXXXXXXX.X.ooooooooO. \",\n\".Xoooo+++.X......X.XX.oooooooO. \",\n\".Xoooo+++.XXXXXXXX.XXX.ooooooO. \",\n\".Xoooo+...X......X.....ooooooO. \",\n\".Xoooo+++.XXXXXXXXXXXX.ooooooO. \",\n\".Xoooo+...X.........XX.ooooooO. \",\n\".Xoooo+++.XXXXXXXXXXXX.ooooooO. \",\n\".Xoooo+...X.........XX.ooooooO. \",\n\".Xoooo+++.XXXXXXXXXXXX.ooooooO. \",\n\".Xoooo+...X.........XX.ooooooO. \",\n\".Xoooo+++.XXXXXXXXXXXX.ooooooO. \",\n\".Xoooo+................ooooooO. \",\n\".Xoooo++++++++++++++oooooooooO. \",\n\".Xoooo+...........++oooooooooO. \",\n\".Xoooo++++++++++++++oooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xoo...Oo...o.ooO.OoO.Oo..oooO. \",\n\".Xoo.oo.o.ooo.oo.o.o.O.o.o.ooO. \",\n\".Xoo...Oo..oo.oo.o.o.o.o.o.ooO. \",\n\".Xoo.o.oo.ooo.oo.o.o...o.o.ooO. \",\n\".Xoo.oo.o.ooo.oo.o.o.o.o.o.ooO. \",\n\".Xoo.oo.o...o..oO.Oo.o.o..oooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\"............................... \",\n\"                                \"};\n";
static char _slotValue_mvw85[] = "32";
static char _slotValue_mvw86[] = "1";
static char _slotValue_mvw87[] = "2";
/* END OF OBJ */

static char _slotValue_mvw89[] = "XPMButton";
static char _slotValue_mvw90[] = "mvw.doc.tools.ops.clone";
static char _slotValue_mvw91[] = "mvw.doc.tools.ops";
static char _slotValue_mvw92[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsendToInterface(\"clone\");\n\tbreak;\n\tcase \"enter\":\n\t\tsend(\"www.mesg.tf\", \"suggest\", \"Click to clone the document\");\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tsend(\"www.mesg.tf\", \"clear\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw93[] = "/* XPM */\nstatic char * clone [] = {\n\"32 32 5 1\",\n\" \ts None\tc None\",\n\".\tc black\",\n\"X\tc white\",\n\"o\tc gray\",\n\"O\tc gray30\",\n\"............................... \",\n\".XXXXXXXXXXXXXXXXXXXXXXXXXXXXX. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xooo..........ooooooooooooooO. \",\n\".Xooo.XXXXXXX.X.oooooooooooooO. \",\n\".Xooo.X....XX.XX.ooooooooooooO. \",\n\".Xooo.XXXXXXX.XXX.oooooooooooO. \",\n\".Xooo.X.....X.....oooooooooooO. \",\n\".Xooo.XXXXXXXXXXX.oooooooooooO. \",\n\".Xooo.X......X.........ooooooO. \",\n\".Xooo.XXXXXXXX.XXXXXX.X.oooooO. \",\n\".Xooo.X......X.X...XX.XX.ooooO. \",\n\".Xooo.XXXXXXXX.XXXXXX.XXX.oooO. \",\n\".Xooo.X......X.X....X.....oooO. \",\n\".Xooo.XXXXXXXX.XXXXXXXXXX.oooO. \",\n\".Xooo.XXXXXXXX.X........X.oooO. \",\n\".Xooo..........XXXXXXXXXX.oooO. \",\n\".Xoooooooooooo.X........X.oooO. \",\n\".Xoooooooooooo.XXXXXXXXXX.oooO. \",\n\".Xoooooooooooo.XXXXXXXXXX.oooO. \",\n\".Xoooooooooooo............oooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".Xooooo..o.oo...o.Oo.o...ooooO. \",\n\".Xoooo.Ooo.oo.o.o..o.o.ooooooO. \",\n\".Xoooo.ooo.oo.o.o.o..o..oooooO. \",\n\".Xoooo.ooo.oo.o.o.oO.o.ooooooO. \",\n\".Xoooo.Ooo.oo.o.o.oo.o.ooooooO. \",\n\".Xooooo..o..o...o.oo.o...ooooO. \",\n\".XoooooooooooooooooooooooooooO. \",\n\".XOOOOOOOOOOOOOOOOOOOOOOOOOOOO. \",\n\"............................... \",\n\"                                \"};\n";
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
static char _slotValue_mvw111[] = "\n\tswitch (arg[0]) {\n\tcase \"stat\":\n\t\tif (inProgress == 0) {\n\t\t\tclearWindow();\n\t\t\tinProgress = 1;\n\t\t}\n\t\tfillArc(5, 2, w, h, 0, arg[1] * 3.6);\n\t\tflush();\n\t\treturn;\n\tbreak;\n\tcase \"clear\":\n\t\tinProgress = 0;\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\tcase \"init\":\n\t\tusual();\n\t\th = get(\"height\") - 5;\n\t\tw = h;\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw112[] = "#define violaIcon2_width 36\n#define violaIcon2_height 30\nstatic char violaIcon2_bits[] = {\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00,\n   0x00, 0xe0, 0x30, 0x78, 0x00, 0x00, 0x30, 0x60, 0xcc, 0x01, 0x00, 0x18,\n   0xc0, 0x07, 0x03, 0x00, 0x08, 0x80, 0x01, 0x03, 0x00, 0x0c, 0x00, 0x00,\n   0x06, 0x00, 0x04, 0x00, 0x00, 0x46, 0x01, 0x04, 0x00, 0x00, 0x46, 0x01,\n   0x04, 0x80, 0xa4, 0xff, 0x03, 0x04, 0x0f, 0x00, 0x40, 0x01, 0x04, 0x0f,\n   0x00, 0x40, 0x01, 0x04, 0x0e, 0x04, 0x40, 0x01, 0x08, 0x0e, 0x04, 0x00,\n   0x00, 0x18, 0x1c, 0x04, 0x00, 0x00, 0x30, 0x1c, 0x02, 0x04, 0x00, 0xf0,\n   0x19, 0x0a, 0x74, 0x00, 0xe0, 0x39, 0x02, 0x84, 0x00, 0xc0, 0x31, 0xc9,\n   0x84, 0x00, 0x00, 0x20, 0x29, 0xe5, 0x00, 0x00, 0x60, 0x29, 0x95, 0x00,\n   0x00, 0xc0, 0x29, 0x95, 0x00, 0x00, 0xc0, 0xc8, 0xe4, 0x01, 0x00, 0x80,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n";
static char _slotValue_mvw113[] = "1";
static char _slotValue_mvw114[] = "32";
static char _slotValue_mvw115[] = "6";
/* END OF OBJ */

static char _slotValue_mvw117[] = "txtDisp";
static char _slotValue_mvw118[] = "mvw.doc.title";
static char _slotValue_mvw119[] = "mvw.doc";
static char _slotValue_mvw120[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tif (isBlank(arg[1])) {\n/*\t\t\tset(\"content\", \"<No Title>\");*/\n\t\t\tset(\"content\", \"\");\n\t\t} else {\n\t\t\tif (textWidth(6/*bold_largest*/, arg[1])+10 \n\t\t\t    < width()) {\n\t\t\t\t/*set(\"font\", \"bold_largest\");*/\n\t\t\t\tset(\"content\", concat(\"\\\\f(6)\", arg[1]));\n\t\t\t} else {\n\t\t\t\t/*set(\"font\", \"bold\");*/\n\t\t\t\tset(\"content\", concat(\"\\\\f(5)\", arg[1]));\n\t\t\t}\n\t\t}\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_mvw135[] = "\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\treturn send(nthChild(0), arg[0], arg[1]);\n\tbreak;\n\tcase \"config\":\n\t\tif (lbarVisible == 1) {\n\t\t\tsend(nthChild(0), \"resetWidthConstraint\", arg[3]);\n\t\t}\n\tbreak;\n\tcase \"reload\":\n\tcase \"showSource\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\tcase \"saveAs\":\n\t\treturn send(nthChild(0), arg[0], arg[1]);\n\tbreak;\n\tcase \"tear\":\n\tcase \"quit\":\n\t\tsend(get(\"parent\"), arg[0]);\n\t\treturn;\n\tbreak;\n\tcase \"clonePage\":\n\t\tpagePane = get(\"content\");\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\tobjectListSend_children(\"torn\", arg[1], arg[2]);\n\t\tpagePane = get(\"content\");\n\t\treturn;\n\tbreak;\n\tcase \"whichPageP\":\n\t\treturn send(pagePane, \"whichPageP\");\n\tbreak;\n\tcase \"key_up\":\n\tcase \"key_down\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\tcase \"addTool\":\n\tcase \"addTool_sticky\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(parent(), arg[0], arg[1]);\n\tbreak;\n\tcase \"linkSideBar\":\n\t\tsideBarURL = arg[1];\n\t\tsideBarRatio = arg[2];\n\t\tsideBarMaxWidth = arg[3];\n\t\tsend(self(), \"lbarConfig\", \"on\", \n\t\t\tsideBarURL, sideBarRatio, sideBarMaxWidth);\n\t\treturn;\n\tbreak;\n\tcase \"lbarConfig\":\n\t\tswitch (arg[1]) {\n\t\tcase \"on\":\n\t\t\tset(\"children\", \n\t\t\t\"mvw.doc.view.lbar mvw.doc.view.pane\");\n\t\t\tsend(nthChild(0), \"enable\", \n\t\t\t\targ[2], arg[3], arg[4], width());\n\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tif (lbarVisible == 0) send(nthChild(0), \"visible\", 1);\n\t\t\tpagePane = nthChild(1);\n\t\t\tlbarVisible = 1;\n\t\tbreak;\n\t\tcase \"off\":\n\t\t\tif (lbarVisible == 1) send(nthChild(0), \"disable\");\n\t\t\tset(\"children\",\n\t\t\t\"mvw.doc.view.pane\");\n\t\t\tlbarVisible = 0;\n\t\t\tsend(self(), \"configSelf\");\n\t\t\tpagePane = nthChild(0);\n\t\tbreak;\n\t\t}\n\t\tset(\"content\", pagePane);\n\t\treturn;\n\tbreak;\n\tcase \"sliderConfig\":\n\t\tsend(self(), \"configSelf\");\n\t\tpagePane = nthChild(0);\n\t\tset(\"content\", pagePane);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tpagePane = nthChild(0); /* default scrolbar at right side */\n\t\tset(\"content\", pagePane);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_mvw137[] = "vpane";
static char _slotValue_mvw138[] = "mvw.doc.view";
static char _slotValue_mvw139[] = "mvw.doc.view.lbar";
static char _slotValue_mvw140[] = "mvw.doc.view.lbar.pane mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw141[] = "\n\tswitch (arg[0]) {\n\tcase \"barScroll\":\n\t\treturn send(nthChild(0), arg[0], arg[1]);\n\tbreak;\n\tcase \"enable\":\n\t\tenable = 1;\n\t\tbarURL = arg[1];\n\t\tbarRatio = arg[2];\n\t\tbarMaxWidth = arg[3];\n\t\tparentWidth = arg[4];\n\n\t\tif (barMaxWidth != 0) {\n\t\t\tbarWidth = barMaxWidth;\n\t\t} else {\n\t\t\tbarWidth = float(parentWidth) * \n\t\t\t\t\tfloat(barRatio) / 100.0;\n\t\t}\n\t\tset(\"width\", barWidth);\n\t\tset(\"maxWidth\", barWidth);\n\t\tset(\"visible\", 1);\n\t\tsend(nthChild(0), \"show\", barURL, barWidth);\n\t\treturn;\n\tbreak;\n\tcase \"disable\":\n\t\tenable = 0;\n\t\tset(\"visible\", 0);\n\t\tset(\"y\", 999);/*???? why won't this window go away??*/\n\t\treturn;\n\tbreak;\n\tcase \"lbarEnabledP\":\n\t\treturn enable;\n\tbreak;\n\tcase \"resetWidthConstraint\":\n\t\tparentWidth = arg[1];\n\t\tbarWidth = float(parentWidth) * float(barRatio) / 100.0;\n\t\tset(\"width\", 99);/*lame way to force a re config */\n\t\tset(\"maxWidth\", barWidth);\n\t\treturn;\t\t\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_mvw154[] = "\n\tswitch (arg[0]) {\n\tcase \"barScroll\":\n\t\treturn send(parent(), arg[0], arg[1]);\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw155[] = "1";
static char _slotValue_mvw156[] = "20";
/* END OF OBJ */

static char _slotValue_mvw158[] = "txtButton";
static char _slotValue_mvw159[] = "mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw160[] = "mvw.doc.view.lbar.ctrls.up";
static char _slotValue_mvw161[] = "Up";
static char _slotValue_mvw162[] = "\n\tif (arg[0] == \"buttonRelease\") send(parent(), \"barScroll\", \"up\");\n\tusual();\n";
static char _slotValue_mvw163[] = "normal";
static char _slotValue_mvw164[] = "2";
/* END OF OBJ */

static char _slotValue_mvw166[] = "txtButton";
static char _slotValue_mvw167[] = "mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw168[] = "mvw.doc.view.lbar.ctrls.down";
static char _slotValue_mvw169[] = "Down";
static char _slotValue_mvw170[] = "\n\tif (arg[0] == \"buttonRelease\") send(parent(), \"barScroll\", \"down\");\n\tusual();\n";
static char _slotValue_mvw171[] = "normal";
static char _slotValue_mvw172[] = "1";
/* END OF OBJ */

static char _slotValue_mvw174[] = "field";
static char _slotValue_mvw175[] = "mvw.doc.view.lbar.pane";
static char _slotValue_mvw176[] = "mvw.doc.view.lbar";
static char _slotValue_mvw177[] = "mvw.doc.view.lbar.sb";
static char _slotValue_mvw178[] = "\n\tswitch (arg[0]) {\n\tcase \"shownPositionH\":\n\tcase \"shownPositionV\":\n\t\treturn send(docObj, \"shownPositionV\", arg[1]);\n\tbreak;\n\tcase \"barScroll\":\n\t\tif (arg[1] == \"down\") {\n\t\t\tpgPosPct += 10;\n\t\t\tif (pgPosPct > 100) pgPosPct = 100;\n\t\t} else {\n\t\t\tpgPosPct -= 10;\n\t\t\tif (pgPosPct < 0) pgPosPct = 0;\n\t\t}\n\t\treturn send(docObj, \"shownPositionV\", pgPosPct);\n\tbreak;\n\tcase \"show\":\n\t\tbarURL = arg[1];\n\t\tbarWidth = arg[2];\n\n\t\tset(\"width\", barWidth);\n\n\t\tpgPosPct = 0;\n\n\t\thandler = wwwFormatDetect(\"type\", barURL);\n\t\tsend(\"www.mesg.tf\", \"show\", \n\t\t\t    concat(\"Getting sidebar from \", barURL));\n\n\t\tdocObj = send(\"wwwHandlerDispatch\", \n\t\t\t\t\"dispatch\", handler,\n\t\t\t\t0, barURL,\n\t\t\t\tbarURL, self(),\n\t\t\t\tint(barWidth), 999,\n\t\t\t\t\"\", 1, 0);\n\n\t\t/* XXX kludgy stylesheet turn off */\n\t\tSTG_clean(0);\n\n\t\tsend(docObj, \"display\", barWidth, 999);\n\t\tsend(docObj, \"show\");\n\n\t\tpageHeight = send(docObj, \"vspan\");\n\t\tsend(self(), \"configShare\");\n\n\t\treturn;\n\tbreak;\n\tcase \"toDoInsert\":\n\t\tinsertObj[insertObjCount] = arg[1];\n\t\tinsertObjCount++;\n\t\treturn;\n\tbreak;\n\tcase \"show_request_by_child\":\n\tcase \"post_request_by_child\":\n\t\tsendToInterface(\"busyCursor\", cookie);\n\t\tcursorShape(\"busy\");\n\n\t\tif (arg[0] == \"post_request_by_child\") realMesg = \"post\";\n\t\telse realMesg = \"show\";\n\n\t\tif (torn == 1) destObj = self();\n\t\telse destObj = object(\"mvw\");\n\n\t\tif (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);\n\t\telse stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);\n\n\t\tif (stat) stat = send(\"mvw.doc.view.pane\", \"historyRecord\");\n\n\t\tsendToInterface(\"idleCursor\", cookie);\n\t\tcursorShape(\"idle\");\n\t\treturn stat;\n\tbreak;\n\tcase \"setChildren\":\n\t\tset(\"children\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"configShare\":\n\t\theightDiff = pageHeight - get(\"height\");\n\t\theightRatio =  float(heightDiff) / -100.0;\n\t\tif (heightDiff > 0) {\n\t\t  sliderSize = float(get(\"height\")) / float(pageHeight) * 100;\n\t\t  sliderPos = float(pageYPos) / float(heightDiff) * -100;\n\t\t} else {\n\t\t  sliderSize = 100;\n\t\t  sliderPos = 0;\n\t\t}\n\t\tobjectListSend(\"shownDepend\", \"_shownInfoH\", \n\t\t\t\tsliderPos, sliderSize);\n\t\tobjectListSend(\"shownDepend\", \"setShownNotify\", docObj);\n\t\treturn;\n\tbreak;\n\tcase \"configSliderGeom\":\n\t\tpageHeight = send(docObj, \"vspan\");\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"configSlider\":\n\t\t/* arg[1]\tpageYPos\n\t\t * arg[2]\tpageHeight\n\t\t */\n\t\tpageYPos = arg[1];\n\t\tpageHeight = arg[2];\n\t\tif (pageYPos + pageHeight < get(\"height\")) {\n\t\t\tpageYPos = get(\"height\") - pageHeight;\n\t\t\tif (pageYPos > 0) pageYPos = 0;\n\t\t\tsend(docObj, \"y\", pageYPos);\n\t\t}\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tif (send(parent(), \"lbarEnabledP\") == 0) return;\n\t\tusual();\n\t\t/* ask page object to do the calculation */\n\t\tsend(docObj, \"resize\", get(\"width\"), get(\"height\"));\n\t\tpageYPos = send(docObj, \"yP\");\n\t\tpageHeight = send(docObj, \"vspan\");\n\t\tif (pageYPos + pageHeight < get(\"height\")) {\n\t\t\tpageYPos = get(\"height\") - pageHeight;\n\t\t\tsend(docObj, \"y\", pageYPos);\n\t\t}\n\t\tsend(self(), \"configShare\");\n\t\tconfiged = 1;\n\t\treturn;\n\tbreak;\n\tcase \"update\":\n\t\tpageObj = nthChild(0);\n\t\tpageHeight = arg[1];\n\t\tsend(self(), \"configShare\");\n\t\treturn;\n\tbreak;\n\tcase \"destroyDoc\":\n\tcase \"destroyDoc_qualified\":\n\t\tsend(pageObj, \"VW_event\", \"VIEW_OFF\");\n\t\tsend(pageObj, \"visible\", 0);\n\t\tsend(pageObj, \"freeSelf\");\n\t\tpageObj = 0;\n\t\treturn;\n\tbreak;\n\tcase \"addTool\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(parent(), arg[0], arg[1]);\n\tbreak;\n\tcase \"showSrc\":\n\tcase \"reload\":\n\tcase \"clone\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\tcase \"whichPageP\":\n\t\treturn nthChild(0);\n\tbreak;\n\tcase \"heightP\":\n\t\treturn height();\n\tbreak;\n\tcase \"R\": /* happens sometimes. blah */\n\tcase \"reportNextID\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw179[] = "100";
static char _slotValue_mvw180[] = "999";
static char _slotValue_mvw181[] = "2";
static char _slotValue_mvw182[] = "2";
static char _slotValue_mvw183[] = "6";
/* END OF OBJ */

static char _slotValue_mvw185[] = "field";
static char _slotValue_mvw186[] = "mvw.doc.view.pane";
static char _slotValue_mvw187[] = "mvw.doc.view";
static char _slotValue_mvw188[] = "\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\tsliderPos = arg[1];\n\t\treturn send(pageObj, arg[0], sliderPos);\n\tbreak;\n\tcase \"key_up\":\n\t\treturn send(pageObj, \"scrollPageDown\");\n\tbreak;\n\tcase \"key_down\":\n\t\treturn send(pageObj, \"scrollPageUp\");\n\tbreak;\n\tcase \"procratinate_show\":\n\t\tif (hasConfiged) {\n\t\t\tstat = send(\"mvw.doc.view.pane\", \"show\", arg[1]);\n\t\t\tsend(\"mvw.doc.view.pane\", \"historyRecord\");\n\t\t} else {\n/* wait after the window has opened and configured to the correct size */\n\t\t\tafter(1000, self(), \"procratinate_show\", arg[1]);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"show\":\n\tcase \"post\":\n\tcase \"showDoc\":\n\tcase \"showHistoryDoc\":\n\t\tsendToInterface(\"busyCursor\", cookie);\n\t\tcursorShape(\"busy\");\n\t\tif (arg[0] == \"post\") {\n\t\t\tdoPost = 1;\n\t\t\tpostData = arg[3];\n\t\t} else { \n\t\t\tdoPost = 0;\n\t\t\tpostData = 0;\n\t\t}\n\t\tif (torn == 1) {\n\t\t\tif (arg[] == 2) \n\t\t\t\tstat = send(\"mvw.doc.view.pane\", arg[0], arg[1]);\n\t\t\telse if (arg[] == 3) \n\t\t\t\tstat = send(\"mvw.doc.view.pane\", arg[0], arg[1], arg[2]);\n\t\t\telse\tstat = send(\"mvw.doc.view.pane\", arg[0], arg[1], arg[2], arg[3]);\n\t\t\tsendToInterface(\"idleCursor\", cookie);\n\t\t\tcursorShape(\"idle\");\n\t\t\treturn stat;\n\t\t}\n\t\tif (nthChar(arg[1], 0) == '#') {\n\t\t\tpageYPos = send(pageObj, \"gotoAnchor\", \n\t\t\t\t\tnthChar(arg[1], 1, 999));\n\n\t\t\tpageHeight = send(pageObj, \"vspan\");\n\t\t\theightDiff = pageHeight - get(\"height\");\n\t\t\theightRatio =  float(heightDiff) / -100.0;\n\n\t\t\tif (heightDiff > 0) {\n\t\t\t\tsliderSize = float(get(\"height\")) / float(pageHeight) * 100;\n\t\t\t\tsliderPos = float(pageYPos) / float(heightDiff) * 100;\n\t\t\t\tif (sliderPos > 100) sliderPos = 100;\n\t\t\t} else {\n\t\t\t\tsliderSize = 100;\n\t\t\t\tsliderPos = 0;\n\t\t\t}\n\t\t\tsend(pageObj, \"shownPositionV\", sliderPos);\n\t\t} else {\n\t\t\tif (arg[] == 2)\n\t\t\t  normURL = send(\"normalizeURL\", \"normalizeURL\", arg[1]);\n\t\t\telse \n\t\t\t  normURL = send(\"normalizeURL\", \"normalizeURL\", arg[1], arg[2]);\n\n\t\t\tif (hasConfiged == 0) {\n\t\t\t\tdocToRenderAfterConfigure = normURL;\n\t\t\t\tsendToInterface(\"idleCursor\", cookie);\n\t\t\t\tcursorShape(\"idle\");\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tdocName = normURL;\n\t\t\tdocURL = normURL;\n\n\t\t\tif (findPattern(arg[1], \"telnet:\") != -1) {\n\t\t\t\tstat = send(\"mvw.delegationHandler\", \n\t\t\t\t\t\t\"doTelnet\", normURL);\n\t\t\t\tsendToInterface(\"idleCursor\", cookie);\n\t\t\t\tcursorShape(\"idle\");\n\t\t\t\treturn stat;\n\t\t\t} else if (findPattern(arg[1], \"mailto:\") != -1) {\n\t\t\t\tstat = send(\"mvw.delegationHandler\", \n\t\t\t\t\t\t\"doMailTo\", normURL);\n\t\t\t\tsendToInterface(\"idleCursor\", cookie);\n\t\t\t\tcursorShape(\"idle\");\n\t\t\t\treturn stat;\n\t\t\t}\n\n\t\t\tanchor = parseHTTPAddress(\"anchor\", normURL);\n\n\t\t\tif (exist(pageObj) == 1) send(pageObj, \"undisplay\");\n\n\t\t\tif (exist(docName) == 1) {\n\t\t\t\tset(\"children\", docName);\n\t\t\t\tif (anchor != \"\")  {\n\t\t\t\t\tpageYPos = send(docName, \n\t\t\t\t\t\t\"gotoAnchor\", anchor) * -1;\n\t\t\t\t\tsend(docName, \"y\", pageYPos);\n\t\t\t\t} else {\n\t\t\t\t\tpageYPos = send(docName, \"yP\");\n\t\t\t\t}\n\t\t\t\tif (send(docName, \"configSideBar\") == 1) {\n\t\t\t\t\tsend(parent(), \"linkSideBar\", \n\t\t\t\t  sideBarURL, sideBarRatio, sideBarMaxWidth);\n\t\t\t\t} else {\n\t\t\t\t\tsend(parent(), \"lbarConfig\", \"off\");\n\t\t\t\t}\n\t\t\t\tsend(docName, \"display\", width(), height());\n\n\t\t\t\tsend(docName, \"raise\");/*necessary?*/\n\t\t\t} else {\n\t\t\t\t/* a rough guess at the document type */\n\t\t\t\thandler = wwwFormatDetect(\"type\", docURL);\n\t\t\t\tdocObj = send(\"wwwHandlerDispatch\", \n\t\t\t\t\t\"dispatch\", handler, doPost, docURL, \n\t\t\t\t\tdocName, self(), get(\"width\"), get(\"height\"),\n\t\t\t\t\tanchor, 1, postData);\n\n\t\t\t\t/* XXX kludgy stylesheet turn off */\n\t\t\t\tSTG_clean(0);\n\n\t\t\t\tcursorShape(\"idle\");\n\t\t\t\tif (docObj == 0) {\n\t\t\t\t\tsendToInterface(\"warningDialog\",\n\t\t\t\t\t\tcookie, concat(\"Failed to access\\n\", docURL));\n\t\t\t\t\tsendToInterface(\"idleCursor\", cookie);\n\t\t\t\t\tcursorShape(\"idle\");\n\t\t\t\t\treturn 0;\n\t\t\t\t} else if (docObj == 1) {\n\t\t\t\t\t/* It's OK.. no doc object generated\n\t\t\t\t\t * but wasn't an error (ie: to be \n\t\t\t\t\t * rendered by external viewer)\n\t\t\t\t\t */\n\t\t\t\t\tcursorShape(\"idle\");\n\t\t\t\t\treturn 0;\n\t\t\t\t}\n\n\t\t\t\tif (send(docName, \"configSideBar\") == 1) {\n\t\t\t\t\tsend(parent(), \"linkSideBar\", \n\t\t\t\t  sideBarURL, sideBarRatio, sideBarMaxWidth);\n\t\t\t\t} else {\n\t\t\t\t\tsend(parent(), \"lbarConfig\", \"off\");\n\t\t\t\t}\n\n\t\t\t\tif (insertObjCount > 0) {\n\t\t\t\t\tfor (i = 0; i < insertObjCount; i++)\n\t\t\t\t\t\tsend(insertObj[i], \"insert\");\n\t\t\t\t\tinsertObjCount = 0;\n\t\t\t\t\tsend(self(), \"R\", \n\t\t\t\t\t\tget(\"y\"),get(\"width\"));\n\t\t\t\t}\n\t\t\t\tsend(docName, \"display\", \n\t\t\t\t\tget(\"width\"), get(\"height\"));\n\t\t\t\tsend(docName, \"show\");\n\t\t\t\tpageYPos = send(docName, \"yP\");\n\t\t\t}\n\t\t\too = object(docName);\n\t\t\tif (oldDocName != docName) {\n\t\t\t\tif (pageObj) {\n\t\t\t\t\tsend(pageObj, \"VW_event\", \"VIEW_OFF\");\n\t\t\t\t}\n\t\t\t\tpageObj = oo;\n\t\t\t\tsend(pageObj, \"VW_event\", \"VIEW_ON\");\n\t\t\t} else {\n\t\t\t\tpageObj = oo;\n\t\t\t}\n\n\t\t\tpageHeight = send(pageObj, \"vspan\");\n\t\t\tsend(self(), \"configShare\");\n\t\t}\n\t\tif (docObj != 0) {\n\t\t\ttitle = send(pageObj, \"queryTitle\");\n\t\t\tif (isBlank(title)) title = pageObj;\n\n\t\t\tmvw.doc.title(\"show\", title);\n\t\t\tmvw.doc.url(\"show\", docURL);\n\n\t\t\tif (arg[0] == \"show\") {\n\t\t\t  if (isBlank(title))\n\t\t\t\tsendToInterface(\"newDocument\", cookie, docURL);\n\t\t\t  else\n\t\t\t\tsendToInterface(\"newDocument\", cookie, docURL, title);\n\t\t\t} else { /* arg[0] == \"showHistoryDoc\" */\n\t\t\t    if (isBlank(title))\n\t\t\t    \tsendToInterface(\"historyDocument\", cookie, docURL);\n\t\t\t    else\n\t\t\t    \tsendToInterface(\"historyDocument\", cookie, docURL, title);\n\t\t\t}\n\t\t\tsendToInterface(\"sliderConfig\", cookie, sliderPos, sliderSize);\n\t\t\n\t\t\tindexP = send(pageObj, \"queryIsIndex\");\n\t\t\tif (indexP == 0) {\n\t\t\t\tsendToInterface(\"searchOff\", cookie);\n\t\t\t} else {\n\t\t\t\t/* plain ISINDEX, or ISINDEX ACTION=...*/\n\t\t\t\tsendToInterface(\"searchOn\", cookie);\n\t\t\t}\n\t\t\t\n\t\t}\n\t\tsendToInterface(\"idleCursor\", cookie);\n\t\tcursorShape(\"idle\");\n\t\treturn docName;\n\tbreak;\n\tcase \"toDoInsert\":\n\t\tinsertObj[insertObjCount] = arg[1];\n\t\tinsertObjCount++;\n\t\treturn;\n\tbreak;\n\tcase \"show_request_by_child\":\n\tcase \"post_request_by_child\":\n\t\tif (arg[0] == \"post_request_by_child\") realMesg = \"post\";\n\t\telse realMesg = \"show\";\n\n\t\tif (torn == 1) destObj = self();\n\t\telse destObj = object(\"mvw\");\n\n\t\tif (arg[] == 3) stat = send(destObj, realMesg, arg[1], arg[2]);\n\t\telse stat = send(destObj, realMesg, arg[1], arg[2], arg[3]);\n\t\treturn stat;\n\tbreak;\n\tcase \"hintOn\":\n\tcase \"hintOff\":\n\t\treturn;\n\tbreak;\n\tcase \"setChildren\":\n\t\tset(\"children\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"configShare\":\n\t\theightDiff = pageHeight - get(\"height\");\n\t\theightRatio =  float(heightDiff) / -100.0;\n\t\t/* not working right... should maintain proportional offset */\n\t\tif (heightDiff > 0) {\n\t\t\tsliderSize = float(height()) / float(pageHeight) * 100;\n\t\t\tsliderPos = float(pageYPos) / float(heightDiff) * -100;\n\t\t} else {\n\t\t\tsliderSize = 100;\n\t\t\tsliderPos = 0;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"configSlider\":\n\t\t/* arg[1]\tpageYPos\n\t\t * arg[2]\tpageHeight\n\t\t */\n\t\tpageYPos = arg[1];\n\t\tpageHeight = arg[2];\n\t\tif (pageYPos + pageHeight < get(\"height\")) {\n\t\t\tpageYPos = get(\"height\") - pageHeight;\n\t\t\tif (pageYPos > 0) pageYPos = 0;\n\t\t\tsend(pageObj, \"y\", pageYPos);\n\t\t}\n\t\tsend(self(), \"configShare\");\n\t\tsendToInterface(\"sliderConfig\", cookie, sliderPos, sliderSize);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tusual();\n\t\tif (send(pageObj, \"viewP\") == 1) {\n\t\t\t/* when switching from a sidebar'ed document to\n\t\t\t * a non-sidebar document, this object will be\n\t\t\t * 'configed' (and before the new document gets\n\t\t\t * configed... so we don't want to bother \n\t\t\t * that document (pageObj) until it is ready\n\t\t\t * (when viewP == 1).\n\t\t\t */\n\t\t\t/* ask page object to do the calculation */\n\t\t\tsend(pageObj, \"resize\", get(\"width\"), get(\"height\"));\n\t\t\tpageYPos = send(pageObj, \"yP\");\n\t\t\tpageHeight = send(pageObj, \"vspan\");\n\t\t\tif (pageYPos + pageHeight < get(\"height\")) {\n\t\t\t\tpageYPos = get(\"height\") - pageHeight;\n\t\t\t\tsend(pageObj, \"y\", pageYPos);\n\t\t\t}\n\t\t\tsend(self(), \"configShare\");\n\t\t}\n\t\t/* this call should not be necessary... what was it for? */\n\t\t/*objectListSend(\"shownDepend\", \"kludgeRender\");*/\n\n\t\tconfiged = 1;\n\n\t\t/*XXX a bit tweetchy??????? */\n\t\tsendToInterface(\"sliderConfig\", cookie, sliderPos, sliderSize);\n\t\tif (hasConfiged == 0) {\n\t\t\thasConfiged = 1;\n\t\t\tif (docToRenderAfterConfigure) {\n\t\t\t\tstat = send(self(), \"show\", \n\t\t\t\t\tdocToRenderAfterConfigure);\n\t\t\t\tif (stat) send(self(), \"historyRecord\");\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"update\":\n\t\tpageObj = nthChild(0);\n\t\tpageHeight = arg[1];\n\t\theightDiff = pageHeight - get(\"height\");\n\t\theightRatio =  float(heightDiff) / -100.0;\n\t\tif (heightDiff > 0) h = arg[1];\n\t\telse h = get(\"height\");\n\t\treturn h;\n\tbreak;\n\tcase \"destroyDoc\":\n\tcase \"destroyDoc_qualified\":\n\t\tsend(pageObj, \"freeSelf\");\n\t\tpageObj = 0;\n\t\treturn;\n\tbreak;\n\tcase \"addTool\":\n\tcase \"addTool_sticky\":\n\tcase \"removeTool\":\n\tcase \"destroyTool\":\n\t\treturn send(parent(), arg[0], arg[1]);\n\tbreak;\n\tcase \"search\":\n\t\treturn send(pageObj, \"search\", arg[1]);\n\tbreak;\n\tcase \"outputSGML\":\n\t\treturn send(pageObj, \"outputSGML\");\n\tbreak;\n\tcase \"mailToAuthor\":\n\t\tcontactURL = send(pageObj, \"queryAuthor\");\n\t\tif (contactURL) {\n\t\t\tres.dialogWithButtons(\"show\", \n\t\t\t concat(\"The declared author contact is:\\n\", \n\t\t\t\tcontactURL),\n\t\t\t \"Dismiss\", \"\");\n\t\t} else {\n\t\t\tres.dialogWithButtons(\"show\", \n\t\t\t \"Sorry, no author contact declared in the document.\",\n\t\t\t \"Dismiss\", \"\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"linkSideBar\":\n\t\tsideBarURL = arg[1];\n\t\tsideBarRatio = arg[2];\n\t\tsideBarMaxWidth = arg[3];\n\t\treturn;\n\tbreak;\n\tcase \"reload\":\n\t\t/* is a problem if reloading 'URL#anchor' ? */\n\t\tsendToInterface(\"sliderConfig\", cookie, 0, sliderSize);\n\t\treturn send(pageObj, \"reload\");\n\tbreak;\n\tcase \"whichPageP\":\n\t\treturn nthChild(0);\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"expose\":\n\t\tif (todo) {\n\t\t\thomeDoc = mvw(\"homeDocP\");\n\t\t\tmvw(\"show\", homeDoc);\n\t\t\ttodo = 0;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"reportNextID\":\n\tcase 'R':\n\t\treturn;\n\tbreak;\n\tcase \"historyRecord\":\n\t\tsend(pageObj, \"historyRecord\");\n\t\treturn;\n\tbreak;\n\tcase \"showSource\":\n\t\t/* return temporary file */\n\t\tsendToInterface(\"showSourceFile\", cookie, \n\t\t\t\tHTTPGet(docURL), \"editable\"); \n\t\treturn;\n\tbreak;\n\tcase \"saveAs\":\n\t\t/* return temporary file */\n\t\tsendToInterface(\"saveAs\", cookie, HTTPGet(docURL), arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"getCurrentDocURL\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"getCurrentDocTitle\":\n\t\treturn title;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\ttodo = 0;\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\tcookie = arg[2];\n\t\ttorn = 1;\n\t\tsend(nthChild(0), \"torn\", arg[1]);\n\t\tpageObj = nthChild(0);\n\t\t/* make self reset variables */\n\t\tsend(self(), \"update\", send(pageObj, \"vspan\"));\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_mvw189[] = "595";
static char _slotValue_mvw190[] = "400";
/* END OF OBJ */

static char _slotValue_mvw192[] = "mvw.delegationHandler";
static char _slotValue_mvw193[] = "generic";
static char _slotValue_mvw194[] = "\n\tswitch (arg[0]) {\n\tcase \"doTelnet\":\n\t\t/* arg[1]\tnormalized URL\n\t\t */\n\t\tcmd = send(\"WWWTelnetHandler\", \"connect\", arg[1]);\n\t\tsystem(cmd);\n\t\treturn 1;\n\tbreak;\n\tcase \"doMailTo\":\n\t\t/* arg[1]\tnormalized URL\n\t\t */\n\t\tsubject = concat(\"WWW mail from: \", arg[1]);\n\t\ttt = arg[1];\n\t\ti = findPattern(tt, \"/\");\n\t\tif (i == -1) {\n\t\t\taddress = nthChar(tt, 7, 999);\n\t\t\tcontent = concat(\"This mail was generated by URL:\\n\",\n\t\t\t\t\t tt, \"\\n\");\n\t\t} else {\n\t\t\taddress = nthChar(tt, 7, i-1);\n\t\t\tcontent = concat(nthChar(tt, i+1, 999), \"\\n\");\n\t\t}\n\t\ttmpFile = makeTempFile();\n\t\tsaveFile(tmpFile, content);\n\n\t\tcmd = concat(\"mail -s \\\"\", subject,\n\t\t\t\t \"\\\" \", address, \" < \", tmpFile);\n\t\tsystem(cmd);\n\t\tsystem(concat(\"rm \", tmpFile));\n\t\treturn 1;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_mvw196[] = "generic";
static char _slotValue_mvw197[] = "www.mesg.tf";
static char _slotValue_mvw198[] = "\n\tswitch (arg[0]) {\n\tcase \"clear\":\n\t\tif (isCleared == 0) {\n\t\t\tactiveHelp();\n\t\t\tisCleared = 1;\n\t\t}\n/*XXX many needless operations*/\n\t\tsend(\"mvw.doc.tools.httpStat.icon\", \"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"show\":\n\tcase \"flash\":\n\tcase \"suggest\":\n\t\tisCleared = 0;\n\t\treturn activeHelp(arg[1]);\n\tbreak;\n\tcase \"show_progress\":\n\t\t/* arg[1]\tpercent\n\t\t * arg[2]\tbytes so far\n\t\t */\n\t\tactiveHelp(concat(\"Retrieved \", arg[2], \" bytes, \", \n\t\t\t\t  arg[1], \"%\"));\n\t\tsend(\"mvw.doc.tools.httpStat.icon\", \"stat\", arg[1]);\n\t\tisCleared = 0;\n\t\treturn;\n\tbreak;\n\tcase \"alert\":\n\tcase \"warn\":\n\tcase \"error\":\n\t\tisCleared = 0;\n\t\tsendToInterface(\"modalErrorDialog\",\n\t\t\t\t0, /* may be on top of the wrong shell--\n\t\t\t\t    * now always go on main shell */\n\t\t\t\targ[1]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_mvwHistory2[] = "\n\tswitch (arg[0]) {\n\tcase \"prev\":\n\t\tif (index > 0) {\n\t\t\tindex--;\n\t\t\treturn docAddr[index];\n\t\t} else {\n\t\t\tbell();\n\t\t\treturn \"\";\n\t\t}\n\tbreak;\n\tcase \"next\":\n\t\tif (index < count - 1) {\n\t\t\tindex++;\n\t\t\treturn docAddr[index];\n\t\t} else {\n\t\t\tbell();\n\t\t\treturn \"\";\n\t\t}\n\tbreak;\n\tcase \"add\":\n\t\tindex = count;\n/*\nprint(\"HISTORY add: arg[1] {\", arg[1], \"}++++++++++++++++++++++++++\\n\");\nprint(\"             arg[2] {\", arg[2], \"}++++++++++++++++++++++++++\\n\");\n*/\n\t\tif (isBlank(arg[1]) == 1) {\n\t\t\tdocTitle[count] = \"no title\";\n\t\t} else {\n\t\t\t/* make sure we're storing string representation,\n\t\t\t * rather than possibly object pointer which can\n\t\t\t * get us into trouble if that object is destroyed\n\t\t\t * and we reference it.\n\t\t\t */\n\t\t\tdocTitle[index] = str(arg[1]);\n\t\t}\n\t\tdocAddr[index] = arg[2];\n\t\tcount++;\n\t\tvictimIdx = count - killLatency;\n\t\tif (victimIdx >= 0) {\n\t\t\tvictim = docAddr[victimIdx];\n\t\t\tif (victim != arg[2]) {\n/*print(\"KILLING idx=\", victimIdx,\"{\", victim, \"}\\n\");*/\n\t\t\t\tsend(victim, \"visible\", 0);\n\t\t\t\tsend(victim, \"freeSelf\");\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"historyList_selectedItem\":\n\t\tindex = arg[1];\n\t\treturn;\n     \tbreak;\n\tcase \"back\":\n\t\t/* delete last line */\n\t\tif (count > 1) {\n\t\t\tmvw(\"destroyDoc\", docAddr[index]);\n\t\t\tcount--;\n\t\t\t/* move index only if at bottom of history list */\n\t\t\tif (index >= count) index--;\n\t\t\treturn docAddr[index];\n\t\t} else {\n\t\t\treturn docAddr[0];\n\t\t}\n\tbreak;\n\tcase \"dump\":\n\t\tfor (i = 0; i < count; i++)\n\t\t\tprint(\"[\", i, \"]\\t docTitle={\", docTitle[i], \"}\",\n\t\t\t\t\"\\tdocAddr={\", docAddr[i], \"}\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tindex = -1;\n\t\tcount = 0;\n\t\tkillLatency = 4;\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML__box3[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tinsertObj\n\t\t * arg[2]\twidth to use\n\t\t * arg[3]\theight to use\n\t\t */\n\t\tset(\"width\", arg[2]);\n\t\tset(\"height\", arg[3]);\n\t\tobjectListAppend_children(arg[1]);\n\t\treturn self();\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__box4[] = "100";
static char _slotValue_HTML__box5[] = "8";
static char _slotValue_HTML__box6[] = "blue";
static char _slotValue_HTML__box7[] = "red";
/* END OF OBJ */

static char _slotValue_HTML__box9[] = "field";
static char _slotValue_HTML__box10[] = "HTML__txtBox";
static char _slotValue_HTML__box11[] = "HTML__txtBox.icon";
static char _slotValue_HTML__box12[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML__doc2[] = "\n/*\nprint(\"HTML__doc: self=\", self(), \": \");\nfor (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");print(\"...end\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\tif (viewP == 0) return;\n\t\tusual();\n\t\tif (isHTML) render();\n\t\treturn;\n\tbreak;\n\tcase \"shownPositionV\":\n\t\tif (isHTML) return set(\"y\", arg[1] * heightRatio);\n\t\telse return set(\"shownPositionV\", arg[1]);\n\tbreak;\n\tcase \"inAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"scrollPageUp\":\n\t\tif (isHTML) {\n\t\t\ty = get(\"y\") - parentHeight;\n\t\t\tif (y < parentHeight - get(\"height\"))\n\t\t\t\ty = parentHeight - get(\"height\");\n\t\t\tset(\"y\", y);\n\t\t} else {\n\t\t\t/* not yet implemented */\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"scrollPageDown\":\n\t\tif (isHTML) {\n\t\t\ty = get(\"y\") + parentHeight;\n\t\t\tif (y > 0) y = 0;\n\t\t\tset(\"y\", y);\n\t\t} else {\n\t\t\t/* not yet implemented */\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"F\": /* flush */\n\t\th = 0;\n\t\tsend(self(), \"setStyles\");\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\th = get(\"height\");\n\t\tsend(self(), \"setStyles\");\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(), \n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\n\t\t/* IMPORTANT KLUDGE: this is how this object knows whether \n\t\t * to behave like a single textfield (for ascii only text),\n\t\t * or as container (for compound HTML objects).\n\t\t */\n\t\tset(\"height\", h);\n/*after(1000, \"www\", \"editMode\", 1);*/\n\t\treturn h;\n\tbreak;\n\tcase \"data\":\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn 0;\n\tbreak;\n\tcase 'T':\n\t\t/* arg[1] = y\n\t\t * arg[2] = width\n\t\t *\n\t\t * put this check here rather than \"D\" since it may \"D\" time\n\t\t * may not occur.\n\t\t */\n\t\tif (objectListCount(\"children\") > 0) {\n\t\t\tisHTML = 1;\n\t\t\th = get(\"height\");\n\t\t\tparentHeight = send(parent(), \"heightP\");\n\t\t\theightDiff = h - parentHeight;\n\t\t\tif (heightDiff > 0) {\n\t\t\t\theightRatio = float(heightDiff) / -100.0;\n\t\t\t} else {\n\t\t\t\theightRatio = 0;\n\t\t\t\th = parentHeight;\n\t\t\t}\n\t\t\tset(\"height\", h);\n\t\t\tprevHeight = h;\n\t\t} else {\n\t\t\tprevHeight = get(\"height\");\n\t\t\th = building_vspan();\n\t\t}\n\t\tvspan = h;\n\t\tprevWidth = arg[2];\n\t\treturn vspan;\n\tbreak;\n\tcase \"nameAndURL\":\n\t\tdocName = arg[1];\n\t\tdocURL = arg[2];\n\t\treturn;\t\t\n\tbreak;\n\tcase \"setAnchor\":\n\t\tmakeAnchor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"query_docName\":\n\t\treturn docName;\n\tbreak;\n\tcase \"query_docURL\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tn = countChildren();\n\t\tif (n > 0) \n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return 0; /* special case */\n\t\tn = countChildren();\n\t\tif (n > 0)\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i),\n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset;\n\t\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"follow_href\":\n\t\treturn send(parent(), \"show_request_by_child\", arg[1], docURL);\n\tbreak;\n\tcase \"post_href_n_data\":\n\t\treturn send(parent(), \"post_request_by_child\", arg[1], docURL,\n\t\t\t\t\t\t\targ[2]);\n\tbreak;\n\tcase \"hintOn\":\n\t\treturn send(parent(), \"hintOn\", arg[1]);\n\tbreak;\n\tcase \"hintOff\":\n\t\treturn send(parent(), \"hintOff\");\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tset(\"y\", 0);\n\t\tsend(self(), \"resize\", arg[2], send(parent(), \"heightP\")); \n\t\treturn h;\n\tbreak;\n\tcase \"resize\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (..)\n\t\t * Note: prevWidth & prevHeight also refers to viewer sizes\n\t\t */\n\t\tset(\"width\", arg[1]);\n\t\tif (isHTML) {\n\t\t\tn = countChildren();\n\t\t\tif (n) {\n\t\t\t\txx = arg[1] - 5;\n\t\t\t\th = 0;\n\t\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\t\th += send(nthChild(i), \"R\", h, xx);\n\t\t\t\tvspan = h;\n\t\t\t} else {\n\t\t\t\tvspan = 1;\n\t\t\t}\n\t\t\tparentHeight = send(parent(), \"heightP\");\n\t\t\tif (vspan < parentHeight) vspan = parentHeight;\n\n\t\t\theightDiff = vspan - parentHeight;\n\t\t\tif (heightDiff > 0) {\n\t\t\t\theightRatio = float(heightDiff) / -100.0;\n\t\t\t} else {\n\t\t\t\theightRatio = 0;\n\t\t\t\tvspan = parentHeight;\n\t\t\t}\n\t\t\tset(\"height\", vspan);\n\t\t} else {\n\t\t\tset(\"height\", arg[2]);\n\t\t\tset(\"content\", get(\"content\"));\n\t\t\trender();\n\t\t\tvspan = building_vspan();\n\t\t}\n\t\tprevWidth = arg[1];\n\t\tprevHeight = arg[2];\n\t\treturn;\n\tbreak;\n\tcase \"resizeSelf\":\n\t\tsend(self(), \"resize\", \n\t\t\tget(\"width\"), send(parent(), \"heightP\"));\n\t\tsend(parent(), \"configSlider\", get(\"y\"), get(\"height\"));\n\t\treturn;\n\tbreak;\n\tcase \"VIEW_ON\":\n\t\tfor (i = 0; i < toolsCount; i++) send(tools[i], \"visible\", 1);\n\t\treturn;\n\tbreak;\n\tcase \"display\":\n\t\t/* arg[1]\twidth (of viewer window)\n\t\t * arg[2]\theight (of viewer window)\n\t\t */\n\t\tviewP = 1;\n\t\tsend(self(), \"resize\", arg[1], arg[2]);\n\t\tset(\"visible\", 1);\n\t\tif (get(\"window\")) raise();\n\n\t\tdeepObjectListSend(\"children\", \"visible\", 1);\n\n\t\tfor (i = 0; i < toolsCount; i++) {\n\t\t\tsend(get(\"parent\"), \"addTool\", tools[i]);\n\t\t\tsend(tools[i], \"visible\", 1);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"undisplay\":\n\t\tviewP = 0;\n\t\treturn;\n\tbreak;\n\tcase \"viewP\":\n\t\treturn viewP;\n\tbreak;\n\tcase \"configSelf\":\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn self();\n\tbreak;\n\tcase \"placeID\":\n\t\t/* this is clumsy. should be simplified with a primitive f() */\n\t\t/* find the caller (child) object's place in the obj list */\n\t\tcobj = arg[1];\n\t\tobjPlace = -1;\n\t\tfor (i = objectListCount_children() - 1; i >= 0; i--) {\n\t\t\tprint(\"##/// i=\", i, \"  cobj=\",  cobj, \n\t\t\t\t\"  nc=\", nthChild(i), \"\\n\");\n\t\t\tnobj = nthChild(i);\n\t\t\tif (cobj == nobj) {\n\t\t\t\tobjPlace = i;\n\t\t\t\tprint(\"#### objPlace = \",  i, \"\\n\");\n\t\t\t}\n\t\t}\n\t\tobjPlacePath = concat(objPlace, \" \", arg[2]);\n\t\tprint(\"#### objPlacePath = {\",  objPlacePath, \"}\\n\");\n\t\treturn objPlacePath;\n\tbreak;\n\tcase \"change\":\n/*\nprint(\"!!############ obj = \",  arg[1], \"\\n\");\nprint(\"!!############ objPlacePath = {\",  arg[2], \"}\\n\");\nprint(\"!!############ new data = {\",  arg[3], \"}\\n\");\n*/\n\t\tobjPlacePath = arg[2];\n\t\tnewData = arg[3];\n\n\t\tcpa = nthWord(objPlacePath, 1);\n/*print(\"!!############ childPosToAffect = {\",  cpa, \"}\\n\");*/\n\t\tnewObjPlacePath = nthWord(objPlacePath, 2, 99);\n/*print(\"!!############ new objPlacePath = {\", newObjPlacePath, \"}\\n\");*/\n\n\t\tsend(nthChild(cpa), \"change\", newObjPlacePath, newData);\n\t\tsend(\"www_com\", \"output_change\", objPlacePath, newData);\n\n\t\treturn;\n\tbreak;\n\tcase \"wedge_before\":\n\t\t/* arg[1]\tchild \n\t\t * arg[2]\tobj to insert after child\n\t\t */\n\t\tobjN = arg[1];\n\t\tobjN1 = arg[2];\n\n\t\tooi = 0;\n\t\tn = countChildren();\n\t\tfor (i = 0; i < n; i++) {\n\t\t\tco = nthChild(i);\n\t\t\tif (co == objN) {\n\t\t\t\too[ooi] = objN1;\n\t\t\t\tooi++;\n\t\t\t}\n\t\t\too[ooi] = co;\n\t\t\tooi++;\n\t\t}\n\t\tfor (i = ooi - 1; i >= 0; i--)\n\t\t\tobjectListDelete_children(oo[i]);\n\t\tfor (i = ooi - 1; i >= 0; i--)\n\t\t\tobjectListPrepend_children(oo[i]);\n\t\treturn;\n\tbreak;\n\tcase \"wedge_after\":\n\t\t/* arg[1]\tchild \n\t\t * arg[2]\tobj to insert after child\n\t\t */\n\t\tobjN = arg[1];\n\t\tobjN1 = arg[2];\n\n\t\tooi = 0;\n\t\tn = countChildren();\n\t\tfor (i = 0; i < n; i++) {\n\t\t\tco = nthChild(i);\n\t\t\too[ooi] = co;\n\t\t\tooi++;\n\t\t\tif (co == objN) {\n\t\t\t\too[ooi] = objN1;\n\t\t\t\tooi++;\n\t\t\t}\n\t\t}\n\t\tprint(\"old children list: \", get(\"children\"), \"\\n\");\n\t\t/* IDIOTIC WAY TO DELETE LIST */\n\t\t/*set(\"children\", \"\");*/\n\t\tfor (i = ooi - 1; i >= 0; i--) {\n\t\t\tprint(\"delete OBJ from children list\", oo[i], \"\\n\");\n\t\t\tobjectListDelete_children(oo[i]);\n\t\t}\n\t\t/* re set list in right order */\n\t\tfor (i = ooi - 1; i >= 0; i--) {\n\t\t\tobjectListPrepend_children(oo[i]);\n\t\t}\n\t\tprint(\"new children list: \", get(\"children\"), \"\\n\");\n\t\tinfo();\n\t\treturn;\n\tbreak;\n\tcase \"deleteChild\":\n\t\treturn objectListDelete_children(arg[1]);\n\tbreak;\n\tcase \"wedgeMeIn\":\n\t\t/* arg[1]\tobject to wedge in\n\t\t * arg[2]\tside (0=upper, 1=lower)\n\t\t */\n\t\tif (selectedObj) {\n\t\t\tprint(\"#### selected Obj = \",  selectedObj, \"\\n\");\n\t\t\tprint(\"#### to wedge into Obj = \",  arg[1], \"\\n\");\n\t\t\tsend(selectedObj, \"runAwayFromHome\");\n\t\t\tif (arg[2] == 0) {\n\t\t\t\tprint(\"#### upper side (wedge before)\\n\");\n\t\t\t\tsend(self(), \"wedge_before\", \n\t\t\t\t\targ[1], selectedObj);\n\t\t\t} else {\n\t\t\t\tprint(\"#### lower side (wedge after)\\n\");\n\t\t\t\tsend(self(), \"wedge_after\", \n\t\t\t\t\targ[1], selectedObj);\n\t\t\t}\n\t\t\tselectedObj = 0;\n\t\t\tsend(self(), \"resizeSelf\");\n\t\t} else {\n\t\t\tselectedObj = arg[1];\n\t\t\tprint(\"#### selected Obj = \",  selectedObj, \"\\n\");\n\t\t}\n\t\treturn;\n\tbreak;\n\n\tcase \"CE_change\":\n\t\t/* arg[1] \tCE objPath\n\t\t * arg[2]\tCE newData\n\t\t */\n\t\tobjPlacePath = arg[1];\n\t\tcpa = nthWord(objPlacePath, 1);\n\t\tnewObjPlacePath = nthWord(objPlacePath, 2, 99);\n/*\nprint(\"!!!!!!!!!!############ objPlacePath = {\", objPlacePath, \"}\\n\");\nprint(\"!!!!!!!!!!############ childPosToAffect = {\",  cpa, \"}\\n\");\nprint(\"!!!!!!!!!!############ new objPlacePath = {\", newObjPlacePath, \"}\\n\");\nprint(\"!!!!!!!!!!############ data = {\", arg[2], \"}\\n\");\n*/\n\t\tsend(nthChild(cpa), \"CE_change\", newObjPlacePath, arg[2]);\n\t\treturn;\n\tbreak;\n\tcase \"lock\":\n/*\nprint(\"!!############ obj = \",  arg[1], \"\\n\");\nprint(\"!!############ objPlacePath = {\",  arg[2], \"}\\n\");\n*/\n\t\tobjPlacePath = arg[2];\n\t\tsend(\"www_com\", \"output_lock\", objPlacePath);\n\t\treturn;\n\tbreak;\n\tcase \"unlock\":\n/*\nprint(\"!!############ obj = \",  arg[1], \"\\n\");\nprint(\"!!############ objPlacePath = {\",  arg[2], \"}\\n\");\n*/\n\t\tobjPlacePath = arg[2];\n\t\tsend(\"www_com\", \"output_unlock\", objPlacePath);\n\t\treturn;\n\tbreak;\n\tcase \"CE_lock\":\n\tcase \"CE_unlock\":\n\t\t/* arg[1] \tCE objPath\n\t\t */\n\t\tobjPlacePath = arg[1];\n\t\tcpa = nthWord(objPlacePath, 1);\n\t\tnewObjPlacePath = nthWord(objPlacePath, 2, 99);\n\t\tsend(nthChild(cpa), arg[0], newObjPlacePath);\n\t\treturn;\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"reportTitle\":\n\t\tdocTitle = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"yP\":\n\t\treturn get(\"y\");\n\tbreak;\n\tcase \"y\":\n\t\treturn set(\"y\", arg[1]);\n\tbreak;\n\tcase \"vspan\":\n\t\tif (isHTML) return get(\"height\");\n\t\treturn vspan;\n\tbreak;\n\tcase \"reload\":\n\t\tset(\"name\", \"dunsel\");\n\t\tfor (i = 0; i < toolsCount; i++)\n\t\t\tsend(parent(), \"destroyTool\", tools[i]);\n\t\tsend(\"www\", \"show\", docURL);\n\t\tafter(10000, self(), \"visible\", 0);\n\t\tafter(10001, self(), \"freeSelf\");\n\t\treturn 0;\n\tbreak;\n\tcase \"compact\": /* just to handle bad HTML... */\n\tcase \"L\": /*...*/\n\t\t/* should signal detection of bad HTML */\n\t\treturn 0;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"show\":\n\t\tset(\"visible\", 1);\n\t\trender();\n\t\tif (get(\"window\")) raise();\n\n\t\tfor (i = 0; i < toolsCount; i++) send(tools[i], \"visible\", 1);\n\n\t\trelay_obj[relayIdx] = self();\n\t\trelay_event[relayIdx++] = \"VIEW_OFF\";\n\n\t\treturn;\n\tbreak;\n\tcase \"search\":\n\t\tif (isIndex == 0) {\n\t\t\t/* error cond, but do it anyway */ actionURL = docURL;\n\t\t} else if (isIndex == 1) {\n\t\t\tactionURL = docURL;\n\t\t} else {\n\t\t\tactionURL = isIndex;\n\t\t}\n\t\tcleanURL = send(\"parseHTTPAddress\", \"stripIndex\", actionURL);\n\t\treturn send(parent(), \"show_request_by_child\", \n\t\t\t\tconcat(cleanURL, '?', arg[1]), docURL);\n\tbreak;\n\tcase \"VIEW_OFF\":\n\t\tfor (i = 0; i < toolsCount; i++)\n\t\t\tsend(parent(), \"removeTool\", tools[i]);\n\t\treturn;\n\tbreak;\n\tcase \"blank\":\n\t\tset(\"visible\", 0);\n\t\tsend(self(), \"VIEW_OFF\");\n\t\treturn;\n\tbreak;\n\tcase \"queryAddress\":\n\t\treturn docURL;\n\tbreak;\n\tcase \"queryTitle\":\n\t\tif (docTitle) return docTitle;\n\t\treturn docName;\n\tbreak;\n\tcase \"isIndex\":\n\t\tisIndex = 1;\n\t\treturn;\n\tbreak;\n\tcase \"isIndexURL\":\n\t\tisIndex = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"queryIsIndex\":\n\t\treturn isIndex;\n\tbreak;\n\tcase \"historyRecord\":\n\t\tsend(\"www\", \"addToHistory\", docName, docURL);\n\t\treturn;\n\tbreak;\n\tcase \"toDoInsert\":\n\t\tsend(parent(), \"toDoInsert\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"torn\":\n\t\t/* Variable do not get cloned. So, set variables, \n\t\t * ie: parentHeight, hightDiff.. \n\t\t */\n\t\torig = arg[1];\n\n\t\tdocName = send(orig, \"query_docName\");\n\t\tdocURL = send(orig, \"query_docURL\");\n\n\t\tsend(self(), 'T', 0, get(\"width\")); \n\t\treturn;\n\tbreak;\n\tcase \"output2File\":\n\t\tsend(\"res.getLineEntry\", \"show\", \n\t\t\t\"Enter file name to save to document source to:\", \n\t\t\t\t\"/tmp/out.html\",\n\t\t\t\tself(), \"gotOutputFileName\");\n\t\treturn;\n \tbreak;\n\tcase \"gotOutputFileName\":\n\t\tsend(\"wwwSecurity\", \"getDocAndMoveItToSpecifiedPlace\",\n\t\t\t\tdocURL, arg[1]);\n\t\tsend(\"www.mesg.tf\", \"show\", \n\t\t\tconcat(\"Source saved to file: \", arg[1], \"\\n\"));\n\t\treturn;\n \tbreak;\n\tcase \"showSrc\":\n\t\twwwSrc(\"showByURL\", docURL);\n\t\treturn;\n \tbreak;\n\tcase \"reportAuthor\":\n\t\tauthor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"configSideBar\":\n\t\tif (sideBarURL != 0) {\n\t\t\tsend(parent(), \"linkSideBar\",\n\t\t\t\t sideBarURL, sideBarRatio, sideBarMaxWidth);\n\t\t\treturn 1;\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"linkSideBar\":\n\t\thasSideBarP = 1;\n\t\tsideBarURL = arg[1];\n\t\tsideBarRatio = arg[2];\n\t\tsideBarMaxWidth = arg[3];\n\t\treturn;\n\tbreak;\n\tcase \"queryAuthor\":\n\t\tif (author == \"\") return 0;\n\t\treturn author;\n\tbreak;\n\tcase \"editMode\":\n\t\teditMode = arg[1];\n\t\tprint(\"HTML__DOC: editMode=\", editMode, \"\\n\");\n\t\tn = countChildren();\n\t\tfor (i = 0; i < n; i++) {\n\t\t\tanchor = send(nthChild(i), \"editMode\", editMode);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"outlineSrc\":\n\t\tsend(\"www.mesg.tf\", \"show\", \n\t\t\t\"Outliner not available for HTML\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"print\":\n/*\n1 - the URL of those documents contain \";\" telling the shell that\nthe instruction ended. you have to go out of viola, and enclose\nit in quotation marks.\n*/\n\t\tsend(\"www.mesg.tf\", \"show\", \n\t\t    \"Printing facillity not available for HTML.\\n\");\n\t\treturn;\n \tbreak;\n\tcase \"freeSelf\":\n\t\t/* tools should be freed only when an object really is\n\t\t * going away, and when the doc object is named 'dunsel'\n\t\t * the doc is being reloaded.\n\t\t */\n/*\t\tif (self() != \"dunsel\")\n\t\t\tfor (i = 0; i < toolsCount; i++)\n\t\t\t\tsend(tools[i], \"freeSelf\");\n*/\n\t\tfreeSelf();\n\t\treturn;\n\tbreak;\n\tcase \"VW_relay\":\n\t\trelay_obj[relayIdx] = arg[1];\n\t\trelay_event[relayIdx++] = arg[2];\n\t\treturn 1;\n\tbreak;\n\tcase \"VW_event\":\n\t\tevent = arg[1];\n\t\tfor (i = 0; i < relayIdx; i++)\n\t\t\tif (relay_event[i] == event) send(relay_obj[i], event);\n\t\treturn;\n\tbreak;\n\tcase \"addTool\":\n\t\ttools[toolsCount] = arg[1];\n\t\ttoolsCount++;\n\t\treturn;\n\tbreak;\n\tcase \"addTool_sticky\":\n\t\treturn send(parent(), \"addTool\", arg[1]);\n\tbreak;\n\tcase \"setStyles\":\n\t\ttagPtr = STG_tagPtr(\"BODY\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"fontSlant\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<HTML>\\n\");\n\t\tn = countChildren();\n\t\tif (n) for (i = 0; i < n; i++)\n\t\t\t\tsend(nthChild(i), \"outputSGML\");\n\t\tprint(\"</HTML>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n/*\\width {590}*/\n/*\\height {200}*/\n";
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
static char _slotValue_HTML__foldIcon2[] = "\n\tswitch (arg[0]) {\n\t/* terrible hack */\n\tcase \"folderOpenXBM\":\n\t\treturn \"#define folderOpen_width 16\n#define folderOpen_height 16\nstatic char folderOpen_bits[] = {\n   0x00, 0x00, 0x00, 0x78, 0xf0, 0x87, 0x08, 0x80, 0x08, 0x80, 0xfc, 0x87,\n   0x02, 0x88, 0x02, 0x88, 0x04, 0x90, 0x04, 0x90, 0x08, 0xa0, 0x08, 0xa0,\n   0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\";\n\tbreak;\n\tcase \"folderClosedXBM\":\n\t\treturn \"#define folderClosed_width 16\n#define folderClosed_height 16\nstatic char folderClosed_bits[] = {\n   0x00, 0x00, 0x00, 0x78, 0xf0, 0x87, 0x08, 0x80, 0xf8, 0xbf, 0x04, 0xa0,\n   0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xa0, 0x04, 0xc0,\n   0xf8, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\";\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tfolded = send(parent(), \"toggleFolded\");\n\t\tif (folded)\n\t\t\tset(\"label\", send(\"HTML__foldIcon\", \"folderClosedXBM\"));\n\t\telse\n\t\t\tset(\"label\", send(\"HTML__foldIcon\", \"folderOpenXBM\"));\n\t\trender();\n\tbreak;\n\tcase \"setFolded\":\n\t\tfolded = arg[1];\n\t\tif (folded)\n\t\t\tset(\"label\", send(\"HTML__foldIcon\", \"folderClosedXBM\"));\n\t\telse\n\t\t\tset(\"label\", send(\"HTML__foldIcon\", \"folderOpenXBM\"));\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\treturn send(clone(cloneID()), \"parent\", arg[1]);\n\tbreak;\n\tcase \"parent\":\n\t\tset(\"parent\", arg[1]);\n\t\treturn self();\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tfoldInfo = 1;\n\t\tset(\"label\", send(\"HTML__foldIcon\", \"folderOpenXBM\"));\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML__txtBox3[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\ttxt\n\t\t * arg[3]\twidth to use\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3]);\n\t\th = send(nthChild(0), \"make\", arg[2], arg[3]);\n\t\tset(\"height\", h);\n\t\treturn h + 5;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tset(\"width\", arg[1]);\n\t\th = send(nthChild(0), \"R\", arg[1]);\n\t\tset(\"height\", h);\n\t\treturn h + 5;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\tcolor = getResource(\"Viola.borderColor_doc\");\n\t\tif (color) set(\"BDColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox4[] = "100";
static char _slotValue_HTML__txtBox5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox7[] = "txtDisp";
static char _slotValue_HTML__txtBox8[] = "HTML__txtBox";
static char _slotValue_HTML__txtBox9[] = "HTML__txtBox.txt";
static char _slotValue_HTML__txtBox10[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\ttxt\n\t\t * arg[2]\twidth to use\n\t\t */\n\t\ttxt = arg[1];\n\t\tset(\"width\", arg[2] - 50);\n\t\tset(\"content\", txt);\n\t\tset(\"height\", building_vspan());\n\t\treturn height() + 5;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tclearWindow();\n\t\tset(\"width\", arg[1] - 50);\n\t\tset(\"content\", txt);\n\t\tvspan = set(\"height\", building_vspan());\n\t\trender();\n\t\treturn vspan + 4;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox11[] = "50";
static char _slotValue_HTML__txtBox12[] = "10";
static char _slotValue_HTML__txtBox13[] = "10";
static char _slotValue_HTML__txtBox14[] = "normal";
static char _slotValue_HTML__txtBox15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox17[] = "XBM";
static char _slotValue_HTML__txtBox18[] = "HTML__txtBox";
static char _slotValue_HTML__txtBox19[] = "HTML__txtBox.icon";
static char _slotValue_HTML__txtBox20[] = "#define info_width 34\n#define info_height 33\nstatic char info_bits[] = {\n   0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0xe0, 0x0f, 0x00, 0xfc, 0x00, 0x7c,\n   0x7c, 0x00, 0xfc, 0x00, 0x1f, 0xf0, 0x01, 0xfc, 0x80, 0x0f, 0xe0, 0x03,\n   0xfc, 0xc0, 0x0f, 0xe0, 0x07, 0xfc, 0xe0, 0x07, 0xc0, 0x0f, 0xfc, 0xf0,\n   0x07, 0xc0, 0x1f, 0xfc, 0xf8, 0x07, 0xc0, 0x3f, 0xfc, 0xf8, 0x0f, 0xe0,\n   0x3f, 0xfc, 0xfc, 0x0f, 0xe0, 0x7f, 0xfc, 0xfc, 0x1f, 0xf0, 0x7f, 0xfc,\n   0xfc, 0xff, 0xfe, 0x7f, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xfe, 0x1f,\n   0xf0, 0xff, 0xfc, 0xfe, 0x1f, 0xf0, 0xff, 0xfc, 0xfe, 0x1f, 0xf0, 0xff,\n   0xfc, 0xfe, 0x1f, 0xf0, 0xff, 0xfc, 0xfe, 0x1f, 0xf0, 0xff, 0xfc, 0xfe,\n   0x1f, 0xf0, 0xff, 0xfc, 0xfc, 0x1f, 0xf0, 0x7f, 0xfc, 0xfc, 0x1f, 0xf0,\n   0x7f, 0xfc, 0xfc, 0x1f, 0xf0, 0x7f, 0xfc, 0xf8, 0x1f, 0xf0, 0x3f, 0xfc,\n   0xf8, 0x1f, 0xf0, 0x3f, 0xfc, 0xf0, 0x1f, 0xf0, 0x1f, 0xfc, 0xe0, 0x1f,\n   0xf0, 0x0f, 0xfc, 0xc0, 0x1f, 0xf0, 0x07, 0xfc, 0x80, 0x1f, 0xf0, 0x03,\n   0xfc, 0x00, 0x1f, 0xf0, 0x01, 0xfc, 0x00, 0xfc, 0x7f, 0x00, 0xfc, 0x00,\n   0xe0, 0x0f, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xfc};\n";
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
static char _slotValue_HTML__txtBox_alert3[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\ttxt\n\t\t * arg[3]\twidth to use\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3] - 2);\n\t\th = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\t\tset(\"height\", h);\n\t\tafter(2000, nthChild(1), \"tic\");\n\t\treturn h + 2;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tset(\"width\", arg[1] - 2);\n\t\th = send(nthChild(0), \"R\", arg[1]) + 3;\n\t\tset(\"height\", h);\n\t\treturn h + 2;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
static char _slotValue_HTML__txtBox_alert4[] = "100";
static char _slotValue_HTML__txtBox_alert5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_alert7[] = "txtDisp";
static char _slotValue_HTML__txtBox_alert8[] = "HTML__txtBox_alert";
static char _slotValue_HTML__txtBox_alert9[] = "HTML__txtBox_alert.txt";
static char _slotValue_HTML__txtBox_alert10[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\ttxt\n\t\t * arg[2]\twidth to use\n\t\t */\n\t\ttxt = arg[1];\n\t\tset(\"width\", arg[2] - 50);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\treturn h + 2;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tclearWindow();\n\t\tset(\"width\", arg[1] - 50);\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\trender();\n\t\treturn h + 2;\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
static char _slotValue_HTML__txtBox_alert11[] = "50";
static char _slotValue_HTML__txtBox_alert12[] = "10";
static char _slotValue_HTML__txtBox_alert13[] = "10";
static char _slotValue_HTML__txtBox_alert14[] = "normal";
static char _slotValue_HTML__txtBox_alert15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_alert17[] = "XBM";
static char _slotValue_HTML__txtBox_alert18[] = "HTML__txtBox_alert";
static char _slotValue_HTML__txtBox_alert19[] = "HTML__txtBox_alert.icon";
static char _slotValue_HTML__txtBox_alert20[] = "\n\tswitch (arg[0]) {\n\tcase \"tic\":\n\t\tinvertLine(15,18, x, y);\n\t\tsecond = float(nthWord(date(), 6));\n\t\td = second * 6.0 - 90.0;\n\t\tx = 8 * cos(d) + 15;\n\t\ty = 8 * sin(d) + 18;\n\t\tinvertLine(15,18, x, y);\n\t\tafter(500, self(), \"tic\");\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\tusual();\n\t\tinvertLine(15,18, x, y);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\td = 270;\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox_alert21[] = "#define hand2_width 32\n#define hand2_height 32\nstatic char hand2_bits[] = {\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00,\n   0x80, 0x7f, 0x00, 0x00, 0xe0, 0xff, 0x01, 0x00, 0xf0, 0xff, 0x01, 0x00,\n   0xf8, 0xff, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x3f,\n   0xfe, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0x3f,\n   0xfe, 0x3f, 0x00, 0x00, 0xfe, 0xdf, 0x3f, 0x00, 0xfe, 0xef, 0x7f, 0x00,\n   0xfe, 0xef, 0x7f, 0x00, 0xfe, 0xef, 0x3f, 0x00, 0xfe, 0x3f, 0x00, 0x00,\n   0xfe, 0xdf, 0x3f, 0x00, 0xfe, 0xef, 0x7f, 0x00, 0xfe, 0xef, 0x7f, 0x00,\n   0xfe, 0xef, 0x3f, 0x00, 0xf8, 0x3f, 0x00, 0x00, 0xf0, 0xdf, 0x1f, 0x00,\n   0xc0, 0xdf, 0x1f, 0x00, 0x00, 0xde, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n";
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
static char _slotValue_HTML__txtBox_caution3[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\ttxt\n\t\t * arg[3]\twidth to use\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3]-2);\n\t\th = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\t\tset(\"height\", h);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\treturn h + 2;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tset(\"width\", arg[1]-2);\n\t\th = send(nthChild(0), \"R\", arg[1]) + 3;\n\t\tset(\"height\", h);\n\t\treturn h + 2;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox_caution4[] = "100";
static char _slotValue_HTML__txtBox_caution5[] = "8";
static char _slotValue_HTML__txtBox_caution6[] = "6";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_caution8[] = "txtDisp";
static char _slotValue_HTML__txtBox_caution9[] = "HTML__txtBox_caution";
static char _slotValue_HTML__txtBox_caution10[] = "HTML__txtBox_caution.txt";
static char _slotValue_HTML__txtBox_caution11[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\ttxt\n\t\t * arg[2]\twidth to use\n\t\t */\n\t\ttxt = arg[1];\n\t\tset(\"width\", arg[2] - 50);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'R': /* resize */\n\t\tclearWindow();\n\t\tset(\"width\", arg[1] - 50);\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\trender();\n\t\treturn h;\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\t/*processMouseMove();*/\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
static char _slotValue_HTML__txtBox_caution12[] = "50";
static char _slotValue_HTML__txtBox_caution13[] = "10";
static char _slotValue_HTML__txtBox_caution14[] = "10";
static char _slotValue_HTML__txtBox_caution15[] = "normal";
static char _slotValue_HTML__txtBox_caution16[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_caution18[] = "XBM";
static char _slotValue_HTML__txtBox_caution19[] = "HTML__txtBox_caution";
static char _slotValue_HTML__txtBox_caution20[] = "HTML__txtBox_caution.icon";
static char _slotValue_HTML__txtBox_caution21[] = "\n\tswitch (arg[0]) {\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox_caution22[] = "#define caution_width 34\n#define caution_height 31\nstatic char caution_bits[] = {\n 0x00,0x00,0x00,0x00,0xfc,0x00,0x00,0x00,0x00,0xfc,0xf8,0xff,0xff,0x7f,0xfc,\n 0xf8,0xff,0xff,0x7f,0xfc,0xfc,0xff,0xff,0xff,0xfc,0xfc,0xff,0xfc,0xff,0xfc,\n 0xf8,0x7f,0xf8,0x7f,0xfc,0xf8,0x7f,0xf8,0x7f,0xfc,0xf0,0x7f,0xf8,0x3f,0xfc,\n 0xf0,0x7f,0xf8,0x3f,0xfc,0xe0,0x7f,0xf8,0x1f,0xfc,0xe0,0x7f,0xf8,0x1f,0xfc,\n 0xc0,0x7f,0xf8,0x0f,0xfc,0xc0,0x7f,0xf8,0x0f,0xfc,0x80,0xff,0xfc,0x07,0xfc,\n 0x00,0xff,0xfc,0x03,0xfc,0x00,0xff,0xfc,0x03,0xfc,0x00,0xfe,0xfc,0x01,0xfc,\n 0x00,0xfe,0xff,0x01,0xfc,0x00,0xfc,0xff,0x00,0xfc,0x00,0xfc,0xfc,0x00,0xfc,\n 0x00,0x78,0x78,0x00,0xfc,0x00,0xf8,0x7c,0x00,0xfc,0x00,0xf0,0x3f,0x00,0xfc,\n 0x00,0xe0,0x1f,0x00,0xfc,0x00,0xe0,0x1f,0x00,0xfc,0x00,0xc0,0x0f,0x00,0xfc,\n 0x00,0xc0,0x0f,0x00,0xfc,0x00,0x80,0x07,0x00,0xfc,0x00,0x00,0x00,0x00,0xfc,\n 0x00,0x00,0x00,0x00,0xfc};\n";
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
static char _slotValue_HTML__txtBox_error3[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\ttxt\n\t\t * arg[3]\twidth to use\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3]);\n\t\th = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\t\tset(\"height\", h);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\treturn h + 2;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tset(\"width\", arg[1]);\n\t\th = send(nthChild(0), \"R\", arg[1]) + 3;\n\t\tset(\"height\", h);\n\t\treturn h + 2;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
static char _slotValue_HTML__txtBox_error4[] = "100";
static char _slotValue_HTML__txtBox_error5[] = "8";
static char _slotValue_HTML__txtBox_error6[] = "6";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_error8[] = "txtDisp";
static char _slotValue_HTML__txtBox_error9[] = "HTML__txtBox_error";
static char _slotValue_HTML__txtBox_error10[] = "HTML__txtBox_error.txt";
static char _slotValue_HTML__txtBox_error11[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\ttxt\n\t\t * arg[2]\twidth to use\n\t\t */\n\t\ttxt = arg[1];\n\t\tset(\"width\", arg[2] - 50);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\treturn h + 2;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tclearWindow();\n\t\tset(\"width\", arg[1] - 50);\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\trender();\n\t\treturn h + 2;\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\t/*processMouseMove();*/\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
static char _slotValue_HTML__txtBox_error12[] = "50";
static char _slotValue_HTML__txtBox_error13[] = "10";
static char _slotValue_HTML__txtBox_error14[] = "10";
static char _slotValue_HTML__txtBox_error15[] = "normal";
static char _slotValue_HTML__txtBox_error16[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_error18[] = "XBM";
static char _slotValue_HTML__txtBox_error19[] = "HTML__txtBox_error";
static char _slotValue_HTML__txtBox_error20[] = "HTML__txtBox_error.icon";
static char _slotValue_HTML__txtBox_error21[] = "\n\tswitch (arg[0]) {\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox_error22[] = "#define error_width 32\n#define error_height 29\nstatic char error_bits[] = {\n 0x00,0xfe,0x7f,0x00,0x00,0xff,0xff,0x00,0x80,0xff,0xff,0x01,0xc0,0xff,0xff,\n 0x03,0xe0,0xff,0xff,0x07,0xf0,0xff,0xff,0x0f,0xf8,0xff,0xff,0x1f,0xfc,0xff,\n 0xff,0x3f,0xfe,0xff,0xff,0x7f,0x0e,0x31,0xce,0x78,0xee,0xad,0xb5,0x76,0xee,\n 0xad,0xb5,0x76,0xee,0xad,0xb5,0x76,0x8e,0x31,0xb6,0x78,0xee,0x39,0xb7,0x7c,\n 0xee,0xb5,0xb6,0x7a,0xee,0xb5,0xb6,0x7a,0xee,0xa5,0xb5,0x76,0x0e,0xad,0xcd,\n 0x76,0xfe,0xff,0xff,0x7f,0xfc,0xff,0xff,0x3f,0xf8,0xff,0xff,0x1f,0xf0,0xff,\n 0xff,0x0f,0xe0,0xff,0xff,0x07,0xc0,0xff,0xff,0x03,0x80,0xff,0xff,0x01,0x00,\n 0xff,0xff,0x00,0x00,0xfe,0x7f,0x00,0x00,0x00,0x00,0x00};\n";
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
static char _slotValue_HTML__txtBox_note3[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\ttxt\n\t\t * arg[3]\twidth to use\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3] - 2);\n\t\th = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\t\tset(\"height\", h);\n\t\treturn h + 2;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tset(\"width\", arg[1] - 2);\n\t\th = send(nthChild(0), \"R\", arg[1]) + 3;\n\t\tset(\"height\", h);\n\t\treturn h + 2;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
static char _slotValue_HTML__txtBox_note4[] = "100";
static char _slotValue_HTML__txtBox_note5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_note7[] = "txtDisp";
static char _slotValue_HTML__txtBox_note8[] = "HTML__txtBox_note";
static char _slotValue_HTML__txtBox_note9[] = "HTML__txtBox_note.txt";
static char _slotValue_HTML__txtBox_note10[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\ttxt\n\t\t * arg[2]\twidth to use\n\t\t */\n\t\ttxt = arg[1];\n\t\tset(\"width\", arg[2] - 50);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\treturn h + 2;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tclearWindow();\n\t\tset(\"width\", arg[1] - 50);\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\trender();\n\t\treturn h + 2;\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\t/*processMouseMove();*/\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
static char _slotValue_HTML__txtBox_note11[] = "50";
static char _slotValue_HTML__txtBox_note12[] = "10";
static char _slotValue_HTML__txtBox_note13[] = "10";
static char _slotValue_HTML__txtBox_note14[] = "normal";
static char _slotValue_HTML__txtBox_note15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_note17[] = "XBM";
static char _slotValue_HTML__txtBox_note18[] = "HTML__txtBox_note";
static char _slotValue_HTML__txtBox_note19[] = "HTML__txtBox_note.icon";
static char _slotValue_HTML__txtBox_note20[] = "\n\tswitch (arg[0]) {\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox_note21[] = "#define info_width 32\n#define info_height 32\nstatic char info_bits[] = {\n   0x00, 0xf0, 0x07, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0x80, 0xff, 0xff, 0x00,\n   0xc0, 0xff, 0xff, 0x01, 0xe0, 0x3f, 0xfe, 0x03, 0xf0, 0x1f, 0xfc, 0x07,\n   0xf8, 0x0f, 0xf8, 0x0f, 0xfc, 0x0f, 0xf8, 0x1f, 0xfc, 0x0f, 0xf8, 0x1f,\n   0xfe, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f, 0xfe, 0x3f, 0xfe, 0xff, 0xff, 0x3f,\n   0xff, 0x0f, 0xfc, 0x7f, 0xff, 0x0f, 0xfc, 0x7f, 0xff, 0x1f, 0xfc, 0x7f,\n   0xff, 0x1f, 0xfc, 0x7f, 0xff, 0x1f, 0xfc, 0x7f, 0xff, 0x1f, 0xfc, 0x7f,\n   0xff, 0x1f, 0xfc, 0x7f, 0xfe, 0x1f, 0xfc, 0x3f, 0xfe, 0x1f, 0xfc, 0x3f,\n   0xfe, 0x1f, 0xfc, 0x3f, 0xfc, 0x1f, 0xfc, 0x1f, 0xfc, 0x07, 0xf0, 0x1f,\n   0xf8, 0x07, 0xf0, 0x0f, 0xf0, 0x07, 0xf0, 0x07, 0xe0, 0xff, 0xff, 0x03,\n   0xc0, 0xff, 0xff, 0x01, 0x80, 0xff, 0xff, 0x00, 0x00, 0xfe, 0x3f, 0x00,\n   0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00};\n";
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
static char _slotValue_HTML__txtBox_time3[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\ttxt\n\t\t * arg[3]\twidth to use\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3]);\n\t\th = send(nthChild(0), \"make\", arg[2], arg[3]) + 3;\n\t\tset(\"height\", h);\n\t\tafter(2000, nthChild(1), \"tic\");\n\t\treturn h;\n\tbreak;\n\tcase 'R': /* resize */\n\t\tset(\"width\", arg[1]);\n\t\th = send(nthChild(0), 'R', arg[1]) + 3;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox_time4[] = "100";
static char _slotValue_HTML__txtBox_time5[] = "100";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_time7[] = "txtDisp";
static char _slotValue_HTML__txtBox_time8[] = "HTML__txtBox_time";
static char _slotValue_HTML__txtBox_time9[] = "HTML__txtBox_time.txt";
static char _slotValue_HTML__txtBox_time10[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\ttxt\n\t\t * arg[2]\twidth to use\n\t\t */\n\t\ttxt = arg[1];\n\t\tset(\"width\", arg[2] - 50);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'R': /* resize */\n\t\tclearWindow();\n\t\tset(\"width\", arg[1] - 50);\n\t\tset(\"content\", txt);\n\t\th = building_vspan();\n\t\tif (h < 32) h = 32;\n\t\tset(\"height\", h);\n\t\trender();\n\t\treturn h;\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
static char _slotValue_HTML__txtBox_time11[] = "50";
static char _slotValue_HTML__txtBox_time12[] = "10";
static char _slotValue_HTML__txtBox_time13[] = "10";
static char _slotValue_HTML__txtBox_time14[] = "normal";
static char _slotValue_HTML__txtBox_time15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_time17[] = "XBM";
static char _slotValue_HTML__txtBox_time18[] = "HTML__txtBox_time";
static char _slotValue_HTML__txtBox_time19[] = "HTML__txtBox_time.icon";
static char _slotValue_HTML__txtBox_time20[] = "\n\tswitch (arg[0]) {\n\tcase \"tic\":\n\t\tinvertLine(15,18, x, y);\n\t\tsecond = float(nthWord(date(), 6));\n\t\td = second * 6.0 - 90.0;\n\t\tx = 8 * cos(d) + 15;\n\t\ty = 8 * sin(d) + 18;\n\t\tinvertLine(15,18, x, y);\n\t\tafter(500, self(), \"tic\");\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\tusual();\n\t\tinvertLine(15,18, x, y);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\td = 270;\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML__txtBox_time21[] = "#define timer_width 32\n#define timer_height 32\nstatic char timer_bits[] = {\n   0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x00, 0x08, 0x0a, 0x00,\n   0x00, 0xf8, 0x0f, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x40, 0x01, 0x00,\n   0x00, 0xf0, 0x07, 0x00, 0x00, 0x0c, 0x18, 0x00, 0x00, 0xf3, 0x67, 0x00,\n   0x80, 0xfc, 0x9f, 0x00, 0x40, 0xfe, 0xbf, 0x01, 0x40, 0xff, 0x7f, 0x01,\n   0xa0, 0xff, 0xff, 0x02, 0xa0, 0xff, 0xff, 0x02, 0xd0, 0xff, 0xff, 0x05,\n   0xd0, 0xff, 0xff, 0x07, 0xd0, 0xff, 0xff, 0x05, 0xd0, 0xff, 0xff, 0x07,\n   0xd0, 0xff, 0xff, 0x05, 0xd0, 0xff, 0xff, 0x05, 0xd0, 0xff, 0xff, 0x07,\n   0xa0, 0xff, 0xff, 0x02, 0xa0, 0xff, 0xff, 0x03, 0x40, 0xff, 0x7f, 0x01,\n   0x40, 0xfe, 0xff, 0x01, 0x80, 0xfc, 0xdf, 0x00, 0x00, 0xf3, 0x6f, 0x00,\n   0x00, 0x0c, 0x18, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,\n   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};\n";
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
static char _slotValue_HTML_address2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\th = 0;\n/*\t\tSGMLBuildDoc_setBuff(-1);*/\n\t\tsend(self(), \"setStyles\");\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[2], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor, paneConfig);\n\t\t\tmakeAnchor = 0;\n\t\t} \n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\": /* done */\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tsend(self(), \"setStyles\");\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[2], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor, paneConfig);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"ALIGN\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"center\":\n\t\t\t\tpaneConfig = \"center\";\n\t\t\tbreak;\n\t\t\tcase \"left\":\n\t\t\t\tpaneConfig = \"westToEast\";\n\t\t\tbreak;\n\t\t\tcase \"right\":\n\t\t\t\tpaneConfig = \"eastToWest\";\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"ADDRESS\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = width();\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1] + 20;\n\t\treturn vspan;\n\tbreak;\n\tcase 'T':\n\t\t/* arg[1] = y\n\t\t * arg[2] = width\n\t\t */\n\t\th = get(\"height\");\n\t\tparentHeight = send(parent(), \"heightP\");\n\t\theightDiff = h - parentHeight;\n\t\tif (heightDiff > 0) {\n\t\t\theightRatio =  float(heightDiff) / -100.0;\n\t\t} else {\n\t\t\theightRatio = 0;\n\t\t\th = parentHeight;\n\t\t\tset(\"height\", h);\n\t\t}\n\t\tprevWidth = arg[2];\n\t\tprevHeight = parentHeight;\n\n\t\treturn h;\n\tbreak;\n\tcase \"inAnchor\":\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"setAnchor\":\n\t\tmakeAnchor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"styleSheet\":\n\t\treturn tagPtr;\n\tbreak;\n\tcase \"setStyles\":\n\t\tif (tagPtr == 0) tagPtr = STG_tagPtr(\"ADDRESS\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"fontSlant\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<ADDRESS\");\n\t\tif (tagID) print(\" NAME=\\\"\", tagID, \"\\\">\\n\");\n\t\telse print(\">\\n\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i),\n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset;\n\t\t\t}\n\t\t}\n\t\tprint(\"</ADDRESS>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_attr2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (tagID) {\n\t\t\tsend(parent(), \"setAnchor\", tagID);\n\t\t\ttagID = 0;\n\t\t}\n\t\tif (url) {\n\t\t\tt = concat(\" \\\\b(\", compressSpaces(get(\"label\")),\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t\turl = 0;\n\t\t\treturn t;\n\t\t} else {\n\t\t\treturn compressSpaces(get(\"label\"));\n\t\t}\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"HREF\":\n\t\t\turl = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\tset(\"content2\", self());/*a kludge to deal with cloning*/\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tvspan = 1;\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t  vspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\treturn vspan;\n\tbreak;\n\tcase \"copyObj\":\n\t\turl = send(arg[1], \"url\");\n\t\treturn 0;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"inAnchor\":\n/* trouble is, once attr is copied, 'url' and other info in variables\nare lost. Solution send message to this object to have itself copied\n(including the appropriate variables).\n*/\n\t\treturn url;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"url\":\n\t\t/* for <img ismap...> to ask */\n\t\treturn url;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"findForm\":\n\t\treturn send(parent(), \"findForm\");\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_attr[] = {
    {"class", _slotValue_HTML_attr0},
    {"name", _slotValue_HTML_attr1},
    {"script", _slotValue_HTML_attr2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_author0[] = "field";
static char _slotValue_HTML_author1[] = "HTML_author";
static char _slotValue_HTML_author2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tsend(send(parent(), \"findTop\"), \"reportAuthor\", href);\n\t\thref = 0;\n\t\treturn -1;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"HREF\":\n\t\t\thref = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase 'R':\n\t\treturn 1;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"AI\":\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_author[] = {
    {"class", _slotValue_HTML_author0},
    {"name", _slotValue_HTML_author1},
    {"script", _slotValue_HTML_author2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_base0[] = "field";
static char _slotValue_HTML_base1[] = "HTML_base";
static char _slotValue_HTML_base2[] = "\n        switch (arg[0]) {\n        case \"D\":\n                return -1;\n        break;\n        case \"config\":\n\tcase \"AI\":\n                return;\n        break;\n        case 'R':\n                return 0;\n        break;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"HREF\":\n\t                send(send(parent(), \"findTop\"), \"baseURL\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n        case \"gotoAnchor\":\n                return \"\";\n        break;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak; \n\t}\n        usual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_base[] = {
    {"class", _slotValue_HTML_base0},
    {"name", _slotValue_HTML_base1},
    {"script", _slotValue_HTML_base2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_body0[] = "field";
static char _slotValue_HTML_body1[] = "HTML_body";
static char _slotValue_HTML_body2[] = "\n/*\nprint(\"HTML_BODY: self=\", self(), \": \");\nfor (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");print(\"...end\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"F\": /* flush */\n\t\th = 0;\n/*\t\tSGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\t\tsend(self(), \"setStyles\");\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(), \n\t\t\t\tcompressSpaces(get(\"label\")), \n\t\t\t\tstyle_p[2], \n\t\t\t\tget(\"width\") - style_p[2] - style_p[3],\n\t\t\t\tSGMLBuildDoc_span() + style_p[0],\n\t\t\t\tmakeAnchor) + style_p[1];\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\": /* done */\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\", self());\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[2], \n\t\t\t\tget(\"width\") - style_p[2], \n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"BODY\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"BODY\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"placeID\":\n\t\t/* this is clumsy. should be simplified with a primitive f() */\n\t\t/* find the caller (child) object's place in the obj list */\n\t\tcobj = arg[1];\n\t\tobjPlace = -1;\n\n\t\tfor (i = objectListCount_children() - 1; i >= 0; i--) {\n\t\t\tnobj = nthChild(i);/*bug: can't inline into == XXX*/\n\t\t\tif (cobj == nobj) {\n\t\t\t\tobjPlace = i;\n\t\t\t}\n\t\t}\n\t\tobjPlacePath = concat(objPlace, \" \", arg[2]);\n\t\treturn send(parent(), \"placeID\", self(), objPlacePath);\n\tbreak;\n\tcase \"CE_change\":\n\t\treturn send(nthChild(nthWord(arg[1], 1)), arg[0],\n\t\t\t\tnthWord(arg[1], 2, 99), arg[2]);\n\tbreak;\n\tcase \"CE_lock\":\n\tcase \"CE_unlock\":\n\t\treturn send(nthChild(nthWord(arg[1], 1)), arg[0], \n\t\t\t\tnthWord(arg[1], 2, 99));\n\tbreak;\n\tcase \"inPreP\":\n\tcase \"inAnchor\":\n\tcase \"L\": /*???*/\n\tcase \"compact\":\n\t\treturn 0;\n\tbreak;\n\tcase \"setAnchor\":\n\t\tmakeAnchor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<BODY>\\n\");\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tsend(nthChild(i), \"outputSGML\");\n\t\t}\n\t\tprint(\"</BODY>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"setStyles\":\n\t\tuseTagInfo_align = 1;\n\t\ttagPtr = STG_tagPtr(\"BODY\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"border\");\n\t\t\tif (i) {\n\t\t\t\tset(\"border\", 6);\n\t\t\t\tset(\"BDColor\", get(\"FGColor\"));/*XXX*/\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola.background_doc\");\n\t\tif (color) set(\"BGColor\", color);\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"FGColor\", color);\n\t\tcolor = getResource(\"Viola.borderColor_doc\");\n\t\tif (color) set(\"BDColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_body[] = {
    {"class", _slotValue_HTML_body0},
    {"name", _slotValue_HTML_body1},
    {"script", _slotValue_HTML_body2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_box0[] = "field";
static char _slotValue_HTML_box1[] = "HTML_box";
static char _slotValue_HTML_box2[] = "\n\nprint(\"HTML_box: self=\", self(), \": \");\nfor (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");\nprint(\"^^^^^^^end\\n\");\n\n\tswitch (arg[0]) {\n\tcase \"entity\":\nprint(\"ENTITY FLUSH MATH label>>>>>\", get(\"label\"), \"<<<\\n\");\n\t\tif (isBlank(get(\"label\"))) return 0;\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = get(\"label\");\n\t\ttokCount++;\n\n\t\tentity_number = arg[1];\n\t\tif (entity_number == 50) {/*infin*/\n\t\t} else if (entity_number == 51) { /*integral*/\n\t\t\ttok[tokCount] = 19; /*MINFO_INTEGRAL*/\n\t\t\tdata[tokCount] = \"\";\n\t\t\ttokCount++;\n\t\t} else if (entity_number == 65) { /*sigma*/\n\t\t\ttok[tokCount] = 20; /*MINFO_SUM*/\n\t\t\tdata[tokCount] = \"\";\n\t\t\ttokCount++;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"tok&data\":\n\t\t/* arg[1]\ttoken\n\t\t * arg[2]\tdata\n\t\t */\n\t\ttok[tokCount] = arg[1];\n\t\tdata[tokCount] = arg[2];\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\t/* arg[1]\tdata\n\t\t */\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = arg[1];\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"tok\":\n\t\t/* arg[1]\ttoken type\n\t\t */\n\t\ttok[tokCount] = arg[1];\n\t\tdata[tokCount] = \"\";\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"over\":\n\t\ttok[tokCount] = 4;\n\t\tdata[tokCount] = \"\";\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"F\":\nprint(\"F BOX--- label-{\", get(\"label\"), \"}\\n\");\n\t\tif (isBlank(get(\"label\"))) return -1;\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = get(\"label\");\n\t\ttokCount++;\n\t\treturn -1;\n\tbreak;\n\tcase \"D\":\n\t\tSGMLBuildDoc_setBuff(0);\nprint(\"D BOX--- label-{\", get(\"label\"), \"}\\n\");\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\ttok[tokCount] = 2;\n\t\t\tdata[tokCount] = get(\"label\");\n\t\t\ttokCount++;\n\t\t}\n\n\t\tsend(parent(), \"tok\", 5/*BOX_BEGIN*/);\n\n\t\tfor (i = 0; i < tokCount; i++) {\n\t\t\tprint(\"XXX box_tok \", i, \":   type=\", tok[i], \n\t\t\t\t\"  data={\", data[i], \"}\\n\");\n\t\t}\n\n\t\tfor (i = 0; i < tokCount; i++) {\n\t\t\tsend(parent(), \"tok&data\", tok[i], data[i]);\n\t\t}\n\t\tsend(parent(), \"tok\", 6/*BOX_END*/);\n\t\ttokCount = 0;\n\n\t\treturn 0;/*destroy self*/\n\tbreak;\n\tcase \"R\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_bulletItem3[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\treturn expose();\n\tbreak;\n\tcase \"D\":\n\t\ttxt = send(parent(), \"data\");\n\t\tif (isBlank(txt)) {\n\t\t\treturn 0;\n\t\t} else {\n\t\t\tset(\"content\", txt);\n\t\t\treturn (building_vspan() + 2);\n\t\t}\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t/* arg[2]\tdata\n\t\t * arg[3]\tx\n\t\t * arg[4]\twidth\n\t\t * arg[5]\ty\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"x\", arg[3]);\n\t\tset(\"y\", arg[5]);\n\t\tset(\"width\", arg[4]);\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", arg[2]);\n\t\th = building_vspan() + 4;\n\t\tset(\"height\", h);\n\t\tset(\"maxHeight\", h);\n\t\th += 4;\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\treturn h;\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"R\":\n\tcase \"clone\":\n\tcase \"buttonRelease\":\n\tcase \"config\":\n\tcase \"gotoAnchor\":\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_caution2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"D\": /* done */\n\t\tinPreP = send(parent(), \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", get(\"label\"));\n\t\treturn (building_vspan() + 2);\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tstyle = SGMLGetStyle(\"HTML\", \"CAUTION\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tstyle = SGMLGetStyle(\"HTML\", \"CAUTION\");\n\t\tvspan = style[0];\n\t\tset(\"width\", get(\"width\") - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"BDColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_change2[] = "\n        switch (arg[0]) {\n        case \"D\":\n                return -1;\n        break;\n        case \"config\":\n\tcase \"AI\":\n                return;\n        break;\n        case 'R':\n                return 0;\n        break;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"HREF\":\n\t                send(send(parent(), \"findTop\"), \"baseURL\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n        case \"gotoAnchor\":\n                return \"\";\n        break;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak; \n\t}\n        usual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_change[] = {
    {"class", _slotValue_HTML_change0},
    {"name", _slotValue_HTML_change1},
    {"script", _slotValue_HTML_change2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_changed0[] = "field";
static char _slotValue_HTML_changed1[] = "HTML_changed";
static char _slotValue_HTML_changed2[] = "\n        switch (arg[0]) {\n        case \"D\":\n                return -1;\n        break;\n        case \"config\":\n\tcase \"AI\":\n                return;\n        break;\n        case 'R':\n                return 0;\n        break;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"IDREF\":\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n        case \"gotoAnchor\":\n                return \"\";\n        break;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola.background_doc\");\n\t\tif (color) {\n\t\t\tset(\"BGColor\", color);\n\t\t\tset(\"BDColor\", color);\n\t\t}\n\t\treturn;\n\tbreak; \n\t}\n        usual();\n";
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
static char _slotValue_HTML_cmd2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n/*\t\tsend(parent(), 'A', get(\"label\"));\n*/\n\t\treturn 0;\n\tbreak;\n\tcase \"data\":\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"ref\":\n\t\treturn ref;\n\tbreak;\n\tcase \"setRef\":\n\t\tref = arg[1];\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_cmd[] = {
    {"class", _slotValue_HTML_cmd0},
    {"name", _slotValue_HTML_cmd1},
    {"script", _slotValue_HTML_cmd2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_col20[] = "field";
static char _slotValue_HTML_col21[] = "HTML_col2";
static char _slotValue_HTML_col22[] = "\n\tswitch (arg[0]) {\n\tcase \"F\": /* flush */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = SGMLBuildDoc_span();\n\n\t\t\txx = get(\"width\") / 2;\n\t\t\tcol = _col % 2;\n\t\t\tindent = col * xx;\n\n\t\t\ttxtH = send(txtObj, \"make\", self(), \n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tindent, xx, h, 0);\n\t\t\tif (col == 1) {\n\t\t\t\tset(\"height\", h + txtH);\n\t\t\t} else {\n\t\t\t\tset(\"height\", h);\n\t\t\t\treturn -1;\n\t\t\t}\n\t\t}\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"D\":\n\t\th = send(self(), 'R', get(\"y\"), get(\"width\"));\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'L':\n\t\treturn \"D\";\n\tbreak;\n\tcase \"col\":\n\t\t_col++; /* for listSep to query, to know its place */\n\t\treturn (_col - 1) % 2;\t\t/*XXX dude, implement++ */\n\tbreak;\n\tcase \"colEnd\":\n\t\treturn 1;\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn 0; /* little point account for PRE here */\n\tbreak;\n\tcase \"itemWidth\":\n\t\treturn get(\"width\") / 2;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"DIR\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tset(\"x\", style[2]);\n\n\t\t_col = 0;\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\") / 2;\n\t\t\tfor (i = 0; i < n;) {\n\t\t\t\tcol = i % 2;\n\t\t\t\tindent = col * xx;\n\t\t\t\th = send(nthChild(i), 'R', vspan, xx, indent);\n\t\t\t\ti++;\n\t\t\t\tif ((col == 1) || (i == n)) vspan += h;\n\t\t\t}\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n/*\t\tSGMLBuildDoc_setBuff(-1);*/\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"compact\":\n\t\treturn 1;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagIDCount > 0)\n\t\t\tfor (i = 0; i < tagIDCount; i++)\n\t\t\t\tif (tagIDs[i] == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagIDCount > 0)\n\t\t\tfor (i = 0; i < tagIDCount; i++)\n\t\t\t\tif (tagIDs[i] == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_col32[] = "\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\tset(\"y\", arg[1] * heightRatio);\n\t\treturn;\n\tbreak;\n\tcase \"F\": /* flush */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_li == 0)\n\t\t\t\tstyle_li = SGMLGetStyle(\"HTML\", \"LI\");\n\t\t\ttxtObj = HTML_listSep(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = SGMLBuildDoc_span();\n\n\t\t\txx = get(\"width\") / 3;\n\t\t\tcol = _col % 3;\n\t\t\tindent = col * xx;\n\n\t\t\ttxtH = send(txtObj, \"make\", self(), \n\t\t\t\tget(\"label\"), indent, xx, h);\n\t\t\tif (col == 2) {\n\t\t\t\tset(\"height\", h + txtH);\n\t\t\t} else {\n\t\t\t\tset(\"height\", h);\n\t\t\t\treturn -1;\n\t\t\t}\n\t\t}\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"D\": /* done */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_li == 0) \n\t\t\t\tstyle_li = SGMLGetStyle(\"HTML\", \"LI\");\n\t\t\ttxtObj = HTML_listSep(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = SGMLBuildDoc_span();\n\n\t\t\txx = get(\"width\") / 3;\n\t\t\tcol = _col % 3;\n\t\t\tindent = col * xx;\n\n\t\t\ttxtH = send(txtObj, \"make\", self(), \n\t\t\t\tget(\"label\"), indent, xx, h);\n\t\t\tif (col == 2) {\n\t\t\t\tset(\"height\", h + txtH);\n\t\t\t} else {\n\t\t\t\tset(\"height\", h + txtH); /* the end */\n\t\t\t}\n\t\t}\n\t\treturn get(\"height\");\n\tbreak;\n\tcase 'L':\n\t\treturn \"D\";\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn 0; /* little point account for PRE here */\n\tbreak;\n\tcase \"col\":\n\t\t_col++; /* for listSep to query, to know its place */\n\t\treturn (_col - 1) % 3;\t\t/*XXX dude, implement++ */\n\tbreak;\n\tcase \"colEnd\":\n\t\treturn 2;\n\tbreak;\n\tcase \"itemWidth\":\n\t\treturn get(\"width\") / 3;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"COL3\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tset(\"x\", style[2]);\n\n\t\t_col = 0;\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\") / 3;\n\t\t\tfor (i = 0; i < n;) {\n\t\t\t\tcol = i % 3;\n\t\t\t\tindent = col * xx;\n\t\t\t\th = send(nthChild(i), 'R', vspan, xx, indent);\n\t\t\t\ti++;\n\t\t\t\tif ((col == 2) || (i == n)) vspan += h;\n\t\t\t}\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n/*\t\tSGMLBuildDoc_setBuff(-1);*/\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (get(\"content2\") == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (get(\"content2\") == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_col42[] = "\n\tswitch (arg[0]) {\n\tcase \"shownPositionV\":\n\t\tset(\"y\", arg[1] * heightRatio);\n\t\treturn;\n\tbreak;\n\tcase \"F\": /* flush */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\n\t\t\tif (style_li) style_li = SGMLGetStyle(\"HTML\", \"LI\");\n\t\t\ttxtObj = HTML_listSep(\"clone\", self());\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = SGMLBuildDoc_span();\n\n\t\t\txx = get(\"width\") / 4;\n\t\t\tcol = n % 4;\n\t\t\tindent = col * xx;\n\n\t\t\ttxtH = send(txtObj, \"make\", self(), \n\t\t\t\tget(\"label\"), indent, xx, h);\n\t\t\tif (col == 3) {\n\t\t\t\tset(\"height\", h + txtH);\n\t\t\t} else {\n\t\t\t\tset(\"height\", h);\n\t\t\t\treturn -1;\n\t\t\t}\n\t\t}\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"D\": /* done */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\n\t\t\tif (style_li) style_li = SGMLGetStyle(\"HTML\", \"LI\");\n\t\t\ttxtObj = HTML_listSep(\"clone\", self());\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = SGMLBuildDoc_span();\n\n\t\t\txx = get(\"width\") / 4;\n\t\t\tcol = n % 4;\n\t\t\tindent = col * xx;\n\n\t\t\ttxtH = send(txtObj, \"make\", self(), \n\t\t\t\tget(\"label\"), indent, xx, h);\n\t\t\tif (col == 3) {\n\t\t\t\tset(\"height\", h + txtH);\n\t\t\t} else {\n\t\t\t\tset(\"height\", h + txtH); /* the end */\n\t\t\t}\n\t\t}\n\t\treturn get(\"height\");\n\tbreak;\n\tcase 'L':\n\t\treturn \"D\";\n\tbreak;\n\tcase \"col\":\n\t\t_col = _col + 1; /* for listSep to query, to know its place */\n\t\treturn (_col - 1) % 4;\t\t/*XXX dude, implement++ */\n\tbreak;\n\tcase \"colEnd\":\n\t\treturn 3;\n\tbreak;\n\tcase \"itemWidth\":\n\t\treturn get(\"width\") / 4;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"COL4\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tset(\"x\", style[2]);\n\n\t\t_col = 0;\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\") / 4;\n\t\t\tfor (i = 0; i < n;) {\n\t\t\t\tcol = i % 4;\n\t\t\t\tindent = col * xx;\n\t\t\t\th = send(nthChild(i), 'R', vspan, xx, indent);\n\t\t\t\ti++;\n\t\t\t\tif ((col == 3) || (i == n)) vspan += h;\n\t\t\t}\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n/*\t\tSGMLBuildDoc_setBuff(-1);*/\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (get(\"content2\") == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (get(\"content2\") == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_defList2[] = "\n\tswitch (arg[0]) {\n\tcase \"head\":\n\tcase \"body\":\n\t\ttoMake = arg[0];\n\t\ttxtObj = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"F\": /* flush */\n\t\treturn send(self(), 'm', \"F\");\n\tbreak;\n\tcase \"D\": /* done */\n\t\treturn send(self(), 'm', \"D\");\n\tbreak;\n\tcase \"m\": /* make */\n\t\tif (arg[1] == \"D\") SGMLBuildDoc_setBuff(0);\n\t\telse SGMLBuildDoc_setBuff(-1);/*???*/\n\t\tt = compressSpaces(get(\"label\"));\n\t\tif (isBlank(t) == 1) {\n\t\t\tif (arg[1] == \"F\") {\n\t\t\t\treturn 1;\n\t\t\t} else if (arg[1] == \"D\") {\n\t\t\t\treturn get(\"height\");\n\t\t\t} else {\n\t\t\t\treturn 1;\n\t\t\t}\n\t\t}\n\n\t\tswitch (toMake) {\n\t\tdefault:/* in case the DefList doesn't start with either\n\t\t\t * <DT> or <DD>\n\t\t\t */\n\t\tcase \"head\":\n\t\t\tif (styleDT == 0) styleDT = SGMLGetStyle(\"HTML\", \"DT\");\n\t\t\ty = get(\"height\");\n\t\t\ttxtH = send(txtObj, \"make\", self(), \n\t\t\t\tt, styleDT[2], \n\t\t\t\tget(\"width\") - styleDT[3] - styleDT[2], y);\n\t\tbreak;\n\t\tcase \"body\":\n\t\t\tif (styleDD == 0) styleDD = SGMLGetStyle(\"HTML\", \"DD\");\n\t\t\ty = get(\"height\");\n\t\t\ttxtH = send(txtObj, \"make\", self(), \n\t\t\t\tt, styleDD[2], \n\t\t\t\tget(\"width\") - styleDD[3] - styleDD[2], y);\n\t\tbreak;\n\t\t}\n\t\tif (arg[1] == \"F\") h = set(\"height\", txtH);\n\t\telse if (arg[1] == \"D\") h = set(\"height\", y + txtH);\n\t\telse h = set(\"height\", txtH);\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"DL\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n\t\t/* In case there is <P> in DefList */\n\t\treturn send(self(), \"m\", \"D\");\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"AI\":\n\tcase \"inAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_defListBody2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tsend(parent(), \"body\");\n\t\treturn \"\";\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_defListBody[] = {
    {"class", _slotValue_HTML_defListBody0},
    {"name", _slotValue_HTML_defListBody1},
    {"script", _slotValue_HTML_defListBody2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_defListBody_p0[] = "txtDisp";
static char _slotValue_HTML_defListBody_p1[] = "HTML_defListBody_p";
static char _slotValue_HTML_defListBody_p2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"D\":\n\t\tsend(parent(), \"body\", self());\n\t\t/* just return something, and fill in data later. \n\t\t * But must be big enough (>2) so that textfield widget\n\t\t * won't wine at the height being too small and not\n\t\t * allow for formatting when the data comes.\n\t\t */\n\t\treturn 1;\n\tbreak;\n\tcase 'R': /* resize */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"DD\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()+2) + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdata\n\t\t * arg[3]\tx\n\t\t * arg[4]\twidth\n\t\t * arg[5]\ty\n\t\t */\n\t\tset(\"x\", arg[3]);\n\t\tset(\"y\", arg[5]);\n\t\tset(\"width\", arg[4]);\n\t\tset(\"height\", 8);/* big enough to allow text to be put in */\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", arg[2]);\n\t\th = building_vspan();\n\t\tset(\"height\", h);\n\t\tset(\"maxHeight\", h);\n\t\th += 4;\n\t\treturn h;\n\tbreak;\n\tcase \"config\":\n\tcase \"gotoAnchor\":\n\tcase \"buttonRelease\":\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_defListHead2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tsend(parent(), \"head\");\n\t\treturn \"\";\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_defListHead[] = {
    {"class", _slotValue_HTML_defListHead0},
    {"name", _slotValue_HTML_defListHead1},
    {"script", _slotValue_HTML_defListHead2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_defListHead_p0[] = "txtDisp";
static char _slotValue_HTML_defListHead_p1[] = "HTML_defListHead_p";
static char _slotValue_HTML_defListHead_p2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"D\":\n\t\tsend(parent(), \"head\", self());\n\t\treturn 1;\n\tbreak;\n\tcase 'R': /* resize */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"DT\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()+2) + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdata\n\t\t * arg[3]\tx\n\t\t * arg[4]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"DT\");\n\t\tvspan = style[0];\n\t\tset(\"x\", arg[3]);\n\t\tset(\"y\", arg[5]);\n\t\tset(\"width\", arg[4]);\n\t\tset(\"height\", 8);/* big enough to allow text to be put in */\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", arg[2]);\n\t\th = building_vspan();\n\t\tset(\"height\", h+2);\n\t\tset(\"maxHeight\", h);\n\t\th += vspan + style[1];\n\t\treturn h;\n\tbreak;\n\tcase \"config\":\n\tcase \"gotoAnchor\":\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\n\tcase \"buttonRelease\":\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_example2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\treturn expose(arg[1], arg[2], arg[3], arg[4]);\n\tbreak;\n\tcase \"D\": /* done */\n\t\tinPreP = send(parent(), \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\tset(\"content\", get(\"label\"));\n\t\treturn (building_vspan() + 2);\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tstyle = SGMLGetStyle(\"HTML\", \"XMP\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tset(\"content\", trimEdgeQ(get(\"content\")));/*bug*/\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<XMP>\", get(\"content\"), \"</XMP>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_fail2[] = "\n\t/* Failure notice.\n\t * This object is used to display insertions that failed. \n\t * See HTML_vobjf.v for usage example.\n\t */\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t/* arg[2]\twidth\n\t\t * arg[3]\tmessage\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[2]);\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", arg[3]);\n\t\tset(\"height\", building_vspan());\n\t\treturn (building_vspan() + 2);\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tset(\"y\", arg[1]);\n\t\tset(\"x\", 0);\n\t\tset(\"width\", arg[2] - get(\"x\"));\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan = set(\"height\", building_vspan());\n\t\trender();\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_figa2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tsend(parent(), \"addFigA\", ref,\n\t\t\tint(nthWord(area, 1)), int(nthWord(area, 2)),\n\t\t\tint(nthWord(area, 3)), int(nthWord(area, 4)));\n\t\treturn -1;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"AREA\":\n\t\t\tarea = arg[2];\n\t\tbreak;\n\t\tcase \"HREF\":\n\t\t\tref = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"AI\":\n\t\treturn 0;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_figa[] = {
    {"class", _slotValue_HTML_figa0},
    {"name", _slotValue_HTML_figa1},
    {"script", _slotValue_HTML_figa2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figa_actual0[] = "glass";
static char _slotValue_HTML_figa_actual1[] = "HTML_figa_actual";
static char _slotValue_HTML_figa_actual2[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\tset(\"parent\", arg[1]);\n\t\tref = arg[2];\n\t\tbx = arg[3];\n\t\tby = arg[4];\n\t\tbw = arg[5];\n\t\tbh = arg[6];\n\n\t\tset(\"x\", bx);\n\t\tset(\"y\", by);\n\t\tset(\"width\", bw);\n\t\tset(\"height\", bh);\n/*\n\t\tprint(\"FIGA_ACTUAL: ref=\", ref, \"\\n\");\n\t\tprint(\"FIGA_ACTUAL: x=\", bx, \"\\n\");\n\t\tprint(\"FIGA_ACTUAL: y=\", by, \"\\n\");\n\t\tprint(\"FIGA_ACTUAL: w=\", bw, \"\\n\");\n\t\tprint(\"FIGA_ACTUAL: h=\", bh, \"\\n\");\n*/\n\t\t/* document building routine turned them off by default,\n\t\t * for efficiency, but here we want to use it for hints.\n\t\t */\n\t\teventMask(\"+enterWindow +leaveWindow\");\n\t\treturn -1;\n\tbreak;\n\tcase \"enter\":\n\t\tsend(parent(), \"invertBox\", bx, by, bx + bw, by + bh);\n\t\ttop = send(parent(), \"findTop\");\n\t\treturn send(top, \"hintOn\", \n\t\t\t    concat(\"Entered hot spot for: \", ref));\n\tbreak;\n\tcase \"leave\":\n\t\tsend(parent(), \"invertBox\", bx, by, bx + bw, by + bh);\n\t\treturn send(top, \"hintOff\");\n\tbreak;\n\tcase \"buttonRelease\":\n\t\treturn send(top, \"follow_href\", ref);\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_figa_actual[] = {
    {"class", _slotValue_HTML_figa_actual0},
    {"name", _slotValue_HTML_figa_actual1},
    {"script", _slotValue_HTML_figa_actual2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figcap0[] = "txtDisp";
static char _slotValue_HTML_figcap1[] = "HTML_figcap";
static char _slotValue_HTML_figcap2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tinPreP = send(parent(), \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", get(\"label\"));\n\t\treturn (building_vspan() + 2);\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"FIGCAP\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"FIGCAP\");\n\t\tvspan = style[0];\n\t\tset(\"width\", get(\"width\") - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_figdata2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn 1;\n\tbreak;\n\tcase 'i':\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"gotoAnchor\":\n\tcase \"AI\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_figdata[] = {
    {"class", _slotValue_HTML_figdata0},
    {"name", _slotValue_HTML_figdata1},
    {"script", _slotValue_HTML_figdata2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figure0[] = "field";
static char _slotValue_HTML_figure1[] = "HTML_figure";
static char _slotValue_HTML_figure2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\treturn -1;\n\tbreak;\n\tcase \"D\":\n/*\t\tif (tagPtr == 0) tagPtr = STG_tagPtr(\"FIGURE\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tif (builtFig == 1) {\n\t\t\th = SGMLBuildDoc_span() + style[1];\n\t\t\tset(\"height\", h);\n\t\t\tbuiltFig = 0;\n\t\t\treturn h;\n\t\t} else if (src != 0) {\n\t\t\tbuiltFig = 1;\n\n\t\t\th = get(\"height\");\n\n\t\t\tswitch (bmType) {\n\t\t\tcase \"gif\":\n\t\t\tcase \"image/gif\":\n\t\t\t\tfigTemplate = \"HTML_giff\";\n\t\t\tbreak;\n\t\t\tcase \"xbm\":\n\t\t\tcase \"image/xbm\":\n\t\t\t\tfigTemplate = \"HTML_xbmf\";\n\t\t\tbreak;\n\t\t\tcase \"xpm\":\n\t\t\tcase \"image/xpm\":\n\t\t\t\tfigTemplate = \"HTML_xpmf\";\n\t\t\tbreak;\n\t\t\tcase \"ps\":\n\t\t\tcase \"application/postscript\":\n\t\t\t\tfigTemplate = \"HTML_psf\";\n\t\t\tbreak;\n\t\t\t}\n\t\t\tif (isBlank(figTemplate) == 1) {\n\t\t\t\t/* unknown type */\n\t\t\t\treturn 0;\n\t\t\t} else {\n\t\t\t\tbitmapObj = send(figTemplate, \"clone\");\n\t\t\t\tw = width() - 10;\n\t\t\t\th += send(bitmapObj, \"make\", self(), w, h,\n\t\t\t\t\t src, delayP, delayWidth, delayHeight,\n\t\t\t\t\t ismap);\n\n\t\t\t\tobjectListPrepend(\"children\", bitmapObj);\n\n\t\t\t\t/* oh heck */\n\t\t\t\th = send(self(), 'R', get(\"y\"), get(\"width\"));\n\t\t\t\tfor (i = 0; i < figaCount; i++) {\n\t\t\t\t\tsend(bitmapObj, \"addFigA\", figaRef[i],\n\t\t\t\t\t\tfigaX[i], figaY[i],\n\t\t\t\t\t\tfigaW[i], figaH[i]);\n\t\t\t\t}\n\t\t\t\tif (style == 0)\n\t\t\t\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\t\t\t\treturn style[0] + h;\n\t\t\t}\n\t\t} else {\n\t\t\tif (isBlank(get(\"label\")) == 1) return -1;\n\n\t\t\tbuiltFig = 1;\n\t\t\th = SGMLBuildDoc_span();\n\n\t\t\tswitch (bmType) {\n\t\t\tcase \"gif\":\n\t\t\tcase \"image/gif\":\n\t\t\tcase \"image/GIF\":\n\t\t\t\tfigTemplate = \"HTML_gif\";\n\t\t\tbreak;\n\t\t\tcase \"xbm\":\n\t\t\tcase \"image/xbm\":\n\t\t\t\tfigTemplate = \"HTML_xbm\";\n\t\t\tbreak;\n\t\t\tcase \"xpm\":\n\t\t\tcase \"image/xpm\":\n\t\t\t\tfigTemplate = \"HTML_xpm\";\n\t\t\tbreak;\n/*\t\t\tcase \"ps\":\n\t\t\tcase \"application/postscript\":\n\t\t\t\tfigTemplate = \"HTML_ps\";\n\t\t\tbreak;\n*/\n\t\t\tdefault:\n\t\tprint(\"HTML_figure.v: don't know what FIGURE TYPE is.\\n\");\n\t\t\tbreak;\n\t\t\t}\n\n\t\t\tif (isBlank(figTemplate) == 1) {\n\t\t\t\t/* unknown type */\n\t\t\t\treturn 0;\n\t\t\t} else {\n\t\t\t\tbitmapObj = send(figTemplate, \"clone\");\n\t\t\t\tw = width() - 10;\n\t\t\t\th += send(bitmapObj, \"make\", self(), w, h,\n\t\t\t\t\t get(\"label\"), ismap);\n\t\t\t\tobjectListPrepend(\"children\", bitmapObj);\n\n\t\t\t\t/* oh heck */\n\t\t\t\th = send(self(), 'R', get(\"y\"), get(\"width\"));\n\n\t\t\t\tfor (i = 0; i < figaCount; i++) {\n\t\t\t\t\tsend(bitmapObj, \"addFigA\", figaRef[i],\n\t\t\t\t\t\tfigaX[i], figaY[i],\n\t\t\t\t\t\tfigaW[i], figaH[i]);\n\t\t\t\t}\n\t\t\t\tif (style == 0)\n\t\t\t\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\t\t\t\treturn style[0] + h + style[1];\n\t\t\t}\n\t\t}\n\tbreak;\n\tcase 'R': /* resize */\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\tx (optional)\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n/*\t\tSGMLBuildDoc_setBuff(-1);*/\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"AI\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"TYPE\":\n\t\t\tbmType = arg[2];\n\t\tbreak;\n\t\tcase \"ISMAP\":\n\t\t\tismap = 1;\n\t\tbreak;\n\t\tcase \"SRC\":\n\t\t\tsrc = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"WIDTH\":\n\t\t\tdelayWidth = arg[2];\n\t\tbreak;\n\t\tcase \"HEIGHT\":\n\t\t\tdelayHeight = arg[2];\n\t\tbreak;\n\t\tcase \"MAYDELAY\":\n\t\t\tdelayP = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"addFigA\":\n\t\tfigaRef[figaCount] = arg[1];\n\t\tfigaX[figaCount] = arg[2];\n\t\tfigaY[figaCount] = arg[3];\n\t\tfigaW[figaCount] = arg[4];\n\t\tfigaH[figaCount] = arg[5];\n\t\t++figaCount;\n\t\treturn;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(clone());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_fld2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\tif (label) drawText(35, 1, 1, label);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"inAnchor\":\n\tcase \"compact\":\n\tcase \"L\":\n\t\treturn 0;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"D\":\n\t\tset(\"content2\", self());/*a kludge to deal with cloning*/\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);/* necessary ...*/\n\t\tsend(self(), \"setStyles\");\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (canFold && folded) {\n\t\t\t/* make the first list item go away,\n\t\t\t * to show the toggler */\n\t\t\tsend(nthChild(1), \"R\", 30, get(\"width\"));\n\t\t\tsend(nthChild(0), \"setFolded\", 1);\n\t\t\tset(\"height\", 20);\n\t\t\treturn 20;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tif (foldInfo == 0) {\n\t\t\tsend(self(), \"reInit\");\n\t\t\tif (label) drawText(35, 1, 1, label);\n\t\t}\n\n\t\tif (canFold) vspan += 18;\n\t\tif (canFold == 0 || folded == 0) {\n\t\t\tn = countChildren();\n\t\t\tif (n > canFold) {\n\t\t\t\txx = get(\"width\");\n\t\t\t\tfor (i = canFold; i < n; i++)\n\t\t\t\t  vspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t\t}\n\t\t}\n\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"folded\":\n\t\tif (foldInfo == 0) send(self(), \"reInit\");\n\t\tfolded = arg[1];\n\t\tsend(send(parent(), \"findTop\"), \"resizeSelf\");\n\t\treturn;\n\tbreak;\n\tcase \"toggleFolded\":\n\t\tif (foldInfo == 0) send(self(), \"reInit\");\n\t\tif (folded) folded = 0;\n\t\telse folded = 1;\n\t\tsend(send(parent(), \"findTop\"), \"resizeSelf\");\n\t\treturn folded;\n\tbreak;\n\tcase \"folded?\":\n\t\treturn folded;\n\tbreak;\n\tcase \"canFold?\":\n\t\treturn canFold;\n\tbreak;\n\tcase \"label?\":\n\t\treturn label;\n\tbreak;\n\tcase \"setAnchor\":\n\t\tmakeAnchor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"editMode\":\n\t\teditMode = arg[1];\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\tfor (i = canFold; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"editMode\", editMode);\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"LABEL\":\n\t\t\tlabel = arg[2];\n\t\tbreak;\n\t\tcase \"FOLD\":\n\t\t\tcanFold = 1;\n\t\t\tif (arg[2] == \"yes\" || arg[2] == \"YES\") folded = 1;\n\t\t\tset(\"BDColor\", get(\"FGColor\"));\n\t\t\tnew = send(\"HTML__foldIcon\", \"make\", self());\n\t\t\tset(\"children\", new);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\tfor (i = canFold; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\tfor (i = canFold; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"placeID\":\n\t\t/* this is clumsy. should be simplified with a primitive f() */\n\t\t/* find the caller (child) object's place in the obj list */\n\t\tcobj = arg[1];\n\t\tobjPlace = -1;\n\n\t\tfor (i = objectListCount_children() - 1; i >= 0; i--) {\n\t\t\tnobj = nthChild(i);/*bug: can't inline into == XXX*/\n\t\t\tif (cobj == nobj) {\n\t\t\t\tobjPlace = i;\n\t\t\t}\n\t\t}\n\t\tobjPlacePath = concat(objPlace, \" \", arg[2]);\n\t\treturn send(parent(), \"placeID\", self(), objPlacePath);\n\tbreak;\n\tcase \"edit_gotoPrev\":\n\t\tcobj = arg[1];\n\t\tobjPlace = -1;\n\t\tfor (i = objectListCount_children() - 1; i >= 0; i--) {\n\t\t\tnobj = nthChild(i);/*bug: can't inline into == XXX*/\n\t\t\tif (cobj == nobj) {\n\t\t\t\tobjPlace = i;\n\t\t\t}\n\t\t}\n\t\tsend(nthChild(objPlace-1), \"edit_focus\");\n\t\treturn;\n\tbreak;\n\tcase \"edit_gotoNext\":\n\t\tcobj = arg[1];\n\t\tobjPlace = -1;\n\n\t\tfor (i = objectListCount_children() - 1; i >= 0; i--) {\n\t\t\tnobj = nthChild(i);/*bug: can't inline into == XXX*/\n\t\t\tif (cobj == nobj) {\n\t\t\t\tobjPlace = i;\n\t\t\t}\n\t\t}\n/*\n\tif no next child, ask parent to goto next (then down to\n\tsuitable editable element)...\nprint(\"CCCCCCCCCC objPlace=\", objPlace, \"\\n\");\nprint(\"CCCCCCCCCC o(objPlace)=\", nthChild(objPlace), \"\\n\");\nprint(\"CCCCCCCCCC o(objPlace+1)=\", nthChild(objPlace+1), \"\\n\");\n*/\n\n\t\tsend(nthChild(objPlace+1), \"edit_focus\");\n\t\treturn;\n\tbreak;\n\tcase \"CE_change\":\n\t\treturn send(nthChild(nthWord(arg[1], 1)), arg[0],\n\t\t\t\tnthWord(arg[1], 2, 99), arg[2]);\n\tbreak;\n\tcase \"CE_lock\":\n\tcase \"CE_unlock\":\n\t\treturn send(nthChild(nthWord(arg[1], 1)), arg[0],\n\t\t\t\tnthWord(arg[1], 2, 99));\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<SECTION>\\n\");\n\t\tn = countChildren();\n\t\tif (n) for (i = 0; i < n; i++)\n\t\t\t\tsend(nthChild(i), \"outputSGML\");\n\t\tprint(\"</SECTION>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"setStyles\":\n\t\ttagPtr = STG_tagPtr(\"SECTION\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"border\");\n\t\t\tif (i) {\n\t\t\t\tset(\"border\", 6);\n\t\t\t\tset(\"BDColor\", get(\"FGColor\"));/*XXX*/\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"reInit\":\n\t\t/*HIGH KLUDGE-- to know if clone has occured*/\n\t\tfoldInfo = 1;\n\t\to = object(get(\"content2\"));\n\t\tif (o) {\n\t\t\tcanFold = send(o, \"canFold?\");\n\t\t\tfolded = send(o, \"folded?\");\n\t\t\tlabel = send(o, \"label?\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tfoldInfo = 1;\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_fld[] = {
    {"class", _slotValue_HTML_fld0},
    {"name", _slotValue_HTML_fld1},
    {"script", _slotValue_HTML_fld2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_footnote0[] = "HTML_footnote";
static char _slotValue_HTML_footnote1[] = "field";
static char _slotValue_HTML_footnote2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tnew = send(\"HTML_footnote.ft\", \"clone\");\n\t\tsend(new, \"make\", get(\"label\"));\n\t\tt = concat(\"\\\\o(\", new, \")\");\n\t\treturn t;\n\tbreak;\n\tcase \"AI\":\n\tcase \"AA\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_HTML_footnote4[] = "HTML_footnote.ft";
static char _slotValue_HTML_footnote5[] = "XBM";
static char _slotValue_HTML_footnote6[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonPress\":\n\t\tset(\"BDColor\", \"red\");\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tres.dialogWithButtons(\"show\", get(\"content\"), \"OK\", \"\");\n\t\tset(\"BDColor\", \"LemonChiffon1\");\n\tbreak;\n\tcase \"make\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<FOOTNOTE>\", get(\"content\"), \"</FOOTNOTE>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\tcolor = getResource(\"Viola.borderColor_doc\");\n\t\tif (color) set(\"BDColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_footnote7[] = "\n#define ft_width 10\n#define ft_height 10\nstatic char ft_bits[] = {\n   0x1f, 0x00, 0x29, 0x00, 0x6f, 0x00, 0x89, 0x00, 0xff, 0x00, 0x81, 0x00,\n   0xff, 0x00, 0x81, 0x00, 0xff, 0x00, 0x00, 0x00};\n";
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
static char _slotValue_HTML_form2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\th = 0;\n/*\t\tSGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\tif (inPreP) txt = get(\"label\");\n\t\t\telse txt = compressSpaces(get(\"label\"));\n\t\t\th = send(txtObj, \"make\", self(), txt,\n\t\t\t\t style[3], \n\t\t\t\t get(\"width\") - style[3] - style[2],\n\t\t\t\t SGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\tif (inPreP) txt = get(\"label\");\n\t\t\telse txt = compressSpaces(get(\"label\"));\n\t\t\th += send(txtObj, \"make\", self(), txt,\n\t\t\t\t style[3], \n\t\t\t\t get(\"width\") - style[3] - style[2],\n\t\t\t\t h, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n/*\n\t\ttagPtr = STG_tagPtr(\"FORM\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n/*\t\tnew = send(\"HTML_form.op\", \"clone\", self());\n\t\thh = send(new, \"make\", self(), get(\"width\") - 4, h);\n\t\tobjectListAppend_children(new);\n\t\tset(\"height\", h + hh);\n\t\treturn h + hh;\n*/\n\t\treturn h;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\") - 4;\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\tid = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"METHOD\":\n\t\t\tmethod = arg[2];\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"ACTION\":\n\t\t\taction = arg[2];\n\t\tbreak;\n\t\tcase \"BORDER\":\n\t\t\tset(\"BDColor\", get(\"FGColor\"));\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"regInputer\":\n\t\t/* every input object within the form reports to the form,\n\t\t * so that at submission time, the form can query the input\n\t\t * objects for values.\n\t\t */\n\t\tinputers[icount] = arg[1];\n/*\t\tval = send(inputers[icount], \"value\");*/\n\t\ticount++;\n\t\treturn icount - 1;\n\tbreak;\n\tcase \"resetForm\":\n\t\tfor (i = 0; i < icount; i++) send(inputers[i], \"reset\");\n\t\treturn;\n\tbreak;\n\tcase \"acceptForm\":\n\t\tif (action != \"\") {\n\t\t\tif (findPattern(action, \"mailto:\") != -1) {\n\t\t\t\t/* EMail results\n\t\t\t\t */\n\t\t\t\turl = subject = send(send(parent(),\n\t\t\t\t\t\t\t\"findTop\"),\n\t\t\t\t\t\t\t \"query_docURL\");\n\t\t\t\tsubject = url;\n\t\t\t\taddress = nthChar(action, 7, 999);\n\t\t\t\tcontent = concat(\"Form URL : \", url, \"\\n\\n\",\n\t\t\t\t\t\t \"Action   : \", action, \"\\n\");\n\n\t\t\t\tfor (i = 0; i < icount; i++) {\n\t\t\t\t\tval = send(inputers[i], \"value\");\n\t\t\t\t\tif (val != 0) \n\t\t\t\t\t  content = concat(mh, '\\n', \n\t\t\t\t\t\t\t   content, \n\t\t\t\t\t\t\t   val, '\\n');\n\t\t\t\t}\n\t\t\t\t\n\t\t\t\ttmpFile = makeTempFile();\n\t\t\t\tsaveFile(tmpFile, content);\n\n\t\t\t\twwwSecurity(\"mailFileContentTo,rmFile\",\n\t\t\t\t\t    address, subject, tmpFile);\n\t\t\t} else {\n\t\t\t\t/* Compress results into one-liner. Ick!\n\t\t\t\t */\n\t\t\t\tcontent = \"\";\n\t\t\t\tfor (i = 0; i < icount; i++) {\n\t\t\t\t\tval = send(inputers[i], \"value\");\n/*print(\"FORM VALUE >>>>>>>\", val, \"<<<\\n\");*/\n\t\t\t\t\tif (val != 0)\n\t\t\t\t\t  if(i == 0) {\n\t\t\t\t\t\tcontent = concat(content, \n\t\t\t\t\t\t                 val);\n\t\t\t\t\t  } else {\n\t\t\t\t\t\tcontent = concat(content,\n\t\t\t\t\t\t\t\t '&', val);\n\t\t\t\t\t  }\n\t\t\t\t}\n\t\t\t\tcontent = concat(content, \"\\n\");\n\n\t\t\t\tif (method == \"POST\") {\n/*print(\"FORM POST HREF N DATA >>>>>>>\", concat(action, '?', content), \"<<<\\n\");\n*/\n\t\t\t\t\tsend(send(parent(), \"findTop\"), \n\t\t\t\t\t\t\"post_href_n_data\",\n\t\t\t\t\t\taction, content);\n\t\t\t\t} else {\n/*print(\"FORM FOLLOW HREF >>>>>>>\", concat(action, '?', content), \"<<<\\n\");*/\n\t\t\t\t\tsend(send(parent(), \"findTop\"), \n\t\t\t\t\t\t\"follow_href\", \n\t\t\t\t\t\tconcat(action, '?', content));\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"findForm\":\n\t\treturn self();\n\tbreak;\n\tcase \"reportMailHeader\":\n\t\tmh = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"radioReg\":\n\t\t/* arg[1]\tname of radio group\n\t\t * arg[2]\tradio (input) object to be added to group\n\t\t */\n\t\tradioID[radioi] = arg[1];\n\t\tradioObj[radioi] = arg[2];\n\t\tradioi++;\n\t\treturn;\n\tbreak;\n\tcase \"radioOnReq\":\n\t\t/* arg[1]\tradio group index\n\t\t * arg[2]\tthe radio (input) object to be turned ON\n\t\t */\n\t\tradioGroupName = arg[1];\n\t\tfor (i = 0; i < radioi; i++)\n\t\t\tif (radioID[i] == radioGroupName)\n\t\t\t\tsend(radioObj[i], \"radioOff\");\n\t\tsend(arg[2], \"radioOn\");\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<FORM\");\n\t\tif (id) print(\" ID=\\\"\", id, \"\\\"\");\n\t\tif (action) print(\" ACTION=\\\"\", action, \"\\\"\");\n\t\tif (method) print(\" METHOD=\\\"\", method, \"\\\"\");\n\t\tif (get(\"maxWidth\") < 9999) \n\t\t\t\tprint(\" MAXWIDTH=\", get(\"maxWidth\"));\n\t\tif (get(\"minWidth\") < 9999) \n\t\t\t\tprint(\" MINWIDTH=\", get(\"minWidth\"));\n\t\tprint(\">\\n\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tsend(nthChild(i), \"outputSGML\");\n\t\t}\n\t\tprint(\"</FORM>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_form[] = {
    {"class", _slotValue_HTML_form0},
    {"name", _slotValue_HTML_form1},
    {"script", _slotValue_HTML_form2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_gif0[] = "GIF";
static char _slotValue_HTML_gif1[] = "HTML_gif";
static char _slotValue_HTML_gif2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tlocalFile = HTTPGet(get(\"label\"));\n\t\ttop = send(parent(), \"findTop\");\n\t\turl = send(top, \"query_docURL\");\n\n\t\t/* to get the gif in its natural dimension (lame) */\n\t\tset(\"width\", 0);\n\t\tset(\"height\", 0);\n\n\t\tset(\"label\", localFile, url);\n\t\tsystem(concat(\"rm -f \", localFile));\n\n\t\treturn get(\"height\");\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"IMG\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"label\", get(\"label\"), url);\n\t\tvspan += get(\"height\") + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"buttonPress\":\n\t\txy = mouseLocal();\n\t\tx0 = xy[0];\n\t\ty0 = xy[1];\n\t\tset(\"FGColor\", \"black\");\n\t\tdrawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\t\tdrawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\t\tset(\"FGColor\", \"white\");\n\t\tdrawLine(x0, y0 - 5, x0, y0 + 5);\n\t\tdrawLine(x0 + 5, y0, x0 - 5, y0);\n\tbreak;\n\tcase \"buttonRelease\":\n\t\txy = mouseLocal();\n\t\tx1 = xy[0];\n\t\ty1 = xy[1];\n\t\tref = concat(url, \"?\", x0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\n\t\tset(\"FGColor\", \"black\");\n\t\tdrawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\t\tdrawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\t\tset(\"FGColor\", \"white\");\n\t\tdrawLine(x1, y1 - 5, x1, y1 + 5);\n\t\tdrawLine(x1 + 5, y1, x1 - 5, y1);\n\t\tsend(top, \"follow_href\", ref);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_giff2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tset(\"y\", arg[1]);\n\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGURE\");\n\t\tvspan = style[0] + get(\"height\") + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tw\n\t\t * arg[3]\ty\n\t\t * arg[4]\tdocURL\n\t\t * arg[5]\tdelayP\n\t\t * arg[6]\tdelayWidth\n\t\t * arg[7]\tdelayHeight\n\t\t * arg[8]\tismap\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[2]);\n\t\tset(\"y\", arg[3]);\n\t\tismap = arg[8];\n\n\t\turlParts = HTTPCurrentDocAddrParsed(arg[4]);\n\t\timgURL = concat(urlParts[0], \"://\", urlParts[1], \n\t\t\t\turlParts[2], urlParts[3]);\n\n\t\t/* to get the gif in its natural dimension */\n\t\tset(\"width\", 0);\n\t\tset(\"height\", 0);\n\n\t\tset(\"label\", imgURL, imgURL);\n\t\tsystem(concat(\"rm -f \", localFile));\n\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"addFigA\":\n\t\tnew = send(\"HTML_figa_actual\", \"clone\");\n\t\tsend(new, \"make\", self(), \n\t\t\targ[1], arg[2], arg[3], arg[4], arg[5]);\n\t\tobjectListAppend(\"children\", new);\n\t\treturn;\n\tbreak;\n\tcase \"hintOn\":\n\t\treturn send(parent(), \"hintOn\", arg[1]);\n\tbreak;\n\tcase \"hintOff\":\n\t\treturn send(parent(), \"hintOff\");\n\tbreak;\n\tcase \"buttonPress\":\n\t\tif (ismap) {\n\t\t\txy = mouseLocal();\n\t\t\tx0 = xy[0];\n\t\t\ty0 = xy[1];\n\t\t\tset(\"FGColor\", \"black\");\n\t\t\tdrawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\t\t\tdrawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\t\t\tset(\"FGColor\", \"white\");\n\t\t\tdrawLine(x0, y0 - 5, x0, y0 + 5);\n\t\t\tdrawLine(x0 + 5, y0, x0 - 5, y0);\n\t\t}\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tif (ismap) {\n\t\t\txy = mouseLocal();\n\t\t\tx1 = xy[0];\n\t\t\ty1 = xy[1];\n\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\tref = concat(send(top, \"query_docURL\"), \"?\",\n\t\t\t\t\tx0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\t\t\tset(\"FGColor\", \"black\");\n\t\t\tdrawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\t\t\tdrawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\t\t\tset(\"FGColor\", \"white\");\n\t\t\tdrawLine(x1, y1 - 5, x1, y1 + 5);\n\t\t\tdrawLine(x1 + 5, y1, x1 - 5, y1);\n\t\t\tsend(top, \"follow_href\", ref);\n\t\t}\n\tbreak;\n\tcase \"invertBox\":\n\t\tinvertRect(arg[1], arg[2], arg[3], arg[4]);\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_head2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\tcase \"F\":\n\t\treturn -1;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"HEAD\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = width();\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\": /* useless? */\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"inPreP\":\n\tcase \"inAnchor\":/*XXX*/\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_head[] = {
    {"class", _slotValue_HTML_head0},
    {"name", _slotValue_HTML_head1},
    {"script", _slotValue_HTML_head2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_header_big0[] = "txtDisp";
static char _slotValue_HTML_header_big1[] = "HTML_header_big";
static char _slotValue_HTML_header_big2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\treturn expose();\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"H1\");\n\t\tvspan = style[0];\n\t\tset(\"width\", width() - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tclearWindow();\n\t\trender();/*may be extraneous */\n\t\tvspan += set(\"height\", building_vspan()+2) + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"inAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"setAnchor\":\n\t\ttagID = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tif (tagIDCount > 0)\n\t\t\tfor (i = 0; i < tagIDCount; i++)\n\t\t\t\tif (tagIDs[i] == arg[1]) return get(\"y\");\n\t\treturn 0;\n\tbreak;\n\tcase \"D\": /* done */\n/*\t\tSGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\t\tif (isBlank(get(\"label\"))) return 0;\n\n\t\tsend(self(), \"setStyles\");\t/* stylesheet stuff */\n\n\t\turl = send(parent(), \"inAnchor\");\n\n\t\tinPreP = send(parent(), \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\tif (url) {\n\t\t\tt = concat(\" \\\\b(\", trimEdgeQ(get(\"label\")),\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t} else {\n\t\t\tt = trimEdgeQ(get(\"label\"));\n\t\t}\n\t\tset(\"content\", t);\n\t\tset(\"label\", \"\");\n\t\treturn building_vspan()+2;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<H1\");\n\t\tif (tagID) print(\" NAME=\\\"\", tagID, \"\\\">\");\n\t\telse print(\">\");\n\t\tprint(get(\"content\"), \"</H1>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"ALIGN\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"center\":\n\t\t\t\tset(\"paneConfig\", \"center\");\n\t\t\tbreak;\n\t\t\tcase \"left\":\n\t\t\t\tset(\"paneConfig\", \"westToEast\");\n\t\t\tbreak;\n\t\t\tcase \"right\":\n\t\t\t\tset(\"paneConfig\", \"eastToWest\");\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"setStyles\":\n\t\tuseTagInfo_align = 1;\n\t\ttagPtr = STG_tagPtr(\"H1\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"fontSlant\");\n\t\t\tif (i) {\n\t\t\t\tswitch (i) {\n\t\t\t\tcase \"italic\": \tset(\"font\", i);\tbreak;\n\t\t\t\tcase \"bold\": \tset(\"font\", i);\tbreak;\n\t\t\t\tdefault:\n\t\t\t\tcase \"normal\":\tset(\"font\", i);\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\ti = STG_attr(tagPtr, \"align\");\n\t\t\tif (i) {\n\t\t\t\tuseTagInfo_align = 0;\n\t\t\t\tswitch (i) {\n\t\t\t\tcase \"center\":\n\t\t\t\t\tset(\"paneConfig\", \"center\");\n\t\t\t\tbreak;\n\t\t\t\tcase \"left\":\n\t\t\t\t\tset(\"paneConfig\", \"westToEast\");\n\t\t\t\tbreak;\n\t\t\t\tcase \"right\":\n\t\t\t\t\tset(\"paneConfig\", \"eastToWest\");\n\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\n\tcase \"runAwayFromHome\":\n\t\treturn send(parent(), \"deleteChild\", self());\n\tbreak;\n\tcase \"buttonPress\":\n\t\tif (editMode) {\n\t\t  if (mxy[0] < 3 && mxy[1] < 3) {\n\t\t\tprint(\"HTML_txt: GRAB\\n\");\n\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\tsend(top, \"wedgeMeIn\", self());\n\t\t\treturn;\n\t\t  } else {\n\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\tplid = send(parent(), \"placeID\", self(), \"\");\n\t\t\tsend(top, \"lock\", self(), plid);\n\t\t\tif (lock == 1) {\n\t\t\t\t/* unlock */\n\t\t\t\tset(\"BDColor\", get(\"BGColor\"));\n\t\t\t\tset(\"cursor\", 0);\n\t\t\t\tlock = 0;\n\t\t\t\treturn;\n\t\t\t} else {\n\t\t\t\t/* lock */\n\t\t\t\tset(\"BDColor\", \"red\");\n\t\t\t\tset(\"cursor\", 1);\n\t\t\t\tlock = 1;\n\t\t\t}\n\t\t  }\n\t\t}\n\tbreak;\n\tcase \"edit_focus\":\n\t\twxy = windowPosition();\n\t\tsetMouse(wxy[0] + 2, wxy[1] + 2);\n\t\treturn;\n\tbreak;\n\tcase \"keyPress\":\n\t\tif (editMode) {\n\t\t\tc = key();\n\t\t\tif (c == '\\r') {\n\t\t\t\tinsert(key());\n\t\t\t\tset(\"content\", get(\"content\"));\n\t\t\t\th = building_vspan();\n\t\t\t\tprint(\"BUILDING_VSPAN=\", h, \"\\n\");\n\t\t\t\tset(\"height\", h);\n\t\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\t\tsend(top, \"resizeSelf\");\n\t\t\t\tplid = send(parent(), \"placeID\", self(), \"\");\n\n\t\t\t\tnewTxt = get(\"content\");\n\t\t\t\tset(\"content\", newTxt);\n\n\t\t\t\tsend(top, \"change\", self(), plid, newTxt);\n\t\t\t} else if (c == '\\t') {\n\t\t\t\tif (shiftKeyP()) {\n\t\t\t\t\tsend(parent(), \"edit_gotoPrev\", \n\t\t\t\t\t\tself());\n\t\t\t\t} else {\n\t\t\t\t\tsend(parent(), \"edit_gotoNext\", \n\t\t\t\t\t\tself());\n\t\t\t\t}\n\t\t\t\t/*\n\t\t\t\tsend(parent(),\n\t\t\t\t\teither (shiftKeyP())\n\t\t\t\t\t\t{\"edit_gotoPrev\"}\n\t\t\t\t\t\t{\"edit_gotoNext\"},\n\t\t\t\t\tself());\n\t\t\t\t*/\n\t\t\t} else {\n\t\t\t\tinsert(key());\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"CE_change\":\n\t\tnewData = arg[2];\n\t\tset(\"content\", newData);\n\t\th = building_vspan();\n\t\tprint(\"RE_BUILDING_VSPAN=\", h, \"\\n\");\n\t\tset(\"height\", h);\n\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\tsend(top, \"resizeSelf\");\n\t\treturn;\n\tbreak;\n\tcase \"CE_lock\":\n\t\tif (lock == 0) {\n\t\t\tset(\"BDColor\", \"yellow\");\n\t\t}\n\t\treturn;\t\t\n\tbreak;\n\tcase \"CE_unlock\":\n\t\tif (lock == 0) {\n\t\t\tset(\"BDColor\", get(\"BGColor\"));\n\t\t}\n\t\treturn;\t\t\n\tbreak;\n\tcase \"enter\":\n/*\t\tif (editMode && lock) {\n\t\t\tset(\"cursor\", 1);\n\t\t}\n*/\n\t\tif (editMode) {\n\t\t\tset(\"cursor\", 1);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n/*\t\tif (editMode && lock) {*/\n\t\tif (editMode) {\n\t\t\tset(\"cursor\", 0);\n/*\n\t\t\tset(\"BDColor\", get(\"BGColor\"));\n\t\t\tset(\"cursor\", 0);\n\t\t\tif (lock == 1) {\n\t\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\t\tplid = send(parent(), \"placeID\", self(), \"\");\n\t\t\t\tsend(top, \"unlock\", self(), plid);\n\t\t\t\tlock = 0;\n\t\t\t}\n*/\n\t\t} else {\n\t\t\tprevHint = 0;\n\t\t\twww.mesg.tf(\"clear\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"editMode\":\n\t\teditMode = arg[1];\n\t\treturn;\n\tbreak;\n\n\t}\n\treturn code_HTML_header_large(arg);\n";
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
static char _slotValue_HTML_header_medium2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\texpose(arg[1], arg[2], arg[3], arg[4]);\n\t\treturn;\n\tbreak;\n\tcase \"setAnchor\":\n\t\ttagID = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"inAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tif (tagIDCount > 0)\n\t\t\tfor (i = 0; i < tagIDCount; i++)\n\t\t\t\tif (tagIDs[i] == arg[1]) return get(\"y\");\n\t\treturn 0;\n\tbreak;\n\tcase \"D\": /* done */\n\t\tif (isBlank(get(\"label\"))) return 0;\n\t\tsend(self(), \"setStyles\");\t/* stylesheet stuff */\n\t\tinPreP = send(parent(), \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\tset(\"content\", trimEdgeQ(get(\"label\")));\n\t\tset(\"label\", \"\");\n\t\treturn building_vspan()+2;\t\n\tbreak;\n\tcase \"setStyles\":\n\t\tuseTagInfo_align = 1;\n\t\ttagPtr = STG_tagPtr(\"H2\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"fontSlant\");\n\t\t\tif (i) {\n\t\t\t\tswitch (i) {\n\t\t\t\tcase \"italic\": \tset(\"font\", i);\tbreak;\n\t\t\t\tcase \"bold\": \tset(\"font\", i);\tbreak;\n\t\t\t\tdefault:\n\t\t\t\tcase \"normal\":\tset(\"font\", i);\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\ti = STG_attr(tagPtr, \"align\");\n\t\t\tif (i) {\n\t\t\t\tuseTagInfo_align = 0;\n\t\t\t\tswitch (i) {\n\t\t\t\tcase \"center\":\n\t\t\t\t\tset(\"paneConfig\", \"center\");\n\t\t\t\tbreak;\n\t\t\t\tcase \"left\":\n\t\t\t\t\tset(\"paneConfig\", \"westToEast\");\n\t\t\t\tbreak;\n\t\t\t\tcase \"right\":\n\t\t\t\t\tset(\"paneConfig\", \"eastToWest\");\n\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<H2\");\n\t\tif (tagID) print(\" NAME=\\\"\", tagID, \"\\\"\");\n\t\tprint(\">\", get(\"content\"), \"</H2>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"ALIGN\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"center\":\n\t\t\t\tset(\"paneConfig\", \"center\");\n\t\t\tbreak;\n\t\t\tcase \"left\":\n\t\t\t\tset(\"paneConfig\", \"westToEast\");\n\t\t\tbreak;\n\t\t\tcase \"right\":\n\t\t\t\tset(\"paneConfig\", \"eastToWest\");\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\t}\n\treturn code_HTML_header_medium(arg);\n";
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
static char _slotValue_HTML_header_small2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\treturn expose();\n\tbreak;\n\tcase \"setAnchor\":\n\t\ttagID = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"inAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tif (tagIDCount > 0)\n\t\t\tfor (i = 0; i < tagIDCount; i++)\n\t\t\t\tif (tagIDs[i] == arg[1]) return get(\"y\");\n\t\treturn 0;\n\tbreak;\n\tcase \"D\": /* done */\n/*\t\tSGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\t\tif (isBlank(get(\"label\"))) return 0;\n\t\tsend(self(), \"setStyles\");\t/* stylesheet stuff */\n\t\tinPreP = send(parent(), \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\tset(\"content\", trimEdgeQ(get(\"label\")));\n\t\tset(\"label\", \"\");\n\t\treturn building_vspan()+2;\n\tbreak;\n\tcase \"setStyles\":\n\t\tuseTagInfo_align = 1;\n\t\ttagPtr = STG_tagPtr(\"H3\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"fontSlant\");\n\t\t\tif (i) {\n\t\t\t\tswitch (i) {\n\t\t\t\tcase \"italic\": \tset(\"font\", i);\tbreak;\n\t\t\t\tcase \"bold\": \tset(\"font\", i);\tbreak;\n\t\t\t\tdefault:\n\t\t\t\tcase \"normal\":\tset(\"font\", i);\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\ti = STG_attr(tagPtr, \"align\");\n\t\t\tif (i) {\n\t\t\t\tuseTagInfo_align = 0;\n\t\t\t\tswitch (i) {\n\t\t\t\tcase \"center\":\n\t\t\t\t\tset(\"paneConfig\", \"center\");\n\t\t\t\tbreak;\n\t\t\t\tcase \"left\":\n\t\t\t\t\tset(\"paneConfig\", \"westToEast\");\n\t\t\t\tbreak;\n\t\t\t\tcase \"right\":\n\t\t\t\t\tset(\"paneConfig\", \"eastToWest\");\n\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<H3\");\n\t\tif (tagID) print(\" NAME=\\\"\", tagID, \"\\\"\");\n\t\tprint(\">\", get(\"content\"), \"</H3>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"ALIGN\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"center\":\n\t\t\t\tset(\"paneConfig\", \"center\");\n\t\t\tbreak;\n\t\t\tcase \"left\":\n\t\t\t\tset(\"paneConfig\", \"westToEast\");\n\t\t\tbreak;\n\t\t\tcase \"right\":\n\t\t\t\tset(\"paneConfig\", \"eastToWest\");\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\t}\n\treturn code_HTML_header_small(arg);\n";
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
static char _slotValue_HTML_hpane2[] = "\n\tswitch (arg[0]) {\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"F\": /* flush */\n/*\t\tSGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\tsend(txtObj, \"make\", self(), \n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], width() - style_p[3] - style_p[2],\n\t\t\t\t0, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\treturn -1;\n\tbreak;\n\tcase \"D\":\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\tsend(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], width() - style_p[3] - style_p[2],\n\t\t\t\t0, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n/*\n\t\ttagPtr = STG_tagPtr(\"HPANE\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"HPANE\");\n\t\tvspan = style[0];\n\t\tconfig();\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = (get(\"width\") - 10) / 2;\n\t\t\tcy = style[1];\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\th = send(nthChild(i), 'r');\n\t\t\t\tif (h > vspan) vspan = h;\n\t\t\t}\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"HPANE\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tconfig();\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = (get(\"width\") - 10) / 2;\n\t\t\tcy = style[1];\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\th = send(nthChild(i), \"r\");\n\t\t\t\tif (h > vspan) vspan = h;\n\t\t\t}\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"r\":\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"HPANE\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_hpane[] = {
    {"class", _slotValue_HTML_hpane0},
    {"name", _slotValue_HTML_hpane1},
    {"script", _slotValue_HTML_hpane2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_hr0[] = "field";
static char _slotValue_HTML_hr1[] = "HTML_hr";
static char _slotValue_HTML_hr2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\tcase \"D\":\n\t\treturn 1;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"HR\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tvspan += get(\"height\") + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<HR>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"BGColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_hr3[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_hr[] = {
    {"class", _slotValue_HTML_hr0},  {"name", _slotValue_HTML_hr1}, {"script", _slotValue_HTML_hr2},
    {"height", _slotValue_HTML_hr3}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_ignore0[] = "field";
static char _slotValue_HTML_ignore1[] = "HTML_ignore";
static char _slotValue_HTML_ignore2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\treturn \"\";\n\tbreak;\n\tcase \"AA\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_ignore[] = {
    {"class", _slotValue_HTML_ignore0},
    {"name", _slotValue_HTML_ignore1},
    {"script", _slotValue_HTML_ignore2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_img0[] = "field";
static char _slotValue_HTML_img1[] = "HTML_img";
static char _slotValue_HTML_img2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn 0;\n\tbreak;\n\tcase 'i':\n\t\t/*local_src = cache_cheat(\"local\", src);*/\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\n\t\tif (src) {\n\t\t\tif (ismap) {\n\t\t\t\tnew = send(\"HTML__img\", \"clone\");\n\t\t\t\tif (exist(\"HTML_txtAnchor\"))\n\t\t\t\t  actionURL = send(\"HTML_txtAnchor\", \"url\");\n\t\t\t\telse\n\t\t\t\t  actionURL = 0;\n\t\t\t\tsend(new, \"make\", self(), src, actionURL);\n\t\t\t\tret = concat(\"\\\\o(\", new, \")\");\n\t\t\t\tismap = 0;\n\t\t\t} else {\n\t\t\t\tret = concat(\"\\\\p(\", src, ')');\n\t\t\t}\n\t\t} else {\n\t\t\tret = \"\";\n\t\t}\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\t\treturn ret;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"SRC\":\n\t\t\trel_url = arg[2];\n\t\t\turlParts = HTTPCurrentDocAddrParsed(rel_url);\n\t\t\tsrc = concat(urlParts[0], \"://\", urlParts[1], \n\t\t\t\turlParts[2], urlParts[3]);\n\t\tbreak;\n\t\tcase \"HREF\":\n\t\t\thref = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"ISMAP\":\n\t\t\tismap = 1;\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"AI\":\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"config\":\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_HTML_img4[] = "GIF";
static char _slotValue_HTML_img5[] = "HTML__img";
static char _slotValue_HTML_img6[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\treturn expose();\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\timg url\n\t\t * arg[3]\taction url\n\t\t */\n\t\tactionURL = arg[3];\n\n\t\tset(\"parent\", arg[1]);\n\n\t\t/* to get the gif in its natural dimension */\n\t\tset(\"width\", 0);\n\t\tset(\"height\", 0);\n\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\n\t\turlParts = HTTPCurrentDocAddrParsed(arg[2]);\n\t\timgURL = concat(urlParts[0], \"://\", urlParts[1], \n\t\t\t\turlParts[2], urlParts[3]);\n\n\t\tset(\"label\", imgURL, imgURL);\n\t\tset(\"height\", get(\"height\"));\n\n\t\tsend(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\t\treturn self();\n\tbreak;\n\tcase \"buttonPress\":\n\t\txy = mouseLocal();\n\t\tx0 = xy[0];\n\t\ty0 = xy[1];\n\t\tset(\"FGColor\", \"red\");\n\t\tdrawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\t\tdrawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\t\tset(\"FGColor\", \"white\");\n\t\tdrawLine(x0, y0 - 5, x0, y0 + 5);\n\t\tdrawLine(x0 + 5, y0, x0 - 5, y0);\n\t\tif (actionURL != 0) {\n\t\t\tsend(\"www\", \"show\", \n\t\t\t\tconcat(actionURL, \"?\", x0, \",\", y0));\n\t\t} else {\n\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\tref = concat(send(top, \"query_docURL\"), \"?\",\n\t\t\t\t\tx0, \",\", y0);\n\t\t\tsend(top, \"follow_href\", ref);\n\t\t}\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input2[] = "\n/*\nprint(\"HTML_input: self=\", self(), \"\\n\");\nfor(i=0;i<arg[];i++) print(\"arg[\",i,\"]={\",arg[i],\"}\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tnew = send(self(), \"clone\");\n\t\tif (defaultRows == 0) defaultRows = 1;\n\t\tif (inputObj == 0) inputObj = \"HTML_input_str\";\n\t\tif (objWidth == 0) objWidth = 300;\n\t\t/* inlined objects don't instantiate clones and have\n\t\t * the clone inserted in the holding object's children list\n\t\t * as usual objects do. So, need to tell parent to adopt\n\t\t * the clone that is created here ... don't work. b/c not\n\t\t * all parents are created then...\n\t\t */\n\t\tsend(new, \"make\", inputObj, tagID, defaultVal, \n\t\t\tdefaultRows, objWidth, objHeight, isRadio, \n\t\t\tchecked, disabled, checkWidth, src);\n\t\tt = concat(\"\\\\o(\", new, \")\");\n\n\t\t/* reset defaults */\n\t\ttagID = \"\";\n\t\tinputObj = \"HTML_input_str\";\n\t\tdefaultVal = \"\";\n\t\tdefaultRows = 1;\n\t\tobjWidth = 0;\n\t\tobjHeight = 22;\n\t\tisRadio = 0;\n\t\tchecked = 0;\n\t\tdisabled = 0;\n\t\tcheckWidth = 0;\n\t\tsrc = 0;\n\t\treturn t;\n\tbreak;\n\tcase \"make\":\n\t\tinputObj = arg[1];\n\t\ttagID = arg[2];\n\t\tdefaultVal = arg[3];\n\t\tdefaultRows = arg[4];\n\t\tset(\"width\", arg[5]);\n\t\tset(\"height\", arg[6]);\n\t\tisRadio = arg[7];\n\t\tchecked = arg[8];\n\t\tdisabled = arg[9];\n\t\tcheckWidth = arg[10];\n\t\tsrc = arg[11];\n/*\n\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tif (defaultVal == 0) defaultVal = \"\";/* could be a bad idea*/\n\n\t\tif (checked) defaultVal = 1;\n\n\t\tif (inputObj == -1) return 0; /* ignore */\n\t\tif (inputObj == 0) inputObj = \"HTML_input_str\";\n\n\t\t/* width should really be fed back from the input widgets\n\t\t */\n\t\tif (checkWidth) {\n\t\t\tset(\"width\", textWidth(1, defaultVal) + 10);\n\t\t}\n\n\t\tnew = send(inputObj, \"clone\");\n\t\tobjectListAppend_children(new);\n\t\th = send(new, \"make\", self(), defaultVal,\n\t\t\tget(\"width\") - 2, defaultRows * 22,\n\t\t\tchecked, disabled);\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\n\t\tif (inputObj == \"HTML_input_image\")\n\t\t\tset(\"width\", send(new, \"width?\") + 2);\n\n\t\tif (form == 0) form = send(parent(), \"findForm\");\n\t\tif (form == 0) {\n\t\t\tprint(\"HTML_input: can't find form. self=\",\n\t\t\t\tself(), \"\\n\");\n\t\t} else {\n\t\t\tif (inputObj != \"HTML_input_submit\" &&\n\t\t\t    inputObj != \"HTML_input_reset\")\n\t\t\t\tsend(form, \"regInputer\", self());\n\t\t}\n\t\tif (isRadio) {\n\t\t\tsend(form, \"radioReg\", tagID, self());\n\t\t}\n\t\tif (checked) {\n\t\t\tsend(nthChild(0), \"buttonPress\");\n\t\t\tsend(nthChild(0), \"buttonRelease\");\n\t\t}\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"INPUT\");\n\t\tvspan = style_p[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tww = arg[2] - get(\"x\") - style_p[3];\n\t\tset(\"width\", ww);\n\t\th = send(nthChild(0), \"R\", arg[1], ww - 2);\n\t\treturn vspan + set(\"height\", h) + style_p[1];\n\tbreak;\n\tcase \"r\":\n\t\tset(\"width\", get(\"width\") - 10);\n\t\th = send(nthChild(0), \"R\", 0, get(\"width\"));\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"AI\":\n\t\tswitch (arg[1]) {\n\t\tcase \"TYPE\":\n\t\t\tinputObj = \"HTML_input_str\";\n\t\tbreak;\n\t\tcase \"VALUE\":\n\t\t\tdefaultVal = \"\";\n\t\tbreak;\n\t\tcase \"SIZE\":\n\t\t\tdefaultRows = 1;\n\t\t\tset(\"height\", 29);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"TYPE\":\n\t\t\tinputType = arg[1];\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"int\":\n\t\t\tcase \"float\":\n\t\t\t\tinputObj = \"HTML_input_int\";\n\t\t\t\tdefWidth = 50;\n\t\t\tbreak;\n\t\t\tcase \"percent\":\n\t\t\t\tinputObj = \"HTML_input_percent\";\n\t\t\t\tdefWidth = 300;\n\t\t\tbreak;\n\t\t\tcase \"boolean\":\n\t\t\tcase \"check\":\n\t\t\tcase \"checkbox\":\n\t\t\t\tinputObj = \"HTML_input_check\";\n\t\t\t\tdefWidth = 18;\n\t\t\tbreak;\n\t\t\tcase \"radio\":\n\t\t\t\tinputObj = \"HTML_input_radio\";\n\t\t\t\tisRadio = 1;\n\t\t\t\tdefWidth = 18;\n\t\t\tbreak;\n\t\t\tcase \"doodle\":\n\t\t\tcase \"scribble\":\n\t\t\t\tinputObj = \"HTML_input_doodle\";\n\t\t\t\tisRadio = 1;\n\t\t\t\tdefWidth = 300;\n\t\t\tbreak;\n\t\t\tcase \"text\":/* multiline*/\n\t\t\t\tinputObj = \"HTML_input_text\";\n\t\t\t\tdefWidth = 300;\n\t\t\tbreak;\n\t\t\tcase \"image\":\n\t\t\t\tinputObj = \"HTML_input_image\";\n\t\t\tbreak;\n\t\t\tcase \"hidden\":\n\t\t\t\tinputObj = \"HTML_input_hidden\";\n\t\t\t\tdefWidth = 0;\n\t\t\tbreak;\n\t\t\tcase \"submit\":\n\t\t\t\tinputObj = \"HTML_input_submit\";\n\t\t\t\tdefaultRows = 2;\n\t\t\t\tdefWidth = 100;\n\t\t\tbreak;\n\t\t\tcase \"reset\":\n\t\t\t\tinputObj = \"HTML_input_reset\";\n\t\t\t\tdefaultRows = 2;\n\t\t\t\tdefWidth = 100;\n\t\t\tbreak;\n\t\t\tcase \"str\":\n\t\t\tcase \"date\":\n\t\t\t\tinputObj = \"HTML_input_str\";\n\t\t\t\tdefWidth = 300;\n\t\t\tbreak;\n\t\t\tcase \"password\":\n\t\t\t\tinputObj = \"HTML_input_password\";\n\t\t\t\tdefWidth = 300;\n\t\t\tbreak;\n\t\t\tcase \"audio\":\n\t\t\tdefault:\n\t\t\t\tinputObj = \"HTML_input_fail\";\n\t\t\t\tdefWidth = 300;\n\t\t\tbreak;\n\t\t\t}\n\t\t\tif (objWidth == 0) objWidth = defWidth;\n\t\tbreak;\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"VALUE\":\n\t\t\tdefaultVal = arg[2];\n\t\tbreak;\n\t\tcase \"DISABLED\":\n\t\t\tdisabled = 1;\n\t\tbreak;\n\t\tcase \"ENVVAR\":\n\t\t\tdefaultVal = environVar(arg[2]);\n\t\tbreak;\n\t\tcase \"SRC\":\n\t\t\tsrc = arg[2];\n\t\tbreak;\n\t\tcase \"SIZE\":\n\t\t\ti = findPattern(arg[2], ',');\n\t\t\tif (i == -1) {\n\t\t\t\tsize_cols = int(arg[2]);\n\t\t\t\t/* extra size to allow for scrollbar */\n\t\t\t\tobjWidth = size_cols * textWidth(0, \"n\") + 20;\n\t\t\t} else {\n\t\t\t\tsize_cols = int(nthChar(arg[2], 0, i-1));\n\t\t\t\tdefaultRows = int(nthChar(arg[2], i + 1, 99));\n\t\t\t\tobjWidth = size_cols * textWidth(0, 'n');\n\t\t\t\tobjHeight = defaultRows * 22;\n\t\t\t}\n\t\tbreak;\n\t\tcase \"CHECKED\":\n\t\t\tchecked = 1;\n\t\tbreak;\n\t\tcase \"MINCHARS\":\n\t\t\tminChars = arg[2];\n\t\tbreak;\n\t\tcase \"MAXCHARS\":\n\t\t\tmaxChars = arg[2];\n\t\tbreak;\n\t\tcase \"CHARS\":\n\t\t\tmaxChars = minChars = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"value\":\n\t\t/* push this down another level */\n\t\tif (inputObj == \"HTML_input_image\") {\n\t\t\treturn send(nthChild(0), \"packValue\", tagID);\n\t\t} else if (inputObj == \"HTML_input_radio\") {\n\t\t\treturn send(nthChild(0), \"packValue\", tagID);\n\t\t} else if (inputObj == \"HTML_input_check\") {\n\t\t\treturn send(nthChild(0), \"packValue\", tagID);\n\t\t} else {\n\t\t\treturn concat(HTTPEncodeURL(tagID), '=',\n\t\t\t\tHTTPEncodeURL(send(nthChild(0), \"value\")));\n\t\t}\n\tbreak;\n\tcase \"reset\":\n\t\treturn send(nthChild(0), \"reset\");\n\tbreak;\n\tcase \"radioOnReq\":\n\t\t/* tell form that this radio button wants to be ON */\n\t\treturn send(form, \"radioOnReq\", tagID, self());\n\tbreak;\n\tcase \"radioOff\":\n\t\t/* form calls back to tell this radio button to be OFF*/\n\t\tsend(nthChild(0), \"toggleTo\", 0);\n\t\treturn;\n\tbreak;\n\tcase \"radioOn\":\n\t\t/* form calls back to say that this radio button can be ON */\n\t\tsend(nthChild(0), \"toggleTo\", 1);\n\t\treturn;\n\tbreak;\n\tcase \"acceptForm\":\n\tcase \"resetForm\":\n\t\treturn send(form, arg[0]);\n\tbreak;\n\tcase \"minChars?\":\n\t\treturn minChars;\n\tbreak;\n\tcase \"maxChars?\":\n\t\treturn maxChars;\n\tbreak;\n\tcase \"setWidth\":\n\t\t/* kludge. this is called by child obj, to ask for \n\t\t * width readjustment */\n\t\tset(\"width\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"src?\":\n\t\tprint(\"input self=\", self(), \"\\n\");\n\t\tprint(\"input src=\", src, \"\\n\");\n\t\treturn src;\n\tbreak;\n\tcase \"regInputer\":\n\t\treturn send(form, arg[0], arg[1]);\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<INPUT\");\n\t\tif (tagID) print(\" NAME=\\\"\", tagID, \"\\\"\");\n\t\tif (type) print(\" TYPE=\\\"\", inputType, \"\\\"\");\n\t\tif (checked) print(\" CHECKED\");\n\t\tif (get(\"maxWidth\") < 9999) \n\t\t\tprint(\" MAXWIDTH=\", get(\"maxWidth\"));\n\t\tif (get(\"minWidth\") < 9999) \n\t\t\tprint(\" MINWIDTH=\", get(\"minWidth\"));\n\t\tprint(\">\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_check2[] = "\n\tswitch (arg[0]) {\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tset(\"parent\", arg[1]);\n\t\tvalDefault = arg[2];\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"buttonPress\":\n\tcase \"buttonRelease\":\n\t\tusual();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"packValue\":\n\t\tif (get(\"toggleState\")) \n\t\t\treturn concat(HTTPEncodeURL(arg[1]), '=',\n\t\t\t\tHTTPEncodeURL(valDefault));\n\t\treturn 0;\n\tbreak;\n\tcase \"value\":\n\t\treturn get(\"toggleState\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_doodle4[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tset(\"width\", arg[2]);\n\t\tdeepObjectListSend(\"children\", \"configSelf\");\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tset(\"parent\", arg[1]);\n\t\tval = arg[2];\n\t\tset(\"width\", arg[3]);\n\t\tconfig();\n\t\tsend(nthChild(1), \"setup\");\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"value\":\n\t\treturn send(nthChild(1), \"getVar\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"relay1\":\n\t\treturn send(nthChild(1), arg[1]);\n\tbreak;\n\tcase \"relay2\":\n\t\treturn send(nthChild(1), arg[1], arg[2]);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola.background_doc\");\n\t\tif (color) set(\"BGColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_input_doodle5[] = "100";
static char _slotValue_HTML_input_doodle6[] = "100";
/* END OF OBJ */

static char _slotValue_HTML_input_doodle8[] = "txtButton";
static char _slotValue_HTML_input_doodle9[] = "HTML_input_doodle.ctrl";
static char _slotValue_HTML_input_doodle10[] = "HTML_input_doodle";
static char _slotValue_HTML_input_doodle11[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"relay1\", \"clear\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_input_doodle12[] = "Clear pad";
static char _slotValue_HTML_input_doodle13[] = "20";
static char _slotValue_HTML_input_doodle14[] = "100";
static char _slotValue_HTML_input_doodle15[] = "2";
static char _slotValue_HTML_input_doodle16[] = "2";
/* END OF OBJ */

static char _slotValue_HTML_input_doodle18[] = "field";
static char _slotValue_HTML_input_doodle19[] = "HTML_input_doodle.canvas";
static char _slotValue_HTML_input_doodle20[] = "HTML_input_doodle";
static char _slotValue_HTML_input_doodle21[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\tif (penDownP) {\n\t\t\tx0 = x1;\n\t\t\ty0 = y1;\n\t\t\tx1 = arg[1];\n\t\t\ty1 = arg[2];\n\t\t\tdrawLine(x0, y0, x1, y1);\n\n\t\t\tsegments[count] = 0;\t/* sickie language flaw */\n\t\t\tseg = segments[count];\n\t\t\tseg[0] = x0;\n\t\t\tseg[1] = y0;\n\t\t\tseg[2] = x1;\n\t\t\tseg[3] = y1;\n\t\t\tsegments[count] = seg;\n\n\t\t\tcount++;\n\t\t\treturn;\n\t\t}\n\tbreak;\n\tcase \"buttonPress\":\n\t\tpenDownP = 1;\n\t\tx0 = mouseX();\n\t\ty0 = mouseY();\n\t\tx1 = x0;\n\t\ty1 = y0;\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tpenDownP = 0;\n\tbreak;\n\tcase \"clear\":\n\t\tcount = 0;\n\t\tclearWindow();\n\t\treturn;\n\tbreak;\n\tcase \"dump\":\n\t\tfor (i = 0; i < count; i++) {\n\t\t\tseg = segments[i];\n\t\t\tprint(i, \":\", seg[0], \",\", seg[1], \n\t\t\t\t\" \",  seg[2], \",\", seg[3],\n\t\t\t\t\"\\n\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"getVar\":\n\t\ttt = \"\";\n\t\tfor (i = 0; i < count; i++) {\n\t\t\tseg = segments[i];\n\t\t\ttt = concat(tt, seg[0], \",\", seg[1], \n\t\t\t\t    \",\",  seg[2], \",\", seg[3],\n\t\t\t\t    \";\\n\");\n\t\t}\n\t\treturn tt;\n\tbreak;\n\tcase \"expose\":\n\t\tfor (i = 0; i < count; i++) {\n\t\t\tseg = segments[i];\n\t\t\tdrawLine(seg[0], seg[1], seg[2], seg[3]);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"setup\":\n\t\tpenDownP = 0;\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tpenDownP = 0;\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) {\n\t\t\tset(\"BDColor\", color);\n\t\t\tset(\"FGColor\", color);\n\t\t}\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_fail2[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"width\", arg[2] - 2);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"value\":\n\t\treturn get(\"content\");\n\tbreak;\n\tcase \"reset\":\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_hidden2[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\treturn 0;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tdefaultVal = arg[2];\n\t\treturn 0;\n\tbreak;\n\tcase \"value\":\n\t\treturn defaultVal;\n\tbreak;\n\tcase \"reset\":\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_hidden[] = {
    {"name", _slotValue_HTML_input_hidden0},
    {"class", _slotValue_HTML_input_hidden1},
    {"script", _slotValue_HTML_input_hidden2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_hook0[] = "field";
static char _slotValue_HTML_input_hook1[] = "HTML_input_hook";
static char _slotValue_HTML_input_hook2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (tagID) {\n\t\t\tsend(parent(), \"setAnchor\", tagID);\n\t\t\ttagID = 0;\n\t\t}\n\t\tif (url) {\n\t\t\tt = concat(\"\\\\b(\", compressSpaces(get(\"label\")),\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t\turl = 0;\n\t\t\treturn t;\n\t\t} else {\n\t\t\treturn compressSpaces(get(\"label\"));\n\t\t}\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"HREF\":\n\t\t\turl = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_input_hook[] = {
    {"class", _slotValue_HTML_input_hook0},
    {"name", _slotValue_HTML_input_hook1},
    {"script", _slotValue_HTML_input_hook2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_image0[] = "HTML_input_image";
static char _slotValue_HTML_input_image1[] = "GIF";
static char _slotValue_HTML_input_image2[] = "\n\t/* RIGHT NOW LIMITED TO GIF */\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"width\", arg[2] - 2);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tset(\"parent\", arg[1]);\n\t\tdefaultVal = arg[2];\n\t\tset(\"content\", defaultVal);\n\t\tset(\"width\", 0);\n\t\tset(\"height\", 0);\n\n\t\tvalue = \"\";\n\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\t\tsrc = send(parent(), \"src?\");\n\t\tlocalFile = HTTPGet(src);\n\t\tprint(\"input_image src=\", src, \"\\n\");\n\t\tprint(\"input_image localFile=\", localFile, \"\\n\");\n\t\tset(\"label\", localFile);\n\t\tset(\"width\", get(\"width\"));\n\t\tset(\"height\", get(\"height\"));\n\t\tprint(\"input_image height=\", get(\"height\"), \"\\n\");\n\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n/*\n\t\tsend(\"wwwSecurity\", \"rmTmpFile\", localFile);\n*/\n\t\treturn get(\"height\") + 1;\n\tbreak;\n\tcase \"buttonPress\":\n\t\txy = mouseLocal();\n\t\tx0 = xy[0];\n\t\ty0 = xy[1];\n\t\tset(\"FGColor\", \"red\");\n\t\tdrawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\t\tdrawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\t\tset(\"FGColor\", \"white\");\n\t\tdrawLine(x0, y0 - 5, x0, y0 + 5);\n\t\tdrawLine(x0 + 5, y0, x0 - 5, y0);\n\n\t\tsend(parent(), \"acceptForm\");\n\tbreak;\n\tcase \"value\":\n\t\treturn concat(x0, \",\", y0);\n\tbreak;\n\tcase \"packValue\":\n\t\tid = HTTPEncodeURL(arg[1]);\n\t\treturn concat(id, \".x=\", HTTPEncodeURL(x0), '&',\n\t\t\t\tid, \".y=\", HTTPEncodeURL(y0));\n\tbreak;\n\tcase \"width?\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"reset\":\n\t\tset(\"content\", defaultVal);\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_int2[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tset(\"width\", arg[2]);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\n\t\ttagPtr = STG_tagPtr(\"HPANE\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tset(\"parent\", arg[1]);\n\t\tdefaultVal = arg[2];\n\t\tset(\"content\", defaultVal);\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n/*\n\t\tsend(parent(), \"regInputer\", self());\n\t\tmaxChars = send(parent(), \"maxChars?\");\n\t\tif (maxChars) checkChars = 1;\n\t\tminChars = send(parent(), \"minChars?\");\n\t\tif (minChars) checkChars = 1;\n*/\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"keyPress\":\n\t\tc = key();\n\t\tif (c == '\\r' || c == '\\n') {\n\t\t\tif (checkChars) send(self(), \"checkChars\");\n\t\t\treturn;\n\t\t}\n\tbreak;\n\tcase \"leave\":\n/*\t\tsend(parent(), \"setFormVar\", get(\"content\"));*/\n\t\tif (checkChars) send(self(), \"checkChars\");\n\tbreak;\n\tcase \"checkChars\":\n\t\tlength = strlen(get(\"content\"));\n\t\tif (minChars > 0) {\n\t\t\tif (length < minChars) {\n\t\t\t\tsend(\"www.mesg.tf\", \"suggest\", \nconcat(\"Warning, you have entered less digits than suggested\\n\"));\n\t\t\t}\n\t\t}\n\t\tif (maxChars > 0) {\n\t\t\tif (length < maxChars) {\n\t\t\t\tsend(\"www.mesg.tf\", \"suggest\", \n\t\t\"Warning, you have entered more digits than suggested\\n\");\n\t\t\t}\n\t\t}\n\tbreak;\n\tcase \"value\":\n\t\treturn get(\"content\");\n\tbreak;\n\tcase \"reset\":\n\t\tset(\"content\", defaultVal);\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_password2[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"width\", arg[2] - 2);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t * ...\n\t\t * arg[7]\tdisabled\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tif (arg[6]) disabled = 1;\n\n\t\tset(\"parent\", arg[1]);\n\t\tdefaultVal = arg[2];\n\t\tset(\"content\", defaultVal);\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"enter\":\n\t\tif (disabled) return;\n\tbreak;\n\tcase \"keyPress\":\n\t\tif (disabled) {\n\t\t\tbell();\n\t\t\tsend(\"www.mesg.tf\", \"suggest\", \n\t\t\t\t\"This field has been disabled\\n\");\n\t\t\treturn;\n\t\t} else {\n\t\t\tc = key();\n\n\t\t\tif (c >= ' ' &&  c <= '~') {\n\t\t\t\tpasswd[sl] = c;\n\t\t\t\tsl++;\n\t\t\t} else {\n\t\t\t\tif (c == '\\r' || c == '\\n') {\n\t\t\t\t\treturn;\n\t\t\t\t} else if (c == '\\8') {\n\t\t\t\t  /* 8==Backspace. surely not the way?*/\n\t\t\t\t\tif (sl > 0) sl--;\n\t\t\t\t}\n\t\t\t}\n\t\t\tsend(self(), \"setScreen\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"setScreen\":\n\t\tif (sl == 0) set(\"content\", \"\");\n\t\telse set(\"content\", \n\t\t\tnthChar(\"****************************************\",\n\t\t\t\t1, sl));\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tif (checkChars) send(self(), \"checkChars\");\n\tbreak;\n\tcase \"value\":\n\t\tpasswdStr = \"\";\n\t\tfor (i = 0; i < sl; i++)\n\t\t\tpasswdStr = concat(passwdStr, passwd[i]);\n\t\treturn passwdStr;\n\tbreak;\n\tcase \"reset\":\n\t\tset(\"content\", defaultVal);\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_percent3[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tset(\"width\", arg[2]);\n\t\tconfig();\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tset(\"parent\", arg[1]);\n\t\tval = arg[2];\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\t\tconfig();\n\t\tobjectListSend(\"children\", \"_setVar\", val);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"value\":\n\t\treturn send(nthChild(1), \"getVar\");\n\tbreak;\n\tcase \"setVar.v\":\n\t\tval = arg[1];\n\t\tsend(nthChild(1), \"setVar\", val);\n\t\treturn;\n\tbreak;\n\tcase \"setVar.s\":\n\t\tval = arg[1];\n\t\tsend(nthChild(0), \"setVar\", val);\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_input_percent4[] = "100";
static char _slotValue_HTML_input_percent5[] = "17";
/* END OF OBJ */

static char _slotValue_HTML_input_percent7[] = "HTML_input_percent";
static char _slotValue_HTML_input_percent8[] = "HTML_input_percent.v";
static char _slotValue_HTML_input_percent9[] = "txtEdit";
static char _slotValue_HTML_input_percent10[] = "HTML_input_percent.s";
static char _slotValue_HTML_input_percent11[] = "\n\tswitch (arg[0]) {\n\tcase \"setVar\":\n\tcase \"shownPositionH\":\n\t\tset(\"content\", arg[1]);\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"_setVar\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"keyPress\":\n\t\tif (key() == '\\r') {\n\t\t\tv = get(\"content\");\n\t\t\tif (v > 100) {\n\t\t\t\tv = 100;\n\t\t\t\tset(\"content\", 100);\n\t\t\t\trender();\n\t\t\t}\n\t\t\treturn;\n\t\t}\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_input_percent12[] = "30";
/* END OF OBJ */

static char _slotValue_HTML_input_percent14[] = "slider";
static char _slotValue_HTML_input_percent15[] = "HTML_input_percent";
static char _slotValue_HTML_input_percent16[] = "HTML_input_percent.s";
static char _slotValue_HTML_input_percent17[] = "HTML_input_percent.v";
static char _slotValue_HTML_input_percent18[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tdefaultValue\n\t\t */\n\t\tset(\"shownPositionH\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"setVar\":\n\t\tset(\"shownPositionH\", arg[1]);\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"_setVar\":\n\t\tset(\"shownPositionH\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"getVar\":\n\t\treturn get(\"shownPositionH\");\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"setVar.s\", get(\"content\"));\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_radio3[] = "\n\tswitch (arg[0]) {\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\ttagID\n\t\t * arg[2]\tvalDefault\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t * arg[5]\tchecked\n\t\t * arg[6]\tdisabled\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tset(\"parent\", arg[1]);\n\t\tvalDefault = arg[2];\n\t\tchecked = arg[5];\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"radioOnReq\");\n\t\treturn;\n\tbreak;\n\tcase \"packValue\":\n\t\tif (get(\"toggleState\")) \n\t\t\treturn concat(HTTPEncodeURL(arg[1]), '=',\n\t\t\t\tHTTPEncodeURL(valDefault));\n\t\treturn 0;\n\tbreak;\n\tcase \"value\":\n\t\treturn get(\"toggleState\");\n\tbreak;\n\tcase \"reset\":\n\t\tif (get(\"toggleState\")) {\n\t\t\tif (checked == 0) {\n\t\t\t\tset(\"toggleState\", 0);\n\t\t\t\tclearWindow();\n\t\t\t\trender();\n\t\t\t}\n\t\t} else {\n\t\t\tif (checked == 1) {\n\t\t\t\tset(\"toggleState\", 1);\n\t\t\t\tclearWindow();\n\t\t\t\trender();\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola.background_doc\");\n\t\tif (color) set(\"BGColor\", color);\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"FGColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_reset2[] = "\n\tswitch (arg[0]) {\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"width\", arg[2] - 2);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tset(\"parent\", arg[1]);\n\t\tif (isBlank(arg[2]) == 0) set(\"label\", arg[2]);\n\t\tw = textWidth(1, get(\"label\")) + 20;\n\t\tset(\"width\", w);\n\t\tsend(parent(), \"setWidth\", w+2);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"resetForm\");\n\tbreak;\n\tcase \"reset\":\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_str2[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"width\", arg[2] - 2);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t * arg[5]\tchecked\n\t\t * arg[6]\tdisabled\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tif (arg[6]) disabled = 1;\n\n\t\tset(\"parent\", arg[1]);\n\t\tdefaultVal = arg[2];\n\t\tset(\"content\", defaultVal);\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"enter\":\n\t\tif (disabled == 1) return;\n\tbreak;\n\tcase \"keyPress\":\n\t\tif (disabled == 1) {\n\t\t\tbell();\n\t\t\tsend(\"www.mesg.tf\", \"suggest\", \n\t\t\t\t\"This field has been disabled\\n\");\n\t\t\treturn;\n\t\t} else {\n\t\t\tc = key();\n\t\t\tif (c == '\\r' || c == '\\n') {\n\t\t\t\tif (checkChars) send(self(), \"checkChars\");\n\t\t\t\treturn;\n\t\t\t}\n\t\t}\n\tbreak;\n\tcase \"checkChars\":\n\t\tlength = strlen(get(\"content\"));\n\t\tif (minChars > 0) {\n\t\t\tif (length < minChars) {\n\t\t\t\tsend(\"www.mesg.tf\", \"suggest\", \n\t\"Warning, you have entered less characters than suggested\\n\");\n\t\t\t}\n\t\t}\n\t\tif (maxChars > 0) {\n\t\t\tif (length < maxChars) {\n\t\t\t\tsend(\"www.mesg.tf\", \"suggest\", \n\t\"Warning, you have entered more characters than suggested\\n\");\n\t\t\t}\n\t\t}\n\tbreak;\n\tcase \"leave\":\n\t\tif (checkChars) send(self(), \"checkChars\");\n\tbreak;\n\tcase \"value\":\n\t\treturn trimEdge(get(\"content\"));\n\tbreak;\n\tcase \"reset\":\n\t\tset(\"content\", defaultVal);\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_submit2[] = "\n\tswitch (arg[0]) {\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"width\", arg[2] - 2);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tset(\"parent\", arg[1]);\n\t\tif (isBlank(arg[2]) == 0) set(\"label\", arg[2]);\n\t\tw = textWidth(1, get(\"label\")) + 20;\n\t\tset(\"width\", w);\n\t\tsend(parent(), \"setWidth\", w+2);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tsend(parent(), \"acceptForm\");\n\tbreak;\n\tcase \"reset\":\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_input_text3[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"width\", arg[2] - 2);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\t\tconfig();\n\t\tsend(nthChild(0), \"make\", arg[2], arg[6]);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"value\":\n\tcase \"reset\":\n\t\treturn send(nthChild(0), arg[0], arg[1]);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_HTML_input_text5[] = "HTML_input_text.tf";
static char _slotValue_HTML_input_text6[] = "txtEdit";
static char _slotValue_HTML_input_text7[] = "HTML_input_text.sb";
static char _slotValue_HTML_input_text8[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"width\", arg[2] - 2);\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"enter\":\n\t\tif (disabled) return;\n\tbreak;\n\tcase \"keyPress\":\n\t\tif (disabled) {\n\t\t\tbell();\n\t\t\tsend(\"www.mesg.tf\", \"suggest\", \n\t\t\t\t\"This field has been disabled\\n\");\n\t\t\treturn;\n\t\t}\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdisabled\n\t\t */\n/*\t\ttagPtr = STG_tagPtr(\"INPUT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tdefaultVal = arg[1];\n\t\tset(\"content\", defaultVal);\n\t\tif (arg[2]) disabled = 1;\n\n\t\treturn;\n\tbreak;\n\tcase \"value\":\n\t\treturn get(\"content\");\n\tbreak;\n\tcase \"reset\":\n\t\tset(\"content\", defaultVal);\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_insert2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n/*RAW\t\ttmpf = HTTPGet(docURL);\n\t\tif (tmpf == 0) {\n\t\t\tset(\"content\", \n\t\t\t\tconcat(\"Failed to include \", docURL));\n\t\t\tset(\"BGColor\", \"red\");\n\t\t\tset(\"FGColor\", \"white\");\n\t\t} else {\n\t\t\tset(\"content\", loadFile(tmpf));\n\t\t}\n\t\th = building_vspan();\n\t\tset(\"height\", h);\n*/\n\t\teventMask(\"+pointerMotion +leaveWindow +buttonRelease\");\n\t\tdocURL = send(\"normalizeURL\", \"normalizeURL\", docURL);\n\t\th = 10;\n\t\tsend(send(parent(), \"findTop\"), \"toDoInsert\", self());\n\t\treturn h;\n\tbreak;\n\tcase \"reinsert\":\n\t\tset(\"height\", 0);/*to prevent padding*/\n\n\t\toldObj = nthChild(0);\n\t\tobjectListDelete_children(oldObj);\n\n\t\thandler = wwwFormatDetect(\"type\", docURL);\n\t\tpaneObj = self();\n\t\tcursorShape(\"busy\");\n\t\t\t\t\t/* just to generate unique name */\n\t\tdocName = concat(self(), makeTempFile());\n\t\tdocObj = send(\"wwwHandlerDispatch\", \"dispatch\",\n\t\t\t\thandler, 0 /* no do post */,\n\t\t\t\tdocURL, docName, paneObj,\n\t\t\t\tget(\"width\"), 9999999,\n\t\t\t\tanchor, 1, 0 /* no post data */);\n\t\th = send(docObj, \"vspan\");\n\t\tset(\"children\", docObj);\n\t\tsend(docObj, \"visible\", 1);\n\t\tset(\"height\", h);\n\t\tcursorShape(\"busy\");\n\t\tif (prevHeight != h)\n\t\t\tsend(send(parent(), \"findTop\"), \"resizeSelf\");\n\t\tprevHeight = h;\n\n\t\tsend(oldObj, \"freeSelf\");\n\t\tafter(reInsertDelay, self(), \"reinsert\");\n\t\treturn;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"INSERT\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tif (nthChild(0) != 0) {\n\t\t\tvspan += send(nthChild(0), 'R', 0, width() - 4);\n\t\t\tset(\"height\", vspan);\n\t\t}\n\t\tprevHeight = vspan;\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"HREF\":\n\t\t\tdocURL = arg[2];\n\t\tbreak;\n\t\tcase \"BORDER\":\n\t\t\tset(\"BDColor\", \"black\");\n\t\tbreak;\n\t\tcase \"ASIS\":\n\t\t\traw = 1;\n\t\tbreak;\n\t\tcase \"AFTER\":\n\t\t\treInsertDelay = int(arg[2]);\n\t\t\tafter(reInsertDelay, self(), \"reinsert\");\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"insert\":\n\t\thandler = wwwFormatDetect(\"type\", docURL);\n\t\tpaneObj = self();\n\t\t\t\t\t/* just to generate unique name */\n\t\tdocName = concat(self(), makeTempFile());\n\t\tdocObj = send(\"wwwHandlerDispatch\", \"dispatch\",\n\t\t\t\thandler,\n\t\t\t\t0 /* no do post */,\n\t\t\t\tdocURL,\n\t\t\t\tdocName,\n\t\t\t\tpaneObj,\n\t\t\t\tget(\"width\"),\n\t\t\t\tget(\"height\"),\n\t\t\t\tanchor,\n\t\t\t\t1, \n\t\t\t\t0 /* no post data */);\n\t\th = send(nthChild(0), \"vspan\");\n\t\tset(\"height\", h);\n\t\treturn;\n\tbreak;\n\tcase \"toDoInsert\":\n\t\t/* relay for nested <insert>s */\n\t\tsend(send(parent(), \"findTop\"), \"toDoInsert\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"setChildren\":\n\t\tset(\"children\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_insertTest2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\tcontainer = HTML_insertee(\"clone\");\n\t\tw = width() - 40;\n\t\ty = SGMLBuildDoc_span();\n\t\tsend(container, \"make\", self(), 30, y, w);\n\t\tSGMLBuildDoc_insertObj(container, w);\n\n\t\treturn -1;\n\tbreak;\n\tcase \"D\":\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle[3], width() - style[3] - style[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = width();\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = width();\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n/*\t\tSGMLBuildDoc_setBuff(-1);*/\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_insertTest[] = {
    {"class", _slotValue_HTML_insertTest0},
    {"name", _slotValue_HTML_insertTest1},
    {"script", _slotValue_HTML_insertTest2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_insertee0[] = "field";
static char _slotValue_HTML_insertee1[] = "HTML_insertee";
static char _slotValue_HTML_insertee2[] = "\n\tprint(\"@@@@@@ HTML_insertee clsss = field: args: \");\n\tfor (i =0; i < arg[]; i++) print(arg[i], \", \");\n\tprint(\"====================\\n\");\n\tprint(\"insertee self=\", self(), \"\\n\");\n\n\tswitch (arg[0]) {\n\tcase \"D\":\n/*print(\"insertee: D height=\", height(), \"\\n\");*/\n\t\th = SGMLBuildDoc_span();\n\t\tset(\"height\", h);\nprint(\"insertee: D h=\", h, \"\\n\");\n\t\treturn h;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tvspan = -1;\n\t\tset(\"x\", 30);\t\t/*XXX*/\n\t\tset(\"y\", arg[1]);\n\t\tset(\"width\", arg[2] - x());\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = width();\n\t\t\tfor (i = 0; i < n; i++) {\nprint(\"insertee: child=\", nthChild(i), \"\\n\");\nprint(\"insertee: before vspan=\", vspan, \"\\n\");\n\t\t\t\tvspan = vspan \n\t\t\t\t\t+ send(nthChild(i), 'R', vspan, xx);\nprint(\"insertee: after vspan=\", vspan, \"\\n\");\n\t\t\t}\n\t\t}\n\t\tset(\"height\", vspan);\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tx\n\t\t * arg[3]\ty\n\t\t * arg[4]\twidth\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"x\", arg[2]);\n\t\tset(\"y\", arg[3]);\n\t\tset(\"width\", arg[4]);\n\tprint(\"insertee height=\", height(), \"\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (id == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (id == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_isIndex3[] = "\n\tswitch (arg[0]) {\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"y\", arg[1]);\n\t\tset(\"width\", arg[2] - 2);\n\t\tconfig();\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"D\":\n\t\tsend(send(parent(), \"findTop\"), \"isIndex\");\n\t\treturn get(\"height\")+2;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"LABEL\":\n\t\t\tsend(nthChild(0), \"setLabel\", arg[2]);\n\t\tbreak;\n\t\tcase \"VALUE\":\n\t\t\tdefaultVal = arg[2];\n\t\tbreak;\n\t\t}\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(arg[1]);\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"search\":\n\t\tsend(send(parent(), \"findTop\"), \"search\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_isIndex14[] = "\n\tswitch (arg[0]) {\n\tcase \"setLabel\":\n\t\tset(\"content\", arg[1]);\n\t\tset(\"maxWidth\", textWidth(1, argp[1]) + 10);\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_isIndex25[] = "\n\tswitch (arg[0]) {\n\tcase \"keyPress\":\n\t\tif (key() == '\\r') {\n\t\t\tsend(parent(), \"search\", currentLine());\n\t\t\treturn;\n\t\t}\n\tbreak;\n\tcase \"enter\":\n\t\twww.mesg.tf(\"show\", \"An indexing keyword entry field.\");\n\tbreak;\n\tcase \"leave\":\n\t\twww.mesg.tf(\"clear\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_ititle2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n/*\n\t\tlistItemObj = HTML_txtListItem(\"clone\");\n\t\th = send(listItemObj, \"make\", self(), 20, width() - 20);\n\t\tset(\"children\", listItemObj);\n\n\t\th = send(listItemObj, \"make\", self(), 20, width() - 20);\n\t\tprint(\"*>>>>>>> h = \", h, \"\\n\");\n*/\t\t\n\t\treturn h;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (get(\"content2\") == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (get(\"content2\") == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_ititle3[] = "#define ol_width 16\n#define ol_height 16\nstatic char ol_bits[] = {\n   0x00, 0x00, 0x00, 0x74, 0x00, 0x7a, 0x00, 0x3d, 0x80, 0x1e, 0x00, 0x0f,\n   0xe0, 0x06, 0xf0, 0x01, 0xb0, 0x01, 0xd8, 0x01, 0xe8, 0x00, 0x3c, 0x00,\n   0x0c, 0x04, 0x02, 0x03, 0xf8, 0x00, 0x00, 0x00};\n";
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
static char _slotValue_HTML_label2[] = "\n\tswitch (arg[0]) {\n\tcase \"T\":\n\t\t/* arg[1] = y\n\t\t * arg[2] = width\n\t\t */\n\t\tw = get(\"window\");\n\t\tset(\"window\", 0);\n\t\tset(\"width\", arg[2] - 15);\n\t\tif (height() < 3) {\n\t\t\tprint(\"height = \", height(), \"\\n\");\n\t\t\tset(\"height\", 999);\n\t\t}\n\t\tset(\"x\", 10);\n\t\tset(\"window\", w);\n\t\tset(\"content\", get(\"label\"));\n\t\tset(\"y\", arg[1]);\n\t\th = building_vspan() + 3;\n\t\tset(\"height\", h);\n\t\th += 6;\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tset(\"y\", arg[1]);\n\t\tset(\"width\", arg[2]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan = building_vspan();\n\t\tset(\"height\", vspan);\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_link2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tswitch (rel) {\n\t\tcase \"made\":\n\t\t\tsend(send(parent(), \"findTop\"), \"reportAuthor\", href);\n\t\tbreak;\n\t\tcase \"style\":\n\t\t\tSTG_clean(0/*useless arg*/);\n\t\t\tlocalFile = HTTPGet(href);\n\t\t\tloadSTG(localFile);\n\t\t\toarg = 0;\n\t\t\toargc = 0;\n\t\tbreak;\n\t\tcase \"sidebar\":\n\t\t\t/* Rule to be... can't do because of parser bug\n\t\t\t * if 'maxWidth' is given, that's used.\n\t\t\t * if not then 'ratio' is used, if it is given.\n\t\t\tbarRatio = 0;\n\t\t\tbarMaxWidth = 0;\n\n/**** a parser bug prevents multiple instances of the same attributes!!!\n\n\t\t\tflag = 0;\n\t\t\tfor (i = 0; i < oargc; i++) {\n\t\t\t\tif (flag == 0) flag = oarg[i];\n\t\t\t\telse {\n\t\t\t\t\tif (flag == \"maxWidth\") \n\t\t\t\t\t\tbarMaxWidth = oarg[i];\n\t\t\t\t\telse if (flag == \"ratio\") \n\t\t\t\t\t\tbarRatio = oarg[i];\n\t\t\t\t\tflag = 0;\n\t\t\t\t}\n\t\t\t}\n*/\n\t\t\tbarRatio = oarg[0];\n/*\nprint(\"Bar ratio=\", barRatio, \"\\n\");\nprint(\"Bar maxWidth=\", barMaxWidth, \"\\n\");\n*/\n\t\t\tsend(send(parent(), \"findTop\"), \"linkSideBar\", \n\t\t\t\thref, barRatio, barMaxWidth);\n\t\t\toarg = 0;\n\t\t\toargc = 0;\n\t\tbreak;\n\t\tcase \"tool\":\n\t\t\tlocalFile = HTTPGet(href);\n\t\t\taddrInfo = HTTPCurrentDocAddrParsed(localFile);\n\n\t\t\tif (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];\n\t\t\telse path = concat('/', addrInfo[2]);\n\t\t\tobjFileName = addrInfo[3];\n\n\t\t\taddrInfo = HTTPCurrentDocAddrParsed(href);\n\t\t\tobjName = nthChar(addrInfo[3], 0, \n\t\t\t\t\tstrlen(addrInfo[3]) - 3);\n\t\t\tif (exist(objName)) {\n\t\t\t\tsend(send(parent(), \"findTop\"), \"addTool\", \n\t\t\t\t\tobjName);\n\t\t\t\treturn \"\";\n\t\t\t}\n\n\t\t\tstat = loadObjFile(path, objFileName);\n\n\t\t\tsend(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\n\t\t\tif (stat <= 0) {\n\t\t\t\tprint(\"failed to load obj file {\", objFileName,\n\t\t\t\t\t\"} in {\", path, \"}\\n\");\n\t\t\t}\n\t\t\tsecurityMode(1); \n\t\t\tsend(objName, \"init\"); /* make new object(s) */\n\t\t\tsecurityMode(0);\n\n\t\t\tsend(send(parent(), \"findTop\"), \"addTool\", objName,\n\t\t\t\toarg, oargc);\n\t\t\toarg = 0;\n\t\t\toargc = 0;\n\t\tbreak;\n\t\tcase \"vobj\":\n\t\t\tlocalFile = HTTPGet(href);\n\t\t\taddrInfo = HTTPCurrentDocAddrParsed(localFile);\n\n\t\t\tif (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];\n\t\t\telse path = concat('/', addrInfo[2]);\n\t\t\tobjFileName = addrInfo[3];\n\n\t\t\taddrInfo = HTTPCurrentDocAddrParsed(href);\n\t\t\tobjName = nthChar(addrInfo[3], 0, \n\t\t\t\t\tstrlen(addrInfo[3]) - 3);\n\n\t\t\tstat = loadObjFile(path, objFileName);\n\n\t\t\tsend(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\n\t\t\tif (stat <= 0) {\n\t\t\t\tprint(\"failed to load obj file {\", objFileName,\n\t\t\t\t\t\"} in {\", path, \"}\\n\");\n\t\t\t}\n\t\t\tsecurityMode(1); \n\t\t\tsend(objName, \"init\"); /* make new object(s) */\n\t\t\tsecurityMode(0);\n/*\nprint(\"HTML_LINK load vobj=>>>>>>\", objName, \"<<\\n\");\n\t\t\tfor(i=0; i<oargc; i++) {\nprint(\"HTML_LINK oarg[\", i, \"]= >\", oarg[i], \"<\\n\");\n\t\t\t}\n*/\n\t\t\tif (oarg[] >= 1)\n\t\t\t\th = send(objName, \"make\", self(), oarg[0]);\n\n\t\t\tafter(1, objName, \"configSelf\");\n\t\t\toarg = 0;\n\t\t\toargc = 0;\n\t\t\trel = 0;\n\t\t\thref = 0;\n\t\t\tt = concat(\"\\\\o(\", objName, \")\");\n\t\t\treturn t;\n\t\tbreak;\n\t\t}\n\t\trel = 0;\n\t\thref = 0;\n\t\treturn \"\";\n\tbreak;\n\tcase \"config\":\n\tcase \"R\":\n\t\treturn 0;\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ARG\":\n\t\t\toarg[oargc++] = arg[2];\n\n/*It appears the HTML parser won't handle multiple same attrs.\nprint(\"HTML_LINK ADDING oarg[\", oargc - 1, \"]= >\", oarg[oargc - 1], \"<\\n\");\n*/\n\t\tbreak;\n\t\tcase \"REL\":\n\t\t\trel = arg[2];\n\t\tbreak;\n\t\tcase \"HREF\":\n\t\t\thref = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_link[] = {
    {"class", _slotValue_HTML_link0},
    {"name", _slotValue_HTML_link1},
    {"script", _slotValue_HTML_link2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_list0[] = "field";
static char _slotValue_HTML_list1[] = "HTML_list";
static char _slotValue_HTML_list2[] = "\n/*XXX Because clone() doesn't copy variables, the foldInfo hassle exists.\n */\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\tif (label) drawText(35, 1, 1, label);\n\t\treturn;\n\tbreak;\n\tcase \"D\":\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\t/* to deal with idiotic cases like\n\t\t\t * <UL>foobar</UL>\n\t\t\t * <UL><UL>foobar</UL></UL>\n\t\t\t */\n\t\t\th = 0;\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3],\n\t\t\t\tget(\"width\") - style_p[3] - 30 - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t\tif (h == 0) return 1;\n\t\t\tset(\"height\", h);\n\t\t\treturn h;\n\t\t}\n\n\t\tset(\"content2\", self());/*a kludge to deal with cloning*/\n\t\tif (canFold) {\n\t\t\tif (folded) {\n\t\t\t\t/* make the first list item go away,\n\t\t\t\t * to show the toggler */\n\t\t\t\tsend(nthChild(1), \"R\", 30, get(\"width\"));\n\t\t\t\tsend(nthChild(0), \"setFolded\", 1);\n\t\t\t\treturn get(\"height\") + 20;\n\t\t\t} else {\n\t\t\t\treturn 20;\n\t\t\t}\n\t\t}\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"OL\");\n\t\treturn get(\"height\") + style[1];\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3],\n\t\t\t\tget(\"width\") - style_p[3] - 30 - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'L':\n\t\treturn 'U';\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"UL\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tif (foldInfo == 0) {\n\t\t\tsend(self(), \"reInit\");\n\t\t\tif (label) drawText(35, 1, 1, label);\n\t\t}\n\n\t\tif (canFold) vspan += 18;\n\t\tif (canFold == 0 || folded == 0) {\n\t\t\tn = countChildren();\n\t\t\tif (n > canFold/*XXX warning: logic/numeral mix*/) {\n\t\t\t\txx = get(\"width\");\n\t\t\t\tfor (i = canFold; i < n; i++)\n\t\t\t\t  vspan += send(nthChild(i), 'R', vspan, xx);\n\t\t\t}\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1] + 7; /*xxx should affect in style */\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"UL\");\n\t\tvspan = style[0];\n\t\tset(\"width\", get(\"width\") - style[3]);\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = canFold; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"folded\":\n\t\tif (foldInfo == 0) send(self(), \"reInit\");\n\t\tfolded = arg[1];\n\t\tsend(send(parent(), \"findTop\"), \"resizeSelf\");\n\t\treturn;\n\tbreak;\n\tcase \"toggleFolded\":\n\t\tif (foldInfo == 0) send(self(), \"reInit\");\n\t\tif (folded) folded = 0;\n\t\telse folded = 1;\n\t\tsend(send(parent(), \"findTop\"), \"resizeSelf\");\n\t\treturn folded;\n\tbreak;\n\tcase \"data\":\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"COMPACT\":\n\t\t\tcompact = 1;\n\t\tbreak;\n\t\tcase \"LABEL\":\n\t\t\tlabel = arg[2];\n\t\tbreak;\n\t\tcase \"FOLD\":\n\t\t\tcanFold = 1;\n\t\t\tif (arg[2] == \"yes\" || arg[2] == \"YES\") folded = 1;\n\t\t\tset(\"BDColor\", get(\"FGColor\"));\n\t\t\tnew = send(\"HTML__foldIcon\", \"make\", self());\n\t\t\tset(\"children\", new);\n\t\tbreak;\n\t\tcase \"BORDER\":\n\t\t\tset(\"BDColor\", \"black\");\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"compact\":\n\t\treturn compact;\n\tbreak;\n\tcase \"folded?\":\n\t\treturn folded;\n\tbreak;\n\tcase \"canFold?\":\n\t\treturn canFold;\n\tbreak;\n\tcase \"label?\":\n\t\treturn label;\n\tbreak;\n\tcase \"setAnchor\":\n\t\tmakeAnchor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\tfor (i = canFold; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\tfor (i = canFold; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findForm\":\n\tcase \"findTop\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"reInit\":\n\t\t/*HIGH KLUDGE-- to know if clone has occured*/\n\t\tfoldInfo = 1;\n\t\to = object(get(\"content2\"));\n\t\tif (o) {\n\t\t\tcanFold = send(o, \"canFold?\");\n\t\t\tfolded = send(o, \"folded?\");\n\t\t\tlabel = send(o, \"label?\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tfoldInfo = 1;\n\t\tSGMLBuildDoc_setColors();\n\t\tcolor = getResource(\"Viola.background_doc\");\n\t\tif (color) set(\"BDColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_listBullet2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tlabel\n\t\t */\n\t\treturn send(clone(cloneID()), \"parent\", arg[1]);\n\tbreak;\n\tcase \"parent\":\n\t\tset(\"parent\", arg[1]);\n\t\treturn self();\n\tbreak;\n\tcase \"noBullet\":\n\t\treturn freeSelf();\n\tbreak;\n\tcase \"R\":\n\tcase \"config\":\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"BGColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_listC2[] = "\n/*\tprint(\"@@@@@@ HTML_listC clsss = txtDisp: args: \");\n\tfor (i =0; i < arg[]; i++) print(arg[i], \", \");\n\tprint(\"\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn height();\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n/*\t\tSGMLBuildDoc_setBuff(-1);*/\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], width() - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'L':\n\t\treturn 'U';\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"ULC\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = width();\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"ULC\");\n\t\tvspan = style[0];\n\t\tset(\"width\", width() - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"COMPACT\":\n\t\t\tcompact = 1;\n\t\tbreak;\n\t\tcase \"BORDER\":\n\t\t\tset(\"BDColor\", \"black\");\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"compact\":\n\t\treturn 1;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_listItem2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\th = SGMLBuildDoc_span();\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tvspan = -1;\n\t\tset(\"x\", 30);\t\t/*XXX*/\n\t\tset(\"y\", arg[1]);\n\t\tset(\"width\", arg[2] - get(\"x\"));\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tx\n\t\t * arg[3]\ty\n\t\t * arg[4]\twidth\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"x\", arg[2]);\n\t\tset(\"y\", arg[3]);\n\t\tset(\"width\", arg[4]);\n\n\t\th = 1;\n\n\t\t/* in case there's text before <LI> */\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\t/* ^ needed for this case due to the inserting of this object\n\t\t * by HTML_listSep (at its Flush time).\n\t\t */\n\n\t\ttxt = get(\"label\");\n\t\tif (isBlank(txt) == 0) {\n\t\t\tnew = HTML_txt(\"clone\");\n\t\t\tw = get(\"width\");\n\t\t\th = send(new, \"make\", self(),\n\t\t\t\tcompressSpaces(txt), 0, w, 0, 0);\n\t\t\tobjectListAppend_children(new);\n\t\t\tsend(parent(), \"specialInsertOccured\");\n\t\t}\n\t\treturn h;\n\tbreak;\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (id == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (id == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"L\":\n\tcase \"compact\":\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"C\":/* useless-- but keep to keep viola quiet */\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_listItem[] = {
    {"class", _slotValue_HTML_listItem0},
    {"name", _slotValue_HTML_listItem1},
    {"script", _slotValue_HTML_listItem2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_listMenu0[] = "txtDisp";
static char _slotValue_HTML_listMenu1[] = "HTML_listMenu";
static char _slotValue_HTML_listMenu2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tlabel\n\t\t */\n\t\treturn send(clone(cloneID()), \"parent\", arg[1]);\n\tbreak;\n\tcase \"parent\":\n\t\tset(\"parent\", arg[1]);\n\t\treturn self();\n\tbreak;\n\tcase \"label\":\n\t\tset(\"content\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_listNum2[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tlabel\n\t\t */\n\t\treturn send(clone(cloneID()), \"parent\", arg[1]);\n\tbreak;\n\tcase \"parent\":\n\t\tset(\"parent\", arg[1]);\n\t\treturn self();\n\tbreak;\n\tcase \"label\":\n\t\tset(\"label\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"noBullet\":\n\t\tset(\"label\", \"\");\n\t\tclearWindow();\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_listNum_oval2[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tlabel\n\t\t */\n\t\treturn send(clone(cloneID()), \"parent\", arg[1]);\n\tbreak;\n\tcase \"parent\":\n\t\tset(\"parent\", arg[1]);\n\t\treturn self();\n\tbreak;\n\tcase \"R\":\n\t\treturn 0;\n\tbreak;\n\tcase \"label\":\n\t\tset(\"label\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"noBullet\":\n\t\tset(\"label\", \"\");\n\t\tclearWindow();\n\t\treturn;\n\tbreak;\n\tcase \"render\":\n\tcase \"expose\":\n\t\tusual();\n\t\tdrawOval(0, 0, 27, 17); /* XXX make this flexible */\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_listNumbered2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\tif (label) drawText(35, 1, 1, label);\n\t\treturn;\n\tbreak;\n\tcase \"D\":\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\titemN++;\n\t\t\t\tsend(nthChild(i), \"itemN\", itemN);\n\t\t\t}\n\t\t}\n\t\tset(\"content2\", self());/*a kludge to deal with cloning*/\n\t\tif (canFold) {\n\t\t\tif (folded) {\n\t\t\t\t/* make the first list item go away,\n\t\t\t\t * to show the toggler */\n\t\t\t\tsend(nthChild(1), \"R\", 30, get(\"width\"));\n\t\t\t\tsend(nthChild(0), \"setFolded\", 1);\n\t\t\t\treturn get(\"height\") + 20;\n\t\t\t} else {\n\t\t\t\treturn 20;\n\t\t\t}\n\t\t}\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"OL\");\n\t\treturn get(\"height\") + style[1];\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n/*\t\tSGMLBuildDoc_setBuff(-1);*/\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'L':\n\t\treturn 'O';\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"OL\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tif (foldInfo == 0) {\n\t\t\tsend(self(), \"reInit\");\n\t\t\tif (label) drawText(35, 1, 1, label);\n\t\t}\n\n\t\tif (canFold) vspan += 18;\n\t\tif (canFold == 0 || folded == 0) {\n\t\t\tn = countChildren();\n\t\t\tif (n > canFold/*XXX warning: logic/numeral mix*/) {\n\t\t\t\txx = get(\"width\");\n\t\t\t\tfor (i = canFold; i < n; i++)\n\t\t\t\t  vspan += send(nthChild(i), 'R', vspan, xx);\n\t\t\t}\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"OL\");\n\t\tvspan = style[0];\n\t\tset(\"width\", get(\"width\") - style[3]);\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = canFold; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"folded\":\n\t\tif (foldInfo == 0) send(self(), \"reInit\");\n\t\tfolded = arg[1];\n\t\tsend(send(parent(), \"findTop\"), \"resizeSelf\");\n\t\treturn;\n\tbreak;\n\tcase \"toggleFolded\":\n\t\tif (foldInfo == 0) send(self(), \"reInit\");\n\t\tif (folded) folded = 0;\n\t\telse folded = 1;\n\t\tsend(send(parent(), \"findTop\"), \"resizeSelf\");\n\t\treturn folded;\n\tbreak;\n\tcase \"data\":\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"COMPACT\":\n\t\t\tcompact = 1;\n\t\tbreak;\n\t\tcase \"LABEL\":\n\t\t\tlabel = arg[2];\n\t\tbreak;\n\t\tcase \"FOLD\":\n\t\t\tcanFold = 1;\n\t\t\tif (arg[2] == \"yes\" || arg[2] == \"YES\") folded = 1;\n\t\t\tset(\"BDColor\", get(\"FGColor\"));\n\t\t\tnew = send(\"HTML__foldIcon\", \"make\", self());\n\t\t\tset(\"children\", new);\n\t\tbreak;\n\t\tcase \"BORDER\":\n\t\t\tset(\"BDColor\", \"black\");\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"compact\":\n\t\treturn compact;\n\tbreak;\n\tcase \"folded?\":\n\t\treturn folded;\n\tbreak;\n\tcase \"canFold?\":\n\t\treturn canFold;\n\tbreak;\n\tcase \"label?\":\n\t\treturn label;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\tfor (i = canFold; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > canFold) {\n\t\t\tfor (i = canFold; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"findForm\":\n\t\treturn send(parent(), \"findForm\");\n\tbreak;\n\tcase \"reInit\":\n\t\t/*HIGH KLUDGE-- to know if clone has occured*/\n\t\tfoldInfo = 1;\n\t\to = object(get(\"content2\"));\n\t\tif (o) {\n\t\t\tcanFold = send(o, \"canFold?\");\n\t\t\tfolded = send(o, \"folded?\");\n\t\t\tlabel = send(o, \"label?\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tfoldInfo = 1;\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_listNumberedC2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"OLC\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\titemN++;\n\t\t\t\tsend(nthChild(i), \"itemN\", itemN);\n\t\t\t}\n\t\t}\n\t\treturn height() + style[1];\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], width() - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'L':\n\t\treturn 'O';\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"OLC\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = width();\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"OLC\");\n\t\tvspan = style[0];\n\t\tset(\"width\", width() - style[3]);\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = width();\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"COMPACT\":\n\t\t\tcompact = 1;\n\t\tbreak;\n\t\tcase \"BORDER\":\n\t\t\tset(\"BDColor\", \"black\");\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"compact\":\n\t\treturn 1;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_listSep2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\treturn;\n\tbreak;\n\tcase \"D\":\n\t\tif (send(parent(), \"compact\")) saveSpace = 3;\n\t\tif (specialInsertOccured == 1) {\n\t\t\th = send(self(), 'R', get(\"y\"), get(\"width\"), \n\t\t\t\t get(\"x\")) - saveSpace;\n\t\t} else {\n\t\t\th = get(\"height\") - saveSpace;\n\t\t}\n\t\tSGMLBuildDoc_setBuff(0);\n\t\t/*^^ necessary, else the \"First item\" will appear twice in */\n\t\t/*\n\t\t<UL>\n\t\t<LI>First item\n\t\t<P>\n\t\t<LI>Second item\n\t\t</UL>\n\t\t*/\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tlistType = send(parent(), 'L');\n\t\t\tif (first == 0) {\n\t\t\t\tfirst = 1;\n\t\t\t\tswitch (listType) {\n\t\t\t\tcase 'U':\t/* UL */\n\t\t\t\t\tbulletObj = HTML_listBullet(\"make\", \n\t\t\t\t\t\t\t\t    self());\n\t\t\t\t\tobjectListAppend_children(bulletObj);\n\t\t\t\t\tx_offset = 30;\n\t\t\t\t\tobjResizeSkip = 1;\n\t\t\t\tbreak;\n\t\t\t\tcase 'O':\t/* OL */\n\t\t\t\t\t/*bulletObj = HTML_listNum_oval(\"make\",\n\t\t\t\t\t\t\t      self());*/\n\t\t\t\t\tbulletObj = HTML_listNum(\"make\",self());\n\t\t\t\t\tobjectListAppend_children(bulletObj);\n\t\t\t\t\tx_offset = 30;\n\t\t\t\t\tobjResizeSkip = 1;\n\t\t\t\tbreak;\n\t\t\t\tdefault:\n\t\t\t\t\tx_offset = 35;\n\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (listTxt_style == 0) \n\t\t\t\tlistTxt_style = SGMLGetStyle(\"HTML\", \n\t\t\t\t\t\t\t     \"P_in_listSep\");\n\t\t\ttxtObj = HTML_listTxt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tx_offset,\n\t\t\t\tget(\"width\") - x_offset - listTxt_style[3],\n\t\t\t\th, 0);\n\t\t}\n\t\tset(\"height\", h + 2);\n\t\treturn h;\n\tbreak;\n\tcase \"F\":\n\t\t/* create and set insertObject before \"D\", so flush this obj\n\t\t */\n\t\tif (parent() == 0) return;\n\t\tlistType = send(parent(), 'L');\n\t\ty = SGMLBuildDoc_span();\n\t\tif (first == 0) {\n\t\t\tfirst = 1;\n\t\t\tswitch (listType) {\n\t\t\tcase 'U':\t/* UL */\n\t\t\t\tbulletObj = HTML_listBullet(\"make\", self());\n\t\t\t\tobjectListAppend_children(bulletObj);\n\t\t\t\tx_offset = 30;\n\t\t\t\tobjResizeSkip = 1;\n\t\t\tbreak;\n\t\t\tcase 'O':\t/* OL */\n\t\t\t\tbulletObj = HTML_listNum(\"make\", self());\n\t\t\t/*bulletObj = HTML_listNum_oval(\"make\", self());*/\n\t\t\t\tobjectListAppend_children(bulletObj);\n\t\t\t\tx_offset = 30;\n\t\t\t\tobjResizeSkip = 1;\n\t\t\tbreak;\n\t\t\tdefault:\n\t\t\t\tx_offset = 30;\n\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tswitch (listType) {\n\t\tcase 'U':\t/* UL */\n\t\t\tlistItemContainer = HTML_listItem(\"clone\");\n\t\t\tw = get(\"width\") - 30;\n\t\t\ttxtH = send(listItemContainer, \"make\", self(), \n\t\t\t\t\t30, y, w);\n\t\t\tSGMLBuildDoc_insertObj(listItemContainer, w);\n\n\t\t\treturn -1;\n\t\tbreak;\n\t\tcase 'O':\t/* OL */\n\t\t\tlistItemContainer = HTML_listItem(\"clone\");\n\t\t\tw = get(\"width\") - 40;\n\t\t\ttxtH = send(listItemContainer, \"make\", self(), \n\t\t\t\t\t30, y, w);\n\t\t\tSGMLBuildDoc_insertObj(listItemContainer, w);\n\n\t\t\treturn -1;\n\t\tbreak;\n\t\tcase 'D':\t/* DIR */\n\t\t\tlistItemContainer = HTML_listItem(\"clone\");\n\t\t\tw = get(\"width\") - 30;\n\t\t\ttxtH = send(listItemContainer, \"make\", self(), \n\t\t\t\t\t30, h, w);\n\t\t\tSGMLBuildDoc_insertObj(listItemContainer, w);\n\n\t\t\treturn -1;\n\t\tbreak;\n\t\tcase 'M':\t/* MENU */\n\t\tdefault:\n\t\t\tlistItemContainer = HTML_listItem(\"clone\");\n\t\t\tw = get(\"width\") - 30;\n\t\t\ttxtH = send(listItemContainer, \"make\", self(), \n\t\t\t\t\t30, h, w);\n\t\t\tSGMLBuildDoc_insertObj(listItemContainer, w);\n\t\t\treturn -1;\n\t\tbreak;\n\t\t}\n\tbreak;\n\tcase 'R': /* resize */\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\tx (optional)\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"LI\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - style[3]);\n\t\tif (arg[] == 4) set(\"x\", arg[3]);\n\t\th = 0;\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = objResizeSkip; i < n; i++)\n\t\t\t\th += send(nthChild(i), 'R', h, xx) - saveSpace;\n\t\t}\n\t\tvspan += h;\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"AA\":\n\tcase \"AI\":\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"itemN\":\n\t\tsend(nthChild(0), \"label\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"specialInsertOccured\":\n\t\tspecialInsertOccured = 1;\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"setAnchor\":\n\t\treturn send(parent(), \"setAnchor\", arg[1]);\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_listSep[] = {
    {"class", _slotValue_HTML_listSep0},
    {"name", _slotValue_HTML_listSep1},
    {"script", _slotValue_HTML_listSep2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_listTxt0[] = "txtDisp";
static char _slotValue_HTML_listTxt1[] = "HTML_listTxt";
static char _slotValue_HTML_listTxt2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\twww.mesg.tf(\"clear\");\n\t\tprevHint = 0;\n\t\treturn;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P_in_listSep\");\n\t\tvspan = style[0];\n\t\tset(\"width\", get(\"width\") - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tclearWindow();\n\t\trender();/*may be extraneous */\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P_in_listSep\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tclearWindow();\n\t\tvspan += set(\"height\", building_vspan()+2) + style[1];\n\t\trender(); /* render() affects building_vspan() ? */\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t \t/* arg[1]\tparent\n\t \t * arg[2]\tdata\n\t \t * arg[3]\tx\n\t \t * arg[4]\twidth\n\t \t * arg[5]\ty\n\t \t */\n\t \tset(\"parent\", arg[1]);\n\t \tset(\"x\", arg[3]);\n\t \tset(\"y\", arg[5]);\n\t \tset(\"width\", arg[4]);\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t \tset(\"content\", arg[2]);\n\t \th = building_vspan();\n\t \tset(\"height\", h);\n\t \tset(\"maxHeight\", h);\n\t \tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P_in_listSep\");\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t \treturn style[0] + h + style[1];\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
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
static char _slotValue_HTML_listing2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\texpose(arg[1], arg[2], arg[3], arg[4]);\n\t\treturn;\n\tbreak;\n\tcase \"D\": /* done */\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\tset(\"content\", get(\"label\"));\n\t\treturn building_vspan();\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"LISTING\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_math2[] = "\nprint(\"HTML_math: self=\", self(), \"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\\n\");\nfor(i=0;i<arg[];i++) print(\"arg[\",i,\"]={\",arg[i],\"}\\n\");\n\n\tswitch (arg[0]) {\n\tcase \"config\":\nprint(\"CAUGHT CONFIG\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\t\ttest4();\n\t\treturn;\n\tbreak;\n\tcase \"flush\":\n\t\tif (isBlank(get(\"label\"))) return -1;\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = get(\"label\");\n\t\ttokCount++;\n\n\t\treturn -1;\n\tbreak;\n\tcase \"entity\":\nprint(\"ENTITY FLUSH MATH label>>>>>\", get(\"label\"), \"<<<\\n\");\n\n\t\tif (isBlank(get(\"label\"))) return 0;\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = get(\"label\");\n\t\ttokCount++;\n\n\t\tentity_number = arg[1];\n\t\tif (entity_number == 50) {/*infin*/\n\t\t} else if (entity_number == 51) { /*integral*/\n\t\t\ttok[tokCount] = 19; /*MINFO_INTEGRAL*/\n\t\t\tdata[tokCount] = \"\";\n\t\t\ttokCount++;\n\t\t} else if (entity_number == 65) { /*sigma*/\n\t\t\ttok[tokCount] = 20; /*MINFO_SUM*/\n\t\t\tdata[tokCount] = \"\";\n\t\t\ttokCount++;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"tok&data\":\n\t\t/* arg[1]\ttoken\n\t\t * arg[2]\tdata\n\t\t */\n\t\ttok[tokCount] = arg[1];\n\t\tdata[tokCount] = arg[2];\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\t/* arg[1]\tdata\n\t\t */\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = arg[1];\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"tok\":\n\t\t/* arg[1]\ttoken type\n\t\t */\n\t\ttok[tokCount] = arg[1];\n\t\tdata[tokCount] = \"\";\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"F\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\tif (isBlank(get(\"label\"))) return -1;\n/*print(\"F MATH label>>>>>\", get(\"label\"), \"<<<\\n\");\n*/\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = get(\"label\");\n\t\ttokCount++;\n\n\t\treturn -1;\n\tbreak;\n\tcase \"D\":\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\ttok[tokCount] = 2;\n\t\t\tdata[tokCount] = get(\"label\");\n\t\t\ttokCount++;\n\t\t}\n\n\t\tfor (i = 0; i < tokCount; i++) {\n\t\t\tprint(\"math_tok \", i, \":   type=\", tok[i], \n\t\t\t\t\"data={\", data[i], \"}\\n\");\n\t\t}\n\n/*\t\ttagPtr = STG_tagPtr(\"MATH\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tSGMLMathFormater(tok, data, tokCount);\nprint(\"MATH: D after1 width=\", width(),\"\\n\");\nprint(\"MATH: D after1 height=\", height(),\"\\n\");\n\t\tset(\"width\", get(\"width\"));\n\t\tset(\"height\", get(\"height\"));\nprint(\"MATH: D after2 width=\", width(),\"\\n\");\nprint(\"MATH: D after2 height=\", height(),\"\\n\");\n/*\t\ttokCount = 0;\n*/\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"MATH\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\nprint(\"MATH: R before  width=\", width(),\"\\n\");\nprint(\"MATH: R before  height=\", height(),\"\\n\");\n\t\tSGMLMathFormater(tok, data, tokCount);\n\n\t\tvspan += set(\"height\", get(\"height\")) + style[1];\nprint(\"MATH: R after  width=\", width(),\"\\n\");\nprint(\"MATH: R after  height=\", height(),\"\\n\");\nprint(\"MATH: R result vspan=\", vspan,\"\\n\");\n\t\treturn vspan;\n\tbreak;\n\tcase 'b':\n\t\treturn border;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"MATH\");\n\t\tvspan = style[0];\n\n\t\tSGMLMathFormater(tok, data, tokCount);\n\n\t\tset(\"height\", vspan + get(\"height\") + style[1]);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn 0;\n\tbreak;\n\tcase \"reportTitle\":\n\t\ttitle = arg[1];\n\t\ttitleAtTopP = arg[2];\n\t\ttitleAlign = arg[3];\n\t\treturn;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"BORDER\":\n\t\t\tborder = 1;\n\t\tbreak;\n\t\tcase \"COMPACT\":\n\t\t\tcompact = 1; \t/* NOT USED YET */\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n/*\t\tSGMLBuildDoc_setColors();*/\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_menu2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\": /* flush */\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_li == 0)\n\t\t\t\tstyle_li = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\ty = SGMLBuildDoc_span();\n\t\t\th = send(txtObj, \"make\", self(), get(\"label\"),\n\t\t\t\tstyle_li[2], \n\t\t\t\tget(\"width\") - style_li[2], y, 'M');\n\t\t} \n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\": /* done */\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_li == 0)\n\t\t\t\tstyle_li = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\ty = get(\"height\");\n\t\t\th += send(txtObj, \"make\", self(), get(\"label\"),\n\t\t\t\tstyle_li[2], \n\t\t\t\tget(\"width\") - style_li[2], y, 'M');\n\t\t} \n\t\tset(\"height\", h);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase 'L':\n\t\treturn 'M';\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"MENU\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\t}\n\tbreak;\n\tcase \"compact\":\n\t\treturn 1;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_menuSep2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\ttxt = send(parent(), \"data\");\n\t\tif (isBlank(txt)) {\n\t\t\treturn 0;\n\t\t} else {\n\t\t\tlistItemObj = HTML_txtListItem(\"clone\");\n\n\t\t\tset(\"children\", listItemObj);\n\n\t\t\th = send(listItemObj, \"make\", self(), txt,\n\t\t\t\t\t40, width() - 40);\n\n\t\t\t/* to number or not? */\n\t\t\tif (send(parent(), 'N')) {\n\t\t\t\tbulletObj = HTML_listNum(\"make\", self());\n\t\t\t} else {\n\t\t\t\tbulletObj = HTML_listBullet(\"make\", self());\n\t\t\t}\n\t\t\tobjectListAppend_children(bulletObj);\n\n\t\t\treturn h;\n\t\t}\n\tbreak;\n\tcase 'R': /* resize */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"LI\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tvspan = send(nthChild(0), \"R\", vspan, width() - 40);\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t/* arg[2]\tdata\n\t\t * arg[3]\tx\n\t\t * arg[4]\twidth\n\t\t * arg[5]\ty\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"x\", arg[3]);\n\t\tset(\"y\", arg[5]);\n\n\t\ttxt = arg[2];\n\n\t\tlistItemObj = HTML_txtListItem(\"clone\");\n\n\t\tset(\"children\", listItemObj);\n\n\t\th = send(listItemObj, \"make\", self(), txt,\n\t\t\t\t40, arg[4] - 40);\n\n\t\t/* to number or not? */\n\t\tif (send(parent(), 'N')) {\n\t\t\tbulletObj = HTML_listNum(\"make\", self());\n\t\t} else {\n\t\t\tbulletObj = HTML_listBullet(\"make\", self());\n\t\t}\n\t\tobjectListAppend_children(bulletObj);\n\n\t\tset(\"width\", arg[4]);\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"itemN\":\n\t\tsend(nthChild(1), \"label\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"noBullet\":\n\t\tw = width();\n\t\tset(\"label\", \"\");\n\t\tclearWindow();\n\t\tset(\"width\", w);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_mh2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\ttext = get(\"label\");\n\t\tsend(parent(), \"reportMailHeader\", text);\n\t\treturn -1;\n\tbreak;\n\tcase \"config\":\n\tcase \"R\":\n\t\treturn 0;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_mh[] = {
    {"class", _slotValue_HTML_mh0},
    {"name", _slotValue_HTML_mh1},
    {"script", _slotValue_HTML_mh2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_nextID0[] = "field";
static char _slotValue_HTML_nextID1[] = "HTML_nextID";
static char _slotValue_HTML_nextID2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\treturn -1;\n\tbreak;\n\tcase \"D\":\n/*\t\ttext = get(\"label\");\n\t\tsend(send(parent(), \"findTop\"), \"reportNextID\", text);\n*/\n\t\treturn -1;\n\tbreak;\n\tcase \"R\":\n\t\treturn 0;\n\tbreak;\n\tcase \"config\":\n\tcase \"AA\":\n\tcase \"AI\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_nextID[] = {
    {"class", _slotValue_HTML_nextID0},
    {"name", _slotValue_HTML_nextID1},
    {"script", _slotValue_HTML_nextID2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_option0[] = "field";
static char _slotValue_HTML_option1[] = "HTML_option";
static char _slotValue_HTML_option2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tsend(parent(), \"option\", varDefault, get(\"label\"), checked);\n\t\tvarDefault = \"\";\n\t\tchecked = 0;\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\tcase \"AI\":\n\t\treturn 0;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"VALUE\":\n\t\t\tvarDefault = arg[2];\n\t\tbreak;\n\t\tcase \"SELECTED\":\n\t\tcase \"CHECKED\":\n\t\t\tchecked = 1;\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<OPTION\");\n\t\tif (varDefault) print(\" VALUE=\\\"\", varDefault, \"\\\"\");\n\t\tif (checked) print(\" SELECTED\");\n\t\tprint(\">\\n\");\n\t\tprint(get(\"content\"));\n\t\tprint(\"\\n\");\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_option[] = {
    {"class", _slotValue_HTML_option0},
    {"name", _slotValue_HTML_option1},
    {"script", _slotValue_HTML_option2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_over0[] = "field";
static char _slotValue_HTML_over1[] = "HTML_over";
static char _slotValue_HTML_over2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tset(\"y\", -10);\n\t\tsend(parent(), \"over\");\n\t\treturn 0;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_plain2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"D\": /* done */\n\t\tset(\"content\", get(\"label\"));\n\t\treturn (building_vspan() + 2);\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"EXAMPLE\");/*XXX*/\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_plaintext2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"D\": /* done */\n\t\tset(\"content\", get(\"label\"));\n\t\treturn (building_vspan() + 2);\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_pre2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\treturn;\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n/*\t\tSGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_preTxt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tget(\"label\"),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_preTxt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tget(\"label\"),\n\t\t\t\tstyle_p[3],\n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"PRE\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"r\":\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"PRE\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn 1;\n\tbreak;\n\tcase \"setAnchor\":\n\t\tmakeAnchor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn get(\"label\");\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"findForm\":\n\t\treturn send(parent(), \"findForm\");\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<SECTION>\\n\");\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tsend(nthChild(i), \"outputSGML\");\n\t\t}\n\t\tprint(\"</SECTION>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_pre[] = {
    {"class", _slotValue_HTML_pre0},
    {"name", _slotValue_HTML_pre1},
    {"script", _slotValue_HTML_pre2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_preTxt0[] = "txtDisp";
static char _slotValue_HTML_preTxt1[] = "HTML_preTxt";
static char _slotValue_HTML_preTxt2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\texpose(arg[1], arg[2], arg[3], arg[4]);\n\t\treturn;\n\tbreak;\n\tcase \"D\": /* done */\n\t\tif (isBlank(get(\"label\"))) return 0;\n\t\tif (deco) {\n\t\t\tbox = send(deco, \"clone\");\n\t\t\tobjectListAppend_children(box);\n\t\t\th = send(box, \"make\", self(), \n\t\t\t\tget(\"label\"), get(\"width\"));\n\t\t\treturn h + 2;\n\t\t\t/* +2 for hot-link-indicator border around IMGs */\n\t\t} else {\n\t\t\tinPreP = send(parent(), \"inPreP\");\n\t\t\tif (inPreP) set(\"format\", 0);\n\t\t\tset(\"content\", get(\"label\"));\n\t\t\tset(\"label\", \"\");\n\t\t\tisHTML = 1;\n\t\t\treturn building_vspan()+2;\n\t\t\t/* +2 for hot-link-indicator border around IMGs */\n\t\t}\n\tbreak;\n\tcase \"F\": /* flush */\n\t\treturn 1;\n\tbreak;\n\tcase 'R': /* resize */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tw = arg[2] - get(\"x\") - style[3];\n\t\tset(\"width\", w);\n\t\tif (deco) {\n\t\t\th = send(nthChild(0), \"R\", w);\n\t\t\tset(\"height\", h);\n\t\t\treturn h + style[1];\n\t\t} else {\n\t\t\tset(\"content\", trimEdgeQ(get(\"content\")));\n\t\t\tclearWindow();\n\t\t\tvspan += set(\"height\", building_vspan()+2) + style[1];\n\t\t\t/* +2 for hot-link-indicator border around IMGs */\n\t\t\trender();\n\t\t\treturn vspan;\n\t\t}\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\tvspan = style[0];\n\t\tset(\"width\", get(\"width\") - style[3]);\n\t\tset(\"content\", trimEdgeQ(get(\"content\")));\n\t\tclearWindow();\n\t\trender();\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagIDs[tagIDCount] = arg[2];\n\t\t\ttagIDCount = tagIDCount + 1;\n\t\tbreak;\n\t\tcase \"STYLE\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"QUOTE\":\n\t\t\tbreak;\n\t\t\tcase \"MARGIN\":\n\t\t\tbreak;\n\t\t\tcase \"NOTE\":\n\t\t\t\tdeco = \"HTML__txtBox_note\";\n\t\t\tbreak;\n\t\t\tcase \"CAUTION\":\n\t\t\t\tdeco = \"HTML__txtBox_caution\";\n\t\t\tbreak;\n\t\t\tcase \"WARNING\":\n\t\t\t\tset(\"BDColor\", \"darkOrange\");\n\t\t\t\tdeco = \"HTML__txtBox_caution\";\n\t\t\tbreak;\n\t\t\tcase \"ERROR\":\n\t\t\t\tset(\"BDColor\", \"red\");\n\t\t\t\tdeco = \"HTML__txtBox_error\";\n\t\t\tbreak;\n\t\t\tcase \"TIMED\": /*just for fun*/\n\t\t\t\tdeco = \"HTML__txtBox_time\";\n\t\t\tbreak;\n\t\t\tcase \"NORMAL\":\n\t\t\tdefault:\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\tcase \"COMPACT\":\n\t\t\tcompact = 1; \t/* NOT USED YET */\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"setAnchor\":\n\t\ttagIDs[tagIDCount] = arg[1];\n\t\ttagIDCount++;\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagIDCount > 0)\n\t\t\tfor (i = 0; i < tagIDCount; i++)\n\t\t\t\tif (tagIDs[i] == arg[1]) return get(\"y\");\n\t\treturn 0;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"config\":\n\t\t/* necessary in case of HPANE triggered resizes */\n\t\tclearWindow();\n\t\tusual();\t\t\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<P>\", get(\"content\"), \"\\n\");\n/*\n\t\tn = anchor....\n\t\tif (n) {\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tsend(nthChild(i), \"outputSGML\");\n\t\t}\n*/\n\t\tprint(\"</P>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
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
static char _slotValue_HTML_psep2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn 0;\n\tbreak;\n\tcase 'i':\n\t\tsend(parent(), \"makeTxt\");\n\t\treturn \"\";\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_psf2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tvspan += get(\"height\") + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tw\n\t\t * arg[3]\ty\n\t\t * arg[4]\tsrc\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[2]);\n\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\t\tset(\"y\", style[0]);\n\t\tset(\"x\", arg[3] + style[2]);\n\n/*bleh*/\tlocalSource = HTTPGet(arg[4]);\n\t\tfnNoExt = parseHTTPAddress(\"name\", concat(localSource, \".ps\"));\n\t\tsystem(concat(\"mv \", localSource, \" /tmp/\", fnNoExt, \".ps\"));\n\t\tlocalSource = concat(\"/tmp/\", fnNoExt, \".ps\");\n/*\nprint(\"arg[4]={\", arg[4], \"}\\n\");\nprint(\"localSource={\", localSource, \"}\\n\");\nprint(\"fnNoExt={\", fnNoExt, \"}\\n\");\n*/\n\t\tif (arg[5] > 0) {\n\t\t\tafter(arg[5], self(), \n\t\t\t\t\"loadData\", localSource, arg[6], arg[7]);\n\t\t\tset(\"width\", arg[6]);\n\t\t\tset(\"height\", arg[7]);\n\t\t\treturn height();\n\t\t} else {\n\t\t\tBITPLANES = 1;\n\t\t\tsystem(\"rm -f /tmp/ps2gif.tmp\");\n\t\t\tsaveFile(\"/tmp/ps2gif.tmp\",\n\t\t\t   concat(\"(pstoppm.ps) run\\n\",\n\t\t\t\t  \"80 80 ppmsetdensity\\n\",\n\t\t\t\t  \"(/tmp/) ppmsetprefix\\n\",\n\t\t\t\t  \"(\", fnNoExt, \") ppm\", BITPLANES, \"run\\n\",\n\t\t\t\t  \"80 80 ppmsetdensity\\n\"));\n\t\t\tsystem(\"cd /tmp; gs -DNODISPLAY -dSAFER -q < /tmp/ps2gif.tmp\");\n\n/*\t\t\tsystem(concat(\"rm -f /tmp/\", fnNoExt));\n*/\n\t\t\tlocalFile = concat(\"/tmp/\", fnNoExt, \".gif\");\n/*\nprint(\"localFile={\", localFile, \"}\\n\");\nprint(\"fnNoExt={\", fnNoExt, \"}\\n\");\n*/\n\t\t\tsystem(concat(\"ppmtogif < /tmp/\", \n\t\t\t\t\tfnNoExt, \".ppm > \", localFile));\n\n\t\t\tsystem(concat(\"rm -f /tmp/\", fnNoExt, \".ppm\"));\n\t\t\tsystem(\"rm -f /tmp/ps2gif.tmp\");\n\n\t\t\t/* to get the gif in its natural dimension */\n\t\t\tset(\"width\", 0);\n\t\t\tset(\"height\", 0);\n\n\t\t\tset(\"label\", localFile);\n\n\t\t\treturn height();\n\t\t}\n\tbreak;\n\tcase \"loadData\":\n\t\tset(\"label\", loadFile(arg[1]));\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_quote2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"D\":\n\t\ttext = get(\"label\");\n\t\tset(\"content\", text);\n\t\treturn (building_vspan() + 1);\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_script2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn 0;\n\tbreak;\n\tcase 'i':\n\t\tprint(\"WARNING: INTERPRETING SCRIPT >>\", get(\"label\"), \"<<\\n\");\n\t\tss = interpret(get(\"label\"));\n\t\tprint(\"INTERPRETION RESULT >>\", ss, \"<<\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_script[] = {
    {"class", _slotValue_HTML_script0},
    {"name", _slotValue_HTML_script1},
    {"script", _slotValue_HTML_script2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_select0[] = "HTML_select";
static char _slotValue_HTML_select1[] = "menu";
static char _slotValue_HTML_select2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"option\":\n\t\t/* arg[1]\tselect value\n\t\t * arg[2]\tselect label\n\t\t * arg[3]\tchecked?\n\t\t */\n\t\toptVal[optCount] = arg[1];\n\t\toptLabel[optCount] = compressSpaces(arg[2]);\n\t\tif (arg[3] == 1) checkedItem = optCount + 1;\n\t\toptCount++;\n\t\treturn;\n\tbreak;\n\tcase \"pick\":\n\t\tset(\"label\", optLabel[arg[1]]);\n\t\tvalue = optLabel[arg[1]];\n\t\treturn;\n\tbreak;\n\tcase 'i':\n\t\tnew = send(self(), \"clone\");\n\t\tsend(new, \"make\", tagID, defaultVal, \n\t\t\toptVal, optLabel, optCount, checkedItem);\n\t\tt = concat(\"\\\\o(\", new, \")\");\n\n\t\ttagID = \"\";\n\t\tdefaultVal = \"\";\n\t\toptVal = 0;\n\t\toptLabel = 0;\n\t\toptCount = 0;\n\t\tcheckedItem = 0;\n\n\t\treturn t;\n\tbreak;\n\tcase \"make\":\n\t\ttagID = arg[1];\n\t\tdefaultVal = arg[2];\n\t\toptVal = arg[3];\n\t\toptLabel = arg[4];\n\t\toptCount = arg[5];\n\t\tcheckedItem = arg[6];\n\n\t\t/* cheexy way to set width */\n\t\tmaxLength = 0;\n\t\tfor (i = 0; i < optCount; i++) {\n\t\t\t/* 1== fontID for \"normal\"*/\n\t\t\tn = textWidth(1, optLabel[i]);\n\t\t\tif (n > maxLength) maxLength = n;\n\t\t}\n\t \tmaxLength = maxLength + 33;\n\t\tset(\"width\", maxLength);\n\n/*\t\ttagPtr = STG_tagPtr(\"SELECT\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tif (form == 0) form = send(parent(), \"findForm\");\n\t\tif (form == 0) {\n\t\t\tprint(\"HTML_select: can't find form. self=\",\n\t\t\t\tself(), \"\\n\");\n\t\t} else {\n\t\t\tsend(form, \"regInputer\", self());\n\t\t}\n\n\t\tif (checkedItem == 0) checkedItem = 1;\n\n\t\tset(\"label\", optLabel[checkedItem - 1]);\n\t\tvalue = optLabel[checkedItem - 1];\n\n\t\ttxt = \"\";\n\t\tfor (i = 0; i < optCount; i++) {\n\t\t\ttxt = concat(txt, \".{\", optLabel[i], \n\t\t\t\t\"} {send(self(), \\\"pick\\\", \", i, \");}\\n\");\n\t\t}\n\t\tset(\"menuConfig\", txt);\n\n\t\treturn get(\"height\");\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"y\", arg[1] + 2);\n\t\tset(\"width\", arg[2] - 10);\n\t\treturn height();\n\tbreak;\n\tcase 'r':\n\t\tset(\"width\", width() - 10);\n/*BUG.. somehow, right before this point, height is set to 1.\n\t\tprint(\"HTML_select: r height={\", get(\"height\"), \"}\\n\");\n*/\n\t\tset(\"height\", 20);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"VALUE\":\n\t\t\tdefaultVal = arg[2];\n\t\tbreak;\n\t\tcase \"ENVVAR\":\n\t\t\tdefaultVal = environVar(arg[2]);\n\t\t\t/* attrlist ordering might make a difference */\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"value\":\n\t\treturn concat(HTTPEncodeURL(tagID), '=', HTTPEncodeURL(value));\n\tbreak;\n\tcase \"reset\":\n\t\tset(\"label\", optLabel[checkedItem - 1]);\n\t\tvalue = optLabel[checkedItem - 1];\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_sub2[] = "\n/*\nprint(\"HTML_sub: self=\", self(), \": \");\nfor (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");\nprint(\"^^^^^^^end\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (findPattern(parent(), \"box\") != -1 ||\n\t\t    findPattern(parent(), \"math\") != -1) {\n\t\t\tSGMLBuildDoc_setBuff(0);\n\t\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\t\ttok[tokCount] = 2;\n\t\t\t\tdata[tokCount] = get(\"label\");\n\t\t\t\ttokCount++;\n\t\t\t}\n\t\t\ttest3();\n\t\t\tsend(parent(), \"flush\");\n\t\t\tsend(parent(), \"tok\", 9/*S_SUB*/);\n/*\n\t\t\tfor (i = 0; i < tokCount; i++) {\n\t\t\t\tprint(\"sub_tok \", i, \":   type=\", tok[i], \n\t\t\t\t\t\"  data={\", data[i], \"}\\n\");\n\t\t\t}\n*/\n\t\t\tfor (i = 0; i < tokCount; i++) {\n\t\t\t\tsend(parent(), \"tok&data\", tok[i], data[i]);\n\t\t\t}\n\t\t\tsend(parent(), \"tok\", 10/*E_SUB*/);\n\t\t\ttokCount = 0;\n\t\t\treturn \"\";\n\t\t} else {\n\t\t\tpn = str(parent());\n\t\t\ttt = compressSpaces(get(\"label\"));\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(1)\");\n\t\t}\n\tbreak;\n\tcase \"tok&data\":\n\t\t/* arg[1]\ttoken\n\t\t * arg[2]\tdata\n\t\t */\n\t\ttok[tokCount] = arg[1];\n\t\tdata[tokCount] = arg[2];\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\t/* arg[1]\tdata\n\t\t */\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = arg[1];\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"tok\":\n\t\t/* arg[1]\ttoken type\n\t\t */\n\t\ttok[tokCount] = arg[1];\n\t\tdata[tokCount] = \"\";\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"over\":\n\t\ttok[tokCount] = 4;\n\t\tdata[tokCount] = \"\";\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_sub[] = {
    {"class", _slotValue_HTML_sub0},
    {"name", _slotValue_HTML_sub1},
    {"script", _slotValue_HTML_sub2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_sup0[] = "field";
static char _slotValue_HTML_sup1[] = "HTML_sup";
static char _slotValue_HTML_sup2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (findPattern(parent(), \"box\") != -1 ||\n\t\t    findPattern(parent(), \"math\") != -1) {\n\t\t\tSGMLBuildDoc_setBuff(0);\n\t\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\t\ttok[tokCount] = 2;\n\t\t\t\tdata[tokCount] = get(\"label\");\n\t\t\t\ttokCount++;\n\t\t\t}\n\t\t\ttest3();\n\t\t\tsend(parent(), \"flush\");\n\t\t\tsend(parent(), \"tok\", 12/*S_SUP*/);\n/*\t\t\tfor (i = 0; i < tokCount; i++) {\n\t\t\t\tprint(\"sup_tok \", i, \":   type=\", tok[i], \n\t\t\t\t\t\"  data={\", data[i], \"}\\n\");\n\t\t\t}\n*/\n\t\t\tfor (i = 0; i < tokCount; i++) {\n\t\t\t\tsend(parent(), \"tok&data\", tok[i], data[i]);\n\t\t\t}\n\t\t\tsend(parent(), \"tok\", 13/*E_SUP*/);\n\t\t\ttokCount = 0;\n\t\t\treturn \"\";\n\t\t} else {\n\t\t\tpn = str(parent());\n\t\t\ttt = compressSpaces(get(\"label\"));\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(1)\");\n\t\t}\n\tbreak;\n\tcase \"tok&data\":\n\t\t/* arg[1]\ttoken\n\t\t * arg[2]\tdata\n\t\t */\n\t\ttok[tokCount] = arg[1];\n\t\tdata[tokCount] = arg[2];\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\t/* arg[1]\tdata\n\t\t */\n\t\ttok[tokCount] = 2;\n\t\tdata[tokCount] = arg[1];\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"tok\":\n\t\t/* arg[1]\ttoken type\n\t\t */\n\t\ttok[tokCount] = arg[1];\n\t\tdata[tokCount] = \"\";\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"over\":\n\t\ttok[tokCount] = 4;\n\t\tdata[tokCount] = \"\";\n\t\ttokCount++;\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_sup[] = {
    {"class", _slotValue_HTML_sup0},
    {"name", _slotValue_HTML_sup1},
    {"script", _slotValue_HTML_sup2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_table0[] = "field";
static char _slotValue_HTML_table1[] = "HTML_table";
static char _slotValue_HTML_table2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\treturn -1;\n\tbreak;\n\tcase \"D\":\n/*\t\ttagPtr = STG_tagPtr(\"TABLE\");\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t}\n*/\n\t\tif (title) {\n\t\t\tnew = send(\"HTML_tableCap\", \"clone\");\n\t\t\tobjectListAppend_children(new);\n\t\t\th = send(new, \"make\", self(), title,\n\t\t\t\t\tget(\"width\") - 2, titleAlign);\n\t\t\tSGMLTableFormater(new, titleAtTopP);\n\t\t} else {\n\t\t\tSGMLTableFormater();\n\t\t}\n\t\treturn get(\"height\");\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"TABLE\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tif (title) SGMLTableFormater(new, titleAtTopP);\n\t\telse SGMLTableFormater();\n\t\tvspan += set(\"height\", get(\"height\")) + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'b':\n\t\treturn border;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"TABLE\");\n\t\tvspan = style[0];\n\n\t\tif (title) SGMLTableFormater(new, titleAtTopP);\n\t\telse SGMLTableFormater();\n\n\t\tset(\"height\", vspan + get(\"height\") + style[1]);\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn 0;\n\tbreak;\n\tcase \"reportTitle\":\n\t\ttitle = arg[1];\n\t\ttitleAtTopP = arg[2];\n\t\ttitleAlign = arg[3];\n\t\treturn;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"BORDER\":\n\t\t\tborder = 1;\n\t\t\tset(\"border\", 6);\n\t\tbreak;\n\t\tcase \"COMPACT\":\n\t\t\tcompact = 1; \t/* NOT USED YET */\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + y();\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findForm\":\n\tcase \"findTop\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"BDColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_table[] = {
    {"class", _slotValue_HTML_table0},
    {"name", _slotValue_HTML_table1},
    {"script", _slotValue_HTML_table2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tableCap0[] = "txtLabel";
static char _slotValue_HTML_tableCap1[] = "HTML_tableCap";
static char _slotValue_HTML_tableCap2[] = "\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\tcellType = 32; /* TABLE_CELL_TYPE_TCAP == 32 */\n\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[3]);\n\t\tset(\"label\", arg[2]);\n\t\tset(\"paneConfig\", arg[4]);\n\t\tset(\"height\", 20);\n\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"expose\":\n\t\tusual();\n\t\tif (doneP == 0) {\n\t\t\trender();\n\t\t\tdoneP = 1;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\tusual();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"BDColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n";
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
static char _slotValue_HTML_tableVPane2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tconfig();\n\t\treturn -1;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tchildren list\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"children\", arg[2]);\n\t\tset(\"height\", arg[3]);\n\t\treturn 0;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(arg[1]);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_tableVPane[] = {
    {"class", _slotValue_HTML_tableVPane0},
    {"name", _slotValue_HTML_tableVPane1},
    {"script", _slotValue_HTML_tableVPane2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tb0[] = "field";
static char _slotValue_HTML_tb1[] = "HTML_tb";
static char _slotValue_HTML_tb2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tcellType = 4; /* TABLE_CELL_TYPE_TB == 4 */\n\t\tset(\"y\", -10);\t/* out of the way!!! */\n\t\treturn 1;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_tb[] = {
    {"class", _slotValue_HTML_tb0},
    {"name", _slotValue_HTML_tb1},
    {"script", _slotValue_HTML_tb2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tcap0[] = "field";
static char _slotValue_HTML_tcap1[] = "HTML_tcap";
static char _slotValue_HTML_tcap2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\ttext = get(\"label\");\n\t\tif (align == 0) align = \"center\";\n\t\tsend(parent(), \"reportTitle\", text, topP, align);\n\t\treturn -1;\n\tbreak;\n\tcase \"config\":\n\tcase \"R\":\n\t\treturn 0;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"TOP\":\n\t\t\ttopP = 1;\n\t\tbreak;\n\t\tcase \"ALIGN\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"left\":\n\t\t\t\talign = \"westToEast\";\n\t\t\tbreak;\n\t\t\tcase \"right\":\n\t\t\t\talign = \"eastToWest\";\n\t\t\tbreak;\n\t\t\tcase \"top\":\n\t\t\t\talign = \"northToSouth\";\n\t\t\tbreak;\n\t\t\tcase \"bottom\":\n\t\t\t\talign = \"southToNorth\";\n\t\t\tbreak;\n\t\t\tcase \"center\":\n\t\t\tdefault:\n\t\t\t\talign = \"center\";\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"AI\":\n\t\tswitch (arg[1]) {\n\t\tcase \"TOP\":\n\t\t\ttopP = 0;\n\t\tbreak;\n\t\tcase \"ALIGN\":\n\t\t\talign = \"center\";\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_tcap[] = {
    {"class", _slotValue_HTML_tcap0},
    {"name", _slotValue_HTML_tcap1},
    {"script", _slotValue_HTML_tcap2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_td0[] = "field";
static char _slotValue_HTML_td1[] = "HTML_td";
static char _slotValue_HTML_td2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\treturn;\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3],\n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\n\t\tcellType = 16; /* TABLE_CELL_TYPE_TD == 16 */\n\t\tif (send(parent(), 'b')) set(\"border\", 6);\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"TD\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"TD\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"COLSPAN\":\n\t\t\tcolSpan = arg[2];\n\t\tbreak;\n\t\tcase \"ROWSPAN\":\n\t\t\trowSpan = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) set(\"BDColor\", color);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_td[] = {
    {"class", _slotValue_HTML_td0},
    {"name", _slotValue_HTML_td1},
    {"script", _slotValue_HTML_td2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_textarea0[] = "HTML_textarea";
static char _slotValue_HTML_textarea1[] = "field";
static char _slotValue_HTML_textarea2[] = "\n/* must have no children obj since this obj is spec'ed as\n * an inlined object in the HTML_style.c.\n */\n/*\nprint(\">>> HTML_textarea: self=\", self(), \": \");\nfor (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");\nprint(\"...end\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase 'i':\n\t\tnew = send(\"HTML__textarea\", \"clone\");\n\t\tsend(new, \"make\", tagID, get(\"label\"), objWidth, objHeight);\n\t\tt = concat(\"\\\\o(\", new, \")\");\n\n\t\ttagID = \"\";\n\t\tobjWidth = 300;\n\t\tobjHeight = 100;\n\n\t\treturn t;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"SIZE\":\n\t\t\ti = findPattern(arg[2], ',');\n\t\t\tif (i == -1) {\n\t\t\t\tsize_cols = int(arg[2]);\n\t\t\t\t/* extra size to allow for scrollbar */\n\t\t\t\tobjWidth = size_cols * textWidth(0, \"n\") + 20;\n\t\t\t\tobjHeight = 100;\n\t\t\t} else {\n\t\t\t\tsize_cols = int(nthChar(arg[2], 0, i-1));\n\t\t\t\tobjWidth = size_cols * textWidth(0, 'n');\n\n\t\t\t\tdefaultRows = int(nthChar(arg[2], i+1, 99));\n\t\t\t\tobjHeight = defaultRows * 15;\n\n/*\t\t\t\tset(\"width\", objWidth);\n\t\t\t\tset(\"height\", defaultRows * 15);\n*/\n\t\t\t}\n/*\nprint(\"TEXTAREA SET: objWidth=\", objWidth, \"\\n\");\nprint(\"TEXTAREA SET: objHeight=\", objHeight, \"\\n\");\n*/\n\t\tbreak;\n\t\tcase \"COL\":\n\t\tcase \"COLS\":\n\t\t\tobjWidth = (int(arg[2]) * textWidth(0, \"n\")) + 20;\n/*print(\"TEXTAREA SET: objWidth=\", objWidth, \"\\n\");\n*/\n\t\tbreak;\n\t\tcase \"ROW\":\n\t\tcase \"ROWS\":\n/*print(\"TEXTAREA SET:----------\\n\");\n*/\n\t\t\tobjHeight = int(arg[2]) * 15; /*iffy*/\n/*\nprint(\"TEXTAREA SET: arg[2]=\", arg[2], \"\\n\");\nprint(\"TEXTAREA SET: objHeight=\", objHeight, \"\\n\");\n*/\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"y\", arg[1]);\n\t\tset(\"width\", arg[2] - 2);\n\t\tconfig();\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase 'r':/* BROKEN */\n\t\tset(\"width\", width() - 10);\n\t\tset(\"content\", get(\"content\"));\n\t\th = building_vspan();\n\t\tif (h < heightByRows) h = heightByRows;\n\t\tvspan += set(\"height\", h) + style[1];\n\t\trender();\n\t\treturn vspan + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\ttagID\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\nprint(\"TEXTAREA MAKE: arg width=\", arg[3], \"\\n\");\nprint(\"TEXTAREA MAKE: arg height=\", arg[4], \"\\n\");\n*/\n\t\ttagID = arg[1];\n\t\tdefaultVal = arg[2];\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\t\tconfig();\n\n\t\tsend(nthChild(0), \"make\", arg[2]);\n\n\t\tif (form == 0) form = send(parent(), \"findForm\");\n\t\tif (form == 0) {\n\t\t\tprint(\"HTML_select: can't find form. self=\",\n\t\t\t\tself(), \"\\n\");\n\t\t} else {\n\t\t\tsend(form, \"regInputer\", self());\n\t\t}\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"value\":\n\t\treturn concat(HTTPEncodeURL(tagID), \"=\",\n\t\t\t\tHTTPEncodeURL(send(nthChild(0), \"value\")));\n\tbreak;\n\tcase \"reset\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tobjWidth = 300;\n\t\tobjHeight = 150;\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_HTML_textarea4[] = "HTML__textarea";
static char _slotValue_HTML_textarea5[] = "HTML__textarea.tf HTML__textarea.sb";
static char _slotValue_HTML_textarea6[] = "hpane";
static char _slotValue_HTML_textarea7[] = "\n/*\nprint(\">>> HTML__textarea: self=\", self(), \": \");\nfor (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");\nprint(\"...end\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\theight\n\t\t */\n\t\tset(\"y\", arg[1]);\n\t\tset(\"width\", arg[2] - 2);\n\t\tconfig();\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase 'r':/* BROKEN */\n\t\tset(\"width\", width() - 10);\n\t\tset(\"content\", get(\"content\"));\n\t\th = building_vspan();\n\t\tif (h < heightByRows) h = heightByRows;\n\t\tvspan += set(\"height\", h) + style[1];\n\t\trender();\n\t\treturn vspan + 2;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\ttagID\n\t\t * arg[2]\tdefaultValue\n\t\t * arg[3]\twidth\n\t\t * arg[4]\theight\n\t\t */\n/*\t\tset(\"parent\", arg[1]);*/\n\n\t\ttagID = arg[1];\n\t\tdefaultVal = arg[2];\n\t\tset(\"width\", arg[3]);\n\t\tset(\"height\", arg[4]);\n\n\t\tconfig();\n\n\t\tsend(nthChild(0), \"make\", arg[2]);\n\n\t\tif (form == 0) form = send(parent(), \"findForm\");\n\t\tif (form == 0) {\n\t\t\tprint(\"HTML_select: can't find form. self=\",\n\t\t\t\tself(), \"\\n\");\n\t\t} else {\n\t\t\tsend(form, \"regInputer\", self());\n\t\t}\n\t\treturn get(\"height\") + 2;\n\tbreak;\n\tcase \"value\":\n\t\treturn concat(HTTPEncodeURL(tagID), \"=\",\n\t\t\t\tHTTPEncodeURL(send(nthChild(0), \"value\")));\n\tbreak;\n\tcase \"reset\":\n\t\treturn send(nthChild(0), arg[0]);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tobjWidth = 300;\n\t\tobjHeight = 150;\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_textarea8[] = "300";
static char _slotValue_HTML_textarea9[] = "150";
/* END OF OBJ */

static char _slotValue_HTML_textarea11[] = "txtEdit";
static char _slotValue_HTML_textarea12[] = "HTML__textarea";
static char _slotValue_HTML_textarea13[] = "HTML__textarea.tf";
static char _slotValue_HTML_textarea14[] = "HTML__textarea.sb";
static char _slotValue_HTML_textarea15[] = "\n/*\nprint(\">>>> HTML_textarea.tf: self=\", self(), \": \");\nfor (i=0; i<arg[]; i++) print(\"arg\", i, \" = \", arg[i], \"\\n\");print(\"...end\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"make\":\n\t\t/* arg[1]\tdefaultVal\n\t\t */\n\t\tdefaultVal = arg[1];\n\t\tif (defaultVal != 0) set(\"content\", defaultVal);\n\t\telse set(\"content\", \"\");\n\n\t\teventMask(\"+enterWindow +leaveWindow\");\n\t\treturn;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"TEXTAREA\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\th = building_vspan();\n\t\tif (h < heightByRows) h = heightByRows;\n\t\tvspan += set(\"height\", h) + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"value\":\n\t\treturn get(\"content\");\n\tbreak;\n\tcase \"reset\":\n\t\tset(\"content\", defaultVal);\n\t\tclearWindow();\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<TEXTAREA\");\n\t\tif (tagID) print(\" NAME=\\\"\", tagID, \"\\\"\");\n\t\tif (type) print(\" TYPE=\\\"\", inputType, \"\\\"\");\n\t\tif (checked) print(\" CHECKED\");\n\t\tif (get(\"maxWidth\") < 9999) \n\t\t\tprint(\" MAXWIDTH=\", get(\"maxWidth\"));\n\t\tif (get(\"minWidth\") < 9999) \n\t\t\tprint(\" MINWIDTH=\", get(\"minWidth\"));\n\t\tprint(\">\", get(\"content\"), \"<TEXTAREA>\\n\");\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_th2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\treturn;\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n/*\t\tSGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor, \n\t\t\t\tpaneConfig);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3],\n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor, \n\t\t\t\tpaneConfig);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\n\t\tcellType = 8; /* TABLE_CELL_TYPE_TH == 8 */\n\t\tif (send(parent(), 'b')) set(\"border\", 6);\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"TH\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"TH\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"ALIGN\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"center\":\n\t\t\t\tpaneConfig = \"center\";\n\t\t\tbreak;\n\t\t\tcase \"left\":\n\t\t\t\tpaneConfig = \"westToEast\";\n\t\t\tbreak;\n\t\t\tcase \"right\":\n\t\t\t\tpaneConfig = \"eastToWest\";\n\t\t\tbreak;\n\t\t\tcase \"top\":\n\t\t\t\tpaneConfig = \"northToSouth\";\n\t\t\tbreak;\n\t\t\tcase \"bottom\":\n\t\t\t\tpaneConfig = \"southToNorth\";\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\tcase \"COLSPAN\":\n\t\t\tcolSpan = arg[2];\n\t\tbreak;\n\t\tcase \"ROWSPAN\":\n\t\t\trowSpan = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"findForm\":\n\t\treturn send(parent(), \"findForm\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tcolor = getResource(\"Viola.background_doc\");\n\t\tif (color) set(\"BGColor\", color);\n\t\tcolor = getResource(\"Viola.foreground_doc\");\n\t\tif (color) {\n\t\t\tset(\"FGColor\", color);\n\t\t\tset(\"BDColor\", color);\n\t\t}\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_th[] = {
    {"class", _slotValue_HTML_th0},
    {"name", _slotValue_HTML_th1},
    {"script", _slotValue_HTML_th2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_title0[] = "field";
static char _slotValue_HTML_title1[] = "HTML_title";
static char _slotValue_HTML_title2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\ttext = get(\"label\");\n\t\tsend(send(parent(), \"findTop\"), \"reportTitle\", text);\n\t\treturn -1;\n\tbreak;\n\tcase 'R':\n\t\treturn 1;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_title[] = {
    {"class", _slotValue_HTML_title0},
    {"name", _slotValue_HTML_title1},
    {"script", _slotValue_HTML_title2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tr0[] = "field";
static char _slotValue_HTML_tr1[] = "HTML_tr";
static char _slotValue_HTML_tr2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tcellType = 2; /* TABLE_CELL_TYPE_TR == 2 */\n\t\tset(\"y\", -10);\t/* out of the way!!! */\n\t\treturn 1;\n\tbreak;\n\tcase \"R\":\n\tcase \"r\":\n\t\treturn 1;\n\tbreak;\n\tcase \"config\":\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_tr[] = {
    {"class", _slotValue_HTML_tr0},
    {"name", _slotValue_HTML_tr1},
    {"script", _slotValue_HTML_tr2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txt0[] = "txtDisp";
static char _slotValue_HTML_txt1[] = "HTML_txt";
static char _slotValue_HTML_txt2[] = "\n/*\nprint(\"HTML_txt: self=\", self(), \"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\\n\");\nfor(i=0;i<arg[];i++) print(\"arg[\",i,\"]={\",arg[i],\"}\\n\");\nprint(\"HTML_txt: editMode=\", editMode, \"\\n\");\nprint(\"HTML_txt: lock=\", lock, \"\\n\");\n*/\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\t\treturn expose();\n\tbreak;\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn 0;\n\tbreak;\n\tcase \"fitIn?\":\n\t\t/* arg[1]\tx\n\t\t * arg[2]\ty\n\t\t */\n\t\tx = arg[1];\n\t\ty = arg[2];\n\tbreak;\n\tcase \"runAwayFromHome\":\n\t\treturn send(parent(), \"deleteChild\", self());\n\tbreak;\n\tcase \"buttonPress\":\n\t\tif (editMode) {\n\t\t  mxy = mouseLocal();\n\t\t  if (mxy[0] < 10) {\n\t\t\tprint(\"HTML_txt: GRAB\\n\");\n\t\t\tmy = mxy[1];\n\t\t\tif (my < (height() / 2)) side = 0;\n\t\t\telse side = 1;\n\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\tsend(top, \"wedgeMeIn\", self(), side);\n\t\t\treturn;\n\t\t  } else {\n\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\tplid = send(parent(), \"placeID\", self(), \"\");\n\t\t\tsend(top, \"lock\", self(), plid);\n\t\t\tif (lock == 1) {\n\t\t\t\t/* unlock */\n\t\t\t\tset(\"BGColor\", bgcolor);\n\t\t\t\trender();\n\t\t\t\tset(\"cursor\", 0);\n\t\t\t\tlock = 0;\n\t\t\t\treturn;\n\t\t\t} else {\n\t\t\t\t/* lock */\n\t\t\t\tbgcolor = get(\"BGColor\");\n\t\t\t\tset(\"BGColor\", \"yellow\");\n\t\t\t\trender();\n\t\t\t\tset(\"cursor\", 1);\n\t\t\t\tlock = 1;\n\t\t\t}\n\t\t  }\n\t\t}\n\tbreak;\n\tcase \"edit_focus\":\n\t\twxy = windowPosition();\n\t\tsetMouse(wxy[0] + 2, wxy[1] + 2);\n\t\treturn;\n\tbreak;\n\tcase \"keyPress\":\n\t\tif (editMode) {\n\t\t\tc = key();\n\t\t\tif (c == '\\r') {\n\t\t\t\tinsert(key());\n\t\t\t\tset(\"content\", get(\"content\"));\n\t\t\t\th = building_vspan();\n\t\t\t\tprint(\"BUILDING_VSPAN=\", h, \"\\n\");\n\t\t\t\tset(\"height\", h);\n\t\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\t\tsend(top, \"resizeSelf\");\n\t\t\t\tplid = send(parent(), \"placeID\", self(), \"\");\n\n\t\t\t\tnewTxt = get(\"content\");\n\t\t\t\tset(\"content\", newTxt);\n\n\t\t\t\tsend(top, \"change\", self(), plid, newTxt);\n\t\t\t} else if (c == '\\t') {\n\t\t\t\tif (shiftKeyP()) {\n\t\t\t\t\tsend(parent(), \"edit_gotoPrev\", \n\t\t\t\t\t\tself());\n\t\t\t\t} else {\n\t\t\t\t\tsend(parent(), \"edit_gotoNext\", \n\t\t\t\t\t\tself());\n\t\t\t\t}\n\t\t\t\t/*\n\t\t\t\tsend(parent(),\n\t\t\t\t\teither (shiftKeyP())\n\t\t\t\t\t\t{\"edit_gotoPrev\"}\n\t\t\t\t\t\t{\"edit_gotoNext\"},\n\t\t\t\t\tself());\n\t\t\t\t*/\n\t\t\t} else {\n\t\t\t\tinsert(key());\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"CE_change\":\n\t\tnewData = arg[2];\n\t\tset(\"content\", newData);\n\t\th = building_vspan();\n\t\tprint(\"RE_BUILDING_VSPAN=\", h, \"\\n\");\n\t\tset(\"height\", h);\n\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\tsend(top, \"resizeSelf\");\n\t\treturn;\n\tbreak;\n\tcase \"CE_lock\":\n\t\tif (lock == 0) {\n\t\t\tset(\"BGColor\", \"red\");\n\t\t\trender();\n\t\t}\n\t\treturn;\t\t\n\tbreak;\n\tcase \"CE_unlock\":\n\t\tif (lock == 0) {\n\t\t\tset(\"BGColor\", bgcolor);\n\t\t\trender();\n\t\t}\n\t\treturn;\t\t\n\tbreak;\n\tcase \"enter\":\n\t\tif (editMode && lock) {\n\t\t\tset(\"cursor\", 1);\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tif (editMode && lock) {\n\t\t\tset(\"cursor\", 0);\n/*\n\t\t\tset(\"BDColor\", get(\"BGColor\"));\n\t\t\tset(\"cursor\", 0);\n\t\t\tif (lock == 1) {\n\t\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\t\tplid = send(parent(), \"placeID\", self(), \"\");\n\t\t\t\tsend(top, \"unlock\", self(), plid);\n\t\t\t\tlock = 0;\n\t\t\t}\n*/\n\t\t} else {\n\t\t\tprevHint = 0;\n\t\t\twww.mesg.tf(\"clear\");\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"D\": /* done */\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(parent(), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\tSGMLBuildDoc_setBuff(0);/* necessary ...*/\n\n\t\tif (isBlank(get(\"label\"))) {\n\t\t\t/*XXXXX there is something... \\o's..\n\t\t\t *\tQuestion: how to determine height?\n\t\t\t */\n\t\t\tif (nthChild(0)) return 20;\n\n\t\t\t/* no text in this para object. But, there might\n\t\t\t * be an inlined object containing other objects...\n\t\t\t * Ie: <P><A><H2>Hozer markup</H2></A>\n\t\t\t */\n/*\n\t\t\tvspan = 0;\n\t\t\tif (nthChild(0)) {\nprint(\"TXT: has child!:\", nthChild(0), \"\\n\");\n\t\t\t\tn = countChildren();\nprint(\"TXT: n=\", n, \"\\n\");\n\t\t\t\txx = get(\"width\");\n\t\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\t  vspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t\t\t}\nprint(\"TXT: vspan=\", vspan, \"................................\\n\");\n\t\t\t\tset(\"height\", vspan+10);\n\nprint(\"TXT: height=\", get(\"height\"), \"................................\\n\");\n\t\t\t\treturn (vspan + 10);\n\t\t\t}\n\t\t\treturn 0;\n*/\n\t\t}\n\n\t\tsend(self(), \"setStyles\", parent());\n\n\t\tif (deco) {\n\t\t\tbox = send(deco, \"clone\");\n\t\t\tobjectListAppend_children(box);\n\t\t\tif (inPreP) \n\t\t\t  h = send(box, \"make\", self(), \n\t\t\t\t   get(\"label\"), get(\"width\"));\n\t\t\telse \n\t\t\t  h = send(box, \"make\", self(), \n\t\t\t\t   trimEdgeQ(get(\"label\")), get(\"width\"));\n\t\t\treturn h + 2;\n\t\t\t/* +2 for hot-link-indicator border around IMGs */\n\t\t} else {\n\t\t\tif (inPreP) {\n\t\t\t\tset(\"format\", 0);\n\t\t\t\tset(\"font\", \"fixed\");\n\t\t\t\tset(\"_font\", 0);\n\t\t\t\tset(\"content\", get(\"label\"));\n\t\t\t} else {\n\t\t\t\tset(\"content\", trimEdgeQ(get(\"label\")));\n\t\t\t}\n\t\t\tset(\"label\", \"\");\n\t\t\tisHTML = 1;\n\t\t\treturn building_vspan()+2;\n\t\t\t/* +2 for hot-link-indicator border around IMGs */\n\t\t}\n\tbreak;\n\tcase \"F\": /* flush */\n\t\treturn 1;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tw = arg[2] - get(\"x\") - style[3];\n\t\tset(\"width\", w);\n\t\tif (deco) {\n\t\t\th = send(nthChild(0), \"R\", w);\n\t\t\tset(\"height\", h);\n\t\t\treturn h + style[1];\n\t\t} else {\n\t\t\t/* check to see if this Para object has children\n\t\t\t * objects. This can happen, ie, with this markup\n\t\t\t * <P><A><H2>foo</H2>\n\t\t\t */\n/*\t\t\tif (nthChild(0)) {\n\t\t\t\tn = countChildren();\n\t\t\t\txx = get(\"width\");\n\t\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\t  vspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t\t\tset(\"height\", vspan+1);\n\t\t\t\treturn vspan+1;\n\t\t\t} \n*/\n/*print(\"HTML_txt R: label={\",get(\"content\"), \"}\\n\");*/\n\t\t\t\tset(\"content\", get(\"content\"));\n\t\t\t\tclearWindow();\n\t\t\t\tvspan += set(\"height\", building_vspan()+2)\n\t\t\t\t\t + style[1];\n\t\t\t\t/* +2 for hot-link-indicator border around IMGs */\n\t\t\t\trender();\n\t\t\t\treturn vspan;\n\t\t}\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\tvspan = style[0];\n\t\tset(\"width\", get(\"width\") - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tclearWindow();\n\t\trender();\n\t\tvspan += set(\"height\", building_vspan()) + style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagIDs[tagIDCount] = arg[2];\n\t\t\ttagIDCount++;\n\t\tbreak;\n\t\tcase \"STYLE\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"NOTE\":\n\t\t\t\tdeco = \"HTML__txtBox_note\";\n\t\t\tbreak;\n\t\t\tcase \"CAUTION\":\n\t\t\t\tdeco = \"HTML__txtBox_caution\";\n\t\t\tbreak;\n\t\t\tcase \"WARNING\":\n\t\t\t\tset(\"BDColor\", \"darkOrange\");\n\t\t\t\tdeco = \"HTML__txtBox_caution\";\n\t\t\tbreak;\n\t\t\tcase \"ERROR\":\n\t\t\t\tset(\"BDColor\", \"red\");\n\t\t\t\tdeco = \"HTML__txtBox_error\";\n\t\t\tbreak;\n\t\t\tcase \"TIMED\": /*just for fun*/\n\t\t\t\tdeco = \"HTML__txtBox_time\";\n\t\t\tbreak;\n\t\t\tcase \"QUOTE\":\n\t\t\tcase \"MARGIN\":\n\t\t\tcase \"NORMAL\":\n\t\t\tdefault:\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\tcase \"ALIGN\":\n\t\t\tswitch (arg[2]) {\n\t\t\tcase \"center\":\n\t\t\t\tset(\"paneConfig\", \"center\");\n\t\t\tbreak;\n\t\t\tcase \"left\":\n\t\t\t\tset(\"paneConfig\", \"westToEast\");\n\t\t\tbreak;\n\t\t\tcase \"right\":\n\t\t\t\tset(\"paneConfig\", \"eastToWest\");\n\t\t\tbreak;\n\t\t\t}\n\t\tbreak;\n\t\tcase \"COMPACT\":\n\t\t\tcompact = 1; \t/* NOT USED YET */\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"make\":\n\t\tsend(self(), \"setStyles\", arg[1]);\n\n\t\ttagIDs[tagIDCount] = arg[6];\n\t\ttagIDCount++;\n\n\t\tif (useTagInfo_align)\n\t\t\tif (arg[] > 7) set(\"paneConfig\", arg[7]);\n\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\tcase \"setStyles\":\n\t\tuseTagInfo_align = 1;\n\n\t\tif (findPattern(arg[1], \"address\") != -1) {\n\t\t\t/*tagPtr = send(arg[1], \"styleSheet\");*/\n\t\t\ttagPtr = STG_tagPtr(\"P\", \"ADDRESS\");\n\t\t} else {\n\t\t\ttagPtr = STG_tagPtr(\"P\");\n\t\t}\n\t\tif (tagPtr) {\n\t\t\ti = STG_attr(tagPtr, \"BGColor\");\n\t\t\tif (i) set(\"BGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"FGColor\");\n\t\t\tif (i) set(\"FGColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"BDColor\");\n\t\t\tif (i) set(\"BDColor\", i);\n\t\t\ti = STG_attr(tagPtr, \"fontSlant\");\n\t\t\tif (i) {\n\t\t\t\tswitch (i) {\n\t\t\t\tcase \"italic\": \tset(\"font\", i);\tbreak;\n\t\t\t\tcase \"bold\": \tset(\"font\", i);\tbreak;\n\t\t\t\tdefault:\n\t\t\t\tcase \"normal\":\tset(\"font\", i);\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\ti = STG_attr(tagPtr, \"align\");\n\t\t\tif (i) {\n\t\t\t\tuseTagInfo_align = 0;\n\t\t\t\tswitch (i) {\n\t\t\t\tcase \"center\":\n\t\t\t\t\tset(\"paneConfig\", \"center\");\n\t\t\t\tbreak;\n\t\t\t\tcase \"left\":\n\t\t\t\t\tset(\"paneConfig\", \"westToEast\");\n\t\t\t\tbreak;\n\t\t\t\tcase \"right\":\n\t\t\t\t\tset(\"paneConfig\", \"eastToWest\");\n\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\ti = STG_attr(tagPtr, \"blink\");\n\t\t\tif (i) {\n\t\t\t\tblinkRate = i;\n\t\t\t\tfgc = get(\"FGColor\");\n\t\t\t\tbclr0 = STG_attr(tagPtr, \"blinkColorOn\");\n\t\t\t\tbclr1 = STG_attr(tagPtr, \"blinkColorOff\");\n\t\t\t\tafter(i, self(), \"blink\");\n\t\t\t}\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"blink\":\n\t\tif (blinkOn) {\n\t\t\tblinkOn = 0;\n\t\t\tset(\"FGColor\", bclr1);\n\t\t} else {\n\t\t\tset(\"FGColor\", bclr0);\n\t\t\tblinkOn = 1;\n\t\t}\n\t\trender();\n\t\tafter(blinkRate, self(), \"blink\");\n\t\treturn;\n\tbreak;\n\tcase \"itemN\":\n\t\t/*??? it happens. Just here to quiet it*/\n\t\treturn;\n\tbreak;\n\tcase \"setAnchor\":\n\t\ttagIDs[tagIDCount] = arg[1];\n\t\ttagIDCount++;\n/*\t\tfor (i = 0; i < tagIDCount; i++)\n\t\t\tprint(\"######\", tagIDs[i], \"\\n\");\n*/\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagIDCount > 0)\n\t\t\tfor (i = 0; i < tagIDCount; i++)\n\t\t\t\tif (tagIDs[i] == arg[1]) return get(\"y\");\n\t\treturn 0;\n\tbreak;\n\tcase \"editMode\":\n\t\teditMode = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"config\":\n\t\t/* let 'R' do the resizing */\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<P>\", get(\"content\"), \"\\n\");\n/*\n\t\tn = anchor....\n\t\tif (n) {\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tsend(nthChild(i), \"outputSGML\");\n\t\t}\n*/\n\t\tprint(\"</P>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\treturn code_HTML_txt(arg);\n";
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
static char _slotValue_HTML_txtAnchor2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (tagID) {\n\t\t\tsend(parent(), \"setAnchor\", tagID);\n\t\t\ttagID = 0;\n\t\t}\n\t\tif (nthChild(0)) {\n\t\t\treturn concat(\"\\\\o(\", self(), \")\");\n\t\t} else {\n\t\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\t\telse tt = compressSpaces(get(\"label\"));\n\n\t\t\tif (url) {\n\t\t\t\tt = concat(\"\\\\b(\", tt,\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t\t\turl = 0;\n\t\t\t\treturn t;\n\t\t\t} else {\n\t\t\t\treturn tt;\n\t\t\t}\n\t\t}\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"HREF\":\n\t\t\turl = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = send(\"HTML_txt\", \"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\n\t\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\t\telse tt = compressSpaces(get(\"label\"));\n\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\ttt, style_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\tset(\"content2\", self());/*a kludge to deal with cloning*/\n\t\th = get(\"height\");\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = send(\"HTML_txt\", \"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\n\t\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\t\telse tt = compressSpaces(get(\"label\"));\n\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\ttt, style_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tvspan = 1;\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t  vspan += send(nthChild(i), \"R\", vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\treturn vspan;\n\tbreak;\n\tcase \"copyObj\":\n\t\turl = send(arg[1], \"url\");\n\t\treturn 0;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"inAnchor\":\n/* trouble is, once txtAnchor is copied, 'url' and other info in variables\nare lost. Solution send message to this object to have itself copied\n(including the appropriate variables).\n*/\n\t\treturn url;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"url\":\n\t\t/* for <img ismap...> to ask */\n\t\treturn url;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtAnchor[] = {
    {"class", _slotValue_HTML_txtAnchor0},
    {"name", _slotValue_HTML_txtAnchor1},
    {"script", _slotValue_HTML_txtAnchor2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtBold0[] = "field";
static char _slotValue_HTML_txtBold1[] = "HTML_txtBold";
static char _slotValue_HTML_txtBold2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\t/*XXX this is so so sincerely cheezy */\n\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\telse tt = compressSpaces(get(\"label\"));\n\n\t\tpn = str(parent());\n\t\tif (findPattern(pn, \"pre\") != -1) {\n\t\t\treturn concat(\"\\\\f(4)\", tt, \"\\\\f(0)\");\n\t\t} else if (findPattern(pn, \"example\") != -1) {\n\t\t\treturn concat(\"\\\\f(4)\", tt, \"\\\\f(0)\");\n\t\t} else if (findPattern(pn, \"header_medium\") != -1) {\n\t\t\treturn concat(\"\\\\f(5)\", tt, \"\\\\f(2)\");\n\t\t} else {\n\t\t\treturn concat(\"\\\\f(4)\", tt, \"\\\\f(1)\");\n\t\t}\n\tbreak;\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase \"inPreP\":\n\t\treturn send(get(\"parent\"), \"inPreP\");\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtBold[] = {
    {"class", _slotValue_HTML_txtBold0},
    {"name", _slotValue_HTML_txtBold1},
    {"script", _slotValue_HTML_txtBold2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtBullet0[] = "field";
static char _slotValue_HTML_txtBullet1[] = "HTML_txtBullet";
static char _slotValue_HTML_txtBullet2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn 0;\n\tbreak;\n\tcase 'i':\n\t\treturn concat(\"\\\\f(0)*\\\\f(1)\", compressSpaces(get(\"label\")));\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtBullet[] = {
    {"class", _slotValue_HTML_txtBullet0},
    {"name", _slotValue_HTML_txtBullet1},
    {"script", _slotValue_HTML_txtBullet2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtCommand0[] = "field";
static char _slotValue_HTML_txtCommand1[] = "HTML_txtCommand";
static char _slotValue_HTML_txtCommand2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\telse tt = compressSpaces(get(\"label\"));\n\t\treturn concat(\"\\\\f(0)\", tt, \"\\\\f(1)\");\n\tbreak;\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtCommand[] = {
    {"class", _slotValue_HTML_txtCommand0},
    {"name", _slotValue_HTML_txtCommand1},
    {"script", _slotValue_HTML_txtCommand2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtDD0[] = "field";
static char _slotValue_HTML_txtDD1[] = "HTML_txtDD";
static char _slotValue_HTML_txtDD2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\tif (url = send(parent(), \"inAnchor\"))\n\t\t\t\ttxt = concat(\"\\\\b(\", \n\t\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t\telse\n\t\t\t\ttxt = compressSpaces(get(\"label\"));\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\ttxt, style_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\tif (url = send(parent(), \"inAnchor\"))\n\t\t\t\ttxt = concat(\"\\\\b(\", \n\t\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t\telse\n\t\t\t\ttxt = compressSpaces(get(\"label\"));\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\ttxt, style_p[3],\n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"DD\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"setAnchor\":\n\t\tmakeAnchor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return get(\"y\");\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtDD[] = {
    {"class", _slotValue_HTML_txtDD0},
    {"name", _slotValue_HTML_txtDD1},
    {"script", _slotValue_HTML_txtDD2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtDT0[] = "field";
static char _slotValue_HTML_txtDT1[] = "HTML_txtDT";
static char _slotValue_HTML_txtDT2[] = "\n\tswitch (arg[0]) {\n\tcase \"F\":\n\t\th = 0;\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\tif (url = send(parent(), \"inAnchor\"))\n\t\t\t\ttxt = concat(\"\\\\b(\", \n\t\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t\telse\n\t\t\t\ttxt = compressSpaces(get(\"label\"));\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\ttxt, style_p[3],\n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\tif (url = send(parent(), \"inAnchor\"))\n\t\t\t\ttxt = concat(\"\\\\b(\", \n\t\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t\telse\n\t\t\t\ttxt = compressSpaces(get(\"label\"));\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\ttxt, style_p[3],\n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"DT\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - get(\"x\") - style[3]);\n\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"SECTION\");\n\t\tvspan = style[0];\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t\tvspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"heightP\":\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"widthP\":\n\t\treturn get(\"width\");\n\tbreak;\n\tcase \"AI\":\n\tcase \"noBullet\":\n\t\treturn;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"ID\":\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"data\":\n\t\tSGMLBuildDoc_setBuff(-1);\n\t\treturn compressSpaces(get(\"label\"));\n\tbreak;\n\tcase \"setAnchor\":\n\t\tmakeAnchor = arg[1];\n\t\treturn;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tif (tagID == arg[1]) return self();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\tif (tagID == arg[1]) return y();\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\toffset = send(nthChild(i), \n\t\t\t\t\t\t\"gotoAnchor\", arg[1]);\n\t\t\t\tif (offset > 0) return offset + get(\"y\");\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtDT[] = {
    {"class", _slotValue_HTML_txtDT0},
    {"name", _slotValue_HTML_txtDT1},
    {"script", _slotValue_HTML_txtDT2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtEmphasis0[] = "field";
static char _slotValue_HTML_txtEmphasis1[] = "HTML_txtEmphasis";
static char _slotValue_HTML_txtEmphasis2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\t/*XXX this is so so cheezy-- stop gap solution */\n\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\telse tt = compressSpaces(get(\"label\"));\n\t\tpn = str(parent());\n\t\tif (findPattern(pn, \"pre\") != -1) {\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(0)\");\n\t\t} else if (findPattern(pn, \"example\") != -1) {\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(0)\");\n\t\t} else if (findPattern(pn, \"header_big\") != -1) {\n\t\t\treturn concat(\"\\\\f(9)\", tt, \"\\\\f(6)\");\n\t\t} else if (findPattern(pn, \"header_medium\") != -1) {\n\t\t\treturn concat(\"\\\\f(8)\", tt, \"\\\\f(5)\");\n\t\t} else if (findPattern(pn, \"header_small\") != -1) {\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(4)\");\n\t\t} else {\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(1)\");\n\t\t}\n\tbreak;\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"AA\":\n\t\t/* need to handle arg[1]=TT arg[2]=tt, \n\t\t * arg[1]=B arg[2]=b\n\t\t */\n\t\treturn;\n\tbreak;\n\tcase \"R\":\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtEmphasis[] = {
    {"class", _slotValue_HTML_txtEmphasis0},
    {"name", _slotValue_HTML_txtEmphasis1},
    {"script", _slotValue_HTML_txtEmphasis2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtItalic0[] = "field";
static char _slotValue_HTML_txtItalic1[] = "HTML_txtItalic";
static char _slotValue_HTML_txtItalic2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\t/*XXX this is so so cheezy-- stop gap solution */\n\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\telse tt = compressSpaces(get(\"label\"));\n\n\t\tpn = str(parent());\n\t\tif (findPattern(pn, \"pre\") != -1) {\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(0)\");\n\t\t} else if (findPattern(pn, \"example\") != -1) {\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(0)\");\n\t\t} else if (findPattern(pn, \"header_big\") != -1) {\n\t\t\treturn concat(\"\\\\f(9)\", tt, \"\\\\f(6)\");\n\t\t} else if (findPattern(pn, \"header_medium\") != -1) {\n\t\t\treturn concat(\"\\\\f(8)\", tt, \"\\\\f(5)\");\n\t\t} else if (findPattern(pn, \"header_small\") != -1) {\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(4)\");\n\t\t} else {\n\t\t\treturn concat(\"\\\\f(7)\", tt, \"\\\\f(1)\");\n\t\t}\n\tbreak;\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase \"inPreP\":\n\t\tif (doneSetInPreP == 0) {\n\t\t\tinPreP = send(get(\"parent\"), \"inPreP\");\n\t\t\tdoneSetInPreP = 1;\n\t\t}\n\t\treturn inPreP;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"configSelf\":\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtItalic[] = {
    {"class", _slotValue_HTML_txtItalic0},
    {"name", _slotValue_HTML_txtItalic1},
    {"script", _slotValue_HTML_txtItalic2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtList0[] = "XBM";
static char _slotValue_HTML_txtList1[] = "HTML_txtList";
static char _slotValue_HTML_txtList2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tlistItemObj = HTML_txtListItem(\"clone\", self());\n\t\th = send(listItemObj, \"make\", self(), 20, get(\"width\") - 20);\n\t\tset(\"children\", listItemObj);\n\t\treturn h;\n\tbreak;\n\tcase \"searchAnchor\":\n\t\tn = countChildren();\n\t\tif (n > 0) {\n\t\t\tfor (i = 0; i < n; i++) {\n\t\t\t\tanchor = send(nthChild(i), \n\t\t\t\t\t\t\"searchAnchor\", arg[1]);\n\t\t\t\tif (anchor != \"\") return anchor;\n\t\t\t}\n\t\t}\n\t\treturn \"\";\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn code_HTML_txt(arg);\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_HTML_txtList3[] = "#define ol_width 16\n#define ol_height 16\nstatic char ol_bits[] = {\n   0x00, 0x00, 0x00, 0x74, 0x00, 0x7a, 0x00, 0x3d, 0x80, 0x1e, 0x00, 0x0f,\n   0xe0, 0x06, 0xf0, 0x01, 0xb0, 0x01, 0xd8, 0x01, 0xe8, 0x00, 0x3c, 0x00,\n   0x0c, 0x04, 0x02, 0x03, 0xf8, 0x00, 0x00, 0x00};\n";
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
static char _slotValue_HTML_txtListItem2[] = "\n\tswitch (arg[0]) {\n\tcase \"mouseMove\":\n\t\thint = processMouseMove();\n\t\tif (prevHint != hint) {\n\t\t\tif (isBlank(hint)) www.mesg.tf(\"clear\");\n\t\t\telse www.mesg.tf(\"show\", hint);\n\t\t}\n\t\tprevHint = hint;\n\t\treturn;\n\tbreak;\n\tcase \"leave\":\n\t\tprevHint = 0;\n\t\twww.mesg.tf(\"clear\");\n\t\treturn;\n\tbreak;\n\tcase \"D\":\n\t\tset(\"width\", send(parent(), \"wP\"));\n\t\tinPreP = send(parent, \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\tset(\"content\", text);\n\t\th = building_vspan() + 3;\n\t\tset(\"height\", h);\n\t\tset(\"maxHeight\", h);\n\t\th += 6; /* allow for gapH/V & border*/\n\t\treturn h;\n\tbreak;\n\tcase \"R\": /* resize */\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t * arg[3]\tx (optional)\n\t\t */\n\t\tclearWindow();\n\t\tset(\"y\", arg[1]);\n\t\tset(\"width\", arg[2]);\n\t\tset(\"content\", get(\"content\"));\n\t\th = set(\"height\", building_vspan() + 4);\n\t\trender();\n\t\treturn h;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tdata\n\t\t * arg[3]\tx\n\t\t * arg[4]\twidth\n\t\t * arg[5]\tlistType\n\t\t */\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"x\", arg[3]);\n\t\tset(\"width\", arg[4]);\n\t\tinPreP = send(arg[1], \"inPreP\");\n\t\tif (inPreP) set(\"format\", 0);\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\tset(\"content\", arg[2]);\n\t\th = building_vspan() + 4;\n\t\tset(\"height\", h);\n\t\tset(\"maxHeight\", h);\n\t\tif (arg[5] == 'D') set(\"BGColor\", \"LemonChiffon2\");\n\t\th += 4;\n\t\teventMask(\"+pointerMotion +leaveWindow\");\n\t\treturn h;\n\tbreak;\n\tcase 'i':\n\t\tif (text) text = concat(text, get(\"label\"));\n\t\telse text = get(\"label\");\n\t\treturn;\n\tbreak;\n\tcase 'A':\n\t\t/* arg[1]\tobject to absorb\n\t\t */\n\t\tif (text) text = concat(text, send(arg[1], 'i'));\n\t\telse text = send(arg[1], 'i');\n\t\treturn 0;\n\tbreak;\n\tcase 'P':\n\t\tset(\"parent\", arg[1]);\n\t\treturn h;\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tusual();\n\t\tif (charButtonMask() > 0) {\n\t\t\tref = HTTPDecodeURL(nextTag());\n\t\t\tif (ref) {\n\t\t\t\tif (shiftKeyP()) {\n\t\t\t\t\twww.mesg.tf(\"show\",\n\t\t\t\t\t\tconcat(\"Dest: \", ref));\n\t\t\t\t} else {\n\t\t\t\t\tsetRevVideoFlag(1);\n\t\t\t\t\tsend(send(parent(), \"findTop\"), \n\t\t\t\t\t\t\"follow_href\", ref);\n\t\t\t\t\tsetRevVideoFlag(0);\n\t\t\t\t}\n\t\t\t}\n\t\t} else {\n\t\t\t/* lets user complete cut/paste */\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"findTop\":\n\tcase \"findForm\":\n\t\treturn send(parent(), arg[0]);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_txtProtrude2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\telse tt = compressSpaces(get(\"label\"));\n\t\treturn concat(\"\\\\f(3)\", tt, \"\\\\f(1)\");\n\tbreak;\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtProtrude[] = {
    {"class", _slotValue_HTML_txtProtrude0},
    {"name", _slotValue_HTML_txtProtrude1},
    {"script", _slotValue_HTML_txtProtrude2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtUnderline0[] = "field";
static char _slotValue_HTML_txtUnderline1[] = "HTML_txtUnderline";
static char _slotValue_HTML_txtUnderline2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (send(get(\"parent\"), \"inPreP\")) tt = get(\"label\");\n\t\telse tt = compressSpaces(get(\"label\"));\n\t\treturn tt;\n\t\t/*(\"\\\\u(\", tt, \")\") underline no longer supported in tfed*/\n\tbreak;\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_txtUnderline[] = {
    {"class", _slotValue_HTML_txtUnderline0},
    {"name", _slotValue_HTML_txtUnderline1},
    {"script", _slotValue_HTML_txtUnderline2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vinsert0[] = "field";
static char _slotValue_HTML_vinsert1[] = "HTML_vinsert";
static char _slotValue_HTML_vinsert2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn 0;\n\tbreak;\n\tcase 'i':\n\t\tprint(\"WARNING: INTERPRETING SCRIPT >>\", get(\"label\"), \"<<\\n\");\n\t\tss = interpret(get(\"label\"));\n\t\tprint(\"INTERPRETION RESULT >>\", ss, \"<<\\n\");\n\t\treturn ss;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_vinsert[] = {
    {"class", _slotValue_HTML_vinsert0},
    {"name", _slotValue_HTML_vinsert1},
    {"script", _slotValue_HTML_vinsert2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vobj0[] = "field";
static char _slotValue_HTML_vobj1[] = "HTML_vobj";
static char _slotValue_HTML_vobj2[] = "\n\tswitch (arg[0]) {\n\tcase 'i':\n\t\tif (tagID) {\n\t\t\tsend(parent(), \"setAnchor\", tagID);\n\t\t\ttagID = 0;\n\t\t}\n\t\tif (url) {\n\t\t\tt = concat(\" \\\\b(\", compressSpaces(get(\"label\")),\n\t\t\t\t\t\"\\\\b)\\\\e(\", HTTPEncodeURL(url), \") \");\n\t\t\turl = 0;\n\t\t\treturn t;\n\t\t} else {\n\t\t\treturn compressSpaces(get(\"label\"));\n\t\t}\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"NAME\":\n\t\t\ttagID = arg[2];\n\t\tbreak;\n\t\tcase \"HREF\":\n\t\t\turl = arg[2];\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"F\":\n\t\th = 0;\n/*\t\tSGMLBuildDoc_setBuff(-1);*/ /* bad place to do this */\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th = send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\tSGMLBuildDoc_span(), makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tif (h == 0) return 1;\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"D\":\n\t\tset(\"content2\", self());/*a kludge to deal with cloning*/\n\t\th = get(\"height\");\n\t\tSGMLBuildDoc_setBuff(0);\n\t\tif (isBlank(get(\"label\")) == 0) {\n\t\t\tif (style_p == 0) style_p = SGMLGetStyle(\"HTML\", \"P\");\n\t\t\ttxtObj = HTML_txt(\"clone\");\n\t\t\tobjectListAppend_children(txtObj);\n\t\t\th += send(txtObj, \"make\", self(),\n\t\t\t\tcompressSpaces(get(\"label\")),\n\t\t\t\tstyle_p[3], \n\t\t\t\tget(\"width\") - style_p[3] - style_p[2],\n\t\t\t\th, makeAnchor);\n\t\t\tmakeAnchor = 0;\n\t\t}\n\t\tset(\"height\", h);\n\t\treturn h;\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"P\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\n\t\tvspan = 1;\n\t\tn = countChildren();\n\t\tif (n) {\n\t\t\txx = get(\"width\");\n\t\t\tfor (i = 0; i < n; i++)\n\t\t\t  vspan += send(nthChild(i), 'R', vspan, xx);\n\t\t}\n\t\tset(\"height\", vspan);\n\t\treturn vspan;\n\tbreak;\n\tcase \"copyObj\":\n\t\turl = send(arg[1], \"url\");\n\t\treturn 0;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"expose\":\n\tcase \"render\":\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_vobj[] = {
    {"class", _slotValue_HTML_vobj0},
    {"name", _slotValue_HTML_vobj1},
    {"script", _slotValue_HTML_vobj2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vobjf0[] = "field";
static char _slotValue_HTML_vobjf1[] = "HTML_vobjf";
static char _slotValue_HTML_vobjf2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tdocURL = violaSrc;\n\n\t\tlocalFile = HTTPGet(docURL);\n\n\t\taddrInfo = HTTPCurrentDocAddrParsed(localFile);\n\n\t\tif (nthChar(addrInfo[2], 0) == '/') path = addrInfo[2];\n\t\telse path = concat('/', addrInfo[2]);\n\t\tobjFileName = addrInfo[3];\n\n\t\taddrInfo = HTTPCurrentDocAddrParsed(docURL);\n\t\tobjName = nthChar(addrInfo[3], 0, strlen(addrInfo[3]) - 3);\n\n\t\tstat = loadObjFile(path, objFileName);\n\n\t\tsend(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\n\t\tif (stat <= 0) {\n\t\t\tprint(\"failed to load obj file {\", objFileName,\n\t\t\t\t\"} in {\", path, \"}\\n\");\n\n\t\t\tnew = send(\"HTML_fail\", \"clone\");\n\t\t\tset(\"children\", new);\n\t\t\tvspan = send(new, \"make\", self(), get(\"width\"),\n\t\t\t\t     concat(\"Insert failed here: \", docURL));\n\t\t\treturn vspan;\n\t\t}\n\n\t\t/* from now on, newly made objects are declared unsecure */\n\t\tsecurityMode(1); \n\t\tsend(objName, \"init\"); /* make new object(s) */\n\t\tsecurityMode(0);\n\t\t/* back to normal */\n\n\t\tset(\"children\", objName);\n\t\ttweak(objName, concat(\"set(\\\"parent\\\", \\\"\", self(), \"\\\");\"));\n\n\t\t/* kludge */\n\t\tafter(1, objName, \"configSelf\");\n/*\n\t\tafter(1, self(), \"config\", x(), y(), width(), height()+2);\n\t\tdeepObjectListSend(\"children\", \"configSelf\");\n*/\n\t\tvspan = tweak(nthChild(0), \"height();\") + 2;\n\t\treturn vspan;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"VOBJF\");\n\t\tvspan = style[0];\n\t\tset(\"x\", style[2]);\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tvspan = tweak(nthChild(0), \"height();\") + 2;\n\t\tset(\"height\", vspan);\n\t\tvspan += style[1];\n\t\treturn vspan;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"VOBJF\");\n\t\tset(\"width\", get(\"width\") - style[3]);\n\t\tvspan = tweak(nthChild(0), \"height();\") + 2;\n\t\treturn vspan;\n\tbreak;\n\tcase \"AA\":\n\t\tswitch (arg[1]) {\n\t\tcase \"HREF\":\n\t\t\tviolaSrc = arg[2];\n\t\tbreak;\n\t\tcase \"ARG\":\n\t\t\targ = arg[2];\n\t\tbreak;\n\t\tcase \"MAXWIDTH\":\n\t\t\tset(\"maxWidth\", arg[2]);\n\t\tbreak;\n\t\tcase \"MINWIDTH\":\n\t\t\tset(\"minWidth\", arg[2]);\n\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"AI\":\n\t\treturn;\n\tbreak;\n\tcase \"findTop\":\n\t\treturn send(parent(), \"findTop\");\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_vobjf[] = {
    {"class", _slotValue_HTML_vobjf0},
    {"name", _slotValue_HTML_vobjf1},
    {"script", _slotValue_HTML_vobjf2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vr0[] = "field";
static char _slotValue_HTML_vr1[] = "HTML_vr";
static char _slotValue_HTML_vr2[] = "\n\tswitch (arg[0]) {\n\tcase \"expose\":\n\tcase \"D\":\n\t\treturn 1;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"VR\");\n\t\tset(\"y\", arg[1] + style[0]);\n\t\treturn 10;\n\tbreak;\n\tcase 'r':\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"VR\");\n\t\tafter(1, self(), \"fixHeight\");\n\t\treturn 10;\n\tbreak;\n\tcase \"fixHeight\":\n\t\tph = send(parent(), \"heightP\");\n\t\tset(\"height\", ph - style[0] - style[1]);\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"outputSGML\":\n\t\tprint(\"<VR>\\n\");\n\t\treturn;\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_vview2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\ttext = get(\"label\");\n\t\tsend(send(parent(), \"findTop\"), \"VW_relay\", self(),\"VIEW_ON\");\n\t\tsend(send(parent(), \"findTop\"), \"VW_relay\", self(),\"VIEW_OFF\");\n\t\treturn -1;\n\tbreak;\n\tcase \"VIEW_ON\":\n\t\tprint(\"interpreting: {\", text, \"}\\n\");\n\t\tinterpret(text);\n\t\treturn;\n\tbreak;\n\tcase \"VIEW_OFF\":\n\tcase \"config\":\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\t}\n\tusual();\n";
/* END OF FILE */

static SlotStruct objDesc_HTML_vview[] = {
    {"class", _slotValue_HTML_vview0},
    {"name", _slotValue_HTML_vview1},
    {"script", _slotValue_HTML_vview2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_xbm0[] = "XBM";
static char _slotValue_HTML_xbm1[] = "HTML_xbm";
static char _slotValue_HTML_xbm2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tset(\"label\", get(\"label\"));\n\t\treturn get(\"height\");\n\tbreak;\n\tcase \"R\":\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"XBM\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tset(\"content\", get(\"content\"));\n\t\tvspan += get(\"height\") + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"buttonPress\":\n\t\txy = mouseLocal();\n\t\tx0 = xy[0];\n\t\ty0 = xy[1];\n\t\tset(\"FGColor\", \"black\");\n\t\tdrawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\t\tdrawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\t\tset(\"FGColor\", \"white\");\n\t\tdrawLine(x0, y0 - 5, x0, y0 + 5);\n\t\tdrawLine(x0 + 5, y0, x0 - 5, y0);\n\tbreak;\n\tcase \"buttonRelease\":\n\t\txy = mouseLocal();\n\t\tx1 = xy[0];\n\t\ty1 = xy[1];\n\t\ttop = send(parent(), \"findTop\");\n\t\tref = concat(send(top, \"query_docURL\"), \"?\",\n\t\t\t\tx0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\n\t\tset(\"FGColor\", \"black\");\n\t\tdrawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\t\tdrawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\t\tset(\"FGColor\", \"white\");\n\t\tdrawLine(x1, y1 - 5, x1, y1 + 5);\n\t\tdrawLine(x1 + 5, y1, x1 - 5, y1);\n\t\tsend(top, \"follow_href\", ref);\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_xbmf2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tvspan += get(\"height\") + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tw\n\t\t * arg[3]\ty\n\t\t * arg[4]\tdocURL\n\t\t * arg[5]\tdelayP\n\t\t * arg[6]\tdelayWidth\n\t\t * arg[7]\tdelayHeight\n\t\t * arg[8]\tismap\n\t\t */\n\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[2]);\n\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\t\tset(\"y\", style[0]);\n\t\tset(\"x\", arg[3] + style[2]);\n\t\tismap = arg[8];\n\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\t\tlocalFile = HTTPGet(arg[4]);\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\n\t\tif (arg[5] > 0) {\n\t\t\tafter(arg[5], self(), \n\t\t\t\t\"loadData\", localFile, arg[6], arg[7]);\n\t\t\tset(\"width\", arg[6]);\n\t\t\tset(\"height\", arg[7]);\n\t\t\treturn height();\n\t\t} else {\n\t\t\tset(\"label\", loadFile(localFile));\n\t\t\tsend(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\t\t\treturn height();\n\t\t}\n\tbreak;\n\tcase \"loadData\":\n\t\tset(\"label\", loadFile(arg[1]));\n\t\tsend(\"wwwSecurity\", \"rmTmpFile\", arg[1]);\n\t\trender();\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"buttonPress\":\n\t\tif (ismap) {\n\t\t\txy = mouseLocal();\n\t\t\tx0 = xy[0];\n\t\t\ty0 = xy[1];\n\t\t\tset(\"FGColor\", \"black\");\n\t\t\tdrawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\t\t\tdrawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\t\t\tset(\"FGColor\", \"white\");\n\t\t\tdrawLine(x0, y0 - 5, x0, y0 + 5);\n\t\t\tdrawLine(x0 + 5, y0, x0 - 5, y0);\n\t\t}\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tif (ismap) {\n\t\t\txy = mouseLocal();\n\t\t\tx1 = xy[0];\n\t\t\ty1 = xy[1];\n\t\t\tif (top == 0) top = send(parent(), \"findTop\");\n\t\t\tref = concat(send(top, \"query_docURL\"), \"?\",\n\t\t\t\t\tx0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\n\t\t\tset(\"FGColor\", \"black\");\n\t\t\tdrawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\t\t\tdrawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\t\t\tset(\"FGColor\", \"white\");\n\t\t\tdrawLine(x1, y1 - 5, x1, y1 + 5);\n\t\t\tdrawLine(x1 + 5, y1, x1 - 5, y1);\n\t\t\tsend(top, \"follow_href\", ref);\n\t\t}\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_xpm2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\tset(\"label\", get(\"label\"));\n\t\treturn get(\"height\");\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tif (style == 0) style = SGMLGetStyle(\"HTML\", \"XPM\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tvspan += get(\"height\") + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn 0;\n\tbreak;\n\tcase \"buttonPress\":\n\t\txy = mouseLocal();\n\t\tx0 = xy[0];\n\t\ty0 = xy[1];\n\t\tset(\"FGColor\", \"black\");\n\t\tdrawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\t\tdrawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\t\tset(\"FGColor\", \"white\");\n\t\tdrawLine(x0, y0 - 5, x0, y0 + 5);\n\t\tdrawLine(x0 + 5, y0, x0 - 5, y0);\n\tbreak;\n\tcase \"buttonRelease\":\n\t\txy = mouseLocal();\n\t\tx1 = xy[0];\n\t\ty1 = xy[1];\n\t\ttop = send(parent(), \"findTop\");\n\t\tref = concat(send(top, \"query_docURL\"), \"?\",\n\t\t\t\tx0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\n\t\tset(\"FGColor\", \"black\");\n\t\tdrawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\t\tdrawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\t\tset(\"FGColor\", \"white\");\n\t\tdrawLine(x1, y1 - 5, x1, y1 + 5);\n\t\tdrawLine(x1 + 5, y1, x1 - 5, y1);\n\t\tsend(top, \"follow_href\", ref);\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_HTML_xpmf2[] = "\n\tswitch (arg[0]) {\n\tcase \"D\":\n\t\treturn -1;\n\tbreak;\n\tcase 'R':\n\t\t/* arg[1]\ty\n\t\t * arg[2]\twidth\n\t\t */\n\t\tclearWindow();\n\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\t\tvspan = style[0];\n\t\tset(\"y\", arg[1] + vspan);\n\t\tset(\"x\", style[2]);\n\t\tset(\"width\", arg[2] - x() - style[3]);\n\t\tset(\"label\", get(\"label\"));\n\t\tvspan += get(\"height\") + style[1];\n\t\trender();\n\t\treturn vspan;\n\tbreak;\n\tcase \"make\":\n\t\t/* arg[1]\tparent\n\t\t * arg[2]\tw\n\t\t * arg[3]\ty\n\t\t * arg[4]\tsrc\n\t\t * arg[5]\tdelayP\n\t\t * arg[6]\tdelayWidth\n\t\t * arg[7]\tdelayHeight\n\t\t * arg[8]\tismap\n\t\t */\n\t\tstyle = SGMLGetStyle(\"HTML\", \"FIGDATA\");\n\t\tset(\"y\", arg[3] + style[0]);\n\t\tset(\"x\", style[2]);\n\t\tset(\"parent\", arg[1]);\n\t\tset(\"width\", arg[2]);\n\t\tismap = arg[8];\n\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data...\");\n\n\t\tlocalFile = HTTPGet(arg[4]);\n\n\t\tsend(\"www.mesg.tf\", \"show\", \"Retrieving image data... Done.\");\n\n\t\tif (arg[5] > 0) {\n\t\t\tafter(arg[5], self(), \"loadData\", localFile);\n\t\t\treturn 50; /*XXX*/\n\t\t} else {\n\t\t\tset(\"label\", loadFile(localFile));\n\t\t\tsend(\"wwwSecurity\", \"rmTmpFile\", localFile);\n\t\t\treturn height();\n\t\t}\n\tbreak;\n\tcase \"loadData\":\n\t\tset(\"label\", localFile);\n\t\tsystem(concat(\"rm -f \", localFile));\n\t\treturn;\n\tbreak;\n\tcase \"config\":\n\t\treturn;\n\tbreak;\n\tcase \"gotoAnchor\":\n\t\treturn \"\";\n\tbreak;\n\tcase \"buttonPress\":\n\t\tif (ismap) {\n\t\t\txy = mouseLocal();\n\t\t\tx0 = xy[0];\n\t\t\ty0 = xy[1];\n\t\t\tset(\"FGColor\", \"black\");\n\t\t\tdrawLine(x0 + 1, y0 - 5, x0 + 1, y0 + 5);\n\t\t\tdrawLine(x0 + 5, y0 + 1, x0 - 5, y0 + 1);\n\t\t\tset(\"FGColor\", \"white\");\n\t\t\tdrawLine(x0, y0 - 5, x0, y0 + 5);\n\t\t\tdrawLine(x0 + 5, y0, x0 - 5, y0);\n\t\t}\n\tbreak;\n\tcase \"buttonRelease\":\n\t\tif (ismap) {\n\t\t\txy = mouseLocal();\n\t\t\tx1 = xy[0];\n\t\t\ty1 = xy[1];\n\t\t\ttop = send(parent(), \"findTop\");\n\t\t\tref = concat(send(top, \"query_docURL\"), \"?\",\n\t\t\t\t\tx0, \",\", y0, \",\", x1, \",\", y1, \";\");\n\n\t\t\tset(\"FGColor\", \"black\");\n\t\t\tdrawLine(x1 + 1, y1 - 5, x1 + 1, y1 + 5);\n\t\t\tdrawLine(x1 + 5, y1 + 1, x1 - 5, y1 + 1);\n\t\t\tset(\"FGColor\", \"white\");\n\t\t\tdrawLine(x1, y1 - 5, x1, y1 + 5);\n\t\t\tdrawLine(x1 + 5, y1, x1 - 5, y1);\n\t\t\tsend(top, \"follow_href\", ref);\n\t\t}\n\tbreak;\n\tcase \"clone\":\n\t\treturn clone(cloneID());\n\tbreak;\n\tcase \"init\":\n\t\tusual();\n\t\tSGMLBuildDoc_setColors();\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_invokeExample3[] = "\n\tswitch (arg[0]) {\n\tcase \"render\":\n\t\tset(\"visible\", 1);\n\t\trender();\n\t\traise();\n\t\treturn;\n\tbreak;\n\tcase \"invoke\":\n\t\tdata = tweak(arg[1], \"get(\\\"content\\\");\");\n\n\t\t/* get rid of font-directive from likes of:\n\t\t *\t\\f(7)telnet madlab.sprl.umich.edu\\f(1) port \\f(7)3000\n\t\t */\n\n\t\t/* this is pretty messed up. remember to implement substr() */\n\t\tclearP = 1;\n\t\twhile (clearP) {\n\t\t\tat = findPattern(data, \"\\\\f\");\n\t\t\tif (at == -1) clearP = 0;\n\t\t\telse {\n\t\t\t\tif (at == 1) {\n\t\t\t\t\tdata = nthChar(data, 5, strlen(data));\n\t\t\t\t} else {\n\t\t\t\t\tdata = concat(nthChar(data, 0, at - 2),\n\t\t\t\t\t\tnthChar(data, at + 4, \n\t\t\t\t\t\t\tstrlen(data)));\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tsemiAt = findPattern(data, \";\");\n\t\tif (semiAt == -1) {\n\t\t\tstmt = nthLine(data, 0);\n\t\t\tstmt = trimEdge(nthChar(stmt, 0, 999));\n\t\t} else {\n\t\t\tstmt = trimEdge(nthChar(data, 0, semiAt - 1));\n\t\t}\n\t\tprint(\"stmt={\", stmt, \"}\\n\");\n\n\t\tswitch (nthWord(stmt, 1)) {\n\t\tcase \"finger\":\n\t\t\ttmp = makeTempFile();\n\t\t\tsystem(concat(stmt, \" > \", tmp));\n\t\t\tset(\"visible\", 1);\n\t\t\trender();\n\t\t\tdeepObjectListSend(\"children\", \"render\");\n\t\t\traise();\n\t\t\tsend(nthChild(1), \"show\", tmp);\n\t\t\tsend(nthChild(0), \"show\", stmt);\n\t\t\tsystem(concat(\"rm -f \", tmp));\n\t\tbreak;\n\t\tcase \"telnet\":\n\t\t\t/* can't handle this, pop up a shell */\n\n\t\t\treplaceCharQ(stmt, ';', '\\0');\n\t\t\tp0 = findPattern(stmt, \" port \");\n\t\t\tprint(\">>\", stmt, \"<<< p0=\", p0, \".\\n\");\n\n\t\t\tif (p0 != -1) {\n\t\t\t\t/* Rid of \"port\", b/c it probably looks like:\n\t\t\t\t * telnet eve.assumption.edu port 5000 \n\t\t\t\t */\n\n\t\t\t\tport = nthChar(stmt, p0 + 6, 999);\n\t\t\t\tprint(\" port=>>>\", port, \"<<\\n\");\n\n\t\t\t\thostName = nthWord(stmt, 2, 9);\n\n\t\t\t\tprint(\" hostname=>>>\", hostName, \"<<\\n\");\n\n\t\t\t\tprint(\">>\", concat(\"xterm \", \n\t\t\t\t\t\"-title \\\"\", hostName, \"\\\" \"),\n\t\t\t\t\t\"-e \", stmt, \" \", port, \" &\",\n\t\t\t\t\t\"<<\\n\");\n\t\t\t\tsystem(concat(\"xterm \", \n\t\t\t\t\t\"-title \\\"\", hostName, \"\\\" \",\n\t\t\t\t\t\"-e \", stmt, \" \", port, \" &\"));\n\t\t\t} else {\n\t\t\t\tlogin = \"\";\n\t\t\t\tl0 = findPattern(stmt, \"login\");\n\t\t\t\tif (l0 != -1) {\n\t\t\t\t\tlogin = nthChar(stmt, l0 + 6, 999);\n\t\t\t\t}\n\t\t\t\treplaceCharQ(stmt, ';', '\\0');\n\t\t\t\treplaceCharQ(stmt, '\\\\', '\\0');\n\t\t\t\thostName = nthWord(stmt, 2, 9);\n\n\t\t\t\tif (login) {\n\t\t\t\t\tprint(\">>\", concat(\"xterm \", \n\t\t\t\t\t\t\"-title \\\"\", hostName, \"\\\" \"),\n\t\t\t\t\t\t\"-e \", stmt, \" &\",\n\t\t\t\t\t\t\"<<\\n\");\n\t\t\t\t\tsystem(concat(\"xterm \", \n\t\t\t\t\t\t\"-title \\\"\", hostName, \"\\\" \",\n\t\t\t\t\t\t\"-e \", stmt, \" &\"));\n\t\t\t\t} else {\n\t\t\t\t\tprint(\">>\", concat(\"xterm \", \n\t\t\t\t\t\t\"-title \\\"\", hostName, \"\\\" \"),\n\t\t\t\t\t\t\"-e \", stmt,\n\t\t\t\t\t\t\" -l \", login, \" &\",\n\t\t\t\t\t\t\"<<\\n\");\n\t\t\t\t\tsystem(concat(\"xterm \", \n\t\t\t\t\t\t\"-title \\\"\", hostName, \"\\\" \",\n\t\t\t\t\t\t\"-e \", stmt,\n\t\t\t\t\t\t\" -l \", login, \" &\"));\n\t\t\t\t}\n\t\t\t}\n\t\t\tbreak;\n\t\t}\n\t\treturn;\n\tbreak;\n\tcase \"finger\":\n\t\ttmp = makeTempFile();\n\t\tsystem(concat(\"finger nasanews@space.mit.edu > \", tmp));\n\t\tsend(nthChild(1), \"show\", tmp);\n\t\tsystem(concat(\"rm -f \", tmp));\n\t\treturn;\n\tbreak;\n\tcase \"dismiss\":\n\t\tset(\"visible\", 0);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_invokeExample4[] = "600";
static char _slotValue_invokeExample5[] = "400";
static char _slotValue_invokeExample6[] = "invokeExample.top invokeExample.list invokeExample.ctrl";
/* END OF OBJ */

static char _slotValue_invokeExample8[] = "invokeExample.top";
static char _slotValue_invokeExample9[] = "txtLabel";
static char _slotValue_invokeExample10[] = "invokeExample";
static char _slotValue_invokeExample11[] = "normal";
static char _slotValue_invokeExample12[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"label\", arg[1]);\n\t\treturn;\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_invokeExample13[] = "Finger Info Viewer";
static char _slotValue_invokeExample14[] = "40";
static char _slotValue_invokeExample15[] = "bold_largest";
/* END OF OBJ */

static char _slotValue_invokeExample17[] = "invokeExample.list";
static char _slotValue_invokeExample18[] = "hpane";
static char _slotValue_invokeExample19[] = "invokeExample";
static char _slotValue_invokeExample20[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tsend(nthChild(0), \"show\", arg[1]);\n\t\treturn;\n\tbreak;\n\tcase \"contentP\":\n\t\treturn send(nthChild(0), \"contentP\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_invokeExample32[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\t\tset(\"content\", loadFile(arg[1]));\n/*\nprint(\"loading file >>>>>>>\", arg[1], \"<<<\\n\");\nprint(\"content >>>>>>>\", get(\"content\"), \"<<<\\n\");\n*/\n\t\treturn;\n\tbreak;\n\tcase \"contentP\":\n\t\treturn get(\"content\");\n\tbreak;\n\t}\n\tusual();\n";
static char _slotValue_invokeExample33[] = "invokeExample.list.sb";
static char _slotValue_invokeExample34[] = "fixed";
static char _slotValue_invokeExample35[] = "1";
/* END OF OBJ */

static char _slotValue_invokeExample37[] = "invokeExample.ctrl";
static char _slotValue_invokeExample38[] = "hpane";
static char _slotValue_invokeExample39[] = "invokeExample";
static char _slotValue_invokeExample40[] = "20";
static char _slotValue_invokeExample41[] = "invokeExample.ctrl.dismiss";
static char _slotValue_invokeExample42[] = "\n\tswitch (arg[0]) {\n\tcase \"show\":\n\tcase \"dismiss\":\n\t\tsend(get(\"parent\"), arg[0]);\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_invokeExample44[] = "invokeExample.ctrl.finger";
static char _slotValue_invokeExample45[] = "txtButton";
static char _slotValue_invokeExample46[] = "invokeExample.ctrl";
static char _slotValue_invokeExample47[] = "normal";
static char _slotValue_invokeExample48[] = "Finger nasanews@space.mit.edu";
static char _slotValue_invokeExample49[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(get(\"parent\"), \"show\");\n\tbreak;\n\t}\n\tusual();\n";
/* END OF OBJ */

static char _slotValue_invokeExample51[] = "invokeExample.ctrl.dismiss";
static char _slotValue_invokeExample52[] = "txtButton";
static char _slotValue_invokeExample53[] = "invokeExample.ctrl";
static char _slotValue_invokeExample54[] = "normal";
static char _slotValue_invokeExample55[] = "Dismiss";
static char _slotValue_invokeExample56[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tsend(get(\"parent\"), \"dismiss\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_invokeFinger4[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tinvokeExample(\"invoke\", caller);\n\tbreak;\n\tcase \"new\":\n\t\t/* arg[1]\tcaller\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t */\n\t\treturn send(clone(cloneID()), \"build\", \n\t\t\t\targ[1], arg[2], arg[3], arg[4]);\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tcaller\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t */\n\t\tcaller = arg[1];\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"x\", arg[3] + 2);\n\t\tset(\"y\", arg[4]);\n\t\tset(\"visible\", 1);\n\t\treturn get(\"name\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_invokeGopher4[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tinvokeExample(\"invoke\", caller);\n\tbreak;\n\tcase \"new\":\n\t\t/* arg[1]\tcaller\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t */\n\t\treturn send(clone(cloneID()), \"build\", \n\t\t\t\targ[1], arg[2], arg[3], arg[4]);\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tcaller\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t */\n\t\tcaller = arg[1];\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"x\", arg[3] + 2);\n\t\tset(\"y\", arg[4]);\n\t\tset(\"visible\", 1);\n\t\treturn get(\"name\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_invokeTelnet4[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tinvokeExample(\"invoke\", caller);\n\tbreak;\n\tcase \"new\":\n\t\t/* arg[1]\tcaller\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t */\n\t\treturn send(clone(cloneID(), \"build\", \n\t\t\t\targ[1], arg[2], arg[3], arg[4]);\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tcaller\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t */\n\t\tcaller = arg[1];\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"x\", arg[3] + 2);\n\t\tset(\"y\", arg[4]);\n\t\tset(\"visible\", 1);\n\t\treturn get(\"name\");\n\tbreak;\n\t}\n\tusual();\n";
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
static char _slotValue_invokeWAIS3[] = "\n\tswitch (arg[0]) {\n\tcase \"buttonRelease\":\n\t\tinvokeExample(\"invoke\", caller);\n\tbreak;\n\tcase \"new\":\n\t\t/* arg[1]\tcaller\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t */\n\t\treturn send(clone(cloneID()), \"build\", \n\t\t\t\targ[1], arg[2], arg[3], arg[4]);\n\tbreak;\n\tcase \"build\":\n\t\t/* arg[1]\tcaller\n\t\t * arg[2]\tparent\n\t\t * arg[3]\tx\n\t\t * arg[4]\ty\n\t\t */\n\t\tcaller = arg[1];\n\t\tset(\"parent\", arg[2]);\n\t\tset(\"x\", arg[3] + 2);\n\t\tset(\"y\", arg[4]);\n\t\tset(\"visible\", 1);\n\t\treturn get(\"name\");\n\tbreak;\n\t}\n\tusual();\n";
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
