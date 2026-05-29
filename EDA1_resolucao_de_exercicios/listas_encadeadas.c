//listas encadeadas
//estrutura de dados de tamanho variavel
//ultilizando malloc, cada elemneto novo é alocado dinamicamente
//malloc() fornece ponteiro para area de memoria reservada para novo elemento
// sempre vai ter um ponteiro para prox elemento, tamanho livre, limite é memoria ra

//listas encadeadas , sequencia de objetos do mesmo tipo
//uso sctruct para definir um novo tipo de dados
//contem variaveis de interesse e um ponteiro para a posicao na memoria do proximo

struct ElementoLista {
    int conteudo;
    struct ElementoLista *prox;
};

// lista com cabeca e sem cabeca
//no ultimo elemento tem NULL
// sempre que criar novo ele deve atribuir null ao ponteiro 
//e atualizar o ponteiro do ele anterior com valor 
// da posicao de memoria do novo elemento 

//Com cabeca : conteudo do primeiro ele não é relevante

//Operações basicas: adicionar elementos: malloc() retorna um ponteiro para um novo elemento
//remover elemento free() libera a memoria de um elemneto 
 //Buscar elemntos por indice ou conteudo, contar o numero de elementos
 //imprimir o conteudo da lista
 //salvar em arquivo
 //ler de arquivo

 //As operações dependem da varredura da lista com laços ou recursividade
#include <stdio.h>
#include <stdlib.h>

struct ElementoLista{
    int valor;
    struct ElementoLista *prox; // elemento que vai apontar para prox elemento da lista

};

typedef struct ElementoLista Item; 

//prototipos das funcoes
void imprime(Item *cabeca){// passa o ponteiro para a cabeca da lista 


    Item *atual =cabeca->prox;

    int i = 0;
    while(atual != NULL){
        printf("Valor do item : %3d\n", atual->valor);
        i++;
        atual = atual->prox;

    }

    printf("Total de itens na lista: %d\n",i);


} 

void libera(Item* cabeca){// passo a cabeca e a partir dela usando free é liberada

    Item *atual = cabeca->prox; //ponteiro para o inicio da lista

    Item *liberado; // ponteiro para item a ser liberado

    while(atual !=NULL){

        liberado = atual; //liberado recebe o endereco do atual a ser liberado

        atual = atual->prox; // recebe o endereco do proximo a ser liberado

        printf("Liberando o item de valor %3d na posicao %p\n",liberado->valor, (void*)liberado);

        free(liberado);
    }

}

//funcao para insercao de item
void InsereFim(Item* cabeca, int valor){ // passa o ponteiro para a cabeca da lista  e o valor a ser adicionado no ultimo ele
//cria um ponteiro para novo item e aloca dinamicamente
    Item *novo = (Item*)malloc(sizeof(Item));

    //inicializa o novo item
    novo->prox = NULL; // se torna o ultimo da lista
    novo->valor = valor; // atualiza o valor como o valor que foi passado como paramentro da funcao

    printf("Item de valor %3d alocado no endereco : %p\n", novo->valor,(void*)novo);


    Item *atual = cabeca; 
    while(atual->prox!=NULL){ // varre a lista para chegar na ultima repeticao
        atual = atual->prox;
    }

    atual->prox = novo;

}
int main(int argc, char *argv[]){

    Item cabeca; //cria a cabeca da lista
    cabeca.prox = NULL;

    // imprime o tamanho em bytes de um item da lista
    printf("Tamanho do imtem: %zu bytes\n", sizeof(Item));

    //insere ao final da lista um item alocado dinamicamente
    printf("\n Inserindo itens novos na lista...\n");
    InsereFim(&cabeca, 15);
    InsereFim(&cabeca, 125);
    InsereFim(&cabeca, 155);

    printf("\n Imprimindo itens da lista...\n");
    imprime(&cabeca);

    printf("\nLiberando os memoria dos itens da lista...\n");
    libera(&cabeca);

    return 0;

}