/* file.h */

char* vl_expandPath(char*, char*);
char* getEnvironVars(char**, char*, char*);
int setStackPath(void);
int loadFile(char*, char**);
int saveFile(char*, char*);
char* makeAbsolutePath(const char* path);
