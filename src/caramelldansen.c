#include <stdio.h>
#include <string.h>
// #include <unistd.h>
#include <time.h>

unsigned int sleeptime = 200;

void clearLine()
{
    printf("\x1b[1F"); // Move to beginning of previous line
    printf("\x1b[2K");
    return;
}

int main()
{

    int what;
    struct timespec ts;
    ts.tv_sec = sleeptime / 1000;
    ts.tv_nsec = (sleeptime % 1000) * 1000000;

    for (;;)
    {
        printf("\n\033[101m u u uwa uwa \033[0m");
            fflush(stdout);
            what = nanosleep(&ts, &ts);
            clearLine();
        printf("\n\033[102m u u uwa uwa \033[0m");
            fflush(stdout);
            what = nanosleep(&ts, &ts);
            clearLine();
        printf("\n\033[104m u u uwa uwa \033[0m");
            fflush(stdout);
            what = nanosleep(&ts, &ts);
            clearLine();
        printf("\n\033[43m u u uwa uwa \033[0m");
            fflush(stdout);
            what = nanosleep(&ts, &ts);
            clearLine();
        printf("\n\033[105m u u uwa uwa \033[0m");
            fflush(stdout);
            what = nanosleep(&ts, &ts);
            clearLine();
        printf("\n\033[103m u u uwa uwa \033[0m");
            fflush(stdout);
            what = nanosleep(&ts, &ts);
            clearLine();
        printf("\n\033[106m u u uwa uwa \033[0m");
            fflush(stdout);
            what = nanosleep(&ts, &ts);
            clearLine();
    }
    

    return 0;
}