// M916MaxLen  entry=10000729e

/* M916MaxLen(unsigned int) */

int M916MaxLen(uint param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 2 + 1;
  if (6 < param_1 - 1) {
    if (0xfe < param_1 - 8) {
      iVar1 = (param_1 - 0x107) / 0xff + 2 + param_1 * 2;
    }
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

