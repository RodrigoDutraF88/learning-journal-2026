/*
 * ============================================================
 * EDA - TRABALHO 2: Alocacao Dinamica de Memoria
 * Disciplina: FGA0147 - Estruturas de Dados I
 * Prof. MSc. Filipe Emidio Torres - UnB / FCTE
 *
 * Contexto: sistema para analise de temperaturas diarias
 * de cidades. O numero de dias nao e conhecido antecipadamente,
 * logo o vetor de medicoes e alocado dinamicamente em tempo
 * de execucao (opcao Reset).
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

/* ============================================================
 * SECAO 1 - ENTENDENDO A ALOCACAO DINAMICA NESTE TRABALHO
 * ============================================================
 *
 * Existem DOIS niveis de alocacao dinamica aqui:
 *
 * NIVEL 1 — o vetor de medidas em si (opcao Reset):
 *   dados.medidas = malloc(qtde_dias * sizeof(TMedidas))
 *   Aloca um bloco contendo 'qtde_dias' celulas de TMedidas.
 *   Cada celula tem: char cidade[20] e float *temperatura.
 *   O ponteiro *temperatura ainda nao aponta para nada util.
 *
 * NIVEL 2 — a temperatura de cada medicao (opcao Inserir):
 *   dados.medidas[i].temperatura = malloc(sizeof(float))
 *   Aloca um unico float para cada medicao inserida.
 *   Isso demonstra alocacao dinamica dentro de uma struct.
 *
 * Por que dois niveis?
 *   O enunciado define float *temperatura (ponteiro),
 *   nao float temperatura (valor direto). Isso obriga a
 *   alocar cada temperatura separadamente — esse e exatamente
 *   o ponto pedagogico do exercicio.
 *
 * LIBERACAO (opcao Sair e Reset):
 *   Para cada medida inserida: free(medidas[i].temperatura)
 *   Depois: free(dados.medidas)
 *   Ordem importa: libere sempre do mais interno para o externo.
 * ============================================================ */


/* ============================================================
 * SECAO 2 - FUNCOES
 * ============================================================ */

/*
 * resetar: implementa a opcao (a) do menu.
 *
 * O QUE FAZ:
 *   1. Se ja existir um vetor alocado anteriormente, libera
 *      toda a memoria antes de realocar (evita vazamento).
 *   2. Le do usuario a quantidade de dias (capacidade maxima).
 *   3. Aloca o vetor de TMedidas com essa capacidade.
 *   4. Zera o contador qtde_medidas.
 *
 * POR QUE recebe TTemperaturas* (ponteiro para a struct)?
 *   Para modificar os campos da struct original em main().
 *   Se recebesse por valor (TTemperaturas dados), as alteracoes
 *   seriam perdidas ao retornar da funcao.
 *
 * CUIDADO com o Reset duplo:
 *   Se o usuario chamar Reset duas vezes sem Sair, o vetor
 *   anterior deve ser liberado antes de alocar um novo.
 *   A verificacao (dados->medidas != NULL) garante isso.
 */
void resetar(TTemperaturas *dados) {
    /* --- Passo 1: liberar memoria anterior se existir --- */
    if (dados->medidas != NULL) {
        /*
         * Percorre as medidas JA INSERIDAS e libera
         * cada ponteiro de temperatura individualmente.
         * So libera ate qtde_medidas (as celulas alem disso
         * nunca foram alocadas no nivel 2).
         */
        for (int i = 0; i < dados->qtde_medidas; i++) {
            free(dados->medidas[i].temperatura);
            /*
             * Boa pratica: zerar o ponteiro apos liberar.
             * Evita "dangling pointer" (ponteiro solto).
             */
            dados->medidas[i].temperatura = NULL;
        }
        /* Libera o vetor de medidas em si (nivel 1) */
        free(dados->medidas);
        dados->medidas = NULL;
    }

    /* --- Passo 2: ler a nova capacidade --- */
    printf("  Informe a quantidade de dias (capacidade maxima): ");
    scanf("%d", &dados->qtde_dias);

    /* Validacao basica */
    if (dados->qtde_dias <= 0) {
        printf("  Valor invalido. Nenhuma alocacao realizada.\n");
        dados->medidas = NULL;
        dados->qtde_medidas = 0;
        return;
    }

    /* --- Passo 3: alocar o vetor de TMedidas (nivel 1) --- */
    /*
     * malloc retorna um void* que deve ser convertido para
     * o tipo correto. Aqui alocamos espaco para qtde_dias
     * celulas de TMedidas lado a lado na memoria.
     *
     * Neste momento, os campos *temperatura de cada celula
     * ainda sao lixo de memoria — serao alocados em Inserir.
     */
    dados->medidas = (TMedidas*) malloc(dados->qtde_dias * sizeof(TMedidas));

    if (dados->medidas == NULL) {
        printf("  Erro: falha ao alocar memoria.\n");
        dados->qtde_dias = 0;
        return;
    }

    /* --- Passo 4: zerar o contador de medidas inseridas --- */
    dados->qtde_medidas = 0;

    printf("  Reset concluido. Capacidade: %d dias.\n", dados->qtde_dias);
}

