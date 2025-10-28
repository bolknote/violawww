/* Minimal support to satisfy biop.c dependency on PkInfo2Str without pulling misc.o */
#include "../src/viola/packet.h"
#include <stdio.h>

extern char buff[]; /* from mystrings.c */

char* PkInfo2Str(Packet* pk)
{
    switch (pk->type) {
    case PKT_STR:
        return pk->info.s;
    case PKT_CHR:
        sprintf(buff, "%c", pk->info.c);
        break;
    case PKT_INT:
        sprintf(buff, "%ld", pk->info.i);
        break;
    case PKT_FLT:
        sprintf(buff, "%f", pk->info.f);
        break;
    default:
        buff[0] = '\0';
        break;
    }
    return buff;
}


