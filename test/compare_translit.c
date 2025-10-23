/*
 * Comparison of transliteration methods:
 * 1. Visual/Leetspeak transliteration (visually similar characters)
 * 2. Standard ICU BGN transliteration (used in ViolaWWW browser)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unicode/utrans.h>
#include <unicode/ustring.h>

typedef struct {
    const char *cyrillic;
    const char *visual;
} VisualMap;

/* Visual similarity mapping (leetspeak-style) */
static const VisualMap visual_map[] = {
    /* Lowercase */
    {"а", "a"}, {"б", "6"}, {"в", "B"}, {"г", "r"}, {"д", "ð"},
    {"е", "e"}, {"ё", "ë"}, {"ж", "}|{"}, {"з", "3"}, {"и", "u"},
    {"й", "û"}, {"к", "k"}, {"л", "/\\"}, {"м", "M"}, {"н", "H"},
    {"о", "o"}, {"п", "n"}, {"р", "p"}, {"с", "c"}, {"т", "m"},
    {"у", "y"}, {"ф", "¤Þ"}, {"х", "x"}, {"ц", "u,"}, {"ч", "4"},
    {"ш", "w"}, {"щ", "w,"}, {"ъ", "¯b"}, {"ы", "bl"}, {"ь", "b"},
    {"э", "3"}, {"ю", "IO"}, {"я", "9I"},
    
    /* Uppercase */
    {"А", "A"}, {"Б", "6"}, {"В", "B"}, {"Г", "r"}, {"Д", "ð"},
    {"Е", "E"}, {"Ё", "Ë"}, {"Ж", "}|{"}, {"З", "3"}, {"И", "U"},
    {"Й", "Û"}, {"К", "K"}, {"Л", "/\\"}, {"М", "M"}, {"Н", "H"},
    {"О", "O"}, {"П", "n"}, {"Р", "P"}, {"С", "C"}, {"Т", "T"},
    {"У", "Y"}, {"Ф", "¤þ"}, {"Х", "X"}, {"Ц", "U,"}, {"Ч", "4"},
    {"Ш", "W"}, {"Щ", "W,"}, {"Ъ", "¯b"}, {"Ы", "bI"}, {"Ь", "b"},
    {"Э", "3"}, {"Ю", "IO"}, {"Я", "9I"},
    
    {NULL, NULL}
};

/* Convert UTF-8 Cyrillic text to visual transliteration */
char* visual_transliterate(const char *input) {
    static char output[8192];
    const unsigned char *p = (const unsigned char *)input;
    char *out = output;
    int found, i;
    
    while (*p && (out - output) < sizeof(output) - 100) {
        if (*p < 0x80) {
            *out++ = *p++;
        } else if ((*p & 0xE0) == 0xC0) {
            unsigned char b1 = *p++;
            unsigned char b2 = *p++;
            char utf8_char[3] = {b1, b2, 0};
            
            found = 0;
            for (i = 0; visual_map[i].cyrillic != NULL; i++) {
                if (strcmp(utf8_char, visual_map[i].cyrillic) == 0) {
                    strcpy(out, visual_map[i].visual);
                    out += strlen(visual_map[i].visual);
                    found = 1;
                    break;
                }
            }
            
            if (!found) {
                *out++ = b1;
                *out++ = b2;
            }
        } else if ((*p & 0xF0) == 0xE0) {
            *out++ = *p++;
            *out++ = *p++;
            *out++ = *p++;
        } else {
            *out++ = *p++;
        }
    }
    *out = '\0';
    return output;
}

