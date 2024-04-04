// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>

typedef struct Pair_Vertex{
    int startPoint;
    int endPoint;
} Pair;

typedef struct Linked {
    int Data;
    struct Linked* Next;
} Node;

int Absolute_Visited(int num, int numEdge){
    if(num > 0){return num;}
    else {return num*-1 + numEdge;}
}

Node *Push(Node *Head, int newData){
    Node* newNode = malloc(sizeof(Node));
    newNode->Data = newData;
    newNode->Next = Head;

    return newNode;
}

Node* Pop(Node* Head){
    if(Head == NULL){return NULL;}

    Node* pDelNode = Head;
    Head = Head->Next;

    free(pDelNode);

    return Head;
}

int Top(Node** Head){
    return (*Head)->Data;
}

int isEmpty(Node* Head){
    if(Head == NULL){return 1;}
    return 0;
}

void InsertSortMax(Pair edgeList[], int numEdge){
    for(int i=0; i<numEdge; i++){
        int Max = i;
        for(int j=i + 1; j<numEdge; j++){
            if(edgeList[j].endPoint > edgeList[Max].endPoint){
                Max = j;
            }
        }
        Pair Temp = edgeList[i];
        edgeList[i] = edgeList[Max];
        edgeList[Max] = Temp;
    }
}

void DFS(int Current, Pair edgeList[], int numEdge, int numVertex){
    int Visited[2001];
    for(int i=0; i<=2001; i++){
        Visited[i] = 0;
    }
    Node* Head = NULL;
    Head = Push(Head, Current);

    do {
        Current = Top(&Head);
        Head = Pop(Head);

        if(Visited[Absolute_Visited(Current, numEdge)] == 1){
            continue;
        }
        Visited[Absolute_Visited(Current, numEdge)] = 1;
        printf("%d ", Current);

        for(int i=0; i<numEdge; i++){
            if(edgeList[i].startPoint == Current && Visited[Absolute_Visited(edgeList[i].endPoint, numEdge)] == 0){ 
                Head = Push(Head, edgeList[i].endPoint);
            }
        }
    } while ( ! isEmpty(Head) );
}

Node* enqueue(Node* Head, int newData){
    Node* newNode = malloc(sizeof(Node));
    newNode->Data = newData;
    newNode->Next = NULL;

    if(Head == NULL){return newNode;}

    Node* Curr = Head;
    while(Curr->Next != NULL){Curr = Curr->Next;}

    Curr->Next = newNode;
    return Head;
}

Node* dequeue(Node* Head){
    if(Head == NULL){return NULL;}
    
    Node* DelCurr = Head;
    Head = Head->Next;

    free(DelCurr);

    return Head;
}

int Front(Node** Head){
    return (*Head)->Data;
}

void InsertSortMin(Pair edgeList[], int numEdge){
    for(int i=0; i<numEdge; i++){
        int Min = i;
        for(int j=i + 1; j<numEdge; j++){
            if(edgeList[j].endPoint < edgeList[Min].endPoint){
                Min = j;
            }
        }

        //Swap
        Pair Temp = edgeList[i];
        edgeList[i] = edgeList[Min];
        edgeList[Min] = Temp;
    }
}

void BFS(int Current, Pair edgeList[], int numEdge, int numVertex){

    int Visited[2001];
    for(int i=0; i<=2001; i++){
        Visited[i] = 0;
    }

    Node* Head = NULL;
    Head = enqueue(Head, Current);

    do {

        Current = Front(&Head);
        Head = dequeue(Head);

        if(Visited[Absolute_Visited(Current, numEdge)] == 1){continue;}

        Visited[Absolute_Visited(Current, numEdge)] = 1;

        printf("%d ", Current);

        for(int i=0; i<numEdge; i++){
            if(edgeList[i].startPoint == Current && Visited[Absolute_Visited(edgeList[i].endPoint, numEdge)] == 0){

                Head = enqueue(Head, edgeList[i].endPoint);

            }
        }

    } while ( ! isEmpty(Head) );
}

int main(){
    int vertices, edges; 

    scanf("%d", &vertices);
    scanf("%d", &edges);

    Pair edgeList[edges];
    for(int i=0; i<edges; i++){
        scanf(" %d %d", &edgeList[i].startPoint, &edgeList[i].endPoint);
    }

    int start; 
    scanf("%d", &start);
    
    InsertSortMin(edgeList, edges);
    BFS(start, edgeList, edges, vertices);   
    printf("\n");

    InsertSortMax(edgeList, edges);
    DFS(start, edgeList, edges, vertices);
    return 0;
}