#include "objs.h"

static char _slotValue_res0[] = "res";
static char _slotValue_res1[] = "generic";
static char _slotValue_res2[] = {
#include "embeds/res_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_res[] = {
    {"name", _slotValue_res0},
    {"class", _slotValue_res1},
    {"script", _slotValue_res2},
    {(char*)0, (char*)0},
};

static char _slotValue_res_font0[] = "res.font";
static char _slotValue_res_font1[] = "generic";
static char _slotValue_res_font2[] = {
#include "embeds/res_font_script.v.h"
};
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
static char _slotValue_res_HTMLStyle3[] = {
#include "embeds/res_HTMLStyle_script.v.h"
};
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
static char _slotValue_res_dialogWithButtons5[] = {
#include "embeds/res_dialogWithButtons_script5.v.h"
};
static char _slotValue_res_dialogWithButtons6[] = "res.dialogWithButtons.mesg res.dialogWithButtons.buttons";
/* END OF OBJ */

static char _slotValue_res_dialogWithButtons8[] = "txtDisp";
static char _slotValue_res_dialogWithButtons9[] = "res.dialogWithButtons.mesg";
static char _slotValue_res_dialogWithButtons10[] = "res.dialogWithButtons";
static char _slotValue_res_dialogWithButtons11[] = "4";
static char _slotValue_res_dialogWithButtons12[] = "4";
static char _slotValue_res_dialogWithButtons13[] = {
#include "embeds/res_dialogWithButtons_script.v.h"
};
static char _slotValue_res_dialogWithButtons14[] = "normal";
/* END OF OBJ */

static char _slotValue_res_dialogWithButtons16[] = "hpane";
static char _slotValue_res_dialogWithButtons17[] = "res.dialogWithButtons.buttons";
static char _slotValue_res_dialogWithButtons18[] = "res.dialogWithButtons";
static char _slotValue_res_dialogWithButtons19[] = {
#include "embeds/res_dialogWithButtons_script19.v.h"
};
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
static char _slotValue_res_getLineEntry5[] = {
#include "embeds/res_getLineEntry_script5.v.h"
};
static char _slotValue_res_getLineEntry6[] = "res.getLineEntry.mesg res.getLineEntry.entry res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry7[] = "6";
/* END OF OBJ */

