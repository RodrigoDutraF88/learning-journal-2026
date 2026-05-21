#include <stdio.h>

int main (){

    struct Livros{
        char titulo[100];
        char autor[50];
        int ano_pubi;
        int num_pag;
    } livro;
    struct Livros Livro1 = {"Magico de Oz", "autor1", 2000, 500};
    printf("livro 1 = %s, %s, %d, %d\n", Livro1.titulo, Livro1.autor, Livro1.ano_pubi, Livro1.num_pag);

    return 0;
}
