#include <stdio.h>
void converterMaiuscula(char l[]){
    for(int a = 0; l[a] != '\0'; a++){
        if(l[a] >= 'a' && l[a] <= 'z') l[a] -= 32;
    }
}

void copiaArquivo(FILE *a, FILE *n){
    char linha[100];
    while(!feof(a)){
        if(fgets(linha , sizeof(linha), a) != NULL){
            converterMaiuscula(linha);
            fputs(linha, n);
        }
    }
}

int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    FILE *novo = fopen("novo.txt", "w");
    if(arq == NULL || novo == NULL){
        printf("Erro ao abrir!");

        if(arq != NULL) fclose(arq);
        if(novo != NULL) fclose(novo);
        return 1;
    }

    copiaArquivo(arq, novo);

    fclose(arq);
    fclose(novo);
    return 0;
}