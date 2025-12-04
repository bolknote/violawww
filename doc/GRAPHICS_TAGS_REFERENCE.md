# ViolaWWW Experimental 3D Graphics Tags

This document describes the experimental 3D graphics tags implemented in ViolaWWW based on Pei-Yuan Wei's 1994 proto-VRML proposal.

---

## Historical Context

In 1994, Pei-Yuan Wei independently drafted a proposal for integrating 3D graphics directly into HTML using SGML-based tags. This was a **proto-VRML concept** — developed around the same time as, but independently from, the VRML (Virtual Reality Modeling Language) specification that emerged from the WWW community.

Wei's approach differed from what became VRML 1.0:
- **SGML-based syntax** — designed to blend seamlessly with HTML
- **Scriptable via Viola language** — not a separate scripting layer
- **Multi-user synchronization** — object state changes broadcast to all viewers (the `SC` attribute)

The original design document is preserved at:
- [vrmlNotes.txt](https://web.archive.org/web/20040519161530/http://www.xcf.berkeley.edu/~wei/viola/dev/vrmlNotes.txt)

The list of new tags added to the stylesheet:
- [new tags file](https://web.archive.org/web/20040420173124/http://www.xcf.berkeley.edu/~wei/viola/new)

### Timeline

| Date | Event |
|------|-------|
| 1994 | Pei Wei drafts SGML-based 3D graphics proposal |
| May 1994 | First VRML specification draft (Mark Pesce, Tony Parisi) |
| Nov 1994 | VRML 1.0 released (based on SGI's Open Inventor format) |
| 1997 | VRML 2.0 / VRML97 standardized |
| 2025 | Graphics tags implemented in this ViolaWWW restoration |

Wei's proposal was an independent parallel effort, not an implementation of VRML.

---

## Implementation Status

| Feature | Status |
|---------|--------|
| Container (`<GRAPHICS>`) | ✅ Implemented |
| Primitives (RECT, CIRCLE, OVAL, LINE, POLYGON) | ✅ Implemented |
| Position (`<POS>`) | ✅ Implemented |
| Size (`<SIZE>`) | ✅ Implemented |
| Colors (FGCOLOR, BGCOLOR, BDCOLOR) | ✅ Implemented |
| 2D Rotation (`<ROT Z=...>`) | ✅ Implemented |
| 3D Rotation (`<ROT X=...>`, `<ROT Y=...>`) | ✅ Implemented with perspective |
| Scale (`<SCALE>`) | ✅ Implemented |
| Axis (`<AXIS>`) | ✅ Implemented |
| Interactive scripting (`<ACTION>`, `<BUTTON>`) | ❌ Not implemented |
| Multi-user sync (`SC` attribute) | ❌ Not implemented |

---

## Tag Reference

### Container

#### `<GRAPHICS>`
Container element for a 2D/3D graphics scene.

| Attribute | Type | Description |
|-----------|------|-------------|
| `WIDTH` | integer | Scene width in pixels |
| `HEIGHT` | integer | Scene height in pixels |
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

**Example:**
```html
<GRAPHICS WIDTH=300 HEIGHT=200>
  <BGCOLOR NAME="black"></BGCOLOR>
  <RECT ID="r1">
    <POS X=50 Y=50></POS>
    <SIZE X=100 Y=80></SIZE>
    <FGCOLOR NAME="red"></FGCOLOR>
  </RECT>
</GRAPHICS>
```

---

### Geometric Primitives

#### `<RECT>`
A rectangle shape.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

**Example:**
```html
<RECT ID="myRect">
  <POS X=10 Y=10></POS>
  <SIZE X=80 Y=60></SIZE>
  <FGCOLOR NAME="blue"></FGCOLOR>
  <BDCOLOR NAME="red"></BDCOLOR>
</RECT>
```

#### `<CIRCLE>`
A circle shape (equal width and height).

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

**Example:**
```html
<CIRCLE ID="c1">
  <POS X=100 Y=50></POS>
  <SIZE X=60 Y=60></SIZE>
  <FGCOLOR NAME="green"></FGCOLOR>
</CIRCLE>
```

#### `<OVAL>`
An ellipse/oval shape.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

**Example:**
```html
<OVAL ID="o1">
  <POS X=50 Y=30></POS>
  <SIZE X=100 Y=50></SIZE>
  <FGCOLOR NAME="purple"></FGCOLOR>
</OVAL>
```

#### `<LINE>`
A line segment from (X,Y) to (X+W, Y+H).

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

**Example:**
```html
<LINE ID="l1">
  <POS X=10 Y=10></POS>
  <SIZE X=100 Y=50></SIZE>
  <FGCOLOR NAME="white"></FGCOLOR>
</LINE>
```

#### `<POLYGON>`
A polygon defined by multiple `<POINT>` children.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

**Example (triangle):**
```html
<POLYGON ID="tri">
  <FGCOLOR NAME="yellow"></FGCOLOR>
  <POINT X=50 Y=100></POINT>
  <POINT X=100 Y=20></POINT>
  <POINT X=150 Y=100></POINT>
</POLYGON>
```

#### `<POINT>`
A point defining a polygon vertex.

| Attribute | Type | Description |
|-----------|------|-------------|
| `X` | number | X coordinate |
| `Y` | number | Y coordinate |

---

### Transformations

#### `<POS>`
Position/translation of an object.

| Attribute | Type | Description |
|-----------|------|-------------|
| `X` | number | X position |
| `Y` | number | Y position |
| `Z` | number | Z position (depth) — not used in 2D |

**Example:**
```html
<POS X=60 Y=40></POS>
```

#### `<SIZE>`
Size/dimensions of an object.

| Attribute | Type | Description |
|-----------|------|-------------|
| `X` | number | Width |
| `Y` | number | Height |
| `Z` | number | Depth — not used in 2D |

**Example:**
```html
<SIZE X=100 Y=80></SIZE>
```

#### `<ROT>`
Rotation of an object in 3D space with perspective projection.

| Attribute | Type | Description |
|-----------|------|-------------|
| `X` | number | Rotation around X axis (tilt forward/back) |
| `Y` | number | Rotation around Y axis (turn left/right) |
| `Z` | number | Rotation around Z axis (2D rotation) |

**Examples:**
```html
<!-- 2D rotation: 45 degrees clockwise -->
<ROT Z=45></ROT>

<!-- 3D tilt forward -->
<ROT X=30></ROT>

<!-- 3D turn right -->
<ROT Y=45></ROT>

<!-- Combined 3D rotation -->
<ROT X=20 Y=30 Z=15></ROT>
```

#### `<SCALE>`
Scale transformation.

| Attribute | Type | Description |
|-----------|------|-------------|
| `X` | number | X scale factor (default 1.0) |
| `Y` | number | Y scale factor (default 1.0) |
| `Z` | number | Z scale factor for perspective |

**Examples:**
```html
<!-- Scale to half size -->
<SCALE X=0.5 Y=0.5></SCALE>

<!-- Scale to double size -->
<SCALE X=2 Y=2></SCALE>

<!-- Non-uniform scale -->
<SCALE X=1.5 Y=0.8></SCALE>
```

#### `<AXIS>`
Defines the center point for rotation and scaling.

| Attribute | Type | Description |
|-----------|------|-------------|
| `X` | number | X coordinate of axis center |
| `Y` | number | Y coordinate of axis center |
| `Z` | number | Z coordinate of axis center |

By default, transformations use the center of the shape. Use `<AXIS>` to change the pivot point.

---

### Appearance

#### `<FGCOLOR>`
Foreground/fill color.

| Attribute | Type | Description |
|-----------|------|-------------|
| `NAME` | string | Named color (e.g., "blue", "red") |
| `RGB` | string | RGB color value |

**Example:**
```html
<FGCOLOR NAME="blue"></FGCOLOR>
```

#### `<BGCOLOR>`
Background color of the GRAPHICS container.

| Attribute | Type | Description |
|-----------|------|-------------|
| `NAME` | string | Named color |
| `RGB` | string | RGB color value |

**Example:**
```html
<BGCOLOR NAME="black"></BGCOLOR>
```

#### `<BDCOLOR>`
Border color of a shape.

| Attribute | Type | Description |
|-----------|------|-------------|
| `NAME` | string | Named color |
| `RGB` | string | RGB color value |

**Example:**
```html
<BDCOLOR NAME="red"></BDCOLOR>
```

---

## Complete Examples

### Basic Shapes

```html
<GRAPHICS WIDTH=400 HEIGHT=120>
<BGCOLOR NAME="lightgray"></BGCOLOR>

<RECT ID="rect1">
  <POS X=10 Y=20></POS>
  <SIZE X=70 Y=70></SIZE>
  <FGCOLOR NAME="blue"></FGCOLOR>
</RECT>

<CIRCLE ID="circle1">
  <POS X=100 Y=20></POS>
  <SIZE X=70 Y=70></SIZE>
  <FGCOLOR NAME="red"></FGCOLOR>
</CIRCLE>

<OVAL ID="oval1">
  <POS X=190 Y=30></POS>
  <SIZE X=90 Y=50></SIZE>
  <FGCOLOR NAME="green"></FGCOLOR>
</OVAL>

<LINE ID="line1">
  <POS X=300 Y=20></POS>
  <SIZE X=80 Y=70></SIZE>
  <FGCOLOR NAME="purple"></FGCOLOR>
</LINE>

</GRAPHICS>
```

### 3D Rotation Demo

```html
<GRAPHICS WIDTH=400 HEIGHT=120>
<BGCOLOR NAME="navy"></BGCOLOR>

<!-- No rotation -->
<RECT ID="r1">
  <POS X=30 Y=20></POS>
  <SIZE X=60 Y=80></SIZE>
  <FGCOLOR NAME="cyan"></FGCOLOR>
</RECT>

<!-- Tilted forward (ROT X) -->
<RECT ID="r2">
  <POS X=120 Y=20></POS>
  <SIZE X=60 Y=80></SIZE>
  <FGCOLOR NAME="cyan"></FGCOLOR>
  <ROT X=45></ROT>
</RECT>

<!-- Turned right (ROT Y) -->
<RECT ID="r3">
  <POS X=210 Y=20></POS>
  <SIZE X=60 Y=80></SIZE>
  <FGCOLOR NAME="cyan"></FGCOLOR>
  <ROT Y=45></ROT>
</RECT>

<!-- 2D rotation (ROT Z) -->
<RECT ID="r4">
  <POS X=300 Y=20></POS>
  <SIZE X=60 Y=80></SIZE>
  <FGCOLOR NAME="cyan"></FGCOLOR>
  <ROT Z=45></ROT>
</RECT>

</GRAPHICS>
```

### Scene Composition (House)

```html
<GRAPHICS WIDTH=300 HEIGHT=200>
<BGCOLOR NAME="skyblue"></BGCOLOR>

<!-- Grass -->
<RECT ID="grass">
  <POS X=0 Y=150></POS>
  <SIZE X=300 Y=50></SIZE>
  <FGCOLOR NAME="green"></FGCOLOR>
</RECT>

<!-- House body -->
<RECT ID="house">
  <POS X=80 Y=80></POS>
  <SIZE X=140 Y=100></SIZE>
  <FGCOLOR NAME="brown"></FGCOLOR>
</RECT>

<!-- Roof (triangle) -->
<POLYGON ID="roof">
  <FGCOLOR NAME="red"></FGCOLOR>
  <POINT X=60 Y=80></POINT>
  <POINT X=150 Y=20></POINT>
  <POINT X=240 Y=80></POINT>
</POLYGON>

<!-- Door -->
<RECT ID="door">
  <POS X=130 Y=120></POS>
  <SIZE X=40 Y=60></SIZE>
  <FGCOLOR NAME="saddlebrown"></FGCOLOR>
</RECT>

<!-- Windows -->
<RECT ID="window1">
  <POS X=95 Y=100></POS>
  <SIZE X=25 Y=25></SIZE>
  <FGCOLOR NAME="lightblue"></FGCOLOR>
</RECT>

<RECT ID="window2">
  <POS X=180 Y=100></POS>
  <SIZE X=25 Y=25></SIZE>
  <FGCOLOR NAME="lightblue"></FGCOLOR>
</RECT>

<!-- Sun -->
<CIRCLE ID="sun">
  <POS X=240 Y=10></POS>
  <SIZE X=40 Y=40></SIZE>
  <FGCOLOR NAME="yellow"></FGCOLOR>
</CIRCLE>

</GRAPHICS>
```

---

## Not Implemented

The following features from the original design are **not implemented**:

### Interactive Scripting

The `<ACTION>`, `<BUTTON>`, and inline `<SCRIPT TYPE="viola">` tags are not implemented. The original design proposed:

```html
<!-- NOT IMPLEMENTED -->
<BUTTON ID="btn">
  <ACTION>
    <SCRIPT TYPE="viola">
      switch (arg[0]) {
      case "buttonUp":
        send("#sq1", "closer");
      break;
      }
    </SCRIPT>
  </ACTION>
  <LABEL>Click Me</LABEL>
</BUTTON>
```

### Multi-User Synchronization

The `SC` attribute for broadcasting state changes to other viewers is not implemented.

### Other Tags

- `<HINT>` — tooltip text
- `<TEXT>` — text within graphics
- `<SQUARE>` — use `<RECT>` with equal width/height instead

---

## Source Code References

- **DTD definitions:** `src/libWWW/HTMLDTD.c`
- **Element enum:** `src/libWWW/HTMLDTD.h`
- **Stylesheet mapping:** `src/viola/HTML_style.c`
- **Graphics container:** `src/viola/embeds/HTML_graphics_script.v`
- **Primitives:** `src/viola/embeds/HTML_rect_script.v`, `HTML_circle_script.v`, etc.

---

## See Also

- [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md) — The scripting language
- [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md) — 2D image embedding
- [COLOR_REFERENCE.md](COLOR_REFERENCE.md) — Available color names
- [vrmlNotes.txt (archive.org)](https://web.archive.org/web/20040519161530/http://www.xcf.berkeley.edu/~wei/viola/dev/vrmlNotes.txt) — Original design document
