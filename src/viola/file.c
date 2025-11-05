/*
 * file.c
 */
/*
 * Copyright 1991 Pei-Yuan Wei.  All rights reserved.
 *
 * Permission to use, copy, and/or distribute for any purpose and
 * without fee is hereby granted, provided that both the above copyright
 * notice and this permission notice appear in all copies and derived works.
 * Fees for distribution or use of this software or derived works may only
 * be charged with express written permission of the copyright holder.
 * This software is provided ``as is'' without express or implied warranty.
 */
#include "file.h"
#include "mystrings.h"
#include "utils.h"
#include <fcntl.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/param.h>
#include <limits.h>
#include <unistd.h>

int io_stat;

char* vl_expandPath(char* path, char* buffer)
{
    if (!path)
        return NULL;
    if (path[0] == '~') {
        /*		extern char *cuserid();*/ /* Bede McCall <bede@mitre.org> */
        struct passwd* info;
        char userName[256];
        int i = 0;

        if (path[1] == '\0' || path[1] == '/') {
            char* cp = getlogin();

            /* assume path looks like: "~" "~/viola" */
            if (cp) {
                strcpy(userName, cp);
            } else {
                struct passwd* pwds;

                pwds = getpwuid(getuid());
                strcpy(userName, pwds->pw_name);

                while (userName[i++] != ':')
                    ;
                userName[i] = '\0';
            }
        } else {
            char c;
            /* ie: "~wei/viola" */

            /* get user's name */
            for (; (c = path[i + 1]); i++) {
                if (isalpha(c))
                    userName[i] = c;
                else
                    break;
            }
            userName[i] = '\0';
        }
        if ((info = getpwnam(userName))) {
            strcpy(buffer, info->pw_dir);
            strcat(buffer, &path[i + 1]);
            return buffer;
        }
    } else {
        strcpy(buffer, path);
        return buffer;
    }
    fprintf(stderr, "failed to expand ~ for \"%s\"\n", path);
    return NULL;
}

/*
 * enter environment variables into the resource's variable list.
 *
 */
char* getEnvironVars(char* argv[], char* name, char* content)
{
    if (argv) {
        int ai = 0, i;
        char label[100];

        while (argv[ai]) {
            /*			fprintf(stderr, "argv[%d] = [%s]\n",ai,argv[ai]);*/
            for (i = 0; (label[i] = argv[ai][i]) != '='; i++)
                ;
            label[i] = '\0';
            if (!strcmp(name, label)) {
                strcpy(content, &argv[ai][++i]);
                /*				fprintf(stderr, "name=[%s] content= [%s]\n", name,
                 * content);*/
                return content;
            }
            ++ai;
        }
    }
    return NULL;
}

/*
 * loads a file from disk, and puts it in str.
 *
 * return: -1 if unable to open file.
 */
int loadFile(char* fileName, char** strp)
{
    int fd;
    FILE* fp;
    int i = 0, c;
    long size;

    /* printf("loading file '%s'\n",fileName); */

    fd = open(fileName, O_RDONLY);
    if (!fd) {
        io_stat = -1;
        return -1;
    }
    fp = fdopen(fd, "r");
    if (!fp) {
        io_stat = -1;
        return -1;
    }

    /* determine size of file */
    size = lseek(fd, 0, SEEK_END);

    *strp = (char*)malloc(sizeof(char) * (int)size + 1);

    rewind(fp);
    fread(*strp, size, 1, fp);

    (*strp)[size] = '\0';

    fclose(fp);
    close(fd);

    io_stat = i;

    return i;
}

/*
 * saves a str to a file
 *
 * return: -1 if unable to open file.
 */
int saveFile(char* fileName, char* str)
{
    FILE* fp;

    /*printf("save: name='%s'	 content='%s'\n",fileName,str);*/
    fp = fopen(fileName, "w");

    if (!fp) {
        fprintf(stderr, "Unable to open file '%s'. aborted.\n", fileName);
        return -1;
    }
    fputs(str, fp);

    fclose(fp);

    return 0;
}

/*
 * Convert a relative path to an absolute path.
 * If the path is already absolute or is a URL (contains ':'),
 * return it unchanged (or a copy if needed).
 * Otherwise, make it relative to the current working directory.
 */
char* makeAbsolutePath(const char* path)
{
    char* result;
    char* real_path;
    char cwd[MAXPATHLEN];
    
    if (!path) {
        return NULL;
    }
    
    /* If path starts with '/', it's already absolute */
    if (path[0] == '/') {
        return (char*)path;
    }
    
    /* If path contains ':', it's likely a URL (http://, https://, file://, etc.) */
    if (strchr(path, ':')) {
        return (char*)path;
    }
    
    /* Try to use realpath first, which resolves symlinks and normalizes */
    real_path = realpath(path, NULL);
    if (real_path) {
        result = (char*)malloc(strlen(real_path) + 1);
        if (result) {
            strcpy(result, real_path);
            free(real_path);
            return result;
        }
        free(real_path);
    }
    
    /* Fallback: combine with current working directory */
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        size_t cwd_len = strlen(cwd);
        size_t path_len = strlen(path);
        size_t total_len = cwd_len + 1 + path_len + 1;
        
        result = (char*)malloc(total_len);
        if (result) {
            strcpy(result, cwd);
            if (cwd[cwd_len - 1] != '/') {
                strcat(result, "/");
            }
            strcat(result, path);
            return result;
        }
    }
    
    /* If all else fails, return the original path */
    return (char*)path;
}
