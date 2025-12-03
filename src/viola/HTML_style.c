/*
 * ViolaWWW HTML Stylesheet Configuration
 * =======================================
 *
 * Format: Each line defines styling for one HTML tag (11 fields total)
 *
 * TagName  ProcessingObject  inline notify flush1 flush2 hpane  top bottom left right
 * -------  ----------------  ------ ------ ------ ------ -----  --- ------ ---- -----
 *
 * Field descriptions:
 * -------------------
 * 1. TagName          - HTML tag name (e.g. P, H1, SCRIPT)
 * 2. ProcessingObject - Viola class for rendering (e.g. HTML_txt, HTML_ignore)
 * 3. inline           - 0=block element (breaks line), 1=inline element (flows with text)
 * 4. notifyOnCreation - 0=no, 1=notify when object created
 * 5. flushAlways      - 0=no, 1=flush text buffer before processing
 * 6. flushOnSubTag    - 0=no, 1=flush buffer when encountering nested tag
 * 7. hpane            - 0=no, 1=use horizontal pane layout
 * 8. top              - Top margin/padding in pixels
 * 9. bottom           - Bottom margin/padding in pixels
 * 10. left            - Left margin/padding in pixels
 * 11. right           - Right margin/padding in pixels
 *
 * Examples:
 * ---------
 * P       HTML_txt        0 0 0 1 0  3 3 1 1  - Paragraph: block, flush on subtag, margins 3/3/1/1
 * A       HTML_txtAnchor  1 0 0 1 0  0 0 0 0  - Anchor: inline, flush on subtag, no margins
 * H1      HTML_header_big 0 0 0 1 0  7 5 0 2  - Heading: block, margins 7/5/0/2
 * SCRIPT  HTML_ignore     1 0 0 0 0  0 0 0 0  - Script: inline, ignored content
 */

