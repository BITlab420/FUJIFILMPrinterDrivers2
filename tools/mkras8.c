#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <cups/raster.h>
int main(int argc, char**argv){
  int w=200,h=200, fill=strtol(argv[1],0,0);
  char out[128]; snprintf(out,128,"/tmp/opencode/ras8_%d.raster",fill);
  int fd = open(out, O_CREAT|O_WRONLY|O_TRUNC, 0644);
  cups_raster_t *r = cupsRasterOpen(fd, CUPS_RASTER_WRITE);
  cups_page_header2_t hdr; memset(&hdr,0,sizeof(hdr));
  strcpy(hdr.cupsPageSizeName,"Letter");
  hdr.cupsWidth=w; hdr.cupsHeight=h;
  hdr.cupsBitsPerPixel=8; hdr.cupsBitsPerColor=8; hdr.cupsNumColors=1;
  hdr.cupsColorSpace=CUPS_CSPACE_K;
  hdr.cupsBytesPerLine=w;
  hdr.HWResolution[0]=300; hdr.HWResolution[1]=300;
  cupsRasterWriteHeader2(r,&hdr);
  unsigned char buf[256]; memset(buf,fill,sizeof(buf));
  for(int i=0;i<h;i++) cupsRasterWritePixels(r, buf, hdr.cupsBytesPerLine);
  cupsRasterClose(r); close(fd);
  printf("wrote %s\n",out);
  return 0;
}
