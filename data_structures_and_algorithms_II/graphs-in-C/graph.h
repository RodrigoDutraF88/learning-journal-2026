#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph Graph

Graph* createGraph(int n);
void insertEdge(Graph* g, int u, int v);
void removeEdge(Graph* g, int u, int v);
void printGraph(Graph* g);
void destroyGraph(Graph* g);

#endif 