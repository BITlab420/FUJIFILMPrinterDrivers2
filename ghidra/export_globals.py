import json

import pyghidra

PROJ_LOC = "/tmp/opencode/ghidra-proj"
PROJ_NAME = "proj"
OUT = "/tmp/opencode/globals_export"


def run(program_name):
    with pyghidra.open_program(
        binary_path="/tmp/opencode/%s" % program_name,
        project_location=PROJ_LOC,
        project_name=PROJ_NAME,
        program_name=program_name,
    ) as flat_api:
        prog = flat_api.getCurrentProgram()
        listing = prog.getListing()
        sym = prog.getSymbolTable()
        mem = prog.getMemory()

        blocks = []
        for b in mem.getBlocks():
            blocks.append({
                "name": b.getName(),
                "addr": str(b.getStart()),
                "size": b.getSize(),
                "isInitialized": b.isInitialized(),
            })

        symbols = []
        for s in sym.getAllSymbols(True):
            if s.isExternal():
                continue
            name = s.getName()
            addr = s.getAddress()
            if not addr.isMemoryAddress():
                continue
            # find containing block
            size = None
            dtype = None
            try:
                data = listing.getDataAt(addr)
                if data is not None:
                    dt = data.getDataType()
                    dtype = str(dt)
                    size = data.getLength()
            except Exception:
                dtype = None
            symbols.append({
                "name": name,
                "addr": str(addr),
                "size": size,
                "dtype": dtype,
            })

        out = {"blocks": blocks, "symbols": symbols}
        import os
        os.makedirs(OUT, exist_ok=True)
        with open("%s/%s.json" % (OUT, program_name), "w") as fh:
            json.dump(out, fh, indent=1)
        print("[*] exported %s: %d symbols, %d blocks" % (program_name, len(symbols), len(blocks)))


run("rastertodpp268")
