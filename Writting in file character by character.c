
#include <stdio.h> 
#include <sys/types.h>
#include <stdlib.h> 
#include <fcntl.h>
#include <unistd.h>

int main(){
  char txt[40] = {' '};
  int fd;
  
  fd = open("a.txt", O_RDONLY);

  if(fd < 0)
  {
    printf("\nError in reading file \n");
    exit(0);
  }

  while(read(fd, txt, sizeof(txt)) > 0)
  {
    write(1, txt, sizeof(txt));
  }
  close(fd);
  return 0;
}