/*		Plain text object		HTWrite.c
**		=================
**
**	This version of the stream object just writes to a socket.
**	The socket is assumed open and left open.
**
**	Bugs:
**		strings written must be less than buffer size.
*/
#include "HTPlain.h"

#define BUFFER_SIZE 4096; /* Tradeoff */

#include "HTStyle.h"
#include "HTUtils.h"
#include "HText.h"
#include "HTAnchor.h"
#include <string.h>
#include <strings.h>
#include "HTCharset.h"

extern HTStyleSheet* styleSheet;

/*		HTML Object
**		-----------
*/

struct _HTStream {
    CONST HTStreamClass* isa;

    HText* text;
    HTParentAnchor* anchor; /* To access charset information */
};

/* Forward declaration */
PRIVATE void HTPlain_write ARGS3(HTStream*, me, CONST char*, s, int, l);

/*	Write the buffer out to the socket
**	----------------------------------
*/

/*_________________________________________________________________________
**
**			A C T I O N 	R O U T I N E S
*/

/*	Character handling
**	------------------
*/

PRIVATE void HTPlain_put_character ARGS2(HTStream*, me, char, c) {
    HText_appendCharacter(me->text, c);
}

/*	String handling
**	---------------
**
*/
PRIVATE void HTPlain_put_string ARGS2(HTStream*, me, CONST char*, s) {
    /* Use HTPlain_write for conversion */
    HTPlain_write(me, s, strlen(s));
}

PRIVATE void HTPlain_progress ARGS2(HTStream*, me, int, l) {}

PRIVATE void HTPlain_write ARGS3(HTStream*, me, CONST char*, s, int, l) {
    CONST char* p;
    CONST char* e = s + l;
    char outbuf[65536]; /* 8x buffer for encoding expansion + transliteration */
    int converted_len;
    int i;
    char* charset;
    
    /* Get charset from anchor */
    charset = me->anchor ? HTAnchor_charset(me->anchor) : NULL;
    
    if (l < sizeof(outbuf) / 8) {
        if (charset && strcasecmp(charset, "UTF-8") != 0 && strcasecmp(charset, "utf8") != 0) {
            /* Convert from specified encoding to ASCII */
            if (TRACE)
                fprintf(stderr, "HTPlain: Converting from charset '%s' to ASCII\n", charset);
            converted_len = HTCharset_convert_to_ascii(charset, s, l, outbuf, sizeof(outbuf));
            
            if (converted_len > 0) {
                /* Conversion succeeded */
                for (i = 0; i < converted_len; i++) {
                    HText_appendCharacter(me->text, outbuf[i]);
                }
                return;
            }
            /* If conversion failed, fall through to try UTF-8 path */
        }
        
        /* Try UTF-8 to ASCII conversion (also handles no-charset case) */
        if (l < sizeof(outbuf) / 2) {
            memcpy(outbuf, s, l);
            outbuf[l] = '\0';
            converted_len = HTCharset_utf8_to_ascii_buffer(outbuf, l);
            
            if (converted_len != l || memcmp(s, outbuf, l) != 0) {
                /* Conversion happened, use converted text */
                for (i = 0; i < converted_len; i++) {
                    HText_appendCharacter(me->text, outbuf[i]);
                }
                return;
            }
        }
    }
    
    /* Use original text */
    for (p = s; p < e; p++)
        HText_appendCharacter(me->text, *p);
}

/*	Free an HTML object
**	-------------------
**
**	Note that the SGML parsing context is freed, but the created object is not,
**	as it takes on an existence of its own unless explicitly freed.
*/
PRIVATE void HTPlain_free ARGS1(HTStream*, me) { free(me); }

PRIVATE void HTPlain_end ARGS1(HTStream*, me) {}

/*	End writing
 */

PRIVATE void HTPlain_abort ARGS2(HTStream*, me, HTError, e) { HTPlain_free(me); }

/*		Structured Object Class
**		-----------------------
*/
PUBLIC CONST HTStreamClass HTPlain = {
    "SocketWriter",        HTPlain_free,       HTPlain_end,      HTPlain_abort,
    HTPlain_put_character, HTPlain_put_string, HTPlain_progress, HTPlain_write,
};

/*		New object
**		----------
*/
PUBLIC HTStream* HTPlainPresent ARGS3(HTPresentation*, pres, HTParentAnchor*, anchor, HTStream*,
                                      sink) {

    HTStream* me = (HTStream*)malloc(sizeof(*me));
    if (me == NULL)
        outofmem(__FILE__, "HTPlain_new");
    me->isa = &HTPlain;
    me->anchor = anchor;

    me->text = HText_new(anchor);
    HText_setStyle(me->text, HTStyleNamed(styleSheet, "Example"));
    HText_beginAppend(me->text);

    return (HTStream*)me;
}
