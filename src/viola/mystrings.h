/*
 *     mystrings.h
 */
#define SaveString saveString
#define VSaveString(group, s) saveString(s)

/************************************************************************/
#define LINE_FEED 13

#define MALLOCERR printf("Error: Malloc failed.");
/************************************************************************/

typedef struct strNIntPair {
    int i;
    char* s;
} strNIntPair;

/*
 * size of string used to hold slot content in buffer object...
 */
#define BUFF_SIZE 64000

extern char buff[];

#define NUM_OF_GBUFFS 64
extern int numOfGBuffs;
extern char* GBuff[];
extern int GBuffIdx[];

#define MALLOCSIZE(str) (char*)malloc(sizeof(char) * strlen(str))
#define MAX_LINE_LENGTH 1000
#define MAX_ARGUMENTS 100
/* MAX_LONG must be multiples of 10.b/c some functions use that property...*/
#define MAX_LONG 1000000000

#define PUTSTR(str) fputc(str, stdout)

int cmp_int(int n1, int n2);
long cmp_str(long a, long b); /* Wrapper for strcmp used in hash tables */

char* trimFrontSpaces(char* str);

/*
 * cuts of the spaces, if any, at the beginning and the end of a string.
 */
char* trimEdgeSpaces(char* str);

void SkipBlanks(char* linep, int* i);


/*
 ** Stores the next word in linep in *wordp. Current postion in line is
 ** pointed to by index i.
 ** spaces around the word is trimed.
 *
 * PreCondition: i <= strlen(linep);
 * PostCondition: *wordp contains an argument string from *linep, truncated if necessary.
 */
int NextWord(const char* linep, int i, char* wordp, int maxlen);

/*
 ** Skips the next word linep in *wordp. Current postion in line is
 ** pointed to by index i.
 ** will skip over spaces around the word.
 *
 * PreCondition: i <= strlen(linep);
 *               *wordp must be large enough to hold any argument in *linep.
 * PostCondition: *wordp contains an argument string from *linep.
 */
int SkipNextWord(const char* linep, int i);

/*
 * copys the next phrase, before cutOffWord, onto destStr.
 */
int GetNextPhrase(char* str, int i, char* destStr, char* cutOffWord);

char* NextLines(char** textpp, int* lines, int* size);

/*
** Gets a line of strings.
*
* PreCondition:  commandline must have atleat MAX_LINE_LENGTH characters.
* PostCondition: commandline contains a line of strings ended with '\0'.
*                terminate line with <return>.
* Return: address of the string
*/
char* GetLine(char* commandline);

/*
 ** Determines if a line is all blank(without any printable characters
 ** for command). Control character are not accepted as command characters.
 *
 * PreCondition: inline must end with a zero.
 */
int AllBlank(const char* str);

/*
 ** Searches a char is within a string.
 *
 * RETURN: The index value of where the search char is on the string
 *         -1 if search character is not in the string.
 * PRECONDITION: str must end with null.
 */
int SearchChar(const char* str, char sc);

/*
 ** Cut the trailing spaces.  ie. move the '\0' toward the front,
 ** to fill up the tail spaces.
 *
 * PRECONDITION: str must end with null.
 * RETURN: Number of spaces cut.
 */
int CutTailSpace(char* str);

/* convert a string to int number value */
int strToVal(char* str);

/* puts the int val in str form*/
char* valToStr(long val, char* str);

/*
 * see if str contains any characters in set.
 */
int anyCommonChar(const char* str, const char* set);

/*
 * see if character ch is in string str
 * returns the index of ch in str
 */
int charIsInStr(char ch, const char* str);

int numOfChar(char* str, char ch);

/*
 * trim off the enclosing quotes of a string
 */
char* trimQuote(char* str);

/* allocates bigger space, and append to it.. the original string is freed*/
char* append(char* orig, const char* append);

/* same as append, with a carriage appended at the end */
char* appendLine(char* orig, const char* append);

char* saveString(const char* str);
char* saveStringN(const char* str, int n);
/* MemoryGroup is defined elsewhere, use void* for now */
char* VsaveString(void* group, const char* str);

int eqStr(const char* s1, const char* s2);

char* listSum2Str(int list1[], int list2[], int listLength, char* str);

void insertChar(char* str, int i, char ch);

char* getLines(long low, long high, char* text, long* size);
char* enQuote(char* str);
char* enBracket(char* str);
char* deBracket(char* str);
char* listItem(char* list, int li, int hi);
char* extractWord(char* text, long li, long hi, char* retStr);
