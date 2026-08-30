// _canPrintFromAnotherTray  entry=10000e3d2

bool _canPrintFromAnotherTray(void)

{
  char cVar1;
  
  if (_gModelInfo != 0) {
    cVar1 = _isCalledFromRasterFiler();
    return cVar1 != '\0';
  }
  return false;
}

