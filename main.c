#include "main.h"

int main() {

  struct stat *foo = (struct stat *) malloc(sizeof(struct stat));
  
  if ( stat("main.c", foo) < 0 ) { //stat getting run here
    printf("error: %d - %s\n", errno, strerror(errno));
  } else {

    printf("\nFILE SIZE: %llu bytes\n", foo->st_size);
  

    //mode_t from sys/stat.h has a bunch of useful predefined vars for stuff
        //S_IFMT is one of them, repping entire type of file
    //so using S_IFMT as mask to omit file type and only leave permission info
    printf("FILE PERMISSIONS ('ugo' format): %o\n", ~S_IFMT & foo->st_mode);
    

    //converting epoch time (UNIX timestamp) to human-readable time
    //by using localtime() to conv timer to more convenient 'tm' struct
    time_t atime = foo->st_atime;
    struct tm timestamp = *localtime(&atime);
    
    size_t bufSize = 30;
    char *buf = (char *) malloc( sizeof(char) * bufSize );

    //i think printing asctime() gives the same thing
    //but it's sunday night rn so who gives :)
    strftime(buf, bufSize, "%a %b %d %H:%M:%S %Y\n", &timestamp);
    printf("LAST TIME ACCESSED: %s\n", buf);

    free(buf);
   }

  free(foo);
  return 0;
}
