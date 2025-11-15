#include "../libStyle/libstg.h"
#include "hash.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "utils.h"
#include <string.h>

extern char* loadFile();

STGLib* stgLib;
STGGroup* stgGroup;

HashTable* HT_str2token;
HashTable* HT_token2str;

char* returnSame(char* a)
{
    return a;
}

long tagName2ID(char* s)
{
    HashEntry* entry;
    static long idCount = 0;

    entry = HT_str2token->get(HT_str2token, (long)s);
    if (entry)
        return entry->val;

    entry = HT_str2token->put(HT_str2token, (long)saveString(s), (long)++idCount);
    if (!entry)
        return 0;

    entry = putHashEntry(HT_token2str, idCount, (long)saveString(s));
    if (!entry)
        return 0;
    return idCount;
}

char* tagID2Name(int id)
{
    HashEntry* entry = HT_token2str->get(HT_token2str, (long)id);
    if (entry)
        return (char*)entry->val;
    return NULL;
}

int stgcall_init() {
    HT_str2token = initHashTable(100, (int (*)(HashTable*, long))hash_str, (long (*)(long, long))cmp_str, NULL, NULL, (HashEntry* (*)(HashTable*, long))getHashEntry_str,
                                 (HashEntry* (*)(HashTable*, long, long))putHashEntry_str, (HashEntry* (*)(HashTable*, long, long))putHashEntry_replace_str, (int (*)(HashTable*, long))removeHashEntry_str);
    if (!HT_str2token)
        return 0;
    HT_token2str = initHashTable(100, (int (*)(HashTable*, long))hash_int, (long (*)(long, long))cmp_int, NULL, NULL, (HashEntry* (*)(HashTable*, long))getHashEntry_int,
                                 (HashEntry* (*)(HashTable*, long, long))putHashEntry_int, (HashEntry* (*)(HashTable*, long, long))putHashEntry_replace_int, (int (*)(HashTable*, long))removeHashEntry_int);
    if (!HT_token2str)
        return 0;

    stgLib = STG_init(cmp_int, tagName2ID, tagID2Name, cmp_int, tagName2ID, tagID2Name);
    if (!stgLib)
        return 0;

    return 1;
}

/*XXX now url is filename
 */
int loadSTG(char* url)
{
    char* spec;
    char inFile[500];
    int stat;
    extern int WWW_TraceFlag;

    /* load a stylesheet
     */
    strcpy(inFile, url);
    stat = (int)(long)loadFile(inFile, &spec);

    if (stat == -1) {
        printf("failed to open %s\n", inFile);
        return 0;
    }
    stgGroup = STG_makeGroup(stgLib, spec);

    if (WWW_TraceFlag && stgGroup) {
        printf("### loadSTG: Dumping parsed stylesheet:\n");
        STG_dumpGroup(stgGroup);
    }

    free(spec);
    return (stgGroup ? 1 : 0);
}

/*
 * access to libstg - with style attribute support
 */
int getSTGInfo_tagPtrWithStyle(Packet* result, char* tagName1, char* tagName2, char* styleAttr)
/* tagName2: super element */
/* styleAttr: style attribute value like "WARNING" */
{
    int stat;
    char* context[4];
    STGResult results[2];
    extern int WWW_TraceFlag;

    clearPacket(result);

    if (!stgGroup)
        return 0;

    if (WWW_TraceFlag && styleAttr) {
        printf("### getSTGInfo_tagPtrWithStyle: tag=%s styleAttr=%s\n", tagName1, styleAttr);
    }

    context[0] = (char*)(long)tagName2ID(tagName1);
    context[1] = styleAttr ? (char*)(long)tagName2ID(styleAttr) : NULL;
    if (tagName2 && tagName2[0]) {
        context[2] = (char*)(long)tagName2ID(tagName2);
        context[3] = 0;
        stat = STG_findStyle(stgGroup, context, 2, results, 2);
    } else {
        stat = STG_findStyle(stgGroup, context, 1, results, 1);
    }
    
    if (WWW_TraceFlag && styleAttr) {
        printf("### getSTGInfo_tagPtrWithStyle: STG_findStyle returned %d\n", stat);
    }
    
    if (stat) {
        /* Pack both major and minor into result */
        /* Even if minor is not found, return major so its styles can be applied */
        /* We'll use a simple encoding: store pointer to results array */
        /* Actually, let's return a struct pointer */
        STGResult* res = (STGResult*)malloc(sizeof(STGResult));
        if (res) {
            res->smajor = results[0].smajor;
            res->sminor = results[0].sminor;
            
            if (WWW_TraceFlag && styleAttr) {
                printf("### getSTGInfo_tagPtrWithStyle: found major=%p minor=%p\n", 
                       res->smajor, res->sminor);
            }
            
            result->info.i = (long)res;
            result->type = PKT_INT;
            result->canFree = 0;
            return 1;
        }
    }
    return 0;
}

