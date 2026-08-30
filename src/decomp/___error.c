// ___error  entry=10000e8ae

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int * ___error(void)

{
  int *piVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  piVar1 = (int *)(*(code *)PTR____error_1000121e8)();
  return piVar1;
}

