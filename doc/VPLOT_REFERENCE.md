# VPlot Reference

> **Added in: ViolaWWW 4.0**  
> VPlot is a reverse-engineered reimplementation created in 2025.

**VPlot** is a 3D surface plotter and wireframe model viewer for ViolaWWW. It renders interactive 3D graphics in an embedded X11 window, controlled via the TTY class.

## Historical Context

VPlot is a reverse-engineered reimplementation of the original V-Plot utility written by Scott Silvey in the early 1990s. The original V-Plot was an external X11 program that ViolaWWW communicated with via pseudo-terminal (TTY class) to render 3D graphics in an embedded window. The original binary was lost; this reimplementation was created for ViolaWWW 4.0 based on analysis of the Viola scripts and available documentation.

<img width="636" height="853" src="https://github.com/user-attachments/assets/ec039340-ec27-4a14-96a1-37bd4ee0116d" />

## Architecture

```
┌─────────────────────────────────────────┐
│              ViolaWWW                   │
│  ┌─────────────────────────────────┐    │
│  │         plot.v widget           │    │
│  │  ┌───────────┐ ┌─────────────┐  │    │
│  │  │  Canvas   │ │  Controls   │  │    │
│  │  │  (field)  │ │  (sliders)  │  │    │
│  │  └─────┬─────┘ └──────┬──────┘  │    │
│  │        │              │         │    │
│  │        └──────┬───────┘         │    │
│  │               │                 │    │
│  │         ┌─────▼─────┐           │    │
│  │         │ TTY class │           │    │
│  │         └─────┬─────┘           │    │
│  └───────────────┼─────────────────┘    │
└──────────────────┼──────────────────────┘
                   │ stdin/stdout
            ┌──────▼──────┐
            │   vplot     │
            │  (X11 app)  │
            └─────────────┘
```

## Commands

VPlot reads commands from stdin, one per line. Commands are case-sensitive.

### Window Setup

| Command | Description |
|---------|-------------|
| `window <wid> <width> <height>` | Set target X11 window ID and dimensions |

The window ID is obtained from the Viola widget's `window` property. VPlot renders directly into this window, embedding 3D graphics within the browser.

**Example:**
```
window 0x1234567 400 300
```

### Domain and Grid

| Command | Description |
|---------|-------------|
| `domain <x1> <x2> <y1> <y2>` | Set the X/Y domain for equation plotting |
| `interval <step>` | Set grid step size for equation surface |

**Example:**
```
domain -2 2 -2 2
interval 0.2
```

### Equation Plotting

| Command | Description |
|---------|-------------|
| `equation <expr>` | Set z=f(x,y) equation to plot as a 3D surface |

#### Supported Functions

| Function | Description |
|----------|-------------|
| `sin(x)` | Sine |
| `cos(x)` | Cosine |
| `exp(x)` | Exponential (e^x) |
| `sqrt(x)` | Square root (uses absolute value) |
| `abs(x)` | Absolute value |

#### Supported Operators

| Operator | Description |
|----------|-------------|
| `+` `-` | Addition, subtraction |
| `*` `/` | Multiplication, division |
| `^` | Exponentiation |

#### Variables

- `x` — X coordinate
- `y` — Y coordinate

**Examples:**
```
equation sin(x * y)
equation 0.4 * sin(1 - x*x - y*y)
equation 0.4 * exp(1 - x*x - y*y) * sin(1 - x^4 - y^4)
```

### 3D Model Loading

| Command | Description |
|---------|-------------|
| `file <path>` | Load a 3D model in OFF format |

VPlot supports the standard OFF (Object File Format) for 3D meshes. Models are automatically normalized to fit the view.

**Path Resolution:**
- Absolute paths are used as-is
- Paths starting with `/off/` are resolved relative to the vplot executable directory
- If a path doesn't exist, vplot tries to find it relative to its own location

**Example:**
```
file /off/x29.geom
file /Users/me/models/cube.off
```

### Camera Control

| Command | Description |
|---------|-------------|
| `cx <value>` | Set camera X rotation (0-20, maps to ±180°) |
| `cy <value>` | Set camera Y rotation |
| `cz <value>` | Set camera Z rotation |

The rotation values use a 0-20 scale where 10 is neutral (0°), 0 is -180°, and 20 is +180°. This maps to slider positions in the Viola widget.

**Example:**
```
cx 15
cy 10
cz 5
```

