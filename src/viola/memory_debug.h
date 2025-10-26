/*
 * memory_debug.h - Memory debugging utilities header
 */

#ifndef MEMORY_DEBUG_H
#define MEMORY_DEBUG_H

#include <stddef.h>

#ifdef MALLOC_DEBUG

/* Debug versions of malloc/free with backtrace */
#define MALLOC(size) debug_malloc(size, __FILE__, __LINE__)
#define FREE(ptr) debug_free(ptr, __FILE__, __LINE__)

/* Function declarations */
void print_backtrace(const char* prefix);
void* debug_malloc(size_t size, const char* file, int line);
void debug_free(void* ptr, const char* file, int line);
void init_memory_debug(void);
void disable_memory_debug(void);
void enable_memory_debug(void);

#else

/* Regular malloc/free when debugging is disabled */
#define MALLOC(size) malloc(size)
#define FREE(ptr) free(ptr)

/* Stub declarations */
void print_backtrace(const char* prefix);
void init_memory_debug(void);
void disable_memory_debug(void);
void enable_memory_debug(void);

#endif /* MALLOC_DEBUG */

#endif /* MEMORY_DEBUG_H */
