#!/bin/bash
# Bundle dynamic libraries for macOS app bundle
# Usage: bundle-dylibs.sh <MacOS_dir> <Frameworks_dir> [Resources_dir]

set -e

APP_MACOS="$1"
APP_FRAMEWORKS="$2"
APP_RESOURCES="${3:-}"
PROCESSED_FILE=$(mktemp)
DEPS_FILE=$(mktemp)
ALL_PATHS_FILE=$(mktemp)

# Get non-system dependencies of a file (returns original paths as seen in binary)
get_deps() {
    otool -L "$1" 2>/dev/null | tail -n +2 | awk '{print $1}' | while read dep; do
        case "$dep" in
            /usr/lib/*|/System/*|@*) ;;
            *) echo "$dep" ;;
        esac
    done
}

# Check if already processed (by library name, not path)
is_processed() {
    grep -qx "$1" "$PROCESSED_FILE" 2>/dev/null
}

# Mark as processed
mark_processed() {
    echo "$1" >> "$PROCESSED_FILE"
}

# Collect all dependencies recursively
collect_deps() {
    local bin="$1"
    local deps=$(get_deps "$bin")
    
    for dep in $deps; do
        local libname=$(basename "$dep")
        
        # Store EVERY path we encounter (for path rewriting later)
        # This includes different paths to the same library (opt vs Cellar vs X11)
        echo "$dep" >> "$ALL_PATHS_FILE"
        
        if ! is_processed "$libname"; then
            mark_processed "$libname"
            if [ -f "$dep" ]; then
                # Store path for copying
                echo "$dep" >> "$DEPS_FILE"
                # Recursively collect dependencies
                collect_deps "$dep"
            fi
        fi
    done
}

# Phase 1: Collect all dependencies from main binaries
# Note: vw is the launcher, vw.bin is the actual browser
echo "Processing vw.bin..."
collect_deps "$APP_MACOS/vw.bin"

if [ -f "$APP_MACOS/sgmlsA2B" ]; then
    echo "Processing sgmlsA2B..."
    collect_deps "$APP_MACOS/sgmlsA2B"
fi

# Also process vplot if it exists in Resources
VPLOT_PATH="$APP_RESOURCES/vplot_dir/vplot"
if [ -n "$APP_RESOURCES" ] && [ -f "$VPLOT_PATH" ]; then
    echo "Processing vplot..."
    collect_deps "$VPLOT_PATH"
fi

# Phase 2: Copy all collected libraries
echo "Copying libraries..."
while read dep; do
    libname=$(basename "$dep")
    echo "  Copying $libname"
    cp "$dep" "$APP_FRAMEWORKS/"
    chmod 755 "$APP_FRAMEWORKS/$libname"
done < "$DEPS_FILE"

# Get unique paths (some libs may be referenced via different paths)
sort -u "$ALL_PATHS_FILE" > "${ALL_PATHS_FILE}.sorted"
mv "${ALL_PATHS_FILE}.sorted" "$ALL_PATHS_FILE"

# Phase 3: Fix all paths in the main binaries
echo "Fixing paths in vw.bin..."
while read dep; do
    libname=$(basename "$dep")
    install_name_tool -change "$dep" "@executable_path/../Frameworks/$libname" "$APP_MACOS/vw.bin" 2>/dev/null || true
done < "$ALL_PATHS_FILE"

if [ -f "$APP_MACOS/sgmlsA2B" ]; then
    echo "Fixing paths in sgmlsA2B..."
    while read dep; do
        libname=$(basename "$dep")
        install_name_tool -change "$dep" "@executable_path/../Frameworks/$libname" "$APP_MACOS/sgmlsA2B" 2>/dev/null || true
    done < "$ALL_PATHS_FILE"
fi

# Fix paths in vplot (it's in Resources/vplot_dir/)
if [ -n "$APP_RESOURCES" ] && [ -f "$VPLOT_PATH" ]; then
    echo "Fixing paths in vplot..."
    while read dep; do
        libname=$(basename "$dep")
        # vplot is in Resources/vplot_dir/, Frameworks is at the same level as Resources
        # So from MacOS perspective: @executable_path/../Frameworks works
        # But vplot isn't in MacOS, it's in Resources/vplot_dir
        # Use @loader_path which is relative to the binary being loaded
        install_name_tool -change "$dep" "@loader_path/../../Frameworks/$libname" "$VPLOT_PATH" 2>/dev/null || true
    done < "$ALL_PATHS_FILE"
fi

# Phase 4: Fix library IDs and cross-references in all bundled libraries
echo "Fixing library IDs and cross-references..."
shopt -s nullglob
for lib in "$APP_FRAMEWORKS"/*.dylib; do
    [ -f "$lib" ] || continue
    libname=$(basename "$lib")
    
    # Set library ID
    install_name_tool -id "@executable_path/../Frameworks/$libname" "$lib" 2>/dev/null || true
    
    # Fix all references to bundled libraries (using all encountered paths)
    while read dep; do
        depname=$(basename "$dep")
        install_name_tool -change "$dep" "@executable_path/../Frameworks/$depname" "$lib" 2>/dev/null || true
    done < "$ALL_PATHS_FILE"
done

count=$(ls -1 "$APP_FRAMEWORKS" 2>/dev/null | wc -l | tr -d ' ')
echo "Bundled $count libraries"

# Re-sign all modified binaries (required after install_name_tool)
echo "Re-signing binaries..."
codesign --force --sign - "$APP_MACOS/vw" 2>/dev/null || true
codesign --force --sign - "$APP_MACOS/vw.bin" 2>/dev/null || true
[ -f "$APP_MACOS/sgmlsA2B" ] && codesign --force --sign - "$APP_MACOS/sgmlsA2B" 2>/dev/null || true
[ -f "$VPLOT_PATH" ] && codesign --force --sign - "$VPLOT_PATH" 2>/dev/null || true
for lib in "$APP_FRAMEWORKS"/*.dylib; do
    [ -f "$lib" ] && codesign --force --sign - "$lib" 2>/dev/null || true
done
echo "Done"

rm -f "$PROCESSED_FILE" "$DEPS_FILE" "$ALL_PATHS_FILE"
