# HMML Reference

> **Documentation created in: ViolaWWW 4.0**  
> This document describes the original HMML format from ViolaWWW v3.x (1992-1995).

**HMML** (HyperMedia Markup Language) was an experimental markup language developed by Pei-Yuan Wei for ViolaWWW in the early 1990s, parallel to and extending HTML.

## Historical Context

HMML represents an important moment in web history. In 1993, while HTML was being standardized as a text-focused format, there was significant interest in extending it for multimedia capabilities.

As Tim Berners-Lee noted in April 1993:

> "HMML is in fact already an extension of HTML for multimedia from O'Reilly. There are similar extensions from NCSA. We just have to standardize on them for the next DTD which we define."

Dave Raggett clarified the naming in May 1993:

> "HMML is the name of an internal and experimental DTD developed by Pei Wei. However, things became confused when Tim Berners Lee started using 'HMML' for the proposed replacement for the original HTML DTD. To avoid confusion I am calling the new DTD 'HTML+' which also emphasises that it is a superset of the current format."

ViolaWWW was notable for using a real SGML parser (`sgmls`) for parsing both HTML and HMML. As Pei-Yuan Wei explained in 1994:

> "At one point, ViolaWWW used a real SGML parser (sgmls) entirely (without CERN's parser) for its parsing of HTML (using Dan's DTD) and also HMML (something I had cooked up; this was pre HTML+ DTD days)."

However, due to the lack of document validation in practice, ViolaWWW eventually reverted to using a more forgiving parser for HTML while keeping SGML parsing for HMML.

### ViolaWWW and the Origins of Web Style Sheets

ViolaWWW, launched in 1992, was among the first graphical web browsers and was **the first web browser that supported style sheets linked from documents**. This was a groundbreaking achievement, especially considering it was developed by a single person.

According to Håkon Wium Lie's doctoral dissertation "Cascading Style Sheets" (University of Oslo, 2005), Pei Wei published a style sheet proposal (referred to as "PWP" - Pei Wei's Proposal) in October 1993 on the www-talk mailing list, following Robert Raisch's earlier proposal from June 1993.

When asked about the relationship between these proposals, Pei Wei responded:

> "Well, after Rob left ORA I've basically inherited the stylesheet problem— finish the design, prototype, and final implementation. As Rob has done the good work of writing the initial proposal, I will try to reuse as much of the collected material as possible. But there were and will be changes since Rob presented the proposal this past summer."

## Key Innovation: VOBJF

HMML's most significant feature was the `<VOBJF>` tag, which allowed embedding interactive Viola script objects directly into documents. This was a precursor to Java applets and JavaScript, enabling:

- Interactive widgets embedded in documents
- Network connections from within documents
- Dynamic content updates

As noted in patent litigation documents regarding ViolaWWW:

> "The ViolaWWW source code teaches two ways of creating interactive webpages using embedded applications. One way is by using a simple script file, such as clock.v. All that is required is a webpage (such as violaApps.hmml) and the script file (such as clock.v)."

## HMML Tags

### Document Structure

| Tag | Description |
|-----|-------------|
| `<HMML>` | Root document element |
| `<TITLE>` | Document title (displayed in window header) |
| `<SECTION>` | Document section container |

### Headers

| Tag | Description |
|-----|-------------|
| `<H1>` | Level 1 heading (largest) |
| `<H2>` | Level 2 heading |
| `<H3>` | Level 3 heading (smallest) |

### Text Elements

| Tag | Description |
|-----|-------------|
| `<P>` | Paragraph |
| `<LISTING>` | Preformatted code listing (monospace) |
| `<EXAMPLE>` | Example block with indentation |
| `<QUOTE>` | Block quotation |
| `<AUTHOR>` | Author attribution (italic, right-aligned) |
| `<LABEL>` | Text label |
| `<ITITLE>` | Italic title (inline) |

### Images

| Tag | Attributes | Description |
|-----|------------|-------------|
| `<PIC>` | `SRC` | External image (GIF, etc.) loaded via URL |
| `<XBM>` | (inline data) | X BitMap - monochrome bitmap embedded directly |
| `<XPM>` | (inline data) | X PixMap - color pixmap embedded directly |

### Interactive Elements

| Tag | Attributes | Description |
|-----|------------|-------------|
| `<VOBJF>` | `HREF`, `ARG` | Embedded Viola script object |

## Tag Attributes

### PIC
```html
<PIC SRC="image.gif"></PIC>
```

### XBM (Inline Bitmap)
```html
<XBM>
#define test_width 16
#define test_height 16
static char test_bits[] = {
   0x00, 0x00, 0xe0, 0x07, ...
};
</XBM>
```

### XPM (Inline Pixmap)
```html
<XPM>
/* XPM */
static char * image[] = {
"16 16 3 1",
"  c None",
". c black",
"X c red",
...
};
</XPM>
```

