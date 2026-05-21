#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>


int main(){
    int andar, sala;
    float soma, media;
    int edificio[5][10][24];
    srand(time(NULL));
    for (int a = 0; a < 5; a++) {
        for (int s = 0; s< 10; s ++){
            for (int t=0; t<24; t ++){
                edificio[a][s][t] = rand() % 25 + 1;
            }
        }       
    }
    while(1){
        printf("\nSelecione um andar(1-5):");
        scanf("%d" , &andar);
        if (andar > 5 || andar <1){
            printf("Andar invalido.");
            continue;
        }
        printf("Selecione uma sala(1-10):");
        scanf("%d" , &sala);
        if (sala > 10 || andar <1){
            printf("Sala invalida.");
            continue;
        }
        soma = 0;
        for (int i = 0; i<24; i++){
            printf(" hora %2d : %d graus\n ", i,  edificio[andar -1][sala -1][i]);
            soma += edificio[andar-1 ][sala-1][i];
        }

        media = soma/24;
        printf("Media da temp da sala: %.f \n", media);

        for(int a =0; a<5; a++){
            soma=0;
            for(int s =0; s<10; s++)
                for(int t=0; t<24; t++)
                    soma += edificio[a][s][t];
            printf(" Media temp Andar %d: %.2f graus \n", a +1, soma /(10*24));
        }
        printf("\n consultar outro andar?(1=sim,2=sair):");
        int opcao;
        scanf("%d", &opcao);
        if(opcao != 1) break;

    }
    return 0;

}