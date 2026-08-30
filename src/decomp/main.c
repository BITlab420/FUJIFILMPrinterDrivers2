/* Linux CUPS filter entry for rastertodpp268 (black-box port) */
#include "shim.h"
#include "globals.h"

int SendRasterDoc(_cups_raster_s *param_1, ppd_file_s *param_2);
void ParseOptions(char *options);
void FreeOptions(void);
void SetThisPPD(ppd_file_s *param_1);
void sortPaperResult(ppd_file_s *param_1);

int main(int argc, char **argv)
{
  _cups_raster_s *raster;
  ppd_file_s *ppd;
  char *ppd_path;
  int raster_fd = 0;
  int result = 1;

  setbuf(stderr, NULL);
  setlocale(LC_ALL, "");
  __stack_chk_guard = (uintptr_t)0x1234567890abcdefUL;

  if (argc >= 6 && argc <= 7) {
    _gLoginUserName = argv[2];
    if (strlen(argv[2]) > 0x50) argv[2][0x50] = '\0';
    _gLogJobName = argv[3];
    if (strlen(argv[3]) > 0x50) argv[3][0x50] = '\0';

    if (argc == 7) {
      raster_fd = open(argv[6], O_RDONLY);
      if (raster_fd == -1) {
        perror("ERROR: Unable to open raster file - ");
        sleep(1);
        return 1;
      }
    }

    raster = (void *)cupsRasterOpen(raster_fd, CUPS_RASTER_READ);
    if (raster != NULL) {
      ppd_path = getenv("PPD");
      ppd = ppdOpenFile(ppd_path);
      if (ppd != NULL) {
        sortPaperResult(ppd);
        const char *lut = getenv("BR_LUT_PATH");
        if (lut != NULL) {
          snprintf(_lutfolderpath, sizeof(_lutfolderpath), "%s/", lut);
        } else {
          strcpy(_lutfolderpath, "/usr/share/cups/driver/FUJIFILM/rastertodpp268/LUT/");
        }
        _lutModelfolderpath[0] = '\0';
        ParseOptions(argv[5]);
        SetThisPPD(ppd);
        result = SendRasterDoc(raster, ppd);
        FreeOptions();
        ppdClose(ppd);
        cupsRasterClose(raster);
        if (raster_fd != 0) close(raster_fd);
        return result;
      }
      fprintf(stderr, "%s%s", "ERROR: ", "Open PPD file Failed!\n");
      cupsRasterClose(raster);
      if (raster_fd != 0) close(raster_fd);
      return 1;
    }
    fprintf(stderr, "%s%s", "ERROR: ", "Opening raster file failed!\n");
  } else {
    fprintf(stderr, "%s%s", "ERROR: ", "Need arguments: job-id user title copies options [file]\n");
  }
  return 1;
}
