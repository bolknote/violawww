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
#define POLL_INTERVAL_US 500000  /* 0.5 seconds */
#define POLLS_PER_SECOND (1000000 / POLL_INTERVAL_US)  /* Number of polls per second */
#define MAX_CMD_LEN 256

/* Forward declarations */
static void show_error_dialog(const char *message);

/* Build all required paths based on executable directory */
static int build_paths(const char *exe_dir, char *resources_dir, size_t resources_size,
                      char *vw_path, size_t vw_size, char *viola_path, size_t viola_size,
                      char *plot_path, size_t plot_size) {
    if (exe_dir == NULL || resources_dir == NULL || vw_path == NULL ||
        viola_path == NULL || plot_path == NULL) {
        errno = EINVAL;
        return -1;
    }

    int ret;

    ret = snprintf(resources_dir, resources_size, "%s/../Resources", exe_dir);
    if (ret < 0 || (size_t)ret >= resources_size) return -1;

    ret = snprintf(vw_path, vw_size, "%s/vw.bin", exe_dir);
    if (ret < 0 || (size_t)ret >= vw_size) return -1;

    ret = snprintf(viola_path, viola_size, "%s/res", resources_dir);
    if (ret < 0 || (size_t)ret >= viola_size) return -1;

    ret = snprintf(plot_path, plot_size, "%s/vplot_dir", resources_dir);
    if (ret < 0 || (size_t)ret >= plot_size) return -1;

    return 0;
}

/* Check if vw.bin exists and show error if not */
static int check_vw_binary(const char *vw_path) {
    if (vw_path == NULL) {
        errno = EINVAL;
        return -1;
    }

    struct stat st;
    if (stat(vw_path, &st) != 0) {
        fprintf(stderr, "vw.bin not found at: %s\n", vw_path);
        show_error_dialog("ViolaWWW binary not found. The application may be corrupted.");
        return -1;
    }
    return 0;
}

/* Get the directory containing this executable */
static int get_executable_dir(char *buf, size_t size) {
    if (buf == NULL || size == 0) {
        errno = EINVAL;
        return -1;
    }

    char stack_buf[MAX_PATH];
    char *path_buf = stack_buf;
    uint32_t path_buf_size = (uint32_t)sizeof(stack_buf);

    /* First try with stack buffer; if too small, allocate the required size */
    if (_NSGetExecutablePath(path_buf, &path_buf_size) != 0) {
        char *heap_buf = malloc(path_buf_size);
        if (heap_buf == NULL) {
            return -1;
        }
        path_buf = heap_buf;
        if (_NSGetExecutablePath(path_buf, &path_buf_size) != 0) {
            free(heap_buf);
            return -1;
        }
    }
    
    /* Resolve symlinks and get real path */
    char real_path[MAX_PATH];
    if (realpath(path_buf, real_path) == NULL) {
        if (path_buf != stack_buf) {
            free(path_buf);
        }
        return -1;
    }
    
    if (path_buf != stack_buf) {
        free(path_buf);
    }
    
    /* Get directory part */
    char *dir = dirname(real_path);
    size_t dir_len = strlen(dir);
    if (dir_len + 1 > size) {
        errno = ENAMETOOLONG;
        return -1;
    }
    memcpy(buf, dir, dir_len + 1);
    
    return 0;
}

/* Setup all required environment variables */
static int setup_environment(const char *viola_path, const char *plot_path, const char *resources_dir) {
    char gs_lib[MAX_PATH];
    char gs_resources[MAX_PATH];
    char magick_home[MAX_PATH];
    char magick_config[MAX_PATH * 2];

    /* Set basic environment variables */
    setenv("VIOLA_PATH", viola_path, 1);
    setenv("PLOT_PATH", plot_path, 1);

    /* Set GS_LIB for bundled Ghostscript resources */
    snprintf(gs_resources, sizeof(gs_resources), "%s/ghostscript", resources_dir);
    /* GS_LIB expects paths to lib, Resource, fonts directories */
    int ret = snprintf(gs_lib, sizeof(gs_lib),
             "%s/lib:%s/Resource/Init:%s/Resource:%s/fonts:%s/iccprofiles",
             gs_resources, gs_resources, gs_resources, gs_resources, gs_resources);
    if (ret < 0 || (size_t)ret >= sizeof(gs_lib)) {
        fprintf(stderr, "Failed to build GS_LIB path\n");
        return -1;
    }
    setenv("GS_LIB", gs_lib, 1);
    setenv("GS_FONTPATH", gs_resources, 1);

    /* Set MAGICK_HOME for bundled ImageMagick (built with --disable-installed) */
    snprintf(magick_home, sizeof(magick_home), "%s/ImageMagick", resources_dir);
    setenv("MAGICK_HOME", magick_home, 1);
    /* Also set config path for ImageMagick to find its delegates.xml etc */
    snprintf(magick_config, sizeof(magick_config),
             "%s/etc/ImageMagick-7:%s/share/ImageMagick-7",
             magick_home, magick_home);
    setenv("MAGICK_CONFIGURE_PATH", magick_config, 1);

    return 0;
}

