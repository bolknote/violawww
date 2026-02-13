/*
 * html2.c
 *
 * THIS CODE IS IN EXTREME STATE OF ENTROPY. MUST REVIEW.
 */
#include "utils.h"
#include <ctype.h>
#include <string.h>
#include <strings.h>

#include "HTFont.h"
#include "../libWWW/HTCharset.h"
#include "memory_debug.h"

#define convert_utf8_buffer(str, size) HTCharset_utf8_to_ascii_buffer(str, size)

char* HTAppName = "ViolaWWW";
char* HTAppVersion = "4.0";

#define PRINT_TAG_DELIMS
int printTagDelims = 0;

int http_method;
char* http_dataToPost;

int http_progress_reporter_level = 0;
int http_progress_expected_total_bytes = 0;
int http_progress_total_bytes = 0;
int http_progress_subtotal_bytes = 0;

#undef HTSTRING_H
#include "../libWWW/HTAccess.h"
#include "../libWWW/HTAnchor.h"
#include "../libWWW/HTHistory.h"
#include "../libWWW/HTML.h"
#include "../libWWW/HTMLDTD.h"
#include "../libWWW/HTParse.h"
#include "../libWWW/HTString.h"
#include "../libWWW/HTTCP.h"
#include "../libWWW/HText.h"
#include "../libWWW/SGML.h"

#undef HTWRITE_H
#include "../libWWW/HTFile.h"
#include "../libWWW/HTWriter.h"

#include "DefaultStyles.h"
#include "attr.h"
#include "cexec.h"
#include "class.h"
#include "classlist.h"
#include "event.h"
#include "glib.h"
#include "hash.h"
#include "html.h"
#include "html2.h"
#include "ident.h"
#include "membership.h"
#include "method.h"
#include "misc.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "scanutils.h"
#include "sgml.h"
#include "slib.h"
#include "slotaccess.h"
#include "sys.h"
#include "tfed.h"
#include "vlist.h"

extern VObj* insert_obj; /* from sgml.c */
extern int insert_width;
extern Packet scrapPk;
extern SGMLDocMappingInfo SGMLForms[];
/* SGMLBuildDoc_inChanged is declared in sgml.h */

/* Explicit prototype to fix 64-bit pointer truncation issue */
extern long findMeth(VObj* self, long funcid);

VObj* mesgObj = NULL;

SGMLBuildInfo SBI;
static SGMLTagMappingInfo* fallback_block_tmi = NULL;

/* Global charset for title conversion - set from META tag */
static char* current_document_charset = NULL;

/* Global converted title - set from TITLE tag, applied when anchor becomes available */
static char* pending_title = NULL;

static void html2_reset_stack_state(const char* context) {
    static int stack_underflow_warn = 5;
    int reset_idx = 0;

    if (stack_underflow_warn > 0) {
        fprintf(stderr, "CB_HTML_%s: stack underflow detected (stacki=%d)\n",
                context ? context : "?", SBI.stacki);
        stack_underflow_warn--;
    }

    SBI.stacki = 0;
    dataBuffIdxStackIdx = 0;

    if (SBI.stack[0].dataBuffIdx_localStart >= 0)
        reset_idx = SBI.stack[0].dataBuffIdx_localStart;
    dataBuffIdxStack[0] = reset_idx;
    dataBuffIdx = reset_idx;
}

/* Function to set document charset (called from HTML.c handle_meta_charset) */
void html2_set_document_charset(const char* charset) {
    if (current_document_charset) {
        free(current_document_charset);
        current_document_charset = NULL;
    }
    if (charset) {
        current_document_charset = saveString(charset);
    }
}

/* Function to apply pending title to anchor (called from html.c when anchor becomes available) */
void html2_apply_pending_title(HTParentAnchor* anchor) {
    if (pending_title && anchor) {
        HTAnchor_setTitle(anchor, pending_title);
        free(pending_title);
        pending_title = NULL;
    }
}

/* Function to get pending title (returns NULL if none) */
char* html2_get_pending_title(void) {
    return pending_title;
}

static char* html2_extract_charset_from_content(const char* content) {
    const char* scan;
    const char* start;
    char quote = 0;
    size_t len;
    char* charset;

    if (!content)
        return NULL;

    for (scan = content; *scan; scan++) {
        if (strncasecmp(scan, "charset", 7) == 0) {
            const char* cursor = scan + 7;
            while (*cursor && isspace((unsigned char)*cursor))
                cursor++;
            if (*cursor != '=')
                continue;
            cursor++;
            while (*cursor && isspace((unsigned char)*cursor))
                cursor++;
            if (!*cursor)
                return NULL;
            if (*cursor == '"' || *cursor == '\'')
                quote = *cursor++;
            start = cursor;
            while (*cursor) {
                if (quote) {
                    if (*cursor == quote)
                        break;
                } else if (isspace((unsigned char)*cursor) || *cursor == ';' || *cursor == '"' ||
                           *cursor == '\'') {
                    break;
                }
                cursor++;
            }
            len = cursor - start;
            if (!len)
                return NULL;
            charset = (char*)malloc(len + 1);
            if (!charset)
                return NULL;
            memcpy(charset, start, len);
            charset[len] = '\0';
            return charset;
        }
    }
    return NULL;
}

static void html2_handle_meta_charset(BOOL* present, char** value) {
    char* charset;
    HTParentAnchor* anchor = NULL;
    extern HTParentAnchor* HTMainAnchor;
    extern HText* HTMainText;

    if (!present || !value)
        return;

    if (!present[HTML_META_HTTP_EQUIV] || !value[HTML_META_HTTP_EQUIV] ||
        !present[HTML_META_CONTENT] || !value[HTML_META_CONTENT])
        return;

    if (strcasecmp(value[HTML_META_HTTP_EQUIV], "Content-Type") != 0)
        return;

    charset = html2_extract_charset_from_content(value[HTML_META_CONTENT]);
    if (!charset)
        return;

    html2_set_document_charset(charset);

    if (HTMainText)
        anchor = HText_nodeAnchor(HTMainText);
    if (!anchor && HTMainAnchor)
        anchor = HTMainAnchor;
    if (anchor) {
        char* existing = HTAnchor_charset(anchor);
        if (!existing || !*existing) {
            HTAnchor_setCharset(anchor, charset);
        }
    }

    free(charset);
}

enum sgmlsAttributeTypes {
    SGMLS_ATTR_IMPLIED,
    SGMLS_ATTR_CDATA,
    SGMLS_ATTR_TOKEN,
    SGMLS_ATTR_ID,
    SGMLS_ATTR_IDREF,
    SGMLS_ATTR_ENTITY,
    SGMLS_ATTR_NOTATION
};

int sgml_verbose = 0;

/* Element number of the SCRIPT or STYLE tag we're currently inside,
 * or -1 when not inside either.  Storing the element number (rather than
 * a plain boolean) prevents a mismatched close tag — e.g. </style>
 * inside a <script> block — from accidentally clearing the guard.
 *
 * Primary protection comes from SGML_LITTERAL content model in the
 * SGML parser: only the exact matching close tag triggers end_element.
 * This flag provides defense-in-depth on the builder side. */
static int inside_ignore_element = -1;

/* Flag to track if we're inside Wayback Toolbar comments */
static int inside_wayback_comment = 0;



static char* URLEncodeSeq[] = {
    NULL,  "%01", "%02", "%03", "%04", "%05", "%06", "%07", "%08", "%09", "%0A", "%0B", "%0C",
    "%0D", "%0E", "%0F", "%10", "%11", "%12", "%13", "%14", "%15", "%16", "%17", "%18", "%19",
    "%1A", "%1B", "%1C", "%1D", "%1E", "%1F", "+",   "%21", "%22", "%23", "%24", "%25", "%26",
    "%27", "%28", "%29", "*",   "%2B", "%2C", "-",   ".",   "%2F", "0",   "1",   "2",   "3",
    "4",   "5",   "6",   "7",   "8",   "9",   "%3A", "%3B", "%3C", "%3D", "3E",  "%3F", "@",
    "A",   "B",   "C",   "D",   "E",   "F",   "G",   "H",   "I",   "J",   "K",   "L",   "M",
    "N",   "O",   "P",   "Q",   "R",   "S",   "T",   "U",   "V",   "W",   "X",   "Y",   "Z",
    "%5B", "%5C", "%5D", "%5E", "_",   "%60", "a",   "b",   "c",   "d",   "e",   "f",   "g",
    "h",   "i",   "j",   "k",   "l",   "m",   "n",   "o",   "p",   "q",   "r",   "s",   "t",
    "u",   "v",   "w",   "x",   "y",   "z",   "%7B", "%7C", "%7D", "%7E", "%7F", "%80", "%81",
    "%82", "%83", "%84", "%85", "%86", "%87", "%88", "%89", "%8A", "%8B", "%8C", "%8D", "%8E",
    "%8F", "%90", "%91", "%92", "%93", "%94", "%95", "%96", "%97", "%98", "%99", "%9A", "%9B",
    "%9C", "%9D", "%9E", "%9F", "%A0", "%A1", "%A2", "%A3", "%A4", "%A5", "%A6", "%A7", "%A8",
    "%A9", "%AA", "%AB", "%AC", "%AD", "%AE", "%AF", "%B0", "%B1", "%B2", "%B3", "%B4", "%B5",
    "%B6", "%B7", "%B8", "%B9", "%BA", "%BB", "%BC", "%BD", "%BE", "%BF", "%C0", "%C1", "%C2",
    "%C3", "%C4", "%C5", "%C6", "%C7", "%C8", "%C9", "%CA", "%CB", "%CC", "%CD", "%CE", "%CF",
    "%D0", "%D1", "%D2", "%D3", "%D4", "%D5", "%D6", "%D7", "%D8", "%D9", "%DA", "%DB", "%DC",
    "%DD", "%DE", "%DF", "%E0", "%E1", "%E2", "%E3", "%E4", "%E5", "%E6", "%E7", "%E8", "%E9",
    "%EA", "%EB", "%EC", "%ED", "%EE", "%EF", "%F0", "%F1", "%F2", "%F3", "%F4", "%F5", "%F6",
    "%F7", "%F8", "%F9", "%FA", "%FB", "%FC", "%FD", "%FE", "%FF",
};
char URLEncodeBuff[1000];

