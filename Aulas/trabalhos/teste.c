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


void inserirNotaComProblema(char l[], FILE *a){
    fprintf(a, "%s", l);
}

int valido(char c){
    return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int verificaQuebraDeLinha(int c, FILE *a){
    if(c == '\n'){
        ungetc(c, a);
        return 1;
    }
    return 0;
}

int leEtiqueta(FILE *a, char e[], char l[]){
    int c;
    int e0 = -999;
    int e1 = -999;
    int e2 = -999;
    while((c = fgetc(a)) != '\n' && c != EOF){
        if(c != ' '){
            if(e0 == -999){
                if(!valido(c)){
                    printf("Etiqueta invalida!\n");
                    return 1;
                }
                e0 = c;
                printf("%c", c);
                c = fgetc(a);
                if(verificaQuebraDeLinha(c, a) || !valido(c) || c == EOF){
                    printf("Etiqueta invalida!\n");
                    return 1;
                }
                e1 = c;
                printf("%c", c);
                c = fgetc(a);
                if(verificaQuebraDeLinha(c, a) || !valido(c) || c == EOF){
                    printf("Etiqueta invalida!\n");
                    return 1;
                }
                e2 = c;
                printf("%c\n", c);
                break;
            }
        }
    }
    if(verificaQuebraDeLinha(c, a)){
        printf("Etiqueta invalida!\n");
        return 1;
    }
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
    return 0;
}

int leCor(FILE *a, Cor *c){
    int ch;
    int r = -1;
    int g = -1;
    int b = -1;
    while((ch = fgetc(a)) != '\n' && ch != EOF){
        if((ch != ' ') && (ch < '0' || ch > '9')){
            printf("Erro na formatação da cor!\n");
            return 1;
        }
        if(ch >= '0' && ch <= '9'){
            ungetc(ch, a);
            if(r == -1){
                if(fscanf(a, "%d", &r) != 1)
                    return 1;
            }else if(g == -1){
                if(fscanf(a, "%d", &g) != 1)
                    return 1;
            }else if(b == -1){
                if(fscanf(a, "%d", &b) != 1)
                    return 1;
                break;
            }
        }
    }
    if(verificaQuebraDeLinha(ch, a))
        return 1;
    if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
        printf("Cor invalida!\n");
        return 1;
    }
    c->r = r;
    c->g = g;
    c->b = b;
    return 0;
}

int leRetangulo(FILE *a, Retangulo *r){
    int c;
    int x = -999;
    int y = -999;
    int largura = -999;
    int altura = -999;
    while((c = fgetc(a)) != '\n' && c != EOF){
        if((c != ' ') && (c < '0' || c > '9')){
            printf("Erro na formatação do retangulo!\n");
            return 1;
        }
        if(c >= '0' && c <= '9'){ 
            ungetc(c, a);
            if(x == -999){
                if(fscanf(a, "%d", &x) != 1)
                    return 1;
            }else if(y == -999){
                if(fscanf(a, "%d", &y) != 1)
                    return 1;
            }else if(largura == -999){
                if(fscanf(a, "%d", &largura) != 1)
                    return 1;
            }else if(altura == -999){
                if(fscanf(a, "%d", &altura) != 1)
                    return 1;
                break;
            }
        }
    }
    if(verificaQuebraDeLinha(c, a))
        return 1;
    r->ponto.x = x;
    r->ponto.y = y;
    r->tamanho.largura = largura;
    r->tamanho.altura = altura;
    return 0;
}

int leTexto(FILE *a, char t[], char l[], FILE *p) {
    int c;
    while ((c = fgetc(a)) != '"') {
        if (c == EOF){
            printf("Erro na formatação do texto!\n");
            return 1;
        }
        if (c == '\n') {
            printf("Erro na formatação do texto!\n"); 
            ungetc(c, a); 
            return 1; 
        }
        if(c != ' '){
            printf("Erro na formatação do texto!\n");
            return 1;
        }
    }
    int i = 0;
    while (i < 101 && (c = fgetc(a)) != '"') {
        if (c == EOF) return 1;
        if (c == '\n') { 
            ungetc(c, a); 
            return 1; 
        } 
        t[i++] = c;
    }
    t[i] = '\0';
    if(i == 101){
        printf("Texto maior que o suportado!\n");
        inserirNotaComProblema(l,p);
    }
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
    leRetangulo(arq, &n.retangulo) || leTexto(arq, n.texto, linha, p)){
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


int main(){
    Nota notas[100];
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
    int quantidade = leNotas(notas, arq, problemas);
    inserirNotas(notas, quantidade);

    fclose(arq);
    fclose(problemas);
    return 0;
}