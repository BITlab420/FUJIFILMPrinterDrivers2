// _setDevice2Off  entry=100009d95

void _setDevice2Off(void)

{
  _printf("%s","\x1b%-12345X@PJL\n");
  _printf("%s","@PJL USTATUS DEVICE2=OFF \n");
  _printf("%s","\x1b%-12345X");
  _fflush(*(FILE **)PTR____stdoutp_100012038);
  return;
}

