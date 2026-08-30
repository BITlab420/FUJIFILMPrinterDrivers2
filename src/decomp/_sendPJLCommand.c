// _sendPJLCommand  entry=100009ea8

void _sendPJLCommand(char *param_1)

{
  _printf("%s","\x1b%-12345X@PJL\n");
  _puts(param_1);
  _printf("%s","\x1b%-12345X");
  _fflush(*(FILE **)PTR____stdoutp_100012038);
  return;
}

