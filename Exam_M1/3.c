#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 15

int s[MAX];
int size = 0;
int top = -1;

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return 1;
    }
    return s[top--];
}

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow.\n");
        exit(0);
    }

    // if (data == s[top]){
    //     pop();
    // }
    s[++top] = data;
}

int peek()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        exit(0);
    }
    return s[top];
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%c ", s[i]);
    }
    printf("\n");
}

char *shortenString(char *string, int sizeStr, int *top)
{
    char *s = (char *)malloc(10 * sizeof(char));
    for (int i = 0; i < sizeStr; i++)
    {
        // printf("s: %s, string: %c, top: %d \n", s, string[i], *top);
        if (string[i] == s[*top])
        {
            (*top)--;
        }
        else
        {
            ++(*top);
            s[*top] = string[i];
        }
    }
    printf("top: %d\n", *top);
    if (*top == -1)
    {
        return "Empty String";
    }
    return s;
}

int main()
{

    char string[100];
    scanf("%s", string);
    int str_length = strlen(string);
    if (str_length > 10)
    {
        printf("String Overflow!\n");
        return 1;
    }
    else
    {
        // push
        for (int i = 0; i < 3; i++)
        {
            push(string[i]);
        }
        display();

        // peek
        printf("%c\n", peek());

        // pop
        for (int i = 0; i < 2; i++)
        {
            pop();
        }
        display();

        // shortenString
        int *top_s;
        *top_s = -1;
        char *shortString = shortenString(string, str_length, top_s);
        printf("%s\n", shortString);
        printf("top_s, %d\n", *top_s);
        if (*top_s == -1)
        {
            printf("Stack is empty.\n");
            return 0;
        }
        for (int i = 0; i <= (*top_s)+1; i++)
        {
            printf("%c ", shortString[i]);
        }
        printf("\n");
    }

    return 0;
}