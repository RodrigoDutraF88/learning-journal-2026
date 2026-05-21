#include <stdio.h>




int main(){
    int *ptr;
    int var;
    var = 15;
    ptr = &var;
    printf("%d\n", &var);
    printf("%d\n", ptr);
    printf("%d\n", var);
    printf("%d\n", *ptr);//mesmo que imprimir conteudo de var
    printf("%d\n", &ptr);//endereço do proprio ponteiro
    *ptr = 8;
    printf("%d\n", var); //conteúdo de var foi atualizado atravez do ponteiro
}