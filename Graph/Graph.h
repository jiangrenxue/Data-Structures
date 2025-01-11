#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MAX_VERTICES 100
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;
#endif