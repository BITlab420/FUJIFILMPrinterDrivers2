// _strstr  entry=10000e98c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strstr(char *param_1,char *param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e98c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strstr_100012310)();
  return pcVar1;
}

