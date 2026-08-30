// _setMaintenance  entry=100009e3f

void _setMaintenance(char param_1)

{
  char *pcVar1;
  
  _printf("%s","\x1b%-12345X@PJL\n");
  if (param_1 == '\0') {
    pcVar1 = "@PJL SET NOTIFYBRMAINTENANCE=OFF\n";
  }
  else {
    pcVar1 = "@PJL SET NOTIFYBRMAINTENANCE=ON\n";
  }
  _printf("%s",pcVar1);
  _printf("%s","\x1b%-12345X");
  _fflush(*(FILE **)PTR____stdoutp_100012038);
  return;
}

