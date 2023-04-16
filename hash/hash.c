#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdbool.h>

unsigned int hash(char *str);

typedef struct sllist // Temporary name for self referencing
{
    char *val; // Value of node
    struct sllist *next; // Pointer to next node
}
node;

const int HASH_MAX = 10;



int main(void)
{
    //Declare hashtable
    node *hashtable[HASH_MAX];

    //Fill hashtable with NULLS
    for (int i = 0; i < HASH_MAX;  i++)
    {
        hashtable[i] = NULL;
    }

    //Write to hashtable
    char *name;

    do
    {
    name = get_string("Write a name!\n");

    
    hashtable[hash(name)] = name;

    //Print hashtable
    for (int j = 0; j < HASH_MAX;  j++)
    {
        printf("Value of hashtable[%i] = %s\n", j, hashtable[j]);
    }
    printf("\n");
    } while (name[0] != '\0');

}

unsigned int hash(char *str)
{
    int sum = 0;
    for (int j = 0; str[j] != '\0'; j++)
    {
        sum = sum + str[j];
    }
    return sum % HASH_MAX;
}
