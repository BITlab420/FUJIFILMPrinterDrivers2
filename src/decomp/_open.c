// _open  entry=10000e91a

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _open(char *param_1,int param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e91a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__open_100012278)();
  return iVar1;
}

