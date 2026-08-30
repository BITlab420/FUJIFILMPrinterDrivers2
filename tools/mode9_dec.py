#!/usr/bin/env python3
"""Decode MODE9_16bit band data from the Fuji/Brother rastertodpp format.
Usage: mode9_dec.py out.prn out.pbm
The decoder understands the command format from checkOptByte():
  - substitute: byte0 = (offset<<3) | (count-1), offset<=15/count-1<=7 inline
  - repeat:     byte0 = 0x80 | (offset<<5) | (count-2), offset<=3 inline
  Overflow: 0xFF bytes + remainder for offset/count above the inline range.
"""
import sys, re

class Reader:
    def __init__(self, data):
        self.d = data
        self.i = 0
    def get(self):
        if self.i >= len(self.d):
            raise EOFError
        b = self.d[self.i]; self.i += 1
        return b
    def peek(self):
        if self.i >= len(self.d): return -1
        return self.d[self.i]

def read_overflow(r):
    """overflow value: 0xFF bytes then a remainder byte"""
    val = 0
    while True:
        b = r.get()
        if b == 0xFF:
            val += 255
        else:
            return val + b

def read_substitute(r, cmd, line):
    offset = (cmd >> 3) & 0xf
    count = (cmd & 7) + 1
    if (cmd & 7) == 7:
        count += read_overflow(r)
    if offset == 0xf:
        offset += read_overflow(r)
    base = len(line) - offset
    if base < 0:
        line[:0] = b"\x00" * (-base)
        base = 0
    need = base + count
    if need > len(line):
        line.extend(b"\x00" * (need - len(line)))
    for k in range(count):
        v = r.get()
        line[base+k] = v
    return

def read_repeat(r, cmd, line):
    offset = (cmd >> 5) & 3
    count = (cmd & 0x1f) + 2
    if (cmd & 0x1f) == 0x1f:
        count += read_overflow(r)
    if offset == 3:
        offset += read_overflow(r)
    base = len(line) - offset
    if base < 0:
        line[:0] = b"\x00" * (-base)
        base = 0
    value = r.get()
    need = base + count
    if need > len(line):
        line.extend(b"\x00" * (need - len(line)))
    for k in range(count):
        line[base+k] = value
    return

def decode_page(data):
    r = Reader(data)
    page = []
    line = bytearray()
    # find first ESC*b1030m
    idx = data.find(b"\x1b*b10")
    if idx < 0:
        return page
    r.i = idx
    # consume ESC * b 1 0 3 0 m
    while True:
        b = r.get()
        if b == 0x0c: return page
        if b == 0x6d:  # 'm'
            break
    while True:
        # read ASCII length digits, then 'w'
        while r.peek() >= 0x30 and r.peek() <= 0x39:
            r.get()
        b = r.get()
        if b != 0x77:
            if b == 0x0c: return page
            continue  # not a block (e.g. 1030M)
        count = r.get() * 256 + r.get()
        line = bytearray()
        for _ in range(count):
            ne = r.get()
            if ne == 0xff:
                line = bytearray()
            elif ne == 0:
                pass
            else:
                for _ in range(ne):
                    cmd = r.get()
                    if cmd & 0x80:
                        read_repeat(r, cmd, line)
                    else:
                        read_substitute(r, cmd, line)
            page.append(bytes(line))
        if len(page) > 100000:
            break
    return page

def write_pbm(page, path):
    height = len(page)
    width = max(len(l) for l in page) * 8 if page else 0
    with open(path, "wb") as f:
        f.write(("P4 %d %d\n" % (width, height)).encode())
        for l in page:
            f.write(l)
            f.write(b"\x00" * (width // 8 - len(l)))

if __name__ == "__main__":
    data = open(sys.argv[1], "rb").read()
    page = decode_page(data)
    print("decoded %d lines" % len(page))
    write_pbm(page, sys.argv[2])
    print("wrote", sys.argv[2])
