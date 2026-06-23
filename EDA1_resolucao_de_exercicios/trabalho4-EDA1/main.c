/*
 * Tarefa 4 - Algoritmos de Busca
 * Disciplina: Estruturas de Dados I - UnB/FGA
 * Professor: MSc. Filipe Emidio Torres
 *
 * Arquivo de dados: Lista_Municipios_com_IBGE_Brasil_Versao_CSV.csv
 * Fonte: https://blog.mds.gov.br/redesuas/lista-de-municipios-brasileiros/
 *
 * Estrutura do CSV (separador ponto-e-virgula):
 *   IBGE ; Municipio ; UF ; Regiao ; Populacao ; Porte
 *
 * O arquivo esta ordenado pelo campo IBGE (inteiro), o que permite
 * aplicar busca binaria diretamente sobre o vetor de indices.
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
 * Indice: o que fica carregado em memoria o tempo todo.
 * Armazena apenas o codigo IBGE e o numero da linha no arquivo,
 * conforme especificado no enunciado (opcao 1).
 */
typedef struct {
    int ibge;   /* codigo do municipio (chave de busca) */
    int linha;  /* numero da linha no CSV (1 = cabecalho, 2 = primeiro municipio, ...) */
} Indice;

/*
 * Registro completo: usado somente ao exibir o resultado de uma consulta.
 * Os campos sao lidos sob demanda diretamente do arquivo.
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

int       carregarIndice(const char *nomeArq, Indice **vetor);
int       buscaSequencial(Indice *vetor, int n, int ibge);
int       buscaBinaria(Indice *vetor, int n, int ibge);
int       lerLinha(const char *nomeArq, int numLinha, Municipio *m);
void      exibirMunicipio(const Municipio *m);
void      consultarMunicipio(Indice *vetor, int n);
void      liberarMemoria(Indice **vetor);
double    medirTempo(clock_t inicio, clock_t fim);

/* ------------------------------------------------------------------ */
/* main                                                                 */
/* ------------------------------------------------------------------ */

