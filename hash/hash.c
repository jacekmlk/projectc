#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdbool.h>
#include <string.h> 

typedef struct sllist // Temporary name for self referencing
{
    char *val; // Value of node
    struct sllist *next; // Pointer to next node
}
node;

unsigned int hash(char *str);
node *insert(node *head, char *x);

const int HASH_MAX = 10;

node *hashtable[HASH_MAX];


int main(void)
{
    //Declare hashtable
    

    //Fill hashtable with NULLS
    for (int i = 0; i < HASH_MAX;  i++)
    {
        hashtable[i] = NULL;
    }

    //Write to hashtable
    char *name;

    name = get_string("Write a name!\n");

    hashtable[hash(name)] = insert(hashtable[hash(name)], name);

    for (int j = 0; j < HASH_MAX;  j++)
    {
        if (hashtable[j] != NULL)
        {
            printf("Value of hashtable[%i] = %s\n", j, hashtable[j]->val);
        }

    }
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

//3. Insert new node
node *insert(node *head, char *x)
{
    node *new = malloc(sizeof(node)); //Dynamically allocate space for new sllnode

    if (new == NULL)                  // Make shure we did not runout of memory
    {
        return NULL;
    }

    new->next = head;
    strcpy(new->val, x);

    return new;
}
