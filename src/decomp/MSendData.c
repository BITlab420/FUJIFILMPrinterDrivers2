// MSendData  entry=1000066e8

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MSendData() */

undefined8 MSendData(void)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  
  uVar1 = DAT_100016a78;
  if (DAT_100016a70 != 0) {
    iVar2 = NumericLength(DAT_100016a70 + 2);
    iVar3 = _printf("%ldw%c%c",DAT_100016a70 + 2,0,uVar1 & 0xff);
    if (iVar3 < iVar2 * 0x10000 + 0x30000 >> 0x10) {
      return 1;
    }
    sVar4 = _fwrite(_send_buf,DAT_100016a70,1,*(FILE **)PTR____stdoutp_100012038);
    if (sVar4 == 0) {
      return 1;
    }
  }
  DAT_100016a78 = 0;
  DAT_100016a70 = 0;
  return 0;
}

