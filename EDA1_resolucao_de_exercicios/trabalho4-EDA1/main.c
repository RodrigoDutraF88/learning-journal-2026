/*
 * Tarefa 4 - Algoritmos de Busca
 * Disciplina: Estruturas de Dados I - UnB/FGA
 * Professor: MSc. Filipe Emidio Torres
 *
 * Estrutura real do CSV (separador ';'):
 *   Col 0: ConcatUF+Mun
 *   Col 1: IBGE  (6 digitos)
 *   Col 2: IBGE7 (7 digitos) <-- chave usada pelo enunciado
 *   Col 3: UF
 *   Col 4: Municipio
 *   Col 5: Regiao
 *   Col 6: Populacao 2010
 *   Col 7: Porte
 *   Col 8: Capital
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ------------------------------------------------------------------ */
/* Constantes                                                           */
/* ------------------------------------------------------------------ */
#define NOME_ARQUIVO "Lista_Municipios_com_IBGE_Brasil_Versao_CSV.csv"
#define TAM_CAMPO    128

/* ------------------------------------------------------------------ */
/* Tipos                                                                */
/* ------------------------------------------------------------------ */

/*
 * Indice: unico vetor mantido em memoria.
 * ibge  -> codigo IBGE7 (7 digitos), chave de busca
 * linha -> numero da linha no arquivo (cabecalho = 1, primeiro dado = 2)
 */
typedef struct {
    int ibge;
    int linha;
} Indice;

/*
 * Municipio: preenchido sob demanda ao exibir resultado.
 */
typedef struct {
    int  ibge;
    char municipio[TAM_CAMPO];
    char uf[TAM_CAMPO];
    char regiao[TAM_CAMPO];
    long populacao;
    char porte[TAM_CAMPO];
} Municipio;

/* ------------------------------------------------------------------ */
/* Prototipos                                                           */
/* ------------------------------------------------------------------ */

int    carregarIndice(const char *nomeArq, Indice **vetor);
int    buscaSequencial(Indice *vetor, int n, int ibge);
int    buscaBinaria(Indice *vetor, int n, int ibge);
int    lerLinha(const char *nomeArq, int numLinha, Municipio *m);
void   exibirMunicipio(const Municipio *m);
void   consultarMunicipio(Indice *vetor, int n);
void   liberarMemoria(Indice **vetor);
double medirTempo(clock_t inicio, clock_t fim);

/* ------------------------------------------------------------------ */
/* main                                                                 */
/* ------------------------------------------------------------------ */

