#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <cups/raster.h>
int main(int argc, char**argv){
  int w=200,h=200;
  int fd = open("/tmp/opencode/ras_half.raster", O_CREAT|O_WRONLY|O_TRUNC, 0644);
  cups_raster_t *r = cupsRasterOpen(fd, CUPS_RASTER_WRITE);
  cups_page_header2_t hdr; memset(&hdr,0,sizeof(hdr));
  strcpy(hdr.cupsPageSizeName,"Letter");
  hdr.cupsWidth=w; hdr.cupsHeight=h;
  hdr.cupsBitsPerPixel=1; hdr.cupsBitsPerColor=1; hdr.cupsNumColors=1;
  hdr.cupsColorSpace=CUPS_CSPACE_K;
  hdr.cupsBytesPerLine=(w+7)/8;
  hdr.HWResolution[0]=300; hdr.HWResolution[1]=300;
  cupsRasterWriteHeader2(r,&hdr);
  unsigned char buf[32];
  for(int y=0;y<h;y++){
    memset(buf, (y<100)?0x00:0xff, sizeof(buf));  // top blank, bottom black
    cupsRasterWritePixels(r, buf, hdr.cupsBytesPerLine);
  }
  cupsRasterClose(r); close(fd);
  printf("wrote ras_half.raster (top blank, bottom filled)\n");
  return 0;
}
