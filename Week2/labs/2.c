// Thinnaphat Kanchina 66070501013

#include <stdio.h>
#include <stdlib.h>

int get_max(int *arr, int size)
{
    int max = *arr;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    return max;
}
int get_min(int *arr, int size)
{
    int min = *arr;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) < min)
        {
            min = *(arr + i);
        }
    }
    return min;
}
int get_idx(int *arr, int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == num)
        {
            return i;
        }
    }
    return -1;
}

void show_max_min_and_idx_of_array(int *arr, int size)
{
    int max_num = get_max(arr, size);
    int max_idx = get_idx(arr, size, max_num);
    int min_num = get_min(arr, size);
    int min_idx = get_idx(arr, size, min_num);

    printf("%d %d\n%d %d", max_num, max_idx, min_num, min_idx);
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    show_max_min_and_idx_of_array(arr, n);

    free(arr);
    return 0;
}