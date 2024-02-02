// Thinnaphat Kanchina 66070501013

#include <stdio.h>
#include <limits.h>

int minJumps(int arr[], int n, int start, int end) {
    if (end == start) {
        return 0;
    }
    if (arr[start] == 0) {
        return INT_MAX;
    }

    int min = INT_MAX;
    for (int i = start + 1; i <= start + arr[start] && i <= end; i++) {
        int jumps = minJumps(arr, n, i, end);
        if (jumps != INT_MAX && jumps + 1 < min) {
            min = jumps + 1;
        }
    }

    return min;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int jumps = minJumps(arr, n, 0, n - 1);

    if (jumps == INT_MAX) {
        printf("Not Possible\n");
    } else {
        printf("%d\n", jumps);
    }

    return 0;
}
