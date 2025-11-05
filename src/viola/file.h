/* file.h */

char* vl_expandPath();
char* getEnvironVars();
int setStackPath();
int loadFile();
int saveFile();
char* makeAbsolutePath(const char* path);
