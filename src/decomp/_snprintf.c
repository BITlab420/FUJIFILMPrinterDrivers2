// _snprintf  entry=10000e95c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e95c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_1000122d0)();
  return iVar1;
}

