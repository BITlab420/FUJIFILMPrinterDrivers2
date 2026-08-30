// MEndJob_FAX  entry=10000403b

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MEndJob_FAX() */

bool MEndJob_FAX(void)

{
  int iVar1;
  
  iVar1 = _printf("%s","\x1b%-12345X");
  return iVar1 < 9;
}

