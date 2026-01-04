# ViolaWWW Version 4.0 Beta

**October 2025**

---

## Overview

ViolaWWW is an extensible World Wide Web hypermedia browser, originally created by Pei-Yuan Wei in the early 1990s. Based on the Viola scripting language and toolkit, ViolaWWW was one of the first graphical web browsers and pioneered many features that became standard in modern browsers.

### Historical Context

**ViolaWWW (1990-1995)** - Created by Pei-Yuan Wei at UC Berkeley and O'Reilly & Associates
- 1990: Initial Viola toolkit development
- 1992: First ViolaWWW browser release (predated Mosaic)
- 1993-1995: Version 3.x series with HTML 3.0 support, scripting, stylesheets
- Features ahead of its time: embedded scripts, dynamic toolbars, stylesheet mechanism

**ViolaWWW 4.0 (2025)** - Modern enhancements by Evgeny Stepanischev
- Ported to 64-bit architectures (from original 32-bit)
- HTTPS/TLS support via OpenSSL
- HTTP redirect handling (301, 302, 303, 307, 308)
- Internet Archive (Wayback Machine) integration
- Proto-VRML graphics tags implementation (GRAPHICS, ROT, SCALE, etc.)
- HTML+ CHANGED tag for document revision tracking (yellow background highlighting)
- Multi-encoding support with transliteration (Windows-1251, KOI8-R, UTF-8 → Latin/ASCII)
- Socket timeouts and improved error handling
- Modern build system with parallel compilation
- STG stylesheet support
- Bug fixes including buffer overflow issues and other security improvements

This version brings ViolaWWW into the modern web era while preserving its unique extensible architecture and historical significance.

---

## Key Features

### Original ViolaWWW Features (v3.3)

* **HTML 3.0 Support** - Container-based document model with extensions for:
  - Multiple column formatting
  - Client-side document insertion
  - Dynamically collapsable/expandable lists

* **Sidebar Panel** - Display meta information and navigational links

* **Dynamic Toolbar** - Document-engaged tool applets

* **Stylesheet Mechanism** - Attach styling to documents (fonts, colors, alignments)

* **Scripting Language** - Embed highly interactive scripts/applets in HTML

* **Motif Front-end** - Plus X11-only version for systems without Motif

* **Hotlist Facility** - With HTTP loading progress visualization

* **Experimental Platform** - Source available, highly customizable

### Modern Enhancements (v4.0 - 2025)

#### 64-bit Architecture Port
- Full compatibility with modern 64-bit ARM64 systems (Apple Silicon)
- Fixed pointer size issues (32-bit → 64-bit)
- Updated integer types for proper memory addressing
- Tested on macOS (Apple Silicon M3)
- Maintained backward compatibility with build system

#### Interface Restoration
- Restored original browser appearance from author's drafts and code comments
- Removed non-functional UI elements and placeholder buttons
- Fixed window dimensions and layout to match intended design
- Enabled previously commented-out working features
- Result: Clean interface matching the original vision for ViolaWWW 3.x

#### HTTPS/TLS Support
- Native SSL/TLS via OpenSSL 3.x
- TLS 1.0+ with SNI (Server Name Indication)
- Automatic protocol detection for `https://` URLs
- Secure connections to modern websites
- **Files**: `HTSSL.h`, `HTSSL.c`, `HTTPS.h`, `HTTPS.c`

#### HTTP Keep-Alive Connection Manager
- Connection pooling and reuse for improved performance
- Automatic keep-alive detection via HTTP headers
- Connection pool (max 6 concurrent connections)
- Configurable timeout (default 30 seconds)
- Automatic cleanup of stale connections
- Reduces latency for multiple requests to same host
- **Files**: `HTKeepAlive.h`, `HTKeepAlive.c`

#### HTTP Redirect Handling
- Automatic following of redirects: 301, 302, 303, 307, 308
- Cross-protocol redirects (HTTP ↔ HTTPS)
- Loop prevention (max 10 hops)
- Relative URL resolution
- **Files**: `HTTP.c`, `HTTPS.c`

#### Internet Archive Integration
- Automatic fallback to Wayback Machine for unavailable domains
- DNS failure detection triggers archive search
- CDX API integration for earliest snapshots
- Transparent loading of archived sites with proper base URL handling
- **Files**: `HTWayback.h`, `HTWayback.c`
- **Tests**: `test/test_wayback.c`, `test/test_wayback_detection.c`