/***** hot list defs/decls *****/

#define HBUFF_SIZE 100
char hbuff[HBUFF_SIZE];

int hbuffi = 0, hbuffLimit = 0;
char line[500];
int linei;

HotListItem* theHotList = NULL;
FILE* HotList_fp;
char* HotList_path = NULL;
int theHotListCount = 0;

int HotListLoadedP = 0;

/***** end of hot list defs/decls *****/

int init_html2() { 
    init_memory_debug();
    return 1; 
}

SGMLTagMappingInfo* findTMI(SGMLTagMappingInfo* tagMappingInfo, char* tag)
{
    int i;

    for (i = 0; tagMappingInfo[i].tag; i++)
        if (!strcmp(tag, tagMappingInfo[i].tag))
            return &tagMappingInfo[i];
    return NULL;
}

/*
 */
VObj* html2_parseHTMLDocument(VObj* self, char* address, char** simpleAddress, char** anchorSearch, int width, int method, char* dataToPost)
{
    SGMLBuildInfoState* bstate;
    char c, anchorInfo[64];
    extern char* current_addr;
    int i, stat;

    trimEdgeSpaces(address);

    /* get full address, without anchor */
    char* parsed_addr = HTParse(address, current_addr, PARSE_ACCESS | PARSE_HOST | PARSE_PATH | PARSE_PUNCTUATION);
    *simpleAddress = saveString(parsed_addr);
    free(parsed_addr);  /* Free the result from HTParse */
    HTSimplify(*simpleAddress);

    if (current_addr)
        free(current_addr);
    current_addr = saveString(*simpleAddress);

    /* extract anchor info, if any */
    *anchorSearch = "";
    for (i = 0; (c = address[i]); i++) {
        if (c == '#') {
            strcpy(anchorInfo, address + i + 1);
            *anchorSearch = saveString(anchorInfo);
            break;
        }
    }

    /* prepare SGMLBuildInfo structure
     */
    SBI.stacki = 0;
    SBI.endP = 0;
    SBI.caller = self;

    bstate = &SBI.stack[SBI.stacki];
    bstate->tmi = NULL;
    bstate->dataBuffIdx_localStart = 0;
    bstate->tag = NULL;
    bstate->parent = NULL;
    bstate->obj = self;
    bstate->width = bstate->sub_width = width;
    bstate->y = bstate->sub_y = 0;
    bstate->height = bstate->sub_height = 0;
    bstate->insert = NULL;

    HTOutputStream = NULL;
    HTOutputFormat = NULL;
    HTOutputSource = NO;

    CB_HTML_new();

    http_method = method;
    http_dataToPost = dataToPost;
    HTPushInputBuffer();

    stat = HTLoadAbsolute(*simpleAddress);

    http_method = HTTP_METHOD_GET;
    http_dataToPost = NULL;
    HTPopInputBuffer();

    if (stat) {
        return SBI.stack[0].obj;
    }
    return NULL;
}

void CB_HTML_new() {
    SGMLBuildInfoState* bstate;
    int i, j, tagCount, idx;
    char *dtd = "HTML", *tag;
    SGMLDocMappingInfo* docMappingInfo = NULL;
    SGMLTagMappingInfo *tmi, *tagMappingInfo = NULL;
    SGMLDocMappingInfo* dmi = NULL;
    /*	SGML_dtd sgmldtd;*/
    int* tag2StyleIndexMap;

    /*printf("CB_HTML_new\n");*/

    /* Reset ignore tag flag */
    inside_ignore_element = -1;
    
    /* Reset Wayback comment flag */
    inside_wayback_comment = 0;
    
    /* Reset document charset for new document */
    if (current_document_charset) {
        free(current_document_charset);
        current_document_charset = NULL;
    }
    
    /* Reset pending title for new document */
    if (pending_title) {
        free(pending_title);
        pending_title = NULL;
    }

    fallback_block_tmi = NULL;

    if (!strcmp(dtd, "HTML")) {
        /*		sgmldtd = HTML_dtd;*/
    } else {
        fprintf(stderr, "Unknown DTD %s, not hard coded!\n", dtd);
        return;
    }
    for (i = 0; SGMLForms[i].DTDName; i++) {
        if (!strcmp(SGMLForms[i].DTDName, dtd)) {
            dmi = &SGMLForms[i];
            break;
        }
    }
    if (!dmi) {
        char stylesheetFN[128];
        extern char* sgmlPath;

        sprintf(stylesheetFN, "%s/styles/%s.style", sgmlPath, dtd);

        if (sgml_verbose)
            fprintf(stderr, "loading stylesheet \"%s\" for dtd \" %s\".\n", stylesheetFN, dtd);

        dmi = setSGMLStylesheet(dtd, stylesheetFN);
        if (!dmi) {
            fprintf(stderr, "Failed to read stylesheet \"%s\" for dtd \" %s\".\n", stylesheetFN,
                    dtd);
            return;
        }

        /* setup the tag->styleObj map
         */
        tagCount = HTML_dtd.number_of_tags;
        tag2StyleIndexMap = (int*)malloc(sizeof(int) * tagCount);
        dmi->tag2StyleIndexMap = tag2StyleIndexMap;

        /*		fprintf(stdout,	"DTD=%s tagCount =%d\n", dtd, tagCount);*/

        tagMappingInfo = dmi->tagMap;

        for (i = 0; i < tagCount; i++) {
            tag = HTML_dtd.tags[i].name;
            idx = -1;
            for (j = 0; tagMappingInfo[j].tag; j++) {

                if (!strcmp(tag, tagMappingInfo[j].tag)) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) {
                fprintf(stdout, "Warning: element %s of DTD %s is not defined in stylesheet %s.\n",
                        tag, dtd, stylesheetFN);
                tag2StyleIndexMap[i] = -1;
            } else {
                tag2StyleIndexMap[i] = idx;
            }
            /*			fprintf(stdout,
                                            "%d tag={%s} idx=%d\n",
                                            i, HTML_dtd.tags[i].name, idx);
            */
        }
    }
    tagMappingInfo = dmi->tagMap;

    /*
            for (i = 0; tagMappingInfo[i].tag; i++) {
                    fprintf(stdout,
                            "%d {%s}\n",
                            i, tagMappingInfo[i].tag);
            }
    */
    dataBuffIdxStackIdx = 0;
    dataBuffIdxStack[dataBuffIdxStackIdx] = 0;
    dataBuffIdx = 0;

    SBI.stacki = 0;
    SBI.endP = 0;
    SBI.dmi = dmi;

    SBI.dmi->tagMap = dmi->tagMap;

    bstate = &SBI.stack[SBI.stacki];

    bstate->parent = SBI.caller;
    bstate->dataBuffIdx_localStart = dataBuffIdx;
    bstate->tag = "_HTML";
    bstate->tmi = findTMI(SBI.dmi->tagMap, bstate->tag);

    if (!bstate->tmi) {
        fprintf(stderr, "CB_HTML_new: internal error: no tmi struct for tag=%s\n", tag);
        return;
    }

    bstate->sub_width = bstate->width = GET_width(SBI.caller);

    HTMLBuildObj(bstate, bstate->width, bstate->tmi);

    bstate->sub_y = 0;
    bstate->height = 0;
    bstate->insert = NULL;
}

