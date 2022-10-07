#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
 {
	 int fd;
	 //int   numbofchars;
	 fd = open("teste.txt", O_RDONLY);
	 printf("%s", get_next_line(fd));
	 printf("%s", get_next_line(fd));
	 printf("%s", get_next_line(fd));
	 close(fd);
	 return (0);
 }
