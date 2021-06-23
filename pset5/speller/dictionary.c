// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Number of buckets in hash table
#define N 260

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Hash table
node *table[N] = {NULL};

// Counts words that was loaded
int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int wordhash = hash(word);

    node *tmp = table[wordhash];

    while (tmp != NULL)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }

        tmp = tmp->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // djb2 algorithm by Dan Bernstein, found in http://www.cse.yorku.ca/~oz/hash.html
    unsigned int hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */
    }

    hash = hash % N;

    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the file dictionary and check pointer
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    char buffer[LENGTH + 1];

    while (fscanf(file, "%s", buffer) != EOF)
    {

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        strcpy(new_node->word, buffer);

        unsigned int nodehash = hash(new_node->word);

        new_node->next = table[nodehash];
        table[nodehash] = new_node;

        wordcount++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return wordcount variable from previous load function

    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *tmp;
        while (table[i] != NULL)
        {
            tmp = table[i]->next;

            free(table[i]);

            table[i] = tmp;
        }
        if (table[i] == NULL)
        {
            count++;
        }
    }

    if (count == N)
    {
        return true;
    }

    return false;
}
