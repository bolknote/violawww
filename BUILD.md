# ViolaWWW Build Instructions

This is a modernized build system for ViolaWWW, one of the first graphical web browsers from the early 1990s.

## Prerequisites

### macOS (Darwin)

Install the required dependencies using Homebrew:

```bash
brew install openmotif
```

Make sure you have Xcode Command Line Tools installed:

```bash
xcode-select --install
```

## Quick Start

### Build Everything

```bash
make
```

This will build all libraries and both browser executables (`viola` and `vw`).

### Build Specific Targets

```bash
# Build only VW (Motif interface browser)
make vw

# Build only Viola (Xt interface browser)
make viola

# Build only libraries
make libs
```

### Clean Build Artifacts

```bash
# Remove object files only
make clean

# Remove all build artifacts including executables and libraries
make distclean

# Rebuild everything from scratch
make rebuild
```

## Installation

To install the binaries to your home directory:

```bash
make install
```

This will copy `viola` and `vw` to `~/bin/`.

## Running the Browser

After building, you can run either:

```bash
# Run VW (Motif interface - recommended)
./src/vw/vw

# Run Viola (Xt interface)
./src/viola/viola
```

Or after installation:

```bash
vw
# or
viola
```

## Project Structure

```
violawww2/
├── Makefile           # Main build system
├── BUILD.md           # This file
├── src/
│   ├── libWWW/        # HTTP/HTML library
│   ├── libXPM/        # XPM image support
│   ├── libXPA/        # X Pixmap Allocator
│   ├── libIMG/        # Image loading library
│   ├── libStyle/      # Style library
│   ├── viola/         # Viola browser (Xt interface)
│   └── vw/            # VW browser (Motif interface)
└── res/               # Resource files
```

## Build Configuration

The build system uses the following configuration:

- **Compiler**: cc (clang on macOS)
- **Architecture**: arm64 (Apple Silicon)
- **C Standard**: gnu89 (for compatibility with 1990s code)
- **Optimization**: -Os (size optimization)
- **GUI Toolkit**: Motif (OpenMotif)
- **Auto-detection**: Homebrew and OpenMotif paths are automatically detected

### Customizing the Build

The Makefile automatically detects Homebrew and OpenMotif installation paths. You can override build variables by editing the `Makefile` or passing them on the command line:

```bash
# Build with debugging symbols
make CFLAGS="-g -arch arm64 -std=gnu89 -Wno-everything -D__DARWIN__"

# Use a different compiler
make CC=gcc-13

# Change optimization level
make CFLAGS="-O0 -arch arm64 -std=gnu89 -Wno-everything -D__DARWIN__"

# Override Homebrew prefix (if installed in non-standard location)
make BREW_PREFIX=/usr/local
```

## Troubleshooting

### Build Fails with Missing Headers

Make sure OpenMotif is properly installed:

```bash
brew info openmotif
```

The Makefile automatically detects the OpenMotif installation using `brew --prefix openmotif`. If you have a custom installation, you can override the path:

```bash
make OPENMOTIF_PREFIX=/your/custom/path
```

### X11 Not Found

On macOS, you may need XQuartz:

```bash
brew install --cask xquartz
```

After installation, log out and log back in, or reboot.

### Linker Errors

If you get linker errors about missing symbols, try:

```bash
make distclean
make
```

## Getting Help

To see all available make targets:

```bash
make help
```

To see current build configuration:

```bash
make info
```

## Historical Context

ViolaWWW was created by Pei-Yuan Wei at the University of California, Berkeley in 1991-1992. It was one of the first graphical web browsers and introduced many concepts that later became standard in web browsers.

This modernized build system replaces the original imake-based build system with a cleaner, more maintainable Makefile that works on modern systems.

## License

See the original COPYRIGHT and copyright files in the source directories for licensing information.

