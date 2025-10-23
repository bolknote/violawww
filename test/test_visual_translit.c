/*
 * Visual transliteration test - Cyrillic to visually similar Latin characters
 * 
 * This is a fun demonstration of "leetspeak"-style transliteration where
 * Cyrillic letters are replaced with visually similar Latin characters/symbols.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    const char *cyrillic;
    const char *visual;
} VisualMap;

/* Visual similarity mapping (leetspeak-style) 
** Case matters for visual similarity! */
static const VisualMap visual_map[] = {
    /* Lowercase */
    {"а", "a"},      /* а похожа на a */
    {"б", "6"},      /* б похожа на цифру 6 */
    {"в", "B"},      /* в похожа на прописную B */
    {"г", "r"},      /* г похожа на строчную r */
    {"д", "ð"},      /* д похожа на ð (eth) */
    {"е", "e"},      /* е похожа на e */
    {"ё", "ë"},      /* ё похожа на ë (e с диэрезисом) */
    {"ж", "}|{"},    /* ж - жук */
    {"з", "3"},      /* з похожа на 3 */
    {"и", "u"},      /* и похожа на u */
    {"й", "û"},      /* й похожа на û (u с краткой) */
    {"к", "k"},      /* к похожа на k */
    {"л", "/\\"},    /* л - угол */
    {"м", "M"},      /* м похожа на прописную M */
    {"н", "H"},      /* н похожа на прописную H */
    {"о", "o"},      /* о похожа на o */
    {"п", "n"},      /* п похожа на строчную n */
    {"р", "p"},      /* р похожа на p */
    {"с", "c"},      /* с похожа на c */
    {"т", "m"},      /* т похожа на m (палочка с крышей) */
    {"у", "y"},      /* у похожа на y */
    {"ф", "¤Þ"},     /* ф → ¤Þ (символ валюты + торн прописная) */
    {"х", "x"},      /* х похожа на x */
    {"ц", "u,"},     /* ц - u с хвостиком */
    {"ч", "4"},      /* ч похожа на 4 */
    {"ш", "w"},      /* ш похожа на строчную w */
    {"щ", "w,"},     /* щ - w с хвостиком */
    {"ъ", "¯b"},     /* ъ → ¯b (макрон + b) */
    {"ы", "bl"},     /* ы - b+l */
    {"ь", "b"},      /* ь похожа на b */
    {"э", "3"},      /* э похожа на 3 */
    {"ю", "IO"},     /* ю - I+O */
    {"я", "9I"},     /* я - 9+I */
    
    /* Uppercase */
    {"А", "A"},      /* А похожа на A */
    {"Б", "6"},      /* Б похожа на 6 */
    {"В", "B"},      /* В похожа на B */
    {"Г", "r"},      /* Г похожа на r (Г-образная) */
    {"Д", "ð"},      /* Д → ð (eth, ISO-8859-1) */
    {"Е", "E"},      /* Е похожа на E */
    {"Ё", "Ë"},      /* Ё похожа на Ë (E с диэрезисом) */
    {"Ж", "}|{"},    /* Ж - жук */
    {"З", "3"},      /* З похожа на 3 */
    {"И", "U"},      /* И похожа на прописную U */
    {"Й", "Û"},      /* Й похожа на Û (U с краткой) */
    {"К", "K"},      /* К похожа на K */
    {"Л", "/\\"},    /* Л - угол */
    {"М", "M"},      /* М похожа на M */
    {"Н", "H"},      /* Н похожа на H */
    {"О", "O"},      /* О похожа на O */
    {"П", "n"},      /* П похожа на строчную n (перевёрнутая U) */
    {"Р", "P"},      /* Р похожа на P */
    {"С", "C"},      /* С похожа на C */
    {"Т", "T"},      /* Т похожа на T */
    {"У", "Y"},      /* У похожа на Y */
    {"Ф", "¤þ"},     /* Ф → ¤þ (символ валюты + торн строчная) */
    {"Х", "X"},      /* Х похожа на X */
    {"Ц", "U,"},     /* Ц - U с хвостиком */
    {"Ч", "4"},      /* Ч похожа на 4 */
    {"Ш", "W"},      /* Ш похожа на прописную W */
    {"Щ", "W,"},     /* Щ - W с хвостиком */
    {"Ъ", "¯b"},     /* Ъ → ¯b (макрон + b) */
    {"Ы", "bI"},     /* Ы - b+I */
    {"Ь", "b"},      /* Ь похожа на b */
    {"Э", "3"},      /* Э похожа на 3 (зеркальная) */
    {"Ю", "IO"},     /* Ю - I+O */
    {"Я", "9I"},     /* Я - 9+I */
    
    {NULL, NULL}
};

/* Convert UTF-8 Cyrillic text to visual transliteration */
char* visual_transliterate(const char *input) {
    static char output[4096];
    const unsigned char *p = (const unsigned char *)input;
    char *out = output;
    int found;
    int i;
    
    while (*p && (out - output) < sizeof(output) - 100) {
        if (*p < 0x80) {
            /* ASCII character - just copy */
            *out++ = *p++;
        } else if ((*p & 0xE0) == 0xC0) {
            /* 2-byte UTF-8 character (Cyrillic) */
            unsigned char b1 = *p++;
            unsigned char b2 = *p++;
            char utf8_char[3] = {b1, b2, 0};
            
            /* Find in visual map */
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
                /* Unknown character - copy as is */
                *out++ = b1;
                *out++ = b2;
            }
        } else if ((*p & 0xF0) == 0xE0) {
            /* 3-byte UTF-8 character - just copy */
            *out++ = *p++;
            *out++ = *p++;
            *out++ = *p++;
        } else {
            /* Other multibyte - skip or copy */
            *out++ = *p++;
        }
    }
    *out = '\0';
    
    return output;
}

