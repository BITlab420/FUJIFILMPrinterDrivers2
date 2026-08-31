// _getBackChannelData  entry=10000a1d3

uint _getBackChannelData(undefined8 param_1)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  size_t sVar8;
  char *pcVar9;
  undefined8 uVar10;
  char *pcVar11;
  long lVar12;
  ulong uVar13;
  bool bVar14;
  double dVar15;
  int local_4a0;
  undefined1 local_49c [4];
  int local_498;
  uint local_494;
  int local_490;
  undefined1 local_48c [4];
  undefined1 local_488 [4];
  uint local_484;
  int local_480;
  int local_47c;
  undefined8 local_478;
  undefined8 uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  undefined8 local_448;
  undefined8 uStack_440;
  char local_438 [1024];
  long local_38;
  
  lVar12 = *(long *)PTR____stack_chk_guard_100012028;
  local_38 = lVar12;
  ___bzero(local_438,0x400);
  DAT_100014fe0 = 0;
  _gStatus = 0;
  DAT_100015008 = 0xffffffffffffffff;
  DAT_100015000 = 0xffffffffffffffff;
  DAT_100014ff8 = 0xffffffffffffffff;
  DAT_100014ff0 = 0xffffffffffffffff;
  uVar3 = _cupsBackChannelRead(param_1,local_438,0x3ff);
  if ((int)uVar3 < 1) {
    if (uVar3 == 0) {
      uVar3 = 0;
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s cupsBackChannelRead 0 bytes.\n","DEBUG: ");
    }
LAB_10000aa00:
    if (lVar12 != local_38) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    return uVar3;
  }
  local_438[(int)uVar3] = '\0';
  _fprintf(*(FILE **)PTR____stderrp_100012030,"%s cupsBackChannelRead %d bytes.\n","DEBUG: ",
           (ulong)uVar3);
  bVar2 = false;
  bVar14 = false;
  uVar13 = 0;
