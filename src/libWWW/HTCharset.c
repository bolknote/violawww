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
    inleft = (size_t)outlen;
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
    inleft = (size_t)insize;
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

/* Decode one MIME encoded-word: =?charset?encoding?text?=
** Returns decoded length, or -1 on error
*/
PRIVATE int decode_mime_word(const char* start, const char* end, 
                              char* outbuf, int outsize) {
    char charset[64];
    char encoding;
    const char *p, *text_start, *text_end;
    char decoded[2048];
    int decoded_len = 0;
    int i;
    
    /* Parse: =?charset?encoding?text?= */
    p = start + 2;  /* skip =? */
    
    /* Extract charset */
    i = 0;
    while (p < end && *p != '?' && i < sizeof(charset) - 1) {
        charset[i++] = *p++;
    }
    charset[i] = '\0';
    if (*p != '?') return -1;
    p++;  /* skip ? */
    
    /* Get encoding (Q or B) */
    encoding = *p++;
    if (*p != '?') return -1;
    p++;  /* skip ? */
    
    text_start = p;
    
    /* Find end of text */
    text_end = end - 2;  /* before ?= */
    
    if (encoding == 'Q' || encoding == 'q') {
        /* Quoted-Printable decoding */
        while (p < text_end && decoded_len < sizeof(decoded) - 1) {
            if (*p == '=') {
                /* =XX hex escape */
                if (p + 2 < text_end) {
                    int hi = p[1];
                    int lo = p[2];
                    hi = (hi >= '0' && hi <= '9') ? hi - '0' : 
                         (hi >= 'A' && hi <= 'F') ? hi - 'A' + 10 :
                         (hi >= 'a' && hi <= 'f') ? hi - 'a' + 10 : -1;
                    lo = (lo >= '0' && lo <= '9') ? lo - '0' : 
                         (lo >= 'A' && lo <= 'F') ? lo - 'A' + 10 :
                         (lo >= 'a' && lo <= 'f') ? lo - 'a' + 10 : -1;
                    if (hi >= 0 && lo >= 0) {
                        decoded[decoded_len++] = (hi << 4) | lo;
                        p += 3;
                        continue;
                    }
                }
                decoded[decoded_len++] = *p++;
            } else if (*p == '_') {
                /* underscore = space in Q encoding */
                decoded[decoded_len++] = ' ';
                p++;
            } else {
                decoded[decoded_len++] = *p++;
            }
        }
    } else if (encoding == 'B' || encoding == 'b') {
        /* Base64 decoding */
        static const signed char b64_table[256] = {
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,63,
            52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-1,-1,-1,
            -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,
            15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,
            -1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
            41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
        };
        unsigned int accum = 0;
        int bits = 0;
        
        while (p < text_end && decoded_len < sizeof(decoded) - 1) {
            int v = b64_table[(unsigned char)*p++];
            if (v < 0) continue;  /* skip invalid chars */
            accum = (accum << 6) | v;
            bits += 6;
            if (bits >= 8) {
                bits -= 8;
                decoded[decoded_len++] = (accum >> bits) & 0xFF;
            }
        }
    } else {
        return -1;  /* Unknown encoding */
    }
    
    decoded[decoded_len] = '\0';
    
    /* Convert to ASCII with transliteration */
    return HTCharset_convert_to_ascii(charset, decoded, decoded_len, outbuf, outsize);
}

/* Decode MIME encoded-word (RFC 2047) and transliterate to ASCII
** Handles multiple encoded-words in a string
*/
char* HTCharset_decode_mime(char* str) {
    char result[4096];
    
    if (TRACE)
        fprintf(stderr, "HTCharset_decode_mime: input='%s'\n", str ? str : "(null)");
    char *src = str;
    char *dst = result;
    char *end = result + sizeof(result) - 1;
    
    if (!str) return str;
    
    while (*src && dst < end) {
        /* Look for =? start of encoded-word */
        if (src[0] == '=' && src[1] == '?') {
            /* Find ?= end marker */
            char *word_end = src + 2;
            int q_count = 0;
            
            while (*word_end && q_count < 3) {
                if (*word_end == '?') q_count++;
                word_end++;
            }
            
            /* After loop: word_end points to '=' in "?=" (after third '?') */
            if (q_count == 3 && *word_end == '=') {
                /* Valid encoded-word found, include the trailing '=' */
                word_end++;  /* Now points past the "?=" */
                
                char decoded[1024];
                int len;
                
                if (TRACE)
                    fprintf(stderr, "HTCharset_decode_mime: Found encoded-word, q_count=%d\n", q_count);
                
                len = decode_mime_word(src, word_end, decoded, sizeof(decoded));
                
                if (TRACE)
                    fprintf(stderr, "HTCharset_decode_mime: decode_mime_word returned %d, decoded='%s'\n", 
                            len, len > 0 ? decoded : "(failed)");
                
                if (len > 0) {
                    /* Copy decoded text */
                    int i;
                    for (i = 0; i < len && dst < end; i++) {
                        *dst++ = decoded[i];
                    }
                    src = word_end;
                    
                    /* Skip whitespace between encoded-words */
                    while (*src == ' ' || *src == '\t') {
                        if (src[1] == '=' && src[2] == '?') {
                            src++;  /* Skip space between encoded-words */
                        } else {
                            break;
                        }
                    }
                    continue;
                }
            }
        }
        
        /* Copy regular character */
        *dst++ = *src++;
    }
    
    *dst = '\0';
    
    /* Copy back to original buffer */
    strcpy(str, result);
    return str;
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

char* HTCharset_decode_mime(char* str) {
    return str;  /* No decoding without ICU */
}
#endif

