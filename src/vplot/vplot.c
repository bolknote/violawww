/*
 * vplot - 3D surface plotter and OFF model viewer for ViolaWWW
 *
 * Copyright (c) 2025 Evgeny Stepanischev
 *
 * This is a reverse-engineered reimplementation based on the commands
 * found in the original plot.v script from ViolaWWW. It emulates the
 * original V-Plot utility written by Scott Silvey in the early 1990s.
 *
 * The original V-Plot was an external X11 program that ViolaWWW
 * communicated with via pseudo-terminal (TTY class) to render 3D
 * graphics in an embedded window.
 *
 * USAGE:
 *   vplot reads commands from stdin and renders to an X11 window.
 *   It is designed to be spawned by ViolaWWW's TTY class.
 *
 * SUPPORTED COMMANDS:
 *   window <wid> <width> <height>  - Set target X11 window ID and size
 *   domain <x1> <x2> <y1> <y2>     - Set the X/Y domain for equations
 *   interval <step>                - Set grid step size for equations
 *   equation <expr>                - Set z=f(x,y) equation to plot
 *                                    Supports: sin, cos, exp, sqrt, abs
 *                                    Variables: x, y
 *                                    Operators: + - * / ^
 *   file <path>                    - Load 3D model in OFF format
 *   bgcolor <color>                - Set background color (X11 name)
 *   fgcolor <color>                - Set foreground/line color
 *   cx <angle>                     - Set camera X rotation (0-360)
 *   cy <angle>                     - Set camera Y rotation
 *   cz <angle>                     - Set camera Z rotation
 *   expose                         - Force redraw
 *   mbuf on|off                    - Enable/disable double buffering
 *   quit                           - Exit the program
 *
 * OFF FILE FORMAT:
 *   Supports standard OFF (Object File Format) files with optional
 *   "OFF" header. Comments starting with # are ignored.
 *
 * BUILD:
 *   cc -o vplot vplot.c -I/opt/X11/include -L/opt/X11/lib -lX11 -lm
 */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#ifdef __APPLE__
#include <mach-o/dyld.h>
#include <libgen.h>
#endif

// Logging
static FILE *logfp = NULL;

static void logmsg(const char *fmt, ...) {
    if (!logfp) {
        logfp = fopen("/tmp/vplot.log", "a");
        if (logfp) setbuf(logfp, NULL);
    }
    if (logfp) {
        va_list ap;
        va_start(ap, fmt);
        vfprintf(logfp, fmt, ap);
        va_end(ap);
        fflush(logfp);
    }
}

static Display *dpy = NULL;
static int screen = 0;
static Window win = 0;
static GC gc = NULL;
static Pixmap backbuf = 0;
static int use_backbuf = 0;

static unsigned long fg = 0, bg = 0;
static double cam_x = 30.0, cam_y = 30.0, cam_z = 0.0;
static int win_w = 400, win_h = 400;

// Domain and interval for equation plotting
static double domain_x1 = -2.0, domain_x2 = 2.0;
static double domain_y1 = -2.0, domain_y2 = 2.0;
static double interval = 0.2;

// Simple expression evaluator
static char equation[512] = "0";
static const char *expr_ptr;
static double expr_x, expr_y;

// Forward declarations for expression parser
static double parse_expr(void);
static double parse_term(void);
static double parse_factor(void);
static double parse_primary(void);

static void skip_spaces(void) {
    while (*expr_ptr && isspace((unsigned char)*expr_ptr)) expr_ptr++;
}

static double parse_number(void) {
    skip_spaces();
    char *end;
    double val = strtod(expr_ptr, &end);
    expr_ptr = end;
    return val;
}

