# ViolaWWW Version 4.0 Beta

**January 2025**

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
- UTF-8 transliteration to Latin/ASCII (Cyrillic, German, Polish → readable text)
- Socket timeouts and improved error handling
- Modern build system with parallel compilation

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
- Full compatibility with modern 64-bit systems (x86_64, ARM64)
- Fixed pointer size issues (32-bit → 64-bit)
- Updated integer types for proper memory addressing
- Tested on macOS (Apple Silicon M3)
- Maintained backward compatibility with build system

#### HTTPS/TLS Support
- Native SSL/TLS via OpenSSL 3.x
- TLS 1.0+ with SNI (Server Name Indication)
- Automatic protocol detection for `https://` URLs
- Secure connections to modern websites
- **Files**: `HTSSL.h`, `HTSSL.c`, `HTTPS.h`, `HTTPS.c`

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
- **Test**: `test/test_wayback.c`

#### UTF-8 Transliteration Support
- Automatic UTF-8 to Latin/ASCII conversion via ICU library
- Two-pass transliteration: Any-Latin → ISO-8859-1
- Converts Cyrillic → Latin (яфй → âfj)
- Converts special characters (• → o, — → -)
- Preserves Latin diacritics (ö, ß, Ł, ó, ź, ś)
- **Files**: `HTCharset.h`, `HTCharset.c`
- **Test**: `test/test_htcharset.c` (German, Polish, Russian)

#### Infrastructure Improvements
- 64-bit architecture support (from 32-bit original)
- Socket timeouts (30s for HTTP/HTTPS, 5s for Wayback API)
- Parallel compilation support (`make -j`)
- Comprehensive test suite (`make test`)
- Enhanced error handling and logging
- Buffer overflow protection (increased URL buffer sizes)
- Memory safety improvements for modern systems

---

## Quick Start

### Requirements

- **System**: Unix/Linux/macOS with X11
- **Display**: X11R5 or later (XQuartz on macOS)
- **Optional**: Motif toolkit for enhanced GUI
- **For HTTPS**: OpenSSL 3.x (`brew install openssl@3` on macOS)

### Building

```bash
# Clone the repository
git clone https://github.com/bolknote/violawww.git
cd violawww

# Install dependencies (macOS)
brew install openssl@3

# Compile (parallel build)
make clean
make -j8

# Run tests
make test
```

Two binaries will be generated:
- `src/viola/viola` - Pure XLib version (smaller, no Motif required)
- `src/vw/vw` - Motif version (polished GUI)

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
│   │   ├── HTWayback.c                 # Archive integration
│   │   ├── HTCharset.c                 # Character encoding
│   │   └── HTAccess.c                  # Access manager
│   ├── viola/                          # Pure X11 browser
│   └── vw/                             # Motif browser
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
socket() + connect() (TCP)
  ↓
HTSSL_connect() (TLS handshake)
  ↓
HTSSL_write() (HTTP request over TLS)
  ↓
HTSSL_read() (HTTP response over TLS)
  ↓
Parse & Render
```

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
- Ported to 64-bit architectures (x86_64, ARM64/Apple Silicon)
- HTTPS/TLS support with OpenSSL integration
- HTTP redirect handling (3xx status codes)
- Internet Archive (Wayback Machine) integration
- UTF-8 transliteration to Latin/ASCII (ICU-based)
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

