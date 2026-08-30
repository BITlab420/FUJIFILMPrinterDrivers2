// CreateBandBuf2  entry=100006787

/* CreateBandBuf2(sdata*) */

bool CreateBandBuf2(sdata *param_1)

{
  short sVar1;
  short sVar2;
  sdata *psVar3;
  sdata *psVar4;
  bool bVar5;
  
  if (((byte)param_1[0x14] & 0x18) == 0) {
    psVar3 = param_1 + 0x1c;
    psVar4 = param_1 + 4;
  }
  else {
    psVar3 = param_1 + 0x1a;
    psVar4 = param_1 + 0x18;
  }
  sVar1 = *(short *)psVar3;
  sVar2 = *(short *)psVar4;
  _Planes = _malloc((long)((int)sVar2 * (int)sVar1));
  bVar5 = _Planes == (void *)0x0;
  if (bVar5) {
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ","Insufficient memory!\n");
  }
  else {
    ___bzero(_Planes,(long)((int)sVar2 * (int)sVar1));
  }
  return bVar5;
}

