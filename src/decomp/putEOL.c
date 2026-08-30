// putEOL  entry=1000045aa

/* putEOL(unsigned char*, long*, short*) */

void putEOL(uchar *param_1,long *param_2,short *param_3)

{
  short sVar1;
  long lVar2;
  byte bVar3;
  
  sVar1 = *param_3;
  if (sVar1 == 0) {
    lVar2 = *param_2;
    *param_2 = lVar2 + 1;
    param_1[lVar2] = '\0';
    param_1[*param_2] = '\x10';
    *param_3 = 4;
  }
  else {
    lVar2 = *param_2;
    *param_2 = lVar2 + 1;
    param_1[lVar2] = param_1[lVar2] | (byte)(0x10 >> ((char)sVar1 + 8U & 0x1f));
    bVar3 = (byte)(0x10 >> ((byte)*param_3 & 0x1f));
    if (sVar1 < 4) {
      param_1[*param_2] = bVar3;
      *param_3 = *param_3 + 4;
    }
    else {
      lVar2 = *param_2;
      *param_2 = lVar2 + 1;
      param_1[lVar2] = param_1[lVar2] | bVar3;
      param_1[*param_2] = (uchar)(0x10 << (8U - (char)*param_3 & 0x1f));
      *param_3 = *param_3 + -4;
    }
  }
  return;
}

