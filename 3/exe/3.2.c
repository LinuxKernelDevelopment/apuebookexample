#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int my_dup2(int fd, int fd2);

int
main(void)
{
	int fd2 = 10, myfd;
	int fd = open("haha", O_CREAT | O_RDWR);
	if (fd == -1) {
		printf("error\n");
		exit(-1);
	}
	myfd = my_dup2(fd, fd2);
	write(myfd, "haha");
	return 0;
}

int my_dup2(int fd, int fd2)
{
	openat(fd2, 
}