int main(int argc, char *argv[]) {
    const char *test_text = "Съешь ещё этих мягких французских булок, да выпей же чаю";
    const char *lowercase = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const char *uppercase = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    int i;
    
    /* If arguments provided, just transliterate them */
    if (argc > 1) {
        char input[8192] = "";
        for (i = 1; i < argc; i++) {
            if (i > 1) strcat(input, " ");
            strcat(input, argv[i]);
        }
        printf("%s\n", visual_transliterate(input));
        return 0;
    }
    
    printf("═══════════════════════════════════════════════════════════════════════\n");
    printf("  ВИЗУАЛЬНАЯ ТРАНСЛИТЕРАЦИЯ (Visual/Leetspeak Transliteration)\n");
    printf("═══════════════════════════════════════════════════════════════════════\n\n");
    
    printf("Маппинг визуально похожих символов:\n");
    printf("───────────────────────────────────────────────────────────────────────\n");
    printf("  Г → r     (похоже по форме)\n");
    printf("  Л → /\\    (крыша/угол)\n");
    printf("  я → 9I    (девятка + I)\n");
    printf("  б → 6     (шестёрка)\n");
    printf("  ч → 4     (четвёрка)\n");
    printf("  ш → iii   (три палочки)\n");
    printf("  щ → iii,  (три палочки с хвостиком)\n");
    printf("  ж → }|{   (жук)\n");
    printf("  н → H     (аш)\n");
    printf("  р → p     (пэ)\n");
    printf("  с → c     (си)\n");
    printf("  у → y     (игрек)\n");
    printf("  ы → bl    (бл)\n");
    printf("  ь → b     (бэ)\n");
    printf("  ю → IO    (ай-о)\n");
    printf("  з → 3     (тройка)\n");
    printf("  и → u     (ю)\n");
    printf("  т → T     (тэ)\n");
    printf("  м → M     (эм)\n");
    printf("  в → B     (би)\n");
    printf("  х → x     (икс)\n");
    printf("  к → k     (кей)\n");
    printf("  о → o     (о)\n");
    printf("  а → a     (эй)\n");
    printf("  е → e     (и)\n");
    printf("\n");
    
    printf("═══════════════════════════════════════════════════════════════════════\n");
    printf("  ПОЛНЫЙ РУССКИЙ АЛФАВИТ\n");
    printf("═══════════════════════════════════════════════════════════════════════\n\n");
    
    printf("Строчные буквы (lowercase):\n");
    printf("  Оригинал:  %s\n", lowercase);
    printf("  Визуально: %s\n\n", visual_transliterate(lowercase));
    
    printf("Прописные буквы (uppercase):\n");
    printf("  Оригинал:  %s\n", uppercase);
    printf("  Визуально: %s\n\n", visual_transliterate(uppercase));
    
    printf("═══════════════════════════════════════════════════════════════════════\n");
    printf("  ТЕСТ: Панграмма про французские булочки\n");
    printf("═══════════════════════════════════════════════════════════════════════\n\n");
    
    printf("Оригинал (кириллица):\n");
    printf("┌───────────────────────────────────────────────────────────────────────┐\n");
    printf("│ %s\n", test_text);
    printf("└───────────────────────────────────────────────────────────────────────┘\n\n");
    
    printf("Визуальная транслитерация (leetspeak):\n");
    printf("┌───────────────────────────────────────────────────────────────────────┐\n");
    printf("│ %s\n", visual_transliterate(test_text));
    printf("└───────────────────────────────────────────────────────────────────────┘\n\n");
    
    printf("═══════════════════════════════════════════════════════════════════════\n");
    printf("  ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ\n");
    printf("═══════════════════════════════════════════════════════════════════════\n\n");
    
    const char *examples[] = {
        "Привет, мир!",
        "Москва",
        "Санкт-Петербург",
        "щавель",
        "борщ",
        "чай",
        "жизнь",
        "Владивосток",
        "Хрущёв",
        "юность",
        "ягода",
        NULL
    };
    
    printf("%-25s → %s\n", "Оригинал", "Визуальная транслитерация");
    printf("─────────────────────────────────────────────────────────────────────\n");
    
    for (i = 0; examples[i] != NULL; i++) {
        printf("%-25s → %s\n", examples[i], visual_transliterate(examples[i]));
    }
    
    printf("\n");
    printf("═══════════════════════════════════════════════════════════════════════\n");
    printf("  ПРИМЕЧАНИЯ\n");
    printf("═══════════════════════════════════════════════════════════════════════\n\n");
    printf("• Это художественная/игровая транслитерация для визуального эффекта\n");
    printf("• Не предназначена для серьёзного использования или обратной конвертации\n");
    printf("• Похожа на leetspeak (1337speak) - интернет-сленг замены букв символами\n");
    printf("• Использует визуальное сходство, а не фонетику\n");
    printf("• Некоторые символы могут плохо отображаться в разных терминалах\n\n");
    
    return 0;
}

