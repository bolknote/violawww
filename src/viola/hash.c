/*
 * Copyright 1990 Pei-Yuan Wei.  All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */

/*
 * hash.c
 */
#include "hash.h"
#include "mystrings.h"
#include "utils.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
/*
static int scatter[] = {
112269159,      1414846676,     156382461,      1455714,
872078403,      1874748096,     916896761,      769267518,
820312479,      92728044,       344858293,      1121741130,
1495896251,     208521688,      860811569,      1660932118,
525761943,      736209796,      493907821,      639686562,
654007347,      1905261552,     78746985,       1398328302,
856000655,      1452336924,     1573199653,     2013903098,
500965035,      1800624392,     2077067425,     1672112838
};
*/
int hash_int(HashTable* ht, int n)
{
    return n % ht->size;
}

int hash_str(HashTable* ht, char* str)
{
    int key = 0;

    while (*str)
        key += *str++;
    key = key % ht->size;

    return key;
}

/*
int hash_str(HashTable * ht, char * str)
{
        int key = 0;

        while (*str) key = (key << 1) + scatter[*str++];
        key &= ht->size - 1;

        return key;
}
*/
HashTable* initHashTable(long size, int (*func_hash)(HashTable*, long), long (*func_cmp)(long, long), 
                         void (*func_freeLabel)(long), void (*func_freeVal)(long),
                         HashEntry* (*func_get)(HashTable*, long), HashEntry* (*func_put)(HashTable*, long, long), 
                         HashEntry* (*func_put_replace)(HashTable*, long, long), int (*func_remove)(HashTable*, long))
{
    struct HashTable* ht = (HashTable*)malloc(sizeof(struct HashTable));
    
    if (ht) {
        ht->entries = (HashEntry*)malloc(sizeof(struct HashEntry) * size);
        *ht = (HashTable){
            .entries = ht->entries,
            .size = size,
            .func_hash = func_hash,
            .func_cmp = func_cmp,
            .func_freeLabel = func_freeLabel,
            .func_freeVal = func_freeVal,
            .get = func_get,
            .put = func_put,
            .put_replace = func_put_replace,
            .remove = func_remove
        };

        HashEntry* entryp = ht->entries;
        for (int i = size - 1; i >= 0; i--) {
            *entryp = (HashEntry){
                .next = NULL,
                .label = 0,
                .val = 0
            };
            entryp++;
        }
    }
    return ht;
}

static inline HashEntry* put_hash_entry_block(HashTable* ht, int key, long label, long val)
{
    HashEntry* base_entry = &(ht->entries[key]);
    
    if (base_entry->label) {
        HashEntry* entry = base_entry;
        while (entry->next)
            entry = entry->next;
        
        HashEntry* new_entry = (HashEntry*)malloc(sizeof(struct HashEntry));
        if (new_entry) {
            *new_entry = (HashEntry){
                .label = label,
                .val = val,
                .next = NULL
            };
            entry->next = new_entry;
        } else {
            fprintf(stderr, "malloc failed.\n");
        }
        return new_entry;
    } else {
        *base_entry = (HashEntry){
            .label = label,
            .val = val,
            .next = NULL
        };
        return base_entry;
    }
}

HashEntry* putHashEntry(HashTable* ht, long label, long val)
{
    int key = ht->func_hash(ht, label);
    /*
            if (ht->func_hash == hash_str) {
                    printf("label='%s' \tkey=%ld \tval=%d\n", label, key, val);
            } else {
                    printf("label=%d \tkey=%ld \tval='%s'\n", label, key, val);
            }
    */
    return put_hash_entry_block(ht, key, label, val);
}

HashEntry* putHashEntry_int(HashTable* ht, long label, long val)
{
    int key = label % ht->size;
    return put_hash_entry_block(ht, key, label, val);
}

HashEntry* putHashEntry_str(HashTable* ht, char* label, long val)
{
    int key = 0;
    char* str = label;

    while (*str)
        key += *str++;
    key = key % ht->size;

    return put_hash_entry_block(ht, key, (long)label, val);
}

