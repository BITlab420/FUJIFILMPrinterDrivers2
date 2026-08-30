// StartJobLogFunc  entry=10000200c

/* StartJobLogFunc(unsigned char*, unsigned char*) */

bool StartJobLogFunc(uchar *param_1,uchar *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  tm *ptVar6;
  bool bVar7;
  time_t local_540;
  char local_538 [256];
  char local_438 [1024];
  long local_38;
  
  puVar1 = PTR____stack_chk_guard_100012028;
  local_38 = *(long *)PTR____stack_chk_guard_100012028;
  bVar7 = true;
  if ((param_1 != (uchar *)0x0) && (param_2 != (uchar *)0x0)) {
    iVar3 = _sprintf(local_438,"@PJL JOB NAME=\"%s\"\n",param_2);
    puVar2 = PTR____stdoutp_100012038;
    sVar5 = _fwrite(local_438,(long)iVar3,1,*(FILE **)PTR____stdoutp_100012038);
    if (sVar5 != 0) {
      iVar3 = _sprintf(local_438,"@PJL PRINTLOG ITEM = %d,%s\n",1,"PRINTER");
      sVar5 = _fwrite(local_438,(long)iVar3,1,*(FILE **)puVar2);
      if (sVar5 != 0) {
        _time(&local_540);
        ptVar6 = _gmtime(&local_540);
        _sprintf(local_538,"%s,%d %s %d %d:%d:%d",PTR_s_Sun_100012320[ptVar6->tm_wday],
                 (ulong)(uint)ptVar6->tm_mday,PTR_s_Jan_100012360[ptVar6->tm_mon],
                 (ulong)(ptVar6->tm_year + 0x76c),ptVar6->tm_hour,ptVar6->tm_min,ptVar6->tm_sec);
        iVar3 = _sprintf(local_438,"@PJL PRINTLOG ITEM = %d,%s\n",2,local_538);
        sVar5 = _fwrite(local_438,(long)iVar3,1,*(FILE **)puVar2);
        if (sVar5 != 0) {
          iVar3 = _sprintf(local_438,"@PJL PRINTLOG ITEM = %d,%s\n",3,param_1);
          sVar5 = _fwrite(local_438,(long)iVar3,1,*(FILE **)puVar2);
          if (sVar5 != 0) {
            iVar3 = _sprintf(local_438,"@PJL PRINTLOG ITEM = %d,%s\n",4,"Macintosh");
            sVar5 = _fwrite(local_438,(long)iVar3,1,*(FILE **)puVar2);
            if (sVar5 != 0) {
              iVar3 = _sprintf(local_438,"@PJL SET STRINGCODESET=%s","HPROMAN8\n");
              iVar4 = _printf("%s",local_438);
              bVar7 = iVar4 < iVar3;
            }
          }
        }
      }
    }
  }
  if (*(long *)puVar1 == local_38) {
    return bVar7;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

