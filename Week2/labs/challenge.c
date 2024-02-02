// Thinnaphat Kanchina 66070501013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preprocess_range(int *start, int *end, int *step, int size)
{
    if (*start < 0)
    {
        *start = size + *start;
        if (*start < 0)
        {
            *start = 0;
        }
    }
    if (*end < 0)
    {
        *end = size + *end;
    }

    if (*start > size)
    {
        *start = size - 1;
    }
    if (*end > size)
    {
        *end = size;
    }
}
void show_slice(int *arr, int size, int start, int end, int step)
{
    preprocess_range(&start, &end, &step, size);

    if (step < 0)
    {
        if (start <= end)
        {
            printf("empty");
        }
        for (int i = start; i > end; i += step)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else if (step > 0)
    {
        if (start >= end)
        {
            printf("empty");
        }
        for (int i = start; i < end; i += step)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("ERROR\n");
        return;
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);
    show_slice(arr, size, start, end, step);

    free(arr);

    return 0;
}