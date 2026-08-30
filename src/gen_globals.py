import json
import re
import struct

IMG = open("data/img.bin", "rb").read()
BASE = 0x10000ed10
JSON = json.load(open("data/rastertodpp268.json"))

# symbol addr -> {name, size, dtype}
sym_by_addr = {}
for s in JSON["symbols"]:
    a = int(s["addr"], 16)
    if 0x10000ed10 <= a < 0x1000175c0:
        sym_by_addr.setdefault(a, s)

def bytes_at(addr, n):
    return IMG[addr - BASE: addr - BASE + n]

# ---- real arrays (used with & or as base): name -> size ----
ARRAYS = {
    "_matrix300_Graphics": 1024, "_matrix300_Text": 1024,
    "_matrix600_Graphics": 1024, "_matrix600_Text": 1024,
    "_matrixHQ1200_Graphics": 1024, "_matrixHQ1200_Text": 1024,
    "_white_table": 512, "_white_tablee": 512,
    "_black_table": 512, "_black_tablee": 512,
    "_tblRoman8": 0, "_tblISO88592": 0, "_tblISO88595": 0,
    "_paperName": 0, "_paperArray": 0,
    "_lutfolderpath": 1024, "_lutModelfolderpath": 1024,
    "_gLowLevel": 0,
}
# resolve unknown sizes from next-symbol gap or known addresses
known_gaps = {
    "_tblRoman8": (0x1000125f0, 0x100012650),      # 96
    "_tblISO88592": (0x100012650, 0x1000126d0),    # 128
    "_tblISO88595": (0x1000126d0, 0x100012750),    # 128
    "_paperName": (0x100013f50, 0x100014400),      # 1200
    "_paperArray": (0x1000150f0, 0x1000161f0),     # 4352
    "_gLowLevel": (0x100015070, 0x100015084),      # 20
}
for k, (s, e) in known_gaps.items():
    ARRAYS[k] = e - s

# ---- scalars: name -> (size, ctype) ----
SCALARS = {
    "_send_buf": 8, "_compData": 8, "_Planes": 8, "_pMatrixRow": 8, "_fun_table": 8,
    "_thisPPD": 8, "_options": 8, "_blankPagePtr": 8, "_oddPagePtr": 8, "_evenPagePtr": 8,
    "_gLoginUserName": 8, "_gLogJobName": 8, "_gStatus": 8, "_lFAXDataCnt": 8,
    "_lMatrixRow": 4, "_margins": 2, "_lCount": 2, "_model_language": 4, "_gModelInfo": 4,
    "_num_options": 4, "_gOnePageByte": 2, "_gloopCnt": 4, "_gGetStatusMode": 4,
    "_gEncodingNum": 4, "_model_index": 1,
    # DAT_ scalars (print core)
    "DAT_100016a54": 4, "DAT_100016a70": 4, "DAT_100016a78": 4, "DAT_100016a80": 4,
    "DAT_100016a88": 4, "DAT_100016a98": 4, "DAT_100016aa8": 4, "DAT_100016ab8": 4,
    "DAT_100016f38": 4, "DAT_100016f30": 4, "DAT_100015084": 4, "DAT_1000145f8": 4,
    "DAT_100014744": 4, "DAT_100014938": 4, "DAT_100013f62": 2, "DAT_100016a52": 2,
    "DAT_100016b00": 4, "DAT_100016b08": 4, "DAT_100016b10": 4, "DAT_100016b18": 4,
    "DAT_100016b20": 4, "DAT_100016b30": 4,
    "DAT_100016200": 8, "DAT_100016208": 8, "DAT_100016210": 8, "DAT_100016218": 8,
    "DAT_100016220": 8,
    "DAT_1000104b8": 4, "DAT_1000104c8": 4, "DAT_1000104d0": 4, "DAT_1000104d8": 4,
    "DAT_1000104e0": 4, "DAT_1000104e8": 4, "DAT_1000104f0": 4,
    "DAT_1000150f4": 4, "DAT_100015130": 2, "DAT_100015132": 2, "DAT_100015134": 2,
    "DAT_100015138": 2, "DAT_100015174": 2, "DAT_100015176": 2, "DAT_1000151b8": 2,
    "DAT_1000151ba": 2, "DAT_1000151fc": 2, "DAT_1000151fe": 2,
}
# DAT_ pointers (void*)
DAT_PTRS = ["DAT_100016aa0", "DAT_100016ab0", "DAT_100016ac0"]

# locate address for each scalar by name
def find_addr(name):
    for s in JSON["symbols"]:
        if s["name"] == name:
            return int(s["addr"], 16)
    return None

# additional globals not in symbol table but referenced (define as zero)
EXTRA_SCALARS = {
    "__margins": 8, "__gOnePageByte": 2, "__lCount": 2, "__gGetStatusMode": 4, "__gEncodingNum": 4,
    "DAT_100016a50": 2, "DAT_100016a60": 8, "DAT_100016a90": 8,
}

def ctype_for(size, name, is_ptr):
    if is_ptr:
        return "void *"
    if size == 8: return "uint64_t"
    if size == 4: return "int"
    if size == 2: return "short"
    if size == 1: return "unsigned char"
    return "unsigned char"

lines_h = []
lines_c = []

