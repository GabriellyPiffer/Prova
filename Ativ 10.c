#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

struct Produto produto;

void cadastrarProduto();
void visualizarProduto();
void venderProduto();
    
int main() {
    int opcao;

    do {
        printf("----SuperMais----\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Visualizar produto\n");
        printf("3 - Realizar compra\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarProduto();
                break;
            case 3:
                venderProduto();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}

void cadastrarProduto() {
    system("clear");
    printf("----Cadastrar Produto----\n");
    printf("Nome do produto: ");
    scanf("%s", produto.nome);
    printf("Preço do produto: ");
    scanf("%f", &produto.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &produto.quantidade);
}

void visualizarProduto() {
    system("clear");
    printf("----Informações do Produto----\n");
    printf("Nome: %s\n", produto.nome);
    printf("Preço: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
}


void venderProduto() {
    int quantos;
    system("clear");
    printf("----Compra de Produto----\n");
    printf("Quantidade a comprar: ");
    scanf("%d", &quantos);
    if (quantos <= produto.quantidade) {
        produto.quantidade -= quantos;
        printf("Compra realizada com sucesso!\n");
    } else {
        printf("Estoque insuficiente!\n");
    }

}
