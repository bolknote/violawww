#include "obj.h"
#include "packet.h"

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

char* PkInfo2Str(Packet* pk);
char PkInfo2Char(Packet* pk);
long PkInfo2Int(Packet* pk);
float PkInfo2Flt(Packet* pk);
VObj* PkInfo2Obj(Packet* pk);
VObj* getObject();
