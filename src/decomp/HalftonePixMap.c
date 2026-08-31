// HalftonePixMap  entry=1000033f4

/* HalftonePixMap(long, unsigned char*, long) */

undefined8 HalftonePixMap(long param_1,uchar *param_2,long param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  short sVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  uchar *puVar8;
  byte *pbVar9;
  uchar *puVar10;
  
  if (0 < (int)param_1 << 0x10) {
    sVar4 = 0;
    puVar8 = param_2;
    do {
      DAT_100016a88 = DAT_100016a88 + 1;
      if (sVar4 == 0 || _lMatrixRow <= DAT_100016a88) {
        DAT_100016a88 = 0;
      }
      if (0 < (int)param_3 << 0x10) {
        pbVar9 = (byte *)((ulong)(DAT_100016a88 * _lMatrixRow) + _pMatrixRow);
        uVar1 = 0x8000000000000000;
        uVar5 = 0x80000000;
        lVar7 = 0;
        uVar6 = 0;
        puVar10 = param_2;
        do {
          uVar3 = uVar6 | uVar1;
          if (*pbVar9 < puVar8[lVar7]) {
            uVar6 = uVar3;
          }
          if (puVar8[lVar7] == 0xff) {
            uVar6 = uVar3;
          }
          uVar1 = uVar1 >> 1;
          if (uVar1 == 0) {
            uVar2 = TranslMotorolaLong(uVar6);
            _memcpy(puVar10,&uVar2,8);
            puVar10 = puVar10 + 8;
            uVar1 = 0x8000000000000000;
            uVar6 = 0;
          }
          uVar5 = uVar5 >> 1;
          if (uVar5 == 0) {
            pbVar9 = (byte *)((ulong)(_lMatrixRow * DAT_100016a88) + _pMatrixRow);
            uVar5 = 0x80000000;
          }
          else {
            pbVar9 = pbVar9 + 1;
          }
          lVar7 = lVar7 + 1;
        } while ((short)lVar7 < (short)param_3);
        if (uVar1 != 0x8000000000000000) {
          uVar2 = TranslMotorolaLong(uVar6);
          _memcpy(puVar10,&uVar2,8);
        }
      }
      puVar8 = puVar8 + param_3;
      param_2 = param_2 + (int)((int)(((int)param_3 + 7U & 0xfffffff8) * 0x2000 + 0x30000) >> 0x10 &
                               0xfffffffc);
      sVar4 = sVar4 + 1;
    } while (sVar4 < (short)param_1);
  }
  return 0;
}

