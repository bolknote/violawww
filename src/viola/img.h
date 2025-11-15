typedef struct ImgNode {
    char* id;
    char* filename;
    XImageInfo* ximageinfo;
    int width, height;
    int refc;
    struct ImgNode* next;
} ImgNode;

void purgeImg(void);
int imgNodeRefDec(char*);
ImgNode* imgNodeRefInc(char*, char*);
