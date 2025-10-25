# ViolaWWW Tests

## Test Programs

### test_xpm_injection.c
Tests XPM filename validation to prevent command injection attacks.

**Compile and run:**
```bash
cd test
mkdir -p build
cc -o build/test_xpm_injection test_xpm_injection.c && ./build/test_xpm_injection
```

## Test Resources

### res/test_xpm_security.html
HTML page for manual testing of XPM security fixes in the browser.

**Usage:**
```bash
cd test/res
../../src/vw/vw file://$(pwd)/test_xpm_security.html
```

### XPM Test Files

- `test_xpm_valid.xpm` - Valid 8x8 XPM (should display correctly)
- `test_xpm_overflow.xpm` - 65536x65536 dimensions (should be rejected)
- `test_xpm_excessive_colors.xpm` - 50000 colors (should be rejected)
- `test_xpm_zero_dimensions.xpm` - 0x0 dimensions (should be rejected)

## Expected Results

All security tests should be **rejected** by the XPM parser:
- Integer overflow attempts blocked
- Excessive resource allocation prevented
- Invalid dimensions rejected
- Command injection attempts blocked (12/12 tests pass)

