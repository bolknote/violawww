# CHANGED Tag Reference

> **Added in: ViolaWWW 4.0**  
> This documentation describes the HTML+ CHANGED element. The tag renders changed text with a **LemonChiffon1 background** to highlight modifications.

## Overview

The `<CHANGED>` element is part of the **HTML+ specification** (1993-1994) designed by Dave Raggett. It provides a mechanism for marking document revisions with visual "change bars" — vertical lines in the margin indicating modified content.

ViolaWWW implements this tag with yellow background highlighting (LemonChiffon1 color) instead of margin change bars.

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
CHANGED		HTML_changed		1 0 0 0 0		0 0 0 0
```

| Field | Value | Meaning |
|-------|-------|---------|
| inline | 1 | Inline element (flows with text) |
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

### Tag Processing

**File:** `src/viola/html2.c` (primary path for HTML documents)

```c
/* Handle CHANGED tag for highlighting */
if (element_number == HTML_CHANGED) {
    if (present && present[HTML_CHANGED_ID]) {
        /* Start marker - enter CHANGED region */
        SGMLBuildDoc_inChanged++;
    } else if (present && present[HTML_CHANGED_IDREF]) {
        /* End marker - leave CHANGED region */
        if (SGMLBuildDoc_inChanged > 0) SGMLBuildDoc_inChanged--;
    }
    return;
}
```

The `SGMLBuildDoc_inChanged` counter is managed directly in C code. When this counter is > 0, all text data is automatically wrapped in `\m(...\m)` escape sequences for rendering.

### Current Behavior

1. **Tag is parsed** — SGML_EMPTY mode with ID/IDREF attributes
2. **Inline markers** — `<changed id=X>` inserts `\m(`, `<changed idref=X>` inserts `\m)`
3. **Yellow background** — LemonChiffon1 highlight applied to text between markers
4. **Text color preserved** — original foreground color (from STG) is kept
5. **Paired markers** — ID opens region, IDREF closes it (as per HTML+ spec)

---

## Implementation Details

### Architecture

The implementation uses a global counter to track CHANGED regions across structural boundaries:

1. **`SGMLBuildDoc_inChanged`** — global depth counter for nested CHANGED regions
2. **Direct C handling** — counter incremented/decremented in `html2.c` when parsing `<changed id=X>` / `<changed idref=X>`
3. **Automatic wrapping** — when counter > 0, all text data is wrapped in `\m(...\m)` escape sequences
4. **MASK_MARKED flag** — stored per-character, triggers LemonChiffon1 background rendering

### Key Files Modified

| File | Change |
|------|--------|
| `src/viola/html2.c` | Handles CHANGED tag in `CB_HTML_stag()`; wraps text in `\m(...\m)` in `CB_HTML_data()` |
| `src/viola/sgml.c` | Added `SGMLBuildDoc_inChanged` counter; handles CHANGED for binary ESIS parser |
| `src/viola/sgml.h` | Added `extern int SGMLBuildDoc_inChanged` declaration |
| `src/viola/tfed.h` | Added `MASK_MARKED (1 << 9)` flag for marked text |
| `src/viola/tfed.c` | Added `\m(` / `\m)` escape code parsing and rendering with `gc_mark` |
| `src/viola/glib_x.c` | Added `gc_mark` graphics context with LemonChiffon1 color |
| `src/viola/glib_x.h` | Added `extern GC gc_mark` declaration |

### Rendering Flow

```
<changed id=c1>
        │
        ▼
  html2.c CB_HTML_stag(): SGMLBuildDoc_inChanged++
  (SGMLBuildDoc_inChanged = 1)
        │
        ▼
  <p>text in paragraph 1</p>
        │
        ▼
  html2.c CB_HTML_data(): wraps as "\m(text in paragraph 1\m)"
        │
        ▼
  <p>text in paragraph 2</p>
        │
        ▼
  html2.c CB_HTML_data(): wraps as "\m(text in paragraph 2\m)"
        │
        ▼
<changed idref=c1>
        │
        ▼
  html2.c CB_HTML_stag(): SGMLBuildDoc_inChanged--
  (SGMLBuildDoc_inChanged = 0)
        │
        ▼
  <p>normal text</p> — not wrapped
        │
        ▼
  tfed.c: parses \m( and \m), sets MASK_MARKED flag
        │
        ▼
  tfed.c: renders text with gc_mark (LemonChiffon1 background)
```

### Usage

The original HTML+ paired-marker syntax is now supported:

```html
<p>Normal text. <changed id=c1>This paragraph has changes.
The changes can span across multiple paragraphs.
<changed idref=c1> Back to normal text.</p>
```

### Limitations

- Multiple overlapping regions with different IDs are not tracked separately
- Change bars on margin are not implemented (background highlight only)

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

