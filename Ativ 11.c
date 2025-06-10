#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char banda[50], nome[50];
    int quantidade, ano, generoID;
    float preco;
} cd;

cd CD[100];
int numCd = 0; 

void cadastrarCD();
void venderCD();
void generoporCD();

int main() {
    int opcao;

    do {
        printf("----Som & Arte----\n");
        printf("1 - Cadastrar CD\n");
        printf("2 - Vender CD\n");
        printf("3 - CD por Genero\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {
            case 1:
                cadastrarCD();
                break;
            case 2:
                venderCD();
                break;
            case 3:
                generoporCD();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 0);

    return 0;
}
void cadastrarCD() {
    system("clear");
    if (numCd>= 100) {
        printf("Limite de CDs atingido.\n");
        return;
    }

    printf("----Cadastro de CD----\n");
    printf("Nome: ");
    scanf("%s", CD[numCd].nome);
    printf("Banda: ");
    scanf("%s", CD[numCd].banda);  
    printf("Ano: ");
    scanf("%d", &CD[numCd].ano);   
    printf("ID do genero(1-pop, 2-rock, 3-hip-hop, 4-eletrônica, 5-sertanejo, 6-samba, 7-jazz, 8-blues): ");
    scanf("%d", &CD[numCd].generoID);  
    printf("Quantidade no estoque: ");
     scanf("%d", &CD[numCd].quantidade);
    printf("Preço: R$ ");
    scanf("%f", &CD[numCd].preco);

    printf("\nProduto cadastrado com sucesso!\n");   
    
    printf("\nPressione Enter para continuar...");
    getchar(); 
    getchar(); 
    system("clear");
     numCd++; 
}

void venderCD() {
    system("clear");
    if (numCd == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }
    int quantComprada;
    printf("----Realizar Compra----\n");
    printf("Quantidade de produtos: ");
    scanf("%d", &quantComprada);

    if (quantComprada <= 0) {
        printf("Quantidade inválida.\n");
    } else if (quantComprada > CD[0].quantidade) {
        printf("Estoque insuficiente. Estoque atual: %d\n", CD[0].quantidade);
    } else {
        CD[0].quantidade -= quantComprada; 
        float total = quantComprada * CD[0].preco;
        printf("Compra realizada com sucesso! Total: R$ %.2f\n", total);
        printf("Estoque restante: %d\n", CD[0].quantidade);
    }
    
    printf("\nPressione Enter para continuar...");
    getchar(); 
    getchar(); 
    system("clear");
}

void generoporCD() {
    int id;
    system("clear");
    printf("----Buscar gênero por ID----\n");
    printf("Digite o ID do genero: ");
    scanf("%d", &id);
    
    for (int i = 0; i < numCd; i++) {
        if (CD[i].generoID == id) {
            printf("Nome: %s\n", CD[i].nome);  
            printf("Banda: %s\n", CD[i].banda);  
            printf("Ano: %d\n", CD[i].ano);  
            printf("ID do genero: %d\n", CD[i].generoID);  
            printf("Quantidade no estoque: %d\n", CD[i].quantidade);
            printf("Preço do produto: R$ %.1f\n", CD[i].preco);
            printf("-----------------------------\n");
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar(); 
    getchar(); 
    system("clear");
}

