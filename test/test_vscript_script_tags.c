/*
 * test_vscript_script_tags.c — Verify VSCRIPT and SCRIPT tag parsing
 *
 * Tests that the SGML parser correctly handles VSCRIPT and SCRIPT tags:
 * - Both use SGML_LITTERAL content model (no nested tag parsing)
 * - Content is delivered as character data
 * - Surrounding HTML is parsed normally
 * - Multiple blocks don't interfere with each other
 * - SCRIPT TYPE attribute is parsed
 *
 * Parser-level integration test: real SGML parser + real HTML DTD,
 * mock HTStructured target that logs callback events.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SGML.h"
#include "HTMLDTD.h"

/* ===================================================================
 * Stubs for symbols referenced by SGML.o / HTString.o
 * =================================================================== */

extern int WWW_TraceFlag;

void CB_HTML_data(char *str, int size) {
    (void)str; (void)size;
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
 * Event logging
 * =================================================================== */

typedef enum { EVT_START, EVT_END, EVT_CHAR } EventType;

typedef struct {
    EventType type;
    int       element;
    char      ch;
    /* For start events: record whether TYPE attribute was present */
    int       has_type_attr;
    char      type_attr_value[64];
} Event;

#define MAX_EVENTS 4096
static Event events[MAX_EVENTS];
static int   event_count;

static void reset_events(void) {
    event_count = 0;
}

/* ===================================================================
 * Mock HTStructured target
 * =================================================================== */

typedef struct {
    HTStructuredClass *isa;
} MockTarget;

static void mock_free(HTStructured *me) { (void)me; }
static void mock_end(HTStructured *me) { (void)me; }
static void mock_abort(HTStructured *me, HTError e) { (void)me; (void)e; }

static void mock_put_character(HTStructured *me, char ch) {
    (void)me;
    if (event_count < MAX_EVENTS) {
        events[event_count].type = EVT_CHAR;
        events[event_count].element = -1;
        events[event_count].ch = ch;
        events[event_count].has_type_attr = 0;
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
    (void)me; (void)tagInfo;
    if (event_count < MAX_EVENTS) {
        events[event_count].type = EVT_START;
        events[event_count].element = element_number;
        events[event_count].ch = 0;
        events[event_count].has_type_attr = 0;
        events[event_count].type_attr_value[0] = '\0';

        if (element_number == HTML_SCRIPT && present && value) {
            if (present[HTML_SCRIPT_TYPE] && value[HTML_SCRIPT_TYPE]) {
                events[event_count].has_type_attr = 1;
                strncpy(events[event_count].type_attr_value,
                        value[HTML_SCRIPT_TYPE],
                        sizeof(events[event_count].type_attr_value) - 1);
                events[event_count].type_attr_value[63] = '\0';
            }
        }
        event_count++;
    }
}

static void mock_end_element(HTStructured *me, int element_number) {
    (void)me;
    if (event_count < MAX_EVENTS) {
        events[event_count].type = EVT_END;
        events[event_count].element = element_number;
        events[event_count].ch = 0;
        events[event_count].has_type_attr = 0;
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
 * Helper: feed HTML through a fresh SGML parser
 * =================================================================== */

static void parse_html(const char *html) {
    HTStream *parser = SGML_new(&HTML_dtd,
                                (HTStructured *)&mock_target,
                                NULL);
    SGML_string(parser, html);
    SGML_free(parser);
}

/* ===================================================================
 * Query helpers
 * =================================================================== */

static int count_starts(int element) {
    int n = 0;
    for (int i = 0; i < event_count; i++)
        if (events[i].type == EVT_START && events[i].element == element)
            n++;
    return n;
}

static int count_ends(int element) {
    int n = 0;
    for (int i = 0; i < event_count; i++)
        if (events[i].type == EVT_END && events[i].element == element)
            n++;
    return n;
}

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

static int no_tag_events_between(int from, int to, int allowed_element) {
    for (int i = from + 1; i < to && i < event_count; i++) {
        if (events[i].type == EVT_START || events[i].type == EVT_END) {
            if (events[i].element != allowed_element)
                return 0;
        }
    }
    return 1;
}

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
 * Test framework
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
 * VSCRIPT tests
 * =================================================================== */

/*
 * 1. Basic VSCRIPT: start/end events fire, content is literal.
 */
static int test_vscript_basic(void) {
    parse_html("<b>before</b><vscript>print(\"hello\");</vscript><b>after</b>");

    ASSERT(count_starts(HTML_VSCRIPT) == 1, "1 <VSCRIPT>");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "1 </VSCRIPT>");
    ASSERT(count_starts(HTML_B) == 2, "2 <B> tags around VSCRIPT");
    ASSERT(count_ends(HTML_B) == 2, "2 </B> tags around VSCRIPT");

    return 1;
}

/*
 * 2. VSCRIPT content is delivered as character data (SGML_LITTERAL).
 */
static int test_vscript_content_as_chardata(void) {
    parse_html("<vscript>print(\"test\");</vscript>");

    int s = find_start(HTML_VSCRIPT, 0);
    int e = find_end(HTML_VSCRIPT, 0);
    ASSERT(s >= 0 && e > s, "VSCRIPT block found");

    char buf[256];
    collect_chars_between(s, e, buf, sizeof(buf));
    ASSERT(strcmp(buf, "print(\"test\");") == 0,
           "VSCRIPT content delivered as character data");

    return 1;
}

/*
 * 3. No phantom tags from angle brackets inside VSCRIPT.
 */
static int test_vscript_no_phantom_tags(void) {
    parse_html("<vscript>if (a < b) { x = y; }</vscript><p>ok</p>");

    ASSERT(count_starts(HTML_VSCRIPT) == 1, "1 <VSCRIPT>");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "1 </VSCRIPT>");
    ASSERT(count_starts(HTML_B) == 0, "no phantom <B> from a < b");
    ASSERT(count_starts(HTML_P) == 1, "<P> after VSCRIPT parsed");

    int s = find_start(HTML_VSCRIPT, 0);
    int e = find_end(HTML_VSCRIPT, 0);
    ASSERT(no_tag_events_between(s, e, HTML_VSCRIPT),
           "no phantom tags inside VSCRIPT");

    return 1;
}

/*
 * 4. Empty VSCRIPT block.
 */
static int test_vscript_empty(void) {
    parse_html("<p>a</p><vscript></vscript><p>b</p>");

    ASSERT(count_starts(HTML_VSCRIPT) == 1, "1 <VSCRIPT>");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "1 </VSCRIPT>");
    ASSERT(count_starts(HTML_P) == 2, "2 <P> tags around empty VSCRIPT");

    int s = find_start(HTML_VSCRIPT, 0);
    int e = find_end(HTML_VSCRIPT, 0);
    ASSERT(e == s + 1, "empty VSCRIPT: no events between open/close");

    return 1;
}

/*
 * 5. Content before VSCRIPT is not affected.
 */
static int test_vscript_content_before(void) {
    parse_html("<b>visible</b><vscript>code();</vscript>");

    int bs = find_start(HTML_B, 0);
    int be = find_end(HTML_B, 0);
    ASSERT(bs >= 0 && be > bs, "<B> block found before VSCRIPT");

    char buf[256];
    collect_chars_between(bs, be, buf, sizeof(buf));
    ASSERT(strcmp(buf, "visible") == 0,
           "text before VSCRIPT is 'visible'");

    return 1;
}

/*
 * 6. Content after VSCRIPT is parsed normally.
 */
static int test_vscript_content_after(void) {
    parse_html("<vscript>ignored</vscript><b>visible</b>");

    ASSERT(count_starts(HTML_B) == 1, "<B> after VSCRIPT exists");

    int bs = find_start(HTML_B, 0);
    int be = find_end(HTML_B, 0);
    char buf[256];
    collect_chars_between(bs, be, buf, sizeof(buf));
    ASSERT(strcmp(buf, "visible") == 0,
           "text after VSCRIPT is 'visible'");

    return 1;
}

/* ===================================================================
 * SCRIPT tests (with TYPE attribute for viola scripts)
 * =================================================================== */

/*
 * 7. SCRIPT TYPE="viola" — attribute is parsed and content is literal.
 */
static int test_script_type_viola(void) {
    parse_html("<script type=\"viola\">print(\"hi\");</script><b>ok</b>");

    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT) == 1, "1 </SCRIPT>");
    ASSERT(count_starts(HTML_B) == 1, "<B> after SCRIPT parsed");

    int s = find_start(HTML_SCRIPT, 0);
    ASSERT(s >= 0, "SCRIPT start found");
    ASSERT(events[s].has_type_attr == 1, "TYPE attribute present");
    ASSERT(strcmp(events[s].type_attr_value, "viola") == 0,
           "TYPE attribute value is 'viola'");

    return 1;
}

