def main():
    height = get_height()

    for i in range(1, height + 1):
        for j in range(height - i):
            print(" ", end="")
        for k in range(i):
            print("#", end="")
        print("  ", end="")
        for k in range(i):
            print("#", end="")
        print("")


def get_height():
    n = 0
    while n < 1 or n > 8:
        try:
            n = int(input("Height: "))
        except ValueError:
            continue
    return n


main()