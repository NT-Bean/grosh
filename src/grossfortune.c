#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

char line[500];
char bline[500];

// stolen sraight from Unix Version 7. i hope it's different enough to be fine

int main()
{
    double p;
	register char * l;
	long t;
	FILE *f;

	f = fopen("/usr/bin/grosh/lib/fortunes", "r");
	if (f == NULL) {
		printf("Memory fault -- core dumped\n");
		exit(1);
	}
	time(&t);
	srand(getpid() + (int)((t>>16) + t));
	p = 1.;
	for(;;) {
		l = fgets(line, 500, f);
		if(l == NULL)
			break;
		if(rand() < 2147483648./p)
			strcpy(bline, line);
		p += 1.;
	}
	fputs(bline, stdout);
	return(0);
}