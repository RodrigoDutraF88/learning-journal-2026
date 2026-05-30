/*
 * ============================================================
 * EDA - ATIVIDADE PRATICA 02
 * Disciplina: Estruturas de Dados I - UnB / Faculdade do Gama
 * Professor : MSc. Filipe Emidio Torres
 *
 * Descricao:
 *   A Secretaria da Fazenda do DF possui 3 cadastros de
 *   contribuintes em estruturas diferentes (Industria, Comercio
 *   e Servicos). Este programa carrega essas listas a partir de
 *   arquivos .txt, exibe relatorios individuais e as unifica em
 *   uma unica lista duplamente encadeada com descritor.
 *
 * Arquivos de entrada esperados (mesmo diretorio do executavel):
 *   Industria.txt, Comercio.txt, Servico.txt
 *   Formato de cada linha: CNPJ;RazaoSocial;Cidade;Fone
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
 * SECAO 1 - DEFINICAO DE TIPOS (STRUCTS)
 *
 * Cada struct representa exatamente o que foi especificado
 * no enunciado (Figura 1 e Figura 2).
 * ============================================================ */

/*
 * TCadastro: dados comuns a todos os contribuintes.
 * Usada como payload (carga util) dos nos das listas
 * de Industria, Comercio e Servicos.
 */
typedef struct Cadastro {
    char CNPJ[15];        /* ex: "12345678000101"  */
    char RazaoSocial[50]; /* ex: "Empresa Alpha"   */
    char Cidade[30];      /* ex: "Brasilia"        */
    char Fone[12];        /* ex: "61999990001"     */
} TCadastro;

/*
 * TNoI: no da Lista Industria.
 * Estrutura SIMPLESMENTE encadeada — so possui ponteiro
 * para o proximo elemento (Prox). Nao ha ponteiro para
 * o anterior, logo nao e possivel percorrer ao contrario.
 *
 *  [Dados | Prox] -> [Dados | Prox] -> NULL
 */
typedef struct NoI {
    TCadastro  *Dados; /* ponteiro para os dados do contribuinte */
    struct NoI *Prox;  /* ponteiro para o proximo no             */
} TNoI;

/*
 * TNoC: no da Lista Comercio.
 * Estrutura DUPLAMENTE encadeada SEM descritor — possui
 * ponteiros para o anterior (Ant) e o proximo (Prox).
 * Como nao ha descritor, o acesso ao fim exige percorrer
 * a lista do inicio.
 *
 * NULL <- [Ant | Dados | Prox] <-> [Ant | Dados | Prox] -> NULL
 */
typedef struct NoC {
    TCadastro  *Dados; /* ponteiro para os dados do contribuinte */
    struct NoC *Ant;   /* ponteiro para o no anterior            */
    struct NoC *Prox;  /* ponteiro para o proximo no             */
} TNoC;

/*
 * TNoS: no da Lista Servicos.
 * Mesma estrutura interna do TNoC (dupla), mas esta lista
 * possui um DESCRITOR externo (TDescritorS) que guarda
 * acesso direto ao inicio, ao fim e ao tamanho.
 */
typedef struct NoS {
    TCadastro  *Dados;
    struct NoS *Ant;
    struct NoS *Prox;
} TNoS;

/*
 * TDescritorS: descritor da Lista Servicos.
 * Centraliza as informacoes da lista em uma unica struct,
 * facilitando o acesso ao primeiro e ultimo elemento sem
 * precisar percorrer a lista inteira.
 *
 *  +-----------------------+
 *  | Inicio | Tamanho | Fim|
 *  +-----------------------+
 *      |                |
 *      v                v
 *    [no1] <-> ... <-> [noN]
 */
typedef struct DescritorS {
    TNoS *Inicio;  /* aponta para o primeiro no da lista */
    int   Tamanho; /* quantidade de elementos            */
    TNoS *Fim;     /* aponta para o ultimo no da lista   */
} TDescritorS;

