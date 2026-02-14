#!/bin/bash
# Create custom DMG for ViolaWWW with XQuartz
# Requires: create-dmg (brew install create-dmg)

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
DMG_DIR="$PROJECT_DIR/dmg"
BUILD_DIR="$DMG_DIR/build"
XQUARTZ_VERSION="2.8.5"
XQUARTZ_PKG="XQuartz-${XQUARTZ_VERSION}.pkg"
XQUARTZ_URL="https://github.com/XQuartz/XQuartz/releases/download/XQuartz-${XQUARTZ_VERSION}/${XQUARTZ_PKG}"

echo "=== Creating custom ViolaWWW DMG ==="
echo ""

# Check for create-dmg
if ! command -v create-dmg &> /dev/null; then
    echo "Installing create-dmg..."
    brew install create-dmg
fi

# Create build directory
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

# Check if ViolaWWW.app exists
if [ ! -d "$PROJECT_DIR/ViolaWWW.app" ]; then
    echo "ERROR: ViolaWWW.app not found. Run 'make app' first."
    exit 1
fi

# Copy ViolaWWW.app
echo "Copying ViolaWWW.app..."
cp -r "$PROJECT_DIR/ViolaWWW.app" "$BUILD_DIR/"

# Download XQuartz if not present
if [ ! -f "$DMG_DIR/$XQUARTZ_PKG" ]; then
    echo "Downloading XQuartz ${XQUARTZ_VERSION}..."
    curl -L --progress-bar -o "$DMG_DIR/$XQUARTZ_PKG" "$XQUARTZ_URL"
    echo ""
fi
cp "$DMG_DIR/$XQUARTZ_PKG" "$BUILD_DIR/"

# Convert SVG to PNG for background
BACKGROUND_PNG="$DMG_DIR/background.png"
GLOBE_XPM="$PROJECT_DIR/src/vw/globes.xpm"
PEI_GIF="$DMG_DIR/pei_sm.gif"

echo "Creating background with pixel-perfect globe..."

# Always regenerate to ensure fresh build
rm -f "$BACKGROUND_PNG"

# 1. Convert SVG to PNG first
echo "  - Creating base background..."
if command -v rsvg-convert &> /dev/null; then
    rsvg-convert -w 640 -h 520 "$DMG_DIR/background.svg" > /tmp/bg_small.png
else
    magick "$DMG_DIR/background.svg" -resize 640x520 /tmp/bg_small.png
fi

# Extend with matching background color from SVG
magick /tmp/bg_small.png -gravity NorthWest -background "#1a1a2e" -extent 4096x3072 "$BACKGROUND_PNG"
rm /tmp/bg_small.png

# 2. Create pixel-perfect globe from XPM (48x48, nearest-neighbor from 32x32)
echo "  - Adding pixel-perfect globe..."
head -45 "$GLOBE_XPM" > /tmp/globe1.xpm
# Resize with nearest-neighbor (keeps pixel art crisp)
magick /tmp/globe1.xpm -type TrueColor -filter point -resize 48x48 /tmp/globe48.png
rm /tmp/globe1.xpm

# Composite globe onto background (in header bar)
magick "$BACKGROUND_PNG" /tmp/globe48.png -geometry +22+16 -composite "$BACKGROUND_PNG"
rm /tmp/globe48.png

# 3. Add Pei-Yuan Wei photo (scaled down to fit)
if [ -f "$PEI_GIF" ]; then
    echo "  - Adding Pei-Yuan Wei photo..."
    magick "$PEI_GIF" -type TrueColor -resize 80x100 /tmp/pei.png
    # Add inside the instructions panel (right side)
    magick "$BACKGROUND_PNG" /tmp/pei.png -geometry +510+375 -composite "$BACKGROUND_PNG"
    rm /tmp/pei.png
fi

echo "Background created."

# Remove old DMG
rm -f "$PROJECT_DIR/ViolaWWW.dmg"

echo "Creating DMG..."
create-dmg \
    --volname "ViolaWWW" \
    --volicon "$PROJECT_DIR/res/ViolaWWW.icns" \
    --format ULMO \
    --background "$BACKGROUND_PNG" \
    --window-pos 200 100 \
    --window-size 640 580 \
    --icon-size 64 \
    --icon "$XQUARTZ_PKG" 130 190 \
    --icon "ViolaWWW.app" 320 190 \
    --app-drop-link 510 190 \
    --hide-extension "ViolaWWW.app" \
    --no-internet-enable \
    "$PROJECT_DIR/ViolaWWW.dmg" \
    "$BUILD_DIR"

# Set custom icon on DMG file itself
echo "Setting DMG icon..."
if [ -f "$PROJECT_DIR/res/ViolaWWW.icns" ]; then
    # Create icon resource
    sips -i "$PROJECT_DIR/res/ViolaWWW.icns" >/dev/null 2>&1 || true
    DeRez -only icns "$PROJECT_DIR/res/ViolaWWW.icns" > /tmp/icns.rsrc 2>/dev/null || true
    Rez -append /tmp/icns.rsrc -o "$PROJECT_DIR/ViolaWWW.dmg" 2>/dev/null || true
    SetFile -a C "$PROJECT_DIR/ViolaWWW.dmg" 2>/dev/null || true
    rm -f /tmp/icns.rsrc
fi

# Cleanup
rm -rf "$BUILD_DIR"

echo ""
echo "=== ViolaWWW.dmg created successfully! ==="
ls -lh "$PROJECT_DIR/ViolaWWW.dmg"

