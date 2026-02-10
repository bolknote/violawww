#include "../libStyle/libstg.h"

#ifndef PACKET_DEFINED
#define PACKET_DEFINED
typedef struct Packet Packet;
#endif

extern STGLib* stgLib;
extern STGGroup* stgGroup;

int loadSTG(char* url);
int getSTGInfo(char* tagName, char* attrName, Packet* result);
int getSTGInfo_clean(STGMajor* tagPtr);
int getSTGInfo_tagPtr(Packet* result, char* tagName1, char* tagName2);
int getSTGInfo_tagPtrWithDepth(Packet* result, char* tagName1, char* tagName2, int depth);
int getSTGInfo_tagPtrWithStyle(Packet* result, char* tagName1, char* tagName2, char* styleAttr);
int getSTGInfo_attr(STGMajor* tagPtr, char* attrName, Packet* result);
int getSTGInfo_attrFromResult(long resultPtr, char* attrName, Packet* result);
