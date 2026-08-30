// _BRPrintErrorMessage  entry=10000185e

void _BRPrintErrorMessage(void)

{
  long lVar1;
  
  lVar1 = _BRLocalizedString((void *)0);
  if (lVar1 != 0) {
    _fprintf(*(FILE **)PTR____stderrp_100012030,"%s%s\n","ERROR: ",(char *)lVar1);
    return;
  }
  return;
}

