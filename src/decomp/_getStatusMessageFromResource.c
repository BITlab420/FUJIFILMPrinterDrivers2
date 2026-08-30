// _getStatusMessageFromResource  entry=10000cc27

int _getStatusMessageFromResource(undefined8 param_1)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  cVar2 = _isMessageAvailable((void *)0);
  if (cVar2 == '\0') {
    DAT_100014fe0 = (undefined *)0x0;
    iVar3 = 0;
  }
  else {
    ___bzero(&DAT_100016f40,0x200);
    uVar1 = *(undefined8 *)PTR__kCFAllocatorDefault_100012040;
    lVar4 = _CFStringCreateWithCString(uVar1,param_1,0x600);
    if (lVar4 != 0) {
      lVar5 = _copyCommandFilterBundle();
      if (lVar5 != 0) {
        cVar2 = _isMessageAvailable(_kScanUnableMsg);
        if (cVar2 == '\0') {
          lVar6 = _CFStringCreateWithFormat(uVar1,0,&cf__d__d,_gModelInfo,DAT_100015084);
        }
        else {
          lVar6 = _CFStringCreateWithFormat(uVar1,0,&cf__d,_gModelInfo);
        }
        if (lVar6 != 0) {
          lVar7 = _copyPlistfromBundle(lVar5,&cf_StatusMessage);
          if (lVar7 != 0) {
            lVar8 = _CFDictionaryGetValue(lVar7,lVar6);
            if (lVar8 != 0) {
              lVar9 = _getStatusValue(lVar8,&cf_model);
              lVar8 = _getStatusValue(lVar8,lVar4);
              if ((lVar9 != 0) && (lVar8 != 0)) {
                lVar8 = _CFStringCreateWithFormat(uVar1,0,&cf_____);
                if (lVar8 != 0) {
                  lVar9 = _CFBundleCopyLocalizedString(lVar5,lVar8,lVar8,0);
                  if (lVar9 != 0) {
                    cVar2 = _CFEqual(lVar9,lVar8);
                    if (cVar2 == '\0') {
                      cVar2 = _CFStringGetCString(lVar9,&DAT_100016f40,0x200,0x8000100);
                      if (cVar2 != '\0') {
                        DAT_100014fe0 = &DAT_100016f40;
                      }
                    }
                    _CFRelease(lVar9);
                  }
                  _CFRelease(lVar8);
                }
              }
            }
            _CFRelease(lVar7);
          }
          _CFRelease(lVar6);
        }
        _CFRelease(lVar5);
      }
      _CFRelease(lVar4);
    }
    iVar3 = -(uint)(DAT_100014fe0 == (undefined *)0x0);
  }
  return iVar3;
}

