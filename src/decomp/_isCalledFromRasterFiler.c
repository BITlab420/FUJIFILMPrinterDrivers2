// _isCalledFromRasterFiler  entry=10000e4d5

bool _isCalledFromRasterFiler(void)

{
  long lVar1;
  
  lVar1 = _CFBundleGetMainBundle();
  if (lVar1 != 0) {
    lVar1 = _CFBundleGetIdentifier(lVar1);
    if (lVar1 != 0) {
      lVar1 = _CFStringFind(lVar1,&cf_raster,1);
      return lVar1 != -1;
    }
  }
  return false;
}

