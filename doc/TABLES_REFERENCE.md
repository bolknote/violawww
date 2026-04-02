# HTML Tables Reference

## Overview

ViolaWWW implements the original **HTML+ / early Viola table model** (circa 1993), not the later HTML 4/5 table model. The source of truth for element and attribute names is the SGML DTD in `src/libWWW/HTMLDTD.c`. The source of truth for layout is `src/viola/HTML_share.c`, which builds a table grid from a linear sequence of child objects produced by the HTML formatter.

In practical terms, this means:

- `TABLE` / `TBL` is the table container.
- `TH` and `TD` are direct children of the table.
- `TR` is an empty **row break** marker, not a wrapper around cells.
- `TB` is an empty **separator row** marker.
- `TCAP` is the table caption.

> **Added in: ViolaWWW 4.0** — This document was written during the revival work to record DTD versus implementation behavior. The table feature set itself is original ViolaWWW (v3.x).

---

## Supported elements

| Tag | Role | DTD content model |
|-----|------|-------------------|
| **TABLE** | Table container | `SGML_MIXED` |
| **TBL** | Synonym for **TABLE** (same attributes and Viola class) | `SGML_MIXED` |
| **TCAP** | Table caption; its text and placement are applied to the parent table | `SGML_CDATA` |
| **TH** | Header cell | `SGML_MIXED` |
| **TD** | Data cell | `SGML_MIXED` |
| **TR** | Row break marker (empty element) | `SGML_EMPTY` |
| **TB** | Separator row marker (empty element; thin bar/spacer row) | `SGML_EMPTY` |

There is **no** support in this DTD for **CAPTION**, **THEAD**, **TBODY**, **TFOOT**, **COL**, **COLGROUP**, or for a modern `<TR>...</TR>` container that owns `TH`/`TD` cells. In ViolaWWW markup, authors place `TH`/`TD` directly in the table stream and use `TR` to advance to the next row. `TB` inserts a dedicated separator row between logical groups.

---

## Authoring model

When the formatter walks the children of a table, it treats them as a flat sequence:

1. `TCAP` configures the caption.
2. `TH` and `TD` occupy slots in the current row.
3. `TR` ends the current row and moves to the next one.
4. `TB` creates a separate thin row, then moves to the next row.
5. End of table implicitly closes the final row if no trailing `TR` was present.

This is why historical examples often omit many end tags but still include explicit `TR` markers where a new row must begin before the table ends.

---

## DTD-declared attributes

Declared in `src/libWWW/HTMLDTD.c` (arrays `table_attr`, `tcap_attr`, `th_attr`, `td_attr`). Index constants are in `src/libWWW/HTMLDTD.h`.

### TABLE / TBL

| Attribute | DTD |
|-----------|-----|
| BORDER | ✓ |
| COMPACT | ✓ |
| FOLD | ✓ |
| ID | ✓ |
| INDEX | ✓ |
| LABEL | ✓ |
| MAXWIDTH | ✓ |
| MINWIDTH | ✓ |

### TCAP

| Attribute | DTD |
|-----------|-----|
| ALIGN | ✓ |
| TOP | ✓ |

### TH and TD

| Attribute | DTD |
|-----------|-----|
| ALIGN | ✓ |
| COLSPAN | ✓ |
| ROWSPAN | ✓ |

**Note:** In `HTMLDTD.h`, the row-span constants are spelled `HTML_TD_ROLSPAN` and `HTML_TH_ROLSPAN` (a typo in the identifier names). The markup attribute name is still **ROWSPAN**.

---

## Viola object mapping

Tag-to-class mapping is in `src/viola/HTML_style.c`:

- **TABLE** / **TBL** → `HTML_table`
- **TCAP** → `HTML_tcap`
- **TH** → `HTML_th`
- **TD** → `HTML_td`
- **TR** → `HTML_tr`
- **TB** → `HTML_tb`

Embed scripts (attribute handling and layout hooks):

- `src/viola/embeds/HTML_table_script.v`
- `src/viola/embeds/HTML_tcap_script.v`
- `src/viola/embeds/HTML_th_script.v`
- `src/viola/embeds/HTML_td_script.v`
- `src/viola/embeds/HTML_tr_script.v`
- `src/viola/embeds/HTML_tb_script.v`
- `src/viola/embeds/HTML_tableCap_script.v` (clone used for rendered caption)

For parsed HTML, recognized attributes are delivered to objects through the `AA` message path (see `src/viola/html2.c` and `src/viola/sgml.c`).

---

## Layout behavior

`src/viola/HTML_share.c` classifies each child object by `cellType` (`TABLE_CELL_TYPE_TR`, `TABLE_CELL_TYPE_TB`, `TABLE_CELL_TYPE_TH`, `TABLE_CELL_TYPE_TD`, `TABLE_CELL_TYPE_TCAP`, etc.), reads `COLSPAN` / `ROWSPAN` through `getColSpan()` and `getRowSpan()`, and then builds the matrix used by `HTMLTableFormater()`.

Important runtime details:

- `TR` advances the row index.
- `TB` also advances the row index, but produces a fixed-height separator row (`TABLE_CELL_HEIGHT_TB`).
- `TH` and `TD` occupy the current row and may span multiple columns or rows.
- If the last row is not followed by `TR`, the formatter still closes it when the table ends.

