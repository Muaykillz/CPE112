// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>


int sumTree(int arr[], int n, int index)
{

    if (index >= n)
        return 0;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    return arr[index] + sumTree(arr, n, leftChildIndex) + sumTree(arr, n, rightChildIndex);
}

int main()
{
    int arr[1000];
    int val, index = 0;

    while (1)
    {
        scanf("%d", &val);
        if (val == -1001)
            break;

        arr[index++] = val;
    }

    int result = sumTree(arr, index, 0);

    if (index == 1){
        printf("True\n");
        return 0;
    }
    if (result/2 == arr[0])
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
