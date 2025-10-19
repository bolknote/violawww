/*  HTCharset.c - UTF-8 to ISO-8859-1 transliteration
**
**  Two-pass conversion:
**    1. ICU: Any-Latin (Cyrillic → Latin, Greek → Latin, Chinese → Pinyin)
**    2. iconv: UTF-8 → ISO-8859-1//TRANSLIT (• → *, " → ", keeps é ü ñ)
*/

#include "HTCharset.h"
#include <string.h>

#ifdef USE_ICU
#include <unicode/utrans.h>
#include <unicode/ustring.h>
#include <iconv.h>
#include <errno.h>
#include <stdio.h>

/* Global converters */
static UTransliterator* any_to_latin = NULL;
static iconv_t utf8_to_latin1 = (iconv_t)-1;

static void init_converters() {
    UErrorCode status;
    UChar id_buf[128];
    int32_t id_len;
    
    /* Initialize ICU for PASS 1: transliterate scripts to Latin */
    if (any_to_latin == NULL) {
        status = U_ZERO_ERROR;
        u_uastrcpy(id_buf, "Any-Latin");
        id_len = u_strlen(id_buf);
        
        any_to_latin = utrans_openU(
            id_buf,
            id_len,
            UTRANS_FORWARD,
            NULL, 0,
            NULL,
            &status
        );
        
        if (U_FAILURE(status)) {
            any_to_latin = NULL;
        }
    }
    
    /* Initialize iconv for PASS 2: UTF-8 → ISO-8859-1 with TRANSLIT */
    if (utf8_to_latin1 == (iconv_t)-1) {
        utf8_to_latin1 = iconv_open("ISO-8859-1//TRANSLIT", "UTF-8");
        if (utf8_to_latin1 == (iconv_t)-1) {
            /* Fallback without TRANSLIT */
            utf8_to_latin1 = iconv_open("ISO-8859-1", "UTF-8");
        }
    }
}

/* Convert UTF-8 string to ASCII, returns pointer to static buffer */
char* HTCharset_utf8_to_ascii(const char* utf8_str) {
    static char outbuf[2048];
    
    if (!utf8_str) return (char*)utf8_str;
    
    strncpy(outbuf, utf8_str, sizeof(outbuf) - 1);
    outbuf[sizeof(outbuf) - 1] = '\0';
    
    HTCharset_utf8_to_ascii_buffer(outbuf, strlen(outbuf));
    
    return outbuf;
}

/* Convert UTF-8 buffer to ISO-8859-1 in-place, returns new size
** Two-pass: 1) ICU Any-Latin  2) iconv UTF-8 → ISO-8859-1//TRANSLIT
*/
int HTCharset_utf8_to_ascii_buffer(char* str, int size) {
    char tempbuf[8192];
    char outbuf[8192];
    UChar ubuf[4096];
    int32_t ulen;
    int32_t capacity;
    UErrorCode status;
    int32_t outlen;
    char *inptr;
    char *outptr;
    size_t inleft;
    size_t outleft;
    
    if (!str || size <= 0 || size >= sizeof(tempbuf))
        return size;
    
    init_converters();
    
    if (any_to_latin == NULL || utf8_to_latin1 == (iconv_t)-1)
        return size;
    
    /* === PASS 1: ICU Any-Latin (Привет → Privet, 中文 → Zhōng wén, etc) === */
    status = U_ZERO_ERROR;
    u_strFromUTF8(ubuf, sizeof(ubuf)/sizeof(UChar), &ulen, str, size, &status);
    if (U_FAILURE(status))
        return size;
    
    capacity = ulen + 50;
    if (capacity > sizeof(ubuf)/sizeof(UChar))
        capacity = sizeof(ubuf)/sizeof(UChar);
    
    utrans_transUChars(any_to_latin, ubuf, &ulen, capacity, 0, &ulen, &status);
    if (U_FAILURE(status))
        return size;
    
    /* Convert back to UTF-8 for iconv */
    status = U_ZERO_ERROR;
    u_strToUTF8(tempbuf, sizeof(tempbuf), &outlen, ubuf, ulen, &status);
    if (U_FAILURE(status))
        return size;
    
    tempbuf[outlen] = '\0';
    
    /* === PASS 2: iconv UTF-8 → ISO-8859-1//TRANSLIT (• → *, keeps é ü ñ) === */
    inptr = tempbuf;
    outptr = outbuf;
    inleft = outlen;
    outleft = sizeof(outbuf) - 1;
    
    iconv(utf8_to_latin1, &inptr, &inleft, &outptr, &outleft);
    *outptr = '\0';
    outlen = outptr - outbuf;
    iconv(utf8_to_latin1, NULL, NULL, NULL, NULL); /* reset */
    
    /* Copy result back */
    memcpy(str, outbuf, outlen);
    str[outlen] = '\0';
    
    return outlen;
}

#else
/* No ICU/iconv - pass through unchanged */
char* HTCharset_utf8_to_ascii(const char* utf8_str) {
    return (char*)utf8_str;
}

int HTCharset_utf8_to_ascii_buffer(char* str, int size) {
    return size;
}
#endif

