def main():

    cartao = get_cartao()

    tamanho = len(str(cartao))

    x = teste(cartao, tamanho)

    if x != 0:
        if validar(str(cartao), tamanho) == True:
            if x == 1:
                print("AMEX")
            elif x == 2:
                print("MASTERCARD")
            elif x == 3:
                print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def get_cartao():

    cartao = 0

    while cartao == 0:
        try:
            cartao = int(input("Number: "))
        except ValueError:
            continue

    return cartao


def teste(cartao, tamanho):
    if tamanho == 13 or tamanho == 15 or tamanho == 16:
        if int(cartao / 10000000000000) == 34 or int(cartao / 10000000000000) == 37:
            return 1
        elif int(cartao / 100000000000000) == 51 or int(cartao / 100000000000000) == 52 or int(cartao / 100000000000000) == 53 or int(cartao / 100000000000000) == 54 or int(cartao / 100000000000000) == 55:
            return 2
        elif int(cartao / 1000000000000000) == 4 or int(cartao / 1000000000000) == 4:
            return 3
        else:
            return 0
    else:
        return 0


def validar(cartao, tamanho):

    digits = []

    for i in cartao:
        digits.append(int(i))

    digit1 = []
    for i in range(tamanho - 1, -1, -2):
        digit1.append(digits[i])

    digit2 = []
    for i in range(tamanho - 2, -1, -2):
        digit2.append(digits[i] * 2)

    soma1 = sum(digit1)

    soma2 = 0

    for i in range(len(digit2)):
        if digit2[i] < 10:
            soma2 += digit2[i]
        else:
            d1 = digit2[i] % 10
            d2 = int(digit2[i] / 10)

            soma2 += d1 + d2

    if (soma1 + soma2) % 10 == 0:
        return True
    else:
        return False


main()
