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
    if(fscanf(a, "%d %d %d %d", &r->ponto.x, &r->ponto.y, &r->tamanho.largura, &r->tamanho.altura) != 4)
        printf("Erro ao ler Retangulo!\n");
}

void leTexto(FILE *a, char t[]){
    int aspas = ' ';
    while(aspas != '"'){
        if((aspas = fgetc(a)) == EOF)
            return;
    }
    if(fscanf(a, "%99[^\"]", t) != 1){
        printf("Erro ao ler texto!");
    }
}
void consumirLinha(FILE *a){
    int c;
    while((c = fgetc(a)) != '\n' && c != EOF);
}

Nota leNota(char nome[]){
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
    consumirLinha(arq);

    fclose(arq);
    return n;
}

void leNotas(char n[]){
    FILE *arq = fopen(n, "r");

}



int main(){
    char nome[] = "arquivo.txt";

    leNota(nome);

    return 0;
}