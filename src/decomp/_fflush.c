// _fflush  entry=10000e8d8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100012220)();
  return iVar1;
}

