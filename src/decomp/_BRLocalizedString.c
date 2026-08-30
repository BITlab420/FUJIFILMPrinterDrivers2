// _BRLocalizedString  entry=10000176d

undefined1 * _BRLocalizedString(long param_1)

{
  undefined *puVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined1 *puVar6;
  undefined1 local_238 [512];
  long local_38;
  
  puVar1 = PTR____stack_chk_guard_100012028;
  puVar6 = (undefined1 *)0x0;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  if (param_1 != 0) {
    uVar3 = _CFStringCreateWithCString
                      (*(undefined8 *)PTR__kCFAllocatorDefault_100012040,param_1,0x8000100);
    uVar4 = _CFBundleGetMainBundle();
    puVar6 = (undefined1 *)0x0;
    lVar5 = _CFBundleCopyLocalizedString(uVar4,uVar3,uVar3,0);
    if (lVar5 != 0) {
      cVar2 = _CFStringGetCString(lVar5,local_238,0x200,0x8000100);
      puVar6 = (undefined1 *)0x0;
      if (cVar2 != '\0') {
        puVar6 = local_238;
      }
      _CFRelease(lVar5);
    }
    _CFRelease(uVar3);
  }
  if (*(long *)puVar1 == local_38) {
    return puVar6;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

