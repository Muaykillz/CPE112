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

int findDataInList(node **head, int r)
{
    int idx = -1;
    int count = 0;

    node *ptr = *head;
    while (ptr != NULL)
    {
        if (ptr->data == r)
        {
            idx = count;
            break;
        }
        count++;
        ptr = ptr->next;
    }

    return idx;
}

void insertAfter(node **head, int r, int v)
{
    node *newnode, *ptr, *preptr;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = v;
    newnode->next = NULL;
    ptr = *head;
    preptr = ptr;
    while (preptr->data != r)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (r == (*head)->data)
    {
        newnode->next = (*head)->next;
        (*head)->next = newnode;
    }
    else
    {
        preptr->next = newnode;
        newnode->next = ptr;
    }
}

void insertBefore(node **head, int r, int v)
{
    node *new_node, *ptr, *preptr;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = NULL;
    ptr = *head;
    preptr = ptr;
    while (ptr->data != r)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (r == (*head)->data)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        preptr->next = new_node;
        new_node->next = ptr;
    }
}

int main()
{

    int size;
    scanf("%d", &size);
    node *list = NULL;

    for (int i = 0; i < size; i++)
    {
        int data;
        scanf("%d", &data);
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;
        if (list == NULL)
        {
            list = new_node;
            continue;
        }
        node *ptr = list;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    char mode;
    while (1)
    {
        scanf(" %c", &mode);
        if (mode == 'E')
        {
            break;
        }
        int r, v;
        scanf("%d %d", &r, &v);

        int idx = findDataInList(&list, r);

        if (idx != -1)
        {
            if (mode == 'A')
            {
                insertAfter(&list, r, v);
            }
            else if (mode == 'B')
            {
                insertBefore(&list, r, v);
            }
        }

        traverse(list);
    }

    traverse(list);

    return 0;
}