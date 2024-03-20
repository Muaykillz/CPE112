// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void addNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        struct Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
}

void deleteNode(int data)
{
    struct Node *current = head;

    while (current != NULL && current->data != data)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        return; // Node not found
    }

    if (current == head)
    {
        head = current->next;
    }
    else
    {
        current->prev->next = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);
}

void searchNeighbors(int data)
{
    struct Node *current = head;

    while (current != NULL && current->data != data)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("none\n");
    }
    else
    {
        if (current->prev == NULL)
        {
            printf("NULL ");
        }
        else
        {
            printf("%d ", current->prev->data);
        }

        if (current->next == NULL)
        {
            printf("NULL\n");
        }
        else
        {
            printf("%d\n", current->next->data);
        }
    }
}

void printListForward()
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printListBackward()
{
    struct Node *current = head;
    if (current == NULL)
    {
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main()
{
    char command[5];
    int data;

    while (1)
    {
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0)
        {
            scanf("%d", &data);
            addNode(data);
        }
        else if (strcmp(command, "DEL") == 0)
        {
            scanf("%d", &data);
            deleteNode(data);
        }
        else if (strcmp(command, "SCH") == 0)
        {
            scanf("%d", &data);
            searchNeighbors(data);
        }
        else if (strcmp(command, "END") == 0)
        {
            break;
        }
    }

    printListForward();
    printListBackward();

    return 0;
}
