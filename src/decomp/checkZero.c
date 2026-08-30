// checkZero  entry=100003b27

/* checkZero(unsigned char*, short) */

undefined2 checkZero(uchar *param_1,short param_2)

{
  long lVar1;
  int iVar2;
  undefined6 in_register_00000032;
  
  iVar2 = (int)CONCAT62(in_register_00000032,param_2) >> 1;
  if (0 < iVar2) {
    lVar1 = 0;
    do {
      if (*(short *)(param_1 + lVar1 * 2) != 0) {
        return 0;
      }
      lVar1 = lVar1 + 1;
    } while ((short)lVar1 < iVar2);
  }
  return 1;
}

