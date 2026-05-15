#include <stdio.h>

typedef struct{
    char rua[50];
    int número;
    char cidade[50];
}Endereco;

typedef struct{
    char nome[50];
    int idade;
    Endereco endereco;
}Pessoa;

int main(){
    Pessoa pessoa1 = {"Eduardo", 22, {"Conselheiro Pereiron", 620, "Brasilia"}};
}