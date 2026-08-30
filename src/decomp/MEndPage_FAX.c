// MEndPage_FAX  entry=100004067

/* MEndPage_FAX(cups_page_header2_s*, sdata*) */

undefined8 MEndPage_FAX(cups_page_header2_s *param_1,sdata *param_2)

{
  if (DAT_100016b20 != (void *)0x0) {
    _free(DAT_100016b20);
  }
  DAT_100016b20 = (void *)0x0;
  DAT_100016b18 = 0;
  DAT_100016b10 = 0;
  DAT_100016b08 = 0;
  return 0;
}

