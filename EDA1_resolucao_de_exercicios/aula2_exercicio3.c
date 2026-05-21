#include <stdio.h>


typedef struct Carro {
    char modelo[50];
    int ano_fabri;
    char color[30];
} Carro;

void ImprimirCarro(Carro C) {
    printf("Modelo: %s, Ano: %d, Cor: %s\n", C.modelo, C.ano_fabri, C.color);
}

int main() {
    Carro meuCarro = {"Fusca", 1985, "Azul"};
    ImprimirCarro(meuCarro);

    return 0;
}