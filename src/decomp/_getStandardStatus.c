// _getStandardStatus  entry=10000cb44

char * _getStandardStatus(char *param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  ___bzero(&DAT_100017140,0x200);
  iVar2 = _strncmp(param_1,"com",3);
  if (iVar2 == 0) {
    lVar3 = _CFStringCreateWithCString
                      (*(undefined8 *)PTR__kCFAllocatorDefault_100012040,param_1,0x600);
    param_1 = (char *)0x0;
    if (lVar3 != 0) {
      lVar4 = _copyCommandFilterBundle();
      param_1 = (char *)0x0;
      if (lVar4 != 0) {
        lVar5 = _copyPlistfromBundle(lVar4,&cf_StandardStatus);
        param_1 = (char *)0x0;
        if (lVar5 != 0) {
          lVar6 = _getStatusValue(lVar5,lVar3);
          param_1 = (char *)0x0;
          if (lVar6 != 0) {
            cVar1 = _CFStringGetCString(lVar6,&DAT_100017140,0x200,0x600);
            param_1 = (char *)0x0;
            if (cVar1 != '\0') {
              param_1 = &DAT_100017140;
            }
          }
          _CFRelease(lVar5);
        }
        _CFRelease(lVar4);
      }
      _CFRelease(lVar3);
    }
  }
  return param_1;
}

