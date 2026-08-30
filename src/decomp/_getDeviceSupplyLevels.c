// _getDeviceSupplyLevels  entry=10000cf8a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _getDeviceSupplyLevels(undefined8 param_1)

{
  bool bVar1;
  size_t sVar2;
  size_t sVar3;
  size_t sVar4;
  size_t sVar5;
  size_t sVar6;
  size_t sVar7;
  size_t sVar8;
  char *pcVar9;
  int iVar10;
  long lVar11;
  char *pcVar12;
  char *pcVar13;
  int local_104c;
  char *local_1048;
  char *local_1040;
  char local_1038 [1024];
  char local_c38 [1024];
  char local_838 [1024];
  char local_438 [1024];
  long local_38;
  
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  _DAT_100015068 = 0xffffffffffffffff;
  DAT_100015060 = 0xffffffffffffffff;
  DAT_100015058 = 0xffffffffffffffff;
  _DAT_100015050 = 0xffffffffffffffff;
  _DAT_100015048 = 0xffffffffffffffff;
  _DAT_100015040 = 0xffffffffffffffff;
  _DAT_100015038 = 0xffffffffffffffff;
  _DAT_100015030 = 0xffffffffffffffff;
  DAT_100015028 = 0xffffffffffffffff;
  _DAT_100015020 = 0xffffffffffffffff;
  DAT_100015018 = 0xffffffffffffffff;
  DAT_100015010 = 0xffffffffffffffff;
  DAT_100015008 = 0xffffffffffffffff;
  DAT_100015000 = 0xffffffffffffffff;
  DAT_100014ff8 = 0xffffffffffffffff;
  DAT_100014ff0 = -1;
  if (_gGetStatusMode == 2) {
    local_104c = _getBackChannelData((void *)0);
    switch(_gModelInfo) {
    case 0:
    case 3:
      break;
    case 1:
      if (DAT_100015084 < 8) goto switchD_10000d092_default;
      break;
    case 2:
      if (DAT_100015084 < 5) goto switchD_10000d092_default;
      break;
    default:
switchD_10000d092_default:
      bVar1 = true;
      if (0 < local_104c) {
        iVar10 = 0;
        do {
          if ((_gStatus != 0 && _gStatus != 0x2713) || (2 < iVar10)) break;
          local_104c = _getBackChannelData(param_1);
          iVar10 = iVar10 + 1;
        } while (0 < local_104c);
      }
      goto LAB_10000d1a3;
    }
    if (DAT_100014ff0 < 0) {
      bVar1 = false;
      _getBackChannelData(param_1);
    }
    else {
      bVar1 = false;
    }
  }
  else {
    bVar1 = false;
    if (_gGetStatusMode == 1) {
      local_104c = _getSideChannelSNMPData(_kSupplyLevelID);
      if (((DAT_100014ff0 < 0) && (_gModelInfo == 1)) && (DAT_100015084 < 8)) {
        local_104c = _getSideChannelSNMPData(param_1,_kStatusID);
        bVar1 = true;
      }
    }
    else {
      local_104c = -1;
    }
  }
LAB_10000d1a3:
  lVar11 = 0;
  ___sprintf_chk(local_438,0,0x400,"%s",_kMarkerColor);
  sVar2 = _strlen(local_438);
  local_1040 = local_438 + sVar2;
  ___sprintf_chk(local_838,0,0x400,"%s",_kMarkerLevel);
  sVar3 = _strlen(local_838);
  local_1048 = local_838 + sVar3;
  ___sprintf_chk(local_c38,0,0x400,"%s",_kMarkerName);
  sVar4 = _strlen(local_c38);
  pcVar13 = local_c38 + sVar4;
  ___sprintf_chk(local_1038,0,0x400,"%s",_kMarkerType);
  sVar5 = _strlen(local_1038);
  pcVar12 = local_1038 + sVar5;
  switch(_gModelInfo) {
  case 0:
    do {
      if ((&DAT_100014ff0)[lVar11] < 0) {
        (&DAT_100014ff0)[lVar11] = 0xffffffffffffffff;
      }
      lVar11 = lVar11 + 1;
    } while (lVar11 != 4);
    if (DAT_100015084 < 0xf) {
      lVar11 = 0;
      ___sprintf_chk(local_1040,0,0xffffffffffffffff,"#000000,#ffff00,#00ffff,#ff00ff");
      local_1040 = (char *)_strlen(local_1040);
      ___sprintf_chk(local_1048,0,0xffffffffffffffff,"%ld,%ld,%ld,%ld",DAT_100014ff0,DAT_100015008,
                     DAT_100014ff8,DAT_100015000);
      sVar8 = _strlen(local_1048);
      bVar1 = true;
      do {
        if (*(int *)((long)&_gLowLevel + lVar11) < 0) {
          bVar1 = false;
        }
        lVar11 = lVar11 + 4;
      } while (lVar11 != 0x10);
      local_1048 = local_838 + sVar8 + sVar3;
      if (bVar1) {
        ___sprintf_chk(local_1048,0,0xffffffffffffffff," %s%d,%d,%d,%d",_kMarkerLowLevel,_gLowLevel,
                       DAT_10001507c,DAT_100015074,DAT_100015078);
        sVar6 = _strlen(local_1048);
        local_1048 = local_838 + sVar6 + sVar8 + sVar3;
      }
      pcVar9 = "Black,Yellow,Cyan,Magenta";
    }
    else {
      lVar11 = 0;
      ___sprintf_chk(local_1040,0,0xffffffffffffffff,"#ff00ff,#00ffff,#ffff00,#000000");
      local_1040 = (char *)_strlen(local_1040);
      ___sprintf_chk(local_1048,0,0xffffffffffffffff,"%ld,%ld,%ld,%ld",DAT_100015000,DAT_100014ff8,
                     DAT_100015008,DAT_100014ff0);
      sVar8 = _strlen(local_1048);
      bVar1 = true;
      do {
        if (*(int *)((long)&_gLowLevel + lVar11) < 0) {
          bVar1 = false;
        }
        lVar11 = lVar11 + 4;
      } while (lVar11 != 0x10);
      local_1048 = local_838 + sVar8 + sVar3;
      if (bVar1) {
        ___sprintf_chk(local_1048,0,0xffffffffffffffff," %s%d,%d,%d,%d",_kMarkerLowLevel,
                       DAT_100015078,DAT_100015074,DAT_10001507c,_gLowLevel);
        sVar6 = _strlen(local_1048);
        local_1048 = local_838 + sVar6 + sVar8 + sVar3;
      }
      pcVar9 = "Magenta,Cyan,Yellow,Black";
    }
    ___sprintf_chk(pcVar13,0,0xffffffffffffffff,pcVar9);
    sVar3 = _strlen(pcVar13);
    pcVar13 = local_c38 + sVar3 + sVar4;
    local_1040 = local_438 + (long)local_1040 + sVar2;
    pcVar9 = "ink,ink,ink,ink";
    break;
  case 1:
    if (DAT_100015084 < 8) {
      if ((_gGetStatusMode != 1) || (bVar1)) {
        if (0 < local_104c) {
          pcVar9 = (char *)_determineStatus(_gStatus);
          if (pcVar9 == (char *)0x0) {
            DAT_100014ff0 = -3;
          }
          else {
            iVar10 = _strcmp(pcVar9,_kTonerLowMsg);
            if (iVar10 == 0) {
              DAT_100014ff0 = 10;
            }
            else {
              iVar10 = _strcmp(pcVar9,_kTonerOutMsg);
              if (iVar10 == 0) {
                DAT_100014ff0 = 0;
              }
            }
          }
        }
      }
      else if (DAT_100014ff0 < 0) {
        DAT_100014ff0 = -1;
      }
      else if (10 < DAT_100014ff0) {
        DAT_100014ff0 = -3;
      }
    }
    ___sprintf_chk(local_1040,0,0xffffffffffffffff,"#000000");
    sVar8 = _strlen(local_1040);
    ___sprintf_chk(local_1048,0,0xffffffffffffffff,"%ld",DAT_100014ff0);
    sVar6 = _strlen(local_1048);
    local_1048 = local_838 + sVar6 + sVar3;
    if (-1 < _gLowLevel) {
      ___sprintf_chk(local_1048,0,0xffffffffffffffff," %s%d",_kMarkerLowLevel);
      sVar7 = _strlen(local_1048);
      local_1048 = local_838 + sVar7 + sVar6 + sVar3;
    }
    local_1040 = local_438 + sVar8 + sVar2;
    ___sprintf_chk(pcVar13,0,0xffffffffffffffff,"Black");
    sVar2 = _strlen(pcVar13);
    pcVar13 = local_c38 + sVar2 + sVar4;
    pcVar9 = "toner";
    break;
  case 2:
    if (DAT_100015084 < 5) {
      lVar11 = 0;
      if (_gGetStatusMode == 1) {
        do {
          if ((&DAT_100014ff0)[lVar11] < 0) {
            (&DAT_100014ff0)[lVar11] = 0xffffffffffffffff;
          }
          else if (10 < (&DAT_100014ff0)[lVar11]) {
            (&DAT_100014ff0)[lVar11] = 0xfffffffffffffffd;
          }
          lVar11 = lVar11 + 1;
        } while (lVar11 != 4);
      }
      else if ((0 < local_104c) && (lVar11 = _determineStatus(_gStatus), lVar11 == 0)) {
        _memset_pattern16(&DAT_100014ff0,&DAT_100010560,0x20);
      }
      ___sprintf_chk(local_1040,0,0xffffffffffffffff,"#00ffff,#ff00ff,#ffff00,#000000");
      sVar8 = _strlen(local_1040);
      ___sprintf_chk(local_1048,0,0xffffffffffffffff,"%ld,%ld,%ld,%ld",DAT_100014ff8,DAT_100015000,
                     DAT_100015008,DAT_100014ff0);
      sVar6 = _strlen(local_1048);
      local_1048 = local_838 + sVar6 + sVar3;
      ___sprintf_chk(pcVar13,0,0xffffffffffffffff,"Cyan,Magenta,Yellow,Black");
      sVar3 = _strlen(pcVar13);
    }
    else {
      lVar11 = 0;
      ___sprintf_chk(local_1040,0,0xffffffffffffffff,"#000000,#00ffff,#ff00ff,#ffff00");
      sVar8 = _strlen(local_1040);
      ___sprintf_chk(local_1048,0,0xffffffffffffffff,"%ld,%ld,%ld,%ld",DAT_100014ff0,DAT_100014ff8,
                     DAT_100015000,DAT_100015008);
      sVar6 = _strlen(local_1048);
      bVar1 = true;
      do {
        if (*(int *)((long)&_gLowLevel + lVar11) < 0) {
          bVar1 = false;
        }
        lVar11 = lVar11 + 4;
      } while (lVar11 != 0x10);
      local_1048 = local_838 + sVar6 + sVar3;
      if (bVar1) {
        ___sprintf_chk(local_1048,0,0xffffffffffffffff," %s%d,%d,%d,%d",_kMarkerLowLevel,_gLowLevel,
                       DAT_100015074,DAT_100015078,DAT_10001507c);
        sVar7 = _strlen(local_1048);
        local_1048 = local_838 + sVar7 + sVar6 + sVar3;
      }
      ___sprintf_chk(pcVar13,0,0xffffffffffffffff,"Black,Cyan,Magenta,Yellow");
      sVar3 = _strlen(pcVar13);
    }
    pcVar13 = local_c38 + sVar3 + sVar4;
    local_1040 = local_438 + sVar8 + sVar2;
    pcVar9 = "toner,toner,toner,toner";
    break;
  case 3:
    if (DAT_100014ff0 < 0) {
      DAT_100014ff0 = -1;
    }
    ___sprintf_chk(local_1040,0,0xffffffffffffffff,"#000000");
    sVar8 = _strlen(local_1040);
    ___sprintf_chk(local_1048,0,0xffffffffffffffff,"%ld",DAT_100014ff0);
    if (-1 < _gLowLevel) {
      ___sprintf_chk(local_1048,0,0xffffffffffffffff," %s%d",_kMarkerLowLevel);
    }
    local_1040 = local_438 + sVar8 + sVar2;
    sVar2 = _strlen(local_1048);
    local_1048 = local_838 + sVar2 + sVar3;
    ___sprintf_chk(pcVar13,0,0xffffffffffffffff,"Black");
    sVar2 = _strlen(pcVar13);
    pcVar13 = local_c38 + sVar2 + sVar4;
    pcVar9 = "ink";
    break;
  default:
    goto switchD_10000d2c3_default;
  }
  lVar11 = 0;
  ___sprintf_chk(pcVar12,0,0xffffffffffffffff,pcVar9);
  sVar2 = _strlen(pcVar12);
  pcVar12 = local_1038 + sVar2 + sVar5;
switchD_10000d2c3_default:
  do {
    if (*(ulong *)((long)&DAT_100015010 + lVar11) < 0xb) {
      iVar10 = _strcmp(local_438,_kMarkerColor);
      if (iVar10 != 0) {
        *local_1040 = ',';
        local_1040 = local_1040 + 1;
        *local_1048 = ',';
        local_1048 = local_1048 + 1;
        *pcVar13 = ',';
        pcVar13 = pcVar13 + 1;
        *pcVar12 = ',';
        pcVar12 = pcVar12 + 1;
      }
      ___sprintf_chk(local_1040,0,0xffffffffffffffff,"none");
      sVar2 = _strlen(local_1040);
      local_1040 = local_1040 + sVar2;
      ___sprintf_chk(local_1048,0,0xffffffffffffffff,"%ld",
                     *(undefined8 *)((long)&DAT_100015010 + lVar11));
      sVar2 = _strlen(local_1048);
      local_1048 = local_1048 + sVar2;
      ___sprintf_chk(pcVar13,0,0xffffffffffffffff,"%s",*(undefined8 *)((long)&_supplyName + lVar11))
      ;
      sVar2 = _strlen(pcVar13);
      pcVar13 = pcVar13 + sVar2;
      ___sprintf_chk(pcVar12,0,0xffffffffffffffff,"%s",*(undefined8 *)((long)&_supplyType + lVar11))
      ;
      sVar2 = _strlen(pcVar12);
      pcVar12 = pcVar12 + sVar2;
    }
    lVar11 = lVar11 + 8;
  } while (lVar11 != 0x60);
  iVar10 = _strcmp(local_438,_kMarkerColor);
  if (iVar10 != 0) {
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s %s %s %s\n","ATTR: ",local_438,local_838,
             local_c38,local_1038);
  }
  if (*(long *)PTR____stack_chk_guard_100012028 != local_38) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return local_104c;
}