int main(void) {
    Indice *vetor = NULL;
    int     n     = 0;
    int     opcao;

    do {
        printf("\n===== Algoritmos de Busca - Censo IBGE 2010 =====\n");
        printf("1. Carregar dados\n");
        printf("2. Consultar municipio\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (vetor != NULL) {
                    liberarMemoria(&vetor);
                    n = 0;
                }
                n = carregarIndice(NOME_ARQUIVO, &vetor);
                if (n > 0)
                    printf("Dados carregados: %d municipios.\n", n);
                break;

            case 2:
                if (vetor == NULL || n == 0)
                    printf("Carregue os dados primeiro (opcao 1).\n");
                else
                    consultarMunicipio(vetor, n);
                break;

            case 3:
                liberarMemoria(&vetor);
                printf("Memoria liberada. Encerrando.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 3);

    return 0;
}

/* ------------------------------------------------------------------ */
/* carregarIndice                                                        */
/*                                                                      */
/* Le o arquivo CSV e preenche o vetor com (IBGE7, linha).             */
/* Coluna IBGE7 e a terceira (indice 2, base 0).                       */
/* ------------------------------------------------------------------ */

int carregarIndice(const char *nomeArq, Indice **vetor) {
    FILE *arq = fopen(nomeArq, "r");
    if (arq == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir '%s'.\n", nomeArq);
        return -1;
    }

    char buf[1024];

    /* --- contagem de linhas de dados --- */
    int total = 0;
    fgets(buf, sizeof(buf), arq); /* descarta cabecalho */
    while (fgets(buf, sizeof(buf), arq) != NULL) {
        /* ignora linhas vazias */
        if (buf[0] != '\n' && buf[0] != '\r' && buf[0] != '\0')
            total++;
    }

    *vetor = (Indice *) malloc(total * sizeof(Indice));
    if (*vetor == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria.\n");
        fclose(arq);
        return -1;
    }

    /* --- segunda passagem --- */
    rewind(arq);
    fgets(buf, sizeof(buf), arq); /* pula cabecalho */

    int i = 0;
    int numLinha = 2; /* linha 1 = cabecalho */

    while (fgets(buf, sizeof(buf), arq) != NULL && i < total) {
        if (buf[0] == '\n' || buf[0] == '\r') {
            numLinha++;
            continue;
        }

        /* avanca ate a coluna 2 (IBGE7): pula col 0 e col 1 */
        char *tok = strtok(buf, ";");  /* col 0: ConcatUF+Mun */
        tok = strtok(NULL, ";");       /* col 1: IBGE6         */
        tok = strtok(NULL, ";");       /* col 2: IBGE7         */

        if (tok != NULL) {
            (*vetor)[i].ibge  = atoi(tok);
            (*vetor)[i].linha = numLinha;
            i++;
        }
        numLinha++;
    }

    fclose(arq);
    printf("Arquivo lido com sucesso.\n");
    return i;
}

/* ------------------------------------------------------------------ */
/* buscaSequencial                                                       */
/* ------------------------------------------------------------------ */

int buscaSequencial(Indice *vetor, int n, int ibge) {
    for (int i = 0; i < n; i++) {
        if (vetor[i].ibge == ibge)
            return i;
    }
    return -1;
}

/* ------------------------------------------------------------------ */
/* buscaBinaria                                                          */
/* ------------------------------------------------------------------ */

int buscaBinaria(Indice *vetor, int n, int ibge) {
    int esq  = 0;
    int dir  = n - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2; /* evita overflow */

        if (vetor[meio].ibge == ibge)
            return meio;
        else if (vetor[meio].ibge < ibge)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return -1;
}

/* ------------------------------------------------------------------ */
/* lerLinha                                                              */
/*                                                                      */
/* Abre o arquivo, avanca ate numLinha e parseia os campos.            */
/* Colunas esperadas: 0=concat 1=ibge6 2=ibge7 3=uf 4=mun 5=reg       */
/*                    6=pop 7=porte 8=capital                           */
/* ------------------------------------------------------------------ */

int lerLinha(const char *nomeArq, int numLinha, Municipio *m) {
    FILE *arq = fopen(nomeArq, "r");
    if (arq == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir '%s'.\n", nomeArq);
        return -1;
    }

    char buf[1024];
    for (int i = 1; i < numLinha; i++) {
        if (fgets(buf, sizeof(buf), arq) == NULL) {
            fclose(arq);
            return -1;
        }
    }
    if (fgets(buf, sizeof(buf), arq) == NULL) {
        fclose(arq);
        return -1;
    }
    fclose(arq);

    buf[strcspn(buf, "\r\n")] = '\0';

    char *tok;
    tok = strtok(buf,  ";"); /* col 0: concat    -- ignora */
    tok = strtok(NULL, ";"); /* col 1: ibge6     -- ignora */
    tok = strtok(NULL, ";"); /* col 2: ibge7     */
    if (tok) m->ibge = atoi(tok);

    tok = strtok(NULL, ";"); /* col 3: UF        */
    if (tok) strncpy(m->uf, tok, TAM_CAMPO - 1);

    tok = strtok(NULL, ";"); /* col 4: Municipio */
    if (tok) strncpy(m->municipio, tok, TAM_CAMPO - 1);

    tok = strtok(NULL, ";"); /* col 5: Regiao    */
    if (tok) strncpy(m->regiao, tok, TAM_CAMPO - 1);

    tok = strtok(NULL, ";"); /* col 6: Populacao */
    if (tok) m->populacao = atol(tok);

    tok = strtok(NULL, ";"); /* col 7: Porte     */
    if (tok) strncpy(m->porte, tok, TAM_CAMPO - 1);

    return 0;
}

/* ------------------------------------------------------------------ */
/* exibirMunicipio                                                       */
/* ------------------------------------------------------------------ */

void exibirMunicipio(const Municipio *m) {
    printf("  Municipio  : %s\n", m->municipio);
    printf("  UF         : %s\n", m->uf);
    printf("  Regiao     : %s\n", m->regiao);
    printf("  Populacao  : %ld habitantes (Censo 2010)\n", m->populacao);
    printf("  Porte      : %s\n", m->porte);
}

/* ------------------------------------------------------------------ */
/* medirTempo                                                            */
/* ------------------------------------------------------------------ */

double medirTempo(clock_t inicio, clock_t fim) {
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* ------------------------------------------------------------------ */
/* consultarMunicipio                                                    */
/* ------------------------------------------------------------------ */

void consultarMunicipio(Indice *vetor, int n) {
    int ibge;
    printf("Digite o codigo IBGE do municipio (7 digitos): ");
    scanf("%d", &ibge);

    Municipio m;
    clock_t t_inicio, t_fim;

    /* ---- Busca Sequencial ---- */
    t_inicio = clock();
    int pos_seq = buscaSequencial(vetor, n, ibge);
    t_fim = clock();
    double tempo_seq = medirTempo(t_inicio, t_fim);

    /* ---- Busca Binaria ---- */
    t_inicio = clock();
    int pos_bin = buscaBinaria(vetor, n, ibge);
    t_fim = clock();
    double tempo_bin = medirTempo(t_inicio, t_fim);

    if (pos_seq == -1) {
        printf("Municipio com codigo IBGE %d nao encontrado.\n", ibge);
    } else {
        if (lerLinha(NOME_ARQUIVO, vetor[pos_seq].linha, &m) == 0) {
            printf("\n--- Dados do Municipio ---\n");
            exibirMunicipio(&m);
        }
    }

    printf("\n--- Tempo de execucao ---\n");
    printf("  Busca Sequencial : %.9f segundos\n", tempo_seq);
    printf("  Busca Binaria    : %.9f segundos\n", tempo_bin);

    if (pos_seq != pos_bin)
        fprintf(stderr, "Atencao: resultados divergentes entre as buscas.\n");
}

/* ------------------------------------------------------------------ */
/* liberarMemoria                                                        */
/* ------------------------------------------------------------------ */

void liberarMemoria(Indice **vetor) {
    if (*vetor != NULL) {
        free(*vetor);
        *vetor = NULL;
    }
}