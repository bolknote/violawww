# ViolaWWW Test Suite

## Running Tests

```bash
cd test
make test          # Run all tests
make test-NAME     # Run specific test
make clean         # Clean test artifacts
make help          # Show available tests
```

## Available Tests

| Test | Description |
|------|-------------|
| `test-stg-minors` | Style markup minors tests |
| `test-stg-context` | Style context tests |
| `test-xpm-injection` | XPM security (command injection prevention) |
| `test-htcharset` | Character set conversion tests (requires ICU) |
| `test-wayback-detection` | Web Archive URL detection tests |
| `test-biop` | Binary/string operations tests |
| `test-hash-memory` | Hash table memory leak tests |
| `test-mystrings` | String functions tests |
| `test-pkinfo-concat` | Packet-info concatenation tests |
| `test-sgmls-a2b` | SGMLS ASCII to Binary converter tests |

## Test Details

### test_sgmls_a2b.c
Tests for `sgmlsA2B.c` - SGMLS ASCII to Binary converter.

**Coverage:**
- `filterCtrl`: escape sequence processing (`\n`, `\t`, `\r`, `\\`, `\"`, `\'`, `\f`, `\b`)
- `filterCtrl`: octal escape sequences (`\011`, `\040`)
- `emitInt`: 4-byte big-endian integer output
- `emitToken`: single byte output with masking
- `emitStr`: string output with length parameter
- `findTagID`: tag dictionary lookup
- Token and attribute type constants

### test_xpm_injection.c
Tests XPM filename validation to prevent command injection attacks.

### test_mystrings.c
Comprehensive tests for string functions in `mystrings.c` and `hash.c`.

### test_htcharset.c
Character set conversion tests using ICU library.

### test_wayback_detection.c
Tests for Web Archive (Wayback Machine) URL detection and handling.

### test_biop.c
Tests for binary operations and string manipulation functions.

### test_hash_memory.c
Tests for hash table implementation and memory management.

### test_stg_minors.c / test_stg_context.c
Tests for STG (style) parsing and context handling.

### test_pkinfo_concat.c
Tests for packet info concatenation functions.

## Test Resources

### res/test_xpm_security.html
HTML page for manual testing of XPM security fixes in the browser.

```bash
cd test/res
../../src/vw/vw file://$(pwd)/test_xpm_security.html
```

### XPM Test Files

| File | Description | Expected Result |
|------|-------------|-----------------|
| `test_xpm_valid.xpm` | Valid 8x8 XPM | Should display correctly |
| `test_xpm_overflow.xpm` | 65536x65536 dimensions | Should be rejected |
| `test_xpm_excessive_colors.xpm` | 50000 colors | Should be rejected |
| `test_xpm_zero_dimensions.xpm` | 0x0 dimensions | Should be rejected |

## Test Output

Test results are saved in `build/`:
- `results.txt` - Summary of PASS/FAIL for each test
- `test-*.log` - Detailed output for each test

## Adding New Tests

1. Create `test_name.c` in the `test/` directory
2. Add target to `Makefile`:
   ```makefile
   test-name: test_name.c $(DEPENDENCIES)
       @echo "Building test..."
       @mkdir -p $(BUILD_DIR)
       @$(CC) $(CFLAGS) -o $(BUILD_DIR)/test_name test_name.c $(LIBS)
       @./$(BUILD_DIR)/test_name
   ```
3. Add to `TESTS` list in Makefile
4. Add to test runner section in Makefile
5. Update this README
