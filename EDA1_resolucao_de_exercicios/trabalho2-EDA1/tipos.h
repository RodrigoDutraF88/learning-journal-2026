#ifndef TIPOS_H
#define TIPOS_H


typedef struct {
    char   cidade[20];
    float *temperatura;
} TMedidas;

typedef struct {
    int       qtde_dias;     
    int       qtde_medidas;  
    TMedidas *medidas;       
} TTemperaturas;

#endif 