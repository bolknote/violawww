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
    long (*func_hash)();
    long (*func_cmp)();
    long (*func_freeLabel)();
    long (*func_freeVal)();
    HashEntry* (*get)(struct HashTable*, long);
    HashEntry* (*put)();
    HashEntry* (*put_replace)();
    long (*remove)(struct HashTable*, long);
} HashTable;

int hash_int();
int hash_str();
HashTable* initHashTable();

HashEntry* putHashEntry();
HashEntry* putHashEntry_replace();
HashEntry* getHashEntry();
int removeHashEntry();

HashEntry* putHashEntry_cancelable_int(HashTable* ht, long label, long val);

HashEntry* putHashEntry_int(HashTable* ht, long label, long val);
HashEntry* putHashEntry_replace_int(HashTable* ht, long label, long val);
HashEntry* getHashEntry_int(HashTable* ht, long label);
int removeHashEntry_int(HashTable* ht, long label);

HashEntry* putHashEntry_str(HashTable* ht, char* label, long val);
HashEntry* putHashEntry_replace_str(HashTable* ht, char* label, long val);
HashEntry* getHashEntry_str(HashTable* ht, char* label);
int removeHashEntry_str(HashTable* ht, char* label);

void dumpHashTable();
