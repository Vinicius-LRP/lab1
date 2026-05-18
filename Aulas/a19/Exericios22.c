#include <stdio.h>

typedef struct{
    char nome[50];
    float preco;
}Produto;

void imprimeLista(Produto **lista, int n){
    for(int a = 0; a < n ; a++){
        printf("Nome: %s\n", (lista[a])->nome);
        printf("Preço: %.2f\n", (lista[a])->preco);
    }
}



int main(){
    Produto p1 = {"Escova", 5.99};
    Produto p2 = {"Creme dental", 4.99};
    Produto p3 = {"Fio dental", 3.99};

    Produto *lista[3] = {&p1, &p2, &p3};

    imprimeLista(lista, 3);
}