// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    } else {
        s->items[++s->top] = value;
    }
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
        return '\0';
    } else {
        return s->items[s->top--];
    }
}

bool isPalindrome(char *input) {
    Stack s;
    initStack(&s);

    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        push(&s, input[i]);
    }

    for (int i = 0; i < length; i++) {
        char popped = pop(&s);

        if (popped != input[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char input[MAX_SIZE];

    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
