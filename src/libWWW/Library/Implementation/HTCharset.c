/*  HTCharset.c - Character encoding conversion and transliteration
**
**  Hybrid transliteration chain:
**    ICU chain: Russian-Latin/BGN → Any-Latin
**    - BGN handles Cyrillic (щ→shch, я→ya, readable for English)
**    - Any-Latin handles everything else (Greek→Latin, Arabic→Latin, 中文→pinyin, etc.)
**
**  Three-pass conversion:
**    1. iconv: Source encoding → UTF-8 (e.g., windows-1251 → UTF-8)
**    2. ICU: Russian-Latin/BGN; Any-Latin (chain transliteration)
**    3. iconv: UTF-8 → ISO-8859-1//TRANSLIT (• → *, " → ", keeps é ü ñ)
*/

#include "HTCharset.h"
#include "HTUtils.h"
#include <string.h>
#include <strings.h>

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
    UChar id_buf[256];
    
    /* Initialize hybrid transliterator as a chain:
    ** Russian-Latin/BGN handles Cyrillic (щ→shch, я→ya)
    ** Any-Latin handles everything else (Greek, Arabic, Chinese, etc.)
    ** Chain ensures both are applied in sequence */
    if (any_to_latin == NULL) {
        status = U_ZERO_ERROR;
        u_uastrcpy(id_buf, "Russian-Latin/BGN; Any-Latin");
        
        any_to_latin = utrans_openU(
            id_buf,
            u_strlen(id_buf),
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
** Hybrid chain approach: Russian-Latin/BGN → Any-Latin
**   - BGN handles Cyrillic (щ→shch, я→ya, readable for English)
**   - Any-Latin handles everything else (Greek, Arabic, Chinese, etc.)
** Two-pass: 1) ICU chain transliteration  2) iconv UTF-8 → ISO-8859-1//TRANSLIT
** WARNING: Output may be up to 2x larger than input due to transliteration
**          Caller must ensure str buffer has enough space
*/
int HTCharset_utf8_to_ascii_buffer(char* str, int size) {
    char tempbuf[16384];
    char outbuf[16384];
    UChar ubuf[8192];
    int32_t ulen;
    int32_t capacity;
    UErrorCode status;
    int32_t outlen;
    char *inptr;
    char *outptr;
    size_t inleft;
    size_t outleft;
    
    if (!str || size <= 0 || size >= sizeof(tempbuf) / 2)
        return size;
    
    init_converters();
    
    if (any_to_latin == NULL || utf8_to_latin1 == (iconv_t)-1)
        return size;
    
    /* === PASS 1: ICU chain transliteration (BGN for Cyrillic, Any-Latin for rest) === */
    status = U_ZERO_ERROR;
    u_strFromUTF8(ubuf, sizeof(ubuf)/sizeof(UChar), &ulen, str, size, &status);
    if (U_FAILURE(status))
        return size;
    
    capacity = ulen + 100;
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

/* Convert from arbitrary encoding to ASCII with transliteration
** Three-pass conversion:
**   1. iconv: Source encoding → UTF-8
**   2. ICU: Any-Latin
**   3. iconv: UTF-8 → ISO-8859-1//TRANSLIT
*/
int HTCharset_convert_to_ascii(const char* charset, const char* inbuf, int insize,
                                 char* outbuf, int outsize) {
    char utf8buf[32768];
    char* inptr;
    char* outptr;
    size_t inleft;
    size_t outleft;
    iconv_t cd;
    int utf8_size;
    int result;
    
    if (!inbuf || insize <= 0 || !outbuf || outsize <= 0)
        return -1;
    
    /* If already UTF-8 or no charset specified, skip to transliteration */
    if (!charset || strcasecmp(charset, "UTF-8") == 0 || strcasecmp(charset, "utf8") == 0) {
        if (insize >= outsize)
            return -1;
        memcpy(outbuf, inbuf, insize);
        outbuf[insize] = '\0';
        return HTCharset_utf8_to_ascii_buffer(outbuf, insize);
    }
    
    /* === PASS 0: Convert from source encoding to UTF-8 (IGNORE invalid/mixed bytes) === */
    cd = iconv_open("UTF-8//IGNORE", charset);
    if (cd == (iconv_t)-1) {
        if (TRACE)
            fprintf(stderr, "HTCharset: Cannot convert from %s to UTF-8\n", charset);
        return -1;
    }
    
    inptr = (char*)inbuf;
    outptr = utf8buf;
    inleft = insize;
    outleft = sizeof(utf8buf) - 1;
    
    if (iconv(cd, &inptr, &inleft, &outptr, &outleft) == (size_t)-1) {
        if (TRACE)
            fprintf(stderr, "HTCharset: Conversion from %s to UTF-8 failed: %s\n", 
                    charset, strerror(errno));
        iconv_close(cd);
        return -1;
    }
    
    *outptr = '\0';
    utf8_size = outptr - utf8buf;
    iconv_close(cd);
    
    if (TRACE)
        fprintf(stderr, "HTCharset: Converted %d bytes from %s to %d bytes UTF-8\n",
                insize, charset, utf8_size);
    
    /* === PASS 1-2: UTF-8 → Transliterated ASCII === */
    if (utf8_size >= outsize)
        return -1;
    
    memcpy(outbuf, utf8buf, utf8_size);
    outbuf[utf8_size] = '\0';
    
    result = HTCharset_utf8_to_ascii_buffer(outbuf, utf8_size);
    
    return result;
}

#else
/* No ICU/iconv - pass through unchanged */
char* HTCharset_utf8_to_ascii(const char* utf8_str) {
    return (char*)utf8_str;
}

int HTCharset_utf8_to_ascii_buffer(char* str, int size) {
    return size;
}

int HTCharset_convert_to_ascii(const char* charset, const char* inbuf, int insize,
                                 char* outbuf, int outsize) {
    /* No ICU/iconv support - just copy */
    if (insize >= outsize)
        return -1;
    memcpy(outbuf, inbuf, insize);
    outbuf[insize] = '\0';
    return insize;
}
#endif

