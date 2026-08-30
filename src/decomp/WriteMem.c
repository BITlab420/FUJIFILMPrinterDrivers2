// WriteMem  entry=10000482e

/* WriteMem(unsigned char*, unsigned char, long, short*) */

long WriteMem(uchar *param_1,uchar param_2,long param_3,short *param_4)

{
  int iVar1;
  short sVar2;
  int *piVar3;
  uchar *puVar4;
  int *piVar5;
  int iVar6;
  long lVar7;
  short sVar8;
  ushort uVar9;
  int iVar10;
  
  if (param_2 == '\0') {
    if (0x3f < param_3) {
      puVar4 = _white_tablee;
      goto LAB_100004898;
    }
    puVar4 = _white_table;
  }
  else {
    if (0x3f < param_3) {
      puVar4 = _black_tablee;
LAB_100004898:
      lVar7 = (long)(((ulong)(param_3 >> 0x3f) >> 0x3a) + param_3) >> 6;
      piVar3 = (int *)(puVar4 + lVar7 * 8 + -8);
      piVar5 = (int *)(puVar4 + lVar7 * 8 + -4);
      goto LAB_1000048a2;
    }
    puVar4 = _black_table;
  }
  piVar3 = (int *)(puVar4 + param_3 * 8);
  piVar5 = (int *)(puVar4 + param_3 * 8 + 4);
LAB_1000048a2:
  iVar6 = (int)*param_4 + *piVar3;
  sVar2 = (short)((int)(((uint)(iVar6 >> 0x1f) >> 0x1d) + iVar6) >> 3);
  sVar8 = (ushort)(0 < iVar6 % 8) + sVar2;
  iVar10 = (8 - (uint)(ushort)*param_4) - *piVar3;
  if (-1 < sVar8) {
    iVar1 = *piVar5;
    iVar6 = (short)((ushort)(0 < iVar6 % 8) + sVar2) * 8 + 8;
    lVar7 = 0;
    do {
      param_1[lVar7] =
           param_1[lVar7] | (byte)((iVar1 << ((byte)iVar10 & 7)) >> ((byte)iVar6 & 0x1f));
      lVar7 = lVar7 + 1;
      iVar6 = iVar6 + -8;
    } while ((int)lVar7 <= (int)sVar8);
  }
  uVar9 = -(short)iVar10 & 7;
  *param_4 = uVar9;
  return (long)(short)(sVar8 + (ushort)(uVar9 == 0));
}

