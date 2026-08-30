// _copyCommandFilterBundle  entry=10000e514

undefined8 _copyCommandFilterBundle(void)

{
  uint uVar1;
  undefined8 uVar2;
  char *pcVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  
  pcVar3 = _getenv("PPD");
  lVar4 = _ppdOpenFile(pcVar3);
  if (lVar4 != 0) {
    uVar1 = *(uint *)(lVar4 + 0x108);
    if (uVar1 != 0) {
      lVar6 = *(long *)(lVar4 + 0x110);
      lVar9 = 0;
      do {
        pcVar3 = *(char **)(lVar6 + lVar9 * 8);
        if ((pcVar3 != (char *)0x0) && (pcVar5 = _strstr(pcVar3,"commandto"), pcVar5 != (char *)0x0)
           ) {
          uVar2 = *(undefined8 *)PTR__kCFAllocatorDefault_100012040;
          lVar6 = _CFStringCreateWithCString(uVar2,pcVar3,0x600);
          if (lVar6 != 0) {
            uVar7 = _CFStringGetLength(lVar6);
            lVar9 = _CFStringCreateMutableCopy(uVar2,uVar7,lVar6);
            _CFRelease(lVar6);
            lVar6 = _CFStringFind(lVar9,&cf__Library,0);
            if (0 < lVar6) {
              _CFStringDelete(lVar9,0,lVar6);
            }
            lVar6 = _CFStringFind(lVar9,&cf__Contents,0);
            if (lVar6 != -1) {
              lVar8 = _CFStringGetLength(lVar9);
              _CFStringDelete(lVar9,lVar6,lVar8 - lVar6);
            }
            _ppdClose(lVar4);
            if (lVar9 == 0) {
              return 0;
            }
            uVar7 = 0;
            lVar4 = _CFURLCreateWithFileSystemPath(uVar2,lVar9,0,1);
            if (lVar4 != 0) {
              uVar7 = _CFBundleCreate(uVar2,lVar4);
              _CFRelease(lVar4);
            }
            _CFRelease(lVar9);
            return uVar7;
          }
          break;
        }
        lVar9 = lVar9 + 1;
      } while ((uint)lVar9 < uVar1);
    }
    _ppdClose(lVar4);
  }
  return 0;
}

