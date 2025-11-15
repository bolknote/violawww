#include "obj.h"
#include "packet.h"

extern int cmd_history;
extern int verbose;

int transferNumList2Array(char*, int*, int);
int argNumsToInt(Packet*, int, int*);
VObjList* strOListToOList(char*);
char* OListToStr(VObjList*);
char* OListToStrPlusSuffix(VObjList*, char*);

/*
void setNotifyShownInfo();
void setDependShownInfo();
*/
int makeArgv(char**, char*);

char* PkInfos2Str(int, Packet*);

char* PkInfo2Str(Packet* pk);
char PkInfo2Char(Packet* pk);
long PkInfo2Int(Packet* pk);
float PkInfo2Flt(Packet* pk);
VObj* PkInfo2Obj(Packet* pk);
VObj* getObject();
