// CheckOptionValue  entry=100002517

/* CheckOptionValue(char const*, char const*) */

bool CheckOptionValue(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  
  bVar3 = false;
  if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
    pcVar2 = (char *)GetOption(param_1);
    if (pcVar2 != (char *)0x0) {
      iVar1 = _strcmp(pcVar2,param_2);
      bVar3 = iVar1 == 0;
    }
  }
  return bVar3;
}

