// GetModelType  entry=1000069db

/* GetModelType(ppd_file_s*) */

byte GetModelType(ppd_file_s *param_1)

{
  long lVar1;
  char *pcVar2;
  byte bVar3;
  
  bVar3 = 0;
  lVar1 = _ppdFindAttr(param_1,"DefaultColorSpace",0);
  if (lVar1 != 0) {
    pcVar2 = _strstr(*(char **)(lVar1 + 0xa8),"Gray");
    bVar3 = 3;
    if (pcVar2 == (char *)0x0) {
      lVar1 = _ppdFindAttr(param_1,"APPrinterIconPath",0);
      pcVar2 = _strstr(*(char **)(lVar1 + 0xa8),"BRInk");
      bVar3 = pcVar2 == (char *)0x0 | 4;
    }
  }
  return bVar3;
}

