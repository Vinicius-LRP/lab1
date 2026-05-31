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

typedef struct{
    Nota notas[100];
    int quantidade;
    int notaAtual;
    char textoEditor[101];
    int cursor;
}Programa;

int valido(char c){
    return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int leEtiqueta(FILE *a, char e[]){
    char e1;
    char e2;
    char e3;
    if(fscanf(a, " %c%c%c", &e1, &e2, &e3) != 3){
        printf("Erro ao ler etiqueta!\n");
        return 1;
    }
    if (!valido(e1) || !valido(e2) || !valido(e3)) {
        printf("Etiqueta diferente da permitida!\n");
        return 1;
    }
    e[0] = e1;
    e[1] = e2;
    e[2] = e3;
    return 0;
}

int leCor(FILE *a, Cor *c){
    int vermelho;
    int verde;
    int azul;
    if(fscanf(a, "%d%d%d", &vermelho, &verde, &azul) != 3){
        printf("Erro ao ler cor!\n");
        return 1;
    }
    if(vermelho < 0 || vermelho > 255 || verde < 0 || verde > 255 || azul < 0 || azul > 255){
        printf("Cor invalida!\n");
        return 1;
    }
    c->r = vermelho;
    c->g = verde;
    c->b = azul;
    return 0;
}

int leRetangulo(FILE *a, Retangulo *r){
    if(fscanf(a, "%d%d%d%d", &r->ponto.x, &r->ponto.y, &r->tamanho.largura, &r->tamanho.altura) != 4){
        printf("Erro ao ler Retangulo!\n");
        return 1;
    }
    return 0;
}

int leTexto(FILE *a, char t[]){
    int aspas = ' ';
    while(aspas != '"'){
        if((aspas = fgetc(a)) == EOF)
            return 1;
    }
    if(fscanf(a, "%100[^\"]", t) != 1){
        printf("Erro ao ler texto!");
        return 1;
    }
    return 0;
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
    

    if(leEtiqueta(arq, n.etiqueta)) n.etiqueta[0] = 'x'; 
    if(leCor(arq, &n.cor)) n.etiqueta[0] = 'x';
    if(leRetangulo(arq, &n.retangulo)) n.etiqueta[0] = 'x';
    if(leTexto(arq, n.texto)) n.etiqueta[0] = 'x';
    consumirLinha(arq);

    return n;
}

int leNotas(Nota n[], FILE *arq){
    Nota nt;
    int a = 0;
    while(a < 100){
        int c = fgetc(arq);
        if(c == EOF)
            break;
        ungetc(c, arq);
        nt = leNota(arq);
        if(nt.etiqueta[0] != 'x'){
            n[a] = nt;
            printf("%d\n", a);
            a++;
        }
    }
    return a;
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

void proximaNota(Programa *p){
    if(p->notaAtual < p->quantidade - 1){
        p->notaAtual++;
    }
}

void notaAnterior(Programa *p){
    if(p->notaAtual > 0){
        p->notaAtual--;
    }
}

void imprimeNotaAtual(Programa *p){
    printf("Texto: %s\n", p->notas[p->notaAtual].texto);
}

void inicializarPrograma(Programa *p){

    FILE *arq = fopen("arquivo.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir!\n");
        return;
    }
    p->quantidade = leNotas(p->notas, arq);
    p->notaAtual = 0;
    inserirNotas(p->notas, p->quantidade);
    imprimeNotaAtual(p);

    fclose(arq);

}

int main(){

    Programa programa = {0};

    inicializarPrograma(&programa);
    
    return 0;
    
}