/*
 * when things work, send a black hole here to collapse things...
 */
#include "biop.h"
#include "hash.h"
#include "misc.h"
#include "mystrings.h"
#include "obj.h"
#include "packet.h"
#include "slotaccess.h"
#include "utils.h"
#include <string.h>

char *cp, *cp1, *cp2;

typedef struct ProcPair {
    void (*lf)();
    void (*rf)();
} ProcPair;

typedef struct ConvIdx {
    void (*(*opftTable)[4][4])();
    ProcPair (*procTable)[4][4];
} ConvIdx;

ProcPair conv1[4][4] = {/* for + - * / > >= < <= == != */
                        {{
                             NULL, NULL /* int, int	-> int	*/
                         },
                         {
                             NULL, char2int /* int, char	-> int	*/
                         },
                         {
                             int2float, NULL /* int, float	-> float*/
                         },
                         {
                             int2str, NULL /* int, str	-> str	*/
                         }},
                        {{
                             NULL, NULL /* char, int	-> int	*/
                         },
                         {
                             NULL, NULL /* char, char	-> char */
                         },
                         {
                             char2float, NULL /* char, float	-> float*/
                         },
                         {
                             char2str, NULL /* char, str	-> str	*/
                         }},
                        {{
                             NULL, int2float /* float, int	-> float*/
                         },
                         {
                             NULL, char2float /* float, char	-> float*/
                         },
                         {
                             NULL, NULL /* float, float	-> float*/
                         },
                         {
                             float2str, NULL /* float, str	-> str	*/
                         }},
                        {{
                             NULL, int2str /* str, int	-> str	*/
                         },
                         {
                             NULL, char2str /* str, char	-> str	*/
                         },
                         {
                             NULL, float2str /* str, float	-> str	*/
                         },
                         {
                             NULL, NULL /* str, str	-> str	*/
                         }}};

ProcPair conv2[4][4] = {/* for integer operation... mod? */
                        {{
                             NULL, NULL /* int, int	-> int	*/
                         },
                         {
                             NULL, char2int /* int, char	-> int	*/
                         },
                         {
                             NULL, float2int /* int, float	-> int	*/
                         },
                         {
                             NULL, str2int /* int, str	-> int	*/
                         }},
                        {{
                             char2int, NULL /* char, int	-> int	*/
                         },
                         {
                             char2int, char2int /* char, char	-> int	*/
                         },
                         {
                             char2int, float2int /* char, float	-> int	*/
                         },
                         {
                             char2int, str2int /* char, str	-> int	*/
                         }},
                        {{
                             float2int, NULL /* float, int	-> int	*/
                         },
                         {
                             float2int, char2int /* float, char	-> int	*/
                         },
                         {
                             float2int, float2int /* float, float	-> int	*/
                         },
                         {
                             float2int, str2int /* float, str	-> int	*/
                         }},
                        {{
                             str2int, NULL /* str, int	-> int	*/
                         },
                         {
                             str2int, char2int /* str, char	-> int	*/
                         },
                         {
                             str2int, float2int /* str, float	-> int	*/
                         },
                         {
                             str2int, str2int /* str, str	-> int	*/
                         }}};

/*
 * operation function tables
 */
void (*opft_plus[4][4])() = {
    int_plus,   int_plus,   float_plus, str_plus, int_plus, char_plus, float_plus, str_plus,
    float_plus, float_plus, float_plus, str_plus, str_plus, str_plus,  str_plus,   str_plus,
};

void (*opft_minus[4][4])() = {
    int_minus,   int_minus,   float_minus, str_minus, int_minus, char_minus, float_minus, str_minus,
    float_minus, float_minus, float_minus, str_minus, str_minus, str_minus,  str_minus,   str_minus,
};

void (*opft_mod[4][4])() = {
    int_mod,   int_mod,   float_mod, str_mod, int_mod, char_mod, float_mod, str_mod,
    float_mod, float_mod, float_mod, str_mod, str_mod, str_mod,  str_mod,   str_mod,
};

void (*opft_mult[4][4])() = {
    int_mult,   int_mult,   float_mult, str_mult, int_mult, char_mult, float_mult, str_mult,
    float_mult, float_mult, float_mult, str_mult, str_mult, str_mult,  str_mult,   str_mult,
};

void (*opft_div[4][4])() = {
    int_div,   int_div,   float_div, str_div, int_div, char_div, float_div, str_div,
    float_div, float_div, float_div, str_div, str_div, str_div,  str_div,   str_div,
};

void (*opft_eq[4][4])() = {
    int_eq,   int_eq,   float_eq, str_eq, int_eq, char_eq, float_eq, str_eq,
    float_eq, float_eq, float_eq, str_eq, str_eq, str_eq,  str_eq,   str_eq,
};

