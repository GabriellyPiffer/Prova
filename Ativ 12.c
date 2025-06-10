#include <stdio.h>
#include <stdlib.h>

struct Pizza {
    char nome[50];
    float valor;
};

struct Cliente {
    char nome[50], endereco[100];
    int idade;
};

struct Pizza pizzas[50];
struct Cliente clientes[50];
int totalpizza = 0;
int totalcliente = 0;

void CadastrarPizza();
void CadastrarCliente();
void ListarPizza();
void ListarCliente();
void ComprarPizza();
void FinalizarFuncao();

int main() {
    int opcao;
    do {
        printf("----Nostra Pizza----\n");
        printf("1 - Cadastrar pizza\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Listar pizza\n");
        printf("4 - Listar cliente\n");
        printf("5 - Comprar pizza\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção:\n");
        scanf("%d", &opcao);
 

        switch (opcao) {
            case 1:
                CadastrarPizza();
                break;
            case 2:
                CadastrarCliente();
                break;
            case 3:
                ListarPizza();
                break;
            case 4:
                ListarCliente();
                break;
            case 5:
                ComprarPizza();
                break;
            case 0:
                printf("Obrigado(a) pela preferência!\n");
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente!\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

void CadastrarPizza() {
    printf("----Cadastrar Pizza----\n");
    printf("Digite o nome da pizza:\n");
    scanf(" %[^\n]", pizzas[totalpizza].nome);
    
    printf("Digite o valor da pizza:\n");
    scanf("%f", &pizzas[totalpizza].valor);


    totalpizza++;
    FinalizarFuncao();
}

void CadastrarCliente() {
    printf("----Cadastrar Cliente----\n");
    printf("Digite o nome do cliente:\n");
    scanf(" %[^\n]", clientes[totalcliente].nome);
    
    printf("Digite sua idade:\n");
    scanf("%d", &clientes[totalcliente].idade);

    printf("Informe seu endereço (Rua, Bairro e Número): \n");
    scanf(" %[^\n]", clientes[totalcliente].endereco);

    totalcliente++;
    FinalizarFuncao();
}

void ListarPizza() {
    printf("----Listar Pizza----\n");
    for (int i = 0; i < totalpizza; i++) {
        printf("\nPizza %d: %s \nR$ %.2f\n", i + 1, pizzas[i].nome, pizzas[i].valor);
    }
    FinalizarFuncao();
}

void ListarCliente() { 
    printf("----Listar Clientes----\n");
    for (int i = 0; i < totalcliente; i++) {
        printf("Cliente %d: %s\n", i + 1, clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Endereço: %s\n", clientes[i].endereco);
    }
    FinalizarFuncao();
}

void ComprarPizza() {
    printf("----Comprar Pizza----\n");
    int cliente;
    float total = 0;
    int qntdpizza;
    int pizza;
    
    printf("Digite o número do cliente(número informado no listar cliente):\n");
    scanf("%d", &cliente);
    
    if (cliente > 0 && cliente <= totalcliente) {
        printf("\nPizzas disponíveis:\n");
        ListarPizza();
        printf("\nQuantas pizzas você deseja comprar?\n");
        scanf("%d", &qntdpizza);
        
        for (int i = 0; i < qntdpizza; i++) {
            printf("Digite o número da pizza %d: \n", i + 1);
            scanf("%d", &pizza);
            
            if (pizza > 0 && pizza <= totalpizza) {
                printf("\n%s \nR$ %.2f\n", pizzas[pizza - 1].nome, pizzas[pizza - 1].valor);
                total += pizzas[pizza - 1].valor;
            } else {
                printf("Pizza inválida!\n");
            }
        }
        
        printf("----Finalizado-----\n");
        printf("Total: R$ %.2f\n", total);
    } else {
        printf("Cliente inválido!\n");
    }
    FinalizarFuncao();
}

void FinalizarFuncao() {
    printf("\nPressione Enter para continuar....\n");
    getchar();
    getchar();
    system("clear");
}