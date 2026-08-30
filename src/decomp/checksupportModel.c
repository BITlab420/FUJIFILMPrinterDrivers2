// checksupportModel  entry=100006d53

/* checksupportModel(ppd_file_s*) */

undefined8 checksupportModel(ppd_file_s *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffff;
  if (*(int *)(param_1 + 0x18) == 10) {
    uVar1 = 0;
  }
  return uVar1;
}

