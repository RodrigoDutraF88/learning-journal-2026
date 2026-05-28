#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* ============================================================
 * SECAO 1 - DEFINICAO DE TIPOS (STRUCTS)
 * ============================================================ */
 
/* Dados originais compartilhados pelas 3 listas de entrada */
typedef struct Cadastro {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
} TCadastro;
 
/* --- Lista Industria: simplesmente encadeada --- */
typedef struct NoI {
    TCadastro *Dados;
    struct NoI *Prox;
} TNoI;
 
/* --- Lista Comercio: duplamente encadeada (sem descritor) --- */
typedef struct NoC {
    TCadastro *Dados;
    struct NoC *Ant;
    struct NoC *Prox;
} TNoC;
 
/* --- Lista Servicos: duplamente encadeada COM descritor --- */
typedef struct NoS {
    TCadastro *Dados;
    struct NoS *Ant;
    struct NoS *Prox;
} TNoS;
 
typedef struct DescritorS {
    TNoS *Inicio;
    int   Tamanho;
    TNoS *Fim;
} TDescritorS;
 
/* --- Dados unificados (acrescenta campo Tipo) --- */
typedef struct CadastroUnificado {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo; /* 'I' = Industria | 'C' = Comercio | 'S' = Servico */
} TCadastroUnificado;
 
/* --- Lista Unificada: duplamente encadeada COM descritor --- */
typedef struct NoU {
    TCadastroUnificado *Dados;
    struct NoU *Ant;
    struct NoU *Prox;
} TNoU;
 
typedef struct DescritorU {
    TNoU *Inicio;
    int   Tamanho;
    TNoU *Fim;
} TDescritorU;
 
 
/* ============================================================
 * SECAO 2 - FUNCOES: LISTA INDUSTRIA (simplesmente encadeada)
 * ============================================================ */
 
/*
 * Insere um novo no no FINAL da lista Industria.
 * Aloca memoria para o no e para os dados.
 * Retorna o ponteiro atualizado para o inicio da lista.
 */
TNoI* inserirIndustria(TNoI *lista, TCadastro dados) {
    /* TODO: implementar
     * 1. Alocar TNoI com malloc
     * 2. Alocar TCadastro com malloc e copiar os dados
     * 3. Se lista == NULL, novo no eh o primeiro
     * 4. Senao, percorrer ate o fim e encadear
     * 5. Retornar o inicio da lista
     */
    return lista; /* placeholder */
}
 
/*
 * Imprime todos os nos da lista Industria do inicio ao fim.
 */
void imprimirIndustria(TNoI *lista) {
    /* TODO: implementar
     * Percorrer com ponteiro auxiliar enquanto != NULL
     * Imprimir CNPJ, RazaoSocial, Cidade, Fone de cada no
     */
    if (lista == NULL) {
        printf("Lista Industria vazia.\n");
        return;
    }
}
 
/*
 * Libera toda a memoria alocada pela lista Industria.
 * Retorna NULL para que o ponteiro original seja zerado.
 */
TNoI* liberarIndustria(TNoI *lista) {
    /* TODO: implementar
     * Percorrer a lista, para cada no:
     *   free(no->Dados)
     *   free(no)
     * Retornar NULL
     */
    return NULL;
}
 
/*
 * Le o arquivo Industria.txt e preenche a lista.
 * Formato esperado de cada linha: CNPJ;RazaoSocial;Cidade;Fone
 */
TNoI* carregarIndustria(TNoI *lista, const char *nomeArquivo) {
    /* TODO: implementar
     * 1. Abrir arquivo com fopen
     * 2. Ler linha por linha com fgets ou fscanf
     * 3. Para cada linha, parsear os campos (ex: sscanf com %[^;])
     * 4. Chamar inserirIndustria
     * 5. Fechar arquivo
     */
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro: arquivo '%s' nao encontrado.\n", nomeArquivo);
        return lista;
    }
    fclose(arq);
    return lista;
}
 
 
/* ============================================================
 * SECAO 3 - FUNCOES: LISTA COMERCIO (duplamente encadeada)
 * ============================================================ */
 
/*
 * Insere um novo no no FINAL da lista Comercio.
 * Retorna o ponteiro atualizado para o inicio.
 */
TNoC* inserirComercio(TNoC *lista, TCadastro dados) {
    /* TODO: implementar
     * Similar ao inserirIndustria, mas tambem ajustar ponteiro Ant
     */
    return lista;
}
 
/*
 * Imprime a lista Comercio do inicio ao fim.
 */
