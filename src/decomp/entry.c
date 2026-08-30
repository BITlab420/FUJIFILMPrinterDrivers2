// entry  entry=100001684

void entry(void)

{
  int iVar1;
  long *plVar2;
  int unaff_retaddr;
  
  for (plVar2 = (long *)(&stack0x00000008 + (uint)((unaff_retaddr + 1) * 8)); *plVar2 != 0;
      plVar2 = plVar2 + 1) {
  }
  iVar1 = _main();
                    /* WARNING: Subroutine does not return */
  _exit(iVar1);
}

