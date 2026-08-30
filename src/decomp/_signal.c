// _signal  entry=10000e950

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00010000e950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_1000122c0)();
  return;
}

