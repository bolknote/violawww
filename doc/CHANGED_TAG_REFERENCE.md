# CHANGED Tag Reference

## Overview

The `<CHANGED>` element is part of the **HTML+ specification** (1993-1994) designed by Dave Raggett. It provides a mechanism for marking document revisions with visual "change bars" — vertical lines in the margin indicating modified content.

ViolaWWW includes partial support for this tag (parsing only), but the visual change bars are not yet implemented.

---

## HTML+ Specification

### Syntax

```html
<changed id=z34>text including some changes<changed idref=z34>
```

The element uses **paired markers** instead of container tags:

| Attribute | Purpose |
|-----------|---------|
| `ID` | Signals **start** of changed region |
| `IDREF` | Signals **end** of changed region (references the ID) |

### Why Not a Container?

From the [HTML+ DTD](https://www.w3.org/MarkUp/HTMLPlus/htmlplusdtd.txt):

> "This tag can't act as a container, since changes don't respect the nesting implied by paragraphs, headers, lists etc."

Changes can span across structural boundaries:

```html
<p>Normal text. <changed id=c1>This was modified.</p>
<p>This entire paragraph is part of the change.</p>
<p>End of changes here.<changed idref=c1> Normal text.</p>
```

### Visual Rendering

According to [HTML+ Discussion Document, Section 5.10](https://www.w3.org/MarkUp/HTMLPlus/htmlplus_22.html):

> "Change bars are shown for parts of the document designated with the CHANGED element."

The intended visual appearance is a **vertical bar on the left margin**:

```
┌──────────────────────────────────────────────────┐
│ Normal text here.                                │
│                                                  │
│▌This paragraph contains some changed text that   │
│▌spans multiple lines and should display a        │
│▌change bar on the margin.                        │
│                                                  │
│ Another unchanged paragraph.                     │
└──────────────────────────────────────────────────┘
```

### Additional Attributes (Proposed)

The specification mentions optional attributes for richer metadata:

| Attribute | Purpose |
|-----------|---------|
| `BY` | Who made the change |
| `WHEN` | When the change was made |
| `WHY` | Reason for the change |
| `WHAT` | Description of the change |

These were never implemented in ViolaWWW.

### Related Tags

HTML+ also proposed `<REMOVED>` and `<ADDED>` for legislative documents:

```html
<p>This bill requires access by way of <removed>computer
modem</removed> <added>the largest nonproprietary, nonprofit 
cooperative public computer network,</added> specified information.</p>
```

Rendered as:
- `<removed>` — strikethrough text
- `<added>` — underlined text

These tags are **not implemented** in ViolaWWW.

---

## Current Implementation in ViolaWWW

### DTD Definition

**File:** `src/libWWW/HTMLDTD.c`

```c
static attr changed_attr[] = {{"ID"}, {"IDREF"}, {0}};

// In tags array:
{"CHANGED", changed_attr, HTML_CHANGED_ATTRIBUTES, SGML_EMPTY, 0, 0},
```

### Stylesheet Entry

**File:** `src/viola/HTML_style.c`

```
CHANGED		HTML_changed		0 0 0 0 0		0 0 0 0
```

| Field | Value | Meaning |
|-------|-------|---------|
| inline | 0 | Block element (causes line break) |
| margins | 0 0 0 0 | No margins |

### Object Definition

**File:** `src/viola/objs.c`

```c
static SlotStruct objDesc_HTML_changed[] = {
    {"class", "field"},
    {"name", "HTML_changed"},
    {"script", ...},
    {"BGColor", "LemonChiffon1"},
    {"BDColor", "LemonChiffon1"},
    {(char*)0, (char*)0},
};
```

### Script Handler

**File:** `src/viola/embeds/HTML_changed_script.v`

```viola
case "AA":  // Add Attribute
    switch (arg[1]) {
    case "ID":
    case "IDREF":
    break;  // Attributes are parsed but not used
    }
    return;
break;
```

### Current Behavior

1. **Tag is parsed** — no parsing errors
2. **Object is created** — 1×1 pixel, LemonChiffon1 color
3. **Attributes are ignored** — ID/IDREF not connected
4. **Text is "swallowed"** — block mode breaks text flow
5. **No change bars rendered** — visual feedback missing

---

## Implementation Plan

### Goal

Full implementation of change bars as specified in HTML+.

### Architecture

#### 1. Global Change Region Registry

**New file:** `src/viola/changeregions.c` / `.h`

```c
typedef struct _ChangeRegion {
    char *id;              // Region ID (e.g., "c1")
    VObj *startMarker;     // <changed id=c1> object
    VObj *endMarker;       // <changed idref=c1> object
    int startY;            // Y-coordinate of start (pixels)
    int endY;              // Y-coordinate of end
    int isOpen;            // 1 = not yet closed
    struct _ChangeRegion *next;
} ChangeRegion;

// API
void changeRegion_registerStart(char *id, VObj *marker);
void changeRegion_registerEnd(char *idref, VObj *marker);
ChangeRegion *changeRegion_findById(char *id);
void changeRegion_updatePositions(VObj *docRoot);
void changeRegion_render(Display *dpy, Window win, GC gc, int marginX);
void changeRegion_clear(void);
```

#### 2. Lifecycle

```
HTML Parsing
     │
     ▼
┌─────────────────────────────────────────────────────────┐
│ <changed id=c1>  →  changeRegion_registerStart("c1")    │
│                      creates ChangeRegion, isOpen=1     │
│                                                         │
│ ... text, paragraphs, lists ...                         │
│                                                         │
│ <changed idref=c1> → changeRegion_registerEnd("c1")     │
│                      finds region, sets isOpen=0        │
│                      links startMarker ↔ endMarker      │
└─────────────────────────────────────────────────────────┘
     │
     ▼
Layout Pass
     │
     ▼
┌─────────────────────────────────────────────────────────┐
│ changeRegion_updatePositions()                          │
│   - For each region, calculate startY and endY          │
│   - startY = startMarker->y                             │
│   - endY = endMarker->y + endMarker->height             │
└─────────────────────────────────────────────────────────┘
     │
     ▼
Rendering
     │
     ▼
┌─────────────────────────────────────────────────────────┐
│ changeRegion_render()                                   │
│   - For each closed region:                             │
│     XFillRectangle(dpy, win, gc,                        │
│                    marginX - 6, startY,                 │
│                    3, endY - startY);                   │
└─────────────────────────────────────────────────────────┘
```

### Required Changes

#### Step 1: Fix Stylesheet (Immediate)

**File:** `src/viola/HTML_style.c`

```c
// Change from block to inline:
CHANGED		HTML_changed		1 0 0 0 0		0 0 0 0
//                              ^ inline=1
```

This stops the tag from breaking text flow.

#### Step 2: Make Marker Invisible

**File:** `src/viola/objs.c`

```c
static SlotStruct objDesc_HTML_changed[] = {
    {"class", "field"},
    {"name", "HTML_changed"},
    {"script", ...},
    {"width", "0"},
    {"height", "0"},
    {"visible", "0"},
    {(char*)0, (char*)0},
};
```

#### Step 3: Implement Region Registry

Create `src/viola/changeregions.c` with:
- Hash table for ID → ChangeRegion mapping
- Registration functions for start/end markers
- Position calculation after layout
- Rendering function for change bars

#### Step 4: Update Script Handler

**File:** `src/viola/embeds/HTML_changed_script.v`

```viola
case "AA":
    switch (arg[1]) {
    case "ID":
        registerChangeStart(arg[2], self());
    break;
    case "IDREF":
        registerChangeEnd(arg[2], self());
    break;
    }
    return;
break;
```

#### Step 5: Integrate with Rendering

Modify document rendering to call `changeRegion_render()` after content is drawn.

#### Step 6: Handle Document Navigation

Clear change regions when loading a new document.

### Edge Cases

| Scenario | Handling |
|----------|----------|
| Unclosed `<changed id=X>` | Ignore during rendering (isOpen=1) |
| Multiple `<changed idref=X>` with same ID | Use first match |
| Scroll/resize | Recalculate Y positions |
| Nested frames | Scope to current document |

### Configuration

Add X11 resource for change bar color:

```
Viola.changeBarColor: LemonChiffon1
```

Or for a more traditional "revision mark" appearance:

```
Viola.changeBarColor: red
```

### Effort Estimate

| Task | Time |
|------|------|
| Create `changeregions.c/.h` | 2-3 hours |
| Integrate with parser (script) | 1 hour |
| Integrate with rendering | 2-3 hours |
| Handle scroll and resize | 1-2 hours |
| Testing and debugging | 2-3 hours |
| **Total** | **8-12 hours** |

---

## External References

### W3C HTML+ Documents

- [HTML+ DTD (November 1993)](https://www.w3.org/MarkUp/HTMLPlus/htmlplusdtd.txt) — Original DTD with CHANGED element definition
- [HTML+ Discussion Document, Section 5.10](https://www.w3.org/MarkUp/HTMLPlus/htmlplus_22.html) — Change Bars and Document Amendments
- [HTML+ DTD (April 1994)](https://www.w3.org/MarkUp/htmlplus_paper/htmlplus.dtd) — Updated DTD with "more meaningful attribute names"

### Historical Context

HTML+ was Dave Raggett's proposal to extend HTML with features for:
- Mathematical formulas (`<MATH>`)
- Tables (`<TABLE>`)
- Forms (`<FORM>`)
- Figures with captions (`<FIG>`)
- Change tracking (`<CHANGED>`, `<ADDED>`, `<REMOVED>`)

Many of these features were later incorporated into HTML 3.0 and subsequent versions, though change tracking was dropped in favor of external revision control systems.

---

## See Also

- [HMML_REFERENCE.md](HMML_REFERENCE.md) — ViolaWWW's alternative markup language
- [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md) — Another HTML+ feature implemented in ViolaWWW

