#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    //char *s = get_int("Give int!");

    FILE *file = fopen("text.txt", "r");
    long n = 0;

    char *t;
    while(fread(&t, sizeof(char), 1, file))
    {
        n += 1;
    }
    fclose(file);

    FILE *fl = fopen("text.txt", "r");

    char *s;
    fread(s, sizeof(char), n, fl);
    fclose(file);

    printf("%s\n", s);
    
}

