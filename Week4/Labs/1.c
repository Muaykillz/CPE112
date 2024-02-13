// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000000

int stack[MAX_SIZE];
int size = 0;
int top = -1;

int isFull()
{
    return top == size - 1;
}

int isEmpty()
{
    return top == -1;
}
void push(int data)
{
    // printf("top: %d\n", top);
    if (isFull())
    {
        printf("Stack Overflow.\n");
        exit(0);
    }
    stack[++top] = data;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow.\n");
        exit(0);
    }
    return stack[top--];
}

void show()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    // int size;
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Please enter a positive number.\n");
        return 1;
    }

    int choice, result;
    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int data;
        case 1:
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            result = pop();
            if (result == -1)
            {
                break;
            }
            break;
        case 3:
            show();
            return 0;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
            return 1;
        }
    }
    return 0;
}
