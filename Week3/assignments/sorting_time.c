#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  int score;
  struct Node *next;
} Node;

Node *createNode(int id, int score) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->id = id;
  newNode->score = score;
  newNode->next = NULL;
  return newNode;
}

void insertAtEnd(Node **head, Node *newNode) {
  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void sortByid(Node **head) {
  Node *current = *head, *next;
  while (current != NULL) {
    next = current->next;
    while (next != NULL) {
      if (current->id > next->id) {
        int tempId = current->id;
        int tempScore = current->score;
        current->id = next->id;
        current->score = next->score;
        next->id = tempId;
        next->score = tempScore;
      }
      next = next->next;
    }
    current = current->next;
  }
}

void sortByScore(Node **head) {
  Node *current = *head, *next;
  while (current != NULL) {
    next = current->next;
    while (next != NULL) {
      if (current->score > next->score) {
        int tempId = current->id;
        int tempScore = current->score;
        current->id = next->id;
        current->score = next->score;
        next->id = tempId;
        next->score = tempScore;
      } else if (current->score == next->score && current->id > next->id) {
        int tempId = current->id;
        int tempScore = current->score;
        current->id = next->id;
        current->score = next->score;
        next->id = tempId;
        next->score = tempScore;
      }
      next = next->next;
    }
    current = current->next;
  }
}

void printScore(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d ", current->score);
    current = current->next;
  }
  printf("\n");
}

int main() {

  int size, mode;
  Node *head = NULL;
  scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    int id, score;
    scanf("%d %d", &id, &score);
    Node *newNode = createNode(id, score);
    insertAtEnd(&head, newNode);
  }

  scanf("%d", &mode);

  if (mode == 0) {
    sortByid(&head);
  } else if (mode == 1) {
    sortByScore(&head);
  }

  printScore(head);

  return 0;
}
