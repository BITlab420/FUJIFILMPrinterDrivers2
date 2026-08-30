// SendSecurePrintPJL  entry=100001cda

/* SendSecurePrintPJL(unsigned char*, unsigned char*, char const*) */

undefined8 SendSecurePrintPJL(uchar *param_1,uchar *param_2,char *param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  undefined8 uVar6;
  undefined1 auStack_84f8 [32760];
  undefined4 local_500;
  undefined1 local_4fc;
  undefined8 local_4f8;
  undefined8 uStack_4f0;
  undefined8 local_4e8;
  undefined8 uStack_4e0;
  undefined8 local_4d8;
  undefined8 uStack_4d0;
  undefined8 local_4c8;
  undefined8 uStack_4c0;
  undefined8 local_4b8;
  undefined8 uStack_4b0;
  undefined1 local_4a8;
  undefined8 local_498;
  undefined8 uStack_490;
  undefined8 local_488;
  undefined8 uStack_480;
  undefined8 local_478;
  undefined8 uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  undefined1 local_448;
  char local_438 [1024];
  long local_38;
  
  puVar1 = PTR____stack_chk_guard_100012028;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  if (((param_2 == (uchar *)0x0) || (param_1 == (uchar *)0x0)) || (param_3 == (char *)0x0)) {
    iVar2 = _printf("%s","@PJL SET HOLD=OFF\n");
    uVar6 = 1;
    if (iVar2 < 0x12) goto LAB_100001fe7;
    iVar2 = _sprintf(local_438,"@PJL SET JOBNAME=\"%s\"\n",_gLogJobName);
    iVar3 = _printf("%s",local_438);
    if (iVar3 < iVar2) goto LAB_100001fe7;
    iVar2 = _sprintf(local_438,"@PJL SET USERNAME=\"%s\"\n",_gLoginUserName);
    iVar3 = _printf("%s",local_438);
    if (iVar3 < iVar2) goto LAB_100001fe7;
  }
  else {
    local_458 = 0;
    uStack_450 = 0;
    local_468 = 0;
    uStack_460 = 0;
    local_478 = 0;
    uStack_470 = 0;
    local_488 = 0;
    uStack_480 = 0;
    local_498 = 0;
    uStack_490 = 0;
    local_448 = 0;
    local_4b8 = 0;
    uStack_4b0 = 0;
    local_4c8 = 0;
    uStack_4c0 = 0;
    local_4d8 = 0;
    uStack_4d0 = 0;
    local_4e8 = 0;
    uStack_4e0 = 0;
    local_4f8 = 0;
    uStack_4f0 = 0;
    local_4a8 = 0;
    local_4fc = 0;
    local_500 = 0;
    sVar4 = _strlen((char *)param_2);
    sVar5 = 0x50;
    if ((short)sVar4 < 0x51) {
      sVar5 = (size_t)(short)sVar4;
    }
    _memcpy(&local_498,param_2,sVar5);
    *(undefined1 *)((long)&local_498 + sVar5) = 0;
    sVar4 = _strlen((char *)param_1);
    sVar5 = 0x50;
    if ((short)sVar4 < 0x51) {
      sVar5 = (size_t)(short)sVar4;
    }
    _memcpy(&local_4f8,param_1,sVar5);
    *(undefined1 *)((long)&local_4f8 + sVar5) = 0;
    local_500 = *(undefined4 *)param_3;
    local_4fc = 0;
    iVar2 = _printf("%s","@PJL SET COLLATE=OFF\n");
    uVar6 = 1;
    if (iVar2 < 0x15) goto LAB_100001fe7;
    iVar2 = _sprintf(local_438,"@PJL COPIES=%d\n",1);
    iVar3 = _printf("%s",local_438);
    if (((iVar3 < (short)iVar2) || (iVar2 = _printf("%s","@PJL SET HOLD=STORE\n"), iVar2 < 0x14)) ||
       (iVar2 = _printf("%s","@PJL SET HOLDTYPE=PRIVATE\n"), iVar2 < 0x1a)) goto LAB_100001fe7;
    iVar2 = _sprintf(local_438,"@PJL SET HOLDKEY=%s\n",&local_500);
    iVar3 = _printf("%s",local_438);
    if (iVar3 < (short)iVar2) goto LAB_100001fe7;
    iVar2 = _sprintf(local_438,"@PJL SET JOBNAME=\"%s\"\n",&local_4f8);
    iVar3 = _printf("%s",local_438);
    if (iVar3 < (short)iVar2) goto LAB_100001fe7;
    iVar2 = _sprintf(local_438,"@PJL SET USERNAME=\"%s\"\n",&local_498);
    iVar3 = _printf("%s",local_438);
    if (iVar3 < (short)iVar2) goto LAB_100001fe7;
  }
  uVar6 = 0;
LAB_100001fe7:
  if (*(long *)puVar1 != local_38) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return uVar6;
}

