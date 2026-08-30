// MEndJob  entry=1000057f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MEndJob() */

undefined8 MEndJob(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = _printf("%s","\x1b%-12345X@PJL\n");
  uVar2 = 1;
  if (0xd < iVar1) {
    EndJobLogFunc(_gLogJobName);
    iVar1 = _printf("%s","\x1b%-12345X");
    if (8 < iVar1) {
      FreeBlankPageMemory();
      FreePMatrixRow(DAT_100016f30);
      DisposeCompMemory();
      uVar2 = 0;
    }
  }
  return uVar2;
}

