// GetSleepMode  entry=1000055fa

/* GetSleepMode(ppd_file_s*) */

undefined2 GetSleepMode(ppd_file_s *param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  short sVar5;
  ulong uVar6;
  short sVar7;
  short sVar8;
  
  lVar3 = GetOption("BRSleepTime");
  if (lVar3 == 0) {
    iVar1 = _printf("%s","@PJL DEFAULT AUTOSLEEP = ON\n");
    if (iVar1 < 0x1c) {
      return 1;
    }
    iVar1 = NumericLength(1);
    iVar2 = _printf("@PJL DEFAULT TIMEOUTSLEEP = %d\n",1);
    if (iVar2 < iVar1 + 0x1d) {
      return 1;
    }
    iVar1 = _printf("%s","@PJL SET AUTOSLEEP = ON\n");
    if (iVar1 < 0x18) {
      return 1;
    }
    iVar1 = NumericLength(1);
    uVar6 = 1;
  }
  else {
    lVar3 = _ppdFindCustomOption(param_1,"BRSleepTime");
    sVar5 = 0;
    sVar8 = 0;
    if (lVar3 != 0) {
      lVar3 = _ppdFindCustomParam(lVar3,"Time");
      if (lVar3 == 0) {
        sVar5 = 1;
        sVar8 = 0x3c;
      }
      else {
        sVar5 = *(short *)(lVar3 + 0x84);
        sVar8 = *(short *)(lVar3 + 0x88);
      }
    }
    pcVar4 = (char *)GetOption("com.fujifilm.print.PrintSettings.sleepmode");
    if (pcVar4 == (char *)0x0) {
      return 0;
    }
    iVar1 = _strcmp(pcVar4,"Default");
    if (iVar1 == 0) {
      return 0;
    }
    pcVar4 = (char *)GetOption("com.fujifilm.print.PrintSettings.sleep");
    if (pcVar4 == (char *)0x0) {
      return 0;
    }
    iVar1 = _atoi(pcVar4);
    sVar7 = (short)iVar1;
    if ((sVar7 < sVar5) || (sVar8 < sVar7)) {
      sVar7 = 5;
    }
    iVar1 = _printf("%s","@PJL DEFAULT AUTOSLEEP = ON\n");
    if (iVar1 < 0x1c) {
      return 1;
    }
    iVar1 = NumericLength((long)sVar7);
    iVar2 = _printf("@PJL DEFAULT TIMEOUTSLEEP = %d\n",(ulong)(uint)(int)sVar7);
    if (iVar2 < iVar1 + 0x1d) {
      return 1;
    }
    iVar1 = _printf("%s","@PJL SET AUTOSLEEP = ON\n");
    if (iVar1 < 0x18) {
      return 1;
    }
    iVar1 = NumericLength((long)sVar7);
    uVar6 = (ulong)(uint)(int)sVar7;
  }
  iVar2 = _printf("@PJL SET TIMEOUTSLEEP = %d\n",uVar6);
  if (iVar1 + 0x19 <= iVar2) {
    return 0;
  }
  return 1;
}

