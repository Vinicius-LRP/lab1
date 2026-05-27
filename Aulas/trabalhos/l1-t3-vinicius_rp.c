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

void inserirNota(Nota n, FILE *a){
    if(fprintf(a, "%c%c%c", n.etiqueta[0], n.etiqueta[1], n.etiqueta[2]) < 0)
        printf("Erro ao inserir etiqueta!\n");
    if(fprintf(a, " %d %d %d",n.cor.r, n.cor.g, n.cor.b) < 0)
        printf("Erro ao inserir cor!\n");
    if(fprintf(a, " %d %d %d %d", n.retangulo.ponto.x, n.retangulo.ponto.y, n.retangulo.tamanho.largura, n.retangulo.tamanho.altura) <0)
        printf("Erro ao inserir retangulo!");
    if(fprintf(a, " \"%s\"", n.texto) < 0)
        printf("Erro ao inserir texto!\n");
    if(fprintf(a, " \n") < 0)
        printf("Erro ao criar linha!");
}

void inserirNotas(Nota n[], int t){
    FILE *novo = fopen("novo.txt", "w");
    if(novo == NULL){
        printf("Erro ao abrir!\n");
        return;
    }
    for(int a = 0; a < t; a++){
       inserirNota(n[a], novo);
    }

    fclose(novo);
}

int main(){
    FILE *arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL){
        aprintf("Erro ao abrir!\n");
        return 1;
    }
    Nota notas[3] = {0};


    leNotas(notas,3, arquivo);
    inserirNotas(notas, 3);
    
    fclose(arquivo);
    return 0;
}