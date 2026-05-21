#include <stdio.h>

void AlteraArray( int arr[], int *p){
    for ( int i = 0 ; i < 4 ; i++){
        *(p + i) = *(p + i) * 10;
    }
}
int main(){
    int arr[]= {1, 3, 5, 7};
    int *p = arr;
    AlteraArray(arr, p);

    // Imprimir para verificar se mudou
    for(int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    return 0;

}