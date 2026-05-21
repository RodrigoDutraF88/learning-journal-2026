#include <stdio.h>
// Exercício 10 — Intercalação de vetores
// Crie uma função:
// void intercala(int *v1, int *v2, int *v3, int n);
// Intercale os elementos de v1 e v2 em v3
// Resultado: v3 com tamanho 2n
// Regra: usar apenas aritmética de ponteiros

void intercala(int *v1, int *v2, int *v3, int n){
    for (int i = 0; i < n; i++) {

        *(v3 + (2 * i)) = *(v1 + i);
        
        *(v3 + (2 * i + 1)) = *(v2 + i);
    } 
}

int main(){
    int vetor1[] = {1, 2};
    int vetor2[] = {3, 4};
    int vetor3[4];
    int n = 2;
    intercala( vetor1, vetor2, vetor3, n);
    printf("Vetor intercalado:");
    for (int j = 0; j < 2 * n; j++) {
        printf("%d ", *(vetor3 + j));
    }

    return 0;   
}