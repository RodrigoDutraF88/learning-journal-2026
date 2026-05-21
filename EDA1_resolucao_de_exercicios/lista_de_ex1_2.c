#include <stdio.h>
//Exercício 2 — Ponteiros cruzados
// p1 aponta para A, p2 aponta para B
// Imprima os valores apontados
// Troque os ponteiros (sem trocar os valores das variáveis)
// Imprima novamente
void TrocarNumeros( float *p1, float *p2){
    float temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main(){
    float a = 10;
    float b= 20;
    printf("Numero a= %.2f , e b= %.2f \n", a, b);

    TrocarNumeros(&a, &b);

    printf("Numeros trocados a= %.2f , e b= %.2f \n", a, b);

}