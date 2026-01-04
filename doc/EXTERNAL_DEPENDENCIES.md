# External Dependencies Reference

> **ViolaWWW 4.0 Additions:**  
> - ImageMagick for PostScript-to-GIF conversion
> - `c3270` for `tn3270://` URL support
> - `telnet` bundling in app package
> - Custom program search in app bundle (`Contents/MacOS/`)
> - `MAGICK_HOME` and related environment variables

This document describes the external programs and environment variables used by ViolaWWW.

---

## External Programs

ViolaWWW invokes external programs via `system()`, `popen()`, and `execv()` calls for various functionality.

### Required for Core Features

| Program | Purpose | Invoked From | Search Path |
|---------|---------|--------------|-------------|
| `onsgmls` | SGML parser for HMML documents | `sgmlsA2B.c` | Executable directory, `/opt/homebrew/bin`, `/usr/local/bin`, `/usr/bin`, `PATH` |
| `gs` (Ghostscript) | PostScript rendering and display | `cl_PS.c` | Executable directory, `/opt/homebrew/bin`, `/usr/local/bin`, `/usr/bin`, `PATH` |

### Image Processing

| Program | Purpose | Invoked From | Search Path |
|---------|---------|--------------|-------------|
| `magick` (ImageMagick) | Convert PostScript to GIF for inline display | `HTML_psf_script.v` | `PATH` |

### Network Protocols

| Program | Purpose | Invoked From | Search Path |
|---------|---------|--------------|-------------|
| `telnet` | Handle `telnet://host` URLs | `WWWTelnetHandler_script.v` | `PATH` |
| `rlogin` | Handle `telnet://user@host` URLs (optional, legacy) | `WWWTelnetHandler_script.v` | `PATH` |
| `c3270` | Handle `tn3270://host` URLs (IBM mainframe terminal) | `HTTelnet.c` | `PATH` |
| `xterm` | Terminal emulator for telnet/rlogin sessions | `WWWTelnetHandler_script.v` | `PATH` (typically `/opt/X11/bin`) |

**Note**: `rlogin` is optional. It's only used for `telnet://user@host` URLs (with username). Without it, such URLs will fail but regular `telnet://host` URLs will work. Install via `brew install inetutils`.

**Note**: `c3270` is provided by the x3270 package. Install via `brew install x3270`.

### Mail and Printing

| Program | Purpose | Invoked From | Default Path |
|---------|---------|--------------|--------------|
| `/usr/bin/mail` | Send email (developer feedback, mailto: URLs) | `mail.c`, Viola scripts | Hardcoded |
| `/usr/bin/lpr` | Print documents | `vw.h`, Viola scripts | Hardcoded |

### Audio

| Program | Purpose | Invoked From | Default Path |
|---------|---------|--------------|--------------|
| `/usr/bin/afplay` | Play audio files (AU, AIFF, MP3, etc.) | `wwwHandlerDispatch_script.v` | Hardcoded |

### Image Editors (Optional)

| Program | Purpose | Invoked From | Search Path |
|---------|---------|--------------|-------------|
| `bitmap` | Edit XBM images (X11 bitmap editor) | `VWHandler_xbm_script6.v` | `PATH` |
| `pixmap` | Edit XPM images | `VWHandler_xpm_script6.v` | `PATH` |
| `xv` | External image viewer | `wwwHandlerDispatch_script.v` | `PATH` |

### System Utilities

These standard Unix utilities are used by Viola scripts:

| Program | Purpose |
|---------|---------|
| `rm` | Remove temporary files |
| `mv` | Move/rename files |
| `finger` | Query user information |

---

## Environment Variables

### Core Configuration

| Variable | Purpose | Default | Used By |
|----------|---------|---------|---------|
| `VIOLA_PATH` | Path to Viola resource files (`res/` directory) | None (required) | `viola.c` |
| `PLOT_PATH` | Path to VPLOT resources (`vplot_dir/`) | None | `launcher.c` |
| `VIOLA_SGMLSA2B` | Path to sgmlsA2B executable for HMML processing | None | `VWHandler_hmml_script.v` |
| `WWW_HOME` | Home page URL loaded at startup | None | `vw.c` |
| `WWW_LPR` | Custom print command | `/usr/bin/lpr` | `VWHandler_html_script6.v` |
| `HOME` | User home directory for config files (`~/.viola_history`) | System default | `vw_stubs.c` |
| `TMPDIR` | Temporary directory for file operations | `/tmp` | `wwwSecurity_script.v` |

### Display

