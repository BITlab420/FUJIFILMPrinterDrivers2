// skipBlankPagePrint  entry=100006aa4

/* skipBlankPagePrint(cups_page_header2_s*, sdata*) */

undefined2 skipBlankPagePrint(cups_page_header2_s *param_1,sdata *param_2)

{
  ulong uVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  long lVar5;
  ulong uVar6;
  ushort uVar7;
  ulong uVar8;
  uint uVar9;
  
  pcVar3 = (char *)GetOption("BRSkipBlank");
  if (pcVar3 != (char *)0x0) {
    uVar7 = *(ushort *)(param_2 + 10);
    if ((uVar7 & 1) != 0) {
      uVar7 = uVar7 ^ 1;
      *(ushort *)(param_2 + 10) = uVar7;
    }
    iVar2 = _strcmp(pcVar3,"ON");
    if (iVar2 == 0) {
      uVar9 = *(int *)(param_1 + 0x178) * *(int *)(param_1 + 0x188);
      uVar1 = (ulong)(uVar9 >> 2);
      piVar4 = _Planes;
      uVar8 = 0;
      if (uVar9 >> 2 != 0) {
        uVar6 = 0;
        do {
          if (*piVar4 != 0) goto LAB_100006bca;
          uVar8 = uVar1 - 1;
          if (uVar1 - 1 == uVar6) break;
          piVar4 = piVar4 + 1;
          uVar8 = uVar6 + 1;
          uVar6 = uVar8;
        } while (uVar8 < uVar1);
      }
      uVar6 = 0;
      if ((uVar9 & 3) != 0) {
        do {
          if (*(char *)((long)piVar4 + uVar6) != '\0') {
LAB_100006bca:
            *(short *)(param_2 + 0xe) = *(short *)(param_2 + 0xe) + 1;
            return 0;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uVar9 & 3));
      }
      if (uVar8 == uVar1 - 1) {
        *(ushort *)(param_2 + 10) = uVar7 | 1;
        if ((uVar7 & 2) != 0) {
          return 1;
        }
        lVar5 = GetOption("collate");
        if (lVar5 == 0) {
          return 1;
        }
        if (*(int *)(param_1 + 0x110) != 1) {
          return 1;
        }
        if (1 < *(short *)(param_2 + 0xc)) {
          param_2[10] = (sdata)((byte)param_2[10] | 2);
          _blankPagePtr = _malloc((ulong)uVar9);
          _memcpy(_blankPagePtr,_Planes,(ulong)uVar9);
          return 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

