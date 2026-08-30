// saveOddPage  entry=100006d8c

/* saveOddPage(cups_page_header2_s*, sdata*) */

undefined2 saveOddPage(cups_page_header2_s *param_1,sdata *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar1 = *(ushort *)(param_2 + 10);
  if ((uVar1 & 0x100) == 0) {
    return 0;
  }
  uVar4 = *(ushort *)(param_2 + 0x14);
  if ((uVar4 & 2) != 0) {
    uVar4 = uVar4 ^ 2;
    *(ushort *)(param_2 + 0x14) = uVar4;
  }
  if ((uVar1 & 8) == 0) {
    uVar5 = *(ushort *)(param_2 + 0x10);
  }
  else {
    uVar5 = *(ushort *)(param_2 + 0xe);
    *(ushort *)(param_2 + 0x12) = uVar5;
    if ((uVar1 & 4) == 0) goto LAB_100006dcc;
    uVar5 = uVar5 + 1;
  }
  *(ushort *)(param_2 + 0x12) = uVar5;
LAB_100006dcc:
  if ((uVar5 & 1) == 0) {
    if ((*(int *)(param_1 + 0x110) == 1) && (*(int *)(param_1 + 0x170) == 0)) {
      *(ushort *)(param_2 + 0x14) = uVar4 | 2;
    }
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x188);
  iVar3 = *(int *)(param_1 + 0x178);
  _oddPagePtr = _malloc((ulong)(uint)(iVar2 * iVar3));
  _memcpy(_oddPagePtr,_Planes,(ulong)(uint)(iVar2 * iVar3));
  return 1;
}

