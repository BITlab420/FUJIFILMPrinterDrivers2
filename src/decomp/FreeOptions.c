// FreeOptions  entry=100002494

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* FreeOptions() */

void FreeOptions(void)

{
  _cupsFreeOptions(_num_options,_options);
  _thisPPD = 0;
  return;
}

