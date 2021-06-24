#include <stdio.h>
#include <cs50.h>

int contadigitos(long numero);
int teste(long cartao, int tamanho);
int validar(long cartao);

int main()
{
    long cartao = get_long("Number: ");

    int tamanho = contadigitos(cartao);

    int x = teste(cartao, tamanho); //0 = INVALID, 1 = AMEX, 2 = MASTER, 3 = VISA

    if (x != 0)
    {
        if (validar(cartao))
        {
            if (x == 1)
            {
                printf("AMEX\n");
            }
            else if (x == 2)
            {
                printf("MASTERCARD\n");
            }
            else if (x == 3)
            {
                printf("VISA\n");
            }
        }

        else
        {
            printf("INVALID");
        }
    }
    else
    {
        printf("INVALID");
    }

    return 0;
}

int contadigitos(long numero)
{
    int count = 0;

    while (numero != 0)
    {
        numero = numero / 10;
        count++;
    }
    return count;
}

int teste(long cartao, int tamanho)
{
    if (tamanho == 13 || tamanho == 15 || tamanho == 16)
    {

        if (cartao / 10000000000000 == 34 || cartao / 10000000000000 == 37)
        {
            return 1;
        }
        else if (cartao / 100000000000000 == 51 || cartao / 100000000000000 == 52 || cartao / 100000000000000 == 53 || cartao / 100000000000000 == 54 || cartao / 100000000000000 == 55)
        {
            return 2;
        }
        else if (cartao / 1000000000000000 == 4 || cartao / 1000000000000 == 4)
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int validar(long cartao)
{
    int digits[16] = {0};

    long cartaocopia = cartao;

    for (int i = 0; cartaocopia != 0; i++)
    {
        int digito = cartaocopia % 10;
        digits[i] = digito;
        cartaocopia = cartaocopia / 10;
    }

    int digit1[8] = {0};

    for (int i = 0, j = 0; i < 8; i++, j += 2)
    {
        digit1[i] = digits[j];
    }

    int digit2[8] = {0};

    for (int i = 0, j = 1; i < 8; i++, j += 2)
    {
        digit2[i] = digits[j] * 2;
    }

    int soma1 = 0;
    int soma2 = 0;

    for (int i = 0; i < 8; i++)
    {
        soma1 += digit1[i];
    }
    for (int i = 0; i < 8; i++)
    {
        if (digit2[i] < 10)
        {
            soma2 += digit2[i];
        }
        else
        {
            int d1 = digit2[i] % 10;
            int d2 = digit2[i] / 10;

            soma2 += d1 + d2;
        }
    }

    if ((soma1 + soma2) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}