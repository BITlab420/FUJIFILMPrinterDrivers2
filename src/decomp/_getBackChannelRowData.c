// _getBackChannelRowData  entry=10000a083

undefined8 _getBackChannelRowData(undefined8 param_1,undefined1 *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 local_238 [512];
  long local_38;
  
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  iVar4 = *param_3;
  ___bzero(param_2,(long)iVar4);
  *param_3 = 0;
  iVar2 = _cupsBackChannelRead(param_1,local_238,0x200);
  if (0 < iVar2) {
    iVar4 = iVar4 + -1;
    do {
      iVar1 = *param_3;
      *param_3 = iVar1 + iVar2;
      if (iVar4 <= iVar1 + iVar2) {
        _fprintf(*(FILE **)PTR____stderrp_100012030,"%s getBackChannelRowData buffer overflow.\n",
                 "DEBUG: ");
        _memcpy(param_2,local_238,(long)((iVar2 + iVar4) - *param_3));
        *param_3 = iVar4;
        goto LAB_10000a1aa;
      }
      _memcpy(param_2,local_238,(long)iVar2);
      param_2 = param_2 + iVar2;
      iVar2 = _cupsBackChannelRead(DAT_1000104b8,local_238,0x200);
    } while (0 < iVar2);
  }
  if (iVar2 != 0) {
    piVar3 = ___error();
    if (*piVar3 != 0x23) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s getBackChannelRowData read error.\n","DEBUG: "
              );
      *param_3 = 0;
      *param_2 = 0;
      goto LAB_10000a1aa;
    }
  }
  param_2[*param_3] = 0;
LAB_10000a1aa:
  if (*(long *)PTR____stack_chk_guard_100012028 == local_38) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

