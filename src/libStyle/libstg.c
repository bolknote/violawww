/*
 * Stylesheet library
 * Pei Y. Wei (pei@ora.com), O'Reilly & Associates.
 *
 * To do:
 * + Caching mechanism in $LIBSTG_CACHE
 * + Take input from file desc.
 * + Cache lookups.
 * + Deal with "minors", ie: distinction between <EM role="WARNING"> and
 *   <EM role="NOTE">.
 */
#include "libstg.h"
#include <stdio.h>

/* Forward declarations to avoid including stdlib.h which causes OSByteOrder conflicts */
extern void* malloc(unsigned long);
extern void free(void*);
extern char* strcpy(char*, const char*);
extern char* saveString();
extern int WWW_TraceFlag;

#define TRACE (WWW_TraceFlag)

#define ISSPACE(c) (c == ' ' || c == '\t' || c == '\n')
#define ISTOKEN(c) (c == '=' || c == ',' || c == '(' || c == ')' || c == '{' || c == '}')

#define INDENT_SPACES 80
char indent_spaces[INDENT_SPACES] = {
    "                                                                              "};
#define PRINT_INDENTS(level) printf("%s", &indent_spaces[INDENT_SPACES - 1 - level * 4]);

#define STG_INFO_EOS 0
#define STG_INFO_TOKEN 1
#define STG_INFO_CHAR 2
#define STG_INFO_STR 3

typedef struct STGInfo {
    int type;
    union {
        char* s;
        char c;
        char t;
    } info;
} STGInfo;

/* Parser context - recursion-safe double buffering */
typedef struct ParseContext {
    char buff_a[1000];
    char buff_b[1000];
    char* stgInfo_buff;  /* pointer to current buffer for new token */
    char* stack_str;     /* pointer to previous token buffer */
    int stgInfo_buffIdx;
    char stack_op;
} ParseContext;

STGInfo stgInfo;
char stack_char = '\0';

int (*stg_tagNameCmp)();
int (*stg_tagName2ID)();
char* (*stg_tagID2Name)();
int (*stg_tagAttrNameCmp)();
int (*stg_tagAttrName2ID)();
char* (*stg_tagAttrID2Name)();

/* Initialize parser context */
static inline void init_parse_context(ParseContext* ctx) {
    ctx->stgInfo_buff = ctx->buff_a;
    ctx->stack_str = ctx->buff_b;
    ctx->buff_a[0] = '\0';
    ctx->buff_b[0] = '\0';
    ctx->stgInfo_buffIdx = 0;
    ctx->stack_op = '\0';
}

/* Swap buffers in context */
static inline void swap_buffers(ParseContext* ctx) {
    char* tmp = ctx->stgInfo_buff;
    ctx->stgInfo_buff = ctx->stack_str;
    ctx->stack_str = tmp;
}

STGLib* STG_init(tagNameCmp_f, tagName2ID_f, tagID2Name_f, tagAttrNameCmp_f, tagAttrName2ID_f,
                 tagAttrID2Name_f) int (*tagNameCmp_f)();
int (*tagName2ID_f)();
char* (*tagID2Name_f)();
int (*tagAttrNameCmp_f)();
int (*tagAttrName2ID_f)();
char* (*tagAttrID2Name_f)();
{
    STGLib* stgLib = (STGLib*)malloc(sizeof(struct STGLib));
    stgLib->first = NULL;

    stg_tagNameCmp = tagNameCmp_f;
    stg_tagName2ID = tagName2ID_f;
    stg_tagID2Name = tagID2Name_f;
    stg_tagAttrNameCmp = tagAttrNameCmp_f;
    stg_tagAttrName2ID = tagAttrName2ID_f;
    stg_tagAttrID2Name = tagAttrID2Name_f;

    return stgLib;
}

