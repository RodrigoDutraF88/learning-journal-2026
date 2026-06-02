#include <stdio.h>
#include <stdlib.h>
#include <string.h>


///TCadastro: dados comuns a todos os contribuintes

typedef struct Cadastro {
    char CNPJ[15];       
    char RazaoSocial[50]; 
    char Cidade[30];      
    char Fone[12];       
} TCadastro;


//TNoI: no da Lista Industria
typedef struct NoI {
    TCadastro  *Dados; //ponteiro para os dados do contribuinte
    struct NoI *Prox;  // ponteiro para o proximo no
} TNoI;


//TNoC: no da Lista Comercio, Estrutura duplamente encadeada sem descritor

typedef struct NoC {
    TCadastro  *Dados; 
    struct NoC *Ant;  
    struct NoC *Prox;  
} TNoC;


//// TNoS: no da Lista Servicos,Estrutura duplamente encadeada com descritor
typedef struct NoS {
    TCadastro  *Dados;
    struct NoS *Ant;
    struct NoS *Prox;
} TNoS;


typedef struct DescritorS {
    TNoS *Inicio; 
    int   Tamanho;
    TNoS *Fim;    
} TDescritorS;


/// TCadastroU: dados do contribuinte unificado.

typedef struct CadastroU {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo; // I ,C  ou S 
} TCadastroU;


//////TNoU: no da Lista Unificada, duplamente encadeada igual ao TNoS internamente.
typedef struct NoU {
    TCadastroU *Dados;
    struct NoU *Ant;
    struct NoU *Prox;
} TNoU;

typedef struct DescritorU {
    TNoU *Inicio;
    int   Tamanho;
    TNoU *Fim;
} TDescritorU;

 
//FUNCOES AUXILIARES DE IMPRESSAO

void imprimirCadastro(TCadastro *d) {
    printf("  CNPJ        : %s\n", d->CNPJ);
    printf("  Razao Social: %s\n", d->RazaoSocial);
    printf("  Cidade      : %s\n", d->Cidade);
    printf("  Fone        : %s\n", d->Fone);
}


void imprimirCadastroU(TCadastroU *d) {
    char *tipoStr;
    switch (d->Tipo) {
        case 'I': tipoStr = "Industria"; break;
        case 'C': tipoStr = "Comercio";  break;
        case 'S': tipoStr = "Servico";   break;
        default:  tipoStr = "Desconhecido";
    }
    printf("  CNPJ        : %s\n", d->CNPJ);
    printf("  Razao Social: %s\n", d->RazaoSocial);
    printf("  Cidade      : %s\n", d->Cidade);
    printf("  Fone        : %s\n", d->Fone);
    printf("  Tipo        : %c (%s)\n", d->Tipo, tipoStr);
}



 ///LISTA INDUSTRIA 

TNoI* criarNoIndustria(TCadastro dados) {
    TNoI *novo = (TNoI*) malloc(sizeof(TNoI));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para no de Industria.\n");
        return NULL;
    }
    novo->Dados = (TCadastro*) malloc(sizeof(TCadastro));
    if (novo->Dados == NULL) {
        printf("Erro: falha ao alocar memoria para dados de Industria.\n");
        free(novo); 
        return NULL;
    }
    *novo->Dados = dados;
    novo->Prox = NULL;
    return novo;
}
TNoI* inserirIndustria(TNoI *lista, TCadastro dados) {
    TNoI *novo = criarNoIndustria(dados);
    if (novo == NULL) return lista; 

    if (lista == NULL) {
        return novo; 
    }
    TNoI *aux = lista;
    while (aux->Prox != NULL) {
        aux = aux->Prox;
    }

    aux->Prox = novo;
    return lista; 
}
void imprimirIndustria(TNoI *lista) {
    if (lista == NULL) {
        printf("  Lista Industria esta vazia.\n");
        return;
    }

    TNoI *aux = lista; 
    int contador = 1;

    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastro(aux->Dados);
        aux = aux->Prox; /* avanca para o proximo no */
    }
}

TNoI* liberarIndustria(TNoI *lista) {
    TNoI *aux = lista;
    TNoI *prox;

    while (aux != NULL) {
        prox = aux->Prox;   
        free(aux->Dados);  
        free(aux);        
        aux = prox;        
    }

    return NULL; 
}


