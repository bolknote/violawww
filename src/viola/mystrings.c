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
 * mystrings.c  -  Miscelaneous string functions.
 */

#include "mystrings.h"
#include "sys.h"
#include "utils.h"
#include "memory_debug.h"
#include "ascii.h"  /* for CTRL_d - ASCII code 4 (Ctrl+D, EOF) */
#include <ctype.h>
#include <stdio.h>  /* for snprintf */
#include <stdlib.h>
#include <string.h>
#include <strings.h> /* for strcasecmp */

char buff[BUFF_SIZE];

int numOfGBuffs = 0;
char* GBuff[NUM_OF_GBUFFS];
int GBuffIdx[NUM_OF_GBUFFS];

int cmp_int(int n1, int n2)
{
    return n1 == n2;
}

long cmp_str(long a, long b)
{
    return (long)strcmp((char*)a, (char*)b);
}

void SkipBlanks(char* linep, int* i)
{
    while (linep[*i]) {
        if (!isspace((unsigned char)linep[*i]))
            return;
        ++(*i);
    }
}


/*
 ** Stores the next word in linep in *wordp. Current postion in line is
 ** pointed to by index i.
 ** spaces around the word is trimed.
 *
 * PreCondition: i <= strlen(linep);
 * PostCondition: *wordp contains an argument string from *linep, truncated if necessary.
 */
int NextWord(const char* restrict linep, int i, char* restrict wordp, int maxlen)
{
    if (!linep || i < 0)
        return i;
    
    if (maxlen <= 0) {
        if (maxlen == 0 && wordp)
            wordp[0] = '\0';
        return i;
    }

    /* Skip leading whitespace */
    i += (int)strspn(linep + i, " \t\r\n\f\v");
    
    /* Find word length */
    size_t word_len = strcspn(linep + i, " \t\r\n\f\v");
    
    /* Copy word with truncation */
    if (wordp) {
        size_t copy_len = word_len < (size_t)(maxlen - 1) ? word_len : (size_t)(maxlen - 1);
        if (copy_len > 0) {
            memcpy(wordp, linep + i, copy_len);
            wordp[copy_len] = '\0';
        } else {
            wordp[0] = '\0';
        }
    }

    return i + (int)word_len;
}

/*
 ** Skips the next word linep in *wordp. Current postion in line is
 ** pointed to by index i.
 ** will skip over spaces around the word.
 *
 * PreCondition: i <= strlen(linep);
 *               *wordp must be large enough to hold any argument in *linep.
 * PostCondition: *wordp contains an argument string from *linep.
 */
int SkipNextWord(const char* linep, int i)
{
    if (!linep || i < 0)
        return i;
    
    /* Skip leading whitespace */
    i += (int)strspn(linep + i, " \t\r\n\f\v");
    
    /* Skip word */
    i += (int)strcspn(linep + i, " \t\r\n\f\v");
    
    return i;
}

/*
 * copys the next phrase, up to the cutOffWord, onto destStr.
 * if no cutOffWord is found, the phrase string is copied anyway.
 */
int GetNextPhrase(char* restrict str, int i, char* restrict destStr, char* restrict cutOffWord)
{
    char c;
    int x, y, ci = i, cuti = 0, parenLevel = 0, quoteToggle = 0;
    size_t cutOffWordLen = strlen(cutOffWord);
    extern int hush;

    while ((c = str[ci])) {
        if (parenLevel == 0 && quoteToggle == 0) {
            if (c == cutOffWord[cuti]) {
                ++cuti;
                if (cuti >= cutOffWordLen) {
                    ++ci;
                    goto gag;
                }
            } else {
                cuti = 0;
            }
        }
        if (c == '\"') {
            if (quoteToggle)
                quoteToggle = 0;
            else
                quoteToggle = 1;
            cuti = 0;
        } else if (c == '(') {
            ++parenLevel;
            cuti = 0;
        } else if (c == ')') {
            --parenLevel;
            cuti = 0;
        }
        ++ci;
    }
    cuti = 0;
gag:
    if (cuti) {
        for (y = 0, x = i; x < (ci - cuti); x++, y++)
            destStr[y] = str[x];
        destStr[y] = '\0';
        /* fprintf(stderr, "cuit=%d '%s' i=%d str='%s' ci=%d '%s'\n",cuti, cutOffWord, i, str, ci,
         * destStr); */
        return ci;
    }
    for (y = 0, x = i; str[x]; x++, y++)
        destStr[y] = str[x];
    destStr[y] = '\0';
    /* fprintf(stderr, "'%s' i=%d str='%s' i=%d '%s'\n",cutOffWord, i, str, i, destStr);*/
    return i;
}

