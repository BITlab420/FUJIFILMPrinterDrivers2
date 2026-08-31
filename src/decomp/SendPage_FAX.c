// SendPage_FAX  entry=1000043cb

/* SendPage_FAX(faxcomp*, cups_page_header2_s*) */

undefined2 SendPage_FAX(faxcomp *param_1,cups_page_header2_s *param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  
  if (_lFAXDataCnt != 0) {
    iVar1 = NumericLength(_lFAXDataCnt);
    iVar2 = _printf("\x1bPUTDATA[%ld,",_lFAXDataCnt);
    if (iVar2 < ((iVar1 * 0x10000 + 0xa0000) >> 0x10)) {
      return 1;
    }
    sVar3 = _fwrite(*(void **)(param_1 + 0x18),_lFAXDataCnt,1,*(FILE **)PTR____stdoutp_100012038);
    if (sVar3 == 0) {
      return 1;
    }
    iVar1 = _printf("%s","]\n");
    if (iVar1 < 2) {
      return 1;
    }
  }
  return 0;
}

