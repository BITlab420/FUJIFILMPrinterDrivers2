// _determineModel  entry=10000e225

uint _determineModel(void)

{
  char *pcVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  
  pcVar1 = _getenv("PPD");
  lVar2 = _ppdOpenFile(pcVar1);
  uVar4 = 0xffffffff;
  if (lVar2 != 0) {
    _gModelInfo = 2 - (uint)(*(int *)(lVar2 + 4) == 0);
    DAT_100015084 = *(undefined4 *)(lVar2 + 0x18);
    lVar3 = _ppdFindAttr(lVar2,"cupsCommands",0);
    uVar4 = -(uint)(lVar3 == 0) | 1;
    _ppdClose(lVar2);
  }
  return uVar4;
}

