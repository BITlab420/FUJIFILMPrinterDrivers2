// MSendBandData_FAX  entry=1000040aa

/* MSendBandData_FAX(cups_page_header2_s*, sdata*) */

undefined8 MSendBandData_FAX(cups_page_header2_s *param_1,sdata *param_2)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uchar *puVar5;
  uint uVar6;
  ulong uVar7;
  cups_page_header2_s *pcVar8;
  size_t sVar9;
  long lVar10;
  
  uVar6 = *(uint *)(param_1 + 0x178);
  if (*(int *)(param_1 + 0x174) == 0) {
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ","Invalid Parameter(s).\n");
  }
  else {
    uVar7 = (ulong)(((*(int *)(param_1 + 0x174) + 7U) >> 3) + 3) & 0xfffc;
    sVar9 = (ulong)uVar6 * 0x438 + uVar7;
    puVar5 = _malloc(sVar9);
    DAT_100016b20 = puVar5;
    if (puVar5 == (uchar *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ","Insufficient memory!\n");
    }
    else {
      ___bzero(puVar5,sVar9);
      DAT_100016b10 = puVar5 + (ulong)uVar6 * 0x360;
      DAT_100016b18 = 0;
      DAT_100016b08 = uVar7;
    }
  }
  lVar10 = (long)*(short *)(param_2 + 4);
  sVar2 = (short)*(undefined4 *)(param_1 + 0x164) - (short)*(undefined4 *)(param_1 + 0x128);
  puVar5 = _Planes;
  if ((sVar2 < 0xc) && (iVar4 = ((short)(0xc - sVar2) * 200) / 0x48, 0 < iVar4 * 0x10000)) {
    sVar3 = (short)iVar4;
    sVar2 = 1;
    do {
      puVar5 = puVar5 + *(uint *)(param_1 + 0x188);
      bVar1 = sVar2 < sVar3;
      sVar2 = sVar2 + 1;
    } while (bVar1);
    lVar10 = lVar10 - sVar3;
  }
  if ((*(uint *)(param_1 + 0x120) < 0xc) &&
     (sVar2 = (short)(((short)(0xc - (short)*(uint *)(param_1 + 0x120)) * 200) / 0x48), 0 < sVar2))
  {
    lVar10 = lVar10 - sVar2;
  }
  DAT_100016b00 = DAT_100016b10 + DAT_100016b08;
  if ((*(int *)(param_1 + 400) != 3) || (lVar10 < 1)) goto LAB_100004340;
  uVar6 = *(uint *)(param_1 + 0x188);
  if (200 < uVar6) {
    puVar5 = puVar5 + ((int)(uVar6 * 0x8000 + -0x640000) >> 0x10);
    uVar6 = 200;
  }
  iVar4 = *(int *)(param_1 + 0x180);
  if (iVar4 == 1) {
LAB_1000042a7:
    DAT_100016b18 = (ushort)uVar6;
  }
  else if (iVar4 == 8) {
    uVar6 = (uVar6 + 7) >> 3;
    goto LAB_1000042a7;
  }
  uVar6 = (uint)DAT_100016b18;
  while( true ) {
    if (iVar4 == 1) {
      copyData(puVar5,DAT_100016b10,DAT_100016b18);
    }
    copyData(DAT_100016b10,
             DAT_100016b00 + (int)(short)(((0xd8 - uVar6) - ((int)(0xd8 - uVar6) >> 0x1f)) >> 1),
             DAT_100016b18);
    DAT_100016b00 = DAT_100016b00 + 0xd8;
    lVar10 = lVar10 + -1;
    if (lVar10 == 0) break;
    iVar4 = *(int *)(param_1 + 0x180);
    puVar5 = puVar5 + *(uint *)(param_1 + 0x188);
  }
LAB_100004340:
  _lFAXDataCnt = 0;
  pcVar8 = (cups_page_header2_s *)(ulong)*(uint *)(param_1 + 0x178);
  RawToG3(0x6c0,*(uint *)(param_1 + 0x178),DAT_100016b10 + DAT_100016b08,DAT_100016b20,&_lFAXDataCnt
          ,1);
  SendPage_FAX((faxcomp *)&DAT_100016b08,pcVar8);
  return 0;
}

