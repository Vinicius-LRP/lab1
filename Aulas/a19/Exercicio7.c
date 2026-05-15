#include <stdio.h>

typedef struct{
    char nome[50];
    float preco;
    int quantidade;
}Estoque;

void produto_detalhes(Estoque p){
    printf("Nome do produto: %s\n", p.nome);
    printf("Preço do produto: %.2f\n", p.preco);
    printf("Quantidade: %d\n", p.quantidade);
}

void produto_mais_caro(int tamanho,Estoque p[tamanho]){
    float maior_preco = 0;
    int indice_produto = 0;
    for(int a = 0; a < tamanho; a++){
        if(p[a].preco > maior_preco) {
            maior_preco = p[a].preco;
            indice_produto = a;
        }
    }
    produto_detalhes(p[indice_produto]);
}

void valor_total_estoque(int tamanho, Estoque p[tamanho]){
    float total = 0;
    for(int a = 0; a < tamanho ; a++){
        total += p[a].preco * p[a].quantidade;
    }
    printf("Valor total do estoque: %.2f", total);
}


int main(){

    Estoque produtos[3] = {{"Escova", 5.50, 50}, {"Creme dental", 4.99, 100}, {"Fio dental", 3.99, 30}};
    
    produto_mais_caro(3,produtos);
    valor_total_estoque(3,produtos);

}
