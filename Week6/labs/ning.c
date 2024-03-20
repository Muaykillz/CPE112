#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *binaryTree = NULL;

void createBinaryT(int size) {
    binaryTree = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        binaryTree[i] = -999;
    }
}

void createRoot(int value) {
    if (binaryTree[0] != -999) {
        printf("cannot create duplicated root\n");
    } else {
        binaryTree[0] = value;
    }
}

void insertLeft(int parent, int value, int size) {
    int In = 0;
    for (int i=0; i<size;i++) {
      if (parent == binaryTree[i]) {
        if (binaryTree[(i*2) + 1] == -999) {
            binaryTree[(i*2) + 1] = value;
            In = 1;
            break;
        }
        else if ((i*2)+1 > size) {
          printf("overflow\n");
          In = 1;
          break;
        } 
        else {
          In = 1;
          printf("node already presented\n");
          break;
        } 
      }
    }
  if (In == 0) {
    printf("not found\n");
  }
}
   

void insertRight(int parent, int value, int size) {
  int In = 0;
    for (int i=0; i<size;i++) {
      if (parent == binaryTree[i]) {
        if (binaryTree[(i*2) + 2] == -999) {
            binaryTree[(i*2) + 2] = value;
            In = 1;
            break;
        }
        else if ((i*2)+2 > size) {
          printf("overflow\n");
          In = 1;
          break;
        } 
        else {
          In = 1;
          printf("node already presented\n");
          break;
        } 
      }
    }
  if (In == 0) {
    printf("not found\n");
  }
}


void display(int size) {
    for (int i = 0; i < size; i++) {
        if (binaryTree[i] == -999) {
            printf("null ");
        } else {
            printf("%d ", binaryTree[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int size;
    scanf("%d", &size);
    createBinaryT(size);

    while (1) {
        int parent, value;
        char command[5];
        scanf("%s", command);
        if (strcmp(command, "ROOT") == 0) {
            scanf("%d", &value);
            createRoot(value);
        } else if (strcmp(command, "INSL") == 0) {
            scanf("%d %d", &parent, &value);
            insertLeft(parent, value, size);
        } else if (strcmp(command, "INSR") == 0) {
            scanf("%d %d", &parent, &value);
            insertRight(parent, value, size);
        } else if (strcmp(command, "END") == 0) {
            break;
        }
    }
    display(size);

    free(binaryTree);

    return 0;
}