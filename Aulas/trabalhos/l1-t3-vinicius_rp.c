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
    if(fscanf(a, " %c%c%c", &e[0], &e[1], &e[2]) != 3)
        printf("Erro ao ler etiqueta!\n");
}

void leCor(FILE *a, Cor *c){
    int vermelho;
    int verde;
    int azul;
    if(fscanf(a, "%d%d%d", &vermelho, &verde, &azul) != 3){
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
    if(fscanf(a, "%d%d%d%d", &r->ponto.x, &r->ponto.y, &r->tamanho.largura, &r->tamanho.altura) != 4)
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

Nota leNota(FILE *arq){
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

    return n;
}

void leNotas(Nota n[], int t, FILE *arq){
    for(int a = 0; a < t; a++){
        n[a] = leNota(arq);
    }
}


int main(){
    FILE *arquivo = fopen("arquivo.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }

    Nota notas[3] = {0};

    leNotas(notas, 3, arquivo);

    fclose(arquivo);

    for(int i = 0; i < 3; i++){
        printf("Nota %d\n", i + 1);

        printf("Etiqueta: %c%c%c\n",
               notas[i].etiqueta[0],
               notas[i].etiqueta[1],
               notas[i].etiqueta[2]);

        printf("Cor: %d %d %d\n",
               notas[i].cor.r,
               notas[i].cor.g,
               notas[i].cor.b);

        printf("Posicao: (%d, %d)\n",
               notas[i].retangulo.ponto.x,
               notas[i].retangulo.ponto.y);

        printf("Tamanho: %d x %d\n",
               notas[i].retangulo.tamanho.largura,
               notas[i].retangulo.tamanho.altura);

        printf("Texto: %s\n", notas[i].texto);

        printf("\n");
    }

    return 0;
}