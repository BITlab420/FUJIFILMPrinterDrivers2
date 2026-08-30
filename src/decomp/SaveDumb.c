// SaveDumb  entry=10000387e

/* SaveDumb(long*, unsigned char*) */

int SaveDumb(long *param_1,uchar *param_2)

{
  short sVar1;
  long lVar2;
  
  lVar2 = *param_1;
  if ((0x4000 < lVar2 + DAT_100016a70 || _model_language == 3 && (DAT_100016a80 & 0x7f) == 0) &&
     ((code)(DAT_100016220) != (code)0x0)) {
    sVar1 = (int)((undefined8 (*)(void))DAT_100016220)();
    if (sVar1 != 0) {
      _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s","ERROR: ","Sending data failed!\n");
      goto LAB_10000394e;
    }
    lVar2 = *param_1;
  }
  copyData(param_2,(uchar *)(DAT_100016a70 + _send_buf),(short)lVar2);
  DAT_100016a70 = *param_1 + DAT_100016a70;
  DAT_100016a78 = DAT_100016a78 + 1;
  DAT_100016a80 = DAT_100016a80 + 1;
  sVar1 = 0;
LAB_10000394e:
  return (int)sVar1;
}

