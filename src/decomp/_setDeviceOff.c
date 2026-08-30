// _setDeviceOff  entry=100009ceb

void _setDeviceOff(void)

{
  _printf("%s","\x1b%-12345X@PJL\n");
  _printf("%s","@PJL USTATUS DEVICE=OFF \n");
  _printf("%s","\x1b%-12345X");
  _fflush(*(FILE **)PTR____stdoutp_100012038);
  return;
}

