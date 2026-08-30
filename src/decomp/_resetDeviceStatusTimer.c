// _resetDeviceStatusTimer  entry=10000e6d0

void _resetDeviceStatusTimer(void)

{
  itimerval local_28;
  
  local_28.it_interval.tv_sec = 0;
  local_28.it_interval.tv_usec = 0;
  local_28.it_value.tv_sec = 0;
  local_28.it_value.tv_usec = 0;
  _setitimer(0,&local_28,(itimerval *)0x0);
  return;
}

