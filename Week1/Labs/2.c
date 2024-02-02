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

int *gen_set_range(int start, int end, int size)
{
    int i;
    int *set = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        set[i] = start + i;
    }

    return set;
}

int *crop_set_in_range(int *set, int *size, int start, int end)
{
    int i, j;
    for (i = 0; i < *size; i++)
    {
        if (set[i] < start || set[i] > end)
        {
            for (j = i; j < *size; j++)
            {
                set[j] = set[j + 1];
            }
            (*size)--;
            i--;
        }
    }

    return set;
}

int *sort_set(int *set, int *size)
{
    int i, j, k;
    for (i = 0; i < *size; i++)
    {
        for (j = i + 1; j < *size; j++)
        {
            if (set[i] > set[j])
            {
                int temp = set[i];
                set[i] = set[j];
                set[j] = temp;
            }
        }
    }

    return set;
}

int *get_union(int *set_a, int *set_b, int *size_a, int *size_b, int *union_size)
{
    int i, j, k;
    int *union_set = (int *)malloc((*union_size) * sizeof(int));
    for (i = 0; i < *size_a; i++)
    {
        union_set[i] = set_a[i];
    }
    for (j = 0; j < *size_b; j++)
    {
        union_set[i + j] = set_b[j];
    }
    union_set = arr2set(union_set, union_size);
    union_set = sort_set(union_set, union_size);

    return union_set;
}

int *get_intersection(int *set_a, int *set_b, int *size_a, int *size_b, int *intersection_size){
    int i, j, k;
    int *intersection_set = (int *)malloc((*intersection_size) * sizeof(int));
    int num_intersection = 0;
    for (i = 0; i < *size_a; i++)
    {
        for (j = 0; j < *size_b; j++)
        {
            if (set_a[i] == set_b[j])
            {
                intersection_set[i] = set_a[i];
                num_intersection++;
                (*intersection_size)--;
            }
        }
    }
    (*intersection_size) -= ((*size_b) - num_intersection) + ((*size_a) - num_intersection);
    intersection_set = arr2set(intersection_set, intersection_size);
    intersection_set = sort_set(intersection_set, intersection_size);

    return intersection_set;
}

int *get_difference(int *set_a, int *set_b, int *size_a, int *size_b, int *difference_size){
    int i, j, k;
    int *difference_set = (int *)malloc((*difference_size) * sizeof(int));
    for (i = 0; i < *size_a; i++)
    {
        difference_set[i] = set_a[i];
    }
    for (i = 0; i < *size_a; i++)
    {
        for (j = 0; j < *size_b; j++)
        {
            if (difference_set[i] == set_b[j])
            {
                for (k = i; k < *size_a; k++)
                {
                    difference_set[k] = difference_set[k + 1];
                }
                (*difference_size)--;
            }
        }
    }
    difference_set = arr2set(difference_set, difference_size);
    difference_set = sort_set(difference_set, difference_size);

    return difference_set;
}

int *get_complement(int *set, int *size, int *uni_set, int *uni_size, int *complement_size){
    int i, j, k;
    int *complement_set = (int *)malloc((*uni_size) * sizeof(int));
    for (i = 0; i < *uni_size; i++)
    {
        complement_set[i] = uni_set[i];
    }
    
    for (i = 0; i < *size; i++)
    {
        for (j = 0; j < *uni_size; j++)
        {
            if (set[i] == complement_set[j])
            {
                for (k = j; k < *uni_size; k++)
                {
                    complement_set[k] = complement_set[k + 1];
                }
            }
        }
    }

    complement_set = arr2set(complement_set, complement_size);
    complement_set = sort_set(complement_set, complement_size);

    return complement_set;
}

int main()
{
    int m, n, a_size, b_size, i;

    /* INPUT SECTION */
    // get universal set
    scanf("%d %d", &m, &n);
    int *uni_set = gen_set_range(m, n, (n - m) + 1); // สร้าง universal set ขึ้นมาภายใน range ที่กำหนด

    // get set A
    scanf("%d", &a_size);
    int *arr_a = (int *)malloc(a_size * sizeof(int));
    for (i = 0; i < a_size; i++)
    {
        scanf("%d", &arr_a[i]);
    }
    int *set_a = arr2set(arr_a, &a_size);            // แปลง array เป็น set
    set_a = crop_set_in_range(set_a, &a_size, m, n); // ตัดเซตให้เหลือเฉพาะที่อยู่ใน range ที่กำหนด หรือเอาเฉพาะสมาชิกที่เป็น subset ของ universal set

    // get set B
    scanf("%d", &b_size);
    int *arr_b = (int *)malloc(b_size * sizeof(int));
    for (i = 0; i < b_size; i++)
    {
        scanf("%d", &arr_b[i]);
    }
    int *set_b = arr2set(arr_b, &b_size); // แปลง array เป็น set
    set_b = crop_set_in_range(set_b, &b_size, m, n); // ตัดเซตให้เหลือเฉพาะที่อยู่ใน range ที่กำหนด

    /* OUTPUT SECTION */

    // Show set A
    displayArr(set_a, a_size);

    // Show set B
    displayArr(set_b, b_size);

    // Union
    int union_size = a_size + b_size;
    int *union_set = get_union(set_a, set_b, &a_size, &b_size, &union_size);
    displayArr(union_set, union_size);

    // Intersection
    int intersection_size = a_size + b_size;
    int *intersection_set = get_intersection(set_a, set_b, &a_size, &b_size, &intersection_size);
    displayArr(intersection_set, intersection_size);

    // A - B
    int difference_size = a_size;
    int *difference_set = get_difference(set_a, set_b, &a_size, &b_size, &difference_size);
    displayArr(difference_set, difference_size);

    // B - A
    difference_size = b_size;
    difference_set = get_difference(set_b, set_a, &b_size, &a_size, &difference_size);
    displayArr(difference_set, difference_size);

    // Complement of A
    int complement_size = ((n - m) + 1) - a_size;
    int unisize = ((n - m) + 1);
    int *complement_set = get_complement(set_a, &a_size, uni_set, &unisize, &complement_size);
    displayArr(complement_set, complement_size);

    // Complement of B
    complement_size = ((n - m) + 1) - b_size;
    complement_set = get_complement(set_b, &b_size, uni_set, &unisize, &complement_size);
    displayArr(complement_set, complement_size);

    // free memory
    free(uni_set);
    free(arr_a);
    free(arr_b);
    free(set_a);
    free(set_b);
    free(union_set);
    free(intersection_set);
    free(difference_set);
    free(complement_set);
    

    return 0;
}