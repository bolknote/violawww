/*
 * test_script_style_skip.c — Verify SCRIPT/STYLE content skipping
 *
 * Tests that the SGML parser (with SGML_LITTERAL content model) correctly
 * isolates SCRIPT and STYLE blocks: no phantom tags are generated from
 * their content, only the exact matching close tag terminates the block,
 * and surrounding HTML is parsed normally.
 *
 * This is a parser-level integration test: we feed raw HTML through the
 * real SGML parser with the real HTML DTD, but replace the downstream
 * HTStructured target with a mock that records every callback event.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SGML.h"
#include "HTMLDTD.h"

/* ===================================================================
 * Stubs for symbols that SGML.o / HTString.o reference but we don't need
 * =================================================================== */

/* WWW_TraceFlag is defined in HTString.o — declare as extern here */
extern int WWW_TraceFlag;

void CB_HTML_data(char *str, int size) {
    /* Called directly from SGML.c for HTML comment content.
     * In a test we just ignore it. */
    (void)str;
    (void)size;
}

char *HTAnchor_charset(void *anchor) {
    (void)anchor;
    return NULL;
}

int HTCharset_convert_to_ascii(const char *charset,
                               const char *in, int inlen,
                               char *out, int outlen) {
    (void)charset; (void)in; (void)inlen; (void)out; (void)outlen;
    return 0;
}

int http_progress_notify(int n) {
    (void)n;
    return 0;
}

/* ===================================================================
 * Event logging infrastructure
 * =================================================================== */

typedef enum { EVT_START, EVT_END, EVT_CHAR } EventType;

typedef struct {
    EventType type;
    int       element;   /* for EVT_START / EVT_END */
    char      ch;        /* for EVT_CHAR */
} Event;

#define MAX_EVENTS 4096
static Event events[MAX_EVENTS];
static int   event_count;

static void reset_events(void) {
    event_count = 0;
}

/* ===================================================================
 * Mock HTStructured target
 *
 * The SGML parser extracts the vtable via:
 *     context->actions = (HTStructuredClass*)(((HTStream*)target)->isa);
 * So the first field of our struct must be a pointer that the parser
 * will interpret as HTStructuredClass*.
 * =================================================================== */

typedef struct {
    HTStructuredClass *isa;   /* MUST be first — SGML_new reads it */
} MockTarget;

static void mock_free     (HTStructured *me) { (void)me; }
static void mock_end      (HTStructured *me) { (void)me; }
static void mock_abort    (HTStructured *me, HTError e) { (void)me; (void)e; }

static void mock_put_character(HTStructured *me, char ch) {
    (void)me;
    if (event_count < MAX_EVENTS) {
        events[event_count].type    = EVT_CHAR;
        events[event_count].element = -1;
        events[event_count].ch      = ch;
        event_count++;
    }
}

static void mock_put_string(HTStructured *me, const char *str) {
    (void)me; (void)str;
}

static void mock_progress(HTStructured *me, int n) {
    (void)me; (void)n;
}

static void mock_write(HTStructured *me, const char *str, int len) {
    (void)me; (void)str; (void)len;
}

static void mock_start_element(HTStructured *me, int element_number,
                               const BOOL *present,
                               const char **value,
                               HTTag *tagInfo) {
    (void)me; (void)present; (void)value; (void)tagInfo;
    if (event_count < MAX_EVENTS) {
        events[event_count].type    = EVT_START;
        events[event_count].element = element_number;
        events[event_count].ch      = 0;
        event_count++;
    }
}

static void mock_end_element(HTStructured *me, int element_number) {
    (void)me;
    if (event_count < MAX_EVENTS) {
        events[event_count].type    = EVT_END;
        events[event_count].element = element_number;
        events[event_count].ch      = 0;
        event_count++;
    }
}

static void mock_put_entity(HTStructured *me, int entity_number) {
    (void)me; (void)entity_number;
}

static HTStructuredClass mock_class = {
    "MockTarget",
    mock_free,
    mock_end,
    mock_abort,
    mock_put_character,
    mock_put_string,
    mock_progress,
    mock_write,
    mock_start_element,
    mock_end_element,
    mock_put_entity
};

