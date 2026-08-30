// sortPaperResult  entry=100002592

/* sortPaperResult(ppd_file_s*) */

void sortPaperResult(ppd_file_s *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  short *psVar5;
  float *pfVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  short sVar11;
  undefined4 *puVar12;
  ulong uVar13;
  long lVar14;
  char *pcVar15;
  int iVar16;
  ulong uVar17;
  byte bVar18;
  undefined1 local_80 [72];
  long local_38;
  
  bVar18 = 0;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  lVar14 = 0;
  pcVar15 = _paperArray;
  if (0 < *(int *)(param_1 + 0xa8)) {
    pfVar6 = (float *)(*(long *)(param_1 + 0xb0) + 0x34);
    pcVar15 = _paperArray;
    lVar14 = 0;
    do {
      _strcpy(pcVar15,(char *)(pfVar6 + -0xc));
      *(short *)(pcVar15 + 0x42) = (short)(int)pfVar6[-1];
      *(short *)(pcVar15 + 0x40) = (short)(int)*pfVar6;
      lVar14 = lVar14 + 1;
      pfVar6 = pfVar6 + 0x12;
      pcVar15 = pcVar15 + 0x44;
    } while ((int)lVar14 < *(int *)(param_1 + 0xa8));
  }
  *pcVar15 = '\0';
  (&DAT_100015132)[lVar14 * 0x22] = 0;
  (&DAT_100015130)[lVar14 * 0x22] = 0;
  iVar2 = *(int *)(param_1 + 0xa8);
  if (0 < iVar2 + -2) {
    iVar9 = 2;
    psVar7 = &DAT_100015176;
    uVar13 = 0;
    do {
      iVar3 = (int)(uVar13 + 1);
      if (iVar3 < iVar2 + -1) {
        sVar4 = (&DAT_100015130)[uVar13 * 0x22];
        sVar11 = (&DAT_100015132)[uVar13 * 0x22];
        uVar17 = uVar13 & 0xffffffff;
        psVar5 = psVar7;
        iVar8 = iVar9;
        do {
          sVar1 = *psVar5;
          if (sVar1 < sVar11) {
            uVar17 = (ulong)(iVar8 - 1);
            sVar11 = sVar1;
            sVar4 = psVar5[-1];
          }
          else if (sVar1 == sVar11) {
            sVar1 = psVar5[-1];
            if (sVar1 < sVar4) {
              uVar17 = (ulong)(iVar8 - 1);
            }
            if (sVar1 <= sVar4) {
              sVar4 = sVar1;
            }
          }
          iVar16 = (int)uVar17;
          iVar8 = iVar8 + 1;
          psVar5 = psVar5 + 0x22;
        } while (iVar2 != iVar8);
      }
      else {
        iVar16 = (int)uVar13;
      }
      _memcpy(local_80,_paperArray + uVar13 * 0x44,0x44);
      puVar10 = (undefined4 *)(_paperArray + (long)iVar16 * 0x44);
      puVar12 = (undefined4 *)(_paperArray + uVar13 * 0x44);
      for (lVar14 = 0x11; lVar14 != 0; lVar14 = lVar14 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + (ulong)bVar18 * -2 + 1;
        puVar12 = puVar12 + (ulong)bVar18 * -2 + 1;
      }
      _memcpy(_paperArray + (long)iVar16 * 0x44,local_80,0x44);
      iVar9 = iVar9 + 1;
      psVar7 = psVar7 + 0x22;
      uVar13 = uVar13 + 1;
    } while (iVar3 != iVar2 + -2);
  }
  if (*(long *)PTR____stack_chk_guard_100012028 != local_38) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}

