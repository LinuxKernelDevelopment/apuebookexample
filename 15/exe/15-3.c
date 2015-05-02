#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	FILE *fout;

	fout = popen("hh", "w");

	return 0;
}
