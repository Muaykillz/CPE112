// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow.\n");
        exit(0);
    } else {
        s->items[++s->top] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
        exit(0);
    } else {
        return s->items[s->top--];
    }
}

void convertAndPrint(int n, int x) {
    if (n < 0 || x < 2 || x > 36) {
        printf("invalid\n");
        return;
    }
    Stack s;
    initStack(&s);
    while (n > 0) {
        int remainder = n % x;
        push(&s, remainder);
        n /= x;
    }
    while (!isEmpty(&s)) {
        int digit = pop(&s);
        if (digit < 10) {
            printf("%d", digit);
        } else {
            printf("%c", 'A' + digit - 10);
        }
    }
    printf("\n");
}

int main() {
    int n, x;
    
    scanf("%d", &n);
    scanf("%d", &x);

    convertAndPrint(n, x);

    return 0;
}
