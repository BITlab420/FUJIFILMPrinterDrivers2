// FindOptions  entry=100002551

/* FindOptions(ppd_file_s*, char const*) */

bool FindOptions(ppd_file_s *param_1,char *param_2)

{
  long lVar1;
  long lVar2;
  char *pcVar3;
  
  lVar1 = _ppdFindOption((ppd_file_t *)_thisPPD,"BRResolution");
  lVar2 = 0;
  if (*(int *)(lVar1 + 0xb0) != 0) {
    lVar2 = _ppdFindChoice(lVar1,"1200dpi");
  }
  pcVar3 = _strstr((char *)(lVar2 + 0x2a),"600");
  return pcVar3 == (char *)0x0;
}

