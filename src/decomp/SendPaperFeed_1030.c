// SendPaperFeed_1030  entry=100005969

/* SendPaperFeed_1030(int) */

undefined2 SendPaperFeed_1030(int param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  char *pcVar4;
  long lVar5;
  bool bVar6;
  
  if (1 < param_1 - 1U) {
    return 0;
  }
  pcVar2 = (char *)GetOption("AP_FIRSTPAGE_InputSlot");
  lVar3 = GetOption("AP_FIRSTPAGE_ManualFeed");
  pcVar4 = (char *)GetOption("BRInputSlot");
  lVar5 = GetOption("ManualFeed");
  if (lVar3 != 0) {
    pcVar2 = "Manual";
  }
  if (lVar5 != 0) {
    pcVar4 = "Manual";
  }
  if (pcVar2 == (char *)0x0) {
    if (1 < param_1) {
      return 0;
    }
LAB_1000059e9:
    pcVar2 = pcVar4;
    if (pcVar4 != (char *)0x0) goto LAB_1000059f1;
LAB_100005a50:
    pcVar2 = "\x1b&l7H";
LAB_100005a5e:
    iVar1 = _printf("%s",pcVar2);
    bVar6 = SBORROW4(iVar1,5);
    iVar1 = iVar1 + -5;
  }
  else {
    if (param_1 != 1) goto LAB_1000059e9;
LAB_1000059f1:
    iVar1 = _strcmp(pcVar2,"Tray1");
    if (iVar1 == 0) {
      pcVar2 = "\x1b&l1h1001H";
    }
    else {
      iVar1 = _strcmp(pcVar2,"Tray2");
      if (iVar1 == 0) {
        pcVar2 = "\x1b&l5h1001H";
      }
      else {
        iVar1 = _strcmp(pcVar2,"Tray3");
        if (iVar1 == 0) {
          pcVar2 = "\x1b&l8h1001H";
        }
        else {
          iVar1 = _strcmp(pcVar2,"MPTray");
          if (iVar1 != 0) {
            iVar1 = _strcmp(pcVar2,"Manual");
            if (iVar1 != 0) goto LAB_100005a50;
            pcVar2 = "\x1b&l2H";
            goto LAB_100005a5e;
          }
          pcVar2 = "\x1b&l4h1001H";
        }
      }
    }
    iVar1 = _printf("%s",pcVar2);
    bVar6 = SBORROW4(iVar1,10);
    iVar1 = iVar1 + -10;
  }
  if (bVar6 == iVar1 < 0) {
    return 0;
  }
  return 1;
}