void (*opft_ne[4][4])() = {
    int_ne,   int_ne,   float_ne, str_ne, int_ne, char_ne, float_ne, str_ne,
    float_ne, float_ne, float_ne, str_ne, str_ne, str_ne,  str_ne,   str_ne,
};

void (*opft_gt[4][4])() = {
    int_gt,   int_gt,   float_gt, str_gt, int_gt, char_gt, float_gt, str_gt,
    float_gt, float_gt, float_gt, str_gt, str_gt, str_gt,  str_gt,   str_gt,
};

void (*opft_ge[4][4])() = {
    int_ge,   int_ge,   float_ge, str_ge, int_ge, char_ge, float_ge, str_ge,
    float_ge, float_ge, float_ge, str_ge, str_ge, str_ge,  str_ge,   str_ge,
};

void (*opft_lt[4][4])() = {
    int_lt,   int_lt,   float_lt, str_lt, int_lt, char_lt, float_lt, str_lt,
    float_lt, float_lt, float_lt, str_lt, str_lt, str_lt,  str_lt,   str_lt,
};

void (*opft_le[4][4])() = {
    int_le,   int_le,   float_le, str_le, int_le, char_le, float_le, str_le,
    float_le, float_le, float_le, str_le, str_le, str_le,  str_le,   str_le,
};

void (*opft_and[4][4])() = {
    int_and,   int_and,   float_and, str_and, int_and, char_and, float_and, str_and,
    float_and, float_and, float_and, str_and, str_and, str_and,  str_and,   str_and,
};

void (*opft_or[4][4])() = {
    int_or,   int_or,   float_or, str_or, int_or, char_or, float_or, str_or,
    float_or, float_or, float_or, str_or, str_or, str_or,  str_or,   str_or,
};

ConvIdx biOpConvIdx[] = {{&opft_plus, &conv1},
                         {&opft_minus, &conv1},
                         {&opft_mod, &conv2},
                         {&opft_mult, &conv1},
                         {&opft_div, &conv1},
                         {&opft_eq, &conv1},
                         {&opft_ne, &conv1},
                         {&opft_lt, &conv1},
                         {&opft_le, &conv1},
                         {&opft_gt, &conv1},
                         {&opft_ge, &conv1},
                         {
                             &opft_and, &conv2 /*?*/
                         },
                         {
                             &opft_or, &conv2 /*?*/
                         }};

int biOp(int op, Packet* p1, Packet* p2)
{
    void (*biOpFunc)(), (*convf)();
    ProcPair* convPair;

    if (p1->type == PKT_OBJ) {
        /* this is not efficient... should map
         * PKT_OBJ type into biop.c */
        p1->type = PKT_STR;
        p1->info.s = p1->info.o ? GET_name(p1->info.o) : "";
        p1->canFree = 0;
    }
    if (p1->type == PKT_PKT) {
        p1->type = p1->info.p->type;
        p1->info = p1->info.p->info;
        p1->canFree = p1->info.p->canFree;
        /* could potentially make p1 sticky XXX */
    }
    if (p2->type == PKT_OBJ) {
        /* this is not efficient... should map
         * PKT_OBJ type into biop.c */
        p2->type = PKT_STR;
        p2->info.s = p2->info.o ? GET_name(p2->info.o) : "";
        p2->canFree = 0;
    }
    if (p2->type == PKT_PKT) {
        p2->type = p2->info.p->type;
        p2->info = p2->info.p->info;
        p2->canFree = p2->info.p->canFree;
    }
    convPair = &((*biOpConvIdx[op].procTable)[p1->type][p2->type]);
    if ((convf = convPair->lf))
        convf(p1);
    if ((convf = convPair->rf))
        convf(p2);
    biOpFunc = (*biOpConvIdx[op].opftTable)[p1->type][p2->type];
    biOpFunc(p1, p2);

    return 1;
}

void convError(void) { fprintf(stderr, "conversion error...\n"); }

void int2float(Packet* p)
{
    p->type = PKT_FLT;
    p->info.f = (float)p->info.i;
    p->canFree = 0;
}

void int2str(Packet* p)
{
    extern char buff[];

    p->type = PKT_STR;
    sprintf(buff, "%ld", p->info.i);
    p->info.s = SaveString(buff);
    p->canFree = PK_CANFREE_STR;
}

void char2int(Packet* p)
{
    p->type = PKT_INT;
    p->info.i = (long)p->info.c;
    p->canFree = 0;
}

void char2float(Packet* p)
{
    p->type = PKT_FLT;
    p->info.f = (float)p->info.c;
    p->canFree = 0;
}

void char2str(Packet* p)
{
    p->type = PKT_STR;
    p->info.s = (char*)malloc(sizeof(char) * 2);
    p->info.s[0] = p->info.c;
    p->info.s[1] = '\0';
    p->canFree = PK_CANFREE_STR;
}

