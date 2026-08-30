// _getSideChannelSNMPData  entry=10000abd2

int _getSideChannelSNMPData(char *param_2, ...)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  long lVar15;
  uint uVar16;
  byte *pbVar17;
  ulong uVar18;
  size_t sVar19;
  undefined8 uVar20;
  int iVar21;
  ulong uVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  double dVar26;
  uint local_83c;
  undefined1 local_838 [2048];
  long local_38;
  
  lVar3 = *(long *)PTR____stack_chk_guard_100012028;
  local_83c = 0x800;
  local_38 = lVar3;
  uVar12 = _cupsSideChannelSNMPGet(param_2,local_838,(int *)&local_83c,5.0);
  if ((uVar12 == 1) && (0 < (int)local_83c)) {
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s cupsSideChannelRead %d bytes.\n","DEBUG: ",local_83c);
    sVar19 = (size_t)(int)local_83c;
    pbVar14 = _malloc((long)(int)(local_83c + 1));
    _memcpy(pbVar14,local_838,sVar19);
    uVar22 = (ulong)(int)local_83c;
    pbVar14[uVar22] = 0;
    iVar13 = _strcmp(param_2,_kStatusID);
    if (iVar13 == 0) {
      lVar15 = _atol((char *)pbVar14);
      iVar13 = 1;
      if (0 < lVar15) {
        _gStatus = lVar15;
      }
    }
    else {
      iVar13 = _strcmp(param_2,_kStatusMsgID);
      if (iVar13 == 0) {
        if (pbVar14 == (byte *)0x0) {
          DAT_100014fe0 = 0;
          iVar13 = 0;
        }
        else {
          DAT_100014fe0 = _convertToUTF8String(pbVar14);
          iVar13 = 1;
        }
      }
      else {
        iVar13 = _strcmp(param_2,_kSupplyLevelID);
        dVar10 = DAT_1000104f0;
        dVar9 = DAT_1000104e8;
        dVar8 = DAT_1000104e0;
        dVar7 = DAT_1000104d8;
        dVar6 = DAT_1000104d0;
        dVar5 = DAT_1000104c8;
        dVar4 = DAT_1000104c0;
        if (iVar13 == 0) {
          iVar13 = 1;
          pbVar11 = pbVar14;
          if (pbVar14 != (byte *)0x0) {
            while( true ) {
              pbVar17 = pbVar11;
              bVar1 = *pbVar17;
              if ((bVar1 == 0xff) || (iVar21 = (int)uVar22, iVar21 < 1)) break;
              local_83c = iVar21 - 1;
              uVar22 = (ulong)local_83c;
              pbVar11 = pbVar17 + 1;
              if ((pbVar17[1] != 0xff) && (0 < (int)local_83c)) {
                local_83c = iVar21 - 2;
                uVar22 = (ulong)local_83c;
                bVar2 = pbVar17[2];
                uVar12 = (uint)bVar2;
                pbVar11 = pbVar17 + 2;
                if ((uVar12 != 0xff) && (0 < (int)local_83c)) {
                  if ((byte)(bVar1 + 0x5f) < 4) {
                    if ((uVar12 == 2) && (1 < iVar21 + -3)) {
                      uVar20 = 0;
                      if (pbVar17[4] != 0) {
                        dVar26 = ((double)pbVar17[3] / (double)pbVar17[4]) * dVar4;
                        uVar20 = 0;
                        if (((((0.0 < dVar26) && (uVar20 = 10, dVar5 <= dVar26)) &&
                             (uVar20 = 0x19, dVar6 <= dVar26)) &&
                            ((uVar20 = 0x28, dVar7 <= dVar26 && (uVar20 = 0x37, dVar8 <= dVar26))))
                           && ((uVar20 = 0x46, dVar9 <= dVar26 && (uVar20 = 100, dVar26 < dVar10))))
                        {
                          uVar20 = 0x55;
                        }
                      }
                      (&DAT_100014ff0)[(byte)(bVar1 + 0x5f)] = uVar20;
                    }
                    goto switchD_10000aeea_default;
                  }
                  if ((byte)(bVar1 + 0x7f) < 4) {
                    if (bVar2 == 0) goto switchD_10000aeea_default;
                    switch(_gModelInfo) {
                    case 0:
                      bVar25 = SBORROW4(DAT_100015084,0xd);
                      bVar24 = DAT_100015084 + -0xd < 0;
                      bVar23 = DAT_100015084 == 0xd;
                      break;
                    case 1:
                      bVar25 = SBORROW4(DAT_100015084,7);
                      bVar24 = DAT_100015084 + -7 < 0;
                      bVar23 = DAT_100015084 == 7;
                      break;
                    case 2:
                      bVar25 = SBORROW4(DAT_100015084,4);
                      bVar24 = DAT_100015084 + -4 < 0;
                      bVar23 = DAT_100015084 == 4;
                      break;
                    case 3:
                      goto switchD_10000aeea_caseD_3;
                    default:
                      goto switchD_10000aeea_default;
                    }
                    if (!bVar23 && bVar25 == bVar24) {
switchD_10000aeea_caseD_3:
                      (&DAT_100014ff0)[(byte)(bVar1 + 0x7f)] = (long)(char)pbVar17[uVar12 + 2];
                    }
                    goto switchD_10000aeea_default;
                  }
                  if ((byte)(bVar1 + 0x7a) < 4) {
                    if (bVar2 == 0) goto switchD_10000aeea_default;
                    switch(_gModelInfo) {
                    case 0:
                      bVar25 = SBORROW4(DAT_100015084,0xd);
                      bVar24 = DAT_100015084 + -0xd < 0;
                      bVar23 = DAT_100015084 == 0xd;
                      break;
                    case 1:
                      bVar25 = SBORROW4(DAT_100015084,7);
                      bVar24 = DAT_100015084 + -7 < 0;
                      bVar23 = DAT_100015084 == 7;
                      break;
                    case 2:
                      bVar25 = SBORROW4(DAT_100015084,4);
                      bVar24 = DAT_100015084 + -4 < 0;
                      bVar23 = DAT_100015084 == 4;
                      break;
                    case 3:
                      goto switchD_10000af25_caseD_3;
                    default:
                      goto switchD_10000aeea_default;
                    }
                    if (!bVar23 && bVar25 == bVar24) {
switchD_10000af25_caseD_3:
                      *((int *)((unsigned char *)&_gLowLevel + (unsigned)(byte)(bVar1 + 0x7a))) = (int)(char)pbVar17[uVar12 + 2];
                    }
                    goto switchD_10000aeea_default;
                  }
                  if (_gModelInfo == 0) goto switchD_10000aeea_default;
                  uVar22 = (ulong)bVar1;
                  if (bVar1 < 0x53) {
                    if (bVar1 - 0x31 < 7) {
                      uVar22 = (ulong)(byte)(bVar1 - 0x31);
                    }
                    goto switchD_10000af80_caseD_58;
                  }
                  uVar18 = 0xd;
                  switch((uint)bVar1) {
                  case 0x53:
                  case 0x54:
                  case 0x55:
                  case 0x56:
                  case 0x57:
                    uVar22 = (ulong)(byte)(bVar1 + 0xb5);
                  default:
switchD_10000af80_caseD_58:
                    uVar18 = uVar22;
                    if (((uint)uVar18 < 10) && ((0x30fUL >> (uVar18 & 0x3f) & 1) != 0)) {
                      uVar16 = pbVar17[uVar12 + 2] - 1;
                      uVar20 = 0xffffffffffffffff;
                      if (uVar16 < 4) {
                        uVar20 = *(undefined8 *)(&DAT_100010520 + (long)(int)uVar16 * 8);
                      }
                      (&DAT_100014ff0)[uVar18] = uVar20;
                    }
                    else if ((uint)uVar18 < 0xf) break;
                    goto switchD_10000aeea_default;
                  case 0x61:
                    break;
                  case 99:
                    uVar18 = 0xe;
                    break;
                  case 100:
                    uVar18 = 7;
                  }
                  uVar16 = pbVar17[uVar12 + 2] - 1;
                  uVar20 = 0xffffffffffffffff;
                  if (uVar16 < 3) {
                    uVar20 = *(undefined8 *)(&DAT_100010540 + (long)(int)uVar16 * 8);
                  }
                  (&DAT_100014ff0)[uVar18] = uVar20;
switchD_10000aeea_default:
                  local_83c = (iVar21 + -3) - uVar12;
                  uVar22 = (ulong)local_83c;
                  pbVar11 = pbVar17 + (ulong)uVar12 + 3;
                }
              }
            }
          }
        }
        else {
          iVar13 = _atoi((char *)pbVar14);
        }
      }
    }
    _free(pbVar14);
  }
  else {
    iVar13 = 0;
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s %d\n","DEBUG: ","No response!",(ulong)uVar12);
  }
  if (lVar3 == local_38) {
    return iVar13;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

