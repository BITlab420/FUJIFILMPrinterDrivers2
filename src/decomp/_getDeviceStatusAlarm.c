// _getDeviceStatusAlarm  entry=10000e709

void _getDeviceStatusAlarm(int param_1)

{
  itimerval local_30;
  
  if (param_1 == 0xe) {
    local_30.it_value.tv_sec = 0;
    local_30.it_value.tv_usec = 0;
    local_30.it_interval.tv_sec = 0;
    local_30.it_interval.tv_usec = 0;
    _setitimer(0,&local_30,(itimerval *)0x0);
    _fflush(*(FILE **)PTR____stdoutp_100012038);
    _getDeviceStatus(0);
    local_30.it_value.tv_sec = 0x1e;
    local_30.it_value.tv_usec = 0;
    local_30.it_interval.tv_sec = 3;
    local_30.it_interval.tv_usec = 0;
    _setitimer(0,&local_30,(itimerval *)0x0);
  }
  return;
}

