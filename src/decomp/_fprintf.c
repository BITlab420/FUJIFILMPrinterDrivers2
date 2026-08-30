// _fprintf  entry=10000e8de

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fprintf_100012228)();
  return iVar1;
}

