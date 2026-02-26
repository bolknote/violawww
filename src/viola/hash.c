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
#include <inttypes.h>
#include <string.h>
static const unsigned int scatter[256] = {
     254970132,  2009114045,  1555322802,  1898824451,
     960045696,  1960239289,      802046,  1782549599,
    1246619308,  1954271093,  2070620938,   125472635,
     990429592,   558296561,    18410966,  1503176791,
    1939103556,  1573615661,  1309544802,  1494577907,
     303705008,   680815145,    71295406,     9063247,
     737039068,  1138786277,  1571580602,   818564459,
    1971044552,   488519009,    69630086,   985552199,
    2096111988,   807913117,   434214674,   721485539,
    1671946464,  1648308121,  1052643934,   859481663,
    1113205516,   281685077,   508884586,  1295869787,
     604302328,  1338915025,  1388580662,  1944133175,
    1134088100,   338465037,   674883778,   228550355,
    2019901968,  1167995145,   222416654,  1693424943,
    2101636924,  1953486021,  1003474458,  1247993163,
    2122793768,   788396097,  1728885222,  1015022375,
     446786004,   854644605,  2044855922,   828353219,
    1100304192,  1983409785,   843454398,  1577594911,
     522198892,  1137211701,   625471946,   394899259,
    2074461784,  1746170801,  2010865814,   702153751,
    1071443972,   692820461,  1483010082,  1081133747,
     121309296,   123004905,    84274286,  1017339663,
    1830828956,  2139822501,  1789419898,   364961067,
      12809608,  1345891105,   684399430,   518922503,
     199123508,  2010372189,   101557714,  1321322147,
     404319648,  1811586393,   561794334,  1688218111,
    1597490124,  1143911957,  1822170410,   131557147,
     302207160,  1414635153,   976675318,  1014716919,
     569950308,  1927320269,  1843865474,  1241620115,
    2041806544,  1727041225,   409221582,  1872597231,
    1343862780,   971656837,   210642138,    39603467,
      38295528,  1762020865,   960083110,  1358999271,
     541002388,   847825213,  1404859698,  1772049027,
     407649280,  2059254841,   523809406,   486183903,
     758716460,    78963445,  1554610314,  1537117947,
     590711576,  2059254129,   799970134,  1220354007,
    1334067396,    44268461,    68718306,   516547187,
    1994827056,  1504257449,  1077196590,  1104556751,
     650699868,   876966757,  1339627578,   464334059,
    1965943368,  1570693345,  1412464134,   498052295,
    1398498036,  1388816925,    71726226,    74468963,
    1598405216,  1438239513,   173230046,   957312447,
    1606163596,   873660373,  1774715882,  1817650907,
    1465152888,  1032897617,   974812342,  1201100215,
    1511485732,   642536589,  1112614466,  1329698387,
     300710800,  1354149001,  1095722126,  1397048495,
     499499196,   995395653,  1860254618,   153844939,
     931933352,   238707649,    25655142,   737352359,
    1288399700,    71858941,  1157866482,  1034730051,
    1981671616,   740739577,   228855102,  1188476831,
    2035863788,  1023478965,   340770634,   796470971,
    1115164632,  2063777585,   122848790,   235010967,
    2135576964,  1737694573,  1541991842,   132168243,
    1239220720,   961618793,   747389422,   534955663,
     229133596,  1473219877,   805211898,   240073899,
     326835976,  1460721313,   353804486,  2126706823,
    1613177780,   784546781,  1330381650,  1338807843,
    1374471968,   691845337,   537068190,   810054015,
     682046796,  1178012053,  1754835626,   914138779,
    1689803320,   223062545,   288278390,  1291129207,
     682942948,   204461645,   272098562,   287264275,
     164640848,  2091944521,  1589858126,  2141632623,
    2064157052,  1315865093,  1703481946,   177237131,
    1058193768,   274348417,   783677990,  1964459623
};

static inline int compute_str_hash(const char* str, int size)
{
    unsigned int key = 0;
    while (*str)
        key = (key << 1) + scatter[(unsigned char)*str++];
    return (int)(key % (unsigned int)size);
}

int hash_int(HashTable* ht, intptr_t n)
{
    /* Use unsigned to avoid issues with negative values */
    uintptr_t un = (uintptr_t)n;
    return (int)(un % (uintptr_t)ht->size);
}

