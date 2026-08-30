// _setDeviceOn  entry=100009bd0

void _setDeviceOn(void)

{
  char cVar1;
  
  _printf("%s","\x1b%-12345X@PJL\n");
  if (_gModelInfo != 0) {
    cVar1 = _isMessageAvailable(_kGenericMsg);
    if ((cVar1 != '\0') && (_gModelInfo != 3)) {
      _printf("%s","@PJL DINQUIRE STRINGCODESET\r\n");
      _printf("%s","@PJL INQUIRE LANG\r\n");
    }
    if (_gModelInfo == 1) {
      _printf("%s","@PJL INFO STATUS\n");
    }
  }
  _printf("%s","@PJL USTATUS DEVICE=ON \n");
  _printf("%s","\x1b%-12345X");
  _fflush(*(FILE **)PTR____stdoutp_100012038);
  return;
}