static MockTarget mock_target = { &mock_class };

/* ===================================================================
 * Helper: feed an HTML string through a fresh SGML parser
 * =================================================================== */

static void parse_html(const char *html) {
    HTStream *parser = SGML_new(&HTML_dtd,
                                (HTStructured *)&mock_target,
                                NULL /* no anchor */);
    SGML_string(parser, html);
    /* Clean up parser internals (calls mock_free, which is a no-op) */
    SGML_free(parser);
}

/* ===================================================================
 * Helper: query the event log
 * =================================================================== */

/* Count how many start-element events exist for a given tag */
static int count_starts(int element) {
    int n = 0;
    for (int i = 0; i < event_count; i++)
        if (events[i].type == EVT_START && events[i].element == element)
            n++;
    return n;
}

/* Count how many end-element events exist for a given tag */
static int count_ends(int element) {
    int n = 0;
    for (int i = 0; i < event_count; i++)
        if (events[i].type == EVT_END && events[i].element == element)
            n++;
    return n;
}

/* Find index of the Nth occurrence of start(element).  Returns -1 if not found. */
static int find_start(int element, int nth) {
    int seen = 0;
    for (int i = 0; i < event_count; i++) {
        if (events[i].type == EVT_START && events[i].element == element) {
            if (seen == nth) return i;
            seen++;
        }
    }
    return -1;
}

/* Find index of the Nth occurrence of end(element).  Returns -1 if not found. */
static int find_end(int element, int nth) {
    int seen = 0;
    for (int i = 0; i < event_count; i++) {
        if (events[i].type == EVT_END && events[i].element == element) {
            if (seen == nth) return i;
            seen++;
        }
    }
    return -1;
}

/* Check that no start_element / end_element events (for tags OTHER than
 * `allowed_element`) appear between event indices `from` and `to` (exclusive). */
static int no_tag_events_between(int from, int to, int allowed_element) {
    for (int i = from + 1; i < to && i < event_count; i++) {
        if (events[i].type == EVT_START || events[i].type == EVT_END) {
            if (events[i].element != allowed_element)
                return 0;  /* found a rogue tag event */
        }
    }
    return 1;
}

/* Collect all put_character data between event indices `from` and `to`
 * (exclusive) into `buf`.  Returns length written. */
static int collect_chars_between(int from, int to, char *buf, int bufsize) {
    int n = 0;
    for (int i = from + 1; i < to && i < event_count; i++) {
        if (events[i].type == EVT_CHAR && n < bufsize - 1)
            buf[n++] = events[i].ch;
    }
    buf[n] = '\0';
    return n;
}

/* ===================================================================
 * Test framework helpers
 * =================================================================== */

static int tests_passed  = 0;
static int tests_failed  = 0;
static int asserts_total = 0;

#define ASSERT(cond, msg) do { \
    asserts_total++; \
    if (!(cond)) { \
        fprintf(stderr, "  FAIL: %s  (line %d)\n", msg, __LINE__); \
        return 0; \
    } \
} while(0)

#define RUN_TEST(fn) do { \
    printf("  %-60s", #fn); \
    reset_events(); \
    if (fn()) { \
        printf("PASS\n"); \
        tests_passed++; \
    } else { \
        printf("FAIL\n"); \
        tests_failed++; \
    } \
} while(0)

/* ===================================================================
 * Test cases
 * =================================================================== */

/*
 * 1. Basic: tags inside <script> must NOT be parsed as real HTML tags.
 *    The < in "a < b" would previously be interpreted as opening a <B> tag.
 */
