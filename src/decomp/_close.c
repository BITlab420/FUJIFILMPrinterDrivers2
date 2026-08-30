// _close  entry=10000e8cc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _close(int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__close_100012210)();
  return iVar1;
}

