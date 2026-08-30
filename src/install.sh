#!/bin/bash
# Install the recompiled rastertodpp268 as a CUPS filter.
# Run as root. Adjust the CUPS_MODEL_DIR if your distro differs.
set -e

FILTER_SRC="$(dirname "$0")/rastertodpp268"
PPD_SRC="${1:-/home/everything411/raster}"   # dir containing the FUJIFILM *.ppd.gz files

CUPS_FILTER_DIR=/usr/lib/cups/filter
CUPS_MODEL_DIR=/usr/share/cups/model
LUT_DIR=/usr/share/cups/driver/FUJIFILM/rastertodpp268/LUT

echo "== 1. Install filter binary =="
install -m 755 "$FILTER_SRC" "$CUPS_FILTER_DIR/rastertodpp268"

echo "== 2. Install LUT (halftone) tables =="
mkdir -p "$LUT_DIR"
cp "$PPD_SRC"/*.bin "$LUT_DIR/"

echo "== 3. Install PPDs (cupsFilter path rewritten for Linux) =="
mkdir -p "$CUPS_MODEL_DIR/FUJIFILM"
for gz in "$PPD_SRC"/*.gz; do
    name="$(basename "$gz" .gz)"
    gzip -dc "$gz" \
      | sed 's#/Library/Printers/FUJIFILM/Filter/rastertodpp268.bundle/Contents/MacOS/rastertodpp268#/usr/lib/cups/filter/rastertodpp268#g; s#/Library/Printers/FUJIFILM/Filter/commandtofilter2.bundle/Contents/MacOS/commandtofilter2#/usr/lib/cups/filter/commandtofilter2#g' \
      > "$CUPS_MODEL_DIR/FUJIFILM/$name"
    echo "   installed $name"
done

echo
echo "== Done. Add the printer with: =="
echo "   sudo lpadmin -p DocuPrint -m 'FUJIFILM/FUJIFILM Q505p for DocuPrint P268 dw CUPS' -v <device-uri> -E"
echo "   (device-uri: usb://FUJIFILM/... or socket://<printer-ip>:9100)"

echo "== 4. Install commandtofilter2 stub =="
install -m 755 "$(dirname "$0")/commandtofilter2" "$CUPS_FILTER_DIR/commandtofilter2" 2>/dev/null || true
