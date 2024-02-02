// Thinnaphat Kanchina 66070501013

#include <stdio.h>
#include <string.h>
#include <math.h>

struct Student {
   char name[101];
   float score;
};

int main() {
   int size;
   scanf("%d", &size);

   struct Student students[size];

   for (int i = 0; i < size; i++) {
       scanf("%s %f", students[i].name, &students[i].score);
   }

   // Calculate mean
   float sum = 0;
   for (int i = 0; i < size; i++) {
       sum += students[i].score;
   }
   float mean = sum / size;

   // Calculate standard deviation
   float squared_diff_sum = 0;
   for (int i = 0; i < size; i++) {
       float diff = students[i].score - mean;
       squared_diff_sum += diff * diff;
   }
   float variance = squared_diff_sum / size;
   float std_dev = sqrt(variance);

   // Find student with highest and lowest scores
   struct Student *max_student = &students[0];
   struct Student *min_student = &students[0];
   for (int i = 1; i < size; i++) {
       if (students[i].score > max_student->score) {
           max_student = &students[i];
       }
       if (students[i].score < min_student->score) {
           min_student = &students[i];
       }
   }

   printf("%.2f %.2f %s %s\n", mean, std_dev, max_student->name, min_student->name);

   return 0;
}
