// _getStatusMessageFromDevice  entry=10000ce0c

ulong _getStatusMessageFromDevice(double param_1)

{
  ulong uVar1;
  
  if (_gGetStatusMode == 1) {
    uVar1 = _getSideChannelSNMPData(_kStatusMsgID);
    return uVar1;
  }
  return (ulong)(uint)((int)((uint)(DAT_100014fe0 == 0 || _gGetStatusMode != 2) << 0x1f) >> 0x1f);
}