HashEntry* putHashEntry_cancelable_int(HashTable* ht, long label, long val)
{
    int key = label % ht->size;
    HashEntry* base_entry = &(ht->entries[key]);

    if (base_entry->label) {
        HashEntry* entry;
        for (entry = base_entry; entry->label; entry = entry->next) {
            if (entry->label == label) {
                // nevermind. entry of same id already exist
                return base_entry;
            }
            if (!entry->next)
                break;
        }
        HashEntry* new_entry = (HashEntry*)malloc(sizeof(struct HashEntry));
        if (new_entry) {
            *new_entry = (HashEntry){
                .label = label,
                .val = val,
                .next = NULL
            };
            entry->next = new_entry;
        } else {
            fprintf(stderr, "malloc() failed.\n");
        }
        return new_entry;
    } else {
        *base_entry = (HashEntry){
            .label = label,
            .val = val,
            .next = NULL
        };
        return base_entry;
    }
}

static inline HashEntry* put_hash_entry_replace(HashTable* ht, int key, long label, long val)
{
    HashEntry* base_entry = &(ht->entries[key]);

    if (base_entry->label) {
        HashEntry* entry;
        for (entry = base_entry; entry->label; entry = entry->next) {
            if (entry->label == label) {
                // override
                entry->val = val;
                return base_entry;
            }
            if (!entry->next)
                break;
        }
        HashEntry* new_entry = (HashEntry*)malloc(sizeof(struct HashEntry));
        if (new_entry) {
            *new_entry = (HashEntry){
                .label = label,
                .val = val,
                .next = NULL
            };
            entry->next = new_entry;
        } else {
            fprintf(stderr, "malloc() failed.\n");
        }
        return new_entry;
    } else {
        *base_entry = (HashEntry){
            .label = label,
            .val = val,
            .next = NULL
        };
        return base_entry;
    }
}

HashEntry* putHashEntry_replace(HashTable* ht, long label, long val)
{
    int key = ht->func_hash(ht, label);
    return put_hash_entry_replace(ht, key, label, val);
}

HashEntry* putHashEntry_replace_int(HashTable* ht, long label, long val)
{
    int key = label % ht->size;
    return put_hash_entry_replace(ht, key, label, val);
}

HashEntry* putHashEntry_replace_str(HashTable* ht, char* label, long val)
{
    int key = 0;
    char* str = label;

    while (*str)
        key += *str++;
    key = key % ht->size;

    return put_hash_entry_replace(ht, key, (long)label, val);
}

#ifdef NOT_USED
HashEntry* getHashEntry(HashTable* ht, long label)
{
    int key;
    HashEntry *entry, *base_entry;

    if (!ht) {
        printf("Internal error: ht==NULL\n");
        return 0;
    }

    /*	key = ht->func_hash(ht, label);*/

    if (ht->func_hash == hash_str) {
        char* str = label;

        key = 0;
        while (*str)
            key += *str++;
        key = key % ht->size;
        /*
                        key = 0;
                        while (*str) key = (key << 1) + scatter[*str++];
                        key &= ht->size - 1;
        */
    } else if (ht->func_hash == hash_int) {
        key = label % ht->size;
    }

    base_entry = &(ht->entries[key]);

    if (ht->func_hash == hash_str) {
        /* Use strcmp: returns 0 for equality, so we check for !result */
        for (entry = base_entry; entry; entry = entry->next) {
            if (entry->label) {
                if (strcmp((char*)entry->label, (char*)label) == 0)
                    return entry;
            }
        }
    } else if (ht->func_cmp == cmp_int) {
        for (entry = base_entry; entry; entry = entry->next) {
            /*!!!! next line MUST be present, else things seems to not work right. very strance...
             * must be using entry-existence-only value somewhere */
            if (entry->label)

                if (entry->label == label)
                    return entry;
        }
    } else {
        for (entry = base_entry; entry; entry = entry->next) {
            if (ht->func_cmp(entry->label, label))
                return entry;
        }
    }
    /*
            if (ht->func_hash == hash_str) {
                 printf("key=%d \tlabel=\"%s\" \tval=%d\n",
                    key, (char*)label, entry->val);
            } else {
                printf("key=%d \tlabel=%d \tval=0x%x\n",
                    key, entry->label, entry->val);
            }
    */
    return NULL;
}
#endif

HashEntry* getHashEntry_str(HashTable* ht, char* label)
{
    if (label == 0)
        return NULL;

    int key = 0;
    char* str = label;
    while (*str)
        key += *str++;
    key = key % ht->size;

    for (HashEntry* entry = &(ht->entries[key]); entry; entry = entry->next)
        if (entry->label)
            if (((char*)entry->label)[0] == ((char*)label)[0])
                if (!strcmp((char*)entry->label, (char*)label))
                    return entry;
    return NULL;
}

