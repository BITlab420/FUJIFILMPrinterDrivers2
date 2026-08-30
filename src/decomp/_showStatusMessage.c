// _showStatusMessage  entry=10000e014

void _showStatusMessage(void)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  FILE *pFVar6;
  
  pcVar4 = (char *)_determineStatus((void *)0);
  puVar1 = PTR____stderrp_100012030;
  pFVar6 = *(FILE **)PTR____stderrp_100012030;
  pcVar5 = "%s%s\n";
  if (pcVar4 != (char *)0x0) {
    _fprintf(pFVar6,"%s%s\n","DEBUG: ",pcVar4);
    cVar2 = _isMessageAvailable(_kGenericMsg);
    if (cVar2 == '\0') {
      return;
    }
    iVar3 = _strcmp(pcVar4,_kTonerOutMsg);
    if ((iVar3 == 0) && (cVar2 = _isMessageAvailable(pcVar4), cVar2 != '\0')) {
      return;
    }
    iVar3 = _strcmp(pcVar4,_kGenericMsg);
    if (iVar3 == 0) {
      pFVar6 = *(FILE **)puVar1;
    }
    else {
      _getStatusMessageFromResource(pcVar4);
      pFVar6 = *(FILE **)puVar1;
      if (DAT_100014fe0 != (char *)0x0) {
        pcVar5 = "%sMessage=%s\n";
        pcVar4 = DAT_100014fe0;
        goto LAB_10000e0d4;
      }
    }
    pcVar5 = "%sMessage=%s\n";
  }
  pcVar4 = "unknown";
LAB_10000e0d4:
  _fprintf(pFVar6,pcVar5,"DEBUG: ",pcVar4);
  return;
}

