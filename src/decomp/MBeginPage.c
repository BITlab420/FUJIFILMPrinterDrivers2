// MBeginPage  entry=10000585f

/* MBeginPage(cups_page_header2_s*, sdata*, int) */

undefined2 MBeginPage(cups_page_header2_s *param_1,sdata *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  char *pcVar5;
  
  sVar1 = BeginSkipBlankPage(param_1,param_2);
  if ((sVar1 != 1) && (sVar1 = BeginDriverDuplex(param_1,param_2), sVar1 != 1)) {
    BeginDriverDXCollate(param_1,param_2);
    sVar1 = SendPaperFeed_1030(param_3);
    if (sVar1 != 0) {
      return 1;
    }
    if (((byte)param_2[0xb] & 1) == 0) {
      iVar2 = NumericLength((ulong)*(uint *)(param_1 + 0x154));
      uVar4 = (ulong)*(uint *)(param_1 + 0x154);
    }
    else {
      iVar2 = NumericLength(1);
      uVar4 = 1;
    }
    iVar3 = _printf("\x1b&l%dX",uVar4);
    if (iVar3 < ((iVar2 * 0x10000 + 0x40000) >> 0x10)) {
      return 1;
    }
    if (((byte)param_2[0x14] & 4) == 0) {
      pcVar5 = "\x1b*b1030m";
    }
    else {
      pcVar5 = "\x1b*b1032m";
    }
    iVar2 = _printf("%s",pcVar5);
    if (iVar2 < 8) {
      return 1;
    }
    ResetSendBuf();
    AllocateCompMemory((ulong)*(uint *)(param_1 + 0x174),(ulong)*(uint *)(param_1 + 0x178));
  }
  return 0;
}

