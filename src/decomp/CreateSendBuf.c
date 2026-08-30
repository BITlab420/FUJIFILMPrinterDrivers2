// CreateSendBuf  entry=100003742

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CreateSendBuf(sdata*) */

undefined8 CreateSendBuf(sdata *param_1)

{
  char *pcVar1;
  FILE *pFVar2;
  
  if (_model_language != 10) {
    if (_model_language == 0) {
      pFVar2 = *(FILE **)PTR____stderrp_100012030;
      pcVar1 = "Unknown printer model.\n";
    }
    else {
      __lCount = 0;
      _send_buf = _malloc(0x4040);
      if (_send_buf != (void *)0x0) {
        DAT_100016a70 = 0;
        DAT_100016a78 = 0;
        DAT_100016a80 = 0;
        return 0;
      }
      pFVar2 = *(FILE **)PTR____stderrp_100012030;
      pcVar1 = "Insufficient memory!\n";
      _send_buf = (void *)0x0;
    }
    _fprintf(pFVar2,"%s%s","ERROR: ",pcVar1);
  }
  return 1;
}

