#pragma once
/* hash.h
 *
 */

typedef struct HashEntry {
    struct HashEntry* next;
    long label;
    long val;
} HashEntry;

typedef struct HashTable {
    HashEntry* entries;
    int size;
    int (*func_hash)(struct HashTable*, long);
    long (*func_cmp)(long, long);
    void (*func_freeLabel)(long);
    void (*func_freeVal)(long);
    HashEntry* (*get)(struct HashTable*, long);
    HashEntry* (*put)(struct HashTable*, long, long);
    HashEntry* (*put_replace)(struct HashTable*, long, long);
    int (*remove)(struct HashTable*, long);
} HashTable;

int hash_int(HashTable*, int);
int hash_str(HashTable*, char*);
HashTable* initHashTable(long, int (*)(HashTable*, long), long (*)(long, long), void (*)(long), void (*)(long), HashEntry* (*)(HashTable*, long), HashEntry* (*)(HashTable*, long, long), HashEntry* (*)(HashTable*, long, long), int (*)(HashTable*, long));

HashEntry* putHashEntry(struct HashTable*, long, long);
HashEntry* putHashEntry_replace(struct HashTable*, long, long);
HashEntry* getHashEntry(struct HashTable*, long);
int removeHashEntry(struct HashTable*, long);

HashEntry* putHashEntry_cancelable_int(HashTable* ht, long label, long val);

HashEntry* putHashEntry_int(HashTable* ht, long label, long val);
HashEntry* putHashEntry_replace_int(HashTable* ht, long label, long val);
HashEntry* getHashEntry_int(HashTable* ht, long label);
int removeHashEntry_int(HashTable* ht, long label);

HashEntry* putHashEntry_str(HashTable* ht, char* label, long val);
HashEntry* putHashEntry_replace_str(HashTable* ht, char* label, long val);
HashEntry* getHashEntry_str(HashTable* ht, char* label);
int removeHashEntry_str(HashTable* ht, char* label);

void dumpHashTable(HashTable*);
