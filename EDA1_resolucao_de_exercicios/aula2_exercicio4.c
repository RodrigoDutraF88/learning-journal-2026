#include <stdio.h>
#include <string.h>

typedef struct Produto{
    char Nome[50];
    float Preco; 
    int Qnt_estoque;
}Produto;

void AtualizarProduto( Produto *P, char nome[], float preco, int qnt_estoque){
    strcpy(P->Nome, nome);
    P->Preco = 1.5 * preco;
    P->Qnt_estoque = qnt_estoque - 1;

}
void ImprimirProduto(Produto P) {
    printf("Nome: %s, Preço: %f, Quantidade em estoque: %d\n", P.Nome, P.Preco, P.Qnt_estoque);
}

int main(){
    Produto Produto1 = {"Fusca", 40000, 15};
    
    printf("Antes:\n");
    ImprimirProduto(Produto1);
    
    AtualizarProduto(&Produto1, "Fusca", Produto1.Preco, Produto1.Qnt_estoque);
    
    printf("Depois:\n");
    ImprimirProduto(Produto1);
}