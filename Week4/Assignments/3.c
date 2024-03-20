// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

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
        exit(0);
    } else {
        s->items[++s->top] = value;
    }
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
        exit(0);
    } else {
        return s->items[s->top--];
    }
}

bool isPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(char *str) {
    Stack s;
    initStack(&s);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&s, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(&s) || !isPair(pop(&s), str[i])) {
                return false;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char str[MAX_SIZE];
    scanf("%s", str);

    if (isBalanced(str)) {
        printf("The string is balanced\n");
    } else {
        printf("The string is not balanced\n");
    }

    return 0;
}