static int test_script_no_phantom_tags(void) {
    parse_html("<b>vis</b><script>if (a < b) { x(); }</script><b>vis2</b>");

    /* Two <B> tags: one before and one after the script block */
    ASSERT(count_starts(HTML_B) == 2,
           "expected exactly 2 <B> start events (before and after script)");
    ASSERT(count_ends(HTML_B) == 2,
           "expected exactly 2 </B> end events");

    /* Exactly one SCRIPT open/close */
    ASSERT(count_starts(HTML_SCRIPT) == 1, "expected 1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT) == 1,   "expected 1 </SCRIPT>");

    /* No tag events between SCRIPT open and close (only char data) */
    int s = find_start(HTML_SCRIPT, 0);
    int e = find_end(HTML_SCRIPT, 0);
    ASSERT(s >= 0 && e > s,
           "SCRIPT start must precede SCRIPT end");
    ASSERT(no_tag_events_between(s, e, HTML_SCRIPT),
           "no phantom tags between <SCRIPT> and </SCRIPT>");

    return 1;
}

/*
 * 2. document.write("<p>hello</p>") inside script must not generate
 *    start_element(P) / end_element(P).
 */
static int test_script_docwrite_tags(void) {
    parse_html("<script>document.write(\"<p>hello</p>\");</script>");

    ASSERT(count_starts(HTML_P) == 0, "no <P> tag from script content");
    ASSERT(count_ends(HTML_P)   == 0, "no </P> tag from script content");
    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "1 </SCRIPT>");

    return 1;
}

/*
 * 3. CSS selectors with > (child combinator) and < in attr selectors.
 */
static int test_style_css_selectors(void) {
    parse_html("<style>div > p { color: red; } a[href^=\"<\"] { display: none; }</style><b>after</b>");

    ASSERT(count_starts(HTML_STYLE) == 1, "1 <STYLE>");
    ASSERT(count_ends(HTML_STYLE)   == 1, "1 </STYLE>");
    ASSERT(count_starts(HTML_B)     == 1, "<B> after style block is parsed");
    ASSERT(count_ends(HTML_B)       == 1, "</B> after style block is parsed");

    /* No phantom tags inside the style block */
    int s = find_start(HTML_STYLE, 0);
    int e = find_end(HTML_STYLE, 0);
    ASSERT(no_tag_events_between(s, e, HTML_STYLE),
           "no phantom tags inside STYLE block");

    return 1;
}

/*
 * 4. Cross-tag close: </style> inside <script> must NOT close the block.
 *    Only </script> should terminate it.
 */
static int test_cross_tag_close_in_script(void) {
    parse_html("<script>var s = \"</style>\";</script><b>ok</b>");

    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "1 </SCRIPT>");
    /* </style> must NOT generate a STYLE end event */
    ASSERT(count_ends(HTML_STYLE)    == 0,
           "</style> inside <script> must not generate end(STYLE)");
    /* <b> after the block is parsed normally */
    ASSERT(count_starts(HTML_B) == 1, "<B> parsed after block");

    return 1;
}

/*
 * 5. Cross-tag close: </script> inside <style> must NOT close the block.
 */
static int test_cross_tag_close_in_style(void) {
    parse_html("<style>/* </script> */</style><b>ok</b>");

    ASSERT(count_starts(HTML_STYLE) == 1, "1 <STYLE>");
    ASSERT(count_ends(HTML_STYLE)   == 1, "1 </STYLE>");
    ASSERT(count_ends(HTML_SCRIPT)  == 0,
           "</script> inside <style> must not generate end(SCRIPT)");
    ASSERT(count_starts(HTML_B)     == 1, "<B> parsed after block");

    return 1;
}

/*
 * 6. Empty SCRIPT block: <script></script> — no content, no issues.
 */
static int test_empty_script(void) {
    parse_html("<b>a</b><script></script><b>b</b>");

    ASSERT(count_starts(HTML_B) == 2, "2 <B> tags around empty script");
    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "1 </SCRIPT>");

    int s = find_start(HTML_SCRIPT, 0);
    int e = find_end(HTML_SCRIPT, 0);
    ASSERT(e == s + 1, "empty script has no events between open/close");

    return 1;
}

/*
 * 7. Multiple SCRIPT and STYLE blocks — no state bleeding between them.
 */
