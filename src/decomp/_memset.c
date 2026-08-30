// _memset  entry=10000e90e

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _memset(void *param_1,int param_2,size_t param_3)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e90e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__memset_100012268)();
  return pvVar1;
}

