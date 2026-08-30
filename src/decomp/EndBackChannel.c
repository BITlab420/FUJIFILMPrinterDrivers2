// EndBackChannel  entry=100002f5a

/* EndBackChannel(int) */

void EndBackChannel(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 2) {
    _setDeviceOff();
  }
  puVar1 = PTR____stderrp_100012030;
  _fprintf(*(FILE **)PTR____stderrp_100012030,"%s\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-cover-open-warning\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-toner-empty-report\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-toner-low-report\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-marker-waste-full-warning\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-marker-waste-almost-full-report\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-media-empty-warning\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-media-jam-warning\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-input-tray-missing-warning\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-cover-open-report\n","STATE: ");
  _fprintf(*(FILE **)puVar1,"%s-output-area-full-warning\n","STATE: ");
  return;
}

