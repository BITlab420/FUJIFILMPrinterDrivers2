// SendPageData  entry=100002da3

/* SendPageData(_cups_raster_s*, ppd_file_s*, cups_page_header2_s*, int, sdata*) */

int SendPageData(_cups_raster_s *param_1,ppd_file_s *param_2,cups_page_header2_s *param_3,
                int param_4,sdata *param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  ulong uVar6;
  
  sVar4 = 1;
  if (((param_1 != (_cups_raster_s *)0x0) && (param_3 != (cups_page_header2_s *)0x0)) &&
     (param_2 != (ppd_file_s *)0x0)) {
    *(undefined2 *)(param_5 + 8) = 0;
    if (0 < _gGetStatusMode) {
      _startDeviceStatusTimer();
    }
    uVar6 = 0;
    if (*(int *)(param_3 + 0x178) != 0) {
      uVar3 = (uint)*(ushort *)(param_5 + 4);
      do {
        CreateBandBuf((ulong)*(uint *)(param_3 + 0x188),(short)uVar3);
        iVar2 = _cupsRasterReadPixels(param_1,_Planes,(int)(short)uVar3 * *(int *)(param_3 + 0x188))
        ;
        if (iVar2 == 0) break;
        uVar1 = (int)((int (*)(void *, void *, int))DAT_100016208)(param_3,param_5,param_4);
        if (uVar1 != 0) {
          _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ",
                   "Initializing the printer for new page failed.\n");
LAB_100002eec:
          uVar6 = (ulong)uVar1;
          goto LAB_100002ef7;
        }
        uVar1 = (int)((int (*)(void *, void *))DAT_100016218)(param_3,param_5);
        if (uVar1 != 0) {
          _fprintf(*(FILE **)PTR____stderrp_100012030,"ERROR: Sending line No.%d failed!\n",uVar6);
          goto LAB_100002eec;
        }
        DestroyBandBuf();
        *(short *)(param_5 + 8) = *(short *)(param_5 + 8) + 1;
        uVar3 = (uint)*(short *)(param_5 + 4);
        uVar5 = (int)uVar6 + uVar3;
        uVar6 = (ulong)uVar5;
      } while (uVar5 < *(uint *)(param_3 + 0x178));
      uVar6 = 0;
    }
LAB_100002ef7:
    sVar4 = (short)uVar6;
    if (0 < _gGetStatusMode) {
      _resetDeviceStatusTimer();
    }
  }
  return (int)sVar4;
}

