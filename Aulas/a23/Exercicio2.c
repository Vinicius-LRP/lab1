#include <stdio.h>

int main(){
    FILE *arq = fopen("arquivo.txt", "w");

    if(arq == NULL){
        printf("Não foi possivel abrir o arquivo!\n");
        return 1;
    }

    printf("Arquivo aberto com sucesso!\n");

    fclose(arq);

    return 0;
}