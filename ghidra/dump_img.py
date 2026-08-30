import pyghidra

PROJ_LOC = "/tmp/opencode/ghidra-proj"
PROJ_NAME = "proj"


def run(program_name, start, size, outfile):
    with pyghidra.open_program(
        binary_path="/tmp/opencode/%s" % program_name,
        project_location=PROJ_LOC,
        project_name=PROJ_NAME,
        program_name=program_name,
    ) as flat_api:
        prog = flat_api.getCurrentProgram()
        mem = prog.getMemory()
        start_addr = prog.getAddressFactory().getDefaultAddressSpace().getAddress(start)
        data = flat_api.getBytes(start_addr, size)
        with open(outfile, "wb") as fh:
            fh.write(bytes(data))
        print("[*] dumped %d bytes from 0x%x to %s" % (size, start, outfile))


# data region: __cstring at 0x10000ed10 .. end of __bss 0x1000175c0
run("rastertodpp268", 0x10000ed10, 0x1000175c0 - 0x10000ed10, "/tmp/opencode/img.bin")