STGGroup* STG_makeGroup(lib, gspec)
STGLib* lib;
char* gspec;
{
    char* cp = gspec;
    STGGroup* group = (STGGroup*)malloc(sizeof(struct STGGroup));
    STGMajor* major = NULL;
    STGMinor* minor;

    if (!group) {
        fprintf(stderr, "malloc failed\n");
        return NULL;
    }

    group->DTD = NULL;
    group->next = NULL;
    group->first = NULL;

    addGroup(&lib->first, group);

    while (*cp) {
        if (ISSPACE(*cp)) {
            while (ISSPACE(*cp))
                cp++;
        } else if (*cp == '(') {
            if (TRACE) printf("### makeGroup: found '(', calling parseMajor\n");
            cp++; /* Skip the '(' before calling parseMajor */
            /* Clear global stgInfo before each top-level parse */
            stgInfo.type = 0;
            stgInfo.info.t = '\0';
            major = parseMajor(NULL, &cp);
            if (TRACE) printf("### makeGroup: parseMajor returned major=%p, has minors=%s\n",
                             major, major && major->firstMinorChild ? "YES" : "NO");
            addMajor(&group->first, major);
            if (TRACE) printf("### makeGroup: after addMajor, group->first=%p, first has minors=%s\n",
                             group->first, 
                             group->first && group->first->firstMinorChild ? "YES" : "NO");
        } else if (*cp == '{') {
            /* probably should not happen here at top level
             * (must be inside a major)
             */
            cp++; /* Skip the '{' before calling parseMinor */
            minor = parseMinor(&cp, NULL);
        }
    }
    return group;
}

/* not used.
STGMajor *appendMajor(firstChild, child)
        STGMajor *firstChild;
        STGMajor *child;
{
        STGMajor *p;
        if (!firstChild) return child;
        for (p = firstChild; p->next; p = p->next);
        p->next = child;
        return firstChild;
}
*/

STGStrList* addID(firstChild, id)
STGStrList** firstChild;
char* id;
{
    STGStrList* child = (STGStrList*)malloc(sizeof(struct STGStrList));

    if (!child) {
        fprintf(stderr, "malloc failed\n");
        return NULL;
    }
    child->val = id;
    child->next = NULL;

    if (*firstChild)
        child->next = *firstChild;
    *firstChild = child;
    return child;
}

/* compress add*() to macro
 */
STGGroup* addGroup(firstChild, child)
STGGroup** firstChild;
STGGroup* child;
{
    if (*firstChild)
        child->next = *firstChild;
    *firstChild = child;
    return child;
}

STGMajor* addMajor(firstChild, child)
STGMajor** firstChild;
STGMajor* child;
{
    if (*firstChild)
        child->next = *firstChild;
    *firstChild = child;
    return child;
}

STGMinor* addMinor(firstChild, child)
STGMinor** firstChild;
STGMinor* child;
{
    if (TRACE) printf("### addMinor: firstChild=%p *firstChild=%p child=%p\n", 
                     firstChild, *firstChild, child);
    if (*firstChild)
        child->next = *firstChild;
    *firstChild = child;
    if (TRACE) printf("### addMinor: after add, *firstChild=%p\n", *firstChild);
    return child;
}

/*
(HEAD,BODY 				fontSize=18
                                        mesg="Hi there\n"
        {compact			spacing}
                                        foregroundColor=black
    (H1 				fontSize=28)
                                        backgroundColor=white
)
*/

