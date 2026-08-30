// GetMargins  entry=100003698

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* GetMargins(cups_page_header2_s*, short) */

void GetMargins(cups_page_header2_s *param_1,short param_2)

{
  undefined2 uVar1;
  long lVar2;
  ulong uVar3;
  short sVar4;
  if (param_1 == (cups_page_header2_s *)0x0) {
    __margins = 0;
    return;
  }
  uVar3 = (ulong)*(uint *)(param_1 + 0x118);
  sVar4 = (short)((uint)((int)param_2 - ((int)param_2 >> 0x1f)) >> 1) +
          (short)*(undefined4 *)(param_1 + 0x138);
  lVar2 = (long)sVar4 * uVar3;
  sVar4 = (short)((uint)((int)(lVar2 / 0x12) + (int)(lVar2 >> 0x3f)) >> 2) - (sVar4 >> 0xf);
  if (uVar3 < 0x4b0) {
    if (uVar3 == 0x96) {
      sVar4 = sVar4 + -0x14;
      goto LAB_100003729;
    }
    if (uVar3 == 300) {
      sVar4 = sVar4 + -0x28;
      goto LAB_100003729;
    }
  }
  else if (uVar3 == 0x4b0) {
    sVar4 = sVar4 + -0xa0;
    goto LAB_100003729;
  }
  sVar4 = sVar4 + -0x50;
LAB_100003729:
  uVar1 = (undefined2)((int)sVar4 + 7U >> 3);
  __margins = (ulong)CONCAT22(uVar1,uVar1);
  return;
}

