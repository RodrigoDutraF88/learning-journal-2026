#include <stdio.h>
// Recebe vetor v[p..r] com p <= r. Rearranja
 // os elementos do vetor e devolve j em p..r
 // tal que v [p..j- 1] <= v [j] < v[j+1..r].
int separa (int v [ ] , int p, int r) {
    int c = v[r]; // pivô
    int t, j = p;
    for (int k = p; k < r; ++k)
        if (v[k] <= c) {
            t = v [ j ] , v [ j ] = v[k], v[k] = t;
            ++j;
        }
    t = v [ j ] , v [ j ] = v[r], v[r] = t;
    return j;
}

void quicksort (int v [ ] , int p, int r){
    if (p < r) {
        int j = separa ( v , p, r);
        quicksort ( v , p, j- 1 );
        quicksort ( v , j+1 , r);
    }
}

int main(){
    // Vetor de teste desordenado
    int v[] = {7, 2, 9, 4, 3, 8, 1, 6, 5};
    int n = sizeof(v) / sizeof(v[0]); // Descobre o tamanho total do vetor (9 elementos)

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\n");

    // ATENÇÃO: O quicksort do slide recebe o índice do primeiro elemento (0) 
    // e o índice do ÚLTIMO elemento (n - 1), não o tamanho total do vetor.
    quicksort(v, 0, n - 1);

    printf("Vetor ordenado pelo QuickSort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;

}