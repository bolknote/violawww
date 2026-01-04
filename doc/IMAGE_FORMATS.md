# Image Format Support in ViolaWWW

This document describes all graphics formats supported by ViolaWWW and the HTML tags used to embed them.

## Overview

ViolaWWW supports image formats through two separate subsystems:

1. **libIMG** (xloadimage-based) — handles raster image loading for the GIF class
2. **libXPM** — handles X PixMap format (XPM version 3)
3. **Native X11** — X BitMap (XBM) format
4. **ImageMagick** — converts PostScript to GIF for display

---

## Supported Image Formats

### Primary Formats (Web Use)

| Format | MIME Type | Extension | Notes |
|--------|-----------|-----------|-------|
| **GIF** | `image/gif` | `.gif` | GIF87a and GIF89a (no animation) |
| **XBM** | `image/xbm` | `.xbm` | X BitMap — monochrome, text-based C code |
| **XPM** | `image/xpm` | `.xpm` | X PixMap — color, text-based C code |
| **PostScript** | `application/postscript` | `.ps`, `.eps` | Converted to GIF via ImageMagick |

### Additional Formats (via libIMG/xloadimage)

These formats are loaded by the libIMG library (based on xloadimage) and automatically converted for display:

| Format | Description |
|--------|-------------|
| **PBM/PGM/PPM** | Portable Bitmap/Graymap/Pixmap (NetPBM formats) |
| **Sun Rasterfile** | Sun Microsystems raster format (monochrome and color RGB) |
| **Utah RLE** | Utah Raster Toolkit format |
| **FBM** | Fuzzy Bitmap images |
| **PCX** | PC Paintbrush format |
| **GEM** | GEM Bit Image format |
| **MacPaint** | Macintosh MacPaint format |
| **G3 FAX** | Group 3 FAX images |
| **McIDAS** | McIDAS areafile format |
| **CMU WM** | CMU Window Manager raster format |
| **Faces** | Faces Project images |
| **XWD** | X Window Dump (except TrueColor/DirectColor) |
| **X10/X11 Bitmap** | X10 and X11 bitmap formats |
| **X Pixmap** | X Pixmap format (XPM1) |

---

## HTML Tags for Images

### `<IMG>` / `<IMAGE>`

The standard inline image tag. Uses the GIF class to display images.

**Attributes:**

| Attribute | Description |
|-----------|-------------|
| `SRC` | URL of the image file |
| `ALT` | Alternative text |
| `ISMAP` | Server-side image map — click sends coordinates to server |
| `WIDTH` | Display width in pixels |
| `HEIGHT` | Display height in pixels (not currently used) |
| `MAXWIDTH` | Maximum width constraint |
| `MINWIDTH` | Minimum width constraint |
| `LGAP` | Left gap (margin) |
| `RGAP` | Right gap (margin) |
| `TGAP` | Top gap (margin) |
| `BGAP` | Bottom gap (margin) |
| `HREF` | Link URL (when image is clickable) |

**Supported formats:** All formats supported by libIMG (GIF, PBM, PPM, Sun Rasterfile, etc.)

**Example:**

```html
<IMG SRC="photo.gif" ALT="A photo">
<IMG SRC="diagram.pbm" ISMAP>
```

---

### `<FIGURE>` / `<FIG>`

Extended image container with support for client-side image maps, captions, and inline data.

**Attributes:**

| Attribute | Description |
|-----------|-------------|
| `TYPE` | Image format (required for inline data) |
| `SRC` | URL of external image file |
| `WIDTH` | Display width in pixels |
| `HEIGHT` | Display height in pixels |
| `MAXWIDTH` | Maximum width constraint |
| `MINWIDTH` | Minimum width constraint |
| `MAYDELAY` | Delayed loading in milliseconds |
| `ISMAP` | Server-side image map |

**TYPE values:**

| Value | Alternative | Description |
|-------|-------------|-------------|
| `gif` | `image/gif` | GIF format |
| `xbm` | `image/xbm` | X BitMap (monochrome) |
| `xpm` | `image/xpm` | X PixMap (color) |
| `ps` | `application/postscript` | PostScript (converted to GIF) |

**Child elements:**

- `<FIGDATA>` — Contains inline image data
- `<FIGA>` — Client-side image map hotspot (with `HREF` and `AREA` attributes)
- `<FIGCAP>` — Figure caption

**Examples:**

External image:

```html
<FIGURE TYPE="gif" SRC="photo.gif">
  <FIGCAP>Photo caption</FIGCAP>
</FIGURE>
```

Inline XBM:

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

Inline GIF (Base64 encoded):

```html
<FIGURE TYPE="gif">
<FIGDATA>
R0lGODlhCAAIAIAAAP8AAAAAACH5BAAAAAAALAAAAAAIAAgAAAIKhI+py+0Po5yUFQA7
</FIGDATA>
</FIGURE>
```

Inline PostScript:

```html
<FIGURE TYPE="ps" WIDTH="200" HEIGHT="150">
<FIGDATA>
%!PS-Adobe-2.0
%%Title: Drawing
%%Pages: 1
%%EndComments
%%Page: 1 1
newpath
0 0 moveto 100 0 lineto 100 150 lineto 0 150 lineto closepath
0.9 0.3 0.3 setrgbcolor fill
showpage
%%EOF
</FIGDATA>
</FIGURE>
```

With client-side image map:

