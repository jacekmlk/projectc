#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct sllist // Temporary name for self referencing
{
    int val; // Value of node
    struct sllist *next; // Pointer to next node
}
sllnode;

sllnode *create(int x);
bool find(sllnode *head, int x);
sllnode *insert(sllnode *head, int x);
void destroy(sllnode *head);

int main(void)
{
    char decision = '\0';
    sllnode *newlist;
    int d = 0;

    while (decision != 'x')
    {
        decision = get_char("What to do? c - create, s - search, i - insert, d - destroy, x - exit: \n");

        if (decision == 'c')            //1. Create a linked list - if it not exist
        {
            int i = get_int("Give me first element: ");
            newlist = create(i);

            printf("Element: %i, Adress of newlist:%p, Adress of next: %p\n", newlist->val, newlist, newlist->next);
            d = 1;
        }

        else if (decision == 's' && d == 1)        //2. Search for element
        {
            int z = get_int("Search for element: ");
            bool exist = find(newlist, z);

            if (exist == true)
            {
                printf("Exist!\n");
            }
            else
            {
                printf("Not exist!\n");
            }
        }

        else if (decision == 'i' && d == 1)            //3. Insert new node
        {
            int w = get_int("Insert element: ");
            newlist = insert(newlist, w);

            for (sllnode *ptr = newlist; ptr != NULL; ptr = ptr->next)
            {
                printf("%p -> %i %p\n", ptr, ptr->val, ptr->next);
            }
        }

        else if (decision == 'd' && d == 1)             //.5 Delete entire linked list
        {
            if (d == 1)
            {
                destroy(newlist);
            }
            d = 0;
        }
    }

    if (d == 1)
    {
        destroy(newlist);
    }



    //4. Delete single node

}

//1. Create a linked list - if it not exist
sllnode *create(int x)
{
    sllnode *new = malloc(sizeof(sllnode)); //Dynamically allocate space for new sllnode

    if (new == NULL)                        // Make shure we did not runout of memory
    {
        return NULL;
    }

    new->val = x;                           // Initialize node val field
    new->next = NULL;                       // Initialize node next field

    return new;                             // Return pointer to newly create node
}

//2. Search for element
bool find(sllnode *head, int x)             //head - pointer to first element of the list
{
    sllnode *ptr = head;                    //Create temporary pointer to not loose head
    while (ptr->val != x)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            return false;
        }
    }
    return true;
}

//3. Insert new node
sllnode *insert(sllnode *head, int x)
{
    sllnode *new = malloc(sizeof(sllnode)); //Dynamically allocate space for new sllnode

    if (new == NULL)                        // Make shure we did not runout of memory
    {
        destroy(head);
        return NULL;
    }

    new->next = head;
    new->val = x;

    return new;
}

//.5 Delete entire linked list
void destroy(sllnode *head)
{
    sllnode *ptr = head;
    while (ptr != NULL)
    {
        sllnode *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    ptr = NULL;
}