int main(void) {
    Indice *vetor = NULL;   /* vetor de indices alocado dinamicamente */
    int     n     = 0;      /* quantidade de municipios carregados    */
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
                /* libera vetor anterior, se existir */
                if (vetor != NULL) {
                    liberarMemoria(&vetor);
                    n = 0;
                }
                n = carregarIndice(NOME_ARQUIVO, &vetor);
                if (n > 0)
                    printf("Dados carregados: %d municipios.\n", n);
                break;

            case 2:
                if (vetor == NULL || n == 0) {
                    printf("Carregue os dados primeiro (opcao 1).\n");
                } else {
                    consultarMunicipio(vetor, n);
                }
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
/* Le o arquivo CSV e preenche o vetor de Indice com (ibge, linha).    */
/* Retorna o numero de municipios carregados, ou -1 em erro.           */
/* ------------------------------------------------------------------ */

int carregarIndice(const char *nomeArq, Indice **vetor) {
    FILE *arq = fopen(nomeArq, "r");
    if (arq == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir '%s'.\n", nomeArq);
        return -1;
    }

    /* --- primeira passagem: contar linhas de dados (excluindo cabecalho) --- */
    char buf[512];
    int total = 0;

    /* descarta cabecalho */
    if (fgets(buf, sizeof(buf), arq) == NULL) {
        fclose(arq);
        return -1;
    }

    while (fgets(buf, sizeof(buf), arq) != NULL)
        total++;

    /* --- alocar vetor --- */
    *vetor = (Indice *) malloc(total * sizeof(Indice));
    if (*vetor == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memoria.\n");
        fclose(arq);
        return -1;
    }

    /* --- segunda passagem: preencher vetor --- */
    rewind(arq);
    fgets(buf, sizeof(buf), arq); /* pula cabecalho novamente */

    int i = 0;
    int numLinha = 2; /* linha 1 = cabecalho; dados comecam na linha 2 */

    while (fgets(buf, sizeof(buf), arq) != NULL && i < total) {
        /* o primeiro campo separado por ';' e o codigo IBGE */
        char *tok = strtok(buf, ";");
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
/*                                                                      */
/* Percorre o vetor do inicio ao fim procurando o codigo IBGE.         */
/* Retorna o indice no vetor, ou -1 se nao encontrado.                 */
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
/*                                                                      */
/* Busca pelo codigo IBGE num vetor ja ordenado por esse campo.        */
/* A cada iteracao descarta metade dos elementos restantes.            */
/* Retorna o indice no vetor, ou -1 se nao encontrado.                 */
/* ------------------------------------------------------------------ */

int buscaBinaria(Indice *vetor, int n, int ibge) {
    int esq = 0;
    int dir = n - 1;

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
/* Abre o arquivo, avanca ate a linha indicada e parseia os campos     */
/* para a struct Municipio. Retorna 0 em sucesso, -1 em erro.          */
/* ------------------------------------------------------------------ */

int lerLinha(const char *nomeArq, int numLinha, Municipio *m) {
    FILE *arq = fopen(nomeArq, "r");
    if (arq == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir '%s'.\n", nomeArq);
        return -1;
    }

    char buf[512];
    for (int i = 1; i < numLinha; i++) {
        if (fgets(buf, sizeof(buf), arq) == NULL) {
            fclose(arq);
            return -1;
        }
    }

    /* le a linha alvo */
    if (fgets(buf, sizeof(buf), arq) == NULL) {
        fclose(arq);
        return -1;
    }
    fclose(arq);

    /* remove '\n' e '\r' do final */
    buf[strcspn(buf, "\r\n")] = '\0';

    /* parseia os 6 campos separados por ';' */
    char *tok;

    tok = strtok(buf, ";");  if (tok) m->ibge = atoi(tok);
    tok = strtok(NULL, ";"); if (tok) strncpy(m->municipio, tok, TAM_CAMPO - 1);
    tok = strtok(NULL, ";"); if (tok) strncpy(m->uf,        tok, TAM_CAMPO - 1);
    tok = strtok(NULL, ";"); if (tok) strncpy(m->regiao,    tok, TAM_CAMPO - 1);
    tok = strtok(NULL, ";"); if (tok) m->populacao = atol(tok);
    tok = strtok(NULL, ";"); if (tok) strncpy(m->porte,     tok, TAM_CAMPO - 1);

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
/*                                                                      */
/* Converte dois instantes de clock_t para segundos.                   */
/* ------------------------------------------------------------------ */

double medirTempo(clock_t inicio, clock_t fim) {
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

/* ------------------------------------------------------------------ */
/* consultarMunicipio                                                    */
/*                                                                      */
/* Le um codigo IBGE do usuario, executa as duas buscas medindo tempo  */
/* e exibe o resultado.                                                 */
/* ------------------------------------------------------------------ */

void consultarMunicipio(Indice *vetor, int n) {
    int ibge;
    printf("Digite o codigo IBGE do municipio: ");
    scanf("%d", &ibge);

    Municipio m;
    int pos;
    clock_t t_inicio, t_fim;

    /* ---- Busca Sequencial ---- */
    t_inicio = clock();
    pos = buscaSequencial(vetor, n, ibge);
    t_fim = clock();
    double tempo_seq = medirTempo(t_inicio, t_fim);

    /* ---- Busca Binaria ---- */
    t_inicio = clock();
    int pos_bin = buscaBinaria(vetor, n, ibge);
    t_fim = clock();
    double tempo_bin = medirTempo(t_inicio, t_fim);

    if (pos == -1) {
        printf("Municipio com codigo IBGE %d nao encontrado.\n", ibge);
    } else {
        /* usa a posicao encontrada (qualquer uma serve; ambas devem coincidir) */
        if (lerLinha(NOME_ARQUIVO, vetor[pos].linha, &m) == 0) {
            printf("\n--- Dados do Municipio ---\n");
            exibirMunicipio(&m);
        }
    }

    /* exibe tempos independentemente de ter encontrado ou nao */
    printf("\n--- Tempo de execucao ---\n");
    printf("  Busca Sequencial : %.9f segundos\n", tempo_seq);
    printf("  Busca Binaria    : %.9f segundos\n", tempo_bin);

    /* aviso se os dois algoritmos divergirem (nao deveria ocorrer) */
    if (pos != pos_bin) {
        fprintf(stderr, "Atencao: resultados divergentes entre as buscas.\n");
    }
}

/* ------------------------------------------------------------------ */
/* liberarMemoria                                                        */
/*                                                                      */
/* Libera o vetor alocado e anula o ponteiro para evitar uso posterior. */
/* ------------------------------------------------------------------ */

void liberarMemoria(Indice **vetor) {
    if (*vetor != NULL) {
        free(*vetor);
        *vetor = NULL;
    }
}