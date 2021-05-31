#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void cipher(string text, string key);
int checkkey(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key");

        return 1;
    }
    else
    {
        switch (checkkey(argv[1]))
        {
        case 1:
            printf("Key must contain 26 characters.");
            return 1;
            break;

        case 2:
            printf("Key must contain only letters.");
            return 1;
            break;

        case 3:
            printf("Key must not repeat letters.");
            return 1;
            break;

        default:
            break;
        }
    }

    string plaintext = get_string("plaintext: ");

    cipher(plaintext, argv[1]);

    return 0;
}

int checkkey(string key)
{
    if (strlen(key) != 26)
    {
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return 2;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        int n = 0; //counts repetition
        for (int j = 0; j < 26; j++)
        {
            if (key[i] == key[j])
            {
                n++;
            }
        }
        if (n > 1)
        {
            return 3;
        }
    }
}

void cipher(string text, string key)
{
    int size = strlen(text);

    char ciphertext[size];

    for (int i = 0; i <= size; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            char upp = 'A', lowr = 'a'; //upper and lowercase references

            for (int j = 0; j < 26; j++, upp++, lowr++)
            {
                if (text[i] == upp)
                {
                    ciphertext[i] = toupper(key[j]);
                }
                else if (text[i] == lowr)
                {
                    ciphertext[i] = tolower(key[j]);
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