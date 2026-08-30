// RawToG3  entry=100004461

/* RawToG3(int, int, unsigned char*, unsigned char*, long*, short) */

undefined8
RawToG3(int param_1,int param_2,uchar *param_3,uchar *param_4,long *param_5,short param_6)

{
  uchar uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  short local_3c [2];
  long local_38;
  
  local_38 = 0;
  local_3c[1] = 0;
  local_3c[0] = 0;
  *param_5 = 0;
  putEOL(param_4,param_5,local_3c);
  if (0 < param_2) {
    lVar2 = 1;
    lVar3 = 0;
    do {
      uVar1 = '\0';
      local_3c[1] = 0;
      lVar4 = 0;
      if (0 < param_1) {
        do {
          lVar3 = get_run_length(param_3,uVar1,&local_38,local_3c + 1);
          Encode(param_4,param_5,uVar1,lVar3,local_3c);
          lVar4 = lVar4 + lVar3;
          uVar1 = -(uVar1 == '\0');
          lVar3 = local_38;
        } while (lVar4 < param_1);
      }
      putEOL(param_4,param_5,local_3c);
      lVar3 = lVar3 + 1;
      bVar5 = lVar2 != param_2;
      lVar2 = lVar2 + 1;
      local_38 = lVar3;
    } while (bVar5);
  }
  lVar2 = 5;
  if (param_6 != 0) {
    do {
      putEOL(param_4,param_5,local_3c);
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  if (local_3c[0] != 0) {
    *param_5 = *param_5 + 1;
  }
  return 1;
}

