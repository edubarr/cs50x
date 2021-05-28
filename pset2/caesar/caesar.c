#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int checkkey(string arg);
void cipher(string text, int key);

int main(int argc, string argv[])
{
    if (argc != 2) //Check usage
    {
        printf("Usage: ./caesar key");
        return 1; //Return error code
    }
    else if (!checkkey(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    cipher(plaintext, atoi(argv[1]));

    return 0;
}

int checkkey(string arg)
{
    for (int i = 0, n = strlen(arg); i < n; i++)
    {
        if (isdigit(arg[i]) == 0)
        {
            return 0;
        }
    }
    if (atoi(arg) < 0)
    {
        return 0;
    }

    return 1;
}

void cipher(string text, int key)
{
    int size = strlen(text);

    char ciphertext[size];

    for (int i = 0; i <= size; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            if (((text[i] + key) >= 'A' && (text[i] + key) <= 'Z') || ((text[i] + key) >= 'a' && (text[i] + key) <= 'z'))
            {
                ciphertext[i] = text[i] + key;
            }
            else
            {
                if (text[i] >= 'A' && text[i] <= 'Z')
                {
                    int upletter = text[i] + key;

                    while (upletter > 'Z')
                    {
                        upletter -= 26;
                    }

                    ciphertext[i] = upletter;
                }
                else if (text[i] >= 'a' && text[i] <= 'z')
                {
                    int lowletter = text[i] + key;

                    while (lowletter > 'z')
                    {
                        lowletter -= 26;
                    }

                    ciphertext[i] = lowletter;
                }
            }
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}