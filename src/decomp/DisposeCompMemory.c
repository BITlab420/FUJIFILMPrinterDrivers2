// DisposeCompMemory  entry=1000039ca

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* DisposeCompMemory() */

void DisposeCompMemory(void)

{
  if (DAT_100016aa0 != (void *)0x0) {
    _free(DAT_100016aa0);
  }
  if (DAT_100016ac0 != (void *)0x0) {
    _free(DAT_100016ac0);
  }
  _compData = 0;
  DAT_100016aa0 = (void *)0x0;
  DAT_100016ab0 = 0;
  DAT_100016ac0 = (void *)0x0;
  DAT_100016a98 = 0;
  DAT_100016aa8 = 0;
  DAT_100016ab8 = 0;
  return;
}

