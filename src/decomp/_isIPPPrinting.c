// _isIPPPrinting  entry=10000e484

undefined1 _isIPPPrinting(void)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = _getenv("DEVICE_URI");
  iVar1 = _strncmp("ipp://",pcVar2,6);
  if ((iVar1 != 0) && (pcVar2 = _strstr(pcVar2,"._ipp"), pcVar2 == (char *)0x0)) {
    return 0;
  }
  return 1;
}

