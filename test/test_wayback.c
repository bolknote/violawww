/*
 * Test for HTWayback Web Archive integration
 * 
 * Tests that HTWaybackCheck correctly queries the Internet Archive
 * CDX API and returns the earliest snapshot URL.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Include HTWayback from libWWW */
#include "../src/libWWW/Library/Implementation/HTWayback.h"
#include "../src/libWWW/Library/Implementation/HTUtils.h"

/* Stubs for UI functions (not used in tests) */
void showHelpMessageInMainWindow(char* message) {
    (void)message;  /* Do nothing in tests */
}

void* mesgObj = NULL;
void* findObject(int id) { (void)id; return NULL; }
int getIdent(const char* name) { (void)name; return 0; }
int sendMessage1N1str(void* obj, const char* msg, char* str) { 
    (void)obj; (void)msg; (void)str; 
    return 0; 
}

/* Test case structure */
typedef struct {
    const char* input_url;
    const char* expected_contains;  /* Wayback URL should contain this */
    const char* expected_timestamp_prefix; /* Timestamp should start with this */
    const char* description;
} TestCase;

/* Test cases */
TestCase test_cases[] = {
    {
        "http://www.hackzone.ru/",
        "web.archive.org/web/",
        "1997",  /* Should get snapshot from 1997 */
        "hackzone.ru - archived since 1997"
    },
    {
        "http://nonexistent-domain-xyz12345.invalid/",
        NULL,
        NULL,
        "Non-existent domain - should return NULL"
    },
    {NULL, NULL, NULL, NULL}  /* Sentinel */
};

int main(int argc, char* argv[]) {
    int i;
    int passed = 0;
    int failed = 0;
    int total = 0;
    
    printf("=====================================\n");
    printf("HTWayback Test Suite\n");
    printf("=====================================\n\n");
    
    for (i = 0; test_cases[i].input_url != NULL; i++) {
        TestCase* tc = &test_cases[i];
        char* result;
        int test_passed = 0;
        
        total++;
        
        printf("Test %d: %s\n", i + 1, tc->description);
        printf("  Input: %s\n", tc->input_url);
        
        result = HTWaybackCheck(tc->input_url);
        
        if (tc->expected_contains == NULL) {
            /* Expect NULL result */
            if (result == NULL) {
                printf("  ✓ PASS: Correctly returned NULL\n");
                test_passed = 1;
            } else {
                printf("  ✗ FAIL: Expected NULL but got: %s\n", result);
                test_passed = 0;
            }
        } else {
            /* Expect non-NULL result with certain content */
            if (result == NULL) {
                printf("  ✗ FAIL: Expected Wayback URL but got NULL\n");
                test_passed = 0;
            } else {
                printf("  Result: %s\n", result);
                
                /* Check if result contains expected string */
                if (strstr(result, tc->expected_contains) != NULL) {
                    printf("  ✓ Contains: %s\n", tc->expected_contains);
                    
                    /* Check timestamp if specified */
                    if (tc->expected_timestamp_prefix) {
                        if (strstr(result, tc->expected_timestamp_prefix) != NULL) {
                            printf("  ✓ Timestamp starts with: %s\n", tc->expected_timestamp_prefix);
                            test_passed = 1;
                        } else {
                            printf("  ✗ FAIL: Timestamp doesn't start with %s\n", tc->expected_timestamp_prefix);
                            test_passed = 0;
                        }
                    } else {
                        test_passed = 1;
                    }
                } else {
                    printf("  ✗ FAIL: Result doesn't contain '%s'\n", tc->expected_contains);
                    test_passed = 0;
                }
            }
        }
        
        if (result) {
            free(result);
        }
        
        if (test_passed) {
            passed++;
            printf("  Status: PASS ✓\n");
        } else {
            failed++;
            printf("  Status: FAIL ✗\n");
        }
        printf("\n");
    }
    
    printf("=====================================\n");
    printf("Test Results:\n");
    printf("  Total:  %d\n", total);
    printf("  Passed: %d ✓\n", passed);
    printf("  Failed: %d ✗\n", failed);
    printf("=====================================\n");
    
    return (failed == 0) ? 0 : 1;
}