TNoI* carregarIndustria(TNoI *lista, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("  Erro: arquivo '%s' nao encontrado.\n", nomeArquivo);
        return lista;
    }

    TCadastro dados;
    char linha[120]; ///buffer para a linha inteira

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        // sscanf com %[^;] le ate encontrar ';',o espaco antes de %[ descarta espacos residuais
         // %*c consome o ';' separador sem armazenar
        int lidos = sscanf(linha,
            "%14[^;]%*c%49[^;]%*c%29[^;]%*c%11[^\n]",
            dados.CNPJ,
            dados.RazaoSocial,
            dados.Cidade,
            dados.Fone);

        if (lidos == 4) {
            lista = inserirIndustria(lista, dados);
        }
    }

    fclose(arq);
    printf("  Arquivo '%s' carregado.\n", nomeArquivo);
    return lista;
}
 
///LISTA COMERCIO 

TNoC* criarNoComercio(TCadastro dados) {
    TNoC *novo = (TNoC*) malloc(sizeof(TNoC));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para no de Comercio.\n");
        return NULL;
    }

    novo->Dados = (TCadastro*) malloc(sizeof(TCadastro));
    if (novo->Dados == NULL) {
        printf("Erro: falha ao alocar memoria para dados de Comercio.\n");
        free(novo);
        return NULL;
    }

    *novo->Dados = dados;
    novo->Ant  = NULL;
    novo->Prox = NULL;
    return novo;
}

TNoC* inserirComercio(TNoC *lista, TCadastro dados) {
    TNoC *novo = criarNoComercio(dados);
    if (novo == NULL) return lista;

    if (lista == NULL) {
        return novo;
    }

    TNoC *aux = lista;
    while (aux->Prox != NULL) {
        aux = aux->Prox;
    }

    aux->Prox  = novo; ///ultimo no aponta para o novo  
    novo->Ant  = aux;  // novo no aponta de volta ao ultimo 

    return lista;
}
void imprimirComercio(TNoC *lista) {
    if (lista == NULL) {
        printf("  Lista Comercio esta vazia.\n");
        return;
    }

    TNoC *aux = lista;
    int contador = 1;

    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastro(aux->Dados);
        aux = aux->Prox;
    }
}

void imprimirComercioInvertida(TNoC *lista) {
    if (lista == NULL) {
        printf("  Lista Comercio esta vazia.\n");
        return;
    }

    TNoC *aux = lista;
    while (aux->Prox != NULL) {
        aux = aux->Prox;
    }

    int contador = 1;
    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastro(aux->Dados);
        aux = aux->Ant;
    }
}

TNoC* liberarComercio(TNoC *lista) {
    TNoC *aux = lista;
    TNoC *prox;

    while (aux != NULL) {
        prox = aux->Prox;
        free(aux->Dados);
        free(aux);
        aux = prox;
    }

    return NULL;
}

TNoC* carregarComercio(TNoC *lista, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("  Erro: arquivo '%s' nao encontrado.\n", nomeArquivo);
        return lista;
    }

    TCadastro dados;
    char linha[120];

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        int lidos = sscanf(linha,
            "%14[^;]%*c%49[^;]%*c%29[^;]%*c%11[^\n]",
            dados.CNPJ,
            dados.RazaoSocial,
            dados.Cidade,
            dados.Fone);

        if (lidos == 4) {
            lista = inserirComercio(lista, dados);
        }
    }

    fclose(arq);
    printf("  Arquivo '%s' carregado.\n", nomeArquivo);
    return lista;
}

//LISTA SERVICOS

TNoS* criarNoServicos(TCadastro dados) {
    TNoS *novo = (TNoS*) malloc(sizeof(TNoS));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para no de Servicos.\n");
        return NULL;
    }

    novo->Dados = (TCadastro*) malloc(sizeof(TCadastro));
    if (novo->Dados == NULL) {
        printf("Erro: falha ao alocar memoria para dados de Servicos.\n");
        free(novo);
        return NULL;
    }

    *novo->Dados = dados;
    novo->Ant  = NULL;
    novo->Prox = NULL;

    return novo;
}

void inserirServicos(TDescritorS *desc, TCadastro dados) {
    TNoS *novo = criarNoServicos(dados);
    if (novo == NULL) return;

    if (desc->Inicio == NULL) {

        desc->Inicio = novo;
        desc->Fim    = novo;
    } else {

        novo->Ant        = desc->Fim; // o Ant do novo no aponta para o atual ultimo 
        desc->Fim->Prox  = novo;//o Prox do atual ultimo aponta para o novo no
        desc->Fim        = novo;//desc->Fim e atualizado para o novo no
    }

    desc->Tamanho++;
}