static int test_multiple_blocks(void) {
    parse_html(
        "<style>p{}</style>"
        "<b>mid</b>"
        "<script>x();</script>"
        "<b>end</b>"
    );

    ASSERT(count_starts(HTML_STYLE)  == 1, "1 <STYLE>");
    ASSERT(count_ends(HTML_STYLE)    == 1, "1 </STYLE>");
    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "1 </SCRIPT>");
    ASSERT(count_starts(HTML_B)      == 2, "2 <B> tags between blocks");

    /* Verify ordering: STYLE comes before SCRIPT */
    int style_e = find_end(HTML_STYLE, 0);
    int script_s = find_start(HTML_SCRIPT, 0);
    ASSERT(style_e < script_s, "STYLE block ends before SCRIPT block starts");

    return 1;
}

/*
 * 8. HTML comment syntax <!-- --> inside SCRIPT treated as literal data,
 *    not as a real HTML comment (the classic 90s JS-in-comments pattern).
 */
static int test_html_comment_in_script(void) {
    parse_html("<script><!--\nvar x = 1;\n//--></script><b>ok</b>");

    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "1 </SCRIPT>");
    ASSERT(count_starts(HTML_B)      == 1, "<B> after script is parsed");

    /* No phantom tags from the comment syntax */
    int s = find_start(HTML_SCRIPT, 0);
    int e = find_end(HTML_SCRIPT, 0);
    ASSERT(no_tag_events_between(s, e, HTML_SCRIPT),
           "<!-- inside script does not create phantom tags");

    return 1;
}

/*
 * 9. Case-insensitive close tag: </Script>, </SCRIPT>, </sCrIpT>
 *    must all close the block (LITTERAL uses TOUPPER matching).
 */
static int test_case_insensitive_close(void) {
    /* Mixed-case close tag */
    parse_html("<script>a</Script>");
    ASSERT(count_starts(HTML_SCRIPT) == 1, "<script> opened");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "</Script> closed it");

    reset_events();
    parse_html("<SCRIPT>b</script>");
    ASSERT(count_starts(HTML_SCRIPT) == 1, "<SCRIPT> opened");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "</script> closed it");

    reset_events();
    parse_html("<script>c</sCrIpT>");
    ASSERT(count_starts(HTML_SCRIPT) == 1, "<script> opened");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "</sCrIpT> closed it");

    return 1;
}

/*
 * 10. Content after </script> is parsed normally: verify data fidelity.
 */
static int test_content_after_script(void) {
    parse_html("<script>ignored</script><b>visible</b>");

    ASSERT(count_starts(HTML_B) == 1, "<B> after script exists");
    ASSERT(count_ends(HTML_B)   == 1, "</B> after script exists");

    /* Collect character data between <B> and </B> */
    int bs = find_start(HTML_B, 0);
    int be = find_end(HTML_B, 0);
    char buf[256];
    collect_chars_between(bs, be, buf, sizeof(buf));
    ASSERT(strcmp(buf, "visible") == 0,
           "text after script block is 'visible'");

    return 1;
}

/*
 * 11. SCRIPT content IS delivered as character data (not swallowed by parser).
 *     The html2.c layer suppresses it via inside_ignore_element, but the
 *     SGML parser itself correctly delivers it through put_character.
 */
static int test_script_content_as_chardata(void) {
    parse_html("<script>hello</script>");

    int s = find_start(HTML_SCRIPT, 0);
    int e = find_end(HTML_SCRIPT, 0);
    ASSERT(s >= 0 && e > s, "SCRIPT block found");

    char buf[256];
    collect_chars_between(s, e, buf, sizeof(buf));
    ASSERT(strcmp(buf, "hello") == 0,
           "SCRIPT content delivered as character data");

    return 1;
}

/*
 * 12. Content BEFORE <script> is not affected — verify data fidelity.
 */
static int test_content_before_script(void) {
    parse_html("<b>before</b><script>junk</script>");

    int bs = find_start(HTML_B, 0);
    int be = find_end(HTML_B, 0);
    ASSERT(bs >= 0 && be > bs, "<B> block found before script");

    char buf[256];
    collect_chars_between(bs, be, buf, sizeof(buf));
    ASSERT(strcmp(buf, "before") == 0,
           "text before script is 'before'");

    return 1;
}