/*
 * inserirMedida: implementa a opcao (b) do menu.
 *
 * O QUE FAZ:
 *   1. Verifica se o vetor foi alocado (Reset foi chamado).
 *   2. Verifica se ainda ha espaco (qtde_medidas < qtde_dias).
 *   3. Le o nome da cidade e a temperatura do usuario.
 *   4. Copia o nome da cidade para a celula atual do vetor.
 *   5. Aloca um float para a temperatura (nivel 2) e armazena.
 *   6. Incrementa qtde_medidas.
 *
 * INDICE ATUAL: dados->medidas[dados->qtde_medidas]
 *   qtde_medidas e usado como indice da proxima posicao livre.
 *   Antes da 1a insercao: qtde_medidas = 0 -> usa [0]
 *   Antes da 2a insercao: qtde_medidas = 1 -> usa [1]
 *   E assim por diante.
 */
void inserirMedida(TTemperaturas *dados) {
    /* --- Verificacoes de seguranca --- */
    if (dados->medidas == NULL) {
        printf("  Erro: execute o Reset antes de inserir.\n");
        return;
    }

    if (dados->qtde_medidas >= dados->qtde_dias) {
        printf("  Erro: capacidade maxima atingida (%d dias).\n", dados->qtde_dias);
        return;
    }

    /* --- Indice da posicao livre atual --- */
    int idx = dados->qtde_medidas;

    /* --- Le o nome da cidade --- */
    printf("  Nome da cidade: ");
    /*
     * scanf com %19s le ate 19 chars (deixa espaco para '\0').
     * Se o nome tiver espacos, use: scanf(" %19[^\n]", ...)
     */
    scanf(" %19[^\n]", dados->medidas[idx].cidade);

    /* --- Le o valor da temperatura --- */
    float temp;
    printf("  Temperatura (graus C): ");
    scanf("%f", &temp);

    /* --- Aloca o float e armazena (nivel 2) --- */
    /*
     * malloc(sizeof(float)) reserva espaco para um unico float.
     * O endereco desse espaco e atribuido ao ponteiro *temperatura
     * da celula atual.
     */
    dados->medidas[idx].temperatura = (float*) malloc(sizeof(float));

    if (dados->medidas[idx].temperatura == NULL) {
        printf("  Erro: falha ao alocar memoria para temperatura.\n");
        return;
    }

    /*
     * *dados->medidas[idx].temperatura = temp
     * O * desreferencia o ponteiro para ESCREVER o valor
     * no espaco alocado.
     */
    *dados->medidas[idx].temperatura = temp;

    /* --- Incrementa o contador --- */
    dados->qtde_medidas++;

    printf("  Medida inserida: %s - %.1f graus C\n",
           dados->medidas[idx].cidade,
           *dados->medidas[idx].temperatura);
}

/*
 * calcularEstatisticas: implementa a opcao (c) do menu.
 *
 * O QUE FAZ:
 *   Percorre o vetor de medidas inseridas e calcula:
 *   - Temperatura media (soma / qtde_medidas)
 *   - Menor temperatura (e a cidade correspondente)
 *   - Maior temperatura (e a cidade correspondente)
 *
 * ESTRATEGIA:
 *   Inicializa min e max com a primeira medida (indice 0),
 *   depois compara com as demais (indice 1 em diante).
 *   Guarda o INDICE do min e do max para acessar a cidade.
 *
 * LEITURA de *temperatura:
 *   Como temperatura e um ponteiro, para ler o valor usa-se
 *   o operador de desreferenciamento *:
 *     *dados->medidas[i].temperatura
 */
