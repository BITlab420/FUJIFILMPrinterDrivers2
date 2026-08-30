// _gmtime  entry=10000e8f6

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * _gmtime(time_t *param_1)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR__gmtime_100012248)();
  return ptVar1;
}

