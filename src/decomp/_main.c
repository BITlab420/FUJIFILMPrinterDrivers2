// _main  entry=1000027db

int _main(uint param_1,undefined8 *param_2)

{
  undefined *puVar1;
  short sVar2;
  int iVar3;
  size_t sVar4;
  _cups_raster_s *p_Var5;
  char *pcVar6;
  ppd_file_s *ppVar7;
  long lVar8;
  FILE *pFVar9;
  
  puVar1 = PTR____stderrp_100012030;
  _setbuf(*(FILE **)PTR____stderrp_100012030,(char *)0x0);
  _setupLanguage();
  if ((param_1 & 0xfffffffe) == 6) {
    pcVar6 = (char *)param_2[2];
    _gLoginUserName = pcVar6;
    sVar4 = _strlen(pcVar6);
    if (sVar4 < 0x51) {
      pcVar6[sVar4] = '\0';
    }
    else {
      pcVar6[0x50] = '\0';
    }
    pcVar6 = (char *)param_2[3];
    _gLogJobName = pcVar6;
    sVar4 = _strlen(pcVar6);
    if (sVar4 < 0x51) {
      pcVar6[sVar4] = '\0';
    }
    else {
      pcVar6[0x50] = '\0';
    }
    iVar3 = 0;
    if ((param_1 == 7) && (iVar3 = _open((char *)param_2[6],0), iVar3 == -1)) {
      _perror("ERROR: Unable to open raster file - ");
      _sleep(1);
      return 1;
    }
    p_Var5 = (_cups_raster_s *)_cupsRasterOpen(iVar3,0);
    if (p_Var5 != (_cups_raster_s *)0x0) {
      pcVar6 = _getenv("PPD");
      ppVar7 = (ppd_file_s *)_ppdOpenFile(pcVar6);
      if (ppVar7 != (ppd_file_s *)0x0) {
        sortPaperResult(ppVar7);
        pcVar6 = (char *)*param_2;
        ___bzero(&_lutfolderpath,0x400);
        ___bzero(&_lutModelfolderpath,0x400);
        sVar4 = _strlen(&_lutfolderpath);
        *(undefined8 *)(&DAT_100016248 + sVar4) = 0x7265746e6972502f;
        *(undefined8 *)(&_lutfolderpath + sVar4) = 0x7972617262694c2f;
        (&DAT_100016252)[sVar4] = 0;
        *(undefined2 *)(&DAT_100016250 + sVar4) = 0x2f73;
        sVar4 = _strlen(&_lutModelfolderpath);
        *(undefined8 *)(&DAT_100016648 + sVar4) = 0x2f7365686361432f;
        *(undefined8 *)(&_lutModelfolderpath + sVar4) = 0x7972617262694c2f;
        (&DAT_100016650)[sVar4] = 0;
        lVar8 = _ppdFindAttr(ppVar7,"Manufacturer",0);
        if ((lVar8 != 0) && (*(char **)(lVar8 + 0xa8) != (char *)0x0)) {
          _strcat(&_lutfolderpath,*(char **)(lVar8 + 0xa8));
          _strcat(&_lutModelfolderpath,*(char **)(lVar8 + 0xa8));
          if (pcVar6 != (char *)0x0) {
            sVar4 = _strlen(&_lutModelfolderpath);
            *(undefined2 *)(&_lutModelfolderpath + sVar4) = 0x2f;
            _strcat(&_lutModelfolderpath,pcVar6);
          }
          sVar4 = _strlen(&_lutfolderpath);
          *(undefined2 *)(&DAT_100016244 + sVar4) = 0x2f;
          *(undefined4 *)(&_lutfolderpath + sVar4) = 0x54554c2f;
          sVar4 = _strlen(&_lutModelfolderpath);
          *(undefined2 *)(&DAT_100016644 + sVar4) = 0x2f;
          *(undefined4 *)(&_lutModelfolderpath + sVar4) = 0x54554c2f;
        }
        ParseOptions((char *)param_2[5]);
        SetThisPPD(ppVar7);
        sVar2 = SendRasterDoc(p_Var5,ppVar7);
        FreeOptions();
        _ppdClose(ppVar7);
        _cupsRasterClose(p_Var5);
        if (iVar3 != 0) {
          _close(iVar3);
        }
        return (int)sVar2;
      }
      _fprintf(*(FILE **)puVar1,"%s%s","ERROR: ","Open PPD file Failed!\n");
      _cupsRasterClose(p_Var5);
      if (iVar3 == 0) {
        return 1;
      }
      _close(iVar3);
      return 1;
    }
    pFVar9 = *(FILE **)puVar1;
    pcVar6 = "Opening raster file failed!\n";
  }
  else {
    pFVar9 = *(FILE **)puVar1;
    pcVar6 = "Need arguments: job-id user title copies options [file]\n";
  }
  _fprintf(pFVar9,"%s%s","ERROR: ",pcVar6);
  return 1;
}

