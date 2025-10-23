/*
 * Stylesheet Library (libstg.h)
 *
 * Pei Y. Wei (pei@ora.com), O'Reilly & Associates
 *
 *
 * Refer to http://.... for more documentation and usage.
 *
 *
 *
 */

/**********************************/

typedef struct STGStrList {
    struct STGStrList* next;
    char* val;
} STGStrList;

typedef struct STGAssert {
    struct STGAssert* next;
    char* name; /* replace with hashtable token */
    char* val;
} STGAssert;

typedef struct STGMajor {
    struct STGMajor* next;
    struct STGMajor* super;
    struct STGStrList* IDList;
    struct STGAssert* firstAssert;
    struct STGMajor* firstMajorChild;
    struct STGMinor* firstMinorChild;
} STGMajor;

typedef struct STGMinor {
    struct STGMinor* next;
    struct STGStrList* IDList;
    struct STGAssert* firstAssert;
    struct STGMajor* super;
} STGMinor;

typedef struct STGResult {
    struct STGMajor* smajor;
    struct STGMinor* sminor;
} STGResult;

typedef struct STGGroup {
    struct STGGroup* next;
    struct STGMajor* first;
    char* DTD;
} STGGroup;

typedef struct STGLib {
    struct STGGroup* first;
} STGLib;

void STG_dumpLib(STGLib* lib);
void STG_dumpGroup(STGGroup* group);
void STG_dumpMajor(STGMajor* major, int level);
void STG_dumpMinor(STGMinor* minor, int level);
STGMajor* parseMajor(STGMajor* superMajor, char** s);
STGMinor* parseMinor(char** s, STGMajor* major);
STGGroup* addGroup(STGGroup** firstChild, STGGroup* child);
STGMajor* addMajor(STGMajor** firstChild, STGMajor* child);
STGMinor* addMinor(STGMinor** firstChild, STGMinor* child);
STGAssert* assertAttr(STGAssert** firstAssert, char* name, char* val);
struct ParseContext;
int nextToken(struct ParseContext* ctx, char** s);

STGLib* STG_init(int (*tagNameCmp_f)(), long (*tagName2ID_f)(), char* (*tagID2Name_f)(), 
                 int (*tagAttrNameCmp_f)(), long (*tagAttrName2ID_f)(), char* (*tagAttrID2Name_f)());
STGGroup* STG_makeGroup(STGLib* lib, char* gspec);
int STG_findStyle(STGGroup* group, char* context[], int contextCount, STGResult results[], int maxResults);
STGAssert* STGFindAssert(STGMajor* major, char* attrName);
STGAssert* STGFindAssertWithMinor(STGMajor* major, STGMinor* minor, char* attrName);
STGMinor* matchMinor(STGMajor* major, char* attrName, char* attrVal);

int freeGroup(STGLib* lib, STGGroup** group);
int freeLib(STGLib* lib);