### Colors

| Command | Description |
|---------|-------------|
| `bgcolor <color>` | Set background color (currently ignored, uses widget default) |
| `fgcolor <color>` | Set foreground/line color |

Colors are specified as X11 color names (e.g., `black`, `white`, `yellow`, `LemonChiffon1`).

**Example:**
```
fgcolor yellow
```

### Display Control

| Command | Description |
|---------|-------------|
| `expose` | Force redraw |
| `mbuf on\|off` | Enable/disable double buffering |
| `quit` | Exit the program |

Double buffering (`mbuf on`) reduces flicker during animation.

---

## OFF File Format

VPlot supports the standard OFF (Object File Format) for 3D polygon meshes.

### Format Structure

```
OFF
<num_vertices> <num_faces> <num_edges>
<vertex 0: x y z>
<vertex 1: x y z>
...
<face 0: n v1 v2 ... vn>
<face 1: n v1 v2 ... vn>
...
```

### Example OFF File

```off
OFF
8 6 0
# Cube vertices
-1 -1 -1
 1 -1 -1
 1  1 -1
-1  1 -1
-1 -1  1
 1 -1  1
 1  1  1
-1  1  1
# Cube faces (6 quads)
4 0 1 2 3
4 7 6 5 4
4 0 4 5 1
4 1 5 6 2
4 2 6 7 3
4 3 7 4 0
```

### Notes

- The `OFF` header line is optional
- Comments starting with `#` are allowed anywhere
- Empty lines are skipped
- The edge count (third number) is typically ignored
- Face vertex indices are 0-based
- Faces can have 3-31 vertices (triangles, quads, polygons)

### Included Models

The `vplot_dir/off/` directory contains sample models:

| File | Description |
|------|-------------|
| `x29.geom` | X-29 forward-swept wing experimental aircraft (Grumman) |
| `TomCat` | F-14 Tomcat fighter jet |

---

## Viola Integration

### Environment Setup

Set the `PLOT_PATH` environment variable to the vplot directory:

```bash
export PLOT_PATH="/path/to/vplot_dir"
```

The directory should contain:
- `vplot` — the vplot binary
- `off/` — subdirectory with OFF model files

### Example Widget (plot.v)

The `examples/plot.v` file provides a complete interactive widget with:

- **Canvas** — X11 window for 3D rendering
- **Menu** — preset equations and models
- **Sliders** — real-time camera rotation control
- **Recording** — capture and replay rotation sequences

#### Basic Structure

```
\class {vpane}
\name {plot}
\children {plot.TTY plot.head plot.body plot.cmd}
```

#### TTY Configuration

```
\class {TTY}
\name {plot.TTY}
\script {
    switch (arg[0]) {
    case "init":
        PLOT_PATH = environVar("PLOT_PATH");
        set("path", concat(PLOT_PATH, "/vplot"));
        initialize();
        set("inDelimStr1", "\n");
        set("inDelimStr2", "\r");
        set("outDelimStr", "\n");
        startClient();
        return;
    break;
    ...
    }
}
```

#### Sending Commands

```
TTYObj = send(parent(), "TTYObjP");
send(TTYObj, "output", "domain -2 2 -2 2");
send(TTYObj, "output", "interval .2");
send(TTYObj, "output", "equation sin(x * y)");
send(TTYObj, "output", "expose");
```

#### Slider-to-Camera Binding

```
\class {slider}
\name {plot.body.ctrl.cam.x}
\script {
    switch (arg[0]) {
    case "_shownPositionV":
        send(TTYObj, "cx", arg[1]);
    break;
    }
}
```

---

## HiDPI Support

VPlot automatically detects HiDPI/Retina displays and scales rendering:

1. **macOS**: Defaults to 2x scale for Retina displays
2. **Xft.dpi**: Reads X11 DPI setting if available
3. **Environment**: Override with `VPLOT_SCALE` environment variable

```bash
export VPLOT_SCALE=1.5
```

---

## Building

VPlot is built as part of the main ViolaWWW build:

```bash
make
```

Or build standalone:

```bash
cd src/vplot
cc -o vplot vplot.c -I/opt/X11/include -L/opt/X11/lib -lX11 -lm
```

---

## See Also

- [TTY_REFERENCE.md](TTY_REFERENCE.md) — TTY class for external process communication
- [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md) — Viola scripting language reference