### VOBJF (Viola Object)
```html
<VOBJF HREF="widget.v"></VOBJF>
<VOBJF HREF="app.v" ARG="param1"></VOBJF>
```

## Example Document

```html
<HMML>
<TITLE>Sample HMML Document</TITLE>
<SECTION>

<H1>Welcome to HMML</H1>

<P>
This is a paragraph demonstrating the HyperMedia Markup Language.
</P>

<H2>Inline Image</H2>

<XBM>
#define circle_width 16
#define circle_height 16
static char circle_bits[] = {
   0x00, 0x00, 0xe0, 0x07, 0x10, 0x08,
   0x08, 0x10, 0x04, 0x20, 0x04, 0x20,
   0x04, 0x20, 0x08, 0x10, 0x10, 0x08,
   0xe0, 0x07, 0x00, 0x00, 0x00, 0x00};
</XBM>

<H2>Code Example</H2>

<LISTING>
int main() {
    printf("Hello, HMML!\n");
    return 0;
}
</LISTING>

<QUOTE>
HMML was one of the earliest hypermedia markup languages.
</QUOTE>

<AUTHOR>ViolaWWW Team, 1992-1994</AUTHOR>

</SECTION>
</HMML>
```

## Binary HMML Format (.hmmlb)

HMML documents can be pre-compiled into a binary format for faster loading. This eliminates the need to run the SGML parser at load time.

### Compilation

```bash
sgmlsA2B HMML document.hmml > document.hmmlb
```

The `sgmlsA2B` utility:
1. Invokes `onsgmls` (from OpenSP) to parse the SGML
2. Converts the ESIS (Element Structure Information Set) output to binary
3. Outputs a `.hmmlb` file

### Binary Format Structure

```
Header:
  0x00000000        (4 bytes) - Reserved
  0x12345678        (4 bytes) - Byte order hint
  version           (4 bytes) - Format version (currently 2)
  DTDNameSize       (4 bytes) - Length of DTD name
  DTDName           (variable) - DTD name string (e.g., "HMML")

Tag Dictionary:
  TAGDICT marker    (1 byte)
  tagCount          (4 bytes) - Number of unique tags
  [
    tagID           (4 bytes)
    nameSize        (4 bytes)
    tagName         (variable)
  ]...

Document Content:
  [
    TAG marker      (1 byte)
    tagID           (4 bytes)
    [attributes...]
    [content...]
    ETAG marker     (1 byte)
    tagID           (4 bytes)
  ]...
```

### Markers

| Marker | Value | Description |
|--------|-------|-------------|
| TAGDICT | 'D' | Tag dictionary section |
| TAG | 'T' | Start tag |
| ETAG | 'E' | End tag |
| DATA | 'C' | Character data |
| ATTR | 'A' | Attribute |

## Processing Pipeline

```
.hmml file
    │
    ▼
onsgmls (SGML parser)
    │
    ▼
ESIS stream (text)
    │
    ▼
sgmlsA2B (converter)
    │
    ▼
.hmmlb file (binary)
    │
    ▼
SGMLBuildDocB() → Document display
```

## ViolaWWW Stylesheet Language (PWP/STG)

ViolaWWW pioneered a stylesheet language that predates CSS. The syntax was inspired by Lisp, using nested parentheses to express contextual selectors in the document structure.

### Original PWP Syntax (1993)

From Pei Wei's original proposal, here is a sample stylesheet:

```lisp
(HEAD,BODY fontSize=normal
           BGColor=white
           FGColor=black
  (H1 fontSize=largest
      BGColor=red
      FGColor=white)
  (H2 fontSize=large)
  (P)
  (A FGColor=red)
  (CMD,KBD,SCREEN,LISTING,EXAMPLE fontFamily=fixed)
  (BOLD,EMPH,STRONG fontSlant=bold)
  (I fontSlant=italic)
  (ADDRESS
    (P fontSlant=italic))
  (OL
    (LI numStyle=roman
      (LI numStyle=number
        (LI numStyle=alpha)
      )
    )
  )
  (FOOTNOTE fontSize=small
    (P)
  )
)
```

The nested parentheses express **contextual selectors**: `(ADDRESS (P fontSlant=italic))` means "P elements inside ADDRESS elements should be italic". This was a powerful feature that CSS later adopted with its descendant selectors.

### Supported Properties

Properties documented in the original proposal:

