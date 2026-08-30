// FunctionLock  entry=1000022be

/* FunctionLock(ppd_file_s*) */

bool FunctionLock(ppd_file_s *param_1)

{
  undefined *puVar1;
  int iVar2;
  size_t sVar3;
  char local_828 [80];
  undefined1 local_7d8;
  char local_428 [1032];
  long local_20;
  
  puVar1 = PTR____stack_chk_guard_100012028;
  local_20 = *(long *)PTR____stack_chk_guard_100012028;
  _strcpy(local_828,_gLoginUserName);
  sVar3 = _strlen(local_828);
  if (sVar3 < 0x51) {
    local_828[sVar3] = '\0';
  }
  else {
    local_7d8 = 0;
  }
  iVar2 = _sprintf(local_428,"@PJL SET LOGINUSER=\"%s\"\n",local_828);
  sVar3 = _fwrite(local_428,(long)iVar2,1,*(FILE **)PTR____stdoutp_100012038);
  if (*(long *)puVar1 == local_20) {
    return sVar3 == 0;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