#### Multi-Encoding Transliteration Support
- Automatic character encoding detection from HTTP headers (`x-archive-guessed-charset`, `Content-Type`)
- Support for multiple encodings: UTF-8, Windows-1251, KOI8-R, ISO-8859-1, and more
- Three-pass conversion pipeline:
  1. Source encoding → UTF-8 (via iconv with //IGNORE for mixed bytes)
  2. Any-Latin transliteration (Cyrillic, Greek, Chinese → Latin via ICU)
  3. UTF-8 → ISO-8859-1//TRANSLIT for ASCII compatibility
- Converts Cyrillic → Latin (Привет → Privet, яфй → âfj)
- Converts special characters (• → *, → → ->, — → -)
- Preserves Latin diacritics (ö, ß, Ł, ó, ź, ś)
- **Files**: `HTCharset.h`, `HTCharset.c`, `HTAnchor.h`, `HTAnchor.c`, `HTMIME.c`, `SGML.c`
- **Test**: `test/test_htcharset.c` (German, Polish, Russian, Windows-1251, KOI8-R)

#### NNTP News Protocol Improvements
- **New URL schemes**: `nntp://host/group` and `news://host/group` for direct server access
- No need to set `NNTPSERVER` environment variable when using URL with host
- Article access by number: `nntp://host/group/article-number`
- RFC 2047 MIME encoded-word decoding in article headers (Subject, From, etc.)
- Transliteration of non-ASCII characters in newsgroup listings and articles
- Example: `=?UTF-8?Q?J=C3=B6rg?=` → "Jörg" (Latin diacritics preserved in ISO-8859-1)
- Supports both Quoted-Printable (`?Q?`) and Base64 (`?B?`) encodings
- Fixed EOF handling for `-funsigned-char` compiler flag
- Proper connection cleanup after each request (prevents hangs)
- **Files**: `HTNews.c`, `HTCharset.c`
- **Documentation**: [PROTOCOLS_REFERENCE.md](doc/PROTOCOLS_REFERENCE.md)

#### Mathematical Expression Rendering
- Native rendering of mathematical HTML entities and expressions
- Supported entities: `&pi;` (π), `&sigma;` (Σ), `&infin;` (∞), `&integral;` (∫)
- Subscripts and superscripts with proper scaling and positioning
- Fraction rendering with horizontal division lines
- Parentheses and brackets that scale to content height
- Complex nested expressions with proper layout and alignment
- Vector graphics rendering for integral symbol using X11 drawing primitives
- Automatic scaling of symbols in superscript/subscript contexts
- **Files**: `htmath.h`, `htmath.c`, `embeds/HTML_math_script.v`
- **HTML Tag**: `<MATH>` element support

#### HTML+ CHANGED Tag (Document Revision Tracking)
- Implementation of HTML+ (1993) `<CHANGED>` element for marking document revisions
- Paired marker syntax: `<changed id=X>text<changed idref=X>` (not a container tag)
- Visual highlighting with LemonChiffon1 (pale yellow) background
- Spans across structural boundaries (paragraphs, lists, headers)
- Preserves original text color (compatible with stylesheets)
- **Files**: `html2.c`, `sgml.c`, `tfed.c`, `glib_x.c`
- **Documentation**: [CHANGED_TAG_REFERENCE.md](doc/CHANGED_TAG_REFERENCE.md)

#### Proto-VRML Graphics Tags (Full Implementation)
- Implementation of Pei-Yuan Wei's 1994 experimental 3D graphics proposal
- Container: `<GRAPHICS>` with WIDTH, HEIGHT attributes
- Primitives: `<RECT>`, `<SQUARE>`, `<CIRCLE>`, `<OVAL>`, `<LINE>`, `<POLYGON>`, `<POINT>`, `<TEXT>`
- Text rendering: `<TEXT LABEL="...">` with XRender-based rotation and scaling
- Positioning and sizing: `<POS>`, `<SIZE>` with X, Y, Z coordinates
- 3D transformations with perspective projection:
  - `<ROT X=... Y=... Z=...>` — rotation around all three axes
  - `<SCALE X=... Y=... Z=...>` — scaling with perspective
  - `<AXIS>` — transformation center point
- Colors: `<FGCOLOR>`, `<BGCOLOR>`, `<BDCOLOR>` with named colors
- Interactive elements: `<BUTTON>` with LABEL, HREF, HINT attributes (3D appearance, click handling, status bar hints)
- Interactive scripting: `<ACTION>` with inline `<SCRIPT TYPE="viola">` for all shapes
- Multi-user sync: `SC` attribute for real-time property synchronization via UDP broadcast
- **Files**: `embeds/HTML_graphics_script.v`, `HTML_button_script.v`, `HTML_rect_script.v`, `HTML_polygon_script.v`, etc.
- **Documentation**: [GRAPHICS_TAGS_REFERENCE.md](doc/GRAPHICS_TAGS_REFERENCE.md)

#### TTY Interface Restoration
- Restored inter-process communication via TTY class
- Run external programs and capture their output
- Bidirectional communication with child processes
- Configurable delimiters for output parsing
- **Documentation**: [TTY_REFERENCE.md](doc/TTY_REFERENCE.md)

#### VPLOT 3D Surface Plotter
- Interactive 3D surface and wireframe model viewer
- Mathematical expression parser (sin, cos, exp, sqrt, abs, etc.)
- Real-time rotation via sliders or mouse drag
- Support for OFF file format (3D models)
- HiDPI/Retina display support
- **Files**: `examples/plot.v`, `examples/vplot.v`
- **Documentation**: [VPLOT_REFERENCE.md](doc/VPLOT_REFERENCE.md)

#### macOS Distribution
- Native macOS application bundle (ViolaWWW.app)
- Standalone launcher with automatic XQuartz detection and startup
- Dynamic library bundling (no Homebrew required at runtime)
- DMG installer with retro-style background and XQuartz package
- Universal support for Finder launch and terminal execution
- **Files**: `src/launcher/launcher.c`, `scripts/bundle-dylibs.sh`, `scripts/create-dmg.sh`

#### Infrastructure Improvements
- 64-bit architecture support (from 32-bit original)
- Socket timeouts (30s for HTTP/HTTPS, 5s for Wayback API)
- Parallel compilation support (`make -j`)
- Comprehensive test suite (`make test`)
- Enhanced error handling and logging
- Buffer overflow protection (increased URL buffer sizes)
- Memory safety improvements for modern systems

---

## Screenshots

### ViolaWWW Motif Frontend (vw)

*Modern web browsing with the classic Motif interface*

<img src=https://github.com/user-attachments/assets/74be8482-9a0c-43a2-b415-d6f9a317bd73 width=636 height=785>

---


## Quick Start

### Requirements

#### Required Dependencies

- **X11**: XQuartz on macOS (`brew install --cask xquartz`)
- **OpenMotif**: Motif toolkit (`brew install openmotif`)
- **Byacc**: Berkeley Yacc parser generator (`brew install byacc`)

#### Optional Dependencies (Build Time)

These are linked at build time and bundled into the app:

- **OpenSSL 3.x**: For HTTPS support (`brew install openssl@3`)
- **ICU4C**: For UTF-8 transliteration (`brew install icu4c`)

#### Optional Dependencies (Runtime)

These external programs are called by ViolaWWW for specific features:

| Program | Installation | Purpose | Bundled in .app |
|---------|--------------|---------|-----------------|
| **Ghostscript** | `brew install ghostscript` | PostScript display and conversion | ✅ Yes |
| **ImageMagick** | `brew install imagemagick` or `./scripts/build-imagemagick.sh` | PostScript-to-GIF conversion | ✅ Yes (if built) |
| **OpenSP** | `brew install open-sp` | HMML document parsing (`onsgmls`) | ✅ Yes |
| **telnet** | `brew install telnet` | `telnet://host` URL support | ✅ Yes |
| **rlogin** | `brew install inetutils` | `rlogin://user@host` URLs (optional) | ✅ Yes (if available) |
| **x3270** | `brew install x3270` | `tn3270://host` URLs (IBM mainframe) | ✅ Yes (if available) |

**Note**: When building `ViolaWWW.app`, these programs are automatically bundled if available. The app bundle is self-contained and doesn't require Homebrew at runtime (only XQuartz is needed).

**Note**: Without OpenMotif, only the pure X11 version (`viola`) will be built. The Motif version (`vw`) requires OpenMotif.

### Building

```bash
# Clone the repository
git clone https://github.com/bolknote/violawww.git
cd violawww

# Install dependencies (macOS)
brew install --cask xquartz    # X11 window system (required)
brew install openmotif byacc   # Required for building
brew install openssl@3 icu4c   # HTTPS, UTF-8 transliteration
brew install ghostscript open-sp telnet x3270  # PostScript, HMML, telnet/tn3270 URLs

# Compile (parallel build)
make clean
make -j8

# Run tests
make test
```

Two binaries will be generated:
- `src/viola/viola` - Pure XLib version (smaller, no Motif required)
- `src/vw/vw` - Motif version (polished GUI)

### macOS App Bundle & DMG

Build a standalone macOS application bundle with bundled libraries:

```bash
# Build ViolaWWW.app bundle
make app

# Create distributable DMG with custom background
make dmg

# Or use custom DMG script with retro-style installer
make dmg-custom
```

The app bundle includes:
- Native macOS launcher with automatic XQuartz startup
- All required dynamic libraries bundled (no Homebrew needed at runtime)
- XQuartz installer package for easy dependency installation
- Retro-style DMG background with installation instructions

**Note**: XQuartz is still required to run ViolaWWW, but it's included in the DMG for convenience.

### Running

```bash
# Start with a URL
./src/vw/vw https://example.com

# Or use environment variable
export WWW_HOME=https://info.cern.ch
./src/vw/vw

# Pure X11 version
./src/viola/viola https://example.com
```

### X Resources

Add to `~/.Xdefaults` for better appearance:

```xdefaults
Viola.x:                550
Viola.y:                10
Viola.width:            620
Viola.height:           700
Viola*foreground:       black
Viola*background:       grey80
Viola.foreground_doc:   black
Viola.background_doc:   grey90
```

Then reload: `xrdb -load ~/.Xdefaults`

---

## Web Archive Integration

### Automatic Fallback

When a domain doesn't resolve (DNS error), ViolaWWW automatically:
1. Detects DNS failure
2. Queries Internet Archive CDX API
3. Finds the **earliest available snapshot**
4. Loads archived version transparently

### Example Usage

```bash
# Try a defunct site - will automatically load from archive
./src/vw/vw http://www.hackzone.ru/

# Browser will detect DNS failure and load:
# https://web.archive.org/web/19970327140651/http://www.hackzone.ru:80/
```

### Technical Details

- **API**: [CDX Search API](https://web.archive.org/cdx/search/cdx)
- **Query**: `/cdx/search/cdx?url=<URL>&limit=1&sort=ascending`
- **Format**: Plain text (space-separated fields)
- **Timeout**: 5 seconds for archive.org queries
- **Base URL**: Automatically updates for proper relative link resolution
- **Smart Detection**: Prevents infinite loops by detecting Web Archive URLs and skipping fallback

### Web Archive URL Detection

The system intelligently detects when a URL is already from the Web Archive to prevent infinite loops:

- ✅ Detects `https://web.archive.org/web/TIMESTAMP/URL` patterns
- ✅ Handles both HTTP and HTTPS Web Archive URLs
- ✅ Supports subdomains (e.g., `subdomain.web.archive.org`)
- ✅ Skips Wayback fallback for already-archived URLs
- ✅ Prevents recursive archive queries

---

## HTTPS Support

### Features

- ✅ TLS 1.0+ support (OpenSSL 3.x)
- ✅ SNI (Server Name Indication)
- ✅ Automatic redirect following (HTTP→HTTPS)
- ✅ Standard port 443
- ⚠️ Certificate verification disabled (for compatibility)

### Security Notes

**WARNING**: For compatibility with old/self-signed certificates, SSL certificate verification is set to `SSL_VERIFY_NONE`. This is suitable for testing and browsing trusted sites but makes connections susceptible to MITM attacks.

### Testing HTTPS

```bash
# Simple test
./src/vw/vw https://example.com

# Historic site with HTTPS
./src/vw/vw https://info.cern.ch

# With verbose logging
./src/vw/vw -v https://example.com
```

---

## HTTP/HTTPS Keep-Alive Connection Pool

### Overview

ViolaWWW 4.0 implements persistent HTTP/HTTPS connections (keep-alive) with a connection pool, significantly improving page load performance by reusing TCP/SSL connections.

### Features

- ✅ **Connection Pool**: Up to 6 concurrent persistent connections
- ✅ **Automatic Connection Reuse**: Transparent reuse for same-host requests
- ✅ **Smart Redirect Handling**: Reuses connections for same-host redirects
- ✅ **Stale Connection Detection**: Automatic detection and cleanup of broken connections
- ✅ **HTTP/1.1 Support**: Full chunked transfer encoding support
- ✅ **Content-Length Handling**: Efficient reading without waiting for EOF
- ✅ **Statistics Tracking**: Per-connection metrics (reuses, bytes, age)

### Performance Improvements

**Without Keep-Alive:**
- Each request = new TCP + SSL handshake
- HTTPS handshake: ~500-1500 ms per resource
- Page with 10 images ≈ 30-40 round trips

**With Keep-Alive:**
- Connection reuse across multiple requests
- HTTPS handshake: only once per host
- Page with 10 images ≈ 13-15 round trips
- **Speed improvement: 18-80× faster** 🚀

### Technical Details

**Connection Pool Management:**
- Maximum 6 simultaneous connections (HTTP/1.1 spec)
- Idle timeout: 30 seconds
- Automatic cleanup of expired/broken connections
- Thread-safe design (single-threaded for now)

**Protocol Compliance:**
- HTTP/1.0: Keep-Alive with Content-Length
- HTTP/1.1: Keep-Alive with chunked encoding
- Graceful fallback for non-supporting servers

**Socket Timeouts:**
- Connect: 30 seconds
- Read (with Content-Length): 60 seconds
- Read (chunked): 10 seconds between chunks
- Read (no length): 60 seconds until EOF

### Debug Mode

Enable verbose logging to see connection statistics:

```bash
./src/vw/vw -v https://example.com
```

Output will show:
```
HTKeepAlive: Reusing HTTPS connection to example.com:443 (reuse #3)
HTTPS: Downloaded 8796 bytes in 1066 ms (8.1 KB/s, connect: 0 ms)
HTKeepAlive: Stored HTTPS connection (reuses=3, requests=4, bytes=25680)
```

### Architecture

**New Files:**
- `src/libWWW/Library/Implementation/HTKeepAlive.h` - Connection pool API
- `src/libWWW/Library/Implementation/HTKeepAlive.c` - Pool implementation

**Modified Files:**
- `src/libWWW/Library/Implementation/HTTPS.c` - HTTPS with keep-alive
- `src/libWWW/Library/Implementation/HTTP.c` - HTTP with keep-alive
- `src/viola/viola.c` - Pool initialization

### Limitations

1. Maximum 6 connections per pool
2. 30-second idle timeout
3. Some servers (e.g., web.archive.org) inconsistently support keep-alive

---

## Testing

### Run All Tests

```bash
make test
```

### Individual Tests

```bash
# Character set conversion
./test/test_htcharset

# Web Archive integration
./test/test_wayback

# Web Archive URL detection
./test/test_wayback_detection

# HTTPS functionality (manual)
./src/vw/vw test_https.html
```

---

## Architecture

### Directory Structure

```
violawww2/
├── src/
│   ├── libWWW/Library/Implementation/  # WWW protocol library
│   │   ├── HTTP.c, HTTPS.c             # HTTP/HTTPS clients
│   │   ├── HTSSL.c                     # SSL/TLS wrapper
│   │   ├── HTKeepAlive.c               # Connection manager
│   │   ├── HTWayback.c                 # Archive integration
│   │   ├── HTCharset.c                 # Character encoding
│   │   └── HTAccess.c                  # Access manager
│   ├── libIMG/                         # Image handling (GIF, XBM, XPM, etc)
│   ├── libStyle/                       # Stylesheet processing
│   ├── libXPA/                         # X Pixmap Applets
│   ├── libXPM/                         # X Pixmap library
│   ├── viola/                          # Viola toolkit & core browser
│   └── vw/                             # ViolaWWW Motif frontend
├── test/                               # Unit tests
├── Makefile                            # Main build file
└── README.md                           # This file
```

### Protocol Flow

```
User Request (https://example.com)
  ↓
HTAccess.c (protocol dispatcher)
  ↓
HTTPS.c (HTTPS protocol handler)
  ↓
HTKeepAlive.c (connection manager)
  ├─ Check for existing connection
  ├─ Reuse if available & valid
  └─ Create new if needed
  ↓
socket() + connect() (TCP)
  ↓
HTSSL_connect() (TLS handshake)
  ↓
HTSSL_write() (HTTP request over TLS)
  ↓
HTSSL_read() (HTTP response over TLS)
  ↓
Connection returned to pool (keep-alive)
or closed (Connection: close)
  ↓
Parse & Render
```

---

## HMML Support (Legacy Format)

ViolaWWW originally supported **HMML** (HyperMedia Markup Language) — Pei-Yuan Wei's experimental markup language that predated/paralleled HTML in the early 1990s.

### What is HMML?

HMML was ViolaWWW's native document format with elements like:
- `HMML` (root), `BODY`, `SECTION`, `TITLE`
- `H1-H3` headers, `P` paragraphs
- `PIC`, `XBM`, `XPM` for images
- `VOBJF` for embedded Viola objects
- `LISTING`, `EXAMPLE`, `QUOTE`

### File Extensions

- `.hmml` — text HMML documents (require SGML parsing)
- `.hmmlb` — binary HMML (pre-parsed)

### Requirements

HMML support requires the **OpenSP** SGML parser:

```bash
# macOS
brew install open-sp

# Linux (Debian/Ubuntu)
sudo apt-get install opensp
```

The `onsgmls` utility from OpenSP is used to parse HMML documents. The path is configured in `src/viola/sgmlsA2B.c` via the `SGMLS_PATH` constant (default: `/opt/homebrew/bin/onsgmls`).

### Note

HMML is essentially a historical curiosity. Modern web content uses HTML, which ViolaWWW parses natively without external dependencies.

---

## Known Limitations

1. **SSL/TLS**: Certificate verification disabled by default
2. **HTTP/2**: Not supported (HTTP/1.0 only)
3. **JavaScript**: Limited scripting (Viola script only)
4. **CSS**: Basic stylesheet support only
5. **Modern HTML**: HTML 3.0 era support
6. **Redirects**: No UI for redirect chains
7. **Wayback**: No cache for API results

---

## Development

### Building from Source

```bash
# Clean build
make clean
make -j$(nproc)

# Debug build
make clean
CFLAGS="-g -O0" make

# Without OpenSSL
make clean
make NO_SSL=1
```

### Code Analysis Tools

New Makefile targets for analyzing unused includes and libraries:

```bash
# Show all analysis commands
make check-help

# Quick analysis (no extra tools needed)
make check-includes-manual   # Show include hierarchy
make check-libs              # Show linked libraries
make check-symbols           # Show used symbols from libraries
make check-unused            # Build with unused code warnings

# Advanced analysis (requires include-what-you-use)
brew install include-what-you-use
make check-includes          # Analyze glib_x.c
make check-includes-all      # Analyze all sources
```

### Code Style

The codebase maintains the original ViolaWWW style:
- K&R-style C
- 4-space indentation (tabs in some areas)
- ANSI C with some C99 features
- Original libwww conventions

### Contributing

Contributions are welcome! Areas of interest:
- Modern protocol support
- Security improvements
- Character encoding
- Test coverage
- Documentation

---

## Acknowledgements

### Original ViolaWWW (1990-1995)

**Author**: Pei-Yuan Wei (wei@ora.com)  
**Organization**: O'Reilly & Associates, Inc.

**Special Thanks**:
- Tim Berners-Lee - WWW invention
- CERN team - libwww library
- Jon Blow (ORA) - Lexical analyzer
- Scott Silvey (ORA) - Motif front-end
- Terry Allen (ORA) - SGML testing
- Dale Dougherty & Tim O'Reilly - Supporting Viola at ORA
- Beta testers community

### Modern Enhancements (2025)

**Developer**: Evgeny Stepanischev (imbolk@gmail.com)

**Contributions**:
- Ported to 64-bit ARM64 architecture (Apple Silicon)
- HTTPS/TLS support with OpenSSL integration
- HTTP redirect handling (3xx status codes)
- Internet Archive (Wayback Machine) integration
- Multi-encoding support with transliteration (Windows-1251, KOI8-R, UTF-8 → Latin/ASCII via iconv + ICU)
- Character encoding detection from HTTP headers (x-archive-guessed-charset, Content-Type)
- NNTP news protocol improvements (`nntp://` and `news://` URL schemes, MIME encoded-word decoding, transliteration)
- Proto-VRML graphics tags implementation (GRAPHICS, RECT, CIRCLE, POLYGON, ROT, SCALE, SC sync, etc.)
- HTML+ CHANGED tag implementation (document revision highlighting with LemonChiffon1 background)
- TTY interface restoration for external process communication
- VPLOT 3D surface plotter implementation
- macOS app bundle with native launcher and DMG distribution
- Socket timeouts and error handling
- Modern build system improvements
- Comprehensive test suite
- Buffer overflow and memory safety fixes
- Documentation updates

---

## License

ViolaWWW is provided as-is for educational and research purposes. The original source was made available by O'Reilly & Associates. Modern enhancements (2025) maintain the same open approach.

---

## Contact

### Historical
- Original Author: Pei-Yuan Wei (`wei@ora.com`)
- Mailing List: `viola@ora.com` (historical)

### Current Maintainer
- Developer: Evgeny Stepanischev
- Email: `imbolk@gmail.com`

---

**ViolaWWW** - Pioneering the Web since 1992, enhanced for the modern era in 2025.

