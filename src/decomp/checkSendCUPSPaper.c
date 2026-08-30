// checkSendCUPSPaper  entry=10000358d

/* checkSendCUPSPaper(unsigned char**, short, short, long*) */

void checkSendCUPSPaper(uchar **param_1,short param_2,short param_3,long *param_4)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  short sVar4;
  uchar *puVar5;
  short sVar6;
  
  *param_4 = 0;
  pcVar3 = _paperArray;
  lVar2 = 0;
  if (_paperArray != '\0') {
    sVar4 = 0;
    do {
      sVar6 = 0;
      puVar5 = &_paperName;
      do {
        iVar1 = _strcmp(pcVar3,(char *)(puVar5 + 0x12));
        if (((iVar1 == 0) && (param_2 <= (short)(&DAT_100015130)[lVar2 * 0x22])) &&
           (param_3 <= (short)(&DAT_100015132)[lVar2 * 0x22])) {
          *param_4 = (long)(short)(&DAT_100015132)[lVar2 * 0x22] - (long)param_3;
          *param_1 = puVar5;
          return;
        }
        puVar5 = puVar5 + 0x32;
        sVar6 = sVar6 + 1;
      } while (sVar6 < 0x18);
      sVar4 = sVar4 + 1;
      lVar2 = (long)sVar4;
      pcVar3 = _paperArray + lVar2 * 0x44;
    } while ((_paperArray)[lVar2 * 0x44] != '\0');
  }
  *param_1 = (uchar *)"USERDEF";
  *param_4 = (0x264 - (long)param_3 << 0x20) + (0x264 - (long)param_3 << 0x22) >> 0x20;
  return;
}

