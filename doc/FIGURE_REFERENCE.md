# FIGURE Element Reference

## Overview

The `<FIGURE>` element in ViolaWWW is used to embed and display images and graphics within HTML documents. It supports multiple image formats and provides advanced features like clickable regions (image maps) and delayed loading.

## Syntax

```html
<FIGURE [attributes]>
  [<FIGDATA>...</FIGDATA>]
  [<FIGA>...</FIGA>]
  [<FIGCAP>...</FIGCAP>]
</FIGURE>
```

**Note:** `<FIG>` can be used as a shorthand for `<FIGURE>`. Both forms are equivalent and support the same attributes.

## Attributes Summary

| Element | Attribute | Status | Description |
|---------|-----------|--------|-------------|
| FIGURE/FIG | TYPE | ✅ Required | Image format type |
| FIGURE/FIG | SRC | ✅ Optional | URL to external image file |
| FIGURE/FIG | WIDTH | ✅ Optional | Width in pixels |
| FIGURE/FIG | HEIGHT | ✅ Optional | Height in pixels |
| FIGURE/FIG | MAXWIDTH | ✅ Optional | Maximum width constraint |
| FIGURE/FIG | MINWIDTH | ✅ Optional | Minimum width constraint |
| FIGURE/FIG | MAYDELAY | ✅ Optional | Delayed loading in ms |
| FIGURE/FIG | ISMAP | ✅ Optional | Server-side image map |
| FIGURE/FIG | FOLD | ❌ DTD only | Not implemented |
| FIGURE/FIG | LABEL | ❌ DTD only | Not implemented |
| FIGA | HREF | ✅ Required | Target URL for hotspot |
| FIGA | AREA | ✅ Required | Region coordinates "x y w h" |
| FIGDATA | — | — | No attributes |
| FIGCAP | — | — | No attributes |

## Attributes

### TYPE (required)
Specifies the image format type.

**Supported values for inline data (with FIGDATA):**
- `xbm` or `image/xbm` - X BitMap format (monochrome)
- `xpm` or `image/xpm` - X PixMap format (color)
- `gif` or `image/gif` or `image/GIF` - GIF format (Base64 encoded)
- `ps` or `application/postscript` - PostScript format (converted to GIF via ImageMagick)

**Supported values for external files (with SRC):**
- `xbm` or `image/xbm` - X BitMap format
- `xpm` or `image/xpm` - X PixMap format  
- `gif` or `image/gif` - GIF format
- `ps` or `application/postscript` - PostScript format

**Note:** GIF format requires Base64 encoding for inline data because it is a binary format. The browser decodes using the built-in `Base64DecodeToFile()` function.

### SRC (optional)
Specifies the URL of an external image file.

**Behavior:**
- If `SRC` is present, the image is loaded from the specified URL
- If `SRC` is absent, inline data from `<FIGDATA>` is used
- For GIF images, either `SRC` (external file) or Base64-encoded `FIGDATA` (inline) can be used

**Example:**
```html
<FIGURE TYPE="xbm" SRC="worldmap.xbm">
```

### WIDTH and HEIGHT (optional)
Specify the dimensions of the figure in pixels.

**Usage:**
- `WIDTH` - Width in pixels
- `HEIGHT` - Height in pixels
- If not specified or set to 0, natural dimensions of the image are used
- Can be used to scale images

**Example:**
```html
<FIGURE TYPE="xpm" SRC="icon.xpm" WIDTH="64" HEIGHT="64">
```

### MAXWIDTH and MINWIDTH (optional)
Specify constraints on the figure width.

**Usage:**
- `MAXWIDTH` - Maximum width in pixels
- `MINWIDTH` - Minimum width in pixels
- Used for responsive sizing

### MAYDELAY (optional)
Enables delayed/progressive loading of images.

**Usage:**
- Value in milliseconds
- If set, image loading can be delayed
- Used with `WIDTH` and `HEIGHT` to reserve space while loading

**Example:**
```html
<FIGURE TYPE="gif" SRC="large.gif" WIDTH="200" HEIGHT="150" MAYDELAY="2000">
```

### ISMAP (optional)
Makes the image an interactive image map (server-side).

**Behavior:**
- When present, clicking on the image sends coordinates to the server
- Format: `URL?x0,y0,x1,y1;`
- Used for interactive graphics and maps

**Example:**
```html
<FIGURE TYPE="xbm" SRC="map.xbm" ISMAP>
```

