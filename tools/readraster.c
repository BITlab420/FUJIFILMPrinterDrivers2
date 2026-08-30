#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <cups/raster.h>
int main(int argc, char**argv){
  int fd = open(argv[1], O_RDONLY);
  cups_raster_t *r = cupsRasterOpen(fd, CUPS_RASTER_READ);
  cups_page_header2_t h;
  while (cupsRasterReadHeader2(r, &h)){
    printf("page: %ux%d bpl=%d bpc=%d bpp=%d colors=%d cspace=%d\n",
      h.cupsWidth, h.cupsHeight, h.cupsBytesPerLine, h.cupsBitsPerColor, h.cupsBitsPerPixel, h.cupsNumColors, h.cupsColorSpace);
    break;
  }
  cupsRasterClose(r); close(fd);
  return 0;
}
