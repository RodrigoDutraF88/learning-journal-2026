//listas encadeadas
//estrutura de dados de tamanho variavel
//ultilizando malloc, cada elemneto novo é alocado dinamicamente
//malloc() fornece ponteiro para area de memoria reservada para novo elemento
// sempre vai ter um ponteiro para prox elemento, tamanho livre, limite é memoria ra

//listas encadeadas , sequencia de objetos do mesmo tipo
//uso sctruct para definir um novo tipo de dados
//contem variaveis de interesse e um ponteiro para a posicao na memoria do proximo

struct ElementoLista {
    int conteudo;
    struct ElementoLista *prox;
}

// lista com cabeca e sem cabeca
//no ultimo elemento tem NULL
// sempre que criar novo ele deve atribuir null ao ponteiro 
//e atualizar o ponteiro do ele anterior com valor 
// da posicao de memoria do novo elemento 

//Com cabeca : conteudo do primeiro ele não é relevante