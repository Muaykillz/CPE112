#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

void deleteFirstOccurrence(struct Node** head, int x) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == x) {
        struct Node* temp = *head;
        if (temp->next == *head) {
            *head = NULL;
        } else {
            struct Node* current = *head;
            while (current->next != *head) {
                current = current->next;
            }
            current->next = temp->next;
            *head = temp->next;
        }
        free(temp);
    } else {
        struct Node* current = *head;
        while (current->next != *head && current->next->data != x) {
            current = current->next;
        }
        if (current->next->data == x) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    char command;
    int value;

    while (scanf(" %c", &command) == 1) {
        if (command == 'E') {
            break;
        }

        scanf("%d", &value);
        switch (command) {
            case 'I':
                insertAtEnd(&head, value);
                break;
            case 'D':
                deleteFirstOccurrence(&head, value);
                break;
        }
    }

    printList(head);
    return 0;
}
