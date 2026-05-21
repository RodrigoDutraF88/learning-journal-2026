#include <stdio.h>
// Exercício 4 — Swap manual (sem função)
// Declare duas variáveis inteiras
// Use ponteiros para trocar os valores dentro da main
// Não use variável auxiliar tradicional (use manipulação via ponteiros)
int main(){
    int numero1 = 10;
    int numero2 = 20;
    int *ptr1 = &numero1;
    int *ptr2 = &numero2;
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    printf("numero1: %d, numero2: %d",*ptr1, *ptr2);
}