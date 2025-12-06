#!/bin/bash
# Generate macOS .icns icon from violaIcon.xbm
# Usage: make-icon.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
XBM_FILE="$PROJECT_DIR/src/viola/violaIcon.xbm"
OUTPUT_DIR="$PROJECT_DIR/resources"
ICONSET_DIR="$OUTPUT_DIR/ViolaWWW.iconset"
ICNS_FILE="$OUTPUT_DIR/ViolaWWW.icns"

mkdir -p "$OUTPUT_DIR"
rm -rf "$ICONSET_DIR"
mkdir -p "$ICONSET_DIR"

echo "=== Generating ViolaWWW.icns from violaIcon.xbm ==="

# Create a Python script to convert XBM to PNG
python3 << 'PYTHON_SCRIPT'
import os
import struct

# XBM data from violaIcon.xbm
xbm_bytes = bytes([
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00,
    0x38, 0x0c, 0x1e, 0x00, 0x0c, 0x18, 0x73, 0x00, 0x06, 0xf0, 0xc1, 0x00,
    0x02, 0x60, 0xc0, 0x00, 0x03, 0x00, 0x80, 0x01, 0x01, 0x00, 0x80, 0x51,
    0x01, 0x00, 0x80, 0x51, 0x01, 0x20, 0xe9, 0xff, 0xc1, 0x03, 0x00, 0x50,
    0xc1, 0x03, 0x00, 0x50, 0x81, 0x03, 0x01, 0x50, 0x82, 0x03, 0x01, 0x00,
    0x06, 0x07, 0x01, 0x00, 0x0c, 0x87, 0x00, 0x01, 0x7c, 0x86, 0x02, 0x1d,
    0x78, 0x8e, 0x00, 0x21, 0x70, 0x4c, 0x32, 0x21, 0x00, 0x48, 0x4a, 0x39,
    0x00, 0x58, 0x4a, 0x25, 0x00, 0x70, 0x4a, 0x25, 0x00, 0x30, 0x32, 0x79,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
])

WIDTH = 32
HEIGHT = 32

# Convert XBM to pixel array (1 = black, 0 = white/transparent)
def xbm_to_pixels():
    pixels = []
    for y in range(HEIGHT):
        row = []
        for x in range(WIDTH):
            byte_pos = x // 8
            bit_pos = x % 8
            byte = xbm_bytes[y * (WIDTH // 8) + byte_pos]
            bit = (byte >> bit_pos) & 1
            row.append(bit)
        pixels.append(row)
    return pixels

pixels = xbm_to_pixels()

# Simple PNG encoder (no external dependencies)
def create_png(width, height, rgba_data):
    def crc32(data):
        import zlib
        return zlib.crc32(data) & 0xffffffff
    
    def chunk(chunk_type, data):
        return struct.pack('>I', len(data)) + chunk_type + data + struct.pack('>I', crc32(chunk_type + data))
    
    # PNG signature
    png = b'\x89PNG\r\n\x1a\n'
    
    # IHDR chunk
    ihdr_data = struct.pack('>IIBBBBB', width, height, 8, 6, 0, 0, 0)  # 8-bit RGBA
    png += chunk(b'IHDR', ihdr_data)
    
    # IDAT chunk (image data)
    import zlib
    raw_data = b''
    for y in range(height):
        raw_data += b'\x00'  # filter type: none
        raw_data += rgba_data[y * width * 4:(y + 1) * width * 4]
    
    compressed = zlib.compress(raw_data, 9)
    png += chunk(b'IDAT', compressed)
    
    # IEND chunk
    png += chunk(b'IEND', b'')
    
    return png

def scale_pixels(pixels, scale):
    """Scale pixel art (nearest neighbor)"""
    new_height = len(pixels) * scale
    new_width = len(pixels[0]) * scale
    scaled = []
    for y in range(new_height):
        row = []
        for x in range(new_width):
            orig_y = y // scale
            orig_x = x // scale
            row.append(pixels[orig_y][orig_x])
        scaled.append(row)
    return scaled

def pixels_to_rgba(pixels, fg=(0, 0, 0, 255), bg=(255, 255, 255, 255)):
    """Convert 1-bit pixels to RGBA"""
    rgba = bytearray()
    for row in pixels:
        for pixel in row:
            if pixel:
                rgba.extend(fg)
            else:
                rgba.extend(bg)
    return bytes(rgba)

# Generate icons at different sizes
output_dir = os.environ.get('ICONSET_DIR', 'ViolaWWW.iconset')

sizes = [
    (16, 'icon_16x16.png'),
    (32, 'icon_16x16@2x.png'),
    (32, 'icon_32x32.png'),
    (64, 'icon_32x32@2x.png'),
    (128, 'icon_128x128.png'),
    (256, 'icon_128x128@2x.png'),
    (256, 'icon_256x256.png'),
    (512, 'icon_256x256@2x.png'),
    (512, 'icon_512x512.png'),
    (1024, 'icon_512x512@2x.png'),
]

for size, filename in sizes:
    scale = size // 32
    if scale < 1:
        scale = 1
    
    if scale == 1 and size < 32:
        # For sizes smaller than 32, we need to downsample
        # For simplicity, just use scale 1 and crop/center
        scaled = pixels
        # Create centered version
        scaled_pixels = [[0] * size for _ in range(size)]
        offset = (32 - size) // 2
        for y in range(size):
            for x in range(size):
                if 0 <= y + offset < 32 and 0 <= x + offset < 32:
                    scaled_pixels[y][x] = pixels[y + offset][x + offset]
        rgba = pixels_to_rgba(scaled_pixels)
    else:
        scaled = scale_pixels(pixels, scale)
        # Crop to exact size if needed
        if len(scaled) > size:
            offset = (len(scaled) - size) // 2
            scaled = [row[offset:offset+size] for row in scaled[offset:offset+size]]
        rgba = pixels_to_rgba(scaled)
    
    png_data = create_png(size, size, rgba)
    
    filepath = os.path.join(output_dir, filename)
    with open(filepath, 'wb') as f:
        f.write(png_data)
    print(f"  Created {filename} ({size}x{size})")

print("PNG files generated successfully")
PYTHON_SCRIPT

# Use iconutil to create .icns
echo "Creating .icns file..."
ICONSET_DIR="$ICONSET_DIR" iconutil -c icns "$ICONSET_DIR" -o "$ICNS_FILE"

echo ""
echo "=== Icon created: $ICNS_FILE ==="
ls -lh "$ICNS_FILE"

# Cleanup
rm -rf "$ICONSET_DIR"