/*
 * gets and returns the next specified lines in a string.
 * unless preceded by '\\' lines are separated by '\n'
 *
 * "lines" specify how many lines to read.
 * returns: number of characters in returned string
 *          string containing the next number of "lines"
 */
char* NextLines(char** textpp, int * lines, int * size)
{
    char c = '\0', *textSavep, *cp;
    int linesToGet = *lines;

    *lines = 0;
    *size = 0;

    if (textpp == NULL)
        return NULL;

    textSavep = *textpp;

    while (**textpp) {
        /* ignore '\n' if preceded by '\\' */
        if (**textpp == '\n' || **textpp == '\r') {
            if (c == '\\') {
                /* back up -- don't want to include '\\' */
                c = **textpp;
                --(*size);
                ++(*textpp);
            } else {
                if (++(*lines) >= linesToGet) {
                    ++(*textpp);
                    break;
                }
            }
        }
        if (*size > BUFF_SIZE) {
            /* exceeding line buffer size */
            *textpp = textSavep;
            *lines = 0;
            *size = 0;
            return NULL;
        }
        c = **textpp;
        buff[(*size)++] = **textpp;
        ++(*textpp);
    }
    buff[(*size)] = '\0';
    if ((cp = (char*)malloc(sizeof(char) * (*size + 1))) == NULL) {
        perror("NextLines(): malloc failed.");
        return NULL;
    }
    strcpy(cp, buff);
    return cp;
}

/*
 * skip the next specified lines in a string.
 * unless preceded by '\\' lines are separated by '\n'
 *
 * "lines" specify how many lines to skip.
 * returns: current textpp value;
 */
char* SkipNextLines(char** textpp, int * lines, int * size)
{
    char c = '\0';
    int linesToGet = *lines;

    *lines = 0;
    *size = 0;

    if (textpp == NULL)
        return NULL;

    for (;;) {
        if (**textpp == '\0')
            return NULL;

        /* ignore '\n' if preceded by '\\' */
        if (**textpp == '\n' || **textpp == '\r') {
            if (c == '\\') {
                /* back up -- don't want to include '\\' */
                c = **textpp;
                --(*size);
                ++(*textpp);
            } else {
                if (++(*lines) >= linesToGet) {
                    ++(*textpp);
                    return *textpp;
                }
            }
        }
        c = **textpp;
        ++(*size);
        ++(*textpp);
    }
}

/*
** Gets a line of strings.
*
* PreCondition:  commandline must have atleat MAX_LINE_LENGTH characters.
* PostCondition: commandline contains a line of strings ended with '\0'.
*                terminate line with <return> or Ctrl+D (EOF).
* Return: address of the string
*/
char* GetLine(char* commandline)
{
    char c;
    int i = 0;

    while (((c = getchar()) != '\n') && (i < (MAX_LINE_LENGTH - 1))) {
        if (c == CTRL_d)  /* Ctrl+D (ASCII 4) - EOF signal */
            break;
        commandline[i++] = c;
    }
    commandline[i] = '\0';

    return commandline;
}

/*
 ** Determines if a line is all blank(without any printable characters
 ** for command). Control character are not accepted as command characters.
 *
 * PreCondition: str must end with a zero.
 */
int AllBlank(const char* str)
{
    if (!str)
        return 1;
    return str[strspn(str, " \t\r\n\f\v")] == '\0';
}

/*
 ** Searches a char is within a string.
 *
 * RETURN: The index value of where the search char is on the string
 *         -1 if search character is not in the string.
 * PRECONDITION: str must end with null.
 */
int SearchChar(const char* str, char sc)
{
    const char* pos = strchr(str, sc);
    return pos ? (int)(pos - str) : -1;
}

/*
 ** Cut the trailing spaces.  ie. move the '\0' toward the front,
 ** to fill up the tail spaces.
 *
 * PRECONDITION: str must end with null.
 * RETURN: Number of spaces cut.
 *         0 if strings is set to NULL.
 */
