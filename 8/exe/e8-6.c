#include "apue.h"
#include <stdlib.h>

int
main()
{
	pid_t pid;

	pid = fork();
	if (pid < 0) {
		printf("fork error\n");
	} else if (pid == 0) {
		exit(0);
	} else {
		sleep(5);
		system("ps aux | grep Z");
	}
	return 0;
}
