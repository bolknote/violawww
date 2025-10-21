/*
 * Unit test for STG context + minors interaction
 * Tests that minors work correctly with hierarchical context
 */
#include <stdio.h>
#include <string.h>
#include "../src/libStyle/libstg.h"

extern void* malloc(unsigned long);
extern void free(void*);
extern char* saveString(const char*);

int WWW_TraceFlag = 1;

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

/* Test: P with minor should get minor attrs, not ADDRESS attrs */
int test_context_vs_minor() {
    STGLib* lib;
    STGGroup* group;
    char* spec = 
        "(ADDRESS border=0 (P border=1) fontSize=largest BDColor=green ) "
        "(P BGColor=white FGColor=black {STYLE \"WARNING\" FGColor=red BDColor=orange border=1 } )";
    char* context[3];
    STGResult results[2];
    int stat;
    STGAssert* assert;
    
    printf("\n=== Test: Context vs Minor ===\n");
    printf("Spec: ADDRESS with P (border=1, fontSize=largest, BDColor=green)\n");
    printf("      P with minor WARNING (FGColor=red, BDColor=orange)\n");
    printf("Query: P with styleAttr=WARNING, no parent context\n\n");
    
    lib = STG_init(test_tagNameCmp, test_tagName2ID, test_tagID2Name,
                   test_tagNameCmp, test_tagName2ID, test_tagID2Name);
    group = STG_makeGroup(lib, spec);
    
    if (!group || !group->first) {
        printf("FAIL: Failed to parse spec\n");
        return 0;
    }
    
    /* Query for P with WARNING attribute, no parent */
    context[0] = (char*)(long)test_tagName2ID("P");
    context[1] = (char*)(long)test_tagName2ID("WARNING");
    context[2] = 0;
    
    stat = STG_findStyle(group, context, 1, results, 1);
    
    if (!stat) {
        printf("FAIL: STG_findStyle returned 0\n");
        return 0;
    }
    
    if (!results[0].sminor) {
        printf("FAIL: Minor not found for WARNING\n");
        return 0;
    }
    
    printf("✓ Minor found\n");
    
    /* Check FGColor - should be 'red' from minor, not 'black' from major */
    assert = STGFindAssertWithMinor(results[0].smajor, results[0].sminor, 
                                    (char*)(long)test_tagName2ID("FGColor"));
    if (!assert) {
        printf("FAIL: FGColor not found\n");
        return 0;
    }
    if (strcmp(assert->val, "red") != 0) {
        printf("FAIL: FGColor should be 'red', got '%s'\n", assert->val);
        return 0;
    }
    printf("✓ FGColor = red (from minor)\n");
    
    /* Check BDColor - should be 'orange' from minor, NOT 'green' from ADDRESS */
    assert = STGFindAssertWithMinor(results[0].smajor, results[0].sminor,
                                    (char*)(long)test_tagName2ID("BDColor"));
    if (!assert) {
        printf("FAIL: BDColor not found\n");
        return 0;
    }
    if (strcmp(assert->val, "orange") != 0) {
        printf("FAIL: BDColor should be 'orange', got '%s' (probably from wrong context)\n", 
               assert->val);
        return 0;
    }
    printf("✓ BDColor = orange (from minor, not from ADDRESS context)\n");
    
    /* Check BGColor - should be 'white' from P major */
    assert = STGFindAssertWithMinor(results[0].smajor, results[0].sminor,
                                    (char*)(long)test_tagName2ID("BGColor"));
    if (!assert) {
        printf("FAIL: BGColor not found\n");
        return 0;
    }
    if (strcmp(assert->val, "white") != 0) {
        printf("FAIL: BGColor should be 'white', got '%s'\n", assert->val);
        return 0;
    }
    printf("✓ BGColor = white (from P major)\n");
    
    freeLib(lib);
    printf("PASS\n");
    return 1;
}

int main() {
    int passed = 0;
    int total = 1;
    
    printf("STG Context + Minors Test\n");
    printf("=========================\n");
    
    if (test_context_vs_minor()) passed++;
    
    printf("\n");
    printf("=========================\n");
    printf("Results: %d/%d tests passed\n", passed, total);
    
    if (passed == total) {
        printf("SUCCESS\n");
        return 0;
    } else {
        printf("FAILURE\n");
        return 1;
    }
}

