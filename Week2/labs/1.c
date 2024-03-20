// Thinnaphat Kanchina 66070501013

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int mode;
    scanf("%d", &mode);
    if (mode == 0)
    {
        for (int i = 0; i < n; i += 2)
        {
            printf("%d ", *(arr + i));
        }
    }
    else if (mode == 1)
    {
        if (n > 1)
        {
            for (int i = 1; i < n; i += 2)
            {
                printf("%d ", *(arr + i));
            }
        }
        else
        {
            printf("none");
        }
    }
    free(arr);
    return 0;
}