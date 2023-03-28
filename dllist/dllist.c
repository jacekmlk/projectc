#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdbool.h>

typedef struct dllist //Temp for self - referencing
{
    int val; //Value of node
    struct dllist *prev; // Pointer to previous node
    struct dllist *next; // Pointer to next node
}
dllnode;

dllnode *create(int x);
dllnode *insert(dllnode *head, int pos, int x);
void destroy(dllnode *head);
bool search(dllnode *head, int x);
dllnode *delete(dllnode *head, int pos);

int main(void)
{
    char decision = '\0';
    dllnode *list;
    decision = '\0';
    int exist = 0;

    while (decision != 'x')
    {
        decision = get_char("What to do? c - create, s - search, i - insert, d - destroy, r - delete, x - exit: \n");

        if (decision =='c')
        {
            //1. Create first node
            int i = get_int("Give value: ");

            list = create(i);
            exist = 1;

            printf("%p -> %p :val: %i -> %p\n", list->prev, list, list->val, list->next);
        }

        else if (decision == 'i')
        {
            //2. Insert value at desired place
            int pos = get_int("Give position: ");
            
            int val = get_int("Give value: ");

            list = insert(list, pos, val);

            for (dllnode *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                printf("%p -> %p :val: %i -> %p\n", ptr->prev, ptr, ptr->val, ptr->next);
            }
        }

        else if (decision == 'f')
        {
            //3. Search for element
            int s = get_int("Give number : ");
            if (search(list, s) == true)
            {
                printf("Found!\n");
            }
            else
            {
                printf("Not found!\n");
            }
            
        }

        else if (decision == 'r')
        {
            //4. Delete

            int pos = 0;
            while (true)
            {
                pos = get_int("To delete give position: ");
                if (pos >= 0)
                {
                    break;
                }
            }

            list = delete(list, pos);

            for (dllnode *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                printf("%p -> %p :val: %i -> %p\n", ptr->prev, ptr, ptr->val, ptr->next);
            }
        }

        else if (decision == 'd')
        {
            destroy(list);
            exist = 0;
        }
    }

    if (exist == 1)
    {
        destroy(list);
    }


}

//1. Create first node
dllnode *create(int x)
{
    dllnode *new = malloc(sizeof(dllnode));

    if (new == NULL)                        // Memorycheck
    {
        return NULL;
    }

    new->val = x;
    new->prev = NULL;
    new->next = NULL;

    return new;
}

//2. Insert node at desired place
dllnode *insert(dllnode *head,int pos, int x)
{
    dllnode *new = malloc(sizeof(dllnode));

    if (new == NULL)
    {
        return NULL;
    }

    new->val = x;
    dllnode *temp = head;

    if (pos == 0)                       // Return on the begining
    {
        new->next = temp;
        new->prev = temp->prev;
        temp->prev = new;

        return new;
    }
    else                                // Choose place or at the end
    {
        for (int i = 1; temp->next != NULL && i < pos; i++)
        {
            temp = temp->next;
        }

        new->next = temp->next;
        temp->next = new;
        new->prev = temp;

        return head;
    }

}

//3 Search 
bool search(dllnode *head, int x)
{
    dllnode *temp = head;
    while (temp->val != x)
    {
        if (temp->next == NULL)
        {
            return false;
        }
        else
        {
            temp = head->next;
        }
    }
    return true;
}

//4. Delete element
dllnode *delete(dllnode *head, int pos)
{
    dllnode *ptr = head;
    int i = 0;

    while (i < pos && ptr->next != NULL )
    {
        ptr = ptr->next;
        i++;
    }

    if (i == 0) //Begining
    {
        dllnode *following = ptr->next;
        following->prev = NULL;

        free(ptr);

        return following;
    }
    else // Middle
    {
        if (ptr->next != NULL)
        {
            dllnode *previous = ptr->prev;
            previous->next = ptr->next;
            dllnode *following = ptr->next;
            following->prev = ptr->prev;
        }
        else
        {
            dllnode *previous = ptr->prev;
            previous->next = NULL;
        }

        free(ptr);
    }

    return head;
}

//.5 Delete entire linked list
void destroy(dllnode *head)
{
    dllnode *ptr = head;
    while (ptr != NULL)
    {
        dllnode *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    ptr = NULL;
}