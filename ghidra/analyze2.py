import os

import pyghidra

OUTDIR = "/tmp/opencode/ghidra-out"
PROJ_LOC = "/tmp/opencode/ghidra-proj"
PROJ_NAME = "proj"


def analyze(program_name):
    with pyghidra.open_program(
        binary_path="/tmp/opencode/%s" % program_name,
        project_location=PROJ_LOC,
        project_name=PROJ_NAME,
        program_name=program_name,
    ) as flat_api:
        from ghidra.app.decompiler import DecompInterface
        from ghidra.util.task import ConsoleTaskMonitor

        prog = flat_api.getCurrentProgram()
        listing = prog.getListing()
        fm = prog.getFunctionManager()
        sym = prog.getSymbolTable()

        decomp = DecompInterface()
        decomp.openProgram(prog)
        monitor = ConsoleTaskMonitor()

        extfuncs = {}
        for s in sym.getAllSymbols(True):
            try:
                if s.isExternal():
                    extfuncs[s.getName()] = 0
            except Exception:
                pass

        func_dir = os.path.join(OUTDIR, program_name)
        os.makedirs(func_dir, exist_ok=True)

        funcs = []
        it = fm.getFunctions(True)
        while it.hasNext():
            funcs.append(it.next())

        report = []
        for f in funcs:
            fn = f.getName()
            called_ext = set()
            body = f.getBody()
            ait = listing.getInstructions(body, True)
            while ait.hasNext():
                ins = ait.next()
                if ins.getFlowType().isCall():
                    for r in ins.getReferencesFrom():
                        sf = fm.getFunctionAt(r.getToAddress())
                        if sf is not None and sf.isExternal():
                            extfuncs[sf.getName()] = extfuncs.get(sf.getName(), 0) + 1
                            called_ext.add(sf.getName())
            code = ""
            try:
                res = decomp.decompileFunction(f, 120, monitor)
                if res is not None and res.decompileCompleted():
                    code = res.getDecompiledFunction().getC()
            except Exception as e:
                code = "// decompile error: %s" % e
            safe = fn.replace("/", "_").replace("\\", "_").replace(" ", "_")
            with open(os.path.join(func_dir, safe + ".c"), "w") as fh:
                fh.write("// %s  entry=%s\n" % (fn, f.getEntryPoint()))
                fh.write(code)
            report.append((fn, str(f.getEntryPoint()), sorted(called_ext)))

        with open(os.path.join(OUTDIR, program_name + "_report.txt"), "w") as fh:
            fh.write("=== EXTERNAL (IMPORTED) FUNCTION USAGE by call count ===\n")
            for k, v in sorted(extfuncs.items(), key=lambda x: -x[1]):
                fh.write("%-60s %d\n" % (k, v))
            fh.write("\n=== ALL FUNCTIONS with external deps ===\n")
            for fn, ep, ce in report:
                fh.write("%-60s %s ext={%s}\n" % (fn, ep, ",".join(ce)))
            fh.write("\n=== FUNCTION COUNT: %d ===\n" % len(funcs))
        print("[*] Done %s: %d functions" % (program_name, len(funcs)))
        decomp.dispose()


analyze("commandtofilter2")
analyze("rastertodpp268")
print("[*] ALL DONE")
