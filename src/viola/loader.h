#pragma once

#include <stdio.h>

#ifndef CLASSINFO_DEFINED
typedef struct ClassInfo ClassInfo;
#endif

ClassInfo* getClassInfo(void);
int init_loader(char* path);
int load_object(char* filename, char* pathname);
int load_objects_slots(FILE* fp, long (*slotv)[100][2], int* slotc);
int setStackPath();
int setViolaPath(char* newPathStr);
