// _getStatusValue  entry=10000e1b3

long _getStatusValue(void *param_1, void *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar1 = _CFDictionaryGetValue();
  lVar2 = 0;
  if (lVar1 != 0) {
    lVar2 = _CFGetTypeID(lVar1);
    lVar3 = _CFArrayGetTypeID();
    if (lVar2 == lVar3) {
      lVar2 = _CFArrayGetCount(lVar1);
      if (_gModelInfo < lVar2) {
        lVar1 = _CFArrayGetValueAtIndex(lVar1);
      }
      if (lVar1 == 0) {
        return 0;
      }
    }
    lVar3 = _CFGetTypeID(lVar1);
    lVar4 = _CFStringGetTypeID();
    lVar2 = 0;
    if (lVar3 == lVar4) {
      lVar2 = lVar1;
    }
  }
  return lVar2;
}

