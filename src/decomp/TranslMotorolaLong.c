// TranslMotorolaLong  entry=1000030d8

/* TranslMotorolaLong(unsigned long) -- 8-byte byte-order reversal */

undefined8 TranslMotorolaLong(ulong param_1)

{
  ulong v;

  v = (ulong)param_1;
  return (v >> 56) |
         ((v >> 40) & 0x000000000000ff00UL) |
         ((v >> 24) & 0x0000000000ff0000UL) |
         ((v >> 8) & 0x00000000ff000000UL) |
         ((v << 8) & 0x000000ff00000000UL) |
         ((v << 24) & 0x0000ff0000000000UL) |
         ((v << 40) & 0x00ff000000000000UL) |
         ((v << 56) & 0xff00000000000000UL);
}
