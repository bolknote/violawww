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

## Attributes

### TYPE (required)
Specifies the image format type.

**Supported values for inline data (with FIGDATA):**
- `xbm` or `image/xbm` - X BitMap format (monochrome)
- `xpm` or `image/xpm` - X PixMap format (color)

**Supported values for external files (with SRC):**
- `xbm` or `image/xbm` - X BitMap format
- `xpm` or `image/xpm` - X PixMap format  
- `gif` or `image/gif` or `image/GIF` - GIF format
- `ps` or `application/postscript` - PostScript format

**Note:** GIF format does NOT support inline data (FIGDATA) because it is a binary format and HTML at the time had no mechanism for embedding binary data (like base64 encoding).

### SRC (optional)
Specifies the URL of an external image file.

**Behavior:**
- If `SRC` is present, the image is loaded from the specified URL
- If `SRC` is absent, inline data from `<FIGDATA>` is used
- For GIF images, `SRC` is **required**

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

### FOLD and LABEL (legacy)
Legacy attributes with limited or no implementation.

## Nested Elements

### FIGDATA
Contains inline image data for text-based formats (XBM, XPM).

**Supported formats:**
- **XBM** - X BitMap C code
- **XPM** - X PixMap C code

**NOT supported:**
- GIF (binary format)
- PS (typically too large)

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

**Important notes:**
- FIGDATA content is treated as literal text (SGML_LITTERAL mode)
- Leading and trailing whitespace is automatically trimmed
- The format must be valid C code that XBM/XPM libraries can parse

### FIGA
Defines a clickable region (hotspot) within the figure (client-side image map).

**Attributes:**
- `HREF` - URL to navigate to when region is clicked
- `AREA` - Region coordinates: "x y width height"

**Example:**
```html
<FIGURE TYPE="xbm" SRC="worldmap.xbm">
  <FIGA HREF="http://example.com/americas" AREA="0 0 10 10"></FIGA>
  <FIGA HREF="http://example.com/europe" AREA="20 0 10 10"></FIGA>
</FIGURE>
```

**Behavior:**
- Multiple FIGA elements can be used in one FIGURE
- Hovering over a hotspot inverts the region and shows a hint
- Clicking navigates to the specified HREF
- Coordinates are relative to the top-left corner of the figure

### FIGCAP
Provides a caption for the figure.

**Example:**
```html
<FIGURE TYPE="xbm" SRC="worldmap.xbm">
  <FIGCAP>World Map - Click regions for more info</FIGCAP>
</FIGURE>
```

## Format Support Matrix

| Format | Inline (FIGDATA) | External (SRC) | Notes |
|--------|------------------|----------------|-------|
| XBM    | ✅ Yes           | ✅ Yes         | Monochrome, text-based C code |
| XPM    | ✅ Yes           | ✅ Yes         | Color, text-based C code |
| GIF    | ❌ No            | ✅ Yes         | Binary format, no inline support |
| PS     | ❌ No            | ✅ Yes         | PostScript, typically external only |

## Implementation Details

### Processing Flow

**For inline data (no SRC):**
1. HTML parser collects FIGDATA content
2. Content is stored in the figure's `label` attribute
3. Parser calls case "D" which triggers case "make"
4. Appropriate handler (HTML_xbm or HTML_xpm) is cloned
5. Handler's `make` method processes the data:
   - Whitespace is trimmed from label
   - For XBM: `GLMakeXBMFromASCII()` parses C code
   - For XPM: `GLMakeXPMFromASCII()` parses C code
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

**For external files:**
- `HTML_xbmf` → class `XBM` (uses file loading)
- `HTML_xpmf` → class `XPM` (uses file loading)
- `HTML_giff` → class `GIF` (uses file loading)
- `HTML_psf` → class `PS` (uses file loading)

### Scripts

The following Viola scripts handle FIGURE elements:

- `HTML_figure_script.v` - Main FIGURE element handler
- `HTML_figdata_script.v` - FIGDATA sub-element handler
- `HTML_figa_script.v` - FIGA sub-element handler
- `HTML_figa_actual_script.v` - FIGA hotspot implementation
- `HTML_xbm_script.v` - XBM inline handler
- `HTML_xpm_script.v` - XPM inline handler
- `HTML_xbmf_script.v` - XBM file handler
- `HTML_xpmf_script.v` - XPM file handler
- `HTML_giff_script.v` - GIF file handler
- `HTML_psf_script.v` - PostScript file handler

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

## Limitations and Known Issues

1. **No GIF inline support**: GIF is a binary format and cannot be embedded inline without encoding schemes like base64, which ViolaWWW does not support.

2. **Whitespace sensitivity**: Early versions had issues with whitespace in FIGDATA. Current implementation automatically trims leading/trailing whitespace.

3. **File cleanup timing**: Some handlers (like `HTML_gif_script.v`) had bugs where temporary files were deleted before rendering completed. External file handlers (with 'f' suffix) handle this correctly.

4. **PostScript support**: PS support is experimental and may have limitations.

5. **Case "gif" in inline branch**: The code in `HTML_figure_script.v` lines 75-78 attempts to use `HTML_gif` for inline data, but this is incorrect as `HTML_gif` lacks a "make" handler and cannot process inline data. This code path will fail silently.

## Historical Context

The FIGURE element was part of early HTML extensions proposed for ViolaWWW before the IMG tag became standardized. It provided more sophisticated features than IMG:

- Support for multiple formats
- Client-side image maps (FIGA)
- Captions (FIGCAP)
- Delayed loading
- Inline embedding of text-based formats

Many of these features were later incorporated into HTML standards (IMG tag, AREA/MAP elements for image maps, etc.).

## See Also

- [MATH_REFERENCE.md](MATH_REFERENCE.md) - Mathematical notation support
- [STG_REFERENCE.md](STG_REFERENCE.md) - Stylesheet reference
- `examples/test_figa.html` - Interactive image map example
- `examples/test_xbm_inline2.html` - Inline XBM and XPM examples
- `examples/test_figure_ps.html` - PostScript figure example