LAB_10000a99b:
  local_448 = 0;
  uStack_440 = 0;
  local_458 = 0;
  uStack_450 = 0;
  local_468 = 0;
  uStack_460 = 0;
  local_478 = 0;
  uStack_470 = 0;
  if ((local_438[(int)uVar13] != '\n') && (local_438[(int)uVar13] != '\r')) {
    lVar7 = 0;
LAB_10000a2dc:
    uVar13 = (ulong)(int)uVar13;
    do {
      cVar1 = local_438[uVar13];
      while( true ) {
        iVar4 = (int)uVar13;
        if ((cVar1 == '\n') || (cVar1 == '\r')) {
          if ((int)uVar3 <= iVar4) goto LAB_10000a9d6;
          iVar4 = _strncmp((char *)&local_478,"CODE=",5);
          if (iVar4 == 0) {
            _gStatus = _atol((char *)((long)&local_478 + 5));
            goto LAB_10000a9d6;
          }
          iVar4 = _strncmp((char *)&local_478,"DISPLAY=",8);
          if (iVar4 == 0) {
            DAT_100014fe0 = _convertToUTF8String(&uStack_470);
            goto LAB_10000a9d6;
          }
          iVar4 = _strncmp((char *)&local_478,"INFOMAINTE=",0xb);
          if (iVar4 == 0) {
            iVar4 = _sscanf((char *)&local_478,"INFOMAINTE=\"A%d,%d,%d,%x,%x\"",&local_484,local_488
                            ,local_48c,&local_480,&local_47c);
            if (((iVar4 != 0) && (uVar5 = local_484 - 1, uVar5 < 4)) && (local_47c != 0)) {
              dVar15 = ((double)local_480 / (double)local_47c) * DAT_1000104c0;
              uVar10 = 0;
              if (((((0.0 < dVar15) && (uVar10 = 10, DAT_1000104c8 <= dVar15)) &&
                   ((uVar10 = 0x19, DAT_1000104d0 <= dVar15 &&
                    ((uVar10 = 0x28, DAT_1000104d8 <= dVar15 &&
                     (uVar10 = 0x37, DAT_1000104e0 <= dVar15)))))) &&
                  (uVar10 = 0x46, DAT_1000104e8 <= dVar15)) &&
                 (uVar10 = 100, dVar15 < DAT_1000104f0)) {
                uVar10 = 0x55;
              }
              (&DAT_100014ff0)[(int)uVar5] = uVar10;
              local_484 = uVar5;
            }
            goto LAB_10000a9d6;
          }
          iVar4 = _strncmp((char *)&local_478,"STATUS=",7);
          if (iVar4 == 0) {
            iVar4 = _strcmp((char *)((long)&local_478 + 7),"TRUE");
            uVar3 = (uint)(iVar4 == 0);
            goto LAB_10000aa00;
          }
          sVar8 = _strlen((char *)&local_478);
          iVar4 = _strncmp((char *)&local_478,"@PJL DINQUIRE STRINGCODESET\r\n",sVar8);
          if (iVar4 == 0) {
            bVar14 = true;
            goto LAB_10000a9d6;
          }
          if (bVar14) {
            iVar4 = _strcmp((char *)&local_478,"HPUTF8");
            if (iVar4 == 0) {
              _gEncodingNum = 0x8000100;
            }
          }
          else {
            if ((_gEncodingNum == 0x8000100) ||
               (iVar4 = _strncmp((char *)&local_478,"@PJL INQUIRE LANG\r\n",sVar8), iVar4 != 0)) {
              if (bVar2) {
                iVar4 = _strcmp((char *)&local_478,"DUCTH");
                if ((((iVar4 != 0) && (iVar4 = _strcmp((char *)&local_478,"DANISH"), iVar4 != 0)) &&
                    ((iVar4 = _strcmp((char *)&local_478,"FRENCH"), iVar4 != 0 &&
                     ((iVar4 = _strcmp((char *)&local_478,"GERMAN"), iVar4 != 0 &&
                      (iVar4 = _strcmp((char *)&local_478,"ENGLISH"), iVar4 != 0)))))) &&
                   ((iVar4 = _strcmp((char *)&local_478,"FINNISH"), iVar4 != 0 &&
                    ((((iVar4 = _strcmp((char *)&local_478,"ITALIAN"), iVar4 != 0 &&
                       (iVar4 = _strcmp((char *)&local_478,"SPANISH"), iVar4 != 0)) &&
                      (iVar4 = _strcmp((char *)&local_478,"SWEDISH"), iVar4 != 0)) &&
                     ((iVar4 = _strcmp((char *)&local_478,"NORWEGIAN"), iVar4 != 0 &&
                      (iVar4 = _strcmp((char *)&local_478,"PORTUGUESE"), iVar4 != 0)))))))) {
                  iVar4 = _strcmp((char *)&local_478,"RUSSIAN");
                  if ((iVar4 == 0) || (iVar4 = _strcmp((char *)&local_478,"BULGARIAN"), iVar4 == 0))
                  {
                    _gEncodingNum = 0x502;
                  }
                  else {
                    iVar4 = _strcmp((char *)&local_478,"CZECH");
                    if (((iVar4 == 0) || (iVar4 = _strcmp((char *)&local_478,"POLISH"), iVar4 == 0))
                       || ((iVar4 = _strcmp((char *)&local_478,"ROMANIAN"), iVar4 == 0 ||
                           ((iVar4 = _strcmp((char *)&local_478,"HUNGARIAN"), iVar4 == 0 ||
                            (iVar4 = _strcmp((char *)&local_478,"SLOVAKIAN"), iVar4 == 0)))))) {
                      _gEncodingNum = 0x501;
                    }
                    else {
                      iVar4 = _strcmp((char *)&local_478,"TURKISH");
                      if (iVar4 == 0) {
                        _gEncodingNum = 0x504;
                      }
                      else {
                        iVar4 = _strcmp((char *)&local_478,"JAPANESE");
                        if (iVar4 == 0) {
                          _gEncodingNum = 0xa01;
                        }
                        else {
                          _gEncodingNum = -1;
                        }
                      }
                    }
                  }
                  bVar14 = false;
                  bVar2 = false;
                  goto LAB_10000a9d6;
                }
                _gEncodingNum = 0x500;
              }
              else {
                sVar8 = _strlen((char *)&local_478);
                iVar4 = _strncmp((char *)&local_478,"@PJL INFO SENDLABELDATA\n",sVar8);
                if (iVar4 == 0) {
                  DAT_100014fec = 1;
                  uVar3 = 0;
                  goto LAB_10000aa00;
                }
                iVar4 = _strncmp((char *)&local_478,"DATA=",5);
                if (iVar4 == 0) {
                  pcVar9 = _malloc(0x3b);
                  iVar4 = _sscanf((char *)&local_478,"DATA=\"8%d,%d,%d,%s\"",&local_494,local_49c,
                                  &local_4a0,pcVar9);
                  if ((iVar4 == 0) || (uVar5 = local_494 - 1, 8 < uVar5)) goto LAB_10000a929;
                  bVar14 = pcVar9 != (char *)0x0;
                  iVar4 = 0;
                  pcVar11 = pcVar9;
                  local_494 = uVar5;
                  iVar6 = 0;
                  if (local_4a0 < 2) goto LAB_10000a8ae;
                  goto joined_r0x00010000a84b;
                }
              }
              bVar14 = false;
              bVar2 = false;
              goto LAB_10000a9d6;
            }
            bVar2 = true;
          }
          bVar14 = false;
          goto LAB_10000a9d6;
        }
        if ((int)uVar3 <= iVar4) goto LAB_10000a9d6;
        if (cVar1 == '\f') break;
        if ((uint)lVar7 < 0x40) {
          uVar13 = (ulong)(iVar4 + 1);
          *(char *)((long)&local_478 + lVar7) = cVar1;
          lVar7 = lVar7 + 1;
          goto LAB_10000a2dc;
        }
      }
      uVar13 = uVar13 + 1;
    } while( true );
  }
  uVar13 = (ulong)((int)uVar13 + 1);
  goto LAB_10000a9d6;
  while( true ) {
    iVar6 = _sscanf(pcVar11,"%x,%n",&local_498,&local_490);
    if ((iVar6 != 0) && (0 < local_490)) {
      pcVar11 = pcVar11 + local_490;
    }
    iVar4 = iVar4 + 1;
    bVar14 = pcVar11 != (char *)0x0;
    iVar6 = iVar4;
    if (local_4a0 + -1 <= iVar4) break;
joined_r0x00010000a84b:
    iVar4 = iVar6;
    if ((pcVar11 == (char *)0x0) || (bVar14 = true, *pcVar11 == -1)) break;
  }
LAB_10000a8ae:
  if ((((iVar4 == local_4a0 + -1) && (bVar14)) && (*pcVar11 != -1)) &&
     (iVar4 = _sscanf(pcVar11,"%x",&local_498), iVar4 != 0)) {
    if ((long)(int)local_494 < 4) {
      (&DAT_100014ff0)[(int)local_494] = (long)local_498;
    }
    else if (4 < (int)local_494) {
      local_494 = local_494 - 5;
      *((int *)((unsigned char *)&_gLowLevel + (int)local_494)) = local_498;
    }
  }
LAB_10000a929:
  _free(pcVar9);
  bVar14 = false;
  bVar2 = false;
  lVar12 = *(long *)PTR____stack_chk_guard_100012028;
LAB_10000a9d6:
  if ((int)uVar3 <= (int)uVar13) goto LAB_10000aa00;
  goto LAB_10000a99b;
}

