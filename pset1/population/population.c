#include <stdio.h>
#include <cs50.h>

int main()
{
    int starting = 0, ending = 0, years = 0;

    while (starting < 9)
    {
        starting = get_int("Enter the starting population: ");
    }

    while (ending < starting)
    {
        ending = get_int("Enter the ending population: ");
    }

    while (starting < ending)
    {
        starting = starting + (starting / 3) - (starting / 4);
        years++;
    }
    printf("Years: %d", years);

}