int CutTailSpace(char* str)
{
    if (!str)
        return 0;
    
    size_t len = strlen(str);
    size_t orig_len = len;
    
    while (len > 0 && isspace((unsigned char)str[len - 1]))
        str[--len] = '\0';
    
    return (int)(orig_len - len);
}

/*
 * cuts of the spaces, if any, at the beginning and the end of a string.
 */
char* trimEdgeSpaces(char* str)
{
    if (!str)
        return str;
    trimFrontSpaces(str);
    CutTailSpace(str);
    return str;
}

/*
 * rids of the leading spaces
 * shift string toward left to write over leading spaces
 */
char* trimFrontSpaces(char* str)
{
    if (!str)
        return str;
    
    size_t lead = strspn(str, " \t\r\n\f\v");
    if (lead > 0 && str[lead] != '\0') {
        size_t len = strlen(str + lead) + 1; /* +1 for null terminator */
        memmove(str, str + lead, len);
    }
    return str;
}

/*
 ** Convert a string to signed int number value
 *
 * PRECONDITION: string must be unsigned and contain only digits with
 *               possibly sign(first char).
 *               Camas and decimal points are ignored.
 * RETURN: proper value. or 0 if str is NULL
 * NOTE: Spaces at edges are ok. ex: "   ---2345.3555 " -> (-2345)
 */
int strToVal(char* str)
{
    long i;
    int j = 1, val = 0, negate = 1;
    size_t len;

    if (str == NULL)
        return 0;

    len = strlen(str);
    for (i = (long)(len - 1); i >= 0; i--) {
        /* fprintf(stderr, "%d %d %d %d\n",(*(str+i)-'0'), val,*(str+i),j);*/
        if (*(str + i) == '-')
            negate *= -1;
        if (*(str + i) == '.') {
            j = 1;
            val = 0;
            continue;
        }
        if (isdigit(*(str + i))) {
            val += (*(str + i) - '0') * j;
            j *= 10;
        }
    }
    val *= negate;
    return val;
}

/*
 ** puts the signed int val in str form
 *
 * PRECONDITION: val must be integer.
 * NOTE: str must be large enough to hold the number (at least 32 bytes recommended)
 * NOTE: Values are clamped to MAX_LONG to ensure they fit in minimum buffer size (16 bytes)
 */
char* valToStr(long val, char* str)
{
    if (val > MAX_LONG)
        val = MAX_LONG;
    if (val < -MAX_LONG)
        val = -MAX_LONG;

    snprintf(str, 32, "%ld", val);
    return str;
}

/*
 * find where the common character is
 * RETURN: -1 if none.
 */
int commonCharAt(const char* str, const char* set)
{
    const char* pos = strpbrk(str, set);
    if (!pos)
        return -1;
    
    int i = 0;
    while (*set) {
        if (*set == *pos)
            return i;
        set++;
        i++;
    }
    return -1;
}

/*
 * see if str contains any characters in set.
 */
int anyCommonChar(const char* str, const char* set)
{
    return strpbrk(str, set) != NULL;
}

/*
 * see if character ch is in string str
 */
int charIsInStr(char ch, const char* str)
{
    return strchr(str, ch) != NULL;
}

int numOfChar(char str[], char sc)
{
    int count = 0;
    
    while (*str) {
        if (*str == sc)
            count++;
        str++;
    }
    return count;
}

/*
 * trim off the enclosing quotes of a string
 */
char* trimQuote(char* str)
{
    char *s, *h = str;

    /* Safety check: ensure str is not NULL */
    if (!str)
        return str;

    while (*str != '\0') {
        if (*str == '\"') {
            s = str;
            while (*s != '\0') {
                *s = *(s + 1);
                s++;
            }
        }
        str++;
    }
    return h;
}

/* allocates bigger space, and append to it.. the original string is freed*/
char* append(char* orig, const char* append_str)
{
    if (!orig || !append_str)
        return orig;

    size_t orig_len = strlen(orig);
    size_t append_len = strlen(append_str);
    char* sp = (char*)malloc(sizeof(char) * (orig_len + append_len + 1));
    
    if (sp) {
        memcpy(sp, orig, orig_len);
        memcpy(sp + orig_len, append_str, append_len);
        sp[orig_len + append_len] = '\0';
        free(orig);
        return sp;
    }
    
    fprintf(stderr, "malloc failed.");
    return NULL;
}

