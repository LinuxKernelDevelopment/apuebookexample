#include "apue.h"

int		globvar = 6;

pid_t my_vfork()
{
	return vfork();
}

int
main(void)
{
	int			var;
	pid_t		pid;

	var = 88;
	printf("before my_vfork\n");
	if ((pid = my_vfork()) < 0) {
		err_sys("my_vfork error");
	} else if (pid == 0) {
		globvar++;
		var++;
		_exit(0);
	}

	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,
		var);
	exit(0);
}