void CB_HTML_data(char* str, int size)
{
    SGMLBuildInfoState* bstate;
    char tempbuf[8192];
    int converted_size;

    /* Bounds check for stack access */
    if (SBI.stacki < 0) {
        html2_reset_stack_state("data");
    }
    if (SBI.stacki >= 100) {
        fprintf(stderr, "CB_HTML_data: stack overflow: %d\n", SBI.stacki);
        return;
    }
    bstate = &SBI.stack[SBI.stacki];

    /* Check for HTML comments in the data */
    if (size >= 7 && strncmp(str, "<!--", 4) == 0) {
        char comment_buf[8192];
        if (size < sizeof(comment_buf)) {
            memcpy(comment_buf, str, size);
            comment_buf[size] = '\0';
            
            /* Check for Wayback Toolbar comments */
            if (strstr(comment_buf, "BEGIN WAYBACK TOOLBAR INSERT")) {
                inside_wayback_comment = 1;
                return;
            }
            if (strstr(comment_buf, "END WAYBACK TOOLBAR INSERT")) {
                inside_wayback_comment = 0;
                return;
            }

            /* Ignore all other comments */
            return;
        }
    }
    
    /* Ignore data inside SCRIPT and STYLE tags */
    if (inside_ignore_element >= 0) {
        return;
    }
    
    /* Ignore data inside Wayback Toolbar comments */
    if (inside_wayback_comment) {
        return;
    }

    if (bstate->obj) {
        /* Convert UTF-8 to Latin1 */
        if (size < sizeof(tempbuf)) {
            memcpy(tempbuf, str, size);
            tempbuf[size] = '\0';
            converted_size = convert_utf8_buffer(tempbuf, size);
            str = tempbuf;
            size = converted_size;
        }
        
        /* If inside CHANGED region, prepend \m( */
        if (SGMLBuildDoc_inChanged > 0) {
            dataBuff[dataBuffIdx++] = '\\';
            dataBuff[dataBuffIdx++] = 'm';
            dataBuff[dataBuffIdx++] = '(';
        }
        
        strncpy(&dataBuff[dataBuffIdx], str, size);

        dataBuff[dataBuffIdx + size] = '\0';

        /*
        printf("DATA size===%d\n", size);
        printf("...obj=%s lidx=%d idx=%d DATA {%s}\n",
        GET_name(bstate->obj), dataBuffIdxStack[dataBuffIdxStackIdx],
        dataBuffIdx, &dataBuff[dataBuffIdx]);
        }*/
        dataBuffIdx += size;
        
        /* If inside CHANGED region, append \m) */
        if (SGMLBuildDoc_inChanged > 0) {
            dataBuff[dataBuffIdx++] = '\\';
            dataBuff[dataBuffIdx++] = 'm';
            dataBuff[dataBuffIdx++] = ')';
        }
    }
    /*	else {
                    fprintf(stderr,
                            "@@@@ NO object to receive: DATA(%d) -%s\n",
                            size, str);
            }
    */
}

void CB_HTML_special_entity(int entity_number, char* data, int dataLength)
{
    SGMLBuildInfoState* bstate;
    SGMLBuildInfoState* parent_bstate;

    /* Ignore entities inside Wayback Toolbar comments */
    if (inside_wayback_comment) {
        return;
    }

    /* Bounds check for stack access */
    if (SBI.stacki < 1 || SBI.stacki >= 100) {
        fprintf(stderr, "CB_HTML_special_entity: stacki out of bounds: %d\n", SBI.stacki);
        return;
    }
    parent_bstate = &SBI.stack[SBI.stacki - 1];
    bstate = &SBI.stack[SBI.stacki];

    if (bstate->obj && parent_bstate && parent_bstate->tmi &&
        (parent_bstate->tmi->flushAlwaysP || parent_bstate->tmi->flushOnSubTagP)) {
        int src_starti, src_endi, size;
        char* cp;
        int span;

        if (dataLength > 0) {
            cp = (char*)malloc(sizeof(char) * (dataLength + 1));
            strncpy(cp, data, dataLength);
            cp[dataLength] = '\0';
        } else {
            cp = (char*)malloc(sizeof(char));
            *cp = '\0';
        }

        if (GET_label(bstate->obj))
            free(GET_label(bstate->obj));
        SET_label(bstate->obj, cp);
        /*
                        span = getVSpan(bstate->obj, STR_F);
        */
		sendMessage1N1int(bstate->obj, "entity", entity_number);
    }
}

