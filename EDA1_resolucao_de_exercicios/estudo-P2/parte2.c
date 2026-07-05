//Slides 12 ao 16

//SLIDE 12 Pilhas

//LIFO: last in, First out
//Ultimo elemento armazenado é o primeiro a ser removido
//Maioria dos compiladores em C usa pilha para passar argumantos para funções
//Inclusão é feita por meio de Empilhamento
//Exclusão por Desempilhamento
//Push e Pop

//Filas
//FIFO: First in, first Out,
//Primeiro elemento armazenado é o primeiro a ser removido
//Enfileiramento e Desenfileiramento
//Se pode implementar usando o vetor Circular

//Tem filas simplesmente encadeadas com e sem descritor
// E duplamente encadeadas com e sem descritor


// Slide 13 Buscas
//ALgoritmos e Complexidades

//Tipos de Busca
//Dados desordenados: busca sequencial
//Dados ordenados: busca binaria

//Busca linear: vetor ordenado ou desordenado
//Busca binaria: vetor ordenado


//Busca Sequencial: O(n)
//Busca Binária: O(log2n)

//SLIDE 14
//Arvores
//São adequadas para representa dados de maneira hierárquica
//Exemplos: Organogramas, Arvores de diretorios
//Raiz ou nó pai
//Filho, irmãos, Grau(quantidade de subarvores de um nó define seu grau)
//Folha: Nó com grau igual a 0
//Nível: Relativo ao posicionamento hierárquico de um nó dentro da árvore.
//Altura
//Floresta: conjunto de zero ou mais arvores disjuntas

// Nodo || Grau || Nivel 

//Arvores binárias: estruturas do tipo árvore onde o grau de cada nó é menor ou igual a dois
//árvore binária pode ser vazia , isto é, na7o possue nennhum nó
//Atente a arvores onde o vetor é da esquerda ou dirente, algumas podem parecer similares mas são diferentes devido a isso.
//Implementações: ALocação Estática e Dinâmica

//Alocação Dinâmica : Esquerda || Informação || Direita

//Código pronto de árvore binária:

#include <stdio.h>
#include <stdlib.h>

typedef struct TNoBin {
int valor;
struct TNoBin *esq;
struct TNoBin *dir;
} TNoBin;

TNoBin *criarNo(int valor) {
TNoBin *novo = (TNoBin *)malloc(sizeof(TNoBin));
    if (novo == NULL) {
    fprintf(stderr, "Erro: falha ao alocar memoria.\n");
    exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void destruirArvore(TNoBin *raiz) {
    if (raiz == NULL) {
    return;
    }
    destruirArvore(raiz->esq);
    destruirArvore(raiz->dir);
    free(raiz);
    }

int main(void) {
    TNoBin *raiz = criarNo(10);
    raiz->esq = criarNo(5);
    raiz->dir = criarNo(20);
    raiz->esq->esq = criarNo(3);
    raiz->esq->dir = criarNo(7);
printf("Estrutura da arvore:\n");
imprimirArvore(raiz, 0);
printf("\nPre-ordem: ");
imprimirPreOrdem(raiz);
printf("\n");
destruirArvore(raiz);
printf("\nArvore liberada da memoria.\n");
return 0;
}

//SLIDE 15
//Construção de árvores binárias

//SLIDE 16
//árvore Binária de Pesquisa
// Ultilizada para armazenar uma tabela de símbolos para fins de minimizar a comlexidade do algoritmo de pesquisa destes simbolos
//Deve obviamente existir uma relação de ordem entre eles , ex e1> e2

//Construção:
// A instalação de um símbolo s em uma ABP A
// segue o seguinte princípio:
// a. Se A for vazia, instalar s na raiz de A;
// b. Caso contrário:
// a. Se s for menor que raiz de A: Instalar s na subárvore da
// esquerda de A;
// b. Se s for maior que raiz de A: Instalar s na subárvore da
// direita de A;

//A operação de localização de um símbolo é semelhando à inserção

//A exclusão já é um pouco mais complicada, pode demandar a reestruturação da ABP
