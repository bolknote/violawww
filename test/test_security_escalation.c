/* Test program for security escalation prevention */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Minimal structures for testing */
typedef struct {
    long padding[10];
    long security;
    char* name;
} TestVObj;

#define GET_security(obj) (((TestVObj*)(obj))->security)
#define GET_name(obj) (((TestVObj*)(obj))->name)

/* Simulate the security escalation check from cl_generic.c */
int try_set_security(TestVObj* self, long newLevel, long* result_level) {
    long currentLevel = GET_security(self);
    
    /* Security: block privilege escalation from untrusted (1) to trusted (0) */
    if (currentLevel > 0 && newLevel == 0) {
        /* Escalation denied */
        *result_level = currentLevel;
        return 0;  /* Failure */
    }
    
    /* Set the new level */
    self->security = newLevel;
    *result_level = newLevel;
    return 1;  /* Success */
}

int main() {
    int passed = 0, failed = 0;
    
    printf("=== Security Escalation Prevention Tests ===\n\n");
    
    /* Test 1: Trusted object can stay trusted */
    {
        TestVObj obj = {.security = 0, .name = "trusted"};
        long result_level;
        int success = try_set_security(&obj, 0, &result_level);
        
        int test_passed = (success == 1 && result_level == 0);
        printf("[%s] Trusted object setting security=0 (should succeed)\n", 
               test_passed ? "PASS" : "FAIL");
        printf("  Initial: 0, New: 0, Result: %ld, Success: %d\n\n", result_level, success);
        
        if (test_passed) passed++; else failed++;
    }
    
    /* Test 2: Trusted object can become untrusted */
    {
        TestVObj obj = {.security = 0, .name = "trusted"};
        long result_level;
        int success = try_set_security(&obj, 1, &result_level);
        
        int test_passed = (success == 1 && result_level == 1);
        printf("[%s] Trusted object setting security=1 (should succeed)\n", 
               test_passed ? "PASS" : "FAIL");
        printf("  Initial: 0, New: 1, Result: %ld, Success: %d\n\n", result_level, success);
        
        if (test_passed) passed++; else failed++;
    }
    
    /* Test 3: Untrusted object CANNOT become trusted (CRITICAL) */
    {
        TestVObj obj = {.security = 1, .name = "untrusted"};
        long result_level;
        int success = try_set_security(&obj, 0, &result_level);
        
        int test_passed = (success == 0 && result_level == 1);
        printf("[%s] Untrusted object setting security=0 (MUST FAIL)\n", 
               test_passed ? "PASS" : "FAIL");
        printf("  Initial: 1, New: 0, Result: %ld, Success: %d\n\n", result_level, success);
        
        if (test_passed) passed++; else failed++;
    }
    
    /* Test 4: Untrusted object can stay untrusted */
    {
        TestVObj obj = {.security = 1, .name = "untrusted"};
        long result_level;
        int success = try_set_security(&obj, 1, &result_level);
        
        int test_passed = (success == 1 && result_level == 1);
        printf("[%s] Untrusted object setting security=1 (should succeed)\n", 
               test_passed ? "PASS" : "FAIL");
        printf("  Initial: 1, New: 1, Result: %ld, Success: %d\n\n", result_level, success);
        
        if (test_passed) passed++; else failed++;
    }
    
    /* Test 5: High security level cannot escalate to trusted */
    {
        TestVObj obj = {.security = 99, .name = "high_security"};
        long result_level;
        int success = try_set_security(&obj, 0, &result_level);
        
        int test_passed = (success == 0 && result_level == 99);
        printf("[%s] High security (99) setting security=0 (MUST FAIL)\n", 
               test_passed ? "PASS" : "FAIL");
        printf("  Initial: 99, New: 0, Result: %ld, Success: %d\n\n", result_level, success);
        
        if (test_passed) passed++; else failed++;
    }
    
    /* Test 6: High security can lower to 1 (still untrusted) */
    {
        TestVObj obj = {.security = 99, .name = "high_security"};
        long result_level;
        int success = try_set_security(&obj, 1, &result_level);
        
        int test_passed = (success == 1 && result_level == 1);
        printf("[%s] High security (99) setting security=1 (should succeed)\n", 
               test_passed ? "PASS" : "FAIL");
        printf("  Initial: 99, New: 1, Result: %ld, Success: %d\n\n", result_level, success);
        
        if (test_passed) passed++; else failed++;
    }
    
    printf("=== Results: %d passed, %d failed ===\n", passed, failed);
    return (failed == 0) ? 0 : 1;
}

