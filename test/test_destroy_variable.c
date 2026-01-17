/*
 * Integration test for destroyVariable functionality.
 * Tests the variable management functions: setVariable, getVariable, destroyVariable.
 *
 * This test creates a minimal mock of the symbol table (symStr2ID) to test
 * destroyVariable_internal without pulling in the entire Viola runtime.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* ===== Test framework ===== */
static int tests_run = 0;
static int tests_passed = 0;
static int tests_failed = 0;

#define ASSERT(cond, msg) do { \
    tests_run++; \
    if (cond) { \
        tests_passed++; \
        printf("PASS: %s\n", msg); \
    } else { \
        tests_failed++; \
        printf("FAIL: %s\n", msg); \
    } \
} while(0)

/* ===== Minimal Attr structure (from attr.h) ===== */
typedef struct Attr {
    struct Attr* next;
    long id;
    intptr_t val;
} Attr;

/* ===== Minimal Packet structure (from packet.h) ===== */
enum {
    PKT_INT = 0,
    PKT_CHR,
    PKT_FLT,
    PKT_STR,
};

#define PK_CANFREE_STR 1

typedef struct Packet {
    union {
        void* o;
        long i;
        float f;
        char c;
        char* s;
        struct Attr* a;
    } info;
    char type;
    char canFree;
    char sticky;
} Packet;

/* ===== Minimal HashEntry and HashTable for mock symStr2ID ===== */
typedef struct HashEntry {
    intptr_t key;
    intptr_t val;
    struct HashEntry* next;
} HashEntry;

typedef struct HashTable {
    HashEntry** table;
    int size;
    HashEntry* (*get)(struct HashTable*, intptr_t key);
} HashTable;

/* Simple hash table for testing - stores up to 100 string->id mappings */
#define MOCK_TABLE_SIZE 100
static HashEntry* mockEntries[MOCK_TABLE_SIZE];
static int mockCount = 0;

static HashEntry* mock_get(HashTable* ht, intptr_t key) {
    const char* name = (const char*)key;
    for (int i = 0; i < mockCount; i++) {
        if (mockEntries[i] && strcmp((const char*)mockEntries[i]->key, name) == 0) {
            return mockEntries[i];
        }
    }
    return NULL;
}

static void mock_put(const char* name, long id) {
    if (mockCount >= MOCK_TABLE_SIZE) return;
    HashEntry* entry = malloc(sizeof(HashEntry));
    entry->key = (intptr_t)name;
    entry->val = id;
    entry->next = NULL;
    mockEntries[mockCount++] = entry;
}

static HashTable mockHashTable = {
    .table = NULL,
    .size = 0,
    .get = mock_get
};

/* Global symbol table pointer (mocked) */
HashTable* symStr2ID = &mockHashTable;

/* ===== Helper functions ===== */
static void clearPacket(Packet* pk) {
    if (pk) {
        if (pk->canFree == PK_CANFREE_STR && pk->type == PKT_STR && pk->info.s) {
            free(pk->info.s);
        }
        pk->type = 0;
        pk->info.i = 0;
        pk->canFree = 0;
    }
}

static Packet* makePacket(void) {
    Packet* pk = malloc(sizeof(Packet));
    if (pk) {
        pk->type = 0;
        pk->info.i = 0;
        pk->canFree = 0;
        pk->sticky = 0;
    }
    return pk;
}

static Attr* makeAttr(long id, intptr_t val) {
    Attr* attr = malloc(sizeof(Attr));
    if (attr) {
        attr->id = id;
        attr->val = val;
        attr->next = NULL;
    }
    return attr;
}

static void prependAttr(Attr** head, Attr* attr) {
    if (attr) {
        attr->next = *head;
        *head = attr;
    }
}

/* ===== Copy of destroyVariable_internal from cexec.c ===== */
static Attr* destroyVariable_internal(Attr* varlist, char* name) {
    Attr *head = varlist;
    Attr *prev = NULL;
    HashEntry* entry;
    long varid;

    if (!name || !varlist) {
        return varlist;
    }

    if ((entry = symStr2ID->get(symStr2ID, (long)name))) {
        varid = entry->val;

        for (; varlist; prev = varlist, varlist = varlist->next) {
            if (varlist->id == varid) {
                /* Found the variable - remove it from the list */
                if (prev) {
                    prev->next = varlist->next;
                } else {
                    head = varlist->next;
                }
                /* Free the packet if it exists */
                if (varlist->val) {
                    Packet *pk = (Packet*)(varlist->val);
                    clearPacket(pk);
                    free(pk);
                }
                free(varlist);
                return head;
            }
        }
    }
    return head;
}

/* ===== Helper to create a variable in varlist ===== */
static Attr* createVariable(Attr* varlist, const char* name, long id, const char* value) {
    /* Register name->id in mock symbol table */
    mock_put(name, id);
    
    /* Create packet with string value */
    Packet* pk = makePacket();
    pk->type = PKT_STR;
    pk->info.s = strdup(value);
    pk->canFree = PK_CANFREE_STR;
    
    /* Create attr and prepend to list */
    Attr* attr = makeAttr(id, (intptr_t)pk);
    prependAttr(&varlist, attr);
    
    return varlist;
}

/* ===== Helper to find variable by id ===== */
static Attr* findVariableById(Attr* varlist, long id) {
    for (; varlist; varlist = varlist->next) {
        if (varlist->id == id) {
            return varlist;
        }
    }
    return NULL;
}

/* ===== Helper to count variables in list ===== */
static int countVariables(Attr* varlist) {
    int count = 0;
    for (; varlist; varlist = varlist->next) {
        count++;
    }
    return count;
}

