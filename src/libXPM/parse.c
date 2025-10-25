/* Copyright 1990,91 GROUPE BULL -- See licence conditions in file COPYRIGHT */
/*****************************************************************************\
* parse.c:                                                                    *
*                                                                             *
*  XPM library                                                                *
*  Parse an XPM file or array and store the found informations                *
*  in an an xpmInternAttrib structure which is returned.                      *
*                                                                             *
*  Developed by Arnaud Le Hors                                                *
\*****************************************************************************/

#include "xpmP.h"
#include <stdlib.h>

char* xpmColorKeys[] = {
    "s",  /* key #1: symbol */
    "m",  /* key #2: mono visual */
    "g4", /* key #3: 4 grays visual */
    "g",  /* key #4: gray visual */
    "c",  /* key #5: color visual */
};

// function call in case of error, frees only localy allocated variables
#undef RETURN
#define RETURN(status)                                                                             \
    {                                                                                              \
        if (colorTable)                                                                            \
            xpmFreeColorTable(colorTable, ncolors);                                                \
        if (chars)                                                                                 \
            free(chars);                                                                           \
        if (pixelindex)                                                                            \
            free(pixelindex);                                                                      \
        if (hints_cmt)                                                                             \
            free(hints_cmt);                                                                       \
        if (colors_cmt)                                                                            \
            free(colors_cmt);                                                                      \
        if (pixels_cmt)                                                                            \
            free(pixels_cmt);                                                                      \
        return (status);                                                                           \
    }

// This function parses an Xpm file or data and store the found informations
// in an xpmInternAttrib structure which is returned.
int xpmParseData(xpmData* data, xpmInternAttrib* attrib_return, XpmAttributes* attributes)
{
    /* variables to return */
    unsigned int width, height;
    unsigned int ncolors = 0;
    unsigned int cpp;
    unsigned int x_hotspot, y_hotspot, hotspot = 0;
    char*** colorTable = NULL;
    unsigned int* pixelindex = NULL;
    char* hints_cmt = NULL;
    char* colors_cmt = NULL;
    char* pixels_cmt = NULL;

    /* calculation variables */
    // read number of colors, it is different to ncolors to avoid
    // problem when freeing the colorTable in case an error
    // occurs while reading the hints line
    unsigned int rncolors = 0;
    char *chars = NULL, buf[BUFSIZ];
    unsigned int* iptr;

    /*
     * read hints: width, height, ncolors, chars_per_pixel
     */
    if (!(xpmNextUI(data, &width) && xpmNextUI(data, &height) && xpmNextUI(data, &rncolors) &&
          xpmNextUI(data, &cpp)))
        RETURN(XpmFileInvalid);

    ncolors = rncolors;

    /*
     * Security: validate dimensions to prevent integer overflow and excessive memory allocation
     * Limit to 65535x65535 pixels (reasonable maximum for early 90s browser)
     */
    if (width == 0 || height == 0 || width > 65535 || height > 65535)
        RETURN(XpmFileInvalid);
    
    /* Check for integer overflow in width * height */
    if (width > 0xFFFFFFFF / height)
        RETURN(XpmFileInvalid);
    
    /* Validate color count - must be at least 1 and not excessive */
    if (ncolors == 0 || ncolors > 32768)
        RETURN(XpmFileInvalid);
    
    /* Validate chars per pixel - must be at least 1 and reasonable */
    if (cpp == 0 || cpp > 16)
        RETURN(XpmFileInvalid);

    /*
     * read hotspot coordinates if any
     */
    hotspot = xpmNextUI(data, &x_hotspot) && xpmNextUI(data, &y_hotspot);

    /*
     * store the hints comment line
     */
    if (attributes && (attributes->valuemask & XpmReturnInfos))
        xpmGetCmt(data, &hints_cmt);

    // read colors
    colorTable = (char***)calloc(ncolors, sizeof(char**));
    if (!colorTable)
        RETURN(XpmNoMemory);

    for (unsigned int a = 0; a < ncolors; a++) {
        xpmNextString(data); // skip the line
        colorTable[a] = (char**)calloc((NKEYS + 1), sizeof(char*));
        if (!colorTable[a])
            RETURN(XpmNoMemory);

        // read pixel value
        *colorTable[a] = (char*)malloc(cpp);
        if (!*colorTable[a])
            RETURN(XpmNoMemory);
        for (unsigned int b = 0; b < cpp; b++)
            colorTable[a][0][b] = xpmGetC(data);

        // read color keys and values
        unsigned int l;
        while ((l = xpmNextWord(data, buf))) {
            unsigned int key;
            for (key = 1; key < NKEYS + 1; key++)
                if (!strncmp(xpmColorKeys[key - 1], buf, l))
                    break;
            if (key <= NKEYS && (l = xpmNextWord(data, buf))) {
                colorTable[a][key] = (char*)malloc(l + 1);
                if (!colorTable[a][key])
                    RETURN(XpmNoMemory);
                strncpy(colorTable[a][key], buf, l);
                colorTable[a][key][l] = '\0';
            } else
                RETURN(XpmFileInvalid); // key without value
        }
    }

    /*
     * store the colors comment line
     */
    if (attributes && (attributes->valuemask & XpmReturnInfos))
        xpmGetCmt(data, &colors_cmt);

    // read pixels and index them on color number
    pixelindex = (unsigned int*)malloc(sizeof(unsigned int) * width * height);
    if (!pixelindex)
        RETURN(XpmNoMemory);

    iptr = pixelindex;

    chars = (char*)malloc(cpp);
    if (!chars)
        RETURN(XpmNoMemory);

    for (unsigned int y = 0; y < height; y++) {
        xpmNextString(data);
        for (unsigned int x = 0; x < width; x++, iptr++) {
            for (unsigned int a = 0; a < cpp; a++)
                chars[a] = xpmGetC(data);
            
            unsigned int a;
            for (a = 0; a < ncolors; a++)
                if (!strncmp(colorTable[a][0], chars, cpp))
                    break;
            if (a == ncolors)
                RETURN(XpmFileInvalid); // no color matches
            *iptr = a;
        }
    }

    /*
     * store the pixels comment line
     */
    if (attributes && (attributes->valuemask & XpmReturnInfos))
        xpmGetCmt(data, &pixels_cmt);

    free(chars);

    /*
     * store found informations in the xpmInternAttrib structure
     */
    attrib_return->width = width;
    attrib_return->height = height;
    attrib_return->cpp = cpp;
    attrib_return->ncolors = ncolors;
    attrib_return->colorTable = colorTable;
    attrib_return->pixelindex = pixelindex;

    if (attributes) {
        if (attributes->valuemask & XpmReturnInfos) {
            attributes->hints_cmt = hints_cmt;
            attributes->colors_cmt = colors_cmt;
            attributes->pixels_cmt = pixels_cmt;
        }
        if (hotspot) {
            attributes->x_hotspot = x_hotspot;
            attributes->y_hotspot = y_hotspot;
            attributes->valuemask |= XpmHotspot;
        }
    }
    return (XpmSuccess);
}