HashEntry* getHashEntry_int(HashTable* ht, long label)
{
    if (label == 0)
        return NULL;

    int key = label % ht->size;
    for (HashEntry* entry = &(ht->entries[key]); entry; entry = entry->next)
        if (entry->label == label)
            return entry;

    return NULL;
}

#ifdef NOT_USED
int removeHashEntry(HashTable* ht, long label)
{
    int key;
    HashEntry *entry, *base_entry, *prevEntry;

    key = ht->func_hash(ht, label);
    base_entry = &(ht->entries[key]);

    prevEntry = NULL;
    for (entry = base_entry; entry; entry = entry->next) {
        if (entry->label) {
            if (ht->func_cmp(entry->label, label)) {
                /*
                                                if (ht->func_hash == hash_str) {
                                        printf("REMOVE key=%d \tlabel=\"%s\" \tval=%d\n",
                                                        key, (char*)entry->label, entry->val);
                                                } else {
                                        printf("REMOVE key=%d \tlabel=%d \tval=0x%x\n",
                                                        key, entry->label, entry->val);
                                                }
                */
                if (ht->func_freeLabel)
                    ht->func_freeLabel(entry->label);
                if (ht->func_freeVal)
                    ht->func_freeVal(entry->val);

                if (prevEntry) {
                    prevEntry->next = entry->next;
                    free(entry);
                } else {
                    if (entry->next) {
                        HashEntry* to_free = entry->next;
                        entry->label = entry->next->label;
                        entry->val = entry->next->val;
                        entry->next = entry->next->next;
                        free(to_free);
                    } else {
                        entry->label = 0;
                        entry->val = 0;
                    }
                }
                return 1;
            }
        }
        prevEntry = entry;
    }
    return NULL;
}
#endif

int removeHashEntry_int(HashTable* ht, long label)
{
    if (label == 0)
        return 0;

    int key = label % ht->size;

    HashEntry* prevEntry = NULL;
    for (HashEntry* entry = &(ht->entries[key]); entry; entry = entry->next) {
        if (entry->label == label) {
            if (ht->func_freeLabel)
                ht->func_freeLabel(entry->label);
            if (ht->func_freeVal)
                ht->func_freeVal(entry->val);
            if (prevEntry) {
                prevEntry->next = entry->next;
                free(entry);
            } else {
                if (entry->next) {
                    HashEntry* to_free = entry->next;
                    entry->label = entry->next->label;
                    entry->val = entry->next->val;
                    entry->next = entry->next->next;
                    free(to_free);
                } else {
                    entry->label = 0;
                    entry->val = 0;
                }
            }
            return 1;
        }
        prevEntry = entry;
    }
    return 0;
}

int removeHashEntry_str(HashTable* ht, char* label)
{
    if (label == 0)
        return 0;

    char* str = label;
    int key = 0;
    while (*str)
        key += *str++;
    key = key % ht->size;

    HashEntry* prevEntry = NULL;
    for (HashEntry* entry = &(ht->entries[key]); entry; entry = entry->next) {
        if (entry->label) {
            if (((char*)(entry->label))[0] == ((char*)label)[0]) {
                if (!strcmp((char*)(entry->label), label)) {
                    if (ht->func_freeLabel)
                        ht->func_freeLabel(entry->label);
                    if (ht->func_freeVal)
                        ht->func_freeVal(entry->val);
                    if (prevEntry) {
                        prevEntry->next = entry->next;
                        free(entry);
                    } else {
                        if (entry->next) {
                            HashEntry* to_free = entry->next;
                            entry->label = entry->next->label;
                            entry->val = entry->next->val;
                            entry->next = entry->next->next;
                            free(to_free);
                        } else {
                            entry->label = 0;
                            entry->val = 0;
                        }
                    }
                    return 1;
                }
            }
        }
        prevEntry = entry;
    }
    return 0;
}

void dumpHashTable(HashTable* ht)
{
    printf("size = %d\n", ht->size);

    for (int i = 0; i < ht->size; i++) {
        for (HashEntry* hp = &(ht->entries[i]); hp; hp = hp->next)
            if (hp->label) {
                if (ht->func_hash == hash_str) {
                    printf("%d\tlabel=\"%s\"\tval=%ld\n", i, (char*)hp->label, hp->val);
                } else {
                    printf("%d\tlabel=%ld\tval=0x%lx\n", i, hp->label, hp->val);
                }
            }
    }
}
