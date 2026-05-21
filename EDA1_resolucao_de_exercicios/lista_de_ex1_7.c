#include <stdio.h>
// Exercício 7 — Maior elemento do vetor
// Implemente:
// int maior(int *v, int tamanho);
// Use apenas ponteiros (sem v[i])
// Retorne o maior valor

int maior(int *v, int tamanho){
    int max = *v;
    for (int i= 0; i < tamanho; i++){
        if ( *(v + i) > max){
            max = *(v + i);
        }
    
    }
    return max;
}
int main(){
    int vetor1[]= {1, 2, 3, 4};
    int *ptr = vetor1;
    int resultado = maior(ptr, 4);
    printf("Maior : %d", resultado);


}