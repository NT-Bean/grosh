#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

const char facetop[] = "              ____\n";
const char face2nd[] = "            /`    `\\\n";
const char facemid[] = "            | >  < |\n";
const char face4th[] ="            \\_.--._/\n";
const char facelast[] ="            _,)()(,_\n";
const char barftop[] = " _,..oo$@)()(}()()(){}(@$oo..,_ \n";

const char barflast[] ="`*$@)(}()(){)()()()(){)()()(@$*`\n";

char* wrapstr(char str[])
{
    char input[2134];
    input[strcspn(input, "\n")] = 0;
    strcpy(str, input);

    // char strbuff[30] = "\0";
    for (;;)
    {
        for(int i = 30; i >= 0; i--)
        {
            if(input[i] == ' ')
            {
                // strncpy(strbuff, input, i);
                strcpy(input + 2, input);
                strncpy(input, input + 2, 30);
            }
        }
    }
    
    return "peepee poopoo";
}
int main(int argc, char** argv)
{
    
    char input[2000] = "uh oh except its 30 chars long";
    if (argv[1] != NULL)
    {
        strcpy(input, argv[1]);
    }

    if(strlen(input) > 30)
    {

    }

    printf("%s%s%s%s%s%s", facetop, face2nd, facemid, face4th, facelast, barftop);
    printf("|%s|", input);
    
    printf("\n%s\n", barflast);

    return 0;
}