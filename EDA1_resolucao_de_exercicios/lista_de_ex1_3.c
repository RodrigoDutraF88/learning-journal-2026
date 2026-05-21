#include <stdio.h>
// Exercício 3 — Incremento indireto
// Declare uma variável inteira
// Use um ponteiro para:
// somar 5
// multiplicar por 2
// Imprima o resultado final
// Atenção: Não acessar diretamente a variável (somente via ponteiro).


int main(){
    int variavel = 100;
    int *p1 = &variavel;
    *p1 = *p1 + 5;
    *p1 = *p1 * 2;
    printf("Incremento direto: variavel = %d", *p1);
}