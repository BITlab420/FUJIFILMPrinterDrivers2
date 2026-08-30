// GetDateTime_FAX  entry=100003fd7

/* GetDateTime_FAX(long) */

undefined * GetDateTime_FAX(long param_1)

{
  tm *ptVar1;
  long local_18;
  
  local_18 = param_1;
  ptVar1 = _localtime(&local_18);
  _snprintf(&DAT_100016b30,0x400,"%02d/%02d/%04d(%02d:%02d:%02d)",(ulong)(uint)ptVar1->tm_mday,
            (ulong)(ptVar1->tm_mon + 1),(ulong)(ptVar1->tm_year + 0x76c),ptVar1->tm_hour,
            ptVar1->tm_min,ptVar1->tm_sec);
  return &DAT_100016b30;
}

