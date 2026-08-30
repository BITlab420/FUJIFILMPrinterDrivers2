// _setupLanguage  entry=1000016c0

void _setupLanguage(void)

{
  undefined8 uVar1;
  char *pcVar2;
  long lVar3;
  long local_18;
  
  pcVar2 = _getenv("APPLE_LANGUAGE");
  if ((pcVar2 == (char *)0x0) && (pcVar2 = _getenv("LANG"), pcVar2 == (char *)0x0)) {
    return;
  }
  uVar1 = *(undefined8 *)PTR__kCFAllocatorDefault_100012040;
  local_18 = _CFStringCreateWithCString(uVar1,pcVar2,0x8000100);
  if (local_18 != 0) {
    lVar3 = _CFArrayCreate(uVar1,&local_18,1,PTR__kCFTypeArrayCallBacks_100012050);
    if (lVar3 != 0) {
      _CFPreferencesSetAppValue
                (&cf_AppleLanguages,lVar3,
                 *(undefined8 *)PTR__kCFPreferencesCurrentApplication_100012048);
      _setlocale(6,"");
      _CFRelease(lVar3);
    }
    _CFRelease(local_18);
  }
  return;
}