/* Setup PATH environment variable */
static int setup_path(const char *exe_dir) {
    const char *old_path = getenv("PATH");
    int needed = snprintf(NULL, 0, "%s:/opt/homebrew/bin:/usr/local/bin%s%s",
                          exe_dir,
                          old_path ? ":" : "",
                          old_path ? old_path : "");
    if (needed < 0) {
        fprintf(stderr, "Failed to calculate PATH length\n");
        return -1;
    }

    size_t buf_size = (size_t)needed + 1;
    char *new_path = malloc(buf_size);
    if (new_path == NULL) {
        fprintf(stderr, "Failed to allocate memory for PATH\n");
        return -1;
    }

    int written = snprintf(new_path, buf_size, "%s:/opt/homebrew/bin:/usr/local/bin%s%s",
                           exe_dir,
                           old_path ? ":" : "",
                           old_path ? old_path : "");
    if (written < 0 || (size_t)written >= buf_size) {
        free(new_path);
        fprintf(stderr, "Failed to build new PATH\n");
        return -1;
    }

    setenv("PATH", new_path, 1);
    free(new_path);
    return 0;
}

/* Check if X server is running by testing DISPLAY connection */
static int is_x_server_running(void) {
    /* Try to connect to X server using xset (use full path for Finder launch) */
    const char *xset_paths[] = {
        "/opt/X11/bin/xset",
        "/usr/X11/bin/xset",
        "/usr/local/bin/xset",
        NULL
    };

    struct stat st;
    for (int i = 0; xset_paths[i] != NULL; i++) {
        if (stat(xset_paths[i], &st) == 0) {
            char cmd[MAX_CMD_LEN];
            int ret = snprintf(cmd, sizeof(cmd), "%s q >/dev/null 2>&1", xset_paths[i]);
            if (ret > 0 && (size_t)ret < sizeof(cmd)) {
                if (system(cmd) == 0) {
                    return 1;  /* Success */
                }
            }
        }
    }

    /* Fallback: check if XQuartz process is running */
    return (system("pgrep -x Xquartz >/dev/null 2>&1") == 0) ? 1 : 0;
}

/* Check if XQuartz is installed */
static int is_xquartz_installed(void) {
    struct stat st;
    return (stat(XQUARTZ_APP, &st) == 0);
}

/* Launch XQuartz and wait for it to be ready */
static int launch_xquartz(void) {
    printf("Starting XQuartz...\n");
    
    /* Launch XQuartz in background (use full path for Finder launch) */
    int ret = system("/usr/bin/open -a XQuartz");
    if (ret != 0) {
        fprintf(stderr, "Failed to launch XQuartz\n");
        return -1;
    }
    
    /* Wait for X server to become available */
    int max_iterations = WAIT_TIMEOUT_SEC * POLLS_PER_SECOND;
    for (int i = 0; i < max_iterations; i++) {
        usleep(POLL_INTERVAL_US);
        if (is_x_server_running()) {
            printf("XQuartz is ready.\n");
            return 0;
        }
    }
    
    fprintf(stderr, "Timeout waiting for XQuartz to start\n");
    return -1;
}

/* Ensure DISPLAY is set and XQuartz is running */
static int ensure_xquartz_ready(void) {
    /* Ensure DISPLAY is set */
    if (getenv("DISPLAY") == NULL) {
        setenv("DISPLAY", XQUARTZ_DISPLAY, 1);
    }

    /* Check XQuartz */
    if (!is_xquartz_installed()) {
        show_error_dialog("XQuartz is required but not installed.\\n\\nPlease download and install XQuartz from:\\nhttps://www.xquartz.org/");
        /* Open XQuartz download page */
        system("open https://www.xquartz.org/");
        return -1;
    }

    /* Start XQuartz if not running */
    if (!is_x_server_running()) {
        if (launch_xquartz() != 0) {
            show_error_dialog("Failed to start XQuartz.\\n\\nPlease start XQuartz manually and try again.");
            return -1;
        }
    }

    return 0;
}

/* Prepare arguments for execv */
static char **prepare_argv(int argc, char *argv[], const char *vw_path) {
    if (argc < 0 || argv == NULL || vw_path == NULL) {
        errno = EINVAL;
        return NULL;
    }

    char **new_argv = malloc((argc + 1) * sizeof(char *));
    if (new_argv == NULL) {
        fprintf(stderr, "Memory allocation failed for arguments\n");
        return NULL;
    }

    new_argv[0] = (char *)vw_path;  /* Cast away const - execv doesn't modify */
    for (int i = 1; i < argc; i++) {
        new_argv[i] = argv[i];
    }
    new_argv[argc] = NULL;

    return new_argv;
}

