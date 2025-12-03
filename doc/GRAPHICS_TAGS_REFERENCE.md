# ViolaWWW Experimental 3D Graphics Tags

This document describes experimental 3D graphics tags that were designed for ViolaWWW but **never fully implemented**. These tags are defined in the DTD and parsed by the browser, but their content is ignored.

⚠️ **Note:** This is a historical document. None of these tags produce any visual output.

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

Wei's proposal was an independent parallel effort, not an implementation of VRML.

---

## Implementation Status

All 18 graphics-related tags are:
- ✅ **Defined in DTD** (`src/libWWW/HTMLDTD.c`, `HTMLDTD.h`)
- ✅ **Parsed by SGML parser** (attributes extracted correctly)
- ❌ **Not rendered** — all mapped to `HTML_ignore` in `src/viola/HTML_style.c`

In the source code, these tags are marked with `/*vr exp*/` comments (VR experimental):

```
AXIS        HTML_ignore     1 0 0 0 0       0 0 0 0
BDCOLOR     HTML_ignore     1 0 0 0 0       0 0 0 0
BGCOLOR     HTML_ignore     1 0 0 0 0       0 0 0 0
BUTTON      HTML_ignore     1 0 0 0 0       0 0 0 0
CIRCLE      HTML_ignore     1 0 0 0 0       0 0 0 0
FGCOLOR     HTML_ignore     1 0 0 0 0       0 0 0 0
GRAPHICS    HTML_ignore     1 0 0 0 0       0 0 0 0
HINT        HTML_ignore     1 0 0 0 0       0 0 0 0
LINE        HTML_ignore     1 0 0 0 0       0 0 0 0
OVAL        HTML_ignore     1 0 0 0 0       0 0 0 0
POINT       HTML_ignore     1 0 0 0 0       0 0 0 0
POLYGON     HTML_ignore     1 0 0 0 0       0 0 0 0
POS         HTML_ignore     1 0 0 0 0       0 0 0 0
RECT        HTML_ignore     1 0 0 0 0       0 0 0 0
ROT         HTML_ignore     1 0 0 0 0       0 0 0 0
SCALE       HTML_ignore     1 0 0 0 0       0 0 0 0
SIZE        HTML_ignore     1 0 0 0 0       0 0 0 0
TEXT        HTML_ignore     1 0 0 0 0       0 0 0 0
```

---

## Tag Reference

### Container

#### `<GRAPHICS>`
Container element for a 3D graphics scene.

| Attribute | Type | Description |
|-----------|------|-------------|
| `WIDTH` | integer | Scene width in pixels |
| `HEIGHT` | integer | Scene height in pixels |
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

**Example from design document:**
```html
<GRAPHICS width=100 height=100>
  <SQUARE ID="sq1">
    ...
  </SQUARE>
</GRAPHICS>
```

---

### Geometric Primitives

#### `<CIRCLE>`
A circle shape.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

#### `<OVAL>`
An ellipse/oval shape.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

#### `<RECT>`
A rectangle shape.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

#### `<SQUARE>`
A square shape.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

#### `<LINE>`
A line segment.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

#### `<POINT>`
A point in 2D space.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `X` | number | X coordinate |
| `Y` | number | Y coordinate |

#### `<POLYGON>`
A polygon defined by multiple points.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier |
| `NAME` | string | Object name |

---

### Transformations

These tags define 3D transformations with X, Y, Z coordinates and the special `SC` attribute.

#### The `SC` Attribute

From the design document:
> "The SC attribute says that whenever the attributes in this object changes, relay the change to a server that broadcasts the change to all other browsers looking at this object..."

This was intended for **multi-user synchronization** — a remarkably forward-thinking feature for 1994, predating WebSockets by over 15 years.

#### `<POS>`
Position/translation of an object.

| Attribute | Type | Description |
|-----------|------|-------------|
| `SC` | flag | Sync changes to server |
| `X` | number | X position |
| `Y` | number | Y position |
| `Z` | number | Z position (depth) |

**Example:**
```html
<POS SC x=60 y=40>
```

#### `<SIZE>`
Size/dimensions of an object.

| Attribute | Type | Description |
|-----------|------|-------------|
| `SC` | flag | Sync changes to server |
| `X` | number | Width |
| `Y` | number | Height |
| `Z` | number | Depth |

**Example:**
```html
<SIZE SC x=20 y=20>
```

#### `<ROT>`
Rotation of an object.

| Attribute | Type | Description |
|-----------|------|-------------|
| `SC` | flag | Sync changes to server |
| `X` | number | Rotation around X axis |
| `Y` | number | Rotation around Y axis |
| `Z` | number | Rotation around Z axis |

**Example:**
```html
<ROT SC>
```

#### `<SCALE>`
Scale transformation.

| Attribute | Type | Description |
|-----------|------|-------------|
| `SC` | flag | Sync changes to server |
| `X` | number | X scale factor |
| `Y` | number | Y scale factor |
| `Z` | number | Z scale factor |

**Example from design:**
```html
<SCALE x=1 y=1 z=1.5>
```