STGMajor* parseMajor(superMajor, s)
STGMajor* superMajor;
char** s;
{
    ParseContext ctx;  /* Local context - recursion-safe */
    STGMajor* major = (STGMajor*)malloc(sizeof(struct STGMajor));

    if (!major) {
        perror("malloc failed\n");
        return NULL;
    }

    if (TRACE) printf("### parseMajor: CREATED major=%p\n", major);

    major->next = NULL;
    major->super = superMajor;
    major->IDList = NULL;
    major->firstAssert = NULL;
    major->firstMajorChild = NULL;
    major->firstMinorChild = NULL;

    init_parse_context(&ctx);
    ctx.stack_op = '(';
    
    /* Clear global stgInfo to prevent contamination from previous parse */
    stgInfo.type = 0;
    stgInfo.info.t = '\0';

    while (nextToken(&ctx, s)) {
        if (TRACE) printf("### major: nextToken returned type=%d ", stgInfo.type);
        if (stgInfo.type == STG_INFO_TOKEN) {
            if (TRACE) printf("token='%c'\n", stgInfo.info.t);
            if (stgInfo.info.t == '(') {
                if (TRACE) printf("### major: found nested '(', calling parseMajor\n");
                /* nextToken already skipped '(' */
                addMajor(&(major->firstMajorChild), parseMajor(major, s));
                /* Reset state after nested major so parent can accept new attributes */
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
                stgInfo.type = 0;  /* Clear global state from nested parse */
            } else if (stgInfo.info.t == ')') {
                ++(*s);
                return major;
            } else if (stgInfo.info.t == '{') {
                /* nextToken already skipped '{' */
                STGMinor* parsedMinor = parseMinor(s, major);
                if (TRACE) printf("### major: parseMinor returned %p\n", parsedMinor);
                if (parsedMinor) {
                    if (TRACE) printf("### major: BEFORE addMinor, major=%p major->firstMinorChild=%p\n",
                                     major, major->firstMinorChild);
                    addMinor(&(major->firstMinorChild), parsedMinor);
                    if (TRACE) printf("### major: AFTER addMinor, major->firstMinorChild=%p\n",
                                     major->firstMinorChild);
                }
                /* Reset state after nested minor so parent can accept new attributes */
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
                stgInfo.type = 0;  /* Clear global state from nested parse */
                if (TRACE) printf("### major: AFTER reset, major->firstMinorChild=%p\n",
                                 major->firstMinorChild);
            } else if (stgInfo.info.t == ',') {
                ctx.stack_op = stgInfo.info.t;
            } else if (stgInfo.info.t == '=') {
                ctx.stack_op = stgInfo.info.t;
                if (ctx.stack_str[0]) {
                    /*				     printf("### major: attn: %s = <expect>\n",
                                                                    stack_str);
                    */
                } else {
                    printf("libstg: major: error-- no left side to '='.\n");
                    return major;
                }
            }
        } else if (stgInfo.type == STG_INFO_STR) {
            if (TRACE) printf("string='%s' stack_op='%c'\n", stgInfo.info.s, ctx.stack_op);
            if (ctx.stack_op == '=') {
                /*
                                                printf("### major: assert: %s = %s\n",
                                                        ctx.stack_str, stgInfo.info.s);
                */
                assertAttr(&major->firstAssert, ctx.stack_str, stgInfo.info.s);
                stgInfo.info.s = NULL;
                stgInfo.type = 0;
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
            } else if (ctx.stack_op == '(') {
                /*				printf("### major: add(1): %s\n",
                                                stgInfo.info.s);
                */
                addID(&major->IDList, (char*)(long)stg_tagName2ID(stgInfo.info.s));

                stgInfo.info.s = NULL;
                stgInfo.type = 0;
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
            } else if (ctx.stack_op == ',') {
                /*				printf("### major: add: %s\n",
                                                stgInfo.info.s);
                */
                addID(&major->IDList, (char*)(long)stg_tagName2ID(stgInfo.info.s));

                stgInfo.info.s = NULL;
                stgInfo.type = 0;
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
            } else if (ctx.stack_op == '\0') {
                if (ctx.stack_str[0]) {
                    /*					printf("@@@ major: flag: %s\n",
                                                                    ctx.stack_str);
                    */
                    assertAttr(&major->firstAssert, ctx.stack_str, NULL);
                    ctx.stack_str[0] = '\0';
                    ctx.stack_op = '\0';
                }
                /* else: keep the string in stack_str, don't reset - might be followed by '=' */
            } else {
                printf("libstg: major: unable to apply word.\n");
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
                return major;
            }
        } else {
            printf("libstg: major: parse error (unknown type).\n");
            if (TRACE) printf("### parseMajor: RETURNING major=%p (error)\n", major);
            return major;
        }
    }
    if (TRACE) printf("### parseMajor: RETURNING major=%p (normal) has minors=%s\n",
                     major, major->firstMinorChild ? "YES" : "NO");
    return major;
}

