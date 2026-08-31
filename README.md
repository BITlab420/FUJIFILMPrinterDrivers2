# FUJIFILM DocuPrint P/M 2xx CUPS Driver — Linux native port (black-box recompilation)

Reverse-engineered the macOS-only CUPS raster filters
`rastertodpp268` / `commandtofilter2` (from the Fuji Xerox / FUJIFILM
DocuPrint P225/P228/P260/P265/P268 & M225/M228/M260/M265/M268 driver) and
recompiled them to a **byte-identical native Linux filter**.

The printer is a rebadged **Brother** engine (SNMP OID `1.3.6.1.4.1.2435`,
HQ1200), so the output speaks the same PJL + PCL + mode-9 band protocol as
the printer's native firmware.

## Verification: byte-identical with the real driver ✅

The ORIGINAL macOS x86_64 binaries run under **Rosetta 2** on an ARM Mac
(`tests/run_duipa.sh`). Feeding the same raster + PPD to both, masking the
per-run timestamps, and byte-comparing gives:

| test raster | result |
|---|---|
| `ras_half.raster` (1-bit, half blank) | **IDENTICAL** |
| `ras_00/ff/aa/5a` (1-bit fills) | **IDENTICAL** |
| `test.raster` (8-bit CMYK Letter) | **IDENTICAL** |
| `two.raster` (2-page) | **IDENTICAL** |

Reference outputs from the original driver are in `tests/refs/`;
`tests/compare.sh` re-runs the comparison.

Beyond the base rasters, `tests/run_duipa_more.sh` runs a 32-case edge
suite against the original binary: multi-print (copies up to 9), multi-page
duplex long/short-edge, odd/even/single-page duplex, 8-bit grayscale at
300/600/1200 dpi, non-Letter papers (Legal/A5/Env10), blank pages, tiny/wide/
tall pages, odd pixel sizes, and PPD option strings (resolution, toner save,
skip-blank, media type, duplex). All byte-compare **IDENTICAL**.