| Variable | Purpose | Default | Used By |
|----------|---------|---------|---------|
| `DISPLAY` | X11 display server connection | `:0` (XQuartz) | `launcher.c`, X11 libraries |

### Network Protocols

| Variable | Purpose | Default | Used By |
|----------|---------|---------|---------|
| `NNTPSERVER` | NNTP server hostname for `news:` URLs | None | `HTNews.c` |
| `USER` | Username for anonymous FTP password | None | `HTFTP.c` |

### Ghostscript

| Variable | Purpose | Default | Used By |
|----------|---------|---------|---------|
| `GS_LIB` | Ghostscript library/resource paths | None | Ghostscript (`gs`) |
| `GS_FONTPATH` | Additional font search paths | None | Ghostscript (`gs`) |
| `GHOSTVIEW` | Ghostscript viewer preference | None | Legacy |

### VPLOT

| Variable | Purpose | Default | Used By |
|----------|---------|---------|---------|
| `VPLOT_SCALE` | Scale factor for 3D rendering (e.g., `2.0`) | `1.0` | `vplot.c` |

### System

| Variable | Purpose | Default | Used By |
|----------|---------|---------|---------|
| `PATH` | Search path for external programs | System default | All `system()` calls |
| `PRINTER` | Default printer name | System default | Print functionality |

### Debugging (Development)

| Variable | Purpose | Used By |
|----------|---------|---------|
| `YYDEBUG` | Enable parser debugging output | `viola.c` |
| `MallocGuardEdges` | macOS memory debugging | Development |
| `MallocScribble` | macOS memory debugging | Development |
| `MallocStackLogging` | macOS memory debugging | Development |

---

## Program Search Logic

### onsgmls and gs

These programs use a custom search function that checks paths in order:

```c
static const char* find_program(void) {
    // 1. Same directory as the ViolaWWW executable
    // 2. /opt/homebrew/bin/<program>
    // 3. /usr/local/bin/<program>
    // 4. /usr/bin/<program>
    // 5. Fallback to PATH lookup
}
```

This allows bundled executables (in `.app/Contents/MacOS/`) to be found first.

### Other Programs

All other external programs are found via the standard `PATH` environment variable. The launcher prepends the application's `MacOS/` directory to `PATH`, so bundled executables take precedence.

---

## Platform-Specific Notes

### macOS

- XQuartz is required for X11 support (`DISPLAY` environment)
- `telnet` is not included in macOS by default; install via `brew install telnet`
- `rlogin` has been removed from modern macOS (deprecated protocol)
- Audio playback uses native `afplay` command

### Homebrew Paths

ViolaWWW checks both Intel (`/usr/local/bin`) and Apple Silicon (`/opt/homebrew/bin`) Homebrew paths.

### App Bundle

When running from `ViolaWWW.app`, the launcher:
1. Sets `VIOLA_PATH` to `Contents/Resources/res`
2. Sets `PLOT_PATH` to `Contents/Resources/vplot_dir`
3. Sets `GS_LIB` and `GS_FONTPATH` for bundled Ghostscript
4. Prepends `Contents/MacOS` to `PATH`

---

## Installation Requirements

### Required

| Dependency | Installation | Purpose |
|------------|--------------|---------|
| XQuartz | [xquartz.org](https://www.xquartz.org/) | X11 display server |

### Optional (for full functionality)

| Dependency | Installation | Purpose |
|------------|--------------|---------|
| Ghostscript | `brew install ghostscript` | PostScript support |
| ImageMagick | `brew install imagemagick` | PS-to-GIF conversion |
| OpenSP | `brew install open-sp` | HMML document support |
| telnet | `brew install telnet` | `telnet://host` URL support |
| inetutils | `brew install inetutils` | `telnet://user@host` URLs (provides `rlogin`) |
| x3270 | `brew install x3270` | `tn3270://host` URL support (provides `c3270`) |

**Note**: `telnet` and `inetutils` conflict (both provide telnet binary). Use `brew install --force inetutils` to install alongside telnet, or choose one. The `rlogin` program from inetutils is optional — only needed for telnet URLs with username.

---

## See Also

- [TTY_REFERENCE.md](TTY_REFERENCE.md) — Running external programs from Viola scripts
- [HMML_REFERENCE.md](HMML_REFERENCE.md) — HMML processing pipeline
- [SOUND_REFERENCE.md](SOUND_REFERENCE.md) — Audio playback
- [VPLOT_REFERENCE.md](VPLOT_REFERENCE.md) — 3D visualization

