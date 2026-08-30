// FreeBlankPageMemory  entry=100006be4

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* FreeBlankPageMemory() */

void FreeBlankPageMemory(void)

{
  if (_blankPagePtr != (void *)0x0) {
    _free(_blankPagePtr);
    return;
  }
  return;
}

