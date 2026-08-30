// MSendBandData  entry=100005b5a

/* MSendBandData(cups_page_header2_s*, sdata*) */

int MSendBandData(cups_page_header2_s *param_1,sdata *param_2)

{
  char cVar1;
  bool bVar2;
  byte *pbVar3;
  byte bVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  ulong uVar13;
  int iVar14;
  short sVar15;
  uint uVar16;
  uint uVar17;
  ushort *puVar18;
  long lVar19;
  ulong *puVar20;
  short sVar21;
  short sVar22;
  byte *pbVar23;
  ushort uVar24;
  int iVar25;
  long lVar26;
  int iVar27;
  uint uVar28;
  ushort *puVar29;
  short sVar30;
  long local_68;
  union { ushort w; byte _0_1_; byte _1_1_; } local_5d [2];
  ulong local_58;
  ulong local_50 [3];
  ushort local_32;
  
  local_68 = 1;
  if ((*(ushort *)(param_2 + 10) & 1) != 0) {
LAB_100005ba6:
    sVar5 = 0;
    goto LAB_100005ba8;
  }
  if ((*(ushort *)(param_2 + 10) & 0x300) == 0x100) {
    sVar5 = checkdriverduplexPage(param_2);
    if (sVar5 == 1) goto LAB_100005ba6;
  }
  else {
    sVar5 = 0;
  }
  if (((byte)param_2[0x14] & 2) != 0) {
    ReverseProcess((uchar *)_Planes,*(ushort *)(param_1 + 0x188),*(short *)(param_2 + 4));
  }
  if (*(int *)(param_1 + 0x180) == 8) {
    sVar5 = HalftonePixMap((long)*(short *)(param_2 + 4),(uchar *)_Planes,
                           (ulong)*(uint *)(param_1 + 0x174));
    if (sVar5 != 0) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"ERROR: Sending line No.%d failed!\n",
               (ulong)(uint)(int)*(short *)(param_2 + 4));
      goto LAB_100005ba8;
    }
    _compData = _Planes;
    if (*(int *)(param_1 + 0x180) != 8) {
      sVar5 = 0;
      goto LAB_100005cb2;
    }
    DAT_100016a98 =
         (ushort)((*(int *)(param_1 + 0x174) + 7U & 0xfffffff8) * 0x2000 + 0x30000 >> 0x10) & 0xfffc
    ;
    sVar5 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x180) != 1) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ","Unsupported data format!\n");
      goto LAB_100005ba8;
    }
