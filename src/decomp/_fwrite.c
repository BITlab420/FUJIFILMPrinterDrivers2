// _fwrite  entry=10000e8ea

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fwrite(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fwrite_100012238)();
  return sVar1;
}

