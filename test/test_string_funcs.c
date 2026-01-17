/*
 * Tests for newly implemented string functions in cl_generic.c:
 * - deleteSubStr(str, start, end)
 * - deleteSubStrQ(str, start, end)
 * - replaceStrQ(originalStr, pattern, patternReplaceStr)
 * - sprintf(format, args...)
 * - countWords(str)
 * - not(boolean)
 * - item(str, n1 [, n2])
 * - nthItem(str, n)
 *
 * This test file contains isolated copies of the functions to avoid
 * pulling in the entire Viola runtime.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== Minimal definitions from packet.h ===== */
typedef long VObj;

enum {
    PKT_INT,
    PKT_CHR,
    PKT_FLT,
    PKT_STR,
    PKT_OBJ,
};

#define PK_CANFREE_STR 1

typedef struct Packet {
    union {
        VObj* o;
        long i;
        float f;
        char c;
        char* s;
    } info;
    char type;
    char canFree;
} Packet;

/* ===== Minimal implementations of helper functions ===== */
#define BUFF_SIZE 10000
char buff[BUFF_SIZE];

static char* SaveString(const char* s) {
    if (!s) return NULL;
    char* new_s = malloc(strlen(s) + 1);
    if (new_s) strcpy(new_s, s);
    return new_s;
}

static char* PkInfo2Str(Packet* pk) {
    if (pk->type == PKT_STR) return pk->info.s;
    if (pk->type == PKT_CHR) {
        static char buf[2];
        buf[0] = pk->info.c;
        buf[1] = '\0';
        return buf;
    }
    return "";
}

static long PkInfo2Int(Packet* pk) {
    if (pk->type == PKT_INT) return pk->info.i;
    return 0;
}

static float PkInfo2Flt(Packet* pk) {
    if (pk->type == PKT_FLT) return pk->info.f;
    return 0.0f;
}

static char PkInfo2Char(Packet* pk) {
    if (pk->type == PKT_CHR) return pk->info.c;
    return '\0';
}