int hash_str(HashTable* ht, intptr_t label)
{
    char* str = (char*)label;

    if (!str)
        return 0;

    return compute_str_hash(str, ht->size);
}
HashTable* initHashTable(int size, 
                         int (*func_hash)(HashTable*, intptr_t), 
                         intptr_t (*func_cmp)(intptr_t, intptr_t), 
                         void (*func_freeLabel)(intptr_t), 
                         void (*func_freeVal)(intptr_t),
                         HashEntry* (*func_get)(HashTable*, intptr_t), 
                         HashEntry* (*func_put)(HashTable*, intptr_t, intptr_t), 
                         HashEntry* (*func_put_replace)(HashTable*, intptr_t, intptr_t), 
                         int (*func_remove)(HashTable*, intptr_t))
{
    if (size <= 0) {
        fprintf(stderr, "initHashTable: invalid size %d (must be > 0)\n", size);
        return NULL;
    }
    
    struct HashTable* ht = (HashTable*)malloc(sizeof(struct HashTable));
    
    if (!ht) {
        fprintf(stderr, "initHashTable: malloc failed for HashTable\n");
        return NULL;
    }
    
    ht->entries = (HashEntry*)malloc(sizeof(struct HashEntry) * (size_t)size);
    if (!ht->entries) {
        fprintf(stderr, "initHashTable: malloc failed for entries\n");
        free(ht);
        return NULL;
    }
    
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
    return ht;
}

static inline HashEntry* put_hash_entry_block(HashTable* ht, int key, intptr_t label, intptr_t val)
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

HashEntry* putHashEntry(HashTable* ht, intptr_t label, intptr_t val)
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

HashEntry* putHashEntry_int(HashTable* ht, intptr_t label, intptr_t val)
{
    int key = (int)((uintptr_t)label % (uintptr_t)ht->size);
    return put_hash_entry_block(ht, key, label, val);
}

HashEntry* putHashEntry_str(HashTable* ht, intptr_t label, intptr_t val)
{
    char* str = (char*)label;

    if (!str)
        return NULL;

    return put_hash_entry_block(ht, compute_str_hash(str, ht->size), label, val);
}

HashEntry* putHashEntry_cancelable_int(HashTable* ht, intptr_t label, intptr_t val)
{
    int key = (int)((uintptr_t)label % (uintptr_t)ht->size);
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

static inline HashEntry* put_hash_entry_replace(HashTable* ht, int key, intptr_t label, intptr_t val)
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

HashEntry* putHashEntry_replace(HashTable* ht, intptr_t label, intptr_t val)
{
    int key = ht->func_hash(ht, label);
    return put_hash_entry_replace(ht, key, label, val);
}

HashEntry* putHashEntry_replace_int(HashTable* ht, intptr_t label, intptr_t val)
{
    int key = (int)((uintptr_t)label % (uintptr_t)ht->size);
    return put_hash_entry_replace(ht, key, label, val);
}

HashEntry* putHashEntry_replace_str(HashTable* ht, intptr_t label, intptr_t val)
{
    char* str = (char*)label;

    if (!str)
        return NULL;

    return put_hash_entry_replace(ht, compute_str_hash(str, ht->size), label, val);
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
        key = compute_str_hash((char*)label, ht->size);
    } else if (ht->func_hash == hash_int) {
        key = (int)((uintptr_t)label % (uintptr_t)ht->size);
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

HashEntry* getHashEntry_str(HashTable* ht, intptr_t label)
{
    char* labelStr = (char*)label;
    if (!labelStr)
        return NULL;

    int key = compute_str_hash(labelStr, ht->size);

    for (HashEntry* entry = &(ht->entries[key]); entry; entry = entry->next)
        if (entry->label)
            if (((char*)entry->label)[0] == labelStr[0])
                if (!strcmp((char*)entry->label, labelStr))
                    return entry;
    return NULL;
}

HashEntry* getHashEntry_int(HashTable* ht, intptr_t label)
{
    if (label == 0)
        return NULL;

    int key = (int)((uintptr_t)label % (uintptr_t)ht->size);
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

int removeHashEntry_int(HashTable* ht, intptr_t label)
{
    if (label == 0)
        return 0;

    int key = (int)((uintptr_t)label % (uintptr_t)ht->size);

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

int removeHashEntry_str(HashTable* ht, intptr_t label)
{
    char* labelStr = (char*)label;
    if (!labelStr)
        return 0;

    int key = compute_str_hash(labelStr, ht->size);

    HashEntry* prevEntry = NULL;
    for (HashEntry* entry = &(ht->entries[key]); entry; entry = entry->next) {
        if (entry->label) {
            if (((char*)(entry->label))[0] == labelStr[0]) {
                if (!strcmp((char*)(entry->label), labelStr)) {
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
                    printf("%d\tlabel=\"%s\"\tval=%" PRIdPTR "\n", i, (char*)hp->label, hp->val);
                } else {
                    printf("%d\tlabel=%" PRIdPTR "\tval=0x%" PRIxPTR "\n", i, hp->label, hp->val);
                }
            }
    }
}
