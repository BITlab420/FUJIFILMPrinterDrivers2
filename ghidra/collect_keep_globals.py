import pyghidra

PROJ_LOC = "/tmp/opencode/ghidra-proj"
PROJ_NAME = "proj"


def run(program_name):
    with pyghidra.open_program(
        binary_path="/tmp/opencode/%s" % program_name,
        project_location=PROJ_LOC,
        project_name=PROJ_NAME,
        program_name=program_name,
    ) as flat_api:
        prog = flat_api.getCurrentProgram()
        fm = prog.getFunctionManager()
        listing = prog.getListing()
        sym = prog.getSymbolTable()

        funcs = {}
        it = fm.getFunctions(True)
        while it.hasNext():
            f = it.next()
            funcs[f.getName()] = f

        ext_names = set()
        for s in sym.getAllSymbols(True):
            if s.isExternal():
                ext_names.add(s.getName())

        callees = {}
        globals_used = {}
        for fn, f in funcs.items():
            callees[fn] = set()
            globals_used[fn] = set()
            ait = listing.getInstructions(f.getBody(), True)
            while ait.hasNext():
                ins = ait.next()
                for r in ins.getReferencesFrom():
                    sf = fm.getFunctionAt(r.getToAddress())
                    if sf is not None:
                        callees[fn].add(sf.getName())
                    else:
                        gs = sym.getSymbols(r.getToAddress())
                        for g in gs:
                            if not g.isExternal():
                                globals_used[fn].add(g.getName())

        cache = {}

        def reach(fn, depth=0):
            if fn in cache:
                return cache[fn]
            if depth > 100:
                return set()
            res = set()
            for c in callees.get(fn, ()):
                if c in ext_names:
                    res.add(c)
                else:
                    res |= reach(c, depth + 1)
            cache[fn] = res
            return res

        CF = set()
        for fn, f in funcs.items():
            bad = [x for x in reach(fn) if x.startswith("_CF") or x.startswith("_FS") or x.startswith("_FSPath") or x == "dyld_stub_binder"]
            if bad:
                CF.add(fn)

        keep = [fn for fn in funcs if fn not in CF]
        print("keep count: %d (of %d)" % (len(keep), len(funcs)))
        keep.sort()
        print("STUB set (%d): %s" % (len(CF), " ".join(sorted(CF))))

        g = set()
        for fn in keep:
            g |= globals_used.get(fn, ())
        g = sorted(g)
        print("\nGLOBALS USED BY KEEP SET (%d):" % len(g))
        for x in g:
            print(x)

        with open("/tmp/opencode/keep_globals.txt", "w") as fh:
            fh.write("\n".join(g))
        with open("/tmp/opencode/keep_funcs.txt", "w") as fh:
            fh.write("\n".join(keep))
        with open("/tmp/opencode/stub_funcs.txt", "w") as fh:
            fh.write("\n".join(sorted(CF)))


run("rastertodpp268")
