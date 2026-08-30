// _isMessageAvailable  entry=100009c96

bool _isMessageAvailable(undefined8 param_1)

{
  char *pcVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  
  pcVar1 = _getenv("PPD");
  lVar2 = _ppdOpenFile(pcVar1);
  if (lVar2 == 0) {
    bVar4 = false;
  }
  else {
    lVar3 = _ppdFindAttr(lVar2,"cupsIPPReason",param_1);
    bVar4 = lVar3 != 0;
    _ppdClose(lVar2);
  }
  return bVar4;
}