### FOLD (not implemented for FIGURE)
Collapsible/expandable section attribute.

**How it works in other elements (UL, OL, etc.):**
- When present, a folder icon (📂/📁) appears next to the element
- Clicking the icon toggles visibility of the content
- `FOLD="yes"` - initially collapsed
- `FOLD` (without value) - initially expanded

**Example (works in lists, not in FIGURE):**
```html
<UL FOLD="yes">
  <LI>This content is initially hidden</LI>
  <LI>Click folder icon to expand</LI>
</UL>
```

This is similar to HTML5 `<details>/<summary>` elements, but implemented in 1993.

**Status in FIGURE:** Declared in DTD but handler not implemented.

### LABEL (not implemented for FIGURE)
Element identifier for anchors and references.

**How it works in other elements:**
- Assigns an identifier to the element
- Can be used as anchor target for navigation

**Status in FIGURE:** Declared in DTD but handler not implemented.

## Nested Elements

### FIGDATA
Contains inline image data.

**Attributes:** None. FIGDATA has no attributes.

**Supported formats:**
- **XBM** - X BitMap C code (text)
- **XPM** - X PixMap C code (text)
- **GIF** - Base64 encoded binary data
- **PS** - PostScript code (converted to GIF via ImageMagick)

**Example - XBM:**
```html
<FIGURE TYPE="xbm" WIDTH="32" HEIGHT="32">
<FIGDATA>
#define worldmap_width 32
#define worldmap_height 32
static char worldmap_bits[] = {
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   /* ... more data ... */
};
</FIGDATA>
</FIGURE>
```

**Example - XPM:**
```html
<FIGURE TYPE="xpm" WIDTH="20" HEIGHT="20">
<FIGDATA>
/* XPM */
static char * arrow [] = {
"20 20 4 1",
"       c gray50",
".      c white",
"X      c black",
"o      c grey75",
"                    ",
" .................X ",
/* ... more lines ... */
};
</FIGDATA>
</FIGURE>
```

**Example - GIF (Base64 encoded):**
```html
<FIGURE TYPE="gif">
<FIGDATA>
R0lGODlhCAAIAIAAAP8AAAAAACH5BAAAAAAALAAAAAAIAAgAAAIKhI+py+0Po5yUFQA7
</FIGDATA>
<FIGCAP>8x8 red square GIF</FIGCAP>
</FIGURE>
```

**Example - PostScript:**
```html
<FIGURE TYPE="ps" WIDTH="200" HEIGHT="150">
<FIGDATA>
%!PS-Adobe-2.0
%%Title: Simple Drawing
%%Pages: 1
%%EndComments
%%Page: 1 1
newpath
0 0 moveto 100 0 lineto 100 150 lineto 0 150 lineto closepath
0.9 0.3 0.3 setrgbcolor fill
showpage
%%EOF
</FIGDATA>
  <FIGA HREF="http://example.com/red" AREA="0 0 100 150"></FIGA>
</FIGURE>
```

**Important notes:**
- FIGDATA content is treated as literal text (SGML_LITTERAL mode)
- Leading and trailing whitespace is automatically trimmed
- XBM/XPM: format must be valid C code that libraries can parse
- GIF: must be Base64 encoded (use `base64 < image.gif` to encode)
- PS: WIDTH and HEIGHT attributes are used to set BoundingBox for correct sizing

### FIGA
Defines a clickable region (hotspot) within the figure (client-side image map).

FIGA is an SGML empty element - the closing tag `</FIGA>` is optional.

**Attributes:**
- `HREF` - URL to navigate to when region is clicked
- `AREA` - Region coordinates: "x y width height"

**Example:**
```html
<FIGURE TYPE="xbm" SRC="worldmap.xbm">
  <FIGA HREF="http://example.com/americas" AREA="0 0 16 32"></FIGA>
  <FIGA HREF="http://example.com/europe" AREA="16 0 16 32"></FIGA>
</FIGURE>
```

**Behavior:**
- Multiple FIGA elements can be used in one FIGURE
- Hovering over a hotspot draws an inverted rectangle outline around the region
- Clicking navigates to the specified HREF
- Coordinates are relative to the top-left corner of the figure

### FIGCAP
Provides a caption for the figure.

**Attributes:** None. FIGCAP has no attributes.

