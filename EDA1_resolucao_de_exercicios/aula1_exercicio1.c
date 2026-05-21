#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Each index = a product type, value = quantity in stock
    char *nomes[10] = {
        "arroz", "feijao", "macarrao", "acucar", "sal",
        "oleo", "cafe", "leite", "farinha", "fermento"
    };

    int estoque[10];

    // Initialize with random quantities (1 to 50)
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        estoque[i] = rand() % 50 + 1;
    }

    int opcao, produto, quantidade;

    do {
        // Print current stock state
        printf("\n=== Estado atual do estoque ===\n");
        for (int i = 0; i < 10; i++) {
            printf("%d - %-10s: %d unidades\n", i + 1, nomes[i], estoque[i]);
        }

        printf("\n1 - Comprar produto\n");
        printf("2 - Adicionar ao estoque\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Numero do produto: ");
                scanf("%d", &produto);
                printf("Quantidade a comprar: ");
                scanf("%d", &quantidade);

                if (produto < 1 || produto > 10) {
                    printf("Produto invalido.\n");
                } else if (quantidade > estoque[produto - 1]) {
                    printf("Estoque insuficiente! Disponivel: %d\n", estoque[produto - 1]);
                } else {
                    estoque[produto - 1] -= quantidade;
                    printf("Compra realizada!\n");
                }
                break;

            case 2:
                printf("Numero do produto: ");
                scanf("%d", &produto);
                printf("Quantidade a adicionar: ");
                scanf("%d", &quantidade);

                if (produto < 1 || produto > 10) {
                    printf("Produto invalido.\n");
                } else {
                    estoque[produto - 1] += quantidade;
                    printf("Estoque atualizado!\n");
                }
                break;

            case 3:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}
