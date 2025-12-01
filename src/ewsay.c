#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

char facetop[] = "  ____\n";
char face2nd[] = "/`    `\\\n";
char facemid[] = "| >  < |\n";
char face4th[] ="\\_.--._/\n";
char facelast[] ="_,)()(,_\n";

int main(int argc, char** argv)
{
    printf("%s", facetop);
    printf("%s", face2nd);
    printf("%s", facemid);
    printf("%s", face4th);
    printf("%s", facelast);
    
    char testue[50] = "uhoh";
    if (argv[1] != NULL)
    {
        strcpy(testue, argv[1]);
    }
    printf("%s\n", testue);

    return 0;
}