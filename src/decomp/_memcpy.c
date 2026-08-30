// _memcpy  entry=10000e908

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _memcpy(void *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__memcpy_100012260)();
  return pvVar1;
}

