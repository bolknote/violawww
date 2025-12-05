/*
 * vw_stubs.c
 *
 * Stub implementations of vw functions for standalone viola binary
 * (without the vw Motif interface).
 * 
 * Includes persistent URL history storage in ~/.viola_history
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#include "../libWWW/HTParse.h"

/* Stub for docViews - not available in standalone viola */
void* docViews = NULL;

/* --- Persistent History Implementation --- */

#define MAX_HISTORY_URLS 4096
#define MAX_URL_LENGTH 2048
#define HISTORY_FILENAME ".viola_history"

static char* historyURLs[MAX_HISTORY_URLS];
static int historyCount = 0;
static int historyLoaded = 0;

/* Get path to history file (~/.viola_history) */
static char* getHistoryFilePath(void) {
    static char path[1024];
    const char* home = getenv("HOME");
    
    if (!home) {
        struct passwd* pw = getpwuid(getuid());
        if (pw) {
            home = pw->pw_dir;
        }
    }
    
    if (!home) {
        return NULL;
    }
    
    snprintf(path, sizeof(path), "%s/%s", home, HISTORY_FILENAME);
    return path;
}

/* Load history from file */
static void loadHistory(void) {
    FILE* fp;
    char* path;
    char line[MAX_URL_LENGTH];
    
    if (historyLoaded) {
        return;
    }
    historyLoaded = 1;
    
    path = getHistoryFilePath();
    if (!path) {
        return;
    }
    
    fp = fopen(path, "r");
    if (!fp) {
        return;
    }
    
    while (fgets(line, sizeof(line), fp) && historyCount < MAX_HISTORY_URLS) {
        /* Remove trailing newline */
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        
        if (len > 0) {
            historyURLs[historyCount] = strdup(line);
            if (historyURLs[historyCount]) {
                historyCount++;
            }
        }
    }
    
    fclose(fp);
}

/* Save a single URL to history file (append) */
static void saveURLToFile(const char* url) {
    FILE* fp;
    char* path;
    
    path = getHistoryFilePath();
    if (!path) {
        return;
    }
    
    fp = fopen(path, "a");
    if (!fp) {
        return;
    }
    
    fprintf(fp, "%s\n", url);
    fclose(fp);
}

/* Check if URL is in standalone history */
int isURLInHistory(void* dvi, char* url) {
    int i;
    char* canonicalURL;
    
    (void)dvi; /* Not used in standalone mode */
    
    if (!url || !*url) {
        return 0;
    }
    
    /* Ensure history is loaded */
    loadHistory();
    
    /* Check exact match first */
    for (i = 0; i < historyCount; i++) {
        if (historyURLs[i] && !strcmp(url, historyURLs[i])) {
            return 1;
        }
    }
    
    /* Try normalizing URL relative to each history entry */
    for (i = 0; i < historyCount; i++) {
        if (!historyURLs[i]) {
            continue;
        }
        
        canonicalURL = HTParse(url, historyURLs[i], PARSE_ALL);
        if (canonicalURL) {
            HTSimplify(canonicalURL);
            
            /* Check if canonical URL matches any history entry */
            int j;
            for (j = 0; j < historyCount; j++) {
                if (historyURLs[j] && !strcmp(canonicalURL, historyURLs[j])) {
                    free(canonicalURL);
                    return 1;
                }
            }
            free(canonicalURL);
        }
    }
    
    return 0;
}

/* Add URL to standalone history (persistent) */
void addURLToStandaloneHistory(const char* url) {
    int i;
    char* urlCopy;
    
    if (!url || !*url) {
        return;
    }
    
    /* Ensure history is loaded */
    loadHistory();
    
    /* Check if already exists */
    for (i = 0; i < historyCount; i++) {
        if (historyURLs[i] && !strcmp(url, historyURLs[i])) {
            return; /* Already in history */
        }
    }
    
    /* Add to memory */
    if (historyCount < MAX_HISTORY_URLS) {
        urlCopy = strdup(url);
        if (urlCopy) {
            historyURLs[historyCount++] = urlCopy;
            /* Also save to file */
            saveURLToFile(url);
        }
    }
}

/* Stub for compareDocViewCloneID - not used in standalone */
int compareDocViewCloneID(void* vkey, void* vdata) {
    (void)vkey;
    (void)vdata;
    return 0;
}

/* Stub for registerSyncSocket - no Xt in standalone viola */
void registerSyncSocket(int fd) {
    (void)fd;
    /* In standalone viola, sync processing happens via polling in event loop */
}