static char _slotValue_res_getLineEntry9[] = "txtDisp";
static char _slotValue_res_getLineEntry10[] = "res.getLineEntry.mesg";
static char _slotValue_res_getLineEntry11[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry12[] = {
#include "embeds/res_getLineEntry_script.v.h"
};
static char _slotValue_res_getLineEntry13[] = "2";
static char _slotValue_res_getLineEntry14[] = "2";
static char _slotValue_res_getLineEntry15[] = "normal";
/* END OF OBJ */

static char _slotValue_res_getLineEntry17[] = "txtEdit";
static char _slotValue_res_getLineEntry18[] = "res.getLineEntry.entry";
static char _slotValue_res_getLineEntry19[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry20[] = {
#include "embeds/res_getLineEntry_script20.v.h"
};
static char _slotValue_res_getLineEntry21[] = "4";
static char _slotValue_res_getLineEntry22[] = "4";
static char _slotValue_res_getLineEntry23[] = "normal";
/* END OF OBJ */

static char _slotValue_res_getLineEntry25[] = "hpane";
static char _slotValue_res_getLineEntry26[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry27[] = "res.getLineEntry";
static char _slotValue_res_getLineEntry28[] = "res.getLineEntry.buttons.ok res.getLineEntry.buttons.cancel";
static char _slotValue_res_getLineEntry29[] = {
#include "embeds/res_getLineEntry_script29.v.h"
};
static char _slotValue_res_getLineEntry30[] = "22";
static char _slotValue_res_getLineEntry31[] = "3";
/* END OF OBJ */

static char _slotValue_res_getLineEntry33[] = "txtButton";
static char _slotValue_res_getLineEntry34[] = "OK";
static char _slotValue_res_getLineEntry35[] = "res.getLineEntry.buttons.ok";
static char _slotValue_res_getLineEntry36[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry37[] = {
#include "embeds/res_getLineEntry_script37.v.h"
};
static char _slotValue_res_getLineEntry38[] = "10";
/* END OF OBJ */

static char _slotValue_res_getLineEntry40[] = "txtButton";
static char _slotValue_res_getLineEntry41[] = "Cancel";
static char _slotValue_res_getLineEntry42[] = "res.getLineEntry.buttons.cancel";
static char _slotValue_res_getLineEntry43[] = "res.getLineEntry.buttons";
static char _slotValue_res_getLineEntry44[] = {
#include "embeds/res_getLineEntry_script44.v.h"
};
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
static char _slotValue_shell6[] = {
#include "embeds/shell_script6.v.h"
};
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
static char _slotValue_shell25[] = {
#include "embeds/shell_script25.v.h"
};
static char _slotValue_shell26[] = {
#include "embeds/shell_menuConfig.v.h"
};
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
static char _slotValue_shell37[] = {
#include "embeds/shell_script37.v.h"
};
static char _slotValue_shell38[] = {
#include "embeds/shell_menuConfig38.v.h"
};
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
static char _slotValue_shell49[] = {
#include "embeds/shell_menuConfig49.v.h"
};
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
static char _slotValue_shell65[] = {
#include "embeds/shell_script65.v.h"
};
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
static char _slotValue_shell91[] = {
#include "embeds/shell_script91.v.h"
};
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
static char _slotValue_shell111[] = {
#include "embeds/shell_script.v.h"
};
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
static char _slotValue_shell134[] = {
#include "embeds/shell_script134.v.h"
};
static char _slotValue_shell135[] = "shell.out.sb";
static char _slotValue_shell136[] = "1";
static char _slotValue_shell137[] = "fixed";
/* END OF OBJ */

static char _slotValue_shell139[] = "shell.mesg";
static char _slotValue_shell140[] = "txtDisp";
static char _slotValue_shell141[] = "shell";
static char _slotValue_shell142[] = "1";
static char _slotValue_shell143[] = {
#include "embeds/shell_script143.v.h"
};
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
static char _slotValue_VWHandler_fail2[] = {
#include "embeds/VWHandler_fail_script.v.h"
};
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
static char _slotValue_VWHandler_gif2[] = {
#include "embeds/VWHandler_gif_script.v.h"
};
/* END OF OBJ */

static char _slotValue_VWHandler_gif4[] = "GIF";
static char _slotValue_VWHandler_gif5[] = "VWHandler_gif.gif";
static char _slotValue_VWHandler_gif6[] = {
#include "embeds/VWHandler_gif_script6.v.h"
};
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
static char _slotValue_VWHandler_hmml2[] = {
#include "embeds/VWHandler_hmml_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_VWHandler_hmml[] = {
    {"class", _slotValue_VWHandler_hmml0},
    {"name", _slotValue_VWHandler_hmml1},
    {"script", _slotValue_VWHandler_hmml2},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_hmml_fail0[] = "txtDisp";
static char _slotValue_VWHandler_hmml_fail1[] = "VWHandler_fail";
static char _slotValue_VWHandler_hmml_fail2[] = {
#include "embeds/VWHandler_hmml_fail_script.v.h"
};
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
static char _slotValue_VWHandler_hmmlb3[] = {
#include "embeds/VWHandler_hmmlb_script.v.h"
};
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
static char _slotValue_VWHandler_html2[] = {
#include "embeds/VWHandler_html_script.v.h"
};
/* END OF OBJ */

static char _slotValue_VWHandler_html4[] = "HTML";
static char _slotValue_VWHandler_html5[] = "VWHandler_html.tf";
static char _slotValue_VWHandler_html6[] = {
#include "embeds/VWHandler_html_script6.v.h"
};
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
static char _slotValue_VWHandler_html22[] = {
#include "embeds/VWHandler_html_script22.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_VWHandler_html2[] = {
    {"class", _slotValue_VWHandler_html20},
    {"name", _slotValue_VWHandler_html21},
    {"script", _slotValue_VWHandler_html22},
    {(char*)0, (char*)0},
};

static char _slotValue_VWHandler_plaintext0[] = "generic";
static char _slotValue_VWHandler_plaintext1[] = "VWHandler_plaintext";
static char _slotValue_VWHandler_plaintext2[] = {
#include "embeds/VWHandler_plaintext_script.v.h"
};
/* END OF OBJ */

static char _slotValue_VWHandler_plaintext4[] = "txtDisp";
static char _slotValue_VWHandler_plaintext5[] = "VWHandler_plaintext.tf";
static char _slotValue_VWHandler_plaintext6[] = {
#include "embeds/VWHandler_plaintext_script6.v.h"
};
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
static char _slotValue_VWHandler_vobj2[] = {
#include "embeds/VWHandler_vobj_script.v.h"
};
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
static char _slotValue_VWHandler_vobjf2[] = {
#include "embeds/VWHandler_vobjf_script.v.h"
};
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
static char _slotValue_VWHandler_xbm2[] = {
#include "embeds/VWHandler_xbm_script.v.h"
};
/* END OF OBJ */

static char _slotValue_VWHandler_xbm4[] = "XBM";
static char _slotValue_VWHandler_xbm5[] = "VWHandler_xbm.xbm";
static char _slotValue_VWHandler_xbm6[] = {
#include "embeds/VWHandler_xbm_script6.v.h"
};
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
static char _slotValue_VWHandler_xpm2[] = {
#include "embeds/VWHandler_xpm_script.v.h"
};
/* END OF OBJ */

static char _slotValue_VWHandler_xpm4[] = "XPM";
static char _slotValue_VWHandler_xpm5[] = "VWHandler_xpm.xpm";
static char _slotValue_VWHandler_xpm6[] = {
#include "embeds/VWHandler_xpm_script6.v.h"
};
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
static char _slotValue_WWWEMailHandler2[] = {
#include "embeds/WWWEMailHandler_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_WWWEMailHandler[] = {
    {"class", _slotValue_WWWEMailHandler0},
    {"name", _slotValue_WWWEMailHandler1},
    {"script", _slotValue_WWWEMailHandler2},
    {(char*)0, (char*)0},
};

static char _slotValue_WWWTelnetHandler0[] = "generic";
static char _slotValue_WWWTelnetHandler1[] = "WWWTelnetHandler";
static char _slotValue_WWWTelnetHandler2[] = {
#include "embeds/WWWTelnetHandler_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_WWWTelnetHandler[] = {
    {"class", _slotValue_WWWTelnetHandler0},
    {"name", _slotValue_WWWTelnetHandler1},
    {"script", _slotValue_WWWTelnetHandler2},
    {(char*)0, (char*)0},
};

static char _slotValue_normalizeURL0[] = "normalizeURL";
static char _slotValue_normalizeURL1[] = "generic";
static char _slotValue_normalizeURL2[] = {
#include "embeds/normalizeURL_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_normalizeURL[] = {
    {"name", _slotValue_normalizeURL0},
    {"class", _slotValue_normalizeURL1},
    {"script", _slotValue_normalizeURL2},
    {(char*)0, (char*)0},
};

static char _slotValue_parseHTTPAddress0[] = "generic";
static char _slotValue_parseHTTPAddress1[] = "parseHTTPAddress";
static char _slotValue_parseHTTPAddress2[] = {
#include "embeds/parseHTTPAddress_script.v.h"
};
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
static char _slotValue_www9[] = {
#include "embeds/www_script9.v.h"
};
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
static char _slotValue_www26[] = {
#include "embeds/www_script26.v.h"
};
static char _slotValue_www27[] = {
#include "embeds/www_menuConfig.v.h"
};
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
static char _slotValue_www38[] = {
#include "embeds/www_menuConfig38.v.h"
};
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
static char _slotValue_www63[] = {
#include "embeds/www_menuConfig63.v.h"
};
static char _slotValue_www64[] = "90";
static char _slotValue_www65[] = "4";
static char _slotValue_www66[] = "10";
static char _slotValue_www67[] = "normal";
/* END OF OBJ */

static char _slotValue_www69[] = "vpane";
static char _slotValue_www70[] = "www.doc";
static char _slotValue_www71[] = "www";
static char _slotValue_www72[] = "www.doc.tools www.doc.title www.doc.view";
static char _slotValue_www73[] = {
#include "embeds/www_script73.v.h"
};
static char _slotValue_www74[] = "2";
/* END OF OBJ */

static char _slotValue_www76[] = "hpane";
static char _slotValue_www77[] = "www.doc.title";
static char _slotValue_www78[] = "www.doc";
static char _slotValue_www79[] = "www.doc.title.tf";
static char _slotValue_www80[] = {
#include "embeds/www_script80.v.h"
};
static char _slotValue_www81[] = "38";
static char _slotValue_www82[] = "2";
/* END OF OBJ */

static char _slotValue_www84[] = "txtDisp";
static char _slotValue_www85[] = "www.doc.title.tf";
static char _slotValue_www86[] = "www.doc.title";
static char _slotValue_www87[] = {
#include "embeds/www_script87.v.h"
};
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
static char _slotValue_www100[] = {
#include "embeds/www_script.v.h"
};
static char _slotValue_www101[] = "2";
static char _slotValue_www102[] = "39";
/* END OF OBJ */

static char _slotValue_www104[] = "hpane";
static char _slotValue_www105[] = "www.doc.tools.dyna";
static char _slotValue_www106[] = "www.doc.tools";
static char _slotValue_www107[] = {
#include "embeds/www_script107.v.h"
};
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
static char _slotValue_www123[] = {
#include "embeds/www_script123.v.h"
};
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
static char _slotValue_www132[] = {
#include "embeds/www_script132.v.h"
};
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
static char _slotValue_www141[] = {
#include "embeds/www_script141.v.h"
};
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
static char _slotValue_www150[] = {
#include "embeds/www_script150.v.h"
};
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
static char _slotValue_www159[] = {
#include "embeds/www_script159.v.h"
};
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
static char _slotValue_www168[] = {
#include "embeds/www_script168.v.h"
};
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
static char _slotValue_www186[] = {
#include "embeds/www_script186.v.h"
};
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
static char _slotValue_www197[] = {
#include "embeds/www_script197.v.h"
};
/* END OF OBJ */

static char _slotValue_www199[] = "field";
static char _slotValue_www200[] = "www.doc.view.sTUb";
static char _slotValue_www201[] = "www.doc.view";
static char _slotValue_www202[] = {
#include "embeds/www_script202.v.h"
};
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
static char _slotValue_www214[] = {
#include "embeds/www_script214.v.h"
};
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
static char _slotValue_www225[] = {
#include "embeds/www_script225.v.h"
};
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
static char _slotValue_www239[] = {
#include "embeds/www_script239.v.h"
};
/* END OF OBJ */

static char _slotValue_www241[] = "slider";
static char _slotValue_www242[] = "www.doc.view.lbar.sb";
static char _slotValue_www243[] = "www.doc.view";
static char _slotValue_www244[] = "www.doc.view.lbar.pane";
static char _slotValue_www245[] = {
#include "embeds/www_script245.v.h"
};
static char _slotValue_www246[] = "left2right";
static char _slotValue_www247[] = "20";
/* END OF OBJ */

static char _slotValue_www249[] = "vpane";
static char _slotValue_www250[] = "www.doc.view";
static char _slotValue_www251[] = "www.doc.view.lbar";
static char _slotValue_www252[] = "www.doc.view.lbar.pane www.doc.view.lbar.ctrls";
static char _slotValue_www253[] = {
#include "embeds/www_script253.v.h"
};
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
static char _slotValue_www266[] = {
#include "embeds/www_script266.v.h"
};
static char _slotValue_www267[] = "1";
static char _slotValue_www268[] = "20";
/* END OF OBJ */

static char _slotValue_www270[] = "txtButton";
static char _slotValue_www271[] = "www.doc.view.lbar.ctrls";
static char _slotValue_www272[] = "www.doc.view.lbar.ctrls.up";
static char _slotValue_www273[] = "Up";
static char _slotValue_www274[] = {
#include "embeds/www_script274.v.h"
};
static char _slotValue_www275[] = "normal";
static char _slotValue_www276[] = "2";
/* END OF OBJ */

static char _slotValue_www278[] = "txtButton";
static char _slotValue_www279[] = "www.doc.view.lbar.ctrls";
static char _slotValue_www280[] = "www.doc.view.lbar.ctrls.down";
static char _slotValue_www281[] = "Down";
static char _slotValue_www282[] = {
#include "embeds/www_script282.v.h"
};
static char _slotValue_www283[] = "normal";
static char _slotValue_www284[] = "1";
/* END OF OBJ */

static char _slotValue_www286[] = "field";
static char _slotValue_www287[] = "www.doc.view.lbar.pane";
static char _slotValue_www288[] = "www.doc.view.lbar";
static char _slotValue_www289[] = "www.doc.view.lbar.sb";
static char _slotValue_www290[] = {
#include "embeds/www_script290.v.h"
};
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
static char _slotValue_www301[] = {
#include "embeds/www_script301.v.h"
};
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
static char _slotValue_www318[] = {
#include "embeds/www_script318.v.h"
};
static char _slotValue_www319[] = "2";
static char _slotValue_www320[] = "1";
static char _slotValue_www321[] = "fixed";
/* END OF OBJ */

static char _slotValue_www323[] = "field";
static char _slotValue_www324[] = "www.progress";
static char _slotValue_www325[] = "www";
static char _slotValue_www326[] = {
#include "embeds/www_script326.v.h"
};
static char _slotValue_www327[] = "5";
/* END OF OBJ */

static char _slotValue_www329[] = "XBMButton";
static char _slotValue_www330[] = "www.ahelp.label";
static char _slotValue_www331[] = "www.mesg";
static char _slotValue_www332[] = {
#include "embeds/www_script332.v.h"
};
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
static char _slotValue_www358[] = {
#include "embeds/www_script358.v.h"
};
static char _slotValue_www359[] = "fixed";
/* END OF OBJ */

static char _slotValue_www361[] = "XBMButton";
static char _slotValue_www362[] = "www.url.setURL";
static char _slotValue_www363[] = "www.url";
static char _slotValue_www364[] = {
#include "embeds/www_script364.v.h"
};
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
static char _slotValue_www371[] = {
#include "embeds/www_script371.v.h"
};
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
static char _slotValue_wwwAbout3[] = {
#include "embeds/wwwAbout_script.v.h"
};
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
Version 4.0 Beta\n\
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
static char _slotValue_wwwAbout48[] = {
#include "embeds/wwwAbout_script48.v.h"
};
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
static char _slotValue_wwwAbout84[] = {
#include "embeds/wwwAbout_script84.v.h"
};
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
static char _slotValue_wwwDialog_confirm2[] = {
#include "embeds/wwwDialog_confirm_script.v.h"
};
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
static char _slotValue_wwwDocuPort4[] = {
#include "embeds/wwwDocuPort_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_wwwDocuPort[] = {
    {"name", _slotValue_wwwDocuPort0},   {"class", _slotValue_wwwDocuPort1},
    {"path", _slotValue_wwwDocuPort2},   {"args", _slotValue_wwwDocuPort3},
    {"script", _slotValue_wwwDocuPort4}, {(char*)0, (char*)0},
};

static char _slotValue_wwwFormatDetect0[] = "generic";
static char _slotValue_wwwFormatDetect1[] = "wwwFormatDetect";
static char _slotValue_wwwFormatDetect2[] = {
#include "embeds/wwwFormatDetect_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_wwwFormatDetect[] = {
    {"class", _slotValue_wwwFormatDetect0},
    {"name", _slotValue_wwwFormatDetect1},
    {"script", _slotValue_wwwFormatDetect2},
    {(char*)0, (char*)0},
};

static char _slotValue_wwwHandlerDispatch0[] = "wwwHandlerDispatch";
static char _slotValue_wwwHandlerDispatch1[] = "generic";
static char _slotValue_wwwHandlerDispatch2[] = {
#include "embeds/wwwHandlerDispatch_script.v.h"
};
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
static char _slotValue_wwwHistory3[] = {
#include "embeds/wwwHistory_script3.v.h"
};
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
static char _slotValue_wwwHistory22[] = {
#include "embeds/wwwHistory_script.v.h"
};
static char _slotValue_wwwHistory23[] = "70";
static char _slotValue_wwwHistory24[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory26[] = "wwwHistory.top.back";
static char _slotValue_wwwHistory27[] = "txtButton";
static char _slotValue_wwwHistory28[] = "wwwHistory.top";
static char _slotValue_wwwHistory29[] = "Back";
static char _slotValue_wwwHistory30[] = "normal";
static char _slotValue_wwwHistory31[] = {
#include "embeds/wwwHistory_script31.v.h"
};
static char _slotValue_wwwHistory32[] = "70";
static char _slotValue_wwwHistory33[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory35[] = "wwwHistory.top.next";
static char _slotValue_wwwHistory36[] = "txtButton";
static char _slotValue_wwwHistory37[] = "wwwHistory.top";
static char _slotValue_wwwHistory38[] = "Next";
static char _slotValue_wwwHistory39[] = "normal";
static char _slotValue_wwwHistory40[] = {
#include "embeds/wwwHistory_script40.v.h"
};
static char _slotValue_wwwHistory41[] = "70";
static char _slotValue_wwwHistory42[] = "4";
/* END OF OBJ */

static char _slotValue_wwwHistory44[] = "wwwHistory.top.title";
static char _slotValue_wwwHistory45[] = "txtLabel";
static char _slotValue_wwwHistory46[] = "wwwHistory.top";
static char _slotValue_wwwHistory47[] = "World Wide Web Travels";
static char _slotValue_wwwHistory48[] = "bold";
static char _slotValue_wwwHistory49[] = {
#include "embeds/wwwHistory_script49.v.h"
};
/* END OF OBJ */

static char _slotValue_wwwHistory51[] = "wwwHistory.top.dismiss";
static char _slotValue_wwwHistory52[] = "txtButton";
static char _slotValue_wwwHistory53[] = "wwwHistory.top";
static char _slotValue_wwwHistory54[] = "Dismiss";
static char _slotValue_wwwHistory55[] = "normal";
static char _slotValue_wwwHistory56[] = {
#include "embeds/wwwHistory_script56.v.h"
};
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
static char _slotValue_wwwHistory76[] = {
#include "embeds/wwwHistory_script76.v.h"
};
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
static char _slotValue_wwwHTMLSrc4[] = {
#include "embeds/wwwHTMLSrc_script4.v.h"
};
static char _slotValue_wwwHTMLSrc5[] = "600";
static char _slotValue_wwwHTMLSrc6[] = "400";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc8[] = "wwwHTMLSrc.top";
static char _slotValue_wwwHTMLSrc9[] = "txtDisp";
static char _slotValue_wwwHTMLSrc10[] = "wwwHTMLSrc";
static char _slotValue_wwwHTMLSrc11[] = "normal";
static char _slotValue_wwwHTMLSrc12[] = {
#include "embeds/wwwHTMLSrc_script.v.h"
};
static char _slotValue_wwwHTMLSrc13[] = "20";
static char _slotValue_wwwHTMLSrc14[] = "black";
static char _slotValue_wwwHTMLSrc15[] = "LemonChiffon3";
static char _slotValue_wwwHTMLSrc16[] = "black";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc18[] = "wwwHTMLSrc.list";
static char _slotValue_wwwHTMLSrc19[] = "hpane";
static char _slotValue_wwwHTMLSrc20[] = "wwwHTMLSrc";
static char _slotValue_wwwHTMLSrc21[] = {
#include "embeds/wwwHTMLSrc_script21.v.h"
};
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
static char _slotValue_wwwHTMLSrc36[] = {
#include "embeds/wwwHTMLSrc_script36.v.h"
};
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
static char _slotValue_wwwHTMLSrc48[] = {
#include "embeds/wwwHTMLSrc_script48.v.h"
};
static char _slotValue_wwwHTMLSrc49[] = "1";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc51[] = "wwwHTMLSrc.ctrl.apply";
static char _slotValue_wwwHTMLSrc52[] = "txtButton";
static char _slotValue_wwwHTMLSrc53[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc54[] = "normal";
static char _slotValue_wwwHTMLSrc55[] = "Apply Changes";
static char _slotValue_wwwHTMLSrc56[] = {
#include "embeds/wwwHTMLSrc_script56.v.h"
};
static char _slotValue_wwwHTMLSrc57[] = "grey45";
static char _slotValue_wwwHTMLSrc58[] = "white";
static char _slotValue_wwwHTMLSrc59[] = "white";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc61[] = "wwwHTMLSrc.ctrl.store";
static char _slotValue_wwwHTMLSrc62[] = "txtButton";
static char _slotValue_wwwHTMLSrc63[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc64[] = "normal";
static char _slotValue_wwwHTMLSrc65[] = "Store Changes";
static char _slotValue_wwwHTMLSrc66[] = {
#include "embeds/wwwHTMLSrc_script66.v.h"
};
static char _slotValue_wwwHTMLSrc67[] = "grey45";
static char _slotValue_wwwHTMLSrc68[] = "white";
static char _slotValue_wwwHTMLSrc69[] = "white";
/* END OF OBJ */

static char _slotValue_wwwHTMLSrc71[] = "wwwHTMLSrc.ctrl.dismiss";
static char _slotValue_wwwHTMLSrc72[] = "txtButton";
static char _slotValue_wwwHTMLSrc73[] = "wwwHTMLSrc.ctrl";
static char _slotValue_wwwHTMLSrc74[] = "normal";
static char _slotValue_wwwHTMLSrc75[] = "Dismiss";
static char _slotValue_wwwHTMLSrc76[] = {
#include "embeds/wwwHTMLSrc_script76.v.h"
};
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
static char _slotValue_wwwHotFolder3[] = {
#include "embeds/wwwHotFolder_script3.v.h"
};
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
static char _slotValue_wwwHotFolder22[] = {
#include "embeds/wwwHotFolder_script.v.h"
};
static char _slotValue_wwwHotFolder23[] = "70";
static char _slotValue_wwwHotFolder24[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder26[] = "wwwHotFolder.top.add";
static char _slotValue_wwwHotFolder27[] = "txtButton";
static char _slotValue_wwwHotFolder28[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder29[] = "Add";
static char _slotValue_wwwHotFolder30[] = "normal";
static char _slotValue_wwwHotFolder31[] = {
#include "embeds/wwwHotFolder_script31.v.h"
};
static char _slotValue_wwwHotFolder32[] = "70";
static char _slotValue_wwwHotFolder33[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder35[] = "wwwHotFolder.top.delete";
static char _slotValue_wwwHotFolder36[] = "txtButton";
static char _slotValue_wwwHotFolder37[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder38[] = "Delete";
static char _slotValue_wwwHotFolder39[] = "normal";
static char _slotValue_wwwHotFolder40[] = {
#include "embeds/wwwHotFolder_script40.v.h"
};
static char _slotValue_wwwHotFolder41[] = "70";
static char _slotValue_wwwHotFolder42[] = "2";
/* END OF OBJ */

static char _slotValue_wwwHotFolder44[] = "wwwHotFolder.top.edit";
static char _slotValue_wwwHotFolder45[] = "txtButton";
static char _slotValue_wwwHotFolder46[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder47[] = "Edit";
static char _slotValue_wwwHotFolder48[] = "normal";
static char _slotValue_wwwHotFolder49[] = {
#include "embeds/wwwHotFolder_script49.v.h"
};
static char _slotValue_wwwHotFolder50[] = "70";
/* END OF OBJ */

static char _slotValue_wwwHotFolder52[] = "wwwHotFolder.top.title";
static char _slotValue_wwwHotFolder53[] = "txtLabel";
static char _slotValue_wwwHotFolder54[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder55[] = "Hot List";
static char _slotValue_wwwHotFolder56[] = "bold";
static char _slotValue_wwwHotFolder57[] = {
#include "embeds/wwwHotFolder_script57.v.h"
};
/* END OF OBJ */

static char _slotValue_wwwHotFolder59[] = "wwwHotFolder.top.dismiss";
static char _slotValue_wwwHotFolder60[] = "txtButton";
static char _slotValue_wwwHotFolder61[] = "wwwHotFolder.top";
static char _slotValue_wwwHotFolder62[] = "Dismiss";
static char _slotValue_wwwHotFolder63[] = "normal";
static char _slotValue_wwwHotFolder64[] = {
#include "embeds/wwwHotFolder_script64.v.h"
};
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
static char _slotValue_wwwHotFolder84[] = {
#include "embeds/wwwHotFolder_script84.v.h"
};
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
static char _slotValue_wwwSecurity2[] = {
#include "embeds/wwwSecurity_script.v.h"
};
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
static char _slotValue_wwwSrc3[] = {
#include "embeds/wwwSrc_script3.v.h"
};
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
static char _slotValue_wwwSrc15[] = {
#include "embeds/wwwSrc_script.v.h"
};
static char _slotValue_wwwSrc16[] = "4";
static char _slotValue_wwwSrc17[] = "3";
/* END OF OBJ */

static char _slotValue_wwwSrc19[] = "wwwSrc.ctrl.ops";
static char _slotValue_wwwSrc20[] = "menu";
static char _slotValue_wwwSrc21[] = "wwwSrc.ctrl";
static char _slotValue_wwwSrc22[] = "File";
static char _slotValue_wwwSrc23[] = {
#include "embeds/wwwSrc_menuConfig.v.h"
};
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
static char _slotValue_wwwSrc42[] = {
#include "embeds/wwwSrc_script42.v.h"
};
static char _slotValue_wwwSrc43[] = "normal";
static char _slotValue_wwwSrc44[] = "100";
static char _slotValue_wwwSrc45[] = "2";
static char _slotValue_wwwSrc46[] = "2";
/* END OF OBJ */

static char _slotValue_wwwSrc48[] = "wwwSrc.top";
static char _slotValue_wwwSrc49[] = "txtDisp";
static char _slotValue_wwwSrc50[] = "wwwSrc";
static char _slotValue_wwwSrc51[] = "fixed";
static char _slotValue_wwwSrc52[] = {
#include "embeds/wwwSrc_script52.v.h"
};
static char _slotValue_wwwSrc53[] = "30";
static char _slotValue_wwwSrc54[] = "5";
/* END OF OBJ */

static char _slotValue_wwwSrc56[] = "wwwSrc.list";
static char _slotValue_wwwSrc57[] = "hpane";
static char _slotValue_wwwSrc58[] = "wwwSrc";
static char _slotValue_wwwSrc59[] = {
#include "embeds/wwwSrc_script59.v.h"
};
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
static char _slotValue_wwwSrc73[] = {
#include "embeds/wwwSrc_script73.v.h"
};
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
static char _slotValue_wwwURL2[] = {
#include "embeds/wwwURL_script2.v.h"
};
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
static char _slotValue_wwwURL18[] = {
#include "embeds/wwwURL_script.v.h"
};
static char _slotValue_wwwURL19[] = "5";
static char _slotValue_wwwURL20[] = "1";
static char _slotValue_wwwURL21[] = "fixed";
/* END OF OBJ */

static char _slotValue_wwwURL23[] = "hpane";
static char _slotValue_wwwURL24[] = "wwwURL.buttons";
static char _slotValue_wwwURL25[] = "wwwURL";
static char _slotValue_wwwURL26[] = "wwwURL.buttons.ok wwwURL.buttons.cancel wwwURL.buttons.cut wwwURL.buttons.clear";
static char _slotValue_wwwURL27[] = {
#include "embeds/wwwURL_script27.v.h"
};
static char _slotValue_wwwURL28[] = "25";
static char _slotValue_wwwURL29[] = "4";
static char _slotValue_wwwURL30[] = "3";
/* END OF OBJ */

static char _slotValue_wwwURL32[] = "txtButton";
static char _slotValue_wwwURL33[] = "Use Selected";
static char _slotValue_wwwURL34[] = "wwwURL.buttons.cut";
static char _slotValue_wwwURL35[] = "wwwURL.buttons";
static char _slotValue_wwwURL36[] = {
#include "embeds/wwwURL_script36.v.h"
};
static char _slotValue_wwwURL37[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL39[] = "txtButton";
static char _slotValue_wwwURL40[] = "Clear";
static char _slotValue_wwwURL41[] = "wwwURL.buttons.clear";
static char _slotValue_wwwURL42[] = "wwwURL.buttons";
static char _slotValue_wwwURL43[] = {
#include "embeds/wwwURL_script43.v.h"
};
static char _slotValue_wwwURL44[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL46[] = "txtButton";
static char _slotValue_wwwURL47[] = "OK";
static char _slotValue_wwwURL48[] = "wwwURL.buttons.ok";
static char _slotValue_wwwURL49[] = "wwwURL.buttons";
static char _slotValue_wwwURL50[] = {
#include "embeds/wwwURL_script50.v.h"
};
static char _slotValue_wwwURL51[] = "10";
/* END OF OBJ */

static char _slotValue_wwwURL53[] = "txtButton";
static char _slotValue_wwwURL54[] = "Cancel";
static char _slotValue_wwwURL55[] = "wwwURL.buttons.cancel";
static char _slotValue_wwwURL56[] = "wwwURL.buttons";
static char _slotValue_wwwURL57[] = {
#include "embeds/wwwURL_script57.v.h"
};
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
static char _slotValue_mvw3[] = {
#include "embeds/mvw_script3.v.h"
};
/* END OF OBJ */

static char _slotValue_mvw5[] = "generic";
static char _slotValue_mvw6[] = "www";
static char _slotValue_mvw7[] = {
#include "embeds/mvw_script7.v.h"
};
/* END OF OBJ */

static char _slotValue_mvw9[] = "vpane";
static char _slotValue_mvw10[] = "mvw.doc";
static char _slotValue_mvw11[] = "mvw";
static char _slotValue_mvw12[] = "mvw.doc.url mvw.doc.title mvw.doc.view";
static char _slotValue_mvw13[] = {
#include "embeds/mvw_script13.v.h"
};
/* END OF OBJ */

static char _slotValue_mvw15[] = "txtDisp";
static char _slotValue_mvw16[] = "mvw.doc.url";
static char _slotValue_mvw17[] = "mvw.doc";
static char _slotValue_mvw18[] = {
#include "embeds/mvw_script18.v.h"
};
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
static char _slotValue_mvw29[] = {
#include "embeds/mvw_script29.v.h"
};
static char _slotValue_mvw30[] = "45";
/* END OF OBJ */

static char _slotValue_mvw32[] = "hpane";
static char _slotValue_mvw33[] = "mvw.doc.tools.dyna";
static char _slotValue_mvw34[] = "mvwTools";
static char _slotValue_mvw35[] = {
#include "embeds/mvw_script35.v.h"
};
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
static char _slotValue_mvw47[] = {
#include "embeds/mvw_script47.v.h"
};
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
static char _slotValue_mvw56[] = {
#include "embeds/mvw_script56.v.h"
};
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
static char _slotValue_mvw65[] = {
#include "embeds/mvw_script65.v.h"
};
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
static char _slotValue_mvw74[] = {
#include "embeds/mvw_script74.v.h"
};
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
static char _slotValue_mvw83[] = {
#include "embeds/mvw_script83.v.h"
};
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
static char _slotValue_mvw92[] = {
#include "embeds/mvw_script92.v.h"
};
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
static char _slotValue_mvw111[] = {
#include "embeds/mvw_script.v.h"
};
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
static char _slotValue_mvw120[] = {
#include "embeds/mvw_script120.v.h"
};
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
static char _slotValue_mvw135[] = {
#include "embeds/mvw_script135.v.h"
};
/* END OF OBJ */

static char _slotValue_mvw137[] = "vpane";
static char _slotValue_mvw138[] = "mvw.doc.view";
static char _slotValue_mvw139[] = "mvw.doc.view.lbar";
static char _slotValue_mvw140[] = "mvw.doc.view.lbar.pane mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw141[] = {
#include "embeds/mvw_script141.v.h"
};
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
static char _slotValue_mvw154[] = {
#include "embeds/mvw_script154.v.h"
};
static char _slotValue_mvw155[] = "1";
static char _slotValue_mvw156[] = "20";
/* END OF OBJ */

static char _slotValue_mvw158[] = "txtButton";
static char _slotValue_mvw159[] = "mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw160[] = "mvw.doc.view.lbar.ctrls.up";
static char _slotValue_mvw161[] = "Up";
static char _slotValue_mvw162[] = {
#include "embeds/mvw_script162.v.h"
};
static char _slotValue_mvw163[] = "normal";
static char _slotValue_mvw164[] = "2";
/* END OF OBJ */

static char _slotValue_mvw166[] = "txtButton";
static char _slotValue_mvw167[] = "mvw.doc.view.lbar.ctrls";
static char _slotValue_mvw168[] = "mvw.doc.view.lbar.ctrls.down";
static char _slotValue_mvw169[] = "Down";
static char _slotValue_mvw170[] = {
#include "embeds/mvw_script170.v.h"
};
static char _slotValue_mvw171[] = "normal";
static char _slotValue_mvw172[] = "1";
/* END OF OBJ */

static char _slotValue_mvw174[] = "field";
static char _slotValue_mvw175[] = "mvw.doc.view.lbar.pane";
static char _slotValue_mvw176[] = "mvw.doc.view.lbar";
static char _slotValue_mvw177[] = "mvw.doc.view.lbar.sb";
static char _slotValue_mvw178[] = {
#include "embeds/mvw_script178.v.h"
};
static char _slotValue_mvw179[] = "100";
static char _slotValue_mvw180[] = "999";
static char _slotValue_mvw181[] = "2";
static char _slotValue_mvw182[] = "2";
static char _slotValue_mvw183[] = "6";
/* END OF OBJ */

static char _slotValue_mvw185[] = "field";
static char _slotValue_mvw186[] = "mvw.doc.view.pane";
static char _slotValue_mvw187[] = "mvw.doc.view";
static char _slotValue_mvw188[] = {
#include "embeds/mvw_script188.v.h"
};
static char _slotValue_mvw189[] = "595";
static char _slotValue_mvw190[] = "400";
/* END OF OBJ */

static char _slotValue_mvw192[] = "mvw.delegationHandler";
static char _slotValue_mvw193[] = "generic";
static char _slotValue_mvw194[] = {
#include "embeds/mvw_script194.v.h"
};
/* END OF OBJ */

static char _slotValue_mvw196[] = "generic";
static char _slotValue_mvw197[] = "www.mesg.tf";
static char _slotValue_mvw198[] = {
#include "embeds/mvw_script198.v.h"
};
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
static char _slotValue_mvwHistory2[] = {
#include "embeds/mvwHistory_script.v.h"
};
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
static char _slotValue_HTML__box3[] = {
#include "embeds/HTML__box_script3.v.h"
};
static char _slotValue_HTML__box4[] = "100";
static char _slotValue_HTML__box5[] = "8";
static char _slotValue_HTML__box6[] = "blue";
static char _slotValue_HTML__box7[] = "red";
/* END OF OBJ */

static char _slotValue_HTML__box9[] = "field";
static char _slotValue_HTML__box10[] = "HTML__txtBox";
static char _slotValue_HTML__box11[] = "HTML__txtBox.icon";
static char _slotValue_HTML__box12[] = {
#include "embeds/HTML__box_script.v.h"
};
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
static char _slotValue_HTML__doc2[] = {
#include "embeds/HTML__doc_script.v.h"
};
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
static char _slotValue_HTML__foldIcon2[] = {
#include "embeds/HTML__foldIcon_script.v.h"
};
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
static char _slotValue_HTML__txtBox3[] = {
#include "embeds/HTML__txtBox_script3.v.h"
};
static char _slotValue_HTML__txtBox4[] = "100";
static char _slotValue_HTML__txtBox5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox7[] = "txtDisp";
static char _slotValue_HTML__txtBox8[] = "HTML__txtBox";
static char _slotValue_HTML__txtBox9[] = "HTML__txtBox.txt";
static char _slotValue_HTML__txtBox10[] = {
#include "embeds/HTML__txtBox_script.v.h"
};
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
static char _slotValue_HTML__txtBox_alert3[] = {
#include "embeds/HTML__txtBox_alert_script3.v.h"
};
static char _slotValue_HTML__txtBox_alert4[] = "100";
static char _slotValue_HTML__txtBox_alert5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_alert7[] = "txtDisp";
static char _slotValue_HTML__txtBox_alert8[] = "HTML__txtBox_alert";
static char _slotValue_HTML__txtBox_alert9[] = "HTML__txtBox_alert.txt";
static char _slotValue_HTML__txtBox_alert10[] = {
#include "embeds/HTML__txtBox_alert_script.v.h"
};
static char _slotValue_HTML__txtBox_alert11[] = "50";
static char _slotValue_HTML__txtBox_alert12[] = "10";
static char _slotValue_HTML__txtBox_alert13[] = "10";
static char _slotValue_HTML__txtBox_alert14[] = "normal";
static char _slotValue_HTML__txtBox_alert15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_alert17[] = "XBM";
static char _slotValue_HTML__txtBox_alert18[] = "HTML__txtBox_alert";
static char _slotValue_HTML__txtBox_alert19[] = "HTML__txtBox_alert.icon";
static char _slotValue_HTML__txtBox_alert20[] = {
#include "embeds/HTML__txtBox_alert_script20.v.h"
};
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
static char _slotValue_HTML__txtBox_caution3[] = {
#include "embeds/HTML__txtBox_caution_script3.v.h"
};
static char _slotValue_HTML__txtBox_caution4[] = "100";
static char _slotValue_HTML__txtBox_caution5[] = "8";
static char _slotValue_HTML__txtBox_caution6[] = "6";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_caution8[] = "txtDisp";
static char _slotValue_HTML__txtBox_caution9[] = "HTML__txtBox_caution";
static char _slotValue_HTML__txtBox_caution10[] = "HTML__txtBox_caution.txt";
static char _slotValue_HTML__txtBox_caution11[] = {
#include "embeds/HTML__txtBox_caution_script.v.h"
};
static char _slotValue_HTML__txtBox_caution12[] = "50";
static char _slotValue_HTML__txtBox_caution13[] = "10";
static char _slotValue_HTML__txtBox_caution14[] = "10";
static char _slotValue_HTML__txtBox_caution15[] = "normal";
static char _slotValue_HTML__txtBox_caution16[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_caution18[] = "XBM";
static char _slotValue_HTML__txtBox_caution19[] = "HTML__txtBox_caution";
static char _slotValue_HTML__txtBox_caution20[] = "HTML__txtBox_caution.icon";
static char _slotValue_HTML__txtBox_caution21[] = {
#include "embeds/HTML__txtBox_caution_script21.v.h"
};
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
static char _slotValue_HTML__txtBox_error3[] = {
#include "embeds/HTML__txtBox_error_script3.v.h"
};
static char _slotValue_HTML__txtBox_error4[] = "100";
static char _slotValue_HTML__txtBox_error5[] = "8";
static char _slotValue_HTML__txtBox_error6[] = "6";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_error8[] = "txtDisp";
static char _slotValue_HTML__txtBox_error9[] = "HTML__txtBox_error";
static char _slotValue_HTML__txtBox_error10[] = "HTML__txtBox_error.txt";
static char _slotValue_HTML__txtBox_error11[] = {
#include "embeds/HTML__txtBox_error_script.v.h"
};
static char _slotValue_HTML__txtBox_error12[] = "50";
static char _slotValue_HTML__txtBox_error13[] = "10";
static char _slotValue_HTML__txtBox_error14[] = "10";
static char _slotValue_HTML__txtBox_error15[] = "normal";
static char _slotValue_HTML__txtBox_error16[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_error18[] = "XBM";
static char _slotValue_HTML__txtBox_error19[] = "HTML__txtBox_error";
static char _slotValue_HTML__txtBox_error20[] = "HTML__txtBox_error.icon";
static char _slotValue_HTML__txtBox_error21[] = {
#include "embeds/HTML__txtBox_error_script21.v.h"
};
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
static char _slotValue_HTML__txtBox_note3[] = {
#include "embeds/HTML__txtBox_note_script3.v.h"
};
static char _slotValue_HTML__txtBox_note4[] = "100";
static char _slotValue_HTML__txtBox_note5[] = "8";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_note7[] = "txtDisp";
static char _slotValue_HTML__txtBox_note8[] = "HTML__txtBox_note";
static char _slotValue_HTML__txtBox_note9[] = "HTML__txtBox_note.txt";
static char _slotValue_HTML__txtBox_note10[] = {
#include "embeds/HTML__txtBox_note_script.v.h"
};
static char _slotValue_HTML__txtBox_note11[] = "50";
static char _slotValue_HTML__txtBox_note12[] = "10";
static char _slotValue_HTML__txtBox_note13[] = "10";
static char _slotValue_HTML__txtBox_note14[] = "normal";
static char _slotValue_HTML__txtBox_note15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_note17[] = "XBM";
static char _slotValue_HTML__txtBox_note18[] = "HTML__txtBox_note";
static char _slotValue_HTML__txtBox_note19[] = "HTML__txtBox_note.icon";
static char _slotValue_HTML__txtBox_note20[] = {
#include "embeds/HTML__txtBox_note_script20.v.h"
};
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
static char _slotValue_HTML__txtBox_time3[] = {
#include "embeds/HTML__txtBox_time_script3.v.h"
};
static char _slotValue_HTML__txtBox_time4[] = "100";
static char _slotValue_HTML__txtBox_time5[] = "100";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_time7[] = "txtDisp";
static char _slotValue_HTML__txtBox_time8[] = "HTML__txtBox_time";
static char _slotValue_HTML__txtBox_time9[] = "HTML__txtBox_time.txt";
static char _slotValue_HTML__txtBox_time10[] = {
#include "embeds/HTML__txtBox_time_script.v.h"
};
static char _slotValue_HTML__txtBox_time11[] = "50";
static char _slotValue_HTML__txtBox_time12[] = "10";
static char _slotValue_HTML__txtBox_time13[] = "10";
static char _slotValue_HTML__txtBox_time14[] = "normal";
static char _slotValue_HTML__txtBox_time15[] = "1";
/* END OF OBJ */

static char _slotValue_HTML__txtBox_time17[] = "XBM";
static char _slotValue_HTML__txtBox_time18[] = "HTML__txtBox_time";
static char _slotValue_HTML__txtBox_time19[] = "HTML__txtBox_time.icon";
static char _slotValue_HTML__txtBox_time20[] = {
#include "embeds/HTML__txtBox_time_script20.v.h"
};
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
static char _slotValue_HTML_address2[] = {
#include "embeds/HTML_address_script.v.h"
};
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
static char _slotValue_HTML_attr2[] = {
#include "embeds/HTML_attr_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_attr[] = {
    {"class", _slotValue_HTML_attr0},
    {"name", _slotValue_HTML_attr1},
    {"script", _slotValue_HTML_attr2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_author0[] = "field";
static char _slotValue_HTML_author1[] = "HTML_author";
static char _slotValue_HTML_author2[] = {
#include "embeds/HTML_author_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_author[] = {
    {"class", _slotValue_HTML_author0},
    {"name", _slotValue_HTML_author1},
    {"script", _slotValue_HTML_author2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_base0[] = "field";
static char _slotValue_HTML_base1[] = "HTML_base";
static char _slotValue_HTML_base2[] = {
#include "embeds/HTML_base_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_base[] = {
    {"class", _slotValue_HTML_base0},
    {"name", _slotValue_HTML_base1},
    {"script", _slotValue_HTML_base2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_body0[] = "field";
static char _slotValue_HTML_body1[] = "HTML_body";
static char _slotValue_HTML_body2[] = {
#include "embeds/HTML_body_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_body[] = {
    {"class", _slotValue_HTML_body0},
    {"name", _slotValue_HTML_body1},
    {"script", _slotValue_HTML_body2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_box0[] = "field";
static char _slotValue_HTML_box1[] = "HTML_box";
static char _slotValue_HTML_box2[] = {
#include "embeds/HTML_box_script.v.h"
};
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
static char _slotValue_HTML_bulletItem3[] = {
#include "embeds/HTML_bulletItem_script.v.h"
};
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
static char _slotValue_HTML_caution2[] = {
#include "embeds/HTML_caution_script.v.h"
};
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
static char _slotValue_HTML_change2[] = {
#include "embeds/HTML_change_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_change[] = {
    {"class", _slotValue_HTML_change0},
    {"name", _slotValue_HTML_change1},
    {"script", _slotValue_HTML_change2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_changed0[] = "field";
static char _slotValue_HTML_changed1[] = "HTML_changed";
static char _slotValue_HTML_changed2[] = {
#include "embeds/HTML_changed_script.v.h"
};
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
static char _slotValue_HTML_cmd2[] = {
#include "embeds/HTML_cmd_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_cmd[] = {
    {"class", _slotValue_HTML_cmd0},
    {"name", _slotValue_HTML_cmd1},
    {"script", _slotValue_HTML_cmd2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_col20[] = "field";
static char _slotValue_HTML_col21[] = "HTML_col2";
static char _slotValue_HTML_col22[] = {
#include "embeds/HTML_col_script.v.h"
};
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
static char _slotValue_HTML_col32[] = {
#include "embeds/HTML_col_script32.v.h"
};
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
static char _slotValue_HTML_col42[] = {
#include "embeds/HTML_col_script42.v.h"
};
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
static char _slotValue_HTML_defList2[] = {
#include "embeds/HTML_defList_script.v.h"
};
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
static char _slotValue_HTML_defListBody2[] = {
#include "embeds/HTML_defListBody_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_defListBody[] = {
    {"class", _slotValue_HTML_defListBody0},
    {"name", _slotValue_HTML_defListBody1},
    {"script", _slotValue_HTML_defListBody2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_defListBody_p0[] = "txtDisp";
static char _slotValue_HTML_defListBody_p1[] = "HTML_defListBody_p";
static char _slotValue_HTML_defListBody_p2[] = {
#include "embeds/HTML_defListBody_p_script.v.h"
};
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
static char _slotValue_HTML_defListHead2[] = {
#include "embeds/HTML_defListHead_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_defListHead[] = {
    {"class", _slotValue_HTML_defListHead0},
    {"name", _slotValue_HTML_defListHead1},
    {"script", _slotValue_HTML_defListHead2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_defListHead_p0[] = "txtDisp";
static char _slotValue_HTML_defListHead_p1[] = "HTML_defListHead_p";
static char _slotValue_HTML_defListHead_p2[] = {
#include "embeds/HTML_defListHead_p_script.v.h"
};
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
static char _slotValue_HTML_example2[] = {
#include "embeds/HTML_example_script.v.h"
};
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
static char _slotValue_HTML_fail2[] = {
#include "embeds/HTML_fail_script.v.h"
};
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
static char _slotValue_HTML_figa2[] = {
#include "embeds/HTML_figa_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_figa[] = {
    {"class", _slotValue_HTML_figa0},
    {"name", _slotValue_HTML_figa1},
    {"script", _slotValue_HTML_figa2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figa_actual0[] = "glass";
static char _slotValue_HTML_figa_actual1[] = "HTML_figa_actual";
static char _slotValue_HTML_figa_actual2[] = {
#include "embeds/HTML_figa_actual_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_figa_actual[] = {
    {"class", _slotValue_HTML_figa_actual0},
    {"name", _slotValue_HTML_figa_actual1},
    {"script", _slotValue_HTML_figa_actual2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figcap0[] = "txtDisp";
static char _slotValue_HTML_figcap1[] = "HTML_figcap";
static char _slotValue_HTML_figcap2[] = {
#include "embeds/HTML_figcap_script.v.h"
};
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
static char _slotValue_HTML_figdata2[] = {
#include "embeds/HTML_figdata_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_figdata[] = {
    {"class", _slotValue_HTML_figdata0},
    {"name", _slotValue_HTML_figdata1},
    {"script", _slotValue_HTML_figdata2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_figure0[] = "field";
static char _slotValue_HTML_figure1[] = "HTML_figure";
static char _slotValue_HTML_figure2[] = {
#include "embeds/HTML_figure_script.v.h"
};
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
static char _slotValue_HTML_fld2[] = {
#include "embeds/HTML_fld_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_fld[] = {
    {"class", _slotValue_HTML_fld0},
    {"name", _slotValue_HTML_fld1},
    {"script", _slotValue_HTML_fld2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_footnote0[] = "HTML_footnote";
static char _slotValue_HTML_footnote1[] = "field";
static char _slotValue_HTML_footnote2[] = {
#include "embeds/HTML_footnote_script.v.h"
};
/* END OF OBJ */

static char _slotValue_HTML_footnote4[] = "HTML_footnote.ft";
static char _slotValue_HTML_footnote5[] = "XBM";
static char _slotValue_HTML_footnote6[] = {
#include "embeds/HTML_footnote_script6.v.h"
};
static char _slotValue_HTML_footnote7[] = {
#include "embeds/HTML_footnote_label.v.h"
};
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
static char _slotValue_HTML_form2[] = {
#include "embeds/HTML_form_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_form[] = {
    {"class", _slotValue_HTML_form0},
    {"name", _slotValue_HTML_form1},
    {"script", _slotValue_HTML_form2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_gif0[] = "GIF";
static char _slotValue_HTML_gif1[] = "HTML_gif";
static char _slotValue_HTML_gif2[] = {
#include "embeds/HTML_gif_script.v.h"
};
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
static char _slotValue_HTML_giff2[] = {
#include "embeds/HTML_giff_script.v.h"
};
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
static char _slotValue_HTML_head2[] = {
#include "embeds/HTML_head_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_head[] = {
    {"class", _slotValue_HTML_head0},
    {"name", _slotValue_HTML_head1},
    {"script", _slotValue_HTML_head2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_header_big0[] = "txtDisp";
static char _slotValue_HTML_header_big1[] = "HTML_header_big";
static char _slotValue_HTML_header_big2[] = {
#include "embeds/HTML_header_big_script.v.h"
};
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
static char _slotValue_HTML_header_medium2[] = {
#include "embeds/HTML_header_medium_script.v.h"
};
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
static char _slotValue_HTML_header_small2[] = {
#include "embeds/HTML_header_small_script.v.h"
};
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
static char _slotValue_HTML_hpane2[] = {
#include "embeds/HTML_hpane_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_hpane[] = {
    {"class", _slotValue_HTML_hpane0},
    {"name", _slotValue_HTML_hpane1},
    {"script", _slotValue_HTML_hpane2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_hr0[] = "field";
static char _slotValue_HTML_hr1[] = "HTML_hr";
static char _slotValue_HTML_hr2[] = {
#include "embeds/HTML_hr_script.v.h"
};
static char _slotValue_HTML_hr3[] = "1";
/* END OF FILE */

static SlotStruct objDesc_HTML_hr[] = {
    {"class", _slotValue_HTML_hr0},  {"name", _slotValue_HTML_hr1}, {"script", _slotValue_HTML_hr2},
    {"height", _slotValue_HTML_hr3}, {(char*)0, (char*)0},
};

static char _slotValue_HTML_ignore0[] = "field";
static char _slotValue_HTML_ignore1[] = "HTML_ignore";
static char _slotValue_HTML_ignore2[] = {
#include "embeds/HTML_ignore_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_ignore[] = {
    {"class", _slotValue_HTML_ignore0},
    {"name", _slotValue_HTML_ignore1},
    {"script", _slotValue_HTML_ignore2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_img0[] = "field";
static char _slotValue_HTML_img1[] = "HTML_img";
static char _slotValue_HTML_img2[] = {
#include "embeds/HTML_img_script.v.h"
};
/* END OF OBJ */

static char _slotValue_HTML_img4[] = "GIF";
static char _slotValue_HTML_img5[] = "HTML__img";
static char _slotValue_HTML_img6[] = {
#include "embeds/HTML_img_script6.v.h"
};
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
static char _slotValue_HTML_input2[] = {
#include "embeds/HTML_input_script.v.h"
};
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
static char _slotValue_HTML_input_check2[] = {
#include "embeds/HTML_input_check_script.v.h"
};
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
static char _slotValue_HTML_input_doodle4[] = {
#include "embeds/HTML_input_doodle_script4.v.h"
};
static char _slotValue_HTML_input_doodle5[] = "100";
static char _slotValue_HTML_input_doodle6[] = "100";
/* END OF OBJ */

static char _slotValue_HTML_input_doodle8[] = "txtButton";
static char _slotValue_HTML_input_doodle9[] = "HTML_input_doodle.ctrl";
static char _slotValue_HTML_input_doodle10[] = "HTML_input_doodle";
static char _slotValue_HTML_input_doodle11[] = {
#include "embeds/HTML_input_doodle_script.v.h"
};
static char _slotValue_HTML_input_doodle12[] = "Clear pad";
static char _slotValue_HTML_input_doodle13[] = "20";
static char _slotValue_HTML_input_doodle14[] = "100";
static char _slotValue_HTML_input_doodle15[] = "2";
static char _slotValue_HTML_input_doodle16[] = "2";
/* END OF OBJ */

static char _slotValue_HTML_input_doodle18[] = "field";
static char _slotValue_HTML_input_doodle19[] = "HTML_input_doodle.canvas";
static char _slotValue_HTML_input_doodle20[] = "HTML_input_doodle";
static char _slotValue_HTML_input_doodle21[] = {
#include "embeds/HTML_input_doodle_script21.v.h"
};
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
static char _slotValue_HTML_input_fail2[] = {
#include "embeds/HTML_input_fail_script.v.h"
};
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
static char _slotValue_HTML_input_hidden2[] = {
#include "embeds/HTML_input_hidden_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_input_hidden[] = {
    {"name", _slotValue_HTML_input_hidden0},
    {"class", _slotValue_HTML_input_hidden1},
    {"script", _slotValue_HTML_input_hidden2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_hook0[] = "field";
static char _slotValue_HTML_input_hook1[] = "HTML_input_hook";
static char _slotValue_HTML_input_hook2[] = {
#include "embeds/HTML_input_hook_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_input_hook[] = {
    {"class", _slotValue_HTML_input_hook0},
    {"name", _slotValue_HTML_input_hook1},
    {"script", _slotValue_HTML_input_hook2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_input_image0[] = "HTML_input_image";
static char _slotValue_HTML_input_image1[] = "GIF";
static char _slotValue_HTML_input_image2[] = {
#include "embeds/HTML_input_image_script.v.h"
};
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
static char _slotValue_HTML_input_int2[] = {
#include "embeds/HTML_input_int_script.v.h"
};
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
static char _slotValue_HTML_input_password2[] = {
#include "embeds/HTML_input_password_script.v.h"
};
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
static char _slotValue_HTML_input_percent3[] = {
#include "embeds/HTML_input_percent_script3.v.h"
};
static char _slotValue_HTML_input_percent4[] = "100";
static char _slotValue_HTML_input_percent5[] = "17";
/* END OF OBJ */

static char _slotValue_HTML_input_percent7[] = "HTML_input_percent";
static char _slotValue_HTML_input_percent8[] = "HTML_input_percent.v";
static char _slotValue_HTML_input_percent9[] = "txtEdit";
static char _slotValue_HTML_input_percent10[] = "HTML_input_percent.s";
static char _slotValue_HTML_input_percent11[] = {
#include "embeds/HTML_input_percent_script.v.h"
};
static char _slotValue_HTML_input_percent12[] = "30";
/* END OF OBJ */

static char _slotValue_HTML_input_percent14[] = "slider";
static char _slotValue_HTML_input_percent15[] = "HTML_input_percent";
static char _slotValue_HTML_input_percent16[] = "HTML_input_percent.s";
static char _slotValue_HTML_input_percent17[] = "HTML_input_percent.v";
static char _slotValue_HTML_input_percent18[] = {
#include "embeds/HTML_input_percent_script18.v.h"
};
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
static char _slotValue_HTML_input_radio3[] = {
#include "embeds/HTML_input_radio_script.v.h"
};
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
static char _slotValue_HTML_input_reset2[] = {
#include "embeds/HTML_input_reset_script.v.h"
};
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
static char _slotValue_HTML_input_str2[] = {
#include "embeds/HTML_input_str_script.v.h"
};
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
static char _slotValue_HTML_input_submit2[] = {
#include "embeds/HTML_input_submit_script.v.h"
};
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
static char _slotValue_HTML_input_text3[] = {
#include "embeds/HTML_input_text_script.v.h"
};
/* END OF OBJ */

static char _slotValue_HTML_input_text5[] = "HTML_input_text.tf";
static char _slotValue_HTML_input_text6[] = "txtEdit";
static char _slotValue_HTML_input_text7[] = "HTML_input_text.sb";
static char _slotValue_HTML_input_text8[] = {
#include "embeds/HTML_input_text_script8.v.h"
};
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
static char _slotValue_HTML_insert2[] = {
#include "embeds/HTML_insert_script.v.h"
};
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
static char _slotValue_HTML_insertTest2[] = {
#include "embeds/HTML_insertTest_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_insertTest[] = {
    {"class", _slotValue_HTML_insertTest0},
    {"name", _slotValue_HTML_insertTest1},
    {"script", _slotValue_HTML_insertTest2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_insertee0[] = "field";
static char _slotValue_HTML_insertee1[] = "HTML_insertee";
static char _slotValue_HTML_insertee2[] = {
#include "embeds/HTML_insertee_script.v.h"
};
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
static char _slotValue_HTML_isIndex3[] = {
#include "embeds/HTML_isIndex_script3.v.h"
};
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
static char _slotValue_HTML_isIndex14[] = {
#include "embeds/HTML_isIndex_script.v.h"
};
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
static char _slotValue_HTML_isIndex25[] = {
#include "embeds/HTML_isIndex_script25.v.h"
};
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
static char _slotValue_HTML_ititle2[] = {
#include "embeds/HTML_ititle_script.v.h"
};
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
static char _slotValue_HTML_label2[] = {
#include "embeds/HTML_label_script.v.h"
};
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
static char _slotValue_HTML_link2[] = {
#include "embeds/HTML_link_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_link[] = {
    {"class", _slotValue_HTML_link0},
    {"name", _slotValue_HTML_link1},
    {"script", _slotValue_HTML_link2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_list0[] = "field";
static char _slotValue_HTML_list1[] = "HTML_list";
static char _slotValue_HTML_list2[] = {
#include "embeds/HTML_list_script.v.h"
};
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
static char _slotValue_HTML_listBullet2[] = {
#include "embeds/HTML_listBullet_script.v.h"
};
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
static char _slotValue_HTML_listC2[] = {
#include "embeds/HTML_listC_script.v.h"
};
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
static char _slotValue_HTML_listItem2[] = {
#include "embeds/HTML_listItem_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_listItem[] = {
    {"class", _slotValue_HTML_listItem0},
    {"name", _slotValue_HTML_listItem1},
    {"script", _slotValue_HTML_listItem2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_listMenu0[] = "txtDisp";
static char _slotValue_HTML_listMenu1[] = "HTML_listMenu";
static char _slotValue_HTML_listMenu2[] = {
#include "embeds/HTML_listMenu_script.v.h"
};
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
static char _slotValue_HTML_listNum2[] = {
#include "embeds/HTML_listNum_script.v.h"
};
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
static char _slotValue_HTML_listNum_oval2[] = {
#include "embeds/HTML_listNum_oval_script.v.h"
};
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
static char _slotValue_HTML_listNumbered2[] = {
#include "embeds/HTML_listNumbered_script.v.h"
};
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
static char _slotValue_HTML_listNumberedC2[] = {
#include "embeds/HTML_listNumberedC_script.v.h"
};
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
static char _slotValue_HTML_listSep2[] = {
#include "embeds/HTML_listSep_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_listSep[] = {
    {"class", _slotValue_HTML_listSep0},
    {"name", _slotValue_HTML_listSep1},
    {"script", _slotValue_HTML_listSep2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_listTxt0[] = "txtDisp";
static char _slotValue_HTML_listTxt1[] = "HTML_listTxt";
static char _slotValue_HTML_listTxt2[] = {
#include "embeds/HTML_listTxt_script.v.h"
};
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
static char _slotValue_HTML_listing2[] = {
#include "embeds/HTML_listing_script.v.h"
};
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
static char _slotValue_HTML_math2[] = {
#include "embeds/HTML_math_script.v.h"
};
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
static char _slotValue_HTML_menu2[] = {
#include "embeds/HTML_menu_script.v.h"
};
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
static char _slotValue_HTML_menuSep2[] = {
#include "embeds/HTML_menuSep_script.v.h"
};
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
static char _slotValue_HTML_mh2[] = {
#include "embeds/HTML_mh_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_mh[] = {
    {"class", _slotValue_HTML_mh0},
    {"name", _slotValue_HTML_mh1},
    {"script", _slotValue_HTML_mh2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_nextID0[] = "field";
static char _slotValue_HTML_nextID1[] = "HTML_nextID";
static char _slotValue_HTML_nextID2[] = {
#include "embeds/HTML_nextID_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_nextID[] = {
    {"class", _slotValue_HTML_nextID0},
    {"name", _slotValue_HTML_nextID1},
    {"script", _slotValue_HTML_nextID2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_option0[] = "field";
static char _slotValue_HTML_option1[] = "HTML_option";
static char _slotValue_HTML_option2[] = {
#include "embeds/HTML_option_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_option[] = {
    {"class", _slotValue_HTML_option0},
    {"name", _slotValue_HTML_option1},
    {"script", _slotValue_HTML_option2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_over0[] = "field";
static char _slotValue_HTML_over1[] = "HTML_over";
static char _slotValue_HTML_over2[] = {
#include "embeds/HTML_over_script.v.h"
};
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
static char _slotValue_HTML_plain2[] = {
#include "embeds/HTML_plain_script.v.h"
};
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
static char _slotValue_HTML_plaintext2[] = {
#include "embeds/HTML_plaintext_script.v.h"
};
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
static char _slotValue_HTML_pre2[] = {
#include "embeds/HTML_pre_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_pre[] = {
    {"class", _slotValue_HTML_pre0},
    {"name", _slotValue_HTML_pre1},
    {"script", _slotValue_HTML_pre2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_preTxt0[] = "txtDisp";
static char _slotValue_HTML_preTxt1[] = "HTML_preTxt";
static char _slotValue_HTML_preTxt2[] = {
#include "embeds/HTML_preTxt_script.v.h"
};
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
static char _slotValue_HTML_psep2[] = {
#include "embeds/HTML_psep_script.v.h"
};
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
static char _slotValue_HTML_psf2[] = {
#include "embeds/HTML_psf_script.v.h"
};
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
static char _slotValue_HTML_quote2[] = {
#include "embeds/HTML_quote_script.v.h"
};
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
static char _slotValue_HTML_script2[] = {
#include "embeds/HTML_script_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_script[] = {
    {"class", _slotValue_HTML_script0},
    {"name", _slotValue_HTML_script1},
    {"script", _slotValue_HTML_script2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_select0[] = "HTML_select";
static char _slotValue_HTML_select1[] = "menu";
static char _slotValue_HTML_select2[] = {
#include "embeds/HTML_select_script.v.h"
};
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
static char _slotValue_HTML_sub2[] = {
#include "embeds/HTML_sub_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_sub[] = {
    {"class", _slotValue_HTML_sub0},
    {"name", _slotValue_HTML_sub1},
    {"script", _slotValue_HTML_sub2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_sup0[] = "field";
static char _slotValue_HTML_sup1[] = "HTML_sup";
static char _slotValue_HTML_sup2[] = {
#include "embeds/HTML_sup_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_sup[] = {
    {"class", _slotValue_HTML_sup0},
    {"name", _slotValue_HTML_sup1},
    {"script", _slotValue_HTML_sup2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_table0[] = "field";
static char _slotValue_HTML_table1[] = "HTML_table";
static char _slotValue_HTML_table2[] = {
#include "embeds/HTML_table_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_table[] = {
    {"class", _slotValue_HTML_table0},
    {"name", _slotValue_HTML_table1},
    {"script", _slotValue_HTML_table2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tableCap0[] = "txtLabel";
static char _slotValue_HTML_tableCap1[] = "HTML_tableCap";
static char _slotValue_HTML_tableCap2[] = {
#include "embeds/HTML_tableCap_script.v.h"
};
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
static char _slotValue_HTML_tableVPane2[] = {
#include "embeds/HTML_tableVPane_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_tableVPane[] = {
    {"class", _slotValue_HTML_tableVPane0},
    {"name", _slotValue_HTML_tableVPane1},
    {"script", _slotValue_HTML_tableVPane2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tb0[] = "field";
static char _slotValue_HTML_tb1[] = "HTML_tb";
static char _slotValue_HTML_tb2[] = {
#include "embeds/HTML_tb_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_tb[] = {
    {"class", _slotValue_HTML_tb0},
    {"name", _slotValue_HTML_tb1},
    {"script", _slotValue_HTML_tb2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tcap0[] = "field";
static char _slotValue_HTML_tcap1[] = "HTML_tcap";
static char _slotValue_HTML_tcap2[] = {
#include "embeds/HTML_tcap_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_tcap[] = {
    {"class", _slotValue_HTML_tcap0},
    {"name", _slotValue_HTML_tcap1},
    {"script", _slotValue_HTML_tcap2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_td0[] = "field";
static char _slotValue_HTML_td1[] = "HTML_td";
static char _slotValue_HTML_td2[] = {
#include "embeds/HTML_td_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_td[] = {
    {"class", _slotValue_HTML_td0},
    {"name", _slotValue_HTML_td1},
    {"script", _slotValue_HTML_td2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_textarea0[] = "HTML_textarea";
static char _slotValue_HTML_textarea1[] = "field";
static char _slotValue_HTML_textarea2[] = {
#include "embeds/HTML_textarea_script2.v.h"
};
/* END OF OBJ */

static char _slotValue_HTML_textarea4[] = "HTML__textarea";
static char _slotValue_HTML_textarea5[] = "HTML__textarea.tf HTML__textarea.sb";
static char _slotValue_HTML_textarea6[] = "hpane";
static char _slotValue_HTML_textarea7[] = {
#include "embeds/HTML_textarea_script7.v.h"
};
static char _slotValue_HTML_textarea8[] = "300";
static char _slotValue_HTML_textarea9[] = "150";
/* END OF OBJ */

static char _slotValue_HTML_textarea11[] = "txtEdit";
static char _slotValue_HTML_textarea12[] = "HTML__textarea";
static char _slotValue_HTML_textarea13[] = "HTML__textarea.tf";
static char _slotValue_HTML_textarea14[] = "HTML__textarea.sb";
static char _slotValue_HTML_textarea15[] = {
#include "embeds/HTML_textarea_script.v.h"
};
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
static char _slotValue_HTML_th2[] = {
#include "embeds/HTML_th_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_th[] = {
    {"class", _slotValue_HTML_th0},
    {"name", _slotValue_HTML_th1},
    {"script", _slotValue_HTML_th2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_title0[] = "field";
static char _slotValue_HTML_title1[] = "HTML_title";
static char _slotValue_HTML_title2[] = {
#include "embeds/HTML_title_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_title[] = {
    {"class", _slotValue_HTML_title0},
    {"name", _slotValue_HTML_title1},
    {"script", _slotValue_HTML_title2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_tr0[] = "field";
static char _slotValue_HTML_tr1[] = "HTML_tr";
static char _slotValue_HTML_tr2[] = {
#include "embeds/HTML_tr_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_tr[] = {
    {"class", _slotValue_HTML_tr0},
    {"name", _slotValue_HTML_tr1},
    {"script", _slotValue_HTML_tr2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txt0[] = "txtDisp";
static char _slotValue_HTML_txt1[] = "HTML_txt";
static char _slotValue_HTML_txt2[] = {
#include "embeds/HTML_txt_script.v.h"
};
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
static char _slotValue_HTML_txtAnchor2[] = {
#include "embeds/HTML_txtAnchor_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtAnchor[] = {
    {"class", _slotValue_HTML_txtAnchor0},
    {"name", _slotValue_HTML_txtAnchor1},
    {"script", _slotValue_HTML_txtAnchor2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtBold0[] = "field";
static char _slotValue_HTML_txtBold1[] = "HTML_txtBold";
static char _slotValue_HTML_txtBold2[] = {
#include "embeds/HTML_txtBold_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtBold[] = {
    {"class", _slotValue_HTML_txtBold0},
    {"name", _slotValue_HTML_txtBold1},
    {"script", _slotValue_HTML_txtBold2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtBullet0[] = "field";
static char _slotValue_HTML_txtBullet1[] = "HTML_txtBullet";
static char _slotValue_HTML_txtBullet2[] = {
#include "embeds/HTML_txtBullet_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtBullet[] = {
    {"class", _slotValue_HTML_txtBullet0},
    {"name", _slotValue_HTML_txtBullet1},
    {"script", _slotValue_HTML_txtBullet2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtCommand0[] = "field";
static char _slotValue_HTML_txtCommand1[] = "HTML_txtCommand";
static char _slotValue_HTML_txtCommand2[] = {
#include "embeds/HTML_txtCommand_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtCommand[] = {
    {"class", _slotValue_HTML_txtCommand0},
    {"name", _slotValue_HTML_txtCommand1},
    {"script", _slotValue_HTML_txtCommand2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtDD0[] = "field";
static char _slotValue_HTML_txtDD1[] = "HTML_txtDD";
static char _slotValue_HTML_txtDD2[] = {
#include "embeds/HTML_txtDD_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtDD[] = {
    {"class", _slotValue_HTML_txtDD0},
    {"name", _slotValue_HTML_txtDD1},
    {"script", _slotValue_HTML_txtDD2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtDT0[] = "field";
static char _slotValue_HTML_txtDT1[] = "HTML_txtDT";
static char _slotValue_HTML_txtDT2[] = {
#include "embeds/HTML_txtDT_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtDT[] = {
    {"class", _slotValue_HTML_txtDT0},
    {"name", _slotValue_HTML_txtDT1},
    {"script", _slotValue_HTML_txtDT2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtEmphasis0[] = "field";
static char _slotValue_HTML_txtEmphasis1[] = "HTML_txtEmphasis";
static char _slotValue_HTML_txtEmphasis2[] = {
#include "embeds/HTML_txtEmphasis_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtEmphasis[] = {
    {"class", _slotValue_HTML_txtEmphasis0},
    {"name", _slotValue_HTML_txtEmphasis1},
    {"script", _slotValue_HTML_txtEmphasis2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtItalic0[] = "field";
static char _slotValue_HTML_txtItalic1[] = "HTML_txtItalic";
static char _slotValue_HTML_txtItalic2[] = {
#include "embeds/HTML_txtItalic_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtItalic[] = {
    {"class", _slotValue_HTML_txtItalic0},
    {"name", _slotValue_HTML_txtItalic1},
    {"script", _slotValue_HTML_txtItalic2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtList0[] = "XBM";
static char _slotValue_HTML_txtList1[] = "HTML_txtList";
static char _slotValue_HTML_txtList2[] = {
#include "embeds/HTML_txtList_script.v.h"
};
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
static char _slotValue_HTML_txtListItem2[] = {
#include "embeds/HTML_txtListItem_script.v.h"
};
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
static char _slotValue_HTML_txtProtrude2[] = {
#include "embeds/HTML_txtProtrude_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtProtrude[] = {
    {"class", _slotValue_HTML_txtProtrude0},
    {"name", _slotValue_HTML_txtProtrude1},
    {"script", _slotValue_HTML_txtProtrude2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_txtUnderline0[] = "field";
static char _slotValue_HTML_txtUnderline1[] = "HTML_txtUnderline";
static char _slotValue_HTML_txtUnderline2[] = {
#include "embeds/HTML_txtUnderline_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_txtUnderline[] = {
    {"class", _slotValue_HTML_txtUnderline0},
    {"name", _slotValue_HTML_txtUnderline1},
    {"script", _slotValue_HTML_txtUnderline2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vinsert0[] = "field";
static char _slotValue_HTML_vinsert1[] = "HTML_vinsert";
static char _slotValue_HTML_vinsert2[] = {
#include "embeds/HTML_vinsert_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_vinsert[] = {
    {"class", _slotValue_HTML_vinsert0},
    {"name", _slotValue_HTML_vinsert1},
    {"script", _slotValue_HTML_vinsert2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vobj0[] = "field";
static char _slotValue_HTML_vobj1[] = "HTML_vobj";
static char _slotValue_HTML_vobj2[] = {
#include "embeds/HTML_vobj_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_vobj[] = {
    {"class", _slotValue_HTML_vobj0},
    {"name", _slotValue_HTML_vobj1},
    {"script", _slotValue_HTML_vobj2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vobjf0[] = "field";
static char _slotValue_HTML_vobjf1[] = "HTML_vobjf";
static char _slotValue_HTML_vobjf2[] = {
#include "embeds/HTML_vobjf_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_vobjf[] = {
    {"class", _slotValue_HTML_vobjf0},
    {"name", _slotValue_HTML_vobjf1},
    {"script", _slotValue_HTML_vobjf2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_vr0[] = "field";
static char _slotValue_HTML_vr1[] = "HTML_vr";
static char _slotValue_HTML_vr2[] = {
#include "embeds/HTML_vr_script.v.h"
};
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
static char _slotValue_HTML_vview2[] = {
#include "embeds/HTML_vview_script.v.h"
};
/* END OF FILE */

static SlotStruct objDesc_HTML_vview[] = {
    {"class", _slotValue_HTML_vview0},
    {"name", _slotValue_HTML_vview1},
    {"script", _slotValue_HTML_vview2},
    {(char*)0, (char*)0},
};

static char _slotValue_HTML_xbm0[] = "XBM";
static char _slotValue_HTML_xbm1[] = "HTML_xbm";
static char _slotValue_HTML_xbm2[] = {
#include "embeds/HTML_xbm_script.v.h"
};
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
static char _slotValue_HTML_xbmf2[] = {
#include "embeds/HTML_xbmf_script.v.h"
};
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
static char _slotValue_HTML_xpm2[] = {
#include "embeds/HTML_xpm_script.v.h"
};
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
static char _slotValue_HTML_xpmf2[] = {
#include "embeds/HTML_xpmf_script.v.h"
};
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
static char _slotValue_invokeExample3[] = {
#include "embeds/invokeExample_script3.v.h"
};
static char _slotValue_invokeExample4[] = "600";
static char _slotValue_invokeExample5[] = "400";
static char _slotValue_invokeExample6[] = "invokeExample.top invokeExample.list invokeExample.ctrl";
/* END OF OBJ */

static char _slotValue_invokeExample8[] = "invokeExample.top";
static char _slotValue_invokeExample9[] = "txtLabel";
static char _slotValue_invokeExample10[] = "invokeExample";
static char _slotValue_invokeExample11[] = "normal";
static char _slotValue_invokeExample12[] = {
#include "embeds/invokeExample_script.v.h"
};
static char _slotValue_invokeExample13[] = "Finger Info Viewer";
static char _slotValue_invokeExample14[] = "40";
static char _slotValue_invokeExample15[] = "bold_largest";
/* END OF OBJ */

static char _slotValue_invokeExample17[] = "invokeExample.list";
static char _slotValue_invokeExample18[] = "hpane";
static char _slotValue_invokeExample19[] = "invokeExample";
static char _slotValue_invokeExample20[] = {
#include "embeds/invokeExample_script20.v.h"
};
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
static char _slotValue_invokeExample32[] = {
#include "embeds/invokeExample_script32.v.h"
};
static char _slotValue_invokeExample33[] = "invokeExample.list.sb";
static char _slotValue_invokeExample34[] = "fixed";
static char _slotValue_invokeExample35[] = "1";
/* END OF OBJ */

static char _slotValue_invokeExample37[] = "invokeExample.ctrl";
static char _slotValue_invokeExample38[] = "hpane";
static char _slotValue_invokeExample39[] = "invokeExample";
static char _slotValue_invokeExample40[] = "20";
static char _slotValue_invokeExample41[] = "invokeExample.ctrl.dismiss";
static char _slotValue_invokeExample42[] = {
#include "embeds/invokeExample_script42.v.h"
};
/* END OF OBJ */

static char _slotValue_invokeExample44[] = "invokeExample.ctrl.finger";
static char _slotValue_invokeExample45[] = "txtButton";
static char _slotValue_invokeExample46[] = "invokeExample.ctrl";
static char _slotValue_invokeExample47[] = "normal";
static char _slotValue_invokeExample48[] = "Finger nasanews@space.mit.edu";
static char _slotValue_invokeExample49[] = {
#include "embeds/invokeExample_script49.v.h"
};
/* END OF OBJ */

static char _slotValue_invokeExample51[] = "invokeExample.ctrl.dismiss";
static char _slotValue_invokeExample52[] = "txtButton";
static char _slotValue_invokeExample53[] = "invokeExample.ctrl";
static char _slotValue_invokeExample54[] = "normal";
static char _slotValue_invokeExample55[] = "Dismiss";
static char _slotValue_invokeExample56[] = {
#include "embeds/invokeExample_script56.v.h"
};
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
static char _slotValue_invokeFinger4[] = {
#include "embeds/invokeFinger_script.v.h"
};
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
static char _slotValue_invokeGopher4[] = {
#include "embeds/invokeGopher_script.v.h"
};
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
static char _slotValue_invokeTelnet4[] = {
#include "embeds/invokeTelnet_script.v.h"
};
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
static char _slotValue_invokeWAIS3[] = {
#include "embeds/invokeWAIS_script.v.h"
};
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
                               (SlotStruct*)0};
