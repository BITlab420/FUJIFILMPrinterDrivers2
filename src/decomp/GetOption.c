// GetOption  entry=1000024b7

/* GetOption(char const*) */

long GetOption(char *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = 0;
  if (param_1 != (char *)0x0) {
    lVar1 = _cupsGetOption(param_1,_num_options,_options);
    if ((lVar1 == 0) && (_thisPPD != 0)) {
      lVar2 = _ppdFindOption(_thisPPD,param_1);
      lVar1 = 0;
      if (lVar2 != 0) {
        lVar1 = 0;
        if (0 < *(int *)(lVar2 + 0xb0)) {
          lVar1 = lVar2 + 0x2a;
        }
      }
    }
  }
  return lVar1;
}

