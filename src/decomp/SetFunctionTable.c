// SetFunctionTable  entry=10000680d

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* SetFunctionTable() */

undefined2 SetFunctionTable(void)

{
  if (_model_language == 10) {
    _fun_table = (void *)MBeginJob_FAX;
    DAT_100016200 = (void *)MEndJob_FAX;
    DAT_100016208 = (void *)MBeginPage_FAX;
    DAT_100016210 = (void *)MEndPage_FAX;
    DAT_100016218 = (void *)MSendBandData_FAX;
    DAT_100016220 = (void *)MSendData_FAX;
  }
  else if (_model_language == 3) {
    _fun_table = (void *)MBeginJob;
    DAT_100016200 = (void *)MEndJob;
    DAT_100016208 = (void *)MBeginPage;
    DAT_100016210 = (void *)MEndPage;
    DAT_100016218 = (void *)MSendBandData;
    DAT_100016220 = (void *)MSendData;
  }
  else {
    if (1 < _model_language - 4U) {
      return 1;
    }
    _fun_table = (void *)MBeginJob;
    DAT_100016200 = (void *)MEndJob;
    DAT_100016208 = (void *)MBeginPage;
    DAT_100016210 = (void *)MEndPage;
    DAT_100016218 = (void *)MSendBandData;
    DAT_100016220 = (void *)0x0;
  }
  return 0;
}

