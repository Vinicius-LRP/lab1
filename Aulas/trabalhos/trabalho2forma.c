#include <stdio.h>

typedef struct{
    int r;
    int g;
    int b;
}Cor;

typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    int largura;
    int altura;
}Tamanho;

typedef struct{
    Ponto ponto;
    Tamanho tamanho;
}Retangulo;

typedef struct{
    char texto[101];
    Cor cor;
    Retangulo retangulo;
    char etiqueta[3];
}Nota;

Nota leNota(FILE *a){
    Nota n = {0};
    char linha[10];

    if(fgets(linha, sizeof(linha), a) != NULL){
        printf("%s", linha);
    }

    return n;
}



int main(){
    FILE *arq = fopen("arquivo.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }
    leNota(arq);

    fclose(arq);
}