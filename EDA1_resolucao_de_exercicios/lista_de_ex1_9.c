#include <stdio.h>
// Exercício 9 — Inversão de vetor (in-place)
// Crie uma função:
// void inverte(int *v, int tamanho);
// Inverta os elementos do vetor
// Não use vetor auxiliar
// Use dois ponteiros (início e fim)
// Exemplo: [1, 2, 3, 4] → [4, 3, 2, 1]

void inverte(int *v, int tamanho){
    int *inicio = v;
    int *final = v + (tamanho - 1);
    int temp;
    while ( inicio < final){
        temp = *inicio;
        *inicio = *final;
        *final = temp;
        inicio++;
        final--;
    }
}

int main(){
    int vetor[] = {1, 2, 3, 4};
    int tamanho = 4;
    inverte(vetor, 4);
    printf("Vetor invertida:");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;   

}