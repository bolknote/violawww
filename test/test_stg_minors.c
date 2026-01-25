/*
 * Unit test for STG minors (style attributes)
 * Tests parsing and matching of minors like {STYLE "WARNING" ...}
 */
#include <stdio.h>
#include <string.h>
#include "../src/libStyle/libstg.h"

/* Minimal implementations needed for testing */
extern void* malloc(unsigned long);
extern void free(void*);
extern char* saveString(const char*); /* From mystrings.o */

int WWW_TraceFlag = 1; /* Enable trace output */

static int test_id_counter = 0;
static char* test_names[100];
static int test_ids[100];
static int test_name_count = 0;

/* Test helper functions */
int test_tagNameCmp(int id1, int id2) {
    return id1 == id2;
}

int test_tagName2ID(const char* name) {
    int i;
    char* name_copy;
    for (i = 0; i < test_name_count; i++) {
        if (!strcmp(test_names[i], name)) {
            return test_ids[i];
        }
    }
    /* Add new - need to copy string! */
    name_copy = (char*)malloc(strlen(name) + 1);
    strcpy(name_copy, name);
    test_names[test_name_count] = name_copy;
    test_ids[test_name_count] = ++test_id_counter;
    test_name_count++;
    return test_id_counter;
}

char* test_tagID2Name(int id) {
    int i;
    for (i = 0; i < test_name_count; i++) {
        if (test_ids[i] == id) {
            return test_names[i];
        }
    }
    return "(unknown)";
}

/* Test cases */
int test_parse_simple_minor() {
    STGLib* lib;
    STGGroup* group;
    STGMajor* major;
    STGMinor* minor;
    STGStrList* ids;
    STGAssert* assert;
    char* spec = "(P {STYLE WARNING FGColor=red } )";
    int found_style = 0, found_warning = 0;
    
    printf("\n=== Test 1: Parse simple minor ===\n");
    
    lib = STG_init(test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name,
                   test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name);
    if (!lib) {
        printf("FAIL: STG_init failed\n");
        return 0;
    }
    
    group = STG_makeGroup(lib, spec);
    if (!group) {
        printf("FAIL: STG_makeGroup failed\n");
        return 0;
    }
    
    major = group->first;
    if (!major) {
        printf("FAIL: No major found\n");
        return 0;
    }
    
    printf("Major has minors: %s\n", major->firstMinorChild ? "YES" : "NO");
    
    minor = major->firstMinorChild;
    if (!minor) {
        printf("FAIL: No minor found (firstMinorChild is NULL)\n");
        printf("Dumping major structure:\n");
        STG_dumpMajor(major, 0);
        return 0;
    }
    
    printf("Minor IDList: ");
    for (ids = minor->IDList; ids; ids = ids->next) {
        printf("%s ", test_tagID2Name((int)(long)ids->val));
        if (!strcmp(test_tagID2Name((int)(long)ids->val), "STYLE")) found_style = 1;
        if (!strcmp(test_tagID2Name((int)(long)ids->val), "WARNING")) found_warning = 1;
    }
    printf("\n");
    
    if (!found_style) {
        printf("FAIL: STYLE not in IDList\n");
        return 0;
    }
    if (!found_warning) {
        printf("FAIL: WARNING not in IDList\n");
        return 0;
    }
    
    printf("Minor attributes:\n");
    for (assert = minor->firstAssert; assert; assert = assert->next) {
        printf("  %s = %s\n", test_tagID2Name((int)(long)assert->name), assert->val);
    }
    
    freeLib(lib);
    printf("PASS\n");
    return 1;
}

int test_match_minor() {
    STGLib* lib;
    STGGroup* group;
    STGMajor* major;
    STGMinor* minor;
    char* spec = "(P {STYLE WARNING FGColor=red } {STYLE NOTE FGColor=blue } )";
    int styleID, warningID, noteID;
    
    printf("\n=== Test 2: Match minor by attribute ===\n");
    
    lib = STG_init(test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name,
                   test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name);
    group = STG_makeGroup(lib, spec);
    major = group->first;
    
    styleID = test_tagName2ID("STYLE");
    warningID = test_tagName2ID("WARNING");
    noteID = test_tagName2ID("NOTE");
    
    /* Test matching WARNING */
    minor = matchMinor(major, (char*)(long)styleID, (char*)(long)warningID);
    if (!minor) {
        printf("FAIL: matchMinor for WARNING returned NULL\n");
        return 0;
    }
    printf("Found WARNING minor\n");
    
    /* Test matching NOTE */
    minor = matchMinor(major, (char*)(long)styleID, (char*)(long)noteID);
    if (!minor) {
        printf("FAIL: matchMinor for NOTE returned NULL\n");
        return 0;
    }
    printf("Found NOTE minor\n");
    
    /* Test non-existent */
    int fooID = test_tagName2ID("FOO");
    minor = matchMinor(major, (char*)(long)styleID, (char*)(long)fooID);
    if (minor) {
        printf("FAIL: matchMinor for FOO should return NULL\n");
        return 0;
    }
    printf("Correctly returned NULL for non-existent FOO\n");
    
    freeLib(lib);
    printf("PASS\n");
    return 1;
}

