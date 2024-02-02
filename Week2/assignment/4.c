// Thinnaphat Kanchina 66070501013

#include <stdio.h>
#include <stdlib.h>

int **get_multiplication_matrix(int a_row, int a_col, int a[a_row][a_col], int b_row, int b_col, int b[b_row][b_col])
{
    int i, j, k;
    int **c = (int **)malloc(a_row * sizeof(int *));
    for (i = 0; i < a_row; i++)
    {
        c[i] = (int *)malloc(b_col * sizeof(int));
    }
    for (i = 0; i < a_row; i++)
    {
        for (j = 0; j < b_col; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < a_col; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

void display_arr(int row, int col, int **arr)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a_row, a_col, b_row, b_col, i, j, k;
    scanf("%d %d", &a_row, &a_col);
    int a[a_row][a_col];
    for (i = 0; i < a_row; i++)
    {
        for (j = 0; j < a_col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &b_row, &b_col);
    int b[b_row][b_col];
    for (i = 0; i < b_row; i++)
    {
        for (j = 0; j < b_col; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    if (a_col != b_row)
    {
        printf("Not Compatible\n");
        return 0;
    }
    int **c = get_multiplication_matrix(a_row, a_col, a, b_row, b_col, b);
    display_arr(a_row, b_col, c);

    return 0;
}
