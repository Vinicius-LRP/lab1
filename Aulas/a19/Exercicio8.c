#include <stdio.h>

typedef struct{
    char nome[50];
    float valor;
}Produto;

void aumentarPreco(Produto *p){
    p->valor *= 1.1;
}
void detalhesProduto(Produto p){
    printf("Nome do produto: %s\n", p.nome);
    printf("Valor do produto: %.2f\n", p.valor);

}



int main(){
    Produto escova = {"Escova Eletrica", 15.99};
   
    Produto produtos[5] = {escova};
    aumentarPreco(&produtos[0]);
    detalhesProduto(produtos[0]);
}