/* same as append, with a carriage appended at the end */
char* appendLine(char* orig, const char* append_str)
{
    if (!orig || !append_str)
        return orig;

    size_t orig_len = strlen(orig);
    size_t append_len = strlen(append_str);
    char* sp = (char*)malloc(sizeof(char) * (orig_len + append_len + 2));
    
    if (sp) {
        memcpy(sp, orig, orig_len);
        memcpy(sp + orig_len, append_str, append_len);
        sp[orig_len + append_len] = '\n';
        sp[orig_len + append_len + 1] = '\0';
        free(orig);
        return sp;
    }
    
    fprintf(stderr, "malloc failed.");
    return NULL;
}

char* saveString(const char* str) {
    if (!str)
        return NULL;

    /* Check for invalid pointers: NULL, very low addresses */
    if ((unsigned long)str < 0x1000) {
        /* Allocate empty string to avoid crashes */
        char* sp = (char*)malloc(1);
        if (sp)
            sp[0] = '\0';
        return sp;
    }
    
    /* Handle sign-extended 32-bit pointers from legacy code paths.
     * If upper 32 bits are 0xFFFFFFFF, the pointer was corrupted.
     * Return empty string to avoid crash.
     */
    if (((unsigned long)str & 0xFFFFFFFF00000000UL) == 0xFFFFFFFF00000000UL) {
        char* sp = (char*)malloc(1);
        if (sp)
            sp[0] = '\0';
        return sp;
    }

    size_t len = strlen(str);
    char* sp = (char*)MALLOC(sizeof(char) * (len + 1));
    if (sp) {
        memcpy(sp, str, len + 1);
        return sp;
    }
    fprintf(stderr, "malloc failed.");
    return NULL;
}

char* saveStringN(const char* str, int size) {
    if (size <= 0)
        return NULL;
    
    char* sp = (char*)MALLOC(sizeof(char) * (size_t)size);
    if (!sp) {
        fprintf(stderr, "malloc failed.");
        return NULL;
    }
    
    if (str) {
        size_t max_copy = (size_t)(size - 1);
        size_t copy_len = 0;
        while (copy_len < max_copy && str[copy_len] != '\0')
            copy_len++;
        memcpy(sp, str, copy_len);
        sp[copy_len] = '\0';
    } else {
        sp[0] = '\0';
    }
    
    return sp;
}

char* VsaveString(void* group, const char* str) /* Actually MemoryGroup*, but avoid header dependency */
{
    if (!str)
        return NULL;

    size_t len = strlen(str);
    char* sp = (char*)Vmalloc(group, sizeof(char) * (len + 1));
    if (sp) {
        memcpy(sp, str, len + 1);
        return sp;
    }
    
    fprintf(stderr, "malloc failed.");
    return NULL;
}

int eqStr(const char* cmpStr, const char* fixedStr) {
    if (!cmpStr || !fixedStr)
        return 0;
    
    size_t len = strlen(cmpStr);
    char* sp = (char*)malloc(sizeof(char) * (len + 1));
    if (!sp)
        return 0;

    memcpy(sp, cmpStr, len + 1);
    trimEdgeSpaces(sp);
    int result = strcmp(sp, fixedStr) == 0 ? 1 : 0;
    free(sp);
    return result;
}

char* listSum2Str(int list1[], int list2[], int listLength, char* str) {
    int i = 0;
    char localBuff[40];

    str[0] = '\0';
    for (; i < listLength; i++) {
        strcat(str, valToStr((long)(list1[i] + list2[i]), localBuff));
        if (i < listLength - 1)
            strcat(str, ",");
    }
    return str;
}

void insertChar(char* eStr, int col, char c) {
    if (!eStr || col < 0)
        return;
    
    size_t len = strlen(eStr);
    size_t pos = (size_t)col;
    
    /* Ensure position is within or at end of string */
    if (pos > len)
        pos = len;
    
    /* Shift characters to the right, including null terminator */
    memmove(eStr + pos + 1, eStr + pos, len - pos + 1);
    eStr[pos] = c;
}

/*
 * Line numbering start at 0
 *
 * Up to the user to free returned data.
 */
