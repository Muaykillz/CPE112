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
        printf("none\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void deleteFirst(node **head)
{
    if (*head == NULL)
    {
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteLast(node **head)
{
    if (*head == NULL)
    {
        return;
    }
    node *ptr = *head;
    node *preptr = ptr;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    if (preptr == ptr)
    {
        *head = NULL;
    }
}
void deleteNumOnce(node **head, int num)
{
    node *ptr = *head;
    node *preptr = ptr;
    int is_found = 0;
    while (ptr != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
        if (ptr != NULL)
        {
            if (ptr->data == num)
            {
                is_found = 1;
                break;
            }
        }
    }
    if (is_found == 1)
    {
        if ((*head)->data == num)
        {
            deleteFirst(head);
        }
        else
        {
            node *temp = ptr;
            preptr->next = ptr->next;
            free(temp);
        }
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

    while (1)
    {
        char mode;
        scanf(" %c", &mode);
        if (mode == 'N')
        {
            int num;
            scanf("%d", &num);
            deleteNumOnce(&list, num);
        }
        else if (mode == 'F')
        {
            deleteFirst(&list);
        }
        else if (mode == 'L')
        {
            deleteLast(&list);
        }
        else
        {
            break;
        }
    }

    traverse(list);

    return 0;
}