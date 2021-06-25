def main():

    text = input("Text: ")

    letters = count_letters(text)
    words = text.count(" ") + 1
    sentences = text.count(".") + text.count("!") + text.count("?")

    l = (letters / words) * 100
    s = (sentences / words) * 100

    index = (0.0588 * l) - (0.296 * s) - 15.8

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")


def count_letters(text):
    letters = 0

    for i in range(len(text)):
        if(text[i].isalpha()):
            letters += 1

    return letters


main()
