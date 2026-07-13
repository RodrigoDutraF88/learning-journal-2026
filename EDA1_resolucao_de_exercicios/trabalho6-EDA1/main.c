#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//questao 3

typedef struct TNoBin {
    int chave;
    struct TNoBin *esquerda;
    struct TNoBin *direita;
} TNoBin;

TNoBin *criarNo(int chave) {
    TNoBin *novo = (TNoBin *) malloc(sizeof(TNoBin));
    novo->chave = chave;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

TNoBin *inserir(TNoBin *raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }
    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }
    return raiz;
}

TNoBin *buscar(TNoBin *raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }
    if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    }
    return buscar(raiz->direita, chave);
}

void preOrdem(TNoBin *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->chave);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void emOrdem(TNoBin *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->chave);
    emOrdem(raiz->direita);
}

void posOrdem(TNoBin *raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->chave);
}

int altura(TNoBin *raiz) {
    if (raiz == NULL) return -1;
    int he = altura(raiz->esquerda);
    int hd = altura(raiz->direita);
    return 1 + (he > hd ? he : hd);
}

void liberarArvore(TNoBin *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

// Questao 4 

typedef struct TNoInventario {
    int codigoPatrimonio;
    char nome[50];
    struct TNoInventario *esquerda;
    struct TNoInventario *direita;
} TNoInventario;

TNoInventario *criarNoInventario(int codigo, const char *nome) {
    TNoInventario *novo = (TNoInventario *) malloc(sizeof(TNoInventario));
    novo->codigoPatrimonio = codigo;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

TNoInventario *inserirInventario(TNoInventario *raiz, int codigo, const char *nome) {
    if (raiz == NULL) {
        return criarNoInventario(codigo, nome);
    }
    if (codigo < raiz->codigoPatrimonio) {
        raiz->esquerda = inserirInventario(raiz->esquerda, codigo, nome);
    } else if (codigo > raiz->codigoPatrimonio) {
        raiz->direita = inserirInventario(raiz->direita, codigo, nome);
    }
    return raiz;
}

/* Recebe a raiz e um codigo de patrimonio, retorna o nome do equipamento
   ou "Nao encontrado" caso o codigo nao exista na arvore. */
const char *buscarEquipamento(TNoInventario *raiz, int codigo) {
    if (raiz == NULL) {
        return "Nao encontrado";
    }
    if (codigo == raiz->codigoPatrimonio) {
        return raiz->nome;
    }
    if (codigo < raiz->codigoPatrimonio) {
        return buscarEquipamento(raiz->esquerda, codigo);
    }
    return buscarEquipamento(raiz->direita, codigo);
}

void liberarInventario(TNoInventario *raiz) {
    if (raiz == NULL) return;
    liberarInventario(raiz->esquerda);
    liberarInventario(raiz->direita);
    free(raiz);
}

//Testes 

int main(void) {
    /* Testes da Questao 3, usando a sequencia da Questao 1 */
    TNoBin *raiz = NULL;
    int chaves[] = {45, 23, 67, 12, 34, 56, 89, 30, 40};
    int n = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, chaves[i]);
    }

    printf("Pre-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em-ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pos-ordem: ");
    posOrdem(raiz);
    printf("\n");

    printf("Altura da arvore: %d\n", altura(raiz));

    TNoBin *resultado = buscar(raiz, 34);
    if (resultado != NULL) {
        printf("Busca por 34: encontrado (chave %d)\n", resultado->chave);
    } else {
        printf("Busca por 34: nao encontrado\n");
    }

    resultado = buscar(raiz, 100);
    if (resultado != NULL) {
        printf("Busca por 100: encontrado (chave %d)\n", resultado->chave);
    } else {
        printf("Busca por 100: nao encontrado\n");
    }

    liberarArvore(raiz);
    raiz = NULL;

    printf("\n");

    /* Testes da Questao 4 */
    TNoInventario *inventario = NULL;
    inventario = inserirInventario(inventario, 1050, "Monitor Dell 24pol");
    inventario = inserirInventario(inventario, 1020, "Teclado Logitech");
    inventario = inserirInventario(inventario, 1080, "Notebook Lenovo");
    inventario = inserirInventario(inventario, 1010, "Mouse sem fio");
    inventario = inserirInventario(inventario, 1035, "Estabilizador");

    printf("Busca codigo 1035: %s\n", buscarEquipamento(inventario, 1035));
    printf("Busca codigo 1080: %s\n", buscarEquipamento(inventario, 1080));
    printf("Busca codigo 9999: %s\n", buscarEquipamento(inventario, 9999));

    liberarInventario(inventario);
    inventario = NULL;

    return 0;
}