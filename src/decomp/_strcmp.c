// _strcmp  entry=10000e974

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _strcmp(char *param_1,char *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e974. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__strcmp_1000122f0)();
  return iVar1;
}

