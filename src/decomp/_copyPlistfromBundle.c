// _copyPlistfromBundle  entry=10000e0df

undefined8 _copyPlistfromBundle(undefined8 param_1,long param_2)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int local_2c = 0;
  long local_28;
  
  if (param_2 != 0) {
    uVar3 = 0;
    lVar2 = _CFBundleCopyResourceURL(param_1,param_2,&cf_plist,0);
    if (lVar2 != 0) {
      uVar4 = *(undefined8 *)PTR__kCFAllocatorDefault_100012040;
      uVar3 = 0;
      local_28 = _CFURLCreateData(uVar4,lVar2,0x8000100,0);
      cVar1 = _CFURLCreateDataAndPropertiesFromResource(uVar4,lVar2,&local_28,0,0,&local_2c);
      if (((cVar1 == '\x01') && (local_2c == 0)) && (local_28 != 0)) {
        uVar3 = _CFPropertyListCreateFromXMLData(uVar4,local_28,0,0);
        _CFRelease(local_28);
      }
      _CFRelease(lVar2);
    }
    return uVar3;
  }
  uVar3 = *(undefined8 *)PTR__kCFAllocatorDefault_100012040;
  uVar4 = _CFBundleGetInfoDictionary();
  uVar3 = _CFDictionaryCreateCopy(uVar3,uVar4);
  return uVar3;
}

