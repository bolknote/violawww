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
            major = parseMajor(NULL, &cp);
            addMajor(&group->first, major);
        } else if (*cp == '{') {
            /* probably should not happen here at top level
             * (must be inside a major)
             */
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
    if (*firstChild)
        child->next = *firstChild;
    *firstChild = child;
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

    major->next = NULL;
    major->super = superMajor;
    major->IDList = NULL;
    major->firstAssert = NULL;
    major->firstMajorChild = NULL;
    major->firstMinorChild = NULL;

    init_parse_context(&ctx);
    ctx.stack_op = '(';

    while (nextToken(&ctx, s)) {
        if (stgInfo.type == STG_INFO_TOKEN) {
            if (stgInfo.info.t == '(') {
                addMajor(&(major->firstMajorChild), parseMajor(major, s));
            } else if (stgInfo.info.t == ')') {
                ++(*s);
                return major;
            } else if (stgInfo.info.t == '{') {
                addMinor(&(major->firstMinorChild), parseMinor(s, major));
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
            if (ctx.stack_op == '=') {
                /*
                                                printf("### major: assert: %s = %s\n",
                                                        ctx.stack_str, stgInfo.info.s);
                */
                assertAttr(&major->firstAssert, ctx.stack_str, stgInfo.info.s);
                stgInfo.info.s = NULL;
                stgInfo.type = 0;
            } else if (ctx.stack_op == '(') {
                /*				printf("### major: add(1): %s\n",
                                                stgInfo.info.s);
                */
                addID(&major->IDList, (char*)(long)stg_tagName2ID(stgInfo.info.s));

                stgInfo.info.s = NULL;
                stgInfo.type = 0;
            } else if (ctx.stack_op == ',') {
                /*				printf("### major: add: %s\n",
                                                stgInfo.info.s);
                */
                addID(&major->IDList, (char*)(long)stg_tagName2ID(stgInfo.info.s));

                stgInfo.info.s = NULL;
                stgInfo.type = 0;
            } else if (ctx.stack_op == '\0') {
                if (ctx.stack_str[0]) {
                    /*					printf("@@@ major: flag: %s\n",
                                                                    ctx.stack_str);
                    */
                    assertAttr(&major->firstAssert, ctx.stack_str, NULL);
                }
            } else {
                printf("libstg: major: unable to apply word.\n");
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
                return major;
            }
            ctx.stack_str[0] = '\0';
            ctx.stack_op = '\0';
        } else {
            printf("libstg: major: parse error (unknown type).\n");
            return major;
        }
    }
    return major;
}

STGMinor* parseMinor(s, major)
char** s;
STGMajor* major;
{
    ParseContext ctx;  /* Local context - recursion-safe */
    STGMinor* minor = (STGMinor*)malloc(sizeof(struct STGMinor));

    if (!major) {
        perror("malloc failed\n");
        return NULL;
    }

    minor->next = NULL;
    minor->firstAssert = NULL;
    minor->super = NULL;

    init_parse_context(&ctx);

    while (nextToken(&ctx, s)) {
        if (stgInfo.type == STG_INFO_TOKEN) {
            if (stgInfo.info.t == '}') {
                return minor;
            }
            if (**s == '{') {
                printf("error: minor: detected nested minor\n");
                return NULL;
            }
        } else if (stgInfo.type == STG_INFO_STR) {
            if (ctx.stack_op == '=') {
                /*				printf("### minor: assert: %s = %s\n",
                                                        ctx.stack_str, stgInfo.info.s);
                */
                assertAttr(&minor->firstAssert, ctx.stack_str, stgInfo.info.s);
            } else if (ctx.stack_op == '{') {
                if (TRACE) printf("### minor: add(1): %s\n", stgInfo.info.s);
            } else if (ctx.stack_op == ',') {
                if (TRACE) printf("### minor: add: %s\n", stgInfo.info.s);
            } else if (ctx.stack_op == '\0') {
                if (TRACE) printf("### minor: flag: %s\n", stgInfo.info.s);
            } else {
                printf("libstg: unable to apply word.\n");
                ctx.stack_str[0] = '\0';
                ctx.stack_op = '\0';
                return NULL;
            }
            ctx.stack_str[0] = '\0';
            ctx.stack_op = '\0';
        } else {
            printf("libstg: parse error (unknown type).\n");
            return NULL;
        }
    }
    return NULL;
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

    if (!minor)
        return;

    PRINT_INDENTS(level);
    printf("--Minor--\n");
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
                matchResults[*matchCount].smajor = major;
                matchResults[*matchCount].sminor = NULL;
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
        majorTryReg[i].sminor = NULL;
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
    }
    matchCount = 0;
    for (i = 0; i < majorResultCount; i++) {
        /*		printf("///// majorTryReg: context %d\n", i);
                        STG_dumpMajor(majorTryReg[i].smajor, 0);
        */
        if (majorTryReg[i].smajor) {
            results[matchCount].smajor = majorTryReg[i].smajor;
            results[matchCount].sminor = majorTryReg[i].sminor;
            ++matchCount;
            if (matchCount >= maxResults)
                break;
        }
    }
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

STGAssert* STGFindAssert(major, attrName)
STGMajor* major;
char* attrName;
{
    STGAssert* assert;
    int stat;

    while (major) {
        /*		STG_dumpMajor(major, 0);*/
        assert = major->firstAssert;
        for (; assert; assert = assert->next) {
            if (stg_tagAttrNameCmp(assert->name, attrName)) {
                return assert;
            }
        }
        major = major->super;
    }
    return NULL;
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
