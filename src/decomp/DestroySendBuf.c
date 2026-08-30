// DestroySendBuf  entry=1000037f3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* DestroySendBuf() */

void DestroySendBuf(void)

{
  if ((_model_language != 0) && (_model_language != 10)) {
    if (_send_buf != (void *)0x0) {
      _free(_send_buf);
    }
    __lCount = 0;
    DAT_100016a88 = 0;
    DAT_100016a80 = 0;
    DAT_100016a78 = 0;
    DAT_100016a70 = 0;
    _send_buf = (void *)0x0;
  }
  return;
}

