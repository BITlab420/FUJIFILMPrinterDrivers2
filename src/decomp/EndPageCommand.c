// EndPageCommand  entry=100005b20

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* EndPageCommand() */

int EndPageCommand(void)

{
  short sVar1;
  int iVar2;
  
  FlushBuf();
  sVar1 = 0;
  iVar2 = _printf("%s","\f");
  if (0 < iVar2) {
    DisposeCompMemory();
    sVar1 = 1;
  }
  return (int)sVar1;
}

