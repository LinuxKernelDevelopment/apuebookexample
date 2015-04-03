#include "apue.h"
#include <fcntl.h>

int mycopy(char*, char*);

int
main(int argc, char *argv[])
{
	mycopy(argv[1], argv[2]);
}

int
all_zero(char *rbuf, int size)
{
	int i;
	for (i = 0; i < size; i++)
		if (rbuf[i] != 0) return 1;
	return 0;
}

int
mycopy(char *pth1, char *pth2)
{
	struct stat buf;
	char *rbuf;
	int nblock, i, fd1, fd2, nr;

	if (stat(pth1, &buf) < 0) 
		err_ret("stat error");
	fd1 = open(pth1, O_RDONLY);
	fd2 = open(pth2, O_CREAT | O_WRONLY);
	nblock = buf.st_blocks;
	rbuf = malloc(buf.st_blksize);
	for (i = 0; i < nblock; i++) {
		nr = read(fd1, rbuf, buf.st_blksize);
		if (all_zero(rbuf, buf.st_blksize))
			write(fd2, rbuf, nr);
	}
	
}
