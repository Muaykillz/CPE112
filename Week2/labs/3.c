// Thinnaphat Kanchina 66070501013

#include <stdio.h>
#include <stdlib.h>

int get_primary_diagonal(int **arr, int row, int col){
    int sum = 0;
    for (int i = 0; i < row; i += 1){
        sum += arr[i][i];
    }
    return sum;
}
int get_secondary_diagonal(int **arr, int row, int col){
    int sum = 0;
    for (int i = 0; i < row; i += 1){
        sum += arr[i][col - i - 1];
    }
    return sum;
}

int main(){

    int row, col;
    scanf("%d %d", &row, &col);
    if (row != col){
        printf("ERROR\n");
        return 0;
    }
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i += 1){
        matrix[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j += 1){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Primary: %d\n", get_primary_diagonal(matrix, row, col));
    printf("Secondary: %d\n", get_secondary_diagonal(matrix, row, col));

    free(matrix);

    return 0;
}