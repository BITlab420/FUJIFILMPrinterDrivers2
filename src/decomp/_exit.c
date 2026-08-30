// _exit  entry=10000e8d2

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00010000e8d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100012218)();
  return;
}

