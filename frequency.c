#include <stdio.h>
#include <stdlib.h>

int *takearray(int k)
{
    int *temp = (int *)malloc(k * sizeof(int));
    return temp;
}

int main()
{
    int n;
    int *original;
    int max = -1;
    int max2 = 0;

    scanf("%d", &n);
    original = takearray(n);


    for (int i = 0; i < n; i++)
    {
        scanf("%d", (original + i));
        if (*(original + i) > max)
            max = *(original + i);
    }

    int *freq;
    freq = takearray(max + 1);


    for (int i = 0; i < max + 1; i++)
    {
        *(freq + i) = 0;
    }


    for (int i = 0; i < n; i++)
    {
        *(freq + *(original + i)) = *(freq + *(original + i)) + 1;
    }

    free(original);
    


    for (int i = 0; i < max + 1; i++)
    {
        if (*(freq + i) > max2)
        {
            max2 = *(freq + i);
        }
    }
    
    for (int i = 0; i < max + 1; i++)
    {
        if (*(freq + i) == max2)
        {
            printf("%d ", i);
        }
    }
    free(freq);
}