// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *head = NULL;

void push(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

int pop() {
  if (head == NULL) {
    printf("empty\n");
    return -1;
  }
  Node *temp = head;
  int data = temp->data;
  head = head->next;
  free(temp);
  return data;
}

void top() {
  if (head == NULL) {
    printf("empty\n");
    return;
  }
  printf("%d\n", head->data);
}

int empty() {
  return head == NULL;
}

int main() {
  char command;
  int data;
  while (1) {
    scanf(" %c", &command);
    switch (command) {
      case 'p':
        scanf(" %d", &data);
        push(data);
        break;
      case 'o':
        data = pop();
        if (data != -1) {
          printf("%d\n", data);
        }
        break;
      case 't':
        top();
        break;
      case 'e':
        printf("%d\n", empty());
        break;
      case 'q':
        return 0;
    }
  }
  return 0;
}
