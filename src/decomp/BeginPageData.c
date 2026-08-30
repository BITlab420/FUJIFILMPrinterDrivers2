// BeginPageData  entry=100002d09

/* BeginPageData(ppd_file_s*, cups_page_header2_s*, int, sdata*) */

int BeginPageData(ppd_file_s *param_1,cups_page_header2_s *param_2,int param_3,sdata *param_4)

{
  short sVar1;
  
  signal(SIGTERM, SIG_IGN);
  sVar1 = 0;
  if ((param_2 != (cups_page_header2_s *)0x0) && (param_1 != (ppd_file_s *)0x0)) {
    if (param_3 == 1) {
      sVar1 = (int)((int (*)(void *, void *, void *))_fun_table)(param_2,param_1,param_4);
      if (sVar1 != 0) {
        _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ",
                 "Initializing printer for new job failed.\n");
        goto LAB_100002d90;
      }
    }
    *(short *)(param_4 + 0x10) = *(short *)(param_4 + 0x10) + 1;
    sVar1 = 0;
  }
LAB_100002d90:
  return (int)sVar1;
}

