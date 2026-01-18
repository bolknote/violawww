# ViolaWWW Documentation

> **Note:** The documentation set in this directory was written or compiled during the ViolaWWW 4.0 (2025) revival work. Documents marked with "Added in: ViolaWWW 4.0" describe features that were implemented or significantly enhanced in version 4.0. Documents without this marker describe features that existed in the original ViolaWWW (v3.x, 1992–1995).

This directory contains technical documentation for ViolaWWW.

---

## Creator Biography and Development History

### [PEI_YUAN_WEI_BIOGRAPHY.md](PEI_YUAN_WEI_BIOGRAPHY.md)
Biography of Pei-Yuan Wei (魏培源, 1969–2023) and the history of ViolaWWW.

Topics covered:
- Early life and education (Taiwan, Berkeley High School, UC Berkeley)
- Creation of Viola language (1990) and ViolaWWW browser (1991–1992)
- Historic correspondence with Tim Berners-Lee (1991)
- Technical innovations that pioneered modern web standards
- ViolaWWW's role in the Eolas vs. Microsoft patent case

### [CHANGELOG_HISTORY.md](CHANGELOG_HISTORY.md)
Comprehensive release history of ViolaWWW based on historical sources and announcements (1991–1995), plus the modern ViolaWWW 4.0 revival timeline (2025–2026).

Topics covered:
- Viola (pre-WWW) releases (1991)
- ViolaWWW browser era (1991–1995)
- Version milestones and feature descriptions
- Historical sources, dates, and announcements
- Known issues and technical changes per release
- ViolaWWW 4.0 revival (2025–2026)

---

## Network Protocols

### [PROTOCOLS_REFERENCE.md](PROTOCOLS_REFERENCE.md)
Complete reference for all supported URL protocols.

Topics covered:
- **HTTP** — HyperText Transfer Protocol (original, 1992)
- **HTTPS** — HTTP Secure with TLS/SSL (added in v4.0, 2025)
- **FTP** — File Transfer Protocol
- **File** — Local filesystem access
- **Gopher** — Pre-WWW distributed document system
- **News/NNTP** — Usenet newsgroup access
- **Telnet** — Remote terminal sessions
- **Rlogin** — Unix remote login
- **TN3270** — IBM mainframe terminal emulation
- **WAIS** — Wide Area Information Servers (conditional)

---

## Character Encoding & Transliteration

### [CHARSET_TRANSLITERATION.md](CHARSET_TRANSLITERATION.md)
Technical overview of the modern iconv+ICU transliteration pipeline.

