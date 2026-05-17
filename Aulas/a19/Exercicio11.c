#include <stdio.h>
#include <string.h>

typedef struct{
    char rua[50];
    int numero;
    char cidade[50];
}Endereco;

typedef struct{
    char nome[50];
    int idade;
    Endereco endereco;
}Cliente;

typedef struct{
    char produto[50];
    int quantidade;
    Cliente cliente;
}Pedido;

Endereco inserirEndereco(char r[], int n, char c[]){
    Endereco e;
    strcpy(e.rua, r);
    e.numero = n;
    strcpy(e.cidade,c);
    return e;
}

Cliente inserirCliente(char n[], int i){
    Cliente c;
    strcpy(c.nome, n);
    c.idade = i;
    return c;
}

Pedido inserirPedido(char pr[], int q){
    Pedido p;
    strcpy(p.produto, pr);
    p.quantidade = q;
    return p;
}

void imprimeEndereco(Endereco e){
    printf("Rua: %s, N° %d, %s\n",e.rua,e.numero,e.cidade);
}

void imprimeCliente(Cliente c){
    printf("Nome: %s\n", c.nome);
    printf("Idade: %d\n", c.idade);
    imprimeEndereco(c.endereco);
}

void imprimePedido(Pedido p){
    printf("Produto: %s\n", p.produto);
    printf("Quantidade: %d\n", p.quantidade);
    imprimeCliente(p.cliente);
}

void leEndereco(Endereco *e){
    char end[50];
    int num;
    char cid[50];
    printf("Digite a rua: ");
    scanf("%s", end);
    printf("Digite o número: ");
    scanf(" %d", &num);
    printf("Digite a cidade: ");
    scanf("%s", cid);
    *e = inserirEndereco(end, num, cid);
}

void leCliente(Cliente *c){
    char nome[50];
    int id;
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);
    printf("Digite a idade: ");
    scanf("%d", &id);
    *c = inserirCliente(nome, id);
    leEndereco(&c->endereco);
}

void lePedido(Pedido *p){
    char pro[50];
    int qnt;
    printf("Digite o nome do produto: ");
    scanf("%s", pro);
    printf("Digite a quantidade: ");
    scanf("%d", &qnt);
    *p = inserirPedido(pro, qnt);
    leCliente(&p->cliente);
}


int main(){

    Pedido pedidos[50];

    lePedido(&pedidos[0]);

    imprimePedido(pedidos[0]);

}
