#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

  struct stat *foo = (struct stat*)malloc(sizeof(foo));
  stat("stat.c", foo);
  printf("FILE SIZE: %llu\n", foo->st_size);
  printf("FILE PERMISSIONS: %d\n", foo->st_mode);
  printf("LAST TIME ACCESS: %ld\n", foo->st_atime);

  return 1;
}
