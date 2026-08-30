// _convertWarningErrorStatusMessage  entry=10000ce46

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * _convertWarningErrorStatusMessage(long param_1)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  cfstringStruct *pcVar6;
  undefined *puVar7;
  cfstringStruct *pcVar8;
  
  _DAT_1000175b0 = 0;
  uRam00000001000175b8 = 0;
  _DAT_1000175a0 = 0;
  uRam00000001000175a8 = 0;
  _DAT_100017590 = 0;
  uRam0000000100017598 = 0;
  _DAT_100017580 = 0;
  uRam0000000100017588 = 0;
  _DAT_100017570 = 0;
  uRam0000000100017578 = 0;
  _DAT_100017560 = 0;
  uRam0000000100017568 = 0;
  _DAT_100017550 = 0;
  uRam0000000100017558 = 0;
  _DAT_100017540 = 0;
  uRam0000000100017548 = 0;
  if (param_1 == 0) {
    _DAT_100017540 = 0;
    uRam0000000100017548 = 0;
    _DAT_100017550 = 0;
    uRam0000000100017558 = 0;
    _DAT_100017560 = 0;
    uRam0000000100017568 = 0;
    _DAT_100017570 = 0;
    uRam0000000100017578 = 0;
    _DAT_100017580 = 0;
    uRam0000000100017588 = 0;
    _DAT_100017590 = 0;
    uRam0000000100017598 = 0;
    _DAT_1000175a0 = 0;
    uRam00000001000175a8 = 0;
    _DAT_1000175b0 = 0;
    uRam00000001000175b8 = 0;
    return (undefined *)0x0;
  }
  uVar5 = *(undefined8 *)PTR__kCFAllocatorDefault_100012040;
  lVar2 = _CFStringCreateWithCString(uVar5,param_1,0x600);
  if (lVar2 == 0) {
    return (undefined *)0x0;
  }
  uVar3 = _CFStringGetLength(lVar2);
  lVar4 = _CFStringCreateMutableCopy(uVar5,uVar3,lVar2);
  puVar7 = (undefined *)0x0;
  if (lVar4 == 0) goto LAB_10000cf76;
  cVar1 = _CFStringHasSuffix(lVar4,&cf__report);
  if (cVar1 == '\0') {
    cVar1 = _CFStringHasSuffix(lVar4,&cf__warning);
    if (cVar1 != '\0') {
      uVar5 = _CFStringGetLength(lVar4);
      pcVar8 = &cf__warning;
      pcVar6 = &cf__report;
      goto LAB_10000cf3a;
    }
  }
  else {
    uVar5 = _CFStringGetLength(lVar4);
    pcVar8 = &cf__report;
    pcVar6 = &cf__warning;
LAB_10000cf3a:
    _CFStringFindAndReplace(lVar4,pcVar8,pcVar6,0,uVar5,0);
  }
  cVar1 = _CFStringGetCString(lVar4,&DAT_100017540,0x80,0x8000100);
  puVar7 = (undefined *)0x0;
  if (cVar1 != '\0') {
    puVar7 = &DAT_100017540;
  }
  _CFRelease(lVar4);
LAB_10000cf76:
  _CFRelease(lVar2);
  return puVar7;
}

