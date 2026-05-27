#include <stdio.h>

typedef struct{
    int r;
    int g;
    int b;
}Cor;

typedef struct{
    int y;
    int x;
}Ponto;

typedef struct{
    int comprimento;
    int altura;
}Tamanho;

typedef struct{
    Ponto ponto;
    Tamanho tamanho;
}Retangulo;


typedef struct{
    char texto[100];
    Cor cor;
    Retangulo retangulo;
    char etiqueta[3];
}Nota;


Nota leArquivo(char nome[]){
    FILE *arq = fopen(nome, "r");
    Nota n;

    if(arq == NULL){
        printf("Erro!");
        return n;
    }
    
    char c;
    for(int a = 0; a < 3; a++){
        if(fscanf(arq, "%c", &c) == 1){
            n.etiqueta[a] = c;
        }
    }
    int i;
    if(fscanf(arq, "%d", &i) == 1){
        n.cor.r = i;
    }
    if(fscanf(arq, "%d", &i) == 1){
        n.cor.g = i;
    }
    if(fscanf(arq, "%d", &i) == 1){
        n.cor.b = i;
    }

    if(fscanf(arq, "%d", &i) == 1){
        n.retangulo.ponto.y = i;
    }
    if(fscanf(arq, "%d", &i) == 1){
        n.retangulo.ponto.x = i;
    }
    if(fscanf(arq, "%d", &i) == 1){
        n.retangulo.tamanho.comprimento = i;
    }
    if(fscanf(arq, "%d", &i) == 1){
        n.retangulo.tamanho.altura = i;
    }
    
    fscanf(arq, "%s", n.texto);



    printf("%c\n", n.etiqueta[0]);
    printf("%c\n", n.etiqueta[1]);
    printf("%c\n", n.etiqueta[2]);

    printf("%d\n", n.cor.r);
    printf("%d\n", n.cor.g);
    printf("%d\n", n.cor.b);

    printf("%d\n",n.retangulo.ponto.y);
    printf("%d\n",n.retangulo.ponto.x);
    printf("%d\n",n.retangulo.tamanho.comprimento);
    printf("%d\n",n.retangulo.tamanho.altura); 
    printf("%s\n", n.texto);  
    
    fclose(arq);
    return n;
}



int main(){
    char nome[] = "arquivo.txt";

    leArquivo(nome);

    return 0;
}