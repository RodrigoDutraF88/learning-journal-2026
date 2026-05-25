#include <stdio.h>
#include <stdlib.h>

#include <string.h>

/*
STRUCT DO PRODUTO

*/
typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

/*
QUESTÃO 5 FUNÇÕES RECURSIVAS

*/

// a) Fatorial recursivo
int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * fatorial(n - 1);
}

// b) Soma recursiva do vetor
int soma_vetor(int v[], int tam) {
    if (tam == 0) {
        return 0;
    }

    return v[tam - 1] + soma_vetor(v, tam - 1);
}

/*

FUNÇÃO PRINCIPAL

*/

int main() {

    /*
    QUESTÃO 1 Vetores, Matrizes e Ponteiros
    */



    // a) Vetor de tamanho 10 inicializado com 0
    int vetor[10] = {0};

    printf("Elementos do vetor:\n");

    for (int i = 0; i < 10; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    // b) Matriz 3x3 com diagonal principal = 1
    int matriz[3][3] = {0};

    for (int i = 0; i < 3; i++) {
        matriz[i][i] = 1;
    }

    printf("\nMatriz identidade 3x3:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    /*
    QUESTÃO 2 Structs

    */


    // a) Criando variável p1
    Produto p1;

    strcpy(p1.nome, "Arroz");
    p1.preco = 25.90;
    p1.quantidade = 10;

    // b) Imprimindo todos os campos
    printf("Nome: %s\n", p1.nome);
    printf("Preco: %.2f\n", p1.preco);
    printf("Quantidade: %d\n", p1.quantidade);

    /*
    QUESTÃO 3 Ponteiros e Structs

    */



    // a) Ponteiro para Produto
    Produto *ptr = &p1;

    // b) Usando ->
    printf("Nome do produto: %s\n", ptr->nome);
    printf("Preco do produto: %.2f\n", ptr->preco);

    // c) Explicação
    printf("\nDiferenca entre ptr->preco e (*ptr).preco:\n");
    printf("As duas formas acessam o campo preco da struct.\n");

    printf("ptr->preco eh apenas uma forma simplificada de escrever (*ptr).preco.\n");

    /*
    QUESTÃO 4 Alocação Dinâmica

    */


    int n;

    printf("Digite a quantidade de produtos: ");
    scanf("%d", &n);

    // Alocando dinamicamente
    Produto *produtos = (Produto *) malloc(n * sizeof(Produto));

    if (produtos == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    // Preenchendo produtos
    for (int i = 0; i < n; i++) {

        printf("\nProduto %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", produtos[i].nome);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
    }

    // Mostrando produtos
    printf("\nProdutos cadastrados:\n");

    for (int i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
    }

    // Liberando memória
    free(produtos);

    printf("\nMemoria liberada com sucesso.\n");
    printf("Isso eh importante para evitar vazamento de memoria.\n");

    /*
    QUESTÃO 5 Recursão
    */

    // a) Teste do fatorial
    int numero = 5;

    printf("Fatorial de %d = %d\n", numero, fatorial(numero));

    // b) Teste soma vetor
    int v[] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    printf("Soma do vetor = %d\n", soma_vetor(v, tamanho));

    // c) Complexidade
    printf("\nComplexidade da funcao soma_vetor:\n");
    printf("A complexidade eh O(n), pois a funcao percorre todos os elementos do vetor uma vez.\n");

    /*
    QUESTÃO 6 Arquivos
    */



    FILE *arquivo;

    // Criando arquivo em modo escrita
    arquivo = fopen("produtos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo!\n");
        return 1;
    }

    // Escrevendo produtos
    fprintf(arquivo, "Feijao 12.50 20\n");
    fprintf(arquivo, "Macarrao 8.90 15\n");

    fclose(arquivo);

    printf("Arquivo criado e dados escritos.\n");

    // Reabrindo em modo leitura
    arquivo = fopen("produtos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    char nome[50];
    float preco;
    int quantidade;

    printf("\nDados lidos do arquivo:\n");

    while (fscanf(arquivo, "%s %f %d", nome, &preco, &quantidade) != EOF) {
        printf("Nome: %s\n", nome);
        printf("Preco: %.2f\n", preco);
        printf("Quantidade: %d\n\n", quantidade);
    }

    fclose(arquivo);

    /*
    QUESTÃO 7 Notação Assintótica
  
    */


    // a) Ordem crescente
    printf("Ordem crescente de crescimento:\n");
    printf("O(1) < O(log n) < O(n) < O(n log n) < O(n^2)\n");

    // b) Busca linear
    printf("\nBusca Linear:\n");
    printf("Melhor caso: O(1), quando o elemento esta na primeira posicao.\n");
    printf("Pior caso: O(n), quando o elemento esta na ultima posicao ou nao existe.\n");

    return 0;
}