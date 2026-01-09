/*
 * Test HTMIME parser with real Wayback data
 * Reads: test/res/wayback_response.bin
 * Created: curl -sS -D - "URL" | tail -c +14 > res/wayback_response.bin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ========== Minimal stubs for HTMIME dependencies ========== */

typedef void* HTAtom;
typedef void* HTParentAnchor;
typedef void* HTPresentation;
typedef int HTFormat;
typedef int HTError;

#define WWW_PLAINTEXT 0
#define FROMASCII(c) (c)
#define CR '\r'
#define LF '\n'
#define YES 1
#define NO 0
#define PRIVATE static
#define PUBLIC
#define ARGS2(t1,n1,t2,n2) (t1 n1, t2 n2)
#define ARGS3(t1,n1,t2,n2,t3,n3) (t1 n1, t2 n2, t3 n3)
#define TRACE 0
#define WHITE(c) (((unsigned char)(c)) <= 32)
#define TOLOWER(c) (((c) >= 'A' && (c) <= 'Z') ? (c) + 32 : (c))

char* HTAtom_name(HTAtom a) { return "test"; }
void outofmem(const char* f, const char* m) { exit(1); }

/* ========== HTMIME parser states ========== */

typedef enum {
    MIME_TRANSPARENT,
    BEGINNING_OF_LINE,
    CONTENT_T,
    CONTENT_TRANSFER_ENCODING,
    CONTENT_TYPE,
    X_ARCHIVE_GUESSED_CHARSET,
    SKIP_GET_VALUE,
    GET_VALUE,
    JUNK_LINE,
    NEWLINE,
    CHECK,
    MIME_NET_ASCII,
    MIME_IGNORE
} MIMEState;

/* Stream class - forward declare struct */
typedef struct _HTStreamClass HTStreamClass;
typedef struct _HTStream HTStream;

struct _HTStreamClass {
    char* name;
    void (*free)(HTStream* me);
    void (*abort)(HTStream* me, HTError e);
    void (*put_character)(HTStream* me, char c);
    void (*put_string)(HTStream* me, const char* s);
    void (*put_block)(HTStream* me, const char* s, int len);
};

struct _HTStream {
    HTStreamClass* isa;
    HTStream* sink;
    HTParentAnchor* anchor;
    HTStream* target;
    HTStreamClass targetClass;
    HTFormat format;
    HTFormat targetRep;
    MIMEState state;
    MIMEState fold_state;
    MIMEState if_ok;
    const char* check_pointer;
    char* boundary;
    int net_ascii;
    int char_count;
};

/* Track body output */
static int body_started = 0;
static int total_body_bytes = 0;
static char first_body[200];

static void sink_free(HTStream* me) {}
static void sink_abort(HTStream* me, HTError e) {}
static void sink_put_char(HTStream* me, char c) {
    if (!body_started) {
        body_started = 1;
        printf("*** BODY STARTED ***\n");
    }
    if (total_body_bytes < 199) first_body[total_body_bytes] = c;
    total_body_bytes++;
}
static void sink_put_string(HTStream* me, const char* s) {
    while (*s) sink_put_char(me, *s++);
}
static void sink_put_block(HTStream* me, const char* s, int len) {
    for (int i = 0; i < len; i++) sink_put_char(me, s[i]);
}

static HTStreamClass sink_class = {
    "TestSink", sink_free, sink_abort, sink_put_char, sink_put_string, sink_put_block
};
static HTStream sink_stream = { &sink_class };
HTStream* HTStreamStack(HTFormat a, HTFormat b, HTStream* c, HTParentAnchor* d) {
    return &sink_stream;
}

