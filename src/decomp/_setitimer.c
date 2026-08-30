// _setitimer  entry=10000e944

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _setitimer(int param_1,itimerval *param_2,itimerval *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e944. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__setitimer_1000122b0)();
  return iVar1;
}