static double parse_primary(void) {
    skip_spaces();
    
    if (*expr_ptr == '(') {
        expr_ptr++;
        double val = parse_expr();
        skip_spaces();
        if (*expr_ptr == ')') expr_ptr++;
        return val;
    }
    
    // Check for functions and variables
    if (strncmp(expr_ptr, "sin", 3) == 0 && !isalnum((unsigned char)expr_ptr[3])) {
        expr_ptr += 3;
        skip_spaces();
        if (*expr_ptr == '(') {
            expr_ptr++;
            double val = parse_expr();
            skip_spaces();
            if (*expr_ptr == ')') expr_ptr++;
            return sin(val);
        }
        return 0;
    }
    if (strncmp(expr_ptr, "cos", 3) == 0 && !isalnum((unsigned char)expr_ptr[3])) {
        expr_ptr += 3;
        skip_spaces();
        if (*expr_ptr == '(') {
            expr_ptr++;
            double val = parse_expr();
            skip_spaces();
            if (*expr_ptr == ')') expr_ptr++;
            return cos(val);
        }
        return 0;
    }
    if (strncmp(expr_ptr, "exp", 3) == 0 && !isalnum((unsigned char)expr_ptr[3])) {
        expr_ptr += 3;
        skip_spaces();
        if (*expr_ptr == '(') {
            expr_ptr++;
            double val = parse_expr();
            skip_spaces();
            if (*expr_ptr == ')') expr_ptr++;
            return exp(val);
        }
        return 0;
    }
    if (strncmp(expr_ptr, "sqrt", 4) == 0 && !isalnum((unsigned char)expr_ptr[4])) {
        expr_ptr += 4;
        skip_spaces();
        if (*expr_ptr == '(') {
            expr_ptr++;
            double val = parse_expr();
            skip_spaces();
            if (*expr_ptr == ')') expr_ptr++;
            return sqrt(fabs(val));
        }
        return 0;
    }
    if (strncmp(expr_ptr, "abs", 3) == 0 && !isalnum((unsigned char)expr_ptr[3])) {
        expr_ptr += 3;
        skip_spaces();
        if (*expr_ptr == '(') {
            expr_ptr++;
            double val = parse_expr();
            skip_spaces();
            if (*expr_ptr == ')') expr_ptr++;
            return fabs(val);
        }
        return 0;
    }
    
    // Variables
    if (*expr_ptr == 'x' && (expr_ptr[1] == '\0' || !isalnum((unsigned char)expr_ptr[1]))) {
        expr_ptr++;
        return expr_x;
    }
    if (*expr_ptr == 'y' && (expr_ptr[1] == '\0' || !isalnum((unsigned char)expr_ptr[1]))) {
        expr_ptr++;
        return expr_y;
    }
    
    // Number
    return parse_number();
}

static double parse_power(void) {
    double base = parse_primary();
    skip_spaces();
    if (*expr_ptr == '^') {
        expr_ptr++;
        double exp_val = parse_factor();
        return pow(base, exp_val);
    }
    return base;
}

static double parse_factor(void) {
    skip_spaces();
    if (*expr_ptr == '-') {
        expr_ptr++;
        return -parse_factor();
    }
    if (*expr_ptr == '+') {
        expr_ptr++;
        return parse_factor();
    }
    return parse_power();
}

static double parse_term(void) {
    double val = parse_factor();
    skip_spaces();
    while (*expr_ptr == '*' || *expr_ptr == '/') {
        char op = *expr_ptr++;
        double right = parse_factor();
        if (op == '*') val *= right;
        else if (right != 0) val /= right;
        skip_spaces();
    }
    return val;
}

static double parse_expr(void) {
    double val = parse_term();
    skip_spaces();
    while (*expr_ptr == '+' || *expr_ptr == '-') {
        char op = *expr_ptr++;
        double right = parse_term();
        if (op == '+') val += right;
        else val -= right;
        skip_spaces();
    }
    return val;
}

static double eval_equation(double x, double y) {
    expr_x = x;
    expr_y = y;
    expr_ptr = equation;
    return parse_expr();
}

static void set_color(unsigned long *dst, const char *name) {
    if (!dpy) return;
    Colormap cmap = DefaultColormap(dpy, screen);
    XColor xcol, exact;
    if (XAllocNamedColor(dpy, cmap, name, &xcol, &exact)) {
        *dst = xcol.pixel;
    }
}

typedef struct { double x,y,z; } Vec3;

// Forward declarations
static Vec3 rot(Vec3 v);
static void project(Vec3 v, int *px, int *py);
static void draw_line(Drawable d, int x1, int y1, int x2, int y2);

// 3D Model data
#define MAX_VERTS 10000
#define MAX_FACES 20000

static Vec3 model_verts[MAX_VERTS];
static int model_nverts = 0;

// Face: first element is count, rest are vertex indices
static int model_faces[MAX_FACES][32];
static int model_nfaces = 0;
static int model_loaded = 0;

