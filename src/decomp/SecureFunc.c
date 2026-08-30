// SecureFunc  entry=100001891

/* SecureFunc(ppd_file_s*) */

undefined2 SecureFunc(ppd_file_s *param_1)

{
  undefined *puVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  size_t sVar7;
  byte bVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte local_d8 [96];
  byte local_78 [88];
  long local_20;
  
  puVar1 = PTR____stack_chk_guard_100012028;
  local_20 = *(long *)PTR____stack_chk_guard_100012028;
  lVar5 = _ppdFindAttr(param_1,"BRSecureCode",0);
  if (lVar5 == 0) goto LAB_100001a52;
  pcVar6 = (char *)GetOption("com.fujifilm.print.PrintSettings.secureprint");
  if (pcVar6 != (char *)0x0) {
    iVar4 = _strcmp(pcVar6,"ON");
    if (iVar4 == 0) {
      pbVar9 = local_78;
      CreateNamefromArray(pbVar9,"com.fujifilm.print.PrintSettings.usernamecnt",
                          "com.fujifilm.print.PrintSettings.username..a.%d..n.");
      if (local_78[0] != 0) {
        pbVar10 = local_78;
        bVar8 = local_78[0];
        do {
          pbVar10 = pbVar10 + 1;
          if (bVar8 < 0x20) {
            pbVar10[-1] = 0x20;
          }
          else if (0x9f < bVar8) {
            pbVar10[-1] = *(byte *)((long)&cf_plist.field1_0x8 + (ulong)bVar8);
          }
          bVar8 = *pbVar10;
        } while (bVar8 != 0);
        while (local_78[0] != 0) {
          if (local_78[0] < 0x20) {
LAB_100001975:
            *pbVar9 = 0x20;
          }
          else if (local_78[0] < 0x7c) {
            if ((local_78[0] - 0x22 < 0x3b) &&
               ((0x40000002a002701U >> ((ulong)(local_78[0] - 0x22) & 0x3f) & 1) != 0))
            goto LAB_100001975;
          }
          else if (local_78[0] == 0x7c) goto LAB_100001975;
          pbVar10 = pbVar9 + 1;
          pbVar9 = pbVar9 + 1;
          local_78[0] = *pbVar10;
        }
      }
      pbVar9 = local_d8;
      CreateNamefromArray(pbVar9,"com.fujifilm.print.PrintSettings.jobnamecnt",
                          "com.fujifilm.print.PrintSettings.jobname..a.%d..n.");
      if (local_d8[0] != 0) {
        pbVar10 = local_d8;
        bVar8 = local_d8[0];
        do {
          pbVar10 = pbVar10 + 1;
          if (bVar8 < 0x20) {
            pbVar10[-1] = 0x20;
          }
          else if (0x9f < bVar8) {
            pbVar10[-1] = *(byte *)((long)&cf_plist.field1_0x8 + (ulong)bVar8);
          }
          bVar8 = *pbVar10;
        } while (bVar8 != 0);
        while (local_d8[0] != 0) {
          if (local_d8[0] < 0x20) {
LAB_100001a13:
            *pbVar9 = 0x20;
          }
          else if (local_d8[0] < 0x7c) {
            if ((local_d8[0] - 0x22 < 0x3b) &&
               ((0x40000002a002701U >> ((ulong)(local_d8[0] - 0x22) & 0x3f) & 1) != 0))
            goto LAB_100001a13;
          }
          else if (local_d8[0] == 0x7c) goto LAB_100001a13;
          pbVar10 = pbVar9 + 1;
          pbVar9 = pbVar9 + 1;
          local_d8[0] = *pbVar10;
        }
      }
      pcVar6 = (char *)GetOption("com.fujifilm.print.PrintSettings.password");
      if ((pcVar6 == (char *)0x0) || (sVar7 = _strlen(pcVar6), sVar7 != 4)) goto LAB_100001a52;
      pbVar10 = local_d8;
      pbVar9 = local_78;
    }
    else {
LAB_100001a52:
      pbVar10 = (byte *)0x0;
      pbVar9 = (byte *)0x0;
      pcVar6 = (char *)0x0;
    }
    sVar2 = SendSecurePrintPJL(pbVar10,pbVar9,pcVar6);
    uVar3 = 1;
    if (sVar2 != 0) goto LAB_100001a68;
  }
  uVar3 = 0;
LAB_100001a68:
  if (*(long *)puVar1 != local_20) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return uVar3;
}

