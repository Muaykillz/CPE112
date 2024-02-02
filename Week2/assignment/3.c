// Thinnaphat Kanchina 66070501013

#include <stdio.h>

#define MAX_SIZE 100

void spiralPrint(int m, int n, int arr[MAX_SIZE][MAX_SIZE]) {
   int i, k = 0, l = 0;

   while (k < m && l < n) {
       for (i = l; i < n; ++i) {
           printf("%d ", arr[k][i]);
       }
       k++;

       for (i = k; i < m; ++i) {
           printf("%d ", arr[i][n - 1]);
       }
       n--;

       if (k < m) {
           for (i = n - 1; i >= l; --i) {
               printf("%d ", arr[m - 1][i]);
           }
           m--;
       }

       if (l < n) {
           for (i = m - 1; i >= k; --i) {
               printf("%d ", arr[i][l]);
           }
           l++;
       }
   }
}

int main() {
   int m, n, i, j;
   scanf("%d %d", &m, &n);

   int arr[MAX_SIZE][MAX_SIZE];

   for (i = 0; i < m; i++) {
       for (j = 0; j < n; j++) {
           scanf("%d", &arr[i][j]);
       }
   }

   spiralPrint(m, n, arr);

   return 0;
}
