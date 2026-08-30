// MEndPage  entry=100005ad6

/* MEndPage(cups_page_header2_s*, sdata*) */

undefined8 MEndPage(cups_page_header2_s *param_1,sdata *param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_2 + 10);
  if ((uVar1 & 0x100) == 0) {
    if ((uVar1 & 1) == 0) {
      EndPageCommand();
      uVar1 = *(ushort *)(param_2 + 10);
    }
    if ((uVar1 & 4) == 0) {
      SendBlankPageEND(param_2,param_1);
    }
  }
  else {
    EndPageDriverDuplex(param_1,param_2);
  }
  return 0;
}

