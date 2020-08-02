#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_sentences(string text);
int count_words(string text);
int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float l = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;

    float index = (0.0588 * l) - (0.296 * s) - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }

}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, text_len = strlen(text); i < text_len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

int count_words(string text)
{
    int words = 0;

    for (int i = 0, text_len = strlen(text); i < text_len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words + 1;
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, text_len = strlen(text); i < text_len; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }

    return letters;
}