/*
 * 8. SCRIPT content is delivered as character data.
 */
static int test_script_content_as_chardata(void) {
    parse_html("<script>var x = 1;</script>");

    int s = find_start(HTML_SCRIPT, 0);
    int e = find_end(HTML_SCRIPT, 0);
    ASSERT(s >= 0 && e > s, "SCRIPT block found");

    char buf[256];
    collect_chars_between(s, e, buf, sizeof(buf));
    ASSERT(strcmp(buf, "var x = 1;") == 0,
           "SCRIPT content delivered as character data");

    return 1;
}

/*
 * 9. SCRIPT without TYPE attribute.
 */
static int test_script_no_type(void) {
    parse_html("<script>alert(1);</script>");

    int s = find_start(HTML_SCRIPT, 0);
    ASSERT(s >= 0, "SCRIPT start found");
    ASSERT(events[s].has_type_attr == 0, "no TYPE attribute");

    return 1;
}

/* ===================================================================
 * Combined VSCRIPT + SCRIPT tests
 * =================================================================== */

/*
 * 10. VSCRIPT followed by SCRIPT — no state bleeding.
 */
static int test_vscript_then_script(void) {
    parse_html(
        "<vscript>print(\"a\");</vscript>"
        "<p>between</p>"
        "<script type=\"viola\">print(\"b\");</script>"
        "<p>end</p>"
    );

    ASSERT(count_starts(HTML_VSCRIPT) == 1, "1 <VSCRIPT>");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "1 </VSCRIPT>");
    ASSERT(count_starts(HTML_SCRIPT) == 1, "1 <SCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT) == 1, "1 </SCRIPT>");
    ASSERT(count_starts(HTML_P) == 2, "2 <P> tags between/after blocks");

    int vs_e = find_end(HTML_VSCRIPT, 0);
    int sc_s = find_start(HTML_SCRIPT, 0);
    ASSERT(vs_e < sc_s, "VSCRIPT ends before SCRIPT starts");

    return 1;
}