LAB_100005cb2:
    DAT_100016a98 = *(ushort *)(param_1 + 0x188);
    _compData = _Planes;
  }
  _Planes = _compData;
  if (*(int *)(param_1 + 400) == 3) {
    if ((*(short *)(param_2 + 8) == 0) && (0 < (short)DAT_100016a54)) {
      uVar10 = ~DAT_100016a54;
      sVar6 = sVar5;
      do {
        uVar10 = uVar10 + 1;
        sVar5 = sVar6;
        if (uVar10 == 0) goto LAB_100005d2d;
        local_68 = 1;
        sVar5 = SaveDumb(&local_68,(uchar *)s__10000f7d6);
        sVar6 = 0;
      } while (sVar5 == 0);
    }
    else {
LAB_100005d2d:
      if (((byte)param_2[0x14] & 4) == 0) {
        if (0 < *(short *)(param_2 + 4)) {
          lVar26 = 0;
          puVar29 = _Planes;
          do {
            local_50[2] = (ulong)DAT_100016a98;
            _compData = puVar29;
            sVar6 = checkZero((uchar *)puVar29,DAT_100016a98);
            if (sVar6 == 0) {
              if ((((byte)DAT_100016a80 & 0x7f) == 0) ||
                 ((lVar26 == 0 && (*(short *)(param_2 + 8) == 0)))) {
                DAT_100016ab0 =
                     (ushort *)
                     ((long)DAT_100016aa0 +
                     (ulong)(((int)(short)DAT_100016a98 & 0xfffeU) >> 1) + (ulong)DAT_100016a98 * 2)
                ;
                DAT_100016ab8 = DAT_100016a98;
                invertData((uchar *)_compData,(uchar *)DAT_100016ab0,DAT_100016a98);
              }
              pbVar3 = DAT_100016ac0;
              uVar16 = *(uint *)(param_1 + 0x174) >> 3;
              uVar11 = *(uint *)(param_1 + 0x174) & 7;
              iVar27 = (uVar11 != 0) + uVar16;
              sVar6 = (short)iVar27;
              iVar25 = (int)sVar6;
              iVar12 = (int)(short)DAT_100016ab8;
              puVar18 = DAT_100016aa0;
              iVar14 = iVar12;
              while (DAT_100016aa0 = puVar18, iVar14 < iVar25) {
                *(byte *)((long)DAT_100016ab0 + (long)(short)iVar12) = 0;
                iVar12 = iVar12 + 1;
                puVar18 = DAT_100016aa0;
                iVar14 = (int)(short)iVar12;
              }
              DAT_100016aa8 = 0;
              *(byte *)puVar18 = 0;
              sVar15 = _margins;
              DAT_100016aa8 = DAT_100016aa8 + 1;
              pbVar23 = (byte *)((long)puVar18 + 1);
              if (0 < _margins) {
                *pbVar3 = 0x80;
                checkOptByte((char *)pbVar3,0,sVar15,&local_32);
                uVar13 = (ulong)local_32;
                local_32 = local_32 + 1;
                pbVar3[uVar13] = 0;
                setCommand((char *)pbVar3,pbVar23,local_32);
                *(byte *)puVar18 = (byte)*puVar18 + 1;
                DAT_100016aa8 = DAT_100016aa8 + local_32;
                pbVar23 = (byte *)((long)puVar18 + (ulong)local_32 + 1);
              }
              uVar10 = DAT_100016aa8;
              if (0 < iVar27 * 0x10000) {
                iVar12 = 0;
                bVar2 = true;
                sVar15 = 0;
                do {
                  if (0xfc < (byte)*puVar18) {
                    *pbVar3 = 0;
                    checkOptByte((char *)pbVar3,0,sVar6 - (short)iVar12,&local_32);
                    uVar11 = -((uVar16 + (uVar11 != 0)) - iVar12);
                    do {
                      lVar19 = (long)sVar15;
                      sVar15 = sVar15 + 1;
                      uVar13 = (ulong)local_32;
                      local_32 = local_32 + 1;
                      pbVar3[uVar13] = *(byte *)((long)_compData + lVar19);
                      uVar10 = (short)uVar11 + 1;
                      uVar11 = (uint)uVar10;
                    } while (uVar10 != 0);
                    setCommand((char *)pbVar3,pbVar23,local_32);
                    *(byte *)puVar18 = (byte)*puVar18 + 1;
                    DAT_100016aa8 = DAT_100016aa8 + local_32;
                    uVar10 = DAT_100016aa8;
                    break;
                  }
                  uVar24 = 0xfef2;
                  sVar30 = sVar15;
                  while (lVar19 = (long)(short)(sVar15 + 0x10e + uVar24),
                        *(byte *)((long)_compData + lVar19) ==
                        *(byte *)((long)DAT_100016ab0 + lVar19)) {
                    sVar30 = sVar30 + 1;
                    sVar7 = sVar15 + 0x10f + uVar24;
                    uVar24 = uVar24 + 1;
                    if (iVar25 <= sVar7) {
                      if (!bVar2) goto LAB_10000660e;
                      DAT_100016aa8 = 0;
                      local_50[2] = 0;
                      goto LAB_100006626;
                    }
                  }
                  sVar7 = sVar15 + 0x10e + uVar24;
                  sVar22 = uVar24 + 0x10e;
                  iVar12 = 0;
                  sVar21 = 0;
                  sVar9 = 1;
                  if (sVar7 < iVar25) {
                    do {
                      sVar21 = sVar9;
                      sVar8 = sVar30 + sVar21;
                      if (iVar25 <= sVar8) break;
                      sVar9 = sVar21 + 1;
                    } while (*(byte *)((long)_compData + (long)sVar8) !=
                             *(byte *)((long)DAT_100016ab0 + (long)sVar8));
                    iVar12 = (int)sVar21;
                    if (sVar21 < 3) goto LAB_1000063b2;
                    iVar12 = iVar12 + sVar7;
                    do {
                      iVar14 = (int)sVar7;
                      uVar28 = iVar12 - iVar14;
                      if (uVar28 == 0 || iVar12 < iVar14) goto LAB_100006510;
                      local_32 = 0;
                      uVar17 = iVar14 + 2;
                      if ((int)uVar17 < iVar12) {
                        sVar9 = (short)uVar17;
                        if ((*(byte *)((long)_compData + (long)sVar7) !=
                             *(byte *)((long)_compData + (long)(iVar14 + 1))) ||
                           (*(byte *)((long)_compData + (long)sVar7) !=
                            *(byte *)((long)_compData + (long)(int)uVar17))) {
                          uVar17 = 2;
                          uVar28 = 2;
                          for (; iVar14 = (int)sVar9, iVar14 < iVar12; sVar9 = sVar7 + 1 + sVar9) {
                            bVar4 = *(byte *)((long)_compData + (long)(iVar14 + -2));
                            sVar9 = (short)uVar17;
                            if ((bVar4 == *(byte *)((long)_compData + (long)(iVar14 + -1))) &&
                               (bVar4 == *(byte *)((long)_compData + (long)(short)(sVar7 + sVar9))))
                            {
                              uVar28 = uVar17 - 2 & 0xffff;
                              break;
                            }
                            uVar28 = uVar17 + 1;
                            uVar17 = uVar28 & 0xffff;
                          }
                          goto LAB_1000062d7;
                        }
                        iVar14 = (int)sVar9;
                        sVar9 = 2;
                        if (iVar14 < iVar12) {
                          do {
                            if (*(byte *)((long)_compData + (long)(iVar14 + -1)) !=
                                *(byte *)((long)_compData + (long)(short)(sVar7 + sVar9))) break;
                            sVar8 = sVar7 + 1 + sVar9;
                            sVar9 = sVar9 + 1;
                            iVar14 = (int)sVar8;
                          } while (iVar14 < iVar12);
                          uVar17 = (uint)(ushort)(sVar7 + sVar9);
                        }
                        *pbVar3 = 0x80;
                        checkOptByte((char *)pbVar3,sVar22,sVar9,&local_32);
                        uVar13 = (ulong)local_32;
                        local_32 = local_32 + 1;
                        pbVar3[uVar13] = *(byte *)((long)_compData + (long)(iVar14 + -1));
                        sVar7 = (short)uVar17;
                      }
                      else {
LAB_1000062d7:
                        *pbVar3 = 0;
                        sVar8 = (short)uVar28;
                        checkOptByte((char *)pbVar3,sVar22,sVar8,&local_32);
                        sVar9 = sVar8;
                        sVar22 = sVar7;
                        do {
                          lVar19 = (long)sVar22;
                          sVar22 = sVar22 + 1;
                          uVar13 = (ulong)local_32;
                          local_32 = local_32 + 1;
                          pbVar3[uVar13] = *(byte *)((long)_compData + lVar19);
                          sVar9 = sVar9 + -1;
                        } while (sVar9 != 0);
                        sVar7 = sVar8 + sVar7;
                      }
                      setCommand((char *)pbVar3,pbVar23,local_32);
                      *(byte *)puVar18 = (byte)*puVar18 + 1;
                      DAT_100016aa8 = DAT_100016aa8 + local_32;
                      pbVar23 = pbVar23 + local_32;
                      sVar22 = 0;
                      uVar10 = DAT_100016aa8;
                    } while ((byte)*puVar18 != 0xfd);
                    sVar21 = sVar7 - sVar30;
                  }
                  else {
LAB_1000063b2:
                    cVar1 = (char)iVar12;
                    if (sVar22 < 0xf) {
                      local_32 = 1;
                      *pbVar3 = cVar1 - 1U | (char)sVar22 * '\b';
                      sVar7 = 0;
                    }
                    else {
                      if (uVar24 == 0xff01) {
                        *pbVar3 = cVar1 - 1U | 0x78;
                        local_32 = 2;
                        pbVar3[1] = 0;
                      }
                      else {
                        local_32 = 1;
                        *pbVar3 = cVar1 - 1U | 0x78;
                        uVar10 = uVar24;
                        if ((short)uVar24 < 0) {
                          bVar4 = (char)uVar24 - 1;
                        }
                        else {
                          do {
                            uVar13 = (ulong)local_32;
                            local_32 = local_32 + 1;
                            pbVar3[uVar13] = 0xff;
                            uVar10 = uVar10 - 0xff;
                          } while (-1 < (short)uVar10);
                          bVar4 = (char)uVar24 + (char)(uVar24 / 0xff);
                        }
                        uVar13 = (ulong)local_32;
                        local_32 = local_32 + 1;
                        pbVar3[uVar13] = bVar4;
                      }
                      sVar7 = 0;
                    }
                    do {
                      uVar13 = (ulong)local_32;
                      local_32 = local_32 + 1;
                      pbVar3[uVar13] = *(byte *)((long)_compData + (long)(short)(sVar30 + sVar7));
                      sVar7 = sVar7 + 1;
                    } while (sVar21 != sVar7);
                    setCommand((char *)pbVar3,pbVar23,local_32);
                    *(byte *)puVar18 = (byte)*puVar18 + 1;
                    DAT_100016aa8 = DAT_100016aa8 + local_32;
                    pbVar23 = pbVar23 + local_32;
                    uVar10 = DAT_100016aa8;
                  }
LAB_100006510:
                  sVar15 = uVar24 + 0x10e + sVar21 + sVar15;
                  iVar12 = (int)sVar15;
                  bVar2 = false;
                } while (iVar12 < iVar25);
              }
LAB_10000660e:
              local_50[2] = (ulong)uVar10;
              if (uVar10 == 0) {
LAB_100006626:
                local_5d[0].w = local_5d[0].w & 0xff00;
                goto LAB_100006632;
              }
              puVar20 = local_50 + 2;
              puVar18 = DAT_100016aa0;
            }
            else {
              local_5d[0].w = CONCAT11(local_5d[0]._1_1_,0xff);
LAB_100006632:
              local_50[1] = 1;
              puVar20 = local_50 + 1;
              puVar18 = (ushort *)local_5d;
            }
            SaveDumb((long *)puVar20,(uchar *)puVar18);
            iVar12 = *(int *)(param_1 + 0x114);
            if (iVar12 == 0x96) {
              local_50[1] = 1;
              local_5d[0].w = local_5d[0].w & 0xff00;
              SaveDumb((long *)(local_50 + 1),(uchar *)local_5d);
              iVar12 = *(int *)(param_1 + 0x114);
            }
            DAT_100016ab0 = _compData;
            uVar13 = (ulong)DAT_100016a98;
            DAT_100016ab8 = DAT_100016a98;
            if (iVar12 == 0x96) {
              DAT_100016ab0 =
                   (ushort *)((long)DAT_100016aa0 + (ulong)(DAT_100016a98 >> 1) + uVar13 * 2);
              copyData((uchar *)_compData,(uchar *)DAT_100016ab0,DAT_100016a98);
            }
            puVar29 = (ushort *)((long)puVar29 + uVar13);
            lVar26 = lVar26 + 1;
          } while (lVar26 < *(short *)(param_2 + 4));
        }
      }
      else if (0 < *(short *)(param_2 + 4)) {
        lVar26 = 0;
        puVar29 = _Planes;
        do {
          local_50[0] = (ulong)DAT_100016a98;
          _compData = puVar29;
          DAT_100016f38 = lVar26;
          sVar6 = checkZero((uchar *)puVar29,DAT_100016a98);
          if (sVar6 == 0) {
            if ((((byte)DAT_100016a80 & 0x7f) == 0) ||
               ((lVar26 == 0 && (*(short *)(param_2 + 8) == 0)))) {
              DAT_100016ab0 =
                   (ushort *)
                   ((long)DAT_100016aa0 +
                   (ulong)(((int)(short)DAT_100016a98 & 0xfffeU) >> 1) + (ulong)DAT_100016a98 * 2);
              DAT_100016ab8 = DAT_100016a98;
              invertData((uchar *)_compData,(uchar *)DAT_100016ab0,DAT_100016a98);
            }
            puVar18 = (ushort *)0x0;
            if (DAT_100016f38 != 0) {
              puVar18 = DAT_100016ab0;
            }
            DAT_100016aa8 =
                 EncodeBAND_MODE9_16bit
                           (_compData,puVar18,(uchar *)DAT_100016aa0,
                            (DAT_100016a98 & 1) + (uint)(DAT_100016a98 >> 1),1,
                            (int)_margins / 2 + ((int)_margins & 1U),
                            (*(uint *)(param_1 + 0x188) >> 1) + (*(uint *)(param_1 + 0x188) & 1));
            local_50[0] = (ulong)DAT_100016aa8;
            if (DAT_100016aa8 == 0) {
              local_5d[0].w = 0;
              goto LAB_100005e74;
            }
            puVar20 = local_50;
            puVar18 = DAT_100016aa0;
          }
          else {
            local_5d[0].w = 0xffff;
LAB_100005e74:
            local_58 = 2;
            puVar20 = &local_58;
            puVar18 = (ushort *)local_5d;
          }
          SaveDumb((long *)puVar20,(uchar *)puVar18);
          iVar12 = *(int *)(param_1 + 0x114);
          if (iVar12 == 0x96) {
            local_58 = 2;
            local_5d[0].w = 0;
            SaveDumb((long *)&local_58,(uchar *)local_5d);
            iVar12 = *(int *)(param_1 + 0x114);
          }
          DAT_100016ab0 = _compData;
          uVar13 = (ulong)DAT_100016a98;
          DAT_100016ab8 = DAT_100016a98;
          if (iVar12 == 0x96) {
            DAT_100016ab0 =
                 (ushort *)((long)DAT_100016aa0 + (ulong)(DAT_100016a98 >> 1) + uVar13 * 2);
            copyData((uchar *)_compData,(uchar *)DAT_100016ab0,DAT_100016a98);
          }
          puVar29 = (ushort *)((long)puVar29 + uVar13);
          lVar26 = lVar26 + 1;
        } while (lVar26 < *(short *)(param_2 + 4));
      }
    }
  }
LAB_100005ba8:
  return (int)sVar5;
}

