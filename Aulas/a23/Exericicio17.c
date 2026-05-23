#include <stdio.h>

int quantidadeLetras(FILE *a){
    int c;
    int quantidade = 0;
    while((c = fgetc(a)) != EOF){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) quantidade++;
    }
    return quantidade;
}

int quantidadeNumeros(FILE *a){
    int c;
    int quantidade = 0;
    while((c = fgetc(a)) != EOF){
        if(c >= '0' && c <= '9') quantidade++;
    }
    return quantidade;
}

int quantidadeCaracter(FILE *a, char d){
    int c;
    int quantidade = 0;
    while((c = fgetc(a)) != EOF){
        if(c == d) quantidade++;
    }
    return quantidade;
}

int main(){
    FILE *arquivo = fopen("arquivo.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir!");
        return 1;
    }

    printf("Letras: %d\n", quantidadeLetras(arquivo));
    rewind(arquivo);
    printf("Números: %d\n", quantidadeNumeros(arquivo));
    rewind(arquivo);
    printf("Espaços: %d\n", quantidadeCaracter(arquivo, ' '));
    rewind(arquivo);
    printf("Quebra Linha: %d\n", quantidadeCaracter(arquivo, '\n'));

    fclose(arquivo);
    return 0;
}