**Example:**
```html
<FIGURE TYPE="xbm" SRC="worldmap.xbm">
  <FIGCAP>World Map - Click regions for more info</FIGCAP>
</FIGURE>
```

## Format Support Matrix

| Format | Inline (FIGDATA) | External (SRC) | FIGA Hotspots | Notes |
|--------|------------------|----------------|---------------|-------|
| XBM    | ✅ Yes           | ✅ Yes         | ✅ Yes        | Monochrome, text-based C code |
| XPM    | ✅ Yes           | ✅ Yes         | ✅ Yes        | Color, text-based C code |
| GIF    | ✅ Yes (Base64)  | ✅ Yes         | ✅ Yes        | Binary format, requires Base64 encoding |
| PS     | ✅ Yes           | ✅ Yes         | ✅ Yes        | Converted to GIF via ImageMagick |

## Implementation Details

### Processing Flow

**For inline data (no SRC):**
1. HTML parser collects FIGDATA content
2. Content is stored in the figure's `label` attribute
3. Parser calls case "D" which triggers case "make"
4. Appropriate handler (HTML_xbm, HTML_xpm, or HTML_ps) is cloned
5. Handler's `make` method processes the data:
   - Whitespace is trimmed from label
   - For XBM: `GLMakeXBMFromASCII()` parses C code
   - For XPM: `GLMakeXPMFromASCII()` parses C code
   - For PS: BoundingBox header is prepended, saved to temp file, converted via ImageMagick
6. Bitmap is created and rendered

**For external files (with SRC):**
1. Parser calls case "D" which detects SRC attribute
2. Appropriate handler (HTML_xbmf, HTML_xpmf, HTML_giff, or HTML_psf) is cloned
3. Handler's `make` method:
   - Calls `HTTPGet(url)` to download file
   - Saves to temporary local file
   - Loads image from local file
   - Cleans up temporary file
4. Image is rendered

### Class Hierarchy

**For inline data:**
- `HTML_xbm` → class `XBM` → inherits from `field`
- `HTML_xpm` → class `XPM` → inherits from `field`
- `HTML_gif_inline` → class `GIF` → Base64 decoded to GIF file via `Base64DecodeToFile()`
- `HTML_ps` → class `GIF` → PS converted to GIF via ImageMagick

**For external files:**
- `HTML_xbmf` → class `XBM` (uses file loading)
- `HTML_xpmf` → class `XPM` (uses file loading)
- `HTML_giff` → class `GIF` (uses file loading)
- `HTML_psf` → class `GIF` (PS converted to GIF via ImageMagick)

### Scripts

The following Viola scripts handle FIGURE elements:

- `HTML_figure_script.v` - Main FIGURE element handler
- `HTML_figdata_script.v` - FIGDATA sub-element handler
- `HTML_figa_script.v` - FIGA sub-element attribute parser
- `HTML_figa_actual_script.v` - FIGA hotspot interaction (hover, click)
- `HTML_xbm_script.v` - XBM inline handler (with FIGA support)
- `HTML_xpm_script.v` - XPM inline handler (with FIGA support)
- `HTML_gif_inline_script.v` - GIF inline handler with Base64 decoding (with FIGA support)
- `HTML_ps_script.v` - PostScript inline handler (with FIGA support)
- `HTML_xbmf_script.v` - XBM external file handler (with FIGA support)
- `HTML_xpmf_script.v` - XPM external file handler (with FIGA support)
- `HTML_gif_script.v` - GIF handler for IMG tag (no FIGA support)
- `HTML_giff_script.v` - GIF external file handler for FIGURE (with FIGA support)
- `HTML_psf_script.v` - PostScript external file handler (with FIGA support)

## Common Usage Examples

### Inline XBM Image
```html
<FIGURE TYPE="xbm" WIDTH="32" HEIGHT="32">
<FIGDATA>
#define icon_width 32
#define icon_height 32
static char icon_bits[] = {
   0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x80,
   /* ... */
};
</FIGDATA>
</FIGURE>
```

### Inline GIF Image (Base64)
```html
<FIGURE TYPE="gif">
<FIGDATA>
R0lGODlhIAAgAIAAAAAAAP///yH5BAAAAAAALAAAAAAgACAAAAJBhI+py+0P
o5y02ouz3rz7D4biSJbmiabqyrbuC8fyTNf2jef6zvf+DwwKh8Si8YhMKpfM
pvMJjUqn1Kr1is1qtwIAOw==
</FIGDATA>
  <FIGA HREF="/left.html" AREA="0 0 16 32"></FIGA>
  <FIGA HREF="/right.html" AREA="16 0 16 32"></FIGA>
  <FIGCAP>32x32 GIF with hotspots</FIGCAP>
</FIGURE>
```