void imprimirServicos(TDescritorS *desc) {
    if (desc->Inicio == NULL) {
        printf("  Lista Servicos esta vazia.\n");
        return;
    }

    printf("  Total de registros: %d\n", desc->Tamanho);

    TNoS *aux = desc->Inicio;
    int contador = 1;

    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastro(aux->Dados);
        aux = aux->Prox;
    }
}

void imprimirServicosInvertida(TDescritorS *desc) {
    if (desc->Fim == NULL) {
        printf("  Lista Servicos esta vazia.\n");
        return;
    }

    printf("  Total de registros: %d\n", desc->Tamanho);

    TNoS *aux = desc->Fim; 
    int contador = 1;

    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastro(aux->Dados);
        aux = aux->Ant; 
    }
}
void liberarServicos(TDescritorS *desc) {
    TNoS *aux = desc->Inicio;
    TNoS *prox;

    while (aux != NULL) {
        prox = aux->Prox;
        free(aux->Dados);
        free(aux);
        aux = prox;
    }

    desc->Inicio   = NULL;
    desc->Fim      = NULL;
    desc->Tamanho  = 0;
}
void carregarServicos(TDescritorS *desc, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("  Erro: arquivo '%s' nao encontrado.\n", nomeArquivo);
        return;
    }

    TCadastro dados;
    char linha[120];

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        int lidos = sscanf(linha,
            "%14[^;]%*c%49[^;]%*c%29[^;]%*c%11[^\n]",
            dados.CNPJ,
            dados.RazaoSocial,
            dados.Cidade,
            dados.Fone);

        if (lidos == 4) {
            inserirServicos(desc, dados);
        }
    }

    fclose(arq);
    printf("  Arquivo '%s' carregado.\n", nomeArquivo);
}

///LISTA UNIFICADA 
TNoU* criarNoUnificada(TCadastroU dados) {
    TNoU *novo = (TNoU*) malloc(sizeof(TNoU));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para no da lista Unificada.\n");
        return NULL;
    }

    novo->Dados = (TCadastroU*) malloc(sizeof(TCadastroU));
    if (novo->Dados == NULL) {
        printf("Erro: falha ao alocar memoria para dados da lista Unificada.\n");
        free(novo);
        return NULL;
    }

    *novo->Dados = dados;
    novo->Ant  = NULL;
    novo->Prox = NULL;

    return novo;
}

void inserirUnificada(TDescritorU *desc, TCadastroU dados) {
    TNoU *novo = criarNoUnificada(dados);
    if (novo == NULL) return;

    if (desc->Inicio == NULL) {
        desc->Inicio = novo;
        desc->Fim    = novo;
    } else {
        novo->Ant       = desc->Fim;
        desc->Fim->Prox = novo;
        desc->Fim       = novo;
    }

    desc->Tamanho++;
}

void imprimirUnificada(TDescritorU *desc) {
    if (desc->Inicio == NULL) {
        printf("  Lista Unificada esta vazia. Execute a opcao 2 primeiro.\n");
        return;
    }

    printf("  Total de registros: %d\n", desc->Tamanho);

    TNoU *aux = desc->Inicio;
    int contador = 1;

    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastroU(aux->Dados);
        aux = aux->Prox;
    }
}

void imprimirUnificadaInvertida(TDescritorU *desc) {
    if (desc->Fim == NULL) {
        printf("  Lista Unificada esta vazia. Execute a opcao 2 primeiro.\n");
        return;
    }

    printf("  Total de registros: %d\n", desc->Tamanho);

    TNoU *aux = desc->Fim;
    int contador = 1;

    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastroU(aux->Dados);
        aux = aux->Ant;
    }
}

void liberarUnificada(TDescritorU *desc) {
    TNoU *aux = desc->Inicio;
    TNoU *prox;

    while (aux != NULL) {
        prox = aux->Prox;
        free(aux->Dados);
        free(aux);
        aux = prox;
    }
    desc->Inicio  = NULL;
    desc->Fim     = NULL;
    desc->Tamanho = 0;
}

