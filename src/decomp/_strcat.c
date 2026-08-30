// _strcat  entry=10000e96e

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strcat(char *param_1,char *param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e96e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strcat_1000122e8)();
  return pcVar1;
}