/*
 * access to libstg - original version for backward compatibility
 * Returns just STGMajor* for old code
 */
int getSTGInfo_tagPtr(Packet* result, char* tagName1, char* tagName2)
/* tagName2: super element */
{
    int stat;
    char* context[4];
    STGResult results[2];

    clearPacket(result);

    if (!stgGroup)
        return 0;

    context[0] = (char*)(long)tagName2ID(tagName1);
    context[1] = 0; /* No style attribute in old API */
    if (tagName2) {
        context[2] = (char*)(long)tagName2ID(tagName2);
        context[3] = 0;
        stat = STG_findStyle(stgGroup, context, 2, results, 2);
    } else {
        stat = STG_findStyle(stgGroup, context, 1, results, 1);
    }
    if (stat) {
        /* Old API: return only major pointer (backward compatible) */
        result->info.i = (long)results[0].smajor;
        result->type = PKT_INT;
        result->canFree = 0;
        return 1;
    }
    return 0;
}

/* Get attribute from STGResult (supports both major and minor) */
int getSTGInfo_attrFromResult(long resultPtr, char* attrName, Packet* result)
/* resultPtr: Actually STGResult* */
{
    STGResult* stgRes = (STGResult*)resultPtr;
    STGAssert* assert;

    clearPacket(result);
    if (!stgRes || !stgRes->smajor)
        return 0;
    if (!attrName)
        return 0;
    
    /* Use new function that checks minor first, then major */
    assert = STGFindAssertWithMinor(stgRes->smajor, stgRes->sminor, (char*)(long)tagName2ID(attrName));
    if (assert) {
        result->info.s = assert->val;
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;
    }
    return 0;
}

/* Original function - for backward compatibility, assumes tagPtr is just STGMajor* */
int getSTGInfo_attr(STGMajor* tagPtr, char* attrName, Packet* result)
{
    STGAssert* assert;

    clearPacket(result);
    if (!tagPtr)
        return 0;
    if (!attrName)
        return 0;
    assert = STGFindAssert(tagPtr, (char*)(long)tagName2ID(attrName));
    if (assert) {
        result->info.s = assert->val;
        result->type = PKT_STR;
        result->canFree = 0;
        return 1;
    }
    return 0;
}

int getSTGInfo_clean(STGMajor* tagPtr)
{
    freeGroup(stgLib, &stgGroup);

    return 1;
}

/*
 * access to libstg.
 */
int getSTGInfo(char* tagName, char* attrName, Packet* result)
{
    int stat;
    char* context[20];
    STGResult results[2];
    STGAssert* assert;

    clearPacket(result);

    /* BUG no context spec
     */
    context[0] = (char*)(long)tagName2ID(tagName);
    context[1] = 0;

    if (!stgGroup)
        return 0;

    stat = STG_findStyle(stgGroup, context, 1, results, 1);

    if (stat) {
        assert = STGFindAssert(results[0].smajor, (char*)(long)tagName2ID(attrName));
        if (assert) {
            result->info.s = assert->val;
            result->type = PKT_STR;
            result->canFree = 0;
            return 1;
        }
    }
    return 0;
}
