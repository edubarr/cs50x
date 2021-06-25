# Identify using DNA

import csv
import sys
import re


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    data = []
    # Read data into memory from file
    with open(sys.argv[1]) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            data.append(row)

    # Read data into memory from file
    with open(sys.argv[2]) as dnafile:
        dna = dnafile.read()

    # Create a list of STRs from the data csv
    strlist = list(data[0])
    strlist.remove('name')

    # Create a Dictionary with the quantities of consecutives STRs
    strqnt = {}
    for i in strlist:
        strqnt[i] = repeats(dna, i)

    # Interates and checks a match
    for i in range(len(data)):
        tmpperson = data[i].copy()
        tmpperson.pop('name')

        if tmpperson == strqnt:
            print(data[i]["name"])
            break
        elif i == len(data) - 1:
            print("No match")


def repeats(sequence, dnastr):  # Calculate the biggest consecutive STR
    groups = re.findall('((?:' + re.escape(dnastr) + ')*)', sequence)

    largest = max(groups, key=len)

    return str(int(len(largest) / len(dnastr)))


main()