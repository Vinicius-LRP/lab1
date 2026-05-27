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
    char texto[100];
    Cor cor;
    Retangulo retangulo;
    char etiqueta[3];
}Nota;

void leEtiqueta(FILE *a, char e[]){
    for(int i = 0; i < 3; i++){
        if(fscanf(a, "%c", &e[i]) != 1){
            printf("Erro ao ler etiqueta!\n");
            return;
        }
    }
}

void leCor(FILE *arq, Cor *c){
    if(fscanf(arq, "%d %d %d", &c->r, &c->g, &c->b) != 3){
        printf("Erro ao ler cor!\n");
    }
}

Nota leArquivo(char nome[]){
    FILE *arq = fopen(nome, "r");
    Nota n = {0};

    if(arq == NULL){
        printf("Erro!");
        return n;
    }
    leEtiqueta(arq, n.etiqueta);
    leCor(arq, &n.cor);

    fscanf(arq, "%s", n.texto);



    printf("%c\n", n.etiqueta[0]);
    printf("%c\n", n.etiqueta[1]);
    printf("%c\n", n.etiqueta[2]);
    
    printf("%d\n", n.cor.r);
    printf("%d\n", n.cor.g);
    printf("%d\n", n.cor.b);

    printf("%d\n",n.retangulo.ponto.y);
    printf("%d\n",n.retangulo.ponto.x);
    printf("%d\n",n.retangulo.tamanho.largura);
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