void calcularEstatisticas(TTemperaturas *dados) {
    /* --- Verificacoes --- */
    if (dados->medidas == NULL || dados->qtde_medidas == 0) {
        printf("  Nenhuma medida registrada ainda.\n");
        return;
    }

    float soma = 0.0f;
    int   idx_min = 0; /* indice da menor temperatura */
    int   idx_max = 0; /* indice da maior temperatura */

    /* Percorre todas as medidas inseridas */
    for (int i = 0; i < dados->qtde_medidas; i++) {
        float t = *dados->medidas[i].temperatura; /* desreferencia */

        soma += t;

        /* Atualiza minimo */
        if (t < *dados->medidas[idx_min].temperatura) {
            idx_min = i;
        }

        /* Atualiza maximo */
        if (t > *dados->medidas[idx_max].temperatura) {
            idx_max = i;
        }
    }

    float media = soma / dados->qtde_medidas;

    /* --- Exibe os resultados --- */
    printf("\n  === Estatisticas ===\n");
    printf("  Medidas registradas : %d\n", dados->qtde_medidas);
    printf("  Temperatura media   : %.2f graus C\n", media);
    printf("  Menor temperatura   : %.2f graus C — %s\n",
           *dados->medidas[idx_min].temperatura,
           dados->medidas[idx_min].cidade);
    printf("  Maior temperatura   : %.2f graus C — %s\n",
           *dados->medidas[idx_max].temperatura,
           dados->medidas[idx_max].cidade);
}

/*
 * sair: implementa a opcao (d) do menu.
 *
 * O QUE FAZ:
 *   Libera TODA a memoria alocada dinamicamente, na ordem
 *   correta: do mais interno (temperaturas) para o externo
 *   (vetor de medidas).
 *
 * ORDEM DE LIBERACAO (obrigatoria):
 *   1. Para cada medida inserida: free(*temperatura)
 *   2. free(medidas)   <- libera o vetor inteiro
 *
 *   Se fizer na ordem errada (free(medidas) primeiro),
 *   perde-se o acesso aos ponteiros *temperatura e nao e
 *   mais possivel libera-los -> vazamento de memoria.
 */
void sair(TTemperaturas *dados) {
    if (dados->medidas != NULL) {
        /* Nivel 2: libera cada temperatura individualmente */
        for (int i = 0; i < dados->qtde_medidas; i++) {
            free(dados->medidas[i].temperatura);
            dados->medidas[i].temperatura = NULL;
        }

        /* Nivel 1: libera o vetor de medidas */
        free(dados->medidas);
        dados->medidas = NULL;
    }

    dados->qtde_dias     = 0;
    dados->qtde_medidas  = 0;

    printf("  Memoria liberada. Encerrando programa.\n");
}


/* ============================================================
 * SECAO 3 - FUNCAO PRINCIPAL
 * ============================================================ */

int main() {
    /*
     * Inicializa a struct com valores seguros.
     * medidas = NULL e essencial: a funcao resetar verifica
     * se medidas != NULL para decidir se libera antes de realocar.
     * Se nao inicializar com NULL, o primeiro Reset pode tentar
     * dar free em um endereco invalido -> comportamento indefinido.
     */
    TTemperaturas dados = {0, 0, NULL};

    int opcao;

    do {
        printf("\n========================================\n");
        printf("   Analise de Temperaturas de Cidades\n");
        printf("========================================\n");
        printf("  1. Reset\n");
        printf("  2. Inserir Medida\n");
        printf("  3. Estatistica\n");
        printf("  0. Sair\n");
        printf("----------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Reset ---\n");
                resetar(&dados);
                break;

            case 2:
                printf("\n--- Inserir Medida ---\n");
                inserirMedida(&dados);
                break;

            case 3:
                printf("\n--- Estatistica ---\n");
                calcularEstatisticas(&dados);
                break;

            case 0:
                sair(&dados);
                break;

            default:
                printf("  Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}