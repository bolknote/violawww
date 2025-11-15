#include "tfed.h"

struct _HTAtom;
typedef struct _HTAtom* HTFormat;
struct _HTParentAnchor;
typedef struct _HTParentAnchor HTParentAnchor;

int init_html(void);
int html_backtrack(void);
int html_search(VObj*, char*);
char* html_pathSimplify(char*);
TFStruct* html_updateTFStruct(VObj*, char*);
TFStruct* html_setUpTFStruct(VObj*, char*);
TFStruct* html_clone(void);
char* html_get_title(VObj*, char*);
char* html_get_src(char*);
int html_deleteDoc(VObj*, char*);
int html_setCacheLimit(int);
int html_clearCache(VObj*);
char* html_headerInfo(VObj*);
char* html_WWWNameOfFile(char*);
int data_reader(void);
void HTJustRead(HTFormat, HTParentAnchor*, int);
int html_fetchDocument(VObj*, char*, char**, char**, FILE*);
char* html_parseDocument(void);
