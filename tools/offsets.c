#include <stdio.h>
#include <stddef.h>
#include <cups/cups.h>
#include <cups/ppd.h>
#include <cups/raster.h>
int main(void){
  printf("ppd_file: language_level=%zu color_device=%zu model_number=%zu num_sizes=%zu sizes=%zu\n",
    offsetof(ppd_file_t, language_level),
    offsetof(ppd_file_t, color_device),
    offsetof(ppd_file_t, model_number),
    offsetof(ppd_file_t, num_sizes),
    offsetof(ppd_file_t, sizes));
  printf("ppd_attr: value=%zu\n", offsetof(ppd_attr_t, value));
  printf("ppd_option: choices=%zu num_choices=%zu\n", offsetof(ppd_option_t, choices), offsetof(ppd_option_t, num_choices));
  printf("ppd_choice: choice=%zu\n", offsetof(ppd_choice_t, choice));
  printf("page_header: HWResolution=%zu cupsWidth=%zu cupsHeight=%zu cupsBitsPerColor=%zu cupsBitsPerPixel=%zu cupsBytesPerLine=%zu cupsColorSpace=%zu\n",
    offsetof(cups_page_header2_t, HWResolution),
    offsetof(cups_page_header2_t, cupsWidth),
    offsetof(cups_page_header2_t, cupsHeight),
    offsetof(cups_page_header2_t, cupsBitsPerColor),
    offsetof(cups_page_header2_t, cupsBitsPerPixel),
    offsetof(cups_page_header2_t, cupsBytesPerLine),
    offsetof(cups_page_header2_t, cupsColorSpace));
  return 0;
}
