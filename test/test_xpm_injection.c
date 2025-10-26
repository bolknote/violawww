/* Test program for XPM filename validation (command injection protection) */
#include <stdio.h>
#include <stdlib.h>

/* Copy of the validation function from data.c */
static int xpmValidateFilename(char* filename)
{
    char* p = filename;
    
    if (!filename || !*filename)
        return 0;
    
    /* Check for dangerous shell metacharacters */
    while (*p) {
        char c = *p;
        
        /* Allow alphanumeric */
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            p++;
            continue;
        }
        
        /* Allow safe punctuation */
        if (c == '-' || c == '_' || c == '.' || c == '/') {
            p++;
            continue;
        }
        
        /* Reject any other character (including shell metacharacters) */
        return 0;
    }
    
    return 1;
}

int main() {
    /* Test cases */
    struct {
        char* filename;
        int expected;
        char* description;
    } tests[] = {
        {"test.xpm.Z", 1, "Valid compressed file"},
        {"path/to/file.xpm", 1, "Valid path with slash"},
        {"file-name_123.xpm", 1, "Valid with dash and underscore"},
        {"; echo test", 0, "Semicolon (shell separator)"},
        {"| cat", 0, "Pipe character"},
        {"file with spaces.xpm", 0, "Filename with spaces"},
        {"true&true", 0, "Ampersand (background execution)"},
        {"true>/dev/null", 0, "Greater-than (redirection)"},
        {"$(true)", 0, "Dollar-parenthesis with true command"},
        {"`true`", 0, "Backtick with true command"},
        {NULL, 0, "NULL pointer"},
        {"", 0, "Empty string"}
    };
    
    int passed = 0, failed = 0;
    
    printf("=== XPM Filename Validation Security Tests ===\n\n");
    
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        int result = xpmValidateFilename(tests[i].filename);
        int success = (result == tests[i].expected);
        
        printf("[%s] %s\n", success ? "PASS" : "FAIL", tests[i].description);
        printf("  Filename: %s\n", tests[i].filename ? tests[i].filename : "(null)");
        printf("  Expected: %s, Got: %s\n\n", 
               tests[i].expected ? "ACCEPT" : "REJECT",
               result ? "ACCEPT" : "REJECT");
        
        if (success)
            passed++;
        else
            failed++;
    }
    
    printf("=== Results: %d passed, %d failed ===\n", passed, failed);
    return (failed == 0) ? 0 : 1;
}

