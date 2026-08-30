// Compress_FAX  entry=100004393

/* Compress_FAX(faxcomp*, cups_page_header2_s*) */

void Compress_FAX(faxcomp *param_1,cups_page_header2_s *param_2)

{
  _lFAXDataCnt = 0;
  RawToG3(0x6c0,*(int *)(param_2 + 0x178),(uchar *)(*(long *)(param_1 + 8) + *(long *)param_1),
          *(uchar **)(param_1 + 0x18),&_lFAXDataCnt,1);
  return;
}

