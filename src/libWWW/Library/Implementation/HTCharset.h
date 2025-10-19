/*  HTCharset.h - UTF-8 to ISO-8859-1 transliteration
**
**  Two-pass conversion using ICU:
**    1. ICU: Any-Latin (Cyrillic → Latin, Greek → Latin, Chinese → Pinyin)
**    2. ICU: Convert to ISO-8859-1 (keeps diacritics é ü ñ, • → ?)
*/

#ifndef HTCHARSET_H
#define HTCHARSET_H

/* Convert UTF-8 string to ASCII with transliteration
** Returns pointer to static buffer (valid until next call)
** Returns original string if conversion fails or not available
*/
char* HTCharset_utf8_to_ascii(const char* utf8_str);

/* Convert UTF-8 buffer to ASCII in-place
** Returns new size (may be smaller than original)
** Modifies str in place
*/
int HTCharset_utf8_to_ascii_buffer(char* str, int size);

#endif /* HTCHARSET_H */

