/* Comprehensive memory leak tests for hash table implementation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/viola/hash.h"
#include "../src/viola/mystrings.h"

static int tests_run = 0;
static int tests_passed = 0;

#define ASSERT(cond, msg) do { \
    tests_run++; \
    if (!(cond)) { \
        printf("FAIL: %s\n", msg); \
        return 0; \
    } else { \
        printf("PASS: %s\n", msg); \
        tests_passed++; \
    } \
} while (0)

/* Test 1: Remove first entry from int hash table with multiple entries in chain */
static int test_remove_first_int() {
    printf("\n--- Test: Remove first entry (int keys) ---\n");
    
    HashTable* ht = initHashTable(3, hash_int, NULL, NULL, NULL, 
                                   NULL, NULL, NULL, NULL);
    ASSERT(ht != NULL, "Hash table initialization");
    
    /* Insert 3 entries that will hash to the same bucket */
    /* With size=3, entries 3, 6, 9 all hash to bucket 0 */
    putHashEntry_int(ht, 3, 100);
    putHashEntry_int(ht, 6, 200);
    putHashEntry_int(ht, 9, 300);
    
    /* Verify all entries exist */
    HashEntry* e1 = getHashEntry_int(ht, 3);
    HashEntry* e2 = getHashEntry_int(ht, 6);
    HashEntry* e3 = getHashEntry_int(ht, 9);
    ASSERT(e1 != NULL && e1->val == 100, "Entry 3 found with val 100");
    ASSERT(e2 != NULL && e2->val == 200, "Entry 6 found with val 200");
    ASSERT(e3 != NULL && e3->val == 300, "Entry 9 found with val 300");
    
    /* Remove first entry (key=3) */
    int ret = removeHashEntry_int(ht, 3);
    ASSERT(ret == 1, "Remove returned 1");
    
    /* Verify remaining entries */
    HashEntry* after1 = getHashEntry_int(ht, 3);
    HashEntry* after2 = getHashEntry_int(ht, 6);
    HashEntry* after3 = getHashEntry_int(ht, 9);
    ASSERT(after1 == NULL, "Entry 3 removed");
    ASSERT(after2 != NULL && after2->val == 200, "Entry 6 still exists");
    ASSERT(after3 != NULL && after3->val == 300, "Entry 9 still exists");
    
    free(ht->entries);
    free(ht);
    return 1;
}

/* Test 2: Remove first entry from string hash table with multiple entries in chain */
static int test_remove_first_str() {
    printf("\n--- Test: Remove first entry (string keys) ---\n");
    
    HashTable* ht = initHashTable(3, hash_str, NULL, NULL, NULL, 
                                   NULL, NULL, NULL, NULL);
    ASSERT(ht != NULL, "Hash table initialization");
    
    /* Insert entries with same hash */
    putHashEntry_str(ht, "abc", 100);
    putHashEntry_str(ht, "def", 200);
    putHashEntry_str(ht, "ghi", 300);
    
    /* Verify all entries exist */
    HashEntry* e1 = getHashEntry_str(ht, "abc");
    HashEntry* e2 = getHashEntry_str(ht, "def");
    HashEntry* e3 = getHashEntry_str(ht, "ghi");
    ASSERT(e1 != NULL && e1->val == 100, "Entry 'abc' found with val 100");
    ASSERT(e2 != NULL && e2->val == 200, "Entry 'def' found with val 200");
    ASSERT(e3 != NULL && e3->val == 300, "Entry 'ghi' found with val 300");
    
    /* Remove first entry */
    int ret = removeHashEntry_str(ht, "abc");
    ASSERT(ret == 1, "Remove returned 1");
    
    /* Verify remaining entries */
    HashEntry* after1 = getHashEntry_str(ht, "abc");
    HashEntry* after2 = getHashEntry_str(ht, "def");
    HashEntry* after3 = getHashEntry_str(ht, "ghi");
    ASSERT(after1 == NULL, "Entry 'abc' removed");
    ASSERT(after2 != NULL && after2->val == 200, "Entry 'def' still exists");
    ASSERT(after3 != NULL && after3->val == 300, "Entry 'ghi' still exists");
    
    free(ht->entries);
    free(ht);
    return 1;
}

/* Test 3: Remove middle entry from chain */
static int test_remove_middle() {
    printf("\n--- Test: Remove middle entry from chain ---\n");
    
    HashTable* ht = initHashTable(3, hash_int, NULL, NULL, NULL, 
                                   NULL, NULL, NULL, NULL);
    ASSERT(ht != NULL, "Hash table initialization");
    
    /* Insert 3 entries */
    putHashEntry_int(ht, 3, 100);
    putHashEntry_int(ht, 6, 200);
    putHashEntry_int(ht, 9, 300);
    
    /* Remove middle entry (key=6) */
    int ret = removeHashEntry_int(ht, 6);
    ASSERT(ret == 1, "Remove returned 1");
    
    /* Verify remaining entries */
    HashEntry* e1 = getHashEntry_int(ht, 3);
    HashEntry* e2 = getHashEntry_int(ht, 6);
    HashEntry* e3 = getHashEntry_int(ht, 9);
    ASSERT(e1 != NULL && e1->val == 100, "Entry 3 still exists");
    ASSERT(e2 == NULL, "Entry 6 removed");
    ASSERT(e3 != NULL && e3->val == 300, "Entry 9 still exists");
    
    free(ht->entries);
    free(ht);
    return 1;
}

