#include <stdio.h>

int main(void)
{
    int arr[] = {1,4,8,3,5,6};
    int max = 6;
    int m;
    
    for (int j = 0; j < max-1; j++)
    {
        for (int i = 0; i < max - i - 1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                m = arr[i];
                arr[i] = arr[i+1];
                arr[i + 1] = m;
            }
        }
    }

    for (int k = 0; k < max; k++)
    {
        printf("%i\n", arr[k]);
    }

    
}





