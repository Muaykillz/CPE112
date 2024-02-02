// Thinnaphat Kanchina 66070501013

#include <stdio.h>

int main() {
   int m, n;

   if (scanf("%d %d", &m, &n) != 2) {
       fprintf(stderr, "Error: Invalid input\n");
       return 1;
   }
   int matrix[m][n];

   for (int i = 0; i < m; i++) {
       for (int j = 0; j < n; j++) {
           if (scanf("%d", &matrix[i][j]) != 1) {
               fprintf(stderr, "Error: Invalid input\n");
               return 1;
           }
       }
   }

   int isSymmetric = 1, isSkewSymmetric = 1;
   for (int i = 0; i < m; i++) {
       for (int j = 0; j < i; j++) {
           if (matrix[i][j] != matrix[j][i]) {
               isSymmetric = 0;
           }
           if (matrix[i][j] != -matrix[j][i]) {
               isSkewSymmetric = 0;
           }
           if (!isSymmetric && !isSkewSymmetric) {
               break;
           }
       }
   }

   // show the result
   if (isSymmetric) {
       printf("The matrix is symmetric\n");
   } else if (isSkewSymmetric) {
       printf("The matrix is skew-symmetric\n");
   } else {
       printf("None\n");
   }

   return 0;
}
