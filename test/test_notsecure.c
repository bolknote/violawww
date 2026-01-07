/* Test program for notSecure() function security checks */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Minimal VObj structure for testing */
typedef struct {
    long padding[10];  /* Placeholder slots */
    long security;     /* Security slot */
    char* name;        /* Object name */
} TestVObj;

/* Simulated GET_security macro */
#define GET_security(obj) (((TestVObj*)(obj))->security)
#define GET_name(obj) (((TestVObj*)(obj))->name)

/* Copy of notSecure() from cl_cosmic.c for standalone testing */
int notSecure(TestVObj* self)
{
    /* NULL object is treated as untrusted */
    if (self == NULL) return 1;
    
    if (GET_security(self) > 0) {
        /* Don't print in tests */
        return 1;
    }
    return 0;
}

int main() {
    struct {
        TestVObj* obj;
        int expected;
        char* description;
    } tests[10];
    
    int num_tests = 0;
    
    /* Create test objects */
    TestVObj trusted_obj = {.security = 0, .name = "trusted"};
    TestVObj untrusted_obj = {.security = 1, .name = "untrusted"};
    TestVObj high_security_obj = {.security = 99, .name = "high_security"};
    
    /* Test 1: NULL object should be untrusted */
    tests[num_tests].obj = NULL;
    tests[num_tests].expected = 1;
    tests[num_tests].description = "NULL object returns 1 (untrusted)";
    num_tests++;
    
    /* Test 2: Trusted object (security=0) should be secure */
    tests[num_tests].obj = &trusted_obj;
    tests[num_tests].expected = 0;
    tests[num_tests].description = "Trusted object (security=0) returns 0 (allowed)";
    num_tests++;
    
    /* Test 3: Untrusted object (security=1) should be blocked */
    tests[num_tests].obj = &untrusted_obj;
    tests[num_tests].expected = 1;
    tests[num_tests].description = "Untrusted object (security=1) returns 1 (blocked)";
    num_tests++;
    
    /* Test 4: High security level should be blocked */
    tests[num_tests].obj = &high_security_obj;
    tests[num_tests].expected = 1;
    tests[num_tests].description = "High security (security=99) returns 1 (blocked)";
    num_tests++;
    
    int passed = 0, failed = 0;
    
    printf("=== notSecure() Function Security Tests ===\n\n");
    
    for (int i = 0; i < num_tests; i++) {
        int result = notSecure(tests[i].obj);
        int success = (result == tests[i].expected);
        
        printf("[%s] %s\n", success ? "PASS" : "FAIL", tests[i].description);
        printf("  Object: %s, Security: %ld\n", 
               tests[i].obj ? GET_name(tests[i].obj) : "(null)",
               tests[i].obj ? GET_security(tests[i].obj) : -1);
        printf("  Expected: %d, Got: %d\n\n", tests[i].expected, result);
        
        if (success)
            passed++;
        else
            failed++;
    }
    
    printf("=== Results: %d passed, %d failed ===\n", passed, failed);
    return (failed == 0) ? 0 : 1;
}

