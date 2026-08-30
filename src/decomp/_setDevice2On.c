// _setDevice2On  entry=100009d40

void _setDevice2On(void)

{
  _printf("%s","\x1b%-12345X@PJL\n");
  _printf("%s","@PJL USTATUS DEVICE2=ON \n");
  _printf("%s","\x1b%-12345X");
  _fflush(*(FILE **)PTR____stdoutp_100012038);
  return;
}

