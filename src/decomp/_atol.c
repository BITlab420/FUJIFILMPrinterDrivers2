// _atol  entry=10000e8c6

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long _atol(char *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)PTR__atol_100012208)();
  return lVar1;
}

