#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cups/cups.h>
#include <cups/raster.h>
int main(int argc, char**argv){
  int w=200,h=200;
  int fd = open("/tmp/opencode/br.raster", O_CREAT|O_WRONLY|O_TRUNC, 0644);
  cups_raster_t *r = cupsRasterOpen(fd, CUPS_RASTER_WRITE);
  cups_page_header2_t hdr; memset(&hdr,0,sizeof(hdr));
  strncpy(hdr.MediaClass,"PwgRaster\0",10);
  strcpy(hdr.cupsPageSizeName,"Letter");
  hdr.cupsWidth=w; hdr.cupsHeight=h;
  hdr.cupsBitsPerPixel=1; hdr.cupsBitsPerColor=1; hdr.cupsNumColors=1;
  hdr.cupsColorSpace=CUPS_CSPACE_K;
  hdr.cupsBytesPerLine=(w+7)/8;
  hdr.HWResolution[0]=300; hdr.HWResolution[1]=300;
  hdr.Duplex=CUPS_FALSE;
  cupsRasterWriteHeader2(r,&hdr);
  unsigned char buf[32]; memset(buf,0xaa,sizeof(buf));
  for(int i=0;i<h;i++) cupsRasterWritePixels(r, buf, hdr.cupsBytesPerLine);
  cupsRasterClose(r); close(fd);
  printf("wrote %dx%d 1-bit raster\n",w,h);
  return 0;
}
