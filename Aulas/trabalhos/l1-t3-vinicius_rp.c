#include <stdio.h>
#include <string.h>

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
}Programa;

void inserirNotaComProblema(char l[], FILE *a){
    fprintf(a, "%s", l);
}

int valido(char c){
    return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int leEtiqueta(FILE *a, char e[], char l[]){
    if(l[0] == '\n' || l[1] == '\n' || l[2] == '\n') {
        printf("Etiqueta diferente da permitida!\n");
        return 1;
    }
    if(fscanf(a, " %c%c%c", &e[0], &e[1], &e[2]) != 3){
        printf("Erro ao ler etiqueta!\n");
        return 1;
    }

    if (!valido(e[0]) || !valido(e[1]) || !valido(e[2])) {
        printf("Etiqueta diferente da permitida!\n");
        return 1;
    }
    return 0;
}

int leCor(FILE *a, Cor *c){
    if(fscanf(a, "%d%d%d", &c->r, &c->g, &c->b) != 3){
        printf("Erro ao ler cor!\n");
        return 1;
    }
    if(c->r < 0 || c->r > 255 || c->g < 0 || c->g > 255 || c->b < 0 || c->b > 255){
        printf("Cor invalida!\n");
        return 1;
    }
    return 0;
}

int leRetangulo(FILE *a, Retangulo *r){
    if(fscanf(a, "%d%d%d%d", &r->ponto.x, &r->ponto.y, &r->tamanho.largura, &r->tamanho.altura) != 4){
        printf("Erro ao ler Retangulo!\n");
        return 1;
    }
    return 0;
}

int leTexto(FILE *a, char t[]) {
    int c;
    while ((c = fgetc(a)) != '"') {
        if (c == EOF) return 1;
        if (c == '\n') { 
            ungetc(c, a); 
            return 1; 
        }
    }
    int i = 0;
    while (i < 100 && (c = fgetc(a)) != '"') {
        if (c == EOF) return 1;
        if (c == '\n') { 
            ungetc(c, a); 
            return 1; 
        } 
        t[i++] = c;
    }
    t[i] = '\0';
    return 0;
}

void consumirLinha(FILE *a){
    int c;
    while((c = fgetc(a)) != '\n' && c != EOF);
}

Nota leNota(FILE *arq, FILE *p){
    Nota n = {0};
    Nota np = {0};
    char linha[300];
    long pos = ftell(arq);

    if(fgets(linha, sizeof(linha), arq) == NULL){
        n.cor.r = -3;
        return n;
    }
    fseek(arq, pos, SEEK_SET);

    if(leEtiqueta(arq, n.etiqueta, linha) || leCor(arq, &n.cor) || 
    leRetangulo(arq, &n.retangulo) || leTexto(arq, n.texto)){
        inserirNotaComProblema(linha, p);
        consumirLinha(arq);  
        np.cor.r = -2; 
        return np;
    }
    consumirLinha(arq);
    return n;
}

int leNotas(Nota n[], FILE *arq, FILE *p){
    Nota nt = {0};
    int a = 0;
    while(a < 100){
        nt = leNota(arq, p);
        if(nt.cor.r == -3) break;   
        if(nt.cor.r != -2){         
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

int main(){

    Programa p = {0};
    FILE *arq = fopen("arquivo.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }
    FILE *problemas = fopen("problemas.txt", "w");
    if(problemas == NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }
    p.quantidade = leNotas(p.notas, arq, problemas);
    p.notaAtual = 0;
    inserirNotas(p.notas, p.quantidade);
    imprimeNotaAtual(&p);

    fclose(arq);
    fclose(problemas);
    return 0;
}