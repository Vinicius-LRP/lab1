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
    if(fscanf(arq," %c %c %c", &nota.etiqueta[0], &nota.etiqueta[1], &nota.etiqueta[2]) != 3){
        printf("Erro!");
        return nota;
    }
    if(fscanf(arq,"%d%d%d", &nota.cor.r, &nota.cor.g, &nota.cor.b) != 3){
        printf("Erro!");
        return nota;
    }
    if(fscanf(arq,"%d%d%d%d", &nota.retangulo.ponto.x , &nota.retangulo.ponto.y , &nota.retangulo.altura , &nota.retangulo.largura ) != 4){
        printf("Erro!");
        return nota;
    }
    if(fscanf(arq, " \"%100[^\"]\"", nota.texto) != 1){
        printf("Erro!");
        return nota;
    }
    printf("%c%c%c\n", nota.etiqueta[0], nota.etiqueta[1], nota.etiqueta[2]);
    printf("%d %d %d\n", nota.cor.r, nota.cor.g, nota.cor.b);
    printf("%d %d %d %d\n", nota.retangulo.ponto.x , nota.retangulo.ponto.y , nota.retangulo.altura , nota.retangulo.largura);
    int c;
    while((c = getc(arq)) != '\n' && c != EOF);
    printf("%s\n", nota.texto);
    
    return nota;
}

int main(){
    Nota notas[100];
    FILE *arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL){
        printf("Erro!\n");
        return 1;
    }

    notas[0] = leNota(arquivo);
    notas[1] = leNota(arquivo);
    notas[2] = leNota(arquivo);

    fclose(arquivo);
    return 0;
}