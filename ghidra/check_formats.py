import glob
import re

# Find printf-family calls with literal format strings, count specifiers vs args.
# Flags: %% is literal. %d %s %x %u %c %f %ld %zu %04d etc.
SPEC = re.compile(r"%(?:[-+ 0#]*\d*(?:\.\d+)?[hlLjzt]*[diouxXeEfFgGaAcspn%])")


def count_specs(fmt):
    n = 0
    i = 0
    while i < len(fmt):
        if fmt[i] != "%":
            i += 1
            continue
        if i + 1 < len(fmt) and fmt[i + 1] == "%":
            i += 2
            continue
        # consume until a conversion char
        m = re.match(r"%[-+ 0#]*\d*(?:\.\d+)?[hlLjzt]*[diouxXeEfFgGaAcspn]", fmt[i:])
        if m:
            n += 1
            i += len(m.group(0))
        else:
            i += 1
    return n


def find_args_after(tokens, idx):
    # from position after the format string token, count comma-separated top-level args
    depth = 0
    args = []
    cur = ""
    for t in tokens[idx:]:
        for ch in t:
            if ch in "([":
                depth += 1
            elif ch in ")]":
                depth -= 1
            if ch == "," and depth == 0:
                args.append(cur.strip())
                cur = ""
            else:
                cur += ch
    if cur.strip():
        args.append(cur.strip())
    return args


for f in sorted(glob.glob("/tmp/opencode/recomp/*.c")):
    src = open(f).read()
    # strip comments
    code = re.sub(r"/\*.*?\*/", " ", src, flags=re.S)
    code = re.sub(r"//[^\n]*", " ", code)
    for m in re.finditer(r"(_?printf|_?fprintf|_?sprintf|_?snprintf)\s*\(([^;]*?)\)", code, flags=re.S):
        fn = m.group(1)
        inner = m.group(2)
        # find the format string literal
        fm = re.search(r'"((?:[^"\\]|\\.)*)"', inner)
        if not fm:
            continue
        fmt = fm.group(1)
        nspec = count_specs(fmt)
        if nspec == 0:
            continue
        # count args after the format literal (top-level commas)
        rest = inner[fm.end():]
        depth = 0
        nargs = 0
        for ch in rest:
            if ch in "([":
                depth += 1
            elif ch in ")]":
                depth -= 1
            elif ch == "," and depth == 0:
                nargs += 1
        if nargs < nspec:
            print("%s: %s: fmt=%r needs %d, has %d args" % (f.split('/')[-1], fn, fmt, nspec, nargs))
