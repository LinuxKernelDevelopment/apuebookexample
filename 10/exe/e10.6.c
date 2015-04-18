#include <stdio.h>
#include <unistd.h>

void WAIT_PARENT(void);
void WAIT_CHILD(void);
void TELL_CHILD(void);
void TELL_PARENT();
void TELL_WAIT(void);
int
main(void)
{
	TELL_WAIT();
	char buf[10];
	int glob = 0;
	pid_t pid;
	pid = fork();
	for (;;)
		if (pid < 0) {
			err_sys("fork error");
		} else if (pid == 0) {
			TELL_PARENT();
			glob++;
			sprintf(buf, "%d\t%d\n", getpid(), glob);
			write(STDOUT_FILENO, buf, sizeof(buf));
			sleep(1);
			WAIT_PARENT();
		} else {
			WAIT_CHILD();
			glob++;
			sprintf(buf, "%d\t%d\n", getpid(), glob);
			write(STDOUT_FILENO, buf, sizeof(buf));
			sleep(1);
			TELL_CHILD();
		}
	return 0;
}