/* Standard ICU BGN transliteration (as used in ViolaWWW) */
char* icu_transliterate(const char *input) {
    static char output[8192];
    UChar ubuf[4096];
    UChar result_buf[4096];
    int32_t ulen;
    int32_t result_len;
    UErrorCode status = U_ZERO_ERROR;
    static UTransliterator *trans = NULL;
    UChar id_buf[256];
    
    /* Initialize transliterator (Russian-Latin/BGN; Any-Latin chain) */
    if (trans == NULL) {
        u_uastrcpy(id_buf, "Russian-Latin/BGN; Any-Latin");
        trans = utrans_openU(id_buf, u_strlen(id_buf), UTRANS_FORWARD,
                            NULL, 0, NULL, &status);
        if (U_FAILURE(status)) {
            strcpy(output, "[ICU Error]");
            return output;
        }
    }
    
    /* Convert UTF-8 to UChar */
    u_strFromUTF8(ubuf, 4096, &ulen, input, -1, &status);
    if (U_FAILURE(status)) {
        strcpy(output, "[UTF-8 Conversion Error]");
        return output;
    }
    
    /* Transliterate */
    u_strcpy(result_buf, ubuf);
    result_len = ulen;
    int32_t limit = result_len;
    utrans_transUChars(trans, result_buf, &result_len, 4096, 0, &limit, &status);
    if (U_FAILURE(status)) {
        strcpy(output, "[Transliteration Error]");
        return output;
    }
    
    /* Convert back to UTF-8 */
    u_strToUTF8(output, 8192, NULL, result_buf, result_len, &status);
    if (U_FAILURE(status)) {
        strcpy(output, "[UTF-8 Output Error]");
        return output;
    }
    
    return output;
}

/* Print side-by-side comparison in 3 columns */
void print_comparison(const char *line) {
    char *visual = visual_transliterate(line);
    char *icu = icu_transliterate(line);
    
    /* Print as tab-separated columns for piping to 'column -t -s $'\t'' */
    printf("%s\t%s\t%s\n", line, visual, icu);
}

int main(int argc, char *argv[]) {
    char line[1024];
    
    if (argc > 1 && strcmp(argv[1], "-f") == 0) {
        /* Read from stdin */
        /* Print header */
        printf("ОРИГИНАЛ\tВИЗУАЛЬНО (Leetspeak)\tICU BGN (браузер)\n");
        printf("───────────────────────────────\t───────────────────────────────\t───────────────────────────────\n");
        
        while (fgets(line, sizeof(line), stdin)) {
            /* Remove trailing newline */
            line[strcspn(line, "\n")] = 0;
            print_comparison(line);
        }
        
        return 0;
    }
    
    if (argc > 1) {
        /* Process command line argument */
        char input[8192] = "";
        int i;
        for (i = 1; i < argc; i++) {
            if (i > 1) strcat(input, " ");
            strcat(input, argv[i]);
        }
        
        printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
        printf("║  СРАВНЕНИЕ МЕТОДОВ ТРАНСЛИТЕРАЦИИ                                     ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════╝\n\n");
        
        print_comparison(input);
        
        return 0;
    }
    
    /* Demo mode */
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║  СРАВНЕНИЕ МЕТОДОВ ТРАНСЛИТЕРАЦИИ                                     ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    printf("║  1. ВИЗУАЛЬНАЯ (Visual/Leetspeak) - визуально похожие символы        ║\n");
    printf("║  2. ICU BGN (Russian-Latin/BGN) - стандарт географических названий   ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n\n");
    
    const char *examples[] = {
        "Привет, мир!",
        "Москва",
        "Санкт-Петербург",
        "щавель",
        "борщ",
        "чай",
        "жизнь",
        "Съешь ещё этих мягких французских булок",
        NULL
    };
    
    int i;
    for (i = 0; examples[i] != NULL; i++) {
        print_comparison(examples[i]);
    }
    
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║  ОПИСАНИЕ МЕТОДОВ                                                     ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n\n");
    
    printf("ВИЗУАЛЬНАЯ ТРАНСЛИТЕРАЦИЯ (Visual/Leetspeak):\n");
    printf("  • Основана на визуальном сходстве символов\n");
    printf("  • Примеры: ж→}|{, л→/\\, я→9I, ч→4, б→6\n");
    printf("  • Художественный/игровой эффект\n");
    printf("  • Похожа на интернет-сленг 1337speak\n\n");
    
    printf("ICU BGN ТРАНСЛИТЕРАЦИЯ (Russian-Latin/BGN):\n");
    printf("  • Стандарт Board on Geographic Names (BGN/PCGN)\n");
    printf("  • Примеры: ж→zh, ш→sh, щ→shch, я→ya, ю→yu\n");
    printf("  • Фонетически читаемая для англоязычных\n");
    printf("  • Используется в ViolaWWW браузере\n");
    printf("  • Официальный стандарт для географических названий\n\n");
    
    return 0;
}

