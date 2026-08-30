// ReverseProcess  entry=10000276f

/* ReverseProcess(unsigned char*, unsigned short, short) */

void ReverseProcess(uchar *param_1,ushort param_2,short param_3)

{
  void *pvVar1;
  uchar *puVar2;
  long lVar3;
  undefined6 in_register_00000012;
  size_t sVar4;
  uint uVar5;
  undefined6 in_register_00000032;
  
  uVar5 = (int)CONCAT62(in_register_00000032,param_2) * (int)CONCAT62(in_register_00000012,param_3);
  sVar4 = (size_t)(int)uVar5;
  pvVar1 = _malloc(sVar4);
  _memcpy(pvVar1,param_1,sVar4);
  ___bzero(param_1,sVar4);
  if (uVar5 != 0 && -1 < (long)((ulong)uVar5 << 0x20)) {
    puVar2 = (uchar *)((sVar4 - 1) + (long)pvVar1);
    lVar3 = 0;
    do {
      param_1[lVar3] = *puVar2;
      lVar3 = lVar3 + 1;
      puVar2 = puVar2 + -1;
    } while (lVar3 < (long)sVar4);
  }
  _free(pvVar1);
  return;
}