STGMinor* parseMinor(s, major)
char** s;
STGMajor* major;
{
    ParseContext ctx;
    STGMinor* minor = (STGMinor*)malloc(sizeof(struct STGMinor));

    if (!minor) {
        perror("malloc failed\n");
        return NULL;
    }

    minor->next = NULL;
    minor->IDList = NULL;
    minor->firstAssert = NULL;
    minor->super = major;

    init_parse_context(&ctx);
    
    /* Clear global stgInfo to prevent contamination from previous parse */
    stgInfo.type = 0;
    stgInfo.info.t = '\0';

    while (nextToken(&ctx, s)) {
        if (stgInfo.type == STG_INFO_TOKEN) {
            if (stgInfo.info.t == '}') {
                return minor;
            }
            if (**s == '{') {
                printf("error: minor: detected nested minor\n");
                return minor;
            }
        } else if (stgInfo.type == STG_INFO_STR) {
            if (ctx.stack_op == '=') {
                assertAttr(&minor->firstAssert, ctx.stack_str, stgInfo.info.s);
            } else if (ctx.stack_op == '{') {
                /* First ID - like "STYLE" */
                addID(&minor->IDList, (char*)(long)stg_tagName2ID(stgInfo.info.s));
            } else if (ctx.stack_op == ',') {
                /* Additional IDs - like "WARNING", "NOTE" */
                addID(&minor->IDList, (char*)(long)stg_tagName2ID(stgInfo.info.s));
            } else if (ctx.stack_op == '\0') {
                /* Flag attribute or ID */
                addID(&minor->IDList, (char*)(long)stg_tagName2ID(stgInfo.info.s));
            } else {
                printf("libstg: minor: unable to apply word.\n");
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
                return minor;
            }
            ctx.stack_str[0] = '\0';
            ctx.stack_op = '\0';
        } else {
            printf("libstg: minor: parse error (unknown type).\n");
            return minor;
        }
    }
    return minor;
}

void STG_dumpAssert(assert, level) STGAssert* assert;
int level;
{
    PRINT_INDENTS(level);
    printf("%s (%d) = %s    \n", stg_tagAttrID2Name(assert->name), assert->name, assert->val);
}

void STG_dumpMinor(minor, level) STGMinor* minor;
int level;
{
    STGAssert* assert;
    STGStrList* ids;

    if (!minor)
        return;

    PRINT_INDENTS(level);
    printf("--Minor: ");
    for (ids = minor->IDList; ids; ids = ids->next)
        printf("%s (%d), ", stg_tagID2Name(ids->val), ids->val);
    printf("\n");
    
    for (assert = minor->firstAssert; assert; assert = assert->next) {
        STG_dumpAssert(assert, level + 1);
    }
    PRINT_INDENTS(level);
    printf("---------\n");
}

void STG_dumpMajor(major, level) STGMajor* major;
int level;
{
    STGMinor* minor;
    STGMajor* cmajor;
    STGAssert* assert;
    STGStrList* ids;

    if (!major)
        return;

    PRINT_INDENTS(level);
    printf("Major: ");
    for (ids = major->IDList; ids; ids = ids->next)
        printf("%s (%d), ", stg_tagID2Name(ids->val), ids->val);
    printf("\n");

    for (assert = major->firstAssert; assert; assert = assert->next) {
        STG_dumpAssert(assert, level);
    }

    for (cmajor = major->firstMajorChild; cmajor; cmajor = cmajor->next) {
        STG_dumpMajor(cmajor, level + 1);
    }
    for (minor = major->firstMinorChild; minor; minor = minor->next) {
        STG_dumpMinor(minor, level + 1);
    }
}

