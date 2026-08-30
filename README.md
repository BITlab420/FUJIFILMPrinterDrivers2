# FUJIFILM DocuPrint P/M 2xx CUPS driver — Linux port (minimal branch)

Native Linux port of the macOS CUPS raster filter `rastertodpp268` for the
FUJIFILM DocuPrint P225/P228/P260/P265/P268 & M225/M228/M260/M265/M268
(a rebadged **Brother** engine). Rebuilt from a Ghidra decompile of the
original Mach-O binary; output is byte-identical to the original driver.

## Build

    make            # -> rastertodpp268, commandtofilter2
    sudo make install

Requires gcc + libcups/libcupsimage.

## Files

    rastertodpp268.c     whole port, single translation unit
    commandtofilter2.c   calibration pass-through stub
    LUT/                 halftone matrices (loaded from $BR_LUT_PATH)
    ppd/                 18 decompressed driver PPDs

## Run

    PPD=ppd/<your-model>.ppd BR_LUT_PATH=$PWD/LUT \
      ./rastertodpp268 0 user job 1 "" page.raster > out.prn

For the full repository (decoder, RE scripts, 对拍 verification harness,
original binaries) see the `master` branch.
