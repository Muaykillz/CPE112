#include <stdio.h>

int findLastRemaining(int arr[], int size, int step) {
    int currentIndex = 0;
    while (size > 1) {
        currentIndex = (currentIndex + step - 1) % size;
        for (int i = currentIndex; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    return arr[0];
}

int main() {
    int size, step;

    scanf("%d %d", &size, &step);

    int arr[size];
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    int result = findLastRemaining(arr, size, step);
    printf("%d\n", result);

    return 0;
}
