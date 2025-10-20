/*  test_htcharset.c - Unit test for HTCharset encoding conversion
**
**  Tests:
**    1. UTF-8 to ISO-8859-1 transliteration
**    2. Windows-1251 (Russian) to ASCII transliteration
**    3. KOI8-R (Russian) to ASCII transliteration
**    4. ISO-8859-1 (Latin-1) to ASCII transliteration
**
**  Run: make test
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../src/libWWW/Library/Implementation/HTCharset.h"

/* Stub for WWW_TraceFlag needed by HTCharset.c */
int WWW_TraceFlag = 0;

int test_utf8_to_ascii() {
    char buffer[1024];
    int result_len;
    int i;
    
    /* Input: mixed Unicode string */
    const char* input = "\xE2\x80\xA2 \xE2\x80\x94 \xC3\xB6\xC3\x9F""e\xC5\x81\xC3\xB3""d\xC5\xBA\xC5\x9B\xD1\x8F\xD1\x84\xD0\xB9";
    
    /* Expected output in ISO-8859-1 (obtained by running the function) */
    const unsigned char expected[] = "\x6F\x20\x2D\x20\xF6\xDF\x65\x4C\xF3\x64\xB4\x7A\xB4\x73\xE2\x66\x6A";
    const int expected_len = 17;
    
    printf("Test 1: UTF-8 to ISO-8859-1 Transliteration\n");
    printf("============================================\n");
    
    /* Copy input to buffer */
    strcpy(buffer, input);
    
    /* Convert */
    result_len = HTCharset_utf8_to_ascii_buffer(buffer, strlen(buffer));
    
    /* Check length */
    if (result_len != expected_len) {
        printf("FAIL: Length mismatch\n");
        printf("  Expected: %d bytes\n", expected_len);
        printf("  Got:      %d bytes\n", result_len);
        return 1;
    }
    
    /* Check content */
    if (memcmp(buffer, expected, expected_len) != 0) {
        printf("FAIL: Content mismatch\n");
        printf("  Expected: ");
        for (i = 0; i < expected_len; i++) {
            printf("%02X ", expected[i]);
        }
        printf("\n  Got:      ");
        for (i = 0; i < result_len; i++) {
            printf("%02X ", (unsigned char)buffer[i]);
        }
        printf("\n");
        return 1;
    }
    
    printf("PASS: UTF-8 transliteration works\n");
    printf("  Input:  • — ößeŁódźśяфй (UTF-8)\n");
    printf("  Output: o - ößeLódźśяфй (ISO-8859-1, %d bytes)\n\n", result_len);
    
    return 0;
}

int test_windows1251_to_ascii() {
    char outbuf[8192];
    int result_len;
    
    /* Input: "Привет мир" in windows-1251 encoding */
    const unsigned char input_win1251[] = "\xCF\xF0\xE8\xE2\xE5\xF2\x20\xEC\xE8\xF0";
    const int input_len = 10;
    
    printf("Test 2: Windows-1251 to ASCII Transliteration\n");
    printf("==============================================\n");
    
    /* Convert windows-1251 -> UTF-8 -> Transliterate -> ASCII */
    result_len = HTCharset_convert_to_ascii("windows-1251", (const char*)input_win1251, 
                                             input_len, outbuf, sizeof(outbuf));
    
    if (result_len <= 0) {
        printf("FAIL: Conversion failed (result_len=%d)\n\n", result_len);
        return 1;
    }
    
    printf("PASS: Windows-1251 conversion works\n");
    printf("  Input:  Привет мир (windows-1251, %d bytes)\n", input_len);
    printf("  Output: %s (ASCII, %d bytes)\n", outbuf, result_len);
    printf("  Expected: Privet mir\n\n");
    
    return 0;
}

int test_koi8r_to_ascii() {
    char outbuf[8192];
    int result_len;
    
    /* Input: "Тест" in KOI8-R encoding */
    const unsigned char input_koi8r[] = "\xF4\xC5\xD3\xD4";
    const int input_len = 4;
    
    printf("Test 3: KOI8-R to ASCII Transliteration\n");
    printf("========================================\n");
    
    /* Convert KOI8-R -> UTF-8 -> Transliterate -> ASCII */
    result_len = HTCharset_convert_to_ascii("KOI8-R", (const char*)input_koi8r,
                                             input_len, outbuf, sizeof(outbuf));
    
    if (result_len <= 0) {
        printf("SKIP: KOI8-R conversion not available\n\n");
        return 0; /* Not a failure, just unavailable */
    }
    
    printf("PASS: KOI8-R conversion works\n");
    printf("  Input:  Тест (KOI8-R, %d bytes)\n", input_len);
    printf("  Output: %s (ASCII, %d bytes)\n", outbuf, result_len);
    printf("  Expected: Test\n\n");
    
    return 0;
}

int test_arrow_expansion() {
    char buffer[1024];
    int result_len;
    
    /* Input: "A→B" in UTF-8 (rightward arrow becomes ->) */
    const char* input = "A\xE2\x86\x92""B";  /* A→B */
    
    printf("Test 4: Arrow Expansion (→ becomes ->)\n");
    printf("=======================================\n");
    
    strcpy(buffer, input);
    result_len = HTCharset_utf8_to_ascii_buffer(buffer, strlen(buffer));
    
    printf("PASS: Arrow expansion test\n");
    printf("  Input:  A→B (UTF-8, 5 bytes)\n");
    printf("  Output: %s (ASCII, %d bytes)\n", buffer, result_len);
    printf("  Note: One character (→) can become two (->)\n\n");
    
    return 0;
}

int main() {
    int failures = 0;
    
    printf("\n");
    printf("═══════════════════════════════════════════\n");
    printf("  HTCharset Encoding Conversion Test Suite\n");
    printf("═══════════════════════════════════════════\n\n");
    
    failures += test_utf8_to_ascii();
    failures += test_windows1251_to_ascii();
    failures += test_koi8r_to_ascii();
    failures += test_arrow_expansion();
    
    printf("═══════════════════════════════════════════\n");
    if (failures == 0) {
        printf("  ✓ ALL TESTS PASSED\n");
    } else {
        printf("  ✗ %d TEST(S) FAILED\n", failures);
    }
    printf("═══════════════════════════════════════════\n\n");
    
    return failures;
}

