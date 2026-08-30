// NumericLength  entry=100003d43

/* NumericLength(long) */

int NumericLength(long param_1)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  
  iVar3 = 1;
  if (param_1 != 0) {
    lVar1 = -param_1;
    if (-1 < (int)param_1) {
      lVar1 = param_1;
    }
    iVar3 = 0;
    if ((int)lVar1 != 0) {
      lVar1 = (long)(int)lVar1;
      do {
        iVar3 = iVar3 + 1;
        uVar2 = lVar1 + 9;
        lVar1 = lVar1 / 10;
      } while (0x12 < uVar2);
    }
    iVar3 = iVar3 - (int)(param_1 >> 0x3f);
  }
  return iVar3;
}