/*
 * 13. SCRIPT with TYPE attribute — attributes are still parsed.
 */
static int test_script_with_attributes(void) {
    parse_html("<script type=\"text/javascript\">code</script><b>ok</b>");

    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "1 </SCRIPT>");
    ASSERT(count_starts(HTML_B)      == 1, "<B> after script");

    int s = find_start(HTML_SCRIPT, 0);
    int e = find_end(HTML_SCRIPT, 0);
    char buf[256];
    collect_chars_between(s, e, buf, sizeof(buf));
    ASSERT(strcmp(buf, "code") == 0,
           "content after attribute still delivered");

    return 1;
}

/*
 * 14. Angle brackets galore inside script — stress test.
 *     JS comparison operators, generics, template literals, etc.
 */
static int test_script_many_angle_brackets(void) {
    parse_html(
        "<script>"
        "if (a<b && c>d) { e=f<g; }"
        "var t = '<div class=\"x\">';"
        "x = 1 << 2; y = 8 >> 1;"
        "</script>"
        "<p>safe</p>"
    );

    /* The ONLY element events should be SCRIPT and P */
    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "1 </SCRIPT>");
    ASSERT(count_starts(HTML_P)      == 1, "1 <P> after script");
    ASSERT(count_ends(HTML_P)        == 1, "1 </P> after script");

    /* Specifically: no <B>, <G>, <DIV> phantom tags */
    ASSERT(count_starts(HTML_B)   == 0, "no phantom <B> from a<b");
    ASSERT(count_starts(HTML_DL)  == 0, "no phantom <DL>");  /* d is not a tag */

    int s = find_start(HTML_SCRIPT, 0);
    int e = find_end(HTML_SCRIPT, 0);
    ASSERT(no_tag_events_between(s, e, HTML_SCRIPT),
           "no tag events inside script with many angle brackets");

    return 1;
}

/*
 * 15. STYLE followed by SCRIPT — verify independent isolation.
 */
static int test_style_then_script_isolation(void) {
    parse_html(
        "<style>.a < .b { }</style>"
        "<p>between</p>"
        "<script>if (x < y) z();</script>"
        "<p>end</p>"
    );

    ASSERT(count_starts(HTML_STYLE)  == 1, "1 <STYLE>");
    ASSERT(count_ends(HTML_STYLE)    == 1, "1 </STYLE>");
    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT)   == 1, "1 </SCRIPT>");
    ASSERT(count_starts(HTML_P)      == 2, "2 <P> tags between/after blocks");

    return 1;
}

/* ===================================================================
 * Main
 * =================================================================== */

int main(void) {
    /* Suppress SGML parser trace output during tests */
    WWW_TraceFlag = 0;

    printf("==============================================\n");
    printf("  SCRIPT/STYLE Skipping Tests (SGML parser)\n");
    printf("==============================================\n");

    RUN_TEST(test_script_no_phantom_tags);
    RUN_TEST(test_script_docwrite_tags);
    RUN_TEST(test_style_css_selectors);
    RUN_TEST(test_cross_tag_close_in_script);
    RUN_TEST(test_cross_tag_close_in_style);
    RUN_TEST(test_empty_script);
    RUN_TEST(test_multiple_blocks);
    RUN_TEST(test_html_comment_in_script);
    RUN_TEST(test_case_insensitive_close);
    RUN_TEST(test_content_after_script);
    RUN_TEST(test_script_content_as_chardata);
    RUN_TEST(test_content_before_script);
    RUN_TEST(test_script_with_attributes);
    RUN_TEST(test_script_many_angle_brackets);
    RUN_TEST(test_style_then_script_isolation);

    printf("==============================================\n");
    printf("  Results: %d passed, %d failed (%d assertions)\n",
           tests_passed, tests_failed, asserts_total);
    printf("==============================================\n");

    return tests_failed ? 1 : 0;
}
