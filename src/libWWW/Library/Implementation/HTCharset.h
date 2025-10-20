/*  HTCharset.h - Character encoding conversion and transliteration
**
**  Conversion process:
**    1. Convert from source encoding (e.g., windows-1251) to UTF-8
**    2. ICU: Any-Latin (Cyrillic → Latin, Greek → Latin, Chinese → Pinyin)
**    3. iconv: UTF-8 → ISO-8859-1//TRANSLIT (• → *, keeps é ü ñ)
*/

#ifndef HTCHARSET_H
#define HTCHARSET_H

/* Convert UTF-8 string to ASCII with transliteration
** Returns pointer to static buffer (valid until next call)
** Returns original string if conversion fails or not available
*/
char* HTCharset_utf8_to_ascii(const char* utf8_str);

/* Convert UTF-8 buffer to ASCII in-place
** WARNING: Output may be larger than input (up to 2x for some transliterations)
** str buffer must have enough space for expansion
** Returns new size (may be larger or smaller than original)
** Modifies str in place
*/
int HTCharset_utf8_to_ascii_buffer(char* str, int size);

/* Convert from arbitrary encoding to ASCII with transliteration
** charset: Source encoding (e.g., "windows-1251", "KOI8-R", "ISO-8859-1")
**          NULL or "UTF-8" means source is already UTF-8
** inbuf: Input buffer
** insize: Input size in bytes
** outbuf: Output buffer (must be at least insize * 8 bytes for safety)
** outsize: Output buffer size in bytes
** Returns: Number of bytes written to outbuf, or -1 on error
*/
int HTCharset_convert_to_ascii(const char* charset, const char* inbuf, int insize,
                                 char* outbuf, int outsize);

#endif /* HTCHARSET_H */

