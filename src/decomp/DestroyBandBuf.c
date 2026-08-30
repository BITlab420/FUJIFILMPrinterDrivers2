// DestroyBandBuf  entry=100002440

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* DestroyBandBuf() */

void DestroyBandBuf(void)

{
  if (_Planes != (void *)0x0) {
    _free(_Planes);
    return;
  }
  return;
}

