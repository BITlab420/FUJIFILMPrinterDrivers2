// checkZero  entry=100003b27

/* checkZero(unsigned char*, short) */

undefined2 checkZero(uchar *param_1,short param_2)

{
  long lVar1;
  int iVar2;
  ushort uVar3;
  
  iVar2 = (int)((uint)(ushort)param_2 >> 1);
  if (0 < iVar2) {
    lVar1 = 0;
    do {
      _memcpy(&uVar3,param_1 + lVar1 * 2,2);
      if (uVar3 != 0) {
        return 0;
      }
      lVar1 = lVar1 + 1;
    } while ((short)lVar1 < iVar2);
  }
  return 1;
}

