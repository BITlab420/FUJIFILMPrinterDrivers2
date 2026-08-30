// _strncmp  entry=10000e986

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _strncmp(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e986. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__strncmp_100012308)();
  return iVar1;
}

