#!/bin/bash

set -e

cd /Users/bolk/Projects/violawww/src/vw

CFLAGS="-Os -arch arm64 -std=gnu89 -Wno-everything -I/opt/homebrew/include -I/opt/homebrew/Cellar/openmotif/2.3.8_3/include -I../viola -D__DARWIN__"

echo "=== Building ViolaWWW Browser (vw) ==="

for src in box.c callbacks.c catalog.c cursor.c dialog.c edit.c fileIO.c fonts.c history.c hotlist.c menu.c mail.c selection.c vw.c; do
    obj=${src%.c}.o
    echo "Compiling $src..."
    cc $CFLAGS -c $src -o $obj || exit 1
done

echo "=== Linking vw ==="

VIOLA_OBJS=$(ls ../viola/*.o | grep -v main.o | tr '\n' ' ')

cc -o vw -L/opt/homebrew/lib -L/opt/homebrew/Cellar/openmotif/2.3.8_3/lib -arch arm64 \
    box.o callbacks.o catalog.o cursor.o dialog.o edit.o fileIO.o fonts.o history.o hotlist.o mail.o menu.o selection.o vw.o \
    $VIOLA_OBJS \
    ../libWWW/Library/darwin/libwww.a \
    ../libXPM/libXpm.a \
    ../libXPA/src/libXpa.a \
    ../libIMG/libIMG.a \
    ../libStyle/libstg.o \
    -lXm -lXext -lXmu -lXt -lSM -lICE -lX11 -lm

echo "=== VW Built Successfully! ==="
ls -lh vw

