// ResetFunctionTable  entry=100006a4e

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* ResetFunctionTable() */

void ResetFunctionTable(void)

{
  DAT_100016220 = 0;
  DAT_100016218 = 0;
  DAT_100016210 = 0;
  DAT_100016208 = 0;
  DAT_100016200 = 0;
  _fun_table = 0;
  return;
}

