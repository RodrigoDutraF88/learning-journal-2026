#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

//resetar:implementa a opcao (a) do menu se ja existir um vetor alocado anteriormente, 
//libera toda a memoria antes de realocar, le do usuario a quantidade de dias ( capacidade maxima) e
///aloca o vetor de TMedidas com essa capacidade e zera o contador qtde_medidas.

void resetar(TTemperaturas *dados) {
   
    if (dados->medidas != NULL) {
     
        for (int i = 0; i < dados->qtde_medidas; i++) {
            free(dados->medidas[i].temperatura);
   
            dados->medidas[i].temperatura = NULL;
        }
     
        free(dados->medidas);
        dados->medidas = NULL;
    }


    printf("  Informe a quantidade de dias (capacidade maxima): ");
    scanf("%d", &dados->qtde_dias);

 
    if (dados->qtde_dias <= 0) {
        printf("  Valor invalido. Nenhuma alocacao realizada.\n");
        dados->medidas = NULL;
        dados->qtde_medidas = 0;
        return;
    }

// alocar o vetor de TMedidas ,nivel 1
   
    dados->medidas = (TMedidas*) malloc(dados->qtde_dias * sizeof(TMedidas));

    if (dados->medidas == NULL) {
        printf("  Erro: falha ao alocar memoria.\n");
        dados->qtde_dias = 0;
        return;
    }


    dados->qtde_medidas = 0;

    printf("  Reset concluido. Capacidade: %d dias.\n", dados->qtde_dias);
}


 //inserirMedida: implementa a opcao (b) do menu, verifica se o vetor foi alocado (Reset foi chamado),
 //verifica se ainda ha espaco, le o nome da cidade e a temperatura do usuario, 
 //copia o nome da cidade para a celula atual do vetor, aloca um float para a temperatura (nivel 2) e armazena,
 //incrementa qtde_medidas.
 
void inserirMedida(TTemperaturas *dados) {

    if (dados->medidas == NULL) {
        printf("  Erro: execute o Reset antes de inserir.\n");
        return;
    }

    if (dados->qtde_medidas >= dados->qtde_dias) {
        printf("  Erro: capacidade maxima atingida (%d dias).\n", dados->qtde_dias);
        return;
    }

    int idx = dados->qtde_medidas;

    printf("  Nome da cidade: ");

    scanf(" %19[^\n]", dados->medidas[idx].cidade);

  
    float temp;
    printf("  Temperatura (graus C): ");
    scanf("%f", &temp);


    dados->medidas[idx].temperatura = (float*) malloc(sizeof(float));

    if (dados->medidas[idx].temperatura == NULL) {
        printf("  Erro: falha ao alocar memoria para temperatura.\n");
        return;
    }

  
    *dados->medidas[idx].temperatura = temp;

    dados->qtde_medidas++;

    printf("  Medida inserida: %s - %.1f graus C\n",
           dados->medidas[idx].cidade,
           *dados->medidas[idx].temperatura);
}


// calcularEstatisticas: implementa a opcao (c) do menu, percorre o vetor de medidas inseridas e calcula:
///temperatura media, menor temperatura, maior temperatura
 
void calcularEstatisticas(TTemperaturas *dados) {
    if (dados->medidas == NULL || dados->qtde_medidas == 0) {
        printf("  Nenhuma medida registrada ainda.\n");
        return;
    }

    float soma = 0.0f;
    int   idx_min = 0; 
    int   idx_max = 0; 

   
    for (int i = 0; i < dados->qtde_medidas; i++) {
        float t = *dados->medidas[i].temperatura; 

        soma += t;

 
        if (t < *dados->medidas[idx_min].temperatura) {
            idx_min = i;
        }


        if (t > *dados->medidas[idx_max].temperatura) {
            idx_max = i;
        }
    }

    float media = soma / dados->qtde_medidas;

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

// sair: implementa a opcao (d) do menu, libera toda a memoria alocada dinamicamente, na ordem
//correta do mais interno (temperaturas) para o externo, (vetor de medidas).

void sair(TTemperaturas *dados) {
    if (dados->medidas != NULL) {
    
        for (int i = 0; i < dados->qtde_medidas; i++) {
            free(dados->medidas[i].temperatura);
            dados->medidas[i].temperatura = NULL;
        }

        free(dados->medidas);
        dados->medidas = NULL;
    }

    dados->qtde_dias     = 0;
    dados->qtde_medidas  = 0;

    printf("  Memoria liberada. Encerrando programa.\n");
}


int main() {

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