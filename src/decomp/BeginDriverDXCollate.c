// BeginDriverDXCollate  entry=100006e2d

/* BeginDriverDXCollate(cups_page_header2_s*, sdata*) */

undefined8 BeginDriverDXCollate(cups_page_header2_s *param_1,sdata *param_2)

{
  void *pvVar1;
  ulong uVar2;
  
  if ((*(ushort *)(param_2 + 10) & 0x600) == 0x400) {
    uVar2 = (ulong)(uint)(*(int *)(param_1 + 0x188) * *(int *)(param_1 + 0x178));
    pvVar1 = _malloc(uVar2);
    _evenPagePtr = pvVar1;
    ___bzero(pvVar1,uVar2);
    _memcpy(pvVar1,_Planes,uVar2);
  }
  return 0;
}

