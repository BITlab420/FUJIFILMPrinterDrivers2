// SendRasterDoc  entry=100002ad4

/* SendRasterDoc(_cups_raster_s*, ppd_file_s*) */

int SendRasterDoc(_cups_raster_s *param_1,ppd_file_s *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  FILE *pFVar6;
  long *plVar7;
  sdata local_770 [48];
  cups_page_header2_s local_740 [1800];
  long local_38;
  
  plVar7 = (long *)PTR____stack_chk_guard_100012028;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  if ((param_1 == (_cups_raster_s *)0x0) || (param_2 == (ppd_file_s *)0x0)) {
    pFVar6 = *(FILE **)PTR____stderrp_100012030;
    pcVar5 = "Invalid Parameter(s).\n";
  }
  else {
    sVar1 = GetModel(param_2);
    if (sVar1 != 0) {
      sVar1 = SetFunctionTable();
      if (sVar1 == 0) {
        _gGetStatusMode = BeginBackChannel();
        CreateSendBuf(local_770);
        iVar2 = _cupsRasterReadHeader2(param_1,local_740);
        if (iVar2 == 0) {
          sVar1 = 0;
        }
        else {
          iVar2 = 1;
          do {
            iVar4 = iVar2;
            _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%d\n","PAGE: ",iVar4);
            sVar1 = BeginPageData(param_2,local_740,iVar4,local_770);
            if ((sVar1 != 0) ||
               (sVar1 = SendPageData(param_1,param_2,local_740,iVar4,local_770), sVar1 != 0))
            goto LAB_100002c82;
            EndPageData(local_740,local_770);
            iVar3 = _cupsRasterReadHeader2(param_1,local_740);
            iVar2 = iVar4 + 1;
          } while (iVar3 != 0);
          sVar1 = 0;
LAB_100002c82:
          plVar7 = (long *)PTR____stack_chk_guard_100012028;
          if (iVar4 != 0) {
            ((void (*)(void))DAT_100016200)();
            _fflush(*(FILE **)PTR____stdoutp_100012038);
            plVar7 = (long *)PTR____stack_chk_guard_100012028;
          }
        }
        DestroySendBuf();
        ResetFunctionTable();
        EndBackChannel(_gGetStatusMode);
      }
      else {
        _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ",
                 "Setting function table failed!\n");
      }
      goto LAB_100002b31;
    }
    pFVar6 = *(FILE **)PTR____stderrp_100012030;
    pcVar5 = "Unknown printer model.\n";
  }
  _fprintf(pFVar6,"%s%s","ERROR: ",pcVar5);
  sVar1 = 1;
LAB_100002b31:
  if (*plVar7 != local_38) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return (int)sVar1;
}