void float2str(Packet* p)
{
    p->type = PKT_STR;
    sprintf(buff, "%f", p->info.f);
    p->info.s = SaveString(buff);
    p->canFree = PK_CANFREE_STR;
}

void float2int(Packet* p)
{
    p->type = PKT_INT;
    p->info.i = (long)p->info.f;
    p->canFree = 0;
}

void str2int(Packet* p)
{
    if (p->canFree & PK_CANFREE_STR)
        free(p->info.s);
    p->type = PKT_INT;
    p->info.i = atoi(p->info.s);
    p->canFree = 0;
}

void str2float(Packet* p)
{
    if (p->canFree & PK_CANFREE_STR)
        free(p->info.s);
    p->type = PKT_FLT;
    p->info.f = (float)atof(p->info.s);
    p->canFree = 0;
}

void int_plus(Packet* p1, Packet* p2)
{
    p1->info.i += p2->info.i;
    p1->canFree = 0;
}

void char_plus(Packet* p1, Packet* p2)
{
    p1->info.c += p2->info.c;
    p1->canFree = 0;
}

void float_plus(Packet* p1, Packet* p2)
{
    p1->info.f += p2->info.f;
    p1->canFree = 0;
}

void str_plus(Packet* p1, Packet* p2)
{
    cp1 = PkInfo2Str(p1);
    cp2 = PkInfo2Str(p2);
    cp = (char*)malloc(sizeof(char) * (strlen(cp1) + strlen(cp2) + 1));
    strcpy(cp, cp2);
    strcat(cp, cp1);
    if (p1->canFree & PK_CANFREE_STR)
        free(p1->info.s);
    p1->info.s = cp;
    p1->canFree = PK_CANFREE_STR;
}

void int_minus(Packet* p1, Packet* p2)
{
    p1->info.i -= p2->info.i;
    p1->canFree = 0;
}

void char_minus(Packet* p1, Packet* p2)
{
    p1->info.c -= p2->info.c;
    p1->canFree = 0;
}

void float_minus(Packet* p1, Packet* p2)
{
    p1->info.f -= p2->info.f;
    p1->canFree = 0;
}

void str_minus(Packet* p1, Packet* p2)
{
    /* huh? */
}

void int_mod(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i % p2->info.i;
    p1->canFree = 0;
}

void char_mod(Packet* p1, Packet* p2)
{
    p1->info.c = p1->info.c % p2->info.c;
    p1->canFree = 0;
}

void float_mod(Packet* p1, Packet* p2)
{
    p1->info.f = (long)p1->info.f % (long)p2->info.f; /*??*/
    p1->canFree = 0;
}

void str_mod(Packet* p1, Packet* p2)
{
    /* hummm */
}

void int_mult(Packet* p1, Packet* p2)
{
    p1->info.i *= p2->info.i;
    p1->canFree = 0;
}

void char_mult(Packet* p1, Packet* p2)
{
    p1->info.c *= p2->info.c;
    p1->canFree = 0;
}

void float_mult(Packet* p1, Packet* p2)
{
    p1->info.f *= p2->info.f;
    p1->canFree = 0;
}

void str_mult(Packet* p1, Packet* p2)
{
    /* there is no possibility */
}

void int_div(Packet* p1, Packet* p2)
{
    if (p2->info.i) {
        p1->info.i /= p2->info.i;
        p1->canFree = 0;
        return;
    } else {
        fprintf(stderr, "error: int_div() div by zero.\n");
    }
}

void char_div(Packet* p1, Packet* p2)
{
    if (p2->info.c) {
        p1->info.c /= p2->info.c;
        p1->canFree = 0;
        return;
    } else {
        fprintf(stderr, "error: char_div() div by zero.\n");
    }
}

void float_div(Packet* p1, Packet* p2)
{
    if (p2->info.f != 0.0f) {
        p1->info.f /= p2->info.f;
        p1->canFree = 0;
        return;
    } else {
        fprintf(stderr, "error: float_div() div by zero.\n");
    }
}

void str_div(Packet* p1, Packet* p2)
{
    /* get out of here! */
}

void int_eq(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i == p2->info.i;
    p1->canFree = 0;
}

void char_eq(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.c == p2->info.c;
    p1->type = PKT_INT;
    p1->canFree = 0;
}

void float_eq(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.f == p2->info.f;
    p1->type = PKT_INT;
    p1->canFree = 0;
}

void str_eq(Packet* p1, Packet* p2)
{
    cp = p1->info.s;

    p1->type = PKT_INT;
    if (!p1->info.s || !p2->info.s) {
        if (!p1->info.s && !p2->info.s)
            p1->info.i = 1;
        else
            p1->info.i = 0;
    } else {
        p1->info.i =
            ((*(p1->info.s) == *(p2->info.s)) ? (strcmp(p1->info.s, p2->info.s) ? 0 : 1) : 0);
    }
    if (p1->canFree & PK_CANFREE_STR) {
        if (cp)
            free(cp);
        p1->canFree = 0;
    }
}

