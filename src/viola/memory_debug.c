/*
 * memory_debug.c - Memory debugging utilities with backtrace support
 * 
 * This file provides enhanced memory debugging capabilities including
 * backtrace printing for malloc/free errors.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>

#ifdef MALLOC_DEBUG

/* Global flag to enable/disable memory debugging */
static int memory_debug_enabled = 1;

/* Function to print backtrace */
void print_backtrace(const char* prefix) {
    if (!memory_debug_enabled) return;
    
    void *array[20];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace(array, 20);
    strings = backtrace_symbols(array, size);

    fprintf(stderr, "%s: Backtrace (%zd frames):\n", prefix, size);
    for (i = 0; i < size; i++) {
        fprintf(stderr, "  %zd: %s\n", i, strings[i]);
    }
    fprintf(stderr, "\n");

    free(strings);
}

/* Enhanced malloc with backtrace */
void* debug_malloc(size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    
    if (!ptr) {
        fprintf(stderr, "MALLOC ERROR: Failed to allocate %zu bytes at %s:%d\n", size, file, line);
        print_backtrace("MALLOC ERROR");
        return NULL;
    }
    
    if (memory_debug_enabled) {
        fprintf(stderr, "MALLOC: %p (%zu bytes) at %s:%d\n", ptr, size, file, line);
    }
    
    return ptr;
}

/* Enhanced free with backtrace */
void debug_free(void* ptr, const char* file, int line) {
    if (!ptr) {
        fprintf(stderr, "FREE WARNING: Attempting to free NULL pointer at %s:%d\n", file, line);
        print_backtrace("FREE WARNING");
        return;
    }
    
    if (memory_debug_enabled) {
        fprintf(stderr, "FREE: %p at %s:%d\n", ptr, file, line);
    }
    
    free(ptr);
}

/* Signal handler for malloc errors */
void malloc_error_handler(int sig) {
    fprintf(stderr, "\n=== MALLOC ERROR DETECTED ===\n");
    fprintf(stderr, "Signal: %d\n", sig);
    print_backtrace("MALLOC ERROR");
    fprintf(stderr, "=== END BACKTRACE ===\n\n");
    
    /* Don't exit, just print backtrace and continue */
}

/* Initialize memory debugging */
void init_memory_debug(void) {
    /* Set up signal handler for malloc errors */
    signal(SIGABRT, malloc_error_handler);
    
    /* Enable malloc error reporting */
    setenv("MallocStackLogging", "1", 1);
    setenv("MallocScribble", "1", 1);
    setenv("MallocGuardEdges", "1", 1);
    
    fprintf(stderr, "Memory debugging enabled\n");
}

/* Disable memory debugging */
void disable_memory_debug(void) {
    memory_debug_enabled = 0;
}

/* Enable memory debugging */
void enable_memory_debug(void) {
    memory_debug_enabled = 1;
}

#else

/* Stub functions when MALLOC_DEBUG is not defined */
void print_backtrace(const char* prefix) { (void)prefix; }
void* debug_malloc(size_t size, const char* file, int line) { 
    (void)file; (void)line; 
    return malloc(size); 
}
void debug_free(void* ptr, const char* file, int line) { 
    (void)file; (void)line; 
    free(ptr); 
}
void init_memory_debug(void) { }
void disable_memory_debug(void) { }
void enable_memory_debug(void) { }

#endif /* MALLOC_DEBUG */
