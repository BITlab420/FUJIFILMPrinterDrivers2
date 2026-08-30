// _canBlackPrint  entry=10000e293

uint _canBlackPrint(void)

{
  char cVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  FILE *pFVar5;
  
  if (_gGetStatusMode == 2) {
    cVar1 = _isCalledFromRasterFiler();
    if (cVar1 != '\0') {
      uVar4 = 0;
      goto LAB_10000e3ca;
    }
    _setDeviceOff();
    _printf("%s","\x1b%-12345X@PJL\n");
    _printf("%s","@PJL INFO BLACKPRINT\n");
    _printf("%s","\x1b%-12345X");
    _printf("%s","\f");
    _setDeviceOn();
    uVar2 = _getBackChannelData(DAT_1000104b0);
  }
  else {
    uVar2 = 0;
    if (_gGetStatusMode == 1) {
      uVar2 = _getSideChannelSNMPData(DAT_1000104b0,_kBlackPrintID);
      DAT_100014fe0 = 0;
      _gStatus = 0;
    }
  }
  uVar4 = 0;
  if (-1 < (int)uVar2) {
    uVar4 = uVar2;
  }
  if (uVar4 == 0) {
    cVar1 = _isMessageAvailable(_kNoBlackPrintMsg);
    if (cVar1 == '\0') goto LAB_10000e3ca;
    pFVar5 = *(FILE **)PTR____stderrp_100012030;
    puVar3 = _kNoBlackPrintMsg;
  }
  else {
    cVar1 = _isMessageAvailable(_kBlackPrintMsg);
    puVar3 = PTR____stderrp_100012030;
    if (cVar1 == '\0') goto LAB_10000e3ca;
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s\n","INFO: ");
    pFVar5 = *(FILE **)puVar3;
    puVar3 = _kBlackPrintMsg;
  }
  _fprintf(pFVar5,"%s+%s\n","STATE: ",puVar3);
LAB_10000e3ca:
  return uVar4 & 0xff;
}