PRIVATE void HTMIME_put_character(HTStream* me, char c) {
    me->char_count++;
    
    /* Debug around header end */
    if (me->char_count >= 1880 && me->char_count <= 2000) {
        fprintf(stderr, "[%d] state=%d char='%c'(0x%02x)\n", 
                me->char_count, me->state, 
                (c >= 32 && c < 127) ? c : '.', (unsigned char)c);
    }
    
    if (me->state == MIME_TRANSPARENT) {
        (*me->targetClass.put_character)(me->target, c);
        return;
    }

    if (me->net_ascii) {
        c = FROMASCII(c);
        if (c == CR) return;
        else if (c == LF) c = '\n';
    }

    switch (me->state) {
    case MIME_IGNORE:
        return;
    case MIME_TRANSPARENT:
        (*me->targetClass.put_character)(me->target, c);
        return;
    case MIME_NET_ASCII:
        (*me->targetClass.put_character)(me->target, c);
        return;

    case NEWLINE:
        if (c == '\r') break;
        if (c != '\n' && WHITE(c)) {
            me->state = me->fold_state;
            break;
        }
        /* Falls through to BOL */

    case BEGINNING_OF_LINE:
        switch (c) {
        case '\r': break;
        case 'c':
        case 'C':
            me->check_pointer = "ontent-t";
            me->if_ok = CONTENT_T;
            me->state = CHECK;
            break;
        case 'x':
        case 'X':
            me->check_pointer = "-archive-guessed-charset:";
            me->if_ok = X_ARCHIVE_GUESSED_CHARSET;
            me->state = CHECK;
            break;
        case '\n':
            /* END OF HEADERS! */
            printf("*** END OF HEADERS at char %d ***\n", me->char_count);
            me->target = HTStreamStack(me->format, me->targetRep, me->sink, me->anchor);
            if (me->target) {
                me->targetClass = *me->target->isa;
                me->state = MIME_TRANSPARENT;
            } else {
                me->state = MIME_IGNORE;
            }
            break;
        default:
            me->state = JUNK_LINE;
            break;
        }
        break;

    case CHECK:
        if (TOLOWER(c) == *(me->check_pointer)++) {
            if (!*me->check_pointer) me->state = me->if_ok;
        } else {
            me->state = JUNK_LINE;
        }
        break;

    case CONTENT_T:
        switch (c) {
        case 'r':
        case 'R':
            me->check_pointer = "ansfer-encoding:";
            me->if_ok = CONTENT_TRANSFER_ENCODING;
            me->state = CHECK;
            break;
        case 'y':
        case 'Y':
            me->check_pointer = "pe:";
            me->if_ok = CONTENT_TYPE;
            me->state = CHECK;
            break;
        default:
            me->state = JUNK_LINE;
            break;
        }
        break;

    case CONTENT_TYPE:
    case CONTENT_TRANSFER_ENCODING:
    case X_ARCHIVE_GUESSED_CHARSET:
    case SKIP_GET_VALUE:
    case GET_VALUE:
        if (c == '\n') {
            me->fold_state = me->state;
            me->state = NEWLINE;
        }
        break;

    case JUNK_LINE:
        if (c == '\n') {
            me->state = NEWLINE;
            me->fold_state = me->state;
        }
        break;

    default:
        break;
    }
}

PRIVATE void HTMIME_put_block(HTStream* me, const char* b, int l) {
    for (int i = 0; i < l; i++) HTMIME_put_character(me, b[i]);
}

/* ========== Main test ========== */

