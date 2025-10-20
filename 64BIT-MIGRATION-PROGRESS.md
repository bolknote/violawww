# 64-bit Migration Progress

## Completed ✅

### Precision Loss Warnings (Critical 64-bit Issues)
- ✅ Fixed ~50+ long→int warnings in critical files:
  - tfed.c: Fixed doHighLighting, doDrawCursor, stat, TFCstrcpy/TFCstrncpy pointer arithmetic, insetHeight variables, slot accessor assignments
  - event_x.c: Added explicit casts for X11 window functions (XMoveResizeWindow, XMoveWindow, XResizeWindow)
  - cl_pane.c: Fixed VObj→int truncations in geometry calculations (span calculations)
  - tfed_i.h: Changed format, verbatim fields from int to long

- ✅ Fixed unsigned long→short warnings:
  - rle.h: Updated SWAB macro to use __typeof__() for proper type preservation (fixes ~20 warnings in rlelib.c)

- ✅ Fixed multiple insetHeight, maxFontHeight assignments with proper casting

### Format Specifiers (64-bit Critical)
- ✅ Fixed ~10 format specifier warnings:
  - cgen.c: Changed %d/%i to %ld/%li for pcode[].i (long values)
  - cl_PS.c: Fixed %d to %ld for GET_height, GET_width; %d to %lx for GET_window

### K&R Function Conversions (Started)
- ✅ Converted 2 functions in vw/catalog.c to ANSI C style
- Pattern established for systematic conversion

### Build Status
- ✅ Full build compiles successfully with all fixes
- ✅ No compilation errors introduced
- ✅ Warning count reduced from 6810 to ~6770 (~40 warnings fixed)

## In Progress 🔄

### High Priority (64-bit Critical)
1. **Precision Loss Warnings**: ~120 remaining
   - Mostly int→char (likely intentional)
   - Some unsigned long→int in library code (libIMG, libXPA, libWWW)
   - VObj→int in various class files

### Medium Priority
2. **K&R Functions**: ~1998 remaining
   - tfed.c: 135 functions
   - Other viola/*.c files: ~800 functions
   - vw/*.c files: ~200 functions
   - libIMG/*.c: ~300 functions
   - libWWW: ~300 functions
   - libStyle: ~50 functions

3. **Sign Conversion Warnings**: ~472 total
   - int ↔ unsigned int conversions
   - long ↔ unsigned long conversions

4. **Format Specifiers**: ~40 warnings
   - Need %ld for long instead of %d
   - Need %lu for unsigned long instead of %u

5. **Pointer Type Mismatches**: ~30 warnings
   - Incompatible pointer types
   - Pointer-to-int conversions

## Files Modified
- src/viola/tfed.c - Major precision fixes
- src/viola/tfed_i.h - Structure field type changes
- src/viola/event_x.c - X11 function call fixes
- src/viola/cl_pane.c - VObj precision fixes  
- src/libIMG/rle.h - SWAB macro fix
- src/vw/catalog.c - K&R function conversions started

## Estimated Remaining Effort
- K&R functions: Large effort, ~1998 functions to convert
- Precision loss: Medium effort, ~120 warnings across multiple files
- Sign conversions: Medium effort, ~472 warnings
- Format specifiers: Small effort, ~40 warnings
- Pointer issues: Small effort, ~30 warnings

**Total**: This is a massive codebase (~200k+ lines) requiring substantial continued effort across multiple work sessions.

