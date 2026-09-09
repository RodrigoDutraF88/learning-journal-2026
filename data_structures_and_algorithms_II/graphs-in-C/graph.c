// Implementation of graph operations
//this will change depending in the implementation of the graph
//with matrix, list

//matrix
struct Graph {
    int n;
    int **matrix;
};

//list
typedef struct No {
    int v;
    struct No *next;
} No;
struct Graph {
    int n;
    No **list;
};

//Full matrix implementation

Graph* createGraph(int n) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->matrix[i] = (int*)calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            g->matrix[i][j] = 0;
        }
    }
    return g;
}

void insertEdge(Graph* g, int u, int v) {
        g->matrix[u][v] = 1;
        g->matrix[v][u] = 1; 

}

void removeEdge(Graph* g, int u, int v) {
    g->matrix[u][v] = 0;
    g->matrix[v][u] = 0; 
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

void destroyGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g);
}

//full list implementation

Graph* createGraph(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->n = n;
    g->list = malloc(n * sizeof(No*));
    for (int i = 0; i < n; i++) {
        g->list[i] = NULL;
    }
    return g;
}

void insertEdge(Graph* g, int u, int v) {
    No *newNode = malloc(sizeof(No));
    newNode->v = v;
    newNode->next = g->list[u];
    g->list[u] = newNode;

    newNode = malloc(sizeof(No));
    newNode->v = u;
    newNode->next = g->list[v];
    g->list[v] = newNode;
}

void removeEdge(Graph* g, int u, int v) {
    No *prev = NULL;
    No *curr = g->list[u];
    while (curr != NULL) {
        if (curr->v == v) {
            if (prev == NULL) {
                g->list[u] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    prev = NULL;
    curr = g->list[v];
    while (curr != NULL) {
        if (curr->v == u) {
            if (prev == NULL) {
                g->list[v] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d: ", i);
        No *curr = g->list[i];
        while (curr != NULL) {
            printf("%d -> ", curr->v);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}