void STG_dumpGroup(group) STGGroup* group;
{
    STGMajor* major;
    int level = 0;
    for (major = group->first; major; major = major->next) {
        STG_dumpMajor(major, 1);
    }
}

void STG_dumpLib(lib) STGLib* lib;
{
    STGGroup* group;

    for (group = lib->first; group; group = group->next) {
        printf("-----------GROUP----------\n");
        STG_dumpGroup(group);
    }
}

/*
 how to use:

ex 1:
        0 tag	"P"
        0 attr	NULL

ex 2:
        0 tag	"EM"
        0 attr	"role"

ex 3:
        0 tag	"P"
        0 attr	NULL
        1 tag	"ADDRESS"
        1 attr	NULL

*/
/* Match minor by attribute name and value
 * For: {STYLE WARNING ...} matches attr="STYLE" attrVal="WARNING"
 * Returns matching minor or NULL
 */
STGMinor* matchMinor(major, attrName, attrVal)
STGMajor* major;
char *attrName, *attrVal;
{
    STGMinor* minor;
    STGStrList* ids;
    int attrNameMatch = 0;
    int attrValMatch = 0;
    
    if (!attrName || !attrVal) {
        if (TRACE) printf("### matchMinor: attrName=%s attrVal=%s - NULL INPUT\n", 
                          attrName ? attrName : "(null)", 
                          attrVal ? attrVal : "(null)");
        return NULL;
    }
    
    if (TRACE) printf("### matchMinor: Looking for attrName=%s(%d) attrVal=%s(%d)\n",
                      stg_tagID2Name(attrName), attrName,
                      stg_tagID2Name(attrVal), attrVal);
    
    for (minor = major->firstMinorChild; minor; minor = minor->next) {
        attrNameMatch = 0;
        attrValMatch = 0;
        
        if (TRACE) printf("### matchMinor: Checking minor with IDList:\n");
        
        /* Check if minor IDList contains both attrName and attrVal */
        for (ids = minor->IDList; ids; ids = ids->next) {
            if (TRACE) printf("###   ID: %s(%d)\n", stg_tagID2Name(ids->val), ids->val);
            
            if (stg_tagNameCmp(ids->val, attrName)) {
                attrNameMatch = 1;
                if (TRACE) printf("###   -> attrName MATCH!\n");
            }
            if (stg_tagNameCmp(ids->val, attrVal)) {
                attrValMatch = 1;
                if (TRACE) printf("###   -> attrVal MATCH!\n");
            }
        }
        
        if (attrNameMatch && attrValMatch) {
            if (TRACE) printf("### matchMinor: FOUND MATCHING MINOR!\n");
            return minor;
        }
    }
    
    if (TRACE) printf("### matchMinor: NO MATCH FOUND\n");
    return NULL;
}