char* HTML_stylesheet_str = "\
P 		HTML_txt 		0 0 0 1 0		3 3 1 1\n\
A 		HTML_txtAnchor	 	1 0 0 1 0		0 0 0 0\n\
ATTR 		HTML_attr	 	1 0 0 1 0		0 0 0 0\n\
AUTHOR 		HTML_author	 	0 0 0 0 0		0 0 0 0\n\
B 		HTML_txtBold	 	1 0 0 0 0		0 0 0 0\n\
BR 		HTML_txt	 	0 0 0 1 0		0 0 0 0\n\
BOLD 		HTML_txtBold	 	1 0 0 0 0		0 0 0 0\n\
STRONG		HTML_txtBold	 	1 0 0 0 0		0 0 0 0\n\
EM 		HTML_txtEmphasis 	1 0 0 0 0		0 0 0 0\n\
EMPH		HTML_txtEmphasis 	1 0 0 0 0		0 0 0 0\n\
I 		HTML_txtItalic	 	1 0 0 0 0		0 0 0 0\n\
ITALIC 		HTML_txtItalic	 	1 0 0 0 0		0 0 0 0\n\
TT 		HTML_txtItalic	 	1 0 0 0 0		0 0 0 0\n\
CODE 		HTML_txtCommand 	1 0 0 0 0		0 0 0 0\n\
KEY 		HTML_txtCommand 	1 0 0 0 0		0 0 0 0\n\
KBD 		HTML_txtCommand 	1 0 0 0 0		0 0 0 0\n\
CMD 		HTML_txtCommand 	1 0 0 0 0		0 0 0 0\n\
VAR 		HTML_txtCommand 	1 0 0 0 0		0 0 0 0\n\
DFN 		HTML_txtItalic	 	1 0 0 0 0		0 0 0 0\n\
CITE 		HTML_txtItalic	 	1 0 0 0 0		0 0 0 0\n\
SAMP 		HTML_txtCommand	 	1 0 0 0 0		0 0 0 0\n\
U 		HTML_txtUnderline 	1 0 0 0 0		0 0 0 0\n\
UNDER 		HTML_txtUnderline 	1 0 0 0 0		0 0 0 0\n\
HPANE	 	HTML_hpane 		0 0 0 1 1		0 0 0 0\n\
H1 		HTML_header_big 	0 0 0 1 0		7 5 0 2\n\
H2 		HTML_header_medium 	0 0 0 1 0		7 5 0 2\n\
H3 		HTML_header_small 	0 0 0 1 0		5 5 0 2\n\
H4 		HTML_header_small 	0 0 0 1 0		5 5 0 2\n\
H5 		HTML_header_small 	0 0 0 1 0		5 5 0 2\n\
H6 		HTML_header_small 	0 0 0 1 0		5 5 0 2\n\
H7 		HTML_header_small 	0 0 0 1 0		5 5 0 2\n\
XMP		HTML_example 		0 0 0 1 0		3 3 0 2\n\
SCREEN	 	HTML_plain 		0 0 0 1 0		3 3 0 2\n\
LIT	 	HTML_listing 		0 0 0 1 0		3 3 0 2\n\
LISTING 	HTML_listing 		0 0 0 1 0		0 0 0 2\n\
TITLE 		HTML_title 		0 0 0 0 0		0 0 0 0\n\
LI 		HTML_listSep	 	0 0 0 1 0		0 2 0 0\n\
P_in_listSep	HTML_listTxt	 	0 0 0 1 0		0 3 20 2\n\
OL		HTML_listNumbered	0 0 0 1 0		3 3 0 2\n\
OLC		HTML_listNumberedC	0 0 0 1 0		3 3 0 2\n\
UL 		HTML_list  		0 0 0 1 0		2 3 0 2\n\
ULC 		HTML_listC  		0 0 0 1 0		2 3 0 2\n\
DL 		HTML_fld		0 0 0 1 0		2 3 0 2\n\
DT 		HTML_txtDT		0 0 0 1 0		0 1 0 2\n\
DD 		HTML_txtDD		0 0 0 1 0		0 1 50 0\n\
ADDRESS		HTML_address 		0 0 0 1 0		10 10 100 0\n\
ISINDEX		HTML_isIndex 		0 0 0 1 0		3 7 0 0\n\
HEAD		HTML_head 		0 0 0 0 0		0 0 0 0\n\
BODY		HTML_body 		0 0 0 1 0		0 10 1 1\n\
HTML 		HTML_fld 		0 0 0 1 0		0 10 0 1\n\
MENU		HTML_menu 		0 0 0 1 0		3 7 0 2\n\
META		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
NEXTID		HTML_nextID 		0 0 0 0 0		0 0 0 2\n\
PRE		HTML_pre 		0 0 0 1 0		3 7 0 2\n\
EXAMPLE		HTML_example 		0 0 0 1 0		3 7 0 2\n\
PLAIN		HTML_plain 		0 0 0 1 0		3 7 0 2\n\
BLOCKQUOTE	HTML_fld		0 0 0 1 0		3 4 20 20\n\
IMG		HTML_img 		1 0 0 0 0		3 7 0 0\n\
IMAGE		HTML_img 		1 0 0 0 0		3 7 0 0\n\
INSERT		HTML_insert		0 0 0 1 0		3 7 1 2\n\
COMMENT		HTML_fld 		0 0 0 1 0		3 7 0 2\n\
DLC		HTML_fld 		0 0 0 1 0		3 7 0 2\n\
PLAINTEXT	HTML_plain 		0 0 0 1 0		3 7 0 2\n\
QUOTE		HTML_fld 		0 0 0 1 0		3 7 0 2\n\
FIG		HTML_figure 		0 0 0 1 0		5 3 0 2\n\
FIGURE		HTML_figure 		0 0 0 1 0		5 3 0 2\n\
FIGA		HTML_figa 		1 0 0 0 0		0 0 0 0\n\
FIGCAP 		HTML_fld 		0 0 0 1 0		0 3 0 0\n\
DIR 		HTML_col2 		0 0 0 1 0		3 7 0 0\n\
_HTML 		HTML__doc 		0 0 0 0 0		1 0 1 1\n\
SECTION 	HTML_fld 		0 0 0 0 0		0 10 0 2\n\
TABLE		HTML_table		0 0 0 1 0		0 10 0 2\n\
TBL		HTML_table		0 0 0 1 0		0 10 0 2\n\
TCAP		HTML_tcap		0 0 0 0 0		0 0 0 0\n\
TH		HTML_th			0 0 0 0 0		0 0 0 0\n\
TD		HTML_td			0 0 0 0 0		0 0 0 0\n\
TR		HTML_tr			0 0 0 0 0		0 0 0 0\n\
TB		HTML_tb			0 0 0 0 0		2 2 0 0\n\
VOBJ 		HTML_vobj	 	1 0 0 1 0		0 0 0 0\n\
VOBJF 		HTML_vobjf 		0 0 0 1 0		3 10 0 0\n\
HR 		HTML_hr 		0 0 0 1 0		7 5 0 0\n\
VR 		HTML_vr 		0 0 0 1 0		0 0 0 0\n\
FORM		HTML_form		0 0 0 1 0		0 10 0 2\n\
FOOTNOTE	HTML_footnote		1 0 0 0 0		0 10 0 2\n\
INPUT		HTML_input		1 0 0 0 0		0 10 2 2\n\
TEXTAREA	HTML_textarea		1 0 0 0 0		0 10 2 2\n\
CAUTION		HTML_caution 		0 0 0 1 0		2 10 2 2\n\
MH		HTML_mh			0 0 0 0 0		0 0 0 0\n\
LINK		HTML_link		1 0 0 0 0		0 3 0 0\n\
SELECT		HTML_select		1 0 0 0 0		0 10 2 2\n\
OPTION		HTML_option		1 0 0 0 0		0 0 2 2\n\
PRE 		HTML_listing 		0 0 0 1 0		3 7 0 2\n\
COL2 		HTML_col2 		0 0 0 1 0		1 1 1 2\n\
COL3 		HTML_col3 		0 0 0 1 0		1 1 1 2\n\
COL4 		HTML_col4 		0 0 0 1 0		1 1 1 2\n\
FIGDATA		HTML_figdata 		1 0 0 1 0		0 1 0 0\n\
XBM		HTML_xbm 		0 0 0 1 0		0 0 0 0\n\
XPM		HTML_xpm 		0 0 0 1 0		0 0 0 0\n\
L 		HTML_txt 		0 0 0 1 0		3 7 1 2\n\
AUTHOR		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
ENTRY		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
VINSERT		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
VSCRIPT		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
VVIEW		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
GROUP		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
SECURITY	HTML_security		1 0 0 0 0		0 0 0 0\n\
MATH		HTML_math		0 0 0 1 0		0 10 0 0\n\
OVER		HTML_over		0 0 0 1 0		0 0 0 0\n\
SUB		HTML_sub		1 0 0 0 0		0 0 0 0\n\
SUP		HTML_sup		1 0 0 0 0		0 0 0 0\n\
BOX		HTML_box		0 0 0 1 0		0 0 0 0\n\
#not yet\n\
LABEL		HTML_label		0 0 0 0 0		0 0 0 0\n\
BYLINE		HTML_byline		0 0 0 0 0		0 0 0 0\n\
BASE		HTML_base		0 0 0 0 0		0 0 0 0\n\
CHANGED		HTML_changed		0 0 0 0 0		0 0 0 0\n\
#proto-vrml graphics (implemented)\n\
GRAPHICS	HTML_graphics		0 0 0 1 0		5 5 5 5\n\
RECT		HTML_rect		0 0 0 1 0		0 0 0 0\n\
CIRCLE 		HTML_circle		0 0 0 1 0		0 0 0 0\n\
OVAL		HTML_oval		0 0 0 1 0		0 0 0 0\n\
SQUARE		HTML_square		0 0 0 1 0		0 0 0 0\n\
LINE		HTML_line		0 0 0 1 0		0 0 0 0\n\
POLYGON 	HTML_polygon		0 0 0 1 0		0 0 0 0\n\
POINT		HTML_point		1 0 0 1 0		0 0 0 0\n\
POS		HTML_pos		1 0 0 1 0		0 0 0 0\n\
SIZE		HTML_size		1 0 0 1 0		0 0 0 0\n\
FGCOLOR		HTML_fgcolor		1 0 0 1 0		0 0 0 0\n\
BDCOLOR		HTML_bdcolor		1 0 0 1 0		0 0 0 0\n\
BGCOLOR		HTML_bgcolor		1 0 0 1 0		0 0 0 0\n\
#proto-vrml (not yet implemented)\n\
AXIS 		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
BUTTON 		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
HINT		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
ROT		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
SCALE		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
TEXT		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
ACTION		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
SCRIPT		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
STYLE		HTML_ignore		1 0 0 0 0		0 0 0 0\n\
";
