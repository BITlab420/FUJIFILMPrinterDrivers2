// CancelJob  entry=100003059

/* CancelJob(int) */

void CancelJob(int param_1)

{
  int iVar1;
  
  sendNULLData();
  iVar1 = _gGetStatusMode;
  if (0 < _gGetStatusMode) {
    _gStatus = 0x2711;
    _gGetStatusMode = 0;
    _resetDeviceStatusTimer();
  }
  signal(SIGTERM, SIG_IGN);
  ((void (*)(void))DAT_100016200)();
  EndBackChannel(iVar1);
  _fflush(*(FILE **)PTR____stdoutp_100012038);
  DestroySendBuf();
  DestroyBandBuf();
  DisposGrayMemory();
                    /* WARNING: Subroutine does not return */
  _exit(0);
}