## Structure

    bin/                    original macOS Mach-O x86_64 binaries (binary blob deps)
      rastertodpp268        the raster filter (macOS)
      commandtofilter2      calibration filter (macOS)
    LUT/                    halftone threshold matrices (BRML + 32x32 byte matrix),
                            6 files used by the driver (binary blob deps)
    ppd/                    18 FUJIFILM driver PPDs (unmodified)
    src/                    the Linux port source
      shim.h                types + Ghidra-macro fixes + symbol aliasing
      globals.h             data image symbol map + hand-fixed aliases
      build.sh              build (concatenate + gcc -lcups -lcupsimage)
      build.py              concatenates shim+globals+decompiled funcs+main
      gen_globals.py        (optional) regenerate globals from data/*
      install.sh            root install: filter + LUT + rewritten PPDs
      commandtofilter2_stub.c  pass-through stub (calibration not ported)
      decomp/               fixed decompiled C, one file per function
      data/                 img.bin (34992-byte data image) + symbol export json
    ghidra/                 analysis scripts used during the RE
    tools/                  verification helpers
      mode9_dec2.py         MODE9_16bit band decoder (byte-identical to
                            brlaser's brdecode) -> render what the printer prints
      mode9_dec.py          brlaser-format decoder (for cross-checks)
      readraster.c          print CUPS raster header
      mkras*.c              generate synthetic test rasters
      offsets.c             libcups struct field offset checks
    tests/                  test rasters + PPD + duipa (对拍) harness + refs/
    tools/mkgen.c           generic multi-page raster generator for edge cases

## How the port works

1. Ghidra headless decompile of `rastertodpp268` (Mach-O x86_64, symbols
   intact — not stripped).
2. All ~140 real functions decompiled to C; the ~87 import-stub / CF-stub
   files handled by `shim.h`.
3. Global data (`__data/__bss/__cstring/__const`, 34992 bytes) dumped to
   `data/img.bin` and symbol-mapped into `globals.h`/`decomp/globals.c`.
4. Fixed ~11 classes of Ghidra/decompile + recompile bugs, e.g.:
   - `&array + N` pointer-to-array scaling (`_paperArray`, `_tblISO88592`, ...)
   - C hex-escape greediness (`"\x1bE"` -> `"\x1b" "E"`)
   - dropped printf/fprintf args (PAGE counter, ...)
   - `TranslMotorolaLong` / `copyData` broken decompiles
   - **Ghidra `CONCATxx(a,b)` = `a` is the HIGH byte** (shim had them reversed)
   - memory-alias bugs: `DAT_100015130` (paper sort keys) overlaps
     `_paperArray`; `_margins` is the low half of `__margins` — these must
     alias the same storage in the port, exactly like the original binary.
5. Only hand-written code: `decomp/main.c` (CUPS filter entry) and `shim.h`.

## Build & install

    cd src
    ./build.sh            # -> ./rastertodpp268 (needs gcc + libcups/libcupsimage)
    sudo ./install.sh     # filter + LUT + rewritten PPDs, then add the printer

Manual run:

    PPD=/path/to/fujifilm_p268.ppd BR_LUT_PATH=/path/to/LUT \
      ./rastertodpp268 0 user job 1 "" page.raster > out.prn

`page.raster` is CUPS raster (`application/vnd.cups-raster`), e.g. from
`cupsfilter`.

## Render what the printer will print (no printer needed)

    python3 tools/mode9_dec2.py out.prn out.pbm    # then view the PBM

The decoder is byte-identical to brlaser's `brdecode` and reproduces the
input raster exactly (1-bit case) and the halftoned content rows for 8-bit
input. Key format facts: blocks `<len>w\x00<count>` (count = lines), each line
`[num_edits][edits]` with `0xff` = blank (clear buffer) and `0x00` = unchanged;
edits use a **cursor** (`line_offset`, reset per line) over a **persisted**
buffer that only grows when an edit writes past its end.

## 对拍 (byte-comparison vs the original)

    # Linux side
    PPD=fujifilm_p268.ppd BR_LUT_PATH=... ./rastertodpp268 0 u t 1 "" test.raster > port.prn
    # macOS side (Rosetta runs the original x86_64 binary)
    PPD=fujifilm_p268.ppd ./rastertodpp268.orig 0 u t 1 "" test.raster > ref.prn
    tests/compare.sh ref.prn port.prn      # masks timestamps, byte-diffs

## Relation to brlaser

[brlaser](https://github.com/pdewacht/brlaser) is an independent GPL Brother
driver for the same printer engine. It shares the OUTER protocol and the exact
**command-byte format** (substitute `(offset<<3)|(count-1)`, repeat
`0x80|(offset<<5)|(count-2)`, 0xff-byte overflow, blank line `0xff`) but is a
separate, much simpler implementation:

| | brlaser | this port (original driver) |
|---|---|---|
| block packing | variable lines up to 16350 B/block | fixed 128 lines/block |
| line encoder | simple greedy delta | MODE9_16bit (16-bit halfwords) |
| PJL | minimal (`JOB NAME=`, `RAS1200MODE`, ...) | full (`HOLD`, `JOBNAME/USERNAME/LOGINUSER`, `TRANSFERLEVEL`, `PAGEPROTECT`, ...) |
| paper | PPD size name directly | own paper mapping table |
| margins | none | left-margin repeat handled |
| features | single-sided minimal | duplex/density/sleep/calibration/status |

brlaser's `brdecode.cc` was used to cross-validate the decoder in `tools/`.
For a faithful, feature-complete, byte-identical driver use this port; brlaser
is only useful as a minimal fallback or as a decoding reference.

## Status / limitations

- Monochrome + grayscale printing works, byte-identical to the original.
- Status reporting via backchannel/SNMP is stubbed; CUPS sees no device status.
- `commandtofilter2` (calibration) is a pass-through stub.
- The only run-to-run difference vs the original is the `JOBTIME` /
  `PRINTLOG ITEM = 2` timestamps.

## Credits

RE'd and ported by **BITlab420**. Original driver is (c) FUJIFILM Business
Innovation / Brother. The port is provided for interoperability with hardware
you own.