/*
 * TCadastroU: dados do contribuinte UNIFICADO.
 * Igual ao TCadastro, porem acrescenta o campo Tipo,
 * que identifica a origem do registro:
 *   'I' = Industria
 *   'C' = Comercio
 *   'S' = Servico
 */
typedef struct CadastroU {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo; /* 'I', 'C' ou 'S' */
} TCadastroU;

/*
 * TNoU: no da Lista Unificada.
 * Duplamente encadeada, igual ao TNoS internamente.
 */
typedef struct NoU {
    TCadastroU *Dados;
    struct NoU *Ant;
    struct NoU *Prox;
} TNoU;

/*
 * TDescritorU: descritor da Lista Unificada.
 * Mesma logica do TDescritorS, mas para TNoU.
 */
typedef struct DescritorU {
    TNoU *Inicio;
    int   Tamanho;
    TNoU *Fim;
} TDescritorU;


/* ============================================================
 * SECAO 2 - FUNCOES AUXILIARES DE IMPRESSAO
 *
 * Centralizam o formato de exibicao para nao repetir
 * o mesmo printf em cada funcao de relatorio.
 * ============================================================ */

/*
 * imprimirCadastro: imprime os campos de um TCadastro.
 * Recebe um ponteiro para TCadastro (nunca NULL).
 */
void imprimirCadastro(TCadastro *d) {
    printf("  CNPJ        : %s\n", d->CNPJ);
    printf("  Razao Social: %s\n", d->RazaoSocial);
    printf("  Cidade      : %s\n", d->Cidade);
    printf("  Fone        : %s\n", d->Fone);
}

/*
 * imprimirCadastroU: imprime os campos de um TCadastroU,
 * incluindo o campo Tipo com seu significado por extenso.
 */
void imprimirCadastroU(TCadastroU *d) {
    /* Converte o char Tipo em texto legivel */
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


/* ============================================================
 * SECAO 3 - LISTA INDUSTRIA (simplesmente encadeada)
 * ============================================================ */

/*
 * criarNoIndustria: aloca e inicializa um novo TNoI.
 *
 * Por que separar a criacao do no da logica de insercao?
 *   - Responsabilidade unica: esta funcao so aloca e inicializa.
 *   - Reuso: qualquer parte do codigo pode criar um no sem
 *     depender da logica de insercao.
 *   - Gerencia de memoria centralizada: o tratamento de falha
 *     de malloc fica em um so lugar.
 *
 * Retorna o ponteiro para o novo no, ou NULL se falhar.
 */
TNoI* criarNoIndustria(TCadastro dados) {
    /* Aloca memoria para o no em si */
    TNoI *novo = (TNoI*) malloc(sizeof(TNoI));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para no de Industria.\n");
        return NULL;
    }

    /* Aloca memoria para os dados dentro do no */
    novo->Dados = (TCadastro*) malloc(sizeof(TCadastro));
    if (novo->Dados == NULL) {
        printf("Erro: falha ao alocar memoria para dados de Industria.\n");
        free(novo); /* libera o no ja alocado para nao vazar memoria */
        return NULL;
    }

    /*
     * Copia toda a struct TCadastro de uma vez.
     * O operador * desreferencia o ponteiro, permitindo
     * a copia campo a campo de forma implicita.
     */
    *novo->Dados = dados;

    /* Lista simplesmente encadeada: so ha Prox */
    novo->Prox = NULL;

    return novo;
}

/*
 * inserirIndustria: insere um no no FINAL da lista Industria.
 *
 * Por que no final?
 *   Mantem a ordem de insercao igual a ordem do arquivo .txt.
 *
 * Recebe o inicio da lista e os dados a inserir.
 * Retorna o inicio (atualizado se a lista era vazia).
 *
 * Caso lista vazia:
 *   lista == NULL -> novo no vira o inicio
 *
 * Caso lista com elementos:
 *   Percorre ate o ultimo no (aux->Prox == NULL)
 *   e encadeia o novo ao final.
 */
