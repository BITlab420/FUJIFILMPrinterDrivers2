// sendOddPage  entry=10000707b

/* sendOddPage(cups_page_header2_s*, sdata*, unsigned char*) */

int sendOddPage(cups_page_header2_s *param_1,sdata *param_2,uchar *param_3)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  param_2[0xb] = (sdata)((byte)param_2[0xb] | 2);
  CreateBandBuf((ulong)*(uint *)(param_1 + 0x188),*(short *)(param_1 + 0x178));
  sVar3 = (int)((int (*)(void *, void *, int))DAT_100016208)(param_1,param_2,(int)*(short *)(param_2 + 0x12));
  if (sVar3 == 0) {
    iVar1 = *(int *)(param_1 + 0x188);
    iVar2 = *(int *)(param_1 + 0x178);
    ___bzero(_Planes,(ulong)(uint)(iVar1 * iVar2));
    if (param_3 != (uchar *)0x0) {
      _memcpy(_Planes,param_3,(ulong)(uint)(iVar1 * iVar2));
    }
    if (*(short *)(param_2 + 0x26) == 1) {
      param_2[0x14] = (sdata)((byte)param_2[0x14] | 2);
    }
    sVar3 = (int)((int (*)(void *, void *))DAT_100016218)(param_1,param_2);
    if (sVar3 == 0) {
      DestroyBandBuf();
      EndPageCommand();
      if ((*(ushort *)(param_2 + 10) & 0x200) != 0) {
        *(ushort *)(param_2 + 10) = *(ushort *)(param_2 + 10) ^ 0x200;
      }
      sVar3 = 0;
    }
  }
  else {
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ",
             "Initializing the printer for new page failed.\n");
  }
  return (int)sVar3;
}

