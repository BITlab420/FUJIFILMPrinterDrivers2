// setCommand  entry=100003b51

/* setCommand(char*, unsigned char*, short) */

void setCommand(char *param_1,uchar *param_2,short param_3)

{
  if (0 < param_3) {
    do {
      *param_2 = *param_1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