---

## Effective behavior in parsed HTML

Two layers matter here:

1. The DTD decides which attributes ordinary HTML parsing recognizes.
2. The embed scripts and `HTML_share.c` decide what those recognized attributes actually do.

That distinction matters because some scripts contain `AA` branches for attributes that are **not declared in the DTD**. Those branches exist in code, but ordinary parsed HTML will not reach them.

### TABLE (`HTML_table_script.v`)

| Attribute | Status |
|-----------|--------|
| BORDER | Implemented. The script sets `border`, and cells query the parent table when drawing. |
| ID | Implemented. Stored as `tagID` and used by anchor lookup/navigation code. |
| MAXWIDTH / MINWIDTH | Parsed and stored on the table object, but `HTMLTableFormater()` does **not** consult them when computing the grid. Do not rely on them for actual table sizing. |
| COMPACT | Parsed and stored, but the script explicitly marks it as **not used yet**. |
| FOLD / INDEX / LABEL | Declared in the DTD, but `HTML_table_script.v` has no `AA` handler for them, so they have no visible effect here. |

### TCAP (`HTML_tcap_script.v`)

| Attribute | Status |
|-----------|--------|
| ALIGN | Implemented; mapped to the caption placement/alignment logic. |
| TOP | Implemented; controls whether the caption is placed at the top (`topP`). |

### TH (`HTML_th_script.v`)

| Attribute | Status |
|-----------|--------|
| ALIGN | Implemented; converted to `paneConfig` and passed into `HTML_txt` creation. |
| COLSPAN / ROWSPAN | Implemented; used by `HTML_share.c`. |
| ID | Script support exists, but `ID` is **not declared in the DTD for `TH`**. In ordinary parsed HTML, this attribute is therefore not forwarded to the script. |

`HTML_th_script.v` also has handlers for `MAXWIDTH` / `MINWIDTH`, but those attributes are not declared in the DTD for `TH`. From ordinary HTML markup, they are therefore not available through the normal parser path.

### TD (`HTML_td_script.v`)

| Attribute | Status |
|-----------|--------|
| COLSPAN / ROWSPAN | Implemented; used by `HTML_share.c`. |
| ALIGN | Declared in the DTD, but **not implemented** in `HTML_td_script.v`: there is no `AA` branch for it, and `HTML_txt` is created without the alignment argument used by `TH`. |
| ID | Script support exists, but `ID` is **not declared in the DTD for `TD`**. In ordinary parsed HTML, this attribute is therefore not forwarded to the script. |
| MAXWIDTH / MINWIDTH | Script support exists, but these attributes are **not declared in the DTD for `TD`**. From ordinary parsed HTML, they are therefore not forwarded to the script. |

### TR / TB

Neither element has DTD attributes (`no_attr`). `TB` renders as a fixed-height separator row (`TABLE_CELL_HEIGHT_TB` in `HTML_share.c`).

---

## Example (HTML+ style)

Logical structure: caption, then header cells, then `TR` to move to the next row, then body cells. Omitted end tags were common in period examples. The important part is that row boundaries are still expressed with explicit `TR` markers, except that the final row may end implicitly at `</TABLE>`.

```html
<TABLE border>
<TCAP align="right">Figure 1: Example table</TCAP>
<TH rowspan=2><TH colspan=2>average
<TH rowspan=2>other category<TR>
<TH>height<TH>weight<TR>
<TH align="left">males<TD>1.9<TD>.003<TD>yyy<TR>
<TH align="left">females<TD>1.7<TD>.002<TD>xxx
</TABLE>
```

### Example with `TB` (separator row)

`TB` is an empty separator-row marker: a thin bar between logical blocks. A typical pattern is a header row, then `TB`, then ordinary `TD` rows. It is **not** a modern `<tbody>` equivalent.

```html
<TABLE border>
<TCAP top>Use of the PRE tag</TCAP>
<TH>HTML Source</TH><TH>Output</TH><TR>
<TB>
<TD>
<PRE>
Hello,
 Hello <EM>there</EM> world.
</PRE>
</TD>
<TD>
<PRE>
Hello,
 Hello <EM>there</EM> world.
</PRE>
</TD><TR>
</TABLE>
```

Both examples above follow the Viola book chapter on tables. Archived source page (Pei-Yuan Wei, Berkeley XCF): [chp11_table.html on the Wayback Machine](https://web.archive.org/web/20040207193507id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp11_table.html). That page also links to a historical "Test sample" (`testTableAll.html`).

<img width="640" height="200" alt="" src="https://github.com/user-attachments/assets/fcde395c-bcd2-4ed9-9480-8f6f961e42dc" />

---

## See also

- [chp11_table.html (archived)](https://web.archive.org/web/20040207193507id_/http://www.xcf.berkeley.edu/~wei/viola/book/chp11_table.html) — Viola book, table tags and both examples
- `src/libWWW/HTMLDTD.c` — element and attribute definitions
- `src/libWWW/HTMLDTD.h` — `HTML_TABLE_*`, `HTML_TCAP_*`, `HTML_TH_*`, `HTML_TD_*` indices
- `src/viola/HTML_share.c` — `HTMLTableFormater`, colspan/rowspan grid
- [STG_REFERENCE.md](STG_REFERENCE.md) — **TABLE** entry in STG for default spacing/style
