// _BRPrintInfoMessage  entry=10000182b

void _BRPrintInfoMessage(void)

{
  long lVar1;
  
  lVar1 = _BRLocalizedString((void *)0);
  if (lVar1 != 0) {
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s\n","INFO: ",(char *)lVar1);
    return;
  }
  return;
}

