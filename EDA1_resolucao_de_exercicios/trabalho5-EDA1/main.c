#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void preOrdem(No *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
}

void posOrdem(No *raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->valor);
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

/* Insercao usada apenas para montar a arvore do exercicio 6,
   seguindo a regra de ABP a partir da sequencia de pre-ordem. */
No* inserirBST(No *raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserirBST(raiz->esquerda, valor);
    else
        raiz->direita = inserirBST(raiz->direita, valor);
    return raiz;
}

/*  Parte 1: arvore com raiz 15 */
No* montarArvoreParte1(void) {
    No *n15 = criarNo(15);
    No *n8  = criarNo(8);
    No *n22 = criarNo(22);
    No *n4  = criarNo(4);
    No *n11 = criarNo(11);
    No *n18 = criarNo(18);
    No *n27 = criarNo(27);
    No *n2  = criarNo(2);
    No *n6  = criarNo(6);
    No *n10 = criarNo(10);
    No *n13 = criarNo(13);

    n15->esquerda = n8;  n15->direita = n22;
    n8->esquerda  = n4;  n8->direita  = n11;
    n22->esquerda = n18; n22->direita = n27;
    n4->esquerda  = n2;  n4->direita  = n6;
    n18->esquerda = n10; n18->direita = n13;

    return n15;
}

/* Parte 2, exercicios 1-3: arvore com raiz 40 */
No* montarArvoreParte2(void) {
    No *n40 = criarNo(40);
    No *n20 = criarNo(20);
    No *n60 = criarNo(60);
    No *n10 = criarNo(10);
    No *n30 = criarNo(30);
    No *n50 = criarNo(50);
    No *n70 = criarNo(70);
    No *n5  = criarNo(5);
    No *n15 = criarNo(15);
    No *n55 = criarNo(55);

    n40->esquerda = n20; n40->direita = n60;
    n20->esquerda = n10; n20->direita = n30;
    n60->esquerda = n50; n60->direita = n70;
    n10->esquerda = n5;  n10->direita = n15;
    n70->direita  = n55;

    return n40;
}

/* Parte 2, exercicio 4: arvore com raiz 25 */
No* montarArvoreExercicio4(void) {
    No *n25 = criarNo(25);
    No *n12 = criarNo(12);
    No *n37 = criarNo(37);
    No *n8  = criarNo(8);
    No *n15 = criarNo(15);
    No *n30 = criarNo(30);
    No *n40 = criarNo(40);
    No *n10 = criarNo(10);

    n25->esquerda = n12; n25->direita = n37;
    n12->esquerda = n8;  n12->direita = n15;
    n37->esquerda = n30; n37->direita = n40;
    n8->direita   = n10;

    return n25;
}

/*Parte 2, exercicio 6: arvore reconstruida a partir do
   percurso em pre-ordem 50 25 10 30 75 60 90  */
No* montarArvoreExercicio6(void) {
    int preOrdemValores[] = {50, 25, 10, 30, 75, 60, 90};
    int n = sizeof(preOrdemValores) / sizeof(int);
    No *raiz = NULL;
    for (int i = 0; i < n; i++)
        raiz = inserirBST(raiz, preOrdemValores[i]);
    return raiz;
}

void mostrarPercursos(No *raiz, const char *nomeArvore) {
    printf("Arvore: %s\n", nomeArvore);
    printf("Pre-ordem: ");  preOrdem(raiz); printf("\n");
    printf("Em-ordem:  ");  emOrdem(raiz);  printf("\n");
    printf("Pos-ordem: ");  posOrdem(raiz); printf("\n\n");
}

int main(void) {
    No *arvoreParte1 = montarArvoreParte1();
    No *arvoreParte2 = montarArvoreParte2();
    No *arvoreExercicio4 = montarArvoreExercicio4();
    No *arvoreExercicio6 = montarArvoreExercicio6();

    mostrarPercursos(arvoreParte1, "Parte 1 (raiz 15)");
    mostrarPercursos(arvoreParte2, "Parte 2, exercicios 1-3 (raiz 40)");
    mostrarPercursos(arvoreExercicio4, "Parte 2, exercicio 4 (raiz 25)");
    mostrarPercursos(arvoreExercicio6, "Parte 2, exercicio 6 (raiz 50)");

    liberarArvore(arvoreParte1);
    liberarArvore(arvoreParte2);
    liberarArvore(arvoreExercicio4);
    liberarArvore(arvoreExercicio6);

    return 0;
}