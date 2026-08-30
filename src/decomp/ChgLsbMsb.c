// ChgLsbMsb  entry=10000493c

/* ChgLsbMsb(char*, char*, long) */

void ChgLsbMsb(char *param_1,char *param_2,long param_3)

{
  byte bVar1;
  byte bVar2;
  
  if (0 < param_3) {
    do {
      bVar1 = *param_1;
      bVar2 = (bVar1 & 2) << 5 |
              (bVar1 & 4) << 3 |
              bVar1 * '\x02' & 0x10 | bVar1 >> 1 & 8 | bVar1 >> 3 & 4 | bVar1 >> 5 & 2 | bVar1 >> 7;
      if ((bVar1 & 1) != 0) {
        bVar2 = bVar2 ^ 0x80;
      }
      *param_2 = bVar2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

