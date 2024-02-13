// 66070501013 Thinnaphat Kanchina

#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
  int n;
  scanf("%d", &n);
  towerOfHanoi(n, 'A', 'C', 'B');
  printf("Total moves: %d\n", (1 << n) - 1);
  return 0;
}
