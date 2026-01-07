/* Test program for path validation (shell injection prevention) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Path validation function - mirrors logic from wwwSecurity_script.v */
static int isValidPath(const char* s) {
    if (!s || !*s) return 0;
    
    /* Check for path traversal */
    if (strstr(s, "..") != NULL) return 0;
    
    /* Check for shell metacharacters */
    if (strchr(s, ';') != NULL) return 0;
    if (strchr(s, '|') != NULL) return 0;
    if (strchr(s, '&') != NULL) return 0;
    if (strchr(s, '`') != NULL) return 0;
    if (strchr(s, '$') != NULL) return 0;
    if (strchr(s, '(') != NULL) return 0;
    if (strchr(s, ')') != NULL) return 0;
    if (strchr(s, '<') != NULL) return 0;
    if (strchr(s, '>') != NULL) return 0;
    if (strchr(s, '"') != NULL) return 0;
    if (strchr(s, '\'') != NULL) return 0;
    if (strchr(s, '\\') != NULL) return 0;
    if (strchr(s, '\n') != NULL) return 0;
    if (strchr(s, '\r') != NULL) return 0;
    if (strchr(s, ' ') != NULL) return 0;
    if (strchr(s, '\t') != NULL) return 0;
    
    return 1;
}

/* Check if path is in a valid temp directory */
static int isTmpPath(const char* path) {
    if (!isValidPath(path)) return 0;
    
    /* Must start with /tmp/ or /var/tmp/ */
    if (strncmp(path, "/tmp/", 5) == 0) return 1;
    if (strncmp(path, "/var/tmp/", 9) == 0) return 1;
    
    return 0;
}

int main() {
    struct {
        const char* path;
        int expected_valid;
        int expected_tmp;
        const char* description;
    } tests[] = {
        /* Valid paths */
        {"/tmp/viola_12345", 1, 1, "Valid temp file"},
        {"/var/tmp/file.txt", 1, 1, "Valid /var/tmp file"},
        {"/home/user/file.txt", 1, 0, "Valid non-temp path"},
        {"/path/to/file-name_123.txt", 1, 0, "Valid with dash and underscore"},
        
        /* Path traversal attacks */
        {"/tmp/../etc/passwd", 0, 0, "Path traversal with .."},
        {"/tmp/foo/../../../etc/passwd", 0, 0, "Multiple path traversal"},
        {"../../../etc/passwd", 0, 0, "Relative path traversal"},
        
        /* Shell injection attacks */
        {"/tmp/file; rm -rf /", 0, 0, "Semicolon injection"},
        {"/tmp/file | cat /etc/passwd", 0, 0, "Pipe injection"},
        {"/tmp/file && evil", 0, 0, "Ampersand injection"},
        {"/tmp/`whoami`", 0, 0, "Backtick command substitution"},
        {"/tmp/$(id)", 0, 0, "Dollar-paren command substitution"},
        {"/tmp/file > /etc/passwd", 0, 0, "Redirect injection"},
        {"/tmp/file < /etc/passwd", 0, 0, "Input redirect injection"},
        {"/tmp/file\"quote", 0, 0, "Double quote injection"},
        {"/tmp/file'quote", 0, 0, "Single quote injection"},
        {"/tmp/file\\escape", 0, 0, "Backslash injection"},
        {"/tmp/file\nwith\nnewlines", 0, 0, "Newline injection"},
        {"/tmp/file with spaces", 0, 0, "Space in filename"},
        {"/tmp/file\twith\ttabs", 0, 0, "Tab in filename"},
        
        /* Edge cases */
        {NULL, 0, 0, "NULL pointer"},
        {"", 0, 0, "Empty string"},
        {"/tmp/", 1, 1, "Just /tmp/"},
        
        /* Non-temp paths that are valid but not tmp */
        {"/etc/passwd", 1, 0, "System file (valid path, not tmp)"},
    };
    
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0, failed = 0;
    
    printf("=== Path Validation Security Tests ===\n\n");
    
    for (int i = 0; i < num_tests; i++) {
        int valid_result = isValidPath(tests[i].path);
        int tmp_result = isTmpPath(tests[i].path);
        
        int valid_ok = (valid_result == tests[i].expected_valid);
        int tmp_ok = (tmp_result == tests[i].expected_tmp);
        int success = valid_ok && tmp_ok;
        
        printf("[%s] %s\n", success ? "PASS" : "FAIL", tests[i].description);
        printf("  Path: %s\n", tests[i].path ? tests[i].path : "(null)");
        printf("  isValidPath: expected=%d, got=%d %s\n", 
               tests[i].expected_valid, valid_result, valid_ok ? "" : "MISMATCH");
        printf("  isTmpPath: expected=%d, got=%d %s\n\n", 
               tests[i].expected_tmp, tmp_result, tmp_ok ? "" : "MISMATCH");
        
        if (success)
            passed++;
        else
            failed++;
    }
    
    printf("=== Results: %d passed, %d failed ===\n", passed, failed);
    return (failed == 0) ? 0 : 1;
}