lines_c.append("/* auto-generated globals for rastertodpp268 (Linux port) */")
lines_c.append('#include <stdint.h>')
lines_c.append('')
lines_c.append('unsigned char _img[%d] = {' % len(IMG))
# emit img as hex
for i in range(0, len(IMG), 12):
    chunk = IMG[i:i+12]
    lines_c.append("    " + ", ".join("0x%02x" % b for b in chunk) + ",")
lines_c.append('};')
lines_c.append('')
lines_h.append('#ifndef GLOBALS_H')
lines_h.append('#define GLOBALS_H')
lines_h.append('#include <stdint.h>')
lines_h.append('extern unsigned char _img[%d];' % len(IMG))
lines_h.append('')

# real arrays
for name, size in ARRAYS.items():
    addr = find_addr(name)
    if addr is None:
        print("WARN: no addr for array", name)
        continue
    data = bytes_at(addr, size)
    arr_type = "unsigned char"
    lines_h.append('extern %s %s[%d];' % (arr_type, name, size))
    lines_c.append('%s %s[%d] = {' % (arr_type, name, size))
    for i in range(0, size, 12):
        chunk = data[i:i+12]
        lines_c.append("    " + ", ".join("0x%02x" % b for b in chunk) + ",")
    lines_c.append('};')
    lines_c.append('')

# scalars
for name, size in SCALARS.items():
    addr = find_addr(name)
    init = 0
    if addr is not None:
        init = int.from_bytes(bytes_at(addr, min(size, 8)), "little")
    if name in ("DAT_100016200", "DAT_100016208", "DAT_100016210", "DAT_100016218", "DAT_100016220"):
        ct = "void *"
    else:
        ct = ctype_for(size, name, False)
    lines_h.append('extern %s %s;' % (ct, name))
    lines_c.append('%s %s = %d;' % (ct, name, init if ct != "void *" else 0))
lines_c.append('')

# DAT_ pointers
for name in DAT_PTRS:
    addr = find_addr(name)
    init = 0
    if addr is not None:
        init = int.from_bytes(bytes_at(addr, 8), "little")
    lines_h.append('extern void *%s;' % name)
    lines_c.append('void *%s = (void *)0x%x;' % (name, init))
lines_c.append('')

# extra scalars (zero-init)
for name, size in EXTRA_SCALARS.items():
    ct = ctype_for(size, name, False)
    lines_h.append('extern %s %s;' % (ct, name))
    lines_c.append('%s %s = 0;' % (ct, name))
lines_c.append('')

# day/month name arrays
lines_h.append('extern char *PTR_s_Sun_100012320[7];')
lines_h.append('extern char *PTR_s_Jan_100012360[12];')
days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
mons = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
lines_c.append('char *PTR_s_Sun_100012320[7] = { "%s" };' % '", "'.join(days))
lines_c.append('char *PTR_s_Jan_100012360[12] = { "%s" };' % '", "'.join(mons))
lines_c.append('')

# single-byte string ref used by MSendBandData
lines_h.append('#define s__10000f7d6 (_img + 0x%x)' % (0x10000f7d6 - BASE))
lines_c.append('')

# ---- comprehensive img macros for remaining referenced data symbols ----
import glob as _glob

# already-defined names (arrays + scalars)
defined = set()
defined.update(ARRAYS.keys())
defined.update(SCALARS.keys())
defined.update(DAT_PTRS)
defined.update(EXTRA_SCALARS.keys())
defined.update(["PTR_s_Sun_100012320", "PTR_s_Jan_100012360", "s__10000f7d6"])

real_c = [f for f in _glob.glob("decomp/*.c")]
refs = set()
for f in real_c:
    src = open(f).read()
    for m in re.finditer(r"\b((?:DAT_[0-9a-fA-F]+)|(?:PTR_[A-Za-z0-9_]+)|(?:_[a-z][A-Za-z0-9_]*))\b", src):
        refs.add(m.group(1))

skip = set()
for f in real_c:
    src = open(f).read()
    for m in re.finditer(r"// (\S+)", src):
        skip.add(m.group(1))

by_name = {}
for s in JSON["symbols"]:
    a = int(s["addr"], 16)
    if 0x10000ed10 <= a < 0x1000175c0:
        by_name.setdefault(s["name"], s)

extra = []
for n in sorted(refs):
    if n in defined or n in skip:
        continue
    if n.startswith("DAT_"):
        a = int(n[4:], 16)
        size = 4
    elif n in by_name:
        a = int(by_name[n]["addr"], 16)
        size = by_name[n]["size"] or 8
    else:
        continue
    if not (0x10000ed10 <= a < 0x1000175c0):
        continue
    off = a - BASE
    if size == 8:
        extra.append("#define %s (*(uint64_t *)(_img + 0x%x))" % (n, off))
    elif size == 4:
        extra.append("#define %s (*(int *)(_img + 0x%x))" % (n, off))
    elif size == 2:
        extra.append("#define %s (*(short *)(_img + 0x%x))" % (n, off))
    else:
        extra.append("#define %s (*(unsigned char *)(_img + 0x%x))" % (n, off))

lines_h.append('/* img-based macros for referenced data symbols */')
lines_h.extend(extra)

lines_h.append('#endif')

open("decomp/globals.h", "w").write("\n".join(lines_h) + "\n")
open("decomp/globals.c", "w").write("\n".join(lines_c) + "\n")
print("generated globals.h (%d lines) globals.c (%d lines), %d img macros" % (len(lines_h), len(lines_c), len(extra)))