void CB_HTML_stag(int element_number, BOOL* present, char** value, HTTag* tagInfo)
{
    SGMLBuildInfoState* parent_parent_bstate;
    SGMLBuildInfoState* parent_bstate;
    SGMLBuildInfoState* bstate;
    char* cp;
    char attrName[64];
    int attrTypeID;
    SGMLTagMappingInfo* ctmi;
    VObj* _insert_obj = insert_obj;
    int i, x, y, width;
    char* tag;
    SGMLTagMappingInfo* tmi;
    int hadFlushed = 0;
    char* str;
    int size, span, src_starti, src_endi;

    tag = HTML_dtd.tags[element_number].name;

#ifdef PRINT_TAG_DELIMS
    if (printTagDelims) {
        fprintf(stderr, "########################## HTML\t(%s\n", tag);
    }
#endif

    /* Ignore SCRIPT and STYLE opening tags — content is suppressed until
     * the matching close tag arrives.  The SGML parser uses SGML_LITTERAL
     * content model for these elements, so it will not call CB_HTML_stag
     * for any markup inside the block; only the exact close tag triggers
     * CB_HTML_etag.  We record WHICH element we're inside so that only
     * the matching close tag can clear the guard (defense-in-depth). */
    if (element_number == HTML_SCRIPT || element_number == HTML_STYLE) {
        inside_ignore_element = element_number;
        return;
    }

    /* Defense-in-depth: if the SGML parser somehow delivers a start tag
     * while we're inside a SCRIPT/STYLE block (should never happen with
     * SGML_LITTERAL, but guard against parser bugs), silently drop it.
     * Returning before any stack manipulation keeps SBI.stacki consistent. */
    if (inside_ignore_element >= 0) {
        return;
    }

    /* Ignore all tags inside Wayback Toolbar comments */
    if (inside_wayback_comment) {
        return;
    }

    int is_meta_tag = (element_number == HTML_META);
    if (is_meta_tag) {
        html2_handle_meta_charset(present, value);
    }

    /* Bounds check for stack access */
    if (SBI.stacki < 0 || SBI.stacki >= 100) {
        fprintf(stderr, "CB_HTML_stag[%s]: stacki out of bounds: %d\n",
                tag ? tag : "?", SBI.stacki);
        return;
    }
    parent_bstate = &SBI.stack[SBI.stacki];
    
    /* Check if stack overflow would occur before incrementing */
    if (SBI.stacki >= 99) {
        fprintf(stderr, "CB_HTML_stag: stack overflow, max nesting depth exceeded\n");
        return;
    }
    SBI.stacki++;
    bstate = &SBI.stack[SBI.stacki];

    /*	fprintf(stderr, "@@@@ stacki=%d\n", SBI.stacki);*/

    /* map HTML parser's tag ID (element_number) to stylesheet element */
    if (!SBI.dmi || element_number < 0 || element_number >= HTML_dtd.number_of_tags) {
        SBI.stacki--;
        return;
    }

    /* Handle CHANGED tag for highlighting - must be before styleIndex check */
    if (element_number == HTML_CHANGED) {
        if (present && present[HTML_CHANGED_ID] && value && value[HTML_CHANGED_ID]) {
            /* Start marker - enter CHANGED region */
            SGMLBuildDoc_inChanged++;
        } else if (present && present[HTML_CHANGED_IDREF] && value && value[HTML_CHANGED_IDREF]) {
            /* End marker - leave CHANGED region */
            if (SGMLBuildDoc_inChanged > 0) SGMLBuildDoc_inChanged--;
        }
        /* CHANGED is SGML_EMPTY - we incremented stacki above, decrement it back */
        SBI.stacki--;
        return;
    }

    int styleIndex = SBI.dmi->tag2StyleIndexMap[element_number];
    if (styleIndex < 0) {
        if (tagInfo && tagInfo->contents == SGML_EMPTY) {
            bstate->tmi = NULL;
            bstate->obj = NULL;
            SBI.stacki--;
            return;
        }

        if (!fallback_block_tmi && SBI.dmi) {
            int fallbackIndex = (HTML_P < HTML_dtd.number_of_tags)
                               ? SBI.dmi->tag2StyleIndexMap[HTML_P]
                               : -1;
            if (fallbackIndex >= 0)
                fallback_block_tmi = &SBI.dmi->tagMap[fallbackIndex];
            else
                fallback_block_tmi = &SBI.dmi->tagMap[0];
        }

        bstate->tmi = fallback_block_tmi;
    } else {
        bstate->tmi = &SBI.dmi->tagMap[styleIndex];
    }
    if (is_meta_tag) {
        bstate->obj = NULL;
        SBI.stacki--;
        return;
    }

    /* make parent object its own-- the *first time* that the
     * inline object becomes a container.
     */
    if (parent_bstate->tmi && bstate->tmi &&
        parent_bstate->tmi->inlineP &&
        !bstate->tmi->inlineP && /* don't copy if sub-obj is inlined */
        parent_bstate->obj && !GET__children(parent_bstate->obj)) {
        extern int global_cloneID;
        Packet argv[2];
        VObjList* olist;
        VObj* parentParent;

        if (!parent_bstate->tmi->cloneMeth)
            parent_bstate->tmi->cloneMeth = (long (*)(VObj*, Packet*, int, Packet*))findMeth(
                parent_bstate->tmi->template, STR_clone);
        if (!parent_bstate->tmi->template) {
            fprintf(stderr, "SGMLBuild_B: can't find clone method for template object '%s'\n",
                    parent_bstate->tmi->type);
            goto skip_clone;  /* Skip cloning if no template */
        }
        argv[0].info.i = global_cloneID++;
        argv[0].type = PKT_INT;
        argv[0].canFree = 0;
        if (parent_bstate->tmi->cloneMeth) {
            parent_bstate->tmi->cloneMeth(parent_bstate->tmi->template, &scrapPk, 1, &argv[0]);
            /* Check if clone succeeded */
            if (!scrapPk.info.o) {
                fprintf(stderr, "SGMLBuild_B: clone failed for template object '%s'\n",
                        parent_bstate->tmi->type);
                goto skip_clone;
            }
        } else {
            goto skip_clone;  /* Skip cloning if no method */
        }

        parentParent = GET__parent(parent_bstate->obj);
        if (parentParent) {
            olist = GET__children(parentParent);
            if (olist) {
                for (; olist; olist = olist->next) {
                    /*printf(">>>%s\n", GET_name(olist->o));
                     */
                    if (olist->o == parent_bstate->obj) {
                        olist->o = scrapPk.info.o;
                        /*printf(">>>>>>>>%s\n", GET_name(olist->o));
                         */
                        break;
                    }
                }
            } else {
                /* unexpected error*/
            }
        }
        /* Send copyObj only if the cloned object actually implements it */
        {
            long copyId = getIdent("copyObj");
            if (findMeth(scrapPk.info.o, copyId)) {
                argv[0].info.s = "copyObj";
                argv[0].type = PKT_STR;
                argv[0].canFree = 0;
                argv[1].info.o = parent_bstate->obj;
                argv[1].type = PKT_OBJ;
                argv[1].canFree = 0;
                sendMessagePackets(scrapPk.info.o, argv, 2);
            }
        }
        parent_bstate->obj = scrapPk.info.o;

        /* because the n-1 level object has been turned into a
         * container, n-2 level object needs to be told to flush
         */
        {
            if (dataBuffIdxStackIdx >= 2) {
                src_starti = dataBuffIdxStack[dataBuffIdxStackIdx - 2];
                src_endi = dataBuffIdxStack[dataBuffIdxStackIdx - 1];

                dataBuffIdxStack[dataBuffIdxStackIdx - 2] = src_endi;
                size = src_endi - src_starti;
                /*
                printf("COPY (for n-2) src_starti=%d\n", src_starti);
                printf("COPY (for n-2) src_endi=%d\n", src_endi);
                */
            } else {
                size = 0;
            }
            if (size < 0) {
                cp = (char*)malloc(sizeof(char));
                *cp = '\0';
            } else {
                cp = (char*)malloc(sizeof(char) * (size + 1));
                strncpy(cp, &dataBuff[src_starti], size);
                cp[size] = '\0';
            }
            /*printf("COPY (for n-2) str={%s}\n", cp);*/

            /* Bounds check before accessing stack[SBI.stacki - 2] */
            if (SBI.stacki >= 2 && SBI.stacki < 100) {
                parent_parent_bstate = &SBI.stack[SBI.stacki - 2];
            } else {
                parent_parent_bstate = NULL;
            }
            if (parent_parent_bstate && parent_parent_bstate->obj) {
                if (GET_label(parent_parent_bstate->obj))
                    free(GET_label(parent_parent_bstate->obj));
                SET_label(parent_parent_bstate->obj, cp);

                /* in case obj needs this information */
                SGMLBuildDoc_span = parent_parent_bstate->sub_y;
                span = getVSpan(parent_parent_bstate->obj, STR_F);
            } else {
                free(cp);  /* Free allocated string if not used */
            }
        }
    }
    skip_clone:  /* Label for skipping failed clone operations */
    {
#ifdef fdlkjsdjsdfl
        /* flush n-1 level object
         */
        {
            if (dataBuffIdxStackIdx >= 1) {
                src_starti = dataBuffIdxStack[dataBuffIdxStackIdx - 1];
                src_endi = dataBuffIdx;

                dataBuffIdxStack[dataBuffIdxStackIdx] = src_endi;
                size = src_endi - src_starti;

                printf("COPY (for n-1) src_starti=%d\n", src_starti);
                printf("COPY (for n-1) src_endi=%d\n", src_endi);

            } else {
                size = 0;
            }
            if (size < 0) {
                cp = (char*)malloc(sizeof(char));
                *cp = '\0';
            } else {
                cp = (char*)malloc(sizeof(char) * (size + 1));
                strncpy(cp, &dataBuff[src_starti], size);
                cp[size] = '\0';
            }
            printf("COPY (for n-1) str={%s}\n", cp);
            if (parent_bstate) {
                if (GET_label(parent_bstate->obj))
                    free(GET_label(parent_bstate->obj));
                SET_label(parent_bstate->obj, cp);

                /* in case obj needs this information */
                SGMLBuildDoc_span = parent_bstate->sub_y;
                span = getVSpan(parent_bstate->obj, STR_F);
                hadFlushed = 1;
            }
        }
#endif
    }
    bstate->dataBuffIdx_localStart = dataBuffIdx;
    dataBuffIdxStack[++dataBuffIdxStackIdx] = dataBuffIdx;

    bstate->parent = parent_bstate->obj;

    bstate->tag = tag;
    bstate->styleAttr = NULL; /* Initialize style attribute */
    bstate->obj = HTMLBuildObj(bstate, parent_bstate->sub_width, bstate->tmi);

    /* Check if object creation failed */
    if (!bstate->obj) {
        fprintf(stderr, "CB_HTML_stag: HTMLBuildObj failed for tag=%s\n", tag);
        SBI.stacki--;  /* Pop the failed state from stack */
        return;
    }

    if (bstate->obj && parent_bstate->obj && bstate->obj != parent_bstate->obj) {
        SET__parent(bstate->obj, parent_bstate->obj);
        SET_parent(bstate->obj, VSaveString(GET__memoryGroup(bstate->obj), GET_name(parent_bstate->obj)));
    }
    if (bstate->tmi->notifyOnCreationP) {
        sendTokenMessage(bstate->obj, STR_C);

#ifdef DOES_NOT_WORK
        if (insert_obj) {
            VObjList *olist, *subObj;
            int _width, span;

            printf("HTML2.c INSERT_OBJ is called for STAG!!!\n");

            _insert_obj = insert_obj;
            insert_obj = NULL;

            if (insert_width == -1) {
                _width = bstate->width;
            } else {
                _width = insert_width;
                insert_width = -1;
            }

            /*
                                    SET__parent(bstate->obj, _insert_obj);
                                    SET_parent(bstate->obj, GET_name(_insert_obj));
            */
            if (bstate->obj) {
                olist = GET__children(bstate->obj);
                /*
                                                parent_bstate->sub_y += bstate->span;
                                                parent_bstate->height += bstate->span;
                */
                                SET__children(bstate->obj,
				      appendObjToList(olist, _insert_obj);
            }
            /* Due to the call-back sequencencing, it's
             * not clear how to achieve totally transparent
             * object insertion. So, the bug is that
             * the inserted object can't expect normal
             * ESIS data stream...
             */

            span = getVSpan(_insert_obj, STR_C);
            SGMLBuildDoc_span = span;

            if (span == 0) {
                /* destroy object -- it's useless XXX*/
                /*				subObj = NULL;*/

            } else if (span != -1) {
                /*				*h = span;
                                                SET_height(subObj, *h);
                */
            }

            bstate->insert = _insert_obj;
        }
#endif
    }

    /*
     * please excuse the use of __content2 attr
     */
    if (bstate->obj)
        SET__content2(bstate->obj, bstate->tmi);

    bstate->sub_y = 0;
    bstate->height = 0;

    if (bstate->obj && bstate->tmi)
        SET_x(bstate->obj, bstate->tmi->left);

    if (bstate->tmi) {
        y = parent_bstate->sub_y + bstate->tmi->top;
        width = parent_bstate->sub_width - bstate->tmi->left - bstate->tmi->right;
    } else {
        y = parent_bstate->sub_y;
        width = parent_bstate->sub_width;
    }
    if (bstate->obj) {
        SET_y(bstate->obj, y);
        SET_width(bstate->obj, width);
    }

    if (bstate->obj && tagInfo && tagInfo->number_of_attributes && present && value) {
        char** tagAttrNames = tagInfo->attributes;
        for (i = 0; i < tagInfo->number_of_attributes; i++) {
            if (present[i]) {
                /* Save STYLE attribute for later use in minor matching */
                if (!strcasecmp(tagAttrNames[i], "STYLE")) {
                    /* Copy the string since value[i] will be freed by SGML parser */
                    if (bstate->styleAttr)
                        free(bstate->styleAttr);
                    bstate->styleAttr = saveString(value[i]);
                    /* Don't send AA for STYLE - will be sent as setStyleAttr in etag */
                } else {
                    sendMessage1N2str(bstate->obj, "AA", tagAttrNames[i], value[i]);
                }
            }
        }
    }

    /*
    printf("obj=%s lidx=%d idx=%d DATA {%s}\n",
    GET_name(bstate->obj), dataBuffIdxStack[dataBuffIdxStackIdx],
    dataBuffIdx, &dataBuff[dataBuffIdxStack[dataBuffIdxStackIdx]]);
    */

    /*	if (parent_bstate->obj && bstate->tmi &&
                parent_bstate->tmi->flushAlwaysP || bstate->tmi->flushOnSubTagP ||
                parent_bstate->tmi->inlineP) {
    */

    /* Flush any text in buffer
     */
    if (!hadFlushed)
        if (parent_bstate->obj && bstate->tmi &&
            (parent_bstate->tmi->flushAlwaysP ||
             (bstate->tmi->flushOnSubTagP && !bstate->tmi->inlineP))) {

            span = 0;
            src_starti = dataBuffIdxStack[dataBuffIdxStackIdx - 1];
            src_endi = dataBuffIdx;

            dataBuffIdxStack[dataBuffIdxStackIdx - 1] = src_starti;

            /*
             * XXX THIS MALLOCing is NOT necessary for HTML, but needed for HMML.
             * UNIFY THIS DUDE. BUT, MALLOC (AND FREE) PROPPERLY. MUST FIX THIS.?
             */
            size = src_endi - src_starti;
            if (size < 0) {
                size = 0;
            }
            if (size) {
                cp = (char*)malloc(sizeof(char) * (size + 1));
                strncpy(cp, &dataBuff[src_starti], size);
                cp[size] = '\0';
            } else {
                cp = (char*)malloc(sizeof(char));
                *cp = '\0';
            }

            if (parent_bstate->obj) {
                if (GET_label(parent_bstate->obj))
                    free(GET_label(parent_bstate->obj));
                SET_label(parent_bstate->obj, cp);
            } else {
                free(cp);  /* Free allocated string if not used */
            }

            /*
            printf("FLUSH as parent: obj=%s lidx=%d idx=%d DATA {%s}\n",
              GET_name(parent_bstate->obj), dataBuffIdxStack[dataBuffIdxStackIdx - 1],
              dataBuffIdx, GET_label(parent_bstate->obj));

            printf("FLUSH1 as parent: obj=%s height=%d sub_y=%d\n",
              GET_name(parent_bstate->obj),
              parent_bstate->height, parent_bstate->sub_y);
            */

            if (1 /*!hadFlushed*/) {
                /* in case obj needs this information */
                SGMLBuildDoc_span = parent_bstate->sub_y;

                /* Tell parent object to flush out any data (and
                 * create  objects to process that data, if necessary).
                 * Return any vspan to insert.
                 */
                span = getVSpan(parent_bstate->obj, STR_F);
            }
            /*
            printf("FLUSH2 as parent: obj=%s height=%d sub_y=%d span=%d\n",
              GET_name(parent_bstate->obj),
              parent_bstate->height, parent_bstate->sub_y, span);
            */
            /* Flush action might have caused object insertion,
             * and thus affected sub_y
             */
            if (bstate->obj)
                SET_y(bstate->obj, parent_bstate->sub_y + span + bstate->tmi->top);

            if (span == 0) {
                /* destroy object -- it's useless */
                /*
                printf("DESTROYING obj=%s data={%s}\n",
                GET_name(parent_bstate->obj), GET_label(parent_bstate->obj));
                */
                parent_bstate->obj = NULL;
                dataBuffIdx = parent_bstate->dataBuffIdx_localStart;
                /*???*/

            } else if (span != -1 && parent_bstate->obj) {

                /*			span += bstate->tmi->top + bstate->tmi->bottom;*/

                parent_bstate->sub_y += span;
                parent_bstate->height += span;

                SET_height(parent_bstate->obj, parent_bstate->height);
                /*
                printf("FLUSH3 as parent: obj=%s height=%d sub_y=%d span=%d\n",
                GET_name(parent_bstate->obj),
                parent_bstate->height, parent_bstate->sub_y, span);
                */
            }
            /* if obj is a hpane, then postpone its and
             * its children's geometry till the end of
             * hpane is reached...
             */
            /*		if (!tmi->hpaneP)
                                    ... += bstate->tmi->top + bstate->tmi->bottom;
            */

            /*
                            if (parent_bstate->obj) {
                                fprintf(stderr,
                                    "FLUSH exiting %s. obj='%s' span=%d height=%d\n",
                                    "stag", GET_name(parent_bstate->obj),
                                    span, parent_bstate->height);
                            }
            */
        }
    if (parent_bstate->obj && bstate->tmi) {
        if (insert_obj) {
            VObjList *olist, *subObj;
            int _width, span;

            /*printf("HTML2.c INSERT_OBJ is called for STAG!!!\n");*/

            _insert_obj = insert_obj;
            insert_obj = NULL;

            if (insert_width == -1) {
                _width = bstate->width;
            } else {
                _width = insert_width;
                insert_width = -1;
            }

            /* can't use parent's sub_y, since the insertion
             * object is the new reference frame
             */
            SET_y(bstate->obj, bstate->tmi->top);

            SET__parent(bstate->obj, _insert_obj);
            SET_parent(bstate->obj, VSaveString(GET__memoryGroup(bstate->obj), GET_name(_insert_obj)));

            olist = GET__children(_insert_obj);
            SET__children(_insert_obj, appendObjToList(olist, bstate->obj));

            if (parent_bstate->obj) {
                olist = GET__children(parent_bstate->obj);
                SET__children(parent_bstate->obj, appendObjToList(olist, _insert_obj));
            }
            /* Due to the call-back sequencencing, it's
             * not clear how to achieve totally transparent
             * object insertion. So, the bug is that
             * the inserted object can't expect normal
             * ESIS data stream...
             */

            span = getVSpan(_insert_obj, STR_C);
            SGMLBuildDoc_span = span;

            if (span == 0) {
                /* destroy object -- it's useless XXX*/
                /*				subObj = NULL;*/

            } else if (span != -1) {
                /*				*h = span;
                                                SET_height(subObj, *h);
                */
            }
            if (SBI.stacki > 0)
                parent_bstate->insert = _insert_obj;

            /*			if (!bstate->tmi->inlineP) {
                                      VObjList *olist;

                                      olist = GET__children(parent_bstate->obj);
                                      SET__children(parent_bstate->obj,
                                                    appendObjToList(olist, _insert_obj));
                                    }
            */
        } else {
            VObjList* olist;
            olist = GET__children(parent_bstate->obj);
            SET__children(parent_bstate->obj, appendObjToList(olist, bstate->obj));
        }
    }
}

void CB_HTML_etag(int element_number)
{
    SGMLBuildInfoState* parent_bstate;
    SGMLBuildInfoState* bstate;
    Packet evalResult;
    char* cp;
    int size, src_starti, src_endi;

    nullPacket(&evalResult);

#ifdef PRINT_TAG_DELIMS
    if (printTagDelims) {
        fprintf(stderr, "########################## HTML\t)%s\n",
                HTML_dtd.tags[element_number].name);
    }
#endif

    /* Ignore SCRIPT and STYLE closing tags.  Only clear the guard if
     * the close tag matches the element that set it — this prevents a
     * stray </style> from disabling a guard set by <script>, etc.
     * With SGML_LITTERAL content model, the parser guarantees only the
     * matching close tag reaches here; the element check is defense-in-depth. */
    if (element_number == HTML_SCRIPT || element_number == HTML_STYLE) {
        if (inside_ignore_element == element_number) {
            inside_ignore_element = -1;
        }
        return;
    }

    /* Defense-in-depth: if the SGML parser somehow delivers an end tag
     * while we're inside a SCRIPT/STYLE block, silently drop it. */
    if (inside_ignore_element >= 0) {
        return;
    }

    
    /* Handle Wayback Toolbar comments - no special handling needed for end tags */
    if (element_number == HTML_COMMENT) {
        return;
    }

    /* Ignore tags entirely while inside Wayback Toolbar comments */
    if (inside_wayback_comment) {
        return;
    }

    /* CHANGED is handled entirely in CB_HTML_stag - ignore etag */
    if (element_number == HTML_CHANGED) {
        return;
    }

    /* Bounds check and fix stack access order */
    if (SBI.stacki < 0 || SBI.stacki >= 100) {
        const char* name = (element_number >= 0 && element_number < HTML_dtd.number_of_tags)
                               ? HTML_dtd.tags[element_number].name
                               : "?";
        fprintf(stderr, "CB_HTML_etag[%s]: stacki out of bounds: %d\n",
                name, SBI.stacki);
        return;
    }
    bstate = &SBI.stack[SBI.stacki];

    if (!bstate->obj) {
        SBI.stacki--;
        return;
    }

    SBI.stacki--;
    if (SBI.stacki >= 0 && SBI.stacki < 100)
        parent_bstate = &SBI.stack[SBI.stacki];
    else
        parent_bstate = NULL;

    /* Ignore data processing inside Wayback Toolbar comments */
    if (inside_wayback_comment) {
        return;
    }

    /* Handle TITLE tag - extract title and set it with charset conversion */
    if (element_number == HTML_TITLE) {
        extern HTParentAnchor* HTMainAnchor;
        extern HText* HTMainText;
        HTParentAnchor* anchor = NULL;
        char* title_text = NULL;
        char* charset = NULL;
        char outbuf[4096];
        char tempbuf[4096];
        int converted_len;
        
        /* Try to get anchor from HTMainText or HTMainAnchor */
        if (HTMainText) {
            anchor = HText_nodeAnchor(HTMainText);
        }
        if (!anchor && HTMainAnchor) {
            anchor = HTMainAnchor;
        }
        
        /* Try to get charset from anchor first, then from global variable */
        if (anchor) {
            charset = HTAnchor_charset(anchor);
        }
        
        /* Fallback to global charset if anchor charset not available */
        if (!charset || strlen(charset) == 0) {
            charset = current_document_charset;
        }
        
        /* Extract title from dataBuff */
        if (dataBuffIdxStackIdx >= 0) {
            src_starti = dataBuffIdxStack[dataBuffIdxStackIdx];
            src_endi = dataBuffIdx;
            size = src_endi - src_starti;
            
            if (size > 0 && size < sizeof(tempbuf)) {
                memcpy(tempbuf, &dataBuff[src_starti], size);
                tempbuf[size] = '\0';
                
                /* Convert title from document charset to ASCII if needed */
                if (charset && strlen(charset) > 0 && 
                    strcasecmp(charset, "UTF-8") != 0 && strcasecmp(charset, "utf8") != 0) {
                    /* Convert from document charset to ASCII */
                    converted_len = HTCharset_convert_to_ascii(charset, tempbuf, size, 
                                                               outbuf, sizeof(outbuf));
                    if (converted_len > 0) {
                        title_text = (char*)malloc(converted_len + 1);
                        if (title_text) {
                            memcpy(title_text, outbuf, converted_len);
                            title_text[converted_len] = '\0';
                        }
                    }
                } else {
                    /* Already UTF-8, convert to ASCII in-place */
                    converted_len = HTCharset_utf8_to_ascii_buffer(tempbuf, size);
                    if (converted_len > 0 && converted_len < (int)sizeof(tempbuf)) {
                        title_text = (char*)malloc(converted_len + 1);
                        if (title_text) {
                            memcpy(title_text, tempbuf, converted_len);
                            title_text[converted_len] = '\0';
                        }
                    }
                }
                
                /* Set title on anchor if available, otherwise save for later */
                if (anchor) {
                    HTAnchor_setTitle(anchor, title_text ? title_text : tempbuf);
                    /* Clear pending title if we set it directly */
                    if (pending_title) {
                        free(pending_title);
                        pending_title = NULL;
                    }
                } else {
                    /* Save title for later when anchor becomes available */
                    if (pending_title) {
                        free(pending_title);
                    }
                    pending_title = title_text ? saveString(title_text) : saveString(tempbuf);
                    /* Don't free title_text here - it's saved in pending_title */
                    title_text = NULL; /* Prevent double free */
                }
                
                if (title_text)
                    free(title_text);
            }
        }
        
        /* Replace dataBuff content with converted title for normal label processing */
        if (pending_title) {
            /* Replace the raw title in dataBuff with converted title */
            size_t pending_len = strlen(pending_title);
            if (dataBuffIdxStackIdx >= 0 && pending_len < (DATABUFF_SIZE - dataBuffIdxStack[dataBuffIdxStackIdx])) {
                src_starti = dataBuffIdxStack[dataBuffIdxStackIdx];
                /* Clear old data */
                int old_size = dataBuffIdx - src_starti;
                if (old_size > 0) {
                    memset(&dataBuff[src_starti], 0, old_size);
                }
                /* Copy converted title */
                memcpy(&dataBuff[src_starti], pending_title, pending_len);
                dataBuffIdx = src_starti + pending_len;
            }
        } else if (anchor && HTAnchor_title(anchor)) {
            /* Replace with title from anchor */
            char* anchor_title = HTAnchor_title(anchor);
            size_t anchor_title_len = strlen(anchor_title);
            if (dataBuffIdxStackIdx >= 0 && anchor_title_len < (DATABUFF_SIZE - dataBuffIdxStack[dataBuffIdxStackIdx])) {
                src_starti = dataBuffIdxStack[dataBuffIdxStackIdx];
                /* Clear old data */
                int old_size = dataBuffIdx - src_starti;
                if (old_size > 0) {
                    memset(&dataBuff[src_starti], 0, old_size);
                }
                /* Copy anchor title */
                memcpy(&dataBuff[src_starti], anchor_title, anchor_title_len);
                dataBuffIdx = src_starti + anchor_title_len;
            }
        }
        /* Continue with normal processing - it will use converted title from dataBuff */
    }

    if (bstate->tmi) {
        if (bstate->tmi->inlineP
            /*&& !GET__children(bstate->obj)*/) { /*HIO*/
            src_starti = dataBuffIdxStack[dataBuffIdxStackIdx];
            src_endi = dataBuffIdx;
            size = src_endi - src_starti;
            if (size < 0) {
                fprintf(stderr, "html parsing error occured.\n");
                size = 0;
            }
            if (size) {
                cp = (char*)malloc(sizeof(char) * (size + 1));
                strncpy(cp, &dataBuff[src_starti], size);
                cp[size] = '\0';
            } else {
                cp = (char*)malloc(sizeof(char));
                *cp = '\0';
            }

            if (GET_label(bstate->obj))
                free(GET_label(bstate->obj));

            SET_label(bstate->obj, cp);

            /* rock back, and insert text with hyper directives
             */
            sendMessage1chr_result(bstate->obj, 'i', &evalResult);

            dataBuffIdx = dataBuffIdxStack[dataBuffIdxStackIdx];

            /* rolll back parent's index as well */
            dataBuffIdxStack[dataBuffIdxStackIdx] = src_starti;

            cp = PkInfo2Str(&evalResult);
            if (cp) {
                /* Set parent's label directly with the returned inline data */
                if (parent_bstate && parent_bstate->obj) {
                    char* parent_label = GET_label(parent_bstate->obj);
                    if (parent_label)
                        free(parent_label);
                    SET_label(parent_bstate->obj, saveString(cp));
                }
                /* Also copy to dataBuff for compatibility */
                for (; *cp; cp++)
                    dataBuff[dataBuffIdx++] = *cp;
            }
            clearPacket(&evalResult);
            /*
            printf("INLINE1 obj=%s lidx=%d idx=%d DATA {%s}\n",
            GET_name(bstate->obj), dataBuffIdxStack[dataBuffIdxStackIdx], dataBuffIdx,
            &dataBuff[dataBuffIdxStack[dataBuffIdxStackIdx]]);
            */
            if (parent_bstate && parent_bstate->obj /*lame check*/) {
                VObjList* olist;
                olist = GET__children(parent_bstate->obj);
                olist = removeVObjListNode(olist, (long)bstate->obj);
                SET__children(parent_bstate->obj, olist);
            }
        } else {
            int span;

            /*XXX			src_starti = dataBuffIdxStack[dataBuffIdxStackIdx];
             */
            src_starti = dataBuffIdxStack[dataBuffIdxStackIdx];
            src_endi = dataBuffIdx;
            /*
                                    while (src_starti < src_endi &&
                                          isspace(dataBuff[src_starti]))
                                            src_starti++;
            */
            dataBuffIdxStack[dataBuffIdxStackIdx] = src_starti;

            size = src_endi - src_starti;
            if (size < 0) {
                fprintf(stderr, "html parsing error occured.\n");
                size = 0;
            }
            if (size) {
                cp = (char*)malloc(sizeof(char) * (size + 1));
                if (!cp) {
                    perror("malloc failed");
                    return;
                }
                strncpy(cp, &dataBuff[src_starti], size);
                cp[size] = '\0';
                /* Don't overwrite label if it was already set by inline child (e.g. FIGDATA) */
                char* existing_label = GET_label(bstate->obj);
                if (existing_label && strlen(existing_label) > (size_t)size) {
                    /* Keep existing label - it has more data (from inline child) */
                    free(cp);
                } else {
                    if (existing_label)
                        free(existing_label);
                    SET_label(bstate->obj, cp);
                }
                /*
                printf("etag: obj=%s lidx=%d idx=%d DATA size=%d cp={%s} dataBuffIdxStackIdx=%d\n",
                GET_name(bstate->obj), bstate->dataBuffIdx_localStart,
                dataBuffIdx, size, cp, dataBuffIdxStackIdx);
                */
            }
            /*
            printf("etag: obj=%s lidx=%d idx=%d DATA {%s} dataBuffIdxStackIdx=%d\n",
            GET_name(bstate->obj), dataBuffIdxStack[dataBuffIdxStackIdx - 1],
            dataBuffIdx, GET_label(bstate->obj), dataBuffIdxStackIdx);
            */
            /* in case obj needs this information
             */
            if (parent_bstate)
                SGMLBuildDoc_span = parent_bstate->sub_y;

            /* Pass style attribute to object before calling D method */
            if (bstate->styleAttr) {
                extern int WWW_TraceFlag;
                if (WWW_TraceFlag) printf("### CB_HTML_etag: sending setStyleAttr with %s\n", bstate->styleAttr);
                sendMessage1N1str(bstate->obj, "setStyleAttr", bstate->styleAttr);
                free(bstate->styleAttr); /* Free the copied string */
                bstate->styleAttr = NULL; /* Reset after use to avoid reuse */
            }

            if (parent_bstate != bstate->obj)
                span = getVSpan(bstate->obj, STR_D);
            else
                span = 0;
            if (span == 0) {
                /* destroy object -- it's useless */
                /* safer not to use parent_bstate for parent
                 * info, because of insertion, script action..?
                 */
                VObj* parent = GET__parent(bstate->obj);
                if (parent) {
                    VObjList* olist = GET__children(parent);
                    olist = removeVObjListNode(olist, (long)bstate->obj);
                    sendMessage1(bstate->obj, "freeSelf");
                    SET__children(parent, olist);
                }
                bstate->obj = NULL;

            } else if (span != -1 && bstate->obj) {

                bstate->height = span;
                SET_height(bstate->obj, span);

                span += bstate->tmi->top + bstate->tmi->bottom;

                if (parent_bstate) {
                    parent_bstate->sub_y += span;
                    parent_bstate->height += span;
                    if (parent_bstate->obj)
                        SET_height(parent_bstate->obj, parent_bstate->height);
                }

                /*
                   fprintf(stderr,
                        "XXXX EXITING etag: parent: obj='%s' bs->h=%d bs->sub_y=%d h=%d\n",
                        parent_bstate->obj ? GET_name(parent_bstate->obj) : "<NULL>",
                        parent_bstate->height,
                        parent_bstate->sub_y, bstate->height);
                */
            }
            /*
                    if (bstate->obj)
                        fprintf(stderr,
                    "EXITING etag: obj='%s' bs->h=%d parent_bs->h=%d parent_bs->sub_y=%d\n",
                    GET_name(bstate->obj), bstate->height, parent_bstate->height,
                    parent_bstate->sub_y);
            */
        }
    }
    /*
            if (bstate->obj) {
                    fprintf(stderr,
                            "exiting %s (end). obj='%s'\n", "tag",
                                    GET_name(bstate->obj));
                    fprintf(stderr,
                            "Obj=%s: parent=%s x=%d y=%d width=%d  height=%d\n",
                            GET_name(bstate->obj),
                            GET__parent(bstate->obj) ? GET_name(GET__parent(bstate->obj)) :
       "(NULL)", GET_x(bstate->obj), GET_y(bstate->obj), GET_width(bstate->obj),
       GET_height(bstate->obj));
            }
    */
    if (bstate->tmi) {
        if (bstate->tmi->inlineP && bstate->obj /* && !GET__children(bstate->obj) */) {
            --dataBuffIdxStackIdx;
        } else {
            dataBuffIdx = dataBuffIdxStack[--dataBuffIdxStackIdx];
        }
    }

    if (SBI.stacki > 0 && parent_bstate && parent_bstate->insert) {
        /*		fprintf(stderr, "####### Self: insert=%s, parent_h=%d h=%d\n",
                                GET_name(parent_bstate->insert),
                                parent_bstate->height,
                                bstate->height);
        */
        SGMLBuildDoc_span = bstate->height + bstate->tmi->top + bstate->tmi->bottom;
        SGMLBuildDoc_span = getVSpan(parent_bstate->insert, STR_D);
        parent_bstate->insert = NULL;
    }
    /*
            if (bstate->insert) {
                    fprintf(stderr,
                      "!!!!!!!!!!!! POPing parent that was inserted--------.\n");
                    CB_HTML_etag(-1);
                    fprintf(stderr,
                      "!!!!!!!!!!!! finished POPing------------------------.\n");
            }
    */
}

void CB_HTML_end() {
    SGMLBuildInfoState* bstate;
    int i, elemNum = 0; /*lame*/
    char* tag;
    HTTag* htagp;

    /* Bounds check for stack access */
    if (SBI.stacki < 0 || SBI.stacki >= 100) {
        fprintf(stderr, "CB_HTML_end: stacki out of bounds: %d\n", SBI.stacki);
        return;
    }
    bstate = &SBI.stack[SBI.stacki];
    tag = bstate->tag;

    SBI.endP = 1;

    /* Check if tag is NULL */
    if (!tag) {
        CB_HTML_etag(elemNum);
        return;
    }

    /* do binary search, atleast! */
    for (i = 0; i < HTML_ELEMENTS; i++) {
        htagp = &HTML_dtd.tags[i];
        if (htagp && htagp->name && !strcmp(tag, htagp->name)) {
            CB_HTML_etag(i);
            return;
        }
    }
    CB_HTML_etag(elemNum /*not correct*/);
    /*	fprintf(stderr, "@@@@ HTML END\n");
     */
}

VObj* HTMLBuildObj(SGMLBuildInfoState* bstate, int parentWidth, SGMLTagMappingInfo* tmi)
{
    Packet argv[1];
    char* dtd;
    extern int global_cloneID;
    int mask;
    int containsAnchor = 1;
    /*
            bstate->tmi = &(bstate->tagMappingInfo[
                            bstate->localizingTagIDMap[bstate->tagID]]);
            bstate->tmi = findTMI(SBI.dmi->tagMap, bstate->tag);
    */
    /*
            fprintf(stderr,
                    "HTMLBuildObj: tag '%s' .....................\n",
                    bstate->tmi->tag);
    */
    if (!bstate->tmi->template) {
        /*		fprintf(stderr,
                                "LOADING object '%s'\n", bstate->tmi->type);
        */
        argv[0].info.s = bstate->tmi->type;
        argv[0].type = PKT_STR;
        argv[0].canFree = 0;

        bstate->tmi->template = PkInfo2Obj(&argv[0]);

        if (!bstate->tmi->template) {
            fprintf(stderr, "...can't get template object '%s'\n", bstate->tmi->type);
        }
        if (bstate->tmi->template) {
            bstate->tmi->cloneMeth =
                (long (*)(VObj*, Packet*, int, Packet*))findMeth(bstate->tmi->template, STR_clone);
            if (!bstate->tmi->template) {
                fprintf(stderr, "SGMLBuild_B: can't find clone method for template object '%s'\n",
                        bstate->tmi->type);
            }
        }
    }
    if (!bstate->tmi->template) {
        fprintf(stderr, "HTMLBuildObj: Failed to get template object\n");
        return NULL;
    }
    /* clone template object
     */
    argv[0].info.i = global_cloneID++;
    argv[0].type = PKT_INT;
    argv[0].canFree = 0;

    if (bstate->tmi->inlineP) {
        bstate->obj = bstate->tmi->template;
    } else {
        if (bstate->tmi->cloneMeth)
            bstate->tmi->cloneMeth(bstate->tmi->template, &scrapPk, 1, &argv[0]);
        bstate->obj = scrapPk.info.o;
    }

    if (!bstate->obj) {
        fprintf(stderr, "HTMLBuildObj: failed to clone template object '%s'\n",
                GET_name(bstate->tmi->template));
        fprintf(stderr, "SGMLBuild_B: STR_clone=%d\n", STR_clone);
        callMeth(bstate->tmi->template, &scrapPk, 1, &argv[0], STR_clone);
        bstate->obj = scrapPk.info.o;
        return NULL;
    }
    /*
            fprintf(stderr,
                    "HTMLBuildObj: BUILT: '%s'\n", GET_name(bstate->obj));
    */
    /* Security: set trust level based on document source */
    {
        extern char* current_addr;
        extern int isLocalAddress(const char* addr);
        if (current_addr && isLocalAddress(current_addr)) {
            SET_security(bstate->obj, 0);  /* Local = trusted */
        } else {
            SET_security(bstate->obj, 1);  /* Remote = untrusted */
        }
    }
    
    /* modify template object attributes
     */
    if (bstate->parent && bstate->obj) {
        if (bstate->obj == bstate->parent) {
            /* to avoid circular references possibly
             * caused by bad markup - abort object creation*/
            fprintf(stderr, "Detected illegal recursive use of tag '%s' - aborting to prevent infinite loop.\n", bstate->tmi->tag);
            return NULL;
        } else {
            SET__parent(bstate->obj, bstate->parent);
            SET_parent(bstate->obj, VSaveString(GET__memoryGroup(bstate->obj), GET_name(bstate->parent)));
        }
    }

    if (!bstate->obj) return NULL;

    SET_x(bstate->obj, bstate->tmi->left);

    bstate->y += bstate->tmi->top;
    SET_y(bstate->obj, bstate->y);

    bstate->width = parentWidth - bstate->tmi->left - bstate->tmi->right;
    if (!bstate->tmi->inlineP) {
        SET_width(bstate->obj, bstate->width);
    }

    bstate->sub_width = bstate->width;

    /* not useful now */
    /*
            dtd = SBI.dmi->DTDName;
            SET__varList(bstate->obj,
                    setVariable_id_STR(GET__varList(bstate->obj),
                                    STR_dtd, dtd, 0));
    */
    /* ick ick ick etc */
    if (containsAnchor)
        mask = GET__eventMask(bstate->obj) | PointerMotionMask;
    else
        mask = GET__eventMask(bstate->obj) & ~(EnterWindowMask | LeaveWindowMask);

    SET__eventMask(bstate->obj, mask);

    return bstate->obj;
}

char* encodeURL(char* str)
{
    char *s, *buffp = URLEncodeBuff, *encode;
    unsigned char c;

    while ((c = (unsigned char)*str++) && (encode = URLEncodeSeq[c])) {
        do {
            *buffp++ = *encode++;
        } while (*encode);
    }
    *buffp++ = '\0';

    s = (char*)malloc(sizeof(char) * (buffp - URLEncodeBuff));
    strcpy(s, URLEncodeBuff);

    return s;
}

char* decodeURL(char* str)
{
    char *s = str, *buffp = URLEncodeBuff, dd[3];

    while (*s) {
        if (*s == '%') {
            s++;
            dd[0] = *s++;
            dd[1] = *s++;
            dd[2] = '\0';
            *buffp++ = (char)strtol(dd, NULL, 16);
        } else {
            *buffp++ = *s++;
        }
    }
    *buffp++ = '\0';

    s = (char*)malloc(sizeof(char) * (buffp - URLEncodeBuff));
    strcpy(s, URLEncodeBuff);

    return s;
}

int http_progress_notify(int n)
{
    char notice[256];
    extern int perishableActiveHelp;

    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj) {
        perishableActiveHelp++;

        /*		printf("PROGRES: level=%d   n=%d  subtotal=%d\n",
                               http_progress_reporter_level,
                                n, http_progress_subtotal_bytes);
        */
        http_progress_subtotal_bytes += n;
        if (http_progress_expected_total_bytes && http_progress_reporter_level <= 1) {
            http_progress_total_bytes += n;
            /*
                                    sprintf(notice, "Retrieved %d percent (%d out of %d).",
                                            (int)((float)http_progress_total_bytes /
                                            (float)http_progress_expected_total_bytes *
                                            100.0),
                                            http_progress_total_bytes,
                                            http_progress_expected_total_bytes);
            */
            /*
                                    printf("\t\t\tRetrieved %d percent (%d out of %d).\n",
                                            (int)((float)http_progress_total_bytes /
                                            (float)http_progress_expected_total_bytes *
                                            100.0),
                                            http_progress_total_bytes,
                                            http_progress_expected_total_bytes);
            */
            sendMessage1N2int(mesgObj, "show_progress",
                              (int)((float)http_progress_total_bytes /
                                    (float)http_progress_expected_total_bytes * 100.0),
                              http_progress_total_bytes);
        } else {
            sprintf(notice, "Secondary retrieval: %d bytes.", http_progress_subtotal_bytes);
            /*			printf("Secondary retrieval: %d bytes.\n",
                                            http_progress_subtotal_bytes);
            */
            sendMessage1N1str(mesgObj, "show", notice);
        }
        perishableActiveHelp--;
    }
    return 0;
}

