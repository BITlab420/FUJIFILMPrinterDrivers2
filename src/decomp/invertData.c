// invertData  entry=100003ac9

/* invertData(unsigned char*, unsigned char*, short) */

void invertData(uchar *param_1,uchar *param_2,short param_3)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar7;
  byte *pbVar5;
  byte *pbVar6;
  
  uVar4 = (ulong)((uint)(ushort)param_3 >> 3);
  pbVar5 = param_2;
  pbVar6 = param_1;
  if ((short)uVar4 != 0) {
    uVar4 = (ulong)((int)uVar4 - 1U & 0xffff);
    pbVar5 = param_2 + uVar4 * 8 + 8;
    pbVar6 = param_1 + uVar4 * 8 + 8;
    uVar3 = -((uint)(int)param_3 >> 3);
    do {
      _memcpy(&uVar7,param_1,8);
      param_1 = (uchar *)((long)param_1 + 8);
      uVar7 = ~uVar7;
      _memcpy(param_2,&uVar7,8);
      param_2 = (uchar *)((long)param_2 + 8);
      uVar2 = (short)uVar3 + 1;
      uVar3 = (uint)uVar2;
    } while (uVar2 != 0);
  }
  if ((param_3 & 7U) != 0) {
    uVar3 = -((uint)(ushort)param_3 & 7);
    do {
      bVar1 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      *pbVar5 = ~bVar1;
      pbVar5 = pbVar5 + 1;
      uVar2 = (short)uVar3 + 1;
      uVar3 = (uint)uVar2;
    } while (uVar2 != 0);
  }
  return;
}

