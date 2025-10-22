#pragma once

#ifndef CLASSINFO_DEFINED
typedef struct ClassInfo ClassInfo;
#endif

ClassInfo* getClassInfo();
int init_loader();
int load_object();
int load_objects_slots();
int setStackPath();
int setViolaPath();
