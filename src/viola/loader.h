typedef struct ClassInfo ClassInfo;

ClassInfo *getClassInfo();
int init_loader();
int load_object();
int load_objects_slots();
int setStackPath();
int setViolaPath();
