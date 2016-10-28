#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

int main() {

  struct stat *foo = (struct stat*)malloc(sizeof(foo));
  stat("stat.c", foo);
  printf("FILE SIZE: %llu\n", foo->st_size);
  printf("FILE PERMISSIONS: %o\n", foo->st_mode);

  struct tm *ktime = (struct tm*)malloc(sizeof(struct tm));
  char buff[100];
  *buff = asctime(gmtime(foo->st_atime));

  //printf("LAST TIME ACCESSED: %d\n", &atime);
  //char buff[20];
  //strftime(buff, 20, "%Y-%m-%d %H:%M:%S", gmtime( foo->st_atime ));
  //printf("LAST TIME ACCESSED: %s/n", buff);

  //feint words

  free(ktime);
  free(foo);
  return 1;
}
