// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void traverse(node *head)
{
    node *current = head;
    if (current == NULL)
    {
        printf("Invalid\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    int size = 0;
    int mode = 0;
    scanf("%d", &size);
    if (size == 0){
        printf("Invalid\n");
        return 0;
    }
    scanf("%d", &mode);
    if (mode == 1)
    {
        for (int i = 0; i < size; i++)
        {
            int data;
            scanf("%d", &data);
            node *new_node = (node *)malloc(sizeof(node));
            new_node->data = data;
            new_node->next = head;
            head = new_node;
        }
    }
    else if (mode == 2){
        for (int i = 0; i < size; i++)
        {
            int data;
            scanf("%d", &data);
            node *new_node = (node *)malloc(sizeof(node));
            new_node->data = data;
            new_node->next = NULL;
            if (head == NULL)
            {
                head = new_node;
            }
            else
            {
                node *current = head;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = new_node;
            }
        }
    }

    traverse(head);

    return 0;
}