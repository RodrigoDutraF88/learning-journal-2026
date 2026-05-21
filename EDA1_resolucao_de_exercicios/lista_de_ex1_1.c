#include <stdio.h>
//Exercício 1 — Inspeção de memória
//Declare: 
// uma variável inteira
// uma variável float
// um ponteiro para cada tipo
// Atribua corretamente os endereços
// Imprima:
// valor da variável

int main(){
    int numero = 100;
    float numero2= 200;
    int *ptr1 = &numero;
    float *ptr2 = &numero2;
    printf(" Numero1 = %d, Numero2 = %.2f", *ptr1, *ptr2);

}