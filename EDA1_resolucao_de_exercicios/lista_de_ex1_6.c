#include <stdio.h>
// Exercício 6 — Modificação por função
// Implemente uma função:
// void dobra(int *x);
// A função deve dobrar o valor de x
// Teste na main
// Verifique: o que acontece se passar sem ponteiro?

void dobrarNumero(int *x){
    *x = *x * 2;
}
int main(){
    int numero1 = 10;
    int *ptr1 = &numero1;
    dobrarNumero(ptr1);
    printf("Numero1: %d", *ptr1);
}