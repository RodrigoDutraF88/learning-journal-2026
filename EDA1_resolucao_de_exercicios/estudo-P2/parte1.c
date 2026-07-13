//Aqui vou anotar as partes principais do conteúdo de estrutura de dados um para minha prova 2
//Dividi meu estudo em duas partes para auxiliar no processo
//Parte 1 será sobre os slides das aulas 8 a 11

//Métodos de Ordenação ALgoritimos e complexidades

//Antes quero revisar sobre Notação Big O
//O(1): Constante, o tempo nunca aumenta, ex: x = vetor[5], sempre faz uma operação , mesmo sendo vetor de 10 ou 10000. 
//O(log n): A cada passo eliminamos metade dos dados, ex: busca binaria
//O(n): Percorre todos os elementos, se dobrar tamanho, dobra o trabalho
//O(n log n): é a complexidade dos melhores algorítmos de ordenação, quase linear
//O(n^2): Quadrática, aparece quando temos dois laços.
//O(n^3): Três laços
//O(2^n): Exponencial, muito ruim e cresce muito rápido ,para cada elemento existem duas escolhas.
//O(n!): Fatorial, uma das piores complexidades, gera todas as permutações.

// O(1) -> O(log n) -> O(n) -> O(n log n) -> O(n^2) -> O(n^3) -> O(2^n) -> O(n!) 

//Ordeção: útil para encontrar dado específico, requer menos esforço computacional se 
// o conjunto estiver ordenado

//Seleção

//Melhor Caso O n^2
//Pior Caso O n^2
//Estavel e nao altera ordem de chaves iguais


int smallerIndex(int vet[], int tam, int ini){
    int min = ini, j;
    for(j=ini+1; j<tam; j++){
        if(vet[min] > vet[j]) // se o veton min for menor, não ocorrerá MIN = J; e continuará tentando achar um que j seja maior, se isso não acontecer, 
                             // significa que o min ja foi encontrado
            min = j;
    }
    return min;
}

void selectionSort( int vet[], int tam){
    int i, min, aux;
    for(i=0; i<tam; i++){ //vai trocando toda vez que for substituindo, ex: no index 1 coloca o 1, agora começa a sel pelo index 2...
        //Acha posicao do menor elemento a partir de i
        min = smallerIndex(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[min]; //ordena , coloca menor valor de min no index i
        vet[min] = aux; //coloca auxiliar na posição do min

    }
}


//Quicksort

//Melhor caso: O(N log N)
//Pior caso: O(N^2)
//Recursivo, a escolha do pivo afeta sua compelcidade
//estável

//Inserção

//Melhor caso: O(N)
//Pior caso: O(N^2)
//estável

//Bolha
//Melhor caso: O(N)
//Pior caso: O(N^2)

//Intercalação
//Melhor caso: O(N log N)
//Pior caso: O(N log N)
// Recursivo
//Usa um vetor temporário
//Estável

//SLIDE 9, Listas Encadeadas

//Listas sequenciais: desvantagens:
//Quantidade pre-definida de espaço
//Quantidade de Nós pre-definida, impossibilidade de alocar mais memória

//Listas Encadeadas
//Pode-se adicionar e manipular a ordem facilmente
//Dinâmica, flexivel
// O acesso a um nó é feito de forma sequencial, O(n). Diferente do vetor O(1)
//é uma sequência de nós não contíguos

struct TNo
{
    int Numero;
    TNo *Prox; //Ponteiro que aponta para prox nó
};

//Ultimo nó tem ponteiro NULL
// tem sempre um ponteiro que aponta pra o priemiro de uma lista
//Operações:
//Inclusão na cabeça: Basta criar o novo nó e apontar ele para o antigo início e atualizar. O(1) 
//Inclusão na calda: Processo parecido com de inserir na cabeça mas o ponteiro prox é NULL por ser último e ponteiro AUX deve percorrer a lista inteira para achar último, e modificar o PROX desse último nó para apontar para pNovoNo.O(n)
//Inclusão antes de chave: Parecido com inclusao na calda porem deve ser procurado com o AUX o nó em que o PROX aponta para pChave. pNovoNo também aponta para Chave, e AUX que aponta para o anterior aponta agora para pNovoNo. O(n)

//Exclusão na cabeça: AUX aponta para primeiro, pLista aponta para proximo da lista que vai se tornar primeiro, free AUX.
//Exclusão na Calda: AUX percorre lista e acha penultimo, free do último pelo vetor do penultimo, vetor no novo último = NULL 
//Exclusão de uma chave: AUX percorre ate encontrar chave, novo AUX pPost, depois do da chave, free pAnt -> Prox, pAnt->Prox = pPost

//Lista encadeada com descritor
struct TLista
{
    TNo *Primeiro;
    int Qtde;
    TNo *Ultimo;
}

//SLIDE 10 Listas Circulares

//Identificação de último e primeiro é relativa

//SLIDE 11 Lista Duplamente Encadeadas
//Ponteiro para anterior, permitirá mais flexibilidade nas operações
//Reduzem a complecidade da temoção de um elemento do final da lista de O(n) para O(1)
//Aumenta responsabilidade, agora cada inserção ou remoção precisa mantes dois sentidos de ligação consistentes

struct TNo{
    TNo *Ant;
    int NUmero;
    TNo *Prox;
}

//Ponteiro Ant do primeiro ele é NULL, lista aponta para ele

//Operações: 
//Inclusão na cabeça: parecido, Null passa para novo primeiro da lista
//Inclusão na calda: 
//Inclusão antes de chave: 

//Exclusão na cabeça:
//Exclusão na Calda: 
//Exclusão de uma chave: Nao precisa de outro aux

//Lista dupla permite a navegação nos dois sentidos
//A lista circular elimina o fim fixo da lista e A lista circular dupla combina essas duas ideias

