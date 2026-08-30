// BeginSkipBlankPage  entry=100006a8a

/* BeginSkipBlankPage(cups_page_header2_s*, sdata*) */

int BeginSkipBlankPage(cups_page_header2_s *param_1,sdata *param_2)

{
  short sVar1;
  
  if ((*(ushort *)(param_2 + 10) & 0x204) == 0) {
    sVar1 = skipBlankPagePrint(param_1,param_2);
  }
  else {
    sVar1 = 0;
  }
  return (int)sVar1;
}

