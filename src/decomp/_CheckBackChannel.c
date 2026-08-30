// _CheckBackChannel  entry=100009f2e

int _CheckBackChannel(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  int iVar5;
  int local_28;
  undefined1 local_21;
  int local_20;
  char local_19;
  
  iVar2 = _determineModel();
  iVar5 = -1;
  if (((0 < iVar2) && (pcVar3 = _getenv("SOFTWARE"), pcVar3 != (char *)0x0)) &&
     (iVar2 = _strncmp("CUPS/1.3",pcVar3,8), iVar2 < 1)) {
    pcVar3 = _getenv("DEVICE_URI");
    iVar2 = _strncmp("usb://",pcVar3,6);
    if ((iVar2 != 0) && (pcVar3 = _strstr(pcVar3,"._riousbprint._tcp."), pcVar3 == (char *)0x0)) {
      cVar1 = _isIPPPrinting();
      if ((cVar1 != '\0') && (cVar1 = _isCalledFromRasterFiler(), cVar1 != '\0')) {
        return -1;
      }
      local_28 = 1;
      cVar1 = _isCalledFromRasterFiler();
      iVar2 = _cupsSideChannelDoRequest
                        (CUPS_SC_CMD_GET_BIDI,(char *)&local_21,(int *)&local_28,5.0);
      bVar4 = local_28 == 1 && iVar2 == 1;
      return (bVar4 - 1) + (uint)bVar4;
    }
    local_20 = 1;
    iVar2 = _cupsSideChannelDoRequest(CUPS_SC_CMD_GET_BIDI,(char *)&local_19,(int *)&local_20,5.0);
    if (((iVar2 == 1) && (local_20 == 1)) && (local_19 == '\x01')) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s Use Back Channel (PJL)\n","DEBUG: ");
      iVar5 = 2;
    }
  }
  return iVar5;
}