TNoI* inserirIndustria(TNoI *lista, TCadastro dados) {
    TNoI *novo = criarNoIndustria(dados);
    if (novo == NULL) return lista; /* falha de alocacao, lista inalterada */

    /* Caso especial: lista estava vazia */
    if (lista == NULL) {
        return novo; /* novo no e o unico elemento */
    }

    /* Percorre ate o ultimo no */
    TNoI *aux = lista;
    while (aux->Prox != NULL) {
        aux = aux->Prox;
    }

    /* Encadeia o novo no ao final */
    aux->Prox = novo;

    return lista; /* inicio da lista nao muda */
}

/*
 * imprimirIndustria: percorre e exibe todos os nos da lista
 * Industria do inicio ao fim (unica direcao possivel, pois
 * e simplesmente encadeada).
 */
void imprimirIndustria(TNoI *lista) {
    if (lista == NULL) {
        printf("  Lista Industria esta vazia.\n");
        return;
    }

    TNoI *aux = lista; /* ponteiro auxiliar, nunca modifica 'lista' */
    int contador = 1;

    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastro(aux->Dados);
        aux = aux->Prox; /* avanca para o proximo no */
    }
}

/*
 * liberarIndustria: libera toda a memoria alocada pela lista.
 *
 * Ordem de liberacao para cada no:
 *   1. Salva o ponteiro para o proximo (antes de liberar o no atual)
 *   2. Libera os dados (TCadastro) do no atual
 *   3. Libera o no (TNoI) em si
 *
 * Retorna NULL para que o chamador possa zerar seu ponteiro:
 *   listaI = liberarIndustria(listaI); -> listaI agora e NULL
 */
TNoI* liberarIndustria(TNoI *lista) {
    TNoI *aux = lista;
    TNoI *prox;

    while (aux != NULL) {
        prox = aux->Prox;   /* salva o proximo antes de liberar */
        free(aux->Dados);   /* libera os dados alocados         */
        free(aux);          /* libera o no em si                */
        aux = prox;         /* avanca para o proximo            */
    }

    return NULL; /* indica que a lista foi completamente liberada */
}

/*
 * carregarIndustria: le o arquivo e preenche a lista Industria.
 *
 * Formato esperado de cada linha do arquivo:
 *   CNPJ;RazaoSocial;Cidade;Fone\n
 *
 * Estrategia de leitura:
 *   fgets le a linha inteira -> sscanf com %[^;] le ate o ';'
 *   O formato %[^;] significa "leia qualquer caractere exceto ';'"
 */
TNoI* carregarIndustria(TNoI *lista, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("  Erro: arquivo '%s' nao encontrado.\n", nomeArquivo);
        return lista;
    }

    TCadastro dados;
    char linha[120]; /* buffer para a linha inteira */

    /* Le uma linha por vez ate o fim do arquivo */
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        /*
         * sscanf com %[^;] le ate encontrar ';'
         * O espaco antes de %[ descarta espacos/newlines residuais
         * %*c consome o ';' separador sem armazenar
         */
        int lidos = sscanf(linha,
            "%14[^;]%*c%49[^;]%*c%29[^;]%*c%11[^\n]",
            dados.CNPJ,
            dados.RazaoSocial,
            dados.Cidade,
            dados.Fone);

        /* So insere se todos os 4 campos foram lidos corretamente */
        if (lidos == 4) {
            lista = inserirIndustria(lista, dados);
        }
    }

    fclose(arq);
    printf("  Arquivo '%s' carregado.\n", nomeArquivo);
    return lista;
}


/* ============================================================
 * SECAO 4 - LISTA COMERCIO (duplamente encadeada, sem descritor)
 * ============================================================ */

/*
 * criarNoComercio: aloca e inicializa um novo TNoC.
 * Inicializa Ant e Prox como NULL — o encadeamento
 * e feito pela funcao inserirComercio.
 */
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

/*
 * inserirComercio: insere um no no FINAL da lista Comercio.
 *
 * Diferenca em relacao a lista Industria:
 *   Alem de encadear no->Prox, tambem ajusta o ponteiro
 *   Ant do novo no para apontar ao ultimo no existente.
 *   Isso permite percorrer a lista ao contrario.
 *
 * Visualizacao apos insercao:
 *   [no1] <-> [no2] <-> [novo]
 *    Ant=NULL  Ant=no1   Ant=no2
 *    Prox=no2  Prox=novo Prox=NULL
 */
