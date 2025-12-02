# ViolaWWW Documentation

This directory contains technical documentation for ViolaWWW's advanced HTML features and extensions.

## Available Documentation

### [VIOLA_FUNCTIONS.md](VIOLA_FUNCTIONS.md)
Complete reference for all built-in functions available in the Viola language.

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
- Utility Functions

All functions include parameter descriptions and return values.

### [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md)
Complete reference for the `<FIGURE>` element and related tags:
- **FIGURE** - Advanced image embedding element
- **FIGDATA** - Inline image data container (XBM, XPM formats)
- **FIGA** - Client-side image map hotspots
- **FIGCAP** - Figure captions

Topics covered:
- All attributes: TYPE, SRC, WIDTH, HEIGHT, ISMAP, MAXWIDTH, MINWIDTH, MAYDELAY
- Format support: XBM, XPM, GIF, PostScript
- Inline data vs external files
- Interactive image maps
- Implementation details

### [MATH_REFERENCE.md](MATH_REFERENCE.md)
Mathematical notation and formula rendering support in ViolaWWW.

Topics covered:
- Mathematical markup syntax
- Supported operators and symbols
- Formula layout and rendering
- Examples of complex mathematical expressions

### [STG_REFERENCE.md](STG_REFERENCE.md)
Stylesheet (STG) system reference for customizing HTML rendering.

Topics covered:
- Stylesheet syntax and format
- Style properties and values
- Applying styles to HTML elements
- Custom styling examples

### [CATALOG.md](CATALOG.md)
Personal URL Catalog — a hierarchical bookmark organizer.

Topics covered:
- Creating and organizing folders and links
- Navigation and selection
- Keyboard shortcuts
- File format specification
- Implementation notes (original vs. restored code)

### [HMML_REFERENCE.md](HMML_REFERENCE.md)
HMML (HyperMedia Markup Language) — Pei-Yuan Wei's experimental markup language that predated/paralleled HTML.

Topics covered:
- Historical context (quotes from Tim Berners-Lee, 1993)
- Complete tag reference (SECTION, H1-H3, P, LISTING, QUOTE, etc.)
- Inline images (XBM, XPM) and external images (PIC)
- VOBJF — embedded interactive Viola objects (precursor to Java applets)
- Binary format (.hmmlb) specification
- Processing pipeline (onsgmls → sgmlsA2B → .hmmlb)
- Stylesheet format

## ViolaWWW HTML Extensions

ViolaWWW implemented many pioneering features that were ahead of their time:

### HMML — HyperMedia Markup Language
- **Alternative to HTML** developed in parallel (1992-1994)
- **SGML-based** with proper DTD and validation
- **VOBJF element** — embedded interactive objects (precursor to Java applets/JavaScript)
- **Inline images** — XBM and XPM data embedded directly in documents
- **Binary compilation** — .hmml → .hmmlb for faster loading

### Image Handling
- **FIGURE element** with inline data support (text-based formats)
- **Client-side image maps** (FIGA) before HTML 3.2
- **Delayed loading** (MAYDELAY attribute)
- Multiple format support (XBM, XPM, GIF, PostScript)

### Mathematical Notation
- Native mathematical formula rendering
- Specialized math markup
- Fraction, superscript, and subscript support

### Styling System
- External stylesheet support (STG files)
- Element-specific styling rules
- Layout control (margins, padding, positioning)

### Other Features
- **VOBJ** - Embedded Viola objects
- **HPANE** - Horizontal panes
- **Interactive forms** with various input types
- **Tables** (before HTML 3.0)

## Historical Context

ViolaWWW (1991-1994) was one of the first graphical web browsers and pioneered many features that were later standardized in HTML:

- **HMML** - HyperMedia Markup Language, an SGML-based alternative to HTML
- **Embedded objects** - VOBJF predated Java applets and JavaScript
- **Images in documents** - FIGURE element predated IMG
- **Client-side image maps** - FIGA predated AREA/MAP
- **Stylesheets** - STG system predated CSS
- **Tables** - Implemented before HTML 3.0
- **Forms** - Rich form elements

As Tim Berners-Lee noted in 1993: *"HMML is in fact already an extension of HTML for multimedia from O'Reilly."*

Many of these innovations influenced the development of HTML standards and modern web browsers.

## See Also

- [Main README](../README.md) - Project overview and build instructions
- [TODO](../TODO.md) - Known issues and future enhancements
- [LICENSE](../LICENSE.md) - Licensing information