static void clear_model(void) {
    model_nverts = 0;
    model_nfaces = 0;
    model_loaded = 0;
}

static int load_off_model(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        logmsg("load_off: cannot open '%s'\n", filename);
        return 0;
    }
    
    char line[1024];
    int expected_verts = 0, expected_faces = 0;
    
    // Skip header (might be "OFF" or comments starting with #)
    while (fgets(line, sizeof(line), fp)) {
        char *p = line;
        while (*p && isspace(*p)) p++;
        if (*p == '#' || *p == '\0') continue;
        // Check for OFF header
        if (strncmp(p, "OFF", 3) == 0) {
            // May have numbers on same line
            p += 3;
            while (*p && isspace(*p)) p++;
            if (*p == '\0' || *p == '#') continue;
        }
        // Try to parse vertex/face counts
        int ne = 0;
        if (sscanf(p, "%d %d %d", &expected_verts, &expected_faces, &ne) >= 2) {
            logmsg("load_off: header: nv=%d, nf=%d, ne=%d\n", expected_verts, expected_faces, ne);
            break;
        }
    }
    
    clear_model();
    
    // Read vertices (exactly expected_verts lines)
    double minx = 1e30, miny = 1e30, minz = 1e30;
    double maxx = -1e30, maxy = -1e30, maxz = -1e30;
    
    while (model_nverts < expected_verts && model_nverts < MAX_VERTS && fgets(line, sizeof(line), fp)) {
        char *p = line;
        while (*p && isspace(*p)) p++;
        if (*p == '#' || *p == '\0') continue;
        
        double x, y, z;
        if (sscanf(p, "%lf %lf %lf", &x, &y, &z) == 3) {
            model_verts[model_nverts].x = x;
            model_verts[model_nverts].y = y;
            model_verts[model_nverts].z = z;
            if (x < minx) minx = x; if (x > maxx) maxx = x;
            if (y < miny) miny = y; if (y > maxy) maxy = y;
            if (z < minz) minz = z; if (z > maxz) maxz = z;
            model_nverts++;
        }
    }
    
    // Normalize model to [-1,1] range
    double cx = (minx + maxx) / 2.0;
    double cy = (miny + maxy) / 2.0;
    double cz = (minz + maxz) / 2.0;
    double scale = maxx - minx;
    if (maxy - miny > scale) scale = maxy - miny;
    if (maxz - minz > scale) scale = maxz - minz;
    if (scale < 1e-10) scale = 1.0;
    scale = 2.0 / scale;
    
    for (int i = 0; i < model_nverts; i++) {
        model_verts[i].x = (model_verts[i].x - cx) * scale;
        model_verts[i].y = (model_verts[i].y - cy) * scale;
        model_verts[i].z = (model_verts[i].z - cz) * scale;
    }
    
    logmsg("load_off: loaded %d vertices\n", model_nverts);
    
    // Read faces
    while (model_nfaces < expected_faces && model_nfaces < MAX_FACES && fgets(line, sizeof(line), fp)) {
        char *p = line;
        while (*p && isspace(*p)) p++;
        if (*p == '#' || *p == '\0') continue;
        
        int count;
        if (sscanf(p, "%d", &count) == 1 && count >= 3 && count < 32) {
            model_faces[model_nfaces][0] = count;
            // Parse vertex indices
            int ok = 1;
            for (int i = 0; i < count && ok; i++) {
                // Skip to next number
                while (*p && !isspace(*p)) p++;
                while (*p && isspace(*p)) p++;
                if (sscanf(p, "%d", &model_faces[model_nfaces][i+1]) != 1) ok = 0;
            }
            if (ok) model_nfaces++;
        }
    }
    
    fclose(fp);
    model_loaded = 1;
    logmsg("load_off: loaded %d faces\n", model_nfaces);
    return 1;
}

static void draw_model(Drawable d) {
    if (!model_loaded || model_nverts == 0) return;
    
    // Draw wireframe of all faces
    for (int f = 0; f < model_nfaces; f++) {
        int count = model_faces[f][0];
        for (int i = 0; i < count; i++) {
            int v1 = model_faces[f][i + 1];
            int v2 = model_faces[f][((i + 1) % count) + 1];
            if (v1 < 0 || v1 >= model_nverts) continue;
            if (v2 < 0 || v2 >= model_nverts) continue;
            
            Vec3 p1 = rot(model_verts[v1]);
            Vec3 p2 = rot(model_verts[v2]);
            
            int px1, py1, px2, py2;
            project(p1, &px1, &py1);
            project(p2, &px2, &py2);
            
            draw_line(d, px1, py1, px2, py2);
        }
    }
}