/* return: 1== OK, can stop now further searches */
int matchMajor(major, tag, attr, max, matchResults, matchCount)
STGMajor* major;
char *tag, *attr;
int max;
STGResult* matchResults;
int* matchCount;
{
    STGStrList* ids;
    STGMajor* cmajor;
    STGMinor* minor;
    /*
            PRINT_INDENTS(0); printf("matchMajor: ");
            for (ids = major->IDList; ids; ids = ids->next)
                    printf("%s ", ids->val);
            printf("\n");
    */

    for (ids = major->IDList; ids; ids = ids->next)
        if (ids) {
            /*			printf("*** %s(%d) == %s(%d)  ?\n",
                                            tagID2Name(ids->val), ids->val,
                                            tagID2Name(tag), tag);
            */
            if (stg_tagNameCmp(ids->val, tag)) {
                /* Tag matches - now check for minor if attr is specified */
                minor = NULL;
                if (attr) {
                    /* attr format expected: "attrName:attrValue" or just store both */
                    /* For now we assume attr contains the attribute value like "WARNING" */
                    /* and we search for minors with STYLE/WARNING pattern */
                    if (TRACE) printf("### matchMajor: tag matched, looking for minor with attr=%s(%d)\n",
                                     stg_tagID2Name(attr), attr);
                    minor = matchMinor(major, (char*)(long)stg_tagName2ID("STYLE"), attr);
                    if (TRACE) printf("### matchMajor: matchMinor returned %p\n", minor);
                }
                
                matchResults[*matchCount].smajor = major;
                matchResults[*matchCount].sminor = minor;
                ++(*matchCount);
                if (*matchCount >= max)
                    return 1;
            }
        }

    for (cmajor = major->firstMajorChild; cmajor; cmajor = cmajor->next) {
        if (matchMajor(cmajor, tag, attr, max, matchResults, matchCount))
            return 1;
    }
    return 0;
}

/* params:
 *	context 	context array of tag/attr pair
 *	contextCount	array count
 *	results		array of major/minor pairs
 *	maxResults	maximum number of
 * return:		result count.
 *			0 means no style found.
 * 			>1 means context isn't specific enough.
 */
int STG_findStyle(group, context, contextCount, results, maxResults)
STGGroup* group;
char* context[];
int contextCount;
STGResult results[];
int maxResults;
{
    char *tag, *attr;
    int i, j, inContext, matchCount = 0;
    STGResult majorResults[10];
    int majorResultCount = 0;
    STGResult majorTryReg[10];
    int majorTryRegCount = 0;
    STGStrList* ids;
    STGMajor* maj = NULL;

    /*	context[0].tag = "P";
            context[0].attr = NULL;
            context[1].tag = "ADDRESS";
            context[1].attr = NULL;
    */
    tag = context[0];
    attr = context[1];

    for (maj = group->first; maj; maj = maj->next) {
        if (matchMajor(maj, tag, attr, maxResults, majorResults, &majorResultCount))
            break;
    }

    if (majorResultCount == 0) {
        /*		printf("###### terminal search result: ZERO\n");*/
        return 0;
    }
    /*
            for (i = 0; i < majorResultCount; i++) {
                    printf("###### terminal search result: context %d\n", i);
                    STG_dumpMajor(majorResults[i].smajor, 0);
            }
    */
    /* eliminate by context
     */
    for (i = 0; i < majorResultCount; i++) {
        majorTryReg[i].smajor = majorResults[i].smajor;
        majorTryReg[i].sminor = majorResults[i].sminor;
    }
    for (i = 0; i < majorResultCount; i++) {
        for (maj = majorTryReg[i].smajor, j = 0; maj && j < contextCount; maj = maj->super, j++) {
            tag = context[j * 2];
            inContext = 0;
            for (ids = maj->IDList; ids; ids = ids->next) {
                if (stg_tagNameCmp(ids->val, tag)) {
                    inContext = 1;
                    break;
                }
            }
            if (!inContext)
                majorTryReg[i].smajor = NULL;
        }
        /* If we didn't check all context levels (j < contextCount), 
         * this style doesn't have enough parent hierarchy - reject it.
         */
        if (TRACE) {
            printf("### STG_findStyle: after context check: candidate %d j=%d contextCount=%d smajor=%p\n",
                   i, j, contextCount, majorTryReg[i].smajor);
        }
        if (majorTryReg[i].smajor && j < contextCount) {
            if (TRACE) printf("### STG_findStyle: REJECTING candidate %d (incomplete context)\n", i);
            majorTryReg[i].smajor = NULL;
        }
    }
    matchCount = 0;
    for (i = 0; i < majorResultCount; i++) {
        if (TRACE) {
            printf("### STG_findStyle: candidate %d: smajor=%p j=%d contextCount=%d\n",
                   i, majorTryReg[i].smajor, 0, contextCount);
        }
        if (majorTryReg[i].smajor) {
            results[matchCount].smajor = majorTryReg[i].smajor;
            results[matchCount].sminor = majorTryReg[i].sminor;
            if (TRACE) {
                printf("### STG_findStyle: ACCEPTED candidate %d as result %d (major=%p minor=%p)\n",
                       i, matchCount, results[matchCount].smajor, results[matchCount].sminor);
            }
            ++matchCount;
            if (matchCount >= maxResults)
                break;
        }
    }
    if (TRACE) printf("### STG_findStyle: returning matchCount=%d\n", matchCount);
    return matchCount;
}

