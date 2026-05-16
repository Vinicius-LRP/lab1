#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    float valor;
}Produto;

typedef struct{
    char nome[50];
    char cpf[50];
}Cliente;

typedef struct{
    Cliente cliente;
    Produto produto[50];
    int quantidadeProduto;
    float valorTotal;
}Pedido;

Cliente inserirCliente(char n[], char c[]){
    Cliente p;
    strcpy(p.nome, n);
    strcpy(p.cpf, c);
    return p;
}

Produto inserirProduto(char n[], float v){
    Produto p;
    strcpy(p.nome, n);
    p.valor = v;
    return p;
}

float calculaValorTotal(float v, int qnt){
    return v * qnt;
}

Pedido criarPedido(char nc[], char c[], char np[], float v, int qp){
    Pedido p;
    p.cliente = inserirCliente(nc,c);
    p.quantidadeProduto = qp;
    for(int a = 0; a < p.quantidadeProduto ; a++){
        p.produto[a] = inserirProduto(np,v);
    }
    p.valorTotal = calculaValorTotal(v , p.quantidadeProduto);
    return p;
}
void consultarPedido(Pedido p){
    printf("Informações do pedido\n");
    printf("Nome do cliente: %s\n",p.cliente.nome);
    printf("CPF do cliente: %s\n",p.cliente.cpf);
    for(int a = 0; a < p.quantidadeProduto ; a++){
        printf("Nome do produto: %s\n",p.produto[a].nome);
        printf("Valor do produto: %.2f\n",p.produto[a].valor);
    }
    printf("Valor total: %.2f\n", p.valorTotal);
}

int main(){
    Pedido pedidos[50] = {criarPedido("Otavio", "06029330404", "Escova", 9.99, 2)};
    
    consultarPedido(pedidos[0]);
    
}