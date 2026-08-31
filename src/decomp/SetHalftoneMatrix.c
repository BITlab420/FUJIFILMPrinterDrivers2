// SetHalftoneMatrix  entry=100003100

/* SetHalftoneMatrix(cups_page_header2_s*, ppd_file_s*, short*) */

undefined8 SetHalftoneMatrix(cups_page_header2_s *param_1,ppd_file_s *param_2,short *param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  ssize_t sVar7;
  size_t sVar8;
  uint uVar9;
  size_t sVar10;
  char local_448 [8];
  char local_440 [8];
  char local_438 [1024];
  long local_38;
  
  puVar1 = PTR____stack_chk_guard_100012028;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  pcVar5 = (char *)GetOption("BRHalfTonePattern");
  pcVar6 = (char *)GetOption("BRResolution");
  uVar9 = 2;
  if ((pcVar5 != (char *)0x0) && (pcVar6 != (char *)0x0)) {
    iVar2 = _strcmp(pcVar6,"300dpi");
    if (iVar2 == 0) {
      iVar2 = _strcmp(pcVar5,"HalftoneKind4");
      uVar9 = (uint)(iVar2 == 0);
    }
    else {
      iVar2 = _strcmp(pcVar6,"600dpi");
      if (iVar2 == 0) {
        iVar2 = _strcmp(pcVar5,"HalftoneKind4");
        uVar9 = (iVar2 == 0) | 2;
      }
      else {
        iVar2 = _strcmp(pcVar6,"2400x600dpi");
        if (iVar2 == 0) {
          iVar2 = _strcmp(pcVar5,"HalftoneKind4");
          uVar9 = (iVar2 == 0) | 4;
        }
      }
    }
  }
  *param_3 = 0;
  ___bzero(local_438,0x400);
  _strcat(local_438,&_lutfolderpath);
  {
    static const char lutname[6][0x20] = {
      "0300-G13.bin", "0300-T13.bin", "0600-G13.bin",
      "0600-T13.bin", "HQ1200-G13.bin", "HQ1200-T13.bin"
    };
    _strcat(local_438,lutname[uVar9]);
  }
  iVar2 = _open(local_438,0);
  if (-1 < iVar2) {
    local_440[4] = 0;
    local_440[0] = '\0';
    local_440[1] = '\0';
    local_440[2] = '\0';
    local_440[3] = '\0';
    sVar7 = _read(iVar2,local_440,4);
    if ((sVar7 == 4) && (iVar3 = _strcmp(local_440,"BRML"), iVar3 == 0)) {
      local_448[4] = 0;
      local_448[0] = '\0';
      local_448[1] = '\0';
      local_448[2] = '\0';
      local_448[3] = '\0';
      sVar7 = _read(iVar2,local_448,4);
      if (sVar7 == 4) {
        iVar3 = _atoi(&local_448[2]);
        local_448[4] = 0;
        local_448[0] = '\0';
        local_448[1] = '\0';
        local_448[2] = '\0';
        local_448[3] = '\0';
        _lMatrixRow = iVar3;
        sVar7 = _read(iVar2,local_448,4);
        if (((sVar7 == 4) && (iVar4 = _atoi(&local_448[2]), 0 < iVar3)) &&
           (0 < iVar4)) {
          sVar10 = (size_t)(iVar4 * iVar3);
          _pMatrixRow = _malloc(sVar10);
          if ((_pMatrixRow != (undefined *)0x0) &&
             (sVar8 = _read(iVar2,_pMatrixRow,sVar10), sVar8 == sVar10)) {
            _close(iVar2);
            *param_3 = 1;
            goto LAB_10000338c;
          }
        }
      }
    }
  }
  if (_pMatrixRow != (undefined *)0x0) {
    _free(_pMatrixRow);
  }
  _lMatrixRow = 0x20;
  switch((ulong)uVar9) {
  default:
    _pMatrixRow = &_matrix300_Graphics;
    break;
  case 1:
    _pMatrixRow = &_matrix300_Text;
    break;
  case 2:
    _pMatrixRow = &_matrix600_Graphics;
    break;
  case 3:
    _pMatrixRow = &_matrix600_Text;
    break;
  case 4:
    _pMatrixRow = &_matrixHQ1200_Graphics;
    break;
  case 5:
    _pMatrixRow = &_matrixHQ1200_Text;
  }
LAB_10000338c:
  if (*(long *)puVar1 == local_38) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