STGAssert* assertAttr(firstAssert, name, val)
STGAssert** firstAssert;
char* name;
char* val;
{
    STGAssert* new = (STGAssert*)malloc(sizeof(struct STGAssert));

    if (!new) {
        fprintf(stderr, "malloc failed\n");
        return NULL;
    }

    /*	printf("##### assert: %s = %s\n", name, val);*/

    new->name = (char*)(long)stg_tagName2ID(name);
    new->val = saveString(val);
    new->next = NULL;
    /*
            new->name = saveString(name);
            new->val = saveString(val);
            new->next = NULL;
    */
    if (*firstAssert)
        new->next = *firstAssert;
    *firstAssert = new;
    return new;
}

/* Forward declarations for memory management */
static void free_major_tree(STGMajor* major);

int nextToken(ctx, s)
ParseContext* ctx;
char** s;
{
zoro:
    switch (**s) {
    case ' ':
    case '\n':
    case '\t':
    case '\r':
        (*s)++;
        goto zoro;
        break;
    case '=':
    case ',':
    case '(':
    case ')':
    case '{':
    case '}':
        if (stgInfo.type == STG_INFO_STR)
            swap_buffers(ctx);  /* swap instead of strcpy */
        else if (stgInfo.type == STG_INFO_TOKEN)
            ctx->stack_op = stgInfo.info.t;

        stgInfo.type = STG_INFO_TOKEN;
        stgInfo.info.t = **s;
        (*s)++;

        /*printf("### TOKEN token  [%c]\n", stgInfo.info.t);*/

        break;
    case '"': {
        /* String literal in quotes */
        char* cp = *s;
        
        if (stgInfo.type == STG_INFO_STR)
            swap_buffers(ctx);
        else if (stgInfo.type == STG_INFO_TOKEN)
            ctx->stack_op = stgInfo.info.t;
        
        ++cp; /* skip opening quote */
        ctx->stgInfo_buffIdx = 0;
        while (*cp && *cp != '"') {
            ctx->stgInfo_buff[ctx->stgInfo_buffIdx++] = *cp;
            ++cp;
        }
        if (*cp == '"') ++cp; /* skip closing quote */
        ctx->stgInfo_buff[ctx->stgInfo_buffIdx] = '\0';
        *s = cp;
        stgInfo.type = STG_INFO_STR;
        stgInfo.info.s = ctx->stgInfo_buff;
        
        /*printf("### TOKEN quoted str [%s]\n", stgInfo.info.s);*/
    } break;
    default: {
        char* cp = *s;

        if (stgInfo.type == STG_INFO_STR)
            swap_buffers(ctx);  /* swap instead of strcpy */
        else if (stgInfo.type == STG_INFO_TOKEN)
            ctx->stack_op = stgInfo.info.t;

        ctx->stgInfo_buffIdx = 0;
        while (!ISSPACE(*cp) && !ISTOKEN(*cp) && *cp) {
            ctx->stgInfo_buff[ctx->stgInfo_buffIdx++] = *cp;
            ++cp;
        }
        ctx->stgInfo_buff[ctx->stgInfo_buffIdx] = '\0';
        *s = cp;
        stgInfo.type = STG_INFO_STR;
        stgInfo.info.s = ctx->stgInfo_buff;

        /*printf("### TOKEN str    [%s]\n", stgInfo.info.s);*/

    } break;
    }
    if (**s)
        return 1;
    return 0;
}

