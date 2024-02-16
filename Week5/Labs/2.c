// 66070501013 Thinnaphat Kanchina

#include <stdio.h>

int size;

int circularQueue[10];
int front = -1, rear = -1;

void insertq(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1) || (front == -1 && rear == size - 1)) {
        printf("Queue is full!!\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        if (rear == size - 1)
            rear = 0;
        else
            rear = rear + 1;
    }

    circularQueue[rear] = value;
}

int dequeue() {
    int deletedValue;

    if (front == -1) {
        printf("Queue is empty!!\n");
        return -1;
    }

    deletedValue = circularQueue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }

    return deletedValue;
}

void show() {
    if (front == -1) {
        printf("Queue is empty!!\n");
        return;
    }

    printf("Front: %d\n", front);
    printf("Items: ");
    int i = front;
    do {
        printf("%d ", circularQueue[i]);
        if (i == rear)
            break;
        if (i == size - 1)
            i = 0;
        else
            i++;
    } while (1);
    printf("\nRear: %d\n", rear);
}

int main() {
    int value;
    char command;

    scanf("%d", &size);

    while (1) {
        scanf(" %c", &command);

        if (command == 'E') {
            break;
        } else if (command == 'I') {
            scanf("%d", &value);
            insertq(value);
        } else if (command == 'D') {
            int deletedValue = dequeue();
            if (deletedValue != -1) {
                printf("%d\n", deletedValue);
            }
        } else if (command == 'S') {
            show();
        }
    }

    return 0;
}
