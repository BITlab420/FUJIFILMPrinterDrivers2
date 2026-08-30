// Encode  entry=10000474d

/* Encode(unsigned char*, long*, unsigned char, long, short*) */

void Encode(uchar *param_1,long *param_2,uchar param_3,long param_4,short *param_5)

{
  long lVar1;
  long lVar2;
  
  while( true ) {
    lVar2 = param_4;
    if (0x9ff < param_4) {
      lVar2 = param_4 + -0xa00;
      lVar1 = WriteMem(param_1 + *param_2,param_3,0xa00,param_5);
      *param_2 = *param_2 + lVar1;
    }
    if (lVar2 < 0x40) break;
    param_4 = (long)(short)(lVar2 % 0x40);
    lVar1 = WriteMem(param_1 + *param_2,param_3,lVar2 - param_4,param_5);
    lVar1 = lVar1 + *param_2;
    *param_2 = lVar1;
    if (lVar2 % 0x40 << 0x30 < 0x40000000000000) {
LAB_100004806:
      lVar2 = WriteMem(param_1 + lVar1,param_3,param_4,param_5);
      *param_2 = *param_2 + lVar2;
      return;
    }
  }
  lVar1 = *param_2;
  param_4 = lVar2;
  goto LAB_100004806;
}

