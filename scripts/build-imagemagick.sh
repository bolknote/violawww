#!/bin/bash
# Build ImageMagick from source with paths for ViolaWWW.app bundle
# Run this script once before 'make app' to enable bundled ImageMagick
#
# Usage: ./scripts/build-imagemagick.sh
#
# Requirements:
#   - Xcode Command Line Tools
#   - Homebrew with: brew install libtool pkg-config jpeg-turbo libpng libtiff webp \
#                    little-cms2 freetype fontconfig glib libzip xz openjpeg openexr liblqr

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

# ImageMagick version
IM_VERSION="7.1.2-9"
IM_URL="https://imagemagick.org/archive/ImageMagick-${IM_VERSION}.tar.gz"

# Installation prefix - with --disable-installed, ImageMagick looks for configs
# relative to the executable, so this prefix is only used during build
INSTALL_PREFIX="/tmp/imagemagick-install"

# Build directory
BUILD_DIR="/tmp/imagemagick-build-$$"
INSTALL_DIR="$PROJECT_DIR/build/imagemagick"
CACHE_DIR="$PROJECT_DIR/build/downloads"
ARCHIVE_FILE="$CACHE_DIR/ImageMagick-${IM_VERSION}.tar.gz"

echo "=== Building ImageMagick ${IM_VERSION} for ViolaWWW ==="
echo "Install prefix: $INSTALL_PREFIX"
echo "Build output: $INSTALL_DIR"
echo ""

# Create directories
mkdir -p "$BUILD_DIR"
mkdir -p "$INSTALL_DIR"
mkdir -p "$CACHE_DIR"

# Download source (if not cached)
if [ -f "$ARCHIVE_FILE" ]; then
    echo "Using cached archive: $ARCHIVE_FILE"
else
    echo "Downloading ImageMagick..."
    curl -L --progress-bar "$IM_URL" -o "$ARCHIVE_FILE"
fi

# Extract
echo "Extracting..."
cd "$BUILD_DIR"
tar -xzf "$ARCHIVE_FILE"
cd ImageMagick-*

# Configure with statically-linked coders (no module loading needed)
# This embeds all image format support directly into libMagickCore
echo "Configuring (with static coders)..."
PKG_CONFIG_PATH="/opt/homebrew/lib/pkgconfig:/opt/homebrew/opt/jpeg-turbo/lib/pkgconfig:/opt/homebrew/opt/libpng/lib/pkgconfig" \
LDFLAGS="-L/opt/homebrew/lib" \
CPPFLAGS="-I/opt/homebrew/include" \
./configure \
    --prefix="$INSTALL_PREFIX" \
    --disable-installed \
    --without-modules \
    --without-x \
    --disable-openmp \
    --disable-docs \
    --without-perl \
    --without-raqm \
    --without-djvu \
    --without-jxl \
    --without-heic \
    --without-raw \
    --without-gvc \
    --enable-shared \
    --disable-static \
    --quiet

# Build
echo "Building (this may take a few minutes)..."
make -j$(sysctl -n hw.ncpu) --quiet

# Install to local directory
echo "Installing..."
make DESTDIR="$BUILD_DIR/install" install --quiet

# Copy to project build directory
echo "Copying to $INSTALL_DIR..."
rm -rf "$INSTALL_DIR"
cp -r "$BUILD_DIR/install$INSTALL_PREFIX" "$INSTALL_DIR"

# Fix dylib paths to be relocatable using @loader_path
echo "Fixing library paths for relocatable build..."

# Fix library IDs (use @rpath for flexibility)
for lib in "$INSTALL_DIR/lib/"*.dylib; do
    [ -f "$lib" ] || continue
    libname=$(basename "$lib")
    install_name_tool -id "@rpath/$libname" "$lib" 2>/dev/null || true
done

# Fix references in libraries
for lib in "$INSTALL_DIR/lib/"*.dylib; do
    [ -f "$lib" ] || continue
    otool -L "$lib" 2>/dev/null | grep "$INSTALL_PREFIX" | awk '{print $1}' | while read dep; do
        depname=$(basename "$dep")
        install_name_tool -change "$dep" "@rpath/$depname" "$lib" 2>/dev/null || true
    done
done

# Fix references in binaries and add rpath
for bin in "$INSTALL_DIR/bin/"*; do
    [ -f "$bin" ] || continue
    [ -x "$bin" ] || continue
    # Add rpath for local lib/ (for testing) and Frameworks/ (for app bundle)
    install_name_tool -add_rpath "@executable_path/../lib" "$bin" 2>/dev/null || true
    install_name_tool -add_rpath "@executable_path/../Frameworks" "$bin" 2>/dev/null || true
    # Fix library references
    otool -L "$bin" 2>/dev/null | grep "$INSTALL_PREFIX" | awk '{print $1}' | while read dep; do
        depname=$(basename "$dep")
        install_name_tool -change "$dep" "@rpath/$depname" "$bin" 2>/dev/null || true
    done
    # Re-sign after modification
    codesign --force --sign - "$bin" 2>/dev/null || true
done

# Re-sign libraries
for lib in "$INSTALL_DIR/lib/"*.dylib; do
    [ -f "$lib" ] || continue
    codesign --force --sign - "$lib" 2>/dev/null || true
done

# Clean up build directory
echo "Cleaning up..."
rm -rf "$BUILD_DIR"

# Verify build using MAGICK_HOME (relocatable mode)
echo ""
echo "=== Verification ==="
# Test that binary runs
if ! "$INSTALL_DIR/bin/magick" -version >/dev/null 2>&1; then
    echo "ERROR: magick binary fails to run"
    "$INSTALL_DIR/bin/magick" -version 2>&1 || true
    exit 1
fi
echo "Binary runs OK"

# With --disable-installed, ImageMagick uses MAGICK_HOME to find configs
export MAGICK_HOME="$INSTALL_DIR"
export MAGICK_CONFIGURE_PATH="$INSTALL_DIR/etc/ImageMagick-7:$INSTALL_DIR/share/ImageMagick-7"
FORMAT_COUNT=$("$INSTALL_DIR/bin/magick" -list format 2>/dev/null | wc -l | tr -d ' ')
echo "Registered formats: $FORMAT_COUNT"

if [ "$FORMAT_COUNT" -gt 100 ]; then
    echo ""
    echo "=== SUCCESS ==="
    echo "ImageMagick built successfully (relocatable mode)!"
    echo ""
    echo "Location: $INSTALL_DIR"
    echo "Size: $(du -sh "$INSTALL_DIR" | cut -f1)"
    echo ""
    echo "Next steps:"
    echo "  1. Run 'make app' to build ViolaWWW.app with bundled ImageMagick"
    echo ""
    echo "Note: App can be installed anywhere (MAGICK_HOME set by launcher)"
else
    echo ""
    echo "=== WARNING ==="
    echo "ImageMagick built but format count is low ($FORMAT_COUNT)."
    echo "Check for errors above."
    exit 1
fi

