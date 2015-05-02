#include "apue.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
	int					fd;
	pid_t				pid, cpid;

	if ((fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0)
		err_sys("open error");
	if (write(fd, "abcdef", 6) != 6)
		err_sys("write error");

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid > 0) {
		WAIT_CHILD();
		if (write_lock(fd, 0, SEEK_SET, 1) < 0)
			err_sys("write_lock error");
		printf("gain write lock\n");
	} else {
		if (read_lock(fd, 0, SEEK_SET, 1) < 0)
			err_sys("read_lock error");
		printf("gain read lock 1\n");
		TELL_PARENT(getppid());
		if ((cpid = fork()) < 0) {
			err_sys("fork error");
		} else if (cpid > 0) {
			if (read_lock(fd, 0, SEEK_SET, 1) < 0)
				err_sys("read_lock error");
			printf("gain read lock 2\n");
		}
	}
	return 0;
}