### Inline PostScript Image
```html
<FIGURE TYPE="ps" WIDTH="200" HEIGHT="150">
<FIGDATA>
%!PS-Adobe-2.0
%%Title: Color Boxes
%%Pages: 1
%%EndComments
%%Page: 1 1
newpath 0 0 moveto 100 0 lineto 100 150 lineto 0 150 lineto closepath
0.9 0.3 0.3 setrgbcolor fill
newpath 100 0 moveto 200 0 lineto 200 150 lineto 100 150 lineto closepath
0.3 0.3 0.9 setrgbcolor fill
showpage
%%EOF
</FIGDATA>
  <FIGA HREF="/left.html" AREA="0 0 100 150"></FIGA>
  <FIGA HREF="/right.html" AREA="100 0 100 150"></FIGA>
  <FIGCAP>Click left (red) or right (blue)</FIGCAP>
</FIGURE>
```

### External GIF with Delayed Loading
```html
<FIGURE TYPE="gif" SRC="photo.gif" WIDTH="300" HEIGHT="200" MAYDELAY="1000">
  <FIGCAP>Photo (loading...)</FIGCAP>
</FIGURE>
```

### Interactive Image Map with Client-Side Hotspots
```html
<FIGURE TYPE="xbm" SRC="map.xbm">
  <FIGA HREF="/region1.html" AREA="10 10 50 50"></FIGA>
  <FIGA HREF="/region2.html" AREA="70 10 50 50"></FIGA>
  <FIGCAP>Click on a region</FIGCAP>
</FIGURE>
```

### Server-Side Image Map
```html
<FIGURE TYPE="xbm" SRC="map.xbm" ISMAP>
  <FIGCAP>Click anywhere on the map</FIGCAP>
</FIGURE>
```

### Using FIG Shorthand
```html
<FIG TYPE="xbm" SRC="icon.xbm" WIDTH="32" HEIGHT="32">
  <FIGCAP>Using FIG instead of FIGURE</FIGCAP>
</FIG>
```

## Limitations and Known Issues

1. **GIF inline requires Base64**: GIF is a binary format and must be Base64 encoded for inline embedding. The browser uses the built-in `Base64DecodeToFile()` function for decoding.

2. **Whitespace sensitivity**: Early versions had issues with whitespace in FIGDATA. Current implementation automatically trims leading/trailing whitespace.

3. **File cleanup timing**: Some handlers (like `HTML_gif_script.v`) had bugs where temporary files were deleted before rendering completed. External file handlers (with 'f' suffix) handle this correctly.

4. **PostScript conversion**: PostScript images (both inline and external) are converted to GIF via ImageMagick before display. This requires the `magick` command to be available in PATH. For inline PS, the WIDTH and HEIGHT attributes are used to set the BoundingBox.

5. **Base64 decoding is built-in**: Inline GIF decoding uses the built-in `Base64DecodeToFile()` function which wraps `HTUU_decode()` from `src/libWWW/HTUU.c`. No external commands are required.

7. **FOLD/LABEL not implemented for FIGURE**: These attributes are declared in the DTD but have no handler in `HTML_figure_script.v`. They work in other elements like `UL`, `OL`, `HTML_fld`.

## Historical Context

The FIGURE element was part of early HTML extensions proposed for ViolaWWW before the IMG tag became standardized. It provided more sophisticated features than IMG:

- Support for multiple formats
- Client-side image maps (FIGA)
- Captions (FIGCAP)
- Delayed loading
- Inline embedding of text-based formats

Many of these features were later incorporated into HTML standards (IMG tag, AREA/MAP elements for image maps, etc.).

## Original Documentation

The FIGURE element was originally proposed by Pei Y. Wei in May 1993 on the www-talk mailing list:

**[Re: Keeping HTML Simple & Format negotiation between Browser & Server](https://ksi.cpsc.ucalgary.ca/archives/WWW-TALK/www-talk-1993q2.messages/409.html)**

This email describes the original design rationale for FIGURE, FIGDATA, FIGA, FIGCAP, and ISMAP, including examples that remain valid today.


