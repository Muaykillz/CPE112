// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int getPrecedence(char operator) {
    if (operator == '^') {
        return 3;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '+' || operator == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);

    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&s, token);
        } else if (token == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop the '('
        } else {
            while (!isEmpty(&s) && getPrecedence(s.items[s.top]) >= getPrecedence(token)) {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
        i++;
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("%s\n", postfix);

    return 0;
}