Topics covered:
- Why transliteration is needed with Latin-1 rendering
- Three-pass flow (iconv → ICU chain → iconv //TRANSLIT)
- Call sites (HTTP plain text, HTML parsing, NNTP MIME headers/bodies)
- Dependencies, fallbacks, and growth/edge-case considerations

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

### [IMAGE_FORMATS.md](IMAGE_FORMATS.md)
Complete reference for all supported image formats.

Topics covered:
- **Primary formats:** GIF, XBM, XPM, PostScript
- **Additional formats (via libIMG):** PBM/PGM/PPM, Sun Rasterfile, Utah RLE, FBM, PCX, GEM, MacPaint, G3 FAX, McIDAS, CMU WM, XWD
- **HTML tags:** `<IMG>`, `<FIGURE>`, `<FIGDATA>`, `<FIGA>`, `<XBM>`, `<XPM>`
- Image processing capabilities (dithering, zoom, rotation, etc.)
- Handler classes hierarchy

### [FIGURE_REFERENCE.md](FIGURE_REFERENCE.md)
Advanced image embedding for HTML documents.

Topics covered:
- **FIGURE** element with TYPE, SRC, WIDTH, HEIGHT attributes
- **FIGDATA** — inline image data (XBM, XPM formats)
- **FIGA** — client-side image map hotspots (predated HTML AREA/MAP)
- **FIGCAP** — figure captions
- Format support: XBM, XPM, GIF, PostScript

### [CHANGED_TAG_REFERENCE.md](CHANGED_TAG_REFERENCE.md)
**CHANGED** element for document revision tracking (HTML+ specification).

Topics covered:
- HTML+ change bars specification (Dave Raggett, 1993)
- Paired markers with ID/IDREF attributes
- Current implementation status in ViolaWWW
- Full implementation plan for visual change bars
- Related tags: `<REMOVED>`, `<ADDED>`
- External references to W3C HTML+ documents

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

### [FOSI_REFERENCE.md](FOSI_REFERENCE.md)
**FOSI** (Formatting Output Specification Instance) — SGML-based stylesheet system (partial implementation).

Topics covered:
- FOSI document structure and SGML syntax
- FONT element (size, weight, posture, colors)
- INDENT element (margins, first-line indentation)
- E-I-C (Element In Context) binding mechanism
- Autonomous document format vs. stylesheet usage
- Complete examples with styling demonstrations

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
- Primitives: `<RECT>`, `<SQUARE>`, `<CIRCLE>`, `<OVAL>`, `<LINE>`, `<POLYGON>`, `<POINT>`, `<TEXT>`
- Text: `<TEXT LABEL="...">` with XRender rotation/scaling support
- Transformations: `<POS>`, `<SIZE>`, `<ROT>` (X/Y/Z with perspective), `<SCALE>`, `<AXIS>`
- Appearance: `<FGCOLOR>`, `<BGCOLOR>`, `<BDCOLOR>`
- Interactive: `<BUTTON>` with LABEL, HREF, HINT, colors
- Complete examples including 3D rotation demo and scene composition

**Multi-user sync:** `SC` attribute for real-time property synchronization via UDP broadcast.

Historical sources:
- [vrmlNotes.txt](https://web.archive.org/web/20040519161530/http://www.xcf.berkeley.edu/~wei/viola/dev/vrmlNotes.txt) — original design document
- [new tags list](https://web.archive.org/web/20040420173124/http://www.xcf.berkeley.edu/~wei/viola/new) — stylesheet additions

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

## Security

### [SECURITY_IMPLEMENTATION.md](SECURITY_IMPLEMENTATION.md)
**Complete security system implementation (v4.0).**

Topics covered:
- Two trust levels (trusted/untrusted)
- Protected operations requiring user confirmation
- Security dialog implementation
- Trusted documents list
- Files modified for security

### [SECURITY_REFERENCE.md](SECURITY_REFERENCE.md)
Analysis of ViolaWWW's original security architecture and identified vulnerabilities (v3.x).

Topics covered:
- Security levels and privilege checking (`notSecure()`)
- Global security mode (`securityMode`)
- Protected operations (`tweak()`, `loadFile()`, `exit()`, etc.)
- Critical vulnerabilities (privilege escalation, object loading)
- HTML tag security implications
- Historical context and modern security comparison

---

## Build & Integration

### [EXTERNAL_DEPENDENCIES.md](EXTERNAL_DEPENDENCIES.md)
External programs and environment variables used by ViolaWWW.

Topics covered:
- Required external programs (onsgmls, gs, magick, telnet)
- Program search paths and lookup order
- Environment variables (VIOLA_PATH, DISPLAY, GS_LIB, etc.)
- Platform-specific notes (macOS, Homebrew)
- Installation requirements

### [BUILD_PROCESS.md](BUILD_PROCESS.md)
macOS app bundle and DMG creation internals.

Topics covered:
- App bundle structure (`ViolaWWW.app`)
- Build stages (`make app`, `make dmg`)
- Dynamic library bundling (`bundle-dylibs.sh`)
- DMG creation with custom background
- ImageMagick custom build process
- Path resolution and troubleshooting

---

## Historical Context

ViolaWWW (1991–1994) was one of the first graphical web browsers and pioneered many features that later reappeared in other systems and standards:

| ViolaWWW Feature | Rough modern analogue |
|------------------|----------------|
| HMML | Alternative SGML-based markup |
| VOBJF (embedded objects) | Java applets, JavaScript |
| FIGURE element | HTML IMG |
| FIGA (image maps) | HTML AREA/MAP |
| STG stylesheets | CSS (similar in spirit) |
| FOSI stylesheets | DSSSL / XSL-FO (similar in spirit) |
| Tables | HTML 3.0 Tables |
| 3D Graphics tags | VRML, WebGL |
| TTY (external processes) | External helper processes; IPC |
| VPLOT (3D visualization) | WebGL, Three.js |
| CHANGED (revision tracking) | Track Changes (Word), Git diff |

Modern enhancements (TLS, transliteration, Wayback, etc.) are documented in the main [README.md](../README.md) under “Modern Enhancements.”

As Tim Berners-Lee noted in 1993: *"HMML is in fact already an extension of HTML for multimedia from O'Reilly."*

---

## See Also

- [Main README](../README.md) - Project overview and build instructions
- [TODO](../TODO.md) - Known issues and future enhancements
- [LICENSE](../LICENSE.md) - Licensing information
- [PEI_YUAN_WEI_BIOGRAPHY.md](PEI_YUAN_WEI_BIOGRAPHY.md) - Biography of Pei-Yuan Wei and ViolaWWW history
- [CHANGELOG_HISTORY.md](CHANGELOG_HISTORY.md) - Comprehensive release history (1991–1995)
- [CHARSET_TRANSLITERATION.md](CHARSET_TRANSLITERATION.md) - Encoding/transliteration pipeline
