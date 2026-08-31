// ConvString  entry=100001b97

/* ConvString(unsigned char*, short, short) */

void ConvString(uchar *param_1,short param_2,short param_3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = (int)(uint)(ushort)param_3;
  if (iVar2 == 0x4e4) {
    bVar1 = *param_1;
    while (bVar1 != 0) {
      if (bVar1 < 0x20) {
        if (param_2 != 0) {
          *param_1 = 0x20;
        }
      }
      else if (0x9f < bVar1) {
        *param_1 = *(byte *)((long)&cf_plist.field1_0x8 + (ulong)bVar1);
      }
      bVar1 = param_1[1];
      param_1 = param_1 + 1;
    }
  }
  else if (iVar2 == 0x4e3) {
    bVar1 = *param_1;
    while (bVar1 != 0) {
      if (bVar1 < 0x20) {
        if (param_2 != 0) {
          *param_1 = 0x20;
        }
      }
      else if ((char)bVar1 < '\0') {
        *param_1 = _tblISO88592[bVar1];
      }
      bVar1 = param_1[1];
      param_1 = param_1 + 1;
    }
  }
  else if (iVar2 == 0x4e2) {
    bVar1 = *param_1;
    while (bVar1 != 0) {
      if (bVar1 < 0x20) {
        if (param_2 != 0) {
          *param_1 = 0x20;
        }
      }
      else if ((char)bVar1 < '\0') {
        *param_1 = *(byte *)((long)&cf__warning.field1_0x8 + (ulong)bVar1);
      }
      bVar1 = param_1[1];
      param_1 = param_1 + 1;
    }
  }
  else {
    bVar1 = *param_1;
    while (bVar1 != 0) {
      if ((bVar1 < 0x20) && (param_2 != 0)) {
        *param_1 = 0x20;
      }
      bVar1 = param_1[1];
      param_1 = param_1 + 1;
    }
  }
  return;
}

