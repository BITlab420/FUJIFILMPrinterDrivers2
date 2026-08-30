// BeginDriverDuplex  entry=100006d67

/* BeginDriverDuplex(cups_page_header2_s*, sdata*) */

int BeginDriverDuplex(cups_page_header2_s *param_1,sdata *param_2)

{
  short sVar1;
  
  if (((byte)param_2[0xb] & 2) == 0) {
    sVar1 = saveOddPage(param_1,param_2);
  }
  else {
    if ((*(ushort *)(param_2 + 0x14) & 2) != 0) {
      *(ushort *)(param_2 + 0x14) = *(ushort *)(param_2 + 0x14) ^ 2;
    }
    sVar1 = 0;
  }
  return (int)sVar1;
}

