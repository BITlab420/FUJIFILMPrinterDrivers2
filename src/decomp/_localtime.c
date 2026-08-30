// _localtime  entry=10000e8fc

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * _localtime(time_t *param_1)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e8fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR__localtime_100012250)();
  return ptVar1;
}