void user_message(char* message)
{
    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj)
        sendMessage1N1str(mesgObj, "show", message);
}

void user_alert(char* message)
{
    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj)
        sendMessage1N1str(mesgObj, "alert", message);
}

int user_message_confirm(char* message)
{
    Packet* result = makePacket();
    int i = 0;

    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj) {
        sendMessage1N1str_result(mesgObj, "dialog_confirm", message, result);
#ifndef VWMOTIF
        modalLoop();
        i = PkInfo2Int(modalResult);
        clearPacket(modalResult);
#else
        i = PkInfo2Int(result);
#endif
    }
    clearPacket(result);
    free(result);
    return i;
}

char* user_prompt_default(char* message, char* deflt)
{
    Packet* result = makePacket();
    char* s = NULL;

    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj) {
        sendMessage1N2str_result(mesgObj, "dialog_prompt_default", message, deflt, result);
#ifndef VWMOTIF
        modalLoop();
        s = saveString(PkInfo2Str(modalResult));
        clearPacket(modalResult);
#else
        s = saveString(PkInfo2Str(result));
#endif
    }
    clearPacket(result);
    free(result);
    return s;
}

char* user_prompt_password(char* message)
{
    Packet* result = makePacket();
    char* s = NULL;

    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj) {
        sendMessage1N1str_result(mesgObj, "dialog_prompt_password", message, result);
#ifndef VWMOTIF
        modalLoop();
        s = saveString(PkInfo2Str(modalResult));
        clearPacket(modalResult);
#else
        s = saveString(PkInfo2Str(result));
#endif
    }
    clearPacket(result);
    free(result);
    return s;
}

