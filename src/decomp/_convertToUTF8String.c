// _convertToUTF8String  entry=10000aa4a

undefined * _convertToUTF8String(undefined *param_1)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined *puVar6;
  
  ___bzero(&DAT_100017340,0x200);
  puVar6 = (undefined *)0x0;
  if (param_1 != (undefined *)0x0) {
    if (_gEncodingNum == 0) {
      _getDeviceCharCode();
    }
    puVar6 = param_1;
    if ((_gEncodingNum != 0x8000100) && (puVar6 = (undefined *)0x0, _gEncodingNum != -1)) {
      uVar5 = *(undefined8 *)PTR__kCFAllocatorDefault_100012040;
      lVar2 = _CFStringCreateWithCString(uVar5,param_1);
      puVar6 = (undefined *)0x0;
      if (lVar2 != 0) {
        uVar3 = _CFStringGetLength(lVar2);
        lVar4 = _CFStringCreateMutableCopy(uVar5,uVar3,lVar2);
        puVar6 = (undefined *)0x0;
        if (lVar4 != 0) {
          uVar5 = _CFStringGetLength(lVar4);
          _CFStringFindAndReplace(lVar4,&cf__,&cf___,0,uVar5,0);
          cVar1 = _CFStringGetCString(lVar4,&DAT_100017340,0x200,0x8000100);
          puVar6 = &DAT_100017340;
          if (cVar1 == '\0') {
            puVar6 = (undefined *)0x0;
          }
          _CFRelease(lVar4);
        }
        _CFRelease(lVar2);
      }
    }
  }
  return puVar6;
}

