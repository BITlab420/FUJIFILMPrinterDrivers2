// _isBRMaintenanceAvailable  entry=10000e422

bool _isBRMaintenanceAvailable(void)

{
  bool bVar1;
  
  switch(_gModelInfo) {
  case 0:
    return 0xd < DAT_100015084;
  case 1:
    bVar1 = 7 < DAT_100015084;
    break;
  case 2:
    bVar1 = 4 < DAT_100015084;
    break;
  case 3:
    bVar1 = true;
    break;
  default:
    bVar1 = false;
  }
  return bVar1;
}