void user_prompt_username_and_password(char* message, char** username, char** password)
{
    Packet* result = makePacket();
    char *ret, *s, buff[200];
    int i;

    *username = NULL;
    *password = NULL;

    if (!mesgObj)
        mesgObj = findObject(getIdent("www.mesg.tf"));
    if (mesgObj) {
        sendMessage1N1str_result(mesgObj, "dialog_prompt_username_and_password", message, result);
#ifndef VWMOTIF
        modalLoop();
        ret = PkInfo2Str(modalResult);
#else
        ret = PkInfo2Str(result);
#endif
        s = strchr(ret, '\n');
        i = s - ret;
        strncpy(buff, ret, i);
        buff[i] = '\0';
        trimEdgeSpaces(buff);
        *username = saveString(buff);

        *password = saveString(s);
        trimEdgeSpaces(*password);
#ifndef VWMOTIF
        clearPacket(modalResult);
#endif
    }
    clearPacket(result);
    free(result);
}

void nullifyCallerDataBuff() {
    /* Bounds check for stack access */
    if (SBI.stacki >= 0 && SBI.stacki < 99) {
        dataBuff[SBI.stack[SBI.stacki + 1].dataBuffIdx_localStart] = '\0';
    }
}

Bool initHotList() {
    char *url, *desc, *date, *cp;
    char local_buff[1000];                    /* use local buffer instead of global */
    extern char* vl_expandPath(char*, char*); /* proper declaration */

    cp = vl_expandPath("~/.mosaic-hotlist-default", local_buff);
    if (!cp) {
        return False; /* no home directory or path expansion failed */
    }
    HotList_path = saveString(cp);
    HotList_fp = fopen(HotList_path, "r");
    if (HotList_fp) {
        cp = HotList_nextLine(); /* format id */
        cp = HotList_nextLine(); /* ? */

        for (;;) {
            url = HotList_nextLine(); /* URL */
            if (*url == '\0')
                break;
            date = "";
            for (cp = url; *cp; cp++) {
                if (*cp == ' ') {
                    date = cp + 1;
                    *cp = '\0';
                    break;
                }
            }
            url = saveString(url);
            date = saveString(trimEdgeSpaces(date));
            desc = saveString(HotList_nextLine()); /* Desc */
            if (*desc == '\0')
                break;
            addHotListItem(url, desc, date);
        }
        fclose(HotList_fp);
    }
    HotListLoadedP = 1;

    return 1;
}

