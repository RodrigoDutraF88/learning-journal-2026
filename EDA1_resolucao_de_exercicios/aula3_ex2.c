#include <stdio.h>

void TrocarNumeros( float *ptr1, float *ptr2){
    float temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main(){
    float a = 20;
    float b= 40;
    printf("Numero a= %.2f , e b= %.2f \n", a, b);

    TrocarNumeros(&a, &b);

    printf("Numeros trocados a= %.2f , e b= %.2f \n", a, b);

}