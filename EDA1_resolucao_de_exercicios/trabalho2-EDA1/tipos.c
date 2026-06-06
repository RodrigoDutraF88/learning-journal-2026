/*
 * tipos.h
 * ============================================================
 * Definicao dos tipos exigidos pelo enunciado do Trabalho 2.
 *
 * Este arquivo deve ser incluido no main.c com: #include "tipos.h"
 *
 * ENTENDENDO AS STRUCTS:
 *
 * TMedidas representa UMA medicao de temperatura de uma cidade.
 *   - cidade[20]: nome da cidade (string de ate 19 chars + '\0')
 *   - *temperatura: PONTEIRO para float.
 *     Por que ponteiro e nao simplesmente float?
 *     Porque o enunciado quer alocacao dinamica ate no campo
 *     interno da struct. Cada temperatura sera alocada com
 *     malloc(sizeof(float)) individualmente.
 *
 * TTemperaturas e o "container" que gerencia todas as medicoes.
 *   - qtde_dias: capacidade maxima do vetor (definida no Reset)
 *   - qtde_medidas: quantas medicoes foram inseridas ate agora
 *   - *medidas: vetor dinamico de TMedidas, alocado no Reset
 *     com malloc(qtde_dias * sizeof(TMedidas))
 *
 * Visualizacao da estrutura na memoria apos Reset e 2 insercoes:
 *
 *  TTemperaturas
 *  +------------------+
 *  | qtde_dias   = 5  |
 *  | qtde_medidas= 2  |
 *  | *medidas --------|----> [ medidas[0]        ] [ medidas[1]        ] ...
 *  +------------------+      | cidade="Brasilia" | | cidade="Gama"     |
 *                            | *temperatura ---> | | *temperatura ---> |
 *                            +-------------------+ +-------------------+
 *                                        |                    |
 *                                        v                    v
 *                                    [25.3f]              [22.1f]
 *                         (malloc de 1 float)   (malloc de 1 float)
 * ============================================================
 */

#ifndef TIPOS_H
#define TIPOS_H

/*
 * TMedidas: armazena nome da cidade e um ponteiro para
 * a temperatura daquela medicao.
 * O ponteiro *temperatura deve ser alocado dinamicamente
 * em cada insercao e liberado em cada remocao/reset/sair.
 */
typedef struct {
    char   cidade[20];
    float *temperatura;
} TMedidas;

/*
 * TTemperaturas: estrutura principal que gerencia o vetor
 * de medicoes.
 *
 * qtde_dias    = capacidade maxima (alocada no Reset)
 * qtde_medidas = contador de medicoes inseridas (0 apos Reset)
 * *medidas     = vetor dinamico de TMedidas
 */
typedef struct {
    int       qtde_dias;     /* capacidade maxima do vetor        */
    int       qtde_medidas;  /* quantas medidas foram inseridas   */
    TMedidas *medidas;       /* vetor dinamico de TMedidas        */
} TTemperaturas;

#endif /* TIPOS_H */