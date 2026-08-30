// MBeginJob_FAX  entry=100003d9d

/* MBeginJob_FAX(cups_page_header2_s*, ppd_file_s*, sdata*) */

undefined2 MBeginJob_FAX(cups_page_header2_s *param_1,ppd_file_s *param_2,sdata *param_3)

{
  int iVar1;
  int iVar2;
  time_t tVar3;
  char *pcVar4;
  size_t sVar5;
  long *plVar6;
  uint uVar7;
  ulong uVar8;
  short sVar9;
  char local_78 [64];
  long local_38;
  
  plVar6 = (long *)PTR____stack_chk_guard_100012028;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  *(undefined2 *)(param_3 + 4) = *(undefined2 *)(param_1 + 0x178);
  *(undefined2 *)param_3 = 1;
  *(undefined2 *)(param_3 + 2) = 0;
  iVar1 = _printf("%s","\x1b%-12345X@PJL\n");
  if (0xd < iVar1) {
    iVar1 = _printf("%s","@PJL ENTER LANGUAGE=FCL\n");
    uVar8 = 0x18;
    if (iVar1 < 0x18) goto LAB_100003ec0;
    tVar3 = _time((time_t *)0x0);
    GetDateTime_FAX(tVar3);
    _printf("\x1b" "DATE[%s\t2]\n",&DAT_100016b30);
    iVar1 = _printf("%s","\x1bRESOLUTION[FINE]\n");
    if (0x11 < iVar1) {
      pcVar4 = (char *)GetOption("com.fujifilm.print.PrintSettings.faxnum");
      iVar1 = _strcmp(pcVar4,"NULL");
      if ((iVar1 != 0) && (*pcVar4 != '\0')) {
        sVar5 = _strlen(pcVar4);
        iVar1 = _printf("\x1b" "DIALNUM[%s]\n",pcVar4);
        if ((iVar1 < (short)((short)sVar5 + 0xb)) ||
           (iVar1 = _printf("%s","\x1bSENDFAX[]\n"), iVar1 < 0xb)) goto LAB_100003ebb;
      }
      pcVar4 = (char *)GetOption("com.fujifilm.print.PrintSettings.count");
      if (pcVar4 != (char *)0x0) {
        iVar1 = _atoi(pcVar4);
        uVar8 = 1;
        if ((iVar1 << 0x10 < 0) || (uVar8 = 0, iVar1 << 0x10 < 1)) goto LAB_100003ec0;
        sVar9 = 1;
        do {
          _sprintf(local_78,"com.fujifilm.print.PrintSettings.faxarray..a.%d",uVar8);
          pcVar4 = (char *)GetOption(local_78);
          iVar2 = _strcmp(pcVar4,"NULL");
          if ((iVar2 != 0) && (*pcVar4 != '\0')) {
            sVar5 = _strlen(pcVar4);
            iVar2 = _printf("\x1b" "DIALNUM[%s]\n",pcVar4);
            uVar8 = 1;
            plVar6 = (long *)PTR____stack_chk_guard_100012028;
            if ((iVar2 < (short)((short)sVar5 + 0xb)) ||
               (iVar2 = _printf("%s","\x1bSENDFAX[]\n"),
               plVar6 = (long *)PTR____stack_chk_guard_100012028, iVar2 < 0xb)) goto LAB_100003ec0;
          }
          uVar7 = (uint)sVar9;
          uVar8 = (ulong)uVar7;
          sVar9 = sVar9 + 1;
        } while ((int)uVar7 < (int)(short)iVar1);
      }
      uVar8 = 0;
      goto LAB_100003ec0;
    }
  }
LAB_100003ebb:
  uVar8 = 1;
LAB_100003ec0:
  if (*plVar6 != local_38) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return (short)uVar8;
}

