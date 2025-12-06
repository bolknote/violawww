/*
 * ViolaWWW Launcher
 * 
 * Sets up environment variables and ensures XQuartz is running
 * before launching the main ViolaWWW browser.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <mach-o/dyld.h>
#include <sys/stat.h>
#include <errno.h>

#define XQUARTZ_APP "/Applications/Utilities/XQuartz.app"
#define XQUARTZ_DISPLAY ":0"
#define MAX_PATH 4096
#define WAIT_TIMEOUT_SEC 10

/* Get the directory containing this executable */
static int get_executable_dir(char *buf, size_t size) {
    uint32_t bufsize = (uint32_t)size;
    if (_NSGetExecutablePath(buf, &bufsize) != 0) {
        return -1;
    }
    
    /* Resolve symlinks and get real path */
    char real_path[MAX_PATH];
    if (realpath(buf, real_path) == NULL) {
        return -1;
    }
    
    /* Get directory part */
    char *dir = dirname(real_path);
    strncpy(buf, dir, size - 1);
    buf[size - 1] = '\0';
    
    return 0;
}

/* Check if X server is running by testing DISPLAY connection */
static int is_x_server_running(void) {
    /* Try to connect to X server using xset */
    int ret = system("xset q >/dev/null 2>&1");
    return (ret == 0);
}

/* Check if XQuartz is installed */
static int is_xquartz_installed(void) {
    struct stat st;
    return (stat(XQUARTZ_APP, &st) == 0);
}

/* Launch XQuartz and wait for it to be ready */
static int launch_xquartz(void) {
    printf("Starting XQuartz...\n");
    
    /* Launch XQuartz in background */
    int ret = system("open -a XQuartz");
    if (ret != 0) {
        fprintf(stderr, "Failed to launch XQuartz\n");
        return -1;
    }
    
    /* Wait for X server to become available */
    for (int i = 0; i < WAIT_TIMEOUT_SEC * 2; i++) {
        usleep(500000); /* 0.5 seconds */
        if (is_x_server_running()) {
            printf("XQuartz is ready.\n");
            return 0;
        }
    }
    
    fprintf(stderr, "Timeout waiting for XQuartz to start\n");
    return -1;
}

/* Show error dialog using osascript */
static void show_error_dialog(const char *message) {
    char cmd[1024];
    snprintf(cmd, sizeof(cmd),
        "osascript -e 'display dialog \"%s\" buttons {\"OK\"} default button \"OK\" with icon stop with title \"ViolaWWW\"'",
        message);
    system(cmd);
}

int main(int argc, char *argv[]) {
    char exe_dir[MAX_PATH];
    char resources_dir[MAX_PATH];
    char vw_path[MAX_PATH];
    char viola_path[MAX_PATH];
    char plot_path[MAX_PATH];
    
    /* Get directory of this executable (MacOS/) */
    if (get_executable_dir(exe_dir, sizeof(exe_dir)) != 0) {
        fprintf(stderr, "Failed to get executable directory\n");
        return 1;
    }
    
    /* Build paths */
    snprintf(resources_dir, sizeof(resources_dir), "%s/../Resources", exe_dir);
    snprintf(vw_path, sizeof(vw_path), "%s/vw.bin", exe_dir);
    snprintf(viola_path, sizeof(viola_path), "%s/res", resources_dir);
    snprintf(plot_path, sizeof(plot_path), "%s/vplot_dir", resources_dir);
    
    /* Check that vw.bin exists */
    struct stat st;
    if (stat(vw_path, &st) != 0) {
        fprintf(stderr, "vw.bin not found at: %s\n", vw_path);
        show_error_dialog("ViolaWWW binary not found. The application may be corrupted.");
        return 1;
    }
    
    /* Set environment variables */
    setenv("VIOLA_PATH", viola_path, 1);
    setenv("PLOT_PATH", plot_path, 1);
    
    /* Ensure DISPLAY is set */
    if (getenv("DISPLAY") == NULL) {
        setenv("DISPLAY", XQUARTZ_DISPLAY, 1);
    }
    
    /* Check XQuartz */
    if (!is_xquartz_installed()) {
        show_error_dialog("XQuartz is required but not installed.\\n\\nPlease download and install XQuartz from:\\nhttps://www.xquartz.org/");
        /* Open XQuartz download page */
        system("open https://www.xquartz.org/");
        return 1;
    }
    
    /* Start XQuartz if not running */
    if (!is_x_server_running()) {
        if (launch_xquartz() != 0) {
            show_error_dialog("Failed to start XQuartz.\\n\\nPlease start XQuartz manually and try again.");
            return 1;
        }
    }
    
    /* Build argument list for execv */
    /* We pass through all arguments */
    char **new_argv = malloc((argc + 1) * sizeof(char *));
    if (new_argv == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    new_argv[0] = vw_path;
    for (int i = 1; i < argc; i++) {
        new_argv[i] = argv[i];
    }
    new_argv[argc] = NULL;
    
    /* Execute vw.bin */
    printf("Starting ViolaWWW...\n");
    printf("  VIOLA_PATH=%s\n", viola_path);
    printf("  PLOT_PATH=%s\n", plot_path);
    printf("  DISPLAY=%s\n", getenv("DISPLAY"));
    
    execv(vw_path, new_argv);
    
    /* If we get here, execv failed */
    fprintf(stderr, "Failed to execute vw.bin: %s\n", strerror(errno));
    free(new_argv);
    return 1;
}

