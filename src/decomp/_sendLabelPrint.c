// _sendLabelPrint  entry=100009dea

void _sendLabelPrint(void)

{
  _printf("%s","\x1b%-12345X@PJL\n");
  _printf("%s","@PJL INFO SENDLABELDATA\n");
  _printf("%s","\x1b%-12345X");
  _fflush(*(FILE **)PTR____stdoutp_100012038);
  return;
}

