#include <stdio.h>
#include <stddef.h>
#include <cups/ppd.h>
int main(void){
  printf("sizeof ppd_size_t=%zu\n", sizeof(ppd_size_t));
  printf("name=%zu width=%zu length=%zu\n", offsetof(ppd_size_t,name), offsetof(ppd_size_t,width), offsetof(ppd_size_t,length));
  return 0;
}
