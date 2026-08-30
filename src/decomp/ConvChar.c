// ConvChar  entry=10000236e

/* ConvChar(unsigned char*, unsigned char, unsigned char*, short) */

void ConvChar(uchar *param_1,uchar param_2,uchar *param_3,short param_4)

{
  byte bVar1;
  
  bVar1 = *param_1;
  if (bVar1 != 0) {
    do {
      if (bVar1 < 0x20) {
        if (param_4 != 0) {
          *param_1 = ' ';
        }
      }
      else if ((byte)(param_2 - 1) < bVar1) {
        *param_1 = param_3[(ulong)bVar1 - (ulong)param_2];
      }
      bVar1 = param_1[1];
      param_1 = param_1 + 1;
    } while (bVar1 != 0);
  }
  return;
}

