#include <unistd.h>
#include <signal.h>
#include <stdio.h>

unsigned int time[100], i = 0;

static void
sig_alrm(int signo)
{
	int i;
	printf("time is up\n");
	for (i = 0; time[i + 1] != 0; i++)
		time[i] = time[i + 1] - time[0];
	time[i] = time[i + 1];
	for (i = 0; time[i] != 0; i++)
		printf("%d\t", time[i]);
	printf("\n");
	alarm(time[0]);
}

void 
set_alarm(int t)
{
	if (time[0] == 0)
		alarm(t);
	time[i++] = t;
}

int
main(void)
{
	int j;
	for (j = 0; j < 100; j++)
		time[j] = 0;
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");
	set_alarm(5);
	set_alarm(10);
	set_alarm(15);
	for (;;)
		pause();
	return 0;
}
