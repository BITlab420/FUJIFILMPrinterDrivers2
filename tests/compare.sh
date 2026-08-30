#!/bin/bash
# Normalize + diff two .prn outputs. Masks the per-run timestamps in
# PRINTLOG ITEM = 2 lines, then byte-compares.
# Usage: compare.sh ref.prn port.prn
set -e
R="${1:-ref.prn}"
P="${2:-port.prn}"

normalize() {
  # replace the date part "Sun,30 Aug 2026 9:2:16" with <DATE>
  sed -E 's@(PRINTLOG ITEM = 2,)[A-Za-z]{3},[0-9]+ [A-Za-z]{3} [0-9]+ [0-9:]+@\1<DATE>@' "$1"
}

echo "== sizes =="
wc -c "$R" "$P"

echo "== first diff (normalized) =="
if diff <(normalize "$R") <(normalize "$P") > /tmp/duipa.diff; then
  echo "IDENTICAL (except timestamps) -> RE is byte-correct"
else
  echo "DIFFERENT. First 20 differing byte offsets:"
  cmp -l <(normalize "$R") <(normalize "$P") 2>/dev/null | head -20 || true
  echo
  echo "Context around first difference:"
  python3 - "$R" "$P" <<'EOF'
import sys,re
def norm(f):
    d=open(f,'rb').read()
    return re.sub(rb'(PRINTLOG ITEM = 2,)[A-Za-z]{3},[0-9]+ [A-Za-z]{3} [0-9]+ [0-9:]+', b'\\1<DATE>', d)
a,b=norm(sys.argv[1]),norm(sys.argv[2])
i=0
while i<min(len(a),len(b)) and a[i]==b[i]: i+=1
print("first diff at byte", i)
print("ref :", a[max(0,i-20):i+40])
print("port:", b[max(0,i-20):i+40])
EOF
fi
