#include <stdio.h>

void adicionarNomes(FILE *arq){
    for(int a = 0; a < 5; a++){
        char nome[50];
        printf("Digite o nome %d:", a + 1);
        scanf("%s", nome);
        
        fputs(nome, arq);
        fputs("\n", arq);
    }
}




int main(){
    FILE *arq = fopen("arquivo.txt", "w");
    if(arq == NULL){
        printf("Erro ao abrir!");
        return 1;
    }
    adicionarNomes(arq);


    fclose(arq);
    return 0;
}