void gerarListaUnificada(TDescritorU *desc,
                         TNoI *listI,
                         TNoC *listC,
                         TDescritorS *descS) {

    if (desc->Inicio != NULL) {
        printf("  Lista Unificada anterior sera substituida.\n");
        liberarUnificada(desc);
    }

    TCadastroU dadosU;  
    TNoI *auxI = listI;
    while (auxI != NULL) {

        strncpy(dadosU.CNPJ,        auxI->Dados->CNPJ,        14); dadosU.CNPJ[14]        = '\0';
        strncpy(dadosU.RazaoSocial, auxI->Dados->RazaoSocial, 49); dadosU.RazaoSocial[49] = '\0';
        strncpy(dadosU.Cidade,      auxI->Dados->Cidade,       29); dadosU.Cidade[29]      = '\0';
        strncpy(dadosU.Fone,        auxI->Dados->Fone,         11); dadosU.Fone[11]        = '\0';
        dadosU.Tipo = 'I';

        inserirUnificada(desc, dadosU);
        auxI = auxI->Prox;
    }
    TNoC *auxC = listC;
    while (auxC != NULL) {
        strncpy(dadosU.CNPJ,        auxC->Dados->CNPJ,        14); dadosU.CNPJ[14]        = '\0';
        strncpy(dadosU.RazaoSocial, auxC->Dados->RazaoSocial, 49); dadosU.RazaoSocial[49] = '\0';
        strncpy(dadosU.Cidade,      auxC->Dados->Cidade,       29); dadosU.Cidade[29]      = '\0';
        strncpy(dadosU.Fone,        auxC->Dados->Fone,         11); dadosU.Fone[11]        = '\0';
        dadosU.Tipo = 'C'; 

        inserirUnificada(desc, dadosU);
        auxC = auxC->Prox;
    }

    TNoS *auxS = descS->Inicio;
    while (auxS != NULL) {
        strncpy(dadosU.CNPJ,        auxS->Dados->CNPJ,        14); dadosU.CNPJ[14]        = '\0';
        strncpy(dadosU.RazaoSocial, auxS->Dados->RazaoSocial, 49); dadosU.RazaoSocial[49] = '\0';
        strncpy(dadosU.Cidade,      auxS->Dados->Cidade,       29); dadosU.Cidade[29]      = '\0';
        strncpy(dadosU.Fone,        auxS->Dados->Fone,         11); dadosU.Fone[11]        = '\0';
        dadosU.Tipo = 'S'; 
        inserirUnificada(desc, dadosU);
        auxS = auxS->Prox;
    }
}

void apagarListas(TNoI **listI, TNoC **listC,
    TDescritorS *descS, TDescritorU *descU) {
    *listI = liberarIndustria(*listI); 
    *listC = liberarComercio(*listC);  
    liberarServicos(descS);           
    liberarUnificada(descU);         
    printf("  Todas as listas foram apagadas e a memoria foi liberada.\n");
}

int main() {
    TNoI    *listaI = NULL;
    TNoC    *listaC = NULL;
    TDescritorS listaS = {NULL, 0, NULL};
    TDescritorU listaU = {NULL, 0, NULL};
    int opcao;
    do {
        printf("\n========================================\n");
        printf("   SECRETARIA DA FAZENDA - DF\n");
        printf("   Cadastro Unificado de Contribuintes\n");
        printf("========================================\n");
        printf("  1. Carregar Dados de Entrada\n");
        printf("  2. Gerar Lista Unificada\n");
        printf("  3. Relatorio: Industrias\n");
        printf("  4. Relatorio: Comercio\n");
        printf("  5. Relatorio: Comercio Invertida\n");
        printf("  6. Relatorio: Servicos\n");
        printf("  7. Relatorio: Servicos Invertida\n");
        printf("  8. Relatorio: Lista Unificada\n");
        printf("  9. Relatorio: Lista Unificada Invertida\n");
        printf(" 10. Apagar Listas\n");
        printf("  0. Sair\n");
        printf("----------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\n--- Carregando dados de entrada ---\n");
                listaI = carregarIndustria(listaI, "Industria.txt");
                listaC = carregarComercio(listaC,  "Comercio.txt");
                carregarServicos(&listaS,           "Servico.txt");
                break;

            case 2:
                printf("\n--- Gerando Lista Unificada ---\n");
                gerarListaUnificada(&listaU, listaI, listaC, &listaS);
                printf("  Concluido. Total: %d registros.\n", listaU.Tamanho);
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
                printf("\n--- Encerrando programa ---\n");
                apagarListas(&listaI, &listaC, &listaS, &listaU);
                break;

            default:
                printf("  Opcao invalida! Digite um numero entre 0 e 10.\n");
        }

    } while (opcao != 0);

    return 0;
}