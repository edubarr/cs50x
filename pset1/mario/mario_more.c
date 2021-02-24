#include <cs50.h>
#include <stdio.h>

int get_height();

int main(void)
{
    int height = get_height();

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}

int get_height()
{
    int n = 0;

    while (n < 1 || n > 8)
    {
        n = get_int("Height: ");
    }

    return n;
}