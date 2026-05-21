#include <stdio.h>


int main(){
    int vetor1[3] = {1, 2, 3}; // posição 0,1,2
    int i;
    printf("%d\n",vetor1[0]);
    for ( i = 0; i<3; i++){
        printf("valor[%d]: %d\n", i, vetor1[i]);
    };


}