void int_ne(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i != p2->info.i;
    p1->canFree = 0;
}

void char_ne(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.c != p2->info.c;
    p1->canFree = 0;
}

void float_ne(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.f != p2->info.f;
    p1->canFree = 0;
}

void str_ne(Packet* p1, Packet* p2)
{
    cp = p1->info.s;

    p1->type = PKT_INT;
    if (!p1->info.s || !p2->info.s) {
        if (!p1->info.s && !p2->info.s)
            p1->info.i = 0;
        else
            p1->info.i = 1;
    } else {
        p1->info.i =
            ((*(p1->info.s) != *(p2->info.s)) ? 1 : (strcmp(p1->info.s, p2->info.s) ? 1 : 0));
    }
    if (p1->canFree & PK_CANFREE_STR) {
        if (cp)
            free(cp);
        p1->canFree = 0;
    }
}

void int_lt(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i < p2->info.i;
    p1->canFree = 0;
}

void char_lt(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.c < p2->info.c;
    p1->canFree = 0;
}

void float_lt(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.f < p2->info.f;
    p1->canFree = 0;
}

void str_lt(Packet* p1, Packet* p2)
{
    cp = p1->info.s;

    p1->type = PKT_INT;
    if (!p1->info.s || !p2->info.s) {
        p1->info.i = 0; /* not meaningful... */
    } else {
        p1->info.i = (strcmp(p1->info.s, p2->info.s) < 0);
    }
    if (p1->canFree & PK_CANFREE_STR) {
        if (cp)
            free(cp);
        p1->canFree = 0;
    }
}

void int_le(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i <= p2->info.i;
    p1->canFree = 0;
}

void char_le(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.c <= p2->info.c;
    p1->canFree = 0;
}

void float_le(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.f <= p2->info.f;
    p1->canFree = 0;
}

void str_le(Packet* p1, Packet* p2)
{
    cp = p1->info.s;

    p1->type = PKT_INT;
    if (!p1->info.s || !p2->info.s) {
        p1->info.i = 0; /* not meaningful... */
    } else {
        p1->info.i = (strcmp(p1->info.s, p2->info.s) <= 0);
    }
    if (p1->canFree & PK_CANFREE_STR) {
        if (cp)
            free(cp);
        p1->canFree = 0;
    }
}

void int_gt(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i > p2->info.i;
    p1->canFree = 0;
}

void char_gt(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.c > p2->info.c;
    p1->canFree = 0;
}

void float_gt(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.f > p2->info.f;
    p1->canFree = 0;
}

void str_gt(Packet* p1, Packet* p2)
{
    cp = p1->info.s;

    p1->type = PKT_INT;
    if (!p1->info.s || !p2->info.s) {
        p1->info.i = 0; /* not meaningful... */
    } else {
        p1->info.i = (strcmp(p1->info.s, p2->info.s) > 0);
    }
    if (p1->canFree & PK_CANFREE_STR) {
        if (cp)
            free(cp);
        p1->canFree = 0;
    }
}

void int_ge(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i >= p2->info.i;
    p1->canFree = 0;
}

void char_ge(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.c >= p2->info.c;
    p1->canFree = 0;
}

void float_ge(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.f >= p2->info.f;
    p1->canFree = 0;
}

void str_ge(Packet* p1, Packet* p2)
{
    cp = p1->info.s;

    p1->type = PKT_INT;
    if (!p1->info.s || !p2->info.s) {
        p1->info.i = 0; /* not meaningful... */
    } else {
        p1->info.i = (strcmp(p1->info.s, p2->info.s) >= 0);
    }
    if (p1->canFree & PK_CANFREE_STR) {
        if (cp)
            free(cp);
        p1->canFree = 0;
    }
}

void int_and(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i && p2->info.i;
    p1->canFree = 0;
}

void char_and(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.c && p2->info.c;
    p1->canFree = 0;
}

void float_and(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = (p1->info.f != 0.0f) && (p2->info.f != 0.0f);
    p1->canFree = 0;
}

void str_and(Packet* p1, Packet* p2)
{
    /* get with it. */
}

void int_or(Packet* p1, Packet* p2)
{
    p1->info.i = p1->info.i || p2->info.i;
    p1->canFree = 0;
}

void char_or(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = p1->info.c || p2->info.c;
    p1->canFree = 0;
}

void float_or(Packet* p1, Packet* p2)
{
    p1->type = PKT_INT;
    p1->info.i = (p1->info.f != 0.0f) || (p2->info.f != 0.0f);
    p1->canFree = 0;
}

void str_or(Packet* p1, Packet* p2)
{
    /* sheesh... */
}
