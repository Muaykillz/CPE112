// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001

typedef struct
{
  char character;
  int priority;
} CharPriority;

void enqueue(CharPriority queue[], int *rear, char character, int priority)
{
  int i = *rear;
  while (i > 0 && queue[i - 1].priority > priority)
  {
    queue[i] = queue[i - 1];
    i--;
  }
  queue[i].character = character;
  queue[i].priority = priority;
  (*rear)++;
}

void dequeue(CharPriority queue[], int *front, char *character, int *priority)
{
  *character = queue[*front].character;
  *priority = queue[*front].priority;
  (*front)++;
}

void printSecretCode(char input[])
{
  CharPriority queue[MAX_LENGTH];
  int front = 0, rear = 0;
  int length = strlen(input);

  for (int i = 0; i < length; i++)
  {
    char currentChar = input[i];
    int priority;

    if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z'))
    {
      if (currentChar == 'A' || currentChar == 'E' || currentChar == 'I' || currentChar == 'O' || currentChar == 'U' ||
          currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u')
      {
        priority = 1;
      }
      else
      {
        priority = 3;
      }
    }
    else
    {
      priority = 2;
    }

    enqueue(queue, &rear, currentChar, priority);
  }

  for (int i = 0; i < length; i++)
  {
    char currentChar;
    int priority;
    dequeue(queue, &front, &currentChar, &priority);
    printf("%c", currentChar);
  }

  printf("\n");
}

int main()
{
  char input[MAX_LENGTH];
  fgets(input, MAX_LENGTH, stdin);

  // Remove newline character from the input
  input[strcspn(input, "\n")] = '\0';

  printSecretCode(input);

  return 0;
}
