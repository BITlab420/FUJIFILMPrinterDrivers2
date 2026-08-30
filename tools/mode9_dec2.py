#!/usr/bin/env python3
"""MODE9_16bit band decoder (matching brlaser's brdecode.cc exactly).

- <len>w <count-2bytes> blocks; count = number of lines
- line: num_edits byte
    0xff -> line buffer cleared (blank)
    0x00 -> line unchanged (buffer reused)
    else -> line_offset=0; apply edits to the PERSISTED buffer
- edit (repeat/substitute): cursor semantics
    end = line_offset + offset + count; buffer grows only if end > size
    line_offset += offset; write count bytes; line_offset += count
- the raster line = the (fixed) buffer; content written at cursor positions
"""
import sys

class Reader:
    def __init__(self, data):
        self.d=data; self.i=0
    def get(self):
        b=self.d[self.i]; self.i+=1; return b
    def peek(self):
        return -1 if self.i>=len(self.d) else self.d[self.i]

def read_overflow(r):
    s=0
    while True:
        b=r.get(); s+=b
        if b!=255: return s

def read_edit(r, cmd, line, off0):
    if cmd&0x80:
        off=(cmd>>5)&3
        if off==3: off+=read_overflow(r)
        cnt=cmd&31
        if cnt==31: cnt+=read_overflow(r)
        cnt+=2
        val=r.get()
    else:
        off=(cmd>>3)&15
        if off==15: off+=read_overflow(r)
        cnt=cmd&7
        if cnt==7: cnt+=read_overflow(r)
        cnt+=1
    end=off0+off+cnt
    if end>len(line): line.extend(b"\x00"*(end-len(line)))
    p=off0+off
    if cmd&0x80:
        for i in range(cnt): line[p+i]=val
    else:
        for i in range(cnt): line[p+i]=r.get()
    return p+cnt

def decode(data):
    idx=data.find(b"\x1b*b10")
    if idx<0: return []
    r=Reader(data); r.i=idx
    while True:
        b=r.get()
        if b==0x0c: return []
        if b==0x6d: break
    lines=[]; line=bytearray()
    while True:
        while r.peek()>=0x30 and r.peek()<=0x39: r.get()
        b=r.get()
        if b!=0x77:
            if b==0x0c: break
            continue
        count=r.get()*256+r.get()
        for _ in range(count):
            ne=r.get()
            if ne==0xff:
                line=bytearray()
            elif ne==0:
                pass
            else:
                off0=0
                for _e in range(ne):
                    cmd=r.get()
                    off0=read_edit(r,cmd,line,off0)
            lines.append(bytes(line))
    return lines

def write_pbm(page, path):
    h=len(page); w=max(len(l) for l in page)*8 if page else 0
    with open(path,"wb") as f:
        f.write(("P4 %d %d\n"%(w,h)).encode())
        for l in page:
            f.write(bytes(l)); f.write(b"\x00"*(w//8-len(l)))

if __name__=="__main__":
    page=decode(open(sys.argv[1],"rb").read())
    print("decoded %d lines"%len(page))
    write_pbm(page, sys.argv[2])
    print("wrote",sys.argv[2])
