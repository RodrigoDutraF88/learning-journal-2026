//aplaying graphs in C

/*
Basic Operations
1)Create a graph
3)Insert a vertex
4)Insert an edge
5)Remove a vertex
6)Remove an edge
7) Print the graph
8) Delete the graph

General structure: 
graph.h -> public interface
main.c ->program
graph.c -> implementation
*/


#include <stdio.h>
#include "graph.h"

int main() {
    Grafo *g = criaGrafo(4);

    inserirAresta(g, 0, 1);
    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 3);

    imprimirGrafo(g);
    destruirGrafo(g);
    return 0;
}
