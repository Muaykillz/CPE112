#include <stdio.h>
#define ROW 4
#define COL 6

void findAvg(int data[ROW][COL])
{
    int x, y, sum, kx, ky;

    for (y=1; y<ROW-1; y++){
        for (x=1; x<COL-1; x++){
            sum = 0;
            for (ky=-1; ky<=1; ky++){
                for (kx=-1; kx<=1; kx++){
                    sum += data[y+ky][x+kx];
                }
            }

            data[y][x] = (int)sum/9;
        }
    }
}

void printData(int data[ROW][COL]){
    int x, y;
    for (y=0; y<ROW; y++){
        for (x=0; x<COL; x++){
            printf("%d ", data[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    int input[ROW][COL] = { {1, 1, 1, 2, 2, 2},
                            {3, 3, 3, 4, 4, 4},
                            {1, 1, 1, 2, 2, 2},
                            {3, 3, 3, 4, 4, 4} };

    findAvg(input);
    printData(input);
    return 0;
}