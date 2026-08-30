import pyghidra

PROJ_LOC = "/tmp/opencode/ghidra-proj"
PROJ_NAME = "proj"


def classify(program_name):
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

        reach_cache = {}

        def reach(fn, depth=0):
            if fn in reach_cache:
                return reach_cache[fn]
            if depth > 100:
                return set()
            res = set()
            for c in callees.get(fn, ()):
                if c in ext_names:
                    res.add(c)
                else:
                    res |= reach(c, depth + 1)
            reach_cache[fn] = res
            return res

        print("=== %s ===" % program_name)
        print("total funcs: %d, total external symbols imported: %d" % (len(funcs), len(ext_names)))

        print("\n-- [STUB] functions reaching CF/Carbon --")
        for fn in sorted(funcs):
            bad = [x for x in reach(fn) if x.startswith("_CF") or x.startswith("_FS") or x.startswith("_FSPath") or x == "dyld_stub_binder"]
            if bad:
                print("%-45s %s" % (fn, sorted(bad)))

        print("\n-- [PURE] functions (no external reach) --")
        pure = [fn for fn in sorted(funcs) if not reach(fn)]
        print("%d pure: %s" % (len(pure), " ".join(pure)))

        print("\n-- globals used by PURE functions --")
        pg = set()
        for fn in pure:
            pg |= globals_used.get(fn, ())
        for g in sorted(pg):
            print(g)

        print("\n-- [CUPS/LIBC] external symbols reachable from _main --")
        r = sorted(reach("_main"))
        for x in r:
            print(x)
        print("count=%d" % len(r))


classify("rastertodpp268")
