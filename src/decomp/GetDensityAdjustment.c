// GetDensityAdjustment  entry=1000054e8

/* GetDensityAdjustment(ppd_file_s*) */

undefined2 GetDensityAdjustment(ppd_file_s *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  short sVar6;
  short sVar7;
  
  lVar4 = GetOption("BRDensityAdjustment");
  if (lVar4 != 0) {
    lVar4 = _ppdFindCustomOption(param_1,"BRDensityAdjustment");
    sVar6 = 0;
    sVar7 = 0;
    if (lVar4 != 0) {
      lVar4 = _ppdFindCustomParam(lVar4,"Density");
      if (lVar4 == 0) {
        sVar6 = -6;
        sVar7 = 6;
      }
      else {
        sVar6 = *(short *)(lVar4 + 0x84);
        sVar7 = *(short *)(lVar4 + 0x88);
      }
    }
    pcVar5 = (char *)GetOption("com.fujifilm.print.PrintSettings.densitymode");
    if ((pcVar5 != (char *)0x0) && (iVar2 = _strcmp(pcVar5,"Default"), iVar2 != 0)) {
      iVar2 = _atoi(pcVar5);
      sVar1 = (short)iVar2;
      if ((sVar1 < sVar6) || (sVar7 < sVar1)) {
        sVar1 = 0;
      }
      iVar2 = NumericLength((long)sVar1);
      iVar3 = _printf("@PJL SET DENSITY = %d\n",(ulong)(uint)(int)sVar1);
      if (iVar3 < iVar2 + 0x14) {
        return 1;
      }
      iVar2 = NumericLength((long)sVar1);
      iVar3 = _printf("@PJL SET DEVBIASADJUST = %d\n",(ulong)(uint)(int)sVar1);
      if (iVar3 < iVar2 + 0x1a) {
        return 1;
      }
    }
  }
  return 0;
}