static Vec3 rot(Vec3 v) {
    // Convert slider values (0-20) to angle range
    double ax = (cam_x - 10.0) * 18.0 * M_PI / 180.0;  // -180 to 180 degrees
    double ay = (cam_y - 10.0) * 18.0 * M_PI / 180.0;
    double az = (cam_z - 10.0) * 18.0 * M_PI / 180.0;

    double cx = cos(ax), sx = sin(ax);
    double cy = cos(ay), sy = sin(ay);
    double cz = cos(az), sz = sin(az);

    double x = v.x, y = v.y, z = v.z;

    // Rx
    double y1 = cx*y - sx*z;
    double z1 = sx*y + cx*z;
    y = y1; z = z1;

    // Ry
    double x2 = cy*x + sy*z;
    double z2 = -sy*x + cy*z;
    x = x2; z = z2;

    // Rz
    double x3 = cz*x - sz*y;
    double y3 = sz*x + cz*y;
    x = x3; y = y3;

    Vec3 r = {x,y,z};
    return r;
}

static void project(Vec3 v, int *px, int *py) {
    double scale = (win_w < win_h ? win_w : win_h) * 0.35;
    *px = (int)(win_w/2  + v.x * scale);
    *py = (int)(win_h/2  - v.y * scale);
}

static void draw_line(Drawable d, int x1, int y1, int x2, int y2) {
    XDrawLine(dpy, d, gc, x1, y1, x2, y2);
}

static void draw_surface(Drawable d) {
    // Calculate grid dimensions
    double range_x = domain_x2 - domain_x1;
    double range_y = domain_y2 - domain_y1;
    int nx = (int)(range_x / interval) + 1;
    int ny = (int)(range_y / interval) + 1;
    
    if (nx > 100) nx = 100;
    if (ny > 100) ny = 100;
    if (nx < 2) nx = 2;
    if (ny < 2) ny = 2;
    
    double dx = range_x / (nx - 1);
    double dy = range_y / (ny - 1);
    
    // Normalize coordinates to fit in view
    double max_coord = fmax(fabs(domain_x1), fmax(fabs(domain_x2), fmax(fabs(domain_y1), fabs(domain_y2))));
    double scale = 1.0 / (max_coord > 0 ? max_coord : 1.0);
    
    // Draw grid lines
    for (int i = 0; i < nx; i++) {
        double x = domain_x1 + i * dx;
        for (int j = 0; j < ny - 1; j++) {
            double y1 = domain_y1 + j * dy;
            double y2 = domain_y1 + (j+1) * dy;
            double z1 = eval_equation(x, y1);
            double z2 = eval_equation(x, y2);
            
            Vec3 v1 = {x * scale, y1 * scale, z1 * scale};
            Vec3 v2 = {x * scale, y2 * scale, z2 * scale};
            
            Vec3 r1 = rot(v1);
            Vec3 r2 = rot(v2);
            
            int px1, py1, px2, py2;
            project(r1, &px1, &py1);
            project(r2, &px2, &py2);
            
            draw_line(d, px1, py1, px2, py2);
        }
    }
    
    for (int j = 0; j < ny; j++) {
        double y = domain_y1 + j * dy;
        for (int i = 0; i < nx - 1; i++) {
            double x1 = domain_x1 + i * dx;
            double x2 = domain_x1 + (i+1) * dx;
            double z1 = eval_equation(x1, y);
            double z2 = eval_equation(x2, y);
            
            Vec3 v1 = {x1 * scale, y * scale, z1 * scale};
            Vec3 v2 = {x2 * scale, y * scale, z2 * scale};
            
            Vec3 r1 = rot(v1);
            Vec3 r2 = rot(v2);
            
            int px1, py1, px2, py2;
            project(r1, &px1, &py1);
            project(r2, &px2, &py2);
            
            draw_line(d, px1, py1, px2, py2);
        }
    }
}