/*
 * 11. Multiple VSCRIPT blocks.
 */
static int test_multiple_vscript(void) {
    parse_html(
        "<vscript>first();</vscript>"
        "<p>mid</p>"
        "<vscript>second();</vscript>"
    );

    ASSERT(count_starts(HTML_VSCRIPT) == 2, "2 <VSCRIPT> starts");
    ASSERT(count_ends(HTML_VSCRIPT) == 2, "2 </VSCRIPT> ends");
    ASSERT(count_starts(HTML_P) == 1, "1 <P> between them");

    int s1 = find_start(HTML_VSCRIPT, 0);
    int e1 = find_end(HTML_VSCRIPT, 0);
    char buf[256];
    collect_chars_between(s1, e1, buf, sizeof(buf));
    ASSERT(strcmp(buf, "first();") == 0, "first VSCRIPT content correct");

    int s2 = find_start(HTML_VSCRIPT, 1);
    int e2 = find_end(HTML_VSCRIPT, 1);
    collect_chars_between(s2, e2, buf, sizeof(buf));
    ASSERT(strcmp(buf, "second();") == 0, "second VSCRIPT content correct");

    return 1;
}

/*
 * 12. VSCRIPT + SCRIPT + SCRIPT TYPE="viola" in one document
 *     (mirrors test_vscript.html).
 */
