// Thinnaphat Kanchina 66070501013

#include <stdio.h>
#include <stdlib.h>

int *arr2set(int *arr, int *size)
{
    int i, j, k;
    for (i = 0; i < (*size); i++)
    {
        for (j = i + 1; j < (*size); j++)
        {
            if (arr[i] == arr[j])
            {
                for (k = j; k < (*size); k++)
                {
                    arr[k] = arr[k + 1];
                }
                (*size)--;
                j--;
            }
        }
    }
    int *set = (int *)malloc((*size) * sizeof(int));
    for (i = 0; i < *size; i++)
    {
        set[i] = arr[i];
    }

    return set;
}

void displayArr(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    if (size == 0)
    {
        printf("empty");
    }
    printf("\n");
}

int main()
{
    int size, i;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *set = arr2set(arr, &size);
    printf("%d\n", size);
    displayArr(set, size);

    // free memory
    free(arr);
    free(set);
    

    return 0;
}