/* ===== Copy of deleteSubStr from cl_generic.c ===== */
static long meth_generic_deleteSubStr(void* self, Packet* result, int argc, Packet argv[]) {
    char *str, *newStr;
    long start, end, len, newLen;

    result->type = PKT_STR;

    if (argc < 3) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    str = PkInfo2Str(&argv[0]);
    start = PkInfo2Int(&argv[1]);
    end = PkInfo2Int(&argv[2]);

    if (!str) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    len = strlen(str);

    if (start < 0) start = 0;
    if (end >= len) end = len - 1;
    if (start > end || start >= len) {
        result->info.s = SaveString(str);
        result->canFree = PK_CANFREE_STR;
        return 1;
    }

    newLen = len - (end - start + 1);
    newStr = (char*)malloc(newLen + 1);
    if (!newStr) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    if (start > 0) {
        strncpy(newStr, str, start);
    }
    strcpy(newStr + start, str + end + 1);

    result->info.s = newStr;
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/* ===== Copy of deleteSubStrQ from cl_generic.c ===== */
static long meth_generic_deleteSubStrQ(void* self, Packet* result, int argc, Packet argv[]) {
    char *str;
    long start, end, len;

    result->type = PKT_STR;

    if (argc < 3) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    str = PkInfo2Str(&argv[0]);
    start = PkInfo2Int(&argv[1]);
    end = PkInfo2Int(&argv[2]);

    if (!str) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    len = strlen(str);

    if (start < 0) start = 0;
    if (end >= len) end = len - 1;
    if (start > end || start >= len) {
        result->info.s = str;
        result->canFree = 0;
        return 1;
    }

    memmove(str + start, str + end + 1, len - end);

    result->info.s = str;
    result->canFree = 0;
    return 1;
}

/* ===== Copy of replaceStrQ from cl_generic.c ===== */
static long meth_generic_replaceStrQ(void* self, Packet* result, int argc, Packet argv[]) {
    char *cp, *lp;
    char *inStr, *patStr, *repStr;
    int pi = 0;
    size_t patLength;

    result->type = PKT_STR;

    if (argc < 3) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    inStr = PkInfo2Str(&argv[0]);
    patStr = PkInfo2Str(&argv[1]);
    repStr = PkInfo2Str(&argv[2]);

    if (!inStr || !patStr || !repStr) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    patLength = strlen(patStr);
    if (patLength == 0) {
        result->info.s = inStr;
        result->canFree = 0;
        return 1;
    }

    buff[0] = '\0';
    lp = inStr;
    for (cp = inStr; *cp; cp++) {
        if (*cp == patStr[pi]) {
            if (++pi >= patLength) {
                size_t prefixLen = (cp - lp) - (patLength - 1);
                if (prefixLen > 0) {
                    strncat(buff, lp, prefixLen);
                }
                strcat(buff, repStr);
                lp = cp + 1;
                pi = 0;
            }
        } else {
            pi = 0;
        }
    }
    strcat(buff, lp);

    result->info.s = buff;
    result->canFree = 0;
    return 1;
}

/* ===== Copy of sprintf from cl_generic.c ===== */
static int sprintf_warning_count = 0; /* Track warnings for testing */

static long meth_generic_sprintf(void* self, Packet* result, int argc, Packet argv[]) {
    char *fmt, *cp;
    char tempBuff[256];
    int argIdx = 1;
    int specCount = 0;
    size_t outLen = 0;

    result->type = PKT_STR;

    if (argc < 1) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    fmt = PkInfo2Str(&argv[0]);
    if (!fmt) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    /* Count format specifiers for runtime validation */
    for (cp = fmt; *cp; cp++) {
        if (*cp == '%' && *(cp + 1)) {
            cp++;
            if (*cp != '%') {
                specCount++;
            }
        }
    }

    /* Warn if argument count doesn't match specifier count */
    if (specCount > argc - 1) {
        fprintf(stderr, "sprintf: warning: format expects %d arguments, but only %d provided\n",
                specCount, argc - 1);
        sprintf_warning_count++;
    } else if (specCount < argc - 1) {
        fprintf(stderr, "sprintf: warning: format expects %d arguments, but %d provided (extra ignored)\n",
                specCount, argc - 1);
        sprintf_warning_count++;
    }

    buff[0] = '\0';

    for (cp = fmt; *cp; cp++) {
        if (*cp == '%' && *(cp + 1)) {
            cp++;
            switch (*cp) {
            case 's':
                if (argIdx < argc) {
                    char *s = PkInfo2Str(&argv[argIdx++]);
                    if (s) strcat(buff, s);
                } else {
                    strcat(buff, "(null)");
                }
                break;
            case 'd':
            case 'i':
                if (argIdx < argc) {
                    snprintf(tempBuff, sizeof(tempBuff), "%ld", 
                             PkInfo2Int(&argv[argIdx++]));
                    strcat(buff, tempBuff);
                } else {
                    strcat(buff, "0");
                }
                break;
            case 'f':
                if (argIdx < argc) {
                    snprintf(tempBuff, sizeof(tempBuff), "%f", 
                             PkInfo2Flt(&argv[argIdx++]));
                    strcat(buff, tempBuff);
                } else {
                    strcat(buff, "0.000000");
                }
                break;
            case 'c':
                if (argIdx < argc) {
                    char c = PkInfo2Char(&argv[argIdx++]);
                    outLen = strlen(buff);
                    buff[outLen] = c;
                    buff[outLen + 1] = '\0';
                } else {
                    strcat(buff, "?");
                }
                break;
            case '%':
                outLen = strlen(buff);
                buff[outLen] = '%';
                buff[outLen + 1] = '\0';
                break;
            default:
                outLen = strlen(buff);
                buff[outLen] = '%';
                buff[outLen + 1] = *cp;
                buff[outLen + 2] = '\0';
                break;
            }
        } else {
            outLen = strlen(buff);
            buff[outLen] = *cp;
            buff[outLen + 1] = '\0';
        }
    }

    result->info.s = SaveString(buff);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/* ===== Test framework ===== */
static int tests_run = 0;
static int tests_passed = 0;
static int tests_failed = 0;

#define ASSERT(cond, msg) do { \
    tests_run++; \
    if (!(cond)) { \
        printf("FAIL: %s\n", msg); \
        tests_failed++; \
    } else { \
        printf("PASS: %s\n", msg); \
        tests_passed++; \
    } \
} while (0)

static void make_str_packet(Packet* p, char* s) {
    p->type = PKT_STR;
    p->info.s = s;
    p->canFree = 0;
}

static void make_int_packet(Packet* p, long i) {
    p->type = PKT_INT;
    p->info.i = i;
    p->canFree = 0;
}

static void make_flt_packet(Packet* p, float f) {
    p->type = PKT_FLT;
    p->info.f = f;
    p->canFree = 0;
}

static void make_chr_packet(Packet* p, char c) {
    p->type = PKT_CHR;
    p->info.c = c;
    p->canFree = 0;
}

/* ===== Tests ===== */
static int test_deleteSubStr(void) {
    printf("\n--- Test: deleteSubStr ---\n");
    
    Packet result;
    Packet argv[3];
    long ret;
    
    /* Test 1: Delete middle substring */
    make_str_packet(&argv[0], "Hello World");
    make_int_packet(&argv[1], 5);
    make_int_packet(&argv[2], 10);
    
    ret = meth_generic_deleteSubStr(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStr returns 1");
    ASSERT(result.type == PKT_STR, "result type is PKT_STR");
    ASSERT(strcmp(result.info.s, "Hello") == 0, "deleteSubStr('Hello World', 5, 10) == 'Hello'");
    ASSERT(result.canFree == PK_CANFREE_STR, "result.canFree is PK_CANFREE_STR");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 2: Delete from beginning */
    make_str_packet(&argv[0], "Hello World");
    make_int_packet(&argv[1], 0);
    make_int_packet(&argv[2], 5);
    
    ret = meth_generic_deleteSubStr(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStr returns 1");
    ASSERT(strcmp(result.info.s, "World") == 0, "deleteSubStr('Hello World', 0, 5) == 'World'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 3: Delete from end */
    make_str_packet(&argv[0], "Hello World");
    make_int_packet(&argv[1], 6);
    make_int_packet(&argv[2], 10);
    
    ret = meth_generic_deleteSubStr(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStr returns 1");
    ASSERT(strcmp(result.info.s, "Hello ") == 0, "deleteSubStr('Hello World', 6, 10) == 'Hello '");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 4: Delete single character */
    make_str_packet(&argv[0], "Hello");
    make_int_packet(&argv[1], 2);
    make_int_packet(&argv[2], 2);
    
    ret = meth_generic_deleteSubStr(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStr returns 1");
    ASSERT(strcmp(result.info.s, "Helo") == 0, "deleteSubStr('Hello', 2, 2) == 'Helo'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 5: Invalid range (start > end) */
    make_str_packet(&argv[0], "Hello");
    make_int_packet(&argv[1], 5);
    make_int_packet(&argv[2], 2);
    
    ret = meth_generic_deleteSubStr(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStr returns 1 for invalid range");
    ASSERT(strcmp(result.info.s, "Hello") == 0, "deleteSubStr with invalid range returns copy");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 6: End beyond string length */
    make_str_packet(&argv[0], "Hello");
    make_int_packet(&argv[1], 3);
    make_int_packet(&argv[2], 100);
    
    ret = meth_generic_deleteSubStr(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStr returns 1");
    ASSERT(strcmp(result.info.s, "Hel") == 0, "deleteSubStr('Hello', 3, 100) == 'Hel'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 7: Negative start */
    make_str_packet(&argv[0], "Hello");
    make_int_packet(&argv[1], -5);
    make_int_packet(&argv[2], 1);
    
    ret = meth_generic_deleteSubStr(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStr returns 1");
    ASSERT(strcmp(result.info.s, "llo") == 0, "deleteSubStr('Hello', -5, 1) == 'llo'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    return 1;
}

static int test_deleteSubStrQ(void) {
    printf("\n--- Test: deleteSubStrQ ---\n");
    
    Packet result;
    Packet argv[3];
    long ret;
    
    /* Test 1: Delete middle substring */
    char str1[] = "Hello World";
    make_str_packet(&argv[0], str1);
    make_int_packet(&argv[1], 5);
    make_int_packet(&argv[2], 10);
    
    ret = meth_generic_deleteSubStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStrQ returns 1");
    ASSERT(result.type == PKT_STR, "result type is PKT_STR");
    ASSERT(strcmp(result.info.s, "Hello") == 0, "deleteSubStrQ modifies string in place");
    ASSERT(result.canFree == 0, "result.canFree is 0");
    ASSERT(result.info.s == str1, "result points to original string");
    
    /* Test 2: Delete from beginning */
    char str2[] = "Hello World";
    make_str_packet(&argv[0], str2);
    make_int_packet(&argv[1], 0);
    make_int_packet(&argv[2], 5);
    
    ret = meth_generic_deleteSubStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStrQ returns 1");
    ASSERT(strcmp(result.info.s, "World") == 0, "deleteSubStrQ('Hello World', 0, 5) == 'World'");
    
    /* Test 3: Delete single character */
    char str3[] = "Hello";
    make_str_packet(&argv[0], str3);
    make_int_packet(&argv[1], 2);
    make_int_packet(&argv[2], 2);
    
    ret = meth_generic_deleteSubStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStrQ returns 1");
    ASSERT(strcmp(result.info.s, "Helo") == 0, "deleteSubStrQ('Hello', 2, 2) == 'Helo'");
    
    /* Test 4: Invalid range */
    char str4[] = "Hello";
    make_str_packet(&argv[0], str4);
    make_int_packet(&argv[1], 5);
    make_int_packet(&argv[2], 2);
    
    ret = meth_generic_deleteSubStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "deleteSubStrQ returns 1 for invalid range");
    ASSERT(strcmp(result.info.s, "Hello") == 0, "deleteSubStrQ with invalid range - unchanged");
    
    return 1;
}

static int test_replaceStrQ(void) {
    printf("\n--- Test: replaceStrQ ---\n");
    
    Packet result;
    Packet argv[3];
    long ret;
    
    /* Test 1: Simple replacement */
    make_str_packet(&argv[0], "Hello World");
    make_str_packet(&argv[1], "World");
    make_str_packet(&argv[2], "Universe");
    
    ret = meth_generic_replaceStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "replaceStrQ returns 1");
    ASSERT(result.type == PKT_STR, "result type is PKT_STR");
    ASSERT(strcmp(result.info.s, "Hello Universe") == 0, 
           "replaceStrQ('Hello World', 'World', 'Universe') == 'Hello Universe'");
    ASSERT(result.canFree == 0, "result.canFree is 0");
    
    /* Test 2: Multiple replacements */
    make_str_packet(&argv[0], "foo bar foo baz foo");
    make_str_packet(&argv[1], "foo");
    make_str_packet(&argv[2], "X");
    
    ret = meth_generic_replaceStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "replaceStrQ returns 1");
    ASSERT(strcmp(result.info.s, "X bar X baz X") == 0,
           "replaceStrQ replaces all occurrences");
    
    /* Test 3: No match */
    make_str_packet(&argv[0], "Hello World");
    make_str_packet(&argv[1], "xyz");
    make_str_packet(&argv[2], "123");
    
    ret = meth_generic_replaceStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "replaceStrQ returns 1");
    ASSERT(strcmp(result.info.s, "Hello World") == 0,
           "replaceStrQ with no match returns original");
    
    /* Test 4: Empty pattern */
    make_str_packet(&argv[0], "Hello");
    make_str_packet(&argv[1], "");
    make_str_packet(&argv[2], "X");
    
    ret = meth_generic_replaceStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "replaceStrQ returns 1 for empty pattern");
    ASSERT(strcmp(result.info.s, "Hello") == 0,
           "replaceStrQ with empty pattern returns original");
    
    /* Test 5: Replace with empty string */
    make_str_packet(&argv[0], "Hello World");
    make_str_packet(&argv[1], " World");
    make_str_packet(&argv[2], "");
    
    ret = meth_generic_replaceStrQ(NULL, &result, 3, argv);
    ASSERT(ret == 1, "replaceStrQ returns 1");
    ASSERT(strcmp(result.info.s, "Hello") == 0,
           "replaceStrQ can delete by replacing with empty string");
    
    return 1;
}

static int test_sprintf(void) {
    printf("\n--- Test: sprintf ---\n");
    
    Packet result;
    Packet argv[5];
    long ret;
    
    /* Test 1: Simple string format */
    make_str_packet(&argv[0], "Hello %s!");
    make_str_packet(&argv[1], "World");
    
    ret = meth_generic_sprintf(NULL, &result, 2, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(result.type == PKT_STR, "result type is PKT_STR");
    ASSERT(strcmp(result.info.s, "Hello World!") == 0,
           "sprintf('Hello %s!', 'World') == 'Hello World!'");
    ASSERT(result.canFree == PK_CANFREE_STR, "result.canFree is PK_CANFREE_STR");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 2: Integer format */
    make_str_packet(&argv[0], "Number: %d");
    make_int_packet(&argv[1], 42);
    
    ret = meth_generic_sprintf(NULL, &result, 2, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strcmp(result.info.s, "Number: 42") == 0,
           "sprintf('Number: %d', 42) == 'Number: 42'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 3: Float format */
    make_str_packet(&argv[0], "Value: %f");
    make_flt_packet(&argv[1], 3.14f);
    
    ret = meth_generic_sprintf(NULL, &result, 2, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strncmp(result.info.s, "Value: 3.14", 11) == 0,
           "sprintf('Value: %f', 3.14) starts with 'Value: 3.14'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 4: Character format */
    make_str_packet(&argv[0], "Char: %c");
    make_chr_packet(&argv[1], 'X');
    
    ret = meth_generic_sprintf(NULL, &result, 2, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strcmp(result.info.s, "Char: X") == 0,
           "sprintf('Char: %c', 'X') == 'Char: X'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 5: Escaped percent */
    make_str_packet(&argv[0], "100%% complete");
    
    ret = meth_generic_sprintf(NULL, &result, 1, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strcmp(result.info.s, "100% complete") == 0,
           "sprintf('100%% complete') == '100% complete'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 6: Multiple format specifiers */
    make_str_packet(&argv[0], "%s has %d items");
    make_str_packet(&argv[1], "List");
    make_int_packet(&argv[2], 5);
    
    ret = meth_generic_sprintf(NULL, &result, 3, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strcmp(result.info.s, "List has 5 items") == 0,
           "sprintf('%s has %d items', 'List', 5) == 'List has 5 items'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 7: %i format */
    make_str_packet(&argv[0], "Number: %i");
    make_int_packet(&argv[1], -10);
    
    ret = meth_generic_sprintf(NULL, &result, 2, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strcmp(result.info.s, "Number: -10") == 0,
           "sprintf('Number: %i', -10) == 'Number: -10'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 8: No format specifiers */
    make_str_packet(&argv[0], "Plain text");
    
    ret = meth_generic_sprintf(NULL, &result, 1, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strcmp(result.info.s, "Plain text") == 0,
           "sprintf('Plain text') == 'Plain text'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 9: Missing arguments - should use defaults and warn */
    printf("  (expecting warning on stderr for next test)\n");
    int prev_warnings = sprintf_warning_count;
    make_str_packet(&argv[0], "Hello %s, you have %d messages");
    make_str_packet(&argv[1], "User");
    /* Missing second argument! */
    
    ret = meth_generic_sprintf(NULL, &result, 2, argv);
    ASSERT(ret == 1, "sprintf returns 1 even with missing args");
    ASSERT(strcmp(result.info.s, "Hello User, you have 0 messages") == 0,
           "sprintf with missing int arg uses default '0'");
    ASSERT(sprintf_warning_count > prev_warnings, "sprintf issued warning for missing args");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 10: Extra arguments - should ignore and warn */
    printf("  (expecting warning on stderr for next test)\n");
    prev_warnings = sprintf_warning_count;
    make_str_packet(&argv[0], "Just %s");
    make_str_packet(&argv[1], "one");
    make_str_packet(&argv[2], "extra");
    make_int_packet(&argv[3], 999);
    
    ret = meth_generic_sprintf(NULL, &result, 4, argv);
    ASSERT(ret == 1, "sprintf returns 1 with extra args");
    ASSERT(strcmp(result.info.s, "Just one") == 0,
           "sprintf with extra args ignores them");
    ASSERT(sprintf_warning_count > prev_warnings, "sprintf issued warning for extra args");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 11: Missing string arg uses "(null)" */
    printf("  (expecting warning on stderr for next test)\n");
    make_str_packet(&argv[0], "Name: %s");
    
    ret = meth_generic_sprintf(NULL, &result, 1, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strcmp(result.info.s, "Name: (null)") == 0,
           "sprintf with missing string arg uses '(null)'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 12: Missing char arg uses "?" */
    printf("  (expecting warning on stderr for next test)\n");
    make_str_packet(&argv[0], "Grade: %c");
    
    ret = meth_generic_sprintf(NULL, &result, 1, argv);
    ASSERT(ret == 1, "sprintf returns 1");
    ASSERT(strcmp(result.info.s, "Grade: ?") == 0,
           "sprintf with missing char arg uses '?'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    return 1;
}

/* ===== Copy of countWords from cl_generic.c ===== */
static long meth_generic_countWords(void* self, Packet* result, int argc, Packet argv[]) {
    char *cp;
    int count = 0;
    int inWord = 0;

    result->type = PKT_INT;
    result->canFree = 0;

    if (argc < 1) {
        result->info.i = 0;
        return 0;
    }

    cp = PkInfo2Str(&argv[0]);
    if (!cp) {
        result->info.i = 0;
        return 0;
    }

    /* Count words by detecting transitions from non-word to word */
    while (*cp) {
        if (*cp == ' ' || *cp == '\t' || *cp == '\n' || *cp == '\r') {
            inWord = 0;
        } else {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        }
        cp++;
    }

    result->info.i = count;
    return 1;
}

/* ===== Copy of not from cl_generic.c ===== */
static long meth_generic_not(void* self, Packet* result, int argc, Packet argv[]) {
    result->type = PKT_INT;
    result->canFree = 0;

    if (argc < 1) {
        result->info.i = 1; /* not(nothing) = true */
        return 1;
    }

    /* Get the boolean value and negate it */
    result->info.i = PkInfo2Int(&argv[0]) ? 0 : 1;
    return 1;
}

/* ===== Copy of item from cl_generic.c ===== */
static long meth_generic_item(void* self, Packet* result, int argc, Packet argv[]) {
    char *str, *cp, *start;
    long n1, n2;
    long itemNum = 1;
    int bi = 0;

    result->type = PKT_STR;

    if (argc < 2) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    str = PkInfo2Str(&argv[0]);
    if (!str) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    n1 = PkInfo2Int(&argv[1]);
    if (argc >= 3) {
        n2 = PkInfo2Int(&argv[2]);
    } else {
        n2 = n1;
    }

    /* Validate range */
    if (n1 < 1 || n2 < n1) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    buff[0] = '\0';
    start = str;

    for (cp = str; ; cp++) {
        if (*cp == ',' || *cp == '\0') {
            if (itemNum >= n1 && itemNum <= n2) {
                /* Copy this item */
                if (bi > 0) {
                    buff[bi++] = ','; /* Add comma between items */
                }
                while (start < cp) {
                    buff[bi++] = *start++;
                }
            }
            if (*cp == '\0' || itemNum >= n2) {
                break;
            }
            itemNum++;
            start = cp + 1;
        }
    }
    buff[bi] = '\0';

    result->info.s = SaveString(buff);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/* ===== Copy of nthItem from cl_generic.c ===== */
static long meth_generic_nthItem(void* self, Packet* result, int argc, Packet argv[]) {
    char *str, *cp, *start;
    long n;
    long itemNum = 1;
    int bi = 0;

    result->type = PKT_STR;

    if (argc < 2) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    str = PkInfo2Str(&argv[0]);
    if (!str) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    n = PkInfo2Int(&argv[1]);
    if (n < 1) {
        result->info.s = "";
        result->canFree = 0;
        return 0;
    }

    start = str;

    for (cp = str; ; cp++) {
        if (*cp == ',' || *cp == '\0') {
            if (itemNum == n) {
                /* Copy this item */
                while (start < cp) {
                    buff[bi++] = *start++;
                }
                break;
            }
            if (*cp == '\0') {
                /* Item not found */
                result->info.s = "";
                result->canFree = 0;
                return 0;
            }
            itemNum++;
            start = cp + 1;
        }
    }
    buff[bi] = '\0';

    result->info.s = SaveString(buff);
    result->canFree = PK_CANFREE_STR;
    return 1;
}

/* ===== Tests for countWords ===== */
int test_countWords(void) {
    printf("\n--- Testing countWords ---\n");
    Packet argv[1];
    Packet result;
    long ret;
    
    /* Test 1: Simple words */
    make_str_packet(&argv[0], "Hello World");
    ret = meth_generic_countWords(NULL, &result, 1, argv);
    ASSERT(ret == 1, "countWords returns 1");
    ASSERT(result.info.i == 2, "countWords('Hello World') == 2");
    
    /* Test 2: Multiple spaces */
    make_str_packet(&argv[0], "  one   two   three  ");
    ret = meth_generic_countWords(NULL, &result, 1, argv);
    ASSERT(ret == 1, "countWords returns 1");
    ASSERT(result.info.i == 3, "countWords('  one   two   three  ') == 3");
    
    /* Test 3: Empty string */
    make_str_packet(&argv[0], "");
    ret = meth_generic_countWords(NULL, &result, 1, argv);
    ASSERT(ret == 1, "countWords returns 1 for empty string");
    ASSERT(result.info.i == 0, "countWords('') == 0");
    
    /* Test 4: Only spaces */
    make_str_packet(&argv[0], "   ");
    ret = meth_generic_countWords(NULL, &result, 1, argv);
    ASSERT(ret == 1, "countWords returns 1");
    ASSERT(result.info.i == 0, "countWords('   ') == 0");
    
    /* Test 5: Tabs and newlines */
    make_str_packet(&argv[0], "word1\tword2\nword3");
    ret = meth_generic_countWords(NULL, &result, 1, argv);
    ASSERT(ret == 1, "countWords returns 1");
    ASSERT(result.info.i == 3, "countWords('word1\\tword2\\nword3') == 3");
    
    /* Test 6: Single word */
    make_str_packet(&argv[0], "word");
    ret = meth_generic_countWords(NULL, &result, 1, argv);
    ASSERT(ret == 1, "countWords returns 1");
    ASSERT(result.info.i == 1, "countWords('word') == 1");
    
    return 1;
}

/* ===== Tests for not ===== */
int test_not(void) {
    printf("\n--- Testing not ---\n");
    Packet argv[1];
    Packet result;
    long ret;
    
    /* Test 1: not(0) = 1 */
    make_int_packet(&argv[0], 0);
    ret = meth_generic_not(NULL, &result, 1, argv);
    ASSERT(ret == 1, "not returns 1");
    ASSERT(result.info.i == 1, "not(0) == 1");
    
    /* Test 2: not(1) = 0 */
    make_int_packet(&argv[0], 1);
    ret = meth_generic_not(NULL, &result, 1, argv);
    ASSERT(ret == 1, "not returns 1");
    ASSERT(result.info.i == 0, "not(1) == 0");
    
    /* Test 3: not(42) = 0 */
    make_int_packet(&argv[0], 42);
    ret = meth_generic_not(NULL, &result, 1, argv);
    ASSERT(ret == 1, "not returns 1");
    ASSERT(result.info.i == 0, "not(42) == 0");
    
    /* Test 4: not(-1) = 0 */
    make_int_packet(&argv[0], -1);
    ret = meth_generic_not(NULL, &result, 1, argv);
    ASSERT(ret == 1, "not returns 1");
    ASSERT(result.info.i == 0, "not(-1) == 0");
    
    /* Test 5: not() with no args = 1 */
    ret = meth_generic_not(NULL, &result, 0, argv);
    ASSERT(ret == 1, "not returns 1");
    ASSERT(result.info.i == 1, "not() with no args == 1");
    
    return 1;
}

/* ===== Tests for item ===== */
int test_item(void) {
    printf("\n--- Testing item ---\n");
    Packet argv[3];
    Packet result;
    long ret;
    
    /* Test 1: Single item */
    make_str_packet(&argv[0], "apple,banana,cherry");
    make_int_packet(&argv[1], 2);
    
    ret = meth_generic_item(NULL, &result, 2, argv);
    ASSERT(ret == 1, "item returns 1");
    ASSERT(strcmp(result.info.s, "banana") == 0,
           "item('apple,banana,cherry', 2) == 'banana'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 2: Range of items */
    make_str_packet(&argv[0], "apple,banana,cherry,date");
    make_int_packet(&argv[1], 2);
    make_int_packet(&argv[2], 3);
    
    ret = meth_generic_item(NULL, &result, 3, argv);
    ASSERT(ret == 1, "item returns 1");
    ASSERT(strcmp(result.info.s, "banana,cherry") == 0,
           "item('apple,banana,cherry,date', 2, 3) == 'banana,cherry'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 3: First item */
    make_str_packet(&argv[0], "apple,banana,cherry");
    make_int_packet(&argv[1], 1);
    
    ret = meth_generic_item(NULL, &result, 2, argv);
    ASSERT(ret == 1, "item returns 1");
    ASSERT(strcmp(result.info.s, "apple") == 0,
           "item('apple,banana,cherry', 1) == 'apple'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 4: Last item */
    make_str_packet(&argv[0], "apple,banana,cherry");
    make_int_packet(&argv[1], 3);
    
    ret = meth_generic_item(NULL, &result, 2, argv);
    ASSERT(ret == 1, "item returns 1");
    ASSERT(strcmp(result.info.s, "cherry") == 0,
           "item('apple,banana,cherry', 3) == 'cherry'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 5: All items */
    make_str_packet(&argv[0], "one,two,three");
    make_int_packet(&argv[1], 1);
    make_int_packet(&argv[2], 3);
    
    ret = meth_generic_item(NULL, &result, 3, argv);
    ASSERT(ret == 1, "item returns 1");
    ASSERT(strcmp(result.info.s, "one,two,three") == 0,
           "item('one,two,three', 1, 3) == 'one,two,three'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 6: Invalid range (n1 < 1) */
    make_str_packet(&argv[0], "apple,banana");
    make_int_packet(&argv[1], 0);
    
    ret = meth_generic_item(NULL, &result, 2, argv);
    ASSERT(ret == 0, "item returns 0 for invalid range");
    ASSERT(strcmp(result.info.s, "") == 0,
           "item with n1=0 returns empty string");
    
    return 1;
}

/* ===== Tests for nthItem ===== */
int test_nthItem(void) {
    printf("\n--- Testing nthItem ---\n");
    Packet argv[2];
    Packet result;
    long ret;
    
    /* Test 1: First item */
    make_str_packet(&argv[0], "apple,banana,cherry");
    make_int_packet(&argv[1], 1);
    
    ret = meth_generic_nthItem(NULL, &result, 2, argv);
    ASSERT(ret == 1, "nthItem returns 1");
    ASSERT(strcmp(result.info.s, "apple") == 0,
           "nthItem('apple,banana,cherry', 1) == 'apple'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 2: Second item */
    make_str_packet(&argv[0], "apple,banana,cherry");
    make_int_packet(&argv[1], 2);
    
    ret = meth_generic_nthItem(NULL, &result, 2, argv);
    ASSERT(ret == 1, "nthItem returns 1");
    ASSERT(strcmp(result.info.s, "banana") == 0,
           "nthItem('apple,banana,cherry', 2) == 'banana'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 3: Last item */
    make_str_packet(&argv[0], "apple,banana,cherry");
    make_int_packet(&argv[1], 3);
    
    ret = meth_generic_nthItem(NULL, &result, 2, argv);
    ASSERT(ret == 1, "nthItem returns 1");
    ASSERT(strcmp(result.info.s, "cherry") == 0,
           "nthItem('apple,banana,cherry', 3) == 'cherry'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 4: Out of range */
    make_str_packet(&argv[0], "apple,banana,cherry");
    make_int_packet(&argv[1], 5);
    
    ret = meth_generic_nthItem(NULL, &result, 2, argv);
    ASSERT(ret == 0, "nthItem returns 0 for out of range");
    ASSERT(strcmp(result.info.s, "") == 0,
           "nthItem out of range returns empty string");
    
    /* Test 5: Single item string */
    make_str_packet(&argv[0], "only");
    make_int_packet(&argv[1], 1);
    
    ret = meth_generic_nthItem(NULL, &result, 2, argv);
    ASSERT(ret == 1, "nthItem returns 1");
    ASSERT(strcmp(result.info.s, "only") == 0,
           "nthItem('only', 1) == 'only'");
    if (result.canFree == PK_CANFREE_STR) free(result.info.s);
    
    /* Test 6: Invalid n (< 1) */
    make_str_packet(&argv[0], "apple,banana");
    make_int_packet(&argv[1], 0);
    
    ret = meth_generic_nthItem(NULL, &result, 2, argv);
    ASSERT(ret == 0, "nthItem returns 0 for n < 1");
    ASSERT(strcmp(result.info.s, "") == 0,
           "nthItem with n=0 returns empty string");
    
    return 1;
}

int main(void) {
    printf("=======================================\n");
    printf("String Functions Tests (cl_generic.c)\n");
    printf("=======================================\n");
    
    test_deleteSubStr();
    test_deleteSubStrQ();
    test_replaceStrQ();
    test_sprintf();
    test_countWords();
    test_not();
    test_item();
    test_nthItem();
    
    printf("\n=======================================\n");
    printf("Test Results: %d/%d passed, %d failed\n", tests_passed, tests_run, tests_failed);
    printf("=======================================\n");
    
    if (tests_failed == 0) {
        printf("OVERALL: SUCCESS\n");
        return 0;
    } else {
        printf("OVERALL: FAILURE\n");
        return 1;
    }
}
