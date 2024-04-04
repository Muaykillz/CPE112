#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
   int source, destination, weight;
   struct Edge* next;
} Edge;

void addEdge(Edge** head, int source, int destination, int weight) {
   Edge* newEdge = (Edge*)malloc(sizeof(Edge));
   newEdge->source = source;
   newEdge->destination = destination;
   newEdge->weight = weight;
   newEdge->next = NULL;

   if (*head == NULL || (*head)->source > source || ((*head)->source == source && (*head)->destination > destination) || ((*head)->source == source && (*head)->destination == destination && (*head)->weight > weight)) {
       newEdge->next = *head;
       *head = newEdge;
   } else {
       Edge* current = *head;
       while (current->next != NULL && (current->next->source < source || (current->next->source == source && current->next->destination < destination) || (current->next->source == source && current->next->destination == destination && current->next->weight <= weight))) {
           current = current->next;
       }
       newEdge->next = current->next;
       current->next = newEdge;
   }
}

void printGraph(Edge* head) {
   Edge* current = head;
   while (current != NULL) {
       printf("%d -> %d (%d)\n", current->source, current->destination, current->weight);
       current = current->next;
   }
}

int main() {
   int numEdges;
   scanf("%d", &numEdges);

   Edge* head = NULL;

   for (int i = 0; i < numEdges; i++) {
       int source, destination, weight;
       scanf("%d %d %d", &source, &destination, &weight);
       addEdge(&head, source, destination, weight);
   }

   printGraph(head);

   return 0;
}