TNoC* inserirComercio(TNoC *lista, TCadastro dados) {
    TNoC *novo = criarNoComercio(dados);
    if (novo == NULL) return lista;

    /* Caso especial: lista estava vazia */
    if (lista == NULL) {
        return novo;
    }

    /* Percorre ate o ultimo no */
    TNoC *aux = lista;
    while (aux->Prox != NULL) {
        aux = aux->Prox;
    }

    /* Encadeia nos dois sentidos */
    aux->Prox  = novo; /* ultimo no aponta para o novo  */
    novo->Ant  = aux;  /* novo no aponta de volta ao ultimo */

    return lista;
}

/*
 * imprimirComercio: percorre e exibe a lista Comercio
 * do inicio ao fim, seguindo os ponteiros Prox.
 */
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

/*
 * imprimirComercioInvertida: percorre a lista do FIM ao inicio.
 *
 * Como nao ha descritor com ponteiro para o fim, e necessario
 * primeiro chegar ao ultimo no seguindo Prox, e entao
 * percorrer de volta usando os ponteiros Ant.
 */
void imprimirComercioInvertida(TNoC *lista) {
    if (lista == NULL) {
        printf("  Lista Comercio esta vazia.\n");
        return;
    }

    /* Passo 1: chega ao ultimo no */
    TNoC *aux = lista;
    while (aux->Prox != NULL) {
        aux = aux->Prox;
    }

    /* Passo 2: percorre de volta usando Ant */
    int contador = 1;
    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastro(aux->Dados);
        aux = aux->Ant; /* retrocede para o no anterior */
    }
}

/*
 * liberarComercio: libera toda a memoria da lista Comercio.
 * Logica identica a liberarIndustria — percorre Prox e
 * libera dados e no a cada passo.
 */
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

/*
 * carregarComercio: le o arquivo Comercio.txt e preenche
 * a lista. Logica de leitura identica a carregarIndustria.
 */
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


/* ============================================================
 * SECAO 5 - LISTA SERVICOS (duplamente encadeada COM descritor)
 * ============================================================ */

/*
 * criarNoServicos: aloca e inicializa um novo TNoS.
 * Identico ao criarNoComercio, mas para o tipo TNoS/TCadastro.
 */
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

/*
 * inserirServicos: insere um no no FINAL da lista Servicos.
 *
 * Vantagem do descritor:
 *   desc->Fim ja aponta para o ultimo no, entao NAO e
 *   necessario percorrer a lista — a insercao e O(1).
 *
 * Apos insercao, atualiza:
 *   desc->Fim    -> novo no
 *   desc->Tamanho -> incrementa
 *   (desc->Inicio so e ajustado se a lista estava vazia)
 */
void inserirServicos(TDescritorS *desc, TCadastro dados) {
    TNoS *novo = criarNoServicos(dados);
    if (novo == NULL) return;

    if (desc->Inicio == NULL) {
        /* Lista vazia: novo no e inicio e fim ao mesmo tempo */
        desc->Inicio = novo;
        desc->Fim    = novo;
    } else {
        /*
         * Lista ja tem elementos:
         *   1. O Ant do novo no aponta para o atual ultimo (desc->Fim)
         *   2. O Prox do atual ultimo aponta para o novo no
         *   3. desc->Fim e atualizado para o novo no
         */
        novo->Ant        = desc->Fim;
        desc->Fim->Prox  = novo;
        desc->Fim        = novo;
    }

    desc->Tamanho++; /* incrementa o contador do descritor */
}

/*
 * imprimirServicos: percorre e exibe a lista Servicos
 * do inicio ao fim, partindo de desc->Inicio.
 */
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

/*
 * imprimirServicosInvertida: percorre a lista do FIM ao inicio.
 *
 * Vantagem do descritor aqui:
 *   desc->Fim ja aponta para o ultimo no — sem necessidade
 *   de percorrer a lista para encontra-lo (ao contrario
 *   da lista Comercio que nao tem descritor).
 */