static int test_full_document_like_testfile(void) {
    parse_html(
        "<html><head><title>Test</title></head><body>"
        "<vscript>print(\"HELLO\");</vscript>"
        "<script type=\"viola\">print(\"VIOLA\");</script>"
        "<script>alert(\"JS\");</script>"
        "</body></html>"
    );

    ASSERT(count_starts(HTML_VSCRIPT) == 1, "1 <VSCRIPT>");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "1 </VSCRIPT>");
    ASSERT(count_starts(HTML_SCRIPT) == 2, "2 <SCRIPT> (viola + JS)");
    ASSERT(count_ends(HTML_SCRIPT) == 2, "2 </SCRIPT>");
    ASSERT(count_starts(HTML_TITLE) == 1, "1 <TITLE>");
    ASSERT(count_starts(HTML_BODY) == 1, "1 <BODY>");

    int vs = find_start(HTML_VSCRIPT, 0);
    int ve = find_end(HTML_VSCRIPT, 0);
    char buf[256];
    collect_chars_between(vs, ve, buf, sizeof(buf));
    ASSERT(strcmp(buf, "print(\"HELLO\");") == 0,
           "VSCRIPT content preserved");

    int sc1 = find_start(HTML_SCRIPT, 0);
    ASSERT(events[sc1].has_type_attr == 1,
           "first SCRIPT has TYPE attr");
    ASSERT(strcmp(events[sc1].type_attr_value, "viola") == 0,
           "first SCRIPT TYPE is 'viola'");

    int sc2 = find_start(HTML_SCRIPT, 1);
    ASSERT(events[sc2].has_type_attr == 0,
           "second SCRIPT has no TYPE attr");

    return 1;
}

/*
 * 13. Case-insensitive close for VSCRIPT.
 */
static int test_vscript_case_insensitive_close(void) {
    parse_html("<vscript>a</Vscript>");
    ASSERT(count_starts(HTML_VSCRIPT) == 1, "<vscript> opened");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "</Vscript> closed it");

    reset_events();
    parse_html("<VSCRIPT>b</vscript>");
    ASSERT(count_starts(HTML_VSCRIPT) == 1, "<VSCRIPT> opened");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "</vscript> closed it");

    return 1;
}

/*
 * 14. Cross-tag close: </script> inside <vscript> must not close VSCRIPT.
 */
static int test_vscript_cross_tag_close(void) {
    parse_html("<vscript>var s = \"</script>\";</vscript><b>ok</b>");

    ASSERT(count_starts(HTML_VSCRIPT) == 1, "1 <VSCRIPT>");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "1 </VSCRIPT>");
    ASSERT(count_ends(HTML_SCRIPT) == 0,
           "</script> inside <vscript> must not generate end(SCRIPT)");
    ASSERT(count_starts(HTML_B) == 1, "<B> parsed after block");

    return 1;
}

/*
 * 15. VSCRIPT with multiline content.
 */
static int test_vscript_multiline(void) {
    parse_html(
        "<vscript>\n"
        "x = 1;\n"
        "y = 2;\n"
        "</vscript>"
    );

    ASSERT(count_starts(HTML_VSCRIPT) == 1, "1 <VSCRIPT>");
    ASSERT(count_ends(HTML_VSCRIPT) == 1, "1 </VSCRIPT>");

    int s = find_start(HTML_VSCRIPT, 0);
    int e = find_end(HTML_VSCRIPT, 0);
    char buf[256];
    collect_chars_between(s, e, buf, sizeof(buf));
    ASSERT(strstr(buf, "x = 1;") != NULL, "first line preserved");
    ASSERT(strstr(buf, "y = 2;") != NULL, "second line preserved");

    return 1;
}

/* ===================================================================
 * Main
 * =================================================================== */

int main(void) {
    WWW_TraceFlag = 0;

    printf("==============================================\n");
    printf("  VSCRIPT / SCRIPT Tag Parsing Tests\n");
    printf("==============================================\n");

    RUN_TEST(test_vscript_basic);
    RUN_TEST(test_vscript_content_as_chardata);
    RUN_TEST(test_vscript_no_phantom_tags);
    RUN_TEST(test_vscript_empty);
    RUN_TEST(test_vscript_content_before);
    RUN_TEST(test_vscript_content_after);
    RUN_TEST(test_script_type_viola);
    RUN_TEST(test_script_content_as_chardata);
    RUN_TEST(test_script_no_type);
    RUN_TEST(test_vscript_then_script);
    RUN_TEST(test_multiple_vscript);
    RUN_TEST(test_full_document_like_testfile);
    RUN_TEST(test_vscript_case_insensitive_close);
    RUN_TEST(test_vscript_cross_tag_close);
    RUN_TEST(test_vscript_multiline);

    printf("==============================================\n");
    printf("  Results: %d passed, %d failed (%d assertions)\n",
           tests_passed, tests_failed, asserts_total);
    printf("==============================================\n");

    return tests_failed ? 1 : 0;
}
