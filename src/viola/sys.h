#pragma once

typedef struct MemoryGroupHeap {
    char* mem;
    int size;
    struct MemoryGroupHeap* next;
} MemoryGroupHeap;

typedef struct MemoryGroup {
    struct MemoryGroupHeap* heap;
    int heapUsedOffset;
    int defaultSize;
} MemoryGroup;

/*MemoryGroup *newMemoryGroup();*/

char* _Vmalloc(int size);
void _Vfree(char* x);

/*#define Vmalloc(gp, size) _Vmalloc(size)*/
/*#define Vfree(gp, size) _Vfree(size)*/

#define Vmalloc(gp, size) malloc(size)
#define Vfree(gp, x) free(x)

/*
void freeMemoryGroup();
void freeMemoryGroupHeaps();
*/

#define Rmalloc(x) malloc(x)
#define Rfree(x) free(x)

int init_sys(void);

/* Create a temp file with the given suffix (e.g., ".gif").
 * Uses mkstemps() for secure atomic creation.
 * Returns path allocated with saveString(), or NULL on error.
 * Caller is responsible for deleting the file when done.
 */
char* sys_make_temp_file(const char* suffix);