/* ===== Tests ===== */
static void test_destroyVariable_basic(void) {
    printf("\n--- Testing destroyVariable basic ---\n");
    
    Attr* varlist = NULL;
    
    /* Create a variable */
    varlist = createVariable(varlist, "testVar", 1001, "testValue");
    ASSERT(countVariables(varlist) == 1, "varlist has 1 variable after creation");
    ASSERT(findVariableById(varlist, 1001) != NULL, "testVar exists in varlist");
    
    /* Destroy the variable */
    varlist = destroyVariable_internal(varlist, "testVar");
    ASSERT(countVariables(varlist) == 0, "varlist has 0 variables after destroy");
    ASSERT(findVariableById(varlist, 1001) == NULL, "testVar no longer exists");
}

static void test_destroyVariable_middle(void) {
    printf("\n--- Testing destroyVariable from middle ---\n");
    
    Attr* varlist = NULL;
    
    /* Create three variables */
    varlist = createVariable(varlist, "var1", 2001, "value1");
    varlist = createVariable(varlist, "var2", 2002, "value2");
    varlist = createVariable(varlist, "var3", 2003, "value3");
    
    ASSERT(countVariables(varlist) == 3, "varlist has 3 variables");
    
    /* Destroy the middle one */
    varlist = destroyVariable_internal(varlist, "var2");
    
    ASSERT(countVariables(varlist) == 2, "varlist has 2 variables after destroy");
    ASSERT(findVariableById(varlist, 2001) != NULL, "var1 still exists");
    ASSERT(findVariableById(varlist, 2002) == NULL, "var2 was removed");
    ASSERT(findVariableById(varlist, 2003) != NULL, "var3 still exists");
    
    /* Clean up remaining */
    varlist = destroyVariable_internal(varlist, "var1");
    varlist = destroyVariable_internal(varlist, "var3");
    ASSERT(countVariables(varlist) == 0, "all variables cleaned up");
}

static void test_destroyVariable_first(void) {
    printf("\n--- Testing destroyVariable first item ---\n");
    
    Attr* varlist = NULL;
    
    /* Create two variables (prepend means var2 is first) */
    varlist = createVariable(varlist, "first", 3001, "firstValue");
    varlist = createVariable(varlist, "second", 3002, "secondValue");
    
    ASSERT(varlist->id == 3002, "second is at head of list");
    
    /* Destroy the first (head) */
    varlist = destroyVariable_internal(varlist, "second");
    
    ASSERT(countVariables(varlist) == 1, "varlist has 1 variable");
    ASSERT(varlist->id == 3001, "first is now at head");
    
    /* Clean up */
    varlist = destroyVariable_internal(varlist, "first");
    ASSERT(varlist == NULL, "varlist is empty");
}

static void test_destroyVariable_last(void) {
    printf("\n--- Testing destroyVariable last item ---\n");
    
    Attr* varlist = NULL;
    
    /* Create two variables */
    varlist = createVariable(varlist, "alpha", 4001, "alphaValue");
    varlist = createVariable(varlist, "beta", 4002, "betaValue");
    
    /* alpha was added first, so it's at the end */
    ASSERT(varlist->next->id == 4001, "alpha is at tail of list");
    
    /* Destroy the last (tail) */
    varlist = destroyVariable_internal(varlist, "alpha");
    
    ASSERT(countVariables(varlist) == 1, "varlist has 1 variable");
    ASSERT(varlist->next == NULL, "no more items after head");
    
    /* Clean up */
    varlist = destroyVariable_internal(varlist, "beta");
}

static void test_destroyVariable_nonexistent(void) {
    printf("\n--- Testing destroyVariable non-existent ---\n");
    
    Attr* varlist = NULL;
    
    /* Create a variable */
    varlist = createVariable(varlist, "exists", 5001, "value");
    
    /* Try to destroy a non-existent variable */
    Attr* result = destroyVariable_internal(varlist, "doesNotExist");
    
    ASSERT(result == varlist, "varlist unchanged when destroying non-existent var");
    ASSERT(countVariables(result) == 1, "variable count unchanged");
    
    /* Clean up */
    destroyVariable_internal(varlist, "exists");
}

static void test_destroyVariable_null_inputs(void) {
    printf("\n--- Testing destroyVariable NULL inputs ---\n");
    
    Attr* varlist = NULL;
    
    /* NULL varlist */
    Attr* result = destroyVariable_internal(NULL, "anyName");
    ASSERT(result == NULL, "NULL varlist returns NULL");
    
    /* NULL name */
    varlist = createVariable(varlist, "test", 6001, "value");
    result = destroyVariable_internal(varlist, NULL);
    ASSERT(result == varlist, "NULL name returns unchanged varlist");
    ASSERT(countVariables(result) == 1, "variable not removed with NULL name");
    
    /* Clean up */
    destroyVariable_internal(varlist, "test");
}

/* ===== Main ===== */
int main(void) {
    printf("==========================================\n");
    printf("destroyVariable Integration Tests\n");
    printf("==========================================\n");
    
    test_destroyVariable_basic();
    test_destroyVariable_middle();
    test_destroyVariable_first();
    test_destroyVariable_last();
    test_destroyVariable_nonexistent();
    test_destroyVariable_null_inputs();
    
    printf("\n==========================================\n");
    printf("Test Results: %d/%d passed, %d failed\n", tests_passed, tests_run, tests_failed);
    printf("==========================================\n");
    
    if (tests_failed == 0) {
        printf("OVERALL: SUCCESS\n");
        return 0;
    } else {
        printf("OVERALL: FAILURE\n");
        return 1;
    }
}
