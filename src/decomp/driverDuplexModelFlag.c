// driverDuplexModelFlag  entry=100007254

/* driverDuplexModelFlag(ppd_file_s*, cups_page_header2_s*, sdata*) */

void driverDuplexModelFlag(ppd_file_s *param_1,cups_page_header2_s *param_2,sdata *param_3)

{
  ushort uVar1;
  
  if (((*(int *)(param_1 + 0x18) == 10) && (*(int *)(param_2 + 0x110) == 1)) &&
     (*(int *)(param_2 + 0x114) == 0x4b0)) {
    uVar1 = *(ushort *)(param_3 + 10);
    *(ushort *)(param_3 + 10) = uVar1 | 0x100;
    if ((1 < *(uint *)(param_2 + 0x154)) && (*(short *)(param_3 + 0x16) == 0)) {
      *(ushort *)(param_3 + 10) = uVar1 | 0x500;
    }
  }
  return;
}

