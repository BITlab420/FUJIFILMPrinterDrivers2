// get_run_length  entry=100004649

/* get_run_length(unsigned char*, unsigned char, long*, short*) */

long get_run_length(uchar *param_1,uchar param_2,long *param_3,short *param_4)

{
  byte bVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  short sVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  lVar8 = *param_3;
  sVar5 = *param_4;
  lVar7 = (long)sVar5;
  lVar6 = lVar8;
  do {
    uVar4 = 0x80 >> ((byte)sVar5 & 0x1f);
    bVar1 = param_1[lVar6];
    sVar3 = (short)(lVar6 >> 0x3f);
    iVar2 = (int)(lVar6 >> 0x3f);
    if (param_2 == '\0') {
      if (bVar1 == 0) goto LAB_1000046b7;
      if (sVar5 < 8) {
        while( true ) {
          if ((uVar4 & 0xff & (uint)bVar1) != 0) goto LAB_100004736;
          sVar5 = sVar5 + 1;
          if (7 < sVar5) break;
          uVar4 = (uVar4 & 0xff) >> 1;
        }
      }
LAB_1000046f6:
      if ((short)((short)lVar6 + ((short)((uint)((int)(lVar6 / 0x36) + iVar2) >> 2) - sVar3) * -0xd8
                 ) == 0xd7) {
        lVar8 = (lVar6 - lVar8) * 8 + 7;
        *param_4 = 0;
LAB_100004745:
        return lVar8 - lVar7;
      }
    }
    else {
      if (bVar1 != 0xff) {
        if (sVar5 < 8) {
          while( true ) {
            if ((uVar4 & 0xff & (uint)bVar1) == 0) goto LAB_100004736;
            sVar5 = sVar5 + 1;
            if (7 < sVar5) break;
            uVar4 = (uVar4 & 0xff) >> 1;
          }
        }
        goto LAB_1000046f6;
      }
LAB_1000046b7:
      if ((short)((short)lVar6 + ((short)((uint)((int)(lVar6 / 0x36) + iVar2) >> 2) - sVar3) * -0xd8
                 ) == 0xd7) {
        lVar8 = lVar8 + -1;
        sVar5 = 0;
LAB_100004736:
        lVar8 = (long)sVar5 + (lVar6 - lVar8) * 8;
        *param_4 = sVar5;
        goto LAB_100004745;
      }
    }
    lVar6 = lVar6 + 1;
    *param_3 = lVar6;
    *param_4 = 0;
    sVar5 = 0;
  } while( true );
}

