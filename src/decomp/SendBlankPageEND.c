// SendBlankPageEND  entry=100006bfc

/* SendBlankPageEND(sdata*, cups_page_header2_s*) */

int SendBlankPageEND(sdata *param_1,cups_page_header2_s *param_2)

{
  int iVar1;
  int iVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = *(ushort *)(param_1 + 10);
  if ((uVar4 & 1) != 0) {
    uVar4 = uVar4 ^ 1;
    *(ushort *)(param_1 + 10) = uVar4;
  }
  if (((((uVar4 & 2) != 0) &&
       ((int)*(short *)(param_1 + 0x10) % (int)*(short *)(param_1 + 0xc) == 0)) &&
      (((byte)param_1[0xe] & 1) != 0)) && (*(int *)(param_2 + 0x110) == 1)) {
    *(ushort *)(param_1 + 10) = uVar4 | 4;
    CreateBandBuf((ulong)*(uint *)(param_2 + 0x188),*(short *)(param_2 + 0x178));
    sVar3 = (int)((int (*)(void *, void *, int))DAT_100016208)(param_2,param_1,(int)*(short *)(param_1 + 0x10));
    if (sVar3 != 0) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ",
               "Initializing the printer for new page failed.\n");
      goto LAB_100006d40;
    }
    iVar1 = *(int *)(param_2 + 0x188);
    iVar2 = *(int *)(param_2 + 0x178);
    ___bzero(_Planes,(ulong)(uint)(iVar1 * iVar2));
    if (_blankPagePtr != (void *)0x0) {
      _memcpy(_Planes,_blankPagePtr,(ulong)(uint)(iVar1 * iVar2));
    }
    sVar3 = (int)((int (*)(void *, void *))DAT_100016218)(param_2,param_1);
    if (sVar3 != 0) goto LAB_100006d40;
    DestroyBandBuf();
    sVar3 = (int)((int (*)(void *, void *))DAT_100016210)(param_2,param_1);
    if (sVar3 != 0) goto LAB_100006d40;
    uVar4 = *(ushort *)(param_1 + 10);
    if ((uVar4 & 0x400) == 0) {
      *(undefined2 *)(param_1 + 0xe) = 0;
    }
    if ((uVar4 & 4) != 0) {
      *(ushort *)(param_1 + 10) = uVar4 ^ 4;
    }
  }
  sVar3 = 0;
LAB_100006d40:
  return (int)sVar3;
}

