// clearData  entry=100003a84

/* clearData(unsigned char*, short) */

void clearData(uchar *param_1,short param_2)

{
  ulong uVar1;
  ulong uVar2;
  undefined6 in_register_00000032;
  uchar *puVar3;
  
  uVar2 = CONCAT62(in_register_00000032,param_2) & 0xffffffff;
  uVar1 = uVar2 >> 3;
  puVar3 = param_1;
  if ((short)uVar1 != 0) {
    uVar1 = (ulong)((int)uVar1 - 1U & 0xffff);
    puVar3 = param_1 + uVar1 * 8 + 8;
    ___bzero(param_1,uVar1 * 8 + 8);
  }
  if ((param_2 & 7U) != 0) {
    ___bzero(puVar3,(((ushort)uVar2 & 7) - 1 & 0xffff) + 1);
  }
  return;
}

