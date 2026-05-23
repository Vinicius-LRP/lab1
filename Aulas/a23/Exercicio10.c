#include <stdio.h>

int quantidadeDeCaracteres(FILE *arq){
    int quantidade = 0;
    int c = fgetc(arq);
    while(c != EOF){
        quantidade++;
        c = fgetc(arq);
    }
    return quantidade;
}



int main(){
    FILE *arquivo = fopen("arquivo.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    printf("%d\n", quantidadeDeCaracteres(arquivo));    
    
    fclose(arquivo);
    return 0;
    
}