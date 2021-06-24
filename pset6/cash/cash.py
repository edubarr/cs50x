def main():

    cash = get_cash()

    cents = cash * 100

    coins = 0

    if cents >= 25:
        coins25 = int(cents / 25)
        coins += coins25
        cents -= coins25 * 25

    if cents >= 10:
        coins10 = int(cents / 10)
        coins += coins10
        cents -= coins10 * 10

    if cents >= 5:
        coins5 = int(cents / 5)
        coins += coins5
        cents -= coins5 * 5

    if cents >= 1:
        coins1 = int(cents)
        coins += coins1
        cents -= coins1

    print(f"{coins}")


def get_cash():
    cash = -1

    while cash < 0:
        try:
            cash = float(input("Change owed: "))
        except ValueError:
            continue

    return cash


main()