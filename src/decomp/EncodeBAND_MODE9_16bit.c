// EncodeBAND_MODE9_16bit  entry=1000072d4

/* EncodeBAND_MODE9_16bit(unsigned short*, unsigned short*, unsigned char*, int, int, unsigned int,
   int) */

ulong EncodeBAND_MODE9_16bit
                (ushort *param_1,ushort *param_2,uchar *param_3,int param_4,int param_5,uint param_6
                ,int param_7)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  ushort *puVar14;
  ulong uVar15;
  byte *pbVar16;
  uint uVar17;
  size_t sVar18;
  ushort uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  ushort *puVar23;
  long lVar24;
  byte bVar25;
  int iVar26;
  long lVar27;
  ulong uVar28;
  uint uVar29;
  ushort *puVar30;
  uchar *puVar31;
  uint uVar32;
  byte *pbVar33;
  int iVar34;
  uint uVar35;
  int iVar36;
  int iVar37;
  byte bVar38;
  uint uVar39;
  ushort uVar40;
  ushort uVar41;
  byte *local_b80;
  uint local_ab4;
  int local_aa4;
  byte *local_aa0;
  uint local_a6c;
  ushort *local_a60;
  byte *local_a58;
  union { ulong q; uint _0_4_; byte _0_1_; } local_a50;
  ulong local_a48;
  ushort *local_a40;
  ushort local_a38 [1280];
  long local_38;
  
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  local_ab4 = param_4 * 2 + 1;
  uVar6 = param_4 - 1;
  if (6 < uVar6) {
    if (0xfe < param_4 - 8U) {
      local_ab4 = param_4 * 2 + 2 + (param_4 - 0x107U) / 0xff;
    }
    local_ab4 = local_ab4 + 1;
  }
  if (param_2 == (ushort *)0x0) {
    param_2 = local_a38;
    puVar23 = param_2;
    puVar30 = param_1;
    for (iVar37 = param_4; iVar37 != 0; iVar37 = iVar37 + -1) {
      uVar40 = *puVar30;
      puVar30 = puVar30 + 1;
      *puVar23 = ~uVar40;
      puVar23 = puVar23 + 1;
    }
  }
  uVar11 = 0;
  if (param_5 == 0) {
LAB_100009ba4:
    if (*(long *)PTR____stack_chk_guard_100012028 == local_38) {
      return uVar11;
    }
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  uVar10 = (ulong)(param_6 - 0x120) / 0xff;
  uVar13 = (ulong)(param_6 - 0x10e) / 0xff;
  sVar18 = (ulong)(param_4 - 0x107U) / 0xff + 1;
  uVar11 = 0;
  local_aa4 = param_5;
  do {
    puVar23 = param_1;
    iVar37 = (int)uVar11;
    uVar17 = iVar37 + 2;
    lVar24 = (long)(int)uVar17;
    pbVar2 = param_3 + lVar24;
    if ((iVar37 != 0 || param_6 == 0) || param_6 == 0) {
      local_a6c = (iVar37 != 0 || param_6 == 0) ^ 1;
      local_a58 = pbVar2;
      uVar8 = param_6;
    }
    else if (param_6 == 1) {
      (param_3 + lVar24)[0] = '\0';
      (param_3 + lVar24)[1] = '\0';
      local_a58 = param_3 + lVar24 + 3;
      param_3[lVar24 + 2] = '\0';
      local_a6c = 1;
      uVar8 = 0;
    }
    else {
      if (param_6 < 0x21) {
        *pbVar2 = (char)param_6 + 0x7eU | 0x80;
        pbVar33 = pbVar2;
      }
      else {
        lVar27 = lVar24 + 1;
        *pbVar2 = 0x9f;
        uVar8 = param_6 - 0x21;
        if (0xfe < param_6 - 0x21) {
          _memset(param_3 + lVar27,0xff,uVar10 + 1);
          lVar27 = uVar10 + 2 + lVar24;
          uVar8 = (param_6 - 0x120) + ((param_6 - 0x120) / 0xff) * -0xff;
        }
        pbVar33 = param_3 + lVar27;
        param_3[lVar27] = (uchar)uVar8;
      }
      pbVar33[1] = 0;
      pbVar33[2] = 0;
      local_a6c = 1;
      local_a58 = pbVar33 + 3;
      uVar8 = 0;
    }
    uVar40 = CONCAT11((byte)*puVar23,*(byte *)((long)puVar23 + 1));
    local_a40 = puVar23 + 1;
    puVar30 = param_2 + 1;
    local_a48 = 0;
    local_a50.q = 1;
    iVar22 = 1;
    uVar15 = 1;
    local_a60 = puVar23;
    uVar28 = 1;
    iVar34 = param_4;
    if (CONCAT11((byte)*puVar23,*(byte *)((long)puVar23 + 1)) !=
        CONCAT11((byte)*param_2,*(byte *)((long)param_2 + 1))) goto LAB_100008189;
LAB_1000080d2:
    iVar36 = 0;
    lVar27 = 0;
    uVar41 = uVar40;
    while( true ) {
      uVar21 = (uint)uVar41;
      iVar26 = 0;
      if (iVar34 + -1 == iVar36) break;
      uVar40 = CONCAT11(*(byte *)((long)local_a40 + lVar27),*(byte *)((long)local_a40 + lVar27 + 1))
      ;
      uVar19 = CONCAT11(*(byte *)((long)puVar30 + lVar27),*(byte *)((long)puVar30 + lVar27 + 1));
      iVar22 = (int)uVar15;
      if (uVar40 == uVar41) {
        iVar36 = (iVar34 + -1) - iVar36;
        local_a40 = (ushort *)((long)local_a40 + lVar27 + 2);
        local_aa0 = (byte *)((long)puVar30 + lVar27 + 2);
        if (uVar40 == uVar19) {
          uVar35 = iVar22 + (uint)local_a50.q;
          uVar29 = 1;
          uVar39 = (uint)local_a50.q;
          goto LAB_100008c43;
        }
        local_a48 = (ulong)(iVar22 + -1 + (uint)((uint)local_a50.q == 0));
        uVar29 = 1;
        uVar35 = 1;
        goto LAB_1000084aa;
      }
      uVar15 = (ulong)(iVar22 + (uint)local_a50.q);
      lVar27 = lVar27 + 2;
      iVar36 = iVar36 + 1;
      uVar41 = uVar40;
      if (uVar40 != uVar19) goto code_r0x000100008159;
    }
    uVar39 = 0;
    local_a48 = uVar15;
LAB_100008dc1:
    uVar21 = iVar26 + 1;
    if ((uVar21 == param_4) && (uVar41 == 0)) {
      local_a6c = 0xffff;
LAB_1000099ab:
      uVar8 = (int)local_a58 - (int)pbVar2;
      if (local_ab4 < uVar8) goto LAB_1000099c1;
      if (local_a6c != 0xffff) {
        if (local_a6c == 0) {
          param_3[uVar11] = '\0';
          param_3[iVar37 + 1] = '\0';
          uVar11 = (ulong)uVar17;
          goto LAB_100009b85;
        }
        goto LAB_100009b65;
      }
      param_3[uVar11] = 0xff;
      param_3[iVar37 + 1] = 0xff;
      uVar11 = (ulong)uVar17;
    }
    else {
      uVar35 = (uint)local_a48;
      if ((uint)local_a50.q == 0) {
        pbVar33 = local_a58 + 1;
        uVar39 = uVar35 + uVar8;
        if (uVar39 < 3) {
          bVar25 = (char)uVar39 * ' ' + 0x80;
        }
        else {
          uVar29 = uVar39 - 3;
          if (0xfe < uVar29) {
            uVar8 = (uVar35 - 0x102) + uVar8;
            uVar15 = (ulong)uVar8 / 0xff;
            uVar29 = (uVar8 / 0xff) * -0xff + -0x102 + uVar39;
            _memset(pbVar33,0xff,uVar15 + 1);
            pbVar33 = local_a58 + uVar15 + 2;
          }
          *pbVar33 = (byte)uVar29;
          pbVar33 = pbVar33 + 1;
          bVar25 = 0xe0;
        }
        if (uVar21 < 0x21) {
LAB_1000098c1:
          bVar5 = (char)iVar26 - 1;
        }
        else {
          uVar8 = iVar26 - 0x20;
          if (0xfe < uVar8) {
            uVar15 = (ulong)(iVar26 - 0x11fU) / 0xff;
            uVar8 = iVar26 + -0x11f + ((iVar26 - 0x11fU) / 0xff) * -0xff;
            _memset(pbVar33,0xff,uVar15 + 1);
            pbVar33 = pbVar33 + uVar15 + 1;
          }
          *pbVar33 = (byte)uVar8;
          pbVar33 = pbVar33 + 1;
          bVar5 = 0x1f;
        }
LAB_10000996a:
        *local_a58 = bVar5 | bVar25;
        *pbVar33 = (byte)(uVar41 >> 8);
        pbVar33[1] = (byte)uVar41;
        local_a6c = local_a6c + 1;
        local_a58 = pbVar33 + 2;
      }
      else if (uVar39 != 0) {
        if (2 < uVar21) {
          uVar29 = uVar39 - uVar21;
          if (uVar21 <= uVar39 && uVar29 != 0) {
            local_a60 = local_a60 + local_a48;
            uVar9 = uVar35 + uVar8;
            pbVar33 = local_a58 + 1;
            if (uVar9 < 0xf) {
              bVar25 = (char)uVar9 * '\b';
            }
            else {
              uVar12 = uVar9 - 0xf;
              if (0xfe < uVar12) {
                uVar8 = (uVar35 - 0x10e) + uVar8;
                uVar15 = (ulong)uVar8 / 0xff;
                uVar12 = (uVar8 / 0xff) * -0xff + -0x10e + uVar9;
                _memset(pbVar33,0xff,uVar15 + 1);
                pbVar33 = local_a58 + uVar15 + 2;
              }
              *pbVar33 = (byte)uVar12;
              pbVar33 = pbVar33 + 1;
              bVar25 = 0x78;
            }
            if (uVar29 < 8) {
              bVar5 = (char)uVar29 - 1;
            }
            else {
              uVar29 = uVar29 - 8;
              if (0xfe < uVar29) {
                uVar29 = (uVar39 - 0x108) - iVar26;
                uVar15 = (ulong)uVar29 / 0xff;
                uVar29 = uVar29 % 0xff;
                _memset(pbVar33,0xff,uVar15 + 1);
                pbVar33 = pbVar33 + uVar15 + 1;
              }
              *pbVar33 = (byte)uVar29;
              pbVar33 = pbVar33 + 1;
              bVar5 = 7;
            }
            *local_a58 = bVar5 | bVar25;
            local_a58 = pbVar33;
            if (uVar39 != uVar21) {
              iVar22 = uVar21 - uVar39;
              pbVar16 = pbVar33;
              do {
                *pbVar16 = (byte)*local_a60;
                pbVar16[1] = *(byte *)((long)local_a60 + 1);
                local_a60 = local_a60 + 1;
                pbVar16 = pbVar16 + 2;
                iVar22 = iVar22 + 1;
              } while (iVar22 != 0);
              local_a58 = pbVar33 + (ulong)((uVar39 - 2) - iVar26) * 2 + 2;
            }
            local_a6c = local_a6c + 1;
            uVar35 = 0;
            uVar8 = uVar35;
          }
          pbVar33 = local_a58 + 1;
          uVar39 = uVar35 + uVar8;
          if (uVar39 < 3) {
            bVar25 = (char)uVar39 * ' ' + 0x80;
          }
          else {
            uVar29 = uVar39 - 3;
            if (0xfe < uVar29) {
              uVar8 = (uVar35 - 0x102) + uVar8;
              uVar15 = (ulong)uVar8 / 0xff;
              uVar29 = (uVar8 / 0xff) * -0xff + -0x102 + uVar39;
              _memset(pbVar33,0xff,uVar15 + 1);
              pbVar33 = local_a58 + uVar15 + 2;
            }
            *pbVar33 = (byte)uVar29;
            pbVar33 = pbVar33 + 1;
            bVar25 = 0xe0;
          }
          if (uVar21 < 0x21) goto LAB_1000098c1;
          uVar8 = iVar26 - 0x20;
          if (0xfe < uVar8) {
            uVar15 = (ulong)(iVar26 - 0x11fU) / 0xff;
            uVar8 = iVar26 + -0x11f + ((iVar26 - 0x11fU) / 0xff) * -0xff;
            _memset(pbVar33,0xff,uVar15 + 1);
            pbVar33 = pbVar33 + uVar15 + 1;
          }
          *pbVar33 = (byte)uVar8;
          pbVar33 = pbVar33 + 1;
          bVar5 = 0x1f;
          goto LAB_10000996a;
        }
        uVar29 = uVar21;
        if (uVar21 < uVar39) {
          uVar29 = uVar39;
        }
        local_a60 = local_a60 + local_a48;
        uVar9 = uVar35 + uVar8;
        pbVar33 = local_a58 + 1;
        if (uVar9 < 0xf) {
          bVar25 = (char)uVar9 * '\b';
        }
        else {
          uVar12 = uVar9 - 0xf;
          if (0xfe < uVar12) {
            uVar8 = (uVar35 - 0x10e) + uVar8;
            uVar15 = (ulong)uVar8 / 0xff;
            uVar12 = (uVar8 / 0xff) * -0xff + -0x10e + uVar9;
            _memset(pbVar33,0xff,uVar15 + 1);
            pbVar33 = local_a58 + uVar15 + 2;
          }
          *pbVar33 = (byte)uVar12;
          pbVar33 = pbVar33 + 1;
          bVar25 = 0x78;
        }
        if (uVar29 < 8) {
          bVar5 = (char)uVar29 - 1;
        }
        else {
          uVar8 = uVar29 - 8;
          if (0xfe < uVar8) {
            uVar15 = (ulong)(uVar29 - 0x107) / 0xff;
            uVar8 = (uVar29 - 0x107) + ((uVar29 - 0x107) / 0xff) * -0xff;
            _memset(pbVar33,0xff,uVar15 + 1);
            pbVar33 = pbVar33 + uVar15 + 1;
          }
          *pbVar33 = (byte)uVar8;
          pbVar33 = pbVar33 + 1;
          bVar5 = 7;
        }
        *local_a58 = bVar5 | bVar25;
        if (uVar29 != 0) {
          if (uVar21 < uVar39) {
            uVar21 = uVar39;
          }
          iVar22 = -uVar21;
          pbVar16 = pbVar33;
          do {
            *pbVar16 = (byte)*local_a60;
            pbVar16[1] = *(byte *)((long)local_a60 + 1);
            local_a60 = local_a60 + 1;
            pbVar16 = pbVar16 + 2;
            iVar22 = iVar22 + 1;
          } while (iVar22 != 0);
          pbVar33 = pbVar33 + (ulong)(uVar29 - 1) * 2 + 2;
        }
        local_a6c = local_a6c + 1;
        local_a58 = pbVar33;
      }
      if ((local_a6c < 0x1000) || (local_a6c == 0xffff)) goto LAB_1000099ab;
LAB_1000099c1:
      puVar31 = param_3 + lVar24 + 1;
      bVar25 = (char)param_6 * '\b';
      if (0xe < param_6) {
        uVar8 = param_6 - 0xf;
        if (0xfe < param_6 - 0xf) {
          _memset(param_3 + lVar24 + 1,0xff,uVar13 + 1);
          puVar31 = param_3 + lVar24 + uVar13 + 2;
          uVar8 = (param_6 - 0x10e) + ((param_6 - 0x10e) / 0xff) * -0xff;
        }
        *puVar31 = (uchar)uVar8;
        puVar31 = puVar31 + 1;
        bVar25 = 0x78;
      }
      uVar8 = uVar6;
      if (7 < param_4) {
        uVar8 = param_4 - 8U;
        if (0xfe < param_4 - 8U) {
          _memset(puVar31,0xff,sVar18);
          puVar31 = puVar31 + sVar18;
          uVar8 = param_4 + -0x107 + ((param_4 - 0x107U) / 0xff) * -0xff;
        }
        *puVar31 = (uchar)uVar8;
        puVar31 = puVar31 + 1;
        uVar8 = 7;
      }
      *pbVar2 = (byte)uVar8 | bVar25;
      lVar24 = 0;
      if (param_4 != 0) {
        do {
          puVar31[lVar24 * 2] = (byte)puVar23[lVar24];
          puVar31[lVar24 * 2 + 1] = *(byte *)((long)puVar23 + lVar24 * 2 + 1);
          lVar24 = lVar24 + 1;
        } while (param_4 != (int)lVar24);
        puVar31 = puVar31 + (ulong)uVar6 * 2 + 2;
      }
      uVar8 = (int)puVar31 - (int)pbVar2;
      local_a6c = 1;
LAB_100009b65:
      param_3[uVar11] = (byte)(local_a6c >> 8) | 0x30;
      param_3[iVar37 + 1] = (uchar)local_a6c;
      uVar11 = (ulong)(uVar8 + uVar17);
    }
LAB_100009b85:
    local_aa4 = local_aa4 + -1;
    param_1 = puVar23 + param_7;
    param_2 = puVar23;
    if (local_aa4 == 0) goto LAB_100009ba4;
  } while( true );
code_r0x000100008159:
  local_a40 = (ushort *)((long)local_a40 + lVar27);
  puVar30 = (ushort *)((long)puVar30 + lVar27);
  iVar34 = iVar34 - iVar36;
  local_a48 = (ulong)((iVar22 + (uint)local_a50.q) - (uint)local_a50.q);
  iVar22 = 1;
  uVar28 = local_a50.q;
LAB_100008189:
  local_a50._0_4_ = (uint)uVar28;
  uVar39 = iVar22 - 0x108;
  iVar26 = 0;
  lVar27 = 0;
  iVar36 = -iVar22;
  uVar41 = uVar40;
  do {
    iVar20 = iVar36;
    uVar21 = (uint)uVar41;
    if (iVar34 + -1 == iVar26) {
      uVar39 = iVar22 + iVar26;
      iVar26 = 0;
      goto LAB_100008dc1;
    }
    uVar40 = CONCAT11(*(byte *)((long)local_a40 + lVar27),*(byte *)((long)local_a40 + lVar27 + 1));
    uVar19 = CONCAT11(*(byte *)((long)puVar30 + lVar27),*(byte *)((long)puVar30 + lVar27 + 1));
    iVar3 = (int)local_a48;
    if (uVar40 == uVar41) goto LAB_1000082b6;
    lVar27 = lVar27 + 2;
    iVar26 = iVar26 + 1;
    uVar39 = uVar39 + 1;
    iVar36 = iVar20 + -1;
    uVar41 = uVar40;
  } while (uVar40 != uVar19);
  puVar14 = local_a60 + local_a48;
  uVar35 = iVar3 + uVar8;
  pbVar33 = local_a58 + 1;
  local_a40 = (ushort *)((long)local_a40 + lVar27);
  puVar30 = (ushort *)((long)puVar30 + lVar27);
  iVar34 = iVar34 - iVar26;
  uVar21 = iVar22 + -1 + iVar26;
  if (uVar35 < 0xf) {
    bVar25 = (char)uVar35 * '\b';
  }
  else {
    uVar29 = uVar35 - 0xf;
    if (0xfe < uVar29) {
      uVar8 = iVar3 + -0x10e + uVar8;
      uVar15 = (ulong)uVar8 / 0xff;
      uVar29 = (uVar8 / 0xff) * -0xff + -0x10e + uVar35;
      _memset(pbVar33,0xff,uVar15 + 1);
      pbVar33 = local_a58 + uVar15 + 2;
    }
    *pbVar33 = (byte)uVar29;
    pbVar33 = pbVar33 + 1;
    bVar25 = 0x78;
  }
  if (uVar21 < 8) {
    bVar5 = (char)iVar22 + -2 + (char)iVar26;
  }
  else {
    uVar8 = iVar22 + -9 + iVar26;
    if (0xfe < uVar8) {
      uVar15 = (ulong)(uint)(iVar22 + -0x108 + iVar26) / 0xff;
      _memset(pbVar33,0xff,uVar15 + 1);
      pbVar33 = pbVar33 + uVar15 + 1;
      uVar8 = (uVar39 / 0xff) * -0xff + -0x108 + iVar22 + iVar26;
    }
    *pbVar33 = (byte)uVar8;
    pbVar33 = pbVar33 + 1;
    bVar5 = 7;
  }
  *local_a58 = bVar5 | bVar25;
  if (uVar21 != 0) {
    uVar15 = (ulong)(uint)(iVar22 + -2 + iVar26);
    pbVar16 = pbVar33;
    do {
      *pbVar16 = (byte)*puVar14;
      pbVar16[1] = *(byte *)((long)puVar14 + 1);
      puVar14 = puVar14 + 1;
      pbVar16 = pbVar16 + 2;
      iVar20 = iVar20 + 1;
    } while (iVar20 != 0);
    pbVar33 = pbVar33 + uVar15 * 2 + 2;
    puVar14 = local_a60 + local_a48 + uVar15 + 1;
  }
  local_a6c = local_a6c + 1;
  uVar8 = 0;
  uVar15 = uVar28;
  local_a60 = puVar14;
  local_a58 = pbVar33;
  local_a50.q = uVar28;
  goto LAB_1000080d2;
LAB_1000082b6:
  iVar36 = (iVar34 + -1) - iVar26;
  local_a40 = (ushort *)((long)local_a40 + lVar27 + 2);
  local_aa0 = (byte *)((long)puVar30 + lVar27 + 2);
  if (uVar40 != uVar19) {
    uVar35 = iVar22 + 1 + iVar26;
    uVar29 = 1;
    goto LAB_1000084aa;
  }
  uVar35 = iVar22 + iVar26;
  if (uVar35 < 2) {
    uVar29 = 1;
    local_a50._0_4_ = 0;
    goto LAB_1000084aa;
  }
  uVar29 = iVar22 + -1 + iVar26;
  puVar30 = local_a60 + local_a48;
  uVar35 = iVar3 + uVar8;
  pbVar33 = local_a58 + 1;
  if (uVar35 < 0xf) {
    bVar25 = (char)uVar35 * '\b';
  }
  else {
    uVar9 = uVar35 - 0xf;
    if (0xfe < uVar9) {
      uVar8 = iVar3 + -0x10e + uVar8;
      uVar15 = (ulong)uVar8 / 0xff;
      uVar9 = (uVar8 / 0xff) * -0xff + -0x10e + uVar35;
      _memset(pbVar33,0xff,uVar15 + 1);
      pbVar33 = local_a58 + uVar15 + 2;
    }
    *pbVar33 = (byte)uVar9;
    pbVar33 = pbVar33 + 1;
    bVar25 = 0x78;
  }
  if (uVar29 < 8) {
    bVar5 = (char)iVar22 + -2 + (char)iVar26;
  }
  else {
    uVar8 = iVar22 + -9 + iVar26;
    if (0xfe < uVar8) {
      uVar15 = (ulong)(uint)(iVar22 + -0x108 + iVar26) / 0xff;
      _memset(pbVar33,0xff,uVar15 + 1);
      pbVar33 = pbVar33 + uVar15 + 1;
      uVar8 = (uVar39 / 0xff) * -0xff + -0x108 + iVar22 + iVar26;
    }
    *pbVar33 = (byte)uVar8;
    pbVar33 = pbVar33 + 1;
    bVar5 = 7;
  }
  *local_a58 = bVar5 | bVar25;
  if (uVar29 != 0) {
    uVar15 = (ulong)(uint)(iVar22 + -2 + iVar26);
    iVar22 = -1;
    pbVar16 = pbVar33;
    do {
      *pbVar16 = (byte)*puVar30;
      pbVar16[1] = *(byte *)((long)puVar30 + 1);
      iVar22 = iVar22 + -1;
      puVar30 = puVar30 + 1;
      pbVar16 = pbVar16 + 2;
    } while (iVar20 != iVar22);
    pbVar33 = pbVar33 + uVar15 * 2 + 2;
    puVar30 = local_a60 + local_a48 + uVar15 + 1;
  }
  local_a60 = puVar30;
  uVar29 = 1;
  puVar30 = local_a60;
  local_a58 = pbVar33;
LAB_100008c3d:
  local_a60 = puVar30;
  local_a6c = local_a6c + 1;
  uVar35 = 0;
  uVar8 = 0;
  uVar39 = uVar35;
LAB_100008c43:
  uVar41 = (ushort)uVar21;
  uVar32 = ~uVar29;
  uVar9 = uVar29 - 0x11f;
  iVar20 = uVar35 + uVar8;
  iVar34 = iVar20 * 0x20 + 0x80;
  uVar12 = (uVar35 - 0x102) + uVar8;
  iVar22 = 0;
  iVar26 = 0;
  lVar27 = 0;
  do {
    local_a50._0_1_ = (byte)iVar34;
    local_a50._0_4_ = uVar39;
    if (iVar36 + -1 == iVar26) {
      iVar26 = uVar29 + iVar26;
      uVar39 = 0;
      local_a48 = (ulong)(uVar35 + iVar22);
      goto LAB_100008dc1;
    }
    uVar40 = CONCAT11(*(byte *)((long)local_a40 + lVar27),*(byte *)((long)local_a40 + lVar27 + 1));
    uVar19 = CONCAT11(local_aa0[lVar27],local_aa0[lVar27 + 1]);
    if (uVar40 != uVar41) {
      iVar34 = (iVar36 + -1) - iVar26;
      local_a40 = (ushort *)((long)local_a40 + lVar27 + 2);
      puVar30 = (ushort *)(local_aa0 + lVar27 + 2);
      if (uVar39 != 0) {
        if (uVar40 == uVar19) {
          local_a50.q = (ulong)uVar39;
          uVar15 = (ulong)(uVar35 + 1 + iVar22);
          goto LAB_1000080d2;
        }
        local_a48 = (ulong)(uVar35 + iVar22);
        iVar22 = 1;
        uVar28 = (ulong)uVar39;
        goto LAB_100008189;
      }
      pbVar33 = local_a58 + 1;
      if (2 < (uint)(iVar20 + iVar22)) {
        uVar8 = iVar22 + -3 + iVar20;
        if (0xfe < uVar8) {
          uVar15 = (ulong)(uint)(iVar22 + -0x102 + iVar20) / 0xff;
          _memset(pbVar33,0xff,uVar15 + 1);
          pbVar33 = local_a58 + uVar15 + 2;
          uVar8 = (uVar12 / 0xff) * -0xff + -0x102 + iVar20 + iVar22;
        }
        *pbVar33 = (byte)uVar8;
        pbVar33 = pbVar33 + 1;
        local_a50._0_1_ = 0xe0;
      }
      local_a60 = local_a60 + (uVar35 - uVar32);
      if (uVar29 + 1 + iVar26 < 0x21) {
        bVar25 = (char)uVar29 + -1 + (char)iVar26;
      }
      else {
        uVar8 = (uVar29 - 0x20) + iVar26;
        if (0xfe < uVar8) {
          uVar15 = (ulong)((uVar29 - 0x11f) + iVar26) / 0xff;
          _memset(pbVar33,0xff,uVar15 + 1);
          pbVar33 = pbVar33 + uVar15 + 1;
          uVar8 = (uVar9 / 0xff) * -0xff + -0x11f + uVar29 + iVar26;
        }
        *pbVar33 = (byte)uVar8;
        pbVar33 = pbVar33 + 1;
        bVar25 = 0x1f;
      }
      *local_a58 = bVar25 | (byte)local_a50.q;
      *pbVar33 = (byte)(uVar21 >> 8);
      pbVar33[1] = (byte)uVar21;
      local_a58 = pbVar33 + 2;
      local_a6c = local_a6c + 1;
      if (uVar40 == uVar19) {
        uVar8 = 0;
        local_a50.q = 1;
        uVar15 = 1;
        goto LAB_1000080d2;
      }
      iVar22 = 1;
      local_a48 = 0;
      uVar8 = 0;
      uVar28 = 1;
      goto LAB_100008189;
    }
    lVar27 = lVar27 + 2;
    iVar26 = iVar26 + 1;
    uVar32 = uVar32 + ~uVar39;
    uVar9 = uVar9 + 1;
    iVar22 = iVar22 + uVar39;
    iVar34 = iVar34 + uVar39 * 0x20;
    uVar12 = uVar12 + uVar39;
  } while (uVar41 == uVar19);
  uVar29 = uVar29 + iVar26;
  uVar9 = uVar29;
  if (uVar39 == 0) {
    uVar9 = 0;
  }
  local_a40 = (ushort *)((long)local_a40 + lVar27);
  local_aa0 = local_aa0 + lVar27;
  iVar36 = iVar36 - iVar26;
  local_a48 = (ulong)(((uVar35 - uVar39) - uVar9) + iVar22);
  uVar35 = 1;
LAB_1000084aa:
  local_a50.q = (ulong)(uint)local_a50.q;
  pbVar33 = local_aa0;
  puVar30 = local_a40;
LAB_1000084cf:
  iVar34 = iVar36;
  uVar39 = uVar35;
  local_a40 = puVar30;
  local_aa0 = pbVar33;
  uVar9 = uVar29;
  uVar35 = uVar9 - 0x11f;
  uVar29 = uVar39 - 0x107;
  iVar36 = -uVar39;
  iVar22 = 0;
  lVar27 = 0;
  while( true ) {
    uVar41 = (ushort)uVar21;
    if (iVar34 + -1 == iVar22) {
      iVar26 = uVar9 + iVar22;
      uVar39 = uVar39 + iVar22;
      goto LAB_100008dc1;
    }
    uVar40 = CONCAT11(*(byte *)((long)local_a40 + lVar27),*(byte *)((long)local_a40 + lVar27 + 1));
    uVar19 = CONCAT11(local_aa0[lVar27],local_aa0[lVar27 + 1]);
    iVar26 = (int)local_a48;
    if (uVar40 != uVar41) break;
    lVar27 = lVar27 + 2;
    iVar22 = iVar22 + 1;
    uVar35 = uVar35 + 1;
    uVar29 = uVar29 + 1;
    iVar36 = iVar36 + -1;
    if (uVar41 == uVar19) goto code_r0x000100008567;
  }
  uVar32 = uVar9 + 1 + iVar22;
  uVar12 = uVar39 + iVar22;
  iVar34 = (iVar34 + -1) - iVar22;
  local_a40 = (ushort *)((long)local_a40 + lVar27 + 2);
  puVar30 = (ushort *)(local_aa0 + lVar27 + 2);
  bVar25 = (byte)(uVar21 >> 8);
  cVar4 = (char)iVar22;
  if (uVar12 <= uVar32) {
    local_a60 = local_a60 + (iVar22 + 1 + uVar9 + iVar26);
    pbVar33 = local_a58 + 1;
    uVar39 = iVar26 + uVar8;
    if (uVar39 < 3) {
      bVar5 = (char)uVar39 * ' ' + 0x80;
    }
    else {
      uVar29 = uVar39 - 3;
      if (0xfe < uVar29) {
        uVar8 = iVar26 + -0x102 + uVar8;
        uVar15 = (ulong)uVar8 / 0xff;
        uVar29 = (uVar8 / 0xff) * -0xff + -0x102 + uVar39;
        _memset(pbVar33,0xff,uVar15 + 1);
        pbVar33 = local_a58 + uVar15 + 2;
      }
      *pbVar33 = (byte)uVar29;
      pbVar33 = pbVar33 + 1;
      bVar5 = 0xe0;
    }
    if (uVar32 < 0x21) {
      bVar38 = (char)uVar9 + -1 + cVar4;
    }
    else {
      uVar8 = (uVar9 - 0x20) + iVar22;
      if (0xfe < uVar8) {
        uVar15 = (ulong)((uVar9 - 0x11f) + iVar22) / 0xff;
        _memset(pbVar33,0xff,uVar15 + 1);
        pbVar33 = pbVar33 + uVar15 + 1;
        uVar8 = (uVar35 / 0xff) * -0xff + -0x11f + uVar9 + iVar22;
      }
      *pbVar33 = (byte)uVar8;
      pbVar33 = pbVar33 + 1;
      bVar38 = 0x1f;
    }
    *local_a58 = bVar38 | bVar5;
    *pbVar33 = bVar25;
    pbVar33[1] = (byte)uVar21;
    local_a58 = pbVar33 + 2;
    local_a6c = local_a6c + 1;
    if (uVar40 == uVar19) {
      uVar8 = 0;
      local_a50.q = 1;
      uVar15 = 1;
      goto LAB_1000080d2;
    }
    uVar28 = 1;
    iVar22 = 1;
    local_a48 = 0;
    uVar8 = 0;
    goto LAB_100008189;
  }
  if (2 < uVar32) {
    uVar29 = uVar12 - uVar32;
    puVar14 = local_a60 + local_a48;
    uVar7 = iVar26 + uVar8;
    local_b80 = local_a58 + 1;
    if (uVar7 < 0xf) {
      bVar5 = (char)uVar7 * '\b';
    }
    else {
      uVar1 = uVar7 - 0xf;
      if (0xfe < uVar1) {
        uVar8 = iVar26 + -0x10e + uVar8;
        uVar15 = (ulong)uVar8 / 0xff;
        uVar1 = (uVar8 / 0xff) * -0xff + -0x10e + uVar7;
        _memset(local_b80,0xff,uVar15 + 1);
        local_b80 = local_a58 + uVar15 + 2;
      }
      *local_b80 = (byte)uVar1;
      local_b80 = local_b80 + 1;
      bVar5 = 0x78;
    }
    if (uVar29 < 8) {
      bVar38 = (char)uVar29 - 1;
    }
    else {
      uVar29 = uVar29 - 8;
      if (0xfe < uVar29) {
        uVar29 = ((uVar39 - 0x107) + iVar22) - uVar32;
        uVar15 = (ulong)uVar29 / 0xff;
        uVar29 = uVar29 % 0xff;
        _memset(local_b80,0xff,uVar15 + 1);
        local_b80 = local_b80 + uVar15 + 1;
      }
      *local_b80 = (byte)uVar29;
      local_b80 = local_b80 + 1;
      bVar38 = 7;
    }
    *local_a58 = bVar38 | bVar5;
    if (uVar12 != uVar32) {
      uVar15 = (ulong)(((uVar39 - 1) + iVar22) - uVar32);
      iVar36 = (uVar9 + 1) - uVar39;
      pbVar33 = local_b80;
      do {
        *pbVar33 = (byte)*puVar14;
        pbVar33[1] = *(byte *)((long)puVar14 + 1);
        puVar14 = puVar14 + 1;
        pbVar33 = pbVar33 + 2;
        iVar36 = iVar36 + 1;
      } while (iVar36 != 0);
      local_b80 = local_b80 + uVar15 * 2 + 2;
      puVar14 = local_a60 + local_a48 + uVar15 + 1;
    }
    local_a58 = local_b80 + 1;
    local_a60 = puVar14 + uVar32;
    if (uVar32 < 0x21) {
      bVar5 = (char)uVar9 + '\x7f' + cVar4 | 0x80;
    }
    else {
      uVar8 = (uVar9 - 0x20) + iVar22;
      if (0xfe < uVar8) {
        uVar15 = (ulong)((uVar9 - 0x11f) + iVar22) / 0xff;
        _memset(local_a58,0xff,uVar15 + 1);
        local_a58 = local_b80 + uVar15 + 2;
        uVar8 = (uVar35 / 0xff) * -0xff + -0x11f + uVar9 + iVar22;
      }
      *local_a58 = (byte)uVar8;
      local_a58 = local_a58 + 1;
      bVar5 = 0x9f;
    }
    *local_b80 = bVar5;
    *local_a58 = bVar25;
    local_a58[1] = (byte)uVar21;
    local_a58 = local_a58 + 2;
    local_a6c = local_a6c + 2;
    if (uVar40 == uVar19) {
      uVar8 = 0;
      local_a50.q = 1;
      uVar15 = 1;
      goto LAB_1000080d2;
    }
    iVar22 = 1;
    local_a48 = 0;
    uVar8 = 0;
    uVar28 = 1;
    goto LAB_100008189;
  }
  if (uVar40 != uVar19) {
    iVar22 = uVar39 + 1 + iVar22;
    uVar28 = local_a50.q;
    goto LAB_100008189;
  }
  puVar14 = local_a60 + local_a48;
  uVar21 = iVar26 + uVar8;
  pbVar33 = local_a58 + 1;
  if (uVar21 < 0xf) {
    bVar25 = (char)uVar21 * '\b';
  }
  else {
    uVar35 = uVar21 - 0xf;
    if (0xfe < uVar35) {
      uVar8 = iVar26 + -0x10e + uVar8;
      uVar15 = (ulong)uVar8 / 0xff;
      uVar35 = (uVar8 / 0xff) * -0xff + -0x10e + uVar21;
      _memset(pbVar33,0xff,uVar15 + 1);
      pbVar33 = local_a58 + uVar15 + 2;
    }
    *pbVar33 = (byte)uVar35;
    pbVar33 = pbVar33 + 1;
    bVar25 = 0x78;
  }
  if (uVar12 < 8) {
    bVar5 = (char)uVar39 + -1 + cVar4;
  }
  else {
    uVar8 = (uVar39 - 8) + iVar22;
    if (0xfe < uVar8) {
      uVar15 = (ulong)((uVar39 - 0x107) + iVar22) / 0xff;
      _memset(pbVar33,0xff,uVar15 + 1);
      pbVar33 = pbVar33 + uVar15 + 1;
      uVar8 = (uVar29 / 0xff) * -0xff + -0x107 + uVar39 + iVar22;
    }
    *pbVar33 = (byte)uVar8;
    pbVar33 = pbVar33 + 1;
    bVar5 = 7;
  }
  *local_a58 = bVar5 | bVar25;
  if (uVar12 != 0) {
    uVar15 = (ulong)((uVar39 - 1) + iVar22);
    pbVar16 = pbVar33;
    do {
      *pbVar16 = (byte)*puVar14;
      pbVar16[1] = *(byte *)((long)puVar14 + 1);
      puVar14 = puVar14 + 1;
      pbVar16 = pbVar16 + 2;
      iVar36 = iVar36 + 1;
    } while (iVar36 != 0);
    pbVar33 = pbVar33 + uVar15 * 2 + 2;
    puVar14 = local_a60 + local_a48 + uVar15 + 1;
  }
  local_a6c = local_a6c + 1;
  uVar8 = 0;
  uVar15 = local_a50.q;
  local_a60 = puVar14;
  local_a58 = pbVar33;
  goto LAB_1000080d2;
code_r0x000100008567:
  uVar35 = (uVar39 - 1) + iVar22;
  local_a50.q = 0;
  uVar29 = uVar9 + iVar22;
  pbVar33 = local_aa0 + lVar27;
  puVar30 = (ushort *)((long)local_a40 + lVar27);
  iVar36 = iVar34 - iVar22;
  if (uVar9 + iVar22 < uVar35) goto code_r0x0001000085a8;
  goto LAB_1000084cf;
code_r0x0001000085a8:
  uVar29 = uVar9 + iVar22;
  uVar32 = (uVar39 - 1) + iVar22;
  uVar35 = uVar32 - uVar29;
  puVar30 = local_a60 + local_a48;
  uVar12 = iVar26 + uVar8;
  local_a40 = (ushort *)((long)local_a40 + lVar27);
  local_aa0 = local_aa0 + lVar27;
  pbVar33 = local_a58 + 1;
  iVar36 = iVar34 - iVar22;
  if (uVar12 < 0xf) {
    bVar25 = (char)uVar12 * '\b';
  }
  else {
    uVar7 = uVar12 - 0xf;
    if (0xfe < uVar7) {
      uVar8 = iVar26 + -0x10e + uVar8;
      uVar15 = (ulong)uVar8 / 0xff;
      uVar7 = (uVar8 / 0xff) * -0xff + -0x10e + uVar12;
      _memset(pbVar33,0xff,uVar15 + 1);
      pbVar33 = local_a58 + uVar15 + 2;
    }
    *pbVar33 = (byte)uVar7;
    pbVar33 = pbVar33 + 1;
    bVar25 = 0x78;
  }
  if (uVar35 < 8) {
    bVar5 = (char)uVar35 - 1;
  }
  else {
    uVar35 = uVar35 - 8;
    if (0xfe < uVar35) {
      uVar35 = ((uVar39 - 0x108) + iVar22) - uVar29;
      uVar15 = (ulong)uVar35 / 0xff;
      uVar35 = uVar35 % 0xff;
      _memset(pbVar33,0xff,uVar15 + 1);
      pbVar33 = pbVar33 + uVar15 + 1;
    }
    *pbVar33 = (byte)uVar35;
    pbVar33 = pbVar33 + 1;
    bVar5 = 7;
  }
  *local_a58 = bVar5 | bVar25;
  local_a58 = pbVar33;
  if (uVar32 != uVar29) {
    uVar15 = (ulong)(((uVar39 - 2) + iVar22) - uVar29);
    iVar22 = (uVar9 + 1) - uVar39;
    pbVar16 = pbVar33;
    do {
      *pbVar16 = (byte)*puVar30;
      pbVar16[1] = *(byte *)((long)puVar30 + 1);
      puVar30 = puVar30 + 1;
      pbVar16 = pbVar16 + 2;
      iVar22 = iVar22 + 1;
    } while (iVar22 != 0);
    puVar30 = local_a60 + local_a48 + uVar15 + 1;
    local_a58 = pbVar33 + uVar15 * 2 + 2;
  }
  goto LAB_100008c3d;
}

