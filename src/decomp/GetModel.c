// GetModel  entry=100006914

/* GetModel(ppd_file_s*) */

undefined2 GetModel(ppd_file_s *param_1)

{
  short sVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  
  sVar1 = GetModelType(param_1);
  _model_language = (int)sVar1;
  if (sVar1 == 0) {
    return 0;
  }
  lVar3 = _ppdFindOption(param_1,"BROutput");
  if (lVar3 == 0) {
    return 1;
  }
  pcVar4 = (char *)GetOption("com.fujifilm.print.PrintSettings.outputmenu");
  if (pcVar4 == (char *)0x0) {
    return 1;
  }
  iVar2 = _strcmp(pcVar4,"Facsimile");
  if (iVar2 == 0) {
    pcVar4 = (char *)GetOption("com.fujifilm.print.PrintSettings.faxnum");
    pcVar5 = (char *)GetOption("com.fujifilm.print.PrintSettings.count");
    if (((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) ||
       (iVar2 = _strcmp(pcVar4,"NULL"), iVar2 == 0)) {
      if (pcVar5 == (char *)0x0) {
        return 1;
      }
      iVar2 = _atoi(pcVar5);
      if (iVar2 < 1) {
        return 1;
      }
    }
    _model_language = 10;
    return 1;
  }
  return 1;
}