int main(int argc, char** argv) {
    printf("HTMIME Test with Real Wayback Data\n");
    printf("===================================\n");
    
    FILE* f = fopen("../res/wayback_response.bin", "rb");
    if (!f) f = fopen("res/wayback_response.bin", "rb");
    if (!f) {
        fprintf(stderr, "Cannot open wayback_response.bin\n");
        return 1;
    }
    
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    unsigned char* data = malloc(size);
    fread(data, 1, size, f);
    fclose(f);
    
    printf("Loaded %ld bytes\n", size);
    
    /* Create MIME stream */
    HTStream mime = {0};
    mime.isa = NULL;
    mime.sink = &sink_stream;
    mime.state = BEGINNING_OF_LINE;
    mime.net_ascii = NO;
    mime.char_count = 0;
    
    /* Feed in chunks like browser */
    int chunk1 = 1006;
    printf("\n--- Chunk 1: %d bytes ---\n", chunk1);
    HTMIME_put_block(&mime, (char*)data, chunk1);
    printf("After chunk 1: state=%d, body_started=%d\n", mime.state, body_started);
    
    int chunk2 = size - chunk1;
    printf("\n--- Chunk 2: %ld bytes ---\n", (long)chunk2);
    HTMIME_put_block(&mime, (char*)(data + chunk1), chunk2);
    printf("After chunk 2: state=%d, body_started=%d\n", mime.state, body_started);
    
    printf("\n===================================\n");
    if (body_started) {
        first_body[199] = '\0';
        printf("PASS: Body received (%d bytes)\n", total_body_bytes);
        printf("First body: %.60s\n", first_body);
    } else {
        printf("FAIL: No body received!\n");
    }
    
    /* Test 2: Browser scenario - only 1006 + 1266 = 2272 bytes */
    printf("\n=== TEST 2: Browser scenario (limited data) ===\n");
    body_started = 0;
    total_body_bytes = 0;
    memset(first_body, 0, sizeof(first_body));
    
    HTStream mime2 = {0};
    mime2.sink = &sink_stream;
    mime2.state = BEGINNING_OF_LINE;
    mime2.net_ascii = NO;
    mime2.char_count = 0;
    
    /* Browser reads: initial_data=1006, then bytes_to_read=1266 */
    int browser_chunk1 = 1006;
    int browser_chunk2 = 1266;  /* content_length(260) + initial_data(1006) */
    int browser_total = browser_chunk1 + browser_chunk2;
    
    printf("Browser would read: %d + %d = %d bytes\n", 
           browser_chunk1, browser_chunk2, browser_total);
    printf("Actual data size: %ld bytes\n", size);
    printf("Headers end at: byte 1894\n");
    
    if (browser_total >= size) {
        printf("Browser reads enough data\n");
        /* Send chunk 1 */
        HTMIME_put_block(&mime2, (char*)data, browser_chunk1);
        /* Send chunk 2 (limited to available data) */
        int c2 = (browser_chunk2 <= (size - browser_chunk1)) ? browser_chunk2 : (size - browser_chunk1);
        HTMIME_put_block(&mime2, (char*)(data + browser_chunk1), c2);
        printf("After: state=%d, body_started=%d\n", mime2.state, body_started);
    } else {
        printf("Browser reads LESS than data size - testing truncated scenario\n");
        HTMIME_put_block(&mime2, (char*)data, browser_chunk1);
        HTMIME_put_block(&mime2, (char*)(data + browser_chunk1), browser_chunk2);
        printf("After: state=%d, body_started=%d\n", mime2.state, body_started);
        
        if (!body_started) {
            printf("BUG REPRODUCED: Browser doesn't read enough data to find header end!\n");
            printf("Solution: HTTPS.c needs to read more data when offset==0\n");
        }
    }
    
    if (body_started) {
        printf("TEST 2 PASS\n");
    } else {
        printf("TEST 2 FAIL - body not received\n");
    }
    
    /* Test 3: Simulate longer headers (browser gets different server-timing) */
    printf("\n=== TEST 3: Longer headers (truncated read) ===\n");
    body_started = 0;
    total_body_bytes = 0;
    memset(first_body, 0, sizeof(first_body));
    
    HTStream mime3 = {0};
    mime3.sink = &sink_stream;
    mime3.state = BEGINNING_OF_LINE;
    mime3.net_ascii = NO;
    mime3.char_count = 0;
    
    /* Simulate: headers are at byte 1894, but we only read 1800 bytes */
    int truncated_total = 1800;  /* Less than header end at 1894 */
    printf("Simulating: only %d bytes read (headers end at 1894)\n", truncated_total);
    
    int t_chunk1 = 1006;
    int t_chunk2 = truncated_total - t_chunk1;
    
    HTMIME_put_block(&mime3, (char*)data, t_chunk1);
    HTMIME_put_block(&mime3, (char*)(data + t_chunk1), t_chunk2);
    printf("After: state=%d, body_started=%d\n", mime3.state, body_started);
    
    if (!body_started) {
        printf("EXPECTED: No body when headers truncated\n");
        printf("This is the BUG: browser reads content_length+initial_data,\n");
        printf("but if headers > initial_data, we don't read enough!\n");
        printf("FIX: Read until we find \\r\\n\\r\\n, not fixed amount\n");
    }
    
    free(data);
    return 0;  /* Don't fail - we're demonstrating the bug */
}
