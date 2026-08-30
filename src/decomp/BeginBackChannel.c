// BeginBackChannel  entry=100002cc6

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* BeginBackChannel() */

int BeginBackChannel(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (_model_language != 10) {
    iVar1 = _CheckBackChannel();
    if (0 < iVar1) {
      if (iVar1 == 2) {
        _setDeviceOn();
      }
      signal(SIGALRM, SIG_IGN);
    }
  }
  return iVar1;
}

