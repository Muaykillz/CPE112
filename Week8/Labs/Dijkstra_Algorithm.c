// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#define INF 9999

struct vertex {
  int vertex;
  int path;
  int isVisited;
};

void createGraph(int v, int src, struct vertex vertex[]) {
  for (int i=0; i < v; i++) {
    vertex[i].vertex = i;
    vertex[i].path = INF;
    vertex[i].isVisited = 0;
  }
  vertex[src].path = 0;
}

int get_min(int v, struct vertex vertex[]) {
  int min = INF;
  int minNode = 0;
  for (int i=0; i < v; i++) {
    if (!(vertex[i].isVisited) && vertex[i].path < min) {
      min = vertex[i].path;
      minNode = i;
    }
  }
  return minNode;
}

void dijkstra(int v, struct vertex vertex[], int adjWM[][100]) {
  for (int i=0; i < v; i++) {
    int nearestNode = get_min(v, vertex);
    vertex[nearestNode].isVisited = 1;
    for (int neighbor = 0; neighbor < v; neighbor++) {
      if (adjWM[nearestNode][neighbor] != 0 &&
        vertex[neighbor].path > vertex[nearestNode].path + adjWM[nearestNode][neighbor])
      {
        vertex[neighbor].path = vertex[nearestNode].path + adjWM[nearestNode][neighbor];
      }
    }
  }
}

void display(int v, struct vertex vertex[]) {
  for (int i=0; i < v; i++) {
    printf("%d %d\n", vertex[i].vertex, vertex[i].path);
  }
}

int main() {
  struct vertex vertex[100];
  int v, src, adjWM[100][100];

  scanf(" %d", &v);
  scanf(" %d", &src);
  for (int i=0; i < v; i++) {
    for (int j=0; j < v; j++) {
      scanf(" %d", &adjWM[i][j]);
    }
  }
  createGraph(v, src, vertex);
  dijkstra(v, vertex, adjWM);
  display(v, vertex);

  return 0;
}