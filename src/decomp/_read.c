// _read  entry=10000e938

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t _read(int param_1,void *param_2,size_t param_3)

{
  ssize_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e938. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__read_1000122a0)();
  return sVar1;
}

