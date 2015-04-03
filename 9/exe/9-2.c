#include <unistd.h>
#include <stdio.h>
int
main()
{
	pid_t	pid;
	pid = fork();
	if (pid == 0) {
		printf("haha\n");
		setsid();
		printf("this is child\n");
	} else
		sleep(5);
	return 0;
}
