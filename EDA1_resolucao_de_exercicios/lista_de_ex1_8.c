#include <stdio.h>
#include <string.h>

// Dada uma string:
// char nome[] = "programacao";
// Crie uma função:
// int conta(char *str, char c);
// Retorne quantas vezes c aparece
// Use apenas ponteiros

int conta( char *str, char c){
    int contagem = 0;
    while (*str != '\0'){ 
        if (*str == c){
            contagem++;
        }
        str++; //avança ponteiro
    }
    return contagem;
}

int main(){
    char nome[] = "programacao";
    char c = 'a';
    int resultado = conta(nome, c);
    printf("o char '%c' aparece %d vezes", c, resultado);
}