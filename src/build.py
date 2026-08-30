import glob
import re
import subprocess
import sys

RECDIR = "decomp"
OUT = "all.c"

# 1. identify thunk files (import wrappers)
thunks = set()
for f in glob.glob(RECDIR + "/*.c"):
    src = open(f).read()
    if "(* (code *)PTR_" in src or "(* (code *)PTR_" in src or "PTR__" in src and ("(*(code *)PTR_" in src):
        thunks.add(f)
# also files whose only content is a PTR call
for f in glob.glob(RECDIR + "/*.c"):
    src = open(f).read()
    if "(*(code *)PTR_" in src:
        thunks.add(f)
    elif "code * )PTR_" in src or "(code *)PTR_" in src:
        thunks.add(f)

real = [f for f in glob.glob(RECDIR + "/*.c") if f not in thunks and f.split("/")[-1] not in ("globals.c", "main.c", "_main.c", "entry.c", "start.c")]
print("real files:", len(real), "thunks:", len(thunks))

# 2. extract real signatures
def clean(sig):
    sig = re.sub(r"/\*.*?\*/", "", sig, flags=re.S)
    sig = re.sub(r"//[^\n]*", "", sig)
    sig = re.sub(r"\s+", " ", sig).strip()
    return sig

protos = {}
for f in real:
    src = open(f).read()
    m = re.match(r"// (\S+)", src)
    if not m:
        continue
    name = m.group(1)
    idx = -1
    # find the definition, skipping comment lines
    for m in re.finditer(re.escape(name) + r"\s*\(", src):
        line_start = src.rfind("\n", 0, m.start()) + 1
        line_head = src[line_start:m.start()]
        if "//" in line_head or "/*" in line_head:
            continue
        idx = m.start()
        break
    if idx < 0:
        continue
    # forward to closing paren depth 0
    j = idx
    depth = 0
    while j < len(src):
        c = src[j]
        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
            if depth == 0:
                j += 1
                break
        j += 1
    # backtrack to return type: last boundary before name
    head = src[:idx]
    lines = head.split("\n")
    li = len(lines) - 1
    while li > 0:
        t = lines[li].strip()
        if t == "" or t.startswith("//") or t.startswith("/*") or t.startswith("*") or t.endswith(",") or t.endswith("(") or "entry=" in t:
            li -= 1
            continue
        break
    sig = src[sum(len(x) + 1 for x in lines[:li]):j] if li > 0 else src[:j]
    sig = clean(sig)
    if sig and sig.endswith(")"):
        protos[name] = sig

# special: also extract from known files that failed pattern (fallback to 2nd line)
print("protos extracted:", len(protos))

# build concatenation
parts = []
parts.append("#include \"shim.h\"\n")
parts.append("#include \"globals.h\"\n")
# forward declarations
parts.append("/* forward declarations */\n")
for name in sorted(protos):
    parts.append(protos[name] + ";\n")
parts.append("\n")
for f in sorted(real):
    if f.endswith("_main.c"):
        parts.append("/* %s */\n" % f)
        parts.append(open(f).read())
        parts.append("\n")

# main entry replaced by our own; exclude original _main, entry, start
parts2 = []
for f in sorted(real):
    base = f.split("/")[-1]
    if base in ("_main.c", "entry.c", "entry.c"):
        continue
    parts2.append("/* %s */\n" % f)
    parts2.append(open(f).read())
    parts2.append("\n")

mainc = open(RECDIR + "/main.c").read()
full = "".join(parts) + "".join(parts2) + "/* main */\n" + mainc + "\n/* globals */\n" + open(RECDIR + "/globals.c").read()

open(OUT, "w").write(full)
print("wrote", OUT, len(full), "bytes")
