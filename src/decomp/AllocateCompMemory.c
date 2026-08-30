// AllocateCompMemory  entry=10000398d

/* AllocateCompMemory(unsigned long, unsigned long) */

void AllocateCompMemory(ulong param_1,ulong param_2)

{
  ulong uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = param_1 * 5 >> 3;
    DAT_100016aa0 = _malloc(uVar1);
    DAT_100016ac0 = _malloc(uVar1);
  }
  return;
}