char* getLines(long low, long high, char* text, long* size) {
    char* cp;
    char* begin = text;
    char* end;
    long i = 0;

    if (i < low)
        for (; *begin; begin++)
            if (*begin == '\n')
                if (++i >= low) {
                    begin++;
                    break;
                }
    end = begin;
    if (i <= high)
        for (; *end; end++)
            if (*end == '\n')
                if (i++ >= high) {
                    end++;
                    break;
                }
    *size = end - begin;
    if (*size > 0) {
        cp = (char*)malloc(sizeof(char) * (*size + 1));
        strncpy(cp, begin, (size_t)*size);
        cp[*size] = '\0';
    } else {
        cp = (char*)malloc(sizeof(char));
        cp[0] = '\0';
        *size = 1;
    }
    return cp;
}

/* UNUSED */
char* enQuote(char* str) {
    char* buffp = buff;

    *buffp++ = '\"';
    while (*str)
        *buffp++ = *str++;
    *buffp++ = '\"';
    *buffp = '\0';

    return SaveString(buff);
}

char* enBracket(char* list) {
    char* buffp = buff;

    *buffp++ = '{';
    while (*list)
        *buffp++ = *list++;
    *buffp++ = '}';
    *buffp = '\0';

    return SaveString(buff);
}

/* not properly done - merely replaces {...} with space
 * may bomb if list string is empty ""
 */
char* deBracket(char* list) {
    if (!list[0]) {
        return list;
    } else {
        char c;

        for (size_t i = 0; (c = list[i]); i++) {
            if (c == '{') {
                list[i] = ' ';
                break;
            }
        }

        for (size_t i = strlen(list); i >= 0; i--) {
            if (list[i] == '}') {
                list[i] = '\0';
                break;
            }
        }
        trimFrontSpaces(list);
        return list;
    }
}

/*
 * grabs item(s) out of a {list}
 */
char* listItem(char* list, int li, int hi) {
    char c;
    int i, bi = 0, itemNum = 1, paren = 0;

    /* skip the first left bracket */
    for (i = 0; (c = *(list + i)) != '\0'; i++) {
        if (c == '{') {
            paren = 1;
            ++i;
            break;
        }
    }
    buff[bi++] = '{';

    for (; (c = *(list + i)) != '\0'; i++) {
        if (itemNum > hi)
            break;
        switch (c) {
        case '{':
            if (++paren >= 1)
                if (itemNum >= li)
                    buff[bi++] = '{';
            break;
        case '}':
            if (--paren >= 1)
                if (itemNum >= li)
                    buff[bi++] = '}';
            break;
        case ',':
            if (paren == 1)
                ++itemNum;
            if (paren >= 1) {
                if (itemNum == li) {
                    if (paren >= 2)
                        buff[bi++] = ',';
                } else if ((itemNum > li) && (itemNum <= hi))
                    buff[bi++] = ',';
            }
            break;
        default:
            if (itemNum >= li)
                buff[bi++] = c;
        }
    }
    buff[bi++] = '}';
    buff[bi] = '\0';
    return SaveString(buff);
}

/*
 * individual items must be less than 32 characters long.
 */
int getItemVals(int li, int hi, char* itemStr, long* itemValArray) {
    int itemNum = 1;
    int bi = 0, i, flag = 0, ai = 1;
    char c, str[32]; /* dangerous... */

    if (itemStr == NULL || itemValArray == NULL) {
        return 0;
    }
    for (i = 0; (c = *(itemStr + i)) != '\0'; i++) {
        if (itemNum > hi)
            break;
        if (c == ',') {
            itemNum++;
            if (flag) {
                str[bi] = '\0';
                itemValArray[ai++] = (long)strToVal(str);
                bi = 0;
            }
        } else if (itemNum >= li) {
            if (c != '{' && c != '}')
                str[bi++] = c;
            flag = 1;
        }
    }
    str[bi] = '\0';
    itemValArray[ai++] = (long)strToVal(str);
    itemValArray[ai] = (long)ai;

    return ai;
}

char* extractWord(char* restrict text, long li, long hi, char* restrict retStr) {
    int bi = 0, i = 0;
    long itemNum = 1;
    char c;

    if (!isalnum(*text))
        itemNum = 0; /* head needs skiping */

    while ((c = *(text + i)) != '\0') {
        if (!isalnum(c)) {
            if (itemNum >= hi)
                goto done;
            do {
                if (itemNum >= li)
                    retStr[bi++] = c;
                if ((c = *(text + (++i))) == '\0')
                    goto done;
            } while (!isalnum(c));
            ++itemNum;
        }
        if (itemNum >= li)
            retStr[bi++] = c;
        ++i;
    }
done:
    retStr[bi] = '\0';

    return retStr;
}
