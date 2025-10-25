/*
 * Test for Web Archive URL detection logic
 * 
 * Tests that the system correctly identifies Web Archive URLs
 * and prevents infinite loops when trying to access them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Test case structure */
typedef struct {
    const char* input_url;
    int should_be_archive;  /* 1 if should be detected as archive, 0 if not */
    const char* description;
} TestCase;

/* Test cases for Web Archive URL detection */
TestCase test_cases[] = {
    /* Regular URLs - should NOT be detected as archive */
    {
        "http://example.com/page",
        0,
        "Regular HTTP URL"
    },
    {
        "https://example.com/page",
        0,
        "Regular HTTPS URL"
    },
    {
        "http://www.google.com/search",
        0,
        "Regular domain with www"
    },
    
    /* Web Archive URLs - SHOULD be detected as archive */
    {
        "https://web.archive.org/web/20231201120000/http://example.com/page",
        1,
        "HTTPS Web Archive URL with timestamp"
    },
    {
        "http://web.archive.org/web/20231201120000/http://example.com/page",
        1,
        "HTTP Web Archive URL with timestamp"
    },
    {
        "https://web.archive.org/web/20040327020615/http://www.xcf.berkeley.edu/~wei/viola/vw/about_3.3.html",
        1,
        "Real Web Archive URL from codebase"
    },
    {
        "https://web.archive.org/web/20001110052300/http://webservices.web.cern.ch/WebServices/",
        1,
        "Another real Web Archive URL from codebase"
    },
    
    /* Edge cases */
    {
        "https://web.archive.org/web/",
        1,
        "Web Archive URL without timestamp (edge case)"
    },
    {
        "http://example.com/web/archive/",
        0,
        "URL containing 'web/archive' but not from web.archive.org"
    },
    {
        "https://subdomain.web.archive.org/web/20231201120000/http://example.com/",
        1,
        "Web Archive URL with subdomain"
    },
    
    {NULL, 0, NULL}  /* Sentinel */
};

/* Simulate the improved detection logic */
int is_web_archive_url(const char* url) {
    if (!url) return 0;
    
    /* Check for the Web Archive URL pattern */
    return (strstr(url, "web.archive.org/web/") != NULL) ? 1 : 0;
}

int main(int argc, char* argv[]) {
    int i;
    int passed = 0;
    int failed = 0;
    int total = 0;
    
    printf("=====================================\n");
    printf("Web Archive URL Detection Test\n");
    printf("=====================================\n\n");
    
    for (i = 0; test_cases[i].input_url != NULL; i++) {
        TestCase* tc = &test_cases[i];
        int detected = is_web_archive_url(tc->input_url);
        int test_passed = (detected == tc->should_be_archive);
        
        total++;
        
        printf("Test %d: %s\n", i + 1, tc->description);
        printf("  Input: %s\n", tc->input_url);
        printf("  Expected: %s\n", tc->should_be_archive ? "ARCHIVE" : "NOT ARCHIVE");
        printf("  Detected: %s\n", detected ? "ARCHIVE" : "NOT ARCHIVE");
        
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
