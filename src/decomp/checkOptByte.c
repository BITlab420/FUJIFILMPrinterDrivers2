// checkOptByte  entry=100003b6b

/* checkOptByte(char*, short, short, unsigned short*) */

void checkOptByte(char *param_1,short param_2,short param_3,ushort *param_4)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  char cVar4;
  
  *param_4 = 1;
  cVar4 = (char)param_2;
  if (*param_1 == -0x80) {
    if (param_2 < 3) {
      *param_1 = cVar4 << 5 | 0x80;
    }
    else if (param_2 == 3) {
      *param_1 = -0x20;
      uVar3 = *param_4;
      *param_4 = uVar3 + 1;
      param_1[uVar3] = '\0';
    }
    else {
      *param_1 = -0x20;
      uVar3 = param_2 - 0x102;
      if ((short)uVar3 < 0) {
        cVar4 = cVar4 + -3;
      }
      else {
        cVar4 = (char)uVar3 + (char)(uVar3 / 0xff);
        do {
          uVar1 = *param_4;
          *param_4 = uVar1 + 1;
          param_1[uVar1] = -1;
          uVar3 = uVar3 - 0xff;
        } while (-1 < (short)uVar3);
      }
      uVar3 = *param_4;
      *param_4 = uVar3 + 1;
      param_1[uVar3] = cVar4;
    }
    sVar2 = param_3 + -2;
    if (sVar2 < 0x1f) {
LAB_100003cd3:
      *param_1 = *param_1 | (byte)sVar2;
      return;
    }
    if (sVar2 != 0x1f) {
      *param_1 = *param_1 | 0x1f;
      uVar3 = param_3 - 0x120;
      if ((short)uVar3 < 0) {
        cVar4 = (char)param_3 + -0x21;
      }
      else {
        cVar4 = (char)uVar3 + (char)(uVar3 / 0xff);
        do {
          uVar1 = *param_4;
          *param_4 = uVar1 + 1;
          param_1[uVar1] = -1;
          uVar3 = uVar3 - 0xff;
        } while (-1 < (short)uVar3);
      }
LAB_100003d34:
      uVar3 = *param_4;
      *param_4 = uVar3 + 1;
      param_1[uVar3] = cVar4;
      return;
    }
    *param_1 = *param_1 | 0x1f;
  }
  else {
    if (param_2 < 0xf) {
      *param_1 = cVar4 << 3;
    }
    else if (param_2 == 0xf) {
      *param_1 = 'x';
      uVar3 = *param_4;
      *param_4 = uVar3 + 1;
      param_1[uVar3] = '\0';
    }
    else {
      *param_1 = 'x';
      uVar3 = param_2 - 0x10e;
      if ((short)uVar3 < 0) {
        cVar4 = cVar4 + -0xf;
      }
      else {
        cVar4 = (char)uVar3 + (char)(uVar3 / 0xff);
        do {
          uVar1 = *param_4;
          *param_4 = uVar1 + 1;
          param_1[uVar1] = -1;
          uVar3 = uVar3 - 0xff;
        } while (-1 < (short)uVar3);
      }
      uVar3 = *param_4;
      *param_4 = uVar3 + 1;
      param_1[uVar3] = cVar4;
    }
    sVar2 = param_3 + -1;
    if (sVar2 < 7) goto LAB_100003cd3;
    if (sVar2 != 7) {
      *param_1 = *param_1 | 7;
      uVar3 = param_3 - 0x107;
      if ((short)uVar3 < 0) {
        cVar4 = (char)param_3 + -8;
      }
      else {
        cVar4 = (char)uVar3 + (char)(uVar3 / 0xff);
        do {
          uVar1 = *param_4;
          *param_4 = uVar1 + 1;
          param_1[uVar1] = -1;
          uVar3 = uVar3 - 0xff;
        } while (-1 < (short)uVar3);
      }
      goto LAB_100003d34;
    }
    *param_1 = *param_1 | 7;
  }
  uVar3 = *param_4;
  *param_4 = uVar3 + 1;
  param_1[uVar3] = '\0';
  return;
}

