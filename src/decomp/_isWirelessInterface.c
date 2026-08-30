// _isWirelessInterface  entry=10000e3f2

bool _isWirelessInterface(void)

{
  int iVar1;
  
  if (_gGetStatusMode == 2) {
    return false;
  }
  iVar1 = _getSideChannelSNMPData(DAT_1000104c8,_kInterfaceID);
  return iVar1 == 2;
}