Bool addHotListItem(char * url, char * comment, char * date)
{
    HotListItem *new, *l_hip, *hip;

    new = (HotListItem*)malloc(sizeof(struct HotListItem));
    if (!new)
        return 0;
    new->url = url;
    new->comment = comment;
    new->date = trimEdgeSpaces(date);
    new->next = NULL;
    theHotListCount++;

    if (!theHotList) {
        theHotList = new;
        return 1;
    } else {
        for (hip = theHotList; hip; hip = hip->next) {
            if (!hip->next) {
                hip->next = new;
                return 1;
            }
        }
        return 0;
    }
}

HotListItem* getNthHotListItem(int n)
{
    HotListItem* hip;
    int i = 0;

    for (hip = theHotList; hip; hip = hip->next) {
        if (i++ == n) {
            return hip;
        }
    }
    return NULL;
}

Bool deleteHotListItem(int n)
{
    HotListItem *hip, *l_hip = NULL;
    int i = 0;

    for (hip = theHotList; hip; hip = hip->next) {
        if (i++ == n) {
            if (l_hip)
                l_hip->next = hip->next;
            else
                theHotList = hip->next;
            /* free list item */
            theHotListCount--;
            return 1;
        }
        l_hip = hip;
    }
    return 0;
}

char* dumpHotList(int mode)
{
    HotListItem* hip;
    size_t size = 1; /*for last char*/
    char *list, *cp;

    if (mode == 0) {
        for (hip = theHotList; hip; hip = hip->next)
            size += strlen(hip->url) + 1;
        list = cp = (char*)malloc(sizeof(char) * size);
        for (hip = theHotList; hip; hip = hip->next) {
            size = strlen(hip->url);
            strncpy(cp, hip->url, size);
            cp[size] = '\n';
            cp += size + 1;
        }
        *cp = '\0';
        return list;
    } else {
        for (hip = theHotList; hip; hip = hip->next)
            size += strlen(hip->comment) + 1;
        list = cp = (char*)malloc(sizeof(char) * size);
        for (hip = theHotList; hip; hip = hip->next) {
            size = strlen(hip->comment);
            strncpy(cp, hip->comment, size);
            cp[size] = '\n';
            cp += size + 1;
        }
        *cp = '\0';
        return list;
    }
    /*			printf("url     : %s\n", hip->url);
                            printf("date    : %s\n", hip->date);
                            printf("comment : %s\n\n", hip->comment);
    */
    return NULL;
}

