#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** copyEdgesWithout(int** edges, int edgesSize, int edgeId) {
    int** edgesCopy = (int**)calloc(edgesSize-1, sizeof(int*));
    unsigned int skipped = 0;
    for (unsigned int i = 0; i < edgesSize-1; i++) {
      if (i == edgeId)
        skipped += 1;
      
      edgesCopy[i] = edges[i+skipped];
    }
    return edgesCopy;
  }
  
  bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    // Check if arrived at destination
    if (source == destination)
      return true;
    
    // Go through all edges of current vertice
    for (unsigned int e = 0; e < edgesSize; e++) {
      bool isPair = false;
      int connected_vertex = 0;
      if (edges[e][0] == source) {
        connected_vertex = edges[e][1];
        isPair = true;
      }
      else if (edges[e][1] == source) {
        connected_vertex = edges[e][0];
        isPair = true;
      }
      if (isPair) {
        int **edgesCopy = copyEdgesWithout(edges, edgesSize, e);
        bool foundDest = validPath(n, edgesCopy, edgesSize-1, edgesColSize, connected_vertex, destination);
        free(edgesCopy);
        if (foundDest)
          return true;
      }
    }
  
    // No connection with the destination
    return false;
  }

  int main() {
    // Test case 1
    int n = 3;
    int edgesSize = 3;
    int edgesColSize = 2;
    int source = 0;
    int destination = 2;
    int edges[3][2] = {{0,1},{1,2},{2,0}};
    int** edgesPtr = (int**)calloc(edgesSize, sizeof(int*));
    for (unsigned int i = 0; i < edgesSize; i++) {
      edgesPtr[i] = edges[i];
    }
    bool result = validPath(n, edgesPtr, edgesSize, &edgesColSize, source, destination);
    printf("Result: %s\n", result ? "true" : "false");

    // Test case 2
    n = 6;
    edgesSize = 5;
    source = 0;
    destination = 5;
    int edges2[5][2] = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    edgesPtr = (int**)calloc(edgesSize, sizeof(int*));
    for (unsigned int i = 0; i < edgesSize; i++) {
      edgesPtr[i] = edges2[i];
    }
    result = validPath(n, edgesPtr, edgesSize, &edgesColSize, source, destination);
    printf("Result: %s\n", result ? "true" : "false");

    return 0;
  } 