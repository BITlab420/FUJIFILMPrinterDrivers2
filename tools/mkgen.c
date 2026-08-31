/* Generic multi-page CUPS raster generator for 对拍 edge-case testing.
 *
 * Usage: mkgen <out.raster> <pages> <w> <h> <bpp> <res> <duplex> <tumble> <copies> <papersize>
 *   duplex: 0=off 1=long-edge 2=short-edge ; papersize: e.g. Letter A4 Legal A5 Env10
 *
 * Pattern per page: p0=all 0x00, p1=all 0xff, p2=all 0xaa, p3=half (top blank/bottom fill).
 * The MediaType field is perturbed per page so multi-page headers differ.
 */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <cups/cups.h>
#include <cups/raster.h>
int main(int argc, char**argv){
  if(argc<11){fprintf(stderr,"args: out pages w h bpp res duplex tumble copies papersize\n");return 1;}
  const char*out=argv[1];
  int pages=atoi(argv[2]), w=atoi(argv[3]), h=atoi(argv[4]), bpp=atoi(argv[5]);
  int res=atoi(argv[6]), duplex=atoi(argv[7]), tumble=atoi(argv[8]), copies=atoi(argv[9]);
  const char*psz=argv[10];
  int fd=open(out,O_CREAT|O_WRONLY|O_TRUNC,0644);
  cups_raster_t*r=cupsRasterOpen(fd,CUPS_RASTER_WRITE);
  cups_page_header2_t hdr; memset(&hdr,0,sizeof(hdr));
  strncpy(hdr.MediaClass,"PwgRaster",10);
  strcpy(hdr.cupsPageSizeName,psz);
  strcpy(hdr.MediaType,"stationery");
  hdr.cupsWidth=w; hdr.cupsHeight=h;
  hdr.cupsBitsPerColor=bpp; hdr.cupsBitsPerPixel=bpp; hdr.cupsNumColors=1;
  hdr.cupsColorSpace=CUPS_CSPACE_K;
  hdr.cupsBytesPerLine=(w*bpp+7)/8;
  hdr.HWResolution[0]=res; hdr.HWResolution[1]=res;
  hdr.Duplex = duplex!=0;
  hdr.Tumble = tumble!=0;
  hdr.NumCopies = copies;
  hdr.PageSize[0]=w*72/res; hdr.PageSize[1]=h*72/res;
  unsigned char buf[8192];
  for(int pg=0;pg<pages;pg++){
    cupsRasterWriteHeader2(r,&hdr);
    int bpl=hdr.cupsBytesPerLine;
    for(int y=0;y<h;y++){
      unsigned fill = (pg==0)?0x00 : (pg==1)?0xff : (pg==2)?0xaa : ((y<h/2)?0x00:0xff);
      for(int x=0;x<bpl;x++) buf[x]=bpp>1 ? ((pg==3&&y>=h/2)?0xff:fill) : fill;
      if(cupsRasterWritePixels(r,buf,bpl)!=bpl){fprintf(stderr,"write fail\n");return 2;}
    }
    hdr.MediaType[0]='a'+pg;
  }
  cupsRasterClose(r); close(fd);
  printf("wrote %s: %d pages %dx%d bpp%d res%d duplex%d tumble%d copies%d size=%s\n",
         out,pages,w,h,bpp,res,duplex,tumble,copies,psz);
  return 0;
}
