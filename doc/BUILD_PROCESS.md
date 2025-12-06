# macOS Build Process Reference

This document describes the internal build process for creating `ViolaWWW.app` bundle and `ViolaWWW.dmg` installer.

---

## Overview

The build process consists of several stages:

```
make app          →  ViolaWWW.app (self-contained bundle)
make dmg          →  ViolaWWW.dmg (distributable installer with XQuartz)
```

ImageMagick is built automatically from source during `make app` if not already built.

---

## App Bundle Structure

The final `ViolaWWW.app` has this structure:

```
ViolaWWW.app/
├── Contents/
│   ├── Info.plist              # App metadata
│   ├── PkgInfo                 # Package type (APPL????)
│   ├── MacOS/                  # Executables
│   │   ├── vw                  # Launcher (starts XQuartz, sets env)
│   │   ├── vw.bin              # Main ViolaWWW binary
│   │   ├── sgmlsA2B            # HMML binary converter
│   │   ├── onsgmls             # SGML parser (from OpenSP)
│   │   ├── gs                  # Ghostscript
│   │   ├── magick              # ImageMagick
│   │   ├── telnet              # Telnet client
│   │   └── rlogin              # Remote login (optional)
│   ├── Frameworks/             # Dynamic libraries
│   │   ├── libssl.3.dylib
│   │   ├── libcrypto.3.dylib
│   │   ├── libMagickCore-7.*.dylib
│   │   └── ... (60+ libraries)
│   └── Resources/
│       ├── ViolaWWW.icns       # App icon
│       ├── LICENSE.md
│       ├── res/                # Viola resources
│       ├── ghostscript/        # GS fonts and resources
│       │   ├── lib/
│       │   ├── Resource/
│       │   ├── fonts/
│       │   └── iccprofiles/
│       ├── ImageMagick/        # IM config
│       │   ├── etc/
│       │   └── config-Q16HDRI/
│       └── vplot_dir/          # VPLOT resources
│           └── vplot           # VPLOT binary
```

---

## Build Stages

### Stage 1: Compile Binaries (`make`)

Standard compilation of all source files:

```bash
make -j8
```

Produces:
- `src/vw/vw` — Motif frontend
- `src/viola/viola` — Pure X11 version
- `src/viola/sgmlsA2B` — HMML converter

### Stage 2: Build Launcher (`make launcher`)

Compiles the native macOS launcher:

```bash
cc -arch arm64 -O2 -o src/launcher/launcher src/launcher/launcher.c
```

The launcher (`src/launcher/launcher.c`):
1. Detects XQuartz and starts it if needed
2. Sets environment variables (`VIOLA_PATH`, `PLOT_PATH`, `GS_LIB`, `PATH`)
3. Adds `Contents/MacOS/` to `PATH` for bundled tools
4. Executes `vw.bin` with proper environment

### Stage 3: Create App Bundle (`make app`)

#### 3.1 Create Directory Structure

```bash
mkdir -p ViolaWWW.app/Contents/{MacOS,Frameworks,Resources}
```

#### 3.2 Copy Binaries

| Source | Destination | Notes |
|--------|-------------|-------|
| `src/launcher/launcher` | `MacOS/vw` | Launcher becomes main executable |
| `src/vw/vw` | `MacOS/vw.bin` | Actual browser binary |
| `src/viola/sgmlsA2B` | `MacOS/sgmlsA2B` | HMML converter |

#### 3.3 Bundle External Tools

Each tool is copied if available:

| Tool | Source | Condition |
|------|--------|-----------|
| `onsgmls` | `/opt/homebrew/bin/onsgmls` | If OpenSP installed |
| `gs` | `$(which gs)` | If Ghostscript installed |
| `magick` | `build/imagemagick/bin/magick` | If custom build exists |
| `telnet` | Homebrew telnet | If installed |
| `rlogin` | inetutils | If installed |

#### 3.4 Bundle Resources

```bash
# Ghostscript resources
cp -r $GS_SHARE/{lib,Resource,iccprofiles,fonts} Resources/ghostscript/

# ImageMagick config (if custom build)
cp -r build/imagemagick/{etc,config-*} Resources/ImageMagick/

# Viola resources
cp -r res Resources/
cp -r vplot_dir Resources/
```

#### 3.5 Create Info.plist

