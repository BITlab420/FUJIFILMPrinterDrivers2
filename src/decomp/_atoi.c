// _atoi  entry=10000e8c0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _atoi(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__atoi_100012200)();
  return iVar1;
}