static void draw_axes(Drawable d) {
    // Draw coordinate axes
    Vec3 origin = {0, 0, 0};
    Vec3 ax = {1, 0, 0};
    Vec3 ay = {0, 1, 0};
    Vec3 az = {0, 0, 1};
    
    Vec3 ro = rot(origin);
    Vec3 rx = rot(ax);
    Vec3 ry = rot(ay);
    Vec3 rz = rot(az);
    
    int po[2], px[2], py[2], pz[2];
    project(ro, &po[0], &po[1]);
    project(rx, &px[0], &px[1]);
    project(ry, &py[0], &py[1]);
    project(rz, &pz[0], &pz[1]);
    
    // Use a slightly different shade for axes
    XSetForeground(dpy, gc, fg);
    draw_line(d, po[0], po[1], px[0], px[1]);
    draw_line(d, po[0], po[1], py[0], py[1]);
    draw_line(d, po[0], po[1], pz[0], pz[1]);
}

static void redraw(void) {
    if (!dpy || !win) return;

    Drawable target = use_backbuf && backbuf ? backbuf : win;
    
    XSetForeground(dpy, gc, bg);
    XFillRectangle(dpy, target, gc, 0, 0, win_w, win_h);
    XSetForeground(dpy, gc, fg);
    
    if (model_loaded) {
        draw_model(target);
    } else {
        draw_axes(target);
        draw_surface(target);
    }
    
    if (use_backbuf && backbuf) {
        XCopyArea(dpy, backbuf, win, gc, 0, 0, win_w, win_h, 0, 0);
    }
    
    XFlush(dpy);
}

static void setup_backbuf(void) {
    if (!dpy || !win) return;
    if (backbuf) XFreePixmap(dpy, backbuf);
    backbuf = XCreatePixmap(dpy, win, win_w, win_h, DefaultDepth(dpy, screen));
}

