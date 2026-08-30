#!/bin/bash
# Build rastertodpp268 Linux port (black-box recompilation of the macOS Mach-O filter)
# Requires: gcc, libcups, libcupsimage (headers in /usr/include/cups)
set -e
cd "$(dirname "$0")"

# 1. (Optional) Regenerate globals from scratch. The checked-in globals.h/c already
#    contain hand-fixed definitions (paper_sort_area, cf_ constants, etc.);
#    regeneration will lose those fixes unless gen_globals.py is updated.
# python3 gen_globals.py

# 2. Concatenate: shim + globals + all decompiled functions + main into one translation unit
python3 build.py

# 3. Compile + link
gcc -c -O2 -I. -w \
    -Wno-error=incompatible-pointer-types \
    -Wno-error=int-conversion \
    -Wno-error=implicit-function-declaration \
    -Wno-error=pointer-sign \
    -Wno-error=return-type \
    all.c -o rastertodpp268.o

gcc rastertodpp268.o -lcups -lcupsimage -o rastertodpp268

gcc -O2 -o commandtofilter2 commandtofilter2_stub.c 2>/dev/null || true

echo "Built: $(pwd)/rastertodpp268 (and commandtofilter2 stub)"
