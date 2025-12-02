#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

// how to make any developer sob with just %d lines of code!
// well, any developer who's not me

const char facetop[] = "              ____\n";
const char face2nd[] = "            /`    `\\\n";
const char facemid[] = "            | >  < |\n";
const char face4th[] ="            \\_.--._/\n";
const char facelast[] ="            _,)()(,_\n";
const char barftop[] = " _,..oo$@)()(}()()(){}(@$oo..,_ \n";

const char barflast[] ="`*$@)(}()(){)()()()(){)()()(@$*`\n";

char* wrapstr(char str[])
{
    // i have officially mastered the art of bullshitsu

    static char input[2134] = "somethings fucked up but also";
    strcpy(input, str);

    // char strbuff[30] = "\0";
    for (int i = 0;; i += 33)
    {
        if(input[(i/33)*30+30] == NULL)
        {
            break;
        }
        for(int j = 30; j >= 0; j--)
        {
            if(input[j] == ' ')
            {
                strncpy(input + 3 + (30 - j) +i, input +i, strlen(input));
                    printf("%s\n\n", input);
                strncpy(input +i, input + 2 + (30 - j) +i, 30 + (30 - j));
                    printf("%s\n\n", input);
                input[0 +i] = '#';
                input[31 +i] = '|';
                    printf("%s\n\n", input);
                for(int k = 30 +i;; k--)
                {
                    if(input[k] == ' ')
                    {
                        break;
                    }
                    else
                    {
                        input[k] = ' ';
                    }
                }
                    printf("%s\n\n", input);
                input[32 +i] = '\n';
                input[33 +i] = '|';
                    printf("%s\n\n", input);
                
                break;
            }
        }
    }
    
    return input;
}
int main(int argc, char** argv)
{
    
    char input[2000] = "uh oh except its 30 chars long";
    if (argv[1] != NULL)
    {
        strcpy(input, argv[1]);
    }
    input[strcspn(input, "\n")] = 0;

    char output[2134] = "uh oh delux";
    strcpy(output, input);
    
    if(strlen(input) <= 30)
    {
        strncpy(output + 1, output, strlen(output));
        output[0] = '|';
        output[31] = '|';
        output[32]='\n';
    }
    else
    {
        strcpy(output, wrapstr(input));
    }

    printf("%s%s%s%s%s%s", facetop, face2nd, facemid, face4th, facelast, barftop);
    printf("%s", output);
    
    printf("%s", barflast);

    return 0;
}