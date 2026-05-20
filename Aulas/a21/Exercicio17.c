#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int pontos;
}Jogador;

void imprimeTodos(int tamanho,Jogador lista[]){
    for(int a = 0; a < tamanho ; a++){
        printf("Nome: %s\n", lista[a].nome);
        printf("Pontos: %d\n", lista[a].pontos);
    }
}


int main(){
    Jogador jogadores[3] = {{"Vinicius", 20},{"Carlos", 40},{"Eduardo", 35}};

    imprimeTodos(3, jogadores);
    
}