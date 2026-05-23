#include <stdio.h>

void removerCaracter(FILE *a1, FILE *a2, char c){
    int d;
    while((d = fgetc(a1)) != EOF){
        if(d != c) fputc(d, a2);
    }
}

int main(){
    FILE *arquivo = fopen("arquivo.txt", "r");
    FILE *novo = fopen("novo.txt", "w");

    if(arquivo == NULL || novo == NULL){
        printf("Erro ao abrir!");
        if(arquivo != NULL) fclose(arquivo);
        if(novo != NULL) fclose(novo);
        return 1;
    }

    removerCaracter(arquivo, novo, ' ');

    fclose(arquivo);
    fclose(novo);
    return 0;
}