void imprimirServicosInvertida(TDescritorS *desc) {
    if (desc->Fim == NULL) {
        printf("  Lista Servicos esta vazia.\n");
        return;
    }

    printf("  Total de registros: %d\n", desc->Tamanho);

    TNoS *aux = desc->Fim; /* comeca direto pelo fim */
    int contador = 1;

    while (aux != NULL) {
        printf("\n  --- Contribuinte %d ---\n", contador++);
        imprimirCadastro(aux->Dados);
        aux = aux->Ant; /* retrocede usando o ponteiro Ant */
    }
}

/*
 * liberarServicos: libera toda a memoria da lista Servicos
 * e zera os campos do descritor.
 *
 * Apos liberar, o descritor fica: {NULL, 0, NULL}
 * Isso e importante para que futuras verificacoes
 * (desc->Inicio == NULL) funcionem corretamente.
 */
void liberarServicos(TDescritorS *desc) {
    TNoS *aux = desc->Inicio;
    TNoS *prox;

    while (aux != NULL) {
        prox = aux->Prox;
        free(aux->Dados);
        free(aux);
        aux = prox;
    }

    /* Zera o descritor */
    desc->Inicio   = NULL;
    desc->Fim      = NULL;
    desc->Tamanho  = 0;
}

/*
 * carregarServicos: le o arquivo Servico.txt e preenche
 * a lista via descritor. Logica de leitura identica
 * as outras funcoes de carregamento.
 */
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


/* ============================================================
 * SECAO 6 - LISTA UNIFICADA (duplamente encadeada COM descritor)
 * ============================================================ */

/*
 * criarNoUnificada: aloca e inicializa um novo TNoU.
 * Recebe um TCadastroU que ja contem o campo Tipo preenchido.
 */
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

/*
 * inserirUnificada: insere um no no FINAL da lista Unificada.
 * Logica identica a inserirServicos, mas com TNoU/TCadastroU.
 */
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

/*
 * imprimirUnificada: percorre e exibe a lista Unificada
 * do inicio ao fim. Usa imprimirCadastroU para mostrar
 * tambem o campo Tipo de cada registro.
 */
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

/*
 * imprimirUnificadaInvertida: percorre a lista Unificada
 * do FIM ao inicio usando desc->Fim e os ponteiros Ant.
 */
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

/*
 * liberarUnificada: libera toda a memoria da lista Unificada
 * e zera os campos do descritor. Logica igual a liberarServicos.
 */
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

/*
 * gerarListaUnificada: monta a lista unificada percorrendo
 * as 3 listas de entrada e copiando os dados de cada no,
 * acrescentando o campo Tipo correto para cada origem.
 *
 * Ordem de insercao: primeiro Industria, depois Comercio,
 * depois Servicos (preserva a ordem original de cada lista).
 *
 * ATENCAO: Se a lista unificada ja tiver dados (chamada dupla
 * da opcao 2), ela e liberada antes de ser gerada novamente
 * para evitar duplicatas e vazamento de memoria.
 */