```html
<FIGURE TYPE="xbm" SRC="worldmap.xbm">
  <FIGA HREF="/americas" AREA="0 0 50 100"></FIGA>
  <FIGA HREF="/europe" AREA="50 0 50 100"></FIGA>
  <FIGCAP>Click on a region</FIGCAP>
</FIGURE>
```

---

### `<XBM>` / `<XPM>`

Direct inline image tags for X BitMap and X PixMap formats.

**Example:**

```html
<XBM>
#define icon_width 16
#define icon_height 16
static char icon_bits[] = { 0xff, 0xff, ... };
</XBM>
```

---

## Format Details

### GIF (Graphics Interchange Format)

- **Versions:** GIF87a and GIF89a signatures recognized
- **Animation:** Not supported (only first frame displayed)
- **Transparency:** Supported in GIF89a
- **Interlacing:** Supported
- **Inline:** Requires Base64 encoding in `<FIGDATA>`

### XBM (X BitMap)

- **Color depth:** 1-bit (monochrome)
- **Format:** C source code with static array
- **Inline:** Native text format, no encoding needed

```c
#define name_width 16
#define name_height 16
static char name_bits[] = { 0xff, 0xff, ... };
```

### XPM (X PixMap)

- **Versions:** XPM1 (via libIMG), XPM3 (via libXPM)
- **Color depth:** Up to 256 colors
- **Format:** C source code with color definitions
- **Transparency:** Supported (`None` color)
- **Inline:** Native text format, no encoding needed

```c
/* XPM */
static char * icon [] = {
"16 16 4 1",
"  c None",
". c #000000",
"X c #FF0000",
"o c #FFFFFF",
/* pixel data */
};
```

### PostScript

- **Conversion:** Rendered to GIF via ImageMagick `magick` command
- **Density:** 72-80 DPI
- **BoundingBox:** Automatically prepended from WIDTH/HEIGHT attributes
- **Inline:** Native text format in `<FIGDATA>`

### PBM/PGM/PPM (NetPBM)

- **PBM:** Portable Bitmap (1-bit)
- **PGM:** Portable Graymap (grayscale)
- **PPM:** Portable Pixmap (24-bit color)
- **Both ASCII and binary (raw) formats supported**

### Sun Rasterfile

- **Monochrome and color RGB variants**
- **24-bit "mondo" Sun Rasterfiles supported**

---

## Image Processing Capabilities

The libIMG library provides automatic image processing:

| Feature | Description |
|---------|-------------|
| **Dithering** | Convert color images for monochrome displays |
| **Halftoning** | Alternative to dithering |
| **Brightness** | Adjust image brightness |
| **Gamma correction** | Apply gamma curves |
| **Normalization** | Normalize color range |
| **Grayscale** | Convert to grayscale |
| **Zoom** | Scale images (X and Y independently) |
| **Rotation** | Rotate images |
| **Clipping** | Crop image regions |
| **Smoothing** | Apply smoothing filter |
| **Color reduction** | Reduce color depth |
| **Merging** | Combine multiple images |

---

## Compression Support

Images can be compressed with standard Unix utilities:

| Extension | Decompression |
|-----------|---------------|
| `.Z` | `uncompress` |
| `.gz` | `gunzip` |

The libIMG ZIO (Zipped I/O) subsystem automatically handles decompression.

---

## Handler Classes

ViolaWWW uses different handler classes for different image contexts:

### For `<IMG>` tag

| Class | Purpose |
|-------|---------|
| `HTML_img` | Wrapper that creates `HTML__img` child |
| `HTML__img` | Actual GIF display with ISMAP support |
| `GIF` | Low-level GIF rendering class |

### For `<FIGURE>` tag with external files

| Class | Format |
|-------|--------|
| `HTML_giff` | GIF files |
| `HTML_xbmf` | XBM files |
| `HTML_xpmf` | XPM files |
| `HTML_psf` | PostScript files |

### For `<FIGURE>` tag with inline data

| Class | Format |
|-------|--------|
| `HTML_gif_inline` | GIF (Base64 encoded) |
| `HTML_xbm` | XBM (C source) |
| `HTML_xpm` | XPM (C source) |
| `HTML_ps` | PostScript |

### Base classes

| Class | Purpose |
|-------|---------|
| `GIF` | Renders GIF images (used by all GIF/PS handlers) |
| `XBM` | Renders X BitMap images |
| `XPM` | Renders X PixMap images |

---

## Historical Notes

### FIGURE vs IMG

The `<FIGURE>` element was proposed by Pei-Yuan Wei in May 1993, predating the standardization of the `<IMG>` tag. It provided features later adopted in HTML standards:

- Client-side image maps (`<FIGA>`) → HTML `<MAP>` + `<AREA>`
- Captions (`<FIGCAP>`) → HTML5 `<figcaption>`
- Type negotiation → HTTP Content-Type

### xloadimage Heritage

The libIMG library is derived from xloadimage by Jim Frost (1989-1991). ViolaWWW uses a modified version wrapped as `libxli.c` to provide an API for Viola's graphics subsystem.

---

## See Also

- [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md) — Detailed FIGURE element documentation
- [GRAPHICS_TAGS_REFERENCE.md](GRAPHICS_TAGS_REFERENCE.md) — 2D/3D vector graphics tags
- [VPLOT_REFERENCE.md](VPLOT_REFERENCE.md) — 3D surface/wireframe plotter
- [COLOR_REFERENCE.md](COLOR_REFERENCE.md) — Named color values

