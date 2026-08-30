// CreateNamefromArray  entry=100001a85

/* CreateNamefromArray(unsigned char*, char const*, char const*) */

void CreateNamefromArray(uchar *param_1,char *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  void *pvVar4;
  long lVar5;
  long *plVar6;
  short sVar7;
  char local_78 [64];
  long local_38;
  
  plVar6 = (long *)PTR____stack_chk_guard_100012028;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  local_78[0x30] = '\0';
  local_78[0x31] = '\0';
  local_78[0x32] = '\0';
  local_78[0x33] = '\0';
  local_78[0x34] = '\0';
  local_78[0x35] = '\0';
  local_78[0x36] = '\0';
  local_78[0x37] = '\0';
  local_78[0x38] = '\0';
  local_78[0x39] = '\0';
  local_78[0x3a] = '\0';
  local_78[0x3b] = '\0';
  local_78[0x3c] = '\0';
  local_78[0x3d] = '\0';
  local_78[0x3e] = '\0';
  local_78[0x3f] = '\0';
  local_78[0x20] = '\0';
  local_78[0x21] = '\0';
  local_78[0x22] = '\0';
  local_78[0x23] = '\0';
  local_78[0x24] = '\0';
  local_78[0x25] = '\0';
  local_78[0x26] = '\0';
  local_78[0x27] = '\0';
  local_78[0x28] = '\0';
  local_78[0x29] = '\0';
  local_78[0x2a] = '\0';
  local_78[0x2b] = '\0';
  local_78[0x2c] = '\0';
  local_78[0x2d] = '\0';
  local_78[0x2e] = '\0';
  local_78[0x2f] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  pcVar3 = (char *)GetOption(param_2);
  if (pcVar3 != (char *)0x0) {
    iVar1 = _atoi(pcVar3);
    pvVar4 = _malloc((long)(iVar1 + 1));
    if (pvVar4 != (void *)0x0) {
      lVar5 = 0;
      if (0 < iVar1) {
        sVar7 = 0;
        do {
          local_78[0x30] = '\0';
          local_78[0x31] = '\0';
          local_78[0x32] = '\0';
          local_78[0x33] = '\0';
          local_78[0x34] = '\0';
          local_78[0x35] = '\0';
          local_78[0x36] = '\0';
          local_78[0x37] = '\0';
          local_78[0x38] = '\0';
          local_78[0x39] = '\0';
          local_78[0x3a] = '\0';
          local_78[0x3b] = '\0';
          local_78[0x3c] = '\0';
          local_78[0x3d] = '\0';
          local_78[0x3e] = '\0';
          local_78[0x3f] = '\0';
          local_78[0x20] = '\0';
          local_78[0x21] = '\0';
          local_78[0x22] = '\0';
          local_78[0x23] = '\0';
          local_78[0x24] = '\0';
          local_78[0x25] = '\0';
          local_78[0x26] = '\0';
          local_78[0x27] = '\0';
          local_78[0x28] = '\0';
          local_78[0x29] = '\0';
          local_78[0x2a] = '\0';
          local_78[0x2b] = '\0';
          local_78[0x2c] = '\0';
          local_78[0x2d] = '\0';
          local_78[0x2e] = '\0';
          local_78[0x2f] = '\0';
          local_78[0x10] = '\0';
          local_78[0x11] = '\0';
          local_78[0x12] = '\0';
          local_78[0x13] = '\0';
          local_78[0x14] = '\0';
          local_78[0x15] = '\0';
          local_78[0x16] = '\0';
          local_78[0x17] = '\0';
          local_78[0x18] = '\0';
          local_78[0x19] = '\0';
          local_78[0x1a] = '\0';
          local_78[0x1b] = '\0';
          local_78[0x1c] = '\0';
          local_78[0x1d] = '\0';
          local_78[0x1e] = '\0';
          local_78[0x1f] = '\0';
          local_78[0] = '\0';
          local_78[1] = '\0';
          local_78[2] = '\0';
          local_78[3] = '\0';
          local_78[4] = '\0';
          local_78[5] = '\0';
          local_78[6] = '\0';
          local_78[7] = '\0';
          local_78[8] = '\0';
          local_78[9] = '\0';
          local_78[10] = '\0';
          local_78[0xb] = '\0';
          local_78[0xc] = '\0';
          local_78[0xd] = '\0';
          local_78[0xe] = '\0';
          local_78[0xf] = '\0';
          _sprintf(local_78,param_3);
          pcVar3 = (char *)GetOption(local_78);
          iVar2 = _atoi(pcVar3);
          *(char *)((long)pvVar4 + (long)sVar7) = (char)iVar2;
          sVar7 = sVar7 + 1;
        } while (sVar7 < iVar1);
        lVar5 = (long)sVar7;
      }
      *(undefined1 *)((long)pvVar4 + lVar5) = 0;
      _memcpy(param_1,pvVar4,(long)iVar1);
      param_1[iVar1] = '\0';
    }
    _free(pvVar4);
    plVar6 = (long *)PTR____stack_chk_guard_100012028;
  }
  if (*plVar6 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

