#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    long card = get_long("Number: ");

    int card_size = length(card);

    if (checksum(card, card_size))
    {
        /* code */
    }
    

    return 0;
}

int checksum(long cardc, int size)
{
    int digits[size], digitsx2[size + 1], digits3[size + 1];
    int i, sum2x = 0, sum3 = 0, totalsum = 0;

    for (i = 0; i < size; i++) //Cria um array com os digitos do numero
    {
        digits[i] = cardc % 10;
        cardc /= 10;
    }

    for (i = 0; i < size; i++) //Zera o array 2
    {
        digitsx2[i] = 0;
    }

    for (i = 1; i <= size; i = i + 2) //Atribui os valores ao array 2
    {
        digitsx2[i] = digits[i] * 2;
    }

    for (i = 1; i <= size; i = i + 2) //Separa os digitos dos numeros de 2 digitos.
    {
        if (digitsx2[i] > 9)
        {
            digitsx2[i + 1] = digitsx2[i] % 10;
            digitsx2[i] /= 10;
        }
    }

    for (i = 0; i <= size; i = i + 2) //Atribui os valores ao array 3
    {
        digits3[i] = digits[i];
    }

    for (i = 0; i < size; i++) //Calcula a soma x2
    {
        sum2x += digitsx2[i];
    }

    for (i = 0; i < size; i++) //Calcula a soma 3
    {
        sum3 += digits3[i];
    }

    totalsum = sum2x + sum3;

    if (totalsum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int length(long cards)
{
    int digits = floor(log10(cards)) + 1;

    return digits;
}