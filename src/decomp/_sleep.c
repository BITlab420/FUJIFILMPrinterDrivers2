// _sleep  entry=10000e956

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _sleep(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000e956. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__sleep_1000122c8)();
  return uVar1;
}