void imprimirComercio(TNoC *lista) {
    /* TODO: implementar */
    if (lista == NULL) {
        printf("Lista Comercio vazia.\n");
        return;
    }
}
 
/*
 * Imprime a lista Comercio do FIM ao inicio (invertida).
 * Dica: percorra ate o ultimo no, depois siga os ponteiros Ant.
 */
void imprimirComercioInvertida(TNoC *lista) {
    /* TODO: implementar
     * 1. Ir ate o ultimo no (Prox == NULL)
     * 2. Percorrer de volta usando Ant
     */
    if (lista == NULL) {
        printf("Lista Comercio vazia.\n");
        return;
    }
}
 
/*
 * Libera toda a memoria da lista Comercio.
 */
TNoC* liberarComercio(TNoC *lista) {
    /* TODO: implementar */
    return NULL;
}
 
/*
 * Le o arquivo Comercio.txt e preenche a lista.
 */
TNoC* carregarComercio(TNoC *lista, const char *nomeArquivo) {
    /* TODO: implementar - mesma logica do carregarIndustria */
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro: arquivo '%s' nao encontrado.\n", nomeArquivo);
        return lista;
    }
    fclose(arq);
    return lista;
}
 
 
/* ============================================================
 * SECAO 4 - FUNCOES: LISTA SERVICOS (dupla com descritor)
 * ============================================================ */
 
/*
 * Insere um novo no no FINAL da lista Servicos.
 * Atualiza o descritor (Inicio, Fim, Tamanho).
 */
void inserirServicos(TDescritorS *desc, TCadastro dados) {
    /* TODO: implementar
     * 1. Alocar TNoS e TCadastro
     * 2. Novo no: Prox = NULL, Ant = desc->Fim
     * 3. Se lista vazia: desc->Inicio = novo no
     * 4. Senao: desc->Fim->Prox = novo no
     * 5. desc->Fim = novo no
     * 6. desc->Tamanho++
     */
}
 
/*
 * Imprime a lista Servicos do inicio ao fim.
 */
void imprimirServicos(TDescritorS *desc) {
    /* TODO: implementar - usar desc->Inicio como ponto de partida */
    if (desc->Inicio == NULL) {
        printf("Lista Servicos vazia.\n");
        return;
    }
}
 
/*
 * Imprime a lista Servicos do FIM ao inicio (invertida).
 * Com descritor, voce ja tem acesso direto ao desc->Fim.
 */
void imprimirServicosInvertida(TDescritorS *desc) {
    /* TODO: implementar
     * Comecar em desc->Fim e seguir ponteiros Ant
     */
    if (desc->Fim == NULL) {
        printf("Lista Servicos vazia.\n");
        return;
    }
}
 
/*
 * Libera toda a memoria da lista Servicos e zera o descritor.
 */
void liberarServicos(TDescritorS *desc) {
    /* TODO: implementar
     * Percorrer a lista e dar free em cada no e seus dados
     * Zerar desc->Inicio, desc->Fim e desc->Tamanho
     */
}
 
/*
 * Le o arquivo Servico.txt e preenche a lista.
 */
void carregarServicos(TDescritorS *desc, const char *nomeArquivo) {
    /* TODO: implementar - mesma logica dos anteriores */
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro: arquivo '%s' nao encontrado.\n", nomeArquivo);
        return;
    }
    fclose(arq);
}
 
 
/* ============================================================
 * SECAO 5 - FUNCOES: LISTA UNIFICADA (dupla com descritor)
 * ============================================================ */
 
/*
 * Insere um novo no no FINAL da lista Unificada.
 * Recebe os dados ja preenchidos com o campo Tipo correto.
 */
void inserirUnificada(TDescritorU *desc, TCadastroU dados) {
    /* TODO: implementar - identico ao inserirServicos, mas com TNoU/TCadastroU */
}
 
/*
 * Imprime a lista Unificada do inicio ao fim.
 */
void imprimirUnificada(TDescritorU *desc) {
    /* TODO: implementar - exibir tambem o campo Tipo */
    if (desc->Inicio == NULL) {
        printf("Lista Unificada vazia.\n");
        return;
    }
}
 
/*
 * Imprime a lista Unificada do FIM ao inicio.
 */
void imprimirUnificadaInvertida(TDescritorU *desc) {
    /* TODO: implementar */
    if (desc->Fim == NULL) {
        printf("Lista Unificada vazia.\n");
        return;
    }
}
 
/*
 * Libera toda a memoria da lista Unificada e zera o descritor.
 */
void liberarUnificada(TDescritorU *desc) {
    /* TODO: implementar */
}
 
