/* Minimal commandtofilter2 stub for the Linux port.
 * The real macOS binary handles calibration/LUT management and PJL command
 * jobs. For basic printing it is not invoked by CUPS. This stub forwards
 * application/vnd.cups-command input to stdout (raw command pass-through).
 */
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  char buf[8192];
  ssize_t n;
  while ((n = read(0, buf, sizeof(buf))) > 0)
    write(1, buf, n);
  return 0;
}
