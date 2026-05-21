#include <stdio.h>



int main(){

typedef struct Produto {
    char nome[20];
    float preco;
} Produto;
float *p;
Produto primeiro = {"cadeira", 200};
Produto *ptr = &primeiro;
printf("%s - %.2f", ptr->nome, ptr->preco);

}