/*
 * Gera a lista Unificada a partir das 3 listas de entrada.
 * Percorre cada lista e insere os nos na unificada com o Tipo correto.
 */
void gerarListaUnificada(TDescritorU *desc, TNoI *listI, TNoC *listC, TDescritorS *descS) {
    /* TODO: implementar
     *
     * INDUSTRIA: percorrer listI (usando Prox), para cada no:
     *   - copiar campos CNPJ, RazaoSocial, Cidade, Fone para TCadastroU
     *   - definir Tipo = 'I'
     *   - chamar inserirUnificada
     *
     * COMERCIO: percorrer listC (usando Prox), para cada no:
     *   - copiar campos, Tipo = 'C'
     *   - chamar inserirUnificada
     *
     * SERVICOS: percorrer descS->Inicio (usando Prox), para cada no:
     *   - copiar campos, Tipo = 'S'
     *   - chamar inserirUnificada
     */
}
 
/*
 * Apaga todas as listas (chama todas as funcoes de liberar).
 */
void apagarListas(TNoI **listI, TNoC **listC, TDescritorS *descS, TDescritorU *descU) {
    *listI = liberarIndustria(*listI);
    *listC = liberarComercio(*listC);
    liberarServicos(descS);
    liberarUnificada(descU);
    printf("Todas as listas foram apagadas.\n");
}
 
 
/* ============================================================
 * SECAO 6 - FUNCAO PRINCIPAL (menu)
 * ============================================================ */
 
int main() {
    /* Declaracao das listas */
    TNoI      *listaI = NULL;
    TNoC      *listaC = NULL;
    TDescritorS listaS = {NULL, 0, NULL};
    TDescritorU listaU = {NULL, 0, NULL};
 
    int opcao;
 
    do {
        printf("\n========================================\n");
        printf("  SECRETARIA DA FAZENDA - DF\n");
        printf("========================================\n");
        printf(" 1. Carregar Dados de Entrada\n");
        printf(" 2. Gerar Lista Unificada\n");
        printf(" 3. Relatorio: Industrias\n");
        printf(" 4. Relatorio: Comercio\n");
        printf(" 5. Relatorio: Comercio Invertida\n");
        printf(" 6. Relatorio: Servicos\n");
        printf(" 7. Relatorio: Servicos Invertida\n");
        printf(" 8. Relatorio: Lista Unificada\n");
        printf(" 9. Relatorio: Lista Unificada Invertida\n");
        printf("10. Apagar Listas\n");
        printf(" 0. Sair\n");
        printf("----------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
 
        switch (opcao) {
            case 1:
                printf("\n--- Carregando dados de entrada ---\n");
                listaI = carregarIndustria(listaI, "Industria.txt");
                listaC = carregarComercio(listaC, "Comercio.txt");
                carregarServicos(&listaS, "Servico.txt");
                printf("Dados carregados.\n");
                break;
 
            case 2:
                printf("\n--- Gerando Lista Unificada ---\n");
                gerarListaUnificada(&listaU, listaI, listaC, &listaS);
                printf("Lista Unificada gerada. Total: %d registros.\n", listaU.Tamanho);
                break;
 
            case 3:
                printf("\n--- Relatorio: Industrias ---\n");
                imprimirIndustria(listaI);
                break;
 
            case 4:
                printf("\n--- Relatorio: Comercio ---\n");
                imprimirComercio(listaC);
                break;
 
            case 5:
                printf("\n--- Relatorio: Comercio Invertida ---\n");
                imprimirComercioInvertida(listaC);
                break;
 
            case 6:
                printf("\n--- Relatorio: Servicos ---\n");
                imprimirServicos(&listaS);
                break;
 
            case 7:
                printf("\n--- Relatorio: Servicos Invertida ---\n");
                imprimirServicosInvertida(&listaS);
                break;
 
            case 8:
                printf("\n--- Relatorio: Lista Unificada ---\n");
                imprimirUnificada(&listaU);
                break;
 
            case 9:
                printf("\n--- Relatorio: Lista Unificada Invertida ---\n");
                imprimirUnificadaInvertida(&listaU);
                break;
 
            case 10:
                printf("\n--- Apagando Listas ---\n");
                apagarListas(&listaI, &listaC, &listaS, &listaU);
                break;
 
            case 0:
                printf("\nEncerrando programa...\n");
                /* Boa pratica: liberar tudo antes de sair */
                apagarListas(&listaI, &listaC, &listaS, &listaU);
                break;
 
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
 
    } while (opcao != 0);
 
    return 0;
}