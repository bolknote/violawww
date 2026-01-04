# FOSI_REFERENCE.md

> **Documentation created in: ViolaWWW 4.0**  
> This document describes the original FOSI support from ViolaWWW v3.x (1992-1995).

**FOSI** (Formatting Output Specification Instance) — SGML-based stylesheet system for document formatting.

**Status:** Partially implemented parser infrastructure exists, but stylesheet functionality is not fully operational. This was intended as ViolaWWW's predecessor to CSS.

Topics covered:
- FOSI document structure and syntax
- FONT element properties (size, weight, posture, colors)
- INDENT element properties (margins, first-line indentation)
- E-I-C (Element In Context) binding mechanism
- Autonomous document format vs. stylesheet usage
- Complete examples with styling demonstrations

---

## Overview

FOSI (Formatting Output Specification Instance) is an SGML standard for describing document formatting and presentation. In ViolaWWW, FOSI serves dual purposes:

1. **Autonomous document format** — `.fosi` files containing both content and styling
2. **Stylesheet system** — external style descriptions that could be applied to HTML documents

While the SGML parser infrastructure exists and can read FOSI files, the style application system is incomplete. If fully implemented, FOSI would provide comprehensive typographic control over document rendering.

---

## Document Structure

FOSI documents use SGML syntax with a specific DTD. Here's the basic structure:

```xml
<DOCDESC>
  <STYLDESC>
    <E-I-C GI="P"></E-I-C>
    <FONT SIZE="14" WEIGHT="bold" POSTURE="italic" FGCOL="#000000" BGCOL="#ffffff"></FONT>
    <INDENT LEFTIND="20" RIGHTIND="20" FIRSTLN="10"></INDENT>
  </STYLDESC>

  <CHARLIST>
    Content with applied formatting goes here.
  </CHARLIST>
</DOCDESC>
```

### Core Elements

#### DOCDESC (Document Description)
Root element containing the entire FOSI specification.

#### STYLDESC (Style Description)
Container for style definitions and their application contexts.

#### E-I-C (Element In Context)
Binds styles to specific document elements.
- `GI` attribute specifies the target element name (e.g., "P", "H1", "LI")

#### CHARLIST (Character List)
Contains the actual document content to be formatted.

---

## FONT Element

Controls typographic properties of text.

### Attributes

| Attribute | Values | Description |
|-----------|--------|-------------|
| `SIZE` | Integer (e.g., "12", "14", "18") | Font size in points |
| `WEIGHT` | "bold", "normal" | Font weight |
| `POSTURE` | "italic", "normal" | Font posture/slant |
| `STYLE` | Font style name | Font family/style |
| `WIDTH` | Font width specification | Font width (condensed, normal, expanded) |
| `FGCOL` | Hex color (e.g., "#000000") | Foreground/text color |
| `BGCOL` | Hex color (e.g., "#FFFFFF") | Background color |

### Color Format
Colors use standard hexadecimal RGB format: `#RRGGBB`
- `#000000` = black
- `#FFFFFF` = white
- `#FF0000` = red
- `#00FF00` = green
- `#0000FF` = blue

---

## INDENT Element

Controls paragraph formatting and indentation.

### Attributes

| Attribute | Values | Description |
|-----------|--------|-------------|
| `LEFTIND` | Integer (pixels) | Left margin/indentation |
| `RIGHTIND` | Integer (pixels) | Right margin/indentation |
| `FIRSTLN` | Integer (pixels) | Additional first-line indentation |

---

## Usage Patterns

### Autonomous FOSI Documents

When fully implemented, `.fosi` files would be self-contained documents that render with their specified styling:

```xml
<DOCDESC>
  <STYLDESC>
    <E-I-C GI="P"></E-I-C>
    <FONT SIZE="12" FGCOL="#333333"></FONT>
    <INDENT LEFTIND="30" RIGHTIND="30" FIRSTLN="15"></INDENT>
  </STYLDESC>

  <CHARLIST>
    This paragraph would display with:
    • 12pt font size
    • Dark grey text color (#333333)
    • 30px left and right margins
    • 15px additional first-line indentation
  </CHARLIST>
</DOCDESC>
```

### Stylesheet Application

FOSI could also function as external stylesheets applied to HTML documents:

```xml
<!-- styles.fosi -->
<DOCDESC>
  <STYLDESC>
    <E-I-C GI="P"></E-I-C>
    <FONT SIZE="12" WEIGHT="normal"></FONT>
    <INDENT LEFTIND="20" FIRSTLN="10"></INDENT>

    <E-I-C GI="H1"></E-I-C>
    <FONT SIZE="18" WEIGHT="bold" FGCOL="#000080"></FONT>
  </STYLDESC>
</DOCDESC>
```

