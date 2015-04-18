#include "apue.h"
#include <signal.h>
#include <sys/resource.h>

#define	BUFFSIZE	100

static void
signal_fintr(int signo)
{
	printf("SIGXFSZ caught\n");
}

int
main(void)
{
	int		n, nw;
	char	buf[BUFFSIZE];

	signal(SIGXFSZ, signal_fintr);
	struct rlimit rli = (struct rlimit){ 1024, 1050};
	setrlimit( RLIMIT_FSIZE, &rli);
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (nw = (write(STDOUT_FILENO, buf, n)) != n)
			printf("%d bytes write\n", nw);

	if (n < 0)
		err_sys("read error");

	exit(0);
}
