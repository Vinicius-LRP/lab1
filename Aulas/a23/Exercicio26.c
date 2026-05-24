#include <stdio.h>

void copiarArquivo(FILE *a1, FILE *a2){
    char linha[100];

    while(fgets(linha, sizeof(linha), a1) != NULL){
        for(int a = 0; linha[a] != '\0' ; a++){
            fputc(linha[a], a2);
        }
    }
}

int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    FILE *novo = fopen("novo.txt", "w");
    if(arq == NULL || novo == NULL){
        printf("Erro ao abrir arquivo!");

        if(arq != NULL) fclose(arq);
        if(novo != NULL) fclose(novo);
        return 1;
    }
    copiarArquivo(arq, novo);

    fclose(novo);
    fclose(arq);
    return 0;
}