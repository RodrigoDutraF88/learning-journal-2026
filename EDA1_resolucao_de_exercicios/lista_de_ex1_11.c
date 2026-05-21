#include <stdio.h>
// Exercício 11 — Comparação de strings
// Implemente sua própria versão de:
// int compara(char *s1, char *s2);
// Retorne:
// 0 se iguais
// <0 se s1 < s2
// 0 se s1 > s2
// Sem usar strcmp
int compara(char *s1, char *s2) {
    while (*s1 == *s2 && *s1 != '\0') {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int main() {
    char string1[] = "arvore";
    char string2[] = "galho";
    
    int resultado = compara(string1, string2);

    if (resultado == 0) {
        printf("As strings sao iguais.\n");
    } else if (resultado < 0) {
        printf("A string1 vem antes da string2 (s1 < s2).\n");
    } else {
        printf("A string1 vem depois da string2 (s1 > s2).\n");
    }

    printf("Valor do retorno: %d\n", resultado);

    return 0;
}
