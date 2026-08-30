// EndPageDriverDuplex  entry=100006e89

/* EndPageDriverDuplex(cups_page_header2_s*, sdata*) */

undefined8 EndPageDriverDuplex(cups_page_header2_s *param_1,sdata *param_2)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x154);
  *(undefined2 *)(param_2 + 0x26) = 0;
  *(undefined2 *)(param_2 + 0x28) = 0;
  uVar2 = *(ushort *)(param_2 + 10);
  if ((uVar2 & 0x101) == 0) {
    EndPageCommand();
    return 0;
  }
  uVar3 = iVar1 - 1;
  if ((uVar2 & 0x804) == 4) {
    EndPageCommand();
    if (_oddPagePtr == (uchar *)0x0) {
      return 0;
    }
    sendOddPage(param_1,param_2,_oddPagePtr);
    uVar2 = *(ushort *)(param_2 + 10);
    if ((uVar2 & 0x400) != 0) {
      _gloopCnt = 0;
      if (uVar3 == 0) {
        _gloopCnt = 0;
        return 0;
      }
      do {
        *(ushort *)(param_2 + 10) = uVar2 | 0x800;
        SendBlankPageEND(param_2,param_1);
        uVar2 = *(ushort *)(param_2 + 10) ^ 0x800;
        *(ushort *)(param_2 + 10) = uVar2;
        _gloopCnt = _gloopCnt + 1;
      } while (_gloopCnt < uVar3);
      return 0;
    }
  }
  else {
    if ((uVar2 & 0x804) == 0) {
      if ((((uVar2 & 0x100) == 0) || (((byte)param_2[0x12] & 1) == 0)) && ((uVar2 & 1) == 0)) {
        EndPageCommand();
        if (*(int *)(param_1 + 0x110) != 1) {
          return 0;
        }
        if (_oddPagePtr != (uchar *)0x0) {
          sendOddPage(param_1,param_2,_oddPagePtr);
          if (((*(ushort *)(param_2 + 10) & 0x400) != 0) && (_evenPagePtr != (uchar *)0x0)) {
            for (; uVar3 != 0; uVar3 = uVar3 - 1) {
              if (*(int *)(param_1 + 0x170) == 0) {
                *(undefined2 *)(param_2 + 0x26) = 1;
              }
              sendOddPage(param_1,param_2,_evenPagePtr);
              *(undefined2 *)(param_2 + 0x26) = 0;
              sendOddPage(param_1,param_2,_oddPagePtr);
            }
            _free(_evenPagePtr);
          }
          _free(_oddPagePtr);
        }
      }
      SendBlankPageEND(param_2,param_1);
      return 0;
    }
    if ((uVar2 & 0x800) == 0) {
      return 0;
    }
    EndPageCommand();
    if (_oddPagePtr == (uchar *)0x0) {
      return 0;
    }
    sendOddPage(param_1,param_2,_oddPagePtr);
    if (_gloopCnt != iVar1 + -2) {
      return 0;
    }
  }
  _free(_oddPagePtr);
  return 0;
}