#### `<AXIS>`
Defines an axis (possibly for rotation reference). No attributes defined.

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
<FGCOLOR name="blue">
```

#### `<BGCOLOR>`
Background color.

| Attribute | Type | Description |
|-----------|------|-------------|
| `NAME` | string | Named color |
| `RGB` | string | RGB color value |

#### `<BDCOLOR>`
Border color.

| Attribute | Type | Description |
|-----------|------|-------------|
| `NAME` | string | Named color |
| `RGB` | string | RGB color value |

**Example:**
```html
<BDCOLOR name="red">
```

---

### Interactivity

#### `<BUTTON>`
An interactive button element.

| Attribute | Type | Description |
|-----------|------|-------------|
| `ID` | string | Unique identifier for targeting |
| `HREF` | URL | Link destination |
| `NAME` | string | Button name |

**Example from design:**
```html
<BUTTON ID="btn_closer">
  <ACTION>
    <SCRIPT TYPE="viola">
      switch (arg[0]) {
      case "buttonUp":
        send("#sq1", "closer");
      break;
      }
      usual();
    </SCRIPT>
  </ACTION>
  <POS SC x=10 y=5>
  <SIZE SC x=30 y=15>
  <LABEL>Closer</LABEL>
</BUTTON>
```

#### `<HINT>`
Tooltip/hint text for an object. No attributes — content is the hint text.

**Example:**
```html
<HINT>Click on me, and I'll twist</HINT>
```

#### `<TEXT>`
Text element within graphics context. No attributes defined in DTD.

---

### Scripting (Also Unimplemented)

The design document proposed inline Viola scripting:

#### `<ACTION>`
Event handler container. Defined in DTD but mapped to `HTML_ignore`.

#### `<SCRIPT TYPE="viola">`
Inline Viola script. The `SCRIPT` tag exists in DTD with `SGML_CDATA` content model, but is mapped to `HTML_ignore`.

**Proposed syntax:**
```html
<ACTION>
  <SCRIPT TYPE="viola">
    switch (arg[0]) {
    case "buttonUp":
      for (i = 0; i < 30; i++) {
        rotate(0, 0, 1.0);
        render();
      }
      return;
    break;
    }
    usual();
  </SCRIPT>
</ACTION>
```

**Note:** While inline `<SCRIPT>` was never implemented, Viola scripting **does work** via external files using the `<VOBJF>` tag:
```html
<VOBJF HREF="widget.v"></VOBJF>
```

---

## Complete Example from Design Document

This example demonstrates the intended usage — a scene with a square that can be moved closer or farther by clicking buttons:

```html
<HTML>
<H1>A Revelation in Perspectives</H1>
<P>
Things look smaller when it's farther away, bigger when it's closer.

<GRAPHIC width=100 height=100>
<SQUARE ID="sq1">
  <ACTION>
    <ON ARG0="buttonUp">
      <REPEAT FROM=0 TO=30 INC=1><ROTATE x=0 y=0 z=1></REPEAT>
    </ON>
    <ON ARG0="shrink"><SCALE x=1 y=1 z=1.5></ON>
    <ON ARG0="expand"><SCALE x=1 y=1 z=0.5></ON>
  </ACTION>

  <POS SC x=60 y=40>
  <SIZE SC x=20 y=20>
  <ROT SC>
  <FGCOLOR name="blue">
  <BDCOLOR name="red">
  <HINT>Click on me, and I'll twist</HINT>
</SQUARE>

<BUTTON ID="btn_closer">
  <ACTION>
    <ON ARG0="buttonUp"><SEND DEST="#sq1" ARG0="closer"></ON>
  </ACTION>
  <POS SC x=10 y=5>
  <SIZE SC x=30 y=15>
  <LABEL>Closer</LABEL>
  <HINT>Bring the square closer to view</HINT>
</BUTTON>

<BUTTON ID="btn_farther">
  <ACTION>
    <SCRIPT TYPE="viola">
      switch (arg[0]) {
      case "buttonUp":
        send("#sq1", "farther");
      break;
      }
      usual();
    </SCRIPT>
  </ACTION>
  <POS SC x=40 y=5>
  <SIZE SC x=30 y=15>
  <LABEL>Further</LABEL>
  <HINT>Push the square further from view</HINT>
</BUTTON>

</GRAPHIC>
```

---

## Why It Was Never Completed

These experimental tags represent an ambitious vision from 1994:
- 3D graphics natively in HTML (before WebGL by ~17 years)
- Multi-user synchronization (before WebSockets)
- Declarative scene graphs (before Three.js, A-Frame)

However, ViolaWWW development slowed as:
1. NCSA Mosaic and later Netscape Navigator gained market dominance
2. The separate VRML specification (1994-1997) took a different, non-HTML approach
3. Resources were limited for a solo developer project

The DTD definitions remain as a historical record of an early, independent attempt to bring 3D graphics to the web.

---

## Source Code References

- **DTD definitions:** `src/libWWW/HTMLDTD.c` (lines 127-203, 358-463)
- **Element enum:** `src/libWWW/HTMLDTD.h` (marked with `/*vr exp*/` comments)
- **Stylesheet mapping:** `src/viola/HTML_style.c` (lines 150-169)

---

## See Also

- [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md) — The scripting language that would have powered these objects
- [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md) — 2D image embedding that *was* implemented
- [vrmlNotes.txt (archive.org)](https://web.archive.org/web/20040519161530/http://www.xcf.berkeley.edu/~wei/viola/dev/vrmlNotes.txt) — Original design document
