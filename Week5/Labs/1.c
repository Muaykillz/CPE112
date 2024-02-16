// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_COMMAND_LENGTH 10

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int time;
} Song;

typedef struct Node
{
    Song data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(char name[], char artist[], int time)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data.name, name);
    strcpy(newNode->data.artist, artist);
    newNode->data.time = time;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("No songs in the playlist\n");
    }
    else
    {
        Node *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        printf("Now playing: %s by %s\n", temp->data.name, temp->data.artist);
        free(temp);
    }
}

// void displayPlaylist()
// {
//     if (front == NULL)
//     {
//         printf("No songs in the playlist\n");
//     }
//     else
//     {
//         Node *temp = front;
//         printf("Songs in the playlist:\n");
//         while (temp != NULL)
//         {
//             printf("%s by %s %d\n", temp->data.name, temp->data.artist, temp->data.time);
//             temp = temp->next;
//         }

//         printf("Remaining Time: %d\n", front->data.time);
//     }
// }

void displayPlaylist()
{
    if (front == NULL)
    {
        printf("No songs in the playlist\n");
    }
    else
    {
        Node *temp = front;
        int sum = 0;

        printf("Songs in the playlist:\n");
        while (temp != NULL)
        {
            printf("%s by %s %d\n", temp->data.name, temp->data.artist, temp->data.time);
            sum += temp->data.time;
            temp = temp->next;
        }

        printf("Remaining Time: %d\n", sum);
    }
}

int main()
{
    char input[MAX_COMMAND_LENGTH];
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int time;

    while (1)
    {
        fgets(input, sizeof(input), stdin);

        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        if (strcmp(input, "add") == 0)
        {
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0';
            fgets(artist, sizeof(artist), stdin);
            artist[strlen(artist) - 1] = '\0';
            scanf("%d", &time);
            getchar();

            enqueue(name, artist, time);
        }
        else if (strcmp(input, "play") == 0)
        {
            dequeue();
        }
        else if (strcmp(input, "sum") == 0)
        {
            displayPlaylist();
            break;
        }
    }

    return 0;
}
