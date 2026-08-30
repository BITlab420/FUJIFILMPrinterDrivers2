// sendDriverDuplexCommad  entry=100007181

/* sendDriverDuplexCommad(sdata*) */

undefined2 sendDriverDuplexCommad(sdata *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  char local_438 [1032];
  long local_30;
  
  puVar1 = PTR____stack_chk_guard_100012028;
  local_30 = *(long *)PTR____stack_chk_guard_100012028;
  if (((byte)param_1[0xb] & 1) != 0) {
    iVar2 = _sprintf(local_438,"%s%s","@PJL SET DXBACKSIDEFIRSTSENDMODE=","ON\n");
    iVar3 = _printf("%s",local_438);
    uVar4 = 1;
    if (iVar3 < (short)iVar2) goto LAB_100007233;
    iVar2 = _sprintf(local_438,"%s%s","@PJL SET PCLCONPULSORYFFIGNOREMODE=","ON\n");
    iVar3 = _printf("%s",local_438);
    if (iVar3 < (short)iVar2) goto LAB_100007233;
  }
  uVar4 = 0;
LAB_100007233:
  if (*(long *)puVar1 == local_30) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

