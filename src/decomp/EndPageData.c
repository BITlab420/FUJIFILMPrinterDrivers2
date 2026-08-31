// EndPageData  entry=100002f14

/* EndPageData(cups_page_header2_s*, sdata*) */

int EndPageData(cups_page_header2_s *param_1,sdata *param_2)

{
  short sVar1;
  
  sVar1 = (int)((int (*)(void *, void *))DAT_100016210)(param_1,param_2);
  if (sVar1 == 0) {
    _fflush(*(FILE **)PTR____stdoutp_100012038);
    if (0 < _gGetStatusMode) {
      _getDeviceStatus(0);
    }
    signal(SIGTERM, SIG_IGN);
    sVar1 = 0;
  }
  return (int)sVar1;
}