/*
 * Save the hot list to file.
 * Returns: 1 on success, 0 on failure (could not open file)
 */
int saveHotList() {
    HotListItem* hip;

    HotList_fp = fopen(HotList_path, "w+");

    if (!HotList_fp) {
        return 0; /* failure: could not open file */
    }
    fprintf(HotList_fp, "ncsa-xmosaic-hotlist-format-1\nDefault\n"); /*ick*/
    for (hip = theHotList; hip; hip = hip->next) {
        fprintf(HotList_fp, "%s %s\n", hip->url, hip->date);
        fprintf(HotList_fp, "%s\n", hip->comment);
    }
    fclose(HotList_fp);
    return 1; /* success */
}

char* HotList_nextLine() {
    int end = 0;
    char c;

    linei = 0;
    for (;;) {
        if (hbuffi >= hbuffLimit) {
            hbuffi = 0;
            hbuffLimit = (int)fread(hbuff, sizeof(char), HBUFF_SIZE - 2, HotList_fp);
            hbuff[hbuffLimit] = '\0';
            if (hbuffLimit == 0)
                goto done;
        }
        c = hbuff[hbuffi++];
        if (c == '\n') {
            goto done;
        } else {
            line[linei++] = c;
        }
    }
done:
    line[linei++] = '\0';
    return line;
}
