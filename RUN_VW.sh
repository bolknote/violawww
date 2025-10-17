#!/bin/bash
# Автоопределение DISPLAY для XQuartz
if [ -z "$DISPLAY" ]; then
    DISPLAY=$(ls /private/tmp/com.apple.launchd.*/org.xquartz:0 2>/dev/null | head -1)
    if [ -z "$DISPLAY" ]; then
        DISPLAY=:0
    fi
fi
export DISPLAY
echo "Using DISPLAY=$DISPLAY"
cd /Users/bolk/Projects/violawww
exec src/vw/vw
