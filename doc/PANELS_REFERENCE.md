# Panels and Column Layout Reference

> **Documentation created in: ViolaWWW 4.0**  
> This document describes the panel and column-layout facilities in ViolaWWW: the **HPANE** HTML tag, the **hpane** Viola widget class, **COL2/COL3/COL4** multi-column formatters, and the **LINK rel=sidebar** mechanism. It is based on the original ViolaWWW implementation, the Viola book, and archived examples.

## Contents

- [Overview](#overview)
- [HPANE — HTML Columns Formatter](#hpane--html-columns-formatter)
- [hpane — Viola Widget Class](#hpane--viola-widget-class)
- [COL2, COL3, COL4 — Multi-Column Formatters](#col2-col3-col4--multi-column-formatters)
- [LINK rel=sidebar — Document Sidebar Panel](#link-relsidebar--document-sidebar-panel)
- [Relationships with Other Tags](#relationships-with-other-tags)
- [Implementation Notes](#implementation-notes)
- [Example: testHPane.html](#example-testhpanhtml)
- [References](#references)

---

## Overview

ViolaWWW provides several mechanisms for organizing content into **panels** and **columns**:

| Mechanism | Type | Purpose |
|-----------|------|---------|
| **HPANE** | HTML tag | Block-level “columns formatter”: arrange child elements side-by-side (horizontal layout). Supports `ID`, `MAXWIDTH`, `MINWIDTH`. |
| **hpane** | Viola class | Horizontal pane widget (geometry manager). Default `westToEast`. Used for UI layout (toolbars, forms, sidebar, etc.). |
| **COL2, COL3, COL4** | HTML tags | Multi-column formatters (2, 3, or 4 columns). “Relic” per Viola book; implemented but less used. |
| **DIR** | HTML tag | Directory list; rendered via **HTML_col2** (two-column layout). |
| **LINK rel=sidebar** | HTML `<LINK>` | Declares a sidebar document. Browser shows main document plus a “Topics” navigation panel (e.g. TOC). |

The **HTML HPANE** tag is intended as a “geometry managing device” for side-by-side layout. The **Viola hpane** class is the underlying layout widget used both for HTML HPANE and for browser UI (sidebar, forms, toolbars).

---

## HPANE — HTML Columns Formatter

### Description

**HPANE** is an HTML extension that formats its children **horizontally** (side-by-side). The [Viola book chp11](https://web.archive.org/web/20040207185015id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp11_columns.html) describes it as a “simple way to format things side by side,” taking into account **max/min constraint parameters** that sub-elements may specify. It is “more of a geometry managing device than for tabulation” and “not a replacement for a real multiple-columns text flow,” but “simple and useful for many things.”

The [Viola htmlTags](https://web.archive.org/web/20040311113655id_/http://www.xcf.berkeley.edu/~wei/viola/book/htmlTags) page labels it as **columns formatter** and gives the stylesheet line:

```
HTML_hpane  0 0 0 1 1  0 0 0 0
```

### DTD and Attributes

**Content:** `SGML_MIXED` (text and nested tags).

**Attributes** (in `src/libWWW/HTMLDTD.c`):

| Attribute | Description | Handled in script? |
|-----------|-------------|--------------------|
| **ID** | Anchor identifier | ✅ `tagID = arg[2]` |
| **MAXWIDTH** | Maximum width (pixels) | ✅ `set("maxWidth", arg[2])` |
| **MINWIDTH** | Minimum width (pixels) | ✅ `set("minWidth", arg[2])` |
| **LEFT** | Left margin | ❌ Parsed only |
| **RIGHT** | Right margin | ❌ Parsed only |
| **CENTER** | Centering hint | ❌ Parsed only |
| **STYLE** | STG style reference | ❌ Parsed only |

Only **ID**, **MAXWIDTH**, and **MINWIDTH** are used in `HTML_hpane_script.v`. The rest exist in the DTD but have no effect.

### Stylesheet (HTML_style.c)

```
HPANE   HTML_hpane  0 0 0 1 1  0 0 0 0
```

- Block element (`inline=0`), `flushOnSubTag=1`, **hpane=1** (use horizontal-pane layout).
- Margins: `top=0`, `bottom=0`, `left=0`, `right=0`.

### Content and Layout

- **Text before first child tag** is accumulated as `label` (via `SGMLBuildDoc_setBuff`). On **flush** (`F`) and **display** (`D`), non-blank label is rendered as `HTML_txt` with **P** style and appended as a child.
- **Child elements** (e.g. `SECTION`, `FIGURE`, `P`) are laid out by the script. The *documentation* and examples (e.g. [testHPane.html](#example-testhpanhtml)) imply **horizontal** placement. The *current* `HTML_hpane_script` uses a vertical **r** / **R** layout protocol (stacking children top-to-bottom). See [Implementation Notes](#implementation-notes).

### Script Hooks

- **config**: No-op (geometry delegated to **R** / **r**).
- **F** (flush): Emit `label` as `HTML_txt` if present; return `-1`.
- **D**: Emit `label`, then compute height from children via **r**.
- **R**: Set position (`x`, `y`, `width`) from `style` and parent args; compute height from children **r**.
- **r**: Recursively layout children (**R**), accumulate height, return total.
- **AA** (attributes): Handle `ID`, `MAXWIDTH`, `MINWIDTH`.
- **searchAnchor** / **gotoAnchor**: Support fragment navigation by `ID`.
- **findTop** / **findForm**: Forward to parent.
- **init**: `usual()`, then `SGMLBuildDoc_setColors()`.

**Commented-out in script:** Application of STG colors (`BGColor`, `FGColor`, `BDColor`) from `STG_tagPtr("HPANE")`. Not active.

### STG Grouping

HPANE is often grouped with **BODY**, **INPUT**, and **P** for base styles, e.g.:

```
(BODY,HPANE,INPUT,P
    FGColor=black
    BGColor=grey70
    ...
)
```

---

## hpane — Viola Widget Class

### Description

**hpane** is a Viola widget class, implemented in C in `cl_hpane.c`. It inherits from **pane** and lays out its children **horizontally** by default.

**Viola book:** [class: hpane](https://web.archive.org/web/20040130033553id_/http://www.xcf.berkeley.edu/~wei/viola/book/classes/cl_hpane.html) — “Horizontal pane. Just like the class pane, but with ‘westToEast’ configuration default.”

### Slots and Configuration

- **paneConfig**: `"westToEast"` (`PANE_CONFIG_W2E`).
- **Class script** handles `config`, `render`/`expose`, `configSelf`, `visible`, `init`, `info`, etc. `config` calls `config(x, y, width, height)` and triggers layout.

### Usage in ViolaWWW

The **hpane** class is used for:

- **HTML_hpane** — the object that renders `<HPANE>` (script overrides much of the default behavior).
- **Form controls** — `HTML_input_text`, `HTML_isIndex`, `HTML_textarea`, etc. use **hpane** for “label | field” layout.
- **Sidebar** — `mvw.doc.view.lbar` / `www.doc.view.lbar` (sidebar panel) is an **hpane** (content | Up/Down controls).
- **Toolbars and dialogs** — e.g. `www.doc.tools`, history list, hotlist, URL bar, about box, etc.

---

## COL2, COL3, COL4 — Multi-Column Formatters

### Description

**COL2**, **COL3**, and **COL4** are HTML extension tags for 2-, 3-, and 4-column layout. The [Viola book chp11](https://web.archive.org/web/20040207185015id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp11_columns.html) calls them “Relic columning formatter. Untested.” They are implemented in ViolaWWW.

### Stylesheet

```
COL2   HTML_col2  0 0 0 1 0  1 1 1 2
COL3   HTML_col3  0 0 0 1 0  1 1 1 2
COL4   HTML_col4  0 0 0 1 0  1 1 1 2
```

### Implementation

- **HTML_col2** / **HTML_col3** / **HTML_col4**: `class` **field**, scripts in `HTML_col_script32.v` (COL3), `HTML_col_script42.v` (COL4), etc.
- Children are laid out in a grid (e.g. COL4: `width/4` per column, `indent = col * xx`). Each “row” completes after 2, 3, or 4 items.

### DIR

The **DIR** (directory list) tag uses **HTML_col2**:

```
DIR   HTML_col2  0 0 0 1 0  3 7 0 0
```

So **DIR** is rendered as a two-column layout.

---

## LINK rel=sidebar — Document Sidebar Panel

### Description

A `<LINK REL="sidebar" HREF="..." ARG="...">` in the document head declares a **sidebar** document. The browser displays the main document next to a “Topics” panel (e.g. table of contents) loaded from `HREF`. The layout is **main pane | sidebar** (or **sidebar | main**, depending on view).

### Syntax

```html
<LINK REL="sidebar" HREF="help_xvw_sb_3.3.html" ARG="20">
```

- **HREF**: URL of the sidebar document (often a short TOC or link list).
- **ARG**: Single numeric argument. In `HTML_link_script.v`, it is used as **ratio** (e.g. `20` → 20% width for the sidebar). A “parser bug” prevents multiple `ARG` values, so `maxWidth` / `ratio` cannot both be specified via attributes.

### Processing

1. **HTML_link_script** handles `REL="sidebar"`. It sets `barRatio = oarg[0]` (from **ARG**) and `barMaxWidth = 0`, then sends `linkSideBar(href, barRatio, barMaxWidth)` to the top-level document.
2. The document view (e.g. **mvw_script135**, **www_script197**) handles **linkSideBar**: it enables the **lbar** (sidebar) and sets `children` to `lbar` + main pane (and optionally scrollbar).
3. **lbar** (`mvw.doc.view.lbar` / `www.doc.view.lbar`) is an **hpane**: sidebar content (pane) | Up/Down controls.

### Example

The [ViolaWWW help page](https://web.archive.org/web/20040328124311id_/http://www.xcf.berkeley.edu/~wei/viola/vw/help_xvw_3.3.html) uses:

```html
<LINK REL="sidebar" HREF="help_xvw_sb_3.3.html" ARG="20">
```

This produces the “User’s Guide” layout with a “Topics” sidebar (~20% width) and main help content.

---

## Relationships with Other Tags

- **STG**: Base styles often group `(BODY, HPANE, INPUT, P)`. HPANE can be styled like these tags.
- **INPUT, ISINDEX, TEXTAREA**: Their Viola widgets use **hpane** (label | field) and may read colors from `STG_tagPtr("HPANE")` when HPANE is styled (e.g. in `HTML_input_int_script.v`; currently commented out).
- **FORM**: Contains INPUT etc. HPANE can wrap form-related blocks for column layout.
- **FIGURE**: Often appears *inside* HPANE (e.g. [testHPane.html](#example-testhpanhtml)) with **MAXWIDTH** to constrain width in the column.
- **SECTION**: Used as a column container inside HPANE in examples.

---

## Implementation Notes

### Postponed Geometry (hpaneP)

In **sgml.c**, when flushing content at end-tag:

```c
/* if obj is a hpane, then postpone its and
 * its children's geometry till the end of
 * hpane is reached...
 */
if (!tmi->hpaneP) {
    *h += tmi->top + tmi->bottom;
}
```

For tags with **hpaneP** (e.g. HPANE), `top`/`bottom` are *not* added to the accumulated height at flush time. Geometry for the hpane and its children is effectively deferred until the hpane is fully parsed. **html2.c** contains a commented-out variant of the same idea.

### config and Resize

- **HTML_preTxt_script** (PRE / TEXTAREA-like content): `config` does `clearWindow()` then `usual()` — “necessary in case of HPANE triggered resizes.”
- **www_script301** (doc view): Expose is trapped to avoid default geometry re-arrangement that would reload HTML; hpane is still used “because we do want to reload (to reformat) HTML docs if width is changed.”

### Stylesheet hpane Flag

The stylesheet’s 7th field (**hpane**) is read in **sgml.c** into `tmi->hpaneP` and controls the postponed-geometry behavior. HPANE has `hpane=1`.

### Known Quirks

- **Vertical vs horizontal layout**: Documentation and [testHPane.html](#example-testhpanhtml) imply **horizontal** column layout for HPANE. The current **HTML_hpane_script** lays out children **vertically** (stacked). This may be a longstanding bug or intentional override.
- **Unused variables**: In **D** and **R** branches, `xx = (get("width") - 10) / 2` and `cy = style[1]` are set but never used. The **r** branch uses `xx = get("width")` for child **R** calls.
- **Typo in sgml.c**: Inside a commented-out override block, `hapenP` appears instead of `hpaneP`. The active path uses `hpaneP` correctly.
- **'r' vs "r"**: Script uses `'r'` in **D** and `"r"` in **R** when calling children; both denote the same message.

---

## Example: testHPane.html

The [testHPane.html](https://web.archive.org/web/20040302095217id_/http://www.xcf.berkeley.edu/~wei/viola/vwTests/testHPane.html) demo illustrates **HPANE** as a columns formatter.

### First HPANE — three columns

```html
<HPANE>
<SECTION>
  <EMPH>Gingerbread House going online</EMPH> -- <ITALIC>Punsel Sugartooth</ITALIC>
  <P>What will the future hold...
</SECTION>
<SECTION><EMPH>The black art of debugging</EMPH> -- <ITALIC>Mont Todd</ITALIC>
  <P>Mont shows us how to avoid...
</SECTION>
<FIGURE SRC="..." MAXWIDTH=150>
  <FIGCAP>We're out of sand bags.</FIGCAP>
</FIGURE>
</HPANE>
```

Two **SECTION**s (text columns) and one **FIGURE** (image with **MAXWIDTH**) are intended to appear **side-by-side**.

### Second HPANE — two columns

```html
<HPANE>
<SECTION><CAUTION>Columns</CAUTION>
  <P>Bloo.<P>Blah.<P>And a very fine Bleh.
</SECTION>
<SECTION><CAUTION>Departments</CAUTION>
  <P>UF0 Sightings...<P>Letters to Editors
</SECTION>
</HPANE>
```

Two **SECTION**s for “Columns” and “Departments.”

### Third HPANE — icon row

```html
<HPANE>
<P>Sponsors (actually, just random icons):
<FIGURE ... MAXWIDTH=32></FIGURE>
<FIGURE ... MAXWIDTH=32></FIGURE>
...
</HPANE>
```

Intro **P** plus several **FIGURE**s in a row. No HPANE attributes are used; **FIGURE** uses **MAXWIDTH** for sizing.

---

## References

### Primary

- **Viola book, chp11 — Columns:** [chp11_columns.html](https://web.archive.org/web/20040207185015id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp11_columns.html) (HPANE, COL2/3/4).
- **Viola book, htmlTags:** [htmlTags](https://web.archive.org/web/20040311113655id_/http://www.xcf.berkeley.edu/~wei/viola/book/htmlTags) (HPANE “columns formatter” + stylesheet line).
- **Viola book, class hpane:** [cl_hpane.html](https://web.archive.org/web/20040130033553id_/http://www.xcf.berkeley.edu/~wei/viola/book/classes/cl_hpane.html).
- **Layout illustrations:** [chp9_layouts_withConstraint.xbm](https://web.archive.org/web/20040224221910id_/http://www.xcf.berkeley.edu/~wei/viola/book/dumps/chp9_layouts_withConstraint.xbm), [chp9_layouts.gif](https://web.archive.org/web/20040209084913id_/http://www.xcf.berkeley.edu/~wei/viola/book/dumps/chp9_layouts.gif).

### Examples and Help

- **testHPane.html:** [vwTests/testHPane.html](https://web.archive.org/web/20040302095217id_/http://www.xcf.berkeley.edu/~wei/viola/vwTests/testHPane.html).
- **ViolaWWW help (sidebar):** [help_xvw_3.3.html](https://web.archive.org/web/20040328124311id_/http://www.xcf.berkeley.edu/~wei/viola/vw/help_xvw_3.3.html) with `<LINK REL="sidebar" HREF="help_xvw_sb_3.3.html" ARG="20">`.

### Code

- **HTML HPANE:** `src/viola/embeds/HTML_hpane_script.v`, `src/libWWW/HTMLDTD.c` (hpane_attr), `src/viola/HTML_style.c`.
- **Viola hpane:** `src/viola/cl_hpane.c`, `src/viola/cl_pane.c` (paneConfig, westToEast).
- **COL2/3/4:** `src/viola/embeds/HTML_col_script*.v`, `src/viola/HTML_style.c`.
- **Sidebar:** `src/viola/embeds/HTML_link_script.v` (rel=sidebar), `mvw_script135.v` / `www_script197.v` (linkSideBar, lbar), `objs.c` (lbar hpane).

### WWW-Talk

- **Pei Y. Wei (Dec 1993):** [Re: a compromise on tables, etc.](../www_lists_archive/www-talk.1993q4/0684.html) — “I’ve been calling it HPANE, and it has MINWIDTH and MAXWIDTH constraint attributes.”

### See Also

- [STG_REFERENCE.md](STG_REFERENCE.md) — STG stylesheets, base styles for BODY/HPANE/INPUT/P.
- [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md) — FIGURE, MAXWIDTH, FIGCAP.
- [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md) — Viola widget classes (vpane, hpane, etc.).
