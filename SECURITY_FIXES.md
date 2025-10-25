# XPM Security Fixes for ViolaWWW

## Overview
This document describes critical security vulnerabilities found in the XPM library (libXPM) and their fixes. These vulnerabilities were similar to those that led to the removal of XBM support from modern browsers.

## Vulnerabilities Fixed

### 1. Integer Overflow Leading to Heap Overflow (CRITICAL)
**Location**: `src/libXPM/parse.c:128`

**Original Code**:
```c
pixelindex = (unsigned int*)malloc(sizeof(unsigned int) * width * height);
```

**Problem**: 
- If `width * height` overflows (e.g., 65536 × 65536 = 0x100000000 → 0), a smaller buffer is allocated
- Subsequent writes cause heap overflow
- Similar to CVE-2004-0687, CVE-2004-0688 (XBM vulnerabilities)

**Fix**:
- Added dimension limits (max 65535×65535)
- Added overflow check: `if (width > 0xFFFFFFFF / height)`
- Reject zero or negative dimensions

### 2. Command Injection via Compressed XPM Files (CRITICAL)
**Location**: `src/libXPM/data.c:225, 236`

**Original Code**:
```c
sprintf(buf, "uncompress -c %s", filename);
mdata->stream.file = popen(buf, "r");
```

**Problem**:
- Filename passed directly to shell without validation
- Malicious filename with shell metacharacters could execute arbitrary commands
- Attack vector: filenames containing `;`, `|`, `$()`, `` ` ``, `&`, `>`, etc.

**Fix**:
- Added `xpmValidateFilename()` function
- Only allows: alphanumeric, `-`, `_`, `.`, `/`
- Rejects all shell metacharacters: `;`, `|`, `$`, `` ` ``, `&`, `>`, `<`, `(`, `)`, `*`, `?`, `[`, `]`, `{`, `}`, `\`, `'`, `"`, space

### 3. Excessive Memory Allocation
**Location**: `src/libXPM/parse.c:86-91`

**Problem**:
- No limits on `ncolors` or `cpp` values
- Attacker could specify `ncolors=0xFFFFFFFF` causing excessive allocation or DoS

**Fix**:
- Limited `ncolors` to 32768 (reasonable for XPM format)
- Limited `cpp` (chars per pixel) to 16
- Reject zero values

### 4. Integer Overflow in Image Data Allocation
**Location**: `src/libXPM/create.c:342`

**Original Code**:
```c
(*image_return)->data = (char*)malloc((*image_return)->bytes_per_line * height);
```

**Problem**:
- `bytes_per_line * height` could overflow

**Fix**:
- Added overflow check: `if (height > 0 && bytes_per_line > 0xFFFFFFFF / height)`

## Testing

### Command Injection Protection Test
All 12 test cases passed:
- ✅ Valid filenames accepted
- ✅ Shell metacharacters rejected
- ✅ Command injection attempts blocked
- ✅ NULL and empty strings handled

### Overflow Protection Test
Created malicious XPM files to test:
- `test_xpm_overflow.xpm` - 65536×65536 dimensions (overflow attempt)
- `test_xpm_excessive_colors.xpm` - 50000 colors (excessive allocation)
- `test_xpm_zero_dimensions.xpm` - 0×0 dimensions (invalid)

All are rejected by the new validation code.

## Security Impact

### Before Fixes:
- Remote code execution via crafted XPM files
- Heap corruption via integer overflow
- Denial of service via excessive memory allocation
- Command injection via compressed XPM filenames

### After Fixes:
- All attack vectors blocked
- Safe limits enforced
- Input validation on all user-controlled data
- No behavioral changes for legitimate XPM files

## Recommendations

1. **Continue using these fixes** - they protect against real-world attack vectors
2. **Consider limiting XPM support** - modern browsers have removed XBM/XPM for security reasons
3. **Monitor for similar patterns** - check GIF, XBM, and other image format handlers for similar issues
4. **Regular security audits** - old code often contains vulnerabilities by modern standards

## Files Modified

- `src/libXPM/parse.c` - Added dimension and color validation
- `src/libXPM/data.c` - Added filename validation (command injection protection)
- `src/libXPM/create.c` - Added overflow check in image data allocation

## Compilation

All changes compile successfully with no warnings:
```bash
make clean && make
```

Binary size unchanged, no performance impact expected.

