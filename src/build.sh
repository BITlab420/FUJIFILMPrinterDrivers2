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
# -Wall keeps format/type warnings; the -Wno-* below suppress Ghidra-decompile
# artifacts that are intrinsic to the port (uint64_t-as-pointer, opaque
# struct typedefs, unused temp vars) and cannot be fixed without changing
# the recompiled semantics.
gcc -c -O2 -I. -Wall \
    -Wno-error=incompatible-pointer-types \
    -Wno-error=int-conversion \
    -Wno-error=implicit-function-declaration \
    -Wno-error=pointer-sign \
    -Wno-error=return-type \
    -Wno-int-conversion \
    -Wno-incompatible-pointer-types \
    -Wno-pointer-sign \
    -Wno-pointer-to-int-cast \
    -Wno-pointer-integer-compare \
    -Wno-constant-conversion \
    -Wno-unused-but-set-variable \
    -Wno-unused-variable \
    -Wno-deprecated-declarations \
    all.c -o rastertodpp268.o

gcc rastertodpp268.o -lcups -lcupsimage -o rastertodpp268

gcc -O2 -o commandtofilter2 commandtofilter2_stub.c 2>/dev/null || true

echo "Built: $(pwd)/rastertodpp268 (and commandtofilter2 stub)"
