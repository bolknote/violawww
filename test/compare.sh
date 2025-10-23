#!/bin/bash
# Compare transliteration methods side-by-side

if [ -z "$1" ]; then
    echo "Usage: $0 <file.txt>"
    echo "       cat file.txt | $0 -"
    exit 1
fi

if [ "$1" = "-" ]; then
    ./compare_translit -f | column -t -s $'\t'
else
    ./compare_translit -f < "$1" | column -t -s $'\t'
fi

