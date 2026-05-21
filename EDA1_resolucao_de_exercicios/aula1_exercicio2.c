#include <stdio.h>

int main() {
    int teatro[15][20] = {{0}};
    int fileira, coluna, num;

    while (1) {
    
        printf("\n=== Mapa do Teatro ===\n");
        printf("   ");
        for (int j = 0; j < 20; j++) printf("%2d ", j + 1);
        printf("\n");

        for (int i = 0; i < 15; i++) {
            printf("%2d ", i + 1);
            for (int j = 0; j < 20; j++) {
                printf("[%d]", teatro[i][j]);
            }
            printf("\n");
        }

        printf("\n0 = livre, 1 = ocupado\n");
        printf("Digite o numero da fileira (1-15): ");
        scanf("%d", &fileira);
        printf("Digite o numero da coluna (1-20): ");
        scanf("%d", &coluna);

        // Validate input
        if (fileira < 1 || fileira > 15 || coluna < 1 || coluna > 20) {
            printf("Assento invalido!\n");
            continue;
        }

        if (teatro[fileira - 1][coluna - 1] == 1) {
            printf("Assento ja ocupado!\n");
        } else {
            teatro[fileira - 1][coluna - 1] = 1;
            printf("Assento reservado com sucesso!\n");
        }

        printf("Deseja reservar outro assento? (1 = sim, 2 = sair): ");
        scanf("%d", &num);
        if (num != 1) break;
    }

    return 0;
}