/* Test 4: Remove last entry from chain */
static int test_remove_last() {
    printf("\n--- Test: Remove last entry from chain ---\n");
    
    HashTable* ht = initHashTable(3, hash_int, NULL, NULL, NULL, 
                                   NULL, NULL, NULL, NULL);
    ASSERT(ht != NULL, "Hash table initialization");
    
    /* Insert 3 entries */
    putHashEntry_int(ht, 3, 100);
    putHashEntry_int(ht, 6, 200);
    putHashEntry_int(ht, 9, 300);
    
    /* Remove last entry (key=9) */
    int ret = removeHashEntry_int(ht, 9);
    ASSERT(ret == 1, "Remove returned 1");
    
    /* Verify remaining entries */
    HashEntry* e1 = getHashEntry_int(ht, 3);
    HashEntry* e2 = getHashEntry_int(ht, 6);
    HashEntry* e3 = getHashEntry_int(ht, 9);
    ASSERT(e1 != NULL && e1->val == 100, "Entry 3 still exists");
    ASSERT(e2 != NULL && e2->val == 200, "Entry 6 still exists");
    ASSERT(e3 == NULL, "Entry 9 removed");
    
    free(ht->entries);
    free(ht);
    return 1;
}

/* Test 5: Remove only entry from bucket */
static int test_remove_only() {
    printf("\n--- Test: Remove only entry from bucket ---\n");
    
    HashTable* ht = initHashTable(3, hash_int, NULL, NULL, NULL, 
                                   NULL, NULL, NULL, NULL);
    ASSERT(ht != NULL, "Hash table initialization");
    
    /* Insert single entry */
    putHashEntry_int(ht, 3, 100);
    
    /* Verify it exists */
    HashEntry* e1 = getHashEntry_int(ht, 3);
    ASSERT(e1 != NULL && e1->val == 100, "Entry 3 found");
    
    /* Remove it */
    int ret = removeHashEntry_int(ht, 3);
    ASSERT(ret == 1, "Remove returned 1");
    
    /* Verify it's gone */
    HashEntry* after = getHashEntry_int(ht, 3);
    ASSERT(after == NULL, "Entry 3 removed");
    
    free(ht->entries);
    free(ht);
    return 1;
}

/* Test 6: Remove non-existent entry */
static int test_remove_nonexistent() {
    printf("\n--- Test: Remove non-existent entry ---\n");
    
    HashTable* ht = initHashTable(3, hash_int, NULL, NULL, NULL, 
                                   NULL, NULL, NULL, NULL);
    ASSERT(ht != NULL, "Hash table initialization");
    
    /* Try to remove non-existent entry */
    int ret = removeHashEntry_int(ht, 999);
    ASSERT(ret == 0, "Remove returned 0 for non-existent entry");
    
    free(ht->entries);
    free(ht);
    return 1;
}

/* Test 7: Remove entry zero */
static int test_remove_zero() {
    printf("\n--- Test: Remove entry with label 0 (should be ignored) ---\n");
    
    HashTable* ht = initHashTable(3, hash_int, NULL, NULL, NULL, 
                                   NULL, NULL, NULL, NULL);
    ASSERT(ht != NULL, "Hash table initialization");
    
    /* Try to remove entry with label 0 */
    int ret = removeHashEntry_int(ht, 0);
    ASSERT(ret == 0, "Remove returned 0 for label 0");
    
    free(ht->entries);
    free(ht);
    return 1;
}

/* Test 8: Chain stress test - add and remove multiple entries */
static int test_stress_chain() {
    printf("\n--- Test: Stress test with multiple chain operations ---\n");
    
    HashTable* ht = initHashTable(7, hash_int, NULL, NULL, NULL, 
                                   NULL, NULL, NULL, NULL);
    ASSERT(ht != NULL, "Hash table initialization");
    
    /* Insert 20 entries (not 21, to avoid 0 which is not allowed) */
    for (long i = 1; i <= 20; i++) {
        putHashEntry_int(ht, i, i * 10);
    }
    
    /* Verify all exist */
    for (long i = 1; i <= 20; i++) {
        HashEntry* e = getHashEntry_int(ht, i);
        ASSERT(e != NULL && e->val == i * 10, "Entry found and correct");
    }
    
    /* Remove first 7 entries (one per bucket) */
    for (long i = 1; i <= 7; i++) {
        int ret = removeHashEntry_int(ht, i);
        ASSERT(ret == 1, "Remove succeeded");
    }
    
    /* Verify remaining 13 entries */
    for (long i = 1; i <= 7; i++) {
        HashEntry* e = getHashEntry_int(ht, i);
        ASSERT(e == NULL, "Removed entry not found");
    }
    for (long i = 8; i <= 20; i++) {
        HashEntry* e = getHashEntry_int(ht, i);
        ASSERT(e != NULL && e->val == i * 10, "Remaining entry found and correct");
    }
    
    free(ht->entries);
    free(ht);
    return 1;
}

int main() {
    printf("=======================================\n");
    printf("Hash Table Memory Leak Tests\n");
    printf("=======================================\n");
    
    test_remove_first_int();
    test_remove_first_str();
    test_remove_middle();
    test_remove_last();
    test_remove_only();
    test_remove_nonexistent();
    test_remove_zero();
    test_stress_chain();
    
    printf("\n=======================================\n");
    printf("Test Results: %d/%d passed\n", tests_passed, tests_run);
    printf("=======================================\n");
    
    if (tests_passed == tests_run) {
        printf("OVERALL: SUCCESS\n");
        return 0;
    } else {
        printf("OVERALL: FAILURE\n");
        return 1;
    }
}