Applied to HTML:
```html
<h1>Styled Heading</h1>
<p>Styled paragraph with proper indentation.</p>
```

---

## Complete Examples

### Example 1: Academic Paper Formatting

```xml
<DOCDESC>
  <STYLDESC>
    <!-- Title -->
    <E-I-C GI="H1"></E-I-C>
    <FONT SIZE="20" WEIGHT="bold" FGCOL="#000080"></FONT>
    <INDENT LEFTIND="0" RIGHTIND="0"></INDENT>

    <!-- Abstract -->
    <E-I-C GI="P"></E-I-C>
    <FONT SIZE="11" FGCOL="#333333"></FONT>
    <INDENT LEFTIND="50" RIGHTIND="50" FIRSTLN="20"></INDENT>

    <!-- Body text -->
    <E-I-C GI="P"></E-I-C>
    <FONT SIZE="12" FGCOL="#000000"></FONT>
    <INDENT LEFTIND="30" RIGHTIND="30" FIRSTLN="15"></INDENT>
  </STYLDESC>

  <CHARLIST>
    <H1>Research Paper Title</H1>

    <P>This is the abstract paragraph with wider margins and first-line indentation typical of academic formatting.</P>

    <P>This is a body paragraph with standard margins and indentation. The first line would be indented further to create the traditional paragraph style.</P>
  </CHARLIST>
</DOCDESC>
```

### Example 2: Technical Documentation

```xml
<DOCDESC>
  <STYLDESC>
    <!-- Code examples -->
    <E-I-C GI="PRE"></E-I-C>
    <FONT SIZE="10" STYLE="monospace" FGCOL="#006600" BGCOL="#F0F0F0"></FONT>
    <INDENT LEFTIND="40" RIGHTIND="20"></INDENT>

    <!-- Regular paragraphs -->
    <E-I-C GI="P"></E-I-C>
    <FONT SIZE="12" FGCOL="#000000"></FONT>
    <INDENT LEFTIND="20" RIGHTIND="20"></INDENT>
  </STYLDESC>

  <CHARLIST>
    <P>This paragraph uses standard body text formatting.</P>

    <PRE>
function example() {
    console.log("This code block would display");
    console.log("with monospace font and light background");
}
    </PRE>
  </CHARLIST>
</DOCDESC>
```

### Example 3: Magazine Article

```xml
<DOCDESC>
  <STYLDESC>
    <!-- Headlines -->
    <E-I-C GI="H1"></E-I-C>
    <FONT SIZE="24" WEIGHT="bold" POSTURE="italic" FGCOL="#800000"></FONT>

    <!-- Byline -->
    <E-I-C GI="P"></E-I-C>
    <FONT SIZE="11" STYLE="italic" FGCOL="#666666"></FONT>
    <INDENT LEFTIND="100" RIGHTIND="20"></INDENT>

    <!-- Body -->
    <E-I-C GI="P"></E-I-C>
    <FONT SIZE="13" FGCOL="#000000"></FONT>
    <INDENT LEFTIND="30" RIGHTIND="30" FIRSTLN="20"></INDENT>
  </STYLDESC>

  <CHARLIST>
    <H1>Magazine Article Headline</H1>

    <P>By: Author Name, Staff Writer</P>

    <P>This is the first paragraph of a magazine article. It would have generous margins and first-line indentation for readability.</P>

    <P>Subsequent paragraphs would continue with the same formatting, creating a professional newspaper or magazine layout style.</P>
  </CHARLIST>
</DOCDESC>
```

---

## Implementation Status

**Parser Infrastructure:** ✅ Complete
- SGML parser recognizes FOSI DTD
- File extension `.fosi` registered as `text/fosi` MIME type
- Basic element parsing functional

**Style Application:** ❌ Not implemented
- FONT and INDENT attributes parsed but not applied
- No HTStyle object creation from FOSI properties
- No integration with ViolaWWW rendering system

If fully implemented, FOSI would provide comprehensive document formatting capabilities comparable to modern CSS, with precise control over typography, spacing, and visual presentation.

---

## File Format

- **Extension:** `.fosi`
- **MIME Type:** `text/fosi`
- **Encoding:** 8-bit text (supports various character sets)
- **Parser:** SGML-based with custom FOSI DTD

---

## See Also

- [STG_REFERENCE.md](STG_REFERENCE.md) — ViolaWWW's implemented stylesheet system
- [HMML_REFERENCE.md](HMML_REFERENCE.md) — Alternative SGML-based markup
- [COLOR_REFERENCE.md](COLOR_REFERENCE.md) — Complete color specification guide
