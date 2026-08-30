// _getenv  entry=10000e8f0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_100012240)();
  return pcVar1;
}

