#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || m == n) {
        return head;
    }

    ListNode *dummy = malloc(sizeof(ListNode));
    dummy->next = head;

    ListNode *prev = dummy;
    for (int i = 1; i < m; i++) {
        prev = prev->next;
    }

    ListNode *current = prev->next;
    ListNode *next = NULL;

    for (int i = m; i < n; i++) {
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy->next;
}

void printList(ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

ListNode* createList(int arr[], int size) {
    if (size == 0) {
        return NULL;
    }

    ListNode *head = malloc(sizeof(ListNode));
    head->val = arr[0];
    head->next = NULL;
    ListNode *current = head;

    for (int i = 1; i < size; i++) {
        current->next = malloc(sizeof(ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }

    return head;
}

int main() {
    char input[10];
    int arr[100], m, n, val;
    int i = 0;
    while (1) {
        scanf("%s", input);

        if (strcmp(input, "END") == 0) {
            break;
        }

        val = atoi(input);
        arr[i++] = val;
    }
    scanf("%d %d", &m, &n);
    ListNode *head = createList(arr, i);
    head = reverseBetween(head, m, n);
    printList(head);

    return 0;
}
