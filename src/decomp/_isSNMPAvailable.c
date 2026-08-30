// _isSNMPAvailable  entry=100009ef6

undefined4 _isSNMPAvailable(void)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = _getenv("SOFTWARE");
  if ((pcVar2 != (char *)0x0) && (iVar1 = _strncmp("CUPS/1.4.2",pcVar2,10), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

