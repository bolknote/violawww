# Character Encoding Transliteration

Legacy ViolaWWW rendering still targets ISO-8859-1 fonts. Modern servers often send UTF-8, Windows-1251, KOI8-R, etc. Instead of showing mojibake, we transliterate everything that is not plain Latin-1 into a readable ASCII/Latin-1 approximation.

## Pipeline (HTCharset.c)
- **Pass 0 — to UTF-8:** `iconv(charset → UTF-8//IGNORE)` drops malformed bytes instead of aborting on mixed encodings.
- **Pass 1 — ICU transliteration:** Chain `"Russian-Latin/BGN; Any-Latin"` so Cyrillic uses BGN rules (щ→shch, я→ya) and Any-Latin handles everything else (Greek, Arabic, Chinese → pinyin, etc.). Implemented in `HTCharset_utf8_to_ascii_buffer()`.
- **Pass 2 — to Latin-1 with translit:** `iconv(UTF-8 → ISO-8859-1//TRANSLIT)` maps remaining characters (•→*, →→->, —→-) while preserving Latin diacritics when possible; falls back to plain ISO-8859-1 if `//TRANSLIT` is unavailable.
- **Buffers & growth:** Output can grow ~2×; call sites allocate 8× safety buffers (`HTPlain`, `HTCharset_utf8_to_ascii_buffer`). Caller must provide space.
- **No ICU build:** When compiled without `USE_ICU`, the functions become pass-through copies (no transliteration).

## Entry Points
- `HTCharset_convert_to_ascii(charset, in, len, out, outlen)`: full three-pass conversion from an arbitrary charset to Latin-1/ASCII.
- `HTCharset_utf8_to_ascii_buffer(str, len)`: in-place transliteration of UTF-8 buffers (used when charset is already UTF-8 or unknown).
- `HTCharset_decode_mime(str)`: decodes RFC 2047 encoded-words (`=?charset?Q?...?=` / `=?charset?B?...?=`), then runs `convert_to_ascii`.

## Where It Runs
- **HTTP/plain text:** `HTPlain_write()` grabs `HTAnchor_charset()` and converts the response body when the charset is not UTF-8/Latin-1. Otherwise it tries UTF-8 transliteration before falling back to raw bytes.
- **HTML parsing:** `html2.c` uses `HTCharset_utf8_to_ascii_buffer()` for UTF-8 text slices before handing them to the SGML layer.
- **News/NNTP:** `HTNews.c`
  - Headers: `HTCharset_decode_mime()` transliterates `Subject`, `From`, `Date` and other MIME-encoded fields in group listings and articles.
  - Body: If `Content-Type` has a `charset` that is not Latin-1, each line is run through `HTCharset_convert_to_ascii()` before rendering (format=flowed logic happens after conversion).

## Why This Exists (not original code)
- The 1990s code assumed Latin-1/X11 fonts. Modern content regularly arrives in other encodings; without conversion we would render gibberish or drop text.
- This transliteration chain is a **2025 enhancement** (see main [README.md](../README.md), section “Modern Enhancements”) rather than part of the historic ViolaWWW sources.

## Change History (troubleshooting context)
- **2025-10-25 cb8ad1f6** — Introduced `HTCharset.c/h`: iconv + ICU pipeline for UTF-8/Windows-1251/KOI8-R and other encodings after the repository reshuffle.
- **2025-12-09 f1d285a3** — Added `HTCharset_decode_mime()` and wired NNTP headers to it; fixed UBSan/misaligned hostent issues and news connection cleanup. This resolved unreadable non-ASCII subjects/authors in news listings.

## Operational Notes
- If `iconv()` lacks `//TRANSLIT`, conversion still runs but may drop symbols instead of approximating them.
- `//IGNORE` in the first `iconv()` prevents hard failures on mixed encodings but can discard invalid bytes; this was chosen to keep pages/news bodies readable.
- ICU availability is mandatory for non-Latin scripts; builds without ICU print a warning (“Building without ICU…”) and will not transliterate UTF-8.
