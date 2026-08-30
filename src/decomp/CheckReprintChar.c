// CheckReprintChar  entry=100001c92

/* CheckReprintChar(unsigned char*) */

void CheckReprintChar(uchar *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  do {
    if (bVar1 == 0) {
      return;
    }
    if (bVar1 < 0x20) {
LAB_100001ccb:
      *param_1 = 0x20;
    }
    else if (bVar1 < 0x7c) {
      if ((bVar1 - 0x22 < 0x3b) && ((0x40000002a002701U >> ((ulong)(bVar1 - 0x22) & 0x3f) & 1) != 0)
         ) goto LAB_100001ccb;
    }
    else if (bVar1 == 0x7c) goto LAB_100001ccb;
    bVar1 = param_1[1];
    param_1 = param_1 + 1;
  } while( true );
}

