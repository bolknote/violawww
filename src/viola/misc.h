#include "obj.h"

extern int cmd_history;
extern int verbose;

int transferNumList2Array();
int argNumsToInt();
VObjList* strOListToOList();
char* OListToStr();
char* OListToStrPlusSuffix();

/*
void setNotifyShownInfo();
void setDependShownInfo();
*/
int makeArgv();

char* PkInfos2Str();

char* PkInfo2Str();
char PkInfo2Chr();
char PkInfo2Char();
long PkInfo2Int();
float PkInfo2Flt();
VObj* PkInfo2Obj();
VObj* getObject();
