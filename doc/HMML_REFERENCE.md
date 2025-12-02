# HMML Reference

**HMML** (HyperMedia Markup Language) was an experimental markup language developed by Pei-Yuan Wei for ViolaWWW in the early 1990s, parallel to and extending HTML.

## Historical Context

HMML represents an important moment in web history. In 1993, while HTML was being standardized as a text-focused format, there was significant interest in extending it for multimedia capabilities.

As Tim Berners-Lee noted in April 1993:

> "HMML is in fact already an extension of HTML for multimedia from O'Reilly. There are similar extensions from NCSA. We just have to standardize on them for the next DTD which we define."

ViolaWWW was notable for using a real SGML parser (`sgmls`) for parsing both HTML and HMML. As Pei-Yuan Wei explained in 1994:

> "At one point, ViolaWWW used a real SGML parser (sgmls) entirely (without CERN's parser) for its parsing of HTML (using Dan's DTD) and also HMML (something I had cooked up; this was pre HTML+ DTD days)."

However, due to the lack of document validation in practice, ViolaWWW eventually reverted to using a more forgiving parser for HTML while keeping SGML parsing for HMML.

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

## Stylesheet

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

## See Also

- [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md) - Viola scripting language reference
- [STG_REFERENCE.md](STG_REFERENCE.md) - Stylesheet system reference

