# 64-bit Migration Strategy & Handoff

## Current Status (After Session 1)
- **Warnings Fixed**: ~40 critical warnings
- **Starting Count**: 6810 unique warnings
- **Current Count**: ~6770 warnings
- **Build Status**: ✅ Compiles successfully

## Priority Order for Remaining Work

### Phase 1: Critical 64-bit Safety Issues (HIGH PRIORITY)
**Estimated effort**: 2-3 sessions

1. **Remaining Precision Loss (~120 warnings)**
   - Files to focus on: glib_x.c (16), libIMG files
   - Pattern: unsigned long→int, VObj→int conversions
   - Strategy: Examine each case - is truncation intentional? If yes, add explicit cast. If no, change target type to long.

2. **Format Specifiers (~30 remaining)**
   - Quick wins - systematic search and replace
   - Pattern: `%d` → `%ld` for long, `%u` → `%lu` for unsigned long
   - Files: class.c, event_x.c, cl_generic.c, others
   - Command to find: `grep "format specifies.*long" 64bit-warnings.log`

### Phase 2: Code Modernization (MEDIUM PRIORITY)
**Estimated effort**: 5-10 sessions

3. **K&R Function Conversions (~2000 functions)**
   - This is the bulk of remaining work
   - Pattern established in vw/catalog.c
   - Approach:
     ```c
     // Old K&R style:
     void func(a, b) int a; char* b; { }
     
     // New ANSI C style:
     void func(int a, char* b) { }
     ```
   - Recommended order:
     a. tfed.c (135 functions) - most critical file
     b. Other viola/*.c files (~800 functions)
     c. vw/*.c files (~200 functions)
     d. Library files if needed

### Phase 3: Safety Improvements (LOWER PRIORITY)
**Estimated effort**: 2-3 sessions

4. **Sign Conversion Warnings (~472)**
   - Pattern: int ↔ unsigned int, long ↔ unsigned long
   - Lower priority for 64-bit compatibility
   - Many may be in library code or less critical paths

5. **Pointer Type Mismatches (~30)**
   - Incompatible pointer types
   - Some may require struct changes
   - Review each carefully

## Recommended Tools & Commands

### Finding specific warning types:
```bash
# Precision loss warnings:
grep "loses integer precision" 64bit-warnings.log | grep -o "src/[^:]*" | sort | uniq -c | sort -rn

# Format specifiers:
grep "format specifies" 64bit-warnings.log | head -20

# K&R functions by file:
grep "function definition without a prototype" 64bit-warnings.log | grep -o "src/[^:]*" | sort | uniq -c | sort -rn

# Check progress:
make clean && make check-64bit 2>&1 | grep -c "warning:"
```

### Testing after changes:
```bash
# Quick build test:
make clean && make -j4

# Full warning analysis:
make clean && make check-64bit 2>&1 | tee 64bit-warnings-new.log
```

## Files Modified So Far

### Core Application Files:
- src/viola/tfed.c - Major precision fixes, format fixes
- src/viola/tfed_i.h - Structure changes (format, verbatim → long)
- src/viola/event_x.c - X11 call fixes
- src/viola/cgen.c - Format specifier fixes
- src/viola/cl_pane.c - VObj precision fixes
- src/viola/cl_PS.c - Format specifier fixes

### Library Files:
- src/libIMG/rle.h - SWAB macro fix with __typeof__

### Utility Files:
- src/vw/catalog.c - K&R conversions started (2 functions)

## Known Patterns & Solutions

### Pattern 1: Slot System Values (VObj is long)
```c
// Problem: int x = GET_something(obj);
// Solution: long x = GET_something(obj);
```

### Pattern 2: X11 Window Functions
```c
// Problem: XMoveWindow(display, win, GET_x(obj), GET_y(obj));
// Solution: XMoveWindow(display, win, (int)GET_x(obj), (int)GET_y(obj));
```

### Pattern 3: Pointer Arithmetic
```c
// Problem: int len = ptr2 - ptr1;
// Solution: int len = (int)(ptr2 - ptr1);  // if safe
// Or better: ptrdiff_t len = ptr2 - ptr1;
```

### Pattern 4: Format Specifiers
```c
// Problem: printf("%d", long_value);
// Solution: printf("%ld", long_value);
```

## Next Steps

1. **Continue with format specifiers** (quick wins, ~30 remaining)
2. **Fix remaining critical precision loss** in glib_x.c and other key files  
3. **Begin systematic K&R conversion** starting with tfed.c
4. **Test thoroughly** after each batch of changes
5. **Update this document** with progress

## Notes
- Build time: ~3 seconds clean build with -j4
- The codebase is ~200k+ lines across multiple subsystems
- Most critical work for 64-bit safety is in viola/*.c files
- Library code (libIMG, libWWW) has many warnings but less critical
- Original code dates to early 1990s, extensive K&R style throughout

