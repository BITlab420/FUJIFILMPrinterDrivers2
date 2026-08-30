// _startDeviceStatusTimer  entry=10000e697

void _startDeviceStatusTimer(void)

{
  itimerval local_28;
  
  local_28.it_interval.tv_sec = 0x1e;
  local_28.it_interval.tv_usec = 0;
  local_28.it_value.tv_sec = 3;
  local_28.it_value.tv_usec = 0;
  _setitimer(0,&local_28,(itimerval *)0x0);
  return;
}

