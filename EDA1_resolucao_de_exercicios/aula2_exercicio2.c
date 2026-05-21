#include <stdio.h>

int main(){

    typedef struct Pessoa{
        char nome[50];
        int idade;
        float altura;

    }Pessoa;
    Pessoa Pessoa1 = {"Joao", 25, 1.80};

    Pessoa1.idade = 26;
    Pessoa1.altura = 1.81;

    printf("Pessoa de nome: %s, tem idade %d e altura %f", Pessoa1.nome, Pessoa1.idade, Pessoa1.altura);
    return 0;

}