void gerarListaUnificada(TDescritorU *desc,
                         TNoI *listI,
                         TNoC *listC,
                         TDescritorS *descS) {

    /* Se ja existia uma lista unificada, libera antes de recriar */
    if (desc->Inicio != NULL) {
        printf("  Lista Unificada anterior sera substituida.\n");
        liberarUnificada(desc);
    }

    TCadastroU dadosU; /* variavel auxiliar para montar o TCadastroU */

    /* --- Percorre a lista Industria --- */
    TNoI *auxI = listI;
    while (auxI != NULL) {
        /*
         * Copia os campos do TCadastro para o TCadastroU.
         * strncpy garante que nao ultrapassa o tamanho do destino.
         * O -1 deixa espaco para o '\0' de terminacao da string.
         */
        strncpy(dadosU.CNPJ,        auxI->Dados->CNPJ,        14); dadosU.CNPJ[14]        = '\0';
        strncpy(dadosU.RazaoSocial, auxI->Dados->RazaoSocial, 49); dadosU.RazaoSocial[49] = '\0';
        strncpy(dadosU.Cidade,      auxI->Dados->Cidade,       29); dadosU.Cidade[29]      = '\0';
        strncpy(dadosU.Fone,        auxI->Dados->Fone,         11); dadosU.Fone[11]        = '\0';
        dadosU.Tipo = 'I'; /* marca a origem como Industria */

        inserirUnificada(desc, dadosU);
        auxI = auxI->Prox;
    }

    /* --- Percorre a lista Comercio --- */
    TNoC *auxC = listC;
    while (auxC != NULL) {
        strncpy(dadosU.CNPJ,        auxC->Dados->CNPJ,        14); dadosU.CNPJ[14]        = '\0';
        strncpy(dadosU.RazaoSocial, auxC->Dados->RazaoSocial, 49); dadosU.RazaoSocial[49] = '\0';
        strncpy(dadosU.Cidade,      auxC->Dados->Cidade,       29); dadosU.Cidade[29]      = '\0';
        strncpy(dadosU.Fone,        auxC->Dados->Fone,         11); dadosU.Fone[11]        = '\0';
        dadosU.Tipo = 'C'; /* marca a origem como Comercio */

        inserirUnificada(desc, dadosU);
        auxC = auxC->Prox;
    }

    /* --- Percorre a lista Servicos (via descritor) --- */
    TNoS *auxS = descS->Inicio;
    while (auxS != NULL) {
        strncpy(dadosU.CNPJ,        auxS->Dados->CNPJ,        14); dadosU.CNPJ[14]        = '\0';
        strncpy(dadosU.RazaoSocial, auxS->Dados->RazaoSocial, 49); dadosU.RazaoSocial[49] = '\0';
        strncpy(dadosU.Cidade,      auxS->Dados->Cidade,       29); dadosU.Cidade[29]      = '\0';
        strncpy(dadosU.Fone,        auxS->Dados->Fone,         11); dadosU.Fone[11]        = '\0';
        dadosU.Tipo = 'S'; /* marca a origem como Servico */

        inserirUnificada(desc, dadosU);
        auxS = auxS->Prox;
    }
}

/*
 * apagarListas: libera a memoria de todas as listas de uma vez.
 * Chamada pela opcao 10 do menu e automaticamente ao sair (opcao 0).
 *
 * Usa ponteiro para ponteiro (TNoI**) para que o ponteiro original
 * em main() seja zerado (receba NULL) apos a liberacao.
 */
void apagarListas(TNoI **listI, TNoC **listC,
                  TDescritorS *descS, TDescritorU *descU) {
    *listI = liberarIndustria(*listI); /* *listI passa a ser NULL */
    *listC = liberarComercio(*listC);  /* *listC passa a ser NULL */
    liberarServicos(descS);            /* descS zerado internamente */
    liberarUnificada(descU);           /* descU zerado internamente */
    printf("  Todas as listas foram apagadas e a memoria foi liberada.\n");
}


/* ============================================================
 * SECAO 7 - FUNCAO PRINCIPAL
 * ============================================================ */

int main() {
    /*
     * Declaracao e inicializacao das listas.
     *
     * listaI e listaC sao ponteiros simples (sem descritor),
     * inicializados como NULL (lista vazia).
     *
     * listaS e listaU sao descritores, inicializados com
     * {NULL, 0, NULL} (inicio=NULL, tamanho=0, fim=NULL).
     */
    TNoI        *listaI = NULL;
    TNoC        *listaC = NULL;
    TDescritorS  listaS = {NULL, 0, NULL};
    TDescritorU  listaU = {NULL, 0, NULL};

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
                /* Libera toda a memoria antes de sair */
                apagarListas(&listaI, &listaC, &listaS, &listaU);
                break;

            default:
                printf("  Opcao invalida! Digite um numero entre 0 e 10.\n");
        }

    } while (opcao != 0);

    return 0;
}