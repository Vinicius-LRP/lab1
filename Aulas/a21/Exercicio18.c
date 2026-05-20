#include <stdio.h>
#include <string.h>

typedef struct{
    char cidade[50];
    char cep[10];
}Endereco;


typedef struct{
    char nome[50];
    Endereco endereco;
}Pessoa;

void imprimePessoa(Pessoa *p){
    printf("Nome: %s\n", p->nome);
    printf("Endereço\n");
    printf("%s CEP %s\n", p->endereco.cidade, p->endereco.cep);
}

void mudaCidade(Pessoa *p, char *novaCidade){
    strcpy(p->endereco.cidade, novaCidade);
}

int main(){
    Pessoa p = {"Vinicius", {"Santa Maria", "97040200"}};
    
    imprimePessoa(&p);

    char novaCidade[50] = "São Pedro do Sul";

    mudaCidade(&p, novaCidade);

    imprimePessoa(&p);
}