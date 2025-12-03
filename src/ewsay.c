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

void wrapstr(char input[], char output[2150])
{
    // i have officially mastered the art of bullshitsu
    // 123456789012345678901234567890
    // |234567890123456789012345678901|\n
    
    strcpy(output, input);

    int i = 0;
    for(i = 0; i <= 2150; i+=33)
    {
        if(output[i+30] == '\0')
        {
            memmove(output + i + 1, output + i, strlen(output) + 1);
            int j;
            for(j = i; j <= i + 31; j++)
            {
                if(output[j] == '\0')
                    break;
            }
            for(; j<=30+i; j++)
            {
                output[j] = ' ';
            }
            output[i] = '|';
            output[i+31] = '|';
            output[i+32] = '\n';
            break;   
        }
        for(int j = 29; j >= 0; j--)
        {
            if(output[j+i] == ' ')
            {
                // Example string w/ who knows hoW_many     //original; j = 27
                // Eexample string w/ who knows hOW many
                // |example string w/ who knows hOW many    // took care of the first one
                // |example string w/ who knows hOWhow many // moved char after j onwards by # of chars from j tp char [30]
                // |example string w/ who knows  OWhow many // wiped all chars between
                // |example string w/ who knows  |*how many // performed character replacement 
                memmove(output + 1 + i, output + i, strlen(output) + 1);
                memmove(output + j + (31-j) + i, output + j + i, strlen(output) + j + (30-j));
                for (int k = 30; k >= 0; k--)
                {
                    if(output[k+i] == ' ')
                        break;
                    else
                        output[k+i] = ' ';
                }
                output[31+i] = '|';
                output[32+i] = '\n';
                output[0+i] = '|';
                break;
            }
        }
    }

    return;
}

int main(int argc, char** argv)
{
    
    char input[2000] = "uh oh except its 30 chars long";
    if (argv[1] != NULL)
    {
        strcpy(input, argv[1]);
    }
    input[strcspn(input, "\n")] = 0;
        printf("%s\n\n", input);

    char output[2150] = "uh oh delux";
    strcpy(output, input);
    
    if(strlen(input) <= 30)
    {
        memmove(output + 1, output, strlen(output) + 1);
            int j;
            for(j = 0; j <= 31; j++)
            {
                if(output[j] == '\0')
                    break;
            }
            for(; j<=30; j++)
            {
                output[j] = ' ';
            }
            output[0] = '|';
            output[31] = '|';
            output[32] = '\n';
    }
    else
    {
        wrapstr(input, output);
    }

    printf("%s%s%s%s%s%s", facetop, face2nd, facemid, face4th, facelast, barftop);
    printf("%s", output);
    
    printf("%s", barflast);

    return 0;
}