// _puts  entry=10000e932

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e932. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100012298)();
  return iVar1;
}

