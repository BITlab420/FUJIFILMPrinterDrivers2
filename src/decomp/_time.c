// _time  entry=10000e992

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t _time(time_t *param_1)

{
  time_t tVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e992. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  tVar1 = (*(code *)PTR__time_100012318)();
  return tVar1;
}

