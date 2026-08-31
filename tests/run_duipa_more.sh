#!/bin/bash
# 对拍 edge-case harness: multi-print, multi-page duplex, media/res/options.
# Runs the SAME raster + options through the port and the ORIGINAL macOS
# binary (Rosetta 2), masks per-run timestamps, and byte-compares.
#
# Usage: tests/run_duipa_more.sh
# Requires: tools/mkgen (built), and the original binary at
#           $ORIG (default ../bin/rastertodpp268 works under Rosetta 2).
set -e
cd "$(dirname "$0")"
HERE="$(pwd)"

PORT="${PORT:-$HERE/../src/rastertodpp268}"
ORIG="${ORIG:-$HERE/../bin/rastertodpp268}"
PPD="${PPD:-$HERE/fujifilm_p268.ppd}"
case "$PPD" in /*) ;; *) PPD="$HERE/$PPD" ;; esac
LUT="${BR_LUT_PATH:-$HERE/../LUT}"
MKGEN="${MKGEN:-$HERE/../tools/mkgen}"
TMP="${TMPDIR:-/tmp}/duipa_more"
mkdir -p "$TMP"
export PPD

# build generator if missing
if [ ! -x "$MKGEN" ]; then
  (cd "$HERE/../tools" && cc -O2 -o mkgen mkgen.c -lcups -lcupsimage)
fi

G="$MKGEN"
cd "$TMP"
"$G" mp_copies3.raster 3 200 200 1 300 0 0 3 Letter
"$G" dup_long4.raster  4 200 200 1 300 1 0 1 Letter
"$G" dup_tumble4.raster 4 200 200 1 300 1 1 1 Letter
"$G" dup_odd3.raster   3 200 200 1 300 1 0 1 Letter
"$G" dup_single1.raster 1 200 200 1 300 1 0 1 Letter
"$G" dup8_4.raster     4 200 200 8 300 1 0 1 Letter
"$G" dup_5pages.raster 5 200 200 1 300 1 0 1 Letter
"$G" dup_even2.raster  2 200 200 1 300 1 0 1 Letter
"$G" dup_copies.raster 4 200 200 1 300 1 0 2 Letter
"$G" blank_pages.raster 3 200 200 1 300 0 0 1 Letter
"$G" tiny_page.raster  1 8 8 1 300 0 0 1 Letter
"$G" wide_page.raster  1 3000 100 1 300 0 0 1 Letter
"$G" tall_page.raster  1 100 3000 1 300 0 0 1 Letter
"$G" legal_dup.raster  4 200 300 1 300 1 0 1 Legal
"$G" a5_3.raster       3 148 210 1 300 0 0 1 A5
"$G" env10.raster      2 104 241 1 300 0 0 1 Env10
"$G" bpp8_res600.raster 2 400 400 8 600 0 0 1 Letter
"$G" bpp8_res1200.raster 1 800 800 8 1200 0 0 1 Letter
"$G" odd_w.raster      2 127 200 1 300 0 0 1 Letter
"$G" odd_h.raster      2 200 127 1 300 0 0 1 Letter
"$G" prime_page.raster 3 131 149 1 300 1 0 1 Letter
"$G" copies9.raster    2 200 200 1 300 0 0 9 Letter
"$G" one_dup.raster    1 200 200 1 300 1 0 5 Letter

# option-string cases on the canonical rasters
for f in ras_half.raster ras_ff.raster; do
  [ -f "$f" ] || cp -f "$HERE/$f" .
done

PASS=0; FAIL=0
run() { # label raster [options...]
  local label="$1" ras="$2"; shift 2
  BR_LUT_PATH="$LUT" "$PORT" 0 duipa test 1 "$@" "$ras" > "$label.port" 2>/dev/null || true
  "$ORIG" 0 duipa test 1 "$@" "$ras" > "$label.ref" 2>/dev/null || true
  python3 - "$label" <<'PY'
import re,sys
def norm(b):
    b=re.sub(rb'(PRINTLOG ITEM = 2,)[A-Za-z]{3},[0-9]+ [A-Za-z]{3} [0-9]+ [0-9:]+',b'\\1<DATE>',b)
    b=re.sub(rb'@PJL SET JOBTIME = "[0-9]{14}"',b'@PJL SET JOBTIME = "<TIME>"',b)
    return b
f=sys.argv[1]
r=norm(open(f+'.ref','rb').read()); p=norm(open(f+'.port','rb').read())
if r==p:
    print(f'{f}: IDENTICAL ({len(r)} bytes)'); sys.exit(0)
i=next((i for i in range(min(len(r),len(p))) if r[i]!=p[i]), min(len(r),len(p)))
print(f'{f}: DIFF (ref={len(r)} port={len(p)}) @ {i}')
print('  ref :', r[max(0,i-30):i+30]); print('  port:', p[max(0,i-30):i+30])
sys.exit(1)
PY
}

for f in *.raster; do
  case "$f" in ras_*.raster) continue;; esac
  if run "case_$f" "$f" ""; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
done
if run opts_toner     ras_half.raster "TonerSaveMode=ON"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
if run opts_res600    ras_half.raster "BRResolution=600dpi"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
if run opts_res1200   ras_half.raster "BRResolution=2400x600dpi"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
if run opts_dup_long  ras_half.raster "Duplex=DuplexNoTumble"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
if run opts_dup_short ras_half.raster "Duplex=DuplexTumble"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
if run opts_media     env10.raster     "BRMediaType=Envelopes"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
if run opts_skipblank blank_pages.raster "BRSkipBlank=ON"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
if run opts_collate   ras_half.raster  "Collate=True"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi
if run opts_econ      ras_half.raster  "TonerSaveMode=ON"; then PASS=$((PASS+1)); else FAIL=$((FAIL+1)); fi

echo "PASS=$PASS FAIL=$FAIL"
[ "$FAIL" = "0" ]