/* Find assert in minor, then fallback to major hierarchy */
STGAssert* STGFindAssertWithMinor(major, minor, attrName)
STGMajor* major;
STGMinor* minor;
char* attrName;
{
    STGAssert* assert;
    
    /* First check minor (most specific) */
    if (minor) {
        if (TRACE) printf("### STGFindAssertWithMinor: searching in minor for %s(%d)\n",
                         stg_tagAttrID2Name(attrName), attrName);
        for (assert = minor->firstAssert; assert; assert = assert->next) {
            if (TRACE) printf("###   minor has: %s = %s\n", 
                             stg_tagAttrID2Name(assert->name), assert->val);
            if (stg_tagAttrNameCmp(assert->name, attrName)) {
                if (TRACE) printf("###   FOUND in minor: %s = %s\n",
                                 stg_tagAttrID2Name(assert->name), assert->val);
                return assert;
            }
        }
    }
    
    /* Then check major hierarchy (inheritance) */
    while (major) {
        for (assert = major->firstAssert; assert; assert = assert->next) {
            if (stg_tagAttrNameCmp(assert->name, attrName)) {
                if (TRACE) printf("### STGFindAssertWithMinor: FOUND in major: %s = %s\n",
                                 stg_tagAttrID2Name(assert->name), assert->val);
                return assert;
            }
        }
        major = major->super;
    }
    return NULL;
}

/* Original function - for backward compatibility */
STGAssert* STGFindAssert(major, attrName)
STGMajor* major;
char* attrName;
{
    return STGFindAssertWithMinor(major, NULL, attrName);
}

int freeGroup(STGLib* lib, STGGroup** group) {
    STGGroup *gp, *lgp = NULL;

    if (!lib || !group || !*group)
        return 0;

    for (gp = lib->first; gp; gp = gp->next) {
        if (gp == *group) {
            if (lgp)
                lgp->next = gp->next;
            else
                lib->first = NULL;
            
            /* Free all content before freeing the group itself */
            free_major_tree(gp->first);
            free(gp);
            
            *group = NULL;
            return 1;
        }
        lgp = gp;
    }
    return 0;
}

/* Internal recursive memory freeing functions */

static void free_assert_list(STGAssert* assert) {
    while (assert) {
        STGAssert* next = assert->next;
        /* Note: name and val are from saveString() - should have global free */
        free(assert);
        assert = next;
    }
}

static void free_str_list(STGStrList* list) {
    while (list) {
        STGStrList* next = list->next;
        /* Note: val is stored as (char*)(long)tagID, not allocated */
        free(list);
        list = next;
    }
}

static void free_minor_list(STGMinor* minor) {
    while (minor) {
        STGMinor* next = minor->next;
        free_assert_list(minor->firstAssert);
        free_str_list(minor->IDList);
        free(minor);
        minor = next;
    }
}

static void free_major_tree(STGMajor* major) {
    while (major) {
        STGMajor* next = major->next;
        free_assert_list(major->firstAssert);
        free_str_list(major->IDList);
        free_major_tree(major->firstMajorChild);  /* recursive */
        free_minor_list(major->firstMinorChild);
        free(major);
        major = next;
    }
}

static void free_group_list(STGGroup* group) {
    while (group) {
        STGGroup* next = group->next;
        free_major_tree(group->first);
        /* Note: DTD is not allocated in current code */
        free(group);
        group = next;
    }
}

/* Free entire library - properly plugs memory leak */
int freeLib(STGLib* lib) {
    if (!lib)
        return 0;
    
    free_group_list(lib->first);
    free(lib);
    return 1;
}