int test_assert_with_minor() {
    STGLib* lib;
    STGGroup* group;
    STGMajor* major;
    STGMinor* minor;
    STGAssert* assert;
    char* spec = "(P FGColor=black {STYLE WARNING FGColor=red BDColor=orange } )";
    int styleID, warningID, fgColorID, bdColorID;
    
    printf("\n=== Test 3: Find assert with minor (inheritance) ===\n");
    
    lib = STG_init(test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name,
                   test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name);
    group = STG_makeGroup(lib, spec);
    major = group->first;
    
    styleID = test_tagName2ID("STYLE");
    warningID = test_tagName2ID("WARNING");
    fgColorID = test_tagName2ID("FGColor");
    bdColorID = test_tagName2ID("BDColor");
    
    minor = matchMinor(major, (char*)(long)styleID, (char*)(long)warningID);
    if (!minor) {
        printf("FAIL: Minor not found\n");
        return 0;
    }
    
    /* FGColor should come from minor (red), not major (black) */
    assert = STGFindAssertWithMinor(major, minor, (char*)(long)fgColorID);
    if (!assert) {
        printf("FAIL: FGColor not found\n");
        return 0;
    }
    if (strcmp(assert->val, "red") != 0) {
        printf("FAIL: FGColor should be 'red' from minor, got '%s'\n", assert->val);
        return 0;
    }
    printf("FGColor from minor: %s ✓\n", assert->val);
    
    /* BDColor should come from minor (only in minor) */
    assert = STGFindAssertWithMinor(major, minor, (char*)(long)bdColorID);
    if (!assert) {
        printf("FAIL: BDColor not found\n");
        return 0;
    }
    if (strcmp(assert->val, "orange") != 0) {
        printf("FAIL: BDColor should be 'orange', got '%s'\n", assert->val);
        return 0;
    }
    printf("BDColor from minor: %s ✓\n", assert->val);
    
    /* Without minor, FGColor should be black */
    assert = STGFindAssertWithMinor(major, NULL, (char*)(long)fgColorID);
    if (!assert) {
        printf("FAIL: FGColor not found without minor\n");
        return 0;
    }
    if (strcmp(assert->val, "black") != 0) {
        printf("FAIL: FGColor should be 'black' from major, got '%s'\n", assert->val);
        return 0;
    }
    printf("FGColor from major (no minor): %s ✓\n", assert->val);
    
    freeLib(lib);
    printf("PASS\n");
    return 1;
}

int test_quoted_strings() {
    STGLib* lib;
    STGGroup* group;
    STGMajor* major;
    STGMinor* minor;
    STGStrList* ids;
    char* spec = "(P {STYLE \"WARNING\" FGColor=red } )";
    int found_warning = 0;
    
    printf("\n=== Test 4: Parse quoted strings ===\n");
    
    lib = STG_init(test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name,
                   test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name);
    group = STG_makeGroup(lib, spec);
    major = group->first;
    minor = major->firstMinorChild;
    
    if (!minor) {
        printf("FAIL: No minor found\n");
        return 0;
    }
    
    for (ids = minor->IDList; ids; ids = ids->next) {
        if (!strcmp(test_tagID2Name((int)(long)ids->val), "WARNING")) {
            found_warning = 1;
        }
    }
    
    if (!found_warning) {
        printf("FAIL: WARNING not found in quoted string\n");
        return 0;
    }
    
    printf("Quoted string 'WARNING' parsed correctly ✓\n");
    freeLib(lib);
    printf("PASS\n");
    return 1;
}

int test_fontweight() {
    STGLib* lib;
    STGGroup* group;
    STGMajor* major;
    STGAssert* assert;
    char* spec = "(P fontWeight=bold)";
    int fwID;
    
    printf("\n=== Test 5: fontWeight attribute ===\n");
    
    lib = STG_init(test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name,
                   test_tagNameCmp, (long (*)())test_tagName2ID, (char* (*)())test_tagID2Name);
    if (!lib) {
        printf("FAIL: STG_init failed\n");
        return 0;
    }
    group = STG_makeGroup(lib, spec);
    if (!group || !group->first) {
        printf("FAIL: STG_makeGroup failed or no major\n");
        freeLib(lib);
        return 0;
    }
    major = group->first;
    fwID = test_tagName2ID("fontWeight");
    assert = STGFindAssert(major, (char*)(long)fwID);
    if (!assert) {
        printf("FAIL: fontWeight assert not found\n");
        freeLib(lib);
        return 0;
    }
    if (strcmp(assert->val, "bold") != 0) {
        printf("FAIL: fontWeight expected 'bold', got '%s'\n", assert->val);
        freeLib(lib);
        return 0;
    }
    printf("fontWeight=bold parsed and found ✓\n");
    freeLib(lib);
    printf("PASS\n");
    return 1;
}

int main() {
    int passed = 0;
    int total = 5;
    
    printf("STG Minors Unit Tests\n");
    printf("=====================\n");
    
    if (test_parse_simple_minor()) passed++;
    if (test_match_minor()) passed++;
    if (test_assert_with_minor()) passed++;
    if (test_quoted_strings()) passed++;
    if (test_fontweight()) passed++;
    
    printf("\n");
    printf("=====================\n");
    printf("Results: %d/%d tests passed\n", passed, total);
    
    if (passed == total) {
        printf("SUCCESS\n");
        return 0;
    } else {
        printf("FAILURE\n");
        return 1;
    }
}

