// _getDeviceStatus  entry=10000b143

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _getDeviceStatus(double param_1)

{
  undefined *puVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  char *local_50;
  
  iVar9 = 200;
  if (param_1 < DAT_1000104c8) {
    iVar9 = 500;
  }
  if ((_gStatus == 0) || (iVar4 = 1, _gStatus == 0x2711)) {
    iVar4 = _getDeviceStatusSub();
    puVar1 = PTR____stderrp_100012030;
    if (_gStatus == 0) {
      iVar4 = 0;
    }
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s-%s\n","STATE: ",_kWaitMsg);
    _fprintf(*(FILE **)puVar1,"%s\n","INFO: ");
    cVar3 = _isMessageAvailable(_kBlackPrintMsg);
    if (cVar3 != '\0') {
      _fprintf(*(FILE **)puVar1,"%s-%s\n","STATE: ",_kBlackPrintMsg);
      _fprintf(*(FILE **)puVar1,"%s-%s\n","STATE: ",_kNoBlackPrintMsg);
    }
    if ((_gModelInfo != 0) && (cVar3 = _isCalledFromRasterFiler(), cVar3 != '\0')) {
      _fprintf(*(FILE **)puVar1,"%s-%s\n","STATE: ",_kPaperOutMsg);
    }
  }
  iVar10 = 0;
  do {
    lVar2 = _gStatus;
    if (iVar4 < 1) {
      return iVar4;
    }
    pcVar6 = (char *)_determineStatus(_gStatus);
    if ((pcVar6 == (char *)0x0) ||
       ((iVar5 = _strcmp(pcVar6,_kDiscGuideMsg), iVar5 == 0 && (DAT_100014fec != -1)))) {
      _gStatus = 0;
      DAT_100014fe0 = 0;
      return iVar4;
    }
    pcVar7 = (char *)_getStandardStatus(pcVar6);
    if (pcVar7 != (char *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s+%s\n","STATE: ",pcVar7);
    }
    cVar3 = _isMessageAvailable(_kGenericMsg);
    if ((cVar3 != '\0') &&
       ((iVar5 = _strcmp(pcVar6,_kTonerOutMsg), iVar5 != 0 ||
        (cVar3 = _isMessageAvailable(pcVar6), cVar3 == '\0')))) {
      pcVar8 = _kGenericMsg;
      iVar5 = _strcmp(pcVar6,_kGenericMsg);
      if (((iVar5 == 0) ||
          (iVar5 = _getStatusMessageFromResource(pcVar6), pcVar8 = _kGenericMsg, iVar5 != 0)) &&
         (pcVar6 = pcVar8, _gModelInfo != 0)) {
        _getStatusMessageFromDevice(param_1);
      }
      if (DAT_100014fe0 != 0) {
        _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s\n","INFO: ",pcVar6);
      }
    }
    pcVar8 = _strstr(pcVar6,"-error");
    if ((pcVar8 == (char *)0x0) && (pcVar8 = _strstr(pcVar6,"-warning"), pcVar8 == (char *)0x0)) {
      cVar3 = _isMessageAvailable(pcVar6);
      if (cVar3 == '\0') {
        _gStatus = 0;
        DAT_100014fe0 = 0;
        return iVar4;
      }
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s+%s\n","STATE: ",pcVar6);
      if (param_1 < DAT_1000104c8) {
        if (param_1 != _DAT_100010500) {
          _gStatus = 0;
          DAT_100014fe0 = 0;
          return iVar4;
        }
        if (NAN(param_1) || NAN(_DAT_100010500)) {
          _gStatus = 0;
          DAT_100014fe0 = 0;
          return iVar4;
        }
      }
      _sleep(3);
      _gStatus = 0;
      DAT_100014fe0 = 0;
      return iVar4;
    }
    iVar5 = _strcmp(pcVar6,_kGenericMsg);
    puVar1 = PTR____stderrp_100012030;
    if (iVar5 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s+%s\n","STATE: ",pcVar6);
      if (param_1 < DAT_1000104c8) {
        if (param_1 != _DAT_100010500) {
          _gStatus = 0;
          DAT_100014fe0 = 0;
          return iVar4;
        }
        if (NAN(param_1) || NAN(_DAT_100010500)) {
          _gStatus = 0;
          DAT_100014fe0 = 0;
          return iVar4;
        }
      }
      _sleep(2);
      _fprintf(*(FILE **)puVar1,"%s-%s\n","STATE: ",pcVar6);
      _gStatus = 0;
      DAT_100014fe0 = 0;
      return iVar4;
    }
    cVar3 = _isMessageAvailable(pcVar6);
    puVar1 = PTR____stderrp_100012030;
    if (cVar3 != '\0') {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s+%s\n","STATE: ",pcVar6);
    }
    iVar5 = _strcmp(pcVar6,_kTonerOutMsg);
    local_50 = pcVar7;
    if ((iVar5 == 0) || (iVar5 = _strcmp(pcVar6,_kTonerMissMsg), iVar5 == 0)) {
      if ((_gModelInfo == 0) && (8 < DAT_100015084)) {
        if (DAT_100014fe0 != 0) {
          _fprintf(*(FILE **)puVar1,"%s\n","INFO: ");
          DAT_100014fe0 = 0;
        }
        if ((DAT_100014fe8 != 0) ||
           (cVar3 = _canBlackPrint(), puVar1 = PTR____stderrp_100012030, cVar3 != '\0')) {
          _gStatus = 0;
          DAT_100014fe0 = 0;
          DAT_100014fe8 = 1;
          return iVar4;
        }
        local_50 = (char *)0x0;
        if (pcVar7 != (char *)0x0) {
          _fprintf(*(FILE **)PTR____stderrp_100012030,"%s-%s\n","STATE: ");
          local_50 = (char *)_convertWarningErrorStatusMessage(pcVar7);
          _fprintf(*(FILE **)puVar1,"%s+%s\n","STATE: ");
        }
      }
      else if ((_gModelInfo == 2) && (1 < DAT_100015084)) {
        if (DAT_100014fe0 != 0) {
          _fprintf(*(FILE **)puVar1,"%s\n","INFO: ");
          DAT_100014fe0 = 0;
        }
        if ((param_1 == _DAT_100010500) && (!NAN(param_1) && !NAN(_DAT_100010500))) {
          _gStatus = 0;
          DAT_100014fe8 = 1;
          return iVar4;
        }
        if (DAT_100014fe8 != 0) {
          _gStatus = 0;
          return iVar4;
        }
      }
    }
    else {
      iVar5 = _strcmp(pcVar6,_kPaperOutMsg);
      if (((_gModelInfo != 0) && (iVar5 == 0 || pcVar7 != (char *)0x0)) &&
         (cVar3 = _isCalledFromRasterFiler(), cVar3 != '\0')) {
        _gStatus = 0;
        DAT_100014fe0 = 0;
        return iVar4;
      }
    }
    while (puVar1 = PTR____stderrp_100012030, iVar4 != 0) {
      if ((_gStatus != lVar2 && _gStatus != 0) || (iVar9 <= iVar10)) goto LAB_10000b62a;
      _sleep(3);
      dVar11 = DAT_100010508;
      if (_gModelInfo != 0 || 0.0 < param_1) {
        dVar11 = param_1;
      }
      iVar10 = iVar10 + 1;
      iVar4 = _getDeviceStatusSub(dVar11);
    }
    iVar4 = 0;
LAB_10000b62a:
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s-%s\n","STATE: ",pcVar6);
    if ((local_50 != (char *)0x0) && (iVar5 = _strcmp(pcVar6,local_50), iVar5 != 0)) {
      _fprintf(*(FILE **)puVar1,"%s-%s\n","STATE: ",local_50);
    }
    _fprintf(*(FILE **)puVar1,"%s\n","INFO: ");
    iVar5 = _strcmp(pcVar6,_kTonerOutMsg);
    if ((iVar5 == 0) && (cVar3 = _isMessageAvailable(_kBlackPrintMsg), cVar3 != '\0')) {
      _fprintf(*(FILE **)puVar1,"%s-%s\n","STATE: ",_kBlackPrintMsg);
      _fprintf(*(FILE **)puVar1,"%s-%s\n","STATE: ",_kNoBlackPrintMsg);
    }
    if (iVar9 <= iVar10) {
      _fprintf(*(FILE **)puVar1,"%s Timeout\n","INFO: ");
      return iVar4;
    }
  } while( true );
}