Generated dynamically with:
- `CFBundleExecutable`: `vw`
- `CFBundleIdentifier`: `org.violawww.vw`
- `CFBundleIconFile`: `ViolaWWW`
- Version, copyright, etc.

#### 3.6 Bundle Dynamic Libraries (`scripts/bundle-dylibs.sh`)

This is the most complex step. The script:

**Phase 1: Collect Dependencies**

```bash
# For each binary in MacOS/
otool -L $binary | grep -E '/opt/homebrew|/usr/local' > deps.txt
```

Recursively collects all non-system dynamic libraries.

**Phase 2: Copy Libraries**

```bash
# Copy each unique library to Frameworks/
cp $lib Frameworks/$(basename $lib)
```

**Phase 3: Fix Library Paths**

For each binary and library, rewrite paths:

```bash
# Change absolute paths to relative
install_name_tool -change \
    "/opt/homebrew/lib/libssl.3.dylib" \
    "@executable_path/../Frameworks/libssl.3.dylib" \
    $binary
```

**Phase 4: Fix Library IDs**

```bash
# Set library ID to use @executable_path
install_name_tool -id \
    "@executable_path/../Frameworks/libfoo.dylib" \
    Frameworks/libfoo.dylib
```

**Phase 5: Handle @rpath References**

Some libraries use `@rpath` which must be converted:

```bash
# Replace @rpath with @executable_path/../Frameworks
install_name_tool -change \
    "@rpath/libbar.dylib" \
    "@executable_path/../Frameworks/libbar.dylib" \
    $lib
```

**Phase 6: Code Sign**

```bash
# Ad-hoc sign all binaries and libraries
codesign --force --sign - $binary
codesign --force --sign - Frameworks/*.dylib
```

#### 3.7 Strip Debug Symbols

```bash
strip -x MacOS/*
strip -x Frameworks/*.dylib
```

Reduces bundle size by ~6MB.

#### 3.8 Re-sign After Strip

```bash
codesign --force --sign - MacOS/*
codesign --force --sign - Frameworks/*.dylib
```

---

## DMG Creation

### Method 1: Simple (`make dmg`)

Calls `scripts/create-dmg.sh` which uses the `create-dmg` tool.

### Method 2: Custom (`scripts/create-dmg.sh`)

#### Step 1: Download XQuartz

```bash
curl -L --progress-bar -o dmg/XQuartz-2.8.5.pkg \
    "https://github.com/XQuartz/XQuartz/releases/download/..."
```

Cached in `dmg/` directory.

#### Step 2: Create Background Image

The script creates a retro-style background:

1. Convert `dmg/background.svg` to PNG
2. Add pixel-art globe from `src/vw/globes.xpm`
3. Add Pei-Yuan Wei photo (if `dmg/pei_sm.gif` exists)

```bash
# Create background
rsvg-convert -w 640 -h 520 background.svg > bg.png
magick bg.png -extent 4096x3072 background.png

# Add globe (pixel-perfect scaling)
magick globe.xpm -filter point -resize 48x48 globe.png
magick background.png globe.png -composite background.png
```

#### Step 3: Create DMG

```bash
create-dmg \
    --volname "ViolaWWW" \
    --volicon "resources/ViolaWWW.icns" \
    --format ULMO \                    # LZMA compression
    --background "background.png" \
    --window-size 640 580 \
    --icon "XQuartz-2.8.5.pkg" 130 190 \
    --icon "ViolaWWW.app" 320 190 \
    --app-drop-link 510 190 \
    ViolaWWW.dmg \
    build/
```

#### Step 4: Set DMG Icon

```bash
# Embed icon resource in DMG file
sips -i resources/ViolaWWW.icns
DeRez -only icns ViolaWWW.icns > icns.rsrc
Rez -append icns.rsrc -o ViolaWWW.dmg
SetFile -a C ViolaWWW.dmg
```

---

## ImageMagick Custom Build

ImageMagick is built automatically from source during `make app` if `build/imagemagick/` doesn't exist.

### Why Custom Build?

Homebrew's ImageMagick has hardcoded paths that don't work in app bundles. The custom build creates a relocatable ImageMagick that works from any location.

### Build Process (`scripts/build-imagemagick.sh`)

