// MBeginJob  entry=1000049a4

/* MBeginJob(cups_page_header2_s*, ppd_file_s*, sdata*) */

undefined8 MBeginJob(cups_page_header2_s *param_1,ppd_file_s *param_2,sdata *param_3)

{
  uchar *puVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  tm *ptVar8;
  size_t sVar9;
  long *plVar10;
  undefined8 uVar11;
  bool bVar12;
  time_t local_450;
  short local_448 [4];
  uchar *local_440;
  char local_438 [1024];
  long local_38;
  
  plVar10 = (long *)PTR____stack_chk_guard_100012028;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  DAT_100016a88 = 0;
  *(undefined2 *)(param_3 + 0x14) = 0;
  *(undefined2 *)(param_3 + 4) = *(undefined2 *)(param_1 + 0x178);
  *(undefined2 *)param_3 = 1;
  *(undefined2 *)(param_3 + 2) = 0;
  iVar4 = _printf("%s","\x1b%-12345X@PJL\n");
  uVar11 = 1;
  if (iVar4 < 0xe) goto LAB_100005370;
  SecureFunc(param_2);
  sVar2 = StartJobLogFunc(_gLoginUserName,_gLogJobName);
  if (sVar2 != 0) goto LAB_100005370;
  FunctionLock(param_2);
  pcVar7 = (char *)GetOption("BRResolution");
  if (pcVar7 != (char *)0x0) {
    iVar4 = _strcmp(pcVar7,"300dpi");
    if (iVar4 == 0) {
      pcVar7 = "@PJL SET RESOLUTION = 300\n";
LAB_100004b54:
      iVar4 = _printf("%s",pcVar7);
      if (iVar4 < 0x1a) goto LAB_100005370;
    }
    else {
      iVar4 = _strcmp(pcVar7,"300x600dpi");
      if (iVar4 != 0) {
        iVar4 = _strcmp(pcVar7,"600dpi");
        if (iVar4 == 0) {
          pcVar7 = "@PJL SET RESOLUTION = 600\n";
          goto LAB_100004b54;
        }
        iVar4 = _strcmp(pcVar7,"2400x600dpi");
        if (iVar4 == 0) {
          iVar4 = _printf("%s","@PJL SET RESOLUTION = 1200\n");
          if ((iVar4 < 0x1b) ||
             (iVar4 = _printf("%s","@PJL SET PAPERFEEDSPEED = FULL\n"), iVar4 < 0x1f))
          goto LAB_100005370;
          goto LAB_100004b6e;
        }
      }
      iVar4 = _printf("%s","@PJL SET RESOLUTION = 600\n");
      if (iVar4 < 0x1a) goto LAB_100005370;
      if (*(int *)(param_2 + 0x18) == 8) {
        uVar3 = *(ushort *)(param_3 + 0x14) | 8;
      }
      else {
        uVar3 = *(ushort *)(param_3 + 0x14) | 0x10;
      }
      *(ushort *)(param_3 + 0x14) = uVar3;
    }
  }
LAB_100004b6e:
  if ((*(int *)(param_1 + 0x114) == 0x4b0) && (9 < *(int *)(param_2 + 0x18))) {
    param_3[0x14] = (sdata)((byte)param_3[0x14] | 4);
  }
  pcVar7 = (char *)GetOption("TonerSaveMode");
  if (pcVar7 != (char *)0x0) {
    iVar4 = _strcmp(pcVar7,"ON");
    if (iVar4 == 0) {
      iVar4 = _printf("%s","@PJL SET ECONOMODE = ON\n");
      if (iVar4 < 0x18) goto LAB_100005370;
    }
    else {
      iVar4 = _printf("%s","@PJL SET ECONOMODE = OFF\n");
      if (iVar4 < 0x19) goto LAB_100005370;
    }
  }
  pcVar7 = (char *)GetOption("BRImproveOutput");
  if (pcVar7 != (char *)0x0) {
    iVar4 = _strcmp(pcVar7,"BRLessPaperCurl");
    if (iVar4 == 0) {
      iVar4 = _sprintf(local_438,"%s%s","@PJL SET LESSPAPERCURL=","ON\n");
      iVar5 = _printf("%s",local_438);
      plVar10 = (long *)PTR____stack_chk_guard_100012028;
      if (iVar4 <= iVar5) {
        iVar4 = _sprintf(local_438,"%s%s","@PJL SET FIXINTENSITYUP=","OFF\n");
        iVar5 = _printf("%s",local_438);
        plVar10 = (long *)PTR____stack_chk_guard_100012028;
        if (iVar4 <= iVar5) goto LAB_100004db3;
      }
    }
    else {
      iVar4 = _strcmp(pcVar7,"BRFixIntensity");
      iVar5 = _sprintf(local_438,"%s%s","@PJL SET LESSPAPERCURL=","OFF\n");
      iVar6 = _printf("%s",local_438);
      plVar10 = (long *)PTR____stack_chk_guard_100012028;
      if (iVar4 == 0) {
        if (iVar5 <= iVar6) {
          pcVar7 = "ON\n";
          goto LAB_100004d3d;
        }
      }
      else if (iVar5 <= iVar6) goto LAB_100004cb9;
    }
    goto LAB_10000536b;
  }
  iVar4 = _sprintf(local_438,"%s%s","@PJL SET LESSPAPERCURL=","OFF\n");
  iVar5 = _printf("%s",local_438);
  if (iVar5 < iVar4) goto LAB_10000536b;
LAB_100004cb9:
  pcVar7 = "OFF\n";
LAB_100004d3d:
  iVar4 = _sprintf(local_438,"%s%s","@PJL SET FIXINTENSITYUP=",pcVar7);
  iVar5 = _printf("%s",local_438);
  if (iVar5 < iVar4) goto LAB_10000536b;
LAB_100004db3:
  pcVar7 = (char *)GetOption("BRReduceGhost");
  if (pcVar7 != (char *)0x0) {
    iVar4 = _strcmp(pcVar7,"ON");
    if (iVar4 == 0) {
      pcVar7 = "ON\n";
    }
    else {
      pcVar7 = "OFF\n";
    }
    iVar4 = _sprintf(local_438,"%s%s","@PJL SET TRANSFERLEVELUP=",pcVar7);
    iVar5 = _printf("%s",local_438);
    if (iVar5 < iVar4) goto LAB_10000536b;
  }
  iVar4 = _sprintf(local_438,"%s%s","@PJL SET TRANSFERLEVELUP=","ON\n");
  iVar5 = _printf("%s",local_438);
  if (iVar5 < iVar4) goto LAB_10000536b;
  pcVar7 = (char *)GetOption("com.fujifilm.print.PrintSettings.humiditylevel");
  if (pcVar7 == (char *)0x0) {
    iVar5 = NumericLength(0);
    iVar4 = _printf("@PJL TRANSFERLEVEL=%d\n",0);
    bVar12 = SBORROW4(iVar4,iVar5 + 0x14);
    iVar4 = iVar4 - (iVar5 + 0x14);
LAB_100004ed9:
    uVar11 = 1;
    if (bVar12 != iVar4 < 0) goto LAB_100005370;
  }
  else {
    iVar4 = _atoi(pcVar7);
    if (iVar4 * 0x10000 + 0x2ffffU < 0x5ffff) {
      iVar5 = NumericLength((long)(short)iVar4);
      iVar4 = _printf("@PJL TRANSFERLEVEL=%d\n",(ulong)(uint)(iVar4 * 0x10000 >> 0x10));
      bVar12 = SBORROW4(iVar4,iVar5 + 0x14);
      iVar4 = iVar4 - (iVar5 + 0x14);
      goto LAB_100004ed9;
    }
  }
  uVar11 = 1;
  iVar4 = _printf("%s","@PJL SET MEDIATYPE=");
  if (iVar4 < 0x13) goto LAB_100005370;
  switch(*(undefined4 *)(param_1 + 0x17c)) {
  case 2:
    pcVar7 = "THIN\n";
    goto LAB_100004f9f;
  case 3:
    pcVar7 = "THICK\n";
    goto LAB_100005037;
  case 4:
    iVar4 = _printf("%s","THICK2\n");
    if (iVar4 < 7) goto LAB_100005370;
    break;
  case 5:
    pcVar7 = "BOND\n";
LAB_100004f9f:
    iVar4 = _printf("%s",pcVar7);
    if (iVar4 < 5) goto LAB_100005370;
    break;
  case 6:
    iVar4 = _printf("%s","TRANSPARENCY\n");
    if (iVar4 < 0xd) goto LAB_100005370;
    break;
  case 7:
    iVar4 = _printf("%s","ENVELOPES\n");
    if (iVar4 < 10) goto LAB_100005370;
    break;
  case 8:
    pcVar7 = "ENVTHICK\n";
    goto LAB_100005056;
  case 9:
    pcVar7 = "ENVTHIN\n";
    goto LAB_100004f26;
  case 10:
    pcVar7 = "RECYCLED\n";
    goto LAB_100005056;
  case 0xb:
    pcVar7 = "LABEL\n";
LAB_100005037:
    iVar4 = _printf("%s",pcVar7);
    if (iVar4 < 6) goto LAB_100005370;
    break;
  case 0xc:
    pcVar7 = "POSTCARD\n";
LAB_100005056:
    iVar4 = _printf("%s",pcVar7);
    if (iVar4 < 9) goto LAB_100005370;
    break;
  default:
    pcVar7 = "REGULAR\n";
LAB_100004f26:
    iVar4 = _printf("%s",pcVar7);
    if (iVar4 < 8) goto LAB_100005370;
  }
  sVar2 = GetDensityAdjustment(param_2);
  if ((sVar2 == 1) || (sVar2 = GetSleepMode(param_2), sVar2 == 1)) goto LAB_100005370;
  _time(&local_450);
  ptVar8 = _localtime(&local_450);
  iVar4 = _printf("@PJL SET JOBTIME = \"%04d%02d%02d%02d%02d%02d\"\n",
                  (ulong)(ptVar8->tm_year + 0x76c),(ulong)(ptVar8->tm_mon + 1),
                  (ulong)(uint)ptVar8->tm_mday,(ulong)(uint)ptVar8->tm_hour,
                  (ulong)(uint)ptVar8->tm_min,ptVar8->tm_sec);
  if (iVar4 < 0x24) goto LAB_100005370;
  iVar4 = _printf("%s","@PJL SET ORIENTATION = PORTRAIT\n");
  if (0x1f < iVar4) {
    checkSendCUPSPaper(&local_440,*(short *)(param_1 + 0x164),*(short *)(param_1 + 0x160),
                       (long *)local_448);
    GetMargins(param_1,local_448[0]);
    puVar1 = local_440;
    sVar9 = _strlen((char *)local_440);
    iVar4 = _printf("@PJL SET PAPER = %s\n",puVar1);
    if (((int)sVar9 + 0x12 <= iVar4) &&
       ((((pcVar7 = (char *)GetOption("media"), pcVar7 == (char *)0x0 ||
          (iVar4 = _strcmp("Postcard",pcVar7), iVar4 != 0)) ||
         ((iVar4 = _printf("%s","@PJL SET MEDIATYPE="), 0x12 < iVar4 &&
          (iVar4 = _printf("%s","THICK\n"), 5 < iVar4)))) &&
        (iVar4 = _printf("%s","@PJL SET PAGEPROTECT = AUTO\n"), 0x1b < iVar4)))) {
      pcVar7 = (char *)GetOption("collate");
      if ((pcVar7 == (char *)0x0) || (iVar4 = _strcmp(pcVar7,"false"), iVar4 == 0)) {
        *(undefined2 *)(param_3 + 0x16) = 0;
      }
      else {
        *(undefined2 *)(param_3 + 0x16) = 1;
      }
      pcVar7 = (char *)GetOption("page-set");
      if (pcVar7 != (char *)0x0) {
        iVar4 = _strcmp(pcVar7,"even");
        if (iVar4 == 0) {
          pcVar7 = "@PJL SET MANUALDPX=BACK\n";
        }
        else {
          iVar4 = _strcmp(pcVar7,"odd");
          if (iVar4 != 0) goto LAB_1000052ad;
          pcVar7 = "@PJL SET MANUALDPX=FACE\n";
        }
        iVar4 = _printf("%s",pcVar7);
        if (iVar4 < 0x18) goto LAB_10000536b;
      }
LAB_1000052ad:
      *(undefined2 *)(param_3 + 10) = 0;
      *(undefined2 *)(param_3 + 0x12) = 0;
      driverDuplexModelFlag(param_2,param_1,param_3);
      sendDriverDuplexCommad(param_3);
      iVar4 = _printf("%s","@PJL ENTER LANGUAGE = PCL\n");
      if ((0x19 < iVar4) && (iVar4 = _printf("%s","\x1b" "E"), 1 < iVar4)) {
        if (*(int *)(param_1 + 0x110) == 1) {
          if (*(int *)(param_1 + 0x170) == 0) {
            pcVar7 = "\x1b&l1S";
          }
          else {
            pcVar7 = "\x1b&l2S";
          }
        }
        else {
          pcVar7 = "\x1b&l0S";
        }
        iVar4 = _printf("%s",pcVar7);
        if (4 < iVar4) {
          iVar4 = _strcmp((char *)local_440,"270MM");
          uVar11 = 1;
          if ((iVar4 != 0) || (iVar4 = _printf("%s","\x1b&l1043A"), 7 < iVar4)) {
            pcVar7 = (char *)GetOption("BRReverse");
            if ((pcVar7 != (char *)0x0) && (iVar4 = _strcmp(pcVar7,"ON"), iVar4 == 0)) {
              param_3[0x14] = (sdata)((byte)param_3[0x14] | 2);
            }
            *(undefined4 *)(param_3 + 0xe) = 0;
            pcVar7 = (char *)GetOption("com.apple.print.PrintSettings.PMTotalBeginPages..n.");
            if (pcVar7 == (char *)0x0) {
              *(undefined2 *)(param_3 + 0xc) = 0xffff;
            }
            else {
              iVar4 = _atoi(pcVar7);
              *(short *)(param_3 + 0xc) = (short)iVar4;
              if (((*(int *)(param_1 + 0x110) == 1) && (0x10000 < iVar4 * 0x10000)) &&
                 ((iVar4 * 0x10000 & 0x10000U) != 0)) {
                *(short *)(param_3 + 0xc) = (short)iVar4 + 1;
              }
            }
            pcVar7 = (char *)GetOption("BRSkipBlank");
            if ((pcVar7 != (char *)0x0) && (iVar4 = _strcmp(pcVar7,"ON"), iVar4 == 0)) {
              param_3[10] = (sdata)((byte)param_3[10] | 8);
            }
            SetHalftoneMatrix(param_1,param_2,&DAT_100016f30);
            uVar11 = 0;
          }
          goto LAB_100005370;
        }
      }
    }
  }
LAB_10000536b:
  uVar11 = 1;
LAB_100005370:
  if (*plVar10 != local_38) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return uVar11;
}

