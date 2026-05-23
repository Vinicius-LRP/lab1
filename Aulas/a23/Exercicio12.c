#include <stdio.h>

void copiaArquivo(FILE *arq1, FILE *arq2){
    int c;
    while((c = fgetc(arq1)) != EOF){
        fputc(c, arq2);
    }
}

int main(){
    FILE *origem = fopen("origem.txt", "r");

    if(origem == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    FILE *copia = fopen("copia.txt", "w");

    if(copia == NULL){
        printf("Erro ao abrir arquivo!");
        fclose(origem);
        return 1;
    }

    copiaArquivo(origem, copia);

    fclose(origem);
    fclose(copia);

    return 0;
}