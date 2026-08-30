// CreateBandBuf  entry=1000023a9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CreateBandBuf(unsigned long, short) */

undefined2 CreateBandBuf(ulong param_1,short param_2)

{
  undefined2 uVar1;
  size_t sVar2;
  
  if (param_1 == 0) {
    _fwrite("Invalid Parameter(s).\n",0x16,1,*(FILE **)PTR____stderrp_100012030);
    uVar1 = 1;
  }
  else {
    sVar2 = (long)param_2 * param_1;
    __gOnePageByte = sVar2;
    _Planes = _malloc(sVar2);
    if (_Planes == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ","Insufficient memory!\n");
      uVar1 = 1;
    }
    else {
      ___bzero(_Planes,sVar2);
      uVar1 = 0;
    }
  }
  return uVar1;
}

