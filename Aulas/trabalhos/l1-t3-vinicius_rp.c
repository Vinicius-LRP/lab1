#include <stdio.h>

typedef struct{
    int r;
    int g;
    int b;
}Cor;

typedef struct{
    int coluna;
    int linha;
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
    if(fscanf(a, "%c%c%c", &e[0], &e[1], &e[2]) != 3)
        printf("Erro ao ler etiqueta!\n");
    
}

void leCor(FILE *a, Cor *c){
    int vermelho;
    int verde;
    int azul;
    if(fscanf(a, "%d %d %d", &vermelho, &verde, &azul) != 3){
        printf("Erro ao ler cor!\n");
        return;
    }
    if(vermelho < 0 || vermelho > 255 || verde < 0 || verde > 255 || azul < 0 || azul > 255){
        printf("Cor invalida!\n");
        return;
    }
    c->r = vermelho;
    c->g = verde;
    c->b = azul;
}

void leRetangulo(FILE *a, Retangulo *r){
    if(fscanf(a, "%d %d %d %d", &r->ponto.coluna, &r->ponto.linha, &r->tamanho.largura, &r->tamanho.altura) != 4)
        printf("Erro ao ler Retangulo!\n");

}

void leTexto(FILE *a, char t[]){
    if(fscanf(a, "%s", t) != 1)
        printf("Erro ao ler Texto!\n");
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
    leRetangulo(arq, &n.retangulo);
    leTexto(arq, n.texto);





    printf("%c\n", n.etiqueta[0]);
    printf("%c\n", n.etiqueta[1]);
    printf("%c\n", n.etiqueta[2]);
    
    printf("%d\n", n.cor.r);
    printf("%d\n", n.cor.g);
    printf("%d\n", n.cor.b);

    printf("%d\n",n.retangulo.ponto.coluna);
    printf("%d\n",n.retangulo.ponto.linha);
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