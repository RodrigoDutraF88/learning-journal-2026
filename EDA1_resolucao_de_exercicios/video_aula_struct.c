#include <stdio.h>
#include <stdlib.h>

struct cliente {
    char nome[30];
    char endereco[40];
    char cidade[30];
    int cep;
};

struct cliente infos;

struct drinks {
    int margarita,
        dry_martini,
        caipirinha;

};
struct drinks openbar;
struct drinks *cheers;

void barman(struct drinks *p){ //outro jeito
    p->margarita=18;
    p->dry_martini = 25;
}

//Typedef é usado para uma nova definição de tipo
typedef float reais;

typedef struct pais{
    char brasil;
    char alemanha;
    int japao;
} pais;
pais country; //declara uma variavel country para a estrutura

int main(){
    cheers = &openbar;
    infos.cep = 1234;
    printf("Cep: %d\n",infos.cep);
    cheers->margarita = 31;
    (*cheers).dry_martini = 15; //não usual
    printf("%d\n",cheers->margarita);
    printf("%d\n",(*cheers).dry_martini);

    barman(&openbar);//outro jeito

    reais valor;
    valor = 45.7;

}