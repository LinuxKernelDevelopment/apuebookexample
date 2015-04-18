#include "apue.h"

static void	sig_usr(int);
int sig2str(const char **str, int *signop);

int
main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_sys("can't catch SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		err_sys("can't catch SIGUSR2");
	pause();
}

static void
sig_usr(int signo)
{
	char *str;
	str = malloc(sizeof(char) * 100);
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		err_dump("received signal %d\n", signo);
	sig2str(&str, &signo);
	printf("%s\n", str);
}

int sig2str(const char **str, int *signop)
{
    	
	*str = strsignal(*signop);
	return 0;
}
