#!/bin/bash
# 对拍 (byte-comparison) harness: run the SAME raster through two drivers and diff.
#
#   Linux side : ./run_duipa.sh            -> produces port.prn via ./rastertodpp268
#   macOS side : run with DUPIA_MAC=1      -> produces ref.prn via the ORIGINAL
#                                             x86_64 binary (Rosetta 2)
#
# Both sides must use the SAME raster file and PPD. Compare the two .prn
# files after masking timestamps (they change every run).
set -e
cd "$(dirname "$0")"

PPD="${PPD:-fujifilm_p268.ppd}"
RASTER="${RASTER:-ras_half.raster}"
LUT="${BR_LUT_PATH:-/tmp/opencode/LUT}"

JOB=0; USER=duipa; TITLE=test

if [ "$DUPIA_MAC" = "1" ]; then
  # --- macOS side: run the ORIGINAL x86_64 binary (built for macOS) ---
  ORIG="${ORIG:-./rastertodpp268.orig}"     # original Mach-O binary copied to this dir
  mkdir -p /Library/Printers/FUJIFILM/rastertodpp268/LUT 2>/dev/null || true
  PPD="$PPD" "$ORIG" "$JOB" "$USER" "$TITLE" 1 "" "$RASTER" > ref.prn 2>ref.err || true
  echo "macOS  side: ref.prn $(stat -c%s ref.prn 2>/dev/null || stat -f%z ref.prn) bytes"
else
  # --- Linux side: run the port ---
  PPD="$PPD" BR_LUT_PATH="$LUT" ../rastertodpp268 "$JOB" "$USER" "$TITLE" 1 "" "$RASTER" > port.prn 2>port.err || true
  echo "Linux  side: port.prn $(stat -c%s port.prn) bytes"
fi
