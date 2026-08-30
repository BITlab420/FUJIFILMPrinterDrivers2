// _getDeviceStatusSub  entry=10000b118

undefined8 _getDeviceStatusSub(...)

{
  undefined8 uVar1;
  
  if (_gGetStatusMode == 2) {
    uVar1 = _getBackChannelData((void *)0);
    return uVar1;
  }
  if (_gGetStatusMode == 1) {
    uVar1 = _getSideChannelSNMPData(_kStatusID);
    return uVar1;
  }
  return 0;
}