| Property | Values | Description |
|----------|--------|-------------|
| `fontSize` | `small`, `normal`, `large`, `largest` | Relative font size |
| `fontSlant` | `normal`, `italic`, `bold` | Font style (italic or bold) |
| `fontFamily` | `fixed` | Font family type |
| `fontSpacing` | (values unknown) | Letter/word spacing |
| `numStyle` | `roman`, `number`, `alpha` | List numbering style (**not implemented**) |
| `BGColor` | X11 color names | Background color |
| `FGColor` | X11 color names | Foreground (text) color |
| `BDColor` | X11 color names | Border color |
| `align` | (values unknown) | Text alignment |
| `border` | integer (pixels) | Border width |
| `blink` | integer (milliseconds) | Blink interval |
| `blinkColorOn` | X11 color name | Blink on color |
| `blinkColorOff` | X11 color name | Blink off color |

Color names were taken from the X11 color database (e.g., `red`, `maroon`, `grey70`).

### Linking Stylesheets to Documents

ViolaWWW used HTML's `LINK` element to associate documents with stylesheets:

```html
<link href="path/to/stylesheet.stg" rel="style">
```

**Notably**, ViolaWWW allowed `LINK` elements to appear within the body of the document, enabling different parts of a document to use different stylesheets:

```html
<html>
<head>
<link href="viola/sgml/styles/HTML_sodium.stg" rel="style">
</head>
<body>
<h1>Simple stylesheets test</h1>
...
<link href="viola/sgml/styles/HTML_address1.stg" rel="style">
<p>Second stylesheet in effect starting from here.
...
</body>
</html>
```

When HTML later standardized the linking mechanism for stylesheets, `LINK` elements were restricted to the `HEAD` section only.

### Value Propagation (Inheritance)

PWP used inheritance to propagate values from parent to child elements:

> "Note that properties are inherited down the tree, unless overridden. [...] Having this inheritance behaviour also helps to keep the description short, as lots of information can be derived by the context in the tree structure."

This is the same inheritance model later adopted by CSS.

---

## ViolaWWW Internal Stylesheet Format

HMML uses a stylesheet file (`res/styles/HMML.style`) that maps tags to Viola objects:

```
# Format: TAG TYPE inline notify flushAlways flushOnSub hpane top bottom left right
HMML      HTML__doc           0 0 0 1 0   0  10 10 10
TITLE     HTML_title          0 0 0 0 0   0   0  0  0
SECTION   HTML_fld            0 0 0 1 0  10  10 20 20
H1        HTML_header_big     0 0 0 1 0  15  10  0  0
H2        HTML_header_medium  0 0 0 1 0  12   8  0  0
H3        HTML_header_small   0 0 0 1 0  10   6  0  0
P         HTML_txt            0 0 0 1 0   8   8 10 10
LISTING   HTML_listing        0 0 0 1 0  10  10 20 20
...
```

### Stylesheet Columns

1. **TAG** - HMML tag name
2. **TYPE** - Viola object class to use
3. **inline** - Is this an inline element? (1=yes, 0=no)
4. **notify** - Notify on creation
5. **flushAlways** - Always flush
6. **flushOnSub** - Flush on sub-tag
7. **hpane** - Horizontal pane mode
8. **top** - Top margin (pixels)
9. **bottom** - Bottom margin (pixels)
10. **left** - Left margin (pixels)
11. **right** - Right margin (pixels)

## Requirements

To process `.hmml` files, you need:

- **OpenSP** (provides `onsgmls`): `brew install open-sp`
- **sgmlsA2B** utility (built with ViolaWWW)

Pre-compiled `.hmmlb` files can be loaded without these dependencies.

## File Extensions

| Extension | Description |
|-----------|-------------|
| `.hmml` | HMML source document (requires SGML parser) |
| `.hmmlb` | Pre-compiled binary HMML (loads directly) |
| `.v` | Viola script object (for VOBJF embedding) |

## Historical Significance

ViolaWWW and HMML represent an important "road not taken" in web history. According to Håkon Wium Lie:

> "ViolaWWW was the first web browser that supported style sheets linked from documents. This was quite an achievement, especially when considering that a single person did the design and programming."

The contextual selector syntax pioneered by PWP influenced the development of CSS:

> "By using multi-level parentheses, contextual selectors can easily be expressed. In the sample style sheet above, list items are given numbering styles depending on their level in the structure: the first level is numbered in the roman style, the second in the number style, and the third in the alpha style."

While ViolaWWW never gained the widespread adoption of Mosaic, it was an influential application that inspired other developers and pioneered concepts that became fundamental to the modern web.

## References

- Lie, Håkon Wium. "Cascading Style Sheets." PhD dissertation, University of Oslo, 2005. Available at: https://www.wiumlie.no/2006/phd/css.pdf
- Wei, Pei. "Stylesheet Language." Message posted to www-talk, 22 Oct 1993.
- Raggett, Dave. "Re HMML?" Message posted to www-talk, 25 May 1993.
- www-talk mailing list archives: http://www.webhistory.org/www.lists/

## See Also

- [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md) - Viola scripting language reference
- [STG_REFERENCE.md](STG_REFERENCE.md) - Stylesheet system reference

