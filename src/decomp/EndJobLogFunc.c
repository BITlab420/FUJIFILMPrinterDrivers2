// EndJobLogFunc  entry=10000224b

/* EndJobLogFunc(unsigned char*) */

bool EndJobLogFunc(uchar *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  char local_a8 [128];
  long local_28;
  
  puVar1 = PTR____stack_chk_guard_100012028;
  local_28 = *(long *)PTR____stack_chk_guard_100012028;
  iVar2 = _sprintf(local_a8,"@PJL EOJ NAME=\"%s\"\n",param_1);
  iVar3 = _printf("%s",local_a8);
  if (*(long *)puVar1 == local_28) {
    return iVar3 < iVar2;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

