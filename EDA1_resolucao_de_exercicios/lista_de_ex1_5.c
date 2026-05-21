#include <stdio.h>
// Exercício 5 — Vetor com ponteiros
// Dado um vetor:
// int v[5] = {10, 20, 30, 40, 50};
// Faça:
// Percorra usando ponteiro (não use índice)
// Imprima os valores
// Some todos os elementos usando apenas aritmética de ponteiros
// Dica: use *(p + i) ou incremento de ponteiro

int somaVetorPonteiros(int *v){
    int somador = 0;
    for (int i= 0; i < 5; i++){
        somador += *(v + i); // ATENÇÃO

    }
    return somador;
}

int main(){
    int vetor1[] = {10, 20, 30, 40, 50};  
    int resultado = somaVetorPonteiros(vetor1);
    printf("Resultado da soma dos vetores: %d", resultado);

}