```bash
# Configure with temporary prefix and relocatable options
./configure \
    --prefix=/tmp/imagemagick-install \
    --disable-installed \    # Use MAGICK_HOME at runtime
    --without-modules \      # Static coders (no .so loading)
    --disable-openmp \       # Avoid libomp conflicts
    --without-x \            # No X11 dependency
    ...

# Build and install
make -j8
make DESTDIR=/tmp/install install

# Fix library paths for relocatable build using @rpath
install_name_tool -id "@rpath/libMagickCore-7.Q16HDRI.10.dylib" lib/...
install_name_tool -add_rpath "@executable_path/../lib" bin/magick
install_name_tool -add_rpath "@executable_path/../Frameworks" bin/magick

# Copy to build/imagemagick
cp -r /tmp/install/... build/imagemagick/
```

### Key Options

| Option | Purpose |
|--------|---------|
| `--without-modules` | Compile all coders into libMagickCore (no dynamic loading) |
| `--disable-installed` | Use MAGICK_HOME environment variable at runtime |
| `--disable-openmp` | Avoid conflicts with system OpenMP |
| `@rpath` | Allow library lookup in both `lib/` (testing) and `Frameworks/` (bundle) |

### Result

- 300 image formats built-in
- No module loading at runtime
- **Works from any location** (MAGICK_HOME set by launcher)

---

## Path Resolution

### How Bundled Tools Are Found

The launcher modifies `PATH`:

```c
// launcher.c
snprintf(new_path, sizeof(new_path), "%s:/opt/homebrew/bin:/usr/local/bin:%s",
         exe_dir,    // Contents/MacOS/
         old_path);
setenv("PATH", new_path, 1);
```

When Viola scripts call `system("magick ...")`, the shell finds `Contents/MacOS/magick` first.

### Environment Variables Set by Launcher

The launcher sets these variables for bundled tools:

```c
// launcher.c setup_environment()

// Ghostscript resources
setenv("GS_LIB", ".../Resources/ghostscript/lib:...", 1);
setenv("GS_FONTPATH", ".../Resources/ghostscript", 1);

// ImageMagick (relocatable build with --disable-installed)
setenv("MAGICK_HOME", ".../Resources/ImageMagick", 1);
setenv("MAGICK_CONFIGURE_PATH", ".../etc/ImageMagick-7:...", 1);
```

### How onsgmls and gs Are Found

These have custom search functions in C code:

```c
// sgmlsA2B.c, cl_PS.c
static const char* find_program(void) {
    // 1. Check executable directory (for app bundle)
    snprintf(path, sizeof(path), "%s/program", exe_dir);
    if (access(path, X_OK) == 0) return path;
    
    // 2. Fallback to common paths
    const char* paths[] = {
        "/opt/homebrew/bin/program",
        "/usr/local/bin/program",
        NULL
    };
    ...
}
```

---

## Troubleshooting

### Library Not Found at Runtime

```
dyld: Library not loaded: @executable_path/../Frameworks/libfoo.dylib
```

**Fix**: Check that `bundle-dylibs.sh` processed the library:
```bash
otool -L ViolaWWW.app/Contents/MacOS/vw.bin | grep libfoo
```

### Code Signature Invalid

```
killed: 9
```

**Fix**: Re-sign after any modification:
```bash
codesign --force --sign - ViolaWWW.app/Contents/MacOS/*
```

### ImageMagick "No Decode Delegate"

**Cause**: Using Homebrew ImageMagick instead of custom build.

**Fix**: Run `./scripts/build-imagemagick.sh` and rebuild app.

### Icon Not Showing

**Fix**: Clear icon cache:
```bash
sudo rm -rf /Library/Caches/com.apple.iconservices.store
killall Finder
```

---

## Files Reference

| File | Purpose |
|------|---------|
| `Makefile` | Main build orchestration |
| `src/launcher/launcher.c` | Native macOS launcher |
| `scripts/bundle-dylibs.sh` | Dynamic library bundling |
| `scripts/create-dmg.sh` | DMG creation with custom background |
| `scripts/build-imagemagick.sh` | ImageMagick custom build |
| `dmg/background.svg` | DMG background template |

---

## See Also

- [EXTERNAL_DEPENDENCIES.md](EXTERNAL_DEPENDENCIES.md) — External programs and environment variables
- [Main README](../README.md) — Build instructions

