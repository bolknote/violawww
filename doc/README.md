# ViolaWWW Documentation

This directory contains technical documentation for ViolaWWW.

---

## Browser Interface

### [CATALOG.md](CATALOG.md)
Personal URL Catalog — a hierarchical bookmark organizer.

Topics covered:
- Creating and organizing folders and links
- Navigation and selection
- Keyboard shortcuts
- File format specification

---

## Markup Languages

ViolaWWW supports multiple markup languages and extensions.

### [HMML_REFERENCE.md](HMML_REFERENCE.md)
**HMML** (HyperMedia Markup Language) — Pei-Yuan Wei's experimental markup language that predated/paralleled HTML (1992-1994).

Topics covered:
- Historical context (quotes from Tim Berners-Lee, 1993)
- Complete tag reference (SECTION, H1-H3, P, LISTING, QUOTE, etc.)
- Inline images (XBM, XPM) and external images (PIC)
- VOBJF — embedded interactive Viola objects (precursor to Java applets)
- Binary format (.hmmlb) specification
- Processing pipeline (onsgmls → sgmlsA2B → .hmmlb)

### [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md)
Advanced image embedding for HTML documents.

Topics covered:
- **FIGURE** element with TYPE, SRC, WIDTH, HEIGHT attributes
- **FIGDATA** — inline image data (XBM, XPM formats)
- **FIGA** — client-side image map hotspots (predated HTML AREA/MAP)
- **FIGCAP** — figure captions
- Format support: XBM, XPM, GIF, PostScript

### [MATH_REFERENCE.md](MATH_REFERENCE.md)
Mathematical notation and formula rendering.

Topics covered:
- Mathematical markup syntax
- Supported operators and symbols
- Fraction, superscript, subscript support
- Formula layout and rendering

### [STG_REFERENCE.md](STG_REFERENCE.md)
Stylesheet (STG) system — predated CSS.

Topics covered:
- Stylesheet syntax and format
- Style properties and values
- Applying styles to HTML elements
- Layout control (margins, padding, positioning)

### [COLOR_REFERENCE.md](COLOR_REFERENCE.md)
Complete color specification guide.

Topics covered:
- X11 color names (over 600 colors supported)
- Basic, extended, and grey scale colors
- Light and dark color variants
- Usage in STG stylesheets, Viola objects, and VPLOT
- Color attributes reference (`FGColor`, `BGColor`, `BDColor`)

### [GRAPHICS_TAGS_REFERENCE.md](GRAPHICS_TAGS_REFERENCE.md)
**Experimental 3D Graphics Tags** — Pei-Yuan Wei's 1994 proto-VRML concept, now implemented.

This was Wei's independent proposal for SGML-based 3D graphics, developed around the same time as (but separately from) the VRML specification.

Topics covered:
- Container: `<GRAPHICS>` with WIDTH, HEIGHT
- Primitives: `<RECT>`, `<CIRCLE>`, `<OVAL>`, `<LINE>`, `<POLYGON>`, `<POINT>`
- Transformations: `<POS>`, `<SIZE>`, `<ROT>` (X/Y/Z with perspective), `<SCALE>`, `<AXIS>`
- Appearance: `<FGCOLOR>`, `<BGCOLOR>`, `<BDCOLOR>`
- Complete examples including 3D rotation demo and scene composition

**Not implemented:** Interactive scripting (`<ACTION>`, `<BUTTON>`, inline `<SCRIPT>`), multi-user sync (`SC` attribute).

Historical sources:
- [vrmlNotes.txt](https://web.archive.org/web/20040519161530/http://www.xcf.berkeley.edu/~wei/viola/dev/vrmlNotes.txt) — original design document
- [new tags list](https://web.archive.org/web/20040420173124/http://www.xcf.berkeley.edu/~wei/viola/new) — stylesheet additions

---

## Multimedia

### [SOUND_REFERENCE.md](SOUND_REFERENCE.md)
Audio playback capabilities in ViolaWWW.

Topics covered:
- Viola script functions: `bell()`, `bellVolume()`
- Playing audio files in HTML (hyperlinks, `<INSERT>` tag)
- Auto-play and looping with `AFTER` attribute
- Supported audio formats (AU, AIFF, MP3, AAC, FLAC, etc.)
- macOS implementation using `afplay`

### [VPLOT_REFERENCE.md](VPLOT_REFERENCE.md)
3D surface plotter and wireframe model viewer.

Topics covered:
- Complete command reference (window, domain, equation, file, camera)
- Mathematical expression parser (sin, cos, exp, sqrt, abs)
- OFF file format specification for 3D models
- Viola TTY integration and slider controls
- HiDPI/Retina display support

---

## Programming Language

ViolaWWW includes a built-in scripting language called **Viola**.

### [VIOLA_LANGUAGE.md](VIOLA_LANGUAGE.md)
Complete language reference for Viola — the scripting language and object file format.

Topics covered:
- Object file format (`.v` files) syntax
- Widget classes (vpane, hpane, field, txtButton, etc.)
- Scripting language syntax (C-like)
- Data types, operators, control structures
- Event model and message passing
- Built-in functions overview
- Complete examples

### [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md)
Complete reference for all built-in functions in the Viola language.

Topics covered:
- HTTP Operations
- SGML/HTML Operations
- STG (Stylesheet) Operations
- String Operations
- Object Operations
- File Operations
- System Operations
- Mathematical Functions
- Input/Output Operations
- Time Functions
- Graphics Functions

All functions include parameter descriptions and return values.

### [TTY_REFERENCE.md](TTY_REFERENCE.md)
How to run external programs from Viola — a practical guide.

Topics covered:
- TTY class for inter-process communication
- Step-by-step tutorial with examples
- Complete working example (bc calculator)
- Delimiter configuration
- Environment variables and command-line arguments

---

## Historical Context

ViolaWWW (1991-1994) was one of the first graphical web browsers and pioneered many features that were later standardized:

| ViolaWWW Feature | Later Standard |
|------------------|----------------|
| HMML | Alternative SGML-based markup |
| VOBJF (embedded objects) | Java applets, JavaScript |
| FIGURE element | HTML IMG |
| FIGA (image maps) | HTML AREA/MAP |
| STG stylesheets | CSS |
| Tables | HTML 3.0 Tables |
| 3D Graphics tags | VRML, WebGL |
| TTY (external processes) | Web Workers, WebAssembly |
| VPLOT (3D visualization) | WebGL, Three.js |

As Tim Berners-Lee noted in 1993: *"HMML is in fact already an extension of HTML for multimedia from O'Reilly."*

---

## See Also

- [Main README](../README.md) - Project overview and build instructions
- [TODO](../TODO.md) - Known issues and future enhancements
- [LICENSE](../LICENSE.md) - Licensing information
