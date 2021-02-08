#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long changetext(char inptext, int minlimit, int maxlimit, long ckey);

int main(int argc, string argv[])
{
    long key = 0;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string argument = argv[1];

    for (int i = 0; i <= strlen(argument) - 1; i++)
    {
        if ((islower(argument[i])) || (isupper(argument[i])))       // check if 1st argument is NOT numeric
        {
            printf("characrUsage: ./caesar key\n");
            return 1;
        }
    }

    key = atoi(argument);
    int j = 0;

    string input_msg = get_string("plaintext:  ");          // accept input text
    string ciphertext = input_msg;

    for (int i = 0; i <= strlen(input_msg) - 1; i++)
    {
        if ((input_msg[i] >= 65 && input_msg[i] <= 90))     // For capital alphabets
        {
            int min = 65;
            int max = 90;
            ciphertext[i] = changetext(input_msg[i], min, max, key);        // changing the text as per key
        }
        else
        {
            if ((input_msg[i] >= 97 && input_msg[i] <= 122))        // For small alphabets
            {
                int min = 97;
                int max = 122;
                ciphertext[i] = changetext(input_msg[i], min, max, key);       // changing the text as per key
            }
            else
            {
                ciphertext[i] = input_msg[i];
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);        //Print ciphertext
    return 0;
}

long changetext(char inptext, int minlimit, int maxlimit, long ckey)
{
    //printf(" inptext : %c\n", inptext);
    //printf(" ckey : %ld\n", ckey);


    long cptext;
    int j = inptext + ckey;

    //printf(" j : %i\n", j);

    // Implement the cyclic function

    if (j > maxlimit)
    {
        while (j > maxlimit)
        {
            if ((j % maxlimit) == 0)
            {
                j = (j % maxlimit) + minlimit;
            }
            else
            {
                j = (j % maxlimit) + minlimit - 1;
            }
            //printf(" j while : %i\n", j);
        }
        cptext = j;
        //printf(" cptext : %ld\n", cptext);
    }
    else
    {
        cptext = j;
        //printf(" cptext normal : %ld\n", cptext);
    }
    return cptext;
}