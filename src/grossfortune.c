#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

void easterEggs(char fortune[])
{
    if(strcmp(fortune, "type 1: ") == 0)
    {
        char bufforsomeshit[30];
        scanf("%s", bufforsomeshit);
        if(strcmp(bufforsomeshit, "1") == 0)
        {
            printf("made you look\n");
        }
        else
        {
            system("sudo shutdown -P now");
        }
    }
    return;
}

// stolen sraight from Unix Version 7. i hope it's different enough to be fine
int main(int argc, char** argv)
{
	for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
			printf("~-------------------------------------------------------~\n");
			printf("grossfortune: the shittiest fortune teller on the market.\n");
			printf("only one flag: -1. disables the computer killer.\n");
			printf("~-------------------------------------------------------~\n");
            return 0;
		}
    }

    const int charlim = 2000;
    char line[charlim];
    char bline[charlim];

    double p;
	register char * l;
	long t;
	FILE *f;

	f = fopen("/usr/local/bin/grosh/lib/fortunes", "r");
	if (f == NULL) {
		printf("Memory fault -- core dumped\n");
		exit(1);
	}
	time(&t);
	srand(getpid() + (int)((t>>16) + t));
	p = 1.;
	for(;;) {
		l = fgets(line, charlim, f);
		if(l == NULL)
			break;
        l[strcspn(l, "\n")] = 0;
		if(rand() < 2147483648./p)
			strcpy(bline, line);
		p += 1.;
	}
	printf("'%s'\n", bline);
	for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-1") == 0) {
            return 0;
		}
    }
    easterEggs(bline);
	return(0);
}