static void handle_cmd(char *line) {
    char *nl = strpbrk(line, "\r\n");
    if (nl) *nl = '\0';
    if (*line == '\0') return;

    // Make a copy since strtok modifies the string
    char linecopy[1024];
    strncpy(linecopy, line, sizeof(linecopy)-1);
    linecopy[sizeof(linecopy)-1] = '\0';

    char *cmd = strtok(linecopy, " \t");
    if (!cmd) return;

    if (!strcmp(cmd, "window")) {
        char *sid = strtok(NULL," \t");
        char *sw  = strtok(NULL," \t");
        char *sh  = strtok(NULL," \t");
        if (!sid || !sw || !sh) return;

        if (!dpy) {
            dpy = XOpenDisplay(NULL);
            if (!dpy) {
                fprintf(stderr, "vplot: cannot open display\n");
                exit(1);
            }
            screen = DefaultScreen(dpy);
        }

        win = (Window)strtoul(sid, NULL, 0);
        win_w = atoi(sw);
        win_h = atoi(sh);

        if (gc) XFreeGC(dpy, gc);
        gc = XCreateGC(dpy, win, 0, NULL);
        if (!gc) return;
        
        fg = BlackPixel(dpy, screen);
        bg = WhitePixel(dpy, screen);
        /* Set default background to match Viola widget's LightSteelBlue4 */
        set_color(&bg, "LightSteelBlue4");

        setup_backbuf();
        redraw();
    } else if (!strcmp(cmd, "domain")) {
        char *sx1 = strtok(NULL," \t");
        char *sx2 = strtok(NULL," \t");
        char *sy1 = strtok(NULL," \t");
        char *sy2 = strtok(NULL," \t");
        if (sx1 && sx2 && sy1 && sy2) {
            domain_x1 = atof(sx1);
            domain_x2 = atof(sx2);
            domain_y1 = atof(sy1);
            domain_y2 = atof(sy2);
        }
    } else if (!strcmp(cmd, "interval")) {
        char *sv = strtok(NULL," \t");
        if (sv) interval = atof(sv);
        if (interval <= 0) interval = 0.1;
    } else if (!strcmp(cmd, "equation")) {
        // Get the rest of the line as equation (find "equation" in original line)
        char *eq = strstr(line, "equation");
        if (eq) {
            eq += 8; // skip "equation"
            while (*eq && isspace((unsigned char)*eq)) eq++;
            if (*eq) {
                strncpy(equation, eq, sizeof(equation)-1);
                equation[sizeof(equation)-1] = '\0';
                /* Switch from model to equation mode */
                clear_model();
            }
        }
    } else if (!strcmp(cmd, "bgcolor")) {
        /* Ignore bgcolor - use Viola widget's LightSteelBlue4 background */
        /* This matches the original appearance in plot.gif */
        (void)0;
    } else if (!strcmp(cmd, "fgcolor")) {
        char *name = strtok(NULL, "");
        if (name && dpy && win) {
            while (*name==' ') name++;
            set_color(&fg, name);
        }
    } else if (!strcmp(cmd, "cx")) {
        char *sv = strtok(NULL," \t"); 
        if (sv) cam_x = atof(sv);
        redraw();
    } else if (!strcmp(cmd, "cy")) {
        char *sv = strtok(NULL," \t"); 
        if (sv) cam_y = atof(sv);
        redraw();
    } else if (!strcmp(cmd, "cz")) {
        char *sv = strtok(NULL," \t"); 
        if (sv) cam_z = atof(sv);
        redraw();
    } else if (!strcmp(cmd, "expose")) {
        redraw();
    } else if (!strcmp(cmd, "mbuf")) {
        char *sv = strtok(NULL," \t");
        if (sv) {
            use_backbuf = !strcmp(sv, "on");
            if (use_backbuf && dpy && win && !backbuf) {
                setup_backbuf();
            }
        }
    } else if (!strcmp(cmd, "quit")) {
        if (backbuf) XFreePixmap(dpy, backbuf);
        if (gc) XFreeGC(dpy, gc);
        if (dpy) XCloseDisplay(dpy);
        exit(0);
    } else if (!strcmp(cmd, "file")) {
        char *path = strtok(NULL, " \t\n\r");
        if (path) {
            char resolved_path[1024];
            
            /* If path starts with /off/ or doesn't exist, try relative to vplot */
            if (strncmp(path, "/off/", 5) == 0 || access(path, R_OK) != 0) {
#ifdef __APPLE__
                /* Get path to this executable (macOS) */
                char exe_path[1024];
                uint32_t size = sizeof(exe_path);
                if (_NSGetExecutablePath(exe_path, &size) == 0) {
                    char *exe_dir = dirname(exe_path);
                    /* Models are in off/ subdirectory next to vplot */
                    if (strncmp(path, "/off/", 5) == 0) {
                        snprintf(resolved_path, sizeof(resolved_path), "%s/off/%s", exe_dir, path + 5);
                    } else {
                        snprintf(resolved_path, sizeof(resolved_path), "%s/%s", exe_dir, path);
                    }
                    path = resolved_path;
                }
#else
                /* On Linux, try /proc/self/exe */
                char exe_path[1024];
                ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
                if (len > 0) {
                    exe_path[len] = '\0';
                    char *slash = strrchr(exe_path, '/');
                    if (slash) *slash = '\0';
                    if (strncmp(path, "/off/", 5) == 0) {
                        snprintf(resolved_path, sizeof(resolved_path), "%s/off/%s", exe_path, path + 5);
                    } else {
                        snprintf(resolved_path, sizeof(resolved_path), "%s/%s", exe_path, path);
                    }
                    path = resolved_path;
                }
#endif
            }
            
            logmsg("vplot: loading model '%s'\n", path);
            if (load_off_model(path)) {
                redraw();
            }
        }
    } else if (!strcmp(cmd, "record") || !strcmp(cmd, "clear") || !strcmp(cmd, "replay")) {
        // These are handled by plot.v, ignore here
    }
}

int main(void) {
    char buf[1024];
    char *display_env;
    
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    
    display_env = getenv("DISPLAY");
    logmsg("vplot started, DISPLAY='%s'\n", display_env ? display_env : "(null)");
    
    while (fgets(buf, sizeof(buf), stdin)) {
        logmsg("vplot: received: '%s'\n", buf);
        handle_cmd(buf);
    }
    
    logmsg("vplot: EOF, exiting\n");
    if (backbuf) XFreePixmap(dpy, backbuf);
    if (gc) XFreeGC(dpy, gc);
    if (dpy) XCloseDisplay(dpy);
    if (logfp) fclose(logfp);
    return 0;
}