/* Print startup information */
static void print_startup_info(const char *viola_path, const char *plot_path) {
    printf("Starting ViolaWWW...\n");
    printf("  VIOLA_PATH=%s\n", viola_path);
    printf("  PLOT_PATH=%s\n", plot_path);
    printf("  DISPLAY=%s\n", getenv("DISPLAY"));
}

/* Escape string for safe embedding inside an AppleScript double-quoted literal */
static int escape_for_osascript(const char *in, char *out, size_t out_size) {
    size_t j = 0;
    for (size_t i = 0; in[i] != '\0'; i++) {
        char c = in[i];
        if (c == '"' || c == '\\') {
            if (j + 2 >= out_size) {
                return -1;
            }
            out[j++] = '\\';
            out[j++] = c;
        } else if (c == '\n') {
            if (j + 2 >= out_size) {
                return -1;
            }
            out[j++] = '\\';
            out[j++] = 'n';
        } else {
            if (j + 1 >= out_size) {
                return -1;
            }
            out[j++] = c;
        }
    }
    if (j >= out_size) {
        return -1;
    }
    out[j] = '\0';
    return 0;
}

/* Show error dialog using osascript */
static void show_error_dialog(const char *message) {
    if (message == NULL) {
        return;
    }
    
    /* Worst case each char becomes two (escape), plus terminator */
    size_t esc_size = (strlen(message) * 2) + 1;
    char *escaped = malloc(esc_size);
    if (escaped == NULL) {
        return;
    }
    if (escape_for_osascript(message, escaped, esc_size) != 0) {
        free(escaped);
        return;
    }
    
    int needed = snprintf(NULL, 0,
        "osascript -e 'display dialog \"%s\" buttons {\"OK\"} default button \"OK\" "
        "with icon stop with title \"ViolaWWW\"'",
        escaped);
    if (needed < 0) {
        free(escaped);
        return;
    }
    
    char *cmd = malloc((size_t)needed + 1);
    if (cmd == NULL) {
        free(escaped);
        return;
    }
    
    int result = snprintf(cmd, (size_t)needed + 1,
        "osascript -e 'display dialog \"%s\" buttons {\"OK\"} default button \"OK\" "
        "with icon stop with title \"ViolaWWW\"'",
        escaped);
    if (result >= 0 && (size_t)result < (size_t)needed + 1) {
        system(cmd);
    }

    free(cmd);
    free(escaped);
}

int main(int argc, char *argv[]) {
    char exe_dir[MAX_PATH];
    char resources_dir[MAX_PATH];
    char vw_path[MAX_PATH];
    char viola_path[MAX_PATH];
    char plot_path[MAX_PATH];

    /* Get directory of this executable (MacOS/) */
    if (get_executable_dir(exe_dir, sizeof(exe_dir)) != 0) {
        fprintf(stderr, "Failed to get executable directory: %s\n", strerror(errno));
        return 1;
    }

    /* Build all required paths */
    if (build_paths(exe_dir, resources_dir, sizeof(resources_dir),
                   vw_path, sizeof(vw_path), viola_path, sizeof(viola_path),
                   plot_path, sizeof(plot_path)) != 0) {
        fprintf(stderr, "Failed to build application paths from: %s\n", exe_dir);
        return 1;
    }

    /* Check that vw.bin exists */
    if (check_vw_binary(vw_path) != 0) {
        return 1;
    }

    /* Setup environment variables */
    if (setup_environment(viola_path, plot_path, resources_dir) != 0) {
        fprintf(stderr, "Failed to setup environment variables\n");
        return 1;
    }

    /* Add MacOS directory and common tool paths to PATH */
    if (setup_path(exe_dir) != 0) {
        fprintf(stderr, "Failed to setup PATH environment variable\n");
        return 1;
    }

    /* Ensure DISPLAY is set and XQuartz is running */
    if (ensure_xquartz_ready() != 0) {
        return 1;
    }

    /* Prepare arguments for execv */
    char **new_argv = prepare_argv(argc, argv, vw_path);
    if (new_argv == NULL) {
        fprintf(stderr, "Failed to prepare command line arguments\n");
        return 1;
    }

    /* Execute vw.bin */
    print_startup_info(viola_path, plot_path);

    execv(vw_path, new_argv);

    /* If we get here, execv failed */
    fprintf(stderr, "Failed to execute vw.bin: %s\n", strerror(errno));
    free(new_argv);
    return 1;
}

