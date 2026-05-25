#include <stdio.h>

void juntarArquivos(FILE *a1, FILE *a2,FILE *n){
    char linha[100];
    while(fgets(linha, 100, a1) != NULL){
        fputs(linha, n);
    }
    while(fgets(linha, 100, a2) != NULL){
        fputs(linha, n);
    }
}

int main(){
    FILE *arq1 = fopen("arquivo1.txt", "r");
    FILE *arq2 = fopen("arquivo2.txt", "r");
    FILE *novo = fopen("novo.txt", "w");

    if(arq1 == NULL || arq2 == NULL || novo == NULL){
        printf("Erro ao abrir!");

        if(arq1 != NULL) fclose(arq1);
        if(arq2 != NULL) fclose(arq2);
        if(novo != NULL) fclose(novo);
        return 1;
    }

    juntarArquivos(arq1, arq2, novo);

    fclose(arq1);
    fclose(arq2);
    fclose(novo);
    return 0;
}