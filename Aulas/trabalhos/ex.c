#include <stdio.h>

typedef struct{
    int x;
    int y;
} Ponto;

typedef struct{
    int r;
    int g;
    int b;
} Cor;

typedef struct{
    Ponto ponto;
    int largura;
    int altura;
} Retangulo;

typedef struct{
    char etiqueta[3];
    Cor cor;
    Retangulo retangulo;
    char texto[100];
} Nota;

Nota leNota(FILE *arq){
    Nota nota;
    fscanf(arq, " %c %c %c", &nota.etiqueta[0], &nota.etiqueta[1], &nota.etiqueta[2]);

    return nota;
}

int main(){
    Nota n;
    FILE *arquivo = fopen("arquivo.txt","r");
    if(arquivo == NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }

    n = leNota(arquivo);

    printf("%c", n.etiqueta[0]);
    printf("%c", n.etiqueta[1]);
    printf("%c", n.etiqueta[2]);

    fclose(arquivo);
    return 0;
}