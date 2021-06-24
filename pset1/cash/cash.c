#include <cs50.h>
#include <math.h>
#include <stdio.h>

float get_cash();


int main(void)
{
    int coins = 0;
    float cash = get_cash();

    int cents = cash * 100;

    if (cents >= 25)
    {
        int coins25 = cents / 25;

        coins += coins25;

        cents -= coins25 * 25;
    }
    if (cents >= 10)
    {
        int coins10 = cents / 10;

        coins += coins10;

        cents -= coins10 * 10;
    }
    if (cents >= 5)
    {
        int coins5 = cents / 5;

        coins += coins5;

        cents -= coins5 * 5;
    }
    if (cents >= 1)
    {
        int coins1 = cents;

        coins += coins1;

        cents -= coins1;
    }

    printf("%d", coins);

}

float get_cash()
{
    float cash = -1;

    while (cash < 0)
    {
        cash = get_float("Change owed: ");
    }

    return cash;
}