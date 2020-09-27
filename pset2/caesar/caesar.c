#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");

        return 1;
    }
    else
    {
        for (int j = 0, s = strlen(argv[1]); j < s; j++)

            if (isalpha(argv[1][j]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
    }

    string pltxt = get_string("plaintext: ");

    int plsize = strlen(pltxt);

    printf("ciphertext: ");

    for (int i = 0; i < plsize; i++)
    {
        int r = atoi(argv[1]);
        if (pltxt[i] >= 'A' && pltxt[i] <= 'Z')
        {
            if (pltxt[i] + atoi(argv[1]) <= 'Z')
            {
                printf("%c", pltxt[i] + atoi(argv[1]));
            }
            else
            {
                while (pltxt[i] + r > 'Z')
                {
                    r = r - 26;
                }
                printf("%c", pltxt[i] + r);
            }
        }

        else if (pltxt[i] >= 'a' && pltxt[i] <= 'z')
        {
            if (pltxt[i] + atoi(argv[1]) <= 'z')
            {
                printf("%c", pltxt[i] + atoi(argv[1]));
            }
            else
            {
                while (pltxt[i] + r > 'z')
                {
                    r = r - 26;
                }
                printf("%c", pltxt[i] + r);
            }
        }

        else
        {
            printf("%c", pltxt[i]);
        }

    }
    printf("\n");

    return 0;
}